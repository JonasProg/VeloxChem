from os import environ
from pathlib import Path

from .errorhandler import assert_msg_critical
from .inputparser import InputParser
from .outputstream import OutputStream
from .veloxchemlib import AtomBasis
from .veloxchemlib import BasisFunction
from .veloxchemlib import MolecularBasis
from .veloxchemlib import tensor_order
from .veloxchemlib import chemical_element_name


def _known_aliases_for_basis_sets():
    """
    Maps from common basis name to basis filename.

    :return:
        A dictionary that maps from common basis name to basis filename.
    """

    return {
        '6-31G*': '6-31G_D_',
        '6-31G**': '6-31G_D,P_',
        '6-31+G*': '6-31+G_D_',
        '6-31+G**': '6-31+G_D,P_',
        '6-31++G*': '6-31++G_D_',
        '6-31++G**': '6-31++G_D,P_',
        '6-311G*': '6-311G_D_',
        '6-311G**': '6-311G_D,P_',
        '6-311+G*': '6-311+G_D_',
        '6-311+G**': '6-311+G_D,P_',
        '6-311++G*': '6-311++G_D_',
        '6-311++G**': '6-311++G_D,P_',
        '6-31G(2DF,P)': '6-31G_2DF,P_',
        '6-31G(3DF,3PD)': '6-31G_3DF,3PD_',
        '6-311G(2DF,2PD)': '6-311G_2DF,2PD_',
        '6-311+G(2D,P)': '6-311+G_2D,P_',
        '6-311++G(2D,2P)': '6-311++G_2D,2P_',
        '6-311++G(3DF,3PD)': '6-311++G_3DF,3PD_',
        'DEF2-SV(P)': 'DEF2-SV_P_',
    }


def _basis_name_to_file(name):
    """
    Determines basis set file name from common name.

    :param name:
        Common name of the basis set.

    :return:
        The file name of the basis set.
    """

    known_aliases = _known_aliases_for_basis_sets()

    if name in known_aliases:
        return known_aliases[name]
    else:
        return name


def _basis_file_to_name(fname):
    """
    Determines basis set common name from file name.

    :param fname:
        Name of the basis set file.

    :return:
        The common name of the basis set.
    """

    common_names = []

    for key, val in _known_aliases_for_basis_sets().items():
        if str(fname) == val and key not in common_names:
            common_names.append(key)

    if common_names:
        return sorted(common_names)[0]
    else:
        return str(fname)


def _read_atom_basis(basis_data, elem_id, basis_name):
    """
    Reads basis set data for single atom.

    :param basis_data:
        List with atomic basis data.
    :param elem_id:
        The chemical element identifier.
    :param basis_name:
        Name of the basis set.

    :return:
        The atom basis set.
    """

    atom_basis = AtomBasis()

    while basis_data:
        shell_title = basis_data.pop(0).split()
        assert_msg_critical(
            len(shell_title) == 2,
            'Basis set parser: {}'.format(' '.join(shell_title)),
        )

        if shell_title[0] == 'ECP':
            atom_basis.set_ecp_label(shell_title)
        else:
            angl = tensor_order(shell_title[0])
            npgto = int(shell_title[1])

            expons = [0.0] * npgto
            coeffs = [0.0] * npgto

            for i in range(npgto):
                prims = basis_data.pop(0).split()
                assert_msg_critical(
                    len(prims) == 2,
                    'Basis set parser: {}'.format(' '.join(prims)))

                expons[i] = float(prims[0])
                coeffs[i] = float(prims[1])

            bf = BasisFunction(expons, coeffs, angl)
            bf.normalize()

            atom_basis.add(bf)

    atom_basis.set_identifier(elem_id)
    atom_basis.set_name(basis_name.upper())

    return atom_basis


def _read_basis_file(basis_name, basis_path, ostream):
    """
    Reads basis set from given file.

    :param basis_name:
        Name of the basis set.
    :param basis_path:
        Path to the basis set.
    :param ostream:
        The output stream.

    :return:
        The dictionary with basis set.
    """

    # de-alias basis set name to basis set file
    fname = _basis_name_to_file(basis_name.upper())

    # searching order:
    # 1. given basis_path
    # 2. current directory
    # 3. VLXBASISPATH

    basis_file = Path(basis_path, fname)

    if not basis_file.is_file() and basis_path != '.':
        basis_file = Path('.', fname)

    if not basis_file.is_file() and 'VLXBASISPATH' in environ:
        basis_file = Path(environ['VLXBASISPATH'], fname)

    basis_info = 'Reading basis set from file: ' + str(basis_file)
    ostream.print_info(basis_info)
    ostream.print_blank()

    basis_dict = InputParser(str(basis_file)).input_dict

    assert_msg_critical(
        fname.upper() == basis_dict['basis_set_name'].upper(),
        '_read_basis_file: Inconsistent basis set name',
    )

    return basis_dict


def _gen_basis_key(elem_id, basis_dict):
    """
    Generates basis set key for given chemical element.

    :param elem_id:
        The chemical element identifier.
    :param basis_dict:
        The basis set dictionary.

    :return:
        The basis set key.
    """

    basis_key = 'atombasis_{}'.format(chemical_element_name(elem_id).lower())
    assert_msg_critical(
        basis_key in basis_dict,
        ('MolecularBasis.read: Unsupported chemical element {chemical_element_name(elem_id)}'
         + ' in {basis_set_name}.'),
    )

    return basis_key


@staticmethod
def _MolecularBasis_read(molecule,
                         basis_name,
                         basis_path='.',
                         ostream=OutputStream()):
    """
    Reads AO basis set from file for given molecule.

    :param molecule:
        The molecule.
    :param basis_name:
        Name of the basis set.
    :param basis_path:
        Path to the basis set.
    :param ostream:
        The output stream.

    :return:
        The molecular basis set.
    """

    if ostream is None:
        ostream = OutputStream(None)

    basis_dict = _read_basis_file(basis_name, basis_path, ostream)

    mol_basis = MolecularBasis()

    for elem_id in molecule.get_identifiers():
        basis_key = _gen_basis_key(elem_id, basis_dict)
        atom_basis = _read_atom_basis(basis_dict[basis_key], elem_id,
                                      basis_name)
        mol_basis.add(atom_basis)

    ostream.print_block(mol_basis.info_str('Atomic Basis'))
    ostream.flush()

    return mol_basis


@staticmethod
def _MolecularBasis_read_dict(molecule,
                              basis_name,
                              basis_dict,
                              basis_path='.',
                              ostream=OutputStream()):
    """
    Reads AO basis set from file for given molecule.

    :param molecule:
        The molecule.
    :param basis_name:
        Name of the basis set.
    :param basis_dict:
        Dictionary with additional basis set input.
    :param basis_path:
        Path to the basis set.
    :param ostream:
        The output stream.

    :return:
        The molecular basis set.
    """

    if ostream is None:
        ostream = OutputStream(None)

    mbasis_dict = _read_basis_file(basis_name, basis_path, ostream)

    mol_basis = MolecularBasis()

    for index, elem_id in enumerate(molecule.get_identifiers()):
        idxstr = str(index + 1)
        if idxstr in basis_dict:
            lbasis_name = basis_dict[idxstr]
            lbasis_dict = _read_basis_file(lbasis_name, basis_path, ostream)
            basis_key = _gen_basis_key(elem_id, lbasis_dict)
            atom_basis = _read_atom_basis(lbasis_dict[basis_key], elem_id,
                                          lbasis_name)
            mol_basis.add(atom_basis)
        else:
            basis_key = _gen_basis_key(elem_id, mbasis_dict)
            atom_basis = _read_atom_basis(mbasis_dict[basis_key], elem_id,
                                          basis_name)
            mol_basis.add(atom_basis)

    ostream.print_block(mol_basis.info_str('Atomic Basis'))
    ostream.flush()

    return mol_basis


@staticmethod
def _MolecularBasis_get_avail_basis(element_label):
    """
    Gets the names of available basis sets for an element.

    :param element_label:
        The label of the chemical element.

    :return:
        The tuple of basis sets.
    """

    avail_basis = set()

    basis_path = Path(environ['VLXBASISPATH'])
    basis_files = sorted((x for x in basis_path.iterdir() if x.is_file()))

    for x in basis_files:
        name = _basis_file_to_name(x.name)
        basis = InputParser(str(x)).input_dict
        # check that the given element appears as key
        # and that its value is a non-empty list
        elem = f'atombasis_{element_label.lower()}'
        if elem in basis.keys():
            if basis[elem]:
                avail_basis.add(name)

    return sorted(list(avail_basis))


def _MolecularBasis_get_string(self, title):
    """
    Returns string representation of molecular basis.

    :param title:
        The title of molecular basis.

    :return:
        A string with representation of molecular basis.
    """

    mlabel = self.get_main_basis_label()

    label = 'Molecular Basis (' + title + ')'
    bas_str = f'{label:^60s}\n'
    label = (len(label) + 2) * "="
    bas_str += f'{label:^60s}\n\n'
    label = "Basis: " + mlabel
    bas_str += f'{label:<60s}\n\n'
    label = 'Contracted GTOs'
    bas_str += "  Atom " + f'{label:<26}'
    label = 'Primitive GTOs'
    bas_str += f'{label:<30}\n\n'

    for abasis in self.basis_sets():
        if abasis.get_name() == mlabel:
            id_elem = abasis.get_identifier()
            bas_str += f'  {chemical_element_name(id_elem):<6s}{abasis.contraction_str():<26s}'
            bas_str += f'{abasis.primitives_str():<30s}\n'
    bas_str += '\n'

    for abasis in self.basis_sets():
        if abasis.get_name() != mlabel:
            label = "Replacement Basis: " + abasis.get_name()
            bas_str += f'{label:<60s}\n\n'
            label = 'Contracted GTOs'
            bas_str += "  Atom " + f'{label:<26}'
            label = 'Primitive GTOs'
            bas_str += f'{label:<30}\n\n'
            id_elem = abasis.get_identifier()
            bas_str += f'  {chemical_element_name(id_elem):<6s}{abasis.contraction_str():<26s}'
            bas_str += f'{abasis.primitives_str():<30s}\n'

    bas_str += '\n'
    label = 'Contracted Basis Functions : ' + f'{self.get_dimensions_of_basis()}'
    bas_str += f'{label:<60s}\n'
    label = 'Primitive Basis Functions  : ' + f'{self.get_dimensions_of_primitive_basis()}'
    bas_str += f'{label:<60s}\n\n'

    return bas_str


MolecularBasis.read = _MolecularBasis_read
MolecularBasis.read_dict = _MolecularBasis_read_dict
MolecularBasis.get_avail_basis = _MolecularBasis_get_avail_basis
MolecularBasis.info_str = _MolecularBasis_get_string
