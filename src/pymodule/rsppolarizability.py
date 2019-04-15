from .rspproperty import ResponseProperty


class Polarizability(ResponseProperty):
    """Polarizability class"""

    def __init__(self, rsp_dict):
        """Initializes polarizability"""

        rsp_input = dict(rsp_dict)

        rsp_input['property'] = 'polarizability'
        rsp_input['response'] = 'linear'
        rsp_input['residue'] = 'none'

        if 'operators' in rsp_dict:
            operators = rsp_dict['operators'].replace(' ', '')
            operators = operators.lower().split(',')
            rsp_input['operators'] = tuple(operators)
        else:
            rsp_input['operators'] = ('xyz', 'xyz')

        if 'frequencies' in rsp_dict:
            frequencies = rsp_dict['frequencies'].replace(' ', '')
            frequencies = frequencies.split(',')
            rsp_input['frequencies'] = tuple(map(float, frequencies))
        else:
            rsp_input['frequencies'] = (0,)

        super().__init__(rsp_input)

    def get_property(self, key):
        """Gets polarizability component"""

        # key example: ('x', 'y', 0.1)
        return self.rsp_property[key]

    def print_property(self, ostream):
        """Prints polarizability to output stream"""

        for w in self.rsp_input['frequencies']:
            w_str = 'Polarizability (w={})'.format(w)
            ostream.print_header(w_str.ljust(68))
            ostream.print_header(('-' * len(w_str)).ljust(68))
            for a in self.rsp_input['operators'][0]:
                for b in self.rsp_input['operators'][1]:
                    ops_label = '<<{};{}>>_{}'.format(a, b, w)
                    output_alpha = '{:<15s} {:15.8f}'.format(
                        ops_label, self.rsp_property[(a, b, w)])
                    ostream.print_header(output_alpha.ljust(68))
            ostream.print_blank()
