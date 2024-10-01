#
#                           VELOXCHEM 1.0-RC3
#         ----------------------------------------------------
#                     An Electronic Structure Code
#
#  Copyright © 2018-2022 by VeloxChem developers. All rights reserved.
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


def get_uff_parameters():
    """
    Initialize UFF parameters.

    :return:
        A dictionary containing UFF parameters.
    """

    uff_parameters = {
        'hx': {
            'sigma': 0.2886,
            'epsilon': 0.1839
        },
        'cx': {
            'sigma': 0.3851,
            'epsilon': 0.4389
        },
        'nx': {
            'sigma': 0.3662,
            'epsilon': 0.3219
        },
        'ox': {
            'sigma': 0.3405,
            'epsilon': 0.4013
        },
        'px': {
            'sigma': 0.415,
            'epsilon': 0.1338
        },
        'sx': {
            'sigma': 0.403,
            'epsilon': 0.1437
        },
        'He': {
            'sigma': 0.2104,
            'epsilon': 0.2343
        },
        'Li': {
            'sigma': 0.2184,
            'epsilon': 0.1046
        },
        'Be': {
            'sigma': 0.2446,
            'epsilon': 0.3556
        },
        'B': {
            'sigma': 0.3638,
            'epsilon': 0.7531
        },
        'F': {
            'sigma': 0.2997,
            'epsilon': 0.2092
        },
        'Na': {
            'sigma': 0.2658,
            'epsilon': 0.1255
        },
        'Mg': {
            'sigma': 0.2691,
            'epsilon': 0.4644
        },
        'Al': {
            'sigma': 0.4008,
            'epsilon': 2.1128
        },
        'Si': {
            'sigma': 0.3826,
            'epsilon': 1.6819
        },
        'Cl': {
            'sigma': 0.3516,
            'epsilon': 0.9497
        },
        'Ar': {
            'sigma': 0.3446,
            'epsilon': 0.774
        },
        'K': {
            'sigma': 0.3396,
            'epsilon': 0.1464
        },
        'Ca': {
            'sigma': 0.3028,
            'epsilon': 0.9957
        },
        'Sc': {
            'sigma': 0.2936,
            'epsilon': 0.0795
        },
        'Ti': {
            'sigma': 0.2829,
            'epsilon': 0.0711
        },
        'V': {
            'sigma': 0.2801,
            'epsilon': 0.0669
        },
        'Cr': {
            'sigma': 0.2693,
            'epsilon': 0.0628
        },
        'Mn': {
            'sigma': 0.2638,
            'epsilon': 0.0544
        },
        'Fe': {
            'sigma': 0.2594,
            'epsilon': 0.0544
        },
        'Co': {
            'sigma': 0.2559,
            'epsilon': 0.0586
        },
        'Ni': {
            'sigma': 0.2525,
            'epsilon': 0.0628
        },
        'Cu': {
            'sigma': 0.3114,
            'epsilon': 0.0209
        },
        'Zn': {
            'sigma': 0.2462,
            'epsilon': 0.5188
        },
        'Ga': {
            'sigma': 0.3905,
            'epsilon': 1.7363
        },
        'Ge': {
            'sigma': 0.3813,
            'epsilon': 1.5856
        },
        'As': {
            'sigma': 0.3769,
            'epsilon': 1.2928
        },
        'Se': {
            'sigma': 0.3746,
            'epsilon': 1.2175
        },
        'Br': {
            'sigma': 0.3732,
            'epsilon': 1.0501
        },
        'Kr': {
            'sigma': 0.3689,
            'epsilon': 0.9204
        },
        'Rb': {
            'sigma': 0.3665,
            'epsilon': 0.1674
        },
        'Sr': {
            'sigma': 0.3244,
            'epsilon': 0.9832
        },
        'Y': {
            'sigma': 0.298,
            'epsilon': 0.3012
        },
        'Zr': {
            'sigma': 0.2783,
            'epsilon': 0.2887
        },
        'Nb': {
            'sigma': 0.282,
            'epsilon': 0.2468
        },
        'Mo': {
            'sigma': 0.2719,
            'epsilon': 0.2343
        },
        'Tc': {
            'sigma': 0.2671,
            'epsilon': 0.2008
        },
        'Ru': {
            'sigma': 0.264,
            'epsilon': 0.2343
        },
        'Rh': {
            'sigma': 0.2609,
            'epsilon': 0.2217
        },
        'Pd': {
            'sigma': 0.2583,
            'epsilon': 0.2008
        },
        'Ag': {
            'sigma': 0.2805,
            'epsilon': 0.1506
        },
        'Cd': {
            'sigma': 0.2537,
            'epsilon': 0.9539
        },
        'In': {
            'sigma': 0.3976,
            'epsilon': 2.5061
        },
        'Sn': {
            'sigma': 0.3913,
            'epsilon': 2.3722
        },
        'Sb': {
            'sigma': 0.3938,
            'epsilon': 1.8785
        },
        'Te': {
            'sigma': 0.3982,
            'epsilon': 1.6651
        },
        'I': {
            'sigma': 0.4009,
            'epsilon': 1.4183
        },
        'Xe': {
            'sigma': 0.3924,
            'epsilon': 1.389
        },
        'Cs': {
            'sigma': 0.4024,
            'epsilon': 0.1883
        },
        'Ba': {
            'sigma': 0.3299,
            'epsilon': 1.5229
        },
        'La': {
            'sigma': 0.3138,
            'epsilon': 0.0711
        },
        'Ce': {
            'sigma': 0.3168,
            'epsilon': 0.0544
        },
        'Pr': {
            'sigma': 0.3213,
            'epsilon': 0.0418
        },
        'Nd': {
            'sigma': 0.3185,
            'epsilon': 0.0418
        },
        'Pm': {
            'sigma': 0.316,
            'epsilon': 0.0377
        },
        'Sm': {
            'sigma': 0.3136,
            'epsilon': 0.0335
        },
        'Eu': {
            'sigma': 0.3112,
            'epsilon': 0.0335
        },
        'Gd': {
            'sigma': 0.3001,
            'epsilon': 0.0377
        },
        'Tb': {
            'sigma': 0.3074,
            'epsilon': 0.0293
        },
        'Dy': {
            'sigma': 0.3054,
            'epsilon': 0.0293
        },
        'Ho': {
            'sigma': 0.3037,
            'epsilon': 0.0293
        },
        'Er': {
            'sigma': 0.3021,
            'epsilon': 0.0293
        },
        'Tm': {
            'sigma': 0.3006,
            'epsilon': 0.0251
        },
        'Yb': {
            'sigma': 0.2989,
            'epsilon': 0.9539
        },
        'Lu': {
            'sigma': 0.3243,
            'epsilon': 0.1715
        },
        'Hf': {
            'sigma': 0.2798,
            'epsilon': 0.3012
        },
        'Ta': {
            'sigma': 0.2824,
            'epsilon': 0.3389
        },
        'W': {
            'sigma': 0.2734,
            'epsilon': 0.2803
        },
        'Re': {
            'sigma': 0.2632,
            'epsilon': 0.2761
        },
        'Os': {
            'sigma': 0.278,
            'epsilon': 0.1548
        },
        'Ir': {
            'sigma': 0.253,
            'epsilon': 0.3054
        },
        'Pt': {
            'sigma': 0.2454,
            'epsilon': 0.3347
        },
        'Au': {
            'sigma': 0.2934,
            'epsilon': 0.1632
        },
        'Hg': {
            'sigma': 0.241,
            'epsilon': 1.6108
        },
        'Tl': {
            'sigma': 0.3873,
            'epsilon': 2.845
        },
        'Pb': {
            'sigma': 0.3828,
            'epsilon': 2.7738
        },
        'Bi': {
            'sigma': 0.3893,
            'epsilon': 2.1672
        },
        'Po': {
            'sigma': 0.4195,
            'epsilon': 1.3597
        },
        'At': {
            'sigma': 0.4232,
            'epsilon': 1.1882
        },
        'Rn': {
            'sigma': 0.4245,
            'epsilon': 1.0376
        },
        'Fr': {
            'sigma': 0.4365,
            'epsilon': 0.2092
        },
        'Ra': {
            'sigma': 0.3276,
            'epsilon': 1.6902
        },
        'Ac': {
            'sigma': 0.3099,
            'epsilon': 0.1381
        },
        'Th': {
            'sigma': 0.3025,
            'epsilon': 0.1088
        },
        'Pa': {
            'sigma': 0.305,
            'epsilon': 0.092
        },
        'U': {
            'sigma': 0.3025,
            'epsilon': 0.092
        },
        'Np': {
            'sigma': 0.305,
            'epsilon': 0.0795
        },
        'Pu': {
            'sigma': 0.305,
            'epsilon': 0.0669
        },
        'Am': {
            'sigma': 0.3012,
            'epsilon': 0.0586
        },
        'Cm': {
            'sigma': 0.2963,
            'epsilon': 0.0544
        },
        'Bk': {
            'sigma': 0.2975,
            'epsilon': 0.0544
        },
        'Cf': {
            'sigma': 0.2952,
            'epsilon': 0.0544
        },
        'Es': {
            'sigma': 0.2939,
            'epsilon': 0.0502
        },
        'Fm': {
            'sigma': 0.2927,
            'epsilon': 0.0502
        },
        'Md': {
            'sigma': 0.2917,
            'epsilon': 0.046
        },
        'No': {
            'sigma': 0.2894,
            'epsilon': 0.046
        },
        'Lw': {
            'sigma': 0.2883,
            'epsilon': 0.046
        },
    }

    return uff_parameters
