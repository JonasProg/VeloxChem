import numpy as np

from veloxchem.veloxchemlib import XCNewIntegrator


class TestLibxcRhoB:

    def check_term(self, tol, label, val, val_fd):

        if abs(val_fd) < tol:
            assert abs(val - val_fd) < tol
        else:
            assert abs(val - val_fd) / abs(val_fd) < tol

    def run_rho_b_fd(self, xcfun_label, tol):

        delta_h = 1.0e-6

        xc_drv = XCNewIntegrator()

        rho_a, rho_b = 0.17, 0.15
        nabla_a, nabla_b = 0.26, 0.29
        sigma_aa = nabla_a * nabla_a
        sigma_ab = nabla_a * nabla_b
        sigma_bb = nabla_b * nabla_b
        lapl_a, lapl_b = 0.1, 0.11
        tau_a, tau_b = 0.12, 0.125

        inp = {
            'rho': np.array([rho_a, rho_b]),
            'sigma': np.array([sigma_aa, sigma_ab, sigma_bb]),
            'lapl': np.array([lapl_a, lapl_b]),
            'tau': np.array([tau_a, tau_b]),
        }

        lxc = xc_drv.compute_lxc_for_mgga(xcfun_label, inp['rho'], inp['sigma'],
                                          inp['lapl'], inp['tau'])
        kxc = xc_drv.compute_kxc_for_mgga(xcfun_label, inp['rho'], inp['sigma'],
                                          inp['lapl'], inp['tau'])
        fxc = xc_drv.compute_fxc_for_mgga(xcfun_label, inp['rho'], inp['sigma'],
                                          inp['lapl'], inp['tau'])
        vxc = xc_drv.compute_exc_vxc_for_mgga(xcfun_label, inp['rho'],
                                              inp['sigma'], inp['lapl'],
                                              inp['tau'])

        inp_plus = dict(inp)
        inp_plus['rho'][1] = rho_b + delta_h

        kxc_plus = xc_drv.compute_kxc_for_mgga(xcfun_label, inp_plus['rho'],
                                               inp_plus['sigma'],
                                               inp_plus['lapl'],
                                               inp_plus['tau'])
        fxc_plus = xc_drv.compute_fxc_for_mgga(xcfun_label, inp_plus['rho'],
                                               inp_plus['sigma'],
                                               inp_plus['lapl'],
                                               inp_plus['tau'])
        vxc_plus = xc_drv.compute_exc_vxc_for_mgga(xcfun_label, inp_plus['rho'],
                                                   inp_plus['sigma'],
                                                   inp_plus['lapl'],
                                                   inp_plus['tau'])
        exc_plus = {'zk': vxc_plus['exc']}

        inp_minus = dict(inp)
        inp_minus['rho'][1] = rho_b - delta_h

        kxc_minus = xc_drv.compute_kxc_for_mgga(xcfun_label, inp_minus['rho'],
                                                inp_minus['sigma'],
                                                inp_minus['lapl'],
                                                inp_minus['tau'])
        fxc_minus = xc_drv.compute_fxc_for_mgga(xcfun_label, inp_minus['rho'],
                                                inp_minus['sigma'],
                                                inp_minus['lapl'],
                                                inp_minus['tau'])
        vxc_minus = xc_drv.compute_exc_vxc_for_mgga(xcfun_label,
                                                    inp_minus['rho'],
                                                    inp_minus['sigma'],
                                                    inp_minus['lapl'],
                                                    inp_minus['tau'])
        exc_minus = {'zk': vxc_minus['exc']}

        vrho_b = vxc['vrho'][0][1]
        e_a_plus = exc_plus['zk'][0][0] * (rho_a + rho_b + delta_h)
        e_a_minus = exc_minus['zk'][0][0] * (rho_a + rho_b - delta_h)
        vrho_b_fd = (e_a_plus - e_a_minus) / (delta_h * 2)
        self.check_term(tol, 'vrho_b', vrho_b, vrho_b_fd)

        v2rho2_bb = fxc["v2rho2"][0][2]
        vrho_b_plus = vxc_plus["vrho"][0][1]
        vrho_b_minus = vxc_minus["vrho"][0][1]
        v2rho2_bb_fd = (vrho_b_plus - vrho_b_minus) / (delta_h * 2)
        self.check_term(tol, "v2rho2_bb", v2rho2_bb, v2rho2_bb_fd)

        v2rhosigma_ba = fxc["v2rhosigma"][0][3]
        vsigma_a_plus = vxc_plus["vsigma"][0][0]
        vsigma_a_minus = vxc_minus["vsigma"][0][0]
        v2rhosigma_ba_fd = (vsigma_a_plus - vsigma_a_minus) / (delta_h * 2)
        self.check_term(tol, "v2rhosigma_ba", v2rhosigma_ba, v2rhosigma_ba_fd)

        v2rhosigma_bc = fxc["v2rhosigma"][0][4]
        vsigma_c_plus = vxc_plus["vsigma"][0][1]
        vsigma_c_minus = vxc_minus["vsigma"][0][1]
        v2rhosigma_bc_fd = (vsigma_c_plus - vsigma_c_minus) / (delta_h * 2)
        self.check_term(tol, "v2rhosigma_bc", v2rhosigma_bc, v2rhosigma_bc_fd)

        v2rhosigma_bb = fxc["v2rhosigma"][0][5]
        vsigma_b_plus = vxc_plus["vsigma"][0][2]
        vsigma_b_minus = vxc_minus["vsigma"][0][2]
        v2rhosigma_bb_fd = (vsigma_b_plus - vsigma_b_minus) / (delta_h * 2)
        self.check_term(tol, "v2rhosigma_bb", v2rhosigma_bb, v2rhosigma_bb_fd)

        v2rhotau_ba = fxc["v2rhotau"][0][2]
        vtau_a_plus = vxc_plus["vtau"][0][0]
        vtau_a_minus = vxc_minus["vtau"][0][0]
        v2rhotau_ba_fd = (vtau_a_plus - vtau_a_minus) / (delta_h * 2)
        self.check_term(tol, "v2rhotau_ba", v2rhotau_ba, v2rhotau_ba_fd)

        v2rhotau_bb = fxc["v2rhotau"][0][3]
        vtau_b_plus = vxc_plus["vtau"][0][1]
        vtau_b_minus = vxc_minus["vtau"][0][1]
        v2rhotau_bb_fd = (vtau_b_plus - vtau_b_minus) / (delta_h * 2)
        self.check_term(tol, "v2rhotau_bb", v2rhotau_bb, v2rhotau_bb_fd)

        v3rho3_bbb = kxc["v3rho3"][0][3]
        v2rho2_bb_plus = fxc_plus["v2rho2"][0][2]
        v2rho2_bb_minus = fxc_minus["v2rho2"][0][2]
        v3rho3_bbb_fd = (v2rho2_bb_plus - v2rho2_bb_minus) / (delta_h * 2)
        self.check_term(tol, "v3rho3_bbb", v3rho3_bbb, v3rho3_bbb_fd)

        v3rho2sigma_bba = kxc["v3rho2sigma"][0][6]
        v2rhosigma_ba_plus = fxc_plus["v2rhosigma"][0][3]
        v2rhosigma_ba_minus = fxc_minus["v2rhosigma"][0][3]
        v3rho2sigma_bba_fd = (v2rhosigma_ba_plus -
                              v2rhosigma_ba_minus) / (delta_h * 2)
        self.check_term(tol, "v3rho2sigma_bba", v3rho2sigma_bba,
                        v3rho2sigma_bba_fd)

        v3rho2sigma_bbc = kxc["v3rho2sigma"][0][7]
        v2rhosigma_bc_plus = fxc_plus["v2rhosigma"][0][4]
        v2rhosigma_bc_minus = fxc_minus["v2rhosigma"][0][4]
        v3rho2sigma_bbc_fd = (v2rhosigma_bc_plus -
                              v2rhosigma_bc_minus) / (delta_h * 2)
        self.check_term(tol, "v3rho2sigma_bbc", v3rho2sigma_bbc,
                        v3rho2sigma_bbc_fd)

        v3rho2sigma_bbb = kxc["v3rho2sigma"][0][8]
        v2rhosigma_bb_plus = fxc_plus["v2rhosigma"][0][5]
        v2rhosigma_bb_minus = fxc_minus["v2rhosigma"][0][5]
        v3rho2sigma_bbb_fd = (v2rhosigma_bb_plus -
                              v2rhosigma_bb_minus) / (delta_h * 2)
        self.check_term(tol, "v3rho2sigma_bbb", v3rho2sigma_bbb,
                        v3rho2sigma_bbb_fd)

        v3rho2tau_bba = kxc["v3rho2tau"][0][4]
        v2rhotau_ba_plus = fxc_plus["v2rhotau"][0][2]
        v2rhotau_ba_minus = fxc_minus["v2rhotau"][0][2]
        v3rho2tau_bba_fd = (v2rhotau_ba_plus - v2rhotau_ba_minus) / (delta_h *
                                                                     2)
        self.check_term(tol, "v3rho2tau_bba", v3rho2tau_bba, v3rho2tau_bba_fd)

        v3rho2tau_bbb = kxc["v3rho2tau"][0][5]
        v2rhotau_bb_plus = fxc_plus["v2rhotau"][0][3]
        v2rhotau_bb_minus = fxc_minus["v2rhotau"][0][3]
        v3rho2tau_bbb_fd = (v2rhotau_bb_plus - v2rhotau_bb_minus) / (delta_h *
                                                                     2)
        self.check_term(tol, "v3rho2tau_bbb", v3rho2tau_bbb, v3rho2tau_bbb_fd)

        v3rhosigma2_baa = kxc["v3rhosigma2"][0][6]
        v2sigma2_aa_plus = fxc_plus["v2sigma2"][0][0]
        v2sigma2_aa_minus = fxc_minus["v2sigma2"][0][0]
        v3rhosigma2_baa_fd = (v2sigma2_aa_plus - v2sigma2_aa_minus) / (delta_h *
                                                                       2)
        self.check_term(tol, "v3rhosigma2_baa", v3rhosigma2_baa,
                        v3rhosigma2_baa_fd)

        v3rhosigma2_bac = kxc["v3rhosigma2"][0][7]
        v2sigma2_ac_plus = fxc_plus["v2sigma2"][0][1]
        v2sigma2_ac_minus = fxc_minus["v2sigma2"][0][1]
        v3rhosigma2_bac_fd = (v2sigma2_ac_plus - v2sigma2_ac_minus) / (delta_h *
                                                                       2)
        self.check_term(tol, "v3rhosigma2_bac", v3rhosigma2_bac,
                        v3rhosigma2_bac_fd)

        v3rhosigma2_bab = kxc["v3rhosigma2"][0][8]
        v2sigma2_ab_plus = fxc_plus["v2sigma2"][0][2]
        v2sigma2_ab_minus = fxc_minus["v2sigma2"][0][2]
        v3rhosigma2_bab_fd = (v2sigma2_ab_plus - v2sigma2_ab_minus) / (delta_h *
                                                                       2)
        self.check_term(tol, "v3rhosigma2_bab", v3rhosigma2_bab,
                        v3rhosigma2_bab_fd)

        v3rhosigma2_bcc = kxc["v3rhosigma2"][0][9]
        v2sigma2_cc_plus = fxc_plus["v2sigma2"][0][3]
        v2sigma2_cc_minus = fxc_minus["v2sigma2"][0][3]
        v3rhosigma2_bcc_fd = (v2sigma2_cc_plus - v2sigma2_cc_minus) / (delta_h *
                                                                       2)
        self.check_term(tol, "v3rhosigma2_bcc", v3rhosigma2_bcc,
                        v3rhosigma2_bcc_fd)

        v3rhosigma2_bcb = kxc["v3rhosigma2"][0][10]
        v2sigma2_cb_plus = fxc_plus["v2sigma2"][0][4]
        v2sigma2_cb_minus = fxc_minus["v2sigma2"][0][4]
        v3rhosigma2_bcb_fd = (v2sigma2_cb_plus - v2sigma2_cb_minus) / (delta_h *
                                                                       2)
        self.check_term(tol, "v3rhosigma2_bcb", v3rhosigma2_bcb,
                        v3rhosigma2_bcb_fd)

        v3rhosigma2_bbb = kxc["v3rhosigma2"][0][11]
        v2sigma2_bb_plus = fxc_plus["v2sigma2"][0][5]
        v2sigma2_bb_minus = fxc_minus["v2sigma2"][0][5]
        v3rhosigma2_bbb_fd = (v2sigma2_bb_plus - v2sigma2_bb_minus) / (delta_h *
                                                                       2)
        self.check_term(tol, "v3rhosigma2_bbb", v3rhosigma2_bbb,
                        v3rhosigma2_bbb_fd)

        v3rhosigmatau_baa = kxc["v3rhosigmatau"][0][6]
        v2sigmatau_aa_plus = fxc_plus["v2sigmatau"][0][0]
        v2sigmatau_aa_minus = fxc_minus["v2sigmatau"][0][0]
        v3rhosigmatau_baa_fd = (v2sigmatau_aa_plus -
                                v2sigmatau_aa_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhosigmatau_baa", v3rhosigmatau_baa,
                        v3rhosigmatau_baa_fd)

        v3rhosigmatau_bab = kxc["v3rhosigmatau"][0][7]
        v2sigmatau_ab_plus = fxc_plus["v2sigmatau"][0][1]
        v2sigmatau_ab_minus = fxc_minus["v2sigmatau"][0][1]
        v3rhosigmatau_bab_fd = (v2sigmatau_ab_plus -
                                v2sigmatau_ab_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhosigmatau_bab", v3rhosigmatau_bab,
                        v3rhosigmatau_bab_fd)

        v3rhosigmatau_bca = kxc["v3rhosigmatau"][0][8]
        v2sigmatau_ca_plus = fxc_plus["v2sigmatau"][0][2]
        v2sigmatau_ca_minus = fxc_minus["v2sigmatau"][0][2]
        v3rhosigmatau_bca_fd = (v2sigmatau_ca_plus -
                                v2sigmatau_ca_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhosigmatau_bca", v3rhosigmatau_bca,
                        v3rhosigmatau_bca_fd)

        v3rhosigmatau_bcb = kxc["v3rhosigmatau"][0][9]
        v2sigmatau_cb_plus = fxc_plus["v2sigmatau"][0][3]
        v2sigmatau_cb_minus = fxc_minus["v2sigmatau"][0][3]
        v3rhosigmatau_bcb_fd = (v2sigmatau_cb_plus -
                                v2sigmatau_cb_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhosigmatau_bcb", v3rhosigmatau_bcb,
                        v3rhosigmatau_bcb_fd)

        v3rhosigmatau_bba = kxc["v3rhosigmatau"][0][10]
        v2sigmatau_ba_plus = fxc_plus["v2sigmatau"][0][4]
        v2sigmatau_ba_minus = fxc_minus["v2sigmatau"][0][4]
        v3rhosigmatau_bba_fd = (v2sigmatau_ba_plus -
                                v2sigmatau_ba_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhosigmatau_bba", v3rhosigmatau_bba,
                        v3rhosigmatau_bba_fd)

        v3rhosigmatau_bbb = kxc["v3rhosigmatau"][0][11]
        v2sigmatau_bb_plus = fxc_plus["v2sigmatau"][0][5]
        v2sigmatau_bb_minus = fxc_minus["v2sigmatau"][0][5]
        v3rhosigmatau_bbb_fd = (v2sigmatau_bb_plus -
                                v2sigmatau_bb_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhosigmatau_bbb", v3rhosigmatau_bbb,
                        v3rhosigmatau_bbb_fd)

        v3rhotau2_baa = kxc["v3rhotau2"][0][3]
        v2tau2_aa_plus = fxc_plus["v2tau2"][0][0]
        v2tau2_aa_minus = fxc_minus["v2tau2"][0][0]
        v3rhotau2_baa_fd = (v2tau2_aa_plus - v2tau2_aa_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhotau2_baa", v3rhotau2_baa, v3rhotau2_baa_fd)

        v3rhotau2_bab = kxc["v3rhotau2"][0][4]
        v2tau2_ab_plus = fxc_plus["v2tau2"][0][1]
        v2tau2_ab_minus = fxc_minus["v2tau2"][0][1]
        v3rhotau2_bab_fd = (v2tau2_ab_plus - v2tau2_ab_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhotau2_bab", v3rhotau2_bab, v3rhotau2_bab_fd)

        v3rhotau2_bbb = kxc["v3rhotau2"][0][5]
        v2tau2_bb_plus = fxc_plus["v2tau2"][0][2]
        v2tau2_bb_minus = fxc_minus["v2tau2"][0][2]
        v3rhotau2_bbb_fd = (v2tau2_bb_plus - v2tau2_bb_minus) / (delta_h * 2)
        self.check_term(tol, "v3rhotau2_bbb", v3rhotau2_bbb, v3rhotau2_bbb_fd)

        v4rho4_bbbb = lxc["v4rho4"][0][4]
        v3rho3_bbb_plus = kxc_plus["v3rho3"][0][3]
        v3rho3_bbb_minus = kxc_minus["v3rho3"][0][3]
        v4rho4_bbbb_fd = (v3rho3_bbb_plus - v3rho3_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho4_bbbb", v4rho4_bbbb, v4rho4_bbbb_fd)

        v4rho3sigma_bbba = lxc["v4rho3sigma"][0][9]
        v3rho2sigma_bba_plus = kxc_plus["v3rho2sigma"][0][6]
        v3rho2sigma_bba_minus = kxc_minus["v3rho2sigma"][0][6]
        v4rho3sigma_bbba_fd = (v3rho2sigma_bba_plus -
                               v3rho2sigma_bba_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho3sigma_bbba", v4rho3sigma_bbba,
                        v4rho3sigma_bbba_fd)

        v4rho3sigma_bbbc = lxc["v4rho3sigma"][0][10]
        v3rho2sigma_bbc_plus = kxc_plus["v3rho2sigma"][0][7]
        v3rho2sigma_bbc_minus = kxc_minus["v3rho2sigma"][0][7]
        v4rho3sigma_bbbc_fd = (v3rho2sigma_bbc_plus -
                               v3rho2sigma_bbc_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho3sigma_bbbc", v4rho3sigma_bbbc,
                        v4rho3sigma_bbbc_fd)

        v4rho3sigma_bbbb = lxc["v4rho3sigma"][0][11]
        v3rho2sigma_bbb_plus = kxc_plus["v3rho2sigma"][0][8]
        v3rho2sigma_bbb_minus = kxc_minus["v3rho2sigma"][0][8]
        v4rho3sigma_bbbb_fd = (v3rho2sigma_bbb_plus -
                               v3rho2sigma_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho3sigma_bbbb", v4rho3sigma_bbbb,
                        v4rho3sigma_bbbb_fd)

        v4rho3tau_bbba = lxc["v4rho3tau"][0][6]
        v3rho2tau_bba_plus = kxc_plus["v3rho2tau"][0][4]
        v3rho2tau_bba_minus = kxc_minus["v3rho2tau"][0][4]
        v4rho3tau_bbba_fd = (v3rho2tau_bba_plus -
                             v3rho2tau_bba_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho3tau_bbba", v4rho3tau_bbba,
                        v4rho3tau_bbba_fd)

        v4rho3tau_bbbb = lxc["v4rho3tau"][0][7]
        v3rho2tau_bbb_plus = kxc_plus["v3rho2tau"][0][5]
        v3rho2tau_bbb_minus = kxc_minus["v3rho2tau"][0][5]
        v4rho3tau_bbbb_fd = (v3rho2tau_bbb_plus -
                             v3rho2tau_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho3tau_bbbb", v4rho3tau_bbbb,
                        v4rho3tau_bbbb_fd)

        v4rho2sigma2_bbaa = lxc["v4rho2sigma2"][0][12]
        v3rhosigma2_baa_plus = kxc_plus["v3rhosigma2"][0][6]
        v3rhosigma2_baa_minus = kxc_minus["v3rhosigma2"][0][6]
        v4rho2sigma2_bbaa_fd = (v3rhosigma2_baa_plus -
                                v3rhosigma2_baa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigma2_bbaa", v4rho2sigma2_bbaa,
                        v4rho2sigma2_bbaa_fd)

        v4rho2sigma2_bbac = lxc["v4rho2sigma2"][0][13]
        v3rhosigma2_bac_plus = kxc_plus["v3rhosigma2"][0][7]
        v3rhosigma2_bac_minus = kxc_minus["v3rhosigma2"][0][7]
        v4rho2sigma2_bbac_fd = (v3rhosigma2_bac_plus -
                                v3rhosigma2_bac_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigma2_bbac", v4rho2sigma2_bbac,
                        v4rho2sigma2_bbac_fd)

        v4rho2sigma2_bbab = lxc["v4rho2sigma2"][0][14]
        v3rhosigma2_bab_plus = kxc_plus["v3rhosigma2"][0][8]
        v3rhosigma2_bab_minus = kxc_minus["v3rhosigma2"][0][8]
        v4rho2sigma2_bbab_fd = (v3rhosigma2_bab_plus -
                                v3rhosigma2_bab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigma2_bbab", v4rho2sigma2_bbab,
                        v4rho2sigma2_bbab_fd)

        v4rho2sigma2_bbcc = lxc["v4rho2sigma2"][0][15]
        v3rhosigma2_bcc_plus = kxc_plus["v3rhosigma2"][0][9]
        v3rhosigma2_bcc_minus = kxc_minus["v3rhosigma2"][0][9]
        v4rho2sigma2_bbcc_fd = (v3rhosigma2_bcc_plus -
                                v3rhosigma2_bcc_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigma2_bbcc", v4rho2sigma2_bbcc,
                        v4rho2sigma2_bbcc_fd)

        v4rho2sigma2_bbcb = lxc["v4rho2sigma2"][0][16]
        v3rhosigma2_bcb_plus = kxc_plus["v3rhosigma2"][0][10]
        v3rhosigma2_bcb_minus = kxc_minus["v3rhosigma2"][0][10]
        v4rho2sigma2_bbcb_fd = (v3rhosigma2_bcb_plus -
                                v3rhosigma2_bcb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigma2_bbcb", v4rho2sigma2_bbcb,
                        v4rho2sigma2_bbcb_fd)

        v4rho2sigma2_bbbb = lxc["v4rho2sigma2"][0][17]
        v3rhosigma2_bbb_plus = kxc_plus["v3rhosigma2"][0][11]
        v3rhosigma2_bbb_minus = kxc_minus["v3rhosigma2"][0][11]
        v4rho2sigma2_bbbb_fd = (v3rhosigma2_bbb_plus -
                                v3rhosigma2_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigma2_bbbb", v4rho2sigma2_bbbb,
                        v4rho2sigma2_bbbb_fd)

        v4rho2sigmatau_bbaa = lxc["v4rho2sigmatau"][0][12]
        v3rhosigmatau_baa_plus = kxc_plus["v3rhosigmatau"][0][6]
        v3rhosigmatau_baa_minus = kxc_minus["v3rhosigmatau"][0][6]
        v4rho2sigmatau_bbaa_fd = (v3rhosigmatau_baa_plus -
                                  v3rhosigmatau_baa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigmatau_bbaa", v4rho2sigmatau_bbaa,
                        v4rho2sigmatau_bbaa_fd)

        v4rho2sigmatau_bbab = lxc["v4rho2sigmatau"][0][13]
        v3rhosigmatau_bab_plus = kxc_plus["v3rhosigmatau"][0][7]
        v3rhosigmatau_bab_minus = kxc_minus["v3rhosigmatau"][0][7]
        v4rho2sigmatau_bbab_fd = (v3rhosigmatau_bab_plus -
                                  v3rhosigmatau_bab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigmatau_bbab", v4rho2sigmatau_bbab,
                        v4rho2sigmatau_bbab_fd)

        v4rho2sigmatau_bbca = lxc["v4rho2sigmatau"][0][14]
        v3rhosigmatau_bca_plus = kxc_plus["v3rhosigmatau"][0][8]
        v3rhosigmatau_bca_minus = kxc_minus["v3rhosigmatau"][0][8]
        v4rho2sigmatau_bbca_fd = (v3rhosigmatau_bca_plus -
                                  v3rhosigmatau_bca_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigmatau_bbca", v4rho2sigmatau_bbca,
                        v4rho2sigmatau_bbca_fd)

        v4rho2sigmatau_bbcb = lxc["v4rho2sigmatau"][0][15]
        v3rhosigmatau_bcb_plus = kxc_plus["v3rhosigmatau"][0][9]
        v3rhosigmatau_bcb_minus = kxc_minus["v3rhosigmatau"][0][9]
        v4rho2sigmatau_bbcb_fd = (v3rhosigmatau_bcb_plus -
                                  v3rhosigmatau_bcb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigmatau_bbcb", v4rho2sigmatau_bbcb,
                        v4rho2sigmatau_bbcb_fd)

        v4rho2sigmatau_bbba = lxc["v4rho2sigmatau"][0][16]
        v3rhosigmatau_bba_plus = kxc_plus["v3rhosigmatau"][0][10]
        v3rhosigmatau_bba_minus = kxc_minus["v3rhosigmatau"][0][10]
        v4rho2sigmatau_bbba_fd = (v3rhosigmatau_bba_plus -
                                  v3rhosigmatau_bba_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigmatau_bbba", v4rho2sigmatau_bbba,
                        v4rho2sigmatau_bbba_fd)

        v4rho2sigmatau_bbbb = lxc["v4rho2sigmatau"][0][17]
        v3rhosigmatau_bbb_plus = kxc_plus["v3rhosigmatau"][0][11]
        v3rhosigmatau_bbb_minus = kxc_minus["v3rhosigmatau"][0][11]
        v4rho2sigmatau_bbbb_fd = (v3rhosigmatau_bbb_plus -
                                  v3rhosigmatau_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2sigmatau_bbbb", v4rho2sigmatau_bbbb,
                        v4rho2sigmatau_bbbb_fd)

        v4rho2tau2_bbaa = lxc["v4rho2tau2"][0][6]
        v3rhotau2_baa_plus = kxc_plus["v3rhotau2"][0][3]
        v3rhotau2_baa_minus = kxc_minus["v3rhotau2"][0][3]
        v4rho2tau2_bbaa_fd = (v3rhotau2_baa_plus -
                              v3rhotau2_baa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2tau2_bbaa", v4rho2tau2_bbaa,
                        v4rho2tau2_bbaa_fd)

        v4rho2tau2_bbab = lxc["v4rho2tau2"][0][7]
        v3rhotau2_bab_plus = kxc_plus["v3rhotau2"][0][4]
        v3rhotau2_bab_minus = kxc_minus["v3rhotau2"][0][4]
        v4rho2tau2_bbab_fd = (v3rhotau2_bab_plus -
                              v3rhotau2_bab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2tau2_bbab", v4rho2tau2_bbab,
                        v4rho2tau2_bbab_fd)

        v4rho2tau2_bbbb = lxc["v4rho2tau2"][0][8]
        v3rhotau2_bbb_plus = kxc_plus["v3rhotau2"][0][5]
        v3rhotau2_bbb_minus = kxc_minus["v3rhotau2"][0][5]
        v4rho2tau2_bbbb_fd = (v3rhotau2_bbb_plus -
                              v3rhotau2_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rho2tau2_bbbb", v4rho2tau2_bbbb,
                        v4rho2tau2_bbbb_fd)

        v4rhosigma3_baaa = lxc["v4rhosigma3"][0][10]
        v3sigma3_aaa_plus = kxc_plus["v3sigma3"][0][0]
        v3sigma3_aaa_minus = kxc_minus["v3sigma3"][0][0]
        v4rhosigma3_baaa_fd = (v3sigma3_aaa_plus -
                               v3sigma3_aaa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_baaa", v4rhosigma3_baaa,
                        v4rhosigma3_baaa_fd)

        v4rhosigma3_baac = lxc["v4rhosigma3"][0][11]
        v3sigma3_aac_plus = kxc_plus["v3sigma3"][0][1]
        v3sigma3_aac_minus = kxc_minus["v3sigma3"][0][1]
        v4rhosigma3_baac_fd = (v3sigma3_aac_plus -
                               v3sigma3_aac_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_baac", v4rhosigma3_baac,
                        v4rhosigma3_baac_fd)

        v4rhosigma3_baab = lxc["v4rhosigma3"][0][12]
        v3sigma3_aab_plus = kxc_plus["v3sigma3"][0][2]
        v3sigma3_aab_minus = kxc_minus["v3sigma3"][0][2]
        v4rhosigma3_baab_fd = (v3sigma3_aab_plus -
                               v3sigma3_aab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_baab", v4rhosigma3_baab,
                        v4rhosigma3_baab_fd)

        v4rhosigma3_bacc = lxc["v4rhosigma3"][0][13]
        v3sigma3_acc_plus = kxc_plus["v3sigma3"][0][3]
        v3sigma3_acc_minus = kxc_minus["v3sigma3"][0][3]
        v4rhosigma3_bacc_fd = (v3sigma3_acc_plus -
                               v3sigma3_acc_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_bacc", v4rhosigma3_bacc,
                        v4rhosigma3_bacc_fd)

        v4rhosigma3_bacb = lxc["v4rhosigma3"][0][14]
        v3sigma3_acb_plus = kxc_plus["v3sigma3"][0][4]
        v3sigma3_acb_minus = kxc_minus["v3sigma3"][0][4]
        v4rhosigma3_bacb_fd = (v3sigma3_acb_plus -
                               v3sigma3_acb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_bacb", v4rhosigma3_bacb,
                        v4rhosigma3_bacb_fd)

        v4rhosigma3_babb = lxc["v4rhosigma3"][0][15]
        v3sigma3_abb_plus = kxc_plus["v3sigma3"][0][5]
        v3sigma3_abb_minus = kxc_minus["v3sigma3"][0][5]
        v4rhosigma3_babb_fd = (v3sigma3_abb_plus -
                               v3sigma3_abb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_babb", v4rhosigma3_babb,
                        v4rhosigma3_babb_fd)

        v4rhosigma3_bccc = lxc["v4rhosigma3"][0][16]
        v3sigma3_ccc_plus = kxc_plus["v3sigma3"][0][6]
        v3sigma3_ccc_minus = kxc_minus["v3sigma3"][0][6]
        v4rhosigma3_bccc_fd = (v3sigma3_ccc_plus -
                               v3sigma3_ccc_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_bccc", v4rhosigma3_bccc,
                        v4rhosigma3_bccc_fd)

        v4rhosigma3_bccb = lxc["v4rhosigma3"][0][17]
        v3sigma3_ccb_plus = kxc_plus["v3sigma3"][0][7]
        v3sigma3_ccb_minus = kxc_minus["v3sigma3"][0][7]
        v4rhosigma3_bccb_fd = (v3sigma3_ccb_plus -
                               v3sigma3_ccb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_bccb", v4rhosigma3_bccb,
                        v4rhosigma3_bccb_fd)

        v4rhosigma3_bcbb = lxc["v4rhosigma3"][0][18]
        v3sigma3_cbb_plus = kxc_plus["v3sigma3"][0][8]
        v3sigma3_cbb_minus = kxc_minus["v3sigma3"][0][8]
        v4rhosigma3_bcbb_fd = (v3sigma3_cbb_plus -
                               v3sigma3_cbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_bcbb", v4rhosigma3_bcbb,
                        v4rhosigma3_bcbb_fd)

        v4rhosigma3_bbbb = lxc["v4rhosigma3"][0][19]
        v3sigma3_bbb_plus = kxc_plus["v3sigma3"][0][9]
        v3sigma3_bbb_minus = kxc_minus["v3sigma3"][0][9]
        v4rhosigma3_bbbb_fd = (v3sigma3_bbb_plus -
                               v3sigma3_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma3_bbbb", v4rhosigma3_bbbb,
                        v4rhosigma3_bbbb_fd)

        v4rhosigma2tau_baaa = lxc["v4rhosigma2tau"][0][12]
        v3sigma2tau_aaa_plus = kxc_plus["v3sigma2tau"][0][0]
        v3sigma2tau_aaa_minus = kxc_minus["v3sigma2tau"][0][0]
        v4rhosigma2tau_baaa_fd = (v3sigma2tau_aaa_plus -
                                  v3sigma2tau_aaa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_baaa", v4rhosigma2tau_baaa,
                        v4rhosigma2tau_baaa_fd)

        v4rhosigma2tau_baab = lxc["v4rhosigma2tau"][0][13]
        v3sigma2tau_aab_plus = kxc_plus["v3sigma2tau"][0][1]
        v3sigma2tau_aab_minus = kxc_minus["v3sigma2tau"][0][1]
        v4rhosigma2tau_baab_fd = (v3sigma2tau_aab_plus -
                                  v3sigma2tau_aab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_baab", v4rhosigma2tau_baab,
                        v4rhosigma2tau_baab_fd)

        v4rhosigma2tau_baca = lxc["v4rhosigma2tau"][0][14]
        v3sigma2tau_aca_plus = kxc_plus["v3sigma2tau"][0][2]
        v3sigma2tau_aca_minus = kxc_minus["v3sigma2tau"][0][2]
        v4rhosigma2tau_baca_fd = (v3sigma2tau_aca_plus -
                                  v3sigma2tau_aca_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_baca", v4rhosigma2tau_baca,
                        v4rhosigma2tau_baca_fd)

        v4rhosigma2tau_bacb = lxc["v4rhosigma2tau"][0][15]
        v3sigma2tau_acb_plus = kxc_plus["v3sigma2tau"][0][3]
        v3sigma2tau_acb_minus = kxc_minus["v3sigma2tau"][0][3]
        v4rhosigma2tau_bacb_fd = (v3sigma2tau_acb_plus -
                                  v3sigma2tau_acb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_bacb", v4rhosigma2tau_bacb,
                        v4rhosigma2tau_bacb_fd)

        v4rhosigma2tau_baba = lxc["v4rhosigma2tau"][0][16]
        v3sigma2tau_aba_plus = kxc_plus["v3sigma2tau"][0][4]
        v3sigma2tau_aba_minus = kxc_minus["v3sigma2tau"][0][4]
        v4rhosigma2tau_baba_fd = (v3sigma2tau_aba_plus -
                                  v3sigma2tau_aba_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_baba", v4rhosigma2tau_baba,
                        v4rhosigma2tau_baba_fd)

        v4rhosigma2tau_babb = lxc["v4rhosigma2tau"][0][17]
        v3sigma2tau_abb_plus = kxc_plus["v3sigma2tau"][0][5]
        v3sigma2tau_abb_minus = kxc_minus["v3sigma2tau"][0][5]
        v4rhosigma2tau_babb_fd = (v3sigma2tau_abb_plus -
                                  v3sigma2tau_abb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_babb", v4rhosigma2tau_babb,
                        v4rhosigma2tau_babb_fd)

        v4rhosigma2tau_bcca = lxc["v4rhosigma2tau"][0][18]
        v3sigma2tau_cca_plus = kxc_plus["v3sigma2tau"][0][6]
        v3sigma2tau_cca_minus = kxc_minus["v3sigma2tau"][0][6]
        v4rhosigma2tau_bcca_fd = (v3sigma2tau_cca_plus -
                                  v3sigma2tau_cca_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_bcca", v4rhosigma2tau_bcca,
                        v4rhosigma2tau_bcca_fd)

        v4rhosigma2tau_bccb = lxc["v4rhosigma2tau"][0][19]
        v3sigma2tau_ccb_plus = kxc_plus["v3sigma2tau"][0][7]
        v3sigma2tau_ccb_minus = kxc_minus["v3sigma2tau"][0][7]
        v4rhosigma2tau_bccb_fd = (v3sigma2tau_ccb_plus -
                                  v3sigma2tau_ccb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_bccb", v4rhosigma2tau_bccb,
                        v4rhosigma2tau_bccb_fd)

        v4rhosigma2tau_bcba = lxc["v4rhosigma2tau"][0][20]
        v3sigma2tau_cba_plus = kxc_plus["v3sigma2tau"][0][8]
        v3sigma2tau_cba_minus = kxc_minus["v3sigma2tau"][0][8]
        v4rhosigma2tau_bcba_fd = (v3sigma2tau_cba_plus -
                                  v3sigma2tau_cba_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_bcba", v4rhosigma2tau_bcba,
                        v4rhosigma2tau_bcba_fd)

        v4rhosigma2tau_bcbb = lxc["v4rhosigma2tau"][0][21]
        v3sigma2tau_cbb_plus = kxc_plus["v3sigma2tau"][0][9]
        v3sigma2tau_cbb_minus = kxc_minus["v3sigma2tau"][0][9]
        v4rhosigma2tau_bcbb_fd = (v3sigma2tau_cbb_plus -
                                  v3sigma2tau_cbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_bcbb", v4rhosigma2tau_bcbb,
                        v4rhosigma2tau_bcbb_fd)

        v4rhosigma2tau_bbba = lxc["v4rhosigma2tau"][0][22]
        v3sigma2tau_bba_plus = kxc_plus["v3sigma2tau"][0][10]
        v3sigma2tau_bba_minus = kxc_minus["v3sigma2tau"][0][10]
        v4rhosigma2tau_bbba_fd = (v3sigma2tau_bba_plus -
                                  v3sigma2tau_bba_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_bbba", v4rhosigma2tau_bbba,
                        v4rhosigma2tau_bbba_fd)

        v4rhosigma2tau_bbbb = lxc["v4rhosigma2tau"][0][23]
        v3sigma2tau_bbb_plus = kxc_plus["v3sigma2tau"][0][11]
        v3sigma2tau_bbb_minus = kxc_minus["v3sigma2tau"][0][11]
        v4rhosigma2tau_bbbb_fd = (v3sigma2tau_bbb_plus -
                                  v3sigma2tau_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigma2tau_bbbb", v4rhosigma2tau_bbbb,
                        v4rhosigma2tau_bbbb_fd)

        v4rhosigmatau2_baaa = lxc["v4rhosigmatau2"][0][9]
        v3sigmatau2_aaa_plus = kxc_plus["v3sigmatau2"][0][0]
        v3sigmatau2_aaa_minus = kxc_minus["v3sigmatau2"][0][0]
        v4rhosigmatau2_baaa_fd = (v3sigmatau2_aaa_plus -
                                  v3sigmatau2_aaa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_baaa", v4rhosigmatau2_baaa,
                        v4rhosigmatau2_baaa_fd)

        v4rhosigmatau2_baab = lxc["v4rhosigmatau2"][0][10]
        v3sigmatau2_aab_plus = kxc_plus["v3sigmatau2"][0][1]
        v3sigmatau2_aab_minus = kxc_minus["v3sigmatau2"][0][1]
        v4rhosigmatau2_baab_fd = (v3sigmatau2_aab_plus -
                                  v3sigmatau2_aab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_baab", v4rhosigmatau2_baab,
                        v4rhosigmatau2_baab_fd)

        v4rhosigmatau2_babb = lxc["v4rhosigmatau2"][0][11]
        v3sigmatau2_abb_plus = kxc_plus["v3sigmatau2"][0][2]
        v3sigmatau2_abb_minus = kxc_minus["v3sigmatau2"][0][2]
        v4rhosigmatau2_babb_fd = (v3sigmatau2_abb_plus -
                                  v3sigmatau2_abb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_babb", v4rhosigmatau2_babb,
                        v4rhosigmatau2_babb_fd)

        v4rhosigmatau2_bcaa = lxc["v4rhosigmatau2"][0][12]
        v3sigmatau2_caa_plus = kxc_plus["v3sigmatau2"][0][3]
        v3sigmatau2_caa_minus = kxc_minus["v3sigmatau2"][0][3]
        v4rhosigmatau2_bcaa_fd = (v3sigmatau2_caa_plus -
                                  v3sigmatau2_caa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_bcaa", v4rhosigmatau2_bcaa,
                        v4rhosigmatau2_bcaa_fd)

        v4rhosigmatau2_bcab = lxc["v4rhosigmatau2"][0][13]
        v3sigmatau2_cab_plus = kxc_plus["v3sigmatau2"][0][4]
        v3sigmatau2_cab_minus = kxc_minus["v3sigmatau2"][0][4]
        v4rhosigmatau2_bcab_fd = (v3sigmatau2_cab_plus -
                                  v3sigmatau2_cab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_bcab", v4rhosigmatau2_bcab,
                        v4rhosigmatau2_bcab_fd)

        v4rhosigmatau2_bcbb = lxc["v4rhosigmatau2"][0][14]
        v3sigmatau2_cbb_plus = kxc_plus["v3sigmatau2"][0][5]
        v3sigmatau2_cbb_minus = kxc_minus["v3sigmatau2"][0][5]
        v4rhosigmatau2_bcbb_fd = (v3sigmatau2_cbb_plus -
                                  v3sigmatau2_cbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_bcbb", v4rhosigmatau2_bcbb,
                        v4rhosigmatau2_bcbb_fd)

        v4rhosigmatau2_bbaa = lxc["v4rhosigmatau2"][0][15]
        v3sigmatau2_baa_plus = kxc_plus["v3sigmatau2"][0][6]
        v3sigmatau2_baa_minus = kxc_minus["v3sigmatau2"][0][6]
        v4rhosigmatau2_bbaa_fd = (v3sigmatau2_baa_plus -
                                  v3sigmatau2_baa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_bbaa", v4rhosigmatau2_bbaa,
                        v4rhosigmatau2_bbaa_fd)

        v4rhosigmatau2_bbab = lxc["v4rhosigmatau2"][0][16]
        v3sigmatau2_bab_plus = kxc_plus["v3sigmatau2"][0][7]
        v3sigmatau2_bab_minus = kxc_minus["v3sigmatau2"][0][7]
        v4rhosigmatau2_bbab_fd = (v3sigmatau2_bab_plus -
                                  v3sigmatau2_bab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_bbab", v4rhosigmatau2_bbab,
                        v4rhosigmatau2_bbab_fd)

        v4rhosigmatau2_bbbb = lxc["v4rhosigmatau2"][0][17]
        v3sigmatau2_bbb_plus = kxc_plus["v3sigmatau2"][0][8]
        v3sigmatau2_bbb_minus = kxc_minus["v3sigmatau2"][0][8]
        v4rhosigmatau2_bbbb_fd = (v3sigmatau2_bbb_plus -
                                  v3sigmatau2_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhosigmatau2_bbbb", v4rhosigmatau2_bbbb,
                        v4rhosigmatau2_bbbb_fd)

        v4rhotau3_baaa = lxc["v4rhotau3"][0][4]
        v3tau3_aaa_plus = kxc_plus["v3tau3"][0][0]
        v3tau3_aaa_minus = kxc_minus["v3tau3"][0][0]
        v4rhotau3_baaa_fd = (v3tau3_aaa_plus - v3tau3_aaa_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhotau3_baaa", v4rhotau3_baaa,
                        v4rhotau3_baaa_fd)

        v4rhotau3_baab = lxc["v4rhotau3"][0][5]
        v3tau3_aab_plus = kxc_plus["v3tau3"][0][1]
        v3tau3_aab_minus = kxc_minus["v3tau3"][0][1]
        v4rhotau3_baab_fd = (v3tau3_aab_plus - v3tau3_aab_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhotau3_baab", v4rhotau3_baab,
                        v4rhotau3_baab_fd)

        v4rhotau3_babb = lxc["v4rhotau3"][0][6]
        v3tau3_abb_plus = kxc_plus["v3tau3"][0][2]
        v3tau3_abb_minus = kxc_minus["v3tau3"][0][2]
        v4rhotau3_babb_fd = (v3tau3_abb_plus - v3tau3_abb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhotau3_babb", v4rhotau3_babb,
                        v4rhotau3_babb_fd)

        v4rhotau3_bbbb = lxc["v4rhotau3"][0][7]
        v3tau3_bbb_plus = kxc_plus["v3tau3"][0][3]
        v3tau3_bbb_minus = kxc_minus["v3tau3"][0][3]
        v4rhotau3_bbbb_fd = (v3tau3_bbb_plus - v3tau3_bbb_minus) / (delta_h * 2)
        self.check_term(tol, "v4rhotau3_bbbb", v4rhotau3_bbbb,
                        v4rhotau3_bbbb_fd)

    def test_rho_b_fd_pkzb(self):

        self.run_rho_b_fd('pkzb', 1.0e-7)

    def test_rho_b_fd_tpssh(self):

        self.run_rho_b_fd('tpssh', 1.0e-7)

    def test_rho_b_fd_m06(self):

        self.run_rho_b_fd('m06', 1.0e-6)

    def test_rho_b_fd_scan(self):

        self.run_rho_b_fd('scan', 1.0e-7)
