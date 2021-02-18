from pathlib import PurePath
import numpy as np
import sys
import re
import os

from .errorhandler import assert_msg_critical


class InputParser:
    """
    Implements the input parser and provides functions for parsing VeloxChem
    input files into a format, which passes the needed information to the rest
    of the program.

    :param inpname:
        The name of the input file.
    :param outname:
        The name of the output file.

    Instance variables
        - input_dict: The input dictionary.
        - inpname: The name of the input file.
        - outname: The name of the output file.
        - is_basis_set: The flag for parsing a basis set file.
        - basis_set_name: The name of the basis set.
    """

    def __init__(self, inpname, outname=None):
        """
        Initializes the parser and parses the input file.
        """

        self.input_dict = {}

        self.inpname = inpname
        self.outname = outname

        self.is_basis_set = False
        self.basis_set_name = ''

        self.parse()

    def parse(self):
        """
        Parses the input file.
        """

        errmsg = f'InputParser: bad syntax in file {self.inpname}' + os.linesep
        errmsg += '    You may check for incorrect, incomplete or empty groups.'

        group = None

        input_groups = {}

        with open(str(self.inpname), 'r') as f_inp:

            for line in f_inp:

                # remove comment and extra space
                line = line.strip()
                line = re.sub(r'!.*', '', line)
                line = ' '.join(line.split())

                # skip empty line
                if not line:
                    continue

                # skip first line if reading basis set
                if (not self.is_basis_set) and (line[:10] == '@BASIS_SET'):
                    self.is_basis_set = True
                    self.basis_set_name = line.split()[1]
                    continue

                # begin of group
                if line[0] == '@' and line.lower() != '@end':
                    assert_msg_critical(group is None, errmsg)
                    group = '_'.join(line[1:].strip().lower().split())
                    input_groups[group] = []

                # end of group
                elif line.lower() == '@end':
                    assert_msg_critical(group is not None, errmsg)
                    group = None

                # inside group
                elif group is not None:
                    input_groups[group].append(line)

                # outside group
                else:
                    assert_msg_critical(self.is_basis_set, errmsg)

        self.input_dict = {}

        for group in input_groups:
            self.input_dict[group] = {}

            key = None
            lines_without_key = []

            for line in input_groups[group]:
                if ':' in line:
                    key, value = line.split(':')
                    key = '_'.join(key.strip().lower().split())
                    value = value.strip()
                    if value:
                        self.input_dict[group][key] = value
                    else:
                        self.input_dict[group][key] = []
                else:
                    if key is not None:
                        self.input_dict[group][key].append(line)
                    else:
                        lines_without_key.append(line)

            if key is None:
                self.input_dict[group] = lines_without_key

        # save basis set name
        if self.is_basis_set:
            self.input_dict['basis_set_name'] = self.basis_set_name
            return

        # check empty group
        for group in self.input_dict:
            assert_msg_critical(len(self.input_dict[group]), errmsg)

        # save filename
        if self.outname not in [None, sys.stdout]:
            f_path = PurePath(self.outname)
        else:
            f_path = PurePath(self.inpname)
        self.input_dict['filename'] = str(f_path.with_name(f_path.stem))

        # update checkpoint filename
        abbrev = {
            'scf': 'scf',
            'response': 'rsp',
            'exciton': 'exciton',
            'loprop': 'loprop',
        }

        for job_type in abbrev:
            if job_type not in self.input_dict:
                self.input_dict[job_type] = {}
            if 'checkpoint_file' not in self.input_dict[job_type]:
                checkpoint_file = str(
                    f_path.with_suffix(f'.{abbrev[job_type]}.h5'))
                self.input_dict[job_type]['checkpoint_file'] = checkpoint_file

        # verify options for loprop
        verifyers = {
            'loprop': {
                'checkpoint_file': (lambda v: True, 'Always OK'),
                'localize':
                    (lambda v: v in ['charges'], 'localize: {} illegal value')
            }
        }

        if 'loprop' in self.input_dict:
            for option, value in self.input_dict['loprop'].items():
                verify, msg = verifyers['loprop'][option]
                if not verify(value):
                    raise InputError(msg.format(value))

    def get_dict(self):
        """
        Gets the input dictonary.

        :return:
            A dictionary containing all information form the input file.
        """

        return self.input_dict

    @staticmethod
    def parse_frequencies(input_frequencies):
        """
        Parses frequencies input for response solver.
        Input example: '0.0 - 0.2525 (0.0025), 0.5 - 1.0 (0.02), 2.0'

        :param input_frequencies:
            The string of input frequencies.
        """
        if isinstance(input_frequencies, list):
            return input_frequencies

        if isinstance(input_frequencies, np.ndarray):
            return input_frequencies.tolist()

        frequencies = []
        for w in input_frequencies.split(','):
            if '-' in w:
                m = re.search(r'^(.*)-(.*)\((.*)\)$', w)
                if m is None:
                    m = re.search(r'^(.*)-(.*)-(.*)$', w)

                assert_msg_critical(m is not None,
                                    'InputParser: failed to read frequencies')

                start, stop, step = (float(m.group(1)), float(m.group(2)),
                                     float(m.group(3)))
                stop += 0.01 * step

                frequencies += list(np.arange(start, stop, step))
            elif w:
                frequencies.append(float(w))
        return frequencies


class InputError(Exception):
    pass
