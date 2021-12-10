#
#                           VELOXCHEM 1.0-RC2
#         ----------------------------------------------------
#                     An Electronic Structure Code
#
#  Copyright © 2018-2021 by VeloxChem developers. All rights reserved.
#  Contact: https://veloxchem.org/contact
#
#  SPDX-License-Identifier: LGPL-3.0-or-later
#
#  This file is part of VeloxChem.
#
#  VeloxChem is free software: you can redistribute it and/or modify it under
#  the terms of the GNU Lesser General Public License as published by the Free
#  Software Foundation, either version 3 of the License, or (at your option)
#  any later version.
#
#  VeloxChem is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
#  License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with VeloxChem. If not, see <https://www.gnu.org/licenses/>.

# -*- coding: utf-8 -*-

import os
import platform
import re
import subprocess
import sys
import sysconfig
from pathlib import Path

# we import these modules to get their include directories
import mpi4py
import numpy
import pybind11


class SearchReplace(dict):
    """All-in-one multiple-string-substitution class."""

    def _make_regex(self):
        """Build re object based on the keys of the current dictionary."""
        return re.compile("|".join(map(re.escape, self.keys())))

    def __call__(self, match):
        """Handler invoked for each regex match."""
        return self[match.group(0)]

    def replace(self, text):
        """Translate text, returns the modified text."""
        return self._make_regex().sub(self, text)


def find_exe(executables):
    for exe in executables:
        for path in os.environ["PATH"].split(os.pathsep):
            fname = os.path.join(path, exe)
            if os.path.isfile(fname) and os.access(fname, os.X_OK):
                return exe, path
    return None, None


def get_command_output(command):
    try:
        output = subprocess.check_output(command)
    except subprocess.CalledProcessError:
        cmd_line = " ".join(command)
        print(f"\n*** Error: Failed to execute '{cmd_line}'")
        sys.exit(1)
    return output.decode("utf-8")


def check_cray():
    if "CRAYPE_VERSION" in os.environ and "CXX" in os.environ:
        return True
    return False


def check_dir(dirname, label):
    if not os.path.isdir(dirname):
        print(f"*** Error: {label} dir {dirname} does not exist!")
        sys.exit(1)


def generate_setup(template_file, setup_file, build_lib=Path("build/lib")):

    if isinstance(template_file, str):
        template_file = Path(template_file)

    if isinstance(setup_file, str):
        setup_file = Path(setup_file)

    ext_suffix = (sysconfig.get_config_var("EXT_SUFFIX") or
                  sysconfig.get_config_var("SO"))

    # ==> OS information <==

    print("*** Checking operating system... ", end="")

    is_linux = (platform.system() == "Linux")
    is_macos = (platform.system() == "Darwin")

    if is_linux:
        print("Linux")
    elif is_macos:
        print("MacOS")
    else:
        print()
        print("*** Error: Unsupported OS!")
        print("***        Only Linux and MacOS are supported.")
        sys.exit(1)

    # ==> compiler information <==

    print("*** Checking c++ compiler... ", end="")

    if check_cray():
        cxx, cxx_path = find_exe([os.environ["CXX"]])
    elif "MPICXX" in os.environ:
        cxx, cxx_path = find_exe([os.environ["MPICXX"]])
    else:
        cxx, cxx_path = find_exe(["mpiicpc", "mpicxx", "mpiCXX"])

    print(cxx)

    if cxx is None:
        print("*** Error: Unable to find c++ compiler!")
        if check_cray():
            print("***        Please make sure that CXX is correctly set.")
        else:
            print("***        Please make sure that MPICXX is correctly set.")
        sys.exit(1)

    if cxx in ["icpc", "g++", "clang++"]:
        print(f"*** Error: {cxx} is not a MPI compiler!")
        sys.exit(1)

    if cxx in ["mpiicpc", "mpicxx", "mpiCXX"]:
        cxxname = get_command_output([cxx, "-show"])
    else:
        cxxname = get_command_output([cxx, "--version"])
    if "Cray clang" in cxxname:
        cxxname = cxxname.replace("Cray clang", "Crayclang")
    cxxname = cxxname.split()[0]

    if cxxname in ["icc", "gcc", "clang"]:
        print(f"*** Error: {cxx} is not a c++ compiler!")
        sys.exit(1)

    use_intel = (cxxname == "icpc")
    use_gnu = re.match(r"(.*(c|g|gnu-c)\+\+)", cxxname)
    use_clang = cxxname in ["clang++", "Crayclang"] or re.match(
        r".*-clang\+\+", cxxname)

    if not (use_intel or use_gnu or use_clang):
        print("*** Error: Unrecognized c++ compiler!")
        print("***        Only Intel, GNU, and Clang compilers are supported.")
        sys.exit(1)

    # ==> openmp flags <==

    if use_intel:
        if check_cray():
            cxx_flags = "-qopenmp"
        else:
            cxx_flags = "-xHost -qopenmp"
        omp_flag = "-liomp5"
    elif use_gnu:
        cxx_flags = "-fopenmp"
        omp_flag = "-lgomp"
    elif use_clang:
        cxx_flags = "-Xpreprocessor -fopenmp"
        omp_flag = "-lomp"

    # ==> math library <==

    print("*** Checking math library... ", end="")

    # check conda environment
    is_conda = os.path.exists(os.path.join(sys.prefix, "conda-meta"))

    # check whether MKL is in conda environment
    if is_conda and ("MKLROOT" not in os.environ):
        has_lib = (Path(sys.prefix, "lib/libmkl_core.so").is_file() or
                   Path(sys.prefix, "lib/libmkl_core.dylib").is_file())
        has_header = Path(sys.prefix, "include/mkl.h").is_file()
        if has_lib and has_header:
            os.environ["MKLROOT"] = sys.prefix

    # check whether OpenBLAS is in conda environment
    if is_conda and ("OPENBLASROOT" not in os.environ):
        has_lib = (Path(sys.prefix, "lib/libopenblas.so").is_file() or
                   Path(sys.prefix, "lib/libopenblas.dylib").is_file())
        has_header = (Path(sys.prefix, "include/lapacke.h").is_file() and
                      Path(sys.prefix, "include/cblas.h").is_file())
        if is_conda and has_lib and has_header:
            os.environ["OPENBLASROOT"] = sys.prefix

    use_mkl = ("MKLROOT" in os.environ)
    use_openblas = ("OPENBLASROOT" in os.environ)
    use_craylibsci = ("CRAY_LIBSCI_VERSION" in os.environ)

    if not (use_mkl or use_openblas or use_craylibsci):
        print()
        print("*** Error: Unable to find math library!")
        print("***        Please make sure that you have set MKLROOT or")
        print("***        OPENBLASROOT. OpenBLAS can be downloaded from")
        print("***        https://github.com/xianyi/OpenBLAS")
        sys.exit(1)

    # ==> mkl flags <==

    if use_mkl:
        print("MKL")

        mkl_inc = os.path.join(os.environ["MKLROOT"], "include")
        check_dir(mkl_inc, "mkl include")

        mkl_dir = os.path.join(os.environ["MKLROOT"], "lib", "intel64")
        if not os.path.isdir(mkl_dir):
            mkl_dir = os.path.join(os.environ["MKLROOT"], "lib")
        check_dir(mkl_dir, "mkl lib")

        math_lib = f"MATH_INC := -I{mkl_inc}"
        math_lib += f"\nMATH_LIB := -L{mkl_dir}"
        if is_macos:
            math_lib += f"\nMATH_LIB += -Wl,-rpath,{mkl_dir} -lmkl_rt"
        else:
            math_lib += "\nMATH_LIB += -lmkl_rt -Wl,--no-as-needed"
        math_lib += " -lpthread -lm -ldl"

        if is_linux and not use_intel:
            conf = {
                "@_mkl_interface_layer_@": "MKL_INTERFACE_LP64+MKL_INTERFACE_GNU",
                "@_mkl_threading_layer_@": "MKL_THREADING_GNU",
            }
        elif use_intel:
            conf = {
                "@_mkl_interface_layer_@": "MKL_INTERFACE_LP64",
                "@_mkl_threading_layer_@": "MKL_THREADING_INTEL",
            }
        elif use_clang:
            conf = {
                "@_mkl_interface_layer_@": "MKL_INTERFACE_LP64",
                "@_mkl_threading_layer_@": "MKL_THREADING_INTEL",
            }
        replacer = SearchReplace(conf)

        # read in src/general/ConfigMKL.hpp.in
        conf_mkl_in = Path("src", "general", "ConfigMKL.hpp.in")
        conf_mkl = Path("src", "general", "ConfigMKL.hpp")

        with conf_mkl_in.open("r") as f:
            contents = "".join(f.readlines())

        with conf_mkl.open("w") as f:
            f.write(replacer.replace(contents))

    # ==> openblas flags <==

    elif use_openblas:
        print("OpenBLAS")

        openblas_inc = os.path.join(os.environ["OPENBLASROOT"], "include")
        check_dir(openblas_inc, "openblas include")

        openblas_dir = os.path.join(os.environ["OPENBLASROOT"], "lib")
        check_dir(openblas_dir, "openblas lib")

        math_lib = f"MATH_INC := -I{openblas_inc}"
        math_lib += f"\nMATH_LIB := -L{openblas_dir}"
        math_lib += f"\nMATH_LIB += -Wl,-rpath,{openblas_dir}"
        openblas_flag = "-lopenblas"
        if use_intel:
            openblas_flag += " -lifcore"
        math_lib += f"\nMATH_LIB += {openblas_flag} {omp_flag} -lpthread -lm -ldl"

    # ==> cray-libsci flags <==

    elif use_craylibsci:
        print("Cray LibSci")

        math_lib = "MATH_INC := "
        math_lib += f"\nMATH_LIB := {omp_flag} -lpthread -lm -ldl"

    # ==> extra flags for mac <==

    if is_macos:
        maclibs = "-undefined dynamic_lookup"
    else:
        maclibs = ""

    # ==> lto flag <==

    if use_gnu:
        lto_flag = "-fno-lto"
    else:
        lto_flag = ""

    # ==> xtb package <==

    xtb_root = os.getenv("XTBHOME", sys.prefix)

    # xtb include
    xtb_inc = Path(xtb_root, "include")
    if not xtb_inc.is_dir():
        xtb_inc = Path(xtb_root, "include", "xtb")
    has_xtb_header = xtb_inc.is_dir() and (xtb_inc / "xtb.h").is_file()

    # xtb library
    xtb_dir = Path(xtb_root, "lib64")
    if not xtb_dir.is_dir():
        xtb_dir = Path(xtb_root, "lib")
    has_xtb_lib = ((xtb_dir / "libxtb.so").is_file() or
                   (xtb_dir / "libxtb.dylib").is_file())

    # xtb parameter files
    xtb_path = Path(xtb_root, "share/xtb")
    xtb_params = [
        "param_gfn0-xtb.txt", "param_gfn1-xtb.txt", "param_gfn2-xtb.txt"
    ]
    has_xtb_share = (xtb_path.is_dir() and
                     all([(xtb_path / x).is_file() for x in xtb_params]))

    use_xtb = (has_xtb_header and has_xtb_lib and has_xtb_share)
    if use_xtb:
        xtb_lib = f"XTB_INC := -I{str(xtb_inc)}\n"
        xtb_lib += f"XTB_LIB := -L{str(xtb_dir)} -Wl,-rpath,{str(xtb_dir)} -lxtb\n"
        xtb_lib += f"XTB_PATH := {str(xtb_path)}\n"
        print(f"*** Checking XTB... {xtb_root}")

    # ==> google test <==

    gtest_root = os.getenv("GTESTROOT", None)
    gtest_lib = os.getenv("GTESTLIB", None)

    if (gtest_root is not None) and (not Path(gtest_root, "include").is_dir()):
        gtest_root = None
    if (gtest_lib is not None) and (not Path(gtest_lib).is_file()):
        gtest_lib = None

    # ==> write Makefile.setup <==

    with template_file.open("r", encoding='utf-8') as f_temp:
        lines = f_temp.readlines()

    with setup_file.open("w", encoding='utf-8') as f_mkfile:
        for line in lines:
            if "====placeholder====" in line:
                print("# Automatically generated settings", file=f_mkfile)
                print("", file=f_mkfile)

                python_include_path = sysconfig.get_path("include")
                print("# Python-related headers files", file=f_mkfile)
                print(f"PYTHON_INC = -I{python_include_path}", file=f_mkfile)
                print(f"PYTHON_INC += -I{mpi4py.get_include()}", file=f_mkfile)
                print(f"PYTHON_INC += -I{numpy.get_include()}", file=f_mkfile)
                print(f"PYTHON_INC += -isystem {pybind11.get_include()}",
                      file=f_mkfile)
                # Note: use -isystem to suppress warnings from pybind11

                build_lib_str = (build_lib / "veloxchem").resolve()
                vlx_target_str = "$(BUILD_LIB)/veloxchemlib" + ext_suffix
                print(f"BUILD_LIB := {build_lib_str}", file=f_mkfile)
                print(f"VLX_TARGET := {vlx_target_str}", file=f_mkfile)
                print("", file=f_mkfile)

                print("USE_MPI := true", file=f_mkfile)
                print("USE_MKL := {}".format("true" if use_mkl else "false"),
                      file=f_mkfile)
                print("USE_XTB := {}".format("true" if use_xtb else "false"),
                      file=f_mkfile)
                print("", file=f_mkfile)

                print(math_lib, file=f_mkfile)
                print("", file=f_mkfile)

                print(
                    f"PYTHON := python{sys.version_info[0]}.{sys.version_info[1]}",
                    file=f_mkfile)
                print("", file=f_mkfile)

                print("CXX :=", cxx, file=f_mkfile)
                print("", file=f_mkfile)

                print("CXX_REL_FLG :=", cxx_flags, file=f_mkfile)
                print("CXX_DEB_FLG :=", cxx_flags, file=f_mkfile)
                print("", file=f_mkfile)

                print("MACLIBS :=", maclibs, file=f_mkfile)
                print("", file=f_mkfile)

                print("LTOFLAG :=", lto_flag, file=f_mkfile)
                print("", file=f_mkfile)

                if use_xtb:
                    print(xtb_lib, file=f_mkfile)
                    print("", file=f_mkfile)

                if gtest_root is not None and gtest_lib is not None:
                    print("GST_ROOT :=", gtest_root, file=f_mkfile)
                    print("GST_LIB :=", gtest_lib, file=f_mkfile)
                    print("", file=f_mkfile)

                print("# Generic settings", file=f_mkfile)
            else:
                print(line, end="", file=f_mkfile)

    print(f"*** Successfully generated {setup_file}")
    sys.stdout.flush()


if __name__ == "__main__":

    template_file = "Setup.template"
    setup_file = os.path.join(os.pardir, "src", "Makefile.setup")

    if not os.path.isfile(template_file):
        template_file = os.path.join("config", "Setup.template")
        setup_file = os.path.join("src", "Makefile.setup")

    if not os.path.isfile(template_file):
        print(f"*** Error: Cannot find template file {template_file}")
        sys.exit(1)

    generate_setup(template_file, setup_file)
