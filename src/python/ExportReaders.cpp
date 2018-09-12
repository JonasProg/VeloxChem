//
//                     V.E.L.O.X. C.H.E.M. MP
//      ---------------------------------------------------
//           An Electronic Structure Code for Nanoscale
//
//  Created by Zilvinas Rinkevicius (rinkevic@kth.se), KTH, Sweden.
//  Copyright © 2018 by Velox Chem MP developers. All rights reserved.

#include <boost/python.hpp>

#include "InputData.hpp"
#include "OutputStream.hpp"
#include "MolXYZReader.hpp"
#include "EnvironmentReader.hpp"
#include "BasisReader.hpp"
#include "Molecule.hpp"
#include "MolecularBasis.hpp"

namespace bp = boost::python;

// ==> boost python <==
// functions and classes

void export_readers()
{
    // CMolXYZReader class
    // Note: Need member function pointers for proper overloading

    void (CMolXYZReader::*parse_1)(      CMolecule&     molecule,
                                   const CInputData&    inputData,
                                         COutputStream& oStream)
        = &CMolXYZReader::parse;

    void (CMolXYZReader::*parse_2)(      CMolecule&     molecule,
                                   const CInputData&    inputData,
                                   const int32_t        iGroup,
                                         COutputStream& oStream)
        = &CMolXYZReader::parse;

    bp::class_< CMolXYZReader >
        (
            "CMolXYZReader",
            bp::init<>()
        )
        .def("parse", parse_1)
        .def("parse", parse_2)
        .def("get_state", &CMolXYZReader::getState)
    ;

    // CEnvironmentReader class

    bp::class_< CEnvironmentReader >
        (
            "CEnvironmentReader",
            bp::init<>()
        )
        .def("parse", &CEnvironmentReader::parse)
        .def("get_state", &CEnvironmentReader::getState)
        .def("get_path_to_basis_sets", &CEnvironmentReader::getPathToBasisSets)
    ;

    // CBasisReader class

    bp::class_< CBasisReader >
        (
            "CBasisReader",
            bp::init<>()
        )
        .def("parse", &CBasisReader::parse)
        .def("get_state", &CBasisReader::getState)
        .def("get_ao_basis", &CBasisReader::getAOBasis)
        .def("get_rij_basis", &CBasisReader::getRIJBasis)
        .def("get_min_basis", &CBasisReader::getMinBasis)
    ;
}
