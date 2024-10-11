/* Include files */

#include "sl_groundvehicleDynamics_sfun.h"
#include "c9_sl_groundvehicleDynamics.h"
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c9_event_trigger               (0)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c9_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c9_b_emlrtMCI = { 21,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtMCInfo c9_c_emlrtMCI = { 712,/* lineNo */
  79,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_d_emlrtMCI = { 493,/* lineNo */
  68,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_e_emlrtMCI = { 494,/* lineNo */
  66,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_f_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c9_g_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c9_h_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c9_i_emlrtMCI = { 748,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_j_emlrtMCI = { 765,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_k_emlrtMCI = { 774,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_l_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateinteger.m"/* pName */
};

static emlrtMCInfo c9_m_emlrtMCI = { 38,/* lineNo */
  48,                                  /* colNo */
  "circshift",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m"/* pName */
};

static emlrtMCInfo c9_n_emlrtMCI = { 301,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_o_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c9_p_emlrtMCI = { 518,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_q_emlrtMCI = { 90,/* lineNo */
  13,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pName */
};

static emlrtMCInfo c9_r_emlrtMCI = { 320,/* lineNo */
  39,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_s_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c9_t_emlrtMCI = { 982,/* lineNo */
  131,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_u_emlrtMCI = { 993,/* lineNo */
  132,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c9_v_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonempty.m"/* pName */
};

static emlrtMCInfo c9_w_emlrtMCI = { 288,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtMCInfo c9_x_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "validatencols",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatencols.m"/* pName */
};

static emlrtRSInfo c9_emlrtRSI = { 18, /* lineNo */
  "Path Tracking",                     /* fcnName */
  "#sl_groundvehicleDynamics:6050"     /* pathName */
};

static emlrtRSInfo c9_b_emlrtRSI = { 4,/* lineNo */
  "test",                              /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pathName */
};

static emlrtRSInfo c9_c_emlrtRSI = { 7,/* lineNo */
  "test",                              /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pathName */
};

static emlrtRSInfo c9_d_emlrtRSI = { 8,/* lineNo */
  "test",                              /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pathName */
};

static emlrtRSInfo c9_e_emlrtRSI = { 10,/* lineNo */
  "test",                              /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pathName */
};

static emlrtRSInfo c9_f_emlrtRSI = { 11,/* lineNo */
  "test",                              /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pathName */
};

static emlrtRSInfo c9_g_emlrtRSI = { 13,/* lineNo */
  "test",                              /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pathName */
};

static emlrtRSInfo c9_h_emlrtRSI = { 1,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_i_emlrtRSI = { 1,/* lineNo */
  "InternalAccess",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+map\\+internal\\I"
  "nternalAccess.m"                    /* pathName */
};

static emlrtRSInfo c9_j_emlrtRSI = { 1,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c9_k_emlrtRSI = { 121,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_l_emlrtRSI = { 327,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_m_emlrtRSI = { 330,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_n_emlrtRSI = { 331,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_o_emlrtRSI = { 349,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_p_emlrtRSI = { 382,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_q_emlrtRSI = { 387,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_r_emlrtRSI = { 71,/* lineNo */
  "SharedMapProperties",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\SharedM"
  "apProperties.m"                     /* pathName */
};

static emlrtRSInfo c9_s_emlrtRSI = { 403,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_t_emlrtRSI = { 503,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_u_emlrtRSI = { 30,/* lineNo */
  "CircularBufferIndex",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\Circula"
  "rBufferIndex.m"                     /* pathName */
};

static emlrtRSInfo c9_v_emlrtRSI = { 35,/* lineNo */
  "CircularBuffer",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\Circula"
  "rBuffer.m"                          /* pathName */
};

static emlrtRSInfo c9_w_emlrtRSI = { 926,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c9_x_emlrtRSI = { 727,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c9_y_emlrtRSI = { 873,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c9_ab_emlrtRSI = { 1545,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_bb_emlrtRSI = { 1060,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_cb_emlrtRSI = { 353,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_db_emlrtRSI = { 527,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_eb_emlrtRSI = { 528,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_fb_emlrtRSI = { 239,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_gb_emlrtRSI = { 253,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_hb_emlrtRSI = { 272,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ib_emlrtRSI = { 275,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_jb_emlrtRSI = { 285,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_kb_emlrtRSI = { 288,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_lb_emlrtRSI = { 296,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_mb_emlrtRSI = { 305,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_nb_emlrtRSI = { 310,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ob_emlrtRSI = { 1,/* lineNo */
  "InternalAccess",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\InternalAccess.m"/* pathName */
};

static emlrtRSInfo c9_pb_emlrtRSI = { 325,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_qb_emlrtRSI = { 683,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_rb_emlrtRSI = { 699,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_sb_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c9_tb_emlrtRSI = { 377,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ub_emlrtRSI = { 378,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_vb_emlrtRSI = { 398,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_wb_emlrtRSI = { 399,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_xb_emlrtRSI = { 400,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_yb_emlrtRSI = { 366,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ac_emlrtRSI = { 367,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_bc_emlrtRSI = { 387,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_cc_emlrtRSI = { 388,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_dc_emlrtRSI = { 389,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ec_emlrtRSI = { 485,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_fc_emlrtRSI = { 487,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_gc_emlrtRSI = { 498,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_hc_emlrtRSI = { 499,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ic_emlrtRSI = { 500,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_jc_emlrtRSI = { 506,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_kc_emlrtRSI = { 511,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_lc_emlrtRSI = { 519,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_mc_emlrtRSI = { 522,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_nc_emlrtRSI = { 526,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_oc_emlrtRSI = { 516,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_pc_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c9_qc_emlrtRSI = { 729,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_rc_emlrtRSI = { 732,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_sc_emlrtRSI = { 733,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_tc_emlrtRSI = { 734,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_uc_emlrtRSI = { 749,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_vc_emlrtRSI = { 750,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_wc_emlrtRSI = { 760,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_xc_emlrtRSI = { 769,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_yc_emlrtRSI = { 881,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_ad_emlrtRSI = { 420,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_bd_emlrtRSI = { 425,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_cd_emlrtRSI = { 15,/* lineNo */
  "num2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\num2str.m"/* pathName */
};

static emlrtRSInfo c9_dd_emlrtRSI = { 53,/* lineNo */
  "flt2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\flt2str.m"/* pathName */
};

static emlrtRSInfo c9_ed_emlrtRSI = { 912,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_fd_emlrtRSI = { 456,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c9_gd_emlrtRSI = { 1438,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_hd_emlrtRSI = { 1441,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_id_emlrtRSI = { 1444,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c9_jd_emlrtRSI = { 925,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_kd_emlrtRSI = { 930,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ld_emlrtRSI = { 942,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_md_emlrtRSI = { 946,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_nd_emlrtRSI = { 945,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_od_emlrtRSI = { 950,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_pd_emlrtRSI = { 953,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_qd_emlrtRSI = { 956,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_rd_emlrtRSI = { 957,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_sd_emlrtRSI = { 88,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_td_emlrtRSI = { 117,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ud_emlrtRSI = { 128,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_vd_emlrtRSI = { 133,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_wd_emlrtRSI = { 135,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_xd_emlrtRSI = { 139,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_yd_emlrtRSI = { 31,/* lineNo */
  "NameValueParser",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\robotics\\robotutilsint\\+robotics\\+core\\+internal\\+codegen\\NameValuePar"
  "ser.m"                              /* pathName */
};

static emlrtRSInfo c9_ae_emlrtRSI = { 39,/* lineNo */
  "NameValueParserInterface",          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\robotics\\robotutilsint\\+robotics\\+core\\+internal\\NameValueParserInterfa"
  "ce.m"                               /* pathName */
};

static emlrtRSInfo c9_be_emlrtRSI = { 344,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ce_emlrtRSI = { 961,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_de_emlrtRSI = { 171,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ee_emlrtRSI = { 175,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_fe_emlrtRSI = { 180,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ge_emlrtRSI = { 190,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_he_emlrtRSI = { 195,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ie_emlrtRSI = { 201,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_je_emlrtRSI = { 217,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ke_emlrtRSI = { 222,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_le_emlrtRSI = { 234,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_me_emlrtRSI = { 244,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ne_emlrtRSI = { 252,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_oe_emlrtRSI = { 271,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_pe_emlrtRSI = { 297,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_qe_emlrtRSI = { 304,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_re_emlrtRSI = { 305,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_se_emlrtRSI = { 306,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_te_emlrtRSI = { 45,/* lineNo */
  "PriorityQueue",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pathName */
};

static emlrtRSInfo c9_ue_emlrtRSI = { 489,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ve_emlrtRSI = { 492,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_we_emlrtRSI = { 493,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_xe_emlrtRSI = { 466,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ye_emlrtRSI = { 556,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_af_emlrtRSI = { 1073,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_bf_emlrtRSI = { 71,/* lineNo */
  "PriorityQueue",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pathName */
};

static emlrtRSInfo c9_cf_emlrtRSI = { 506,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_df_emlrtRSI = { 508,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ef_emlrtRSI = { 509,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ff_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c9_gf_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c9_hf_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c9_if_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c9_jf_emlrtRSI = { 991,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_kf_emlrtRSI = { 990,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_lf_emlrtRSI = { 977,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_mf_emlrtRSI = { 974,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_nf_emlrtRSI = { 968,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_of_emlrtRSI = { 967,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_pf_emlrtRSI = { 965,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_qf_emlrtRSI = { 415,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_rf_emlrtRSI = { 426,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_sf_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c9_tf_emlrtRSI = { 1009,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_uf_emlrtRSI = { 1018,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_vf_emlrtRSI = { 1021,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_wf_emlrtRSI = { 1028,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_xf_emlrtRSI = { 1029,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_yf_emlrtRSI = { 1031,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_ag_emlrtRSI = { 301,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_bg_emlrtRSI = { 305,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_cg_emlrtRSI = { 509,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_dg_emlrtRSI = { 510,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_eg_emlrtRSI = { 520,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_fg_emlrtRSI = { 39,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c9_gg_emlrtRSI = { 113,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c9_hg_emlrtRSI = { 22,/* lineNo */
  "matlabCodegenHandle",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\matlabCodegenHandle.m"/* pathName */
};

static emlrtRTEInfo c9_emlrtRTEI = { 11,/* lineNo */
  5,                                   /* colNo */
  "test",                              /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pName */
};

static emlrtRTEInfo c9_b_emlrtRTEI = { 13,/* lineNo */
  38,                                  /* colNo */
  "test",                              /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pName */
};

static emlrtRTEInfo c9_c_emlrtRTEI = { 13,/* lineNo */
  5,                                   /* colNo */
  "test",                              /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pName */
};

static emlrtRTEInfo c9_d_emlrtRTEI = { 15,/* lineNo */
  22,                                  /* colNo */
  "test",                              /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pName */
};

static emlrtRTEInfo c9_e_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "test",                              /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pName */
};

static emlrtRTEInfo c9_f_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c9_g_emlrtRTEI = { 12,/* lineNo */
  5,                                   /* colNo */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m"/* pName */
};

static emlrtRTEInfo c9_h_emlrtRTEI = { 17,/* lineNo */
  20,                                  /* colNo */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m"/* pName */
};

static emlrtRTEInfo c9_i_emlrtRTEI = { 151,/* lineNo */
  45,                                  /* colNo */
  "strcmp",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pName */
};

static emlrtRTEInfo c9_j_emlrtRTEI = { 364,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c9_k_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c9_l_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m"/* pName */
};

static emlrtRTEInfo c9_m_emlrtRTEI = { 740,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_n_emlrtRTEI = { 741,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_o_emlrtRTEI = { 735,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_p_emlrtRTEI = { 736,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_q_emlrtRTEI = { 907,/* lineNo */
  24,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_r_emlrtRTEI = { 92,/* lineNo */
  39,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pName */
};

static emlrtRTEInfo c9_s_emlrtRTEI = { 227,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_t_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c9_u_emlrtRTEI = { 297,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_v_emlrtRTEI = { 303,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_w_emlrtRTEI = { 304,/* lineNo */
  39,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_x_emlrtRTEI = { 360,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_y_emlrtRTEI = { 304,/* lineNo */
  67,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_ab_emlrtRTEI = { 478,/* lineNo */
  18,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_bb_emlrtRTEI = { 476,/* lineNo */
  18,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_cb_emlrtRTEI = { 344,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_db_emlrtRTEI = { 344,/* lineNo */
  44,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_eb_emlrtRTEI = { 345,/* lineNo */
  37,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_fb_emlrtRTEI = { 345,/* lineNo */
  51,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_gb_emlrtRTEI = { 965,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_hb_emlrtRTEI = { 986,/* lineNo */
  26,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_ib_emlrtRTEI = { 986,/* lineNo */
  51,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_jb_emlrtRTEI = { 990,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_kb_emlrtRTEI = { 996,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_lb_emlrtRTEI = { 1009,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_mb_emlrtRTEI = { 409,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_nb_emlrtRTEI = { 1018,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_ob_emlrtRTEI = { 1021,/* lineNo */
  28,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_pb_emlrtRTEI = { 1021,/* lineNo */
  72,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_qb_emlrtRTEI = { 1026,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_rb_emlrtRTEI = { 1026,/* lineNo */
  55,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_sb_emlrtRTEI = { 423,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_tb_emlrtRTEI = { 427,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_ub_emlrtRTEI = { 1031,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_vb_emlrtRTEI = { 415,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_wb_emlrtRTEI = { 419,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_xb_emlrtRTEI = { 1029,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_yb_emlrtRTEI = { 1016,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_ac_emlrtRTEI = { 509,/* lineNo */
  42,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c9_bc_emlrtRTEI = { 520,/* lineNo */
  24,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c9_cc_emlrtRTEI = { 521,/* lineNo */
  17,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c9_dc_emlrtRTEI = { 121,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c9_ec_emlrtRTEI = { 128,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c9_fc_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c9_gc_emlrtRTEI = { 520,/* lineNo */
  13,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c9_hc_emlrtRTEI = { 566,/* lineNo */
  13,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c9_ic_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "Path Tracking",                     /* fName */
  "#sl_groundvehicleDynamics:6050"     /* pName */
};

static emlrtRTEInfo c9_jc_emlrtRTEI = { 13,/* lineNo */
  12,                                  /* colNo */
  "test",                              /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pName */
};

static emlrtRTEInfo c9_kc_emlrtRTEI = { 11,/* lineNo */
  17,                                  /* colNo */
  "test",                              /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pName */
};

static emlrtRTEInfo c9_lc_emlrtRTEI = { 57,/* lineNo */
  25,                                  /* colNo */
  "strcmp",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pName */
};

static emlrtRTEInfo c9_mc_emlrtRTEI = { 304,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_nc_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c9_oc_emlrtRTEI = { 344,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_pc_emlrtRTEI = { 963,/* lineNo */
  18,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_qc_emlrtRTEI = { 986,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_rc_emlrtRTEI = { 1021,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c9_sc_emlrtRTEI = { 509,/* lineNo */
  13,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c9_tc_emlrtRTEI = { 116,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtBCInfo c9_emlrtBCI = { 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  19,                                  /* lineNo */
  5,                                   /* colNo */
  "path",                              /* aName */
  "Path Tracking",                     /* fName */
  "#sl_groundvehicleDynamics:6050",    /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c9_uc_emlrtRTEI = { 22,/* lineNo */
  17,                                  /* colNo */
  "Path Tracking",                     /* fName */
  "#sl_groundvehicleDynamics:6050"     /* pName */
};

static emlrtBCInfo c9_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  36,                                  /* colNo */
  "path",                              /* aName */
  "Path Tracking",                     /* fName */
  "#sl_groundvehicleDynamics:6050",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_emlrtDCI = { 23, /* lineNo */
  36,                                  /* colNo */
  "Path Tracking",                     /* fName */
  "#sl_groundvehicleDynamics:6050",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_c_emlrtBCI = { 1,/* iFirst */
  1500,                                /* iLast */
  23,                                  /* lineNo */
  24,                                  /* colNo */
  "out_path",                          /* aName */
  "Path Tracking",                     /* fName */
  "#sl_groundvehicleDynamics:6050",    /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_b_emlrtDCI = { 23,/* lineNo */
  24,                                  /* colNo */
  "Path Tracking",                     /* fName */
  "#sl_groundvehicleDynamics:6050",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_e_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  756,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_c_emlrtDCI = { 756,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_f_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  756,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_d_emlrtDCI = { 756,/* lineNo */
  49,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_g_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  757,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_e_emlrtDCI = { 757,/* lineNo */
  36,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_h_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  757,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_f_emlrtDCI = { 757,/* lineNo */
  51,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_i_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  913,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_g_emlrtDCI = { 913,/* lineNo */
  27,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  197,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  208,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  209,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_h_emlrtDCI = { 223,/* lineNo */
  27,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_n_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  223,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_i_emlrtDCI = { 223,/* lineNo */
  38,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_o_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  223,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_p_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  259,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_q_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  259,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_r_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  260,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_s_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  260,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_t_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  261,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_u_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  261,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  266,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  271,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_x_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  282,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_y_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  282,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_ab_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  283,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_bb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  283,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_cb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  284,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_db_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  284,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_eb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  258,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_fb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  258,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_j_emlrtDCI = { 303,/* lineNo */
  48,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_gb_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  303,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c9_emlrtECI = { -1, /* nDims */
  303,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c9_k_emlrtDCI = { 304,/* lineNo */
  41,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_hb_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  304,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c9_b_emlrtECI = { -1,/* nDims */
  304,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c9_l_emlrtDCI = { 360,/* lineNo */
  54,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_ib_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  360,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_m_emlrtDCI = { 350,/* lineNo */
  38,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_jb_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  350,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_kb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  179,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_n_emlrtDCI = { 179,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_lb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  179,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_o_emlrtDCI = { 179,/* lineNo */
  57,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_mb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  179,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_p_emlrtDCI = { 179,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_nb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  179,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_q_emlrtDCI = { 179,/* lineNo */
  31,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_ob_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_r_emlrtDCI = { 180,/* lineNo */
  28,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_pb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_qb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_s_emlrtDCI = { 180,/* lineNo */
  64,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_rb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_sb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_t_emlrtDCI = { 180,/* lineNo */
  107,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_tb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_ub_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  147,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_u_emlrtDCI = { 180,/* lineNo */
  147,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_vb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  147,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_wb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  181,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_v_emlrtDCI = { 181,/* lineNo */
  27,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_xb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  181,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_w_emlrtDCI = { 181,/* lineNo */
  38,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_yb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_x_emlrtDCI = { 182,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_ac_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  182,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_y_emlrtDCI = { 182,/* lineNo */
  31,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c9_ab_emlrtDCI = { 92,/* lineNo */
  48,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c9_bb_emlrtDCI = { 92,/* lineNo */
  48,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c9_bc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  291,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_cb_emlrtDCI = { 291,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_cc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  291,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_db_emlrtDCI = { 291,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_dc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  203,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_eb_emlrtDCI = { 203,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_ec_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  203,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_fb_emlrtDCI = { 203,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_fc_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  208,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_gb_emlrtDCI = { 208,/* lineNo */
  43,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_gc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  204,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_hb_emlrtDCI = { 204,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_hc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  204,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c9_ib_emlrtDCI = { 204,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_ic_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  209,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_jb_emlrtDCI = { 209,/* lineNo */
  43,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_jc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  211,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_kb_emlrtDCI = { 211,/* lineNo */
  50,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_kc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  211,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_lb_emlrtDCI = { 211,/* lineNo */
  60,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  231,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  232,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_nc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  525,                                 /* lineNo */
  92,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_oc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  525,                                 /* lineNo */
  105,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_pc_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  304,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_mb_emlrtDCI = { 304,/* lineNo */
  80,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_qc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  239,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_rc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  239,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_sc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  255,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_tc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  255,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_uc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  274,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_vc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  274,                                 /* lineNo */
  68,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_wc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  285,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_xc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  285,                                 /* lineNo */
  93,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_yc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  285,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_ad_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  285,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_bd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  262,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_cd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  262,                                 /* lineNo */
  93,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_dd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  262,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_ed_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  262,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c9_fd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  263,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_gd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  263,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_hd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  268,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_id_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  268,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_jd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  269,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_kd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  269,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_ld_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  270,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_md_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  270,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_nd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  542,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_nb_emlrtDCI = { 542,/* lineNo */
  33,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_od_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  542,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_ob_emlrtDCI = { 542,/* lineNo */
  49,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c9_pb_emlrtDCI = { 458,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c9_qb_emlrtDCI = { 474,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c9_c_emlrtECI = { -1,/* nDims */
  345,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtECInfo c9_d_emlrtECI = { -1,/* nDims */
  344,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtBCInfo c9_pd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  315,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_rb_emlrtDCI = { 315,/* lineNo */
  42,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_qd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  315,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_sb_emlrtDCI = { 315,/* lineNo */
  53,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_rd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  332,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_tb_emlrtDCI = { 332,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_sd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  332,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_ub_emlrtDCI = { 332,/* lineNo */
  57,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c9_e_emlrtECI = { -1,/* nDims */
  996,                                 /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtBCInfo c9_td_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  996,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_vb_emlrtDCI = { 996,/* lineNo */
  32,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c9_f_emlrtECI = { -1,/* nDims */
  986,                                 /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtBCInfo c9_ud_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  986,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_wb_emlrtDCI = { 986,/* lineNo */
  28,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_vd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  986,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_xb_emlrtDCI = { 986,/* lineNo */
  58,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_wd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  986,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_yb_emlrtDCI = { 353,/* lineNo */
  45,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_xd_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  353,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_ac_emlrtDCI = { 1021,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_yd_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  1021,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c9_g_emlrtECI = { -1,/* nDims */
  1021,                                /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c9_bc_emlrtDCI = { 1026,/* lineNo */
  32,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_ae_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  1026,                                /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c9_h_emlrtECI = { -1,/* nDims */
  1026,                                /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c9_cc_emlrtDCI = { 409,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_be_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  409,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_dc_emlrtDCI = { 423,/* lineNo */
  32,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_ce_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  423,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_ec_emlrtDCI = { 415,/* lineNo */
  36,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_de_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  415,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_ee_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  1018,                                /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c9_fc_emlrtDCI = { 1018,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c9_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  520,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c9_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  521,                                 /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c9_ig_emlrtRSI = { 566,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c9_jg_emlrtRSI = { 1016,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_kg_emlrtRSI = { 1026,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_lg_emlrtRSI = { 344,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_mg_emlrtRSI = { 15,/* lineNo */
  "test",                              /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\test.m"/* pathName */
};

static emlrtRSInfo c9_ng_emlrtRSI = { 996,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_og_emlrtRSI = { 986,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_pg_emlrtRSI = { 345,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c9_qg_emlrtRSI = { 521,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static char_T c9_cv[20] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
  'e', 'r', ' ', '2', ',', ' ', 'i', 'd', 'x', ',' };

static char_T c9_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'r', 'i',
  'd', '2', 'w', 'o', 'r', 'l', 'd', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
  'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

static char_T c9_cv2[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o',
  'n', 'e', 'm', 'p', 't', 'y' };

static char_T c9_cv3[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'r', 'i',
  'd', '2', 'w', 'o', 'r', 'l', 'd', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
  'I', 'n', 't', 'e', 'g', 'e', 'r' };

static char_T c9_cv4[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n',
  't', 'e', 'g', 'e', 'r' };

static char_T c9_cv5[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
  'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

static char_T c9_cv6[52] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
  's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g', 'r',
  'i', 'd', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a', 'i', 'l',
  'e', 'd', 'L', 'e', 's', 's', 'T', 'h', 'a', 'n' };

static char_T c9_cv7[16] = { 'N', 'u', 'm', 'N', 'o', 'd', 'e', 's', 'E', 'x',
  'p', 'l', 'o', 'r', 'e', 'd' };

static char_T c9_cv8[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

static char_T c9_cv9[64] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
  's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g', 'r',
  'i', 'd', ':', 'U', 's', 'e', 'r', 'D', 'i', 's', 't', 'a', 'n', 'c', 'e', 'F',
  'u', 'n', 'c', 't', 'i', 'o', 'n', 'R', 'e', 't', 'u', 'r', 'n', 's', 'N', 'a',
  'N', 'O', 'r', 'I', 'n', 'f' };

static char_T c9_cv10[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
  'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm', 'e',
  'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

/* Function Declarations */
static void initialize_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void initialize_params_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_start_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_terminate_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void enable_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void disable_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void sf_gateway_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void ext_mode_exec_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void c9_update_jit_animation_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void c9_do_animation_call_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void set_sim_state_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const mxArray
   *c9_st);
static void c9_initialize_debuginfo_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void c9_test(SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                    const emlrtStack *c9_sp, boolean_T c9_b_logical_map[213200],
                    real_T c9_start[2], real_T c9_goal[2],
                    c9_coder_array_real_T_2D *c9_b_out_path);
static c9_binaryOccupancyMap *c9_binaryOccupancyMap_binaryOccupancyMap
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_binaryOccupancyMap *c9_obj, boolean_T c9_b_varargin_1[213200]);
static void c9_MapInterface_world2grid
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_binaryOccupancyMap *c9_obj, real_T c9_pos[2], real_T c9_idx[2]);
static c9_plannerAStarGrid *c9_plannerAStarGrid_plannerAStarGrid
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_binaryOccupancyMap *c9_b_varargin_1);
static void c9_plannerAStarGrid_setInputState
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_plannerAStarGrid *c9_obj);
static void c9_ind2sub(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c9_ndx[213200], int32_T c9_varargout_1[213200], int32_T
  c9_varargout_2[213200], int32_T c9_b_varargout_3[213200]);
static void c9_validateAStarBuiltinCostFunction
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, char_T c9_strVal_data[], int32_T c9_strVal_size[2], real_T *c9_idx);
static void c9_plannerAStarGrid_plan(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, c9_plannerAStarGrid *c9_obj, real_T
  c9_start[2], real_T c9_goal[2], c9_coder_array_real_T_2D *c9_path);
static void c9_plannerAStarGrid_validateStartGoal
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_binaryOccupancyMap *c9_e_map, real_T
   c9_StartInGrid[2], real_T c9_GoalInGrid[2]);
static real_T c9_plannerAStarGrid_getNodeCostOMDefault
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, real_T c9_currentNode);
static void c9_binaryOccupancyMap_occupancyMatrix
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, boolean_T c9_b_mat[213200]);
static c9_nav_algs_internal_plannerAStarGrid
  *c9_plannerAStarGrid_initializeInternalPlanner
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_nav_algs_internal_plannerAStarGrid
   *c9_iobj_0);
static c9_nav_algs_internal_plannerAStarGrid
  *c9_b_plannerAStarGrid_plannerAStarGrid
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_e_map[213200],
   real_T c9_obstacleThreshold);
static void c9_b_ind2sub(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c9_ndx[213200], int32_T c9_varargout_1[213200], int32_T
  c9_varargout_2[213200]);
static void c9_plannerAStarGrid_runPlan
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_b_astarInternal, real_T
   c9_start[2], real_T c9_goal[2]);
static void c9_plannerAStarGrid_getHeuristicMatrix
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_goalIn[2],
   real_T c9_Hn[213200]);
static void c9_plannerAStarGrid_Chebyshev
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, real_T
   c9_b_pose1[426400], real_T c9_pose2[426400], real_T c9_dist[213200]);
static real_T c9_plannerAStarGrid_Euclidean
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, real_T c9_b_pose1[2], real_T c9_pose2[2]);
static real_T c9_sumColumnB(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c9_b_x[2]);
static void c9_plannerAStarGrid_getNeighbors
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T
   c9_Neighbors_data[], int32_T c9_Neighbors_size[2], real_T *c9_NumNeighbors);
static void c9_plannerAStarGrid_reconstructPath
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_CurrentRow,
   real_T c9_CurrentCol, real_T c9_startIn[2]);
static real_T c9_plannerAStarGrid_gcostValue
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_CurrentRow,
   real_T c9_CurrentCol, real_T c9_i, real_T c9_j);
static void c9_indexShapeCheck(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance);
static void c9_plannerAStarGrid_getEssentialOutput
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_nav_algs_internal_plannerAStarGrid
   *c9_b_astarInternal);
static void c9_warning(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp);
static void c9_plannerAStarGrid_getPathOutput
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_coder_array_real_T_2D *c9_pathOut);
static void c9_MapInterface_grid2worldImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_worldXY);
static void c9_MapInterface_grid2localImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_localXY);
static void c9_MapInterface_local2worldImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_localXY,
   c9_coder_array_real_T_2D *c9_worldXY);
static void c9_b_MapInterface_grid2worldImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_worldXY);
static void c9_b_MapInterface_grid2localImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_localXY);
static void c9_handle_matlabCodegenDestructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_PriorityQueue *c9_obj);
static void c9_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_a__output_of_sprintf_, const char_T
  *c9_identifier, char_T c9_d_y[23]);
static void c9_b_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_d_y[23]);
static void c9_c_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier, real_T
  c9_d_y[1500]);
static void c9_d_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[1500]);
static void c9_e_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier,
  boolean_T *c9_svPtr, real_T c9_d_y[3000]);
static void c9_f_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T *c9_svPtr, real_T c9_d_y[3000]);
static void c9_g_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier,
  boolean_T *c9_svPtr, real_T c9_d_y[1500]);
static void c9_h_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T *c9_svPtr, real_T c9_d_y[1500]);
static void c9_slStringInitializeDynamicBuffers
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static const mxArray *c9_sf_marshallOut_matrix1x1500_real_T_persistent(void
  *chartInstanceVoid, void *c9_inData);
static void c9_sf_marshallIn_matrix1x1500_real_T_persistent(void
  *chartInstanceVoid, const mxArray *c9_mxArrayInData, const char_T *c9_varName,
  void *c9_outData);
static const mxArray *c9_sf_marshallOut_matrix2x1500_real_T_persistent(void
  *chartInstanceVoid, void *c9_inData);
static void c9_sf_marshallIn_matrix2x1500_real_T_persistent(void
  *chartInstanceVoid, const mxArray *c9_mxArrayInData, const char_T *c9_varName,
  void *c9_outData);
static const mxArray *c9_sf_marshallOut_matrix4x1_real_T(void *chartInstanceVoid,
  void *c9_inData);
static void c9_i_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[4]);
static void c9_sf_marshallIn_matrix4x1_real_T(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_sf_marshallOut_matrix4_real_T(void *chartInstanceVoid,
  void *c9_inData);
static void c9_j_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[4]);
static void c9_sf_marshallIn_matrix4_real_T(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_sf_marshallOut_real_T(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_k_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn_real_T(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_sf_marshallOut_matrix410x520_boolean_T(void
  *chartInstanceVoid, void *c9_inData);
static void c9_l_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T c9_d_y[213200]);
static void c9_sf_marshallIn_matrix410x520_boolean_T(void *chartInstanceVoid,
  const mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_sf_marshallOut_matrix1x1500_real_T_1(void
  *chartInstanceVoid, void *c9_inData);
static void c9_sf_marshallIn_matrix1x1500_real_T_1(void *chartInstanceVoid,
  const mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_sf_marshallOut_dynamicmatrix(void *chartInstanceVoid,
  c9_coder_array_real_T_2D *c9_inData);
static void c9_m_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_b_u, const
  emlrtMsgIdentifier *c9_parentId, c9_coder_array_real_T_2D *c9_d_y);
static void c9_sf_marshallIn_dynamicmatrix(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, c9_coder_array_real_T_2D *
  c9_outData);
static const mxArray *c9_sf_marshallOut_matrix1x2_real_T(void *chartInstanceVoid,
  void *c9_inData);
static void c9_n_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[2]);
static void c9_sf_marshallIn_matrix1x2_real_T(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_sf_marshallOut_dynamicmatrix_1(void *chartInstanceVoid,
  c9_coder_array_real_T_2D *c9_inData);
static void c9_o_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_b_u, const
  emlrtMsgIdentifier *c9_parentId, c9_coder_array_real_T_2D *c9_d_y);
static void c9_sf_marshallIn_dynamicmatrix_1(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, c9_coder_array_real_T_2D *
  c9_outData);
static void c9_chart_data_browse_helper
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, int32_T
   c9_ssIdNumber, const mxArray **c9_mxData, uint8_T *c9_isValueTooBig);
static const mxArray *c9_sprintf(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_input0, const
  mxArray *c9_input1);
static const mxArray *c9_feval(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_input0, const
  mxArray *c9_input1);
static void c9_b_feval(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_input0, const
  mxArray *c9_input1);
static void c9_array_real_T_2D_SetSize
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_coder_array_real_T_2D *c9_coderArray, const emlrtRTEInfo
   *c9_srcLocation, int32_T c9_size0, int32_T c9_size1);
static void c9_array_int32_T_SetSize(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, c9_coder_array_int32_T *c9_coderArray,
  const emlrtRTEInfo *c9_srcLocation, int32_T c9_size0);
static void c9_array_real_T_SetSize(SFc9_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const emlrtStack *c9_sp, c9_coder_array_real_T *c9_coderArray,
  const emlrtRTEInfo *c9_srcLocation, int32_T c9_size0);
static void c9_array_real_T_2D_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T_2D *c9_coderArray);
static void c9_array_real_T_2D_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T_2D *c9_coderArray);
static void c9_array_real_T_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T *c9_coderArray);
static void c9_array_int32_T_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_int32_T *c9_coderArray);
static void c9_array_real_T_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T *c9_coderArray);
static void c9_array_int32_T_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_int32_T *c9_coderArray);
static void c9_array_cell_wrap_34_2s_Construct
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   c9_pMatrix[2]);
static void c9_array_cell_wrap_34_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   *c9_pStruct);
static void c9_array_cell_wrap_34_2s_Destructo
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   c9_pMatrix[2]);
static void c9_array_cell_wrap_34_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   *c9_pStruct);
static int32_T c9_div_nzp_s32(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c9_numerator, int32_T c9_denominator, int32_T
  c9_EMLOvCount_src_loc, uint32_T c9_ssid_src_loc, int32_T c9_offset_src_loc,
  int32_T c9_length_src_loc);
static int32_T c9_div_s32_ndbzs(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c9_numerator, int32_T c9_denominator, int32_T
  c9_EMLOvCount_src_loc, uint32_T c9_ssid_src_loc, int32_T c9_offset_src_loc,
  int32_T c9_length_src_loc);
static void init_dsm_address_info(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  emlrtStack c9_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c9_st.tls = chartInstance->c9_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c9_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "navigation_toolbox", 2);
  sfListenerReportChartEnableDisable(chartInstance->c9_RuntimeVar, &_sfTime_, 13);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c9_path_x_not_empty = false;
  chartInstance->c9_path_y_not_empty = false;
  chartInstance->c9_out_path_not_empty = false;
  chartInstance->c9_doneDoubleBufferReInit = false;
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  c9_initialize_debuginfo_c9_sl_groundvehicleDynamics(chartInstance);
}

static void initialize_params_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  static const uint32_T c9_decisionTxtEndIdx = 0U;
  static const uint32_T c9_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c9_chart_data_browse_helper);
  chartInstance->c9_RuntimeVar = sfListenerInitializeUsingSimStruct
    (chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c9_RuntimeVar,
    &chartInstance->c9_IsDebuggerActive,
    &chartInstance->c9_IsSequenceViewerPresent, 1, 0,
    &chartInstance->c9_mlFcnLineNumber, &chartInstance->c9_IsHeatMapPresent, 0);
  chartInstance->c9_SequenceViewerOptimization = 1;
  sfListenerInitializeIsStmtByStmtModeVar(chartInstance->c9_RuntimeVar,
    &chartInstance->c9_IsStmtByStmtMode);
  sfListenerInitializeRuntimeFcnVarsJitOff(chartInstance->c9_RuntimeVar,
    &chartInstance->c9_numFcnVars, chartInstance->c9_dataNames,
    chartInstance->c9_ssIds, chartInstance->c9_fcnDataPtrs,
    chartInstance->c9_outMexFcns, chartInstance->c9_inMexFcns,
    chartInstance->c9_statuses);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c9_JITStateAnimation[0],
                        &chartInstance->c9_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c9_covrtInstance, 1U, 1U, 1U,
    92U);
  covrtChartInitFcn(chartInstance->c9_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c9_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c9_decisionTxtStartIdx, &c9_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c9_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c9_covrtInstance, "", 4U, 0U, 1U, 0U, 3U, 0U,
                  0U, 0U, 2U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c9_covrtInstance, 4U, 0U, 0U,
                     "c9_sl_groundvehicleDynamics", 0, -1, 658);
  covrtEmlIfInitFcn(chartInstance->c9_covrtInstance, 4U, 0U, 0U, 115, 133, -1,
                    173, false);
  covrtEmlIfInitFcn(chartInstance->c9_covrtInstance, 4U, 0U, 1U, 202, 220, -1,
                    260, false);
  covrtEmlIfInitFcn(chartInstance->c9_covrtInstance, 4U, 0U, 2U, 291, 311, -1,
                    353, false);
  covrtEmlForInitFcn(chartInstance->c9_covrtInstance, 4U, 0U, 0U, 460, 471, 550);
  covrtEmlForInitFcn(chartInstance->c9_covrtInstance, 4U, 0U, 1U, 480, 491, 542);
  covrtEmlInitFcn(chartInstance->c9_covrtInstance,
                  "C:/Users/jeff/Qepoxy Dropbox/Jeff whitford/EGH446/egh446_simEnv2024/sim_env/AutoSystems446/test.m",
                  14U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c9_covrtInstance, 14U, 0U, 0U, "test", 0, -1,
                     553);
}

static void mdl_cleanup_runtime_resources_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  sfListenerTerminate(chartInstance->c9_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c9_covrtInstance);
}

static void enable_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  sfListenerReportChartEnableDisable(chartInstance->c9_RuntimeVar, &_sfTime_, 13);
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  sfListenerReportChartEnableDisable(chartInstance->c9_RuntimeVar, &_sfTime_, 14);
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  c9_coder_array_real_T_2D c9_path;
  emlrtStack c9_b_st;
  emlrtStack c9_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c9_b_path_xo[1500];
  real_T c9_b_path_yo[1500];
  real_T c9_b_waypoints_x[4];
  real_T c9_b_waypoints_y[4];
  real_T c9_c_current_x[2];
  real_T c9_c_waypoints_x[2];
  real_T c9_b_a;
  real_T c9_b_b;
  real_T c9_b_current_x;
  real_T c9_b_current_y;
  real_T c9_b_i;
  real_T c9_c_b;
  real_T c9_d_b;
  real_T c9_j;
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 2.0;
  int32_T c9_b_j;
  int32_T c9_c_i;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i2;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  c9_st.tls = chartInstance->c9_fEmlrtCtx;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_path);
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    covrtSigUpdateFcn(chartInstance->c9_covrtInstance, 4U, (real_T)
                      (*chartInstance->c9_d_map)[c9_i]);
  }

  covrtSigUpdateFcn(chartInstance->c9_covrtInstance, 3U,
                    *chartInstance->c9_current_y);
  covrtSigUpdateFcn(chartInstance->c9_covrtInstance, 2U,
                    *chartInstance->c9_current_x);
  for (c9_i1 = 0; c9_i1 < 4; c9_i1++) {
    covrtSigUpdateFcn(chartInstance->c9_covrtInstance, 1U,
                      (*chartInstance->c9_waypoints_y)[c9_i1]);
  }

  for (c9_i2 = 0; c9_i2 < 4; c9_i2++) {
    covrtSigUpdateFcn(chartInstance->c9_covrtInstance, 0U,
                      (*chartInstance->c9_waypoints_x)[c9_i2]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_JITTransitionAnimation[0] = 0U;
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportStartingEventBroadcast(chartInstance->c9_RuntimeVar, 18U, 10);
  }

  chartInstance->c9_sfEvent = c9_event_trigger;
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportStartingSection(chartInstance->c9_RuntimeVar, 0, 1);
  }

  for (c9_i3 = 0; c9_i3 < 4; c9_i3++) {
    c9_b_waypoints_x[c9_i3] = (*chartInstance->c9_waypoints_x)[c9_i3];
  }

  for (c9_i4 = 0; c9_i4 < 4; c9_i4++) {
    c9_b_waypoints_y[c9_i4] = (*chartInstance->c9_waypoints_y)[c9_i4];
  }

  c9_b_current_x = *chartInstance->c9_current_x;
  c9_b_current_y = *chartInstance->c9_current_y;
  for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
    chartInstance->c9_b_map[c9_i5] = (*chartInstance->c9_d_map)[c9_i5];
  }

  chartInstance->c9_numFcnVars = 13U;
  chartInstance->c9_fcnDataPtrs[0] = (void *)&c9_b_waypoints_x;
  chartInstance->c9_fcnDataPtrs[1] = (void *)&c9_b_waypoints_y;
  chartInstance->c9_fcnDataPtrs[2] = (void *)&c9_b_current_x;
  chartInstance->c9_fcnDataPtrs[3] = (void *)&c9_b_current_y;
  chartInstance->c9_fcnDataPtrs[4] = (void *)&chartInstance->c9_b_map;
  chartInstance->c9_fcnDataPtrs[5] = (void *)&c9_b_path_xo;
  chartInstance->c9_fcnDataPtrs[6] = (void *)&c9_b_path_yo;
  chartInstance->c9_fcnDataPtrs[7] = (void *)&c9_b_a;
  chartInstance->c9_fcnDataPtrs[8] = (void *)&c9_b_b;
  chartInstance->c9_fcnDataPtrs[9] = (void *)&c9_b_i;
  chartInstance->c9_fcnDataPtrs[10] = (void *)&c9_j;
  chartInstance->c9_fcnDataPtrs[11] = (void *)&c9_nargin;
  chartInstance->c9_fcnDataPtrs[12] = (void *)&c9_nargout;
  chartInstance->c9_statuses[0] = 0U;
  chartInstance->c9_statuses[1] = 0U;
  chartInstance->c9_statuses[2] = 0U;
  chartInstance->c9_statuses[3] = 0U;
  chartInstance->c9_statuses[4] = 0U;
  chartInstance->c9_statuses[5] = 0U;
  chartInstance->c9_statuses[6] = 0U;
  chartInstance->c9_statuses[7] = 1U;
  chartInstance->c9_statuses[8] = 0U;
  chartInstance->c9_statuses[9] = 0U;
  chartInstance->c9_statuses[10] = 0U;
  chartInstance->c9_statuses[11] = 0U;
  chartInstance->c9_statuses[12] = 0U;
  chartInstance->c9_inMexFcns[0] = (void *)&c9_sf_marshallIn_matrix4x1_real_T;
  chartInstance->c9_inMexFcns[1] = (void *)&c9_sf_marshallIn_matrix4_real_T;
  chartInstance->c9_inMexFcns[2] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_inMexFcns[3] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_inMexFcns[4] = (void *)
    &c9_sf_marshallIn_matrix410x520_boolean_T;
  chartInstance->c9_inMexFcns[5] = (void *)
    &c9_sf_marshallIn_matrix1x1500_real_T_1;
  chartInstance->c9_inMexFcns[6] = (void *)
    &c9_sf_marshallIn_matrix1x1500_real_T_1;
  chartInstance->c9_inMexFcns[7] = NULL;
  chartInstance->c9_inMexFcns[8] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_inMexFcns[9] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_inMexFcns[10] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_inMexFcns[11] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_inMexFcns[12] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_outMexFcns[0] = (void *)&c9_sf_marshallOut_matrix4x1_real_T;
  chartInstance->c9_outMexFcns[1] = (void *)&c9_sf_marshallOut_matrix4_real_T;
  chartInstance->c9_outMexFcns[2] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[3] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[4] = (void *)
    &c9_sf_marshallOut_matrix410x520_boolean_T;
  chartInstance->c9_outMexFcns[5] = (void *)
    &c9_sf_marshallOut_matrix1x1500_real_T_1;
  chartInstance->c9_outMexFcns[6] = (void *)
    &c9_sf_marshallOut_matrix1x1500_real_T_1;
  chartInstance->c9_outMexFcns[7] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[8] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[9] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[10] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[11] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[12] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_ssIds[0] = 0U;
  chartInstance->c9_ssIds[1] = 0U;
  chartInstance->c9_ssIds[2] = 0U;
  chartInstance->c9_ssIds[3] = 0U;
  chartInstance->c9_ssIds[4] = 0U;
  chartInstance->c9_ssIds[5] = 0U;
  chartInstance->c9_ssIds[6] = 0U;
  chartInstance->c9_ssIds[7] = 0U;
  chartInstance->c9_ssIds[8] = 0U;
  chartInstance->c9_ssIds[9] = 0U;
  chartInstance->c9_ssIds[10] = 0U;
  chartInstance->c9_ssIds[11] = 0U;
  chartInstance->c9_ssIds[12] = 0U;
  chartInstance->c9_dataNames[0] = "waypoints_x";
  chartInstance->c9_dataNames[1] = "waypoints_y";
  chartInstance->c9_dataNames[2] = "current_x";
  chartInstance->c9_dataNames[3] = "current_y";
  chartInstance->c9_dataNames[4] = "map";
  chartInstance->c9_dataNames[5] = "path_xo";
  chartInstance->c9_dataNames[6] = "path_yo";
  chartInstance->c9_dataNames[7] = "a";
  chartInstance->c9_dataNames[8] = "b";
  chartInstance->c9_dataNames[9] = "i";
  chartInstance->c9_dataNames[10] = "j";
  chartInstance->c9_dataNames[11] = "nargin";
  chartInstance->c9_dataNames[12] = "nargout";
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportStartingSection(chartInstance->c9_RuntimeVar, 0, 4);
  }

  covrtEmlFcnEval(chartInstance->c9_covrtInstance, 4U, 0, 0);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 3);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 4);
  }

  if (covrtEmlIfEval(chartInstance->c9_covrtInstance, 4U, 0, 0,
                     !chartInstance->c9_path_x_not_empty)) {
    if ((chartInstance->c9_IsDebuggerActive == 1) ||
        (chartInstance->c9_IsSequenceViewerPresent == 1) ||
        (chartInstance->c9_IsHeatMapPresent == 1)) {
      sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 5);
    }

    for (c9_i6 = 0; c9_i6 < 1500; c9_i6++) {
      chartInstance->c9_path_x[c9_i6] = 0.0;
    }

    chartInstance->c9_path_x_not_empty = true;
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 6);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 8);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 9);
  }

  if (covrtEmlIfEval(chartInstance->c9_covrtInstance, 4U, 0, 1,
                     !chartInstance->c9_path_y_not_empty)) {
    if ((chartInstance->c9_IsDebuggerActive == 1) ||
        (chartInstance->c9_IsSequenceViewerPresent == 1) ||
        (chartInstance->c9_IsHeatMapPresent == 1)) {
      sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 10);
    }

    for (c9_i7 = 0; c9_i7 < 1500; c9_i7++) {
      chartInstance->c9_path_y[c9_i7] = 0.0;
    }

    chartInstance->c9_path_y_not_empty = true;
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 11);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 13);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 14);
  }

  if (covrtEmlIfEval(chartInstance->c9_covrtInstance, 4U, 0, 2,
                     !chartInstance->c9_out_path_not_empty)) {
    if ((chartInstance->c9_IsDebuggerActive == 1) ||
        (chartInstance->c9_IsSequenceViewerPresent == 1) ||
        (chartInstance->c9_IsHeatMapPresent == 1)) {
      sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 15);
    }

    for (c9_i8 = 0; c9_i8 < 3000; c9_i8++) {
      chartInstance->c9_out_path[c9_i8] = 0.0;
    }

    chartInstance->c9_out_path_not_empty = true;
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 16);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 18);
  }

  c9_c_current_x[0] = c9_b_current_x;
  c9_c_current_x[1] = c9_b_current_y;
  c9_c_waypoints_x[0] = c9_b_waypoints_x[0];
  c9_c_waypoints_x[1] = c9_b_waypoints_y[0];
  c9_b_st.site = &c9_emlrtRSI;
  for (c9_i9 = 0; c9_i9 < 213200; c9_i9++) {
    chartInstance->c9_c_map[c9_i9] = chartInstance->c9_b_map[c9_i9];
  }

  c9_test(chartInstance, &c9_b_st, chartInstance->c9_c_map, c9_c_current_x,
          c9_c_waypoints_x, &c9_path);
  sfListenerPushScopeForDynamicMatricesJitOff(chartInstance->c9_RuntimeVar, 0U,
    "path", &c9_path, (void *)&c9_sf_marshallOut_dynamicmatrix, (void *)
    &c9_sf_marshallIn_dynamicmatrix, 0U);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 19);
  }

  c9_i10 = c9_path.size[1];
  if (c9_i10 < 0) {
    emlrtDynamicBoundsCheckR2012b(c9_i10, 0, MAX_int32_T, &c9_emlrtBCI, &c9_st);
  }

  c9_c_b = (real_T)c9_i10;
  c9_b_a = 2.0;
  c9_b_b = c9_c_b;
  c9_b_i = 1.0;
  for (c9_c_i = 0; c9_c_i < 2; c9_c_i++) {
    c9_b_i = 1.0 + (real_T)c9_c_i;
    covrtEmlForEval(chartInstance->c9_covrtInstance, 4U, 0, 0, 1);
    c9_d_b = c9_b_b;
    c9_i13 = (int32_T)c9_d_b;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, c9_d_b, mxDOUBLE_CLASS, c9_i13,
      &c9_uc_emlrtRTEI, &c9_st);
    c9_j = 1.0;
    for (c9_b_j = 0; c9_b_j < c9_i13; c9_b_j++) {
      c9_j = 1.0 + (real_T)c9_b_j;
      covrtEmlForEval(chartInstance->c9_covrtInstance, 4U, 0, 1, 1);
      if ((chartInstance->c9_IsDebuggerActive == 1) ||
          (chartInstance->c9_IsSequenceViewerPresent == 1) ||
          (chartInstance->c9_IsHeatMapPresent == 1)) {
        sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 23);
      }

      c9_i17 = c9_path.size[1];
      if (c9_b_b != (real_T)(int32_T)muDoubleScalarFloor(c9_b_b)) {
        emlrtIntegerCheckR2012b(c9_b_b, &c9_emlrtDCI, &c9_st);
      }

      c9_i19 = (int32_T)c9_b_b;
      if ((c9_i19 < 1) || (c9_i19 > c9_i17)) {
        emlrtDynamicBoundsCheckR2012b(c9_i19, 1, c9_i17, &c9_b_emlrtBCI, &c9_st);
      }

      if (c9_b_b != (real_T)(int32_T)muDoubleScalarFloor(c9_b_b)) {
        emlrtIntegerCheckR2012b(c9_b_b, &c9_b_emlrtDCI, &c9_st);
      }

      c9_i21 = (int32_T)c9_b_b;
      if ((c9_i21 < 1) || (c9_i21 > 1500)) {
        emlrtDynamicBoundsCheckR2012b(c9_i21, 1, 1500, &c9_c_emlrtBCI, &c9_st);
      }

      chartInstance->c9_out_path[1 + ((c9_i21 - 1) << 1)] = c9_path.vector.data
        [1 + ((c9_i19 - 1) << 1)];
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    covrtEmlForEval(chartInstance->c9_covrtInstance, 4U, 0, 1, 0);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  covrtEmlForEval(chartInstance->c9_covrtInstance, 4U, 0, 0, 0);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 26);
  }

  c9_i11 = 0;
  for (c9_i12 = 0; c9_i12 < 1500; c9_i12++) {
    chartInstance->c9_path_x[c9_i12] = chartInstance->c9_out_path[c9_i11];
    c9_i11 += 2;
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 27);
  }

  c9_i14 = 0;
  for (c9_i15 = 0; c9_i15 < 1500; c9_i15++) {
    chartInstance->c9_path_y[c9_i15] = chartInstance->c9_out_path[c9_i14 + 1];
    c9_i14 += 2;
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 28);
  }

  for (c9_i16 = 0; c9_i16 < 1500; c9_i16++) {
    c9_b_path_xo[c9_i16] = chartInstance->c9_path_x[c9_i16];
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 29);
  }

  for (c9_i18 = 0; c9_i18 < 1500; c9_i18++) {
    c9_b_path_yo[c9_i18] = chartInstance->c9_path_y[c9_i18];
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 31);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, -31);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportEndingSection(chartInstance->c9_RuntimeVar, 0, 4);
  }

  for (c9_i20 = 0; c9_i20 < 1500; c9_i20++) {
    (*chartInstance->c9_path_xo)[c9_i20] = c9_b_path_xo[c9_i20];
  }

  for (c9_i22 = 0; c9_i22 < 1500; c9_i22++) {
    (*chartInstance->c9_path_yo)[c9_i22] = c9_b_path_yo[c9_i22];
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportEndingSection(chartInstance->c9_RuntimeVar, 0, 1);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportEndingEventBroadcast(chartInstance->c9_RuntimeVar, 18U, 11);
  }

  for (c9_i23 = 0; c9_i23 < 1500; c9_i23++) {
    covrtSigUpdateFcn(chartInstance->c9_covrtInstance, 5U,
                      (*chartInstance->c9_path_xo)[c9_i23]);
  }

  for (c9_i24 = 0; c9_i24 < 1500; c9_i24++) {
    covrtSigUpdateFcn(chartInstance->c9_covrtInstance, 6U,
                      (*chartInstance->c9_path_yo)[c9_i24]);
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_path);
}

static void ext_mode_exec_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_update_jit_animation_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_do_animation_call_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_st;
  c9_st = NULL;
  c9_st = NULL;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_createcellmatrix(5, 1), false);
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", *chartInstance->c9_path_xo, 0, 0U, 1,
    0U, 2, 1, 1500), false);
  sf_mex_setcell(c9_d_y, 0, c9_e_y);
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", *chartInstance->c9_path_yo, 0, 0U, 1,
    0U, 2, 1, 1500), false);
  sf_mex_setcell(c9_d_y, 1, c9_f_y);
  c9_g_y = NULL;
  if (!chartInstance->c9_out_path_not_empty) {
    sf_mex_assign(&c9_g_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_g_y, sf_mex_create("y", chartInstance->c9_out_path, 0, 0U,
      1, 0U, 2, 2, 1500), false);
  }

  sf_mex_setcell(c9_d_y, 2, c9_g_y);
  c9_h_y = NULL;
  if (!chartInstance->c9_path_x_not_empty) {
    sf_mex_assign(&c9_h_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_h_y, sf_mex_create("y", chartInstance->c9_path_x, 0, 0U, 1,
      0U, 2, 1, 1500), false);
  }

  sf_mex_setcell(c9_d_y, 3, c9_h_y);
  c9_i_y = NULL;
  if (!chartInstance->c9_path_x_not_empty) {
    sf_mex_assign(&c9_i_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_i_y, sf_mex_create("y", chartInstance->c9_path_y, 0, 0U, 1,
      0U, 2, 1, 1500), false);
  }

  sf_mex_setcell(c9_d_y, 4, c9_i_y);
  sf_mex_assign(&c9_st, c9_d_y, false);
  return c9_st;
}

static void set_sim_state_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_b_u;
  real_T c9_dv2[3000];
  real_T c9_b_dv[1500];
  real_T c9_dv1[1500];
  real_T c9_dv3[1500];
  real_T c9_dv4[1500];
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_b_u = sf_mex_dup(c9_st);
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_b_u, 0)),
                        "path_xo", c9_b_dv);
  for (c9_i = 0; c9_i < 1500; c9_i++) {
    (*chartInstance->c9_path_xo)[c9_i] = c9_b_dv[c9_i];
  }

  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_b_u, 1)),
                        "path_yo", c9_dv1);
  for (c9_i1 = 0; c9_i1 < 1500; c9_i1++) {
    (*chartInstance->c9_path_yo)[c9_i1] = c9_dv1[c9_i1];
  }

  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_b_u, 2)),
                        "out_path", &chartInstance->c9_out_path_not_empty,
                        c9_dv2);
  for (c9_i2 = 0; c9_i2 < 3000; c9_i2++) {
    chartInstance->c9_out_path[c9_i2] = c9_dv2[c9_i2];
  }

  c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_b_u, 3)),
                        "path_x", &chartInstance->c9_path_x_not_empty, c9_dv3);
  for (c9_i3 = 0; c9_i3 < 1500; c9_i3++) {
    chartInstance->c9_path_x[c9_i3] = c9_dv3[c9_i3];
  }

  c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_b_u, 4)),
                        "path_y", &chartInstance->c9_path_y_not_empty, c9_dv4);
  for (c9_i4 = 0; c9_i4 < 1500; c9_i4++) {
    chartInstance->c9_path_y[c9_i4] = c9_dv4[c9_i4];
  }

  sf_mex_destroy(&c9_b_u);
  sf_mex_destroy(&c9_st);
}

static void c9_initialize_debuginfo_c9_sl_groundvehicleDynamics
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  uint32_T c9_uv[3];
  uint32_T c9_uv1[3];
  const char_T *c9_sv[3];
  void *c9_rv[3];
  void *c9_rv1[3];
  void *c9_rv2[3];
  c9_uv[0] = 0U;
  c9_uv[1] = 0U;
  c9_uv[2] = 0U;
  c9_rv[0] = (void *)&c9_sf_marshallIn_matrix1x1500_real_T_persistent;
  c9_rv[1] = (void *)&c9_sf_marshallIn_matrix1x1500_real_T_persistent;
  c9_rv[2] = (void *)&c9_sf_marshallIn_matrix2x1500_real_T_persistent;
  c9_rv1[0] = (void *)&c9_sf_marshallOut_matrix1x1500_real_T_persistent;
  c9_rv1[1] = (void *)&c9_sf_marshallOut_matrix1x1500_real_T_persistent;
  c9_rv1[2] = (void *)&c9_sf_marshallOut_matrix2x1500_real_T_persistent;
  c9_rv2[0] = (void *)&chartInstance->c9_path_x;
  c9_rv2[1] = (void *)&chartInstance->c9_path_y;
  c9_rv2[2] = (void *)&chartInstance->c9_out_path;
  c9_uv1[0] = 0U;
  c9_uv1[1] = 0U;
  c9_uv1[2] = 0U;
  c9_sv[0] = "path_x";
  c9_sv[1] = "path_y";
  c9_sv[2] = "out_path";
  sfListenerPushScopeForChartJitOff(chartInstance->c9_RuntimeVar, 0U, 3U,
    &c9_sv[0U], &c9_uv1[0U], &c9_rv2[0U], &c9_rv1[0U], &c9_rv[0U], &c9_uv[0U]);
}

static void c9_test(SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                    const emlrtStack *c9_sp, boolean_T c9_b_logical_map[213200],
                    real_T c9_start[2], real_T c9_goal[2],
                    c9_coder_array_real_T_2D *c9_b_out_path)
{
  static char_T c9_b_cv1[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e',
    'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c9_b_cv[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'r', 'i',
    'd', '2', 'w', 'o', 'r', 'l', 'd', ':', 'i', 'n', 'c', 'o', 'r', 'r', 'e',
    'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  c9_binaryOccupancyMap *c9_obj;
  c9_coder_array_real_T_2D c9_grid_path;
  c9_coder_array_real_T_2D c9_idx;
  c9_coder_array_real_T_2D c9_n_x;
  c9_coder_array_real_T_2D c9_path;
  c9_coder_array_real_T_2D c9_pos;
  c9_coder_array_real_T_2D c9_r;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  const mxArray *c9_l_y = NULL;
  const mxArray *c9_m_y = NULL;
  const mxArray *c9_n_y = NULL;
  real_T c9_b_dv[2];
  real_T c9_b_goal[2];
  real_T c9_b_start[2];
  real_T c9_b_x[2];
  real_T c9_d_x[2];
  real_T c9_dv1[2];
  real_T c9_path_goal[2];
  real_T c9_path_start[2];
  real_T c9_b_u;
  real_T c9_c_x;
  real_T c9_d;
  real_T c9_e_x;
  real_T c9_f_k;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_k_y;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 1.0;
  real_T c9_o_x;
  real_T c9_p_x;
  int32_T c9_b_k;
  int32_T c9_b_loop_ub;
  int32_T c9_c_k;
  int32_T c9_c_loop_ub;
  int32_T c9_d_k;
  int32_T c9_d_loop_ub;
  int32_T c9_e_k;
  int32_T c9_e_loop_ub;
  int32_T c9_g_k;
  int32_T c9_h_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_k;
  int32_T c9_loop_ub;
  int32_T c9_nx;
  boolean_T c9_b1;
  boolean_T c9_b2;
  boolean_T c9_b3;
  boolean_T c9_b4;
  boolean_T c9_b_b;
  boolean_T c9_b_p;
  boolean_T c9_c_b;
  boolean_T c9_c_p;
  boolean_T c9_d_b;
  boolean_T c9_e_b;
  boolean_T c9_exitg1;
  boolean_T c9_p;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_grid_path);
  c9_array_real_T_2D_Constructor(chartInstance, &c9_path);
  chartInstance->c9_numFcnVars = 7U;
  chartInstance->c9_fcnDataPtrs[0] = (void *)c9_b_logical_map;
  chartInstance->c9_fcnDataPtrs[1] = (void *)c9_start;
  chartInstance->c9_fcnDataPtrs[2] = (void *)c9_goal;
  chartInstance->c9_fcnDataPtrs[3] = (void *)&c9_path_start;
  chartInstance->c9_fcnDataPtrs[4] = (void *)&c9_path_goal;
  chartInstance->c9_fcnDataPtrs[5] = (void *)&c9_nargin;
  chartInstance->c9_fcnDataPtrs[6] = (void *)&c9_nargout;
  chartInstance->c9_statuses[0] = 0U;
  chartInstance->c9_statuses[1] = 0U;
  chartInstance->c9_statuses[2] = 0U;
  chartInstance->c9_statuses[3] = 0U;
  chartInstance->c9_statuses[4] = 0U;
  chartInstance->c9_statuses[5] = 0U;
  chartInstance->c9_statuses[6] = 0U;
  chartInstance->c9_inMexFcns[0] = (void *)
    &c9_sf_marshallIn_matrix410x520_boolean_T;
  chartInstance->c9_inMexFcns[1] = (void *)&c9_sf_marshallIn_matrix1x2_real_T;
  chartInstance->c9_inMexFcns[2] = (void *)&c9_sf_marshallIn_matrix1x2_real_T;
  chartInstance->c9_inMexFcns[3] = (void *)&c9_sf_marshallIn_matrix1x2_real_T;
  chartInstance->c9_inMexFcns[4] = (void *)&c9_sf_marshallIn_matrix1x2_real_T;
  chartInstance->c9_inMexFcns[5] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_inMexFcns[6] = (void *)&c9_sf_marshallIn_real_T;
  chartInstance->c9_outMexFcns[0] = (void *)
    &c9_sf_marshallOut_matrix410x520_boolean_T;
  chartInstance->c9_outMexFcns[1] = (void *)&c9_sf_marshallOut_matrix1x2_real_T;
  chartInstance->c9_outMexFcns[2] = (void *)&c9_sf_marshallOut_matrix1x2_real_T;
  chartInstance->c9_outMexFcns[3] = (void *)&c9_sf_marshallOut_matrix1x2_real_T;
  chartInstance->c9_outMexFcns[4] = (void *)&c9_sf_marshallOut_matrix1x2_real_T;
  chartInstance->c9_outMexFcns[5] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_outMexFcns[6] = (void *)&c9_sf_marshallOut_real_T;
  chartInstance->c9_ssIds[0] = 0U;
  chartInstance->c9_ssIds[1] = 0U;
  chartInstance->c9_ssIds[2] = 0U;
  chartInstance->c9_ssIds[3] = 0U;
  chartInstance->c9_ssIds[4] = 0U;
  chartInstance->c9_ssIds[5] = 0U;
  chartInstance->c9_ssIds[6] = 0U;
  chartInstance->c9_dataNames[0] = "logical_map";
  chartInstance->c9_dataNames[1] = "start";
  chartInstance->c9_dataNames[2] = "goal";
  chartInstance->c9_dataNames[3] = "path_start";
  chartInstance->c9_dataNames[4] = "path_goal";
  chartInstance->c9_dataNames[5] = "nargin";
  chartInstance->c9_dataNames[6] = "nargout";
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportScriptName(chartInstance->c9_RuntimeVar,
      "C:/Users/jeff/Qepoxy Dropbox/Jeff whitford/EGH446/egh446_simEnv2024/sim_env/AutoSystems446/test.m",
      "", "test");
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportStartingSection(chartInstance->c9_RuntimeVar, 0, 4);
  }

  covrtEmlFcnEval(chartInstance->c9_covrtInstance, 14U, 0, 0);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 4);
  }

  c9_st.site = &c9_b_emlrtRSI;
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    chartInstance->c9_logical_map[c9_i] = c9_b_logical_map[c9_i];
  }

  c9_binaryOccupancyMap_binaryOccupancyMap(chartInstance,
    &chartInstance->c9_occupancy_map, chartInstance->c9_logical_map);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 7);
  }

  c9_b_start[0] = c9_start[0];
  c9_b_start[1] = c9_start[1];
  c9_st.site = &c9_c_emlrtRSI;
  c9_MapInterface_world2grid(chartInstance, &chartInstance->c9_occupancy_map,
    c9_b_start, c9_b_dv);
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_path_start[c9_i1] = c9_b_dv[c9_i1];
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 8);
  }

  c9_b_goal[0] = c9_goal[0];
  c9_b_goal[1] = c9_goal[1];
  c9_st.site = &c9_d_emlrtRSI;
  c9_MapInterface_world2grid(chartInstance, &chartInstance->c9_occupancy_map,
    c9_b_goal, c9_dv1);
  for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
    c9_path_goal[c9_i2] = c9_dv1[c9_i2];
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 10);
  }

  c9_st.site = &c9_e_emlrtRSI;
  c9_plannerAStarGrid_plannerAStarGrid(chartInstance, &c9_st,
    &chartInstance->c9_planner, &chartInstance->c9_occupancy_map);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 11);
  }

  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    c9_b_x[c9_i3] = c9_path_start[c9_i3];
  }

  for (c9_k = 0; c9_k < 2; c9_k++) {
    c9_b_k = c9_k;
    c9_c_x = c9_b_x[c9_b_k];
    c9_e_x = c9_c_x;
    c9_e_x = muDoubleScalarRound(c9_e_x);
    c9_b_x[c9_b_k] = c9_e_x;
  }

  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    c9_d_x[c9_i4] = c9_path_goal[c9_i4];
  }

  for (c9_c_k = 0; c9_c_k < 2; c9_c_k++) {
    c9_d_k = c9_c_k;
    c9_f_x = c9_d_x[c9_d_k];
    c9_g_x = c9_f_x;
    c9_g_x = muDoubleScalarRound(c9_g_x);
    c9_d_x[c9_d_k] = c9_g_x;
  }

  c9_array_real_T_2D_Constructor(chartInstance, &c9_r);
  c9_st.site = &c9_f_emlrtRSI;
  c9_plannerAStarGrid_plan(chartInstance, &c9_st, &chartInstance->c9_planner,
    c9_b_x, c9_d_x, &c9_r);
  c9_st.site = &c9_f_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_grid_path, &c9_emlrtRTEI,
    c9_r.size[0], c9_r.size[1]);
  c9_loop_ub = c9_r.size[0] * c9_r.size[1] - 1;
  for (c9_i5 = 0; c9_i5 <= c9_loop_ub; c9_i5++) {
    c9_grid_path.vector.data[c9_i5] = c9_r.vector.data[c9_i5];
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_r);
  sfListenerPushScopeForDynamicMatricesJitOff(chartInstance->c9_RuntimeVar, 0U,
    "grid_path", &c9_grid_path, (void *)&c9_sf_marshallOut_dynamicmatrix_1,
    (void *)&c9_sf_marshallIn_dynamicmatrix_1, 0U);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 13);
  }

  c9_array_real_T_2D_Constructor(chartInstance, &c9_pos);
  c9_st.site = &c9_g_emlrtRSI;
  c9_obj = &chartInstance->c9_occupancy_map;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_idx);
  c9_b_st.site = &c9_g_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_b_st, &c9_idx, &c9_b_emlrtRTEI,
    c9_grid_path.size[0], c9_grid_path.size[1]);
  c9_b_loop_ub = c9_grid_path.size[0] * c9_grid_path.size[1] - 1;
  for (c9_i6 = 0; c9_i6 <= c9_b_loop_ub; c9_i6++) {
    c9_idx.vector.data[c9_i6] = c9_grid_path.vector.data[c9_i6];
  }

  c9_b_st.site = &c9_ag_emlrtRSI;
  c9_c_st.site = &c9_pc_emlrtRSI;
  c9_p = true;
  c9_d = (real_T)(c9_idx.size[0] * c9_idx.size[1]);
  c9_i7 = (int32_T)c9_d - 1;
  c9_e_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_e_k <= c9_i7)) {
    c9_f_k = (real_T)c9_e_k + 1.0;
    c9_h_x = c9_idx.vector.data[(int32_T)c9_f_k - 1];
    c9_i_x = c9_h_x;
    c9_j_x = c9_i_x;
    c9_c_b = muDoubleScalarIsInf(c9_j_x);
    c9_b1 = !c9_c_b;
    c9_k_x = c9_i_x;
    c9_d_b = muDoubleScalarIsNaN(c9_k_x);
    c9_b4 = !c9_d_b;
    c9_e_b = (c9_b1 && c9_b4);
    if (c9_e_b) {
      c9_l_x = c9_h_x;
      c9_m_x = c9_l_x;
      c9_k_y = c9_m_x;
      c9_k_y = muDoubleScalarFloor(c9_k_y);
      if (c9_k_y == c9_h_x) {
        c9_b_p = true;
      } else {
        c9_b_p = false;
      }
    } else {
      c9_b_p = false;
    }

    c9_c_p = c9_b_p;
    if (c9_c_p) {
      c9_e_k++;
    } else {
      c9_p = false;
      c9_exitg1 = true;
    }
  }

  if (c9_p) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (!c9_b_b) {
    c9_d_y = NULL;
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_cv3, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv4, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c9_f_y = NULL;
    sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_cv, 10, 0U, 1, 0U, 2, 1, 20),
                  false);
    sf_mex_call(&c9_c_st, &c9_l_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 2U, 14, c9_e_y, 14, c9_f_y)));
  }

  c9_c_st.site = &c9_pc_emlrtRSI;
  c9_b2 = (c9_idx.size[0] == 0);
  c9_b3 = (c9_idx.size[1] == 0);
  if ((!!c9_b2) || (!!c9_b3)) {
    c9_g_y = NULL;
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c9_h_y = NULL;
    sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_cv2, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c9_j_y = NULL;
    sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_cv, 10, 0U, 1, 0U, 2, 1, 20),
                  false);
    sf_mex_call(&c9_c_st, &c9_v_emlrtMCI, "error", 0U, 2U, 14, c9_g_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 2U, 14, c9_h_y, 14, c9_j_y)));
  }

  c9_c_st.site = &c9_pc_emlrtRSI;
  if (!((real_T)c9_idx.size[1] == 2.0)) {
    c9_i_y = NULL;
    sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c9_l_y = NULL;
    sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_b_cv1, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c9_m_y = NULL;
    sf_mex_assign(&c9_m_y, sf_mex_create("y", c9_cv, 10, 0U, 1, 0U, 2, 1, 20),
                  false);
    c9_b_u = 2.0;
    c9_n_y = NULL;
    sf_mex_assign(&c9_n_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(&c9_c_st, &c9_x_emlrtMCI, "error", 0U, 2U, 14, c9_i_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 3U, 14, c9_l_y, 14, c9_m_y, 14, c9_n_y)));
  }

  c9_b_st.site = &c9_bg_emlrtRSI;
  c9_b_MapInterface_grid2worldImpl(chartInstance, &c9_b_st, c9_obj, &c9_idx,
    &c9_pos);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_idx);
  c9_st.site = &c9_g_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_path, &c9_c_emlrtRTEI, 2,
    c9_pos.size[0]);
  c9_c_loop_ub = c9_pos.size[0] - 1;
  for (c9_i8 = 0; c9_i8 <= c9_c_loop_ub; c9_i8++) {
    for (c9_i9 = 0; c9_i9 < 2; c9_i9++) {
      c9_path.vector.data[c9_i9 + (c9_i8 << 1)] = c9_pos.vector.data[c9_i8 +
        c9_pos.size[0] * c9_i9];
    }
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_pos);
  sfListenerPushScopeForDynamicMatricesJitOff(chartInstance->c9_RuntimeVar, 0U,
    "path", &c9_path, (void *)&c9_sf_marshallOut_dynamicmatrix, (void *)
    &c9_sf_marshallIn_dynamicmatrix, 0U);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 15);
  }

  c9_array_real_T_2D_Constructor(chartInstance, &c9_n_x);
  c9_st.site = &c9_mg_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_n_x, &c9_d_emlrtRTEI, 2,
    c9_path.size[1]);
  c9_d_loop_ub = (c9_path.size[1] << 1) - 1;
  for (c9_i10 = 0; c9_i10 <= c9_d_loop_ub; c9_i10++) {
    c9_n_x.vector.data[c9_i10] = c9_path.vector.data[c9_i10];
  }

  c9_array_real_T_2D_SetSize(chartInstance, c9_sp, c9_b_out_path,
    &c9_e_emlrtRTEI, 2, c9_n_x.size[1]);
  c9_e_loop_ub = (c9_n_x.size[1] << 1) - 1;
  for (c9_i11 = 0; c9_i11 <= c9_e_loop_ub; c9_i11++) {
    c9_b_out_path->vector.data[c9_i11] = c9_n_x.vector.data[c9_i11];
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_n_x);
  c9_nx = (c9_b_out_path->size[1] << 1) - 1;
  for (c9_g_k = 0; c9_g_k <= c9_nx; c9_g_k++) {
    c9_h_k = c9_g_k;
    c9_o_x = c9_b_out_path->vector.data[c9_h_k];
    c9_p_x = c9_o_x;
    c9_p_x = muDoubleScalarRound(c9_p_x);
    c9_b_out_path->vector.data[c9_h_k] = c9_p_x;
  }

  sfListenerPushScopeForDynamicMatricesJitOff(chartInstance->c9_RuntimeVar, 0U,
    "out_path", c9_b_out_path, (void *)&c9_sf_marshallOut_dynamicmatrix, (void *)
    &c9_sf_marshallIn_dynamicmatrix, 0U);
  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, 17);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportLineNumber(chartInstance->c9_RuntimeVar, 0, -17);
  }

  if ((chartInstance->c9_IsDebuggerActive == 1) ||
      (chartInstance->c9_IsSequenceViewerPresent == 1) ||
      (chartInstance->c9_IsHeatMapPresent == 1)) {
    sfListenerReportEndingSection(chartInstance->c9_RuntimeVar, 0, 4);
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_path);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_grid_path);
}

static c9_binaryOccupancyMap *c9_binaryOccupancyMap_binaryOccupancyMap
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_binaryOccupancyMap *c9_obj, boolean_T c9_b_varargin_1[213200])
{
  static char_T c9_b_cv[7] = { 'l', 'o', 'g', 'i', 'c', 'a', 'l' };

  c9_binaryOccupancyMap *c9_b_obj;
  c9_binaryOccupancyMap *c9_c_obj;
  c9_binaryOccupancyMap *c9_d_obj;
  c9_binaryOccupancyMap *c9_e_obj;
  c9_binaryOccupancyMap *c9_f_obj;
  c9_binaryOccupancyMap *c9_g_obj;
  c9_binaryOccupancyMap *c9_h_obj;
  c9_binaryOccupancyMap *c9_n_obj;
  c9_binaryOccupancyMap *c9_o_obj;
  c9_binaryOccupancyMap *c9_p_obj;
  c9_binaryOccupancyMap *c9_q_obj;
  c9_binaryOccupancyMap *c9_r_obj;
  c9_binaryOccupancyMap *c9_s_obj;
  c9_binaryOccupancyMap *c9_this;
  c9_matlabshared_autonomous_internal_CircularBuffer *c9_c_this;
  c9_matlabshared_autonomous_internal_CircularBuffer *c9_k_obj;
  c9_matlabshared_autonomous_internal_CircularBuffer *c9_l_obj;
  c9_matlabshared_autonomous_internal_CircularBuffer *c9_m_obj;
  c9_matlabshared_autonomous_internal_CircularBuffer *c9_t_obj;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_b_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_b_this;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_c_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_d_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_i_obj;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_j_obj;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_r;
  real_T c9_d_y[2];
  real_T c9_b_x;
  real_T c9_c_x;
  int32_T c9_b_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_k;
  boolean_T c9_b_a;
  boolean_T c9_constVal;
  c9_b_obj = c9_obj;
  c9_c_obj = c9_b_obj;
  c9_b_obj = c9_c_obj;
  c9_b_obj->HasParent = false;
  c9_d_obj = c9_b_obj;
  c9_b_obj = c9_d_obj;
  c9_e_obj = c9_b_obj;
  c9_b_obj = c9_e_obj;
  c9_this = c9_b_obj;
  c9_b_obj = c9_this;
  c9_b_obj->UseGPU = false;
  c9_f_obj = c9_b_obj;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_f_obj->SharedProperties.GridOriginInLocal[c9_i] = 0.0;
  }

  c9_g_obj = c9_b_obj;
  c9_h_obj = c9_g_obj;
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_h_obj->SharedProperties.LocalOriginInWorld[c9_i1] = 0.0;
  }

  for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
    c9_d_y[c9_i2] = -0.5;
  }

  for (c9_k = 0; c9_k < 2; c9_k++) {
    c9_b_k = c9_k;
    c9_b_x = c9_d_y[c9_b_k];
    c9_c_x = c9_b_x;
    c9_c_x = muDoubleScalarCeil(c9_c_x);
    c9_d_y[c9_b_k] = c9_c_x;
  }

  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    c9_h_obj->SharedProperties.LocalOriginInWorldInternal[c9_i3] = c9_d_y[c9_i3]
      / 10.0;
  }

  c9_i_obj = &c9_b_obj->_pobj0;
  c9_index = c9_i_obj;
  c9_j_obj = c9_index;
  c9_index = c9_j_obj;
  c9_b_this = c9_index;
  c9_index = c9_b_this;
  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    c9_index->Head[c9_i4] = 1.0;
  }

  c9_index->DropEntireMap = false;
  for (c9_i5 = 0; c9_i5 < 4; c9_i5++) {
    c9_index->NewRegions[c9_i5] = 0.0;
  }

  for (c9_i6 = 0; c9_i6 < 2; c9_i6++) {
    c9_index->DropTwoRegions[c9_i6] = false;
  }

  c9_b_obj->DefaultValueInternal = false;
  c9_k_obj = &c9_b_obj->Buffer;
  c9_b_index = c9_index;
  c9_constVal = c9_b_obj->DefaultValueInternal;
  c9_l_obj = c9_k_obj;
  c9_b_a = c9_constVal;
  for (c9_i7 = 0; c9_i7 < 213200; c9_i7++) {
    chartInstance->c9_mat[c9_i7] = c9_b_a;
  }

  c9_m_obj = c9_l_obj;
  c9_l_obj = c9_m_obj;
  c9_c_this = c9_l_obj;
  c9_l_obj = c9_c_this;
  c9_l_obj->Index = c9_b_index;
  c9_l_obj->ConstVal = c9_constVal;
  for (c9_i8 = 0; c9_i8 < 7; c9_i8++) {
    c9_l_obj->DataType[c9_i8] = c9_b_cv[c9_i8];
  }

  for (c9_i9 = 0; c9_i9 < 213200; c9_i9++) {
    c9_l_obj->Buffer[c9_i9] = chartInstance->c9_mat[c9_i9];
  }

  c9_n_obj = c9_b_obj;
  c9_o_obj = c9_n_obj;
  c9_p_obj = c9_o_obj;
  c9_q_obj = c9_p_obj;
  for (c9_i10 = 0; c9_i10 < 213200; c9_i10++) {
    c9_q_obj->Buffer.Buffer[c9_i10] = c9_b_varargin_1[c9_i10];
  }

  c9_r_obj = c9_q_obj;
  c9_r = c9_r_obj->Buffer.Index;
  for (c9_i11 = 0; c9_i11 < 2; c9_i11++) {
    c9_r->Head[c9_i11] = 1.0;
  }

  c9_s_obj = c9_q_obj;
  c9_c_index = c9_r;
  c9_t_obj = &c9_s_obj->Buffer;
  c9_d_index = c9_c_index;
  c9_t_obj->Index = c9_d_index;
  return c9_b_obj;
}

static void c9_MapInterface_world2grid
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_binaryOccupancyMap *c9_obj, real_T c9_pos[2], real_T c9_idx[2])
{
  c9_binaryOccupancyMap *c9_b_obj;
  c9_binaryOccupancyMap *c9_c_obj;
  c9_binaryOccupancyMap *c9_d_obj;
  real_T c9_b_a[4];
  real_T c9_c_x[4];
  real_T c9_gOrig[2];
  real_T c9_gridXY[2];
  real_T c9_locWorld[2];
  real_T c9_xlimit[2];
  real_T c9_ylimit[2];
  real_T c9_absx;
  real_T c9_b_r;
  real_T c9_b_x;
  real_T c9_d_x;
  real_T c9_d_y;
  real_T c9_e_x;
  real_T c9_e_y;
  real_T c9_ex;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_k;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_maxval;
  real_T c9_n_x;
  real_T c9_o_x;
  real_T c9_p_x;
  real_T c9_q_x;
  real_T c9_r;
  real_T c9_r_x;
  int32_T c9_b_exponent;
  int32_T c9_b_i;
  int32_T c9_b_idx;
  int32_T c9_b_k;
  int32_T c9_c_k;
  int32_T c9_d_k;
  int32_T c9_e_k;
  int32_T c9_end;
  int32_T c9_exponent;
  int32_T c9_f_k;
  int32_T c9_first;
  int32_T c9_g_k;
  int32_T c9_h_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i_k;
  int32_T c9_k;
  boolean_T c9_s_x[2];
  boolean_T c9_x_data[2];
  boolean_T c9_b1;
  boolean_T c9_b2;
  boolean_T c9_b_b;
  boolean_T c9_b_p;
  boolean_T c9_c_b;
  boolean_T c9_d_b;
  boolean_T c9_e_b;
  boolean_T c9_exitg1;
  boolean_T c9_f_b;
  boolean_T c9_f_y;
  boolean_T c9_g_b;
  boolean_T c9_p;
  (void)chartInstance;
  c9_b_obj = c9_obj;
  c9_c_obj = c9_b_obj;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_locWorld[c9_i] = c9_c_obj->SharedProperties.LocalOriginInWorld[c9_i];
  }

  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_locWorld[c9_i1] = c9_pos[c9_i1] - c9_locWorld[c9_i1];
  }

  c9_d_obj = c9_b_obj;
  for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
    c9_gOrig[c9_i2] = c9_d_obj->SharedProperties.GridOriginInLocal[c9_i2];
  }

  c9_xlimit[0] = c9_gOrig[0];
  c9_xlimit[1] = c9_gOrig[0] + 52.0;
  c9_ylimit[0] = c9_gOrig[1];
  c9_ylimit[1] = c9_gOrig[1] + 41.0;
  c9_gridXY[0] = -c9_ylimit[0] + c9_locWorld[1];
  c9_gridXY[1] = -c9_xlimit[0] + c9_locWorld[0];
  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    c9_gridXY[c9_i3] *= 10.0;
  }

  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    c9_idx[c9_i4] = c9_gridXY[c9_i4];
  }

  for (c9_k = 0; c9_k < 2; c9_k++) {
    c9_b_k = c9_k;
    c9_b_x = c9_idx[c9_b_k];
    c9_d_x = c9_b_x;
    c9_d_x = muDoubleScalarCeil(c9_d_x);
    c9_idx[c9_b_k] = c9_d_x;
  }

  for (c9_i5 = 0; c9_i5 < 2; c9_i5++) {
    c9_c_x[c9_i5] = c9_xlimit[c9_i5];
  }

  for (c9_i6 = 0; c9_i6 < 2; c9_i6++) {
    c9_c_x[c9_i6 + 2] = c9_ylimit[c9_i6];
  }

  for (c9_c_k = 0; c9_c_k < 4; c9_c_k++) {
    c9_d_k = c9_c_k;
    c9_e_x = c9_c_x[c9_d_k];
    c9_d_y = muDoubleScalarAbs(c9_e_x);
    c9_b_a[c9_d_k] = c9_d_y;
  }

  for (c9_i7 = 0; c9_i7 < 4; c9_i7++) {
    c9_b_a[c9_i7] *= 10.0;
  }

  c9_f_x = c9_b_a[0];
  c9_g_x = c9_f_x;
  c9_b_b = muDoubleScalarIsNaN(c9_g_x);
  c9_p = !c9_b_b;
  if (c9_p) {
    c9_b_idx = 1;
  } else {
    c9_b_idx = 0;
    c9_e_k = 2;
    c9_exitg1 = false;
    while ((!c9_exitg1) && (c9_e_k < 5)) {
      c9_h_x = c9_b_a[c9_e_k - 1];
      c9_i_x = c9_h_x;
      c9_c_b = muDoubleScalarIsNaN(c9_i_x);
      c9_b_p = !c9_c_b;
      if (c9_b_p) {
        c9_b_idx = c9_e_k;
        c9_exitg1 = true;
      } else {
        c9_e_k++;
      }
    }
  }

  if (c9_b_idx == 0) {
    c9_maxval = c9_b_a[0];
  } else {
    c9_first = c9_b_idx - 1;
    c9_ex = c9_b_a[c9_first];
    c9_i8 = c9_first;
    for (c9_g_k = c9_i8 + 2; c9_g_k < 5; c9_g_k++) {
      if (c9_ex < c9_b_a[c9_g_k - 1]) {
        c9_ex = c9_b_a[c9_g_k - 1];
      }
    }

    c9_maxval = c9_ex;
  }

  for (c9_f_k = 0; c9_f_k < 2; c9_f_k++) {
    c9_h_k = c9_f_k;
    c9_l_x = c9_gridXY[c9_h_k];
    c9_e_y = muDoubleScalarAbs(c9_l_x);
    c9_gOrig[c9_h_k] = c9_e_y;
  }

  c9_j_x = c9_maxval;
  c9_k_x = c9_j_x;
  c9_m_x = c9_k_x;
  c9_n_x = c9_m_x;
  c9_o_x = c9_n_x;
  c9_absx = muDoubleScalarAbs(c9_o_x);
  c9_p_x = c9_absx;
  c9_q_x = c9_p_x;
  c9_d_b = muDoubleScalarIsInf(c9_q_x);
  c9_e_b = !c9_d_b;
  c9_r_x = c9_p_x;
  c9_f_b = muDoubleScalarIsNaN(c9_r_x);
  c9_b1 = !c9_f_b;
  c9_g_b = (c9_e_b && c9_b1);
  if (!c9_g_b) {
    c9_r = rtNaN;
  } else if (c9_absx < 4.4501477170144028E-308) {
    c9_r = 4.94065645841247E-324;
  } else {
    frexp(c9_absx, &c9_exponent);
    c9_b_exponent = c9_exponent;
    c9_r = ldexp(1.0, c9_b_exponent - 53);
  }

  c9_b_r = c9_r * 2.0;
  for (c9_i9 = 0; c9_i9 < 2; c9_i9++) {
    c9_s_x[c9_i9] = (c9_gOrig[c9_i9] < c9_b_r);
  }

  for (c9_i10 = 0; c9_i10 < 2; c9_i10++) {
    c9_x_data[c9_i10] = c9_s_x[c9_i10];
  }

  c9_f_y = false;
  c9_i_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_i_k < 2)) {
    c9_j_k = (real_T)c9_i_k + 1.0;
    if (!c9_x_data[(int32_T)c9_j_k - 1]) {
      c9_b2 = true;
    } else {
      c9_b2 = false;
    }

    if (!c9_b2) {
      c9_f_y = true;
      c9_exitg1 = true;
    } else {
      c9_i_k++;
    }
  }

  if (c9_f_y) {
    c9_end = 2;
    for (c9_b_i = 0; c9_b_i < c9_end; c9_b_i++) {
      if (c9_gOrig[c9_b_i] < c9_r * 2.0) {
        c9_idx[c9_b_i] = 1.0;
      }
    }
  }

  c9_idx[0] = 411.0 - c9_idx[0];
}

static c9_plannerAStarGrid *c9_plannerAStarGrid_plannerAStarGrid
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_binaryOccupancyMap *c9_b_varargin_1)
{
  static char_T c9_b_cv[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
    's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g',
    'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e', 't',
    'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o',
    'n' };

  static char_T c9_b_cv2[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e',
    't', 'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i',
    'o', 'n' };

  static char_T c9_b_cv4[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e',
    't', 'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i',
    'o', 'n' };

  static char_T c9_b_cv6[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e',
    't', 'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i',
    'o', 'n' };

  static char_T c9_b_cv1[8] = { 'G', 'C', 'o', 's', 't', 'F', 'c', 'n' };

  static char_T c9_b_cv5[8] = { 'H', 'C', 'o', 's', 't', 'F', 'c', 'n' };

  static char_T c9_b_cv3[5] = { 'G', 'C', 'o', 's', 't' };

  static char_T c9_b_cv7[5] = { 'H', 'C', 'o', 's', 't' };

  c9_binaryOccupancyMap *c9_input;
  c9_plannerAStarGrid *c9_b_obj;
  c9_plannerAStarGrid *c9_c_obj;
  c9_plannerAStarGrid *c9_d_obj;
  c9_plannerAStarGrid *c9_e_obj;
  c9_plannerAStarGrid *c9_f_obj;
  c9_plannerAStarGrid *c9_g_obj;
  c9_plannerAStarGrid *c9_h_obj;
  c9_plannerAStarGrid *c9_i_obj;
  c9_plannerAStarGrid *c9_j_obj;
  c9_plannerAStarGrid *c9_k_obj;
  c9_plannerAStarGrid *c9_l_obj;
  c9_plannerAStarGrid *c9_m_obj;
  c9_plannerAStarGrid *c9_n_obj;
  c9_plannerAStarGrid *c9_o_obj;
  c9_plannerAStarGrid *c9_p_obj;
  c9_plannerAStarGrid *c9_q_obj;
  c9_plannerAStarGrid *c9_r_obj;
  c9_plannerAStarGrid *c9_this;
  emlrtStack c9_b_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  const mxArray *c9_k_y = NULL;
  const mxArray *c9_l_y = NULL;
  const mxArray *c9_m_y = NULL;
  const mxArray *c9_n_y = NULL;
  const mxArray *c9_o_y = NULL;
  real_T c9_d;
  real_T c9_d1;
  int32_T c9_a__2_size[2];
  char_T c9_a__2_data[9];
  boolean_T c9_b1;
  boolean_T c9_b2;
  boolean_T c9_b3;
  boolean_T c9_b_b;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_b_obj = c9_obj;
  c9_b_obj->isFirstRun = 1.0;
  c9_st.site = &c9_fb_emlrtRSI;
  c9_c_obj = c9_b_obj;
  c9_b_obj = c9_c_obj;
  c9_b_st.site = &c9_ob_emlrtRSI;
  c9_this = c9_b_obj;
  c9_b_obj = c9_this;
  c9_st.site = &c9_gb_emlrtRSI;
  c9_d_obj = c9_b_obj;
  c9_input = c9_b_varargin_1;
  c9_d_obj->Map = c9_input;
  c9_b_st.site = &c9_pb_emlrtRSI;
  c9_plannerAStarGrid_setInputState(chartInstance, c9_d_obj);
  c9_st.site = &c9_hb_emlrtRSI;
  c9_e_obj = c9_b_obj;
  c9_b_st.site = &c9_tb_emlrtRSI;
  c9_f_obj = c9_e_obj;
  if (c9_f_obj->isFirstRun == 0.0) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (c9_b_b) {
    c9_d_y = NULL;
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_f_y = NULL;
    sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_b_cv1, 10, 0U, 1, 0U, 2, 1, 8),
                  false);
    sf_mex_call(&c9_b_st, &c9_c_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_e_y, 14, c9_f_y)));
  }

  c9_b_st.site = &c9_ub_emlrtRSI;
  c9_g_obj = c9_e_obj;
  c9_g_obj->UseCustomG = 1.0;
  c9_st.site = &c9_ib_emlrtRSI;
  c9_h_obj = c9_b_obj;
  c9_b_st.site = &c9_vb_emlrtRSI;
  c9_i_obj = c9_h_obj;
  if (c9_i_obj->isFirstRun == 0.0) {
    c9_b1 = true;
  } else {
    c9_b1 = false;
  }

  if (c9_b1) {
    c9_g_y = NULL;
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_b_cv2, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_h_y = NULL;
    sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_b_cv2, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_i_y = NULL;
    sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_b_cv3, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c9_b_st, &c9_c_emlrtMCI, "error", 0U, 2U, 14, c9_g_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_h_y, 14, c9_i_y)));
  }

  c9_b_st.site = &c9_wb_emlrtRSI;
  c9_j_obj = c9_h_obj;
  c9_j_obj->UseCustomG = 0.0;
  c9_b_st.site = &c9_xb_emlrtRSI;
  c9_validateAStarBuiltinCostFunction(chartInstance, &c9_b_st, c9_a__2_data,
    c9_a__2_size, &c9_d);
  c9_h_obj->GCost = c9_d;
  c9_b_obj->UseCustomG = 0.0;
  c9_st.site = &c9_jb_emlrtRSI;
  c9_k_obj = c9_b_obj;
  c9_b_st.site = &c9_yb_emlrtRSI;
  c9_l_obj = c9_k_obj;
  if (c9_l_obj->isFirstRun == 0.0) {
    c9_b2 = true;
  } else {
    c9_b2 = false;
  }

  if (c9_b2) {
    c9_j_y = NULL;
    sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_b_cv4, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_k_y = NULL;
    sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_b_cv4, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_l_y = NULL;
    sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_b_cv5, 10, 0U, 1, 0U, 2, 1, 8),
                  false);
    sf_mex_call(&c9_b_st, &c9_c_emlrtMCI, "error", 0U, 2U, 14, c9_j_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_k_y, 14, c9_l_y)));
  }

  c9_b_st.site = &c9_ac_emlrtRSI;
  c9_m_obj = c9_k_obj;
  c9_m_obj->UseCustomH = 1.0;
  c9_st.site = &c9_kb_emlrtRSI;
  c9_n_obj = c9_b_obj;
  c9_b_st.site = &c9_bc_emlrtRSI;
  c9_o_obj = c9_n_obj;
  if (c9_o_obj->isFirstRun == 0.0) {
    c9_b3 = true;
  } else {
    c9_b3 = false;
  }

  if (c9_b3) {
    c9_m_y = NULL;
    sf_mex_assign(&c9_m_y, sf_mex_create("y", c9_b_cv6, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_n_y = NULL;
    sf_mex_assign(&c9_n_y, sf_mex_create("y", c9_b_cv6, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c9_o_y = NULL;
    sf_mex_assign(&c9_o_y, sf_mex_create("y", c9_b_cv7, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c9_b_st, &c9_c_emlrtMCI, "error", 0U, 2U, 14, c9_m_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_n_y, 14, c9_o_y)));
  }

  c9_b_st.site = &c9_cc_emlrtRSI;
  c9_p_obj = c9_n_obj;
  c9_p_obj->UseCustomH = 0.0;
  c9_b_st.site = &c9_dc_emlrtRSI;
  c9_validateAStarBuiltinCostFunction(chartInstance, &c9_b_st, c9_a__2_data,
    c9_a__2_size, &c9_d1);
  c9_n_obj->HCost = c9_d1;
  c9_b_obj->UseCustomH = 0.0;
  c9_st.site = &c9_lb_emlrtRSI;
  c9_b_obj->OccupiedThreshold = 0.65;
  c9_st.site = &c9_mb_emlrtRSI;
  c9_q_obj = c9_b_obj;
  c9_q_obj->TieBreaker = 0.0;
  c9_st.site = &c9_nb_emlrtRSI;
  c9_r_obj = c9_b_obj;
  c9_r_obj->DiagonalSearch = 1.0;
  c9_b_obj->isFirstRun = 0.0;
  return c9_b_obj;
}

static void c9_plannerAStarGrid_setInputState
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_plannerAStarGrid *c9_obj)
{
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  for (c9_i = 0; c9_i < 639600; c9_i++) {
    c9_obj->IdPose[c9_i] = 0.0;
  }

  for (c9_i1 = 0; c9_i1 < 213200; c9_i1++) {
    chartInstance->c9_y[c9_i1] = 1.0 + (real_T)c9_i1;
  }

  c9_ind2sub(chartInstance, chartInstance->c9_y, chartInstance->c9_varargout_4,
             chartInstance->c9_varargout_5, chartInstance->c9_varargout_6);
  for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
    chartInstance->c9_y[c9_i2] = (real_T)chartInstance->c9_varargout_4[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 213200; c9_i3++) {
    chartInstance->c9_poseIdTemp[c9_i3] = (real_T)chartInstance->
      c9_varargout_5[c9_i3];
  }

  for (c9_i4 = 0; c9_i4 < 213200; c9_i4++) {
    chartInstance->c9_dv[c9_i4] = (real_T)chartInstance->c9_varargout_6[c9_i4];
  }

  for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
    c9_obj->IdPose[c9_i5] = chartInstance->c9_y[c9_i5];
  }

  for (c9_i6 = 0; c9_i6 < 213200; c9_i6++) {
    c9_obj->IdPose[c9_i6 + 213200] = chartInstance->c9_poseIdTemp[c9_i6];
  }

  for (c9_i7 = 0; c9_i7 < 213200; c9_i7++) {
    c9_obj->IdPose[c9_i7 + 426400] = chartInstance->c9_dv[c9_i7];
  }

  for (c9_i8 = 0; c9_i8 < 213200; c9_i8++) {
    chartInstance->c9_poseIdTemp[c9_i8] = c9_obj->IdPose[c9_i8 + 213200] - 1.0;
  }

  for (c9_i9 = 0; c9_i9 < 213200; c9_i9++) {
    chartInstance->c9_poseIdTemp[c9_i9] *= 410.0;
  }

  for (c9_i10 = 0; c9_i10 < 213200; c9_i10++) {
    chartInstance->c9_y[c9_i10] = c9_obj->IdPose[c9_i10 + 426400] - 1.0;
  }

  for (c9_i11 = 0; c9_i11 < 213200; c9_i11++) {
    chartInstance->c9_y[c9_i11] *= 410.0;
  }

  for (c9_i12 = 0; c9_i12 < 213200; c9_i12++) {
    chartInstance->c9_y[c9_i12] *= 520.0;
  }

  for (c9_i13 = 0; c9_i13 < 213200; c9_i13++) {
    chartInstance->c9_poseIdTemp[c9_i13] = (c9_obj->IdPose[c9_i13] +
      chartInstance->c9_poseIdTemp[c9_i13]) + chartInstance->c9_y[c9_i13];
  }

  for (c9_i14 = 0; c9_i14 < 213200; c9_i14++) {
    c9_obj->PoseId[c9_i14] = chartInstance->c9_poseIdTemp[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 213200; c9_i15++) {
    c9_obj->NodeCostValue[c9_i15] = -1.0;
  }
}

static void c9_ind2sub(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c9_ndx[213200], int32_T c9_varargout_1[213200], int32_T
  c9_varargout_2[213200], int32_T c9_b_varargout_3[213200])
{
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    c9_varargout_1[c9_i] = (int32_T)c9_ndx[c9_i];
  }

  for (c9_i1 = 0; c9_i1 < 213200; c9_i1++) {
    c9_varargout_1[c9_i1]--;
  }

  for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
    chartInstance->c9_vk[c9_i2] = c9_div_nzp_s32(chartInstance,
      c9_varargout_1[c9_i2], 213200, 0, 0U, 0, 0);
  }

  for (c9_i3 = 0; c9_i3 < 213200; c9_i3++) {
    c9_b_varargout_3[c9_i3] = chartInstance->c9_vk[c9_i3] + 1;
  }

  for (c9_i4 = 0; c9_i4 < 213200; c9_i4++) {
    chartInstance->c9_vk[c9_i4] *= 213200;
  }

  for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
    c9_varargout_1[c9_i5] -= chartInstance->c9_vk[c9_i5];
  }

  for (c9_i6 = 0; c9_i6 < 213200; c9_i6++) {
    chartInstance->c9_vk[c9_i6] = c9_div_nzp_s32(chartInstance,
      c9_varargout_1[c9_i6], 410, 0, 0U, 0, 0);
  }

  for (c9_i7 = 0; c9_i7 < 213200; c9_i7++) {
    c9_varargout_2[c9_i7] = chartInstance->c9_vk[c9_i7] + 1;
  }

  for (c9_i8 = 0; c9_i8 < 213200; c9_i8++) {
    chartInstance->c9_vk[c9_i8] *= 410;
  }

  for (c9_i9 = 0; c9_i9 < 213200; c9_i9++) {
    c9_varargout_1[c9_i9] -= chartInstance->c9_vk[c9_i9];
  }

  for (c9_i10 = 0; c9_i10 < 213200; c9_i10++) {
    c9_varargout_1[c9_i10]++;
  }
}

static void c9_validateAStarBuiltinCostFunction
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, char_T c9_strVal_data[], int32_T c9_strVal_size[2], real_T *c9_idx)
{
  static char_T c9_b_a[9] = { 'E', 'u', 'c', 'l', 'i', 'd', 'e', 'a', 'n' };

  static char_T c9_b_cv[9] = { 'E', 'u', 'c', 'l', 'i', 'd', 'e', 'a', 'n' };

  static char_T c9_b_cv1[9] = { 'M', 'a', 'n', 'h', 'a', 't', 't', 'a', 'n' };

  static char_T c9_b_cv2[9] = { 'C', 'h', 'e', 'b', 'y', 's', 'h', 'e', 'v' };

  c9_cell_wrap_25 c9_b_b[1];
  c9_cell_wrap_25 c9_r;
  real_T c9_idxTemp_data[4];
  int32_T c9_ii_data[4];
  int32_T c9_idxTemp_size[2];
  int32_T c9_ii_size[2];
  int32_T c9_b_idx;
  int32_T c9_b_ii;
  int32_T c9_b_kstr;
  int32_T c9_c_kstr;
  int32_T c9_d_kstr;
  int32_T c9_e_kstr;
  int32_T c9_exitg1;
  int32_T c9_f_kstr;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_ii;
  int32_T c9_kstr;
  int32_T c9_loop_ub;
  char_T c9_b_data[9];
  boolean_T c9_b_x[4];
  boolean_T c9_b_bool;
  boolean_T c9_bool;
  boolean_T c9_c_b;
  boolean_T c9_c_bool;
  boolean_T c9_exitg2;
  (void)chartInstance;
  c9_strVal_size[0] = 1;
  c9_strVal_size[1] = 9;
  for (c9_i = 0; c9_i < 9; c9_i++) {
    c9_strVal_data[c9_i] = c9_b_a[c9_i];
  }

  c9_r.f1.size[0] = 1;
  c9_r.f1.size[1] = 9;
  for (c9_i1 = 0; c9_i1 < 9; c9_i1++) {
    c9_r.f1.data[c9_i1] = c9_strVal_data[c9_i1];
  }

  c9_b_b[0] = c9_r;
  for (c9_i2 = 0; c9_i2 < 9; c9_i2++) {
    c9_b_data[c9_i2] = c9_b_b[0].f1.data[c9_i2];
  }

  c9_bool = false;
  c9_kstr = 1;
  do {
    c9_exitg1 = 0;
    if (c9_kstr - 1 < 9) {
      c9_b_kstr = c9_kstr - 1;
      if (c9_b_cv[c9_b_kstr] != c9_b_data[c9_b_kstr]) {
        c9_exitg1 = 1;
      } else {
        c9_kstr++;
      }
    } else {
      c9_bool = true;
      c9_exitg1 = 1;
    }
  } while (c9_exitg1 == 0);

  c9_b_x[0] = c9_bool;
  for (c9_i3 = 0; c9_i3 < 9; c9_i3++) {
    c9_b_data[c9_i3] = c9_b_b[0].f1.data[c9_i3];
  }

  c9_b_bool = false;
  c9_c_kstr = 1;
  do {
    c9_exitg1 = 0;
    if (c9_c_kstr - 1 < 9) {
      c9_d_kstr = c9_c_kstr - 1;
      if (c9_b_cv1[c9_d_kstr] != c9_b_data[c9_d_kstr]) {
        c9_exitg1 = 1;
      } else {
        c9_c_kstr++;
      }
    } else {
      c9_b_bool = true;
      c9_exitg1 = 1;
    }
  } while (c9_exitg1 == 0);

  c9_b_x[1] = c9_b_bool;
  for (c9_i4 = 0; c9_i4 < 9; c9_i4++) {
    c9_b_data[c9_i4] = c9_b_b[0].f1.data[c9_i4];
  }

  c9_c_bool = false;
  c9_e_kstr = 1;
  do {
    c9_exitg1 = 0;
    if (c9_e_kstr - 1 < 9) {
      c9_f_kstr = c9_e_kstr - 1;
      if (c9_b_cv2[c9_f_kstr] != c9_b_data[c9_f_kstr]) {
        c9_exitg1 = 1;
      } else {
        c9_e_kstr++;
      }
    } else {
      c9_c_bool = true;
      c9_exitg1 = 1;
    }
  } while (c9_exitg1 == 0);

  c9_b_x[2] = c9_c_bool;
  c9_b_x[3] = false;
  c9_b_idx = 0;
  c9_ii = 1;
  c9_exitg2 = false;
  while ((!c9_exitg2) && (c9_ii - 1 < 4)) {
    c9_b_ii = c9_ii;
    if (c9_b_x[c9_b_ii - 1]) {
      c9_b_idx++;
      c9_ii_data[c9_b_idx - 1] = c9_b_ii;
      if (c9_b_idx >= 4) {
        c9_exitg2 = true;
      } else {
        c9_ii++;
      }
    } else {
      c9_ii++;
    }
  }

  c9_c_b = (c9_b_idx < 1);
  if (c9_c_b) {
    c9_i5 = 0;
  } else {
    c9_i5 = c9_b_idx;
  }

  c9_ii_size[1] = c9_i5;
  c9_idxTemp_size[1] = c9_ii_size[1];
  c9_loop_ub = c9_ii_size[1] - 1;
  for (c9_i6 = 0; c9_i6 <= c9_loop_ub; c9_i6++) {
    c9_idxTemp_data[c9_i6] = (real_T)c9_ii_data[c9_i6];
  }

  c9_i7 = 1;
  if ((c9_i7 < 1) || (c9_i7 > c9_idxTemp_size[1])) {
    emlrtDynamicBoundsCheckR2012b(c9_i7, 1, c9_idxTemp_size[1], &c9_d_emlrtBCI,
      (emlrtConstCTX)c9_sp);
  }

  *c9_idx = c9_idxTemp_data[0];
}

static void c9_plannerAStarGrid_plan(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, c9_plannerAStarGrid *c9_obj, real_T
  c9_start[2], real_T c9_goal[2], c9_coder_array_real_T_2D *c9_path)
{
  static char_T c9_b_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c9_b_cv10[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c9_b_cv4[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c9_b_cv7[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c9_cv12[46] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
    's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g',
    'r', 'i', 'd', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'G', 'r', 'i',
    'd', 'I', 'n', 'p', 'u', 't' };

  static char_T c9_b_cv[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l', 'a',
    'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c9_b_cv3[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l',
    'a', 'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c9_b_cv6[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l',
    'a', 'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c9_b_cv9[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l',
    'a', 'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c9_b_cv2[5] = { 'S', 't', 'a', 'r', 't' };

  static char_T c9_b_cv5[5] = { 'S', 't', 'a', 'r', 't' };

  static char_T c9_cv13[5] = { 'S', 't', 'a', 'r', 't' };

  static char_T c9_b_cv8[4] = { 'G', 'o', 'a', 'l' };

  static char_T c9_cv11[4] = { 'G', 'o', 'a', 'l' };

  static char_T c9_cv14[4] = { 'G', 'o', 'a', 'l' };

  c9_binaryOccupancyMap *c9_b_val;
  c9_binaryOccupancyMap *c9_e_map;
  c9_binaryOccupancyMap *c9_val;
  c9_plannerAStarGrid *c9_b_obj;
  c9_plannerAStarGrid *c9_c_obj;
  c9_plannerAStarGrid *c9_d_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  const mxArray *c9_k_y = NULL;
  const mxArray *c9_l_y = NULL;
  const mxArray *c9_m_y = NULL;
  const mxArray *c9_n_y = NULL;
  const mxArray *c9_o_y = NULL;
  const mxArray *c9_q_y = NULL;
  const mxArray *c9_r_y = NULL;
  const mxArray *c9_s_y = NULL;
  const mxArray *c9_u_y = NULL;
  const mxArray *c9_v_y = NULL;
  const mxArray *c9_w_y = NULL;
  const mxArray *c9_x_y = NULL;
  const mxArray *c9_y_y = NULL;
  real_T c9_b_goal[2];
  real_T c9_b_goalgrid[2];
  real_T c9_b_start[2];
  real_T c9_b_startgrid[2];
  real_T c9_e_obj[2];
  real_T c9_f_obj[2];
  real_T c9_goalgrid[2];
  real_T c9_startgrid[2];
  real_T c9_b_k;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_k;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_k;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_k;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_k;
  real_T c9_l_x;
  real_T c9_n_x;
  real_T c9_o_x;
  real_T c9_p_k;
  real_T c9_p_x;
  real_T c9_q_x;
  real_T c9_r_x;
  int32_T c9_c_k;
  int32_T c9_e_k;
  int32_T c9_g_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i_k;
  int32_T c9_j_k;
  int32_T c9_k;
  int32_T c9_k_k;
  int32_T c9_m_k;
  int32_T c9_n_k;
  int32_T c9_o_k;
  boolean_T c9_m_x[2];
  boolean_T c9_x_data[2];
  boolean_T c9_b1;
  boolean_T c9_b2;
  boolean_T c9_b3;
  boolean_T c9_b4;
  boolean_T c9_b5;
  boolean_T c9_b6;
  boolean_T c9_b7;
  boolean_T c9_b_b;
  boolean_T c9_b_p;
  boolean_T c9_c_b;
  boolean_T c9_c_p;
  boolean_T c9_d_b;
  boolean_T c9_d_p;
  boolean_T c9_e_b;
  boolean_T c9_e_p;
  boolean_T c9_exitg1;
  boolean_T c9_f_b;
  boolean_T c9_f_p;
  boolean_T c9_g_b;
  boolean_T c9_h_b;
  boolean_T c9_i_b;
  boolean_T c9_j_b;
  boolean_T c9_k_b;
  boolean_T c9_p;
  boolean_T c9_p_y;
  boolean_T c9_t_y;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_st.site = &c9_ec_emlrtRSI;
  c9_b_st.site = &c9_pc_emlrtRSI;
  c9_p = true;
  c9_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_k < 2)) {
    c9_b_k = (real_T)c9_k + 1.0;
    c9_b_x = c9_start[(int32_T)c9_b_k - 1];
    c9_c_x = c9_b_x;
    c9_c_b = muDoubleScalarIsNaN(c9_c_x);
    c9_b_p = !c9_c_b;
    if (c9_b_p) {
      c9_k++;
    } else {
      c9_p = false;
      c9_exitg1 = true;
    }
  }

  if (c9_p) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (!c9_b_b) {
    c9_d_y = NULL;
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_b_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_f_y = NULL;
    sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_b_cv2, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c9_b_st, &c9_f_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_e_y, 14, c9_f_y)));
  }

  c9_b_st.site = &c9_pc_emlrtRSI;
  c9_c_p = true;
  c9_c_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_c_k < 2)) {
    c9_d_k = (real_T)c9_c_k + 1.0;
    c9_d_x = c9_start[(int32_T)c9_d_k - 1];
    c9_e_x = c9_d_x;
    c9_d_b = muDoubleScalarIsInf(c9_e_x);
    c9_b2 = !c9_d_b;
    c9_f_x = c9_d_x;
    c9_e_b = muDoubleScalarIsNaN(c9_f_x);
    c9_b3 = !c9_e_b;
    c9_f_b = (c9_b2 && c9_b3);
    if (c9_f_b) {
      c9_c_k++;
    } else {
      c9_c_p = false;
      c9_exitg1 = true;
    }
  }

  if (c9_c_p) {
    c9_b1 = true;
  } else {
    c9_b1 = false;
  }

  if (!c9_b1) {
    c9_g_y = NULL;
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_b_cv3, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c9_h_y = NULL;
    sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_b_cv4, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_i_y = NULL;
    sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_b_cv5, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c9_b_st, &c9_g_emlrtMCI, "error", 0U, 2U, 14, c9_g_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_h_y, 14, c9_i_y)));
  }

  c9_st.site = &c9_fc_emlrtRSI;
  c9_b_st.site = &c9_pc_emlrtRSI;
  c9_d_p = true;
  c9_e_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_e_k < 2)) {
    c9_f_k = (real_T)c9_e_k + 1.0;
    c9_g_x = c9_goal[(int32_T)c9_f_k - 1];
    c9_h_x = c9_g_x;
    c9_g_b = muDoubleScalarIsNaN(c9_h_x);
    c9_e_p = !c9_g_b;
    if (c9_e_p) {
      c9_e_k++;
    } else {
      c9_d_p = false;
      c9_exitg1 = true;
    }
  }

  if (c9_d_p) {
    c9_b4 = true;
  } else {
    c9_b4 = false;
  }

  if (!c9_b4) {
    c9_j_y = NULL;
    sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_b_cv6, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c9_k_y = NULL;
    sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_b_cv7, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_l_y = NULL;
    sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_b_cv8, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c9_b_st, &c9_f_emlrtMCI, "error", 0U, 2U, 14, c9_j_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_k_y, 14, c9_l_y)));
  }

  c9_b_st.site = &c9_pc_emlrtRSI;
  c9_f_p = true;
  c9_g_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_g_k < 2)) {
    c9_h_k = (real_T)c9_g_k + 1.0;
    c9_i_x = c9_goal[(int32_T)c9_h_k - 1];
    c9_j_x = c9_i_x;
    c9_h_b = muDoubleScalarIsInf(c9_j_x);
    c9_b6 = !c9_h_b;
    c9_k_x = c9_i_x;
    c9_i_b = muDoubleScalarIsNaN(c9_k_x);
    c9_b7 = !c9_i_b;
    c9_j_b = (c9_b6 && c9_b7);
    if (c9_j_b) {
      c9_g_k++;
    } else {
      c9_f_p = false;
      c9_exitg1 = true;
    }
  }

  if (c9_f_p) {
    c9_b5 = true;
  } else {
    c9_b5 = false;
  }

  if (!c9_b5) {
    c9_m_y = NULL;
    sf_mex_assign(&c9_m_y, sf_mex_create("y", c9_b_cv9, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c9_n_y = NULL;
    sf_mex_assign(&c9_n_y, sf_mex_create("y", c9_b_cv10, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_o_y = NULL;
    sf_mex_assign(&c9_o_y, sf_mex_create("y", c9_cv11, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c9_b_st, &c9_g_emlrtMCI, "error", 0U, 2U, 14, c9_m_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 2U, 14, c9_n_y, 14, c9_o_y)));
  }

  c9_obj->IsGrid = 0.0;
  c9_obj->IsGrid = 1.0;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_startgrid[c9_i] = c9_start[c9_i];
  }

  for (c9_i_k = 0; c9_i_k < 2; c9_i_k++) {
    c9_j_k = c9_i_k;
    c9_l_x = c9_startgrid[c9_j_k];
    c9_n_x = c9_l_x;
    c9_n_x = muDoubleScalarFloor(c9_n_x);
    c9_startgrid[c9_j_k] = c9_n_x;
  }

  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_m_x[c9_i1] = (c9_start[c9_i1] == c9_startgrid[c9_i1]);
  }

  for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
    c9_x_data[c9_i2] = c9_m_x[c9_i2];
  }

  c9_p_y = true;
  c9_k_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_k_k < 2)) {
    c9_l_k = (real_T)c9_k_k + 1.0;
    if (!c9_x_data[(int32_T)c9_l_k - 1]) {
      c9_p_y = false;
      c9_exitg1 = true;
    } else {
      c9_k_k++;
    }
  }

  if (!c9_p_y) {
    c9_q_y = NULL;
    sf_mex_assign(&c9_q_y, sf_mex_create("y", c9_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_r_y = NULL;
    sf_mex_assign(&c9_r_y, sf_mex_create("y", c9_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_s_y = NULL;
    sf_mex_assign(&c9_s_y, sf_mex_create("y", c9_cv13, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(c9_sp, &c9_d_emlrtMCI, "error", 0U, 2U, 14, c9_q_y, 14,
                sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c9_sp, NULL, "message", 1U, 2U, 14, c9_r_y, 14, c9_s_y)));
  }

  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    c9_startgrid[c9_i3] = c9_goal[c9_i3];
  }

  for (c9_m_k = 0; c9_m_k < 2; c9_m_k++) {
    c9_n_k = c9_m_k;
    c9_o_x = c9_startgrid[c9_n_k];
    c9_p_x = c9_o_x;
    c9_p_x = muDoubleScalarFloor(c9_p_x);
    c9_startgrid[c9_n_k] = c9_p_x;
  }

  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    c9_m_x[c9_i4] = (c9_goal[c9_i4] == c9_startgrid[c9_i4]);
  }

  for (c9_i5 = 0; c9_i5 < 2; c9_i5++) {
    c9_x_data[c9_i5] = c9_m_x[c9_i5];
  }

  c9_t_y = true;
  c9_o_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_o_k < 2)) {
    c9_p_k = (real_T)c9_o_k + 1.0;
    if (!c9_x_data[(int32_T)c9_p_k - 1]) {
      c9_t_y = false;
      c9_exitg1 = true;
    } else {
      c9_o_k++;
    }
  }

  if (!c9_t_y) {
    c9_u_y = NULL;
    sf_mex_assign(&c9_u_y, sf_mex_create("y", c9_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_v_y = NULL;
    sf_mex_assign(&c9_v_y, sf_mex_create("y", c9_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_w_y = NULL;
    sf_mex_assign(&c9_w_y, sf_mex_create("y", c9_cv14, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c9_sp, &c9_e_emlrtMCI, "error", 0U, 2U, 14, c9_u_y, 14,
                sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c9_sp, NULL, "message", 1U, 2U, 14, c9_v_y, 14, c9_w_y)));
  }

  c9_st.site = &c9_gc_emlrtRSI;
  c9_q_x = c9_obj->IsGrid;
  c9_r_x = c9_q_x;
  c9_k_b = muDoubleScalarIsNaN(c9_r_x);
  if (c9_k_b) {
    c9_x_y = NULL;
    sf_mex_assign(&c9_x_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    c9_y_y = NULL;
    sf_mex_assign(&c9_y_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    sf_mex_call(&c9_st, &c9_h_emlrtMCI, "error", 0U, 2U, 14, c9_x_y, 14,
                sf_mex_call(&c9_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_st, NULL, "message", 1U, 1U, 14, c9_y_y)));
  }

  if (!(c9_obj->IsGrid != 0.0)) {
    c9_st.site = &c9_hc_emlrtRSI;
    c9_b_obj = c9_obj;
    c9_val = c9_b_obj->Map;
    c9_st.site = &c9_hc_emlrtRSI;
    for (c9_i8 = 0; c9_i8 < 2; c9_i8++) {
      c9_b_start[c9_i8] = c9_start[c9_i8];
    }

    c9_MapInterface_world2grid(chartInstance, c9_val, c9_b_start, c9_startgrid);
    c9_st.site = &c9_ic_emlrtRSI;
    c9_d_obj = c9_obj;
    c9_b_val = c9_d_obj->Map;
    c9_st.site = &c9_ic_emlrtRSI;
    for (c9_i11 = 0; c9_i11 < 2; c9_i11++) {
      c9_b_goal[c9_i11] = c9_goal[c9_i11];
    }

    c9_MapInterface_world2grid(chartInstance, c9_b_val, c9_b_goal, c9_goalgrid);
  } else {
    for (c9_i6 = 0; c9_i6 < 2; c9_i6++) {
      c9_startgrid[c9_i6] = c9_start[c9_i6];
    }

    for (c9_i7 = 0; c9_i7 < 2; c9_i7++) {
      c9_goalgrid[c9_i7] = c9_goal[c9_i7];
    }
  }

  c9_st.site = &c9_jc_emlrtRSI;
  c9_c_obj = c9_obj;
  c9_e_map = c9_c_obj->Map;
  c9_st.site = &c9_kc_emlrtRSI;
  for (c9_i9 = 0; c9_i9 < 2; c9_i9++) {
    c9_b_startgrid[c9_i9] = c9_startgrid[c9_i9];
  }

  for (c9_i10 = 0; c9_i10 < 2; c9_i10++) {
    c9_b_goalgrid[c9_i10] = c9_goalgrid[c9_i10];
  }

  c9_plannerAStarGrid_validateStartGoal(chartInstance, &c9_st, c9_obj, c9_e_map,
    c9_b_startgrid, c9_b_goalgrid);
  for (c9_i12 = 0; c9_i12 < 2; c9_i12++) {
    c9_obj->StartInGrid[c9_i12] = c9_startgrid[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 2; c9_i13++) {
    c9_obj->GoalInGrid[c9_i13] = c9_goalgrid[c9_i13];
  }

  c9_st.site = &c9_oc_emlrtRSI;
  c9_plannerAStarGrid_initializeInternalPlanner(chartInstance, &c9_st, c9_obj,
    &chartInstance->c9_astarInternal);
  c9_st.site = &c9_lc_emlrtRSI;
  for (c9_i14 = 0; c9_i14 < 2; c9_i14++) {
    c9_e_obj[c9_i14] = c9_obj->StartInGrid[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 2; c9_i15++) {
    c9_f_obj[c9_i15] = c9_obj->GoalInGrid[c9_i15];
  }

  c9_plannerAStarGrid_runPlan(chartInstance, &c9_st,
    &chartInstance->c9_astarInternal, c9_e_obj, c9_f_obj);
  c9_st.site = &c9_mc_emlrtRSI;
  c9_plannerAStarGrid_getEssentialOutput(chartInstance, &c9_st, c9_obj,
    &chartInstance->c9_astarInternal);
  c9_st.site = &c9_nc_emlrtRSI;
  c9_plannerAStarGrid_getPathOutput(chartInstance, &c9_st, c9_obj, c9_path);
}

static void c9_plannerAStarGrid_validateStartGoal
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_binaryOccupancyMap *c9_e_map, real_T
   c9_StartInGrid[2], real_T c9_GoalInGrid[2])
{
  static char_T c9_b_cv4[46] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'C', 'o', 'o', 'r', 'd', 'i', 'n', 'a', 't', 'e',
    'O', 'u', 't', 's', 'i', 'd', 'e' };

  static char_T c9_b_cv6[45] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'O', 'c', 'c', 'u', 'p', 'i', 'e', 'd', 'L', 'o',
    'c', 'a', 't', 'i', 'o', 'n' };

  static char_T c9_b_cv[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l', 'a',
    'n', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n', 't', 'e', 'g',
    'e', 'r' };

  static char_T c9_b_cv5[11] = { 'X', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n' };

  static char_T c9_b_cv7[11] = { 'Y', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n' };

  static char_T c9_b_cv1[9] = { 's', 't', 'a', 'r', 't', 'G', 'o', 'a', 'l' };

  static char_T c9_b_cv3[7] = { 'c', 'o', 'l', 'u', 'm', 'n', 's' };

  static char_T c9_rfmt[7] = { '%', '2', '3', '.', '1', '5', 'e' };

  static char_T c9_b_cv8[5] = { 's', 't', 'a', 'r', 't' };

  static char_T c9_b_cv2[4] = { 'r', 'o', 'w', 's' };

  static char_T c9_b_cv9[4] = { 'g', 'o', 'a', 'l' };

  c9_binaryOccupancyMap *c9_b_obj;
  c9_binaryOccupancyMap *c9_e_obj;
  c9_matlabshared_autonomous_internal_SharedMapProperties *c9_c_obj;
  c9_matlabshared_autonomous_internal_SharedMapProperties *c9_f_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_st;
  const mxArray *c9_ab_y = NULL;
  const mxArray *c9_bb_y = NULL;
  const mxArray *c9_cb_y = NULL;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_db_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_eb_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_fb_y = NULL;
  const mxArray *c9_gb_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  const mxArray *c9_k_y = NULL;
  const mxArray *c9_l_y = NULL;
  const mxArray *c9_m_y = NULL;
  const mxArray *c9_n_y = NULL;
  const mxArray *c9_o_y = NULL;
  const mxArray *c9_p_y = NULL;
  const mxArray *c9_q_y = NULL;
  const mxArray *c9_r_y = NULL;
  const mxArray *c9_s_y = NULL;
  const mxArray *c9_t_y = NULL;
  const mxArray *c9_u_y = NULL;
  const mxArray *c9_v_y = NULL;
  const mxArray *c9_w_y = NULL;
  const mxArray *c9_x_y = NULL;
  const mxArray *c9_y_y = NULL;
  real_T c9_pos[4];
  real_T c9_mapSizeX[2];
  real_T c9_mapSizeY[2];
  real_T c9_b_k;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_k;
  real_T c9_d_obj;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_obj;
  real_T c9_g_x;
  real_T c9_g_y;
  real_T c9_goalNode;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_n_x;
  real_T c9_o_x;
  real_T c9_p_x;
  real_T c9_q_x;
  real_T c9_startNode;
  int32_T c9_strX_size[2];
  int32_T c9_strY_size[2];
  int32_T c9_c_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i2;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_k;
  char_T c9_str[23];
  char_T c9_strX_data[11];
  char_T c9_strY_data[11];
  boolean_T c9_d_bv[2];
  boolean_T c9_validIdx[2];
  boolean_T c9_x_data[2];
  boolean_T c9_b1;
  boolean_T c9_b2;
  boolean_T c9_b3;
  boolean_T c9_b_b;
  boolean_T c9_b_p;
  boolean_T c9_c_b;
  boolean_T c9_c_p;
  boolean_T c9_d_b;
  boolean_T c9_e_b;
  boolean_T c9_exitg1;
  boolean_T c9_f_b;
  boolean_T c9_h_y;
  boolean_T c9_isGoalOccupied;
  boolean_T c9_isStartOccupied;
  boolean_T c9_p;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  c9_st.site = &c9_qc_emlrtRSI;
  c9_i = 0;
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_pos[c9_i] = c9_StartInGrid[c9_i1];
    c9_i += 2;
  }

  c9_i2 = 0;
  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    c9_pos[c9_i2 + 1] = c9_GoalInGrid[c9_i3];
    c9_i2 += 2;
  }

  c9_b_st.site = &c9_yc_emlrtRSI;
  c9_c_st.site = &c9_pc_emlrtRSI;
  c9_p = true;
  c9_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_k < 4)) {
    c9_b_k = (real_T)c9_k + 1.0;
    c9_b_x = c9_pos[(int32_T)c9_b_k - 1];
    c9_c_x = c9_b_x;
    c9_d_x = c9_c_x;
    c9_c_b = muDoubleScalarIsInf(c9_d_x);
    c9_b1 = !c9_c_b;
    c9_e_x = c9_c_x;
    c9_d_b = muDoubleScalarIsNaN(c9_e_x);
    c9_b2 = !c9_d_b;
    c9_e_b = (c9_b1 && c9_b2);
    if (c9_e_b) {
      c9_f_x = c9_b_x;
      c9_g_x = c9_f_x;
      c9_g_y = c9_g_x;
      c9_g_y = muDoubleScalarFloor(c9_g_y);
      if (c9_g_y == c9_b_x) {
        c9_b_p = true;
      } else {
        c9_b_p = false;
      }
    } else {
      c9_b_p = false;
    }

    c9_c_p = c9_b_p;
    if (c9_c_p) {
      c9_k++;
    } else {
      c9_p = false;
      c9_exitg1 = true;
    }
  }

  if (c9_p) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (!c9_b_b) {
    c9_d_y = NULL;
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 27),
                  false);
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv4, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c9_f_y = NULL;
    sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_b_cv1, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c9_c_st, &c9_l_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 2U, 14, c9_e_y, 14, c9_f_y)));
  }

  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    c9_validIdx[c9_i4] = (c9_pos[c9_i4] <= 410.0);
  }

  for (c9_i5 = 0; c9_i5 < 2; c9_i5++) {
    c9_d_bv[c9_i5] = (c9_pos[c9_i5 + 2] <= 520.0);
  }

  for (c9_i6 = 0; c9_i6 < 2; c9_i6++) {
    c9_validIdx[c9_i6] = (c9_validIdx[c9_i6] && c9_d_bv[c9_i6]);
  }

  for (c9_i7 = 0; c9_i7 < 2; c9_i7++) {
    c9_d_bv[c9_i7] = (c9_pos[c9_i7] >= 1.0);
  }

  for (c9_i8 = 0; c9_i8 < 2; c9_i8++) {
    c9_validIdx[c9_i8] = (c9_validIdx[c9_i8] && c9_d_bv[c9_i8]);
  }

  for (c9_i9 = 0; c9_i9 < 2; c9_i9++) {
    c9_d_bv[c9_i9] = (c9_pos[c9_i9 + 2] >= 1.0);
  }

  for (c9_i10 = 0; c9_i10 < 2; c9_i10++) {
    c9_validIdx[c9_i10] = (c9_validIdx[c9_i10] && c9_d_bv[c9_i10]);
  }

  for (c9_i11 = 0; c9_i11 < 2; c9_i11++) {
    c9_validIdx[c9_i11] = !c9_validIdx[c9_i11];
  }

  for (c9_i12 = 0; c9_i12 < 2; c9_i12++) {
    c9_x_data[c9_i12] = c9_validIdx[c9_i12];
  }

  c9_h_y = false;
  c9_c_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_c_k < 2)) {
    c9_d_k = (real_T)c9_c_k + 1.0;
    if (!c9_x_data[(int32_T)c9_d_k - 1]) {
      c9_b3 = true;
    } else {
      c9_b3 = false;
    }

    if (!c9_b3) {
      c9_h_y = true;
      c9_exitg1 = true;
    } else {
      c9_c_k++;
    }
  }

  if (c9_h_y) {
    c9_st.site = &c9_rc_emlrtRSI;
    c9_h_x = c9_obj->IsGrid;
    c9_i_x = c9_h_x;
    c9_f_b = muDoubleScalarIsNaN(c9_i_x);
    if (c9_f_b) {
      c9_i_y = NULL;
      sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      c9_j_y = NULL;
      sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c9_st, &c9_h_emlrtMCI, "error", 0U, 2U, 14, c9_i_y, 14,
                  sf_mex_call(&c9_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c9_st, NULL, "message", 1U, 1U, 14, c9_j_y)));
    }

    if (!(c9_obj->IsGrid != 0.0)) {
      c9_st.site = &c9_sc_emlrtRSI;
      c9_b_obj = c9_e_map;
      c9_b_st.site = &c9_ad_emlrtRSI;
      c9_c_obj = &c9_b_obj->SharedProperties;
      c9_d_obj = c9_c_obj->LocalOriginInWorld[0] + c9_c_obj->GridOriginInLocal[0];
      for (c9_i18 = 0; c9_i18 < 2; c9_i18++) {
        c9_mapSizeX[c9_i18] = c9_d_obj + 52.0 * (real_T)c9_i18;
      }

      c9_st.site = &c9_tc_emlrtRSI;
      c9_e_obj = c9_e_map;
      c9_b_st.site = &c9_bd_emlrtRSI;
      c9_f_obj = &c9_e_obj->SharedProperties;
      c9_g_obj = c9_f_obj->LocalOriginInWorld[1] + c9_f_obj->GridOriginInLocal[1];
      for (c9_i22 = 0; c9_i22 < 2; c9_i22++) {
        c9_mapSizeY[c9_i22] = c9_g_obj + 41.0 * (real_T)c9_i22;
      }

      c9_strX_size[1] = 11;
      for (c9_i23 = 0; c9_i23 < 11; c9_i23++) {
        c9_strX_data[c9_i23] = c9_b_cv5[c9_i23];
      }

      c9_strY_size[1] = 11;
      for (c9_i24 = 0; c9_i24 < 11; c9_i24++) {
        c9_strY_data[c9_i24] = c9_b_cv7[c9_i24];
      }
    } else {
      for (c9_i14 = 0; c9_i14 < 2; c9_i14++) {
        c9_mapSizeX[c9_i14] = 1.0 + 409.0 * (real_T)c9_i14;
      }

      for (c9_i16 = 0; c9_i16 < 2; c9_i16++) {
        c9_mapSizeY[c9_i16] = 1.0 + 519.0 * (real_T)c9_i16;
      }

      c9_strX_size[1] = 4;
      for (c9_i17 = 0; c9_i17 < 4; c9_i17++) {
        c9_strX_data[c9_i17] = c9_b_cv2[c9_i17];
      }

      c9_strY_size[1] = 7;
      for (c9_i20 = 0; c9_i20 < 7; c9_i20++) {
        c9_strY_data[c9_i20] = c9_b_cv3[c9_i20];
      }
    }

    c9_k_y = NULL;
    sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_b_cv4, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_l_y = NULL;
    sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_b_cv4, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c9_st.site = &c9_uc_emlrtRSI;
    c9_j_x = c9_mapSizeX[0];
    c9_b_st.site = &c9_cd_emlrtRSI;
    c9_k_x = c9_j_x;
    c9_n_y = NULL;
    sf_mex_assign(&c9_n_y, sf_mex_create("y", c9_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c9_p_y = NULL;
    sf_mex_assign(&c9_p_y, sf_mex_create("y", &c9_k_x, 0, 0U, 0, 0U, 0), false);
    c9_c_st.site = &c9_dd_emlrtRSI;
    c9_emlrt_marshallIn(chartInstance, c9_sprintf(chartInstance, &c9_c_st,
      c9_n_y, c9_p_y), "<output of sprintf>", c9_str);
    c9_t_y = NULL;
    sf_mex_assign(&c9_t_y, sf_mex_create("y", c9_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c9_st.site = &c9_uc_emlrtRSI;
    c9_l_x = c9_mapSizeX[1];
    c9_b_st.site = &c9_cd_emlrtRSI;
    c9_m_x = c9_l_x;
    c9_v_y = NULL;
    sf_mex_assign(&c9_v_y, sf_mex_create("y", c9_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c9_w_y = NULL;
    sf_mex_assign(&c9_w_y, sf_mex_create("y", &c9_m_x, 0, 0U, 0, 0U, 0), false);
    c9_c_st.site = &c9_dd_emlrtRSI;
    c9_emlrt_marshallIn(chartInstance, c9_sprintf(chartInstance, &c9_c_st,
      c9_v_y, c9_w_y), "<output of sprintf>", c9_str);
    c9_x_y = NULL;
    sf_mex_assign(&c9_x_y, sf_mex_create("y", c9_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c9_y_y = NULL;
    sf_mex_assign(&c9_y_y, sf_mex_create("y", &c9_strX_data, 10, 0U, 1, 0U, 2, 1,
      c9_strX_size[1]), false);
    c9_st.site = &c9_vc_emlrtRSI;
    c9_n_x = c9_mapSizeY[0];
    c9_b_st.site = &c9_cd_emlrtRSI;
    c9_o_x = c9_n_x;
    c9_ab_y = NULL;
    sf_mex_assign(&c9_ab_y, sf_mex_create("y", c9_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c9_bb_y = NULL;
    sf_mex_assign(&c9_bb_y, sf_mex_create("y", &c9_o_x, 0, 0U, 0, 0U, 0), false);
    c9_c_st.site = &c9_dd_emlrtRSI;
    c9_emlrt_marshallIn(chartInstance, c9_sprintf(chartInstance, &c9_c_st,
      c9_ab_y, c9_bb_y), "<output of sprintf>", c9_str);
    c9_cb_y = NULL;
    sf_mex_assign(&c9_cb_y, sf_mex_create("y", c9_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c9_st.site = &c9_vc_emlrtRSI;
    c9_p_x = c9_mapSizeY[1];
    c9_b_st.site = &c9_cd_emlrtRSI;
    c9_q_x = c9_p_x;
    c9_db_y = NULL;
    sf_mex_assign(&c9_db_y, sf_mex_create("y", c9_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c9_eb_y = NULL;
    sf_mex_assign(&c9_eb_y, sf_mex_create("y", &c9_q_x, 0, 0U, 0, 0U, 0), false);
    c9_c_st.site = &c9_dd_emlrtRSI;
    c9_emlrt_marshallIn(chartInstance, c9_sprintf(chartInstance, &c9_c_st,
      c9_db_y, c9_eb_y), "<output of sprintf>", c9_str);
    c9_fb_y = NULL;
    sf_mex_assign(&c9_fb_y, sf_mex_create("y", c9_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c9_gb_y = NULL;
    sf_mex_assign(&c9_gb_y, sf_mex_create("y", &c9_strY_data, 10, 0U, 1, 0U, 2,
      1, c9_strY_size[1]), false);
    sf_mex_call(c9_sp, &c9_i_emlrtMCI, "error", 0U, 2U, 14, c9_k_y, 14,
                sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c9_sp, NULL, "message", 1U, 7U, 14, c9_l_y, 14, c9_t_y, 14, c9_x_y, 14,
       c9_y_y, 14, c9_cb_y, 14, c9_fb_y, 14, c9_gb_y)));
  }

  if (c9_GoalInGrid[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_GoalInGrid[0]))
  {
    emlrtIntegerCheckR2012b(c9_GoalInGrid[0], &c9_c_emlrtDCI, (emlrtConstCTX)
      c9_sp);
  }

  c9_i13 = (int32_T)c9_GoalInGrid[0];
  if ((c9_i13 < 1) || (c9_i13 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i13, 1, 410, &c9_e_emlrtBCI, (emlrtConstCTX)
      c9_sp);
  }

  if (c9_GoalInGrid[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_GoalInGrid[1]))
  {
    emlrtIntegerCheckR2012b(c9_GoalInGrid[1], &c9_d_emlrtDCI, (emlrtConstCTX)
      c9_sp);
  }

  c9_i15 = (int32_T)c9_GoalInGrid[1];
  if ((c9_i15 < 1) || (c9_i15 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i15, 1, 520, &c9_f_emlrtBCI, (emlrtConstCTX)
      c9_sp);
  }

  c9_goalNode = c9_obj->PoseId[(c9_i13 + 410 * (c9_i15 - 1)) - 1];
  if (c9_StartInGrid[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_StartInGrid[0]))
  {
    emlrtIntegerCheckR2012b(c9_StartInGrid[0], &c9_e_emlrtDCI, (emlrtConstCTX)
      c9_sp);
  }

  c9_i19 = (int32_T)c9_StartInGrid[0];
  if ((c9_i19 < 1) || (c9_i19 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i19, 1, 410, &c9_g_emlrtBCI, (emlrtConstCTX)
      c9_sp);
  }

  if (c9_StartInGrid[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_StartInGrid[1]))
  {
    emlrtIntegerCheckR2012b(c9_StartInGrid[1], &c9_f_emlrtDCI, (emlrtConstCTX)
      c9_sp);
  }

  c9_i21 = (int32_T)c9_StartInGrid[1];
  if ((c9_i21 < 1) || (c9_i21 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i21, 1, 520, &c9_h_emlrtBCI, (emlrtConstCTX)
      c9_sp);
  }

  c9_startNode = c9_obj->PoseId[(c9_i19 + 410 * (c9_i21 - 1)) - 1];
  c9_st.site = &c9_wc_emlrtRSI;
  c9_isStartOccupied = (c9_plannerAStarGrid_getNodeCostOMDefault(chartInstance,
    &c9_st, c9_obj, c9_startNode) == rtInf);
  if (c9_isStartOccupied) {
    c9_m_y = NULL;
    sf_mex_assign(&c9_m_y, sf_mex_create("y", c9_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c9_o_y = NULL;
    sf_mex_assign(&c9_o_y, sf_mex_create("y", c9_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c9_r_y = NULL;
    sf_mex_assign(&c9_r_y, sf_mex_create("y", c9_b_cv8, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(c9_sp, &c9_j_emlrtMCI, "error", 0U, 2U, 14, c9_m_y, 14,
                sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c9_sp, NULL, "message", 1U, 2U, 14, c9_o_y, 14, c9_r_y)));
  }

  c9_st.site = &c9_xc_emlrtRSI;
  c9_isGoalOccupied = (c9_plannerAStarGrid_getNodeCostOMDefault(chartInstance,
    &c9_st, c9_obj, c9_goalNode) == rtInf);
  if (c9_isGoalOccupied) {
    c9_q_y = NULL;
    sf_mex_assign(&c9_q_y, sf_mex_create("y", c9_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c9_s_y = NULL;
    sf_mex_assign(&c9_s_y, sf_mex_create("y", c9_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c9_u_y = NULL;
    sf_mex_assign(&c9_u_y, sf_mex_create("y", c9_b_cv9, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c9_sp, &c9_k_emlrtMCI, "error", 0U, 2U, 14, c9_q_y, 14,
                sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c9_sp, NULL, "message", 1U, 2U, 14, c9_s_y, 14, c9_u_y)));
  }
}

static real_T c9_plannerAStarGrid_getNodeCostOMDefault
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, real_T c9_currentNode)
{
  c9_binaryOccupancyMap *c9_val;
  c9_plannerAStarGrid *c9_b_obj;
  emlrtStack c9_st;
  real_T c9_b_dv[1];
  real_T c9_dv1[1];
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_cost;
  real_T c9_d_y;
  int32_T c9_b_tmp_size[2];
  int32_T c9_tmp_size[2];
  int32_T c9_b_tmp_data[1];
  int32_T c9_tmp_data[1];
  int32_T c9_b_end;
  int32_T c9_b_i;
  int32_T c9_b_loop_ub;
  int32_T c9_b_trueCount;
  int32_T c9_c_i;
  int32_T c9_d_i;
  int32_T c9_e_i;
  int32_T c9_end;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_loop_ub;
  int32_T c9_trueCount;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_st.site = &c9_ed_emlrtRSI;
  c9_b_obj = c9_obj;
  c9_val = c9_b_obj->Map;
  c9_st.site = &c9_ed_emlrtRSI;
  c9_binaryOccupancyMap_occupancyMatrix(chartInstance, &c9_st, c9_val,
    chartInstance->c9_b_bv);
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    chartInstance->c9_b_occMat[c9_i] = (real_T)chartInstance->c9_b_bv[c9_i];
  }

  if (c9_currentNode != (real_T)(int32_T)muDoubleScalarFloor(c9_currentNode)) {
    emlrtIntegerCheckR2012b(c9_currentNode, &c9_g_emlrtDCI, (emlrtConstCTX)c9_sp);
  }

  c9_i1 = (int32_T)c9_currentNode;
  if ((c9_i1 < 1) || (c9_i1 > 213200)) {
    emlrtDynamicBoundsCheckR2012b(c9_i1, 1, 213200, &c9_i_emlrtBCI,
      (emlrtConstCTX)c9_sp);
  }

  c9_cost = chartInstance->c9_b_occMat[c9_i1 - 1];
  c9_b_x = c9_cost * 10000.0;
  c9_c_x = c9_b_x;
  c9_d_y = c9_c_x;
  c9_d_y = muDoubleScalarRound(c9_d_y);
  c9_cost = c9_d_y / 10000.0;
  c9_b_dv[0] = c9_cost;
  c9_end = 1;
  c9_trueCount = 0;
  for (c9_b_i = 0; c9_b_i < c9_end; c9_b_i++) {
    if (c9_cost > c9_obj->OccupiedThreshold) {
      c9_trueCount++;
    }
  }

  c9_tmp_size[1] = c9_trueCount;
  for (c9_c_i = 0; c9_c_i < c9_end; c9_c_i++) {
    if (c9_cost > c9_obj->OccupiedThreshold) {
      c9_tmp_data[0] = c9_c_i;
    }
  }

  c9_loop_ub = c9_tmp_size[1] - 1;
  for (c9_i2 = 0; c9_i2 <= c9_loop_ub; c9_i2++) {
    c9_b_dv[c9_tmp_data[0]] = rtInf;
  }

  c9_cost = c9_b_dv[0];
  c9_dv1[0] = c9_cost;
  c9_b_end = 1;
  c9_b_trueCount = 0;
  for (c9_d_i = 0; c9_d_i < c9_b_end; c9_d_i++) {
    if (c9_cost <= c9_obj->OccupiedThreshold) {
      c9_b_trueCount++;
    }
  }

  c9_b_tmp_size[1] = c9_b_trueCount;
  for (c9_e_i = 0; c9_e_i < c9_b_end; c9_e_i++) {
    if (c9_cost <= c9_obj->OccupiedThreshold) {
      c9_b_tmp_data[0] = c9_e_i;
    }
  }

  c9_b_loop_ub = c9_b_tmp_size[1] - 1;
  for (c9_i3 = 0; c9_i3 <= c9_b_loop_ub; c9_i3++) {
    c9_dv1[c9_b_tmp_data[0]] = 0.0;
  }

  return c9_dv1[0];
}

static void c9_binaryOccupancyMap_occupancyMatrix
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, boolean_T c9_b_mat[213200])
{
  static char_T c9_b_cv[40] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'c', 'i', 'r', 'c', 's', 'h', 'i', 'f', 't', '_', 'I',
    'n', 'v', 'a', 'l', 'i', 'd', 'S', 'h', 'i', 'f', 't', 'T', 'y', 'p', 'e' };

  static char_T c9_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  c9_binaryOccupancyMap *c9_b_obj;
  c9_binaryOccupancyMap *c9_c_obj;
  c9_binaryOccupancyMap *c9_d_obj;
  c9_binaryOccupancyMap *c9_e_obj;
  c9_binaryOccupancyMap *c9_f_obj;
  c9_matlabshared_autonomous_internal_CircularBuffer *c9_g_obj;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_b_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_c_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_d_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_index;
  c9_matlabshared_autonomous_internal_CircularBufferIndex *c9_r;
  emlrtStack c9_b_st;
  emlrtStack c9_st;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  real_T c9_p[2];
  real_T c9_b_j;
  real_T c9_b_k;
  real_T c9_b_p;
  real_T c9_d;
  real_T c9_d_i;
  real_T c9_d_k;
  real_T c9_dim;
  real_T c9_f_k;
  int32_T c9_absp[2];
  int32_T c9_subArr[2];
  int32_T c9_b_a;
  int32_T c9_b_i;
  int32_T c9_c_a;
  int32_T c9_c_b;
  int32_T c9_c_i;
  int32_T c9_c_k;
  int32_T c9_c_vk;
  int32_T c9_c_x;
  int32_T c9_d_x;
  int32_T c9_e_i;
  int32_T c9_e_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i_y;
  int32_T c9_idx;
  int32_T c9_intp;
  int32_T c9_j;
  int32_T c9_j_y;
  int32_T c9_k;
  int32_T c9_pk;
  int32_T c9_sz;
  int32_T c9_u0;
  int32_T c9_u1;
  int32_T c9_v1;
  boolean_T c9_b_x[2];
  boolean_T c9_shiftright[2];
  boolean_T c9_x_data[2];
  boolean_T c9_b1;
  boolean_T c9_b_b;
  boolean_T c9_d_y;
  boolean_T c9_exitg1;
  boolean_T c9_pok;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_st.site = &c9_fd_emlrtRSI;
  c9_b_obj = c9_obj;
  c9_b_st.site = &c9_gd_emlrtRSI;
  c9_c_obj = c9_b_obj;
  c9_index = c9_c_obj->Buffer.Index;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_b_x[c9_i] = (c9_index->Head[c9_i] == 1.0);
  }

  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_x_data[c9_i1] = c9_b_x[c9_i1];
  }

  c9_d_y = true;
  c9_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_k < 2)) {
    c9_b_k = (real_T)c9_k + 1.0;
    if (!c9_x_data[(int32_T)c9_b_k - 1]) {
      c9_d_y = false;
      c9_exitg1 = true;
    } else {
      c9_k++;
    }
  }

  if (c9_d_y) {
    for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
      c9_b_mat[c9_i2] = c9_b_obj->Buffer.Buffer[c9_i2];
    }
  } else {
    c9_b_st.site = &c9_hd_emlrtRSI;
    c9_d_obj = c9_b_obj;
    c9_b_index = c9_d_obj->Buffer.Index;
    c9_b_st.site = &c9_hd_emlrtRSI;
    for (c9_i3 = 0; c9_i3 < 213200; c9_i3++) {
      c9_b_mat[c9_i3] = c9_b_obj->Buffer.Buffer[c9_i3];
    }

    for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
      c9_p[c9_i4] = -(c9_b_index->Head[c9_i4] - 1.0);
    }

    c9_pok = true;
    c9_c_k = 0;
    c9_exitg1 = false;
    while ((!c9_exitg1) && (c9_c_k < 2)) {
      c9_d_k = (real_T)c9_c_k + 1.0;
      c9_pk = (int32_T)c9_p[(int32_T)c9_d_k - 1];
      if (((real_T)c9_pk != c9_p[(int32_T)c9_d_k - 1]) || (c9_pk == MIN_int32_T))
      {
        c9_pok = false;
        c9_exitg1 = true;
      } else {
        c9_c_k++;
      }
    }

    if (c9_pok) {
      c9_b_b = true;
    } else {
      c9_b_b = false;
    }

    if (!c9_b_b) {
      c9_e_y = NULL;
      sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 40),
                    false);
      c9_f_y = NULL;
      sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 40),
                    false);
      c9_g_y = NULL;
      sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                    false);
      c9_h_y = NULL;
      sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                    false);
      sf_mex_call(&c9_b_st, &c9_m_emlrtMCI, "error", 0U, 2U, 14, c9_e_y, 14,
                  sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c9_b_st, NULL, "message", 1U, 3U, 14, c9_f_y, 14, c9_g_y,
                    14, c9_h_y)));
    }

    for (c9_e_k = 0; c9_e_k < 2; c9_e_k++) {
      c9_f_k = (real_T)c9_e_k + 1.0;
      c9_b_p = c9_p[(int32_T)c9_f_k - 1];
      c9_dim = c9_f_k;
      if (c9_b_p < 0.0) {
        c9_intp = (int32_T)c9_b_p;
        c9_i6 = -c9_intp;
        c9_b1 = false;
      } else {
        c9_i6 = (int32_T)c9_b_p;
        c9_b1 = true;
      }

      c9_d = (real_T)(110 * ((int32_T)c9_dim - 1) + 410);
      c9_sz = (int32_T)c9_d;
      if (c9_i6 > c9_sz) {
        c9_c_x = c9_i6;
        c9_i_y = c9_sz;
        c9_c_a = c9_c_x;
        c9_c_b = c9_i_y;
        c9_d_x = c9_c_a;
        c9_j_y = c9_c_b;
        c9_u0 = c9_d_x;
        c9_u1 = c9_j_y;
        c9_i6 = c9_u0 - c9_u1 * c9_div_s32_ndbzs(chartInstance, c9_u0, c9_u1, 0,
          0U, 0, 0);
      }

      if (c9_i6 > (c9_sz >> 1)) {
        c9_i6 = c9_sz - c9_i6;
        c9_b1 = !c9_b1;
      }

      c9_subArr[(int32_T)c9_f_k - 1] = c9_i6;
      c9_b_x[(int32_T)c9_f_k - 1] = c9_b1;
    }

    for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
      chartInstance->c9_a[c9_i5] = c9_b_mat[c9_i5];
    }

    for (c9_b_i = 0; c9_b_i < 2; c9_b_i++) {
      c9_d_i = (real_T)c9_b_i + 1.0;
      c9_absp[(int32_T)c9_d_i - 1] = c9_subArr[(int32_T)c9_d_i - 1];
      c9_shiftright[(int32_T)c9_d_i - 1] = c9_b_x[(int32_T)c9_d_i - 1];
    }

    for (c9_c_i = 0; c9_c_i < 213200; c9_c_i++) {
      c9_e_i = c9_c_i;
      c9_idx = c9_e_i;
      c9_v1 = c9_idx;
      c9_b_a = c9_v1;
      c9_c_vk = (int32_T)((uint32_T)c9_b_a / 410U);
      c9_subArr[1] = c9_c_vk + 1;
      c9_v1 = (c9_v1 - c9_c_vk * 410) + 1;
      c9_subArr[0] = c9_v1;
      for (c9_j = 0; c9_j < 2; c9_j++) {
        c9_b_j = (real_T)c9_j + 1.0;
        if (c9_shiftright[(int32_T)c9_b_j - 1]) {
          c9_subArr[(int32_T)c9_b_j - 1] -= c9_absp[(int32_T)c9_b_j - 1];
          if (c9_subArr[(int32_T)c9_b_j - 1] <= 0) {
            c9_subArr[(int32_T)c9_b_j - 1] = (110 * ((int32_T)c9_b_j - 1) +
              c9_subArr[(int32_T)c9_b_j - 1]) + 410;
          }
        } else {
          c9_subArr[(int32_T)c9_b_j - 1] += c9_absp[(int32_T)c9_b_j - 1];
          if (c9_subArr[(int32_T)c9_b_j - 1] > 110 * ((int32_T)c9_b_j - 1) + 410)
          {
            c9_subArr[(int32_T)c9_b_j - 1] = (c9_subArr[(int32_T)c9_b_j - 1] -
              110 * ((int32_T)c9_b_j - 1)) - 410;
          }
        }
      }

      c9_b_mat[c9_e_i] = chartInstance->c9_a[(c9_subArr[0] + 410 * (c9_subArr[1]
        - 1)) - 1];
    }

    if (!c9_b_obj->HasParent) {
      for (c9_i7 = 0; c9_i7 < 213200; c9_i7++) {
        c9_b_obj->Buffer.Buffer[c9_i7] = c9_b_mat[c9_i7];
      }

      c9_b_st.site = &c9_id_emlrtRSI;
      c9_e_obj = c9_b_obj;
      c9_r = c9_e_obj->Buffer.Index;
      for (c9_i8 = 0; c9_i8 < 2; c9_i8++) {
        c9_r->Head[c9_i8] = 1.0;
      }

      c9_b_st.site = &c9_id_emlrtRSI;
      c9_f_obj = c9_b_obj;
      c9_c_index = c9_r;
      c9_g_obj = &c9_f_obj->Buffer;
      c9_d_index = c9_c_index;
      c9_g_obj->Index = c9_d_index;
    }
  }
}

static c9_nav_algs_internal_plannerAStarGrid
  *c9_plannerAStarGrid_initializeInternalPlanner
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_nav_algs_internal_plannerAStarGrid
   *c9_iobj_0)
{
  c9_binaryOccupancyMap *c9_val;
  c9_nav_algs_internal_plannerAStarGrid *c9_b_astarInternal;
  c9_nav_algs_internal_plannerAStarGrid *c9_f_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_g_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_h_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_i_obj;
  c9_plannerAStarGrid *c9_b_obj;
  c9_plannerAStarGrid *c9_c_obj;
  c9_plannerAStarGrid *c9_d_obj;
  c9_plannerAStarGrid *c9_e_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  real_T c9_b_distMethodVal;
  real_T c9_b_val;
  real_T c9_b_x;
  real_T c9_c_val;
  real_T c9_c_x;
  real_T c9_d_val;
  real_T c9_d_x;
  real_T c9_distMethodVal;
  real_T c9_e_val;
  real_T c9_e_x;
  real_T c9_th;
  real_T c9_value;
  int32_T c9_b_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_k;
  boolean_T c9_b_b;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_st.site = &c9_jd_emlrtRSI;
  c9_obj->OccupiedThreshold = 0.65;
  c9_st.site = &c9_kd_emlrtRSI;
  c9_b_obj = c9_obj;
  c9_val = c9_b_obj->Map;
  c9_st.site = &c9_kd_emlrtRSI;
  c9_binaryOccupancyMap_occupancyMatrix(chartInstance, &c9_st, c9_val,
    chartInstance->c9_bv);
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    chartInstance->c9_occMat[c9_i] = (real_T)chartInstance->c9_bv[c9_i];
  }

  for (c9_i1 = 0; c9_i1 < 213200; c9_i1++) {
    chartInstance->c9_occMat[c9_i1] *= 10000.0;
  }

  for (c9_k = 0; c9_k < 213200; c9_k++) {
    c9_b_k = c9_k;
    c9_b_x = chartInstance->c9_occMat[c9_b_k];
    c9_c_x = c9_b_x;
    c9_c_x = muDoubleScalarRound(c9_c_x);
    chartInstance->c9_occMat[c9_b_k] = c9_c_x;
  }

  for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
    chartInstance->c9_occMat[c9_i2] /= 10000.0;
  }

  c9_th = c9_obj->OccupiedThreshold;
  c9_st.site = &c9_ld_emlrtRSI;
  c9_st.site = &c9_md_emlrtRSI;
  c9_st.site = &c9_md_emlrtRSI;
  c9_st.site = &c9_nd_emlrtRSI;
  c9_b_astarInternal = c9_b_plannerAStarGrid_plannerAStarGrid(chartInstance,
    c9_iobj_0, chartInstance->c9_occMat, c9_th);
  if (c9_obj->UseCustomH == 0.0) {
    c9_st.site = &c9_od_emlrtRSI;
    c9_c_obj = c9_obj;
    c9_b_val = c9_c_obj->HCost;
    c9_st.site = &c9_od_emlrtRSI;
    c9_f_obj = c9_b_astarInternal;
    c9_distMethodVal = c9_b_val;
    c9_f_obj->HCostMethod = c9_distMethodVal;
    c9_f_obj->UseCustomH = 0.0;
  }

  if (c9_obj->UseCustomG == 0.0) {
    c9_st.site = &c9_pd_emlrtRSI;
    c9_d_obj = c9_obj;
    c9_c_val = c9_d_obj->GCost;
    c9_st.site = &c9_pd_emlrtRSI;
    c9_g_obj = c9_b_astarInternal;
    c9_b_distMethodVal = c9_c_val;
    c9_g_obj->GCostMethod = c9_b_distMethodVal;
    c9_g_obj->UseCustomG = 0.0;
  }

  c9_st.site = &c9_qd_emlrtRSI;
  c9_e_obj = c9_obj;
  c9_b_st.site = &c9_be_emlrtRSI;
  c9_d_x = c9_e_obj->TieBreaker;
  c9_e_x = c9_d_x;
  c9_b_b = muDoubleScalarIsNaN(c9_e_x);
  if (c9_b_b) {
    c9_d_y = NULL;
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    sf_mex_call(&c9_b_st, &c9_h_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_b_st, NULL, "message", 1U, 1U, 14, c9_e_y)));
  }

  if (c9_e_obj->TieBreaker != 0.0) {
    c9_value = 1.07;
  } else {
    c9_value = 1.0;
  }

  c9_st.site = &c9_qd_emlrtRSI;
  c9_h_obj = c9_b_astarInternal;
  c9_d_val = c9_value;
  c9_h_obj->TieBreaker = c9_d_val;
  c9_st.site = &c9_rd_emlrtRSI;
  c9_i_obj = c9_b_astarInternal;
  c9_e_val = c9_obj->DiagonalSearch;
  c9_i_obj->DiagonalSearchFlag = c9_e_val;
  return c9_b_astarInternal;
}

static c9_nav_algs_internal_plannerAStarGrid
  *c9_b_plannerAStarGrid_plannerAStarGrid
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_e_map[213200],
   real_T c9_obstacleThreshold)
{
  c9_nav_algs_internal_plannerAStarGrid *c9_b_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_c_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_this;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  c9_b_obj = c9_obj;
  c9_b_obj->NumPathPoints = 0.0;
  c9_b_obj->UseCustomG = 0.0;
  c9_b_obj->UseCustomH = 0.0;
  c9_b_obj->GCostMethod = 1.0;
  c9_b_obj->HCostMethod = 1.0;
  c9_c_obj = c9_b_obj;
  c9_b_obj = c9_c_obj;
  c9_this = c9_b_obj;
  c9_b_obj = c9_this;
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    c9_b_obj->Map[c9_i] = c9_e_map[c9_i];
  }

  for (c9_i1 = 0; c9_i1 < 426400; c9_i1++) {
    c9_b_obj->PathInternal[c9_i1] = 0.0;
  }

  for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
    c9_b_obj->PathIndicesInternal[c9_i2] = 0.0;
  }

  for (c9_i3 = 0; c9_i3 < 213200; c9_i3++) {
    c9_b_obj->NodesExploredIndicesInternal[c9_i3] = 0.0;
  }

  for (c9_i4 = 0; c9_i4 < 426400; c9_i4++) {
    c9_b_obj->NodesExploredInternal[c9_i4] = 0.0;
  }

  c9_b_obj->ObstacleThreshold = c9_obstacleThreshold;
  c9_b_obj->MapResolution = 10.0;
  for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
    c9_b_obj->ParentCol[c9_i5] = 0.0;
  }

  for (c9_i6 = 0; c9_i6 < 213200; c9_i6++) {
    c9_b_obj->ParentRow[c9_i6] = 0.0;
  }

  for (c9_i7 = 0; c9_i7 < 213200; c9_i7++) {
    chartInstance->c9_b_y[c9_i7] = 1.0 + (real_T)c9_i7;
  }

  for (c9_i8 = 0; c9_i8 < 213200; c9_i8++) {
    c9_b_obj->MapIndex[c9_i8] = chartInstance->c9_b_y[c9_i8];
  }

  for (c9_i9 = 0; c9_i9 < 213200; c9_i9++) {
    chartInstance->c9_b_y[c9_i9] = 1.0 + (real_T)c9_i9;
  }

  c9_b_ind2sub(chartInstance, chartInstance->c9_b_y,
               chartInstance->c9_varargout_3, chartInstance->c9_b_varargout_4);
  for (c9_i10 = 0; c9_i10 < 213200; c9_i10++) {
    chartInstance->c9_b_y[c9_i10] = (real_T)chartInstance->c9_varargout_3[c9_i10];
  }

  for (c9_i11 = 0; c9_i11 < 213200; c9_i11++) {
    chartInstance->c9_allCol[c9_i11] = (real_T)chartInstance->
      c9_b_varargout_4[c9_i11];
  }

  for (c9_i12 = 0; c9_i12 < 213200; c9_i12++) {
    c9_b_obj->AllNodes[c9_i12] = chartInstance->c9_b_y[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 213200; c9_i13++) {
    c9_b_obj->AllNodes[c9_i13 + 213200] = chartInstance->c9_allCol[c9_i13];
  }

  return c9_b_obj;
}

static void c9_b_ind2sub(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c9_ndx[213200], int32_T c9_varargout_1[213200], int32_T
  c9_varargout_2[213200])
{
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    c9_varargout_1[c9_i] = (int32_T)c9_ndx[c9_i];
  }

  for (c9_i1 = 0; c9_i1 < 213200; c9_i1++) {
    c9_varargout_1[c9_i1]--;
  }

  for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
    chartInstance->c9_b_vk[c9_i2] = c9_div_nzp_s32(chartInstance,
      c9_varargout_1[c9_i2], 410, 0, 0U, 0, 0);
  }

  for (c9_i3 = 0; c9_i3 < 213200; c9_i3++) {
    c9_varargout_2[c9_i3] = chartInstance->c9_b_vk[c9_i3] + 1;
  }

  for (c9_i4 = 0; c9_i4 < 213200; c9_i4++) {
    chartInstance->c9_b_vk[c9_i4] *= 410;
  }

  for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
    c9_varargout_1[c9_i5] -= chartInstance->c9_b_vk[c9_i5];
  }

  for (c9_i6 = 0; c9_i6 < 213200; c9_i6++) {
    c9_varargout_1[c9_i6]++;
  }
}

static void c9_plannerAStarGrid_runPlan
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_b_astarInternal, real_T
   c9_start[2], real_T c9_goal[2])
{
  static char_T c9_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  c9_coder_array_int32_T c9_ii;
  c9_coder_array_real_T c9_expNodes;
  c9_coder_array_real_T_2D c9_r;
  c9_nav_algs_internal_PriorityQueue c9_OpenList;
  c9_nav_algs_internal_PriorityQueue *c9_b_obj;
  c9_nav_algs_internal_PriorityQueue *c9_b_this;
  c9_nav_algs_internal_PriorityQueue *c9_c_obj;
  c9_nav_algs_internal_PriorityQueue *c9_d_obj;
  c9_nav_algs_internal_PriorityQueue *c9_e_obj;
  c9_nav_algs_internal_PriorityQueue *c9_f_obj;
  c9_nav_algs_internal_PriorityQueue *c9_g_obj;
  c9_nav_algs_internal_PriorityQueue *c9_h_obj;
  c9_nav_algs_internal_PriorityQueue *c9_m_obj;
  c9_nav_algs_internal_PriorityQueue *c9_this;
  c9_nav_algs_internal_plannerAStarGrid *c9_i_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_j_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_k_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_l_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_d_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  const mxArray *c9_k_y = NULL;
  const mxArray *c9_l_y = NULL;
  const mxArray *c9_m_y = NULL;
  const mxArray *c9_p_y = NULL;
  const mxArray *c9_q_y = NULL;
  real_T c9_openToPush_data[40];
  real_T c9_Neighbors_data[16];
  real_T c9_MinScoreNode_data[5];
  real_T c9_nodeData[5];
  real_T c9_b_goal[2];
  real_T c9_b_start[2];
  real_T c9_CurrentCol;
  real_T c9_CurrentRow;
  real_T c9_JumpCells;
  real_T c9_NumNeighbors;
  real_T c9_XPOS;
  real_T c9_YPOS;
  real_T c9_ab_x;
  real_T c9_b_CurrentCol;
  real_T c9_b_CurrentRow;
  real_T c9_b_a;
  real_T c9_b_j;
  real_T c9_b_p;
  real_T c9_b_u;
  real_T c9_b_varargin_1;
  real_T c9_b_varargin_2;
  real_T c9_b_x;
  real_T c9_bb_x;
  real_T c9_c_CurrentCol;
  real_T c9_c_CurrentRow;
  real_T c9_c_a;
  real_T c9_c_i;
  real_T c9_c_j;
  real_T c9_c_x;
  real_T c9_cb_x;
  real_T c9_d;
  real_T c9_d1;
  real_T c9_d10;
  real_T c9_d11;
  real_T c9_d2;
  real_T c9_d3;
  real_T c9_d4;
  real_T c9_d5;
  real_T c9_d6;
  real_T c9_d7;
  real_T c9_d8;
  real_T c9_d9;
  real_T c9_d_i;
  real_T c9_d_x;
  real_T c9_dataDim;
  real_T c9_e_i;
  real_T c9_e_x;
  real_T c9_f_b;
  real_T c9_f_x;
  real_T c9_flag;
  real_T c9_g_b;
  real_T c9_g_x;
  real_T c9_gcost;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_maxval;
  real_T c9_n_x;
  real_T c9_n_y;
  real_T c9_nodeId;
  real_T c9_o_x;
  real_T c9_o_y;
  real_T c9_openToPushK;
  real_T c9_p_x;
  real_T c9_q_x;
  real_T c9_r_x;
  real_T c9_r_y;
  real_T c9_s_x;
  real_T c9_s_y;
  real_T c9_t_x;
  real_T c9_t_y;
  real_T c9_tentative_gScore;
  real_T c9_u_x;
  real_T c9_u_y;
  real_T c9_v_x;
  real_T c9_v_y;
  real_T c9_w_x;
  real_T c9_x_x;
  real_T c9_y_x;
  int32_T c9_MinScoreNode_size[2];
  int32_T c9_Neighbors_size[2];
  int32_T c9_f_ii[2];
  int32_T c9_g_ii[2];
  int32_T c9_openToPush_size[2];
  int32_T c9_d_ii[1];
  int32_T c9_e_ii[1];
  int32_T c9_K;
  int32_T c9_b_i;
  int32_T c9_b_ii;
  int32_T c9_b_loop_ub;
  int32_T c9_b_openToPushK;
  int32_T c9_c_ii;
  int32_T c9_c_loop_ub;
  int32_T c9_c_openToPushK;
  int32_T c9_d_loop_ub;
  int32_T c9_e_loop_ub;
  int32_T c9_end;
  int32_T c9_exitg1;
  int32_T c9_f_loop_ub;
  int32_T c9_g_loop_ub;
  int32_T c9_h_loop_ub;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i100;
  int32_T c9_i101;
  int32_T c9_i102;
  int32_T c9_i103;
  int32_T c9_i104;
  int32_T c9_i105;
  int32_T c9_i106;
  int32_T c9_i107;
  int32_T c9_i108;
  int32_T c9_i109;
  int32_T c9_i11;
  int32_T c9_i110;
  int32_T c9_i111;
  int32_T c9_i112;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i2;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i3;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  int32_T c9_i33;
  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i4;
  int32_T c9_i40;
  int32_T c9_i41;
  int32_T c9_i42;
  int32_T c9_i43;
  int32_T c9_i44;
  int32_T c9_i45;
  int32_T c9_i46;
  int32_T c9_i47;
  int32_T c9_i48;
  int32_T c9_i49;
  int32_T c9_i5;
  int32_T c9_i50;
  int32_T c9_i51;
  int32_T c9_i52;
  int32_T c9_i53;
  int32_T c9_i54;
  int32_T c9_i55;
  int32_T c9_i56;
  int32_T c9_i57;
  int32_T c9_i58;
  int32_T c9_i59;
  int32_T c9_i6;
  int32_T c9_i60;
  int32_T c9_i61;
  int32_T c9_i62;
  int32_T c9_i63;
  int32_T c9_i64;
  int32_T c9_i65;
  int32_T c9_i66;
  int32_T c9_i67;
  int32_T c9_i68;
  int32_T c9_i69;
  int32_T c9_i7;
  int32_T c9_i70;
  int32_T c9_i71;
  int32_T c9_i72;
  int32_T c9_i73;
  int32_T c9_i74;
  int32_T c9_i75;
  int32_T c9_i76;
  int32_T c9_i77;
  int32_T c9_i78;
  int32_T c9_i79;
  int32_T c9_i8;
  int32_T c9_i80;
  int32_T c9_i81;
  int32_T c9_i82;
  int32_T c9_i83;
  int32_T c9_i84;
  int32_T c9_i85;
  int32_T c9_i86;
  int32_T c9_i87;
  int32_T c9_i88;
  int32_T c9_i89;
  int32_T c9_i9;
  int32_T c9_i90;
  int32_T c9_i91;
  int32_T c9_i92;
  int32_T c9_i93;
  int32_T c9_i94;
  int32_T c9_i95;
  int32_T c9_i96;
  int32_T c9_i97;
  int32_T c9_i98;
  int32_T c9_i99;
  int32_T c9_idx;
  int32_T c9_loop_ub;
  int32_T c9_p;
  boolean_T c9_b1;
  boolean_T c9_b2;
  boolean_T c9_b3;
  boolean_T c9_b4;
  boolean_T c9_b_b;
  boolean_T c9_b_flag;
  boolean_T c9_c_b;
  boolean_T c9_d_b;
  boolean_T c9_e_b;
  boolean_T c9_exitg2;
  boolean_T c9_guard1;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  c9_d_st.prev = &c9_c_st;
  c9_d_st.tls = c9_c_st.tls;
  c9_st.site = &c9_ce_emlrtRSI;
  c9_obj = c9_b_astarInternal;
  emlrtHeapReferenceStackEnterFcnR2012b(&c9_st);
  c9_array_real_T_Constructor(chartInstance, &c9_expNodes);
  c9_array_real_T_2D_Constructor(chartInstance, &c9_r);
  c9_array_int32_T_Constructor(chartInstance, &c9_ii);
  emlrtPushHeapReferenceStackR2021a(&c9_st, true, &c9_OpenList, (void *)
    &c9_handle_matlabCodegenDestructor, chartInstance, NULL, NULL);
  c9_OpenList.matlabCodegenIsDeleted = true;
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    chartInstance->c9_map[c9_i] = c9_obj->Map[c9_i];
  }

  for (c9_i1 = 0; c9_i1 < 213200; c9_i1++) {
    chartInstance->c9_GScore[c9_i1] = rtInf;
  }

  for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
    chartInstance->c9_FScore[c9_i2] = rtInf;
  }

  for (c9_i3 = 0; c9_i3 < 213200; c9_i3++) {
    chartInstance->c9_ExploredNodes[c9_i3] = 0;
  }

  for (c9_i4 = 0; c9_i4 < 213200; c9_i4++) {
    chartInstance->c9_ParentCol1[c9_i4] = 0.0;
  }

  for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
    chartInstance->c9_ParentRow2[c9_i5] = 0.0;
  }

  for (c9_i6 = 0; c9_i6 < 213200; c9_i6++) {
    chartInstance->c9_ClosedMAT[c9_i6] = 0;
  }

  c9_end = 213200;
  for (c9_b_i = 0; c9_b_i < c9_end; c9_b_i++) {
    if (chartInstance->c9_map[c9_b_i] == 1.0) {
      chartInstance->c9_ClosedMAT[c9_b_i] = 1;
    }
  }

  c9_b_st.site = &c9_de_emlrtRSI;
  c9_b_obj = &c9_OpenList;
  c9_c_obj = c9_b_obj;
  c9_c_st.site = &c9_te_emlrtRSI;
  c9_this = c9_c_obj;
  c9_c_obj = c9_this;
  c9_c_st.site = &c9_te_emlrtRSI;
  c9_d_obj = c9_c_obj;
  c9_c_obj = c9_d_obj;
  c9_d_st.site = &c9_ob_emlrtRSI;
  c9_b_this = c9_c_obj;
  c9_c_obj = c9_b_this;
  c9_c_obj->PQInternal = NULL;
  c9_c_obj->PQInternal = priorityqueuecodegen_constructPQ(5.0, 2.0);
  c9_c_obj->matlabCodegenIsDeleted = false;
  c9_b_st.site = &c9_ee_emlrtRSI;
  for (c9_i7 = 0; c9_i7 < 2; c9_i7++) {
    c9_b_goal[c9_i7] = c9_goal[c9_i7];
  }

  c9_plannerAStarGrid_getHeuristicMatrix(chartInstance, &c9_b_st, c9_obj,
    c9_b_goal, chartInstance->c9_map);
  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_n_emlrtDCI, &c9_st);
  }

  c9_i8 = (int32_T)c9_start[0];
  if ((c9_i8 < 1) || (c9_i8 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i8, 1, 410, &c9_kb_emlrtBCI, &c9_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_o_emlrtDCI, &c9_st);
  }

  c9_i9 = (int32_T)c9_start[1];
  if ((c9_i9 < 1) || (c9_i9 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i9, 1, 520, &c9_lb_emlrtBCI, &c9_st);
  }

  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_p_emlrtDCI, &c9_st);
  }

  c9_i10 = (int32_T)c9_start[0];
  if ((c9_i10 < 1) || (c9_i10 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i10, 1, 410, &c9_mb_emlrtBCI, &c9_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_q_emlrtDCI, &c9_st);
  }

  c9_i11 = (int32_T)c9_start[1];
  if ((c9_i11 < 1) || (c9_i11 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i11, 1, 520, &c9_nb_emlrtBCI, &c9_st);
  }

  chartInstance->c9_FScore[(c9_i10 + 410 * (c9_i11 - 1)) - 1] =
    chartInstance->c9_map[(c9_i8 + 410 * (c9_i9 - 1)) - 1];
  c9_b_st.site = &c9_fe_emlrtRSI;
  c9_e_obj = &c9_OpenList;
  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_r_emlrtDCI, &c9_b_st);
  }

  c9_i12 = (int32_T)c9_start[0];
  if ((c9_i12 < 1) || (c9_i12 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i12, 1, 410, &c9_ob_emlrtBCI, &c9_b_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_r_emlrtDCI, &c9_b_st);
  }

  c9_i13 = (int32_T)c9_start[1];
  if ((c9_i13 < 1) || (c9_i13 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i13, 1, 520, &c9_pb_emlrtBCI, &c9_b_st);
  }

  c9_nodeData[0] = c9_obj->MapIndex[(c9_i12 + 410 * (c9_i13 - 1)) - 1];
  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_s_emlrtDCI, &c9_b_st);
  }

  c9_i14 = (int32_T)c9_start[0];
  if ((c9_i14 < 1) || (c9_i14 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i14, 1, 410, &c9_qb_emlrtBCI, &c9_b_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_s_emlrtDCI, &c9_b_st);
  }

  c9_i15 = (int32_T)c9_start[1];
  if ((c9_i15 < 1) || (c9_i15 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i15, 1, 520, &c9_rb_emlrtBCI, &c9_b_st);
  }

  c9_nodeData[1] = c9_obj->MapIndex[(c9_i14 + 410 * (c9_i15 - 1)) - 1];
  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_t_emlrtDCI, &c9_b_st);
  }

  c9_i16 = (int32_T)c9_start[0];
  if ((c9_i16 < 1) || (c9_i16 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i16, 1, 410, &c9_sb_emlrtBCI, &c9_b_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_t_emlrtDCI, &c9_b_st);
  }

  c9_i17 = (int32_T)c9_start[1];
  if ((c9_i17 < 1) || (c9_i17 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i17, 1, 520, &c9_tb_emlrtBCI, &c9_b_st);
  }

  c9_nodeData[2] = chartInstance->c9_FScore[(c9_i16 + 410 * (c9_i17 - 1)) - 1];
  c9_nodeData[3] = 0.0;
  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_u_emlrtDCI, &c9_b_st);
  }

  c9_i18 = (int32_T)c9_start[0];
  if ((c9_i18 < 1) || (c9_i18 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i18, 1, 410, &c9_ub_emlrtBCI, &c9_b_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_u_emlrtDCI, &c9_b_st);
  }

  c9_i19 = (int32_T)c9_start[1];
  if ((c9_i19 < 1) || (c9_i19 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i19, 1, 520, &c9_vb_emlrtBCI, &c9_b_st);
  }

  c9_nodeData[4] = chartInstance->c9_map[(c9_i18 + 410 * (c9_i19 - 1)) - 1];
  priorityqueuecodegen_push(c9_e_obj->PQInternal, &c9_nodeData[0]);
  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_v_emlrtDCI, &c9_st);
  }

  c9_i20 = (int32_T)c9_start[0];
  if ((c9_i20 < 1) || (c9_i20 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i20, 1, 410, &c9_wb_emlrtBCI, &c9_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_w_emlrtDCI, &c9_st);
  }

  c9_i21 = (int32_T)c9_start[1];
  if ((c9_i21 < 1) || (c9_i21 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i21, 1, 520, &c9_xb_emlrtBCI, &c9_st);
  }

  chartInstance->c9_ExploredNodes[(c9_i20 + 410 * (c9_i21 - 1)) - 1] = 1;
  if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
    emlrtIntegerCheckR2012b(c9_start[0], &c9_x_emlrtDCI, &c9_st);
  }

  c9_i22 = (int32_T)c9_start[0];
  if ((c9_i22 < 1) || (c9_i22 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i22, 1, 410, &c9_yb_emlrtBCI, &c9_st);
  }

  if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
    emlrtIntegerCheckR2012b(c9_start[1], &c9_y_emlrtDCI, &c9_st);
  }

  c9_i23 = (int32_T)c9_start[1];
  if ((c9_i23 < 1) || (c9_i23 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i23, 1, 520, &c9_ac_emlrtBCI, &c9_st);
  }

  chartInstance->c9_GScore[(c9_i22 + 410 * (c9_i23 - 1)) - 1] = 0.0;
  c9_CurrentRow = 0.0;
  c9_CurrentCol = 0.0;
  c9_b_st.site = &c9_ge_emlrtRSI;
  c9_plannerAStarGrid_getNeighbors(chartInstance, &c9_b_st, c9_obj,
    c9_Neighbors_data, c9_Neighbors_size, &c9_NumNeighbors);
  do {
    c9_exitg1 = 0;
    c9_b_st.site = &c9_he_emlrtRSI;
    c9_f_obj = &c9_OpenList;
    c9_dataDim = priorityqueuecodegen_getDataDim(c9_f_obj->PQInternal);
    if (!(c9_dataDim <= 5.0)) {
      c9_d_y = NULL;
      sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c9_e_y = NULL;
      sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c9_b_st, &c9_q_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                  sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c9_b_st, NULL, "message", 1U, 1U, 14, c9_e_y)));
    }

    if (!(c9_dataDim >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c9_dataDim, &c9_bb_emlrtDCI, &c9_b_st);
    }

    c9_d = c9_dataDim;
    if (c9_d != (real_T)(int32_T)muDoubleScalarFloor(c9_d)) {
      emlrtIntegerCheckR2012b(c9_d, &c9_ab_emlrtDCI, &c9_b_st);
    }

    c9_MinScoreNode_size[1] = (int32_T)c9_d;
    priorityqueuecodegen_top(c9_f_obj->PQInternal, &c9_MinScoreNode_data[0],
      &c9_nodeId);
    c9_i24 = 3;
    if ((c9_i24 < 1) || (c9_i24 > c9_MinScoreNode_size[1])) {
      emlrtDynamicBoundsCheckR2012b(c9_i24, 1, c9_MinScoreNode_size[1],
        &c9_j_emlrtBCI, &c9_st);
    }

    if (c9_MinScoreNode_data[2] == rtInf) {
      c9_exitg1 = 1;
    } else {
      c9_b_st.site = &c9_ie_emlrtRSI;
      c9_g_obj = &c9_OpenList;
      c9_flag = priorityqueuecodegen_isEmpty(c9_g_obj->PQInternal);
      c9_c_st.site = &c9_bf_emlrtRSI;
      c9_b_x = c9_flag;
      c9_c_x = c9_b_x;
      c9_b_b = muDoubleScalarIsNaN(c9_c_x);
      if (c9_b_b) {
        c9_f_y = NULL;
        sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1,
          19), false);
        c9_g_y = NULL;
        sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1,
          19), false);
        sf_mex_call(&c9_c_st, &c9_h_emlrtMCI, "error", 0U, 2U, 14, c9_f_y, 14,
                    sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c9_c_st, NULL, "message", 1U, 1U, 14, c9_g_y)));
      }

      c9_b_flag = (c9_flag != 0.0);
      if (c9_b_flag) {
        if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
          emlrtIntegerCheckR2012b(c9_start[0], &c9_eb_emlrtDCI, &c9_st);
        }

        c9_i28 = (int32_T)c9_start[0];
        if ((c9_i28 < 1) || (c9_i28 > 410)) {
          emlrtDynamicBoundsCheckR2012b(c9_i28, 1, 410, &c9_dc_emlrtBCI, &c9_st);
        }

        if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
          emlrtIntegerCheckR2012b(c9_start[1], &c9_fb_emlrtDCI, &c9_st);
        }

        c9_i32 = (int32_T)c9_start[1];
        if ((c9_i32 < 1) || (c9_i32 > 520)) {
          emlrtDynamicBoundsCheckR2012b(c9_i32, 1, 520, &c9_ec_emlrtBCI, &c9_st);
        }

        c9_obj->ParentCol[(c9_i28 + 410 * (c9_i32 - 1)) - 1] = c9_start[1];
        if (c9_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[0])) {
          emlrtIntegerCheckR2012b(c9_start[0], &c9_hb_emlrtDCI, &c9_st);
        }

        c9_i36 = (int32_T)c9_start[0];
        if ((c9_i36 < 1) || (c9_i36 > 410)) {
          emlrtDynamicBoundsCheckR2012b(c9_i36, 1, 410, &c9_gc_emlrtBCI, &c9_st);
        }

        if (c9_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_start[1])) {
          emlrtIntegerCheckR2012b(c9_start[1], &c9_ib_emlrtDCI, &c9_st);
        }

        c9_i38 = (int32_T)c9_start[1];
        if ((c9_i38 < 1) || (c9_i38 > 520)) {
          emlrtDynamicBoundsCheckR2012b(c9_i38, 1, 520, &c9_hc_emlrtBCI, &c9_st);
        }

        c9_obj->ParentRow[(c9_i36 + 410 * (c9_i38 - 1)) - 1] = c9_start[0];
        c9_exitg1 = 1;
      } else {
        c9_i27 = 1;
        if ((c9_i27 < 1) || (c9_i27 > c9_MinScoreNode_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c9_i27, 1, c9_MinScoreNode_size[1],
            &c9_k_emlrtBCI, &c9_st);
        }

        c9_d1 = c9_MinScoreNode_data[0];
        if (c9_d1 != (real_T)(int32_T)muDoubleScalarFloor(c9_d1)) {
          emlrtIntegerCheckR2012b(c9_d1, &c9_gb_emlrtDCI, &c9_st);
        }

        c9_i31 = (int32_T)c9_d1;
        if ((c9_i31 < 1) || (c9_i31 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c9_i31, 1, 213200, &c9_fc_emlrtBCI,
            &c9_st);
        }

        c9_CurrentRow = c9_obj->AllNodes[c9_i31 - 1];
        c9_i34 = 1;
        if ((c9_i34 < 1) || (c9_i34 > c9_MinScoreNode_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c9_i34, 1, c9_MinScoreNode_size[1],
            &c9_l_emlrtBCI, &c9_st);
        }

        c9_d2 = c9_MinScoreNode_data[0];
        if (c9_d2 != (real_T)(int32_T)muDoubleScalarFloor(c9_d2)) {
          emlrtIntegerCheckR2012b(c9_d2, &c9_jb_emlrtDCI, &c9_st);
        }

        c9_i37 = (int32_T)c9_d2;
        if ((c9_i37 < 1) || (c9_i37 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c9_i37, 1, 213200, &c9_ic_emlrtBCI,
            &c9_st);
        }

        c9_CurrentCol = c9_obj->AllNodes[c9_i37 + 213199];
        c9_i39 = 1;
        if ((c9_i39 < 1) || (c9_i39 > c9_MinScoreNode_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c9_i39, 1, c9_MinScoreNode_size[1],
            &c9_m_emlrtBCI, &c9_st);
        }

        if (c9_goal[0] != (real_T)(int32_T)muDoubleScalarFloor(c9_goal[0])) {
          emlrtIntegerCheckR2012b(c9_goal[0], &c9_kb_emlrtDCI, &c9_st);
        }

        c9_i41 = (int32_T)c9_goal[0];
        if ((c9_i41 < 1) || (c9_i41 > 410)) {
          emlrtDynamicBoundsCheckR2012b(c9_i41, 1, 410, &c9_jc_emlrtBCI, &c9_st);
        }

        if (c9_goal[1] != (real_T)(int32_T)muDoubleScalarFloor(c9_goal[1])) {
          emlrtIntegerCheckR2012b(c9_goal[1], &c9_lb_emlrtDCI, &c9_st);
        }

        c9_i43 = (int32_T)c9_goal[1];
        if ((c9_i43 < 1) || (c9_i43 > 520)) {
          emlrtDynamicBoundsCheckR2012b(c9_i43, 1, 520, &c9_kc_emlrtBCI, &c9_st);
        }

        if (c9_MinScoreNode_data[0] == c9_obj->MapIndex[(c9_i41 + 410 * (c9_i43
              - 1)) - 1]) {
          for (c9_i44 = 0; c9_i44 < 213200; c9_i44++) {
            c9_obj->ParentCol[c9_i44] = chartInstance->c9_ParentCol1[c9_i44];
          }

          for (c9_i45 = 0; c9_i45 < 213200; c9_i45++) {
            c9_obj->ParentRow[c9_i45] = chartInstance->c9_ParentRow2[c9_i45];
          }

          c9_b_st.site = &c9_je_emlrtRSI;
          for (c9_i49 = 0; c9_i49 < 2; c9_i49++) {
            c9_b_start[c9_i49] = c9_start[c9_i49];
          }

          c9_plannerAStarGrid_reconstructPath(chartInstance, &c9_b_st, c9_obj,
            c9_CurrentRow, c9_CurrentCol, c9_b_start);
          c9_exitg1 = 1;
        } else {
          c9_b_st.site = &c9_ke_emlrtRSI;
          c9_h_obj = &c9_OpenList;
          priorityqueuecodegen_pop(c9_h_obj->PQInternal);
          if (c9_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor
              (c9_CurrentRow)) {
            emlrtIntegerCheckR2012b(c9_CurrentRow, &c9_h_emlrtDCI, &c9_st);
          }

          c9_i48 = (int32_T)c9_CurrentRow;
          if ((c9_i48 < 1) || (c9_i48 > 410)) {
            emlrtDynamicBoundsCheckR2012b(c9_i48, 1, 410, &c9_n_emlrtBCI, &c9_st);
          }

          if (c9_CurrentCol != (real_T)(int32_T)muDoubleScalarFloor
              (c9_CurrentCol)) {
            emlrtIntegerCheckR2012b(c9_CurrentCol, &c9_i_emlrtDCI, &c9_st);
          }

          c9_i51 = (int32_T)c9_CurrentCol;
          if ((c9_i51 < 1) || (c9_i51 > 520)) {
            emlrtDynamicBoundsCheckR2012b(c9_i51, 1, 520, &c9_o_emlrtBCI, &c9_st);
          }

          chartInstance->c9_ClosedMAT[(c9_i48 + 410 * (c9_i51 - 1)) - 1] = 1;
          c9_openToPush_size[0] = (int32_T)c9_NumNeighbors;
          c9_d_loop_ub = (int32_T)c9_NumNeighbors * 5 - 1;
          for (c9_i53 = 0; c9_i53 <= c9_d_loop_ub; c9_i53++) {
            c9_openToPush_data[c9_i53] = 0.0;
          }

          c9_openToPushK = 1.0;
          c9_i55 = (int32_T)c9_NumNeighbors - 1;
          for (c9_p = 0; c9_p <= c9_i55; c9_p++) {
            c9_b_p = (real_T)c9_p + 1.0;
            c9_i58 = (int32_T)c9_b_p;
            if ((c9_i58 < 1) || (c9_i58 > c9_Neighbors_size[0])) {
              emlrtDynamicBoundsCheckR2012b(c9_i58, 1, c9_Neighbors_size[0],
                &c9_lc_emlrtBCI, &c9_st);
            }

            c9_c_i = c9_Neighbors_data[c9_i58 - 1];
            c9_i59 = (int32_T)c9_b_p;
            if ((c9_i59 < 1) || (c9_i59 > c9_Neighbors_size[0])) {
              emlrtDynamicBoundsCheckR2012b(c9_i59, 1, c9_Neighbors_size[0],
                &c9_mc_emlrtBCI, &c9_st);
            }

            c9_j = c9_Neighbors_data[(c9_i59 + c9_Neighbors_size[0]) - 1];
            c9_b_st.site = &c9_le_emlrtRSI;
            c9_j_obj = c9_obj;
            c9_b_CurrentRow = c9_CurrentRow;
            c9_b_CurrentCol = c9_CurrentCol;
            c9_d_i = c9_c_i;
            c9_b_j = c9_j;
            if ((c9_b_CurrentRow + c9_d_i < 1.0) || (c9_b_CurrentRow + c9_d_i >
                 410.0) || (c9_b_CurrentCol + c9_b_j < 1.0) || (c9_b_CurrentCol
                 + c9_b_j > 520.0)) {
              c9_d6 = 1.0;
            } else {
              c9_i64 = (int32_T)(c9_b_CurrentRow + c9_d_i);
              if ((c9_i64 < 1) || (c9_i64 > 410)) {
                emlrtDynamicBoundsCheckR2012b(c9_i64, 1, 410, &c9_nc_emlrtBCI,
                  &c9_b_st);
              }

              c9_i66 = (int32_T)(c9_b_CurrentCol + c9_b_j);
              if ((c9_i66 < 1) || (c9_i66 > 520)) {
                emlrtDynamicBoundsCheckR2012b(c9_i66, 1, 520, &c9_oc_emlrtBCI,
                  &c9_b_st);
              }

              if (c9_j_obj->Map[(c9_i64 + 410 * (c9_i66 - 1)) - 1] >=
                  c9_j_obj->ObstacleThreshold) {
                c9_d6 = 1.0;
              } else {
                c9_d6 = 0.0;
              }
            }

            c9_b_st.site = &c9_le_emlrtRSI;
            c9_d_x = c9_d6;
            c9_e_x = c9_d_x;
            c9_d_b = muDoubleScalarIsNaN(c9_e_x);
            if (c9_d_b) {
              c9_l_y = NULL;
              sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2,
                1, 19), false);
              c9_m_y = NULL;
              sf_mex_assign(&c9_m_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2,
                1, 19), false);
              sf_mex_call(&c9_b_st, &c9_h_emlrtMCI, "error", 0U, 2U, 14, c9_l_y,
                          14, sf_mex_call(&c9_b_st, NULL, "getString", 1U, 1U,
                14, sf_mex_call(&c9_b_st, NULL, "message", 1U, 1U, 14, c9_m_y)));
            }

            if (!(c9_d6 != 0.0)) {
              c9_i70 = (int32_T)(c9_CurrentRow + c9_c_i);
              if ((c9_i70 < 1) || (c9_i70 > 410)) {
                emlrtDynamicBoundsCheckR2012b(c9_i70, 1, 410, &c9_qc_emlrtBCI,
                  &c9_st);
              }

              c9_i71 = (int32_T)(c9_CurrentCol + c9_j);
              if ((c9_i71 < 1) || (c9_i71 > 520)) {
                emlrtDynamicBoundsCheckR2012b(c9_i71, 1, 520, &c9_rc_emlrtBCI,
                  &c9_st);
              }

              if (!((real_T)chartInstance->c9_ClosedMAT[(c9_i70 + 410 * (c9_i71
                     - 1)) - 1] != 0.0)) {
                c9_b_st.site = &c9_me_emlrtRSI;
                c9_l_obj = c9_obj;
                c9_c_CurrentRow = c9_CurrentRow;
                c9_c_CurrentCol = c9_CurrentCol;
                c9_e_i = c9_c_i;
                c9_c_j = c9_j;
                c9_d9 = 0.0;
                c9_f_x = c9_e_i;
                c9_g_x = c9_f_x;
                c9_h_x = c9_g_x;
                c9_n_y = muDoubleScalarAbs(c9_h_x);
                c9_guard1 = false;
                if (c9_n_y > 1.0) {
                  c9_guard1 = true;
                } else {
                  c9_i_x = c9_c_j;
                  c9_j_x = c9_i_x;
                  c9_k_x = c9_j_x;
                  c9_o_y = muDoubleScalarAbs(c9_k_x);
                  if (c9_o_y > 1.0) {
                    c9_guard1 = true;
                  }
                }

                if (c9_guard1) {
                  c9_l_x = c9_e_i;
                  c9_m_x = c9_l_x;
                  c9_o_x = c9_m_x;
                  c9_b_varargin_1 = muDoubleScalarAbs(c9_o_x);
                  c9_q_x = c9_c_j;
                  c9_r_x = c9_q_x;
                  c9_s_x = c9_r_x;
                  c9_b_varargin_2 = muDoubleScalarAbs(c9_s_x);
                  c9_t_x = c9_b_varargin_1;
                  c9_r_y = c9_b_varargin_2;
                  c9_u_x = c9_t_x;
                  c9_s_y = c9_r_y;
                  c9_v_x = c9_u_x;
                  c9_t_y = c9_s_y;
                  c9_b_a = c9_v_x;
                  c9_f_b = c9_t_y;
                  c9_w_x = c9_b_a;
                  c9_u_y = c9_f_b;
                  c9_x_x = c9_w_x;
                  c9_v_y = c9_u_y;
                  c9_maxval = muDoubleScalarMax(c9_x_x, c9_v_y);
                  c9_JumpCells = 2.0 * c9_maxval - 1.0;
                  c9_i79 = (int32_T)c9_JumpCells - 1;
                  c9_K = 0;
                  c9_exitg2 = false;
                  while ((!c9_exitg2) && (c9_K <= c9_i79)) {
                    c9_y_x = c9_e_i / c9_JumpCells;
                    c9_ab_x = c9_y_x;
                    c9_YPOS = c9_ab_x;
                    c9_YPOS = muDoubleScalarRound(c9_YPOS);
                    c9_bb_x = c9_c_j / c9_JumpCells;
                    c9_cb_x = c9_bb_x;
                    c9_XPOS = c9_cb_x;
                    c9_XPOS = muDoubleScalarRound(c9_XPOS);
                    c9_d10 = c9_c_CurrentRow + c9_YPOS;
                    if (c9_d10 != (real_T)(int32_T)muDoubleScalarFloor(c9_d10))
                    {
                      emlrtIntegerCheckR2012b(c9_d10, &c9_nb_emlrtDCI, &c9_b_st);
                    }

                    c9_i88 = (int32_T)c9_d10;
                    if ((c9_i88 < 1) || (c9_i88 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i88, 1, 410,
                        &c9_nd_emlrtBCI, &c9_b_st);
                    }

                    c9_d11 = c9_c_CurrentCol + c9_XPOS;
                    if (c9_d11 != (real_T)(int32_T)muDoubleScalarFloor(c9_d11))
                    {
                      emlrtIntegerCheckR2012b(c9_d11, &c9_ob_emlrtDCI, &c9_b_st);
                    }

                    c9_i93 = (int32_T)c9_d11;
                    if ((c9_i93 < 1) || (c9_i93 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i93, 1, 520,
                        &c9_od_emlrtBCI, &c9_b_st);
                    }

                    if (c9_l_obj->Map[(c9_i88 + 410 * (c9_i93 - 1)) - 1] == 1.0)
                    {
                      c9_d9 = 1.0;
                      c9_exitg2 = true;
                    } else {
                      c9_K++;
                    }
                  }
                }

                c9_b_st.site = &c9_me_emlrtRSI;
                c9_n_x = c9_d9;
                c9_p_x = c9_n_x;
                c9_e_b = muDoubleScalarIsNaN(c9_p_x);
                if (c9_e_b) {
                  c9_p_y = NULL;
                  sf_mex_assign(&c9_p_y, sf_mex_create("y", c9_cv5, 10, 0U, 1,
                    0U, 2, 1, 19), false);
                  c9_q_y = NULL;
                  sf_mex_assign(&c9_q_y, sf_mex_create("y", c9_cv5, 10, 0U, 1,
                    0U, 2, 1, 19), false);
                  sf_mex_call(&c9_b_st, &c9_h_emlrtMCI, "error", 0U, 2U, 14,
                              c9_p_y, 14, sf_mex_call(&c9_b_st, NULL,
                    "getString", 1U, 1U, 14, sf_mex_call(&c9_b_st, NULL,
                    "message", 1U, 1U, 14, c9_q_y)));
                }

                if (!(c9_d9 != 0.0)) {
                  c9_b_st.site = &c9_ne_emlrtRSI;
                  c9_gcost = c9_plannerAStarGrid_gcostValue(chartInstance,
                    &c9_b_st, c9_obj, c9_CurrentRow, c9_CurrentCol, c9_c_i, c9_j);
                  c9_tentative_gScore = chartInstance->c9_GScore[((int32_T)
                    c9_CurrentRow + 410 * ((int32_T)c9_CurrentCol - 1)) - 1] +
                    c9_gcost;
                  c9_i73 = (int32_T)(c9_CurrentRow + c9_c_i);
                  if ((c9_i73 < 1) || (c9_i73 > 410)) {
                    emlrtDynamicBoundsCheckR2012b(c9_i73, 1, 410,
                      &c9_sc_emlrtBCI, &c9_st);
                  }

                  c9_i74 = (int32_T)(c9_CurrentCol + c9_j);
                  if ((c9_i74 < 1) || (c9_i74 > 520)) {
                    emlrtDynamicBoundsCheckR2012b(c9_i74, 1, 520,
                      &c9_tc_emlrtBCI, &c9_st);
                  }

                  if (chartInstance->c9_FScore[(c9_i73 + 410 * (c9_i74 - 1)) - 1]
                      == rtInf) {
                    c9_i76 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i76 < 1) || (c9_i76 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i76, 1, 410,
                        &c9_eb_emlrtBCI, &c9_st);
                    }

                    c9_i78 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i78 < 1) || (c9_i78 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i78, 1, 520,
                        &c9_fb_emlrtBCI, &c9_st);
                    }

                    chartInstance->c9_ExploredNodes[(c9_i76 + 410 * (c9_i78 - 1))
                      - 1] = 1;
                    c9_i81 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i81 < 1) || (c9_i81 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i81, 1, 410,
                        &c9_p_emlrtBCI, &c9_st);
                    }

                    c9_i83 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i83 < 1) || (c9_i83 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i83, 1, 520,
                        &c9_q_emlrtBCI, &c9_st);
                    }

                    chartInstance->c9_ParentCol1[(c9_i81 + 410 * (c9_i83 - 1)) -
                      1] = c9_CurrentCol;
                    c9_i85 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i85 < 1) || (c9_i85 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i85, 1, 410,
                        &c9_r_emlrtBCI, &c9_st);
                    }

                    c9_i87 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i87 < 1) || (c9_i87 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i87, 1, 520,
                        &c9_s_emlrtBCI, &c9_st);
                    }

                    chartInstance->c9_ParentRow2[(c9_i85 + 410 * (c9_i87 - 1)) -
                      1] = c9_CurrentRow;
                    c9_i90 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i90 < 1) || (c9_i90 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i90, 1, 410,
                        &c9_t_emlrtBCI, &c9_st);
                    }

                    c9_i92 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i92 < 1) || (c9_i92 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i92, 1, 520,
                        &c9_u_emlrtBCI, &c9_st);
                    }

                    chartInstance->c9_GScore[(c9_i90 + 410 * (c9_i92 - 1)) - 1] =
                      c9_tentative_gScore;
                    c9_i95 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i95 < 1) || (c9_i95 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i95, 1, 410,
                        &c9_bd_emlrtBCI, &c9_st);
                    }

                    c9_i97 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i97 < 1) || (c9_i97 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i97, 1, 520,
                        &c9_cd_emlrtBCI, &c9_st);
                    }

                    c9_i99 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i99 < 1) || (c9_i99 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i99, 1, 410,
                        &c9_dd_emlrtBCI, &c9_st);
                    }

                    c9_i101 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i101 < 1) || (c9_i101 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i101, 1, 520,
                        &c9_ed_emlrtBCI, &c9_st);
                    }

                    chartInstance->c9_FScore[(c9_i99 + 410 * (c9_i101 - 1)) - 1]
                      = c9_tentative_gScore + chartInstance->c9_map[(c9_i95 +
                      410 * (c9_i97 - 1)) - 1];
                    c9_i102 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i102 < 1) || (c9_i102 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i102, 1, 410,
                        &c9_fd_emlrtBCI, &c9_st);
                    }

                    c9_i103 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i103 < 1) || (c9_i103 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i103, 1, 520,
                        &c9_gd_emlrtBCI, &c9_st);
                    }

                    c9_c_a = c9_obj->MapIndex[(c9_i102 + 410 * (c9_i103 - 1)) -
                      1];
                    c9_g_b = c9_obj->MapIndex[((int32_T)c9_CurrentRow + 410 *
                      ((int32_T)c9_CurrentCol - 1)) - 1];
                    c9_i104 = (int32_T)c9_openToPushK;
                    if ((c9_i104 < 1) || (c9_i104 > c9_openToPush_size[0])) {
                      emlrtDynamicBoundsCheckR2012b(c9_i104, 1,
                        c9_openToPush_size[0], &c9_v_emlrtBCI, &c9_st);
                    }

                    c9_b_openToPushK = c9_i104 - 1;
                    c9_openToPush_data[c9_b_openToPushK] = c9_c_a;
                    c9_openToPush_data[c9_b_openToPushK + c9_openToPush_size[0]]
                      = c9_g_b;
                    c9_i105 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i105 < 1) || (c9_i105 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i105, 1, 410,
                        &c9_hd_emlrtBCI, &c9_st);
                    }

                    c9_i106 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i106 < 1) || (c9_i106 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i106, 1, 520,
                        &c9_id_emlrtBCI, &c9_st);
                    }

                    c9_openToPush_data[c9_b_openToPushK + (c9_openToPush_size[0]
                      << 1)] = chartInstance->c9_FScore[(c9_i105 + 410 *
                      (c9_i106 - 1)) - 1];
                    c9_i107 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i107 < 1) || (c9_i107 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i107, 1, 410,
                        &c9_jd_emlrtBCI, &c9_st);
                    }

                    c9_i108 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i108 < 1) || (c9_i108 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i108, 1, 520,
                        &c9_kd_emlrtBCI, &c9_st);
                    }

                    c9_openToPush_data[c9_b_openToPushK + c9_openToPush_size[0] *
                      3] = chartInstance->c9_GScore[(c9_i107 + 410 * (c9_i108 -
                      1)) - 1];
                    c9_i109 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i109 < 1) || (c9_i109 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i109, 1, 410,
                        &c9_ld_emlrtBCI, &c9_st);
                    }

                    c9_i110 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i110 < 1) || (c9_i110 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i110, 1, 520,
                        &c9_md_emlrtBCI, &c9_st);
                    }

                    c9_openToPush_data[c9_b_openToPushK + (c9_openToPush_size[0]
                      << 2)] = chartInstance->c9_map[(c9_i109 + 410 * (c9_i110 -
                      1)) - 1];
                    c9_b_st.site = &c9_oe_emlrtRSI;
                    c9_m_obj = &c9_OpenList;
                    c9_i111 = (int32_T)c9_openToPushK;
                    if ((c9_i111 < 1) || (c9_i111 > c9_openToPush_size[0])) {
                      emlrtDynamicBoundsCheckR2012b(c9_i111, 1,
                        c9_openToPush_size[0], &c9_w_emlrtBCI, &c9_b_st);
                    }

                    c9_c_openToPushK = c9_i111 - 1;
                    for (c9_i112 = 0; c9_i112 < 5; c9_i112++) {
                      c9_nodeData[c9_i112] = c9_openToPush_data[c9_c_openToPushK
                        + c9_openToPush_size[0] * c9_i112];
                    }

                    priorityqueuecodegen_push(c9_m_obj->PQInternal,
                      &c9_nodeData[0]);
                    c9_openToPushK++;
                  } else {
                    c9_i75 = (int32_T)(c9_CurrentRow + c9_c_i);
                    if ((c9_i75 < 1) || (c9_i75 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i75, 1, 410,
                        &c9_uc_emlrtBCI, &c9_st);
                    }

                    c9_i77 = (int32_T)(c9_CurrentCol + c9_j);
                    if ((c9_i77 < 1) || (c9_i77 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c9_i77, 1, 520,
                        &c9_vc_emlrtBCI, &c9_st);
                    }

                    if (c9_tentative_gScore >= chartInstance->c9_GScore[(c9_i75
                         + 410 * (c9_i77 - 1)) - 1]) {
                    } else {
                      c9_i80 = (int32_T)(c9_CurrentRow + c9_c_i);
                      if ((c9_i80 < 1) || (c9_i80 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i80, 1, 410,
                          &c9_x_emlrtBCI, &c9_st);
                      }

                      c9_i82 = (int32_T)(c9_CurrentCol + c9_j);
                      if ((c9_i82 < 1) || (c9_i82 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i82, 1, 520,
                          &c9_y_emlrtBCI, &c9_st);
                      }

                      chartInstance->c9_ParentCol1[(c9_i80 + 410 * (c9_i82 - 1))
                        - 1] = c9_CurrentCol;
                      c9_i84 = (int32_T)(c9_CurrentRow + c9_c_i);
                      if ((c9_i84 < 1) || (c9_i84 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i84, 1, 410,
                          &c9_ab_emlrtBCI, &c9_st);
                      }

                      c9_i86 = (int32_T)(c9_CurrentCol + c9_j);
                      if ((c9_i86 < 1) || (c9_i86 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i86, 1, 520,
                          &c9_bb_emlrtBCI, &c9_st);
                      }

                      chartInstance->c9_ParentRow2[(c9_i84 + 410 * (c9_i86 - 1))
                        - 1] = c9_CurrentRow;
                      c9_i89 = (int32_T)(c9_CurrentRow + c9_c_i);
                      if ((c9_i89 < 1) || (c9_i89 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i89, 1, 410,
                          &c9_cb_emlrtBCI, &c9_st);
                      }

                      c9_i91 = (int32_T)(c9_CurrentCol + c9_j);
                      if ((c9_i91 < 1) || (c9_i91 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i91, 1, 520,
                          &c9_db_emlrtBCI, &c9_st);
                      }

                      chartInstance->c9_GScore[(c9_i89 + 410 * (c9_i91 - 1)) - 1]
                        = c9_tentative_gScore;
                      c9_i94 = (int32_T)(c9_CurrentRow + c9_c_i);
                      if ((c9_i94 < 1) || (c9_i94 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i94, 1, 410,
                          &c9_wc_emlrtBCI, &c9_st);
                      }

                      c9_i96 = (int32_T)(c9_CurrentCol + c9_j);
                      if ((c9_i96 < 1) || (c9_i96 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i96, 1, 520,
                          &c9_xc_emlrtBCI, &c9_st);
                      }

                      c9_i98 = (int32_T)(c9_CurrentRow + c9_c_i);
                      if ((c9_i98 < 1) || (c9_i98 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i98, 1, 410,
                          &c9_yc_emlrtBCI, &c9_st);
                      }

                      c9_i100 = (int32_T)(c9_CurrentCol + c9_j);
                      if ((c9_i100 < 1) || (c9_i100 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c9_i100, 1, 520,
                          &c9_ad_emlrtBCI, &c9_st);
                      }

                      chartInstance->c9_FScore[(c9_i98 + 410 * (c9_i100 - 1)) -
                        1] = c9_tentative_gScore + chartInstance->c9_map[(c9_i94
                        + 410 * (c9_i96 - 1)) - 1];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  } while (c9_exitg1 == 0);

  if (c9_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor(c9_CurrentRow)) {
    emlrtIntegerCheckR2012b(c9_CurrentRow, &c9_cb_emlrtDCI, &c9_st);
  }

  c9_i25 = (int32_T)c9_CurrentRow;
  if ((c9_i25 < 1) || (c9_i25 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i25, 1, 410, &c9_bc_emlrtBCI, &c9_st);
  }

  if (c9_CurrentCol != (real_T)(int32_T)muDoubleScalarFloor(c9_CurrentCol)) {
    emlrtIntegerCheckR2012b(c9_CurrentCol, &c9_db_emlrtDCI, &c9_st);
  }

  c9_i26 = (int32_T)c9_CurrentCol;
  if ((c9_i26 < 1) || (c9_i26 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i26, 1, 520, &c9_cc_emlrtBCI, &c9_st);
  }

  c9_obj->PathCost = chartInstance->c9_GScore[(c9_i25 + 410 * (c9_i26 - 1)) - 1];
  for (c9_i29 = 0; c9_i29 < 213200; c9_i29++) {
    c9_obj->GCostMatrix[c9_i29] = chartInstance->c9_GScore[c9_i29];
  }

  for (c9_i30 = 0; c9_i30 < 2; c9_i30++) {
    c9_obj->Start[c9_i30] = c9_start[c9_i30];
  }

  for (c9_i33 = 0; c9_i33 < 2; c9_i33++) {
    c9_obj->Goal[c9_i33] = c9_goal[c9_i33];
  }

  c9_b_st.site = &c9_pe_emlrtRSI;
  for (c9_i35 = 0; c9_i35 < 213200; c9_i35++) {
    chartInstance->c9_x[c9_i35] = ((real_T)chartInstance->
      c9_ExploredNodes[c9_i35] == 1.0);
  }

  c9_c_st.site = &c9_ff_emlrtRSI;
  c9_d_st.site = &c9_gf_emlrtRSI;
  c9_idx = 0;
  c9_array_int32_T_SetSize(chartInstance, &c9_d_st, &c9_ii, &c9_t_emlrtRTEI,
    213200);
  c9_b_ii = 1;
  c9_exitg2 = false;
  while ((!c9_exitg2) && (c9_b_ii - 1 < 213200)) {
    c9_c_ii = c9_b_ii;
    if (chartInstance->c9_x[c9_c_ii - 1]) {
      c9_idx++;
      c9_ii.vector.data[c9_idx - 1] = c9_c_ii;
      if (c9_idx >= 213200) {
        c9_exitg2 = true;
      } else {
        c9_b_ii++;
      }
    } else {
      c9_b_ii++;
    }
  }

  c9_c_b = (c9_idx < 1);
  if (c9_c_b) {
    c9_i40 = 0;
  } else {
    c9_i40 = c9_idx;
  }

  c9_indexShapeCheck(chartInstance);
  c9_array_int32_T_SetSize(chartInstance, &c9_d_st, &c9_ii, &c9_k_emlrtRTEI,
    c9_i40);
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_expNodes, &c9_u_emlrtRTEI,
    c9_ii.size[0]);
  c9_loop_ub = c9_ii.size[0] - 1;
  for (c9_i42 = 0; c9_i42 <= c9_loop_ub; c9_i42++) {
    c9_expNodes.vector.data[c9_i42] = (real_T)c9_ii.vector.data[c9_i42];
  }

  c9_obj->NumNodesExplored = (real_T)c9_expNodes.size[0];
  if (!(c9_obj->NumNodesExplored <= 213200.0)) {
    c9_h_y = NULL;
    sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c9_i_y = NULL;
    sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c9_j_y = NULL;
    sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_cv7, 10, 0U, 1, 0U, 2, 1, 16),
                  false);
    c9_b_u = 213200.0;
    c9_k_y = NULL;
    sf_mex_assign(&c9_k_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(&c9_st, &c9_n_emlrtMCI, "error", 0U, 2U, 14, c9_h_y, 14,
                sf_mex_call(&c9_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_st, NULL, "message", 1U, 3U, 14, c9_i_y, 14, c9_j_y, 14, c9_k_y)));
  }

  c9_d3 = c9_obj->NumNodesExplored;
  c9_b1 = (c9_d3 < 1.0);
  if (c9_b1) {
    c9_i46 = -1;
  } else {
    if (c9_d3 != (real_T)(int32_T)muDoubleScalarFloor(c9_d3)) {
      emlrtIntegerCheckR2012b(c9_d3, &c9_j_emlrtDCI, &c9_st);
    }

    c9_i47 = (int32_T)c9_d3;
    if ((c9_i47 < 1) || (c9_i47 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i47, 1, 213200, &c9_gb_emlrtBCI, &c9_st);
    }

    c9_i46 = c9_i47 - 1;
  }

  c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_ii, &c9_v_emlrtRTEI,
    c9_i46 + 1);
  c9_b_loop_ub = c9_i46;
  for (c9_i50 = 0; c9_i50 <= c9_b_loop_ub; c9_i50++) {
    c9_ii.vector.data[c9_i50] = c9_i50;
  }

  c9_d_ii[0] = c9_ii.size[0];
  emlrtSubAssignSizeCheckR2012b(&c9_d_ii[0], 1, &c9_expNodes.size[0], 1,
    &c9_emlrtECI, &c9_st);
  c9_e_ii[0] = c9_ii.size[0];
  c9_c_loop_ub = c9_e_ii[0] - 1;
  for (c9_i52 = 0; c9_i52 <= c9_c_loop_ub; c9_i52++) {
    c9_obj->NodesExploredIndicesInternal[c9_ii.vector.data[c9_i52]] =
      c9_expNodes.vector.data[c9_i52];
  }

  c9_d4 = c9_obj->NumNodesExplored;
  c9_b2 = (c9_d4 < 1.0);
  if (c9_b2) {
    c9_i54 = -1;
  } else {
    if (c9_d4 != (real_T)(int32_T)muDoubleScalarFloor(c9_d4)) {
      emlrtIntegerCheckR2012b(c9_d4, &c9_k_emlrtDCI, &c9_st);
    }

    c9_i56 = (int32_T)c9_d4;
    if ((c9_i56 < 1) || (c9_i56 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i56, 1, 213200, &c9_hb_emlrtBCI, &c9_st);
    }

    c9_i54 = c9_i56 - 1;
  }

  c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_ii, &c9_w_emlrtRTEI,
    c9_i54 + 1);
  c9_e_loop_ub = c9_i54;
  for (c9_i57 = 0; c9_i57 <= c9_e_loop_ub; c9_i57++) {
    c9_ii.vector.data[c9_i57] = c9_i57;
  }

  c9_b_st.site = &c9_qe_emlrtRSI;
  c9_i_obj = c9_obj;
  c9_d5 = c9_i_obj->NumNodesExplored;
  c9_b3 = (c9_d5 < 1.0);
  if (c9_b3) {
    c9_i60 = -1;
  } else {
    if (c9_d5 != (real_T)(int32_T)muDoubleScalarFloor(c9_d5)) {
      emlrtIntegerCheckR2012b(c9_d5, &c9_l_emlrtDCI, &c9_b_st);
    }

    c9_i61 = (int32_T)c9_d5;
    if ((c9_i61 < 1) || (c9_i61 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i61, 1, 213200, &c9_ib_emlrtBCI, &c9_b_st);
    }

    c9_i60 = c9_i61 - 1;
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_expNodes, &c9_x_emlrtRTEI,
    c9_i60 + 1);
  c9_f_loop_ub = c9_i60;
  for (c9_i62 = 0; c9_i62 <= c9_f_loop_ub; c9_i62++) {
    c9_expNodes.vector.data[c9_i62] = c9_i_obj->
      NodesExploredIndicesInternal[c9_i62];
  }

  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_r, &c9_y_emlrtRTEI,
    c9_expNodes.size[0], 2);
  for (c9_i63 = 0; c9_i63 < 2; c9_i63++) {
    c9_g_loop_ub = c9_expNodes.size[0] - 1;
    for (c9_i65 = 0; c9_i65 <= c9_g_loop_ub; c9_i65++) {
      c9_d7 = c9_expNodes.vector.data[c9_i65];
      if (c9_d7 != (real_T)(int32_T)muDoubleScalarFloor(c9_d7)) {
        emlrtIntegerCheckR2012b(c9_d7, &c9_mb_emlrtDCI, &c9_st);
      }

      c9_i68 = (int32_T)c9_d7;
      if ((c9_i68 < 1) || (c9_i68 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c9_i68, 1, 213200, &c9_pc_emlrtBCI, &c9_st);
      }

      c9_r.vector.data[c9_i65 + c9_r.size[0] * c9_i63] = c9_obj->AllNodes
        [(c9_i68 + 213200 * c9_i63) - 1];
    }
  }

  c9_f_ii[0] = c9_ii.size[0];
  c9_f_ii[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&c9_f_ii[0], 2, &c9_r.size[0], 2, &c9_b_emlrtECI,
    &c9_st);
  c9_g_ii[0] = c9_ii.size[0];
  for (c9_i67 = 0; c9_i67 < 2; c9_i67++) {
    c9_h_loop_ub = c9_g_ii[0] - 1;
    for (c9_i69 = 0; c9_i69 <= c9_h_loop_ub; c9_i69++) {
      c9_obj->NodesExploredInternal[c9_ii.vector.data[c9_i69] + 213200 * c9_i67]
        = c9_r.vector.data[c9_i69 + c9_r.size[0] * c9_i67];
    }
  }

  c9_b_st.site = &c9_re_emlrtRSI;
  c9_k_obj = c9_obj;
  c9_d8 = c9_k_obj->NumPathPoints;
  c9_b4 = (c9_d8 < 1.0);
  if (!c9_b4) {
    if (c9_d8 != (real_T)(int32_T)muDoubleScalarFloor(c9_d8)) {
      emlrtIntegerCheckR2012b(c9_d8, &c9_m_emlrtDCI, &c9_b_st);
    }

    c9_i72 = (int32_T)c9_d8;
    if ((c9_i72 < 1) || (c9_i72 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i72, 1, 213200, &c9_jb_emlrtBCI, &c9_b_st);
    }
  }

  c9_b_st.site = &c9_se_emlrtRSI;
  c9_handle_matlabCodegenDestructor(chartInstance, &c9_b_st, &c9_OpenList);
  c9_array_int32_T_Destructor(chartInstance, &c9_ii);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_r);
  c9_array_real_T_Destructor(chartInstance, &c9_expNodes);
  emlrtHeapReferenceStackLeaveFcnR2012b(&c9_st);
}

static void c9_plannerAStarGrid_getHeuristicMatrix
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_goalIn[2],
   real_T c9_Hn[213200])
{
  static char_T c9_b_cv[4] = { 's', 'q', 'r', 't' };

  c9_nav_algs_internal_plannerAStarGrid *c9_b_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  const mxArray *c9_k_y = NULL;
  real_T c9_c_obj[2];
  real_T c9_b_a;
  real_T c9_b_i;
  real_T c9_b_x;
  real_T c9_c_a;
  real_T c9_c_x;
  real_T c9_d_a;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_e_y;
  real_T c9_f_x;
  real_T c9_f_y;
  real_T c9_g_y;
  real_T c9_hcost;
  real_T c9_j_k;
  real_T c9_type;
  real_T c9_val;
  int32_T c9_b_ia;
  int32_T c9_b_ib;
  int32_T c9_b_ic;
  int32_T c9_b_itilerow;
  int32_T c9_b_ix;
  int32_T c9_b_jcol;
  int32_T c9_b_k;
  int32_T c9_b_varargin_1;
  int32_T c9_b_varargin_2;
  int32_T c9_b_varargin_3;
  int32_T c9_b_xj;
  int32_T c9_c_i;
  int32_T c9_c_ix;
  int32_T c9_c_k;
  int32_T c9_c_varargin_1;
  int32_T c9_c_varargin_2;
  int32_T c9_c_xj;
  int32_T c9_d_i;
  int32_T c9_d_k;
  int32_T c9_d_xj;
  int32_T c9_e_k;
  int32_T c9_e_xj;
  int32_T c9_f_k;
  int32_T c9_f_xj;
  int32_T c9_g_k;
  int32_T c9_g_xj;
  int32_T c9_h_k;
  int32_T c9_h_xj;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i_k;
  int32_T c9_i_xj;
  int32_T c9_ia;
  int32_T c9_iacol;
  int32_T c9_ib;
  int32_T c9_ibcol;
  int32_T c9_ibmat;
  int32_T c9_ic;
  int32_T c9_itilerow;
  int32_T c9_ix;
  int32_T c9_jcol;
  int32_T c9_k;
  int32_T c9_k_k;
  int32_T c9_l_k;
  int32_T c9_varargin_3;
  int32_T c9_varargin_4;
  int32_T c9_varargin_5;
  int32_T c9_varargin_6;
  int32_T c9_xj;
  boolean_T c9_b_b;
  boolean_T c9_b_p;
  boolean_T c9_c_b;
  boolean_T c9_guard1;
  boolean_T c9_p;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  if (c9_obj->UseCustomH == 0.0) {
    c9_b_a = c9_obj->TieBreaker;
    for (c9_jcol = 0; c9_jcol < 2; c9_jcol++) {
      c9_b_jcol = c9_jcol;
      c9_iacol = c9_b_jcol;
      c9_ibmat = c9_b_jcol * 213200 - 1;
      for (c9_itilerow = 0; c9_itilerow < 213200; c9_itilerow++) {
        c9_b_itilerow = c9_itilerow;
        c9_ibcol = c9_ibmat + c9_b_itilerow;
        chartInstance->c9_b[c9_ibcol + 1] = c9_goalIn[c9_iacol];
      }
    }

    c9_st.site = &c9_ue_emlrtRSI;
    c9_b_obj = c9_obj;
    for (c9_i1 = 0; c9_i1 < 426400; c9_i1++) {
      chartInstance->c9_pose1[c9_i1] = c9_obj->AllNodes[c9_i1];
    }

    c9_type = c9_obj->HCostMethod;
    if (c9_type != (real_T)(int32_T)muDoubleScalarFloor(c9_type)) {
      emlrtIntegerCheckR2012b(c9_type, &c9_pb_emlrtDCI, &c9_st);
    }

    switch ((int32_T)c9_type) {
     case 2:
      for (c9_k = 0; c9_k < 2; c9_k++) {
        c9_ia = c9_k;
        c9_ib = c9_k;
        c9_ic = c9_k;
        c9_b_varargin_1 = c9_ic + 1;
        c9_b_varargin_2 = c9_ia + 1;
        c9_varargin_3 = c9_ib + 1;
        for (c9_h_k = 0; c9_h_k < 213200; c9_h_k++) {
          c9_b_ia = c9_h_k;
          c9_b_ib = c9_h_k;
          c9_b_ic = c9_h_k;
          c9_c_varargin_1 = c9_b_ic;
          c9_c_varargin_2 = c9_b_varargin_1 - 1;
          c9_b_varargin_3 = c9_b_ia;
          c9_varargin_4 = c9_b_varargin_2 - 1;
          c9_varargin_5 = c9_b_ib;
          c9_varargin_6 = c9_varargin_3 - 1;
          chartInstance->c9_c[c9_c_varargin_1 + 213200 * c9_c_varargin_2] =
            chartInstance->c9_pose1[c9_b_varargin_3 + 213200 * c9_varargin_4] -
            chartInstance->c9_b[c9_varargin_5 + 213200 * c9_varargin_6];
        }
      }

      for (c9_b_k = 0; c9_b_k < 426400; c9_b_k++) {
        c9_e_k = c9_b_k;
        c9_d_x = chartInstance->c9_c[c9_e_k];
        c9_e_y = muDoubleScalarAbs(c9_d_x);
        chartInstance->c9_b[c9_e_k] = c9_e_y;
      }

      for (c9_xj = 0; c9_xj < 213200; c9_xj++) {
        c9_e_xj = c9_xj;
        c9_Hn[c9_e_xj] = chartInstance->c9_b[c9_e_xj];
      }

      for (c9_d_xj = 0; c9_d_xj < 213200; c9_d_xj++) {
        c9_e_xj = c9_d_xj;
        c9_ix = c9_e_xj;
        c9_Hn[c9_e_xj] += chartInstance->c9_b[c9_ix + 213200];
      }
      break;

     case 3:
      c9_plannerAStarGrid_Chebyshev(chartInstance, chartInstance->c9_pose1,
        chartInstance->c9_b, c9_Hn);
      break;

     case 4:
      for (c9_i2 = 0; c9_i2 < 426400; c9_i2++) {
        chartInstance->c9_pose1[c9_i2] -= chartInstance->c9_b[c9_i2];
      }

      for (c9_c_k = 0; c9_c_k < 426400; c9_c_k++) {
        c9_f_k = c9_c_k;
        c9_c_a = chartInstance->c9_pose1[c9_f_k];
        c9_f_y = c9_c_a * c9_c_a;
        chartInstance->c9_b[c9_f_k] = c9_f_y;
      }

      for (c9_b_xj = 0; c9_b_xj < 213200; c9_b_xj++) {
        c9_g_xj = c9_b_xj;
        c9_Hn[c9_g_xj] = chartInstance->c9_b[c9_g_xj];
      }

      for (c9_f_xj = 0; c9_f_xj < 213200; c9_f_xj++) {
        c9_g_xj = c9_f_xj;
        c9_b_ix = c9_g_xj;
        c9_Hn[c9_g_xj] += chartInstance->c9_b[c9_b_ix + 213200];
      }
      break;

     default:
      c9_b_st.site = &c9_xe_emlrtRSI;
      for (c9_i3 = 0; c9_i3 < 426400; c9_i3++) {
        chartInstance->c9_pose1[c9_i3] -= chartInstance->c9_b[c9_i3];
      }

      for (c9_d_k = 0; c9_d_k < 426400; c9_d_k++) {
        c9_g_k = c9_d_k;
        c9_d_a = chartInstance->c9_pose1[c9_g_k];
        c9_g_y = c9_d_a * c9_d_a;
        chartInstance->c9_b[c9_g_k] = c9_g_y;
      }

      for (c9_c_xj = 0; c9_c_xj < 213200; c9_c_xj++) {
        c9_i_xj = c9_c_xj;
        c9_Hn[c9_i_xj] = chartInstance->c9_b[c9_i_xj];
      }

      for (c9_h_xj = 0; c9_h_xj < 213200; c9_h_xj++) {
        c9_i_xj = c9_h_xj;
        c9_c_ix = c9_i_xj;
        c9_Hn[c9_i_xj] += chartInstance->c9_b[c9_c_ix + 213200];
      }

      c9_c_st.site = &c9_ye_emlrtRSI;
      c9_p = false;
      for (c9_i_k = 0; c9_i_k < 213200; c9_i_k++) {
        c9_j_k = (real_T)c9_i_k + 1.0;
        if (c9_p || (c9_Hn[(int32_T)c9_j_k - 1] < 0.0)) {
          c9_b_p = true;
        } else {
          c9_b_p = false;
        }

        c9_p = c9_b_p;
      }

      if (c9_p) {
        c9_i_y = NULL;
        sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_cv8, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c9_j_y = NULL;
        sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_cv8, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c9_k_y = NULL;
        sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1,
          4), false);
        sf_mex_call(&c9_c_st, &c9_o_emlrtMCI, "error", 0U, 2U, 14, c9_i_y, 14,
                    sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c9_c_st, NULL, "message", 1U, 2U, 14, c9_j_y, 14, c9_k_y)));
      }

      for (c9_k_k = 0; c9_k_k < 213200; c9_k_k++) {
        c9_l_k = c9_k_k;
        c9_e_x = c9_Hn[c9_l_k];
        c9_f_x = c9_e_x;
        c9_f_x = muDoubleScalarSqrt(c9_f_x);
        c9_Hn[c9_l_k] = c9_f_x;
      }
      break;
    }

    for (c9_i4 = 0; c9_i4 < 213200; c9_i4++) {
      c9_Hn[c9_i4] /= c9_b_obj->MapResolution;
    }

    for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
      c9_Hn[c9_i5] *= c9_b_a;
    }
  } else {
    for (c9_i = 0; c9_i < 213200; c9_i++) {
      c9_b_i = (real_T)c9_i + 1.0;
      c9_c_i = (int32_T)c9_b_i - 1;
      for (c9_d_i = 0; c9_d_i < 2; c9_d_i++) {
        c9_c_obj[c9_d_i] = c9_obj->AllNodes[c9_c_i + 213200 * c9_d_i];
      }

      c9_st.site = &c9_ve_emlrtRSI;
      c9_hcost = c9_obj->TieBreaker * c9_plannerAStarGrid_Euclidean
        (chartInstance, &c9_st, c9_c_obj, c9_goalIn) / c9_obj->MapResolution;
      c9_st.site = &c9_we_emlrtRSI;
      c9_val = c9_hcost;
      c9_b_x = c9_val;
      c9_b_b = muDoubleScalarIsNaN(c9_b_x);
      c9_guard1 = false;
      if (c9_b_b) {
        c9_guard1 = true;
      } else {
        c9_c_x = c9_val;
        c9_c_b = muDoubleScalarIsInf(c9_c_x);
        if (c9_c_b) {
          c9_guard1 = true;
        }
      }

      if (c9_guard1) {
        c9_d_y = NULL;
        sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_cv9, 10, 0U, 1, 0U, 2, 1,
          64), false);
        c9_h_y = NULL;
        sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_cv9, 10, 0U, 1, 0U, 2, 1,
          64), false);
        sf_mex_call(&c9_st, &c9_p_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                    sf_mex_call(&c9_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c9_st, NULL, "message", 1U, 1U, 14, c9_h_y)));
      }

      c9_Hn[(int32_T)c9_b_i - 1] = c9_hcost;
    }
  }
}

static void c9_plannerAStarGrid_Chebyshev
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, real_T
   c9_b_pose1[426400], real_T c9_pose2[426400], real_T c9_dist[213200])
{
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_d_y;
  real_T c9_e_y;
  real_T c9_ex;
  real_T c9_f_y;
  int32_T c9_b_ia;
  int32_T c9_b_ib;
  int32_T c9_b_ic;
  int32_T c9_b_k;
  int32_T c9_b_varargin_1;
  int32_T c9_b_varargin_2;
  int32_T c9_b_varargin_3;
  int32_T c9_b_xj;
  int32_T c9_c_k;
  int32_T c9_c_varargin_1;
  int32_T c9_c_varargin_2;
  int32_T c9_c_xj;
  int32_T c9_d_k;
  int32_T c9_e_k;
  int32_T c9_f_k;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_ia;
  int32_T c9_ib;
  int32_T c9_ic;
  int32_T c9_ix;
  int32_T c9_k;
  int32_T c9_varargin_3;
  int32_T c9_varargin_4;
  int32_T c9_varargin_5;
  int32_T c9_varargin_6;
  int32_T c9_xj;
  for (c9_k = 0; c9_k < 2; c9_k++) {
    c9_ia = c9_k;
    c9_ib = c9_k;
    c9_ic = c9_k;
    c9_b_varargin_1 = c9_ic + 1;
    c9_b_varargin_2 = c9_ia + 1;
    c9_varargin_3 = c9_ib + 1;
    for (c9_e_k = 0; c9_e_k < 213200; c9_e_k++) {
      c9_b_ia = c9_e_k;
      c9_b_ib = c9_e_k;
      c9_b_ic = c9_e_k;
      c9_c_varargin_1 = c9_b_ic;
      c9_c_varargin_2 = c9_b_varargin_1 - 1;
      c9_b_varargin_3 = c9_b_ia;
      c9_varargin_4 = c9_b_varargin_2 - 1;
      c9_varargin_5 = c9_b_ib;
      c9_varargin_6 = c9_varargin_3 - 1;
      chartInstance->c9_b_c[c9_c_varargin_1 + 213200 * c9_c_varargin_2] =
        c9_b_pose1[c9_b_varargin_3 + 213200 * c9_varargin_4] -
        c9_pose2[c9_varargin_5 + 213200 * c9_varargin_6];
    }
  }

  for (c9_b_k = 0; c9_b_k < 426400; c9_b_k++) {
    c9_c_k = c9_b_k;
    c9_b_x = chartInstance->c9_b_c[c9_c_k];
    c9_d_y = muDoubleScalarAbs(c9_b_x);
    chartInstance->c9_difference[c9_c_k] = c9_d_y;
  }

  for (c9_i = 0; c9_i < 213200; c9_i++) {
    chartInstance->c9_varargin_1[c9_i] = chartInstance->c9_difference[c9_i];
  }

  for (c9_i1 = 0; c9_i1 < 213200; c9_i1++) {
    chartInstance->c9_varargin_2[c9_i1] = chartInstance->c9_difference[c9_i1 +
      213200];
  }

  for (c9_d_k = 0; c9_d_k < 213200; c9_d_k++) {
    c9_f_k = c9_d_k;
    c9_c_x = chartInstance->c9_varargin_1[c9_f_k];
    c9_e_y = chartInstance->c9_varargin_2[c9_f_k];
    c9_d_x = c9_c_x;
    c9_f_y = c9_e_y;
    c9_ex = muDoubleScalarMin(c9_d_x, c9_f_y);
    chartInstance->c9_minval[c9_f_k] = c9_ex;
  }

  for (c9_xj = 0; c9_xj < 213200; c9_xj++) {
    c9_c_xj = c9_xj;
    c9_dist[c9_c_xj] = chartInstance->c9_difference[c9_c_xj];
  }

  for (c9_b_xj = 0; c9_b_xj < 213200; c9_b_xj++) {
    c9_c_xj = c9_b_xj;
    c9_ix = c9_c_xj;
    c9_dist[c9_c_xj] += chartInstance->c9_difference[c9_ix + 213200];
  }

  for (c9_i2 = 0; c9_i2 < 213200; c9_i2++) {
    c9_dist[c9_i2] -= chartInstance->c9_minval[c9_i2];
  }
}

static real_T c9_plannerAStarGrid_Euclidean
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, real_T c9_b_pose1[2], real_T c9_pose2[2])
{
  static char_T c9_b_cv[4] = { 's', 'q', 'r', 't' };

  emlrtStack c9_st;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  real_T c9_b_a[2];
  real_T c9_e_y[2];
  real_T c9_b_x;
  real_T c9_c_a;
  real_T c9_c_x;
  real_T c9_d_y;
  real_T c9_dist;
  real_T c9_f_y;
  int32_T c9_b_k;
  int32_T c9_i;
  int32_T c9_k;
  boolean_T c9_b_p;
  boolean_T c9_p;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_b_a[c9_i] = c9_b_pose1[c9_i] - c9_pose2[c9_i];
  }

  for (c9_k = 0; c9_k < 2; c9_k++) {
    c9_b_k = c9_k;
    c9_c_a = c9_b_a[c9_b_k];
    c9_f_y = c9_c_a * c9_c_a;
    c9_e_y[c9_b_k] = c9_f_y;
  }

  c9_d_y = c9_sumColumnB(chartInstance, c9_e_y);
  c9_st.site = &c9_af_emlrtRSI;
  c9_b_x = c9_d_y;
  c9_dist = c9_b_x;
  c9_c_x = c9_dist;
  if (c9_c_x < 0.0) {
    c9_p = true;
  } else {
    c9_p = false;
  }

  c9_b_p = c9_p;
  if (c9_b_p) {
    c9_g_y = NULL;
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_cv8, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c9_h_y = NULL;
    sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_cv8, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c9_i_y = NULL;
    sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c9_st, &c9_o_emlrtMCI, "error", 0U, 2U, 14, c9_g_y, 14,
                sf_mex_call(&c9_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_st, NULL, "message", 1U, 2U, 14, c9_h_y, 14, c9_i_y)));
  }

  return muDoubleScalarSqrt(c9_dist);
}

static real_T c9_sumColumnB(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c9_b_x[2])
{
  real_T c9_d_y;
  (void)chartInstance;
  c9_d_y = c9_b_x[0];
  c9_d_y += c9_b_x[1];
  return c9_d_y;
}

static void c9_plannerAStarGrid_getNeighbors
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T
   c9_Neighbors_data[], int32_T c9_Neighbors_size[2], real_T *c9_NumNeighbors)
{
  static real_T c9_Neighbors[16] = { -1.0, 0.0, 1.0, -1.0, 1.0, -1.0, 0.0, 1.0,
    -1.0, -1.0, -1.0, 0.0, 0.0, 1.0, 1.0, 1.0 };

  static real_T c9_b_Neighbors[8] = { 0.0, -1.0, 1.0, 0.0, -1.0, 0.0, 0.0, 1.0 };

  int32_T c9_i;
  int32_T c9_i1;
  (void)chartInstance;
  if (c9_obj->DiagonalSearchFlag != (real_T)(int32_T)muDoubleScalarFloor
      (c9_obj->DiagonalSearchFlag)) {
    emlrtIntegerCheckR2012b(c9_obj->DiagonalSearchFlag, &c9_qb_emlrtDCI,
      (emlrtConstCTX)c9_sp);
  }

  if ((int32_T)c9_obj->DiagonalSearchFlag == 0) {
    c9_Neighbors_size[0] = 4;
    c9_Neighbors_size[1] = 2;
    for (c9_i1 = 0; c9_i1 < 8; c9_i1++) {
      c9_Neighbors_data[c9_i1] = c9_b_Neighbors[c9_i1];
    }

    *c9_NumNeighbors = 4.0;
  } else {
    c9_Neighbors_size[0] = 8;
    c9_Neighbors_size[1] = 2;
    for (c9_i = 0; c9_i < 16; c9_i++) {
      c9_Neighbors_data[c9_i] = c9_Neighbors[c9_i];
    }

    *c9_NumNeighbors = 8.0;
  }
}

static void c9_plannerAStarGrid_reconstructPath
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_CurrentRow,
   real_T c9_CurrentCol, real_T c9_startIn[2])
{
  static char_T c9_b_cv[16] = { 'P', 'a', 't', 'h', 'P', 'o', 'i', 'n', 't', 'C',
    'o', 'u', 'n', 't', 'e', 'r' };

  c9_coder_array_int32_T c9_r;
  c9_coder_array_real_T c9_c_x;
  c9_coder_array_real_T_2D c9_b_x;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  real_T c9_CurrentColDummy;
  real_T c9_b_tmp;
  real_T c9_b_u;
  real_T c9_k;
  real_T c9_tmp;
  int32_T c9_iv[2];
  int32_T c9_iv1[2];
  int32_T c9_iv2[1];
  int32_T c9_iv3[1];
  int32_T c9_b_k;
  int32_T c9_b_loop_ub;
  int32_T c9_b_n;
  int32_T c9_b_nd2;
  int32_T c9_c_k;
  int32_T c9_c_loop_ub;
  int32_T c9_d_k;
  int32_T c9_d_loop_ub;
  int32_T c9_e_k;
  int32_T c9_e_loop_ub;
  int32_T c9_exitg1;
  int32_T c9_f_k;
  int32_T c9_f_loop_ub;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_j;
  int32_T c9_loop_ub;
  int32_T c9_n;
  int32_T c9_nd2;
  int32_T c9_offset;
  int32_T c9_vlen;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_k = 1.0;
  chartInstance->c9_OptimalPath[0] = c9_CurrentRow;
  chartInstance->c9_OptimalPath[213200] = c9_CurrentCol;
  if (c9_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor(c9_CurrentRow)) {
    emlrtIntegerCheckR2012b(c9_CurrentRow, &c9_rb_emlrtDCI, (emlrtConstCTX)c9_sp);
  }

  c9_i = (int32_T)c9_CurrentRow;
  if ((c9_i < 1) || (c9_i > 410)) {
    emlrtDynamicBoundsCheckR2012b(c9_i, 1, 410, &c9_pd_emlrtBCI, (emlrtConstCTX)
      c9_sp);
  }

  if (c9_CurrentCol != (real_T)(int32_T)muDoubleScalarFloor(c9_CurrentCol)) {
    emlrtIntegerCheckR2012b(c9_CurrentCol, &c9_sb_emlrtDCI, (emlrtConstCTX)c9_sp);
  }

  c9_i1 = (int32_T)c9_CurrentCol;
  if ((c9_i1 < 1) || (c9_i1 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c9_i1, 1, 520, &c9_qd_emlrtBCI, (emlrtConstCTX)
      c9_sp);
  }

  chartInstance->c9_pathIndices[0] = c9_obj->MapIndex[(c9_i + 410 * (c9_i1 - 1))
    - 1];
  do {
    c9_exitg1 = 0;
    c9_k++;
    if (!(c9_k <= 213200.0)) {
      c9_d_y = NULL;
      sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                    false);
      c9_e_y = NULL;
      sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                    false);
      c9_f_y = NULL;
      sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 16),
                    false);
      c9_b_u = 213200.0;
      c9_g_y = NULL;
      sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0, 0U, 0), false);
      sf_mex_call(c9_sp, &c9_r_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                  sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c9_sp, NULL, "message", 1U, 3U, 14, c9_e_y, 14, c9_f_y, 14, c9_g_y)));
    }

    c9_CurrentColDummy = c9_obj->ParentCol[((int32_T)c9_CurrentRow + 410 *
      ((int32_T)c9_CurrentCol - 1)) - 1];
    c9_CurrentRow = c9_obj->ParentRow[((int32_T)c9_CurrentRow + 410 * ((int32_T)
      c9_CurrentCol - 1)) - 1];
    c9_CurrentCol = c9_CurrentColDummy;
    if ((c9_CurrentRow == 0.0) || (c9_CurrentColDummy == 0.0)) {
      c9_k--;
      c9_exitg1 = 1;
    } else {
      c9_b_k = (int32_T)c9_k - 1;
      chartInstance->c9_OptimalPath[c9_b_k] = c9_CurrentRow;
      chartInstance->c9_OptimalPath[213200 + c9_b_k] = c9_CurrentColDummy;
      if (c9_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor(c9_CurrentRow))
      {
        emlrtIntegerCheckR2012b(c9_CurrentRow, &c9_tb_emlrtDCI, (emlrtConstCTX)
          c9_sp);
      }

      c9_i2 = (int32_T)c9_CurrentRow;
      if ((c9_i2 < 1) || (c9_i2 > 410)) {
        emlrtDynamicBoundsCheckR2012b(c9_i2, 1, 410, &c9_rd_emlrtBCI,
          (emlrtConstCTX)c9_sp);
      }

      if (c9_CurrentColDummy != (real_T)(int32_T)muDoubleScalarFloor
          (c9_CurrentColDummy)) {
        emlrtIntegerCheckR2012b(c9_CurrentColDummy, &c9_ub_emlrtDCI,
          (emlrtConstCTX)c9_sp);
      }

      c9_i5 = (int32_T)c9_CurrentColDummy;
      if ((c9_i5 < 1) || (c9_i5 > 520)) {
        emlrtDynamicBoundsCheckR2012b(c9_i5, 1, 520, &c9_sd_emlrtBCI,
          (emlrtConstCTX)c9_sp);
      }

      chartInstance->c9_pathIndices[(int32_T)c9_k - 1] = c9_obj->MapIndex[(c9_i2
        + 410 * (c9_i5 - 1)) - 1];
      if ((c9_CurrentColDummy == c9_startIn[1]) && (c9_CurrentRow == c9_startIn
           [0])) {
        c9_exitg1 = 1;
      }
    }
  } while (c9_exitg1 == 0);

  c9_obj->NumPathPoints = c9_k;
  c9_i3 = (int32_T)c9_k - 1;
  c9_i4 = (int32_T)c9_k - 1;
  c9_array_int32_T_Constructor(chartInstance, &c9_r);
  c9_st.site = &c9_lg_emlrtRSI;
  c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_r, &c9_cb_emlrtRTEI, c9_i4
    + 1);
  c9_loop_ub = c9_i4;
  for (c9_i6 = 0; c9_i6 <= c9_loop_ub; c9_i6++) {
    c9_r.vector.data[c9_i6] = c9_i6;
  }

  c9_array_real_T_2D_Constructor(chartInstance, &c9_b_x);
  c9_st.site = &c9_lg_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_b_x, &c9_db_emlrtRTEI,
    c9_i3 + 1, 2);
  for (c9_i7 = 0; c9_i7 < 2; c9_i7++) {
    c9_b_loop_ub = c9_i3;
    for (c9_i8 = 0; c9_i8 <= c9_b_loop_ub; c9_i8++) {
      c9_b_x.vector.data[c9_i8 + c9_b_x.size[0] * c9_i7] =
        chartInstance->c9_OptimalPath[c9_i8 + 213200 * c9_i7];
    }
  }

  if ((real_T)c9_b_x.size[0] > 1.0) {
    c9_vlen = c9_b_x.size[0];
    c9_n = c9_b_x.size[0];
    c9_nd2 = (c9_n >> 1) - 1;
    for (c9_j = 0; c9_j < 2; c9_j++) {
      c9_offset = c9_j * c9_vlen;
      for (c9_c_k = 0; c9_c_k <= c9_nd2; c9_c_k++) {
        c9_d_k = c9_c_k;
        c9_tmp = c9_b_x.vector.data[c9_offset + c9_d_k];
        c9_b_x.vector.data[c9_offset + c9_d_k] = c9_b_x.vector.data[((c9_offset
          + c9_n) - c9_d_k) - 1];
        c9_b_x.vector.data[((c9_offset + c9_n) - c9_d_k) - 1] = c9_tmp;
      }
    }
  }

  c9_iv[0] = c9_r.size[0];
  c9_iv[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&c9_iv[0], 2, &c9_b_x.size[0], 2, &c9_d_emlrtECI,
    (void *)c9_sp);
  c9_iv1[0] = c9_r.size[0];
  for (c9_i9 = 0; c9_i9 < 2; c9_i9++) {
    c9_c_loop_ub = c9_iv1[0] - 1;
    for (c9_i11 = 0; c9_i11 <= c9_c_loop_ub; c9_i11++) {
      c9_obj->PathInternal[c9_r.vector.data[c9_i11] + 213200 * c9_i9] =
        c9_b_x.vector.data[c9_i11 + c9_b_x.size[0] * c9_i9];
    }
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_b_x);
  c9_i10 = (int32_T)c9_k - 1;
  c9_i12 = (int32_T)c9_k - 1;
  c9_st.site = &c9_pg_emlrtRSI;
  c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_r, &c9_eb_emlrtRTEI,
    c9_i12 + 1);
  c9_d_loop_ub = c9_i12;
  for (c9_i13 = 0; c9_i13 <= c9_d_loop_ub; c9_i13++) {
    c9_r.vector.data[c9_i13] = c9_i13;
  }

  c9_array_real_T_Constructor(chartInstance, &c9_c_x);
  c9_st.site = &c9_pg_emlrtRSI;
  c9_array_real_T_SetSize(chartInstance, &c9_st, &c9_c_x, &c9_fb_emlrtRTEI,
    c9_i10 + 1);
  c9_e_loop_ub = c9_i10;
  for (c9_i14 = 0; c9_i14 <= c9_e_loop_ub; c9_i14++) {
    c9_c_x.vector.data[c9_i14] = chartInstance->c9_pathIndices[c9_i14];
  }

  if ((real_T)c9_c_x.size[0] > 1.0) {
    c9_b_n = c9_c_x.size[0];
    c9_b_nd2 = (c9_b_n >> 1) - 1;
    for (c9_e_k = 0; c9_e_k <= c9_b_nd2; c9_e_k++) {
      c9_f_k = c9_e_k;
      c9_b_tmp = c9_c_x.vector.data[c9_f_k];
      c9_c_x.vector.data[c9_f_k] = c9_c_x.vector.data[(c9_b_n - c9_f_k) - 1];
      c9_c_x.vector.data[(c9_b_n - c9_f_k) - 1] = c9_b_tmp;
    }
  }

  c9_iv2[0] = c9_r.size[0];
  emlrtSubAssignSizeCheckR2012b(&c9_iv2[0], 1, &c9_c_x.size[0], 1,
    &c9_c_emlrtECI, (void *)c9_sp);
  c9_iv3[0] = c9_r.size[0];
  c9_f_loop_ub = c9_iv3[0] - 1;
  for (c9_i15 = 0; c9_i15 <= c9_f_loop_ub; c9_i15++) {
    c9_obj->PathIndicesInternal[c9_r.vector.data[c9_i15]] =
      c9_c_x.vector.data[c9_i15];
  }

  c9_array_real_T_Destructor(chartInstance, &c9_c_x);
  c9_array_int32_T_Destructor(chartInstance, &c9_r);
}

static real_T c9_plannerAStarGrid_gcostValue
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_plannerAStarGrid *c9_obj, real_T c9_CurrentRow,
   real_T c9_CurrentCol, real_T c9_i, real_T c9_j)
{
  static char_T c9_b_cv[4] = { 's', 'q', 'r', 't' };

  c9_nav_algs_internal_plannerAStarGrid *c9_b_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_st;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_l_y = NULL;
  const mxArray *c9_o_y = NULL;
  const mxArray *c9_q_y = NULL;
  const mxArray *c9_s_y = NULL;
  real_T c9_b_CurrentRow[2];
  real_T c9_b_difference[2];
  real_T c9_c_CurrentRow[2];
  real_T c9_c_c[2];
  real_T c9_d_y[2];
  real_T c9_b_a;
  real_T c9_b_minval;
  real_T c9_b_varargin_2;
  real_T c9_b_x;
  real_T c9_c_a;
  real_T c9_c_varargin_1;
  real_T c9_c_x;
  real_T c9_d_a;
  real_T c9_d_b;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_e_y;
  real_T c9_f_x;
  real_T c9_f_y;
  real_T c9_g_x;
  real_T c9_g_y;
  real_T c9_gcostNeighbor;
  real_T c9_h_x;
  real_T c9_h_y;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_j_y;
  real_T c9_k_x;
  real_T c9_k_y;
  real_T c9_l_x;
  real_T c9_m_y;
  real_T c9_n_y;
  real_T c9_p_y;
  real_T c9_r_y;
  real_T c9_t_y;
  real_T c9_type;
  real_T c9_val;
  int32_T c9_b_i;
  int32_T c9_b_ib;
  int32_T c9_b_ic;
  int32_T c9_b_k;
  int32_T c9_b_varargin_1;
  int32_T c9_b_varargin_3;
  int32_T c9_b_varargin_6;
  int32_T c9_c_k;
  int32_T c9_c_varargin_2;
  int32_T c9_d_k;
  int32_T c9_d_varargin_1;
  int32_T c9_d_varargin_2;
  int32_T c9_e_k;
  int32_T c9_f_k;
  int32_T c9_g_k;
  int32_T c9_h_k;
  int32_T c9_i1;
  int32_T c9_i_k;
  int32_T c9_ib;
  int32_T c9_ic;
  int32_T c9_j_k;
  int32_T c9_k;
  int32_T c9_varargin_3;
  int32_T c9_varargin_6;
  boolean_T c9_b_b;
  boolean_T c9_b_p;
  boolean_T c9_c_b;
  boolean_T c9_guard1;
  boolean_T c9_p;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  if (c9_obj->UseCustomG == 0.0) {
    c9_st.site = &c9_cf_emlrtRSI;
    c9_b_obj = c9_obj;
    c9_b_difference[0] = c9_i;
    c9_b_difference[1] = c9_j;
    c9_type = c9_obj->GCostMethod;
    if (c9_type != (real_T)(int32_T)muDoubleScalarFloor(c9_type)) {
      emlrtIntegerCheckR2012b(c9_type, &c9_pb_emlrtDCI, &c9_st);
    }

    switch ((int32_T)c9_type) {
     case 2:
      for (c9_k = 0; c9_k < 2; c9_k++) {
        c9_ib = c9_k;
        c9_ic = c9_k;
        c9_b_varargin_1 = c9_ic + 1;
        c9_varargin_3 = c9_ib + 1;
        c9_c_varargin_2 = c9_b_varargin_1 - 1;
        c9_varargin_6 = c9_varargin_3 - 1;
        c9_c_c[c9_c_varargin_2] = 0.0 - c9_b_difference[c9_varargin_6];
      }

      for (c9_c_k = 0; c9_c_k < 2; c9_c_k++) {
        c9_g_k = c9_c_k;
        c9_d_x = c9_c_c[c9_g_k];
        c9_f_y = muDoubleScalarAbs(c9_d_x);
        c9_d_y[c9_g_k] = c9_f_y;
      }

      c9_gcostNeighbor = c9_sumColumnB(chartInstance, c9_d_y);
      break;

     case 3:
      for (c9_b_k = 0; c9_b_k < 2; c9_b_k++) {
        c9_b_ib = c9_b_k;
        c9_b_ic = c9_b_k;
        c9_d_varargin_1 = c9_b_ic + 1;
        c9_b_varargin_3 = c9_b_ib + 1;
        c9_d_varargin_2 = c9_d_varargin_1 - 1;
        c9_b_varargin_6 = c9_b_varargin_3 - 1;
        c9_c_c[c9_d_varargin_2] = 0.0 - c9_b_difference[c9_b_varargin_6];
      }

      for (c9_d_k = 0; c9_d_k < 2; c9_d_k++) {
        c9_h_k = c9_d_k;
        c9_e_x = c9_c_c[c9_h_k];
        c9_g_y = muDoubleScalarAbs(c9_e_x);
        c9_b_difference[c9_h_k] = c9_g_y;
      }

      c9_c_varargin_1 = c9_b_difference[0];
      c9_b_varargin_2 = c9_b_difference[1];
      c9_f_x = c9_c_varargin_1;
      c9_k_y = c9_b_varargin_2;
      c9_h_x = c9_f_x;
      c9_m_y = c9_k_y;
      c9_j_x = c9_h_x;
      c9_n_y = c9_m_y;
      c9_d_a = c9_j_x;
      c9_d_b = c9_n_y;
      c9_k_x = c9_d_a;
      c9_p_y = c9_d_b;
      c9_l_x = c9_k_x;
      c9_r_y = c9_p_y;
      c9_b_minval = muDoubleScalarMin(c9_l_x, c9_r_y);
      c9_t_y = c9_sumColumnB(chartInstance, c9_b_difference);
      c9_gcostNeighbor = c9_t_y - c9_b_minval;
      break;

     case 4:
      for (c9_b_i = 0; c9_b_i < 2; c9_b_i++) {
        c9_b_difference[c9_b_i] = -c9_b_difference[c9_b_i];
      }

      for (c9_e_k = 0; c9_e_k < 2; c9_e_k++) {
        c9_i_k = c9_e_k;
        c9_b_a = c9_b_difference[c9_i_k];
        c9_h_y = c9_b_a * c9_b_a;
        c9_d_y[c9_i_k] = c9_h_y;
      }

      c9_gcostNeighbor = c9_sumColumnB(chartInstance, c9_d_y);
      break;

     default:
      c9_b_st.site = &c9_xe_emlrtRSI;
      for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
        c9_b_difference[c9_i1] = -c9_b_difference[c9_i1];
      }

      for (c9_f_k = 0; c9_f_k < 2; c9_f_k++) {
        c9_j_k = c9_f_k;
        c9_c_a = c9_b_difference[c9_j_k];
        c9_j_y = c9_c_a * c9_c_a;
        c9_d_y[c9_j_k] = c9_j_y;
      }

      c9_e_y = c9_sumColumnB(chartInstance, c9_d_y);
      c9_c_st.site = &c9_ye_emlrtRSI;
      c9_g_x = c9_e_y;
      c9_gcostNeighbor = c9_g_x;
      c9_i_x = c9_gcostNeighbor;
      if (c9_i_x < 0.0) {
        c9_p = true;
      } else {
        c9_p = false;
      }

      c9_b_p = c9_p;
      if (c9_b_p) {
        c9_o_y = NULL;
        sf_mex_assign(&c9_o_y, sf_mex_create("y", c9_cv8, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c9_q_y = NULL;
        sf_mex_assign(&c9_q_y, sf_mex_create("y", c9_cv8, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c9_s_y = NULL;
        sf_mex_assign(&c9_s_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1,
          4), false);
        sf_mex_call(&c9_c_st, &c9_o_emlrtMCI, "error", 0U, 2U, 14, c9_o_y, 14,
                    sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c9_c_st, NULL, "message", 1U, 2U, 14, c9_q_y, 14, c9_s_y)));
      }

      c9_gcostNeighbor = muDoubleScalarSqrt(c9_gcostNeighbor);
      break;
    }

    c9_gcostNeighbor /= c9_b_obj->MapResolution;
  } else {
    c9_b_CurrentRow[0] = c9_CurrentRow;
    c9_b_CurrentRow[1] = c9_CurrentCol;
    c9_c_CurrentRow[0] = c9_CurrentRow + c9_i;
    c9_c_CurrentRow[1] = c9_CurrentCol + c9_j;
    c9_st.site = &c9_df_emlrtRSI;
    c9_gcostNeighbor = c9_plannerAStarGrid_Euclidean(chartInstance, &c9_st,
      c9_b_CurrentRow, c9_c_CurrentRow) / c9_obj->MapResolution;
    c9_st.site = &c9_ef_emlrtRSI;
    c9_val = c9_gcostNeighbor;
    c9_b_x = c9_val;
    c9_b_b = muDoubleScalarIsNaN(c9_b_x);
    c9_guard1 = false;
    if (c9_b_b) {
      c9_guard1 = true;
    } else {
      c9_c_x = c9_val;
      c9_c_b = muDoubleScalarIsInf(c9_c_x);
      if (c9_c_b) {
        c9_guard1 = true;
      }
    }

    if (c9_guard1) {
      c9_i_y = NULL;
      sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_cv9, 10, 0U, 1, 0U, 2, 1, 64),
                    false);
      c9_l_y = NULL;
      sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_cv9, 10, 0U, 1, 0U, 2, 1, 64),
                    false);
      sf_mex_call(&c9_st, &c9_p_emlrtMCI, "error", 0U, 2U, 14, c9_i_y, 14,
                  sf_mex_call(&c9_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c9_st, NULL, "message", 1U, 1U, 14, c9_l_y)));
    }
  }

  return c9_gcostNeighbor;
}

static void c9_indexShapeCheck(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c9_plannerAStarGrid_getEssentialOutput
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_nav_algs_internal_plannerAStarGrid
   *c9_b_astarInternal)
{
  static char_T c9_b_cv[12] = { 'N', 'u', 'm', 'P', 'a', 't', 'h', 'N', 'o', 'd',
    'e', 's' };

  c9_coder_array_int32_T c9_r;
  c9_coder_array_real_T c9_path;
  c9_nav_algs_internal_plannerAStarGrid *c9_b_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_c_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_d_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_e_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_f_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_g_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_h_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_i_obj;
  c9_nav_algs_internal_plannerAStarGrid *c9_j_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_st;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_j_y = NULL;
  const mxArray *c9_k_y = NULL;
  const mxArray *c9_l_y = NULL;
  real_T c9_H;
  real_T c9_b_H;
  real_T c9_b_k;
  real_T c9_b_numNodes;
  real_T c9_b_path;
  real_T c9_b_u;
  real_T c9_c_u;
  real_T c9_cost;
  real_T c9_d;
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_d3;
  real_T c9_d4;
  real_T c9_d5;
  real_T c9_numNodes;
  int32_T c9_iv[1];
  int32_T c9_iv1[1];
  int32_T c9_iv2[1];
  int32_T c9_iv3[1];
  int32_T c9_b_loop_ub;
  int32_T c9_c_loop_ub;
  int32_T c9_d_loop_ub;
  int32_T c9_e_loop_ub;
  int32_T c9_f_loop_ub;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i2;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_k;
  int32_T c9_loop_ub;
  boolean_T c9_b_x[2];
  boolean_T c9_x_data[2];
  boolean_T c9_b1;
  boolean_T c9_b2;
  boolean_T c9_b3;
  boolean_T c9_b4;
  boolean_T c9_b5;
  boolean_T c9_b_b;
  boolean_T c9_d_y;
  boolean_T c9_exitg1;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_st.site = &c9_pf_emlrtRSI;
  c9_b_obj = c9_b_astarInternal;
  c9_b_st.site = &c9_qf_emlrtRSI;
  c9_c_obj = c9_b_obj;
  c9_d = c9_c_obj->NumPathPoints;
  c9_b_b = (c9_d < 1.0);
  if (c9_b_b) {
    c9_i = -1;
  } else {
    if (c9_d != (real_T)(int32_T)muDoubleScalarFloor(c9_d)) {
      emlrtIntegerCheckR2012b(c9_d, &c9_yb_emlrtDCI, &c9_b_st);
    }

    c9_i1 = (int32_T)c9_d;
    if ((c9_i1 < 1) || (c9_i1 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i1, 1, 213200, &c9_xd_emlrtBCI, &c9_b_st);
    }

    c9_i = c9_i1 - 1;
  }

  c9_array_real_T_Constructor(chartInstance, &c9_path);
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_path, &c9_gb_emlrtRTEI,
    c9_i + 1);
  c9_loop_ub = c9_i;
  for (c9_i2 = 0; c9_i2 <= c9_loop_ub; c9_i2++) {
    c9_path.vector.data[c9_i2] = c9_c_obj->PathIndicesInternal[c9_i2];
  }

  c9_H = (real_T)c9_path.size[0];
  c9_obj->NumPathPoints = c9_H;
  c9_st.site = &c9_of_emlrtRSI;
  c9_d_obj = c9_b_astarInternal;
  c9_b_st.site = &c9_rf_emlrtRSI;
  c9_e_obj = c9_d_obj;
  c9_d1 = c9_e_obj->NumNodesExplored;
  c9_b1 = (c9_d1 < 1.0);
  if (!c9_b1) {
    if (c9_d1 != (real_T)(int32_T)muDoubleScalarFloor(c9_d1)) {
      emlrtIntegerCheckR2012b(c9_d1, &c9_l_emlrtDCI, &c9_b_st);
    }

    c9_i3 = (int32_T)c9_d1;
    if ((c9_i3 < 1) || (c9_i3 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i3, 1, 213200, &c9_ib_emlrtBCI, &c9_b_st);
    }
  }

  c9_st.site = &c9_nf_emlrtRSI;
  c9_f_obj = c9_b_astarInternal;
  c9_numNodes = c9_f_obj->NumNodesExplored;
  c9_obj->NumNodesExplored = c9_numNodes;
  if (c9_obj->NumPathPoints == 0.0) {
    c9_obj->PathCost = rtInf;
    c9_st.site = &c9_mf_emlrtRSI;
    c9_warning(chartInstance, &c9_st);
  } else {
    c9_st.site = &c9_lf_emlrtRSI;
    c9_g_obj = c9_b_astarInternal;
    c9_cost = c9_g_obj->PathCost;
    c9_obj->PathCost = c9_cost;
  }

  c9_b_path = (real_T)c9_path.size[0];
  c9_b_x[0] = (c9_b_path <= 213200.0);
  c9_b_x[1] = true;
  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    c9_x_data[c9_i4] = c9_b_x[c9_i4];
  }

  c9_d_y = true;
  c9_k = 0;
  c9_exitg1 = false;
  while ((!c9_exitg1) && (c9_k < 2)) {
    c9_b_k = (real_T)c9_k + 1.0;
    if (!c9_x_data[(int32_T)c9_b_k - 1]) {
      c9_d_y = false;
      c9_exitg1 = true;
    } else {
      c9_k++;
    }
  }

  if (!c9_d_y) {
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c9_f_y = NULL;
    sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c9_g_y = NULL;
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 12),
                  false);
    c9_b_u = 213200.0;
    c9_h_y = NULL;
    sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(c9_sp, &c9_t_emlrtMCI, "error", 0U, 2U, 14, c9_e_y, 14,
                sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c9_sp, NULL, "message", 1U, 3U, 14, c9_f_y, 14, c9_g_y, 14, c9_h_y)));
  }

  c9_b_H = (real_T)c9_path.size[0];
  c9_obj->NumPathPoints = c9_b_H;
  for (c9_i5 = 0; c9_i5 < 213200; c9_i5++) {
    chartInstance->c9_pathTemp[c9_i5] = 0.0;
  }

  c9_d2 = c9_obj->NumPathPoints;
  c9_b2 = (c9_d2 < 1.0);
  if (c9_b2) {
    c9_i7 = -1;
  } else {
    c9_i6 = c9_path.size[0];
    c9_i8 = 1;
    if ((c9_i8 < 1) || (c9_i8 > c9_i6)) {
      emlrtDynamicBoundsCheckR2012b(c9_i8, 1, c9_i6, &c9_wd_emlrtBCI,
        (emlrtConstCTX)c9_sp);
    }

    c9_i9 = c9_path.size[0];
    if (c9_d2 != (real_T)(int32_T)muDoubleScalarFloor(c9_d2)) {
      emlrtIntegerCheckR2012b(c9_d2, &c9_xb_emlrtDCI, (emlrtConstCTX)c9_sp);
    }

    c9_i11 = (int32_T)c9_d2;
    if ((c9_i11 < 1) || (c9_i11 > c9_i9)) {
      emlrtDynamicBoundsCheckR2012b(c9_i11, 1, c9_i9, &c9_vd_emlrtBCI,
        (emlrtConstCTX)c9_sp);
    }

    c9_i7 = c9_i11 - 1;
  }

  c9_d3 = c9_obj->NumPathPoints;
  c9_b3 = (c9_d3 < 1.0);
  if (c9_b3) {
    c9_i10 = -1;
  } else {
    if (c9_d3 != (real_T)(int32_T)muDoubleScalarFloor(c9_d3)) {
      emlrtIntegerCheckR2012b(c9_d3, &c9_wb_emlrtDCI, (emlrtConstCTX)c9_sp);
    }

    c9_i12 = (int32_T)c9_d3;
    if ((c9_i12 < 1) || (c9_i12 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i12, 1, 213200, &c9_ud_emlrtBCI,
        (emlrtConstCTX)c9_sp);
    }

    c9_i10 = c9_i12 - 1;
  }

  c9_array_int32_T_Constructor(chartInstance, &c9_r);
  c9_st.site = &c9_og_emlrtRSI;
  c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_r, &c9_hb_emlrtRTEI,
    c9_i10 + 1);
  c9_b_loop_ub = c9_i10;
  for (c9_i13 = 0; c9_i13 <= c9_b_loop_ub; c9_i13++) {
    c9_r.vector.data[c9_i13] = c9_i13;
  }

  c9_st.site = &c9_og_emlrtRSI;
  c9_array_real_T_SetSize(chartInstance, &c9_st, &c9_path, &c9_ib_emlrtRTEI,
    c9_i7 + 1);
  c9_iv[0] = c9_r.size[0];
  emlrtSubAssignSizeCheckR2012b(&c9_iv[0], 1, &c9_path.size[0], 1,
    &c9_f_emlrtECI, (void *)c9_sp);
  c9_iv1[0] = c9_r.size[0];
  c9_c_loop_ub = c9_iv1[0] - 1;
  for (c9_i14 = 0; c9_i14 <= c9_c_loop_ub; c9_i14++) {
    chartInstance->c9_pathTemp[c9_r.vector.data[c9_i14]] =
      c9_path.vector.data[c9_i14];
  }

  for (c9_i15 = 0; c9_i15 < 213200; c9_i15++) {
    c9_obj->Path[c9_i15] = chartInstance->c9_pathTemp[c9_i15];
  }

  c9_st.site = &c9_kf_emlrtRSI;
  c9_h_obj = c9_b_astarInternal;
  c9_b_st.site = &c9_rf_emlrtRSI;
  c9_i_obj = c9_h_obj;
  c9_d4 = c9_i_obj->NumNodesExplored;
  c9_b4 = (c9_d4 < 1.0);
  if (c9_b4) {
    c9_i16 = -1;
  } else {
    if (c9_d4 != (real_T)(int32_T)muDoubleScalarFloor(c9_d4)) {
      emlrtIntegerCheckR2012b(c9_d4, &c9_l_emlrtDCI, &c9_b_st);
    }

    c9_i17 = (int32_T)c9_d4;
    if ((c9_i17 < 1) || (c9_i17 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i17, 1, 213200, &c9_ib_emlrtBCI, &c9_b_st);
    }

    c9_i16 = c9_i17 - 1;
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_path, &c9_jb_emlrtRTEI,
    c9_i16 + 1);
  c9_d_loop_ub = c9_i16;
  for (c9_i18 = 0; c9_i18 <= c9_d_loop_ub; c9_i18++) {
    c9_path.vector.data[c9_i18] = c9_i_obj->NodesExploredIndicesInternal[c9_i18];
  }

  c9_st.site = &c9_jf_emlrtRSI;
  c9_j_obj = c9_b_astarInternal;
  c9_b_numNodes = c9_j_obj->NumNodesExplored;
  c9_obj->NumNodesExplored = c9_b_numNodes;
  if (!(c9_obj->NumNodesExplored <= 213200.0)) {
    c9_i_y = NULL;
    sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c9_j_y = NULL;
    sf_mex_assign(&c9_j_y, sf_mex_create("y", c9_cv6, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c9_k_y = NULL;
    sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_cv7, 10, 0U, 1, 0U, 2, 1, 16),
                  false);
    c9_c_u = 213200.0;
    c9_l_y = NULL;
    sf_mex_assign(&c9_l_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(c9_sp, &c9_u_emlrtMCI, "error", 0U, 2U, 14, c9_i_y, 14,
                sf_mex_call(c9_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c9_sp, NULL, "message", 1U, 3U, 14, c9_j_y, 14, c9_k_y, 14, c9_l_y)));
  }

  for (c9_i19 = 0; c9_i19 < 213200; c9_i19++) {
    chartInstance->c9_pathTemp[c9_i19] = 0.0;
  }

  c9_d5 = c9_obj->NumNodesExplored;
  c9_b5 = (c9_d5 < 1.0);
  if (c9_b5) {
    c9_i20 = -1;
  } else {
    if (c9_d5 != (real_T)(int32_T)muDoubleScalarFloor(c9_d5)) {
      emlrtIntegerCheckR2012b(c9_d5, &c9_vb_emlrtDCI, (emlrtConstCTX)c9_sp);
    }

    c9_i21 = (int32_T)c9_d5;
    if ((c9_i21 < 1) || (c9_i21 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i21, 1, 213200, &c9_td_emlrtBCI,
        (emlrtConstCTX)c9_sp);
    }

    c9_i20 = c9_i21 - 1;
  }

  c9_st.site = &c9_ng_emlrtRSI;
  c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_r, &c9_kb_emlrtRTEI,
    c9_i20 + 1);
  c9_e_loop_ub = c9_i20;
  for (c9_i22 = 0; c9_i22 <= c9_e_loop_ub; c9_i22++) {
    c9_r.vector.data[c9_i22] = c9_i22;
  }

  c9_iv2[0] = c9_r.size[0];
  emlrtSubAssignSizeCheckR2012b(&c9_iv2[0], 1, &c9_path.size[0], 1,
    &c9_e_emlrtECI, (void *)c9_sp);
  c9_iv3[0] = c9_r.size[0];
  c9_f_loop_ub = c9_iv3[0] - 1;
  for (c9_i23 = 0; c9_i23 <= c9_f_loop_ub; c9_i23++) {
    chartInstance->c9_pathTemp[c9_r.vector.data[c9_i23]] =
      c9_path.vector.data[c9_i23];
  }

  c9_array_int32_T_Destructor(chartInstance, &c9_r);
  c9_array_real_T_Destructor(chartInstance, &c9_path);
  for (c9_i24 = 0; c9_i24 < 213200; c9_i24++) {
    c9_obj->NodesExploredIndices[c9_i24] = chartInstance->c9_pathTemp[c9_i24];
  }
}

static void c9_warning(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp)
{
  static char_T c9_msgID[40] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'N', 'o', 'P', 'a', 't', 'h', 'F', 'o', 'u', 'n',
    'd' };

  static char_T c9_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c9_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_b_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_msgID, 10, 0U, 1, 0U, 2, 1, 40),
                false);
  c9_st.site = &c9_sf_emlrtRSI;
  c9_b_feval(chartInstance, &c9_st, c9_d_y, c9_feval(chartInstance, &c9_st,
              c9_e_y, c9_f_y));
}

static void c9_plannerAStarGrid_getPathOutput
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_plannerAStarGrid *c9_obj, c9_coder_array_real_T_2D *c9_pathOut)
{
  c9_binaryOccupancyMap *c9_e_obj;
  c9_binaryOccupancyMap *c9_val;
  c9_coder_array_int32_T c9_r;
  c9_coder_array_real_T c9_path;
  c9_coder_array_real_T_2D c9_idx;
  c9_coder_array_real_T_2D c9_pose;
  c9_coder_array_real_T_2D c9_r1;
  c9_plannerAStarGrid *c9_b_obj;
  c9_plannerAStarGrid *c9_c_obj;
  c9_plannerAStarGrid *c9_d_obj;
  c9_plannerAStarGrid *c9_f_obj;
  c9_plannerAStarGrid *c9_g_obj;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  const mxArray *c9_h_y = NULL;
  const mxArray *c9_i_y = NULL;
  const mxArray *c9_k_y = NULL;
  const mxArray *c9_l_y = NULL;
  real_T c9_b_k;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d;
  real_T c9_d1;
  real_T c9_d2;
  real_T c9_d3;
  real_T c9_d4;
  real_T c9_d5;
  real_T c9_d6;
  real_T c9_d7;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_y;
  int32_T c9_iv[2];
  int32_T c9_iv1[2];
  int32_T c9_iv2[2];
  int32_T c9_iv3[2];
  int32_T c9_b_loop_ub;
  int32_T c9_c_loop_ub;
  int32_T c9_d_loop_ub;
  int32_T c9_e_loop_ub;
  int32_T c9_f_loop_ub;
  int32_T c9_g_loop_ub;
  int32_T c9_h_loop_ub;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i2;
  int32_T c9_i20;
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i3;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  int32_T c9_i33;
  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i4;
  int32_T c9_i40;
  int32_T c9_i41;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i_loop_ub;
  int32_T c9_j_loop_ub;
  int32_T c9_k;
  int32_T c9_k_loop_ub;
  int32_T c9_l_loop_ub;
  int32_T c9_loop_ub;
  int32_T c9_m_loop_ub;
  boolean_T c9_b1;
  boolean_T c9_b10;
  boolean_T c9_b11;
  boolean_T c9_b2;
  boolean_T c9_b3;
  boolean_T c9_b4;
  boolean_T c9_b5;
  boolean_T c9_b6;
  boolean_T c9_b7;
  boolean_T c9_b8;
  boolean_T c9_b9;
  boolean_T c9_b_b;
  boolean_T c9_b_p;
  boolean_T c9_c_b;
  boolean_T c9_c_p;
  boolean_T c9_d_b;
  boolean_T c9_e_b;
  boolean_T c9_exitg1;
  boolean_T c9_f_b;
  boolean_T c9_p;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  c9_st.site = &c9_tf_emlrtRSI;
  c9_b_obj = c9_obj;
  c9_d = c9_b_obj->NumPathPoints;
  c9_b_b = (c9_d < 1.0);
  if (c9_b_b) {
    c9_i = -1;
  } else {
    if (c9_d != (real_T)(int32_T)muDoubleScalarFloor(c9_d)) {
      emlrtIntegerCheckR2012b(c9_d, &c9_cc_emlrtDCI, &c9_st);
    }

    c9_i1 = (int32_T)c9_d;
    if ((c9_i1 < 1) || (c9_i1 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c9_i1, 1, 213200, &c9_be_emlrtBCI, &c9_st);
    }

    c9_i = c9_i1 - 1;
  }

  c9_array_real_T_Constructor(chartInstance, &c9_path);
  c9_array_real_T_SetSize(chartInstance, &c9_st, &c9_path, &c9_lb_emlrtRTEI,
    c9_i + 1);
  c9_loop_ub = c9_i;
  for (c9_i2 = 0; c9_i2 <= c9_loop_ub; c9_i2++) {
    c9_path.vector.data[c9_i2] = c9_b_obj->Path[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 426400; c9_i3++) {
    c9_obj->PathXY[c9_i3] = rtNaN;
  }

  for (c9_i4 = 0; c9_i4 < 426400; c9_i4++) {
    c9_obj->PathInGrid[c9_i4] = rtNaN;
  }

  if (c9_path.size[0] == 0) {
    c9_obj->PathCost = rtInf;
    c9_st.site = &c9_jg_emlrtRSI;
    c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_pathOut,
      &c9_yb_emlrtRTEI, 0, 0);
  } else {
    c9_st.site = &c9_uf_emlrtRSI;
    c9_c_obj = c9_obj;
    c9_d1 = c9_c_obj->NumPathPoints;
    c9_b1 = (c9_d1 < 1.0);
    if (c9_b1) {
      c9_i5 = -1;
    } else {
      if (c9_d1 != (real_T)(int32_T)muDoubleScalarFloor(c9_d1)) {
        emlrtIntegerCheckR2012b(c9_d1, &c9_cc_emlrtDCI, &c9_st);
      }

      c9_i6 = (int32_T)c9_d1;
      if ((c9_i6 < 1) || (c9_i6 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c9_i6, 1, 213200, &c9_be_emlrtBCI, &c9_st);
      }

      c9_i5 = c9_i6 - 1;
    }

    c9_array_real_T_SetSize(chartInstance, &c9_st, &c9_path, &c9_mb_emlrtRTEI,
      c9_i5 + 1);
    c9_b_loop_ub = c9_i5;
    for (c9_i7 = 0; c9_i7 <= c9_b_loop_ub; c9_i7++) {
      c9_path.vector.data[c9_i7] = c9_c_obj->Path[c9_i7];
    }

    c9_array_real_T_2D_Constructor(chartInstance, &c9_pose);
    c9_st.site = &c9_uf_emlrtRSI;
    c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_pose, &c9_nb_emlrtRTEI,
      c9_path.size[0], 3);
    for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
      c9_c_loop_ub = c9_path.size[0] - 1;
      for (c9_i10 = 0; c9_i10 <= c9_c_loop_ub; c9_i10++) {
        c9_d3 = c9_path.vector.data[c9_i10];
        if (c9_d3 != (real_T)(int32_T)muDoubleScalarFloor(c9_d3)) {
          emlrtIntegerCheckR2012b(c9_d3, &c9_fc_emlrtDCI, (emlrtConstCTX)c9_sp);
        }

        c9_i12 = (int32_T)c9_d3;
        if ((c9_i12 < 1) || (c9_i12 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c9_i12, 1, 213200, &c9_ee_emlrtBCI,
            (emlrtConstCTX)c9_sp);
        }

        c9_pose.vector.data[c9_i10 + c9_pose.size[0] * c9_i8] = c9_obj->IdPose
          [(c9_i12 + 213200 * c9_i8) - 1];
      }
    }

    for (c9_i9 = 0; c9_i9 < 426400; c9_i9++) {
      chartInstance->c9_pathXYTemp[c9_i9] = rtNaN;
    }

    c9_d2 = c9_obj->NumPathPoints;
    c9_b2 = (c9_d2 < 1.0);
    if (c9_b2) {
      c9_i11 = -1;
    } else {
      if (c9_d2 != (real_T)(int32_T)muDoubleScalarFloor(c9_d2)) {
        emlrtIntegerCheckR2012b(c9_d2, &c9_ac_emlrtDCI, (emlrtConstCTX)c9_sp);
      }

      c9_i13 = (int32_T)c9_d2;
      if ((c9_i13 < 1) || (c9_i13 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c9_i13, 1, 213200, &c9_yd_emlrtBCI,
          (emlrtConstCTX)c9_sp);
      }

      c9_i11 = c9_i13 - 1;
    }

    c9_array_int32_T_Constructor(chartInstance, &c9_r);
    c9_st.site = &c9_vf_emlrtRSI;
    c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_r, &c9_ob_emlrtRTEI,
      c9_i11 + 1);
    c9_d_loop_ub = c9_i11;
    for (c9_i14 = 0; c9_i14 <= c9_d_loop_ub; c9_i14++) {
      c9_r.vector.data[c9_i14] = c9_i14;
    }

    c9_st.site = &c9_vf_emlrtRSI;
    c9_d_obj = c9_obj;
    c9_val = c9_d_obj->Map;
    c9_st.site = &c9_vf_emlrtRSI;
    c9_e_obj = c9_val;
    c9_array_real_T_2D_Constructor(chartInstance, &c9_idx);
    c9_b_st.site = &c9_vf_emlrtRSI;
    c9_array_real_T_2D_SetSize(chartInstance, &c9_b_st, &c9_idx,
      &c9_pb_emlrtRTEI, c9_pose.size[0], 2);
    for (c9_i15 = 0; c9_i15 < 2; c9_i15++) {
      c9_e_loop_ub = c9_pose.size[0] - 1;
      for (c9_i16 = 0; c9_i16 <= c9_e_loop_ub; c9_i16++) {
        c9_idx.vector.data[c9_i16 + c9_idx.size[0] * c9_i15] =
          c9_pose.vector.data[c9_i16 + c9_pose.size[0] * c9_i15];
      }
    }

    c9_b_st.site = &c9_ag_emlrtRSI;
    c9_c_st.site = &c9_pc_emlrtRSI;
    c9_p = true;
    c9_d4 = (real_T)(c9_idx.size[0] << 1);
    c9_i17 = (int32_T)c9_d4 - 1;
    c9_k = 0;
    c9_exitg1 = false;
    while ((!c9_exitg1) && (c9_k <= c9_i17)) {
      c9_b_k = (real_T)c9_k + 1.0;
      c9_b_x = c9_idx.vector.data[(int32_T)c9_b_k - 1];
      c9_c_x = c9_b_x;
      c9_d_x = c9_c_x;
      c9_c_b = muDoubleScalarIsInf(c9_d_x);
      c9_b4 = !c9_c_b;
      c9_e_x = c9_c_x;
      c9_d_b = muDoubleScalarIsNaN(c9_e_x);
      c9_b6 = !c9_d_b;
      c9_e_b = (c9_b4 && c9_b6);
      if (c9_e_b) {
        c9_f_x = c9_b_x;
        c9_g_x = c9_f_x;
        c9_j_y = c9_g_x;
        c9_j_y = muDoubleScalarFloor(c9_j_y);
        if (c9_j_y == c9_b_x) {
          c9_b_p = true;
        } else {
          c9_b_p = false;
        }
      } else {
        c9_b_p = false;
      }

      c9_c_p = c9_b_p;
      if (c9_c_p) {
        c9_k++;
      } else {
        c9_p = false;
        c9_exitg1 = true;
      }
    }

    if (c9_p) {
      c9_b3 = true;
    } else {
      c9_b3 = false;
    }

    if (!c9_b3) {
      c9_d_y = NULL;
      sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_cv3, 10, 0U, 1, 0U, 2, 1, 33),
                    false);
      c9_e_y = NULL;
      sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv4, 10, 0U, 1, 0U, 2, 1, 47),
                    false);
      c9_g_y = NULL;
      sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_cv, 10, 0U, 1, 0U, 2, 1, 20),
                    false);
      sf_mex_call(&c9_c_st, &c9_l_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                  sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c9_c_st, NULL, "message", 1U, 2U, 14, c9_e_y, 14, c9_g_y)));
    }

    c9_c_st.site = &c9_pc_emlrtRSI;
    c9_b5 = (c9_idx.size[0] == 0);
    if (c9_b5) {
      c9_f_y = NULL;
      sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_cv1, 10, 0U, 1, 0U, 2, 1, 34),
                    false);
      c9_h_y = NULL;
      sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_cv2, 10, 0U, 1, 0U, 2, 1, 48),
                    false);
      c9_i_y = NULL;
      sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_cv, 10, 0U, 1, 0U, 2, 1, 20),
                    false);
      sf_mex_call(&c9_c_st, &c9_v_emlrtMCI, "error", 0U, 2U, 14, c9_f_y, 14,
                  sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c9_c_st, NULL, "message", 1U, 2U, 14, c9_h_y, 14, c9_i_y)));
    }

    c9_array_real_T_2D_Constructor(chartInstance, &c9_r1);
    c9_b_st.site = &c9_bg_emlrtRSI;
    c9_MapInterface_grid2worldImpl(chartInstance, &c9_b_st, c9_e_obj, &c9_idx,
      &c9_r1);
    c9_iv[0] = c9_r.size[0];
    c9_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&c9_iv[0], 2, &c9_r1.size[0], 2,
      &c9_g_emlrtECI, (void *)c9_sp);
    c9_iv1[0] = c9_r.size[0];
    for (c9_i18 = 0; c9_i18 < 2; c9_i18++) {
      c9_f_loop_ub = c9_iv1[0] - 1;
      for (c9_i20 = 0; c9_i20 <= c9_f_loop_ub; c9_i20++) {
        chartInstance->c9_pathXYTemp[c9_r.vector.data[c9_i20] + 213200 * c9_i18]
          = c9_r1.vector.data[c9_i20 + c9_r1.size[0] * c9_i18];
      }
    }

    for (c9_i19 = 0; c9_i19 < 426400; c9_i19++) {
      c9_obj->PathXY[c9_i19] = chartInstance->c9_pathXYTemp[c9_i19];
    }

    for (c9_i21 = 0; c9_i21 < 426400; c9_i21++) {
      chartInstance->c9_pathXYTemp[c9_i21] = rtNaN;
    }

    c9_d5 = c9_obj->NumPathPoints;
    c9_b7 = (c9_d5 < 1.0);
    if (c9_b7) {
      c9_i22 = -1;
    } else {
      if (c9_d5 != (real_T)(int32_T)muDoubleScalarFloor(c9_d5)) {
        emlrtIntegerCheckR2012b(c9_d5, &c9_bc_emlrtDCI, (emlrtConstCTX)c9_sp);
      }

      c9_i23 = (int32_T)c9_d5;
      if ((c9_i23 < 1) || (c9_i23 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c9_i23, 1, 213200, &c9_ae_emlrtBCI,
          (emlrtConstCTX)c9_sp);
      }

      c9_i22 = c9_i23 - 1;
    }

    c9_st.site = &c9_kg_emlrtRSI;
    c9_array_int32_T_SetSize(chartInstance, &c9_st, &c9_r, &c9_qb_emlrtRTEI,
      c9_i22 + 1);
    c9_g_loop_ub = c9_i22;
    for (c9_i24 = 0; c9_i24 <= c9_g_loop_ub; c9_i24++) {
      c9_r.vector.data[c9_i24] = c9_i24;
    }

    c9_st.site = &c9_kg_emlrtRSI;
    c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_r1, &c9_rb_emlrtRTEI,
      c9_pose.size[0], 2);
    for (c9_i25 = 0; c9_i25 < 2; c9_i25++) {
      c9_h_loop_ub = c9_pose.size[0] - 1;
      for (c9_i26 = 0; c9_i26 <= c9_h_loop_ub; c9_i26++) {
        c9_r1.vector.data[c9_i26 + c9_r1.size[0] * c9_i25] =
          c9_pose.vector.data[c9_i26 + c9_pose.size[0] * c9_i25];
      }
    }

    c9_array_real_T_2D_Destructor(chartInstance, &c9_pose);
    c9_iv2[0] = c9_r.size[0];
    c9_iv2[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&c9_iv2[0], 2, &c9_r1.size[0], 2,
      &c9_h_emlrtECI, (void *)c9_sp);
    c9_iv3[0] = c9_r.size[0];
    for (c9_i27 = 0; c9_i27 < 2; c9_i27++) {
      c9_i_loop_ub = c9_iv3[0] - 1;
      for (c9_i28 = 0; c9_i28 <= c9_i_loop_ub; c9_i28++) {
        chartInstance->c9_pathXYTemp[c9_r.vector.data[c9_i28] + 213200 * c9_i27]
          = c9_r1.vector.data[c9_i28 + c9_r1.size[0] * c9_i27];
      }
    }

    c9_array_real_T_2D_Destructor(chartInstance, &c9_r1);
    c9_array_int32_T_Destructor(chartInstance, &c9_r);
    for (c9_i29 = 0; c9_i29 < 426400; c9_i29++) {
      c9_obj->PathInGrid[c9_i29] = chartInstance->c9_pathXYTemp[c9_i29];
    }

    c9_st.site = &c9_wf_emlrtRSI;
    c9_h_x = c9_obj->IsGrid;
    c9_i_x = c9_h_x;
    c9_f_b = muDoubleScalarIsNaN(c9_i_x);
    if (c9_f_b) {
      c9_k_y = NULL;
      sf_mex_assign(&c9_k_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      c9_l_y = NULL;
      sf_mex_assign(&c9_l_y, sf_mex_create("y", c9_cv5, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c9_st, &c9_h_emlrtMCI, "error", 0U, 2U, 14, c9_k_y, 14,
                  sf_mex_call(&c9_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c9_st, NULL, "message", 1U, 1U, 14, c9_l_y)));
    }

    if (c9_obj->IsGrid != 0.0) {
      c9_st.site = &c9_xf_emlrtRSI;
      c9_g_obj = c9_obj;
      c9_d7 = c9_g_obj->NumPathPoints;
      c9_b9 = (c9_d7 < 1.0);
      if (c9_b9) {
        c9_i31 = -1;
      } else {
        if (c9_d7 != (real_T)(int32_T)muDoubleScalarFloor(c9_d7)) {
          emlrtIntegerCheckR2012b(c9_d7, &c9_ec_emlrtDCI, &c9_st);
        }

        c9_i33 = (int32_T)c9_d7;
        if ((c9_i33 < 1) || (c9_i33 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c9_i33, 1, 213200, &c9_de_emlrtBCI,
            &c9_st);
        }

        c9_i31 = c9_i33 - 1;
      }

      c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_idx,
        &c9_vb_emlrtRTEI, c9_i31 + 1, 2);
      for (c9_i35 = 0; c9_i35 < 2; c9_i35++) {
        c9_k_loop_ub = c9_i31;
        for (c9_i37 = 0; c9_i37 <= c9_k_loop_ub; c9_i37++) {
          c9_idx.vector.data[c9_i37 + c9_idx.size[0] * c9_i35] =
            c9_g_obj->PathInGrid[c9_i37 + 213200 * c9_i35];
        }
      }

      c9_b11 = (c9_idx.size[0] == 0);
      if (c9_b11) {
        c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_idx,
          &c9_wb_emlrtRTEI, 1, 2);
        for (c9_i39 = 0; c9_i39 < 2; c9_i39++) {
          c9_idx.vector.data[c9_idx.size[0] * c9_i39] = c9_g_obj->PathInGrid
            [213200 * c9_i39];
        }
      }

      c9_st.site = &c9_xf_emlrtRSI;
      c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_pathOut,
        &c9_xb_emlrtRTEI, c9_idx.size[0], 2);
      c9_m_loop_ub = (c9_idx.size[0] << 1) - 1;
      for (c9_i41 = 0; c9_i41 <= c9_m_loop_ub; c9_i41++) {
        c9_pathOut->vector.data[c9_i41] = c9_idx.vector.data[c9_i41];
      }
    } else {
      c9_st.site = &c9_yf_emlrtRSI;
      c9_f_obj = c9_obj;
      c9_d6 = c9_f_obj->NumPathPoints;
      c9_b8 = (c9_d6 < 1.0);
      if (c9_b8) {
        c9_i30 = -1;
      } else {
        if (c9_d6 != (real_T)(int32_T)muDoubleScalarFloor(c9_d6)) {
          emlrtIntegerCheckR2012b(c9_d6, &c9_dc_emlrtDCI, &c9_st);
        }

        c9_i32 = (int32_T)c9_d6;
        if ((c9_i32 < 1) || (c9_i32 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c9_i32, 1, 213200, &c9_ce_emlrtBCI,
            &c9_st);
        }

        c9_i30 = c9_i32 - 1;
      }

      c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_idx,
        &c9_sb_emlrtRTEI, c9_i30 + 1, 2);
      for (c9_i34 = 0; c9_i34 < 2; c9_i34++) {
        c9_j_loop_ub = c9_i30;
        for (c9_i36 = 0; c9_i36 <= c9_j_loop_ub; c9_i36++) {
          c9_idx.vector.data[c9_i36 + c9_idx.size[0] * c9_i34] =
            c9_f_obj->PathXY[c9_i36 + 213200 * c9_i34];
        }
      }

      c9_b10 = (c9_idx.size[0] == 0);
      if (c9_b10) {
        c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_idx,
          &c9_tb_emlrtRTEI, 1, 2);
        for (c9_i38 = 0; c9_i38 < 2; c9_i38++) {
          c9_idx.vector.data[c9_idx.size[0] * c9_i38] = c9_f_obj->PathXY[213200 *
            c9_i38];
        }
      }

      c9_st.site = &c9_yf_emlrtRSI;
      c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_pathOut,
        &c9_ub_emlrtRTEI, c9_idx.size[0], 2);
      c9_l_loop_ub = (c9_idx.size[0] << 1) - 1;
      for (c9_i40 = 0; c9_i40 <= c9_l_loop_ub; c9_i40++) {
        c9_pathOut->vector.data[c9_i40] = c9_idx.vector.data[c9_i40];
      }
    }

    c9_array_real_T_2D_Destructor(chartInstance, &c9_idx);
  }

  c9_array_real_T_Destructor(chartInstance, &c9_path);
}

static void c9_MapInterface_grid2worldImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_worldXY)
{
  c9_coder_array_real_T_2D c9_b_gridInd;
  c9_coder_array_real_T_2D c9_localXY;
  emlrtStack c9_st;
  int32_T c9_i;
  int32_T c9_loop_ub;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_b_gridInd);
  c9_st.site = &c9_cg_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_b_gridInd,
    &c9_ac_emlrtRTEI, c9_gridInd->size[0], 2);
  c9_loop_ub = c9_gridInd->size[0] * c9_gridInd->size[1] - 1;
  for (c9_i = 0; c9_i <= c9_loop_ub; c9_i++) {
    c9_b_gridInd.vector.data[c9_i] = c9_gridInd->vector.data[c9_i];
  }

  c9_array_real_T_2D_Constructor(chartInstance, &c9_localXY);
  c9_st.site = &c9_cg_emlrtRSI;
  c9_MapInterface_grid2localImpl(chartInstance, &c9_st, c9_obj, &c9_b_gridInd,
    &c9_localXY);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_b_gridInd);
  c9_st.site = &c9_dg_emlrtRSI;
  c9_MapInterface_local2worldImpl(chartInstance, &c9_st, c9_obj, &c9_localXY,
    c9_worldXY);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_localXY);
}

static void c9_MapInterface_grid2localImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_localXY)
{
  c9_cell_wrap_34 c9_reshapes[2];
  c9_coder_array_real_T c9_b_varargin_1;
  c9_coder_array_real_T c9_b_varargin_2;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  real_T c9_gOrig[2];
  real_T c9_xlimit[2];
  real_T c9_ylimit[2];
  real_T c9_b_xlimit;
  real_T c9_b_ylimit;
  int32_T c9_sizes[2];
  int32_T c9_b_loop_ub;
  int32_T c9_c_loop_ub;
  int32_T c9_d_loop_ub;
  int32_T c9_e_loop_ub;
  int32_T c9_expected;
  int32_T c9_f_loop_ub;
  int32_T c9_g_loop_ub;
  int32_T c9_h_loop_ub;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i_loop_ub;
  int32_T c9_loop_ub;
  int32_T c9_result;
  boolean_T c9_b_b;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_gOrig[c9_i] = c9_obj->SharedProperties.GridOriginInLocal[c9_i];
  }

  c9_xlimit[0] = c9_gOrig[0];
  c9_ylimit[0] = c9_gOrig[1];
  c9_st.site = &c9_eg_emlrtRSI;
  c9_b_xlimit = c9_xlimit[0];
  c9_array_real_T_Constructor(chartInstance, &c9_b_varargin_1);
  c9_b_st.site = &c9_eg_emlrtRSI;
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_1,
    &c9_bc_emlrtRTEI, c9_gridInd->size[0]);
  c9_loop_ub = c9_gridInd->size[0] - 1;
  for (c9_i1 = 0; c9_i1 <= c9_loop_ub; c9_i1++) {
    c9_b_varargin_1.vector.data[c9_i1] = c9_b_xlimit + (c9_gridInd->
      vector.data[c9_i1 + c9_gridInd->size[0]] - 1.0) / 10.0;
  }

  c9_b_ylimit = c9_ylimit[0];
  c9_array_real_T_Constructor(chartInstance, &c9_b_varargin_2);
  c9_b_st.site = &c9_qg_emlrtRSI;
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_2,
    &c9_cc_emlrtRTEI, c9_gridInd->size[0]);
  c9_b_loop_ub = c9_gridInd->size[0] - 1;
  for (c9_i2 = 0; c9_i2 <= c9_b_loop_ub; c9_i2++) {
    c9_b_varargin_2.vector.data[c9_i2] = c9_b_ylimit + (410.0 -
      c9_gridInd->vector.data[c9_i2]) / 10.0;
  }

  c9_b_st.site = &c9_fg_emlrtRSI;
  c9_result = c9_b_varargin_1.size[0];
  c9_sizes[0] = c9_result;
  c9_c_st.site = &c9_gg_emlrtRSI;
  c9_expected = c9_sizes[0];
  if (c9_b_varargin_1.size[0] == c9_expected) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (!c9_b_b) {
    c9_d_y = NULL;
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c9_c_st, &c9_w_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 1U, 14, c9_e_y)));
  }

  if (c9_b_varargin_2.size[0] == c9_expected) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (!c9_b_b) {
    c9_f_y = NULL;
    sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c9_g_y = NULL;
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c9_c_st, &c9_w_emlrtMCI, "error", 0U, 2U, 14, c9_f_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 1U, 14, c9_g_y)));
  }

  c9_array_cell_wrap_34_2s_Construct(chartInstance, c9_reshapes);
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_reshapes[0].f1,
    &c9_dc_emlrtRTEI, c9_b_varargin_1.size[0]);
  c9_c_loop_ub = c9_b_varargin_1.size[0] - 1;
  for (c9_i3 = 0; c9_i3 <= c9_c_loop_ub; c9_i3++) {
    c9_reshapes[0].f1.vector.data[c9_i3] = c9_b_varargin_1.vector.data[c9_i3];
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_reshapes[1].f1,
    &c9_dc_emlrtRTEI, c9_b_varargin_2.size[0]);
  c9_d_loop_ub = c9_b_varargin_2.size[0] - 1;
  for (c9_i4 = 0; c9_i4 <= c9_d_loop_ub; c9_i4++) {
    c9_reshapes[1].f1.vector.data[c9_i4] = c9_b_varargin_2.vector.data[c9_i4];
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_1,
    &c9_ec_emlrtRTEI, c9_reshapes[0].f1.size[0]);
  c9_e_loop_ub = c9_reshapes[0].f1.size[0] - 1;
  for (c9_i5 = 0; c9_i5 <= c9_e_loop_ub; c9_i5++) {
    c9_b_varargin_1.vector.data[c9_i5] = c9_reshapes[0].f1.vector.data[c9_i5];
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_2,
    &c9_ec_emlrtRTEI, c9_reshapes[1].f1.size[0]);
  c9_f_loop_ub = c9_reshapes[1].f1.size[0] - 1;
  for (c9_i6 = 0; c9_i6 <= c9_f_loop_ub; c9_i6++) {
    c9_b_varargin_2.vector.data[c9_i6] = c9_reshapes[1].f1.vector.data[c9_i6];
  }

  c9_array_cell_wrap_34_2s_Destructo(chartInstance, c9_reshapes);
  c9_array_real_T_2D_SetSize(chartInstance, &c9_b_st, c9_localXY,
    &c9_fc_emlrtRTEI, c9_b_varargin_1.size[0], 2);
  c9_g_loop_ub = c9_b_varargin_1.size[0] - 1;
  for (c9_i7 = 0; c9_i7 <= c9_g_loop_ub; c9_i7++) {
    c9_localXY->vector.data[c9_i7] = c9_b_varargin_1.vector.data[c9_i7];
  }

  c9_array_real_T_Destructor(chartInstance, &c9_b_varargin_1);
  c9_h_loop_ub = c9_b_varargin_2.size[0] - 1;
  for (c9_i8 = 0; c9_i8 <= c9_h_loop_ub; c9_i8++) {
    c9_localXY->vector.data[c9_i8 + c9_localXY->size[0]] =
      c9_b_varargin_2.vector.data[c9_i8];
  }

  c9_array_real_T_Destructor(chartInstance, &c9_b_varargin_2);
  c9_i9 = c9_localXY->size[0] << 1;
  c9_st.site = &c9_eg_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_localXY, &c9_gc_emlrtRTEI,
    c9_localXY->size[0], 2);
  c9_i10 = c9_i9;
  c9_i_loop_ub = c9_i10 - 1;
  for (c9_i11 = 0; c9_i11 <= c9_i_loop_ub; c9_i11++) {
    c9_localXY->vector.data[c9_i11] += 0.05;
  }
}

static void c9_MapInterface_local2worldImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_localXY,
   c9_coder_array_real_T_2D *c9_worldXY)
{
  emlrtStack c9_st;
  real_T c9_locWorld[2];
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_loop_ub;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_locWorld[c9_i] = c9_obj->SharedProperties.LocalOriginInWorld[c9_i];
  }

  c9_st.site = &c9_ig_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_worldXY, &c9_hc_emlrtRTEI,
    c9_localXY->size[0], 2);
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_loop_ub = c9_localXY->size[0] - 1;
    for (c9_i2 = 0; c9_i2 <= c9_loop_ub; c9_i2++) {
      c9_worldXY->vector.data[c9_i2 + c9_worldXY->size[0] * c9_i1] =
        c9_localXY->vector.data[c9_i2 + c9_localXY->size[0] * c9_i1] +
        c9_locWorld[c9_i1];
    }
  }
}

static void c9_b_MapInterface_grid2worldImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_worldXY)
{
  c9_coder_array_real_T_2D c9_b_gridInd;
  c9_coder_array_real_T_2D c9_localXY;
  emlrtStack c9_st;
  int32_T c9_i;
  int32_T c9_loop_ub;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_b_gridInd);
  c9_st.site = &c9_cg_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_b_gridInd,
    &c9_ac_emlrtRTEI, c9_gridInd->size[0], c9_gridInd->size[1]);
  c9_loop_ub = c9_gridInd->size[0] * c9_gridInd->size[1] - 1;
  for (c9_i = 0; c9_i <= c9_loop_ub; c9_i++) {
    c9_b_gridInd.vector.data[c9_i] = c9_gridInd->vector.data[c9_i];
  }

  c9_array_real_T_2D_Constructor(chartInstance, &c9_localXY);
  c9_st.site = &c9_cg_emlrtRSI;
  c9_b_MapInterface_grid2localImpl(chartInstance, &c9_st, c9_obj, &c9_b_gridInd,
    &c9_localXY);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_b_gridInd);
  c9_st.site = &c9_dg_emlrtRSI;
  c9_MapInterface_local2worldImpl(chartInstance, &c9_st, c9_obj, &c9_localXY,
    c9_worldXY);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_localXY);
}

static void c9_b_MapInterface_grid2localImpl
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_binaryOccupancyMap *c9_obj, c9_coder_array_real_T_2D *c9_gridInd,
   c9_coder_array_real_T_2D *c9_localXY)
{
  c9_cell_wrap_34 c9_reshapes[2];
  c9_coder_array_real_T c9_b_varargin_1;
  c9_coder_array_real_T c9_b_varargin_2;
  emlrtStack c9_b_st;
  emlrtStack c9_c_st;
  emlrtStack c9_st;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_e_y = NULL;
  const mxArray *c9_f_y = NULL;
  const mxArray *c9_g_y = NULL;
  real_T c9_gOrig[2];
  real_T c9_xlimit[2];
  real_T c9_ylimit[2];
  real_T c9_b_xlimit;
  real_T c9_b_ylimit;
  int32_T c9_sizes[2];
  int32_T c9_b_loop_ub;
  int32_T c9_c_loop_ub;
  int32_T c9_d_loop_ub;
  int32_T c9_e_loop_ub;
  int32_T c9_expected;
  int32_T c9_f_loop_ub;
  int32_T c9_g_loop_ub;
  int32_T c9_h_loop_ub;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i_loop_ub;
  int32_T c9_loop_ub;
  int32_T c9_result;
  boolean_T c9_b_b;
  c9_st.prev = c9_sp;
  c9_st.tls = c9_sp->tls;
  c9_b_st.prev = &c9_st;
  c9_b_st.tls = c9_st.tls;
  c9_c_st.prev = &c9_b_st;
  c9_c_st.tls = c9_b_st.tls;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_gOrig[c9_i] = c9_obj->SharedProperties.GridOriginInLocal[c9_i];
  }

  c9_xlimit[0] = c9_gOrig[0];
  c9_ylimit[0] = c9_gOrig[1];
  c9_i1 = c9_gridInd->size[1];
  c9_i2 = 2;
  if ((c9_i2 < 1) || (c9_i2 > c9_i1)) {
    emlrtDynamicBoundsCheckR2012b(c9_i2, 1, c9_i1, &c9_fe_emlrtBCI,
      (emlrtConstCTX)c9_sp);
  }

  c9_i3 = c9_gridInd->size[1];
  c9_i4 = 1;
  if ((c9_i4 < 1) || (c9_i4 > c9_i3)) {
    emlrtDynamicBoundsCheckR2012b(c9_i4, 1, c9_i3, &c9_ge_emlrtBCI,
      (emlrtConstCTX)c9_sp);
  }

  c9_st.site = &c9_eg_emlrtRSI;
  c9_b_xlimit = c9_xlimit[0];
  c9_array_real_T_Constructor(chartInstance, &c9_b_varargin_1);
  c9_b_st.site = &c9_eg_emlrtRSI;
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_1,
    &c9_bc_emlrtRTEI, c9_gridInd->size[0]);
  c9_loop_ub = c9_gridInd->size[0] - 1;
  for (c9_i5 = 0; c9_i5 <= c9_loop_ub; c9_i5++) {
    c9_b_varargin_1.vector.data[c9_i5] = c9_b_xlimit + (c9_gridInd->
      vector.data[c9_i5 + c9_gridInd->size[0]] - 1.0) / 10.0;
  }

  c9_b_ylimit = c9_ylimit[0];
  c9_array_real_T_Constructor(chartInstance, &c9_b_varargin_2);
  c9_b_st.site = &c9_qg_emlrtRSI;
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_2,
    &c9_cc_emlrtRTEI, c9_gridInd->size[0]);
  c9_b_loop_ub = c9_gridInd->size[0] - 1;
  for (c9_i6 = 0; c9_i6 <= c9_b_loop_ub; c9_i6++) {
    c9_b_varargin_2.vector.data[c9_i6] = c9_b_ylimit + (410.0 -
      c9_gridInd->vector.data[c9_i6]) / 10.0;
  }

  c9_b_st.site = &c9_fg_emlrtRSI;
  c9_result = c9_b_varargin_1.size[0];
  c9_sizes[0] = c9_result;
  c9_c_st.site = &c9_gg_emlrtRSI;
  c9_expected = c9_sizes[0];
  if (c9_b_varargin_1.size[0] == c9_expected) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (!c9_b_b) {
    c9_d_y = NULL;
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c9_e_y = NULL;
    sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c9_c_st, &c9_w_emlrtMCI, "error", 0U, 2U, 14, c9_d_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 1U, 14, c9_e_y)));
  }

  if (c9_b_varargin_2.size[0] == c9_expected) {
    c9_b_b = true;
  } else {
    c9_b_b = false;
  }

  if (!c9_b_b) {
    c9_f_y = NULL;
    sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c9_g_y = NULL;
    sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c9_c_st, &c9_w_emlrtMCI, "error", 0U, 2U, 14, c9_f_y, 14,
                sf_mex_call(&c9_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c9_c_st, NULL, "message", 1U, 1U, 14, c9_g_y)));
  }

  c9_array_cell_wrap_34_2s_Construct(chartInstance, c9_reshapes);
  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_reshapes[0].f1,
    &c9_dc_emlrtRTEI, c9_b_varargin_1.size[0]);
  c9_c_loop_ub = c9_b_varargin_1.size[0] - 1;
  for (c9_i7 = 0; c9_i7 <= c9_c_loop_ub; c9_i7++) {
    c9_reshapes[0].f1.vector.data[c9_i7] = c9_b_varargin_1.vector.data[c9_i7];
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_reshapes[1].f1,
    &c9_dc_emlrtRTEI, c9_b_varargin_2.size[0]);
  c9_d_loop_ub = c9_b_varargin_2.size[0] - 1;
  for (c9_i8 = 0; c9_i8 <= c9_d_loop_ub; c9_i8++) {
    c9_reshapes[1].f1.vector.data[c9_i8] = c9_b_varargin_2.vector.data[c9_i8];
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_1,
    &c9_ec_emlrtRTEI, c9_reshapes[0].f1.size[0]);
  c9_e_loop_ub = c9_reshapes[0].f1.size[0] - 1;
  for (c9_i9 = 0; c9_i9 <= c9_e_loop_ub; c9_i9++) {
    c9_b_varargin_1.vector.data[c9_i9] = c9_reshapes[0].f1.vector.data[c9_i9];
  }

  c9_array_real_T_SetSize(chartInstance, &c9_b_st, &c9_b_varargin_2,
    &c9_ec_emlrtRTEI, c9_reshapes[1].f1.size[0]);
  c9_f_loop_ub = c9_reshapes[1].f1.size[0] - 1;
  for (c9_i10 = 0; c9_i10 <= c9_f_loop_ub; c9_i10++) {
    c9_b_varargin_2.vector.data[c9_i10] = c9_reshapes[1].f1.vector.data[c9_i10];
  }

  c9_array_cell_wrap_34_2s_Destructo(chartInstance, c9_reshapes);
  c9_array_real_T_2D_SetSize(chartInstance, &c9_b_st, c9_localXY,
    &c9_fc_emlrtRTEI, c9_b_varargin_1.size[0], 2);
  c9_g_loop_ub = c9_b_varargin_1.size[0] - 1;
  for (c9_i11 = 0; c9_i11 <= c9_g_loop_ub; c9_i11++) {
    c9_localXY->vector.data[c9_i11] = c9_b_varargin_1.vector.data[c9_i11];
  }

  c9_array_real_T_Destructor(chartInstance, &c9_b_varargin_1);
  c9_h_loop_ub = c9_b_varargin_2.size[0] - 1;
  for (c9_i12 = 0; c9_i12 <= c9_h_loop_ub; c9_i12++) {
    c9_localXY->vector.data[c9_i12 + c9_localXY->size[0]] =
      c9_b_varargin_2.vector.data[c9_i12];
  }

  c9_array_real_T_Destructor(chartInstance, &c9_b_varargin_2);
  c9_i13 = c9_localXY->size[0] << 1;
  c9_st.site = &c9_eg_emlrtRSI;
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_localXY, &c9_gc_emlrtRTEI,
    c9_localXY->size[0], 2);
  c9_i14 = c9_i13;
  c9_i_loop_ub = c9_i14 - 1;
  for (c9_i15 = 0; c9_i15 <= c9_i_loop_ub; c9_i15++) {
    c9_localXY->vector.data[c9_i15] += 0.05;
  }
}

static void c9_handle_matlabCodegenDestructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_nav_algs_internal_PriorityQueue *c9_obj)
{
  c9_nav_algs_internal_PriorityQueue *c9_b_obj;
  (void)chartInstance;
  if (!c9_obj->matlabCodegenIsDeleted) {
    c9_obj->matlabCodegenIsDeleted = true;
    c9_b_obj = c9_obj;
    priorityqueuecodegen_destructPQ(c9_b_obj->PQInternal);
  }
}

static void c9_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_a__output_of_sprintf_, const char_T
  *c9_identifier, char_T c9_d_y[23])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_a__output_of_sprintf_),
                        &c9_thisId, c9_d_y);
  sf_mex_destroy(&c9_a__output_of_sprintf_);
}

static void c9_b_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_d_y[23])
{
  int32_T c9_i;
  char_T c9_b_cv[23];
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), c9_b_cv, 1, 10, 0U, 1, 0U, 2, 1,
                23);
  for (c9_i = 0; c9_i < 23; c9_i++) {
    c9_d_y[c9_i] = c9_b_cv[c9_i];
  }

  sf_mex_destroy(&c9_b_u);
}

const mxArray *sf_c9_sl_groundvehicleDynamics_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  const char_T *c9_data[4] = {
    "789c6360f4f465646060e0638000033608cd0be50b4069260654802ecf88838601560616147d30f97e289d9c9f57925a5102e1e425e6a6c275a6e4e766e625e6"
    "95845416a43214a516e7e794a5a68065d2327352433273538391397e205eae1b92149c039202b19d335293b3834b73198a328a112ecc41e6c0c32301877f5908",
    "84073a400f0f747594dac788a60ed33e884c496a710935ed63c3691f442625bf3429271561df090aed4bc1691faa7cb46bacb3554c68716a51714c566a5a5a4c"
    "606a417e45a5824b517e41527e458c17504ca13c23b3242dbf2825c6d5ddc3c4c42c26353d0348c51767e6bae69519191899c40099f1a97965318ea525f9c195",
    "c525a9b9c52085a050d4cb05d943281cf989f417ae7cc3cbc001a605656e33d2d3be4775cbf3e9691f0c0c947d1538cc23365d8ae2b04f004d3eb432222c33d4"
    "bb2cc2abb4dcbca830c023ccb33c1fc91d0104ec21e40e061c7c5a9b0f0064266295", "" };

  c9_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c9_data[0], 1608U, &c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_c_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier, real_T
  c9_d_y[1500])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_d_y);
  sf_mex_destroy(&c9_nullptr);
}

static void c9_d_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[1500])
{
  real_T c9_b_dv[1500];
  int32_T c9_i;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), c9_b_dv, 1, 0, 0U, 1, 0U, 2, 1,
                1500);
  for (c9_i = 0; c9_i < 1500; c9_i++) {
    c9_d_y[c9_i] = c9_b_dv[c9_i];
  }

  sf_mex_destroy(&c9_b_u);
}

static void c9_e_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier,
  boolean_T *c9_svPtr, real_T c9_d_y[3000])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_svPtr, c9_d_y);
  sf_mex_destroy(&c9_nullptr);
}

static void c9_f_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T *c9_svPtr, real_T c9_d_y[3000])
{
  real_T c9_b_dv[3000];
  int32_T c9_i;
  (void)chartInstance;
  if (mxIsEmpty(c9_b_u)) {
    *c9_svPtr = false;
  } else {
    *c9_svPtr = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), c9_b_dv, 1, 0, 0U, 1, 0U, 2,
                  2, 1500);
    for (c9_i = 0; c9_i < 3000; c9_i++) {
      c9_d_y[c9_i] = c9_b_dv[c9_i];
    }
  }

  sf_mex_destroy(&c9_b_u);
}

static void c9_g_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_nullptr, const char_T *c9_identifier,
  boolean_T *c9_svPtr, real_T c9_d_y[1500])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_svPtr, c9_d_y);
  sf_mex_destroy(&c9_nullptr);
}

static void c9_h_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T *c9_svPtr, real_T c9_d_y[1500])
{
  real_T c9_b_dv[1500];
  int32_T c9_i;
  (void)chartInstance;
  if (mxIsEmpty(c9_b_u)) {
    *c9_svPtr = false;
  } else {
    *c9_svPtr = true;
    sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), c9_b_dv, 1, 0, 0U, 1, 0U, 2,
                  1, 1500);
    for (c9_i = 0; c9_i < 1500; c9_i++) {
      c9_d_y[c9_i] = c9_b_dv[c9_i];
    }
  }

  sf_mex_destroy(&c9_b_u);
}

static void c9_slStringInitializeDynamicBuffers
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c9_sf_marshallOut_matrix1x1500_real_T_persistent(void
  *chartInstanceVoid, void *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  real_T c9_b_u[1500];
  int32_T c9_i;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  for (c9_i = 0; c9_i < 1500; c9_i++) {
    c9_b_u[c9_i] = (*(real_T (*)[1500])c9_inData)[c9_i];
  }

  c9_d_y = NULL;
  if (!chartInstance->c9_path_x_not_empty) {
    sf_mex_assign(&c9_d_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u, 0, 0U, 1, 0U, 2, 1, 1500),
                  false);
  }

  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_sf_marshallIn_matrix1x1500_real_T_persistent(void
  *chartInstanceVoid, const mxArray *c9_mxArrayInData, const char_T *c9_varName,
  void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  real_T c9_d_y[1500];
  int32_T c9_i;
  const char_T *c9_identifier;
  boolean_T *c9_svPtr;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_svPtr = &chartInstance->c9_path_x_not_empty;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_svPtr, c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  for (c9_i = 0; c9_i < 1500; c9_i++) {
    (*(real_T (*)[1500])c9_outData)[c9_i] = c9_d_y[c9_i];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_matrix2x1500_real_T_persistent(void
  *chartInstanceVoid, void *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  real_T c9_b_u[3000];
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_i = 0;
  for (c9_i1 = 0; c9_i1 < 1500; c9_i1++) {
    for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
      c9_b_u[c9_i2 + c9_i] = (*(real_T (*)[3000])c9_inData)[c9_i2 + c9_i];
    }

    c9_i += 2;
  }

  c9_d_y = NULL;
  if (!chartInstance->c9_out_path_not_empty) {
    sf_mex_assign(&c9_d_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u, 0, 0U, 1, 0U, 2, 2, 1500),
                  false);
  }

  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_sf_marshallIn_matrix2x1500_real_T_persistent(void
  *chartInstanceVoid, const mxArray *c9_mxArrayInData, const char_T *c9_varName,
  void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  real_T c9_d_y[3000];
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  const char_T *c9_identifier;
  boolean_T *c9_svPtr;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_svPtr = &chartInstance->c9_out_path_not_empty;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_svPtr, c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  c9_i = 0;
  for (c9_i1 = 0; c9_i1 < 1500; c9_i1++) {
    for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
      (*(real_T (*)[3000])c9_outData)[c9_i2 + c9_i] = c9_d_y[c9_i2 + c9_i];
    }

    c9_i += 2;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_matrix4x1_real_T(void *chartInstanceVoid,
  void *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  real_T c9_b_u[4];
  int32_T c9_i;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  for (c9_i = 0; c9_i < 4; c9_i++) {
    c9_b_u[c9_i] = (*(real_T (*)[4])c9_inData)[c9_i];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u, 0, 0U, 1, 0U, 2, 4, 1),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_i_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[4])
{
  real_T c9_b_dv[4];
  int32_T c9_i;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), c9_b_dv, 1, 0, 0U, 1, 0U, 2, 4,
                1);
  for (c9_i = 0; c9_i < 4; c9_i++) {
    c9_d_y[c9_i] = c9_b_dv[c9_i];
  }

  sf_mex_destroy(&c9_b_u);
}

static void c9_sf_marshallIn_matrix4x1_real_T(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  real_T c9_d_y[4];
  int32_T c9_i;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  for (c9_i = 0; c9_i < 4; c9_i++) {
    (*(real_T (*)[4])c9_outData)[c9_i] = c9_d_y[c9_i];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_matrix4_real_T(void *chartInstanceVoid,
  void *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  real_T c9_b_u[4];
  int32_T c9_i;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  for (c9_i = 0; c9_i < 4; c9_i++) {
    c9_b_u[c9_i] = (*(real_T (*)[4])c9_inData)[c9_i];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u, 0, 0U, 1, 0U, 1, 4), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_j_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[4])
{
  real_T c9_b_dv[4];
  int32_T c9_i;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), c9_b_dv, 1, 0, 0U, 1, 0U, 1, 4);
  for (c9_i = 0; c9_i < 4; c9_i++) {
    c9_d_y[c9_i] = c9_b_dv[c9_i];
  }

  sf_mex_destroy(&c9_b_u);
}

static void c9_sf_marshallIn_matrix4_real_T(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  real_T c9_d_y[4];
  int32_T c9_i;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  for (c9_i = 0; c9_i < 4; c9_i++) {
    (*(real_T (*)[4])c9_outData)[c9_i] = c9_d_y[c9_i];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_real_T(void *chartInstanceVoid, void
  *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  real_T c9_b_u;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_b_u = *(real_T *)c9_inData;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_k_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_d;
  real_T c9_d_y;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), &c9_d, 1, 0, 0U, 0, 0U, 0);
  c9_d_y = c9_d;
  sf_mex_destroy(&c9_b_u);
  return c9_d_y;
}

static void c9_sf_marshallIn_real_T(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  real_T c9_d_y;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_y = c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr),
    &c9_thisId);
  sf_mex_destroy(&c9_nullptr);
  *(real_T *)c9_outData = c9_d_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_matrix410x520_boolean_T(void
  *chartInstanceVoid, void *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_i = 0;
  for (c9_i1 = 0; c9_i1 < 520; c9_i1++) {
    for (c9_i2 = 0; c9_i2 < 410; c9_i2++) {
      chartInstance->c9_u[c9_i2 + c9_i] = (*(boolean_T (*)[213200])c9_inData)
        [c9_i2 + c9_i];
    }

    c9_i += 410;
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", chartInstance->c9_u, 11, 0U, 1, 0U,
    2, 410, 520), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_l_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  boolean_T c9_d_y[213200])
{
  int32_T c9_i;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), chartInstance->c9_c_bv, 1, 11,
                0U, 1, 0U, 2, 410, 520);
  for (c9_i = 0; c9_i < 213200; c9_i++) {
    c9_d_y[c9_i] = chartInstance->c9_c_bv[c9_i];
  }

  sf_mex_destroy(&c9_b_u);
}

static void c9_sf_marshallIn_matrix410x520_boolean_T(void *chartInstanceVoid,
  const mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        chartInstance->c9_c_y);
  sf_mex_destroy(&c9_nullptr);
  c9_i = 0;
  for (c9_i1 = 0; c9_i1 < 520; c9_i1++) {
    for (c9_i2 = 0; c9_i2 < 410; c9_i2++) {
      (*(boolean_T (*)[213200])c9_outData)[c9_i2 + c9_i] = chartInstance->
        c9_c_y[c9_i2 + c9_i];
    }

    c9_i += 410;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_matrix1x1500_real_T_1(void
  *chartInstanceVoid, void *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  real_T c9_b_u[1500];
  int32_T c9_i;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  for (c9_i = 0; c9_i < 1500; c9_i++) {
    c9_b_u[c9_i] = (*(real_T (*)[1500])c9_inData)[c9_i];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u, 0, 0U, 1, 0U, 2, 1, 1500),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_sf_marshallIn_matrix1x1500_real_T_1(void *chartInstanceVoid,
  const mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  real_T c9_d_y[1500];
  int32_T c9_i;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  for (c9_i = 0; c9_i < 1500; c9_i++) {
    (*(real_T (*)[1500])c9_outData)[c9_i] = c9_d_y[c9_i];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_dynamicmatrix(void *chartInstanceVoid,
  c9_coder_array_real_T_2D *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  c9_coder_array_real_T_2D c9_b_u;
  emlrtStack c9_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  int32_T c9_i;
  int32_T c9_loop_ub;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_st.tls = chartInstance->c9_fEmlrtCtx;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_b_u);
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_b_u, (emlrtRTEInfo *)
    NULL, 2, c9_inData->size[1]);
  c9_loop_ub = (c9_inData->size[1] << 1) - 1;
  for (c9_i = 0; c9_i <= c9_loop_ub; c9_i++) {
    c9_b_u.vector.data[c9_i] = c9_inData->vector.data[c9_i];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u.vector.data, 0, 0U, 1, 0U, 2,
    2, c9_b_u.size[1]), false);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_b_u);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_m_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_b_u, const
  emlrtMsgIdentifier *c9_parentId, c9_coder_array_real_T_2D *c9_d_y)
{
  static boolean_T c9_bv1[2] = { false, true };

  c9_coder_array_real_T_2D c9_r;
  int32_T c9_iv[2];
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_loop_ub;
  boolean_T c9_d_bv[2];
  c9_array_real_T_2D_Constructor(chartInstance, &c9_r);
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_iv[c9_i] = 2 + 213198 * c9_i;
  }

  c9_array_real_T_2D_SetSize(chartInstance, c9_sp, &c9_r, (emlrtRTEInfo *)NULL,
    sf_mex_get_dimension(c9_b_u, 0), sf_mex_get_dimension(c9_b_u, 1));
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_d_bv[c9_i1] = c9_bv1[c9_i1];
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_b_u), c9_r.vector.data, 1, 0, 0U,
                   1, 0U, 2, c9_d_bv, c9_iv, c9_r.size);
  c9_array_real_T_2D_SetSize(chartInstance, c9_sp, c9_d_y, (emlrtRTEInfo *)NULL,
    2, c9_r.size[1]);
  c9_loop_ub = (c9_r.size[1] << 1) - 1;
  for (c9_i2 = 0; c9_i2 <= c9_loop_ub; c9_i2++) {
    c9_d_y->vector.data[c9_i2] = c9_r.vector.data[c9_i2];
  }

  sf_mex_destroy(&c9_b_u);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_r);
}

static void c9_sf_marshallIn_dynamicmatrix(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, c9_coder_array_real_T_2D *
  c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  c9_coder_array_real_T_2D c9_d_y;
  emlrtMsgIdentifier c9_thisId;
  emlrtStack c9_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c9_nullptr;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_loop_ub;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_st.tls = chartInstance->c9_fEmlrtCtx;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_d_y);
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_m_emlrt_marshallIn(chartInstance, &c9_st, sf_mex_dup(c9_nullptr),
                        &c9_thisId, &c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_outData, (emlrtRTEInfo *)
    NULL, 2, c9_d_y.size[1]);
  c9_loop_ub = c9_d_y.size[1] - 1;
  c9_i = 0;
  for (c9_i1 = 0; c9_i1 <= c9_loop_ub; c9_i1++) {
    for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
      c9_outData->vector.data[c9_i2 + c9_i] = c9_d_y.vector.data[c9_i2 + c9_i];
    }

    c9_i += 2;
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_d_y);
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_matrix1x2_real_T(void *chartInstanceVoid,
  void *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  real_T c9_b_u[2];
  int32_T c9_i;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_b_u[c9_i] = (*(real_T (*)[2])c9_inData)[c9_i];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u, 0, 0U, 1, 0U, 2, 1, 2),
                false);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_n_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c9_b_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_d_y[2])
{
  real_T c9_b_dv[2];
  int32_T c9_i;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_b_u), c9_b_dv, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_d_y[c9_i] = c9_b_dv[c9_i];
  }

  sf_mex_destroy(&c9_b_u);
}

static void c9_sf_marshallIn_matrix1x2_real_T(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  emlrtMsgIdentifier c9_thisId;
  const mxArray *c9_nullptr;
  real_T c9_d_y[2];
  int32_T c9_i;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nullptr), &c9_thisId,
                        c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  for (c9_i = 0; c9_i < 2; c9_i++) {
    (*(real_T (*)[2])c9_outData)[c9_i] = c9_d_y[c9_i];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_sf_marshallOut_dynamicmatrix_1(void *chartInstanceVoid,
  c9_coder_array_real_T_2D *c9_inData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  c9_coder_array_real_T_2D c9_b_u;
  emlrtStack c9_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c9_d_y = NULL;
  const mxArray *c9_mxArrayOutData;
  int32_T c9_i;
  int32_T c9_loop_ub;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_st.tls = chartInstance->c9_fEmlrtCtx;
  c9_mxArrayOutData = NULL;
  c9_mxArrayOutData = NULL;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_b_u);
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, &c9_b_u, (emlrtRTEInfo *)
    NULL, c9_inData->size[0], c9_inData->size[1]);
  c9_loop_ub = c9_inData->size[0] * c9_inData->size[1] - 1;
  for (c9_i = 0; c9_i <= c9_loop_ub; c9_i++) {
    c9_b_u.vector.data[c9_i] = c9_inData->vector.data[c9_i];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_b_u.vector.data, 0, 0U, 1, 0U, 2,
    c9_b_u.size[0], c9_b_u.size[1]), false);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_b_u);
  sf_mex_assign(&c9_mxArrayOutData, c9_d_y, false);
  return c9_mxArrayOutData;
}

static void c9_o_emlrt_marshallIn(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_b_u, const
  emlrtMsgIdentifier *c9_parentId, c9_coder_array_real_T_2D *c9_d_y)
{
  c9_coder_array_real_T_2D c9_r;
  int32_T c9_iv[2];
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_i2;
  int32_T c9_loop_ub;
  boolean_T c9_d_bv[2];
  c9_array_real_T_2D_Constructor(chartInstance, &c9_r);
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_iv[c9_i] = 213200 + -213198 * c9_i;
  }

  c9_array_real_T_2D_SetSize(chartInstance, c9_sp, &c9_r, (emlrtRTEInfo *)NULL,
    sf_mex_get_dimension(c9_b_u, 0), sf_mex_get_dimension(c9_b_u, 1));
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_d_bv[c9_i1] = true;
  }

  sf_mex_import_vs(c9_parentId, sf_mex_dup(c9_b_u), c9_r.vector.data, 1, 0, 0U,
                   1, 0U, 2, c9_d_bv, c9_iv, c9_r.size);
  c9_array_real_T_2D_SetSize(chartInstance, c9_sp, c9_d_y, (emlrtRTEInfo *)NULL,
    c9_r.size[0], c9_r.size[1]);
  c9_loop_ub = c9_r.size[0] * c9_r.size[1] - 1;
  for (c9_i2 = 0; c9_i2 <= c9_loop_ub; c9_i2++) {
    c9_d_y->vector.data[c9_i2] = c9_r.vector.data[c9_i2];
  }

  sf_mex_destroy(&c9_b_u);
  c9_array_real_T_2D_Destructor(chartInstance, &c9_r);
}

static void c9_sf_marshallIn_dynamicmatrix_1(void *chartInstanceVoid, const
  mxArray *c9_mxArrayInData, const char_T *c9_varName, c9_coder_array_real_T_2D *
  c9_outData)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  c9_coder_array_real_T_2D c9_d_y;
  emlrtMsgIdentifier c9_thisId;
  emlrtStack c9_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c9_nullptr;
  int32_T c9_b_loop_ub;
  int32_T c9_i;
  int32_T c9_i1;
  int32_T c9_loop_ub;
  const char_T *c9_identifier;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)
    chartInstanceVoid;
  c9_st.tls = chartInstance->c9_fEmlrtCtx;
  c9_array_real_T_2D_Constructor(chartInstance, &c9_d_y);
  c9_nullptr = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = (const char_T *)c9_identifier;
  c9_thisId.fParent = NULL;
  c9_thisId.bParentIsCell = false;
  c9_o_emlrt_marshallIn(chartInstance, &c9_st, sf_mex_dup(c9_nullptr),
                        &c9_thisId, &c9_d_y);
  sf_mex_destroy(&c9_nullptr);
  c9_array_real_T_2D_SetSize(chartInstance, &c9_st, c9_outData, (emlrtRTEInfo *)
    NULL, c9_d_y.size[0], c9_d_y.size[1]);
  c9_loop_ub = c9_d_y.size[1] - 1;
  for (c9_i = 0; c9_i <= c9_loop_ub; c9_i++) {
    c9_b_loop_ub = c9_d_y.size[0] - 1;
    for (c9_i1 = 0; c9_i1 <= c9_b_loop_ub; c9_i1++) {
      c9_outData->vector.data[c9_i1 + c9_outData->size[0] * c9_i] =
        c9_d_y.vector.data[c9_i1 + c9_d_y.size[0] * c9_i];
    }
  }

  c9_array_real_T_2D_Destructor(chartInstance, &c9_d_y);
  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_chart_data_browse_helper
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, int32_T
   c9_ssIdNumber, const mxArray **c9_mxData, uint8_T *c9_isValueTooBig)
{
  real_T c9_d;
  real_T c9_d1;
  *c9_mxData = NULL;
  *c9_mxData = NULL;
  *c9_isValueTooBig = 0U;
  switch (c9_ssIdNumber) {
   case 16U:
    sf_mex_assign(c9_mxData, sf_mex_create("mxData", *chartInstance->c9_path_xo,
      0, 0U, 1, 0U, 2, 1, 1500), false);
    break;

   case 17U:
    sf_mex_assign(c9_mxData, sf_mex_create("mxData", *chartInstance->c9_path_yo,
      0, 0U, 1, 0U, 2, 1, 1500), false);
    break;

   case 4U:
    sf_mex_assign(c9_mxData, sf_mex_create("mxData",
      *chartInstance->c9_waypoints_x, 0, 0U, 1, 0U, 2, 4, 1), false);
    break;

   case 11U:
    sf_mex_assign(c9_mxData, sf_mex_create("mxData",
      *chartInstance->c9_waypoints_y, 0, 0U, 1, 0U, 1, 4), false);
    break;

   case 6U:
    c9_d = *chartInstance->c9_current_x;
    sf_mex_assign(c9_mxData, sf_mex_create("mxData", &c9_d, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 12U:
    c9_d1 = *chartInstance->c9_current_y;
    sf_mex_assign(c9_mxData, sf_mex_create("mxData", &c9_d1, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 7U:
    *c9_isValueTooBig = 1U;
    break;
  }
}

static const mxArray *c9_sprintf(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_input0, const
  mxArray *c9_input1)
{
  const mxArray *c9_m = NULL;
  (void)chartInstance;
  c9_m = NULL;
  sf_mex_assign(&c9_m, sf_mex_call(c9_sp, NULL, "sprintf", 1U, 2U, 14,
    sf_mex_dup(c9_input0), 14, sf_mex_dup(c9_input1)), false);
  sf_mex_destroy(&c9_input0);
  sf_mex_destroy(&c9_input1);
  return c9_m;
}

static const mxArray *c9_feval(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_input0, const
  mxArray *c9_input1)
{
  const mxArray *c9_m = NULL;
  (void)chartInstance;
  c9_m = NULL;
  sf_mex_assign(&c9_m, sf_mex_call(c9_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c9_input0), 14, sf_mex_dup(c9_input1)), false);
  sf_mex_destroy(&c9_input0);
  sf_mex_destroy(&c9_input1);
  return c9_m;
}

static void c9_b_feval(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, const mxArray *c9_input0, const
  mxArray *c9_input1)
{
  (void)chartInstance;
  sf_mex_call(c9_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c9_input0), 14,
              sf_mex_dup(c9_input1));
  sf_mex_destroy(&c9_input0);
  sf_mex_destroy(&c9_input1);
}

static void c9_array_real_T_2D_SetSize
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c9_sp, c9_coder_array_real_T_2D *c9_coderArray, const emlrtRTEInfo
   *c9_srcLocation, int32_T c9_size0, int32_T c9_size1)
{
  real_T *c9_newData;
  int32_T c9_newCapacity;
  int32_T c9_newNumel;
  (void)chartInstance;
  c9_coderArray->size[0] = c9_size0;
  c9_coderArray->size[1] = c9_size1;
  c9_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c9_coderArray->size[0],
                       c9_srcLocation, (void *)c9_sp), (size_t)(uint32_T)
    c9_coderArray->size[1], c9_srcLocation, (void *)c9_sp);
  if (c9_newNumel > c9_coderArray->vector.allocated) {
    c9_newCapacity = c9_coderArray->vector.allocated;
    if (c9_newCapacity < 16) {
      c9_newCapacity = 16;
    }

    while (c9_newCapacity < c9_newNumel) {
      if (c9_newCapacity > 1073741823) {
        c9_newCapacity = MAX_int32_T;
      } else {
        c9_newCapacity <<= 1;
      }
    }

    c9_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c9_newCapacity);
    if ((void *)c9_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c9_srcLocation, (void *)c9_sp);
    }

    if ((void *)c9_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c9_srcLocation, (void *)c9_sp);
    }

    if (c9_coderArray->vector.data != NULL) {
      memcpy(c9_newData, c9_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c9_coderArray->vector.numel);
      if (c9_coderArray->vector.owner) {
        emlrtFreeMex(c9_coderArray->vector.data);
      }
    }

    c9_coderArray->vector.data = c9_newData;
    c9_coderArray->vector.allocated = c9_newCapacity;
    c9_coderArray->vector.owner = true;
  }

  c9_coderArray->vector.numel = c9_newNumel;
}

static void c9_array_int32_T_SetSize(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c9_sp, c9_coder_array_int32_T *c9_coderArray,
  const emlrtRTEInfo *c9_srcLocation, int32_T c9_size0)
{
  int32_T c9_newCapacity;
  int32_T c9_newNumel;
  int32_T *c9_newData;
  (void)chartInstance;
  c9_coderArray->size[0] = c9_size0;
  c9_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c9_coderArray->size[0], c9_srcLocation, (void *)c9_sp);
  if (c9_newNumel > c9_coderArray->vector.allocated) {
    c9_newCapacity = c9_coderArray->vector.allocated;
    if (c9_newCapacity < 16) {
      c9_newCapacity = 16;
    }

    while (c9_newCapacity < c9_newNumel) {
      if (c9_newCapacity > 1073741823) {
        c9_newCapacity = MAX_int32_T;
      } else {
        c9_newCapacity <<= 1;
      }
    }

    c9_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c9_newCapacity);
    if ((void *)c9_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c9_srcLocation, (void *)c9_sp);
    }

    if ((void *)c9_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c9_srcLocation, (void *)c9_sp);
    }

    if (c9_coderArray->vector.data != NULL) {
      memcpy(c9_newData, c9_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c9_coderArray->vector.numel);
      if (c9_coderArray->vector.owner) {
        emlrtFreeMex(c9_coderArray->vector.data);
      }
    }

    c9_coderArray->vector.data = c9_newData;
    c9_coderArray->vector.allocated = c9_newCapacity;
    c9_coderArray->vector.owner = true;
  }

  c9_coderArray->vector.numel = c9_newNumel;
}

static void c9_array_real_T_SetSize(SFc9_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const emlrtStack *c9_sp, c9_coder_array_real_T *c9_coderArray,
  const emlrtRTEInfo *c9_srcLocation, int32_T c9_size0)
{
  real_T *c9_newData;
  int32_T c9_newCapacity;
  int32_T c9_newNumel;
  (void)chartInstance;
  c9_coderArray->size[0] = c9_size0;
  c9_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c9_coderArray->size[0], c9_srcLocation, (void *)c9_sp);
  if (c9_newNumel > c9_coderArray->vector.allocated) {
    c9_newCapacity = c9_coderArray->vector.allocated;
    if (c9_newCapacity < 16) {
      c9_newCapacity = 16;
    }

    while (c9_newCapacity < c9_newNumel) {
      if (c9_newCapacity > 1073741823) {
        c9_newCapacity = MAX_int32_T;
      } else {
        c9_newCapacity <<= 1;
      }
    }

    c9_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c9_newCapacity);
    if ((void *)c9_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c9_srcLocation, (void *)c9_sp);
    }

    if ((void *)c9_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c9_srcLocation, (void *)c9_sp);
    }

    if (c9_coderArray->vector.data != NULL) {
      memcpy(c9_newData, c9_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c9_coderArray->vector.numel);
      if (c9_coderArray->vector.owner) {
        emlrtFreeMex(c9_coderArray->vector.data);
      }
    }

    c9_coderArray->vector.data = c9_newData;
    c9_coderArray->vector.allocated = c9_newCapacity;
    c9_coderArray->vector.owner = true;
  }

  c9_coderArray->vector.numel = c9_newNumel;
}

static void c9_array_real_T_2D_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T_2D *c9_coderArray)
{
  (void)chartInstance;
  c9_coderArray->vector.data = (real_T *)NULL;
  c9_coderArray->vector.numel = 0;
  c9_coderArray->vector.allocated = 0;
  c9_coderArray->vector.owner = true;
  c9_coderArray->size[0] = 0;
  c9_coderArray->size[1] = 0;
}

static void c9_array_real_T_2D_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T_2D *c9_coderArray)
{
  (void)chartInstance;
  if (c9_coderArray->vector.owner && (c9_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c9_coderArray->vector.data);
  }
}

static void c9_array_real_T_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T *c9_coderArray)
{
  (void)chartInstance;
  c9_coderArray->vector.data = (real_T *)NULL;
  c9_coderArray->vector.numel = 0;
  c9_coderArray->vector.allocated = 0;
  c9_coderArray->vector.owner = true;
  c9_coderArray->size[0] = 0;
}

static void c9_array_int32_T_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_int32_T *c9_coderArray)
{
  (void)chartInstance;
  c9_coderArray->vector.data = (int32_T *)NULL;
  c9_coderArray->vector.numel = 0;
  c9_coderArray->vector.allocated = 0;
  c9_coderArray->vector.owner = true;
  c9_coderArray->size[0] = 0;
}

static void c9_array_real_T_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_real_T *c9_coderArray)
{
  (void)chartInstance;
  if (c9_coderArray->vector.owner && (c9_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c9_coderArray->vector.data);
  }
}

static void c9_array_int32_T_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c9_coder_array_int32_T *c9_coderArray)
{
  (void)chartInstance;
  if (c9_coderArray->vector.owner && (c9_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c9_coderArray->vector.data);
  }
}

static void c9_array_cell_wrap_34_2s_Construct
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   c9_pMatrix[2])
{
  int32_T c9_i;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_array_cell_wrap_34_Constructor(chartInstance, &c9_pMatrix[c9_i]);
  }
}

static void c9_array_cell_wrap_34_Constructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   *c9_pStruct)
{
  c9_array_real_T_Constructor(chartInstance, &c9_pStruct->f1);
}

static void c9_array_cell_wrap_34_2s_Destructo
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   c9_pMatrix[2])
{
  int32_T c9_i;
  for (c9_i = 0; c9_i < 2; c9_i++) {
    c9_array_cell_wrap_34_Destructor(chartInstance, &c9_pMatrix[c9_i]);
  }
}

static void c9_array_cell_wrap_34_Destructor
  (SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c9_cell_wrap_34
   *c9_pStruct)
{
  c9_array_real_T_Destructor(chartInstance, &c9_pStruct->f1);
}

static int32_T c9_div_nzp_s32(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c9_numerator, int32_T c9_denominator, int32_T
  c9_EMLOvCount_src_loc, uint32_T c9_ssid_src_loc, int32_T c9_offset_src_loc,
  int32_T c9_length_src_loc)
{
  int32_T c9_quotient;
  uint32_T c9_absDenominator;
  uint32_T c9_absNumerator;
  uint32_T c9_tempAbsQuotient;
  boolean_T c9_quotientNeedsNegation;
  (void)chartInstance;
  (void)c9_EMLOvCount_src_loc;
  (void)c9_ssid_src_loc;
  (void)c9_offset_src_loc;
  (void)c9_length_src_loc;
  if (c9_numerator < 0) {
    c9_absNumerator = ~(uint32_T)c9_numerator + 1U;
  } else {
    c9_absNumerator = (uint32_T)c9_numerator;
  }

  if (c9_denominator < 0) {
    c9_absDenominator = ~(uint32_T)c9_denominator + 1U;
  } else {
    c9_absDenominator = (uint32_T)c9_denominator;
  }

  c9_quotientNeedsNegation = ((c9_numerator < 0) != (c9_denominator < 0));
  c9_tempAbsQuotient = c9_absNumerator / c9_absDenominator;
  if (c9_quotientNeedsNegation) {
    c9_quotient = -(int32_T)c9_tempAbsQuotient;
  } else {
    c9_quotient = (int32_T)c9_tempAbsQuotient;
  }

  return c9_quotient;
}

static int32_T c9_div_s32_ndbzs(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c9_numerator, int32_T c9_denominator, int32_T
  c9_EMLOvCount_src_loc, uint32_T c9_ssid_src_loc, int32_T c9_offset_src_loc,
  int32_T c9_length_src_loc)
{
  int32_T c9_quotient;
  uint32_T c9_absDenominator;
  uint32_T c9_absNumerator;
  uint32_T c9_tempAbsQuotient;
  boolean_T c9_quotientNeedsNegation;
  (void)chartInstance;
  (void)c9_EMLOvCount_src_loc;
  (void)c9_ssid_src_loc;
  (void)c9_offset_src_loc;
  (void)c9_length_src_loc;
  if (c9_denominator == 0) {
    if (c9_numerator >= 0) {
      c9_quotient = MAX_int32_T;
    } else {
      c9_quotient = MIN_int32_T;
    }
  } else {
    if (c9_numerator < 0) {
      c9_absNumerator = ~(uint32_T)c9_numerator + 1U;
    } else {
      c9_absNumerator = (uint32_T)c9_numerator;
    }

    if (c9_denominator < 0) {
      c9_absDenominator = ~(uint32_T)c9_denominator + 1U;
    } else {
      c9_absDenominator = (uint32_T)c9_denominator;
    }

    c9_quotientNeedsNegation = ((c9_numerator < 0) != (c9_denominator < 0));
    c9_tempAbsQuotient = c9_absNumerator / c9_absDenominator;
    if (c9_quotientNeedsNegation) {
      c9_quotient = -(int32_T)c9_tempAbsQuotient;
    } else {
      c9_quotient = (int32_T)c9_tempAbsQuotient;
    }
  }

  return c9_quotient;
}

static void init_dsm_address_info(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance)
{
  chartInstance->c9_trigger = (const int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 5))[0U];
  chartInstance->c9_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c9_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c9_path_xo = (real_T (*)[1500])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_path_yo = (real_T (*)[1500])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_waypoints_x = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_waypoints_y = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_current_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_current_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_d_map = (boolean_T (*)[213200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c9_sl_groundvehicleDynamics_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3377602181U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2975500334U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2515218823U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1465348408U);
}

mxArray *sf_c9_sl_groundvehicleDynamics_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "nav.algs.internal.codegen.PriorityQueue"));
  return(mxcell3p);
}

mxArray *sf_c9_sl_groundvehicleDynamics_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString(
    "priorityqueuecodegen_constructPQ");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c9_sl_groundvehicleDynamics_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_sl_groundvehicleDynamics(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiDewMbAAEQMHEDMxAABrFA+I5TNCBdngYsrAHFJZUEqSLy4KNkzBUjnJeaC+Ym"
    "lFZ55aflg8y0YEOazYTGfEcl8Tqg4BHywp0y/gQO6fhYs+tmR9AtA+QWJJRnxFRD3w8Jp4PxhSJ"
    "k/KqnlDwEHyvRj2o/NHxxo/gDx80tL4kF+Aem/wIA/vTKipVcmKB+kJ4chk6EA6g4HAv5gQvOHA"
    "MwTAYUOYPpCIVXCY6jECxtavLDB8wlE/4DHy4FISLw4RI/GCzjfD5Z4SYfES0MG1eIFAOwXNWs="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_sl_groundvehicleDynamics_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sd3MI6YWDHm4ACcdsdjAizD";
}

static void sf_opaque_initialize_c9_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  initialize_params_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
  initialize_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_sl_groundvehicleDynamics(void *chartInstanceVar)
{
  enable_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_sl_groundvehicleDynamics(void *chartInstanceVar)
{
  disable_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_sl_groundvehicleDynamics(void *chartInstanceVar)
{
  sf_gateway_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_sl_groundvehicleDynamics
  (SimStruct* S)
{
  return get_sim_state_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_sl_groundvehicleDynamics(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_cleanup_runtime_resources_c9_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_sl_groundvehicleDynamicsInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sl_groundvehicleDynamics_optimization_info();
    }

    mdl_cleanup_runtime_resources_c9_sl_groundvehicleDynamics
      ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c9_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  mdl_start_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo
      (((SFc9_sl_groundvehicleDynamicsInstanceStruct*)chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c9_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  mdl_terminate_c9_sl_groundvehicleDynamics
    ((SFc9_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_sl_groundvehicleDynamics(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_sl_groundvehicleDynamics
      ((SFc9_sl_groundvehicleDynamicsInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c9_sl_groundvehicleDynamics_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [27] = {
    "eNrtWc1z20QUl0Pqtkxb2gPTztCBHLnAtGlaCsNAUttpXJLW4CRtqZmwkZ6tbaRdZT/80QPDnQP",
    "cyn/AlT+AA9w4Fk7McOMvYIYLR95KsqMqbizJpU0Zdka23sq/ffu+38pWqb5m4TiF1zdzllXG72",
    "N4zVjROBLTpcQVzc9a78d042XLsl0iVJ21uZV/2NyBDrCmbrdpPyeWab9BBPFlAb6M+PAJSO5pR",
    "TnLt3nK2iCA2bhAwIXKxVdSX3uU7SxrZhvO8rZLbbfpcu0513BB4txi3uBJfAOtGsixSgXYahnA",
    "Ua7guuMue6RzsBaE6lVcsHek9nPrSoJq6sCIKte0p2jgQa0Pdp1JRVALcoK8TUUUVFQ/t4dQ2Ry",
    "iuR94lLDsunaJbEKA3qFgI3Dw85ZWqL2MfJHfNmVEcUGJV/O9ivHwjNiGh/tcQ7f2cutZ+aoK27",
    "rToaxjtCu0DwzlRz/JoKt2hXdBkA7cYjlj0EhX64cGHvll9hisG7csFIPaj6wiC2FDvrUuakgW5",
    "LtsswrxPJkPu86DVeiCF/KvEkUKYCP+OcBSUmedbxJhoiBnJGlGdzXE2ApnDs1u4W4KFSbcm5g8",
    "M8Cpb1wKHFTzaOujhSb5pJaK+xUMo+rqakZ++7F1pkC0iQ2Zc58gVAJuOPSrnHwdKsm2Z9CoJRV",
    "KmXkFYIWhlmxrVu1xsYM6zptk93RlIiEfGpwOVEFBmDBq6N2bxNMZ9+xLzHDGPTYkZqx8fBFr4q",
    "cQ2Ca2C46pJ9SDNZBmAZk5P2MdWUJpu1QNqiBtQYOskaQlOFhIjJbWBwFssB3Ge2xZcL8ZdwQH+",
    "BUAZg0iGJaFa1iWxGAZN59t1wJ2141nFWnPfKI8sm184zowrCxGVlMJiY1RVWPYuuGGpsE26QMs",
    "7UxSqbCdGtTCGHDCfvRcKV8/eiamL41iqS7XBVqKYBlm2CktbYfNHqxTH8KJJsGeIiLjYfhesPb",
    "4Hp85mO8M3pUK4qwpcY0EbnaMfl5L4E7HtP3ulvS2OtgxMqcL2Hd6UB1gI0xtOXY/JzLofYj7+a",
    "V89joZ01+HZwBM032115jveT730d+ZMiGDrowW7KJ/mNGmke2aSeKmofzlxKMRYR6Z+7AQNLEQC",
    "DcRQF6S2KeHtH6HI6nfLLhSPLeHm7UUSGVwVyfgyil+5VA7Gv084vvtBLyTwhv6Xu2zynutDQlC",
    "tu5Du936GM8z/cFcVfBgm/dbN3BurudS1ebCadWurywsXGlBx8WvLezra6w7f2F+oYW3W8C6rSW",
    "teHOAoexL80Mj2dv+UC9J+V6Z4B8n4/kz538vTYP/44vv+DT4pD9Mi1+ZYJ9XU/Yx9Mbgzibd+K",
    "h754buvSN2Gyub9R6P13szsV5pzHpJ/yzy+6K4qwfks/K+fBbPhSPCLybwJ1P8ZlP4cqyrr/766",
    "eEv906fvfwQXv/1h3PBNHn886P58tipmD4/PEeNOs3uvmYsix+cTfmBoaVzaa1+5e7t6oq/sFSx",
    "HencX6IPquF635cP3u+R1H6H83N4KZNVzfrCrjuJ1Et0dFZP27M8QR/HH/P7Pz+cDn9hMUtePJr",
    "Sl6EDotytPn/Mj5+fHBenk2PwtOQ4vTgdfj//cXIcS8lhaK7VlpHF4B9Z+eJrJlH/PItagbU/T4",
    "yTYyYlx7BGW43dxfD70e5T0ceLYpdx/UMUJxH+udvlx7uRXRbv/W+XMO4Pi106kV2+dJ+qXV6Uc",
    "9azwpUOgV6ynPeOFMTNFMSVpjyXPmv5/u2+/LD9vug5+bDJcVB+OjFGrlJq3cMq128568cbMf3B",
    "6D+Hiks9Z8xbz/jxKpD2uKf/Ef/+O6f+hue3mtFf/Kfpp5eWGPEGkkYvmYbTDWH+rxs9EkDk+Hf",
    "Jz6N+WWP6hnH9y4lUfBu6R5nDe/Kti/OX56eph/8Aq4qJvg==",
    ""
  };

  static char newstr [1925] = "";
  newstr[0] = '\0';
  for (i = 0; i < 27; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c9_sl_groundvehicleDynamics(SimStruct *S)
{
  const char* newstr = sf_c9_sl_groundvehicleDynamics_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2546070411U));
  ssSetChecksum1(S,(386948049U));
  ssSetChecksum2(S,(509974325U));
  ssSetChecksum3(S,(1880669394U));
}

static void mdlRTW_c9_sl_groundvehicleDynamics(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c9_sl_groundvehicleDynamics(SimStruct *S)
{
  SFc9_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  chartInstance = (SFc9_sl_groundvehicleDynamicsInstanceStruct *)utMalloc(sizeof
    (SFc9_sl_groundvehicleDynamicsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc9_sl_groundvehicleDynamicsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_sl_groundvehicleDynamics;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c9_sl_groundvehicleDynamics(chartInstance);
}

void c9_sl_groundvehicleDynamics_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c9_sl_groundvehicleDynamics(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_sl_groundvehicleDynamics(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_sl_groundvehicleDynamics(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_sl_groundvehicleDynamics_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
