from .rspproperty import ResponseProperty
from .inputparser import parse_frequencies


class Polarizability(ResponseProperty):
    """Polarizability class"""

    def __init__(self, rsp_dict):
        """Initializes polarizability"""

        rsp_input = dict(rsp_dict)

        rsp_input['property'] = 'polarizability'
        rsp_input['response'] = 'linear'
        rsp_input['residue'] = 'none'

        rsp_input['a_operator'] = 'dipole'
        rsp_input['a_components'] = 'xyz'

        rsp_input['b_operator'] = 'dipole'
        rsp_input['b_components'] = 'xyz'

        if 'frequencies' not in rsp_dict:
            rsp_input['frequencies'] = '0'

        super().__init__(rsp_input)

    def get_property(self, key):
        """Gets polarizability component"""

        # key example: ('x', 'y', 0.1)
        return self.rsp_property[key]

    def print_property(self, ostream):
        """Prints polarizability to output stream"""

        for w in parse_frequencies(self.rsp_input['frequencies']):
            w_str = 'Polarizability (w={:.4f})'.format(w)
            ostream.print_header(w_str.ljust(68))
            ostream.print_header(('-' * len(w_str)).ljust(68))
            for a in self.rsp_input['a_components']:
                for b in self.rsp_input['b_components']:
                    ops_label = '<<{};{}>>_{:.4f}'.format(a, b, w)
                    output_alpha = '{:<15s} {:15.8f}'.format(
                        ops_label, self.rsp_property[(a, b, w)])
                    ostream.print_header(output_alpha.ljust(68))
            ostream.print_blank()
