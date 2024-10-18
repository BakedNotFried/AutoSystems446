/* Include files */

#include "sl_groundvehicleDynamics_sfun.h"
#include "c5_sl_groundvehicleDynamics.h"
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

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c5_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c5_b_emlrtMCI = { 38,/* lineNo */
  48,                                  /* colNo */
  "circshift",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m"/* pName */
};

static emlrtMCInfo c5_c_emlrtMCI = { 82,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtMCInfo c5_d_emlrtMCI = { 28,/* lineNo */
  19,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c5_e_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtMCInfo c5_f_emlrtMCI = { 21,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m"/* pName */
};

static emlrtMCInfo c5_g_emlrtMCI = { 712,/* lineNo */
  79,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_h_emlrtMCI = { 493,/* lineNo */
  68,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_i_emlrtMCI = { 494,/* lineNo */
  66,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_j_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonnan.m"/* pName */
};

static emlrtMCInfo c5_k_emlrtMCI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c5_l_emlrtMCI = { 13,/* lineNo */
  13,                                  /* colNo */
  "toLogicalCheck",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pName */
};

static emlrtMCInfo c5_m_emlrtMCI = { 748,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_n_emlrtMCI = { 765,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_o_emlrtMCI = { 774,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_p_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validateinteger.m"/* pName */
};

static emlrtMCInfo c5_q_emlrtMCI = { 301,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_r_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c5_s_emlrtMCI = { 518,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_t_emlrtMCI = { 90,/* lineNo */
  13,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pName */
};

static emlrtMCInfo c5_u_emlrtMCI = { 320,/* lineNo */
  39,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_v_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c5_w_emlrtMCI = { 982,/* lineNo */
  131,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_x_emlrtMCI = { 993,/* lineNo */
  132,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtMCInfo c5_y_emlrtMCI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validatenonempty",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatenonempty.m"/* pName */
};

static emlrtMCInfo c5_ab_emlrtMCI = { 288,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtMCInfo c5_bb_emlrtMCI = { 18,/* lineNo */
  23,                                  /* colNo */
  "validatencols",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatencols.m"/* pName */
};

static emlrtRSInfo c5_emlrtRSI = { 14, /* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_b_emlrtRSI = { 52,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_c_emlrtRSI = { 53,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_d_emlrtRSI = { 54,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_e_emlrtRSI = { 86,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_f_emlrtRSI = { 87,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_g_emlrtRSI = { 95,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_h_emlrtRSI = { 122,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_i_emlrtRSI = { 131,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_j_emlrtRSI = { 132,/* lineNo */
  "Path Tracking System/Path Controller",/* fcnName */
  "#sl_groundvehicleDynamics:5963"     /* pathName */
};

static emlrtRSInfo c5_k_emlrtRSI = { 1,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_l_emlrtRSI = { 1,/* lineNo */
  "InternalAccess",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+map\\+internal\\I"
  "nternalAccess.m"                    /* pathName */
};

static emlrtRSInfo c5_m_emlrtRSI = { 4,/* lineNo */
  "path_gen",                          /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pathName */
};

static emlrtRSInfo c5_n_emlrtRSI = { 6,/* lineNo */
  "path_gen",                          /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pathName */
};

static emlrtRSInfo c5_o_emlrtRSI = { 9,/* lineNo */
  "path_gen",                          /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pathName */
};

static emlrtRSInfo c5_p_emlrtRSI = { 10,/* lineNo */
  "path_gen",                          /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pathName */
};

static emlrtRSInfo c5_q_emlrtRSI = { 12,/* lineNo */
  "path_gen",                          /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pathName */
};

static emlrtRSInfo c5_r_emlrtRSI = { 13,/* lineNo */
  "path_gen",                          /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pathName */
};

static emlrtRSInfo c5_s_emlrtRSI = { 15,/* lineNo */
  "path_gen",                          /* fcnName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pathName */
};

static emlrtRSInfo c5_t_emlrtRSI = { 1,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_u_emlrtRSI = { 121,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_v_emlrtRSI = { 327,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_w_emlrtRSI = { 330,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_x_emlrtRSI = { 331,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_y_emlrtRSI = { 349,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_ab_emlrtRSI = { 382,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_bb_emlrtRSI = { 387,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_cb_emlrtRSI = { 71,/* lineNo */
  "SharedMapProperties",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\SharedM"
  "apProperties.m"                     /* pathName */
};

static emlrtRSInfo c5_db_emlrtRSI = { 403,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_eb_emlrtRSI = { 503,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_fb_emlrtRSI = { 30,/* lineNo */
  "CircularBufferIndex",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\Circula"
  "rBufferIndex.m"                     /* pathName */
};

static emlrtRSInfo c5_gb_emlrtRSI = { 35,/* lineNo */
  "CircularBuffer",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\Circula"
  "rBuffer.m"                          /* pathName */
};

static emlrtRSInfo c5_hb_emlrtRSI = { 926,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_ib_emlrtRSI = { 727,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_jb_emlrtRSI = { 873,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_kb_emlrtRSI = { 1545,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_lb_emlrtRSI = { 1060,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_mb_emlrtRSI = { 365,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_nb_emlrtRSI = { 364,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_ob_emlrtRSI = { 366,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_pb_emlrtRSI = { 1438,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_qb_emlrtRSI = { 1441,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_rb_emlrtRSI = { 1444,/* lineNo */
  "MapLayer",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapLaye"
  "r.m"                                /* pathName */
};

static emlrtRSInfo c5_sb_emlrtRSI = { 15,/* lineNo */
  "num2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\num2str.m"/* pathName */
};

static emlrtRSInfo c5_tb_emlrtRSI = { 53,/* lineNo */
  "flt2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\flt2str.m"/* pathName */
};

static emlrtRSInfo c5_ub_emlrtRSI = { 44,/* lineNo */
  "mpower",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m"/* pathName */
};

static emlrtRSInfo c5_vb_emlrtRSI = { 71,/* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo c5_wb_emlrtRSI = { 525,/* lineNo */
  "MapUtils",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\MapUtils.m"/* pathName */
};

static emlrtRSInfo c5_xb_emlrtRSI = { 22,/* lineNo */
  "inflate",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\inflate.m"/* pathName */
};

static emlrtRSInfo c5_yb_emlrtRSI = { 46,/* lineNo */
  "inflate",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m"/* pathName */
};

static emlrtRSInfo c5_ac_emlrtRSI = { 16,/* lineNo */
  "sub2ind",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\sub2ind.m"/* pathName */
};

static emlrtRSInfo c5_bc_emlrtRSI = { 353,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_cc_emlrtRSI = { 527,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_dc_emlrtRSI = { 528,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_ec_emlrtRSI = { 239,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_fc_emlrtRSI = { 253,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_gc_emlrtRSI = { 272,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_hc_emlrtRSI = { 275,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ic_emlrtRSI = { 285,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_jc_emlrtRSI = { 288,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_kc_emlrtRSI = { 296,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_lc_emlrtRSI = { 305,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_mc_emlrtRSI = { 310,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_nc_emlrtRSI = { 1,/* lineNo */
  "InternalAccess",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\InternalAccess.m"/* pathName */
};

static emlrtRSInfo c5_oc_emlrtRSI = { 325,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_pc_emlrtRSI = { 683,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_qc_emlrtRSI = { 699,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_rc_emlrtRSI = { 19,/* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo c5_sc_emlrtRSI = { 377,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_tc_emlrtRSI = { 378,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_uc_emlrtRSI = { 398,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_vc_emlrtRSI = { 399,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_wc_emlrtRSI = { 400,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_xc_emlrtRSI = { 366,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_yc_emlrtRSI = { 367,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ad_emlrtRSI = { 387,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_bd_emlrtRSI = { 388,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_cd_emlrtRSI = { 389,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_dd_emlrtRSI = { 485,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ed_emlrtRSI = { 487,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_fd_emlrtRSI = { 498,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_gd_emlrtRSI = { 499,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_hd_emlrtRSI = { 500,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_id_emlrtRSI = { 506,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_jd_emlrtRSI = { 511,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_kd_emlrtRSI = { 519,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ld_emlrtRSI = { 522,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_md_emlrtRSI = { 526,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_nd_emlrtRSI = { 516,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_od_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c5_pd_emlrtRSI = { 729,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_qd_emlrtRSI = { 732,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_rd_emlrtRSI = { 733,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_sd_emlrtRSI = { 734,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_td_emlrtRSI = { 749,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ud_emlrtRSI = { 750,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_vd_emlrtRSI = { 760,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_wd_emlrtRSI = { 769,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_xd_emlrtRSI = { 881,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_yd_emlrtRSI = { 420,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_ae_emlrtRSI = { 425,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_be_emlrtRSI = { 912,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ce_emlrtRSI = { 456,/* lineNo */
  "binaryOccupancyMap",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pathName */
};

static emlrtRSInfo c5_de_emlrtRSI = { 925,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ee_emlrtRSI = { 930,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_fe_emlrtRSI = { 942,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ge_emlrtRSI = { 946,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_he_emlrtRSI = { 945,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ie_emlrtRSI = { 950,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_je_emlrtRSI = { 953,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ke_emlrtRSI = { 956,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_le_emlrtRSI = { 957,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_me_emlrtRSI = { 88,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ne_emlrtRSI = { 117,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_oe_emlrtRSI = { 128,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_pe_emlrtRSI = { 133,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_qe_emlrtRSI = { 135,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_re_emlrtRSI = { 139,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_se_emlrtRSI = { 31,/* lineNo */
  "NameValueParser",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\robotics\\robotutilsint\\+robotics\\+core\\+internal\\+codegen\\NameValuePar"
  "ser.m"                              /* pathName */
};

static emlrtRSInfo c5_te_emlrtRSI = { 39,/* lineNo */
  "NameValueParserInterface",          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\robotics\\robotutilsint\\+robotics\\+core\\+internal\\NameValueParserInterfa"
  "ce.m"                               /* pathName */
};

static emlrtRSInfo c5_ue_emlrtRSI = { 344,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ve_emlrtRSI = { 961,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_we_emlrtRSI = { 171,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_xe_emlrtRSI = { 175,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ye_emlrtRSI = { 180,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_af_emlrtRSI = { 190,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_bf_emlrtRSI = { 195,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_cf_emlrtRSI = { 201,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_df_emlrtRSI = { 217,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ef_emlrtRSI = { 222,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ff_emlrtRSI = { 234,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_gf_emlrtRSI = { 244,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_hf_emlrtRSI = { 252,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_if_emlrtRSI = { 271,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_jf_emlrtRSI = { 297,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_kf_emlrtRSI = { 304,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_lf_emlrtRSI = { 305,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_mf_emlrtRSI = { 306,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_nf_emlrtRSI = { 45,/* lineNo */
  "PriorityQueue",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pathName */
};

static emlrtRSInfo c5_of_emlrtRSI = { 489,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_pf_emlrtRSI = { 492,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_qf_emlrtRSI = { 493,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_rf_emlrtRSI = { 466,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_sf_emlrtRSI = { 556,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_tf_emlrtRSI = { 1073,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_uf_emlrtRSI = { 71,/* lineNo */
  "PriorityQueue",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pathName */
};

static emlrtRSInfo c5_vf_emlrtRSI = { 506,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_wf_emlrtRSI = { 508,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_xf_emlrtRSI = { 509,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_yf_emlrtRSI = { 39,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_ag_emlrtRSI = { 144,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_bg_emlrtRSI = { 402,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo c5_cg_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c5_dg_emlrtRSI = { 991,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_eg_emlrtRSI = { 990,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_fg_emlrtRSI = { 977,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_gg_emlrtRSI = { 974,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_hg_emlrtRSI = { 968,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ig_emlrtRSI = { 967,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_jg_emlrtRSI = { 965,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_kg_emlrtRSI = { 415,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_lg_emlrtRSI = { 426,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_mg_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c5_ng_emlrtRSI = { 1009,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_og_emlrtRSI = { 1018,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_pg_emlrtRSI = { 1021,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_qg_emlrtRSI = { 1028,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_rg_emlrtRSI = { 1029,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_sg_emlrtRSI = { 1031,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_tg_emlrtRSI = { 301,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_ug_emlrtRSI = { 305,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_vg_emlrtRSI = { 509,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_wg_emlrtRSI = { 510,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_xg_emlrtRSI = { 520,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_yg_emlrtRSI = { 39,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c5_ah_emlrtRSI = { 113,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo c5_bh_emlrtRSI = { 22,/* lineNo */
  "matlabCodegenHandle",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\matlabCodegenHandle.m"/* pathName */
};

static emlrtRTEInfo c5_emlrtRTEI = { 15,/* lineNo */
  9,                                   /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_b_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_c_emlrtRTEI = { 96,/* lineNo */
  9,                                   /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_d_emlrtRTEI = { 97,/* lineNo */
  9,                                   /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_e_emlrtRTEI = { 123,/* lineNo */
  9,                                   /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_f_emlrtRTEI = { 124,/* lineNo */
  9,                                   /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_g_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "path_gen",                          /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pName */
};

static emlrtRTEInfo c5_h_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "path_gen",                          /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pName */
};

static emlrtRTEInfo c5_i_emlrtRTEI = { 333,/* lineNo */
  18,                                  /* colNo */
  "binaryOccupancyMap",                /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\binaryOccupancyMap.m"/* pName */
};

static emlrtRTEInfo c5_j_emlrtRTEI = { 33,/* lineNo */
  1,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_k_emlrtRTEI = { 35,/* lineNo */
  23,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_l_emlrtRTEI = { 35,/* lineNo */
  17,                                  /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_m_emlrtRTEI = { 35,/* lineNo */
  5,                                   /* colNo */
  "sub2ind",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sub2ind.m"/* pName */
};

static emlrtRTEInfo c5_n_emlrtRTEI = { 46,/* lineNo */
  13,                                  /* colNo */
  "inflate",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m"/* pName */
};

static emlrtRTEInfo c5_o_emlrtRTEI = { 56,/* lineNo */
  38,                                  /* colNo */
  "inflate",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m"/* pName */
};

static emlrtRTEInfo c5_p_emlrtRTEI = { 56,/* lineNo */
  29,                                  /* colNo */
  "inflate",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m"/* pName */
};

static emlrtRTEInfo c5_q_emlrtRTEI = { 56,/* lineNo */
  59,                                  /* colNo */
  "inflate",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m"/* pName */
};

static emlrtRTEInfo c5_r_emlrtRTEI = { 128,/* lineNo */
  57,                                  /* colNo */
  "allOrAny",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny.m"/* pName */
};

static emlrtRTEInfo c5_s_emlrtRTEI = { 12,/* lineNo */
  5,                                   /* colNo */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m"/* pName */
};

static emlrtRTEInfo c5_t_emlrtRTEI = { 17,/* lineNo */
  20,                                  /* colNo */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m"/* pName */
};

static emlrtRTEInfo c5_u_emlrtRTEI = { 151,/* lineNo */
  45,                                  /* colNo */
  "strcmp",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pName */
};

static emlrtRTEInfo c5_v_emlrtRTEI = { 364,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_w_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_x_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m"/* pName */
};

static emlrtRTEInfo c5_y_emlrtRTEI = { 740,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_ab_emlrtRTEI = { 741,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_bb_emlrtRTEI = { 735,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_cb_emlrtRTEI = { 736,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_db_emlrtRTEI = { 907,/* lineNo */
  24,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_eb_emlrtRTEI = { 92,/* lineNo */
  39,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m"/* pName */
};

static emlrtRTEInfo c5_fb_emlrtRTEI = { 227,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_gb_emlrtRTEI = { 369,/* lineNo */
  24,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_hb_emlrtRTEI = { 297,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_ib_emlrtRTEI = { 303,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_jb_emlrtRTEI = { 304,/* lineNo */
  39,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_kb_emlrtRTEI = { 360,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_lb_emlrtRTEI = { 304,/* lineNo */
  67,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_mb_emlrtRTEI = { 478,/* lineNo */
  18,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_nb_emlrtRTEI = { 476,/* lineNo */
  18,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_ob_emlrtRTEI = { 344,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_pb_emlrtRTEI = { 344,/* lineNo */
  44,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_qb_emlrtRTEI = { 345,/* lineNo */
  37,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_rb_emlrtRTEI = { 345,/* lineNo */
  51,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_sb_emlrtRTEI = { 965,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_tb_emlrtRTEI = { 986,/* lineNo */
  26,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_ub_emlrtRTEI = { 986,/* lineNo */
  51,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_vb_emlrtRTEI = { 990,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_wb_emlrtRTEI = { 996,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_xb_emlrtRTEI = { 1009,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_yb_emlrtRTEI = { 409,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_ac_emlrtRTEI = { 1018,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_bc_emlrtRTEI = { 1021,/* lineNo */
  28,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_cc_emlrtRTEI = { 1021,/* lineNo */
  72,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_dc_emlrtRTEI = { 1026,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_ec_emlrtRTEI = { 1026,/* lineNo */
  55,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_fc_emlrtRTEI = { 423,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_gc_emlrtRTEI = { 427,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_hc_emlrtRTEI = { 1031,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_ic_emlrtRTEI = { 415,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_jc_emlrtRTEI = { 419,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_kc_emlrtRTEI = { 1029,/* lineNo */
  21,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_lc_emlrtRTEI = { 1016,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_mc_emlrtRTEI = { 509,/* lineNo */
  42,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c5_nc_emlrtRTEI = { 520,/* lineNo */
  24,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c5_oc_emlrtRTEI = { 521,/* lineNo */
  17,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c5_pc_emlrtRTEI = { 121,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_qc_emlrtRTEI = { 128,/* lineNo */
  30,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_rc_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo c5_sc_emlrtRTEI = { 520,/* lineNo */
  13,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c5_tc_emlrtRTEI = { 566,/* lineNo */
  13,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c5_uc_emlrtRTEI = { 305,/* lineNo */
  38,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c5_vc_emlrtRTEI = { 9,/* lineNo */
  16,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_wc_emlrtRTEI = { 10,/* lineNo */
  16,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_xc_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963"     /* pName */
};

static emlrtRTEInfo c5_yc_emlrtRTEI = { 13,/* lineNo */
  5,                                   /* colNo */
  "path_gen",                          /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pName */
};

static emlrtRTEInfo c5_ad_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "path_gen",                          /* fName */
  "C:\\Users\\jeff\\Qepoxy Dropbox\\Jeff whitford\\EGH446\\egh446_simEnv2024\\sim_env\\AutoSystems446\\path_gen.m"/* pName */
};

static emlrtRTEInfo c5_bd_emlrtRTEI = { 57,/* lineNo */
  25,                                  /* colNo */
  "strcmp",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\strcmp.m"/* pName */
};

static emlrtRTEInfo c5_cd_emlrtRTEI = { 304,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_dd_emlrtRTEI = { 31,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c5_ed_emlrtRTEI = { 344,/* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_fd_emlrtRTEI = { 963,/* lineNo */
  18,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_gd_emlrtRTEI = { 986,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_hd_emlrtRTEI = { 1021,/* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtRTEInfo c5_id_emlrtRTEI = { 509,/* lineNo */
  13,                                  /* colNo */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pName */
};

static emlrtRTEInfo c5_jd_emlrtRTEI = { 116,/* lineNo */
  1,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtBCInfo c5_emlrtBCI = { 0,  /* iFirst */
  MAX_int32_T,                         /* iLast */
  47,                                  /* lineNo */
  21,                                  /* colNo */
  "path_x",                            /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  19,                                  /* colNo */
  "path_x",                            /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_emlrtDCI = { 48, /* lineNo */
  19,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  43,                                  /* colNo */
  "path_y",                            /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_b_emlrtDCI = { 48,/* lineNo */
  43,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  18,                                  /* colNo */
  "path_x",                            /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_c_emlrtDCI = { 49,/* lineNo */
  18,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  41,                                  /* colNo */
  "path_y",                            /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_d_emlrtDCI = { 49,/* lineNo */
  41,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  28,                                  /* colNo */
  "path_x",                            /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_e_emlrtDCI = { 84,/* lineNo */
  28,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  51,                                  /* colNo */
  "path_y",                            /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_f_emlrtDCI = { 84,/* lineNo */
  51,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_h_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  95,                                  /* lineNo */
  61,                                  /* colNo */
  "waypointsx",                        /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_g_emlrtDCI = { 95,/* lineNo */
  61,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_i_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  95,                                  /* lineNo */
  85,                                  /* colNo */
  "waypointsy",                        /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_h_emlrtDCI = { 95,/* lineNo */
  85,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_j_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  122,                                 /* lineNo */
  61,                                  /* colNo */
  "waypointsx",                        /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_i_emlrtDCI = { 122,/* lineNo */
  61,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_k_emlrtBCI = { 1,/* iFirst */
  5,                                   /* iLast */
  122,                                 /* lineNo */
  85,                                  /* colNo */
  "waypointsy",                        /* aName */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_j_emlrtDCI = { 122,/* lineNo */
  85,                                  /* colNo */
  "Path Tracking System/Path Controller",/* fName */
  "#sl_groundvehicleDynamics:5963",    /* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c5_emlrtECI = { 2,  /* nDims */
  56,                                  /* lineNo */
  38,                                  /* colNo */
  "inflate",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m"/* pName */
};

static emlrtECInfo c5_b_emlrtECI = { -1,/* nDims */
  56,                                  /* lineNo */
  17,                                  /* colNo */
  "inflate",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m"/* pName */
};

static emlrtBCInfo c5_l_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  56,                                  /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "inflate",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\nav_rst\\nav_rst_lib\\+nav\\+algs\\+internal\\+impl\\inflate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "validateAStarBuiltinCostFunction",  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+internal\\+validation\\validateAStarBuiltinCostFunction.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_n_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  756,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_k_emlrtDCI = { 756,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_o_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  756,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_l_emlrtDCI = { 756,/* lineNo */
  49,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_p_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  757,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_m_emlrtDCI = { 757,/* lineNo */
  36,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_q_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  757,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_n_emlrtDCI = { 757,/* lineNo */
  51,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_r_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  913,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_o_emlrtDCI = { 913,/* lineNo */
  27,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  197,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  208,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  209,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  211,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_p_emlrtDCI = { 223,/* lineNo */
  27,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_w_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  223,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_q_emlrtDCI = { 223,/* lineNo */
  38,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_x_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  223,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_y_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  259,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_ab_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  259,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_bb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  260,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_cb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  260,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_db_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  261,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_eb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  261,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  266,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  271,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  282,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_ib_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  282,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_jb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  283,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_kb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  283,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_lb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  284,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_mb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  284,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_nb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  258,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_ob_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  258,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_r_emlrtDCI = { 303,/* lineNo */
  48,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_pb_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  303,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_c_emlrtECI = { -1,/* nDims */
  303,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c5_s_emlrtDCI = { 304,/* lineNo */
  41,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_qb_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  304,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_d_emlrtECI = { -1,/* nDims */
  304,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c5_t_emlrtDCI = { 360,/* lineNo */
  54,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_rb_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  360,                                 /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_u_emlrtDCI = { 350,/* lineNo */
  38,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_sb_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  350,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_tb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  179,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_v_emlrtDCI = { 179,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ub_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  179,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_w_emlrtDCI = { 179,/* lineNo */
  57,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_vb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  179,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_x_emlrtDCI = { 179,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_wb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  179,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_y_emlrtDCI = { 179,/* lineNo */
  31,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_xb_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ab_emlrtDCI = { 180,/* lineNo */
  28,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_yb_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ac_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_bb_emlrtDCI = { 180,/* lineNo */
  64,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_bc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_cb_emlrtDCI = { 180,/* lineNo */
  107,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_dc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ec_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  180,                                 /* lineNo */
  147,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_db_emlrtDCI = { 180,/* lineNo */
  147,                                 /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_fc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  180,                                 /* lineNo */
  147,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  181,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_eb_emlrtDCI = { 181,/* lineNo */
  27,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_hc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  181,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_fb_emlrtDCI = { 181,/* lineNo */
  38,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ic_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  182,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_gb_emlrtDCI = { 182,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_jc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  182,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_hb_emlrtDCI = { 182,/* lineNo */
  31,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_ib_emlrtDCI = { 92,/* lineNo */
  48,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_jb_emlrtDCI = { 92,/* lineNo */
  48,                                  /* colNo */
  "PriorityQueue",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\PriorityQueue.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo c5_kc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  291,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_kb_emlrtDCI = { 291,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_lc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  291,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_lb_emlrtDCI = { 291,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_mc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  203,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_mb_emlrtDCI = { 203,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_nc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  203,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_nb_emlrtDCI = { 203,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_oc_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  208,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ob_emlrtDCI = { 208,/* lineNo */
  43,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_pc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  204,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_pb_emlrtDCI = { 204,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_qc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  204,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c5_qb_emlrtDCI = { 204,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_rc_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  209,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_rb_emlrtDCI = { 209,/* lineNo */
  43,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_sc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  211,                                 /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_sb_emlrtDCI = { 211,/* lineNo */
  50,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_tc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  211,                                 /* lineNo */
  60,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_tb_emlrtDCI = { 211,/* lineNo */
  60,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_uc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  231,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  232,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wc_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  525,                                 /* lineNo */
  92,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_xc_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  525,                                 /* lineNo */
  105,                                 /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_yc_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  304,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ub_emlrtDCI = { 304,/* lineNo */
  80,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ad_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  239,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_bd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  239,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_cd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  255,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_dd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  255,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ed_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  274,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_fd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  274,                                 /* lineNo */
  68,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_gd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  285,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_hd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  285,                                 /* lineNo */
  93,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_id_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  285,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_jd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  285,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_kd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  262,                                 /* lineNo */
  80,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ld_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  262,                                 /* lineNo */
  93,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_md_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  262,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_nd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  262,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c5_od_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  263,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  263,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_qd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  268,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_rd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  268,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_sd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  269,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_td_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  269,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ud_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  270,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_vd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  270,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_wd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  542,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_vb_emlrtDCI = { 542,/* lineNo */
  33,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_xd_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  542,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_wb_emlrtDCI = { 542,/* lineNo */
  49,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_xb_emlrtDCI = { 458,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c5_yb_emlrtDCI = { 474,/* lineNo */
  20,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c5_e_emlrtECI = { -1,/* nDims */
  345,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtECInfo c5_f_emlrtECI = { -1,/* nDims */
  344,                                 /* lineNo */
  13,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pName */
};

static emlrtBCInfo c5_yd_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  315,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ac_emlrtDCI = { 315,/* lineNo */
  42,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ae_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  315,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_bc_emlrtDCI = { 315,/* lineNo */
  53,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_be_emlrtBCI = { 1,/* iFirst */
  410,                                 /* iLast */
  332,                                 /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_cc_emlrtDCI = { 332,/* lineNo */
  46,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ce_emlrtBCI = { 1,/* iFirst */
  520,                                 /* iLast */
  332,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_dc_emlrtDCI = { 332,/* lineNo */
  57,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c5_g_emlrtECI = { -1,/* nDims */
  996,                                 /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtBCInfo c5_de_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  996,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ec_emlrtDCI = { 996,/* lineNo */
  32,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo c5_h_emlrtECI = { -1,/* nDims */
  986,                                 /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtBCInfo c5_ee_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  986,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_fc_emlrtDCI = { 986,/* lineNo */
  28,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_fe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  986,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_gc_emlrtDCI = { 986,/* lineNo */
  58,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ge_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  986,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_hc_emlrtDCI = { 353,/* lineNo */
  45,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_he_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  353,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_ic_emlrtDCI = { 1021,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ie_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  1021,                                /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_i_emlrtECI = { -1,/* nDims */
  1021,                                /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c5_jc_emlrtDCI = { 1026,/* lineNo */
  32,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_je_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  1026,                                /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c5_j_emlrtECI = { -1,/* nDims */
  1026,                                /* lineNo */
  17,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pName */
};

static emlrtDCInfo c5_kc_emlrtDCI = { 409,/* lineNo */
  30,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_ke_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  409,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_lc_emlrtDCI = { 423,/* lineNo */
  32,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_le_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  423,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_mc_emlrtDCI = { 415,/* lineNo */
  36,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_me_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  415,                                 /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_ne_emlrtBCI = { 1,/* iFirst */
  213200,                              /* iLast */
  1018,                                /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c5_nc_emlrtDCI = { 1018,/* lineNo */
  35,                                  /* colNo */
  "plannerAStarGrid",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c5_oe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  520,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c5_pe_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  521,                                 /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "MapInterface",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtRSInfo c5_ch_emlrtRSI = { 521,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_dh_emlrtRSI = { 986,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_eh_emlrtRSI = { 345,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_fh_emlrtRSI = { 1026,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_gh_emlrtRSI = { 996,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_hh_emlrtRSI = { 344,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\+nav\\+algs\\+internal\\+codegen\\plannerAStarGrid.m"/* pathName */
};

static emlrtRSInfo c5_ih_emlrtRSI = { 566,/* lineNo */
  "MapInterface",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\shared\\autonomous\\maplib\\internal\\+matlabshared\\+autonomous\\+internal\\MapInte"
  "rface.m"                            /* pathName */
};

static emlrtRSInfo c5_jh_emlrtRSI = { 1016,/* lineNo */
  "plannerAStarGrid",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024a\\toolbox\\nav\\navalgs2\\plannerAStarGrid.m"/* pathName */
};

static char_T c5_cv[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
  'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

static char_T c5_cv1[47] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n',
  't', 'e', 'g', 'e', 'r' };

static char_T c5_cv2[52] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
  's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g', 'r',
  'i', 'd', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F', 'a', 'i', 'l',
  'e', 'd', 'L', 'e', 's', 's', 'T', 'h', 'a', 'n' };

static char_T c5_cv3[16] = { 'N', 'u', 'm', 'N', 'o', 'd', 'e', 's', 'E', 'x',
  'p', 'l', 'o', 'r', 'e', 'd' };

static char_T c5_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n', 'E',
  'r', 'r', 'o', 'r' };

static char_T c5_cv5[64] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
  's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g', 'r',
  'i', 'd', ':', 'U', 's', 'e', 'r', 'D', 'i', 's', 't', 'a', 'n', 'c', 'e', 'F',
  'u', 'n', 'c', 't', 'i', 'o', 'n', 'R', 'e', 't', 'u', 'r', 'n', 's', 'N', 'a',
  'N', 'O', 'r', 'I', 'n', 'f' };

static char_T c5_cv6[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'r', 'i',
  'd', '2', 'w', 'o', 'r', 'l', 'd', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
  'N', 'o', 'n', 'e', 'm', 'p', 't', 'y' };

static char_T c5_cv7[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
  'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't', 'r',
  'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o',
  'n', 'e', 'm', 'p', 't', 'y' };

static char_T c5_cv8[20] = { 'i', 'n', 'p', 'u', 't', ' ', 'n', 'u', 'm', 'b',
  'e', 'r', ' ', '2', ',', ' ', 'i', 'd', 'x', ',' };

static char_T c5_cv9[33] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'r', 'i',
  'd', '2', 'w', 'o', 'r', 'l', 'd', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
  'I', 'n', 't', 'e', 'g', 'e', 'r' };

static char_T c5_cv10[39] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'c', 'a', 't',
  'e', 'n', 'a', 't', 'e', ':', 'm', 'a', 't', 'r', 'i', 'x', 'D', 'i', 'm', 'e',
  'n', 's', 'i', 'o', 'n', 'M', 'i', 's', 'm', 'a', 't', 'c', 'h' };

/* Function Declarations */
static void initialize_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void initialize_params_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_start_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_terminate_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void enable_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void disable_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void sf_gateway_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void ext_mode_exec_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void c5_update_jit_animation_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void c5_do_animation_call_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void set_sim_state_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const mxArray
   *c5_st);
static void c5_path_gen(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_g_logical_map[213200],
  real_T c5_goal[2], c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_out_path);
static c5_binaryOccupancyMap *c5_binaryOccupancyMap_binaryOccupancyMap
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, boolean_T c5_b_varargin_1[213200]);
static void c5_binaryOccupancyMap_inflate
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj);
static void c5_MapLayer_getValueAllImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, boolean_T c5_val[213200]);
static boolean_T c5_allinrange(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_x_data[], int32_T c5_x_size[2], int32_T c5_hi);
static void c5_MapInterface_world2grid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, real_T c5_idx[2]);
static void c5_MapInterface_local2gridImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, real_T c5_localXY[2], real_T c5_gridInd[2]);
static void c5_b_MapInterface_world2grid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, real_T c5_pos[2], real_T c5_idx[2]);
static c5_plannerAStarGrid *c5_plannerAStarGrid_plannerAStarGrid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_binaryOccupancyMap *c5_b_varargin_1);
static void c5_plannerAStarGrid_setInputState
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_plannerAStarGrid *c5_obj);
static void c5_ind2sub(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_ndx[213200], int32_T c5_varargout_1[213200], int32_T
  c5_varargout_2[213200], int32_T c5_b_varargout_3[213200]);
static void c5_validateAStarBuiltinCostFunction
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, char_T c5_strVal_data[], int32_T c5_strVal_size[2], real_T *c5_idx);
static void c5_plannerAStarGrid_plan(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_plannerAStarGrid *c5_obj, real_T
  c5_start[2], real_T c5_goal[2], c5_coder_array_real_T_2D *c5_path);
static void c5_plannerAStarGrid_validateStartGoal
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_binaryOccupancyMap *c5_c_map, real_T
   c5_StartInGrid[2], real_T c5_GoalInGrid[2]);
static real_T c5_plannerAStarGrid_getNodeCostOMDefault
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, real_T c5_currentNode);
static c5_nav_algs_internal_plannerAStarGrid
  *c5_plannerAStarGrid_initializeInternalPlanner
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_nav_algs_internal_plannerAStarGrid
   *c5_iobj_0);
static c5_nav_algs_internal_plannerAStarGrid
  *c5_b_plannerAStarGrid_plannerAStarGrid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_c_map[213200],
   real_T c5_obstacleThreshold);
static void c5_b_ind2sub(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_ndx[213200], int32_T c5_varargout_1[213200], int32_T
  c5_varargout_2[213200]);
static void c5_plannerAStarGrid_runPlan
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_b_astarInternal, real_T
   c5_start[2], real_T c5_goal[2]);
static void c5_plannerAStarGrid_getHeuristicMatrix
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_goalIn[2],
   real_T c5_Hn[213200]);
static void c5_plannerAStarGrid_Chebyshev
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, real_T
   c5_b_pose1[426400], real_T c5_pose2[426400], real_T c5_dist[213200]);
static real_T c5_plannerAStarGrid_Euclidean
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, real_T c5_b_pose1[2], real_T c5_pose2[2]);
static real_T c5_sumColumnB(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_c_x[2]);
static real_T c5_sqrt(SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x);
static void c5_plannerAStarGrid_getNeighbors
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T
   c5_Neighbors_data[], int32_T c5_Neighbors_size[2], real_T *c5_NumNeighbors);
static void c5_plannerAStarGrid_reconstructPath
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_CurrentRow,
   real_T c5_CurrentCol, real_T c5_startIn[2]);
static real_T c5_plannerAStarGrid_gcostValue
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_CurrentRow,
   real_T c5_CurrentCol, real_T c5_i, real_T c5_j);
static void c5_indexShapeCheck(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance);
static void c5_plannerAStarGrid_getEssentialOutput
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_nav_algs_internal_plannerAStarGrid
   *c5_b_astarInternal);
static void c5_warning(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp);
static void c5_plannerAStarGrid_getPathOutput
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_coder_array_real_T_2D *c5_pathOut);
static void c5_MapInterface_grid2worldImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_worldXY);
static void c5_MapInterface_grid2localImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_localXY);
static void c5_MapInterface_local2worldImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_localXY,
   c5_coder_array_real_T_2D *c5_worldXY);
static void c5_MapInterface_grid2world
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_idx,
   c5_coder_array_real_T_2D *c5_pos);
static void c5_b_MapInterface_grid2worldImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_worldXY);
static void c5_b_MapInterface_grid2localImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_localXY);
static void c5_b_path_gen(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_g_logical_map[213200],
  real_T c5_start[2], real_T c5_goal[2], c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_out_path);
static void c5_handle_matlabCodegenDestructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_PriorityQueue *c5_obj);
static void c5_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c5_a__output_of_sprintf_, const char_T
  *c5_identifier, char_T c5_d_y[23]);
static void c5_b_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  char_T c5_d_y[23]);
static real_T c5_c_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier);
static real_T c5_d_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static real_T c5_e_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  boolean_T *c5_svPtr);
static real_T c5_f_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T *c5_svPtr);
static void c5_g_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_nullptr, const
  char_T *c5_identifier, boolean_T *c5_svPtr, c5_coder_array_real_T *c5_d_y);
static void c5_h_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_u, const
  emlrtMsgIdentifier *c5_parentId, boolean_T *c5_svPtr, c5_coder_array_real_T
  *c5_d_y);
static void c5_slStringInitializeDynamicBuffers
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance);
static void c5_chart_data_browse_helper
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, int32_T
   c5_ssIdNumber, const mxArray **c5_mxData, uint8_T *c5_isValueTooBig);
static const mxArray *c5_hold(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0);
static const mxArray *c5_plot(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1, const mxArray *c5_input2);
static const mxArray *c5_sprintf(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1);
static const mxArray *c5_feval(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1);
static void c5_b_feval(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1);
static void c5_b_sqrt(SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T *c5_c_x);
static void c5_or(SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                  boolean_T c5_in1_data[], int32_T c5_in1_size[2], boolean_T
                  c5_in2_data[], int32_T c5_in2_size[2]);
static void c5_array_real_T_SetSize(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_int32_T_SetSize(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0);
static void c5_array_real_T_2D_SetSize
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_coder_array_real_T_2D *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0, int32_T c5_size1);
static void c5_array_real_T_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T *c5_coderArray);
static void c5_array_real_T_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T *c5_coderArray);
static void c5_array_s_Y7g3XIg0UrmNkIXtokcBk_C
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_pStruct);
static void c5_array_s_Y7g3XIg0UrmNkIXtokcBk_D
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_pStruct);
static void c5_array_real_T_2D_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray);
static void c5_array_real_T_2D_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray);
static void c5_array_int32_T_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_int32_T *c5_coderArray);
static void c5_array_int32_T_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_int32_T *c5_coderArray);
static void c5_array_cell_wrap_36_2s_Construct
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   c5_pMatrix[2]);
static void c5_array_cell_wrap_36_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   *c5_pStruct);
static void c5_array_cell_wrap_36_2s_Destructo
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   c5_pMatrix[2]);
static void c5_array_cell_wrap_36_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   *c5_pStruct);
static int32_T c5_div_nzp_s32(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc);
static int32_T c5_div_s32_ndbzs(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc);
static void init_dsm_address_info(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c5_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "navigation_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c5_path_x_not_empty = false;
  chartInstance->c5_path_y_not_empty = false;
  chartInstance->c5_timer_not_empty = false;
  chartInstance->c5_future_wp_idx_not_empty = false;
  chartInstance->c5_current_wp_idx_not_empty = false;
  chartInstance->c5_wp_counter_not_empty = false;
  chartInstance->c5_doneDoubleBufferReInit = false;
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  c5_array_real_T_Constructor(chartInstance, &chartInstance->c5_path_x);
  c5_array_real_T_Constructor(chartInstance, &chartInstance->c5_path_y);
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  c5_array_real_T_Destructor(chartInstance, &chartInstance->c5_path_x);
  c5_array_real_T_Destructor(chartInstance, &chartInstance->c5_path_y);
}

static void mdl_setup_runtime_resources_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  static const int32_T c5_b_postfixPredicateTree[3] = { 0, 1, -3 };

  static const int32_T c5_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c5_b_condTxtEndIdx[2] = { 2172, 2205 };

  static const int32_T c5_b_condTxtStartIdx[2] = { 2139, 2176 };

  static const int32_T c5_condTxtEndIdx[2] = { 298, 317 };

  static const int32_T c5_condTxtStartIdx[2] = { 283, 302 };

  static const uint32_T c5_decisionTxtEndIdx = 0U;
  static const uint32_T c5_decisionTxtStartIdx = 0U;
  setDataBrowseFcn(chartInstance->S, (void *)&c5_chart_data_browse_helper);
  chartInstance->c5_RuntimeVar = sfListenerCacheSimStruct(chartInstance->S);
  sfListenerInitializeRuntimeVars(chartInstance->c5_RuntimeVar,
    &chartInstance->c5_IsDebuggerActive,
    &chartInstance->c5_IsSequenceViewerPresent, 0, 0,
    &chartInstance->c5_mlFcnLineNumber, &chartInstance->c5_IsHeatMapPresent, 0);
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c5_JITStateAnimation[0],
                        &chartInstance->c5_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c5_covrtInstance, 1U, 0U, 1U,
    64U);
  covrtChartInitFcn(chartInstance->c5_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c5_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c5_decisionTxtStartIdx, &c5_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c5_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance, "", 4U, 0U, 1U, 0U, 10U, 0U,
                  0U, 0U, 0U, 0U, 4U, 2U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                     "c5_sl_groundvehicleDynamics", 0, -1, 4424);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 280, 317, -1,
                    455, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 559, 576, -1,
                    603, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 785, 810, -1,
                    884, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 921, 947, -1,
                    1028, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 4U, 1061, 1083, -1,
                    1160, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 5U, 2136, 2206, -1,
                    2299, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 6U, 2457, 2495,
                    2543, 2601, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 7U, 3075, 3112, -1,
                    3530, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 8U, 3628, 3658,
                    3685, 3720, false);
  covrtEmlIfInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 9U, 3884, 3909, -1,
                    4340, false);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 283, 317, 2U,
                      0U, &c5_condTxtStartIdx[0], &c5_condTxtEndIdx[0], 3U,
                      &c5_postfixPredicateTree[0], false);
  covrtEmlMCDCInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 2139, 2205,
                      2U, 2U, &c5_b_condTxtStartIdx[0], &c5_b_condTxtEndIdx[0],
                      3U, &c5_b_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 0U, 2139,
    2172, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 1U, 2176,
    2205, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 2U, 2461,
    2494, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 3U, 3078,
    3111, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 4U, 3631,
    3657, -1, 2U);
  covrtEmlRelationalInitFcn(chartInstance->c5_covrtInstance, 4U, 0U, 5U, 3888,
    3908, -1, 4U);
  covrtEmlInitFcn(chartInstance->c5_covrtInstance,
                  "C:/Users/jeff/Qepoxy Dropbox/Jeff whitford/EGH446/egh446_simEnv2024/sim_env/AutoSystems446/path_gen.m",
                  14U, 0U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c5_covrtInstance, 14U, 0U, 0U, "path_gen", 0,
                     -1, 631);
}

static void mdl_cleanup_runtime_resources_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  sfListenerLightTerminate(chartInstance->c5_RuntimeVar);
  covrtDeleteStateflowInstanceData(chartInstance->c5_covrtInstance);
}

static void enable_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  static char_T c5_b_cv1[3] = { '-', '-', 'c' };

  static char_T c5_b_cv[2] = { 'o', 'n' };

  c5_s_Y7g3XIg0UrmNkIXtokcBk c5_path;
  emlrtStack c5_b_st;
  emlrtStack c5_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_p_y = NULL;
  real_T c5_b_waypointsx[5];
  real_T c5_b_waypointsy[5];
  real_T c5_c_waypointsx[2];
  real_T c5_current_wp[2];
  real_T c5_d_waypointsx[2];
  real_T c5_e_waypointsx[2];
  real_T c5_future_wp[2];
  real_T c5_j_y[2];
  real_T c5_l_y[2];
  real_T c5_ab_a;
  real_T c5_ac_a;
  real_T c5_b_a;
  real_T c5_b_b;
  real_T c5_b_capture_distance;
  real_T c5_b_distance_from_wp;
  real_T c5_b_stop;
  real_T c5_b_target_th;
  real_T c5_b_wp_cap_dist;
  real_T c5_bb_a;
  real_T c5_bc_a;
  real_T c5_c_a;
  real_T c5_c_c;
  real_T c5_c_x;
  real_T c5_cb_a;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d_a;
  real_T c5_d_c;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_db_a;
  real_T c5_dist_to_future;
  real_T c5_dist_to_last;
  real_T c5_dist_to_path_last;
  real_T c5_e_a;
  real_T c5_e_c;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_eb_a;
  real_T c5_f_a;
  real_T c5_f_c;
  real_T c5_f_x;
  real_T c5_f_y;
  real_T c5_fb_a;
  real_T c5_g_a;
  real_T c5_g_c;
  real_T c5_g_x;
  real_T c5_g_y;
  real_T c5_gb_a;
  real_T c5_h_a;
  real_T c5_h_c;
  real_T c5_h_x;
  real_T c5_h_y;
  real_T c5_hb_a;
  real_T c5_i_a;
  real_T c5_i_c;
  real_T c5_i_x;
  real_T c5_i_y;
  real_T c5_ib_a;
  real_T c5_j_a;
  real_T c5_j_c;
  real_T c5_j_x;
  real_T c5_jb_a;
  real_T c5_k_a;
  real_T c5_k_c;
  real_T c5_k_x;
  real_T c5_k_y;
  real_T c5_kb_a;
  real_T c5_l_a;
  real_T c5_l_c;
  real_T c5_l_x;
  real_T c5_lb_a;
  real_T c5_m_a;
  real_T c5_m_x;
  real_T c5_mb_a;
  real_T c5_n_a;
  real_T c5_nb_a;
  real_T c5_num_waypoints;
  real_T c5_o_a;
  real_T c5_ob_a;
  real_T c5_p_a;
  real_T c5_pb_a;
  real_T c5_q_a;
  real_T c5_qb_a;
  real_T c5_r_a;
  real_T c5_rb_a;
  real_T c5_s_a;
  real_T c5_sb_a;
  real_T c5_t_a;
  real_T c5_tb_a;
  real_T c5_u_a;
  real_T c5_ub_a;
  real_T c5_v_a;
  real_T c5_vb_a;
  real_T c5_w_a;
  real_T c5_wb_a;
  real_T c5_x_a;
  real_T c5_xb_a;
  real_T c5_y_a;
  real_T c5_yb_a;
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_f_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_loop_ub;
  c5_st.tls = chartInstance->c5_fEmlrtCtx;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 7U,
                    *chartInstance->c5_capture_distance);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 6U,
                    *chartInstance->c5_wp_cap_dist);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 5U, *chartInstance->c5_c_y);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 4U, *chartInstance->c5_b_x);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 3U,
                    *chartInstance->c5_sigma_dist);
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 2U, (real_T)
                      (*chartInstance->c5_f_logical_map)[c5_i]);
  }

  for (c5_i1 = 0; c5_i1 < 5; c5_i1++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 1U,
                      (*chartInstance->c5_waypointsy)[c5_i1]);
  }

  for (c5_i2 = 0; c5_i2 < 5; c5_i2++) {
    covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 0U,
                      (*chartInstance->c5_waypointsx)[c5_i2]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_JITTransitionAnimation[0] = 0U;
  chartInstance->c5_sfEvent = CALL_EVENT;
  for (c5_i3 = 0; c5_i3 < 5; c5_i3++) {
    c5_b_waypointsx[c5_i3] = (*chartInstance->c5_waypointsx)[c5_i3];
  }

  for (c5_i4 = 0; c5_i4 < 5; c5_i4++) {
    c5_b_waypointsy[c5_i4] = (*chartInstance->c5_waypointsy)[c5_i4];
  }

  for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
    chartInstance->c5_logical_map[c5_i5] = (*chartInstance->c5_f_logical_map)
      [c5_i5];
  }

  c5_c_x = *chartInstance->c5_b_x;
  c5_d_y = *chartInstance->c5_c_y;
  c5_b_wp_cap_dist = *chartInstance->c5_wp_cap_dist;
  c5_b_capture_distance = *chartInstance->c5_capture_distance;
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 4U, 0, 0);
  c5_array_s_Y7g3XIg0UrmNkIXtokcBk_C(chartInstance, &c5_path);
  if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 0,
                       !chartInstance->c5_path_x_not_empty) || covrtEmlCondEval
      (chartInstance->c5_covrtInstance, 4U, 0, 1,
       !chartInstance->c5_path_y_not_empty)) {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 0, true);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 0, true);
    c5_c_waypointsx[0] = c5_b_waypointsx[0];
    c5_c_waypointsx[1] = c5_b_waypointsy[0];
    c5_b_st.site = &c5_emlrtRSI;
    for (c5_i6 = 0; c5_i6 < 213200; c5_i6++) {
      chartInstance->c5_b_logical_map[c5_i6] = chartInstance->
        c5_logical_map[c5_i6];
    }

    c5_path_gen(chartInstance, &c5_b_st, chartInstance->c5_b_logical_map,
                c5_c_waypointsx, &c5_path);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &chartInstance->c5_path_x,
      &c5_emlrtRTEI, c5_path.x.size[0]);
    c5_loop_ub = c5_path.x.size[0] - 1;
    for (c5_i7 = 0; c5_i7 <= c5_loop_ub; c5_i7++) {
      chartInstance->c5_path_x.vector.data[c5_i7] = c5_path.x.vector.data[c5_i7];
    }

    chartInstance->c5_path_x_not_empty = true;
    chartInstance->c5_path_x_not_empty = (chartInstance->c5_path_x.size[0] != 0);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &chartInstance->c5_path_y,
      &c5_b_emlrtRTEI, c5_path.y.size[0]);
    c5_b_loop_ub = c5_path.y.size[0] - 1;
    for (c5_i10 = 0; c5_i10 <= c5_b_loop_ub; c5_i10++) {
      chartInstance->c5_path_y.vector.data[c5_i10] =
        c5_path.y.vector.data[c5_i10];
    }

    chartInstance->c5_path_y_not_empty = true;
    chartInstance->c5_path_y_not_empty = (chartInstance->c5_path_y.size[0] != 0);
  } else {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 0, false);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 0, false);
  }

  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 1,
                     !chartInstance->c5_timer_not_empty)) {
    chartInstance->c5_timer = 1.0;
    chartInstance->c5_timer_not_empty = true;
  }

  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 2,
                     !chartInstance->c5_future_wp_idx_not_empty)) {
    chartInstance->c5_future_wp_idx = 2.0;
    chartInstance->c5_future_wp_idx_not_empty = true;
  }

  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 3,
                     !chartInstance->c5_current_wp_idx_not_empty)) {
    chartInstance->c5_current_wp_idx = 1.0;
    chartInstance->c5_current_wp_idx_not_empty = true;
  }

  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 4,
                     !chartInstance->c5_wp_counter_not_empty)) {
    chartInstance->c5_wp_counter = 1.0;
    chartInstance->c5_wp_counter_not_empty = true;
  }

  c5_i8 = chartInstance->c5_path_x.size[0];
  if (c5_i8 < 0) {
    emlrtDynamicBoundsCheckR2012b(c5_i8, 0, MAX_int32_T, &c5_emlrtBCI, &c5_st);
  }

  c5_num_waypoints = (real_T)c5_i8;
  c5_i9 = chartInstance->c5_path_x.size[0];
  if (chartInstance->c5_current_wp_idx != (real_T)(int32_T)muDoubleScalarFloor
      (chartInstance->c5_current_wp_idx)) {
    emlrtIntegerCheckR2012b(chartInstance->c5_current_wp_idx, &c5_emlrtDCI,
      &c5_st);
  }

  c5_i11 = (int32_T)chartInstance->c5_current_wp_idx;
  if ((c5_i11 < 1) || (c5_i11 > c5_i9)) {
    emlrtDynamicBoundsCheckR2012b(c5_i11, 1, c5_i9, &c5_b_emlrtBCI, &c5_st);
  }

  c5_current_wp[0] = chartInstance->c5_path_x.vector.data[c5_i11 - 1];
  c5_i12 = chartInstance->c5_path_y.size[0];
  if (chartInstance->c5_current_wp_idx != (real_T)(int32_T)muDoubleScalarFloor
      (chartInstance->c5_current_wp_idx)) {
    emlrtIntegerCheckR2012b(chartInstance->c5_current_wp_idx, &c5_b_emlrtDCI,
      &c5_st);
  }

  c5_i13 = (int32_T)chartInstance->c5_current_wp_idx;
  if ((c5_i13 < 1) || (c5_i13 > c5_i12)) {
    emlrtDynamicBoundsCheckR2012b(c5_i13, 1, c5_i12, &c5_c_emlrtBCI, &c5_st);
  }

  c5_current_wp[1] = chartInstance->c5_path_y.vector.data[c5_i13 - 1];
  c5_i14 = chartInstance->c5_path_x.size[0];
  if (chartInstance->c5_future_wp_idx != (real_T)(int32_T)muDoubleScalarFloor
      (chartInstance->c5_future_wp_idx)) {
    emlrtIntegerCheckR2012b(chartInstance->c5_future_wp_idx, &c5_c_emlrtDCI,
      &c5_st);
  }

  c5_i15 = (int32_T)chartInstance->c5_future_wp_idx;
  if ((c5_i15 < 1) || (c5_i15 > c5_i14)) {
    emlrtDynamicBoundsCheckR2012b(c5_i15, 1, c5_i14, &c5_d_emlrtBCI, &c5_st);
  }

  c5_future_wp[0] = chartInstance->c5_path_x.vector.data[c5_i15 - 1];
  c5_i16 = chartInstance->c5_path_y.size[0];
  if (chartInstance->c5_future_wp_idx != (real_T)(int32_T)muDoubleScalarFloor
      (chartInstance->c5_future_wp_idx)) {
    emlrtIntegerCheckR2012b(chartInstance->c5_future_wp_idx, &c5_d_emlrtDCI,
      &c5_st);
  }

  c5_i17 = (int32_T)chartInstance->c5_future_wp_idx;
  if ((c5_i17 < 1) || (c5_i17 > c5_i16)) {
    emlrtDynamicBoundsCheckR2012b(c5_i17, 1, c5_i16, &c5_e_emlrtBCI, &c5_st);
  }

  c5_future_wp[1] = chartInstance->c5_path_y.vector.data[c5_i17 - 1];
  c5_b_st.site = &c5_b_emlrtRSI;
  c5_b_a = c5_future_wp[1] - c5_d_y;
  c5_c_a = c5_b_a;
  c5_d_a = c5_c_a;
  c5_e_a = c5_d_a;
  c5_f_a = c5_e_a;
  c5_c_c = c5_f_a * c5_f_a;
  c5_b_st.site = &c5_b_emlrtRSI;
  c5_g_a = c5_future_wp[0] - c5_c_x;
  c5_h_a = c5_g_a;
  c5_i_a = c5_h_a;
  c5_j_a = c5_i_a;
  c5_k_a = c5_j_a;
  c5_d_c = c5_k_a * c5_k_a;
  c5_dist_to_future = c5_c_c + c5_d_c;
  c5_b_st.site = &c5_b_emlrtRSI;
  c5_b_sqrt(chartInstance, &c5_b_st, &c5_dist_to_future);
  c5_b_st.site = &c5_c_emlrtRSI;
  c5_l_a = c5_future_wp[1] - c5_current_wp[1];
  c5_m_a = c5_l_a;
  c5_n_a = c5_m_a;
  c5_o_a = c5_n_a;
  c5_p_a = c5_o_a;
  c5_e_c = c5_p_a * c5_p_a;
  c5_b_st.site = &c5_c_emlrtRSI;
  c5_q_a = c5_future_wp[0] - c5_current_wp[0];
  c5_r_a = c5_q_a;
  c5_s_a = c5_r_a;
  c5_t_a = c5_s_a;
  c5_u_a = c5_t_a;
  c5_f_c = c5_u_a * c5_u_a;
  c5_d = c5_e_c + c5_f_c;
  c5_b_st.site = &c5_c_emlrtRSI;
  c5_b_sqrt(chartInstance, &c5_b_st, &c5_d);
  c5_b_st.site = &c5_d_emlrtRSI;
  c5_v_a = c5_current_wp[1] - c5_d_y;
  c5_w_a = c5_v_a;
  c5_x_a = c5_w_a;
  c5_y_a = c5_x_a;
  c5_ab_a = c5_y_a;
  c5_g_c = c5_ab_a * c5_ab_a;
  c5_b_st.site = &c5_d_emlrtRSI;
  c5_bb_a = c5_current_wp[0] - c5_c_x;
  c5_cb_a = c5_bb_a;
  c5_db_a = c5_cb_a;
  c5_eb_a = c5_db_a;
  c5_fb_a = c5_eb_a;
  c5_h_c = c5_fb_a * c5_fb_a;
  c5_d1 = c5_g_c + c5_h_c;
  c5_b_st.site = &c5_d_emlrtRSI;
  c5_b_sqrt(chartInstance, &c5_b_st, &c5_d1);
  c5_e_y = c5_future_wp[1] - c5_d_y;
  c5_d_x = c5_future_wp[0] - c5_c_x;
  c5_gb_a = c5_e_y;
  c5_b_b = c5_d_x;
  c5_f_y = c5_gb_a;
  c5_e_x = c5_b_b;
  c5_b_target_th = muDoubleScalarAtan2(c5_f_y, c5_e_x);
  if (covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 2,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c5_covrtInstance, 4U, 0U, 0U,
                        c5_dist_to_future, c5_b_capture_distance, -1, 2U,
                        c5_dist_to_future < c5_b_capture_distance)) &&
      covrtEmlCondEval(chartInstance->c5_covrtInstance, 4U, 0, 3,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c5_covrtInstance, 4U, 0U, 1U,
                        chartInstance->c5_future_wp_idx, c5_num_waypoints, -1,
                        2U, chartInstance->c5_future_wp_idx < c5_num_waypoints)))
  {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 1, true);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 5, true);
    chartInstance->c5_current_wp_idx = chartInstance->c5_future_wp_idx;
    chartInstance->c5_future_wp_idx++;
  } else {
    covrtEmlMcdcEval(chartInstance->c5_covrtInstance, 4U, 0, 1, false);
    covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 5, false);
  }

  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 6,
                     covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance,
        4U, 0U, 2U, c5_dist_to_future, c5_b_capture_distance, -1, 2U,
        c5_dist_to_future < c5_b_capture_distance))) {
    c5_b_distance_from_wp = c5_dist_to_future;
  } else {
    c5_b_distance_from_wp = c5_b_capture_distance;
  }

  c5_i18 = chartInstance->c5_path_x.size[0];
  if (c5_num_waypoints != (real_T)(int32_T)muDoubleScalarFloor(c5_num_waypoints))
  {
    emlrtIntegerCheckR2012b(c5_num_waypoints, &c5_e_emlrtDCI, &c5_st);
  }

  c5_i19 = (int32_T)c5_num_waypoints;
  if ((c5_i19 < 1) || (c5_i19 > c5_i18)) {
    emlrtDynamicBoundsCheckR2012b(c5_i19, 1, c5_i18, &c5_f_emlrtBCI, &c5_st);
  }

  c5_current_wp[0] = chartInstance->c5_path_x.vector.data[c5_i19 - 1];
  c5_i20 = chartInstance->c5_path_y.size[0];
  if (c5_num_waypoints != (real_T)(int32_T)muDoubleScalarFloor(c5_num_waypoints))
  {
    emlrtIntegerCheckR2012b(c5_num_waypoints, &c5_f_emlrtDCI, &c5_st);
  }

  c5_i21 = (int32_T)c5_num_waypoints;
  if ((c5_i21 < 1) || (c5_i21 > c5_i20)) {
    emlrtDynamicBoundsCheckR2012b(c5_i21, 1, c5_i20, &c5_g_emlrtBCI, &c5_st);
  }

  c5_current_wp[1] = chartInstance->c5_path_y.vector.data[c5_i21 - 1];
  c5_future_wp[0] = c5_b_waypointsx[4];
  c5_future_wp[1] = c5_b_waypointsy[4];
  c5_b_st.site = &c5_e_emlrtRSI;
  c5_hb_a = c5_current_wp[1] - c5_d_y;
  c5_ib_a = c5_hb_a;
  c5_jb_a = c5_ib_a;
  c5_kb_a = c5_jb_a;
  c5_lb_a = c5_kb_a;
  c5_i_c = c5_lb_a * c5_lb_a;
  c5_b_st.site = &c5_e_emlrtRSI;
  c5_mb_a = c5_current_wp[0] - c5_c_x;
  c5_nb_a = c5_mb_a;
  c5_ob_a = c5_nb_a;
  c5_pb_a = c5_ob_a;
  c5_qb_a = c5_pb_a;
  c5_j_c = c5_qb_a * c5_qb_a;
  c5_dist_to_path_last = c5_i_c + c5_j_c;
  c5_b_st.site = &c5_e_emlrtRSI;
  c5_b_sqrt(chartInstance, &c5_b_st, &c5_dist_to_path_last);
  c5_b_st.site = &c5_f_emlrtRSI;
  c5_rb_a = c5_future_wp[1] - c5_d_y;
  c5_sb_a = c5_rb_a;
  c5_tb_a = c5_sb_a;
  c5_ub_a = c5_tb_a;
  c5_vb_a = c5_ub_a;
  c5_k_c = c5_vb_a * c5_vb_a;
  c5_b_st.site = &c5_f_emlrtRSI;
  c5_wb_a = c5_future_wp[0] - c5_c_x;
  c5_xb_a = c5_wb_a;
  c5_yb_a = c5_xb_a;
  c5_ac_a = c5_yb_a;
  c5_bc_a = c5_ac_a;
  c5_l_c = c5_bc_a * c5_bc_a;
  c5_dist_to_last = c5_k_c + c5_l_c;
  c5_b_st.site = &c5_f_emlrtRSI;
  c5_b_sqrt(chartInstance, &c5_b_st, &c5_dist_to_last);
  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 7,
                     covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance,
        4U, 0U, 3U, c5_dist_to_path_last, c5_b_wp_cap_dist * 2.0, -1, 2U,
        c5_dist_to_path_last < c5_b_wp_cap_dist * 2.0))) {
    chartInstance->c5_wp_counter++;
    c5_f_x = c5_c_x;
    c5_g_x = c5_f_x;
    c5_g_y = c5_g_x;
    c5_g_y = muDoubleScalarRound(c5_g_y);
    c5_i_x = c5_d_y;
    c5_k_x = c5_i_x;
    c5_i_y = c5_k_x;
    c5_i_y = muDoubleScalarRound(c5_i_y);
    c5_j_y[0] = c5_g_y;
    c5_j_y[1] = c5_i_y;
    if (chartInstance->c5_wp_counter != (real_T)(int32_T)muDoubleScalarFloor
        (chartInstance->c5_wp_counter)) {
      emlrtIntegerCheckR2012b(chartInstance->c5_wp_counter, &c5_g_emlrtDCI,
        &c5_st);
    }

    c5_i22 = (int32_T)chartInstance->c5_wp_counter;
    if ((c5_i22 < 1) || (c5_i22 > 5)) {
      emlrtDynamicBoundsCheckR2012b(c5_i22, 1, 5, &c5_h_emlrtBCI, &c5_st);
    }

    c5_d_waypointsx[0] = c5_b_waypointsx[c5_i22 - 1];
    if (chartInstance->c5_wp_counter != (real_T)(int32_T)muDoubleScalarFloor
        (chartInstance->c5_wp_counter)) {
      emlrtIntegerCheckR2012b(chartInstance->c5_wp_counter, &c5_h_emlrtDCI,
        &c5_st);
    }

    c5_i24 = (int32_T)chartInstance->c5_wp_counter;
    if ((c5_i24 < 1) || (c5_i24 > 5)) {
      emlrtDynamicBoundsCheckR2012b(c5_i24, 1, 5, &c5_i_emlrtBCI, &c5_st);
    }

    c5_d_waypointsx[1] = c5_b_waypointsy[c5_i24 - 1];
    c5_b_st.site = &c5_g_emlrtRSI;
    for (c5_i26 = 0; c5_i26 < 213200; c5_i26++) {
      chartInstance->c5_c_logical_map[c5_i26] = chartInstance->
        c5_logical_map[c5_i26];
    }

    c5_b_path_gen(chartInstance, &c5_b_st, chartInstance->c5_c_logical_map,
                  c5_j_y, c5_d_waypointsx, &c5_path);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &chartInstance->c5_path_x,
      &c5_c_emlrtRTEI, c5_path.x.size[0]);
    c5_c_loop_ub = c5_path.x.size[0] - 1;
    for (c5_i27 = 0; c5_i27 <= c5_c_loop_ub; c5_i27++) {
      chartInstance->c5_path_x.vector.data[c5_i27] =
        c5_path.x.vector.data[c5_i27];
    }

    chartInstance->c5_path_x_not_empty = (chartInstance->c5_path_x.size[0] != 0);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &chartInstance->c5_path_y,
      &c5_d_emlrtRTEI, c5_path.y.size[0]);
    c5_e_loop_ub = c5_path.y.size[0] - 1;
    for (c5_i29 = 0; c5_i29 <= c5_e_loop_ub; c5_i29++) {
      chartInstance->c5_path_y.vector.data[c5_i29] =
        c5_path.y.vector.data[c5_i29];
    }

    chartInstance->c5_path_y_not_empty = (chartInstance->c5_path_y.size[0] != 0);
    chartInstance->c5_current_wp_idx = 1.0;
    chartInstance->c5_future_wp_idx = 2.0;
    chartInstance->c5_timer = 1.0;
  }

  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 8,
                     covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance,
        4U, 0U, 4U, c5_dist_to_last, c5_b_wp_cap_dist, -1, 2U, c5_dist_to_last <
        c5_b_wp_cap_dist))) {
    c5_b_stop = 1.0;
  } else {
    c5_b_stop = 0.0;
  }

  if (covrtEmlIfEval(chartInstance->c5_covrtInstance, 4U, 0, 9,
                     covrtRelationalopUpdateFcn(chartInstance->c5_covrtInstance,
        4U, 0U, 5U, c5_b_distance_from_wp, 2.0, -1, 4U, c5_b_distance_from_wp >
        2.0))) {
    c5_h_x = c5_c_x;
    c5_j_x = c5_h_x;
    c5_h_y = c5_j_x;
    c5_h_y = muDoubleScalarRound(c5_h_y);
    c5_l_x = c5_d_y;
    c5_m_x = c5_l_x;
    c5_k_y = c5_m_x;
    c5_k_y = muDoubleScalarRound(c5_k_y);
    c5_l_y[0] = c5_h_y;
    c5_l_y[1] = c5_k_y;
    if (chartInstance->c5_wp_counter != (real_T)(int32_T)muDoubleScalarFloor
        (chartInstance->c5_wp_counter)) {
      emlrtIntegerCheckR2012b(chartInstance->c5_wp_counter, &c5_i_emlrtDCI,
        &c5_st);
    }

    c5_i23 = (int32_T)chartInstance->c5_wp_counter;
    if ((c5_i23 < 1) || (c5_i23 > 5)) {
      emlrtDynamicBoundsCheckR2012b(c5_i23, 1, 5, &c5_j_emlrtBCI, &c5_st);
    }

    c5_e_waypointsx[0] = c5_b_waypointsx[c5_i23 - 1];
    if (chartInstance->c5_wp_counter != (real_T)(int32_T)muDoubleScalarFloor
        (chartInstance->c5_wp_counter)) {
      emlrtIntegerCheckR2012b(chartInstance->c5_wp_counter, &c5_j_emlrtDCI,
        &c5_st);
    }

    c5_i25 = (int32_T)chartInstance->c5_wp_counter;
    if ((c5_i25 < 1) || (c5_i25 > 5)) {
      emlrtDynamicBoundsCheckR2012b(c5_i25, 1, 5, &c5_k_emlrtBCI, &c5_st);
    }

    c5_e_waypointsx[1] = c5_b_waypointsy[c5_i25 - 1];
    c5_b_st.site = &c5_h_emlrtRSI;
    c5_b_path_gen(chartInstance, &c5_b_st, chartInstance->c5_logical_map, c5_l_y,
                  c5_e_waypointsx, &c5_path);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &chartInstance->c5_path_x,
      &c5_e_emlrtRTEI, c5_path.x.size[0]);
    c5_d_loop_ub = c5_path.x.size[0] - 1;
    for (c5_i28 = 0; c5_i28 <= c5_d_loop_ub; c5_i28++) {
      chartInstance->c5_path_x.vector.data[c5_i28] =
        c5_path.x.vector.data[c5_i28];
    }

    chartInstance->c5_path_x_not_empty = (chartInstance->c5_path_x.size[0] != 0);
    c5_array_real_T_SetSize(chartInstance, &c5_st, &chartInstance->c5_path_y,
      &c5_f_emlrtRTEI, c5_path.y.size[0]);
    c5_f_loop_ub = c5_path.y.size[0] - 1;
    for (c5_i30 = 0; c5_i30 <= c5_f_loop_ub; c5_i30++) {
      chartInstance->c5_path_y.vector.data[c5_i30] =
        c5_path.y.vector.data[c5_i30];
    }

    chartInstance->c5_path_y_not_empty = (chartInstance->c5_path_y.size[0] != 0);
    chartInstance->c5_current_wp_idx = 1.0;
    chartInstance->c5_future_wp_idx = 2.0;
    c5_m_y = NULL;
    sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 2),
                  false);
    c5_b_st.site = &c5_i_emlrtRSI;
    c5_hold(chartInstance, &c5_b_st, c5_m_y);
    c5_n_y = NULL;
    sf_mex_assign(&c5_n_y, sf_mex_create("y",
      chartInstance->c5_path_x.vector.data, 0, 0U, 1, 0U, 1,
      chartInstance->c5_path_x.size[0]), false);
    c5_o_y = NULL;
    sf_mex_assign(&c5_o_y, sf_mex_create("y",
      chartInstance->c5_path_y.vector.data, 0, 0U, 1, 0U, 1,
      chartInstance->c5_path_y.size[0]), false);
    c5_p_y = NULL;
    sf_mex_assign(&c5_p_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 3),
                  false);
    c5_b_st.site = &c5_j_emlrtRSI;
    c5_plot(chartInstance, &c5_b_st, c5_n_y, c5_o_y, c5_p_y);
    chartInstance->c5_timer = 1.0;
  }

  c5_array_s_Y7g3XIg0UrmNkIXtokcBk_D(chartInstance, &c5_path);
  chartInstance->c5_timer++;
  *chartInstance->c5_distance_from_wp = c5_b_distance_from_wp;
  *chartInstance->c5_target_th = c5_b_target_th;
  *chartInstance->c5_stop = c5_b_stop;
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 8U,
                    *chartInstance->c5_distance_from_wp);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 9U,
                    *chartInstance->c5_target_th);
  covrtSigUpdateFcn(chartInstance->c5_covrtInstance, 10U,
                    *chartInstance->c5_stop);
}

static void ext_mode_exec_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_update_jit_animation_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_do_animation_call_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_st;
  c5_st = NULL;
  c5_st = NULL;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_createcellmatrix(9, 1), false);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", chartInstance->c5_distance_from_wp,
    0, 0U, 0, 0U, 0), false);
  sf_mex_setcell(c5_d_y, 0, c5_e_y);
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", chartInstance->c5_stop, 0, 0U, 0, 0U,
    0), false);
  sf_mex_setcell(c5_d_y, 1, c5_f_y);
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", chartInstance->c5_target_th, 0, 0U,
    0, 0U, 0), false);
  sf_mex_setcell(c5_d_y, 2, c5_g_y);
  c5_h_y = NULL;
  if (!chartInstance->c5_current_wp_idx_not_empty) {
    sf_mex_assign(&c5_h_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_h_y, sf_mex_create("y", &chartInstance->c5_current_wp_idx,
      0, 0U, 0, 0U, 0), false);
  }

  sf_mex_setcell(c5_d_y, 3, c5_h_y);
  c5_i_y = NULL;
  if (!chartInstance->c5_current_wp_idx_not_empty) {
    sf_mex_assign(&c5_i_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_i_y, sf_mex_create("y", &chartInstance->c5_future_wp_idx,
      0, 0U, 0, 0U, 0), false);
  }

  sf_mex_setcell(c5_d_y, 4, c5_i_y);
  c5_j_y = NULL;
  if (!chartInstance->c5_path_x_not_empty) {
    sf_mex_assign(&c5_j_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_j_y, sf_mex_create("y",
      chartInstance->c5_path_x.vector.data, 0, 0U, 1, 0U, 1,
      chartInstance->c5_path_x.size[0]), false);
  }

  sf_mex_setcell(c5_d_y, 5, c5_j_y);
  c5_k_y = NULL;
  if (!chartInstance->c5_path_x_not_empty) {
    sf_mex_assign(&c5_k_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_k_y, sf_mex_create("y",
      chartInstance->c5_path_y.vector.data, 0, 0U, 1, 0U, 1,
      chartInstance->c5_path_y.size[0]), false);
  }

  sf_mex_setcell(c5_d_y, 6, c5_k_y);
  c5_l_y = NULL;
  if (!chartInstance->c5_current_wp_idx_not_empty) {
    sf_mex_assign(&c5_l_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_l_y, sf_mex_create("y", &chartInstance->c5_timer, 0, 0U, 0,
      0U, 0), false);
  }

  sf_mex_setcell(c5_d_y, 7, c5_l_y);
  c5_m_y = NULL;
  if (!chartInstance->c5_current_wp_idx_not_empty) {
    sf_mex_assign(&c5_m_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c5_m_y, sf_mex_create("y", &chartInstance->c5_wp_counter, 0,
      0U, 0, 0U, 0), false);
  }

  sf_mex_setcell(c5_d_y, 8, c5_m_y);
  sf_mex_assign(&c5_st, c5_d_y, false);
  return c5_st;
}

static void set_sim_state_c5_sl_groundvehicleDynamics
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const mxArray
   *c5_st)
{
  c5_coder_array_real_T c5_r;
  c5_coder_array_real_T c5_r1;
  emlrtStack c5_b_st = { NULL,         /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c5_u;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_loop_ub;
  c5_b_st.tls = chartInstance->c5_fEmlrtCtx;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *chartInstance->c5_distance_from_wp = c5_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 0)), "distance_from_wp");
  *chartInstance->c5_stop = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 1)), "stop");
  *chartInstance->c5_target_th = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 2)), "target_th");
  chartInstance->c5_current_wp_idx = c5_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 3)), "current_wp_idx",
    &chartInstance->c5_current_wp_idx_not_empty);
  chartInstance->c5_future_wp_idx = c5_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_u, 4)), "future_wp_idx",
    &chartInstance->c5_future_wp_idx_not_empty);
  c5_array_real_T_Constructor(chartInstance, &c5_r);
  c5_g_emlrt_marshallIn(chartInstance, &c5_b_st, sf_mex_dup(sf_mex_getcell(c5_u,
    5)), "path_x", &chartInstance->c5_path_x_not_empty, &c5_r);
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &chartInstance->c5_path_x,
    (emlrtRTEInfo *)NULL, c5_r.size[0]);
  c5_loop_ub = c5_r.size[0] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    chartInstance->c5_path_x.vector.data[c5_i] = c5_r.vector.data[c5_i];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_r);
  c5_array_real_T_Constructor(chartInstance, &c5_r1);
  c5_g_emlrt_marshallIn(chartInstance, &c5_b_st, sf_mex_dup(sf_mex_getcell(c5_u,
    6)), "path_y", &chartInstance->c5_path_y_not_empty, &c5_r1);
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &chartInstance->c5_path_y,
    (emlrtRTEInfo *)NULL, c5_r1.size[0]);
  c5_b_loop_ub = c5_r1.size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_b_loop_ub; c5_i1++) {
    chartInstance->c5_path_y.vector.data[c5_i1] = c5_r1.vector.data[c5_i1];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_r1);
  chartInstance->c5_timer = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 7)), "timer", &chartInstance->c5_timer_not_empty);
  chartInstance->c5_wp_counter = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_u, 8)), "wp_counter",
    &chartInstance->c5_wp_counter_not_empty);
  sf_mex_destroy(&c5_u);
  sf_mex_destroy(&c5_st);
}

static void c5_path_gen(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_g_logical_map[213200],
  real_T c5_goal[2], c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_out_path)
{
  c5_coder_array_real_T_2D c5_grid_path;
  c5_coder_array_real_T_2D c5_path;
  emlrtStack c5_st;
  real_T c5_b_goal[2];
  real_T c5_path_goal[2];
  real_T c5_path_start[2];
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 14U, 0, 0);
  c5_st.site = &c5_m_emlrtRSI;
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    chartInstance->c5_e_logical_map[c5_i] = c5_g_logical_map[c5_i];
  }

  c5_binaryOccupancyMap_binaryOccupancyMap(chartInstance,
    &chartInstance->c5_b_occupancy_map, chartInstance->c5_e_logical_map);
  c5_st.site = &c5_n_emlrtRSI;
  c5_binaryOccupancyMap_inflate(chartInstance, &c5_st,
    &chartInstance->c5_b_occupancy_map);
  c5_st.site = &c5_o_emlrtRSI;
  c5_MapInterface_world2grid(chartInstance, &chartInstance->c5_b_occupancy_map,
    c5_path_start);
  c5_b_goal[0] = c5_goal[0];
  c5_b_goal[1] = c5_goal[1];
  c5_st.site = &c5_p_emlrtRSI;
  c5_b_MapInterface_world2grid(chartInstance, &chartInstance->c5_b_occupancy_map,
    c5_b_goal, c5_path_goal);
  c5_st.site = &c5_q_emlrtRSI;
  c5_plannerAStarGrid_plannerAStarGrid(chartInstance, &c5_st,
    &chartInstance->c5_b_planner, &chartInstance->c5_b_occupancy_map);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_grid_path);
  c5_st.site = &c5_r_emlrtRSI;
  c5_plannerAStarGrid_plan(chartInstance, &c5_st, &chartInstance->c5_b_planner,
    c5_path_start, c5_path_goal, &c5_grid_path);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_path);
  c5_st.site = &c5_s_emlrtRSI;
  c5_MapInterface_grid2world(chartInstance, &c5_st,
    &chartInstance->c5_b_occupancy_map, &c5_grid_path, &c5_path);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_grid_path);
  c5_array_real_T_SetSize(chartInstance, c5_sp, &c5_out_path->x, &c5_g_emlrtRTEI,
    c5_path.size[0]);
  c5_loop_ub = c5_path.size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_out_path->x.vector.data[c5_i1] = c5_path.vector.data[c5_i1];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, &c5_out_path->y, &c5_h_emlrtRTEI,
    c5_path.size[0]);
  c5_b_loop_ub = c5_path.size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
    c5_out_path->y.vector.data[c5_i2] = c5_path.vector.data[c5_i2 +
      c5_path.size[0]];
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_path);
}

static c5_binaryOccupancyMap *c5_binaryOccupancyMap_binaryOccupancyMap
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, boolean_T c5_b_varargin_1[213200])
{
  static char_T c5_b_cv[7] = { 'l', 'o', 'g', 'i', 'c', 'a', 'l' };

  c5_binaryOccupancyMap *c5_b_obj;
  c5_binaryOccupancyMap *c5_c_obj;
  c5_binaryOccupancyMap *c5_d_obj;
  c5_binaryOccupancyMap *c5_e_obj;
  c5_binaryOccupancyMap *c5_f_obj;
  c5_binaryOccupancyMap *c5_g_obj;
  c5_binaryOccupancyMap *c5_h_obj;
  c5_binaryOccupancyMap *c5_n_obj;
  c5_binaryOccupancyMap *c5_o_obj;
  c5_binaryOccupancyMap *c5_p_obj;
  c5_binaryOccupancyMap *c5_q_obj;
  c5_binaryOccupancyMap *c5_r_obj;
  c5_binaryOccupancyMap *c5_s_obj;
  c5_binaryOccupancyMap *c5_this;
  c5_matlabshared_autonomous_internal_CircularBuffer *c5_c_this;
  c5_matlabshared_autonomous_internal_CircularBuffer *c5_k_obj;
  c5_matlabshared_autonomous_internal_CircularBuffer *c5_l_obj;
  c5_matlabshared_autonomous_internal_CircularBuffer *c5_m_obj;
  c5_matlabshared_autonomous_internal_CircularBuffer *c5_t_obj;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_b_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_b_this;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_c_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_d_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_i_obj;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_j_obj;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_r;
  real_T c5_d_y[2];
  real_T c5_c_x;
  real_T c5_d_x;
  int32_T c5_b_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_k;
  boolean_T c5_b_a;
  boolean_T c5_constVal;
  c5_b_obj = c5_obj;
  c5_c_obj = c5_b_obj;
  c5_b_obj = c5_c_obj;
  c5_b_obj->HasParent = false;
  c5_d_obj = c5_b_obj;
  c5_b_obj = c5_d_obj;
  c5_e_obj = c5_b_obj;
  c5_b_obj = c5_e_obj;
  c5_this = c5_b_obj;
  c5_b_obj = c5_this;
  c5_b_obj->UseGPU = false;
  c5_f_obj = c5_b_obj;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_f_obj->SharedProperties.GridOriginInLocal[c5_i] = 0.0;
  }

  c5_g_obj = c5_b_obj;
  c5_h_obj = c5_g_obj;
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_h_obj->SharedProperties.LocalOriginInWorld[c5_i1] = 0.0;
  }

  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    c5_d_y[c5_i2] = -0.5;
  }

  for (c5_k = 0; c5_k < 2; c5_k++) {
    c5_b_k = c5_k;
    c5_c_x = c5_d_y[c5_b_k];
    c5_d_x = c5_c_x;
    c5_d_x = muDoubleScalarCeil(c5_d_x);
    c5_d_y[c5_b_k] = c5_d_x;
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_h_obj->SharedProperties.LocalOriginInWorldInternal[c5_i3] = c5_d_y[c5_i3]
      / 10.0;
  }

  c5_i_obj = &c5_b_obj->_pobj0;
  c5_index = c5_i_obj;
  c5_j_obj = c5_index;
  c5_index = c5_j_obj;
  c5_b_this = c5_index;
  c5_index = c5_b_this;
  for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
    c5_index->Head[c5_i4] = 1.0;
  }

  c5_index->DropEntireMap = false;
  for (c5_i5 = 0; c5_i5 < 4; c5_i5++) {
    c5_index->NewRegions[c5_i5] = 0.0;
  }

  for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
    c5_index->DropTwoRegions[c5_i6] = false;
  }

  c5_b_obj->DefaultValueInternal = false;
  c5_k_obj = &c5_b_obj->Buffer;
  c5_b_index = c5_index;
  c5_constVal = c5_b_obj->DefaultValueInternal;
  c5_l_obj = c5_k_obj;
  c5_b_a = c5_constVal;
  for (c5_i7 = 0; c5_i7 < 213200; c5_i7++) {
    chartInstance->c5_c_mat[c5_i7] = c5_b_a;
  }

  c5_m_obj = c5_l_obj;
  c5_l_obj = c5_m_obj;
  c5_c_this = c5_l_obj;
  c5_l_obj = c5_c_this;
  c5_l_obj->Index = c5_b_index;
  c5_l_obj->ConstVal = c5_constVal;
  for (c5_i8 = 0; c5_i8 < 7; c5_i8++) {
    c5_l_obj->DataType[c5_i8] = c5_b_cv[c5_i8];
  }

  for (c5_i9 = 0; c5_i9 < 213200; c5_i9++) {
    c5_l_obj->Buffer[c5_i9] = chartInstance->c5_c_mat[c5_i9];
  }

  c5_n_obj = c5_b_obj;
  c5_o_obj = c5_n_obj;
  c5_p_obj = c5_o_obj;
  c5_q_obj = c5_p_obj;
  for (c5_i10 = 0; c5_i10 < 213200; c5_i10++) {
    c5_q_obj->Buffer.Buffer[c5_i10] = c5_b_varargin_1[c5_i10];
  }

  c5_r_obj = c5_q_obj;
  c5_r = c5_r_obj->Buffer.Index;
  for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
    c5_r->Head[c5_i11] = 1.0;
  }

  c5_s_obj = c5_q_obj;
  c5_c_index = c5_r;
  c5_t_obj = &c5_s_obj->Buffer;
  c5_d_index = c5_c_index;
  c5_t_obj->Index = c5_d_index;
  return c5_b_obj;
}

static void c5_binaryOccupancyMap_inflate
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj)
{
  static real_T c5_colIdx[121] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 3.0,
    3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0,
    4.0, 4.0, 4.0, 4.0, 4.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 7.0, 7.0, 7.0,
    7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0, 8.0,
    8.0, 8.0, 8.0, 8.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0,
    10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 11.0, 11.0,
    11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0, 11.0 };

  static real_T c5_rowIdx[121] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
    10.0, 11.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0,
    2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0, 2.0, 3.0, 4.0, 5.0,
    6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
    10.0, 11.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0,
    2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0, 2.0, 3.0, 4.0, 5.0,
    6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
    10.0, 11.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 1.0,
    2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 };

  static char_T c5_b_cv1[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u',
    'b', '2', 'i', 'n', 'd', ':', 'S', 'u', 'b', 's', 'c', 'r', 'i', 'p', 't',
    'V', 'e', 'c', 't', 'o', 'r', 'S', 'i', 'z', 'e' };

  static char_T c5_b_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b',
    '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  static boolean_T c5_se[121] = { false, false, false, true, true, true, true,
    true, false, false, false, false, true, true, true, true, true, true, true,
    true, true, false, false, true, true, true, true, true, true, true, true,
    true, false, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, false, true, true, true, true, true,
    true, true, true, true, false, false, true, true, true, true, true, true,
    true, true, true, false, false, false, false, true, true, true, true, true,
    false, false, false };

  c5_binaryOccupancyMap *c5_b_obj;
  c5_binaryOccupancyMap *c5_c_obj;
  c5_binaryOccupancyMap *c5_d_obj;
  c5_matlabshared_autonomous_internal_CircularBuffer *c5_e_obj;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_b_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_r;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_e_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  real_T c5_index_data[121];
  real_T c5_shiftedColIdx[121];
  real_T c5_shiftedRowIdx[121];
  real_T c5_varargin_2_data[121];
  real_T c5_b_varargin_1[2];
  real_T c5_b_varargin_2[2];
  real_T c5_b_j;
  real_T c5_b_k;
  real_T c5_c_i;
  real_T c5_c_j;
  real_T c5_d_i;
  real_T c5_x1;
  real_T c5_x2;
  int32_T c5_b_data[121];
  int32_T c5_idx_data[121];
  int32_T c5_b_size[2];
  int32_T c5_b_tmp_size[2];
  int32_T c5_idx_size[2];
  int32_T c5_index_size[2];
  int32_T c5_tmp_size[2];
  int32_T c5_varargin_2_size[2];
  int32_T c5_subse_size[1];
  int32_T c5_b_end;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_b_partialTrueCount;
  int32_T c5_b_trueCount;
  int32_T c5_c_end;
  int32_T c5_c_loop_ub;
  int32_T c5_c_partialTrueCount;
  int32_T c5_c_trueCount;
  int32_T c5_d_loop_ub;
  int32_T c5_e_i;
  int32_T c5_e_loop_ub;
  int32_T c5_end;
  int32_T c5_f_i;
  int32_T c5_f_loop_ub;
  int32_T c5_g_i;
  int32_T c5_g_loop_ub;
  int32_T c5_h_i;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_i;
  int32_T c5_i_loop_ub;
  int32_T c5_j;
  int32_T c5_j_i;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_loop_ub;
  int32_T c5_partialTrueCount;
  int32_T c5_trueCount;
  boolean_T c5_b_tmp_data[121];
  boolean_T c5_bv[121];
  boolean_T c5_idx[121];
  boolean_T c5_subse_data[121];
  boolean_T c5_tmp_data[121];
  boolean_T c5_b_p;
  boolean_T c5_c_p;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_e_st.prev = &c5_d_st;
  c5_e_st.tls = c5_d_st.tls;
  c5_st.site = &c5_nb_emlrtRSI;
  c5_b_st.site = &c5_mb_emlrtRSI;
  c5_MapLayer_getValueAllImpl(chartInstance, &c5_b_st, c5_obj,
    chartInstance->c5_inflatedGrid);
  c5_b_st.site = &c5_wb_emlrtRSI;
  c5_c_st.site = &c5_xb_emlrtRSI;
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    chartInstance->c5_b_map[c5_i] = chartInstance->c5_inflatedGrid[c5_i];
  }

  for (c5_b_i = 0; c5_b_i < 410; c5_b_i++) {
    c5_c_i = (real_T)c5_b_i + 1.0;
    for (c5_j = 0; c5_j < 520; c5_j++) {
      c5_b_j = (real_T)c5_j + 1.0;
      if (chartInstance->c5_b_map[((int32_T)c5_c_i + 410 * ((int32_T)c5_b_j - 1))
          - 1]) {
        c5_d_i = c5_c_i - 6.0;
        for (c5_i2 = 0; c5_i2 < 121; c5_i2++) {
          c5_shiftedRowIdx[c5_i2] = c5_d_i + c5_rowIdx[c5_i2];
        }

        c5_c_j = c5_b_j - 6.0;
        for (c5_i4 = 0; c5_i4 < 121; c5_i4++) {
          c5_shiftedColIdx[c5_i4] = c5_c_j + c5_colIdx[c5_i4];
        }

        for (c5_i5 = 0; c5_i5 < 121; c5_i5++) {
          c5_bv[c5_i5] = (c5_shiftedColIdx[c5_i5] > 0.0);
        }

        for (c5_i6 = 0; c5_i6 < 121; c5_i6++) {
          c5_idx[c5_i6] = ((c5_shiftedRowIdx[c5_i6] > 0.0) && c5_bv[c5_i6]);
        }

        for (c5_i7 = 0; c5_i7 < 121; c5_i7++) {
          c5_bv[c5_i7] = (c5_shiftedRowIdx[c5_i7] <= 410.0);
        }

        for (c5_i8 = 0; c5_i8 < 121; c5_i8++) {
          c5_idx[c5_i8] = (c5_idx[c5_i8] && c5_bv[c5_i8]);
        }

        for (c5_i9 = 0; c5_i9 < 121; c5_i9++) {
          c5_bv[c5_i9] = (c5_shiftedColIdx[c5_i9] <= 520.0);
        }

        for (c5_i10 = 0; c5_i10 < 121; c5_i10++) {
          c5_idx[c5_i10] = (c5_idx[c5_i10] && c5_bv[c5_i10]);
        }

        c5_d_st.site = &c5_yb_emlrtRSI;
        c5_end = 121;
        c5_trueCount = 0;
        for (c5_e_i = 0; c5_e_i < c5_end; c5_e_i++) {
          if (c5_idx[c5_e_i]) {
            c5_trueCount++;
          }
        }

        c5_index_size[0] = 1;
        c5_index_size[1] = c5_trueCount;
        c5_partialTrueCount = 0;
        for (c5_f_i = 0; c5_f_i < c5_end; c5_f_i++) {
          if (c5_idx[c5_f_i]) {
            c5_index_data[c5_partialTrueCount] = c5_shiftedRowIdx[c5_f_i];
            c5_partialTrueCount++;
          }
        }

        c5_b_end = 121;
        c5_b_trueCount = 0;
        for (c5_g_i = 0; c5_g_i < c5_b_end; c5_g_i++) {
          if (c5_idx[c5_g_i]) {
            c5_b_trueCount++;
          }
        }

        c5_varargin_2_size[0] = 1;
        c5_varargin_2_size[1] = c5_b_trueCount;
        c5_b_partialTrueCount = 0;
        for (c5_h_i = 0; c5_h_i < c5_b_end; c5_h_i++) {
          if (c5_idx[c5_h_i]) {
            c5_varargin_2_data[c5_b_partialTrueCount] = c5_shiftedColIdx[c5_h_i];
            c5_b_partialTrueCount++;
          }
        }

        c5_e_st.site = &c5_ac_emlrtRSI;
        if (!c5_allinrange(chartInstance, c5_index_data, c5_index_size, 410)) {
          c5_d_y = NULL;
          sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1,
            30), false);
          c5_e_y = NULL;
          sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1,
            30), false);
          sf_mex_call(&c5_e_st, &c5_d_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                      sf_mex_call(&c5_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c5_e_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
        }

        for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
          c5_b_varargin_1[c5_i11] = (real_T)c5_index_size[c5_i11];
        }

        for (c5_i12 = 0; c5_i12 < 2; c5_i12++) {
          c5_b_varargin_2[c5_i12] = (real_T)c5_varargin_2_size[c5_i12];
        }

        c5_p = false;
        c5_b_p = true;
        c5_k = 0;
        c5_exitg1 = false;
        while ((!c5_exitg1) && (c5_k < 2)) {
          c5_b_k = (real_T)c5_k + 1.0;
          c5_x1 = c5_b_varargin_1[(int32_T)c5_b_k - 1];
          c5_x2 = c5_b_varargin_2[(int32_T)c5_b_k - 1];
          c5_c_p = (c5_x1 == c5_x2);
          if (!c5_c_p) {
            c5_b_p = false;
            c5_exitg1 = true;
          } else {
            c5_k++;
          }
        }

        if (c5_b_p) {
          c5_p = true;
        }

        if (!c5_p) {
          c5_f_y = NULL;
          sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2,
            1, 34), false);
          c5_h_y = NULL;
          sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2,
            1, 34), false);
          sf_mex_call(&c5_e_st, &c5_e_emlrtMCI, "error", 0U, 2U, 14, c5_f_y, 14,
                      sf_mex_call(&c5_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c5_e_st, NULL, "message", 1U, 1U, 14, c5_h_y)));
        }

        if (!c5_allinrange(chartInstance, c5_varargin_2_data, c5_varargin_2_size,
                           520)) {
          c5_g_y = NULL;
          sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1,
            30), false);
          c5_i_y = NULL;
          sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1,
            30), false);
          sf_mex_call(&c5_e_st, &c5_d_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                      sf_mex_call(&c5_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c5_e_st, NULL, "message", 1U, 1U, 14, c5_i_y)));
        }

        c5_idx_size[1] = c5_index_size[1];
        c5_loop_ub = c5_index_size[1] - 1;
        for (c5_i13 = 0; c5_i13 <= c5_loop_ub; c5_i13++) {
          c5_idx_data[c5_i13] = (int32_T)c5_index_data[c5_i13];
        }

        c5_b_size[1] = c5_varargin_2_size[1];
        c5_b_loop_ub = c5_varargin_2_size[1] - 1;
        for (c5_i14 = 0; c5_i14 <= c5_b_loop_ub; c5_i14++) {
          c5_b_data[c5_i14] = (int32_T)c5_varargin_2_data[c5_i14] - 1;
        }

        c5_i15 = c5_b_size[1];
        c5_i16 = c5_i15;
        c5_c_loop_ub = c5_i16 - 1;
        for (c5_i17 = 0; c5_i17 <= c5_c_loop_ub; c5_i17++) {
          c5_b_data[c5_i17] *= 410;
        }

        c5_i18 = c5_idx_size[1];
        c5_i19 = c5_i18;
        c5_d_loop_ub = c5_i19 - 1;
        for (c5_i20 = 0; c5_i20 <= c5_d_loop_ub; c5_i20++) {
          c5_idx_data[c5_i20] += c5_b_data[c5_i20];
        }

        c5_index_size[1] = c5_idx_size[1];
        c5_e_loop_ub = c5_idx_size[1] - 1;
        for (c5_i21 = 0; c5_i21 <= c5_e_loop_ub; c5_i21++) {
          c5_index_data[c5_i21] = (real_T)c5_idx_data[c5_i21];
        }

        c5_c_end = 121;
        c5_c_trueCount = 0;
        for (c5_i_i = 0; c5_i_i < c5_c_end; c5_i_i++) {
          if (c5_idx[c5_i_i]) {
            c5_c_trueCount++;
          }
        }

        c5_subse_size[0] = c5_c_trueCount;
        c5_c_partialTrueCount = 0;
        for (c5_j_i = 0; c5_j_i < c5_c_end; c5_j_i++) {
          if (c5_idx[c5_j_i]) {
            c5_subse_data[c5_c_partialTrueCount] = c5_se[c5_j_i];
            c5_c_partialTrueCount++;
          }
        }

        c5_tmp_size[0] = 1;
        c5_tmp_size[1] = c5_index_size[1];
        c5_f_loop_ub = c5_index_size[1] - 1;
        for (c5_i22 = 0; c5_i22 <= c5_f_loop_ub; c5_i22++) {
          c5_i23 = (int32_T)c5_index_data[c5_i22];
          if ((c5_i23 < 1) || (c5_i23 > 213200)) {
            emlrtDynamicBoundsCheckR2012b(c5_i23, 1, 213200, &c5_l_emlrtBCI,
              &c5_c_st);
          }

          c5_tmp_data[c5_i22] = chartInstance->c5_inflatedGrid[c5_i23 - 1];
        }

        if ((c5_subse_size[0] != c5_tmp_size[1]) && ((c5_tmp_size[1] != 1) &&
             (c5_subse_size[0] != 1))) {
          emlrtDimSizeImpxCheckR2021b(c5_tmp_size[1], c5_subse_size[0],
            &c5_emlrtECI, &c5_c_st);
        }

        c5_idx_size[1] = c5_index_size[1];
        c5_g_loop_ub = c5_index_size[1] - 1;
        for (c5_i24 = 0; c5_i24 <= c5_g_loop_ub; c5_i24++) {
          c5_idx_data[c5_i24] = (int32_T)c5_index_data[c5_i24];
        }

        c5_b_tmp_size[0] = 1;
        c5_b_tmp_size[1] = c5_subse_size[0];
        c5_h_loop_ub = c5_subse_size[0] - 1;
        for (c5_i25 = 0; c5_i25 <= c5_h_loop_ub; c5_i25++) {
          c5_b_tmp_data[c5_i25] = c5_subse_data[c5_i25];
        }

        if (c5_tmp_size[1] == c5_b_tmp_size[1]) {
          c5_i26 = c5_tmp_size[1];
          c5_i_loop_ub = c5_i26 - 1;
          for (c5_i27 = 0; c5_i27 <= c5_i_loop_ub; c5_i27++) {
            c5_tmp_data[c5_i27] = (c5_tmp_data[c5_i27] || c5_b_tmp_data[c5_i27]);
          }
        } else {
          c5_or(chartInstance, c5_tmp_data, c5_tmp_size, c5_b_tmp_data,
                c5_b_tmp_size);
        }

        if (c5_idx_size[1] != c5_tmp_size[1]) {
          emlrtSubAssignSizeCheck1dR2017a(c5_idx_size[1], c5_tmp_size[1],
            &c5_b_emlrtECI, &c5_c_st);
        }

        c5_j_loop_ub = c5_tmp_size[1] - 1;
        for (c5_i28 = 0; c5_i28 <= c5_j_loop_ub; c5_i28++) {
          chartInstance->c5_inflatedGrid[c5_idx_data[c5_i28] - 1] =
            c5_tmp_data[c5_i28];
        }
      }
    }
  }

  c5_st.site = &c5_ob_emlrtRSI;
  c5_b_obj = c5_obj;
  for (c5_i1 = 0; c5_i1 < 213200; c5_i1++) {
    c5_b_obj->Buffer.Buffer[c5_i1] = chartInstance->c5_inflatedGrid[c5_i1];
  }

  c5_b_st.site = &c5_kb_emlrtRSI;
  c5_c_obj = c5_b_obj;
  c5_r = c5_c_obj->Buffer.Index;
  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_r->Head[c5_i3] = 1.0;
  }

  c5_b_st.site = &c5_kb_emlrtRSI;
  c5_d_obj = c5_b_obj;
  c5_index = c5_r;
  c5_c_st.site = &c5_lb_emlrtRSI;
  c5_e_obj = &c5_d_obj->Buffer;
  c5_b_index = c5_index;
  c5_e_obj->Index = c5_b_index;
}

static void c5_MapLayer_getValueAllImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, boolean_T c5_val[213200])
{
  static char_T c5_b_cv[40] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'c', 'i', 'r', 'c', 's', 'h', 'i', 'f', 't', '_', 'I',
    'n', 'v', 'a', 'l', 'i', 'd', 'S', 'h', 'i', 'f', 't', 'T', 'y', 'p', 'e' };

  static char_T c5_b_cv1[5] = { 'i', 'n', 't', '3', '2' };

  c5_binaryOccupancyMap *c5_b_obj;
  c5_binaryOccupancyMap *c5_c_obj;
  c5_binaryOccupancyMap *c5_d_obj;
  c5_binaryOccupancyMap *c5_e_obj;
  c5_matlabshared_autonomous_internal_CircularBuffer *c5_f_obj;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_b_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_c_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_d_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_index;
  c5_matlabshared_autonomous_internal_CircularBufferIndex *c5_r;
  emlrtStack c5_st;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  real_T c5_p[2];
  real_T c5_b_j;
  real_T c5_b_k;
  real_T c5_b_p;
  real_T c5_d;
  real_T c5_d_i;
  real_T c5_d_k;
  real_T c5_dim;
  real_T c5_f_k;
  int32_T c5_absp[2];
  int32_T c5_subArr[2];
  int32_T c5_b_a;
  int32_T c5_b_i;
  int32_T c5_c_a;
  int32_T c5_c_b;
  int32_T c5_c_i;
  int32_T c5_c_k;
  int32_T c5_c_vk;
  int32_T c5_d_x;
  int32_T c5_e_i;
  int32_T c5_e_k;
  int32_T c5_e_x;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i_y;
  int32_T c5_idx;
  int32_T c5_intp;
  int32_T c5_j;
  int32_T c5_j_y;
  int32_T c5_k;
  int32_T c5_pk;
  int32_T c5_sz;
  int32_T c5_u0;
  int32_T c5_u1;
  int32_T c5_v1;
  boolean_T c5_c_x[2];
  boolean_T c5_shiftright[2];
  boolean_T c5_x_data[2];
  boolean_T c5_b1;
  boolean_T c5_b_b;
  boolean_T c5_d_y;
  boolean_T c5_exitg1;
  boolean_T c5_pok;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_pb_emlrtRSI;
  c5_b_obj = c5_obj;
  c5_index = c5_b_obj->Buffer.Index;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_c_x[c5_i] = (c5_index->Head[c5_i] == 1.0);
  }

  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_x_data[c5_i1] = c5_c_x[c5_i1];
  }

  c5_d_y = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    if (!c5_x_data[(int32_T)c5_b_k - 1]) {
      c5_d_y = false;
      c5_exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (c5_d_y) {
    for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
      c5_val[c5_i2] = c5_obj->Buffer.Buffer[c5_i2];
    }
  } else {
    c5_st.site = &c5_qb_emlrtRSI;
    c5_c_obj = c5_obj;
    c5_b_index = c5_c_obj->Buffer.Index;
    c5_st.site = &c5_qb_emlrtRSI;
    for (c5_i3 = 0; c5_i3 < 213200; c5_i3++) {
      c5_val[c5_i3] = c5_obj->Buffer.Buffer[c5_i3];
    }

    for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
      c5_p[c5_i4] = -(c5_b_index->Head[c5_i4] - 1.0);
    }

    c5_pok = true;
    c5_c_k = 0;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_c_k < 2)) {
      c5_d_k = (real_T)c5_c_k + 1.0;
      c5_pk = (int32_T)c5_p[(int32_T)c5_d_k - 1];
      if (((real_T)c5_pk != c5_p[(int32_T)c5_d_k - 1]) || (c5_pk == MIN_int32_T))
      {
        c5_pok = false;
        c5_exitg1 = true;
      } else {
        c5_c_k++;
      }
    }

    if (c5_pok) {
      c5_b_b = true;
    } else {
      c5_b_b = false;
    }

    if (!c5_b_b) {
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 40),
                    false);
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 40),
                    false);
      c5_g_y = NULL;
      sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                    false);
      c5_h_y = NULL;
      sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                    false);
      sf_mex_call(&c5_st, &c5_b_emlrtMCI, "error", 0U, 2U, 14, c5_e_y, 14,
                  sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c5_st, NULL, "message", 1U, 3U, 14, c5_f_y, 14, c5_g_y, 14, c5_h_y)));
    }

    for (c5_e_k = 0; c5_e_k < 2; c5_e_k++) {
      c5_f_k = (real_T)c5_e_k + 1.0;
      c5_b_p = c5_p[(int32_T)c5_f_k - 1];
      c5_dim = c5_f_k;
      if (c5_b_p < 0.0) {
        c5_intp = (int32_T)c5_b_p;
        c5_i6 = -c5_intp;
        c5_b1 = false;
      } else {
        c5_i6 = (int32_T)c5_b_p;
        c5_b1 = true;
      }

      c5_d = (real_T)(110 * ((int32_T)c5_dim - 1) + 410);
      c5_sz = (int32_T)c5_d;
      if (c5_i6 > c5_sz) {
        c5_d_x = c5_i6;
        c5_i_y = c5_sz;
        c5_c_a = c5_d_x;
        c5_c_b = c5_i_y;
        c5_e_x = c5_c_a;
        c5_j_y = c5_c_b;
        c5_u0 = c5_e_x;
        c5_u1 = c5_j_y;
        c5_i6 = c5_u0 - c5_u1 * c5_div_s32_ndbzs(chartInstance, c5_u0, c5_u1, 0,
          0U, 0, 0);
      }

      if (c5_i6 > (c5_sz >> 1)) {
        c5_i6 = c5_sz - c5_i6;
        c5_b1 = !c5_b1;
      }

      c5_subArr[(int32_T)c5_f_k - 1] = c5_i6;
      c5_c_x[(int32_T)c5_f_k - 1] = c5_b1;
    }

    for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
      chartInstance->c5_a[c5_i5] = c5_val[c5_i5];
    }

    for (c5_b_i = 0; c5_b_i < 2; c5_b_i++) {
      c5_d_i = (real_T)c5_b_i + 1.0;
      c5_absp[(int32_T)c5_d_i - 1] = c5_subArr[(int32_T)c5_d_i - 1];
      c5_shiftright[(int32_T)c5_d_i - 1] = c5_c_x[(int32_T)c5_d_i - 1];
    }

    for (c5_c_i = 0; c5_c_i < 213200; c5_c_i++) {
      c5_e_i = c5_c_i;
      c5_idx = c5_e_i;
      c5_v1 = c5_idx;
      c5_b_a = c5_v1;
      c5_c_vk = (int32_T)((uint32_T)c5_b_a / 410U);
      c5_subArr[1] = c5_c_vk + 1;
      c5_v1 = (c5_v1 - c5_c_vk * 410) + 1;
      c5_subArr[0] = c5_v1;
      for (c5_j = 0; c5_j < 2; c5_j++) {
        c5_b_j = (real_T)c5_j + 1.0;
        if (c5_shiftright[(int32_T)c5_b_j - 1]) {
          c5_subArr[(int32_T)c5_b_j - 1] -= c5_absp[(int32_T)c5_b_j - 1];
          if (c5_subArr[(int32_T)c5_b_j - 1] <= 0) {
            c5_subArr[(int32_T)c5_b_j - 1] = (110 * ((int32_T)c5_b_j - 1) +
              c5_subArr[(int32_T)c5_b_j - 1]) + 410;
          }
        } else {
          c5_subArr[(int32_T)c5_b_j - 1] += c5_absp[(int32_T)c5_b_j - 1];
          if (c5_subArr[(int32_T)c5_b_j - 1] > 110 * ((int32_T)c5_b_j - 1) + 410)
          {
            c5_subArr[(int32_T)c5_b_j - 1] = (c5_subArr[(int32_T)c5_b_j - 1] -
              110 * ((int32_T)c5_b_j - 1)) - 410;
          }
        }
      }

      c5_val[c5_e_i] = chartInstance->c5_a[(c5_subArr[0] + 410 * (c5_subArr[1] -
        1)) - 1];
    }

    if (!c5_obj->HasParent) {
      for (c5_i7 = 0; c5_i7 < 213200; c5_i7++) {
        c5_obj->Buffer.Buffer[c5_i7] = c5_val[c5_i7];
      }

      c5_st.site = &c5_rb_emlrtRSI;
      c5_d_obj = c5_obj;
      c5_r = c5_d_obj->Buffer.Index;
      for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
        c5_r->Head[c5_i8] = 1.0;
      }

      c5_st.site = &c5_rb_emlrtRSI;
      c5_e_obj = c5_obj;
      c5_c_index = c5_r;
      c5_f_obj = &c5_e_obj->Buffer;
      c5_d_index = c5_c_index;
      c5_f_obj->Index = c5_d_index;
    }
  }
}

static boolean_T c5_allinrange(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_x_data[], int32_T c5_x_size[2], int32_T c5_hi)
{
  real_T c5_b_k;
  real_T c5_d;
  int32_T c5_exitg1;
  int32_T c5_i;
  int32_T c5_k;
  boolean_T c5_b_b;
  boolean_T c5_p;
  (void)chartInstance;
  c5_d = (real_T)c5_x_size[1];
  c5_i = (int32_T)c5_d - 1;
  c5_k = 0;
  do {
    c5_exitg1 = 0;
    if (c5_k <= c5_i) {
      c5_b_k = (real_T)c5_k + 1.0;
      if ((c5_x_data[(int32_T)c5_b_k - 1] >= 1.0) && (c5_x_data[(int32_T)c5_b_k
           - 1] <= (real_T)c5_hi)) {
        c5_b_b = true;
      } else {
        c5_b_b = false;
      }

      if (!c5_b_b) {
        c5_p = false;
        c5_exitg1 = 1;
      } else {
        c5_k++;
      }
    } else {
      c5_p = true;
      c5_exitg1 = 1;
    }
  } while (c5_exitg1 == 0);

  return c5_p;
}

static void c5_MapInterface_world2grid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, real_T c5_idx[2])
{
  c5_binaryOccupancyMap *c5_b_obj;
  c5_binaryOccupancyMap *c5_c_obj;
  real_T c5_locWorld[2];
  int32_T c5_i;
  int32_T c5_i1;
  c5_b_obj = c5_obj;
  c5_c_obj = c5_b_obj;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_locWorld[c5_i] = c5_c_obj->SharedProperties.LocalOriginInWorld[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_locWorld[c5_i1] = 2.0 - c5_locWorld[c5_i1];
  }

  c5_MapInterface_local2gridImpl(chartInstance, c5_b_obj, c5_locWorld, c5_idx);
}

static void c5_MapInterface_local2gridImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, real_T c5_localXY[2], real_T c5_gridInd[2])
{
  real_T c5_b_a[4];
  real_T c5_d_x[4];
  real_T c5_gOrig[2];
  real_T c5_gridXY[2];
  real_T c5_xlimit[2];
  real_T c5_ylimit[2];
  real_T c5_absx;
  real_T c5_b_r;
  real_T c5_c_x;
  real_T c5_d_y;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_ex;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_k;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_maxval;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r;
  real_T c5_r_x;
  real_T c5_s_x;
  int32_T c5_b_exponent;
  int32_T c5_b_i;
  int32_T c5_b_k;
  int32_T c5_c_k;
  int32_T c5_d_k;
  int32_T c5_e_k;
  int32_T c5_end;
  int32_T c5_exponent;
  int32_T c5_f_k;
  int32_T c5_first;
  int32_T c5_g_k;
  int32_T c5_h_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i_k;
  int32_T c5_idx;
  int32_T c5_k;
  boolean_T c5_t_x[2];
  boolean_T c5_x_data[2];
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_f_y;
  boolean_T c5_g_b;
  boolean_T c5_p;
  (void)chartInstance;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_gOrig[c5_i] = c5_obj->SharedProperties.GridOriginInLocal[c5_i];
  }

  c5_xlimit[0] = c5_gOrig[0];
  c5_xlimit[1] = c5_gOrig[0] + 52.0;
  c5_ylimit[0] = c5_gOrig[1];
  c5_ylimit[1] = c5_gOrig[1] + 41.0;
  c5_gridXY[0] = -c5_ylimit[0] + c5_localXY[1];
  c5_gridXY[1] = -c5_xlimit[0] + c5_localXY[0];
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_gridXY[c5_i1] *= 10.0;
  }

  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    c5_gridInd[c5_i2] = c5_gridXY[c5_i2];
  }

  for (c5_k = 0; c5_k < 2; c5_k++) {
    c5_b_k = c5_k;
    c5_c_x = c5_gridInd[c5_b_k];
    c5_e_x = c5_c_x;
    c5_e_x = muDoubleScalarCeil(c5_e_x);
    c5_gridInd[c5_b_k] = c5_e_x;
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_d_x[c5_i3] = c5_xlimit[c5_i3];
  }

  for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
    c5_d_x[c5_i4 + 2] = c5_ylimit[c5_i4];
  }

  for (c5_c_k = 0; c5_c_k < 4; c5_c_k++) {
    c5_d_k = c5_c_k;
    c5_f_x = c5_d_x[c5_d_k];
    c5_d_y = muDoubleScalarAbs(c5_f_x);
    c5_b_a[c5_d_k] = c5_d_y;
  }

  for (c5_i5 = 0; c5_i5 < 4; c5_i5++) {
    c5_b_a[c5_i5] *= 10.0;
  }

  c5_g_x = c5_b_a[0];
  c5_h_x = c5_g_x;
  c5_b_b = muDoubleScalarIsNaN(c5_h_x);
  c5_p = !c5_b_b;
  if (c5_p) {
    c5_idx = 1;
  } else {
    c5_idx = 0;
    c5_e_k = 2;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_e_k < 5)) {
      c5_i_x = c5_b_a[c5_e_k - 1];
      c5_j_x = c5_i_x;
      c5_c_b = muDoubleScalarIsNaN(c5_j_x);
      c5_b_p = !c5_c_b;
      if (c5_b_p) {
        c5_idx = c5_e_k;
        c5_exitg1 = true;
      } else {
        c5_e_k++;
      }
    }
  }

  if (c5_idx == 0) {
    c5_maxval = c5_b_a[0];
  } else {
    c5_first = c5_idx - 1;
    c5_ex = c5_b_a[c5_first];
    c5_i6 = c5_first;
    for (c5_g_k = c5_i6 + 2; c5_g_k < 5; c5_g_k++) {
      if (c5_ex < c5_b_a[c5_g_k - 1]) {
        c5_ex = c5_b_a[c5_g_k - 1];
      }
    }

    c5_maxval = c5_ex;
  }

  for (c5_f_k = 0; c5_f_k < 2; c5_f_k++) {
    c5_h_k = c5_f_k;
    c5_m_x = c5_gridXY[c5_h_k];
    c5_e_y = muDoubleScalarAbs(c5_m_x);
    c5_gOrig[c5_h_k] = c5_e_y;
  }

  c5_k_x = c5_maxval;
  c5_l_x = c5_k_x;
  c5_n_x = c5_l_x;
  c5_o_x = c5_n_x;
  c5_p_x = c5_o_x;
  c5_absx = muDoubleScalarAbs(c5_p_x);
  c5_q_x = c5_absx;
  c5_r_x = c5_q_x;
  c5_d_b = muDoubleScalarIsInf(c5_r_x);
  c5_e_b = !c5_d_b;
  c5_s_x = c5_q_x;
  c5_f_b = muDoubleScalarIsNaN(c5_s_x);
  c5_b1 = !c5_f_b;
  c5_g_b = (c5_e_b && c5_b1);
  if (!c5_g_b) {
    c5_r = rtNaN;
  } else if (c5_absx < 4.4501477170144028E-308) {
    c5_r = 4.94065645841247E-324;
  } else {
    frexp(c5_absx, &c5_exponent);
    c5_b_exponent = c5_exponent;
    c5_r = ldexp(1.0, c5_b_exponent - 53);
  }

  c5_b_r = c5_r * 2.0;
  for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
    c5_t_x[c5_i7] = (c5_gOrig[c5_i7] < c5_b_r);
  }

  for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
    c5_x_data[c5_i8] = c5_t_x[c5_i8];
  }

  c5_f_y = false;
  c5_i_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_i_k < 2)) {
    c5_j_k = (real_T)c5_i_k + 1.0;
    if (!c5_x_data[(int32_T)c5_j_k - 1]) {
      c5_b2 = true;
    } else {
      c5_b2 = false;
    }

    if (!c5_b2) {
      c5_f_y = true;
      c5_exitg1 = true;
    } else {
      c5_i_k++;
    }
  }

  if (c5_f_y) {
    c5_end = 2;
    for (c5_b_i = 0; c5_b_i < c5_end; c5_b_i++) {
      if (c5_gOrig[c5_b_i] < c5_r * 2.0) {
        c5_gridInd[c5_b_i] = 1.0;
      }
    }
  }

  c5_gridInd[0] = 411.0 - c5_gridInd[0];
}

static void c5_b_MapInterface_world2grid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_binaryOccupancyMap *c5_obj, real_T c5_pos[2], real_T c5_idx[2])
{
  c5_binaryOccupancyMap *c5_b_obj;
  c5_binaryOccupancyMap *c5_c_obj;
  real_T c5_locWorld[2];
  int32_T c5_i;
  int32_T c5_i1;
  c5_b_obj = c5_obj;
  c5_c_obj = c5_b_obj;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_locWorld[c5_i] = c5_c_obj->SharedProperties.LocalOriginInWorld[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_locWorld[c5_i1] = c5_pos[c5_i1] - c5_locWorld[c5_i1];
  }

  c5_MapInterface_local2gridImpl(chartInstance, c5_b_obj, c5_locWorld, c5_idx);
}

static c5_plannerAStarGrid *c5_plannerAStarGrid_plannerAStarGrid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_binaryOccupancyMap *c5_b_varargin_1)
{
  static char_T c5_b_cv[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
    's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g',
    'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e', 't',
    'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o',
    'n' };

  static char_T c5_b_cv2[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e',
    't', 'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i',
    'o', 'n' };

  static char_T c5_b_cv4[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e',
    't', 'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i',
    'o', 'n' };

  static char_T c5_b_cv6[56] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'P', 'r', 'o', 'p', 'e', 'r', 't', 'y', 'S', 'e',
    't', 'I', 'n', 'C', 'o', 'd', 'e', 'G', 'e', 'n', 'e', 'r', 'a', 't', 'i',
    'o', 'n' };

  static char_T c5_b_cv1[8] = { 'G', 'C', 'o', 's', 't', 'F', 'c', 'n' };

  static char_T c5_b_cv5[8] = { 'H', 'C', 'o', 's', 't', 'F', 'c', 'n' };

  static char_T c5_b_cv3[5] = { 'G', 'C', 'o', 's', 't' };

  static char_T c5_b_cv7[5] = { 'H', 'C', 'o', 's', 't' };

  c5_binaryOccupancyMap *c5_input;
  c5_plannerAStarGrid *c5_b_obj;
  c5_plannerAStarGrid *c5_c_obj;
  c5_plannerAStarGrid *c5_d_obj;
  c5_plannerAStarGrid *c5_e_obj;
  c5_plannerAStarGrid *c5_f_obj;
  c5_plannerAStarGrid *c5_g_obj;
  c5_plannerAStarGrid *c5_h_obj;
  c5_plannerAStarGrid *c5_i_obj;
  c5_plannerAStarGrid *c5_j_obj;
  c5_plannerAStarGrid *c5_k_obj;
  c5_plannerAStarGrid *c5_l_obj;
  c5_plannerAStarGrid *c5_m_obj;
  c5_plannerAStarGrid *c5_n_obj;
  c5_plannerAStarGrid *c5_o_obj;
  c5_plannerAStarGrid *c5_p_obj;
  c5_plannerAStarGrid *c5_q_obj;
  c5_plannerAStarGrid *c5_r_obj;
  c5_plannerAStarGrid *c5_this;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_o_y = NULL;
  real_T c5_d;
  real_T c5_d1;
  int32_T c5_a__2_size[2];
  char_T c5_a__2_data[9];
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b_b;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_b_obj = c5_obj;
  c5_b_obj->isFirstRun = 1.0;
  c5_st.site = &c5_ec_emlrtRSI;
  c5_c_obj = c5_b_obj;
  c5_b_obj = c5_c_obj;
  c5_b_st.site = &c5_nc_emlrtRSI;
  c5_this = c5_b_obj;
  c5_b_obj = c5_this;
  c5_st.site = &c5_fc_emlrtRSI;
  c5_d_obj = c5_b_obj;
  c5_input = c5_b_varargin_1;
  c5_d_obj->Map = c5_input;
  c5_b_st.site = &c5_oc_emlrtRSI;
  c5_plannerAStarGrid_setInputState(chartInstance, c5_d_obj);
  c5_st.site = &c5_gc_emlrtRSI;
  c5_e_obj = c5_b_obj;
  c5_b_st.site = &c5_sc_emlrtRSI;
  c5_f_obj = c5_e_obj;
  if (c5_f_obj->isFirstRun == 0.0) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (c5_b_b) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 8),
                  false);
    sf_mex_call(&c5_b_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_f_y)));
  }

  c5_b_st.site = &c5_tc_emlrtRSI;
  c5_g_obj = c5_e_obj;
  c5_g_obj->UseCustomG = 1.0;
  c5_st.site = &c5_hc_emlrtRSI;
  c5_h_obj = c5_b_obj;
  c5_b_st.site = &c5_uc_emlrtRSI;
  c5_i_obj = c5_h_obj;
  if (c5_i_obj->isFirstRun == 0.0) {
    c5_b1 = true;
  } else {
    c5_b1 = false;
  }

  if (c5_b1) {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c5_b_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_h_y, 14, c5_i_y)));
  }

  c5_b_st.site = &c5_vc_emlrtRSI;
  c5_j_obj = c5_h_obj;
  c5_j_obj->UseCustomG = 0.0;
  c5_b_st.site = &c5_wc_emlrtRSI;
  c5_validateAStarBuiltinCostFunction(chartInstance, &c5_b_st, c5_a__2_data,
    c5_a__2_size, &c5_d);
  c5_h_obj->GCost = c5_d;
  c5_b_obj->UseCustomG = 0.0;
  c5_st.site = &c5_ic_emlrtRSI;
  c5_k_obj = c5_b_obj;
  c5_b_st.site = &c5_xc_emlrtRSI;
  c5_l_obj = c5_k_obj;
  if (c5_l_obj->isFirstRun == 0.0) {
    c5_b2 = true;
  } else {
    c5_b2 = false;
  }

  if (c5_b2) {
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_l_y = NULL;
    sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_b_cv5, 10, 0U, 1, 0U, 2, 1, 8),
                  false);
    sf_mex_call(&c5_b_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_j_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_k_y, 14, c5_l_y)));
  }

  c5_b_st.site = &c5_yc_emlrtRSI;
  c5_m_obj = c5_k_obj;
  c5_m_obj->UseCustomH = 1.0;
  c5_st.site = &c5_jc_emlrtRSI;
  c5_n_obj = c5_b_obj;
  c5_b_st.site = &c5_ad_emlrtRSI;
  c5_o_obj = c5_n_obj;
  if (c5_o_obj->isFirstRun == 0.0) {
    c5_b3 = true;
  } else {
    c5_b3 = false;
  }

  if (c5_b3) {
    c5_m_y = NULL;
    sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_n_y = NULL;
    sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 56),
                  false);
    c5_o_y = NULL;
    sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_b_cv7, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c5_b_st, &c5_g_emlrtMCI, "error", 0U, 2U, 14, c5_m_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_n_y, 14, c5_o_y)));
  }

  c5_b_st.site = &c5_bd_emlrtRSI;
  c5_p_obj = c5_n_obj;
  c5_p_obj->UseCustomH = 0.0;
  c5_b_st.site = &c5_cd_emlrtRSI;
  c5_validateAStarBuiltinCostFunction(chartInstance, &c5_b_st, c5_a__2_data,
    c5_a__2_size, &c5_d1);
  c5_n_obj->HCost = c5_d1;
  c5_b_obj->UseCustomH = 0.0;
  c5_st.site = &c5_kc_emlrtRSI;
  c5_b_obj->OccupiedThreshold = 0.65;
  c5_st.site = &c5_lc_emlrtRSI;
  c5_q_obj = c5_b_obj;
  c5_q_obj->TieBreaker = 0.0;
  c5_st.site = &c5_mc_emlrtRSI;
  c5_r_obj = c5_b_obj;
  c5_r_obj->DiagonalSearch = 1.0;
  c5_b_obj->isFirstRun = 0.0;
  return c5_b_obj;
}

static void c5_plannerAStarGrid_setInputState
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_plannerAStarGrid *c5_obj)
{
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  for (c5_i = 0; c5_i < 639600; c5_i++) {
    c5_obj->IdPose[c5_i] = 0.0;
  }

  for (c5_i1 = 0; c5_i1 < 213200; c5_i1++) {
    chartInstance->c5_y[c5_i1] = 1.0 + (real_T)c5_i1;
  }

  c5_ind2sub(chartInstance, chartInstance->c5_y, chartInstance->c5_varargout_4,
             chartInstance->c5_varargout_5, chartInstance->c5_varargout_6);
  for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
    chartInstance->c5_y[c5_i2] = (real_T)chartInstance->c5_varargout_4[c5_i2];
  }

  for (c5_i3 = 0; c5_i3 < 213200; c5_i3++) {
    chartInstance->c5_poseIdTemp[c5_i3] = (real_T)chartInstance->
      c5_varargout_5[c5_i3];
  }

  for (c5_i4 = 0; c5_i4 < 213200; c5_i4++) {
    chartInstance->c5_dv[c5_i4] = (real_T)chartInstance->c5_varargout_6[c5_i4];
  }

  for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
    c5_obj->IdPose[c5_i5] = chartInstance->c5_y[c5_i5];
  }

  for (c5_i6 = 0; c5_i6 < 213200; c5_i6++) {
    c5_obj->IdPose[c5_i6 + 213200] = chartInstance->c5_poseIdTemp[c5_i6];
  }

  for (c5_i7 = 0; c5_i7 < 213200; c5_i7++) {
    c5_obj->IdPose[c5_i7 + 426400] = chartInstance->c5_dv[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 213200; c5_i8++) {
    chartInstance->c5_poseIdTemp[c5_i8] = c5_obj->IdPose[c5_i8 + 213200] - 1.0;
  }

  for (c5_i9 = 0; c5_i9 < 213200; c5_i9++) {
    chartInstance->c5_poseIdTemp[c5_i9] *= 410.0;
  }

  for (c5_i10 = 0; c5_i10 < 213200; c5_i10++) {
    chartInstance->c5_y[c5_i10] = c5_obj->IdPose[c5_i10 + 426400] - 1.0;
  }

  for (c5_i11 = 0; c5_i11 < 213200; c5_i11++) {
    chartInstance->c5_y[c5_i11] *= 410.0;
  }

  for (c5_i12 = 0; c5_i12 < 213200; c5_i12++) {
    chartInstance->c5_y[c5_i12] *= 520.0;
  }

  for (c5_i13 = 0; c5_i13 < 213200; c5_i13++) {
    chartInstance->c5_poseIdTemp[c5_i13] = (c5_obj->IdPose[c5_i13] +
      chartInstance->c5_poseIdTemp[c5_i13]) + chartInstance->c5_y[c5_i13];
  }

  for (c5_i14 = 0; c5_i14 < 213200; c5_i14++) {
    c5_obj->PoseId[c5_i14] = chartInstance->c5_poseIdTemp[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 213200; c5_i15++) {
    c5_obj->NodeCostValue[c5_i15] = -1.0;
  }
}

static void c5_ind2sub(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_ndx[213200], int32_T c5_varargout_1[213200], int32_T
  c5_varargout_2[213200], int32_T c5_b_varargout_3[213200])
{
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    c5_varargout_1[c5_i] = (int32_T)c5_ndx[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 213200; c5_i1++) {
    c5_varargout_1[c5_i1]--;
  }

  for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
    chartInstance->c5_vk[c5_i2] = c5_div_nzp_s32(chartInstance,
      c5_varargout_1[c5_i2], 213200, 0, 0U, 0, 0);
  }

  for (c5_i3 = 0; c5_i3 < 213200; c5_i3++) {
    c5_b_varargout_3[c5_i3] = chartInstance->c5_vk[c5_i3] + 1;
  }

  for (c5_i4 = 0; c5_i4 < 213200; c5_i4++) {
    chartInstance->c5_vk[c5_i4] *= 213200;
  }

  for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
    c5_varargout_1[c5_i5] -= chartInstance->c5_vk[c5_i5];
  }

  for (c5_i6 = 0; c5_i6 < 213200; c5_i6++) {
    chartInstance->c5_vk[c5_i6] = c5_div_nzp_s32(chartInstance,
      c5_varargout_1[c5_i6], 410, 0, 0U, 0, 0);
  }

  for (c5_i7 = 0; c5_i7 < 213200; c5_i7++) {
    c5_varargout_2[c5_i7] = chartInstance->c5_vk[c5_i7] + 1;
  }

  for (c5_i8 = 0; c5_i8 < 213200; c5_i8++) {
    chartInstance->c5_vk[c5_i8] *= 410;
  }

  for (c5_i9 = 0; c5_i9 < 213200; c5_i9++) {
    c5_varargout_1[c5_i9] -= chartInstance->c5_vk[c5_i9];
  }

  for (c5_i10 = 0; c5_i10 < 213200; c5_i10++) {
    c5_varargout_1[c5_i10]++;
  }
}

static void c5_validateAStarBuiltinCostFunction
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, char_T c5_strVal_data[], int32_T c5_strVal_size[2], real_T *c5_idx)
{
  static char_T c5_b_a[9] = { 'E', 'u', 'c', 'l', 'i', 'd', 'e', 'a', 'n' };

  static char_T c5_b_cv[9] = { 'E', 'u', 'c', 'l', 'i', 'd', 'e', 'a', 'n' };

  static char_T c5_b_cv1[9] = { 'M', 'a', 'n', 'h', 'a', 't', 't', 'a', 'n' };

  static char_T c5_b_cv2[9] = { 'C', 'h', 'e', 'b', 'y', 's', 'h', 'e', 'v' };

  c5_cell_wrap_27 c5_b_b[1];
  c5_cell_wrap_27 c5_r;
  real_T c5_idxTemp_data[4];
  int32_T c5_ii_data[4];
  int32_T c5_idxTemp_size[2];
  int32_T c5_ii_size[2];
  int32_T c5_b_idx;
  int32_T c5_b_ii;
  int32_T c5_b_kstr;
  int32_T c5_c_kstr;
  int32_T c5_d_kstr;
  int32_T c5_e_kstr;
  int32_T c5_exitg1;
  int32_T c5_f_kstr;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_ii;
  int32_T c5_kstr;
  int32_T c5_loop_ub;
  char_T c5_b_data[9];
  boolean_T c5_c_x[4];
  boolean_T c5_b_bool;
  boolean_T c5_bool;
  boolean_T c5_c_b;
  boolean_T c5_c_bool;
  boolean_T c5_exitg2;
  (void)chartInstance;
  c5_strVal_size[0] = 1;
  c5_strVal_size[1] = 9;
  for (c5_i = 0; c5_i < 9; c5_i++) {
    c5_strVal_data[c5_i] = c5_b_a[c5_i];
  }

  c5_r.f1.size[0] = 1;
  c5_r.f1.size[1] = 9;
  for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
    c5_r.f1.data[c5_i1] = c5_strVal_data[c5_i1];
  }

  c5_b_b[0] = c5_r;
  for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
    c5_b_data[c5_i2] = c5_b_b[0].f1.data[c5_i2];
  }

  c5_bool = false;
  c5_kstr = 1;
  do {
    c5_exitg1 = 0;
    if (c5_kstr - 1 < 9) {
      c5_b_kstr = c5_kstr - 1;
      if (c5_b_cv[c5_b_kstr] != c5_b_data[c5_b_kstr]) {
        c5_exitg1 = 1;
      } else {
        c5_kstr++;
      }
    } else {
      c5_bool = true;
      c5_exitg1 = 1;
    }
  } while (c5_exitg1 == 0);

  c5_c_x[0] = c5_bool;
  for (c5_i3 = 0; c5_i3 < 9; c5_i3++) {
    c5_b_data[c5_i3] = c5_b_b[0].f1.data[c5_i3];
  }

  c5_b_bool = false;
  c5_c_kstr = 1;
  do {
    c5_exitg1 = 0;
    if (c5_c_kstr - 1 < 9) {
      c5_d_kstr = c5_c_kstr - 1;
      if (c5_b_cv1[c5_d_kstr] != c5_b_data[c5_d_kstr]) {
        c5_exitg1 = 1;
      } else {
        c5_c_kstr++;
      }
    } else {
      c5_b_bool = true;
      c5_exitg1 = 1;
    }
  } while (c5_exitg1 == 0);

  c5_c_x[1] = c5_b_bool;
  for (c5_i4 = 0; c5_i4 < 9; c5_i4++) {
    c5_b_data[c5_i4] = c5_b_b[0].f1.data[c5_i4];
  }

  c5_c_bool = false;
  c5_e_kstr = 1;
  do {
    c5_exitg1 = 0;
    if (c5_e_kstr - 1 < 9) {
      c5_f_kstr = c5_e_kstr - 1;
      if (c5_b_cv2[c5_f_kstr] != c5_b_data[c5_f_kstr]) {
        c5_exitg1 = 1;
      } else {
        c5_e_kstr++;
      }
    } else {
      c5_c_bool = true;
      c5_exitg1 = 1;
    }
  } while (c5_exitg1 == 0);

  c5_c_x[2] = c5_c_bool;
  c5_c_x[3] = false;
  c5_b_idx = 0;
  c5_ii = 1;
  c5_exitg2 = false;
  while ((!c5_exitg2) && (c5_ii - 1 < 4)) {
    c5_b_ii = c5_ii;
    if (c5_c_x[c5_b_ii - 1]) {
      c5_b_idx++;
      c5_ii_data[c5_b_idx - 1] = c5_b_ii;
      if (c5_b_idx >= 4) {
        c5_exitg2 = true;
      } else {
        c5_ii++;
      }
    } else {
      c5_ii++;
    }
  }

  c5_c_b = (c5_b_idx < 1);
  if (c5_c_b) {
    c5_i5 = 0;
  } else {
    c5_i5 = c5_b_idx;
  }

  c5_ii_size[1] = c5_i5;
  c5_idxTemp_size[1] = c5_ii_size[1];
  c5_loop_ub = c5_ii_size[1] - 1;
  for (c5_i6 = 0; c5_i6 <= c5_loop_ub; c5_i6++) {
    c5_idxTemp_data[c5_i6] = (real_T)c5_ii_data[c5_i6];
  }

  c5_i7 = 1;
  if ((c5_i7 < 1) || (c5_i7 > c5_idxTemp_size[1])) {
    emlrtDynamicBoundsCheckR2012b(c5_i7, 1, c5_idxTemp_size[1], &c5_m_emlrtBCI,
      (emlrtConstCTX)c5_sp);
  }

  *c5_idx = c5_idxTemp_data[0];
}

static void c5_plannerAStarGrid_plan(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_plannerAStarGrid *c5_obj, real_T
  c5_start[2], real_T c5_goal[2], c5_coder_array_real_T_2D *c5_path)
{
  static char_T c5_b_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_b_cv10[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv4[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv7[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e',
    'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_cv12[46] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l', 'g',
    's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r', 'g',
    'r', 'i', 'd', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'G', 'r', 'i',
    'd', 'I', 'n', 'p', 'u', 't' };

  static char_T c5_b_cv[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l', 'a',
    'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':', 'e',
    'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_b_cv3[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l',
    'a', 'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv6[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l',
    'a', 'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'N', 'o', 'n', 'N', 'a', 'N' };

  static char_T c5_b_cv9[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l',
    'a', 'n', 'n', 'e', 'r', 'A', 'S', 't', 'a', 'r', 'G', 'r', 'i', 'd', ':',
    'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c5_b_cv2[5] = { 'S', 't', 'a', 'r', 't' };

  static char_T c5_b_cv5[5] = { 'S', 't', 'a', 'r', 't' };

  static char_T c5_cv13[5] = { 'S', 't', 'a', 'r', 't' };

  static char_T c5_b_cv8[4] = { 'G', 'o', 'a', 'l' };

  static char_T c5_cv11[4] = { 'G', 'o', 'a', 'l' };

  static char_T c5_cv14[4] = { 'G', 'o', 'a', 'l' };

  c5_binaryOccupancyMap *c5_b_val;
  c5_binaryOccupancyMap *c5_c_map;
  c5_binaryOccupancyMap *c5_val;
  c5_plannerAStarGrid *c5_b_obj;
  c5_plannerAStarGrid *c5_c_obj;
  c5_plannerAStarGrid *c5_d_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_q_y = NULL;
  const mxArray *c5_r_y = NULL;
  const mxArray *c5_s_y = NULL;
  const mxArray *c5_u_y = NULL;
  const mxArray *c5_v_y = NULL;
  const mxArray *c5_w_y = NULL;
  const mxArray *c5_x_y = NULL;
  const mxArray *c5_y_y = NULL;
  real_T c5_b_goal[2];
  real_T c5_b_goalgrid[2];
  real_T c5_b_start[2];
  real_T c5_b_startgrid[2];
  real_T c5_e_obj[2];
  real_T c5_f_obj[2];
  real_T c5_goalgrid[2];
  real_T c5_startgrid[2];
  real_T c5_b_k;
  real_T c5_c_x;
  real_T c5_d_k;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_k;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_k;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_k;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_o_x;
  real_T c5_p_k;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_s_x;
  int32_T c5_c_k;
  int32_T c5_e_k;
  int32_T c5_g_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_k;
  int32_T c5_j_k;
  int32_T c5_k;
  int32_T c5_k_k;
  int32_T c5_m_k;
  int32_T c5_n_k;
  int32_T c5_o_k;
  boolean_T c5_n_x[2];
  boolean_T c5_x_data[2];
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_d_p;
  boolean_T c5_e_b;
  boolean_T c5_e_p;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_f_p;
  boolean_T c5_g_b;
  boolean_T c5_h_b;
  boolean_T c5_i_b;
  boolean_T c5_j_b;
  boolean_T c5_k_b;
  boolean_T c5_p;
  boolean_T c5_p_y;
  boolean_T c5_t_y;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_st.site = &c5_dd_emlrtRSI;
  c5_b_st.site = &c5_od_emlrtRSI;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_c_x = c5_start[(int32_T)c5_b_k - 1];
    c5_d_x = c5_c_x;
    c5_c_b = muDoubleScalarIsNaN(c5_d_x);
    c5_b_p = !c5_c_b;
    if (c5_b_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv2, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c5_b_st, &c5_j_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_f_y)));
  }

  c5_b_st.site = &c5_od_emlrtRSI;
  c5_c_p = true;
  c5_c_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_c_k < 2)) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    c5_e_x = c5_start[(int32_T)c5_d_k - 1];
    c5_f_x = c5_e_x;
    c5_d_b = muDoubleScalarIsInf(c5_f_x);
    c5_b2 = !c5_d_b;
    c5_g_x = c5_e_x;
    c5_e_b = muDoubleScalarIsNaN(c5_g_x);
    c5_b3 = !c5_e_b;
    c5_f_b = (c5_b2 && c5_b3);
    if (c5_f_b) {
      c5_c_k++;
    } else {
      c5_c_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_c_p) {
    c5_b1 = true;
  } else {
    c5_b1 = false;
  }

  if (!c5_b1) {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv3, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv5, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(&c5_b_st, &c5_k_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_h_y, 14, c5_i_y)));
  }

  c5_st.site = &c5_ed_emlrtRSI;
  c5_b_st.site = &c5_od_emlrtRSI;
  c5_d_p = true;
  c5_e_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_e_k < 2)) {
    c5_f_k = (real_T)c5_e_k + 1.0;
    c5_h_x = c5_goal[(int32_T)c5_f_k - 1];
    c5_i_x = c5_h_x;
    c5_g_b = muDoubleScalarIsNaN(c5_i_x);
    c5_e_p = !c5_g_b;
    if (c5_e_p) {
      c5_e_k++;
    } else {
      c5_d_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_d_p) {
    c5_b4 = true;
  } else {
    c5_b4 = false;
  }

  if (!c5_b4) {
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv7, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_l_y = NULL;
    sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_b_cv8, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c5_b_st, &c5_j_emlrtMCI, "error", 0U, 2U, 14, c5_j_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_k_y, 14, c5_l_y)));
  }

  c5_b_st.site = &c5_od_emlrtRSI;
  c5_f_p = true;
  c5_g_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_g_k < 2)) {
    c5_h_k = (real_T)c5_g_k + 1.0;
    c5_j_x = c5_goal[(int32_T)c5_h_k - 1];
    c5_k_x = c5_j_x;
    c5_h_b = muDoubleScalarIsInf(c5_k_x);
    c5_b6 = !c5_h_b;
    c5_l_x = c5_j_x;
    c5_i_b = muDoubleScalarIsNaN(c5_l_x);
    c5_b7 = !c5_i_b;
    c5_j_b = (c5_b6 && c5_b7);
    if (c5_j_b) {
      c5_g_k++;
    } else {
      c5_f_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_f_p) {
    c5_b5 = true;
  } else {
    c5_b5 = false;
  }

  if (!c5_b5) {
    c5_m_y = NULL;
    sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_b_cv9, 10, 0U, 1, 0U, 2, 1, 38),
                  false);
    c5_n_y = NULL;
    sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_b_cv10, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_o_y = NULL;
    sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_cv11, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c5_b_st, &c5_k_emlrtMCI, "error", 0U, 2U, 14, c5_m_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_n_y, 14, c5_o_y)));
  }

  c5_obj->IsGrid = 0.0;
  c5_obj->IsGrid = 1.0;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_startgrid[c5_i] = c5_start[c5_i];
  }

  for (c5_i_k = 0; c5_i_k < 2; c5_i_k++) {
    c5_j_k = c5_i_k;
    c5_m_x = c5_startgrid[c5_j_k];
    c5_o_x = c5_m_x;
    c5_o_x = muDoubleScalarFloor(c5_o_x);
    c5_startgrid[c5_j_k] = c5_o_x;
  }

  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_n_x[c5_i1] = (c5_start[c5_i1] == c5_startgrid[c5_i1]);
  }

  for (c5_i2 = 0; c5_i2 < 2; c5_i2++) {
    c5_x_data[c5_i2] = c5_n_x[c5_i2];
  }

  c5_p_y = true;
  c5_k_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k_k < 2)) {
    c5_l_k = (real_T)c5_k_k + 1.0;
    if (!c5_x_data[(int32_T)c5_l_k - 1]) {
      c5_p_y = false;
      c5_exitg1 = true;
    } else {
      c5_k_k++;
    }
  }

  if (!c5_p_y) {
    c5_q_y = NULL;
    sf_mex_assign(&c5_q_y, sf_mex_create("y", c5_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_r_y = NULL;
    sf_mex_assign(&c5_r_y, sf_mex_create("y", c5_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_s_y = NULL;
    sf_mex_assign(&c5_s_y, sf_mex_create("y", c5_cv13, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(c5_sp, &c5_h_emlrtMCI, "error", 0U, 2U, 14, c5_q_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 2U, 14, c5_r_y, 14, c5_s_y)));
  }

  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_startgrid[c5_i3] = c5_goal[c5_i3];
  }

  for (c5_m_k = 0; c5_m_k < 2; c5_m_k++) {
    c5_n_k = c5_m_k;
    c5_p_x = c5_startgrid[c5_n_k];
    c5_q_x = c5_p_x;
    c5_q_x = muDoubleScalarFloor(c5_q_x);
    c5_startgrid[c5_n_k] = c5_q_x;
  }

  for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
    c5_n_x[c5_i4] = (c5_goal[c5_i4] == c5_startgrid[c5_i4]);
  }

  for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
    c5_x_data[c5_i5] = c5_n_x[c5_i5];
  }

  c5_t_y = true;
  c5_o_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_o_k < 2)) {
    c5_p_k = (real_T)c5_o_k + 1.0;
    if (!c5_x_data[(int32_T)c5_p_k - 1]) {
      c5_t_y = false;
      c5_exitg1 = true;
    } else {
      c5_o_k++;
    }
  }

  if (!c5_t_y) {
    c5_u_y = NULL;
    sf_mex_assign(&c5_u_y, sf_mex_create("y", c5_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_v_y = NULL;
    sf_mex_assign(&c5_v_y, sf_mex_create("y", c5_cv12, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_w_y = NULL;
    sf_mex_assign(&c5_w_y, sf_mex_create("y", c5_cv14, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c5_sp, &c5_i_emlrtMCI, "error", 0U, 2U, 14, c5_u_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 2U, 14, c5_v_y, 14, c5_w_y)));
  }

  c5_st.site = &c5_fd_emlrtRSI;
  c5_r_x = c5_obj->IsGrid;
  c5_s_x = c5_r_x;
  c5_k_b = muDoubleScalarIsNaN(c5_s_x);
  if (c5_k_b) {
    c5_x_y = NULL;
    sf_mex_assign(&c5_x_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    c5_y_y = NULL;
    sf_mex_assign(&c5_y_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    sf_mex_call(&c5_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_x_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 1U, 14, c5_y_y)));
  }

  if (!(c5_obj->IsGrid != 0.0)) {
    c5_st.site = &c5_gd_emlrtRSI;
    c5_b_obj = c5_obj;
    c5_val = c5_b_obj->Map;
    c5_st.site = &c5_gd_emlrtRSI;
    for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
      c5_b_start[c5_i8] = c5_start[c5_i8];
    }

    c5_b_MapInterface_world2grid(chartInstance, c5_val, c5_b_start, c5_startgrid);
    c5_st.site = &c5_hd_emlrtRSI;
    c5_d_obj = c5_obj;
    c5_b_val = c5_d_obj->Map;
    c5_st.site = &c5_hd_emlrtRSI;
    for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
      c5_b_goal[c5_i11] = c5_goal[c5_i11];
    }

    c5_b_MapInterface_world2grid(chartInstance, c5_b_val, c5_b_goal, c5_goalgrid);
  } else {
    for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
      c5_startgrid[c5_i6] = c5_start[c5_i6];
    }

    for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
      c5_goalgrid[c5_i7] = c5_goal[c5_i7];
    }
  }

  c5_st.site = &c5_id_emlrtRSI;
  c5_c_obj = c5_obj;
  c5_c_map = c5_c_obj->Map;
  c5_st.site = &c5_jd_emlrtRSI;
  for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
    c5_b_startgrid[c5_i9] = c5_startgrid[c5_i9];
  }

  for (c5_i10 = 0; c5_i10 < 2; c5_i10++) {
    c5_b_goalgrid[c5_i10] = c5_goalgrid[c5_i10];
  }

  c5_plannerAStarGrid_validateStartGoal(chartInstance, &c5_st, c5_obj, c5_c_map,
    c5_b_startgrid, c5_b_goalgrid);
  for (c5_i12 = 0; c5_i12 < 2; c5_i12++) {
    c5_obj->StartInGrid[c5_i12] = c5_startgrid[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 2; c5_i13++) {
    c5_obj->GoalInGrid[c5_i13] = c5_goalgrid[c5_i13];
  }

  c5_st.site = &c5_nd_emlrtRSI;
  c5_plannerAStarGrid_initializeInternalPlanner(chartInstance, &c5_st, c5_obj,
    &chartInstance->c5_astarInternal);
  c5_st.site = &c5_kd_emlrtRSI;
  for (c5_i14 = 0; c5_i14 < 2; c5_i14++) {
    c5_e_obj[c5_i14] = c5_obj->StartInGrid[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 2; c5_i15++) {
    c5_f_obj[c5_i15] = c5_obj->GoalInGrid[c5_i15];
  }

  c5_plannerAStarGrid_runPlan(chartInstance, &c5_st,
    &chartInstance->c5_astarInternal, c5_e_obj, c5_f_obj);
  c5_st.site = &c5_ld_emlrtRSI;
  c5_plannerAStarGrid_getEssentialOutput(chartInstance, &c5_st, c5_obj,
    &chartInstance->c5_astarInternal);
  c5_st.site = &c5_md_emlrtRSI;
  c5_plannerAStarGrid_getPathOutput(chartInstance, &c5_st, c5_obj, c5_path);
}

static void c5_plannerAStarGrid_validateStartGoal
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_binaryOccupancyMap *c5_c_map, real_T
   c5_StartInGrid[2], real_T c5_GoalInGrid[2])
{
  static char_T c5_b_cv4[46] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'C', 'o', 'o', 'r', 'd', 'i', 'n', 'a', 't', 'e',
    'O', 'u', 't', 's', 'i', 'd', 'e' };

  static char_T c5_b_cv6[45] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'O', 'c', 'c', 'u', 'p', 'i', 'e', 'd', 'L', 'o',
    'c', 'a', 't', 'i', 'o', 'n' };

  static char_T c5_b_cv[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'l', 'a',
    'n', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'I', 'n', 't', 'e', 'g',
    'e', 'r' };

  static char_T c5_b_cv5[11] = { 'X', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n' };

  static char_T c5_b_cv7[11] = { 'Y', ' ', 'd', 'i', 'r', 'e', 'c', 't', 'i',
    'o', 'n' };

  static char_T c5_b_cv1[9] = { 's', 't', 'a', 'r', 't', 'G', 'o', 'a', 'l' };

  static char_T c5_b_cv3[7] = { 'c', 'o', 'l', 'u', 'm', 'n', 's' };

  static char_T c5_rfmt[7] = { '%', '2', '3', '.', '1', '5', 'e' };

  static char_T c5_b_cv8[5] = { 's', 't', 'a', 'r', 't' };

  static char_T c5_b_cv2[4] = { 'r', 'o', 'w', 's' };

  static char_T c5_b_cv9[4] = { 'g', 'o', 'a', 'l' };

  c5_binaryOccupancyMap *c5_b_obj;
  c5_binaryOccupancyMap *c5_e_obj;
  c5_matlabshared_autonomous_internal_SharedMapProperties *c5_c_obj;
  c5_matlabshared_autonomous_internal_SharedMapProperties *c5_f_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_ab_y = NULL;
  const mxArray *c5_bb_y = NULL;
  const mxArray *c5_cb_y = NULL;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_db_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_eb_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_fb_y = NULL;
  const mxArray *c5_gb_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_p_y = NULL;
  const mxArray *c5_q_y = NULL;
  const mxArray *c5_r_y = NULL;
  const mxArray *c5_s_y = NULL;
  const mxArray *c5_t_y = NULL;
  const mxArray *c5_u_y = NULL;
  const mxArray *c5_v_y = NULL;
  const mxArray *c5_w_y = NULL;
  const mxArray *c5_x_y = NULL;
  const mxArray *c5_y_y = NULL;
  real_T c5_pos[4];
  real_T c5_mapSizeX[2];
  real_T c5_mapSizeY[2];
  real_T c5_b_k;
  real_T c5_c_x;
  real_T c5_d_k;
  real_T c5_d_obj;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_obj;
  real_T c5_g_x;
  real_T c5_g_y;
  real_T c5_goalNode;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_startNode;
  int32_T c5_strX_size[2];
  int32_T c5_strY_size[2];
  int32_T c5_c_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_k;
  char_T c5_str[23];
  char_T c5_strX_data[11];
  char_T c5_strY_data[11];
  boolean_T c5_bv[2];
  boolean_T c5_validIdx[2];
  boolean_T c5_x_data[2];
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_h_y;
  boolean_T c5_isGoalOccupied;
  boolean_T c5_isStartOccupied;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_st.site = &c5_pd_emlrtRSI;
  c5_i = 0;
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_pos[c5_i] = c5_StartInGrid[c5_i1];
    c5_i += 2;
  }

  c5_i2 = 0;
  for (c5_i3 = 0; c5_i3 < 2; c5_i3++) {
    c5_pos[c5_i2 + 1] = c5_GoalInGrid[c5_i3];
    c5_i2 += 2;
  }

  c5_b_st.site = &c5_xd_emlrtRSI;
  c5_c_st.site = &c5_od_emlrtRSI;
  c5_p = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 4)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_c_x = c5_pos[(int32_T)c5_b_k - 1];
    c5_d_x = c5_c_x;
    c5_e_x = c5_d_x;
    c5_c_b = muDoubleScalarIsInf(c5_e_x);
    c5_b1 = !c5_c_b;
    c5_f_x = c5_d_x;
    c5_d_b = muDoubleScalarIsNaN(c5_f_x);
    c5_b2 = !c5_d_b;
    c5_e_b = (c5_b1 && c5_b2);
    if (c5_e_b) {
      c5_g_x = c5_c_x;
      c5_h_x = c5_g_x;
      c5_g_y = c5_h_x;
      c5_g_y = muDoubleScalarFloor(c5_g_y);
      if (c5_g_y == c5_c_x) {
        c5_b_p = true;
      } else {
        c5_b_p = false;
      }
    } else {
      c5_b_p = false;
    }

    c5_c_p = c5_b_p;
    if (c5_c_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 27),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 9),
                  false);
    sf_mex_call(&c5_c_st, &c5_p_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_f_y)));
  }

  for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
    c5_validIdx[c5_i4] = (c5_pos[c5_i4] <= 410.0);
  }

  for (c5_i5 = 0; c5_i5 < 2; c5_i5++) {
    c5_bv[c5_i5] = (c5_pos[c5_i5 + 2] <= 520.0);
  }

  for (c5_i6 = 0; c5_i6 < 2; c5_i6++) {
    c5_validIdx[c5_i6] = (c5_validIdx[c5_i6] && c5_bv[c5_i6]);
  }

  for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
    c5_bv[c5_i7] = (c5_pos[c5_i7] >= 1.0);
  }

  for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
    c5_validIdx[c5_i8] = (c5_validIdx[c5_i8] && c5_bv[c5_i8]);
  }

  for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
    c5_bv[c5_i9] = (c5_pos[c5_i9 + 2] >= 1.0);
  }

  for (c5_i10 = 0; c5_i10 < 2; c5_i10++) {
    c5_validIdx[c5_i10] = (c5_validIdx[c5_i10] && c5_bv[c5_i10]);
  }

  for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
    c5_validIdx[c5_i11] = !c5_validIdx[c5_i11];
  }

  for (c5_i12 = 0; c5_i12 < 2; c5_i12++) {
    c5_x_data[c5_i12] = c5_validIdx[c5_i12];
  }

  c5_h_y = false;
  c5_c_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_c_k < 2)) {
    c5_d_k = (real_T)c5_c_k + 1.0;
    if (!c5_x_data[(int32_T)c5_d_k - 1]) {
      c5_b3 = true;
    } else {
      c5_b3 = false;
    }

    if (!c5_b3) {
      c5_h_y = true;
      c5_exitg1 = true;
    } else {
      c5_c_k++;
    }
  }

  if (c5_h_y) {
    c5_st.site = &c5_qd_emlrtRSI;
    c5_i_x = c5_obj->IsGrid;
    c5_j_x = c5_i_x;
    c5_f_b = muDoubleScalarIsNaN(c5_j_x);
    if (c5_f_b) {
      c5_i_y = NULL;
      sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      c5_j_y = NULL;
      sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c5_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                  sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c5_st, NULL, "message", 1U, 1U, 14, c5_j_y)));
    }

    if (!(c5_obj->IsGrid != 0.0)) {
      c5_st.site = &c5_rd_emlrtRSI;
      c5_b_obj = c5_c_map;
      c5_b_st.site = &c5_yd_emlrtRSI;
      c5_c_obj = &c5_b_obj->SharedProperties;
      c5_d_obj = c5_c_obj->LocalOriginInWorld[0] + c5_c_obj->GridOriginInLocal[0];
      for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
        c5_mapSizeX[c5_i18] = c5_d_obj + 52.0 * (real_T)c5_i18;
      }

      c5_st.site = &c5_sd_emlrtRSI;
      c5_e_obj = c5_c_map;
      c5_b_st.site = &c5_ae_emlrtRSI;
      c5_f_obj = &c5_e_obj->SharedProperties;
      c5_g_obj = c5_f_obj->LocalOriginInWorld[1] + c5_f_obj->GridOriginInLocal[1];
      for (c5_i22 = 0; c5_i22 < 2; c5_i22++) {
        c5_mapSizeY[c5_i22] = c5_g_obj + 41.0 * (real_T)c5_i22;
      }

      c5_strX_size[1] = 11;
      for (c5_i23 = 0; c5_i23 < 11; c5_i23++) {
        c5_strX_data[c5_i23] = c5_b_cv5[c5_i23];
      }

      c5_strY_size[1] = 11;
      for (c5_i24 = 0; c5_i24 < 11; c5_i24++) {
        c5_strY_data[c5_i24] = c5_b_cv7[c5_i24];
      }
    } else {
      for (c5_i14 = 0; c5_i14 < 2; c5_i14++) {
        c5_mapSizeX[c5_i14] = 1.0 + 409.0 * (real_T)c5_i14;
      }

      for (c5_i16 = 0; c5_i16 < 2; c5_i16++) {
        c5_mapSizeY[c5_i16] = 1.0 + 519.0 * (real_T)c5_i16;
      }

      c5_strX_size[1] = 4;
      for (c5_i17 = 0; c5_i17 < 4; c5_i17++) {
        c5_strX_data[c5_i17] = c5_b_cv2[c5_i17];
      }

      c5_strY_size[1] = 7;
      for (c5_i20 = 0; c5_i20 < 7; c5_i20++) {
        c5_strY_data[c5_i20] = c5_b_cv3[c5_i20];
      }
    }

    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_l_y = NULL;
    sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_b_cv4, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c5_st.site = &c5_td_emlrtRSI;
    c5_k_x = c5_mapSizeX[0];
    c5_b_st.site = &c5_sb_emlrtRSI;
    c5_l_x = c5_k_x;
    c5_n_y = NULL;
    sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c5_p_y = NULL;
    sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_l_x, 0, 0U, 0, 0U, 0), false);
    c5_c_st.site = &c5_tb_emlrtRSI;
    c5_emlrt_marshallIn(chartInstance, c5_sprintf(chartInstance, &c5_c_st,
      c5_n_y, c5_p_y), "<output of sprintf>", c5_str);
    c5_t_y = NULL;
    sf_mex_assign(&c5_t_y, sf_mex_create("y", c5_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c5_st.site = &c5_td_emlrtRSI;
    c5_m_x = c5_mapSizeX[1];
    c5_b_st.site = &c5_sb_emlrtRSI;
    c5_n_x = c5_m_x;
    c5_v_y = NULL;
    sf_mex_assign(&c5_v_y, sf_mex_create("y", c5_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c5_w_y = NULL;
    sf_mex_assign(&c5_w_y, sf_mex_create("y", &c5_n_x, 0, 0U, 0, 0U, 0), false);
    c5_c_st.site = &c5_tb_emlrtRSI;
    c5_emlrt_marshallIn(chartInstance, c5_sprintf(chartInstance, &c5_c_st,
      c5_v_y, c5_w_y), "<output of sprintf>", c5_str);
    c5_x_y = NULL;
    sf_mex_assign(&c5_x_y, sf_mex_create("y", c5_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c5_y_y = NULL;
    sf_mex_assign(&c5_y_y, sf_mex_create("y", &c5_strX_data, 10, 0U, 1, 0U, 2, 1,
      c5_strX_size[1]), false);
    c5_st.site = &c5_ud_emlrtRSI;
    c5_o_x = c5_mapSizeY[0];
    c5_b_st.site = &c5_sb_emlrtRSI;
    c5_p_x = c5_o_x;
    c5_ab_y = NULL;
    sf_mex_assign(&c5_ab_y, sf_mex_create("y", c5_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c5_bb_y = NULL;
    sf_mex_assign(&c5_bb_y, sf_mex_create("y", &c5_p_x, 0, 0U, 0, 0U, 0), false);
    c5_c_st.site = &c5_tb_emlrtRSI;
    c5_emlrt_marshallIn(chartInstance, c5_sprintf(chartInstance, &c5_c_st,
      c5_ab_y, c5_bb_y), "<output of sprintf>", c5_str);
    c5_cb_y = NULL;
    sf_mex_assign(&c5_cb_y, sf_mex_create("y", c5_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c5_st.site = &c5_ud_emlrtRSI;
    c5_q_x = c5_mapSizeY[1];
    c5_b_st.site = &c5_sb_emlrtRSI;
    c5_r_x = c5_q_x;
    c5_db_y = NULL;
    sf_mex_assign(&c5_db_y, sf_mex_create("y", c5_rfmt, 10, 0U, 1, 0U, 2, 1, 7),
                  false);
    c5_eb_y = NULL;
    sf_mex_assign(&c5_eb_y, sf_mex_create("y", &c5_r_x, 0, 0U, 0, 0U, 0), false);
    c5_c_st.site = &c5_tb_emlrtRSI;
    c5_emlrt_marshallIn(chartInstance, c5_sprintf(chartInstance, &c5_c_st,
      c5_db_y, c5_eb_y), "<output of sprintf>", c5_str);
    c5_fb_y = NULL;
    sf_mex_assign(&c5_fb_y, sf_mex_create("y", c5_str, 10, 0U, 1, 0U, 2, 1, 23),
                  false);
    c5_gb_y = NULL;
    sf_mex_assign(&c5_gb_y, sf_mex_create("y", &c5_strY_data, 10, 0U, 1, 0U, 2,
      1, c5_strY_size[1]), false);
    sf_mex_call(c5_sp, &c5_m_emlrtMCI, "error", 0U, 2U, 14, c5_k_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 7U, 14, c5_l_y, 14, c5_t_y, 14, c5_x_y, 14,
       c5_y_y, 14, c5_cb_y, 14, c5_fb_y, 14, c5_gb_y)));
  }

  if (c5_GoalInGrid[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_GoalInGrid[0]))
  {
    emlrtIntegerCheckR2012b(c5_GoalInGrid[0], &c5_k_emlrtDCI, (emlrtConstCTX)
      c5_sp);
  }

  c5_i13 = (int32_T)c5_GoalInGrid[0];
  if ((c5_i13 < 1) || (c5_i13 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i13, 1, 410, &c5_n_emlrtBCI, (emlrtConstCTX)
      c5_sp);
  }

  if (c5_GoalInGrid[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_GoalInGrid[1]))
  {
    emlrtIntegerCheckR2012b(c5_GoalInGrid[1], &c5_l_emlrtDCI, (emlrtConstCTX)
      c5_sp);
  }

  c5_i15 = (int32_T)c5_GoalInGrid[1];
  if ((c5_i15 < 1) || (c5_i15 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i15, 1, 520, &c5_o_emlrtBCI, (emlrtConstCTX)
      c5_sp);
  }

  c5_goalNode = c5_obj->PoseId[(c5_i13 + 410 * (c5_i15 - 1)) - 1];
  if (c5_StartInGrid[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_StartInGrid[0]))
  {
    emlrtIntegerCheckR2012b(c5_StartInGrid[0], &c5_m_emlrtDCI, (emlrtConstCTX)
      c5_sp);
  }

  c5_i19 = (int32_T)c5_StartInGrid[0];
  if ((c5_i19 < 1) || (c5_i19 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i19, 1, 410, &c5_p_emlrtBCI, (emlrtConstCTX)
      c5_sp);
  }

  if (c5_StartInGrid[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_StartInGrid[1]))
  {
    emlrtIntegerCheckR2012b(c5_StartInGrid[1], &c5_n_emlrtDCI, (emlrtConstCTX)
      c5_sp);
  }

  c5_i21 = (int32_T)c5_StartInGrid[1];
  if ((c5_i21 < 1) || (c5_i21 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i21, 1, 520, &c5_q_emlrtBCI, (emlrtConstCTX)
      c5_sp);
  }

  c5_startNode = c5_obj->PoseId[(c5_i19 + 410 * (c5_i21 - 1)) - 1];
  c5_st.site = &c5_vd_emlrtRSI;
  c5_isStartOccupied = (c5_plannerAStarGrid_getNodeCostOMDefault(chartInstance,
    &c5_st, c5_obj, c5_startNode) == rtInf);
  if (c5_isStartOccupied) {
    c5_m_y = NULL;
    sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c5_o_y = NULL;
    sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c5_r_y = NULL;
    sf_mex_assign(&c5_r_y, sf_mex_create("y", c5_b_cv8, 10, 0U, 1, 0U, 2, 1, 5),
                  false);
    sf_mex_call(c5_sp, &c5_n_emlrtMCI, "error", 0U, 2U, 14, c5_m_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 2U, 14, c5_o_y, 14, c5_r_y)));
  }

  c5_st.site = &c5_wd_emlrtRSI;
  c5_isGoalOccupied = (c5_plannerAStarGrid_getNodeCostOMDefault(chartInstance,
    &c5_st, c5_obj, c5_goalNode) == rtInf);
  if (c5_isGoalOccupied) {
    c5_q_y = NULL;
    sf_mex_assign(&c5_q_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c5_s_y = NULL;
    sf_mex_assign(&c5_s_y, sf_mex_create("y", c5_b_cv6, 10, 0U, 1, 0U, 2, 1, 45),
                  false);
    c5_u_y = NULL;
    sf_mex_assign(&c5_u_y, sf_mex_create("y", c5_b_cv9, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c5_sp, &c5_o_emlrtMCI, "error", 0U, 2U, 14, c5_q_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 2U, 14, c5_s_y, 14, c5_u_y)));
  }
}

static real_T c5_plannerAStarGrid_getNodeCostOMDefault
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, real_T c5_currentNode)
{
  c5_binaryOccupancyMap *c5_c_obj;
  c5_binaryOccupancyMap *c5_val;
  c5_plannerAStarGrid *c5_b_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  real_T c5_b_dv[1];
  real_T c5_dv1[1];
  real_T c5_c_x;
  real_T c5_cost;
  real_T c5_d_x;
  real_T c5_d_y;
  int32_T c5_b_tmp_size[2];
  int32_T c5_tmp_size[2];
  int32_T c5_b_tmp_data[1];
  int32_T c5_tmp_data[1];
  int32_T c5_b_end;
  int32_T c5_b_i;
  int32_T c5_b_loop_ub;
  int32_T c5_b_trueCount;
  int32_T c5_c_i;
  int32_T c5_d_i;
  int32_T c5_e_i;
  int32_T c5_end;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_loop_ub;
  int32_T c5_trueCount;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_st.site = &c5_be_emlrtRSI;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_b_obj = c5_obj;
  c5_val = c5_b_obj->Map;
  c5_st.site = &c5_be_emlrtRSI;
  c5_c_obj = c5_val;
  c5_b_st.site = &c5_ce_emlrtRSI;
  c5_MapLayer_getValueAllImpl(chartInstance, &c5_b_st, c5_c_obj,
    chartInstance->c5_b_mat);
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    chartInstance->c5_b_occMat[c5_i] = (real_T)chartInstance->c5_b_mat[c5_i];
  }

  if (c5_currentNode != (real_T)(int32_T)muDoubleScalarFloor(c5_currentNode)) {
    emlrtIntegerCheckR2012b(c5_currentNode, &c5_o_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_i1 = (int32_T)c5_currentNode;
  if ((c5_i1 < 1) || (c5_i1 > 213200)) {
    emlrtDynamicBoundsCheckR2012b(c5_i1, 1, 213200, &c5_r_emlrtBCI,
      (emlrtConstCTX)c5_sp);
  }

  c5_cost = chartInstance->c5_b_occMat[c5_i1 - 1];
  c5_c_x = c5_cost * 10000.0;
  c5_d_x = c5_c_x;
  c5_d_y = c5_d_x;
  c5_d_y = muDoubleScalarRound(c5_d_y);
  c5_cost = c5_d_y / 10000.0;
  c5_b_dv[0] = c5_cost;
  c5_end = 1;
  c5_trueCount = 0;
  for (c5_b_i = 0; c5_b_i < c5_end; c5_b_i++) {
    if (c5_cost > c5_obj->OccupiedThreshold) {
      c5_trueCount++;
    }
  }

  c5_tmp_size[1] = c5_trueCount;
  for (c5_c_i = 0; c5_c_i < c5_end; c5_c_i++) {
    if (c5_cost > c5_obj->OccupiedThreshold) {
      c5_tmp_data[0] = c5_c_i;
    }
  }

  c5_loop_ub = c5_tmp_size[1] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_b_dv[c5_tmp_data[0]] = rtInf;
  }

  c5_cost = c5_b_dv[0];
  c5_dv1[0] = c5_cost;
  c5_b_end = 1;
  c5_b_trueCount = 0;
  for (c5_d_i = 0; c5_d_i < c5_b_end; c5_d_i++) {
    if (c5_cost <= c5_obj->OccupiedThreshold) {
      c5_b_trueCount++;
    }
  }

  c5_b_tmp_size[1] = c5_b_trueCount;
  for (c5_e_i = 0; c5_e_i < c5_b_end; c5_e_i++) {
    if (c5_cost <= c5_obj->OccupiedThreshold) {
      c5_b_tmp_data[0] = c5_e_i;
    }
  }

  c5_b_loop_ub = c5_b_tmp_size[1] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_b_loop_ub; c5_i3++) {
    c5_dv1[c5_b_tmp_data[0]] = 0.0;
  }

  return c5_dv1[0];
}

static c5_nav_algs_internal_plannerAStarGrid
  *c5_plannerAStarGrid_initializeInternalPlanner
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_nav_algs_internal_plannerAStarGrid
   *c5_iobj_0)
{
  c5_binaryOccupancyMap *c5_c_obj;
  c5_binaryOccupancyMap *c5_val;
  c5_nav_algs_internal_plannerAStarGrid *c5_b_astarInternal;
  c5_nav_algs_internal_plannerAStarGrid *c5_g_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_h_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_i_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_j_obj;
  c5_plannerAStarGrid *c5_b_obj;
  c5_plannerAStarGrid *c5_d_obj;
  c5_plannerAStarGrid *c5_e_obj;
  c5_plannerAStarGrid *c5_f_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  real_T c5_b_distMethodVal;
  real_T c5_b_val;
  real_T c5_c_val;
  real_T c5_c_x;
  real_T c5_d_val;
  real_T c5_d_x;
  real_T c5_distMethodVal;
  real_T c5_e_val;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_th;
  real_T c5_value;
  int32_T c5_b_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_k;
  boolean_T c5_b_b;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_st.site = &c5_de_emlrtRSI;
  c5_obj->OccupiedThreshold = 0.65;
  c5_st.site = &c5_ee_emlrtRSI;
  c5_b_obj = c5_obj;
  c5_val = c5_b_obj->Map;
  c5_st.site = &c5_ee_emlrtRSI;
  c5_c_obj = c5_val;
  c5_b_st.site = &c5_ce_emlrtRSI;
  c5_MapLayer_getValueAllImpl(chartInstance, &c5_b_st, c5_c_obj,
    chartInstance->c5_mat);
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    chartInstance->c5_occMat[c5_i] = (real_T)chartInstance->c5_mat[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 213200; c5_i1++) {
    chartInstance->c5_occMat[c5_i1] *= 10000.0;
  }

  for (c5_k = 0; c5_k < 213200; c5_k++) {
    c5_b_k = c5_k;
    c5_c_x = chartInstance->c5_occMat[c5_b_k];
    c5_d_x = c5_c_x;
    c5_d_x = muDoubleScalarRound(c5_d_x);
    chartInstance->c5_occMat[c5_b_k] = c5_d_x;
  }

  for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
    chartInstance->c5_occMat[c5_i2] /= 10000.0;
  }

  c5_th = c5_obj->OccupiedThreshold;
  c5_st.site = &c5_fe_emlrtRSI;
  c5_st.site = &c5_ge_emlrtRSI;
  c5_st.site = &c5_ge_emlrtRSI;
  c5_st.site = &c5_he_emlrtRSI;
  c5_b_astarInternal = c5_b_plannerAStarGrid_plannerAStarGrid(chartInstance,
    c5_iobj_0, chartInstance->c5_occMat, c5_th);
  if (c5_obj->UseCustomH == 0.0) {
    c5_st.site = &c5_ie_emlrtRSI;
    c5_d_obj = c5_obj;
    c5_b_val = c5_d_obj->HCost;
    c5_st.site = &c5_ie_emlrtRSI;
    c5_g_obj = c5_b_astarInternal;
    c5_distMethodVal = c5_b_val;
    c5_g_obj->HCostMethod = c5_distMethodVal;
    c5_g_obj->UseCustomH = 0.0;
  }

  if (c5_obj->UseCustomG == 0.0) {
    c5_st.site = &c5_je_emlrtRSI;
    c5_e_obj = c5_obj;
    c5_c_val = c5_e_obj->GCost;
    c5_st.site = &c5_je_emlrtRSI;
    c5_h_obj = c5_b_astarInternal;
    c5_b_distMethodVal = c5_c_val;
    c5_h_obj->GCostMethod = c5_b_distMethodVal;
    c5_h_obj->UseCustomG = 0.0;
  }

  c5_st.site = &c5_ke_emlrtRSI;
  c5_f_obj = c5_obj;
  c5_b_st.site = &c5_ue_emlrtRSI;
  c5_e_x = c5_f_obj->TieBreaker;
  c5_f_x = c5_e_x;
  c5_b_b = muDoubleScalarIsNaN(c5_f_x);
  if (c5_b_b) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                  false);
    sf_mex_call(&c5_b_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
  }

  if (c5_f_obj->TieBreaker != 0.0) {
    c5_value = 1.07;
  } else {
    c5_value = 1.0;
  }

  c5_st.site = &c5_ke_emlrtRSI;
  c5_i_obj = c5_b_astarInternal;
  c5_d_val = c5_value;
  c5_i_obj->TieBreaker = c5_d_val;
  c5_st.site = &c5_le_emlrtRSI;
  c5_j_obj = c5_b_astarInternal;
  c5_e_val = c5_obj->DiagonalSearch;
  c5_j_obj->DiagonalSearchFlag = c5_e_val;
  return c5_b_astarInternal;
}

static c5_nav_algs_internal_plannerAStarGrid
  *c5_b_plannerAStarGrid_plannerAStarGrid
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_c_map[213200],
   real_T c5_obstacleThreshold)
{
  c5_nav_algs_internal_plannerAStarGrid *c5_b_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_c_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_this;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  c5_b_obj = c5_obj;
  c5_b_obj->NumPathPoints = 0.0;
  c5_b_obj->UseCustomG = 0.0;
  c5_b_obj->UseCustomH = 0.0;
  c5_b_obj->GCostMethod = 1.0;
  c5_b_obj->HCostMethod = 1.0;
  c5_c_obj = c5_b_obj;
  c5_b_obj = c5_c_obj;
  c5_this = c5_b_obj;
  c5_b_obj = c5_this;
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    c5_b_obj->Map[c5_i] = c5_c_map[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 426400; c5_i1++) {
    c5_b_obj->PathInternal[c5_i1] = 0.0;
  }

  for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
    c5_b_obj->PathIndicesInternal[c5_i2] = 0.0;
  }

  for (c5_i3 = 0; c5_i3 < 213200; c5_i3++) {
    c5_b_obj->NodesExploredIndicesInternal[c5_i3] = 0.0;
  }

  for (c5_i4 = 0; c5_i4 < 426400; c5_i4++) {
    c5_b_obj->NodesExploredInternal[c5_i4] = 0.0;
  }

  c5_b_obj->ObstacleThreshold = c5_obstacleThreshold;
  c5_b_obj->MapResolution = 10.0;
  for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
    c5_b_obj->ParentCol[c5_i5] = 0.0;
  }

  for (c5_i6 = 0; c5_i6 < 213200; c5_i6++) {
    c5_b_obj->ParentRow[c5_i6] = 0.0;
  }

  for (c5_i7 = 0; c5_i7 < 213200; c5_i7++) {
    chartInstance->c5_b_y[c5_i7] = 1.0 + (real_T)c5_i7;
  }

  for (c5_i8 = 0; c5_i8 < 213200; c5_i8++) {
    c5_b_obj->MapIndex[c5_i8] = chartInstance->c5_b_y[c5_i8];
  }

  for (c5_i9 = 0; c5_i9 < 213200; c5_i9++) {
    chartInstance->c5_b_y[c5_i9] = 1.0 + (real_T)c5_i9;
  }

  c5_b_ind2sub(chartInstance, chartInstance->c5_b_y,
               chartInstance->c5_varargout_3, chartInstance->c5_b_varargout_4);
  for (c5_i10 = 0; c5_i10 < 213200; c5_i10++) {
    chartInstance->c5_b_y[c5_i10] = (real_T)chartInstance->c5_varargout_3[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 213200; c5_i11++) {
    chartInstance->c5_allCol[c5_i11] = (real_T)chartInstance->
      c5_b_varargout_4[c5_i11];
  }

  for (c5_i12 = 0; c5_i12 < 213200; c5_i12++) {
    c5_b_obj->AllNodes[c5_i12] = chartInstance->c5_b_y[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 213200; c5_i13++) {
    c5_b_obj->AllNodes[c5_i13 + 213200] = chartInstance->c5_allCol[c5_i13];
  }

  return c5_b_obj;
}

static void c5_b_ind2sub(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_ndx[213200], int32_T c5_varargout_1[213200], int32_T
  c5_varargout_2[213200])
{
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    c5_varargout_1[c5_i] = (int32_T)c5_ndx[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 213200; c5_i1++) {
    c5_varargout_1[c5_i1]--;
  }

  for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
    chartInstance->c5_b_vk[c5_i2] = c5_div_nzp_s32(chartInstance,
      c5_varargout_1[c5_i2], 410, 0, 0U, 0, 0);
  }

  for (c5_i3 = 0; c5_i3 < 213200; c5_i3++) {
    c5_varargout_2[c5_i3] = chartInstance->c5_b_vk[c5_i3] + 1;
  }

  for (c5_i4 = 0; c5_i4 < 213200; c5_i4++) {
    chartInstance->c5_b_vk[c5_i4] *= 410;
  }

  for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
    c5_varargout_1[c5_i5] -= chartInstance->c5_b_vk[c5_i5];
  }

  for (c5_i6 = 0; c5_i6 < 213200; c5_i6++) {
    c5_varargout_1[c5_i6]++;
  }
}

static void c5_plannerAStarGrid_runPlan
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_b_astarInternal, real_T
   c5_start[2], real_T c5_goal[2])
{
  static char_T c5_b_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  c5_coder_array_int32_T c5_ii;
  c5_coder_array_real_T c5_expNodes;
  c5_coder_array_real_T_2D c5_r;
  c5_nav_algs_internal_PriorityQueue c5_OpenList;
  c5_nav_algs_internal_PriorityQueue *c5_b_obj;
  c5_nav_algs_internal_PriorityQueue *c5_b_this;
  c5_nav_algs_internal_PriorityQueue *c5_c_obj;
  c5_nav_algs_internal_PriorityQueue *c5_d_obj;
  c5_nav_algs_internal_PriorityQueue *c5_e_obj;
  c5_nav_algs_internal_PriorityQueue *c5_f_obj;
  c5_nav_algs_internal_PriorityQueue *c5_g_obj;
  c5_nav_algs_internal_PriorityQueue *c5_h_obj;
  c5_nav_algs_internal_PriorityQueue *c5_m_obj;
  c5_nav_algs_internal_PriorityQueue *c5_this;
  c5_nav_algs_internal_plannerAStarGrid *c5_i_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_j_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_k_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_l_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_d_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_p_y = NULL;
  const mxArray *c5_q_y = NULL;
  real_T c5_openToPush_data[40];
  real_T c5_Neighbors_data[16];
  real_T c5_MinScoreNode_data[5];
  real_T c5_nodeData[5];
  real_T c5_b_goal[2];
  real_T c5_b_start[2];
  real_T c5_CurrentCol;
  real_T c5_CurrentRow;
  real_T c5_JumpCells;
  real_T c5_NumNeighbors;
  real_T c5_XPOS;
  real_T c5_YPOS;
  real_T c5_ab_x;
  real_T c5_b_CurrentCol;
  real_T c5_b_CurrentRow;
  real_T c5_b_a;
  real_T c5_b_j;
  real_T c5_b_p;
  real_T c5_b_varargin_1;
  real_T c5_b_varargin_2;
  real_T c5_bb_x;
  real_T c5_c_CurrentCol;
  real_T c5_c_CurrentRow;
  real_T c5_c_a;
  real_T c5_c_i;
  real_T c5_c_j;
  real_T c5_c_x;
  real_T c5_cb_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d10;
  real_T c5_d11;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  real_T c5_d8;
  real_T c5_d9;
  real_T c5_d_i;
  real_T c5_d_x;
  real_T c5_dataDim;
  real_T c5_db_x;
  real_T c5_e_i;
  real_T c5_e_x;
  real_T c5_f_b;
  real_T c5_f_x;
  real_T c5_flag;
  real_T c5_g_b;
  real_T c5_g_x;
  real_T c5_gcost;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_maxval;
  real_T c5_n_x;
  real_T c5_n_y;
  real_T c5_nodeId;
  real_T c5_o_x;
  real_T c5_o_y;
  real_T c5_openToPushK;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_r_y;
  real_T c5_s_x;
  real_T c5_s_y;
  real_T c5_t_x;
  real_T c5_t_y;
  real_T c5_tentative_gScore;
  real_T c5_u;
  real_T c5_u_x;
  real_T c5_u_y;
  real_T c5_v_x;
  real_T c5_v_y;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_y_x;
  int32_T c5_MinScoreNode_size[2];
  int32_T c5_Neighbors_size[2];
  int32_T c5_f_ii[2];
  int32_T c5_g_ii[2];
  int32_T c5_openToPush_size[2];
  int32_T c5_d_ii[1];
  int32_T c5_e_ii[1];
  int32_T c5_K;
  int32_T c5_b_i;
  int32_T c5_b_ii;
  int32_T c5_b_loop_ub;
  int32_T c5_b_openToPushK;
  int32_T c5_c_ii;
  int32_T c5_c_loop_ub;
  int32_T c5_c_openToPushK;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_end;
  int32_T c5_exitg1;
  int32_T c5_f_loop_ub;
  int32_T c5_g_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  int32_T c5_i11;
  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i5;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i6;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i7;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i8;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i9;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_idx;
  int32_T c5_loop_ub;
  int32_T c5_p;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b_b;
  boolean_T c5_b_flag;
  boolean_T c5_c_b;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg2;
  boolean_T c5_guard1;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_d_st.prev = &c5_c_st;
  c5_d_st.tls = c5_c_st.tls;
  c5_st.site = &c5_ve_emlrtRSI;
  c5_obj = c5_b_astarInternal;
  emlrtHeapReferenceStackEnterFcnR2012b(&c5_st);
  c5_array_real_T_Constructor(chartInstance, &c5_expNodes);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_r);
  c5_array_int32_T_Constructor(chartInstance, &c5_ii);
  emlrtPushHeapReferenceStackR2021a(&c5_st, true, &c5_OpenList, (void *)
    &c5_handle_matlabCodegenDestructor, chartInstance, NULL, NULL);
  c5_OpenList.matlabCodegenIsDeleted = true;
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    chartInstance->c5_map[c5_i] = c5_obj->Map[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 213200; c5_i1++) {
    chartInstance->c5_GScore[c5_i1] = rtInf;
  }

  for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
    chartInstance->c5_FScore[c5_i2] = rtInf;
  }

  for (c5_i3 = 0; c5_i3 < 213200; c5_i3++) {
    chartInstance->c5_ExploredNodes[c5_i3] = 0;
  }

  for (c5_i4 = 0; c5_i4 < 213200; c5_i4++) {
    chartInstance->c5_ParentCol1[c5_i4] = 0.0;
  }

  for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
    chartInstance->c5_ParentRow2[c5_i5] = 0.0;
  }

  for (c5_i6 = 0; c5_i6 < 213200; c5_i6++) {
    chartInstance->c5_ClosedMAT[c5_i6] = 0;
  }

  c5_end = 213200;
  for (c5_b_i = 0; c5_b_i < c5_end; c5_b_i++) {
    if (chartInstance->c5_map[c5_b_i] == 1.0) {
      chartInstance->c5_ClosedMAT[c5_b_i] = 1;
    }
  }

  c5_b_st.site = &c5_we_emlrtRSI;
  c5_b_obj = &c5_OpenList;
  c5_c_obj = c5_b_obj;
  c5_c_st.site = &c5_nf_emlrtRSI;
  c5_this = c5_c_obj;
  c5_c_obj = c5_this;
  c5_c_st.site = &c5_nf_emlrtRSI;
  c5_d_obj = c5_c_obj;
  c5_c_obj = c5_d_obj;
  c5_d_st.site = &c5_nc_emlrtRSI;
  c5_b_this = c5_c_obj;
  c5_c_obj = c5_b_this;
  c5_c_obj->PQInternal = NULL;
  c5_c_obj->PQInternal = priorityqueuecodegen_constructPQ(5.0, 2.0);
  c5_c_obj->matlabCodegenIsDeleted = false;
  c5_b_st.site = &c5_xe_emlrtRSI;
  for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
    c5_b_goal[c5_i7] = c5_goal[c5_i7];
  }

  c5_plannerAStarGrid_getHeuristicMatrix(chartInstance, &c5_b_st, c5_obj,
    c5_b_goal, chartInstance->c5_map);
  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_v_emlrtDCI, &c5_st);
  }

  c5_i8 = (int32_T)c5_start[0];
  if ((c5_i8 < 1) || (c5_i8 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i8, 1, 410, &c5_tb_emlrtBCI, &c5_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_w_emlrtDCI, &c5_st);
  }

  c5_i9 = (int32_T)c5_start[1];
  if ((c5_i9 < 1) || (c5_i9 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i9, 1, 520, &c5_ub_emlrtBCI, &c5_st);
  }

  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_x_emlrtDCI, &c5_st);
  }

  c5_i10 = (int32_T)c5_start[0];
  if ((c5_i10 < 1) || (c5_i10 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i10, 1, 410, &c5_vb_emlrtBCI, &c5_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_y_emlrtDCI, &c5_st);
  }

  c5_i11 = (int32_T)c5_start[1];
  if ((c5_i11 < 1) || (c5_i11 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i11, 1, 520, &c5_wb_emlrtBCI, &c5_st);
  }

  chartInstance->c5_FScore[(c5_i10 + 410 * (c5_i11 - 1)) - 1] =
    chartInstance->c5_map[(c5_i8 + 410 * (c5_i9 - 1)) - 1];
  c5_b_st.site = &c5_ye_emlrtRSI;
  c5_e_obj = &c5_OpenList;
  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_ab_emlrtDCI, &c5_b_st);
  }

  c5_i12 = (int32_T)c5_start[0];
  if ((c5_i12 < 1) || (c5_i12 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i12, 1, 410, &c5_xb_emlrtBCI, &c5_b_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_ab_emlrtDCI, &c5_b_st);
  }

  c5_i13 = (int32_T)c5_start[1];
  if ((c5_i13 < 1) || (c5_i13 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i13, 1, 520, &c5_yb_emlrtBCI, &c5_b_st);
  }

  c5_nodeData[0] = c5_obj->MapIndex[(c5_i12 + 410 * (c5_i13 - 1)) - 1];
  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_bb_emlrtDCI, &c5_b_st);
  }

  c5_i14 = (int32_T)c5_start[0];
  if ((c5_i14 < 1) || (c5_i14 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i14, 1, 410, &c5_ac_emlrtBCI, &c5_b_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_bb_emlrtDCI, &c5_b_st);
  }

  c5_i15 = (int32_T)c5_start[1];
  if ((c5_i15 < 1) || (c5_i15 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i15, 1, 520, &c5_bc_emlrtBCI, &c5_b_st);
  }

  c5_nodeData[1] = c5_obj->MapIndex[(c5_i14 + 410 * (c5_i15 - 1)) - 1];
  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_cb_emlrtDCI, &c5_b_st);
  }

  c5_i16 = (int32_T)c5_start[0];
  if ((c5_i16 < 1) || (c5_i16 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i16, 1, 410, &c5_cc_emlrtBCI, &c5_b_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_cb_emlrtDCI, &c5_b_st);
  }

  c5_i17 = (int32_T)c5_start[1];
  if ((c5_i17 < 1) || (c5_i17 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i17, 1, 520, &c5_dc_emlrtBCI, &c5_b_st);
  }

  c5_nodeData[2] = chartInstance->c5_FScore[(c5_i16 + 410 * (c5_i17 - 1)) - 1];
  c5_nodeData[3] = 0.0;
  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_db_emlrtDCI, &c5_b_st);
  }

  c5_i18 = (int32_T)c5_start[0];
  if ((c5_i18 < 1) || (c5_i18 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i18, 1, 410, &c5_ec_emlrtBCI, &c5_b_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_db_emlrtDCI, &c5_b_st);
  }

  c5_i19 = (int32_T)c5_start[1];
  if ((c5_i19 < 1) || (c5_i19 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i19, 1, 520, &c5_fc_emlrtBCI, &c5_b_st);
  }

  c5_nodeData[4] = chartInstance->c5_map[(c5_i18 + 410 * (c5_i19 - 1)) - 1];
  priorityqueuecodegen_push(c5_e_obj->PQInternal, &c5_nodeData[0]);
  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_eb_emlrtDCI, &c5_st);
  }

  c5_i20 = (int32_T)c5_start[0];
  if ((c5_i20 < 1) || (c5_i20 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i20, 1, 410, &c5_gc_emlrtBCI, &c5_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_fb_emlrtDCI, &c5_st);
  }

  c5_i21 = (int32_T)c5_start[1];
  if ((c5_i21 < 1) || (c5_i21 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i21, 1, 520, &c5_hc_emlrtBCI, &c5_st);
  }

  chartInstance->c5_ExploredNodes[(c5_i20 + 410 * (c5_i21 - 1)) - 1] = 1;
  if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
    emlrtIntegerCheckR2012b(c5_start[0], &c5_gb_emlrtDCI, &c5_st);
  }

  c5_i22 = (int32_T)c5_start[0];
  if ((c5_i22 < 1) || (c5_i22 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i22, 1, 410, &c5_ic_emlrtBCI, &c5_st);
  }

  if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
    emlrtIntegerCheckR2012b(c5_start[1], &c5_hb_emlrtDCI, &c5_st);
  }

  c5_i23 = (int32_T)c5_start[1];
  if ((c5_i23 < 1) || (c5_i23 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i23, 1, 520, &c5_jc_emlrtBCI, &c5_st);
  }

  chartInstance->c5_GScore[(c5_i22 + 410 * (c5_i23 - 1)) - 1] = 0.0;
  c5_CurrentRow = 0.0;
  c5_CurrentCol = 0.0;
  c5_b_st.site = &c5_af_emlrtRSI;
  c5_plannerAStarGrid_getNeighbors(chartInstance, &c5_b_st, c5_obj,
    c5_Neighbors_data, c5_Neighbors_size, &c5_NumNeighbors);
  do {
    c5_exitg1 = 0;
    c5_b_st.site = &c5_bf_emlrtRSI;
    c5_f_obj = &c5_OpenList;
    c5_dataDim = priorityqueuecodegen_getDataDim(c5_f_obj->PQInternal);
    if (!(c5_dataDim <= 5.0)) {
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(&c5_b_st, &c5_t_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                  sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
    }

    if (!(c5_dataDim >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c5_dataDim, &c5_jb_emlrtDCI, &c5_b_st);
    }

    c5_d = c5_dataDim;
    if (c5_d != (real_T)(int32_T)muDoubleScalarFloor(c5_d)) {
      emlrtIntegerCheckR2012b(c5_d, &c5_ib_emlrtDCI, &c5_b_st);
    }

    c5_MinScoreNode_size[1] = (int32_T)c5_d;
    priorityqueuecodegen_top(c5_f_obj->PQInternal, &c5_MinScoreNode_data[0],
      &c5_nodeId);
    c5_i24 = 3;
    if ((c5_i24 < 1) || (c5_i24 > c5_MinScoreNode_size[1])) {
      emlrtDynamicBoundsCheckR2012b(c5_i24, 1, c5_MinScoreNode_size[1],
        &c5_s_emlrtBCI, &c5_st);
    }

    if (c5_MinScoreNode_data[2] == rtInf) {
      c5_exitg1 = 1;
    } else {
      c5_b_st.site = &c5_cf_emlrtRSI;
      c5_g_obj = &c5_OpenList;
      c5_flag = priorityqueuecodegen_isEmpty(c5_g_obj->PQInternal);
      c5_c_st.site = &c5_uf_emlrtRSI;
      c5_c_x = c5_flag;
      c5_d_x = c5_c_x;
      c5_b_b = muDoubleScalarIsNaN(c5_d_x);
      if (c5_b_b) {
        c5_f_y = NULL;
        sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                      false);
        c5_g_y = NULL;
        sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                      false);
        sf_mex_call(&c5_c_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_f_y, 14,
                    sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_c_st, NULL, "message", 1U, 1U, 14, c5_g_y)));
      }

      c5_b_flag = (c5_flag != 0.0);
      if (c5_b_flag) {
        if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
          emlrtIntegerCheckR2012b(c5_start[0], &c5_mb_emlrtDCI, &c5_st);
        }

        c5_i28 = (int32_T)c5_start[0];
        if ((c5_i28 < 1) || (c5_i28 > 410)) {
          emlrtDynamicBoundsCheckR2012b(c5_i28, 1, 410, &c5_mc_emlrtBCI, &c5_st);
        }

        if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
          emlrtIntegerCheckR2012b(c5_start[1], &c5_nb_emlrtDCI, &c5_st);
        }

        c5_i32 = (int32_T)c5_start[1];
        if ((c5_i32 < 1) || (c5_i32 > 520)) {
          emlrtDynamicBoundsCheckR2012b(c5_i32, 1, 520, &c5_nc_emlrtBCI, &c5_st);
        }

        c5_obj->ParentCol[(c5_i28 + 410 * (c5_i32 - 1)) - 1] = c5_start[1];
        if (c5_start[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[0])) {
          emlrtIntegerCheckR2012b(c5_start[0], &c5_pb_emlrtDCI, &c5_st);
        }

        c5_i36 = (int32_T)c5_start[0];
        if ((c5_i36 < 1) || (c5_i36 > 410)) {
          emlrtDynamicBoundsCheckR2012b(c5_i36, 1, 410, &c5_pc_emlrtBCI, &c5_st);
        }

        if (c5_start[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_start[1])) {
          emlrtIntegerCheckR2012b(c5_start[1], &c5_qb_emlrtDCI, &c5_st);
        }

        c5_i38 = (int32_T)c5_start[1];
        if ((c5_i38 < 1) || (c5_i38 > 520)) {
          emlrtDynamicBoundsCheckR2012b(c5_i38, 1, 520, &c5_qc_emlrtBCI, &c5_st);
        }

        c5_obj->ParentRow[(c5_i36 + 410 * (c5_i38 - 1)) - 1] = c5_start[0];
        c5_exitg1 = 1;
      } else {
        c5_i27 = 1;
        if ((c5_i27 < 1) || (c5_i27 > c5_MinScoreNode_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c5_i27, 1, c5_MinScoreNode_size[1],
            &c5_t_emlrtBCI, &c5_st);
        }

        c5_d1 = c5_MinScoreNode_data[0];
        if (c5_d1 != (real_T)(int32_T)muDoubleScalarFloor(c5_d1)) {
          emlrtIntegerCheckR2012b(c5_d1, &c5_ob_emlrtDCI, &c5_st);
        }

        c5_i31 = (int32_T)c5_d1;
        if ((c5_i31 < 1) || (c5_i31 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c5_i31, 1, 213200, &c5_oc_emlrtBCI,
            &c5_st);
        }

        c5_CurrentRow = c5_obj->AllNodes[c5_i31 - 1];
        c5_i34 = 1;
        if ((c5_i34 < 1) || (c5_i34 > c5_MinScoreNode_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c5_i34, 1, c5_MinScoreNode_size[1],
            &c5_u_emlrtBCI, &c5_st);
        }

        c5_d2 = c5_MinScoreNode_data[0];
        if (c5_d2 != (real_T)(int32_T)muDoubleScalarFloor(c5_d2)) {
          emlrtIntegerCheckR2012b(c5_d2, &c5_rb_emlrtDCI, &c5_st);
        }

        c5_i37 = (int32_T)c5_d2;
        if ((c5_i37 < 1) || (c5_i37 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c5_i37, 1, 213200, &c5_rc_emlrtBCI,
            &c5_st);
        }

        c5_CurrentCol = c5_obj->AllNodes[c5_i37 + 213199];
        c5_i39 = 1;
        if ((c5_i39 < 1) || (c5_i39 > c5_MinScoreNode_size[1])) {
          emlrtDynamicBoundsCheckR2012b(c5_i39, 1, c5_MinScoreNode_size[1],
            &c5_v_emlrtBCI, &c5_st);
        }

        if (c5_goal[0] != (real_T)(int32_T)muDoubleScalarFloor(c5_goal[0])) {
          emlrtIntegerCheckR2012b(c5_goal[0], &c5_sb_emlrtDCI, &c5_st);
        }

        c5_i41 = (int32_T)c5_goal[0];
        if ((c5_i41 < 1) || (c5_i41 > 410)) {
          emlrtDynamicBoundsCheckR2012b(c5_i41, 1, 410, &c5_sc_emlrtBCI, &c5_st);
        }

        if (c5_goal[1] != (real_T)(int32_T)muDoubleScalarFloor(c5_goal[1])) {
          emlrtIntegerCheckR2012b(c5_goal[1], &c5_tb_emlrtDCI, &c5_st);
        }

        c5_i43 = (int32_T)c5_goal[1];
        if ((c5_i43 < 1) || (c5_i43 > 520)) {
          emlrtDynamicBoundsCheckR2012b(c5_i43, 1, 520, &c5_tc_emlrtBCI, &c5_st);
        }

        if (c5_MinScoreNode_data[0] == c5_obj->MapIndex[(c5_i41 + 410 * (c5_i43
              - 1)) - 1]) {
          for (c5_i44 = 0; c5_i44 < 213200; c5_i44++) {
            c5_obj->ParentCol[c5_i44] = chartInstance->c5_ParentCol1[c5_i44];
          }

          for (c5_i45 = 0; c5_i45 < 213200; c5_i45++) {
            c5_obj->ParentRow[c5_i45] = chartInstance->c5_ParentRow2[c5_i45];
          }

          c5_b_st.site = &c5_df_emlrtRSI;
          for (c5_i49 = 0; c5_i49 < 2; c5_i49++) {
            c5_b_start[c5_i49] = c5_start[c5_i49];
          }

          c5_plannerAStarGrid_reconstructPath(chartInstance, &c5_b_st, c5_obj,
            c5_CurrentRow, c5_CurrentCol, c5_b_start);
          c5_exitg1 = 1;
        } else {
          c5_b_st.site = &c5_ef_emlrtRSI;
          c5_h_obj = &c5_OpenList;
          priorityqueuecodegen_pop(c5_h_obj->PQInternal);
          if (c5_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor
              (c5_CurrentRow)) {
            emlrtIntegerCheckR2012b(c5_CurrentRow, &c5_p_emlrtDCI, &c5_st);
          }

          c5_i48 = (int32_T)c5_CurrentRow;
          if ((c5_i48 < 1) || (c5_i48 > 410)) {
            emlrtDynamicBoundsCheckR2012b(c5_i48, 1, 410, &c5_w_emlrtBCI, &c5_st);
          }

          if (c5_CurrentCol != (real_T)(int32_T)muDoubleScalarFloor
              (c5_CurrentCol)) {
            emlrtIntegerCheckR2012b(c5_CurrentCol, &c5_q_emlrtDCI, &c5_st);
          }

          c5_i51 = (int32_T)c5_CurrentCol;
          if ((c5_i51 < 1) || (c5_i51 > 520)) {
            emlrtDynamicBoundsCheckR2012b(c5_i51, 1, 520, &c5_x_emlrtBCI, &c5_st);
          }

          chartInstance->c5_ClosedMAT[(c5_i48 + 410 * (c5_i51 - 1)) - 1] = 1;
          c5_openToPush_size[0] = (int32_T)c5_NumNeighbors;
          c5_d_loop_ub = (int32_T)c5_NumNeighbors * 5 - 1;
          for (c5_i53 = 0; c5_i53 <= c5_d_loop_ub; c5_i53++) {
            c5_openToPush_data[c5_i53] = 0.0;
          }

          c5_openToPushK = 1.0;
          c5_i55 = (int32_T)c5_NumNeighbors - 1;
          for (c5_p = 0; c5_p <= c5_i55; c5_p++) {
            c5_b_p = (real_T)c5_p + 1.0;
            c5_i58 = (int32_T)c5_b_p;
            if ((c5_i58 < 1) || (c5_i58 > c5_Neighbors_size[0])) {
              emlrtDynamicBoundsCheckR2012b(c5_i58, 1, c5_Neighbors_size[0],
                &c5_uc_emlrtBCI, &c5_st);
            }

            c5_c_i = c5_Neighbors_data[c5_i58 - 1];
            c5_i59 = (int32_T)c5_b_p;
            if ((c5_i59 < 1) || (c5_i59 > c5_Neighbors_size[0])) {
              emlrtDynamicBoundsCheckR2012b(c5_i59, 1, c5_Neighbors_size[0],
                &c5_vc_emlrtBCI, &c5_st);
            }

            c5_j = c5_Neighbors_data[(c5_i59 + c5_Neighbors_size[0]) - 1];
            c5_b_st.site = &c5_ff_emlrtRSI;
            c5_j_obj = c5_obj;
            c5_b_CurrentRow = c5_CurrentRow;
            c5_b_CurrentCol = c5_CurrentCol;
            c5_d_i = c5_c_i;
            c5_b_j = c5_j;
            if ((c5_b_CurrentRow + c5_d_i < 1.0) || (c5_b_CurrentRow + c5_d_i >
                 410.0) || (c5_b_CurrentCol + c5_b_j < 1.0) || (c5_b_CurrentCol
                 + c5_b_j > 520.0)) {
              c5_d6 = 1.0;
            } else {
              c5_i64 = (int32_T)(c5_b_CurrentRow + c5_d_i);
              if ((c5_i64 < 1) || (c5_i64 > 410)) {
                emlrtDynamicBoundsCheckR2012b(c5_i64, 1, 410, &c5_wc_emlrtBCI,
                  &c5_b_st);
              }

              c5_i66 = (int32_T)(c5_b_CurrentCol + c5_b_j);
              if ((c5_i66 < 1) || (c5_i66 > 520)) {
                emlrtDynamicBoundsCheckR2012b(c5_i66, 1, 520, &c5_xc_emlrtBCI,
                  &c5_b_st);
              }

              if (c5_j_obj->Map[(c5_i64 + 410 * (c5_i66 - 1)) - 1] >=
                  c5_j_obj->ObstacleThreshold) {
                c5_d6 = 1.0;
              } else {
                c5_d6 = 0.0;
              }
            }

            c5_b_st.site = &c5_ff_emlrtRSI;
            c5_e_x = c5_d6;
            c5_f_x = c5_e_x;
            c5_d_b = muDoubleScalarIsNaN(c5_f_x);
            if (c5_d_b) {
              c5_l_y = NULL;
              sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2,
                1, 19), false);
              c5_m_y = NULL;
              sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2,
                1, 19), false);
              sf_mex_call(&c5_b_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_l_y,
                          14, sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U,
                14, sf_mex_call(&c5_b_st, NULL, "message", 1U, 1U, 14, c5_m_y)));
            }

            if (!(c5_d6 != 0.0)) {
              c5_i70 = (int32_T)(c5_CurrentRow + c5_c_i);
              if ((c5_i70 < 1) || (c5_i70 > 410)) {
                emlrtDynamicBoundsCheckR2012b(c5_i70, 1, 410, &c5_ad_emlrtBCI,
                  &c5_st);
              }

              c5_i71 = (int32_T)(c5_CurrentCol + c5_j);
              if ((c5_i71 < 1) || (c5_i71 > 520)) {
                emlrtDynamicBoundsCheckR2012b(c5_i71, 1, 520, &c5_bd_emlrtBCI,
                  &c5_st);
              }

              if (!((real_T)chartInstance->c5_ClosedMAT[(c5_i70 + 410 * (c5_i71
                     - 1)) - 1] != 0.0)) {
                c5_b_st.site = &c5_gf_emlrtRSI;
                c5_l_obj = c5_obj;
                c5_c_CurrentRow = c5_CurrentRow;
                c5_c_CurrentCol = c5_CurrentCol;
                c5_e_i = c5_c_i;
                c5_c_j = c5_j;
                c5_d9 = 0.0;
                c5_g_x = c5_e_i;
                c5_h_x = c5_g_x;
                c5_i_x = c5_h_x;
                c5_n_y = muDoubleScalarAbs(c5_i_x);
                c5_guard1 = false;
                if (c5_n_y > 1.0) {
                  c5_guard1 = true;
                } else {
                  c5_j_x = c5_c_j;
                  c5_k_x = c5_j_x;
                  c5_l_x = c5_k_x;
                  c5_o_y = muDoubleScalarAbs(c5_l_x);
                  if (c5_o_y > 1.0) {
                    c5_guard1 = true;
                  }
                }

                if (c5_guard1) {
                  c5_m_x = c5_e_i;
                  c5_n_x = c5_m_x;
                  c5_p_x = c5_n_x;
                  c5_b_varargin_1 = muDoubleScalarAbs(c5_p_x);
                  c5_r_x = c5_c_j;
                  c5_s_x = c5_r_x;
                  c5_t_x = c5_s_x;
                  c5_b_varargin_2 = muDoubleScalarAbs(c5_t_x);
                  c5_u_x = c5_b_varargin_1;
                  c5_r_y = c5_b_varargin_2;
                  c5_v_x = c5_u_x;
                  c5_s_y = c5_r_y;
                  c5_w_x = c5_v_x;
                  c5_t_y = c5_s_y;
                  c5_b_a = c5_w_x;
                  c5_f_b = c5_t_y;
                  c5_x_x = c5_b_a;
                  c5_u_y = c5_f_b;
                  c5_y_x = c5_x_x;
                  c5_v_y = c5_u_y;
                  c5_maxval = muDoubleScalarMax(c5_y_x, c5_v_y);
                  c5_JumpCells = 2.0 * c5_maxval - 1.0;
                  c5_i79 = (int32_T)c5_JumpCells - 1;
                  c5_K = 0;
                  c5_exitg2 = false;
                  while ((!c5_exitg2) && (c5_K <= c5_i79)) {
                    c5_ab_x = c5_e_i / c5_JumpCells;
                    c5_bb_x = c5_ab_x;
                    c5_YPOS = c5_bb_x;
                    c5_YPOS = muDoubleScalarRound(c5_YPOS);
                    c5_cb_x = c5_c_j / c5_JumpCells;
                    c5_db_x = c5_cb_x;
                    c5_XPOS = c5_db_x;
                    c5_XPOS = muDoubleScalarRound(c5_XPOS);
                    c5_d10 = c5_c_CurrentRow + c5_YPOS;
                    if (c5_d10 != (real_T)(int32_T)muDoubleScalarFloor(c5_d10))
                    {
                      emlrtIntegerCheckR2012b(c5_d10, &c5_vb_emlrtDCI, &c5_b_st);
                    }

                    c5_i88 = (int32_T)c5_d10;
                    if ((c5_i88 < 1) || (c5_i88 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i88, 1, 410,
                        &c5_wd_emlrtBCI, &c5_b_st);
                    }

                    c5_d11 = c5_c_CurrentCol + c5_XPOS;
                    if (c5_d11 != (real_T)(int32_T)muDoubleScalarFloor(c5_d11))
                    {
                      emlrtIntegerCheckR2012b(c5_d11, &c5_wb_emlrtDCI, &c5_b_st);
                    }

                    c5_i93 = (int32_T)c5_d11;
                    if ((c5_i93 < 1) || (c5_i93 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i93, 1, 520,
                        &c5_xd_emlrtBCI, &c5_b_st);
                    }

                    if (c5_l_obj->Map[(c5_i88 + 410 * (c5_i93 - 1)) - 1] == 1.0)
                    {
                      c5_d9 = 1.0;
                      c5_exitg2 = true;
                    } else {
                      c5_K++;
                    }
                  }
                }

                c5_b_st.site = &c5_gf_emlrtRSI;
                c5_o_x = c5_d9;
                c5_q_x = c5_o_x;
                c5_e_b = muDoubleScalarIsNaN(c5_q_x);
                if (c5_e_b) {
                  c5_p_y = NULL;
                  sf_mex_assign(&c5_p_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U,
                    2, 1, 19), false);
                  c5_q_y = NULL;
                  sf_mex_assign(&c5_q_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U,
                    2, 1, 19), false);
                  sf_mex_call(&c5_b_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14,
                              c5_p_y, 14, sf_mex_call(&c5_b_st, NULL,
                    "getString", 1U, 1U, 14, sf_mex_call(&c5_b_st, NULL,
                    "message", 1U, 1U, 14, c5_q_y)));
                }

                if (!(c5_d9 != 0.0)) {
                  c5_b_st.site = &c5_hf_emlrtRSI;
                  c5_gcost = c5_plannerAStarGrid_gcostValue(chartInstance,
                    &c5_b_st, c5_obj, c5_CurrentRow, c5_CurrentCol, c5_c_i, c5_j);
                  c5_tentative_gScore = chartInstance->c5_GScore[((int32_T)
                    c5_CurrentRow + 410 * ((int32_T)c5_CurrentCol - 1)) - 1] +
                    c5_gcost;
                  c5_i73 = (int32_T)(c5_CurrentRow + c5_c_i);
                  if ((c5_i73 < 1) || (c5_i73 > 410)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i73, 1, 410,
                      &c5_cd_emlrtBCI, &c5_st);
                  }

                  c5_i74 = (int32_T)(c5_CurrentCol + c5_j);
                  if ((c5_i74 < 1) || (c5_i74 > 520)) {
                    emlrtDynamicBoundsCheckR2012b(c5_i74, 1, 520,
                      &c5_dd_emlrtBCI, &c5_st);
                  }

                  if (chartInstance->c5_FScore[(c5_i73 + 410 * (c5_i74 - 1)) - 1]
                      == rtInf) {
                    c5_i76 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i76 < 1) || (c5_i76 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i76, 1, 410,
                        &c5_nb_emlrtBCI, &c5_st);
                    }

                    c5_i78 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i78 < 1) || (c5_i78 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i78, 1, 520,
                        &c5_ob_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_ExploredNodes[(c5_i76 + 410 * (c5_i78 - 1))
                      - 1] = 1;
                    c5_i81 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i81 < 1) || (c5_i81 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i81, 1, 410,
                        &c5_y_emlrtBCI, &c5_st);
                    }

                    c5_i83 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i83 < 1) || (c5_i83 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i83, 1, 520,
                        &c5_ab_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_ParentCol1[(c5_i81 + 410 * (c5_i83 - 1)) -
                      1] = c5_CurrentCol;
                    c5_i85 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i85 < 1) || (c5_i85 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i85, 1, 410,
                        &c5_bb_emlrtBCI, &c5_st);
                    }

                    c5_i87 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i87 < 1) || (c5_i87 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i87, 1, 520,
                        &c5_cb_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_ParentRow2[(c5_i85 + 410 * (c5_i87 - 1)) -
                      1] = c5_CurrentRow;
                    c5_i90 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i90 < 1) || (c5_i90 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i90, 1, 410,
                        &c5_db_emlrtBCI, &c5_st);
                    }

                    c5_i92 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i92 < 1) || (c5_i92 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i92, 1, 520,
                        &c5_eb_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_GScore[(c5_i90 + 410 * (c5_i92 - 1)) - 1] =
                      c5_tentative_gScore;
                    c5_i95 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i95 < 1) || (c5_i95 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i95, 1, 410,
                        &c5_kd_emlrtBCI, &c5_st);
                    }

                    c5_i97 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i97 < 1) || (c5_i97 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i97, 1, 520,
                        &c5_ld_emlrtBCI, &c5_st);
                    }

                    c5_i99 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i99 < 1) || (c5_i99 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i99, 1, 410,
                        &c5_md_emlrtBCI, &c5_st);
                    }

                    c5_i101 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i101 < 1) || (c5_i101 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i101, 1, 520,
                        &c5_nd_emlrtBCI, &c5_st);
                    }

                    chartInstance->c5_FScore[(c5_i99 + 410 * (c5_i101 - 1)) - 1]
                      = c5_tentative_gScore + chartInstance->c5_map[(c5_i95 +
                      410 * (c5_i97 - 1)) - 1];
                    c5_i102 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i102 < 1) || (c5_i102 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i102, 1, 410,
                        &c5_od_emlrtBCI, &c5_st);
                    }

                    c5_i103 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i103 < 1) || (c5_i103 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i103, 1, 520,
                        &c5_pd_emlrtBCI, &c5_st);
                    }

                    c5_c_a = c5_obj->MapIndex[(c5_i102 + 410 * (c5_i103 - 1)) -
                      1];
                    c5_g_b = c5_obj->MapIndex[((int32_T)c5_CurrentRow + 410 *
                      ((int32_T)c5_CurrentCol - 1)) - 1];
                    c5_i104 = (int32_T)c5_openToPushK;
                    if ((c5_i104 < 1) || (c5_i104 > c5_openToPush_size[0])) {
                      emlrtDynamicBoundsCheckR2012b(c5_i104, 1,
                        c5_openToPush_size[0], &c5_fb_emlrtBCI, &c5_st);
                    }

                    c5_b_openToPushK = c5_i104 - 1;
                    c5_openToPush_data[c5_b_openToPushK] = c5_c_a;
                    c5_openToPush_data[c5_b_openToPushK + c5_openToPush_size[0]]
                      = c5_g_b;
                    c5_i105 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i105 < 1) || (c5_i105 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i105, 1, 410,
                        &c5_qd_emlrtBCI, &c5_st);
                    }

                    c5_i106 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i106 < 1) || (c5_i106 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i106, 1, 520,
                        &c5_rd_emlrtBCI, &c5_st);
                    }

                    c5_openToPush_data[c5_b_openToPushK + (c5_openToPush_size[0]
                      << 1)] = chartInstance->c5_FScore[(c5_i105 + 410 *
                      (c5_i106 - 1)) - 1];
                    c5_i107 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i107 < 1) || (c5_i107 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i107, 1, 410,
                        &c5_sd_emlrtBCI, &c5_st);
                    }

                    c5_i108 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i108 < 1) || (c5_i108 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i108, 1, 520,
                        &c5_td_emlrtBCI, &c5_st);
                    }

                    c5_openToPush_data[c5_b_openToPushK + c5_openToPush_size[0] *
                      3] = chartInstance->c5_GScore[(c5_i107 + 410 * (c5_i108 -
                      1)) - 1];
                    c5_i109 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i109 < 1) || (c5_i109 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i109, 1, 410,
                        &c5_ud_emlrtBCI, &c5_st);
                    }

                    c5_i110 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i110 < 1) || (c5_i110 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i110, 1, 520,
                        &c5_vd_emlrtBCI, &c5_st);
                    }

                    c5_openToPush_data[c5_b_openToPushK + (c5_openToPush_size[0]
                      << 2)] = chartInstance->c5_map[(c5_i109 + 410 * (c5_i110 -
                      1)) - 1];
                    c5_b_st.site = &c5_if_emlrtRSI;
                    c5_m_obj = &c5_OpenList;
                    c5_i111 = (int32_T)c5_openToPushK;
                    if ((c5_i111 < 1) || (c5_i111 > c5_openToPush_size[0])) {
                      emlrtDynamicBoundsCheckR2012b(c5_i111, 1,
                        c5_openToPush_size[0], &c5_gb_emlrtBCI, &c5_b_st);
                    }

                    c5_c_openToPushK = c5_i111 - 1;
                    for (c5_i112 = 0; c5_i112 < 5; c5_i112++) {
                      c5_nodeData[c5_i112] = c5_openToPush_data[c5_c_openToPushK
                        + c5_openToPush_size[0] * c5_i112];
                    }

                    priorityqueuecodegen_push(c5_m_obj->PQInternal,
                      &c5_nodeData[0]);
                    c5_openToPushK++;
                  } else {
                    c5_i75 = (int32_T)(c5_CurrentRow + c5_c_i);
                    if ((c5_i75 < 1) || (c5_i75 > 410)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i75, 1, 410,
                        &c5_ed_emlrtBCI, &c5_st);
                    }

                    c5_i77 = (int32_T)(c5_CurrentCol + c5_j);
                    if ((c5_i77 < 1) || (c5_i77 > 520)) {
                      emlrtDynamicBoundsCheckR2012b(c5_i77, 1, 520,
                        &c5_fd_emlrtBCI, &c5_st);
                    }

                    if (c5_tentative_gScore >= chartInstance->c5_GScore[(c5_i75
                         + 410 * (c5_i77 - 1)) - 1]) {
                    } else {
                      c5_i80 = (int32_T)(c5_CurrentRow + c5_c_i);
                      if ((c5_i80 < 1) || (c5_i80 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i80, 1, 410,
                          &c5_hb_emlrtBCI, &c5_st);
                      }

                      c5_i82 = (int32_T)(c5_CurrentCol + c5_j);
                      if ((c5_i82 < 1) || (c5_i82 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i82, 1, 520,
                          &c5_ib_emlrtBCI, &c5_st);
                      }

                      chartInstance->c5_ParentCol1[(c5_i80 + 410 * (c5_i82 - 1))
                        - 1] = c5_CurrentCol;
                      c5_i84 = (int32_T)(c5_CurrentRow + c5_c_i);
                      if ((c5_i84 < 1) || (c5_i84 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i84, 1, 410,
                          &c5_jb_emlrtBCI, &c5_st);
                      }

                      c5_i86 = (int32_T)(c5_CurrentCol + c5_j);
                      if ((c5_i86 < 1) || (c5_i86 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i86, 1, 520,
                          &c5_kb_emlrtBCI, &c5_st);
                      }

                      chartInstance->c5_ParentRow2[(c5_i84 + 410 * (c5_i86 - 1))
                        - 1] = c5_CurrentRow;
                      c5_i89 = (int32_T)(c5_CurrentRow + c5_c_i);
                      if ((c5_i89 < 1) || (c5_i89 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i89, 1, 410,
                          &c5_lb_emlrtBCI, &c5_st);
                      }

                      c5_i91 = (int32_T)(c5_CurrentCol + c5_j);
                      if ((c5_i91 < 1) || (c5_i91 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i91, 1, 520,
                          &c5_mb_emlrtBCI, &c5_st);
                      }

                      chartInstance->c5_GScore[(c5_i89 + 410 * (c5_i91 - 1)) - 1]
                        = c5_tentative_gScore;
                      c5_i94 = (int32_T)(c5_CurrentRow + c5_c_i);
                      if ((c5_i94 < 1) || (c5_i94 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i94, 1, 410,
                          &c5_gd_emlrtBCI, &c5_st);
                      }

                      c5_i96 = (int32_T)(c5_CurrentCol + c5_j);
                      if ((c5_i96 < 1) || (c5_i96 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i96, 1, 520,
                          &c5_hd_emlrtBCI, &c5_st);
                      }

                      c5_i98 = (int32_T)(c5_CurrentRow + c5_c_i);
                      if ((c5_i98 < 1) || (c5_i98 > 410)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i98, 1, 410,
                          &c5_id_emlrtBCI, &c5_st);
                      }

                      c5_i100 = (int32_T)(c5_CurrentCol + c5_j);
                      if ((c5_i100 < 1) || (c5_i100 > 520)) {
                        emlrtDynamicBoundsCheckR2012b(c5_i100, 1, 520,
                          &c5_jd_emlrtBCI, &c5_st);
                      }

                      chartInstance->c5_FScore[(c5_i98 + 410 * (c5_i100 - 1)) -
                        1] = c5_tentative_gScore + chartInstance->c5_map[(c5_i94
                        + 410 * (c5_i96 - 1)) - 1];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  } while (c5_exitg1 == 0);

  if (c5_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor(c5_CurrentRow)) {
    emlrtIntegerCheckR2012b(c5_CurrentRow, &c5_kb_emlrtDCI, &c5_st);
  }

  c5_i25 = (int32_T)c5_CurrentRow;
  if ((c5_i25 < 1) || (c5_i25 > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i25, 1, 410, &c5_kc_emlrtBCI, &c5_st);
  }

  if (c5_CurrentCol != (real_T)(int32_T)muDoubleScalarFloor(c5_CurrentCol)) {
    emlrtIntegerCheckR2012b(c5_CurrentCol, &c5_lb_emlrtDCI, &c5_st);
  }

  c5_i26 = (int32_T)c5_CurrentCol;
  if ((c5_i26 < 1) || (c5_i26 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i26, 1, 520, &c5_lc_emlrtBCI, &c5_st);
  }

  c5_obj->PathCost = chartInstance->c5_GScore[(c5_i25 + 410 * (c5_i26 - 1)) - 1];
  for (c5_i29 = 0; c5_i29 < 213200; c5_i29++) {
    c5_obj->GCostMatrix[c5_i29] = chartInstance->c5_GScore[c5_i29];
  }

  for (c5_i30 = 0; c5_i30 < 2; c5_i30++) {
    c5_obj->Start[c5_i30] = c5_start[c5_i30];
  }

  for (c5_i33 = 0; c5_i33 < 2; c5_i33++) {
    c5_obj->Goal[c5_i33] = c5_goal[c5_i33];
  }

  c5_b_st.site = &c5_jf_emlrtRSI;
  for (c5_i35 = 0; c5_i35 < 213200; c5_i35++) {
    chartInstance->c5_x[c5_i35] = ((real_T)chartInstance->
      c5_ExploredNodes[c5_i35] == 1.0);
  }

  c5_c_st.site = &c5_yf_emlrtRSI;
  c5_d_st.site = &c5_ag_emlrtRSI;
  c5_idx = 0;
  c5_array_int32_T_SetSize(chartInstance, &c5_d_st, &c5_ii, &c5_gb_emlrtRTEI,
    213200);
  c5_b_ii = 1;
  c5_exitg2 = false;
  while ((!c5_exitg2) && (c5_b_ii - 1 < 213200)) {
    c5_c_ii = c5_b_ii;
    if (chartInstance->c5_x[c5_c_ii - 1]) {
      c5_idx++;
      c5_ii.vector.data[c5_idx - 1] = c5_c_ii;
      if (c5_idx >= 213200) {
        c5_exitg2 = true;
      } else {
        c5_b_ii++;
      }
    } else {
      c5_b_ii++;
    }
  }

  c5_c_b = (c5_idx < 1);
  if (c5_c_b) {
    c5_i40 = 0;
  } else {
    c5_i40 = c5_idx;
  }

  c5_indexShapeCheck(chartInstance);
  c5_array_int32_T_SetSize(chartInstance, &c5_d_st, &c5_ii, &c5_w_emlrtRTEI,
    c5_i40);
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_expNodes,
    &c5_hb_emlrtRTEI, c5_ii.size[0]);
  c5_loop_ub = c5_ii.size[0] - 1;
  for (c5_i42 = 0; c5_i42 <= c5_loop_ub; c5_i42++) {
    c5_expNodes.vector.data[c5_i42] = (real_T)c5_ii.vector.data[c5_i42];
  }

  c5_obj->NumNodesExplored = (real_T)c5_expNodes.size[0];
  if (!(c5_obj->NumNodesExplored <= 213200.0)) {
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1, 16),
                  false);
    c5_u = 213200.0;
    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(&c5_st, &c5_q_emlrtMCI, "error", 0U, 2U, 14, c5_h_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 3U, 14, c5_i_y, 14, c5_j_y, 14, c5_k_y)));
  }

  c5_d3 = c5_obj->NumNodesExplored;
  c5_b1 = (c5_d3 < 1.0);
  if (c5_b1) {
    c5_i46 = -1;
  } else {
    if (c5_d3 != (real_T)(int32_T)muDoubleScalarFloor(c5_d3)) {
      emlrtIntegerCheckR2012b(c5_d3, &c5_r_emlrtDCI, &c5_st);
    }

    c5_i47 = (int32_T)c5_d3;
    if ((c5_i47 < 1) || (c5_i47 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i47, 1, 213200, &c5_pb_emlrtBCI, &c5_st);
    }

    c5_i46 = c5_i47 - 1;
  }

  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_ii, &c5_ib_emlrtRTEI,
    c5_i46 + 1);
  c5_b_loop_ub = c5_i46;
  for (c5_i50 = 0; c5_i50 <= c5_b_loop_ub; c5_i50++) {
    c5_ii.vector.data[c5_i50] = c5_i50;
  }

  c5_d_ii[0] = c5_ii.size[0];
  emlrtSubAssignSizeCheckR2012b(&c5_d_ii[0], 1, &c5_expNodes.size[0], 1,
    &c5_c_emlrtECI, &c5_st);
  c5_e_ii[0] = c5_ii.size[0];
  c5_c_loop_ub = c5_e_ii[0] - 1;
  for (c5_i52 = 0; c5_i52 <= c5_c_loop_ub; c5_i52++) {
    c5_obj->NodesExploredIndicesInternal[c5_ii.vector.data[c5_i52]] =
      c5_expNodes.vector.data[c5_i52];
  }

  c5_d4 = c5_obj->NumNodesExplored;
  c5_b2 = (c5_d4 < 1.0);
  if (c5_b2) {
    c5_i54 = -1;
  } else {
    if (c5_d4 != (real_T)(int32_T)muDoubleScalarFloor(c5_d4)) {
      emlrtIntegerCheckR2012b(c5_d4, &c5_s_emlrtDCI, &c5_st);
    }

    c5_i56 = (int32_T)c5_d4;
    if ((c5_i56 < 1) || (c5_i56 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i56, 1, 213200, &c5_qb_emlrtBCI, &c5_st);
    }

    c5_i54 = c5_i56 - 1;
  }

  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_ii, &c5_jb_emlrtRTEI,
    c5_i54 + 1);
  c5_e_loop_ub = c5_i54;
  for (c5_i57 = 0; c5_i57 <= c5_e_loop_ub; c5_i57++) {
    c5_ii.vector.data[c5_i57] = c5_i57;
  }

  c5_b_st.site = &c5_kf_emlrtRSI;
  c5_i_obj = c5_obj;
  c5_d5 = c5_i_obj->NumNodesExplored;
  c5_b3 = (c5_d5 < 1.0);
  if (c5_b3) {
    c5_i60 = -1;
  } else {
    if (c5_d5 != (real_T)(int32_T)muDoubleScalarFloor(c5_d5)) {
      emlrtIntegerCheckR2012b(c5_d5, &c5_t_emlrtDCI, &c5_b_st);
    }

    c5_i61 = (int32_T)c5_d5;
    if ((c5_i61 < 1) || (c5_i61 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i61, 1, 213200, &c5_rb_emlrtBCI, &c5_b_st);
    }

    c5_i60 = c5_i61 - 1;
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_expNodes,
    &c5_kb_emlrtRTEI, c5_i60 + 1);
  c5_f_loop_ub = c5_i60;
  for (c5_i62 = 0; c5_i62 <= c5_f_loop_ub; c5_i62++) {
    c5_expNodes.vector.data[c5_i62] = c5_i_obj->
      NodesExploredIndicesInternal[c5_i62];
  }

  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_r, &c5_lb_emlrtRTEI,
    c5_expNodes.size[0], 2);
  for (c5_i63 = 0; c5_i63 < 2; c5_i63++) {
    c5_g_loop_ub = c5_expNodes.size[0] - 1;
    for (c5_i65 = 0; c5_i65 <= c5_g_loop_ub; c5_i65++) {
      c5_d7 = c5_expNodes.vector.data[c5_i65];
      if (c5_d7 != (real_T)(int32_T)muDoubleScalarFloor(c5_d7)) {
        emlrtIntegerCheckR2012b(c5_d7, &c5_ub_emlrtDCI, &c5_st);
      }

      c5_i68 = (int32_T)c5_d7;
      if ((c5_i68 < 1) || (c5_i68 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c5_i68, 1, 213200, &c5_yc_emlrtBCI, &c5_st);
      }

      c5_r.vector.data[c5_i65 + c5_r.size[0] * c5_i63] = c5_obj->AllNodes
        [(c5_i68 + 213200 * c5_i63) - 1];
    }
  }

  c5_f_ii[0] = c5_ii.size[0];
  c5_f_ii[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&c5_f_ii[0], 2, &c5_r.size[0], 2, &c5_d_emlrtECI,
    &c5_st);
  c5_g_ii[0] = c5_ii.size[0];
  for (c5_i67 = 0; c5_i67 < 2; c5_i67++) {
    c5_h_loop_ub = c5_g_ii[0] - 1;
    for (c5_i69 = 0; c5_i69 <= c5_h_loop_ub; c5_i69++) {
      c5_obj->NodesExploredInternal[c5_ii.vector.data[c5_i69] + 213200 * c5_i67]
        = c5_r.vector.data[c5_i69 + c5_r.size[0] * c5_i67];
    }
  }

  c5_b_st.site = &c5_lf_emlrtRSI;
  c5_k_obj = c5_obj;
  c5_d8 = c5_k_obj->NumPathPoints;
  c5_b4 = (c5_d8 < 1.0);
  if (!c5_b4) {
    if (c5_d8 != (real_T)(int32_T)muDoubleScalarFloor(c5_d8)) {
      emlrtIntegerCheckR2012b(c5_d8, &c5_u_emlrtDCI, &c5_b_st);
    }

    c5_i72 = (int32_T)c5_d8;
    if ((c5_i72 < 1) || (c5_i72 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i72, 1, 213200, &c5_sb_emlrtBCI, &c5_b_st);
    }
  }

  c5_b_st.site = &c5_mf_emlrtRSI;
  c5_handle_matlabCodegenDestructor(chartInstance, &c5_b_st, &c5_OpenList);
  c5_array_int32_T_Destructor(chartInstance, &c5_ii);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_r);
  c5_array_real_T_Destructor(chartInstance, &c5_expNodes);
  emlrtHeapReferenceStackLeaveFcnR2012b(&c5_st);
}

static void c5_plannerAStarGrid_getHeuristicMatrix
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_goalIn[2],
   real_T c5_Hn[213200])
{
  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  c5_nav_algs_internal_plannerAStarGrid *c5_b_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  real_T c5_c_obj[2];
  real_T c5_b_a;
  real_T c5_b_i;
  real_T c5_c_a;
  real_T c5_c_x;
  real_T c5_d_a;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_f_x;
  real_T c5_f_y;
  real_T c5_g_x;
  real_T c5_g_y;
  real_T c5_hcost;
  real_T c5_j_k;
  real_T c5_type;
  real_T c5_val;
  int32_T c5_b_ia;
  int32_T c5_b_ib;
  int32_T c5_b_ic;
  int32_T c5_b_itilerow;
  int32_T c5_b_ix;
  int32_T c5_b_jcol;
  int32_T c5_b_k;
  int32_T c5_b_varargin_1;
  int32_T c5_b_varargin_2;
  int32_T c5_b_varargin_3;
  int32_T c5_b_xj;
  int32_T c5_c_i;
  int32_T c5_c_ix;
  int32_T c5_c_k;
  int32_T c5_c_varargin_1;
  int32_T c5_c_varargin_2;
  int32_T c5_c_xj;
  int32_T c5_d_i;
  int32_T c5_d_k;
  int32_T c5_d_xj;
  int32_T c5_e_k;
  int32_T c5_e_xj;
  int32_T c5_f_k;
  int32_T c5_f_xj;
  int32_T c5_g_k;
  int32_T c5_g_xj;
  int32_T c5_h_k;
  int32_T c5_h_xj;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i_k;
  int32_T c5_i_xj;
  int32_T c5_ia;
  int32_T c5_iacol;
  int32_T c5_ib;
  int32_T c5_ibcol;
  int32_T c5_ibmat;
  int32_T c5_ic;
  int32_T c5_itilerow;
  int32_T c5_ix;
  int32_T c5_jcol;
  int32_T c5_k;
  int32_T c5_k_k;
  int32_T c5_l_k;
  int32_T c5_varargin_3;
  int32_T c5_varargin_4;
  int32_T c5_varargin_5;
  int32_T c5_varargin_6;
  int32_T c5_xj;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_guard1;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_obj->UseCustomH == 0.0) {
    c5_b_a = c5_obj->TieBreaker;
    for (c5_jcol = 0; c5_jcol < 2; c5_jcol++) {
      c5_b_jcol = c5_jcol;
      c5_iacol = c5_b_jcol;
      c5_ibmat = c5_b_jcol * 213200 - 1;
      for (c5_itilerow = 0; c5_itilerow < 213200; c5_itilerow++) {
        c5_b_itilerow = c5_itilerow;
        c5_ibcol = c5_ibmat + c5_b_itilerow;
        chartInstance->c5_b[c5_ibcol + 1] = c5_goalIn[c5_iacol];
      }
    }

    c5_st.site = &c5_of_emlrtRSI;
    c5_b_obj = c5_obj;
    for (c5_i1 = 0; c5_i1 < 426400; c5_i1++) {
      chartInstance->c5_pose1[c5_i1] = c5_obj->AllNodes[c5_i1];
    }

    c5_type = c5_obj->HCostMethod;
    if (c5_type != (real_T)(int32_T)muDoubleScalarFloor(c5_type)) {
      emlrtIntegerCheckR2012b(c5_type, &c5_xb_emlrtDCI, &c5_st);
    }

    switch ((int32_T)c5_type) {
     case 2:
      for (c5_k = 0; c5_k < 2; c5_k++) {
        c5_ia = c5_k;
        c5_ib = c5_k;
        c5_ic = c5_k;
        c5_b_varargin_1 = c5_ic + 1;
        c5_b_varargin_2 = c5_ia + 1;
        c5_varargin_3 = c5_ib + 1;
        for (c5_h_k = 0; c5_h_k < 213200; c5_h_k++) {
          c5_b_ia = c5_h_k;
          c5_b_ib = c5_h_k;
          c5_b_ic = c5_h_k;
          c5_c_varargin_1 = c5_b_ic;
          c5_c_varargin_2 = c5_b_varargin_1 - 1;
          c5_b_varargin_3 = c5_b_ia;
          c5_varargin_4 = c5_b_varargin_2 - 1;
          c5_varargin_5 = c5_b_ib;
          c5_varargin_6 = c5_varargin_3 - 1;
          chartInstance->c5_c[c5_c_varargin_1 + 213200 * c5_c_varargin_2] =
            chartInstance->c5_pose1[c5_b_varargin_3 + 213200 * c5_varargin_4] -
            chartInstance->c5_b[c5_varargin_5 + 213200 * c5_varargin_6];
        }
      }

      for (c5_b_k = 0; c5_b_k < 426400; c5_b_k++) {
        c5_e_k = c5_b_k;
        c5_e_x = chartInstance->c5_c[c5_e_k];
        c5_e_y = muDoubleScalarAbs(c5_e_x);
        chartInstance->c5_b[c5_e_k] = c5_e_y;
      }

      for (c5_xj = 0; c5_xj < 213200; c5_xj++) {
        c5_e_xj = c5_xj;
        c5_Hn[c5_e_xj] = chartInstance->c5_b[c5_e_xj];
      }

      for (c5_d_xj = 0; c5_d_xj < 213200; c5_d_xj++) {
        c5_e_xj = c5_d_xj;
        c5_ix = c5_e_xj;
        c5_Hn[c5_e_xj] += chartInstance->c5_b[c5_ix + 213200];
      }
      break;

     case 3:
      c5_plannerAStarGrid_Chebyshev(chartInstance, chartInstance->c5_pose1,
        chartInstance->c5_b, c5_Hn);
      break;

     case 4:
      for (c5_i2 = 0; c5_i2 < 426400; c5_i2++) {
        chartInstance->c5_pose1[c5_i2] -= chartInstance->c5_b[c5_i2];
      }

      for (c5_c_k = 0; c5_c_k < 426400; c5_c_k++) {
        c5_f_k = c5_c_k;
        c5_c_a = chartInstance->c5_pose1[c5_f_k];
        c5_f_y = c5_c_a * c5_c_a;
        chartInstance->c5_b[c5_f_k] = c5_f_y;
      }

      for (c5_b_xj = 0; c5_b_xj < 213200; c5_b_xj++) {
        c5_g_xj = c5_b_xj;
        c5_Hn[c5_g_xj] = chartInstance->c5_b[c5_g_xj];
      }

      for (c5_f_xj = 0; c5_f_xj < 213200; c5_f_xj++) {
        c5_g_xj = c5_f_xj;
        c5_b_ix = c5_g_xj;
        c5_Hn[c5_g_xj] += chartInstance->c5_b[c5_b_ix + 213200];
      }
      break;

     default:
      c5_b_st.site = &c5_rf_emlrtRSI;
      for (c5_i3 = 0; c5_i3 < 426400; c5_i3++) {
        chartInstance->c5_pose1[c5_i3] -= chartInstance->c5_b[c5_i3];
      }

      for (c5_d_k = 0; c5_d_k < 426400; c5_d_k++) {
        c5_g_k = c5_d_k;
        c5_d_a = chartInstance->c5_pose1[c5_g_k];
        c5_g_y = c5_d_a * c5_d_a;
        chartInstance->c5_b[c5_g_k] = c5_g_y;
      }

      for (c5_c_xj = 0; c5_c_xj < 213200; c5_c_xj++) {
        c5_i_xj = c5_c_xj;
        c5_Hn[c5_i_xj] = chartInstance->c5_b[c5_i_xj];
      }

      for (c5_h_xj = 0; c5_h_xj < 213200; c5_h_xj++) {
        c5_i_xj = c5_h_xj;
        c5_c_ix = c5_i_xj;
        c5_Hn[c5_i_xj] += chartInstance->c5_b[c5_c_ix + 213200];
      }

      c5_c_st.site = &c5_sf_emlrtRSI;
      c5_p = false;
      for (c5_i_k = 0; c5_i_k < 213200; c5_i_k++) {
        c5_j_k = (real_T)c5_i_k + 1.0;
        if (c5_p || (c5_Hn[(int32_T)c5_j_k - 1] < 0.0)) {
          c5_b_p = true;
        } else {
          c5_b_p = false;
        }

        c5_p = c5_b_p;
      }

      if (c5_p) {
        c5_i_y = NULL;
        sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c5_j_y = NULL;
        sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c5_k_y = NULL;
        sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1,
          4), false);
        sf_mex_call(&c5_c_st, &c5_r_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                    sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_j_y, 14, c5_k_y)));
      }

      for (c5_k_k = 0; c5_k_k < 213200; c5_k_k++) {
        c5_l_k = c5_k_k;
        c5_f_x = c5_Hn[c5_l_k];
        c5_g_x = c5_f_x;
        c5_g_x = muDoubleScalarSqrt(c5_g_x);
        c5_Hn[c5_l_k] = c5_g_x;
      }
      break;
    }

    for (c5_i4 = 0; c5_i4 < 213200; c5_i4++) {
      c5_Hn[c5_i4] /= c5_b_obj->MapResolution;
    }

    for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
      c5_Hn[c5_i5] *= c5_b_a;
    }
  } else {
    for (c5_i = 0; c5_i < 213200; c5_i++) {
      c5_b_i = (real_T)c5_i + 1.0;
      c5_c_i = (int32_T)c5_b_i - 1;
      for (c5_d_i = 0; c5_d_i < 2; c5_d_i++) {
        c5_c_obj[c5_d_i] = c5_obj->AllNodes[c5_c_i + 213200 * c5_d_i];
      }

      c5_st.site = &c5_pf_emlrtRSI;
      c5_hcost = c5_obj->TieBreaker * c5_plannerAStarGrid_Euclidean
        (chartInstance, &c5_st, c5_c_obj, c5_goalIn) / c5_obj->MapResolution;
      c5_st.site = &c5_qf_emlrtRSI;
      c5_val = c5_hcost;
      c5_c_x = c5_val;
      c5_b_b = muDoubleScalarIsNaN(c5_c_x);
      c5_guard1 = false;
      if (c5_b_b) {
        c5_guard1 = true;
      } else {
        c5_d_x = c5_val;
        c5_c_b = muDoubleScalarIsInf(c5_d_x);
        if (c5_c_b) {
          c5_guard1 = true;
        }
      }

      if (c5_guard1) {
        c5_d_y = NULL;
        sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1,
          64), false);
        c5_h_y = NULL;
        sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1,
          64), false);
        sf_mex_call(&c5_st, &c5_s_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                    sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_st, NULL, "message", 1U, 1U, 14, c5_h_y)));
      }

      c5_Hn[(int32_T)c5_b_i - 1] = c5_hcost;
    }
  }
}

static void c5_plannerAStarGrid_Chebyshev
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, real_T
   c5_b_pose1[426400], real_T c5_pose2[426400], real_T c5_dist[213200])
{
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_ex;
  real_T c5_f_y;
  int32_T c5_b_ia;
  int32_T c5_b_ib;
  int32_T c5_b_ic;
  int32_T c5_b_k;
  int32_T c5_b_varargin_1;
  int32_T c5_b_varargin_2;
  int32_T c5_b_varargin_3;
  int32_T c5_b_xj;
  int32_T c5_c_k;
  int32_T c5_c_varargin_1;
  int32_T c5_c_varargin_2;
  int32_T c5_c_xj;
  int32_T c5_d_k;
  int32_T c5_e_k;
  int32_T c5_f_k;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_ia;
  int32_T c5_ib;
  int32_T c5_ic;
  int32_T c5_ix;
  int32_T c5_k;
  int32_T c5_varargin_3;
  int32_T c5_varargin_4;
  int32_T c5_varargin_5;
  int32_T c5_varargin_6;
  int32_T c5_xj;
  for (c5_k = 0; c5_k < 2; c5_k++) {
    c5_ia = c5_k;
    c5_ib = c5_k;
    c5_ic = c5_k;
    c5_b_varargin_1 = c5_ic + 1;
    c5_b_varargin_2 = c5_ia + 1;
    c5_varargin_3 = c5_ib + 1;
    for (c5_e_k = 0; c5_e_k < 213200; c5_e_k++) {
      c5_b_ia = c5_e_k;
      c5_b_ib = c5_e_k;
      c5_b_ic = c5_e_k;
      c5_c_varargin_1 = c5_b_ic;
      c5_c_varargin_2 = c5_b_varargin_1 - 1;
      c5_b_varargin_3 = c5_b_ia;
      c5_varargin_4 = c5_b_varargin_2 - 1;
      c5_varargin_5 = c5_b_ib;
      c5_varargin_6 = c5_varargin_3 - 1;
      chartInstance->c5_b_c[c5_c_varargin_1 + 213200 * c5_c_varargin_2] =
        c5_b_pose1[c5_b_varargin_3 + 213200 * c5_varargin_4] -
        c5_pose2[c5_varargin_5 + 213200 * c5_varargin_6];
    }
  }

  for (c5_b_k = 0; c5_b_k < 426400; c5_b_k++) {
    c5_c_k = c5_b_k;
    c5_c_x = chartInstance->c5_b_c[c5_c_k];
    c5_d_y = muDoubleScalarAbs(c5_c_x);
    chartInstance->c5_difference[c5_c_k] = c5_d_y;
  }

  for (c5_i = 0; c5_i < 213200; c5_i++) {
    chartInstance->c5_varargin_1[c5_i] = chartInstance->c5_difference[c5_i];
  }

  for (c5_i1 = 0; c5_i1 < 213200; c5_i1++) {
    chartInstance->c5_varargin_2[c5_i1] = chartInstance->c5_difference[c5_i1 +
      213200];
  }

  for (c5_d_k = 0; c5_d_k < 213200; c5_d_k++) {
    c5_f_k = c5_d_k;
    c5_d_x = chartInstance->c5_varargin_1[c5_f_k];
    c5_e_y = chartInstance->c5_varargin_2[c5_f_k];
    c5_e_x = c5_d_x;
    c5_f_y = c5_e_y;
    c5_ex = muDoubleScalarMin(c5_e_x, c5_f_y);
    chartInstance->c5_minval[c5_f_k] = c5_ex;
  }

  for (c5_xj = 0; c5_xj < 213200; c5_xj++) {
    c5_c_xj = c5_xj;
    c5_dist[c5_c_xj] = chartInstance->c5_difference[c5_c_xj];
  }

  for (c5_b_xj = 0; c5_b_xj < 213200; c5_b_xj++) {
    c5_c_xj = c5_b_xj;
    c5_ix = c5_c_xj;
    c5_dist[c5_c_xj] += chartInstance->c5_difference[c5_ix + 213200];
  }

  for (c5_i2 = 0; c5_i2 < 213200; c5_i2++) {
    c5_dist[c5_i2] -= chartInstance->c5_minval[c5_i2];
  }
}

static real_T c5_plannerAStarGrid_Euclidean
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, real_T c5_b_pose1[2], real_T c5_pose2[2])
{
  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  emlrtStack c5_st;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  real_T c5_b_a[2];
  real_T c5_e_y[2];
  real_T c5_c_a;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_d_y;
  real_T c5_dist;
  real_T c5_f_y;
  int32_T c5_b_k;
  int32_T c5_i;
  int32_T c5_k;
  boolean_T c5_b_p;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_b_a[c5_i] = c5_b_pose1[c5_i] - c5_pose2[c5_i];
  }

  for (c5_k = 0; c5_k < 2; c5_k++) {
    c5_b_k = c5_k;
    c5_c_a = c5_b_a[c5_b_k];
    c5_f_y = c5_c_a * c5_c_a;
    c5_e_y[c5_b_k] = c5_f_y;
  }

  c5_d_y = c5_sumColumnB(chartInstance, c5_e_y);
  c5_st.site = &c5_tf_emlrtRSI;
  c5_c_x = c5_d_y;
  c5_dist = c5_c_x;
  c5_d_x = c5_dist;
  if (c5_d_x < 0.0) {
    c5_p = true;
  } else {
    c5_p = false;
  }

  c5_b_p = c5_p;
  if (c5_b_p) {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(&c5_st, &c5_r_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_st, NULL, "message", 1U, 2U, 14, c5_h_y, 14, c5_i_y)));
  }

  return muDoubleScalarSqrt(c5_dist);
}

static real_T c5_sumColumnB(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, real_T c5_c_x[2])
{
  real_T c5_d_y;
  (void)chartInstance;
  c5_d_y = c5_c_x[0];
  c5_d_y += c5_c_x[1];
  return c5_d_y;
}

static real_T c5_sqrt(SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T c5_c_x)
{
  real_T c5_d_x;
  c5_d_x = c5_c_x;
  c5_b_sqrt(chartInstance, c5_sp, &c5_d_x);
  return c5_d_x;
}

static void c5_plannerAStarGrid_getNeighbors
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T
   c5_Neighbors_data[], int32_T c5_Neighbors_size[2], real_T *c5_NumNeighbors)
{
  static real_T c5_Neighbors[16] = { -1.0, 0.0, 1.0, -1.0, 1.0, -1.0, 0.0, 1.0,
    -1.0, -1.0, -1.0, 0.0, 0.0, 1.0, 1.0, 1.0 };

  static real_T c5_b_Neighbors[8] = { 0.0, -1.0, 1.0, 0.0, -1.0, 0.0, 0.0, 1.0 };

  int32_T c5_i;
  int32_T c5_i1;
  (void)chartInstance;
  if (c5_obj->DiagonalSearchFlag != (real_T)(int32_T)muDoubleScalarFloor
      (c5_obj->DiagonalSearchFlag)) {
    emlrtIntegerCheckR2012b(c5_obj->DiagonalSearchFlag, &c5_yb_emlrtDCI,
      (emlrtConstCTX)c5_sp);
  }

  if ((int32_T)c5_obj->DiagonalSearchFlag == 0) {
    c5_Neighbors_size[0] = 4;
    c5_Neighbors_size[1] = 2;
    for (c5_i1 = 0; c5_i1 < 8; c5_i1++) {
      c5_Neighbors_data[c5_i1] = c5_b_Neighbors[c5_i1];
    }

    *c5_NumNeighbors = 4.0;
  } else {
    c5_Neighbors_size[0] = 8;
    c5_Neighbors_size[1] = 2;
    for (c5_i = 0; c5_i < 16; c5_i++) {
      c5_Neighbors_data[c5_i] = c5_Neighbors[c5_i];
    }

    *c5_NumNeighbors = 8.0;
  }
}

static void c5_plannerAStarGrid_reconstructPath
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_CurrentRow,
   real_T c5_CurrentCol, real_T c5_startIn[2])
{
  static char_T c5_b_cv[16] = { 'P', 'a', 't', 'h', 'P', 'o', 'i', 'n', 't', 'C',
    'o', 'u', 'n', 't', 'e', 'r' };

  c5_coder_array_int32_T c5_r;
  c5_coder_array_real_T c5_d_x;
  c5_coder_array_real_T_2D c5_c_x;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  real_T c5_CurrentColDummy;
  real_T c5_b_tmp;
  real_T c5_k;
  real_T c5_tmp;
  real_T c5_u;
  int32_T c5_iv[2];
  int32_T c5_iv1[2];
  int32_T c5_iv2[1];
  int32_T c5_iv3[1];
  int32_T c5_b_k;
  int32_T c5_b_loop_ub;
  int32_T c5_b_n;
  int32_T c5_b_nd2;
  int32_T c5_c_k;
  int32_T c5_c_loop_ub;
  int32_T c5_d_k;
  int32_T c5_d_loop_ub;
  int32_T c5_e_k;
  int32_T c5_e_loop_ub;
  int32_T c5_exitg1;
  int32_T c5_f_k;
  int32_T c5_f_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_j;
  int32_T c5_loop_ub;
  int32_T c5_n;
  int32_T c5_nd2;
  int32_T c5_offset;
  int32_T c5_vlen;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_k = 1.0;
  chartInstance->c5_OptimalPath[0] = c5_CurrentRow;
  chartInstance->c5_OptimalPath[213200] = c5_CurrentCol;
  if (c5_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor(c5_CurrentRow)) {
    emlrtIntegerCheckR2012b(c5_CurrentRow, &c5_ac_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_i = (int32_T)c5_CurrentRow;
  if ((c5_i < 1) || (c5_i > 410)) {
    emlrtDynamicBoundsCheckR2012b(c5_i, 1, 410, &c5_yd_emlrtBCI, (emlrtConstCTX)
      c5_sp);
  }

  if (c5_CurrentCol != (real_T)(int32_T)muDoubleScalarFloor(c5_CurrentCol)) {
    emlrtIntegerCheckR2012b(c5_CurrentCol, &c5_bc_emlrtDCI, (emlrtConstCTX)c5_sp);
  }

  c5_i1 = (int32_T)c5_CurrentCol;
  if ((c5_i1 < 1) || (c5_i1 > 520)) {
    emlrtDynamicBoundsCheckR2012b(c5_i1, 1, 520, &c5_ae_emlrtBCI, (emlrtConstCTX)
      c5_sp);
  }

  chartInstance->c5_pathIndices[0] = c5_obj->MapIndex[(c5_i + 410 * (c5_i1 - 1))
    - 1];
  do {
    c5_exitg1 = 0;
    c5_k++;
    if (!(c5_k <= 213200.0)) {
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                    false);
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                    false);
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 16),
                    false);
      c5_u = 213200.0;
      c5_g_y = NULL;
      sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_u, 0, 0U, 0, 0U, 0), false);
      sf_mex_call(c5_sp, &c5_u_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                  sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c5_sp, NULL, "message", 1U, 3U, 14, c5_e_y, 14, c5_f_y, 14, c5_g_y)));
    }

    c5_CurrentColDummy = c5_obj->ParentCol[((int32_T)c5_CurrentRow + 410 *
      ((int32_T)c5_CurrentCol - 1)) - 1];
    c5_CurrentRow = c5_obj->ParentRow[((int32_T)c5_CurrentRow + 410 * ((int32_T)
      c5_CurrentCol - 1)) - 1];
    c5_CurrentCol = c5_CurrentColDummy;
    if ((c5_CurrentRow == 0.0) || (c5_CurrentColDummy == 0.0)) {
      c5_k--;
      c5_exitg1 = 1;
    } else {
      c5_b_k = (int32_T)c5_k - 1;
      chartInstance->c5_OptimalPath[c5_b_k] = c5_CurrentRow;
      chartInstance->c5_OptimalPath[213200 + c5_b_k] = c5_CurrentColDummy;
      if (c5_CurrentRow != (real_T)(int32_T)muDoubleScalarFloor(c5_CurrentRow))
      {
        emlrtIntegerCheckR2012b(c5_CurrentRow, &c5_cc_emlrtDCI, (emlrtConstCTX)
          c5_sp);
      }

      c5_i2 = (int32_T)c5_CurrentRow;
      if ((c5_i2 < 1) || (c5_i2 > 410)) {
        emlrtDynamicBoundsCheckR2012b(c5_i2, 1, 410, &c5_be_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      if (c5_CurrentColDummy != (real_T)(int32_T)muDoubleScalarFloor
          (c5_CurrentColDummy)) {
        emlrtIntegerCheckR2012b(c5_CurrentColDummy, &c5_dc_emlrtDCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i5 = (int32_T)c5_CurrentColDummy;
      if ((c5_i5 < 1) || (c5_i5 > 520)) {
        emlrtDynamicBoundsCheckR2012b(c5_i5, 1, 520, &c5_ce_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      chartInstance->c5_pathIndices[(int32_T)c5_k - 1] = c5_obj->MapIndex[(c5_i2
        + 410 * (c5_i5 - 1)) - 1];
      if ((c5_CurrentColDummy == c5_startIn[1]) && (c5_CurrentRow == c5_startIn
           [0])) {
        c5_exitg1 = 1;
      }
    }
  } while (c5_exitg1 == 0);

  c5_obj->NumPathPoints = c5_k;
  c5_i3 = (int32_T)c5_k - 1;
  c5_i4 = (int32_T)c5_k - 1;
  c5_array_int32_T_Constructor(chartInstance, &c5_r);
  c5_st.site = &c5_hh_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_ob_emlrtRTEI, c5_i4
    + 1);
  c5_loop_ub = c5_i4;
  for (c5_i6 = 0; c5_i6 <= c5_loop_ub; c5_i6++) {
    c5_r.vector.data[c5_i6] = c5_i6;
  }

  c5_array_real_T_2D_Constructor(chartInstance, &c5_c_x);
  c5_st.site = &c5_hh_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_c_x, &c5_pb_emlrtRTEI,
    c5_i3 + 1, 2);
  for (c5_i7 = 0; c5_i7 < 2; c5_i7++) {
    c5_b_loop_ub = c5_i3;
    for (c5_i8 = 0; c5_i8 <= c5_b_loop_ub; c5_i8++) {
      c5_c_x.vector.data[c5_i8 + c5_c_x.size[0] * c5_i7] =
        chartInstance->c5_OptimalPath[c5_i8 + 213200 * c5_i7];
    }
  }

  if ((real_T)c5_c_x.size[0] > 1.0) {
    c5_vlen = c5_c_x.size[0];
    c5_n = c5_c_x.size[0];
    c5_nd2 = (c5_n >> 1) - 1;
    for (c5_j = 0; c5_j < 2; c5_j++) {
      c5_offset = c5_j * c5_vlen;
      for (c5_c_k = 0; c5_c_k <= c5_nd2; c5_c_k++) {
        c5_d_k = c5_c_k;
        c5_tmp = c5_c_x.vector.data[c5_offset + c5_d_k];
        c5_c_x.vector.data[c5_offset + c5_d_k] = c5_c_x.vector.data[((c5_offset
          + c5_n) - c5_d_k) - 1];
        c5_c_x.vector.data[((c5_offset + c5_n) - c5_d_k) - 1] = c5_tmp;
      }
    }
  }

  c5_iv[0] = c5_r.size[0];
  c5_iv[1] = 2;
  emlrtSubAssignSizeCheckR2012b(&c5_iv[0], 2, &c5_c_x.size[0], 2, &c5_f_emlrtECI,
    (void *)c5_sp);
  c5_iv1[0] = c5_r.size[0];
  for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
    c5_c_loop_ub = c5_iv1[0] - 1;
    for (c5_i11 = 0; c5_i11 <= c5_c_loop_ub; c5_i11++) {
      c5_obj->PathInternal[c5_r.vector.data[c5_i11] + 213200 * c5_i9] =
        c5_c_x.vector.data[c5_i11 + c5_c_x.size[0] * c5_i9];
    }
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_c_x);
  c5_i10 = (int32_T)c5_k - 1;
  c5_i12 = (int32_T)c5_k - 1;
  c5_st.site = &c5_eh_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_qb_emlrtRTEI,
    c5_i12 + 1);
  c5_d_loop_ub = c5_i12;
  for (c5_i13 = 0; c5_i13 <= c5_d_loop_ub; c5_i13++) {
    c5_r.vector.data[c5_i13] = c5_i13;
  }

  c5_array_real_T_Constructor(chartInstance, &c5_d_x);
  c5_st.site = &c5_eh_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_d_x, &c5_rb_emlrtRTEI,
    c5_i10 + 1);
  c5_e_loop_ub = c5_i10;
  for (c5_i14 = 0; c5_i14 <= c5_e_loop_ub; c5_i14++) {
    c5_d_x.vector.data[c5_i14] = chartInstance->c5_pathIndices[c5_i14];
  }

  if ((real_T)c5_d_x.size[0] > 1.0) {
    c5_b_n = c5_d_x.size[0];
    c5_b_nd2 = (c5_b_n >> 1) - 1;
    for (c5_e_k = 0; c5_e_k <= c5_b_nd2; c5_e_k++) {
      c5_f_k = c5_e_k;
      c5_b_tmp = c5_d_x.vector.data[c5_f_k];
      c5_d_x.vector.data[c5_f_k] = c5_d_x.vector.data[(c5_b_n - c5_f_k) - 1];
      c5_d_x.vector.data[(c5_b_n - c5_f_k) - 1] = c5_b_tmp;
    }
  }

  c5_iv2[0] = c5_r.size[0];
  emlrtSubAssignSizeCheckR2012b(&c5_iv2[0], 1, &c5_d_x.size[0], 1,
    &c5_e_emlrtECI, (void *)c5_sp);
  c5_iv3[0] = c5_r.size[0];
  c5_f_loop_ub = c5_iv3[0] - 1;
  for (c5_i15 = 0; c5_i15 <= c5_f_loop_ub; c5_i15++) {
    c5_obj->PathIndicesInternal[c5_r.vector.data[c5_i15]] =
      c5_d_x.vector.data[c5_i15];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_d_x);
  c5_array_int32_T_Destructor(chartInstance, &c5_r);
}

static real_T c5_plannerAStarGrid_gcostValue
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_plannerAStarGrid *c5_obj, real_T c5_CurrentRow,
   real_T c5_CurrentCol, real_T c5_i, real_T c5_j)
{
  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  c5_nav_algs_internal_plannerAStarGrid *c5_b_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_o_y = NULL;
  const mxArray *c5_q_y = NULL;
  const mxArray *c5_s_y = NULL;
  real_T c5_b_CurrentRow[2];
  real_T c5_b_difference[2];
  real_T c5_c_CurrentRow[2];
  real_T c5_c_c[2];
  real_T c5_d_y[2];
  real_T c5_b_a;
  real_T c5_b_minval;
  real_T c5_b_varargin_2;
  real_T c5_c_a;
  real_T c5_c_varargin_1;
  real_T c5_c_x;
  real_T c5_d_a;
  real_T c5_d_b;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_e_y;
  real_T c5_f_x;
  real_T c5_f_y;
  real_T c5_g_x;
  real_T c5_g_y;
  real_T c5_gcostNeighbor;
  real_T c5_h_x;
  real_T c5_h_y;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_j_y;
  real_T c5_k_x;
  real_T c5_k_y;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_m_y;
  real_T c5_n_y;
  real_T c5_p_y;
  real_T c5_r_y;
  real_T c5_t_y;
  real_T c5_type;
  real_T c5_val;
  int32_T c5_b_i;
  int32_T c5_b_ib;
  int32_T c5_b_ic;
  int32_T c5_b_k;
  int32_T c5_b_varargin_1;
  int32_T c5_b_varargin_3;
  int32_T c5_b_varargin_6;
  int32_T c5_c_k;
  int32_T c5_c_varargin_2;
  int32_T c5_d_k;
  int32_T c5_d_varargin_1;
  int32_T c5_d_varargin_2;
  int32_T c5_e_k;
  int32_T c5_f_k;
  int32_T c5_g_k;
  int32_T c5_h_k;
  int32_T c5_i1;
  int32_T c5_i_k;
  int32_T c5_ib;
  int32_T c5_ic;
  int32_T c5_j_k;
  int32_T c5_k;
  int32_T c5_varargin_3;
  int32_T c5_varargin_6;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_guard1;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  if (c5_obj->UseCustomG == 0.0) {
    c5_st.site = &c5_vf_emlrtRSI;
    c5_b_obj = c5_obj;
    c5_b_difference[0] = c5_i;
    c5_b_difference[1] = c5_j;
    c5_type = c5_obj->GCostMethod;
    if (c5_type != (real_T)(int32_T)muDoubleScalarFloor(c5_type)) {
      emlrtIntegerCheckR2012b(c5_type, &c5_xb_emlrtDCI, &c5_st);
    }

    switch ((int32_T)c5_type) {
     case 2:
      for (c5_k = 0; c5_k < 2; c5_k++) {
        c5_ib = c5_k;
        c5_ic = c5_k;
        c5_b_varargin_1 = c5_ic + 1;
        c5_varargin_3 = c5_ib + 1;
        c5_c_varargin_2 = c5_b_varargin_1 - 1;
        c5_varargin_6 = c5_varargin_3 - 1;
        c5_c_c[c5_c_varargin_2] = 0.0 - c5_b_difference[c5_varargin_6];
      }

      for (c5_c_k = 0; c5_c_k < 2; c5_c_k++) {
        c5_g_k = c5_c_k;
        c5_e_x = c5_c_c[c5_g_k];
        c5_f_y = muDoubleScalarAbs(c5_e_x);
        c5_d_y[c5_g_k] = c5_f_y;
      }

      c5_gcostNeighbor = c5_sumColumnB(chartInstance, c5_d_y);
      break;

     case 3:
      for (c5_b_k = 0; c5_b_k < 2; c5_b_k++) {
        c5_b_ib = c5_b_k;
        c5_b_ic = c5_b_k;
        c5_d_varargin_1 = c5_b_ic + 1;
        c5_b_varargin_3 = c5_b_ib + 1;
        c5_d_varargin_2 = c5_d_varargin_1 - 1;
        c5_b_varargin_6 = c5_b_varargin_3 - 1;
        c5_c_c[c5_d_varargin_2] = 0.0 - c5_b_difference[c5_b_varargin_6];
      }

      for (c5_d_k = 0; c5_d_k < 2; c5_d_k++) {
        c5_h_k = c5_d_k;
        c5_f_x = c5_c_c[c5_h_k];
        c5_g_y = muDoubleScalarAbs(c5_f_x);
        c5_b_difference[c5_h_k] = c5_g_y;
      }

      c5_c_varargin_1 = c5_b_difference[0];
      c5_b_varargin_2 = c5_b_difference[1];
      c5_g_x = c5_c_varargin_1;
      c5_k_y = c5_b_varargin_2;
      c5_i_x = c5_g_x;
      c5_m_y = c5_k_y;
      c5_k_x = c5_i_x;
      c5_n_y = c5_m_y;
      c5_d_a = c5_k_x;
      c5_d_b = c5_n_y;
      c5_l_x = c5_d_a;
      c5_p_y = c5_d_b;
      c5_m_x = c5_l_x;
      c5_r_y = c5_p_y;
      c5_b_minval = muDoubleScalarMin(c5_m_x, c5_r_y);
      c5_t_y = c5_sumColumnB(chartInstance, c5_b_difference);
      c5_gcostNeighbor = c5_t_y - c5_b_minval;
      break;

     case 4:
      for (c5_b_i = 0; c5_b_i < 2; c5_b_i++) {
        c5_b_difference[c5_b_i] = -c5_b_difference[c5_b_i];
      }

      for (c5_e_k = 0; c5_e_k < 2; c5_e_k++) {
        c5_i_k = c5_e_k;
        c5_b_a = c5_b_difference[c5_i_k];
        c5_h_y = c5_b_a * c5_b_a;
        c5_d_y[c5_i_k] = c5_h_y;
      }

      c5_gcostNeighbor = c5_sumColumnB(chartInstance, c5_d_y);
      break;

     default:
      c5_b_st.site = &c5_rf_emlrtRSI;
      for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
        c5_b_difference[c5_i1] = -c5_b_difference[c5_i1];
      }

      for (c5_f_k = 0; c5_f_k < 2; c5_f_k++) {
        c5_j_k = c5_f_k;
        c5_c_a = c5_b_difference[c5_j_k];
        c5_j_y = c5_c_a * c5_c_a;
        c5_d_y[c5_j_k] = c5_j_y;
      }

      c5_e_y = c5_sumColumnB(chartInstance, c5_d_y);
      c5_c_st.site = &c5_sf_emlrtRSI;
      c5_h_x = c5_e_y;
      c5_gcostNeighbor = c5_h_x;
      c5_j_x = c5_gcostNeighbor;
      if (c5_j_x < 0.0) {
        c5_p = true;
      } else {
        c5_p = false;
      }

      c5_b_p = c5_p;
      if (c5_b_p) {
        c5_o_y = NULL;
        sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c5_q_y = NULL;
        sf_mex_assign(&c5_q_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1,
          30), false);
        c5_s_y = NULL;
        sf_mex_assign(&c5_s_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1,
          4), false);
        sf_mex_call(&c5_c_st, &c5_r_emlrtMCI, "error", 0U, 2U, 14, c5_o_y, 14,
                    sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
          sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_q_y, 14, c5_s_y)));
      }

      c5_gcostNeighbor = muDoubleScalarSqrt(c5_gcostNeighbor);
      break;
    }

    c5_gcostNeighbor /= c5_b_obj->MapResolution;
  } else {
    c5_b_CurrentRow[0] = c5_CurrentRow;
    c5_b_CurrentRow[1] = c5_CurrentCol;
    c5_c_CurrentRow[0] = c5_CurrentRow + c5_i;
    c5_c_CurrentRow[1] = c5_CurrentCol + c5_j;
    c5_st.site = &c5_wf_emlrtRSI;
    c5_gcostNeighbor = c5_plannerAStarGrid_Euclidean(chartInstance, &c5_st,
      c5_b_CurrentRow, c5_c_CurrentRow) / c5_obj->MapResolution;
    c5_st.site = &c5_xf_emlrtRSI;
    c5_val = c5_gcostNeighbor;
    c5_c_x = c5_val;
    c5_b_b = muDoubleScalarIsNaN(c5_c_x);
    c5_guard1 = false;
    if (c5_b_b) {
      c5_guard1 = true;
    } else {
      c5_d_x = c5_val;
      c5_c_b = muDoubleScalarIsInf(c5_d_x);
      if (c5_c_b) {
        c5_guard1 = true;
      }
    }

    if (c5_guard1) {
      c5_i_y = NULL;
      sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 64),
                    false);
      c5_l_y = NULL;
      sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_cv5, 10, 0U, 1, 0U, 2, 1, 64),
                    false);
      sf_mex_call(&c5_st, &c5_s_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                  sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c5_st, NULL, "message", 1U, 1U, 14, c5_l_y)));
    }
  }

  return c5_gcostNeighbor;
}

static void c5_indexShapeCheck(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_plannerAStarGrid_getEssentialOutput
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_nav_algs_internal_plannerAStarGrid
   *c5_b_astarInternal)
{
  static char_T c5_b_cv[12] = { 'N', 'u', 'm', 'P', 'a', 't', 'h', 'N', 'o', 'd',
    'e', 's' };

  c5_coder_array_int32_T c5_r;
  c5_coder_array_real_T c5_path;
  c5_nav_algs_internal_plannerAStarGrid *c5_b_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_c_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_d_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_e_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_f_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_g_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_h_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_i_obj;
  c5_nav_algs_internal_plannerAStarGrid *c5_j_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  real_T c5_H;
  real_T c5_b_H;
  real_T c5_b_k;
  real_T c5_b_numNodes;
  real_T c5_b_path;
  real_T c5_b_u;
  real_T c5_cost;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_numNodes;
  real_T c5_u;
  int32_T c5_iv[1];
  int32_T c5_iv1[1];
  int32_T c5_iv2[1];
  int32_T c5_iv3[1];
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_f_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_k;
  int32_T c5_loop_ub;
  boolean_T c5_c_x[2];
  boolean_T c5_x_data[2];
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b_b;
  boolean_T c5_d_y;
  boolean_T c5_exitg1;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_st.site = &c5_jg_emlrtRSI;
  c5_b_obj = c5_b_astarInternal;
  c5_b_st.site = &c5_kg_emlrtRSI;
  c5_c_obj = c5_b_obj;
  c5_d = c5_c_obj->NumPathPoints;
  c5_b_b = (c5_d < 1.0);
  if (c5_b_b) {
    c5_i = -1;
  } else {
    if (c5_d != (real_T)(int32_T)muDoubleScalarFloor(c5_d)) {
      emlrtIntegerCheckR2012b(c5_d, &c5_hc_emlrtDCI, &c5_b_st);
    }

    c5_i1 = (int32_T)c5_d;
    if ((c5_i1 < 1) || (c5_i1 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i1, 1, 213200, &c5_he_emlrtBCI, &c5_b_st);
    }

    c5_i = c5_i1 - 1;
  }

  c5_array_real_T_Constructor(chartInstance, &c5_path);
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_path, &c5_sb_emlrtRTEI,
    c5_i + 1);
  c5_loop_ub = c5_i;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_path.vector.data[c5_i2] = c5_c_obj->PathIndicesInternal[c5_i2];
  }

  c5_H = (real_T)c5_path.size[0];
  c5_obj->NumPathPoints = c5_H;
  c5_st.site = &c5_ig_emlrtRSI;
  c5_d_obj = c5_b_astarInternal;
  c5_b_st.site = &c5_lg_emlrtRSI;
  c5_e_obj = c5_d_obj;
  c5_d1 = c5_e_obj->NumNodesExplored;
  c5_b1 = (c5_d1 < 1.0);
  if (!c5_b1) {
    if (c5_d1 != (real_T)(int32_T)muDoubleScalarFloor(c5_d1)) {
      emlrtIntegerCheckR2012b(c5_d1, &c5_t_emlrtDCI, &c5_b_st);
    }

    c5_i3 = (int32_T)c5_d1;
    if ((c5_i3 < 1) || (c5_i3 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i3, 1, 213200, &c5_rb_emlrtBCI, &c5_b_st);
    }
  }

  c5_st.site = &c5_hg_emlrtRSI;
  c5_f_obj = c5_b_astarInternal;
  c5_numNodes = c5_f_obj->NumNodesExplored;
  c5_obj->NumNodesExplored = c5_numNodes;
  if (c5_obj->NumPathPoints == 0.0) {
    c5_obj->PathCost = rtInf;
    c5_st.site = &c5_gg_emlrtRSI;
    c5_warning(chartInstance, &c5_st);
  } else {
    c5_st.site = &c5_fg_emlrtRSI;
    c5_g_obj = c5_b_astarInternal;
    c5_cost = c5_g_obj->PathCost;
    c5_obj->PathCost = c5_cost;
  }

  c5_b_path = (real_T)c5_path.size[0];
  c5_c_x[0] = (c5_b_path <= 213200.0);
  c5_c_x[1] = true;
  for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
    c5_x_data[c5_i4] = c5_c_x[c5_i4];
  }

  c5_d_y = true;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k < 2)) {
    c5_b_k = (real_T)c5_k + 1.0;
    if (!c5_x_data[(int32_T)c5_b_k - 1]) {
      c5_d_y = false;
      c5_exitg1 = true;
    } else {
      c5_k++;
    }
  }

  if (!c5_d_y) {
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 12),
                  false);
    c5_u = 213200.0;
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(c5_sp, &c5_w_emlrtMCI, "error", 0U, 2U, 14, c5_e_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 3U, 14, c5_f_y, 14, c5_g_y, 14, c5_h_y)));
  }

  c5_b_H = (real_T)c5_path.size[0];
  c5_obj->NumPathPoints = c5_b_H;
  for (c5_i5 = 0; c5_i5 < 213200; c5_i5++) {
    chartInstance->c5_pathTemp[c5_i5] = 0.0;
  }

  c5_d2 = c5_obj->NumPathPoints;
  c5_b2 = (c5_d2 < 1.0);
  if (c5_b2) {
    c5_i7 = -1;
  } else {
    c5_i6 = c5_path.size[0];
    c5_i8 = 1;
    if ((c5_i8 < 1) || (c5_i8 > c5_i6)) {
      emlrtDynamicBoundsCheckR2012b(c5_i8, 1, c5_i6, &c5_ge_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_i9 = c5_path.size[0];
    if (c5_d2 != (real_T)(int32_T)muDoubleScalarFloor(c5_d2)) {
      emlrtIntegerCheckR2012b(c5_d2, &c5_gc_emlrtDCI, (emlrtConstCTX)c5_sp);
    }

    c5_i11 = (int32_T)c5_d2;
    if ((c5_i11 < 1) || (c5_i11 > c5_i9)) {
      emlrtDynamicBoundsCheckR2012b(c5_i11, 1, c5_i9, &c5_fe_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_i7 = c5_i11 - 1;
  }

  c5_d3 = c5_obj->NumPathPoints;
  c5_b3 = (c5_d3 < 1.0);
  if (c5_b3) {
    c5_i10 = -1;
  } else {
    if (c5_d3 != (real_T)(int32_T)muDoubleScalarFloor(c5_d3)) {
      emlrtIntegerCheckR2012b(c5_d3, &c5_fc_emlrtDCI, (emlrtConstCTX)c5_sp);
    }

    c5_i12 = (int32_T)c5_d3;
    if ((c5_i12 < 1) || (c5_i12 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i12, 1, 213200, &c5_ee_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_i10 = c5_i12 - 1;
  }

  c5_array_int32_T_Constructor(chartInstance, &c5_r);
  c5_st.site = &c5_dh_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_tb_emlrtRTEI,
    c5_i10 + 1);
  c5_b_loop_ub = c5_i10;
  for (c5_i13 = 0; c5_i13 <= c5_b_loop_ub; c5_i13++) {
    c5_r.vector.data[c5_i13] = c5_i13;
  }

  c5_st.site = &c5_dh_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_path, &c5_ub_emlrtRTEI,
    c5_i7 + 1);
  c5_iv[0] = c5_r.size[0];
  emlrtSubAssignSizeCheckR2012b(&c5_iv[0], 1, &c5_path.size[0], 1,
    &c5_h_emlrtECI, (void *)c5_sp);
  c5_iv1[0] = c5_r.size[0];
  c5_c_loop_ub = c5_iv1[0] - 1;
  for (c5_i14 = 0; c5_i14 <= c5_c_loop_ub; c5_i14++) {
    chartInstance->c5_pathTemp[c5_r.vector.data[c5_i14]] =
      c5_path.vector.data[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 213200; c5_i15++) {
    c5_obj->Path[c5_i15] = chartInstance->c5_pathTemp[c5_i15];
  }

  c5_st.site = &c5_eg_emlrtRSI;
  c5_h_obj = c5_b_astarInternal;
  c5_b_st.site = &c5_lg_emlrtRSI;
  c5_i_obj = c5_h_obj;
  c5_d4 = c5_i_obj->NumNodesExplored;
  c5_b4 = (c5_d4 < 1.0);
  if (c5_b4) {
    c5_i16 = -1;
  } else {
    if (c5_d4 != (real_T)(int32_T)muDoubleScalarFloor(c5_d4)) {
      emlrtIntegerCheckR2012b(c5_d4, &c5_t_emlrtDCI, &c5_b_st);
    }

    c5_i17 = (int32_T)c5_d4;
    if ((c5_i17 < 1) || (c5_i17 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i17, 1, 213200, &c5_rb_emlrtBCI, &c5_b_st);
    }

    c5_i16 = c5_i17 - 1;
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_path, &c5_vb_emlrtRTEI,
    c5_i16 + 1);
  c5_d_loop_ub = c5_i16;
  for (c5_i18 = 0; c5_i18 <= c5_d_loop_ub; c5_i18++) {
    c5_path.vector.data[c5_i18] = c5_i_obj->NodesExploredIndicesInternal[c5_i18];
  }

  c5_st.site = &c5_dg_emlrtRSI;
  c5_j_obj = c5_b_astarInternal;
  c5_b_numNodes = c5_j_obj->NumNodesExplored;
  c5_obj->NumNodesExplored = c5_b_numNodes;
  if (!(c5_obj->NumNodesExplored <= 213200.0)) {
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv2, 10, 0U, 1, 0U, 2, 1, 52),
                  false);
    c5_k_y = NULL;
    sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_cv3, 10, 0U, 1, 0U, 2, 1, 16),
                  false);
    c5_b_u = 213200.0;
    c5_l_y = NULL;
    sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(c5_sp, &c5_x_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 3U, 14, c5_j_y, 14, c5_k_y, 14, c5_l_y)));
  }

  for (c5_i19 = 0; c5_i19 < 213200; c5_i19++) {
    chartInstance->c5_pathTemp[c5_i19] = 0.0;
  }

  c5_d5 = c5_obj->NumNodesExplored;
  c5_b5 = (c5_d5 < 1.0);
  if (c5_b5) {
    c5_i20 = -1;
  } else {
    if (c5_d5 != (real_T)(int32_T)muDoubleScalarFloor(c5_d5)) {
      emlrtIntegerCheckR2012b(c5_d5, &c5_ec_emlrtDCI, (emlrtConstCTX)c5_sp);
    }

    c5_i21 = (int32_T)c5_d5;
    if ((c5_i21 < 1) || (c5_i21 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i21, 1, 213200, &c5_de_emlrtBCI,
        (emlrtConstCTX)c5_sp);
    }

    c5_i20 = c5_i21 - 1;
  }

  c5_st.site = &c5_gh_emlrtRSI;
  c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_wb_emlrtRTEI,
    c5_i20 + 1);
  c5_e_loop_ub = c5_i20;
  for (c5_i22 = 0; c5_i22 <= c5_e_loop_ub; c5_i22++) {
    c5_r.vector.data[c5_i22] = c5_i22;
  }

  c5_iv2[0] = c5_r.size[0];
  emlrtSubAssignSizeCheckR2012b(&c5_iv2[0], 1, &c5_path.size[0], 1,
    &c5_g_emlrtECI, (void *)c5_sp);
  c5_iv3[0] = c5_r.size[0];
  c5_f_loop_ub = c5_iv3[0] - 1;
  for (c5_i23 = 0; c5_i23 <= c5_f_loop_ub; c5_i23++) {
    chartInstance->c5_pathTemp[c5_r.vector.data[c5_i23]] =
      c5_path.vector.data[c5_i23];
  }

  c5_array_int32_T_Destructor(chartInstance, &c5_r);
  c5_array_real_T_Destructor(chartInstance, &c5_path);
  for (c5_i24 = 0; c5_i24 < 213200; c5_i24++) {
    c5_obj->NodesExploredIndices[c5_i24] = chartInstance->c5_pathTemp[c5_i24];
  }
}

static void c5_warning(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp)
{
  static char_T c5_msgID[40] = { 'n', 'a', 'v', ':', 'n', 'a', 'v', 'a', 'l',
    'g', 's', ':', 'p', 'l', 'a', 'n', 'n', 'e', 'r', 'a', 's', 't', 'a', 'r',
    'g', 'r', 'i', 'd', ':', 'N', 'o', 'P', 'a', 't', 'h', 'F', 'o', 'u', 'n',
    'd' };

  static char_T c5_b_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c5_b_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_msgID, 10, 0U, 1, 0U, 2, 1, 40),
                false);
  c5_st.site = &c5_mg_emlrtRSI;
  c5_b_feval(chartInstance, &c5_st, c5_d_y, c5_feval(chartInstance, &c5_st,
              c5_e_y, c5_f_y));
}

static void c5_plannerAStarGrid_getPathOutput
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_plannerAStarGrid *c5_obj, c5_coder_array_real_T_2D *c5_pathOut)
{
  c5_binaryOccupancyMap *c5_e_obj;
  c5_binaryOccupancyMap *c5_val;
  c5_coder_array_int32_T c5_r;
  c5_coder_array_real_T c5_path;
  c5_coder_array_real_T_2D c5_idx;
  c5_coder_array_real_T_2D c5_pose;
  c5_coder_array_real_T_2D c5_r1;
  c5_plannerAStarGrid *c5_b_obj;
  c5_plannerAStarGrid *c5_c_obj;
  c5_plannerAStarGrid *c5_d_obj;
  c5_plannerAStarGrid *c5_f_obj;
  c5_plannerAStarGrid *c5_g_obj;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_k_y = NULL;
  const mxArray *c5_l_y = NULL;
  real_T c5_b_k;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_j_y;
  int32_T c5_iv[2];
  int32_T c5_iv1[2];
  int32_T c5_iv2[2];
  int32_T c5_iv3[2];
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_f_loop_ub;
  int32_T c5_g_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i2;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i3;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i4;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_loop_ub;
  int32_T c5_j_loop_ub;
  int32_T c5_k;
  int32_T c5_k_loop_ub;
  int32_T c5_l_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_m_loop_ub;
  boolean_T c5_b1;
  boolean_T c5_b10;
  boolean_T c5_b11;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b5;
  boolean_T c5_b6;
  boolean_T c5_b7;
  boolean_T c5_b8;
  boolean_T c5_b9;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_f_b;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  c5_st.site = &c5_ng_emlrtRSI;
  c5_b_obj = c5_obj;
  c5_d = c5_b_obj->NumPathPoints;
  c5_b_b = (c5_d < 1.0);
  if (c5_b_b) {
    c5_i = -1;
  } else {
    if (c5_d != (real_T)(int32_T)muDoubleScalarFloor(c5_d)) {
      emlrtIntegerCheckR2012b(c5_d, &c5_kc_emlrtDCI, &c5_st);
    }

    c5_i1 = (int32_T)c5_d;
    if ((c5_i1 < 1) || (c5_i1 > 213200)) {
      emlrtDynamicBoundsCheckR2012b(c5_i1, 1, 213200, &c5_ke_emlrtBCI, &c5_st);
    }

    c5_i = c5_i1 - 1;
  }

  c5_array_real_T_Constructor(chartInstance, &c5_path);
  c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_path, &c5_xb_emlrtRTEI,
    c5_i + 1);
  c5_loop_ub = c5_i;
  for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
    c5_path.vector.data[c5_i2] = c5_b_obj->Path[c5_i2];
  }

  for (c5_i3 = 0; c5_i3 < 426400; c5_i3++) {
    c5_obj->PathXY[c5_i3] = rtNaN;
  }

  for (c5_i4 = 0; c5_i4 < 426400; c5_i4++) {
    c5_obj->PathInGrid[c5_i4] = rtNaN;
  }

  if (c5_path.size[0] == 0) {
    c5_obj->PathCost = rtInf;
    c5_st.site = &c5_jh_emlrtRSI;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_pathOut,
      &c5_lc_emlrtRTEI, 0, 0);
  } else {
    c5_st.site = &c5_og_emlrtRSI;
    c5_c_obj = c5_obj;
    c5_d1 = c5_c_obj->NumPathPoints;
    c5_b1 = (c5_d1 < 1.0);
    if (c5_b1) {
      c5_i5 = -1;
    } else {
      if (c5_d1 != (real_T)(int32_T)muDoubleScalarFloor(c5_d1)) {
        emlrtIntegerCheckR2012b(c5_d1, &c5_kc_emlrtDCI, &c5_st);
      }

      c5_i6 = (int32_T)c5_d1;
      if ((c5_i6 < 1) || (c5_i6 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c5_i6, 1, 213200, &c5_ke_emlrtBCI, &c5_st);
      }

      c5_i5 = c5_i6 - 1;
    }

    c5_array_real_T_SetSize(chartInstance, &c5_st, &c5_path, &c5_yb_emlrtRTEI,
      c5_i5 + 1);
    c5_b_loop_ub = c5_i5;
    for (c5_i7 = 0; c5_i7 <= c5_b_loop_ub; c5_i7++) {
      c5_path.vector.data[c5_i7] = c5_c_obj->Path[c5_i7];
    }

    c5_array_real_T_2D_Constructor(chartInstance, &c5_pose);
    c5_st.site = &c5_og_emlrtRSI;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_pose, &c5_ac_emlrtRTEI,
      c5_path.size[0], 3);
    for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
      c5_c_loop_ub = c5_path.size[0] - 1;
      for (c5_i10 = 0; c5_i10 <= c5_c_loop_ub; c5_i10++) {
        c5_d3 = c5_path.vector.data[c5_i10];
        if (c5_d3 != (real_T)(int32_T)muDoubleScalarFloor(c5_d3)) {
          emlrtIntegerCheckR2012b(c5_d3, &c5_nc_emlrtDCI, (emlrtConstCTX)c5_sp);
        }

        c5_i12 = (int32_T)c5_d3;
        if ((c5_i12 < 1) || (c5_i12 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c5_i12, 1, 213200, &c5_ne_emlrtBCI,
            (emlrtConstCTX)c5_sp);
        }

        c5_pose.vector.data[c5_i10 + c5_pose.size[0] * c5_i8] = c5_obj->IdPose
          [(c5_i12 + 213200 * c5_i8) - 1];
      }
    }

    for (c5_i9 = 0; c5_i9 < 426400; c5_i9++) {
      chartInstance->c5_pathXYTemp[c5_i9] = rtNaN;
    }

    c5_d2 = c5_obj->NumPathPoints;
    c5_b2 = (c5_d2 < 1.0);
    if (c5_b2) {
      c5_i11 = -1;
    } else {
      if (c5_d2 != (real_T)(int32_T)muDoubleScalarFloor(c5_d2)) {
        emlrtIntegerCheckR2012b(c5_d2, &c5_ic_emlrtDCI, (emlrtConstCTX)c5_sp);
      }

      c5_i13 = (int32_T)c5_d2;
      if ((c5_i13 < 1) || (c5_i13 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c5_i13, 1, 213200, &c5_ie_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i11 = c5_i13 - 1;
    }

    c5_array_int32_T_Constructor(chartInstance, &c5_r);
    c5_st.site = &c5_pg_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_bc_emlrtRTEI,
      c5_i11 + 1);
    c5_d_loop_ub = c5_i11;
    for (c5_i14 = 0; c5_i14 <= c5_d_loop_ub; c5_i14++) {
      c5_r.vector.data[c5_i14] = c5_i14;
    }

    c5_st.site = &c5_pg_emlrtRSI;
    c5_d_obj = c5_obj;
    c5_val = c5_d_obj->Map;
    c5_st.site = &c5_pg_emlrtRSI;
    c5_e_obj = c5_val;
    c5_array_real_T_2D_Constructor(chartInstance, &c5_idx);
    c5_b_st.site = &c5_pg_emlrtRSI;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, &c5_idx,
      &c5_cc_emlrtRTEI, c5_pose.size[0], 2);
    for (c5_i15 = 0; c5_i15 < 2; c5_i15++) {
      c5_e_loop_ub = c5_pose.size[0] - 1;
      for (c5_i16 = 0; c5_i16 <= c5_e_loop_ub; c5_i16++) {
        c5_idx.vector.data[c5_i16 + c5_idx.size[0] * c5_i15] =
          c5_pose.vector.data[c5_i16 + c5_pose.size[0] * c5_i15];
      }
    }

    c5_b_st.site = &c5_tg_emlrtRSI;
    c5_c_st.site = &c5_od_emlrtRSI;
    c5_p = true;
    c5_d4 = (real_T)(c5_idx.size[0] << 1);
    c5_i17 = (int32_T)c5_d4 - 1;
    c5_k = 0;
    c5_exitg1 = false;
    while ((!c5_exitg1) && (c5_k <= c5_i17)) {
      c5_b_k = (real_T)c5_k + 1.0;
      c5_c_x = c5_idx.vector.data[(int32_T)c5_b_k - 1];
      c5_d_x = c5_c_x;
      c5_e_x = c5_d_x;
      c5_c_b = muDoubleScalarIsInf(c5_e_x);
      c5_b4 = !c5_c_b;
      c5_f_x = c5_d_x;
      c5_d_b = muDoubleScalarIsNaN(c5_f_x);
      c5_b6 = !c5_d_b;
      c5_e_b = (c5_b4 && c5_b6);
      if (c5_e_b) {
        c5_g_x = c5_c_x;
        c5_h_x = c5_g_x;
        c5_j_y = c5_h_x;
        c5_j_y = muDoubleScalarFloor(c5_j_y);
        if (c5_j_y == c5_c_x) {
          c5_b_p = true;
        } else {
          c5_b_p = false;
        }
      } else {
        c5_b_p = false;
      }

      c5_c_p = c5_b_p;
      if (c5_c_p) {
        c5_k++;
      } else {
        c5_p = false;
        c5_exitg1 = true;
      }
    }

    if (c5_p) {
      c5_b3 = true;
    } else {
      c5_b3 = false;
    }

    if (!c5_b3) {
      c5_d_y = NULL;
      sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv9, 10, 0U, 1, 0U, 2, 1, 33),
                    false);
      c5_e_y = NULL;
      sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 47),
                    false);
      c5_g_y = NULL;
      sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 20),
                    false);
      sf_mex_call(&c5_c_st, &c5_p_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_g_y)));
    }

    c5_c_st.site = &c5_od_emlrtRSI;
    c5_b5 = (c5_idx.size[0] == 0);
    if (c5_b5) {
      c5_f_y = NULL;
      sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv6, 10, 0U, 1, 0U, 2, 1, 34),
                    false);
      c5_h_y = NULL;
      sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv7, 10, 0U, 1, 0U, 2, 1, 48),
                    false);
      c5_i_y = NULL;
      sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 20),
                    false);
      sf_mex_call(&c5_c_st, &c5_y_emlrtMCI, "error", 0U, 2U, 14, c5_f_y, 14,
                  sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c5_c_st, NULL, "message", 1U, 2U, 14, c5_h_y, 14, c5_i_y)));
    }

    c5_array_real_T_2D_Constructor(chartInstance, &c5_r1);
    c5_b_st.site = &c5_ug_emlrtRSI;
    c5_MapInterface_grid2worldImpl(chartInstance, &c5_b_st, c5_e_obj, &c5_idx,
      &c5_r1);
    c5_iv[0] = c5_r.size[0];
    c5_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&c5_iv[0], 2, &c5_r1.size[0], 2,
      &c5_i_emlrtECI, (void *)c5_sp);
    c5_iv1[0] = c5_r.size[0];
    for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
      c5_f_loop_ub = c5_iv1[0] - 1;
      for (c5_i20 = 0; c5_i20 <= c5_f_loop_ub; c5_i20++) {
        chartInstance->c5_pathXYTemp[c5_r.vector.data[c5_i20] + 213200 * c5_i18]
          = c5_r1.vector.data[c5_i20 + c5_r1.size[0] * c5_i18];
      }
    }

    for (c5_i19 = 0; c5_i19 < 426400; c5_i19++) {
      c5_obj->PathXY[c5_i19] = chartInstance->c5_pathXYTemp[c5_i19];
    }

    for (c5_i21 = 0; c5_i21 < 426400; c5_i21++) {
      chartInstance->c5_pathXYTemp[c5_i21] = rtNaN;
    }

    c5_d5 = c5_obj->NumPathPoints;
    c5_b7 = (c5_d5 < 1.0);
    if (c5_b7) {
      c5_i22 = -1;
    } else {
      if (c5_d5 != (real_T)(int32_T)muDoubleScalarFloor(c5_d5)) {
        emlrtIntegerCheckR2012b(c5_d5, &c5_jc_emlrtDCI, (emlrtConstCTX)c5_sp);
      }

      c5_i23 = (int32_T)c5_d5;
      if ((c5_i23 < 1) || (c5_i23 > 213200)) {
        emlrtDynamicBoundsCheckR2012b(c5_i23, 1, 213200, &c5_je_emlrtBCI,
          (emlrtConstCTX)c5_sp);
      }

      c5_i22 = c5_i23 - 1;
    }

    c5_st.site = &c5_fh_emlrtRSI;
    c5_array_int32_T_SetSize(chartInstance, &c5_st, &c5_r, &c5_dc_emlrtRTEI,
      c5_i22 + 1);
    c5_g_loop_ub = c5_i22;
    for (c5_i24 = 0; c5_i24 <= c5_g_loop_ub; c5_i24++) {
      c5_r.vector.data[c5_i24] = c5_i24;
    }

    c5_st.site = &c5_fh_emlrtRSI;
    c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_r1, &c5_ec_emlrtRTEI,
      c5_pose.size[0], 2);
    for (c5_i25 = 0; c5_i25 < 2; c5_i25++) {
      c5_h_loop_ub = c5_pose.size[0] - 1;
      for (c5_i26 = 0; c5_i26 <= c5_h_loop_ub; c5_i26++) {
        c5_r1.vector.data[c5_i26 + c5_r1.size[0] * c5_i25] =
          c5_pose.vector.data[c5_i26 + c5_pose.size[0] * c5_i25];
      }
    }

    c5_array_real_T_2D_Destructor(chartInstance, &c5_pose);
    c5_iv2[0] = c5_r.size[0];
    c5_iv2[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&c5_iv2[0], 2, &c5_r1.size[0], 2,
      &c5_j_emlrtECI, (void *)c5_sp);
    c5_iv3[0] = c5_r.size[0];
    for (c5_i27 = 0; c5_i27 < 2; c5_i27++) {
      c5_i_loop_ub = c5_iv3[0] - 1;
      for (c5_i28 = 0; c5_i28 <= c5_i_loop_ub; c5_i28++) {
        chartInstance->c5_pathXYTemp[c5_r.vector.data[c5_i28] + 213200 * c5_i27]
          = c5_r1.vector.data[c5_i28 + c5_r1.size[0] * c5_i27];
      }
    }

    c5_array_real_T_2D_Destructor(chartInstance, &c5_r1);
    c5_array_int32_T_Destructor(chartInstance, &c5_r);
    for (c5_i29 = 0; c5_i29 < 426400; c5_i29++) {
      c5_obj->PathInGrid[c5_i29] = chartInstance->c5_pathXYTemp[c5_i29];
    }

    c5_st.site = &c5_qg_emlrtRSI;
    c5_i_x = c5_obj->IsGrid;
    c5_j_x = c5_i_x;
    c5_f_b = muDoubleScalarIsNaN(c5_j_x);
    if (c5_f_b) {
      c5_k_y = NULL;
      sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      c5_l_y = NULL;
      sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_cv, 10, 0U, 1, 0U, 2, 1, 19),
                    false);
      sf_mex_call(&c5_st, &c5_l_emlrtMCI, "error", 0U, 2U, 14, c5_k_y, 14,
                  sf_mex_call(&c5_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c5_st, NULL, "message", 1U, 1U, 14, c5_l_y)));
    }

    if (c5_obj->IsGrid != 0.0) {
      c5_st.site = &c5_rg_emlrtRSI;
      c5_g_obj = c5_obj;
      c5_d7 = c5_g_obj->NumPathPoints;
      c5_b9 = (c5_d7 < 1.0);
      if (c5_b9) {
        c5_i31 = -1;
      } else {
        if (c5_d7 != (real_T)(int32_T)muDoubleScalarFloor(c5_d7)) {
          emlrtIntegerCheckR2012b(c5_d7, &c5_mc_emlrtDCI, &c5_st);
        }

        c5_i33 = (int32_T)c5_d7;
        if ((c5_i33 < 1) || (c5_i33 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c5_i33, 1, 213200, &c5_me_emlrtBCI,
            &c5_st);
        }

        c5_i31 = c5_i33 - 1;
      }

      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_idx,
        &c5_ic_emlrtRTEI, c5_i31 + 1, 2);
      for (c5_i35 = 0; c5_i35 < 2; c5_i35++) {
        c5_k_loop_ub = c5_i31;
        for (c5_i37 = 0; c5_i37 <= c5_k_loop_ub; c5_i37++) {
          c5_idx.vector.data[c5_i37 + c5_idx.size[0] * c5_i35] =
            c5_g_obj->PathInGrid[c5_i37 + 213200 * c5_i35];
        }
      }

      c5_b11 = (c5_idx.size[0] == 0);
      if (c5_b11) {
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_idx,
          &c5_jc_emlrtRTEI, 1, 2);
        for (c5_i39 = 0; c5_i39 < 2; c5_i39++) {
          c5_idx.vector.data[c5_idx.size[0] * c5_i39] = c5_g_obj->PathInGrid
            [213200 * c5_i39];
        }
      }

      c5_st.site = &c5_rg_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_pathOut,
        &c5_kc_emlrtRTEI, c5_idx.size[0], 2);
      c5_m_loop_ub = (c5_idx.size[0] << 1) - 1;
      for (c5_i41 = 0; c5_i41 <= c5_m_loop_ub; c5_i41++) {
        c5_pathOut->vector.data[c5_i41] = c5_idx.vector.data[c5_i41];
      }
    } else {
      c5_st.site = &c5_sg_emlrtRSI;
      c5_f_obj = c5_obj;
      c5_d6 = c5_f_obj->NumPathPoints;
      c5_b8 = (c5_d6 < 1.0);
      if (c5_b8) {
        c5_i30 = -1;
      } else {
        if (c5_d6 != (real_T)(int32_T)muDoubleScalarFloor(c5_d6)) {
          emlrtIntegerCheckR2012b(c5_d6, &c5_lc_emlrtDCI, &c5_st);
        }

        c5_i32 = (int32_T)c5_d6;
        if ((c5_i32 < 1) || (c5_i32 > 213200)) {
          emlrtDynamicBoundsCheckR2012b(c5_i32, 1, 213200, &c5_le_emlrtBCI,
            &c5_st);
        }

        c5_i30 = c5_i32 - 1;
      }

      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_idx,
        &c5_fc_emlrtRTEI, c5_i30 + 1, 2);
      for (c5_i34 = 0; c5_i34 < 2; c5_i34++) {
        c5_j_loop_ub = c5_i30;
        for (c5_i36 = 0; c5_i36 <= c5_j_loop_ub; c5_i36++) {
          c5_idx.vector.data[c5_i36 + c5_idx.size[0] * c5_i34] =
            c5_f_obj->PathXY[c5_i36 + 213200 * c5_i34];
        }
      }

      c5_b10 = (c5_idx.size[0] == 0);
      if (c5_b10) {
        c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_idx,
          &c5_gc_emlrtRTEI, 1, 2);
        for (c5_i38 = 0; c5_i38 < 2; c5_i38++) {
          c5_idx.vector.data[c5_idx.size[0] * c5_i38] = c5_f_obj->PathXY[213200 *
            c5_i38];
        }
      }

      c5_st.site = &c5_sg_emlrtRSI;
      c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_pathOut,
        &c5_hc_emlrtRTEI, c5_idx.size[0], 2);
      c5_l_loop_ub = (c5_idx.size[0] << 1) - 1;
      for (c5_i40 = 0; c5_i40 <= c5_l_loop_ub; c5_i40++) {
        c5_pathOut->vector.data[c5_i40] = c5_idx.vector.data[c5_i40];
      }
    }

    c5_array_real_T_2D_Destructor(chartInstance, &c5_idx);
  }

  c5_array_real_T_Destructor(chartInstance, &c5_path);
}

static void c5_MapInterface_grid2worldImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_worldXY)
{
  c5_coder_array_real_T_2D c5_b_gridInd;
  c5_coder_array_real_T_2D c5_localXY;
  emlrtStack c5_st;
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_gridInd);
  c5_st.site = &c5_vg_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_b_gridInd,
    &c5_mc_emlrtRTEI, c5_gridInd->size[0], 2);
  c5_loop_ub = c5_gridInd->size[0] * c5_gridInd->size[1] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_gridInd.vector.data[c5_i] = c5_gridInd->vector.data[c5_i];
  }

  c5_array_real_T_2D_Constructor(chartInstance, &c5_localXY);
  c5_st.site = &c5_vg_emlrtRSI;
  c5_MapInterface_grid2localImpl(chartInstance, &c5_st, c5_obj, &c5_b_gridInd,
    &c5_localXY);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_gridInd);
  c5_st.site = &c5_wg_emlrtRSI;
  c5_MapInterface_local2worldImpl(chartInstance, &c5_st, c5_obj, &c5_localXY,
    c5_worldXY);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_localXY);
}

static void c5_MapInterface_grid2localImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_localXY)
{
  c5_cell_wrap_36 c5_reshapes[2];
  c5_coder_array_real_T c5_b_varargin_1;
  c5_coder_array_real_T c5_b_varargin_2;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  real_T c5_gOrig[2];
  real_T c5_xlimit[2];
  real_T c5_ylimit[2];
  real_T c5_b_xlimit;
  real_T c5_b_ylimit;
  int32_T c5_sizes[2];
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_expected;
  int32_T c5_f_loop_ub;
  int32_T c5_g_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_result;
  boolean_T c5_b_b;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_gOrig[c5_i] = c5_obj->SharedProperties.GridOriginInLocal[c5_i];
  }

  c5_xlimit[0] = c5_gOrig[0];
  c5_ylimit[0] = c5_gOrig[1];
  c5_st.site = &c5_xg_emlrtRSI;
  c5_b_xlimit = c5_xlimit[0];
  c5_array_real_T_Constructor(chartInstance, &c5_b_varargin_1);
  c5_b_st.site = &c5_xg_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_1,
    &c5_nc_emlrtRTEI, c5_gridInd->size[0]);
  c5_loop_ub = c5_gridInd->size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_b_varargin_1.vector.data[c5_i1] = c5_b_xlimit + (c5_gridInd->
      vector.data[c5_i1 + c5_gridInd->size[0]] - 1.0) / 10.0;
  }

  c5_b_ylimit = c5_ylimit[0];
  c5_array_real_T_Constructor(chartInstance, &c5_b_varargin_2);
  c5_b_st.site = &c5_ch_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_2,
    &c5_oc_emlrtRTEI, c5_gridInd->size[0]);
  c5_b_loop_ub = c5_gridInd->size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
    c5_b_varargin_2.vector.data[c5_i2] = c5_b_ylimit + (410.0 -
      c5_gridInd->vector.data[c5_i2]) / 10.0;
  }

  c5_b_st.site = &c5_yg_emlrtRSI;
  c5_result = c5_b_varargin_1.size[0];
  c5_sizes[0] = c5_result;
  c5_c_st.site = &c5_ah_emlrtRSI;
  c5_expected = c5_sizes[0];
  if (c5_b_varargin_1.size[0] == c5_expected) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c5_c_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
  }

  if (c5_b_varargin_2.size[0] == c5_expected) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c5_c_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_f_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 1U, 14, c5_g_y)));
  }

  c5_array_cell_wrap_36_2s_Construct(chartInstance, c5_reshapes);
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_reshapes[0].f1,
    &c5_pc_emlrtRTEI, c5_b_varargin_1.size[0]);
  c5_c_loop_ub = c5_b_varargin_1.size[0] - 1;
  for (c5_i3 = 0; c5_i3 <= c5_c_loop_ub; c5_i3++) {
    c5_reshapes[0].f1.vector.data[c5_i3] = c5_b_varargin_1.vector.data[c5_i3];
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_reshapes[1].f1,
    &c5_pc_emlrtRTEI, c5_b_varargin_2.size[0]);
  c5_d_loop_ub = c5_b_varargin_2.size[0] - 1;
  for (c5_i4 = 0; c5_i4 <= c5_d_loop_ub; c5_i4++) {
    c5_reshapes[1].f1.vector.data[c5_i4] = c5_b_varargin_2.vector.data[c5_i4];
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_1,
    &c5_qc_emlrtRTEI, c5_reshapes[0].f1.size[0]);
  c5_e_loop_ub = c5_reshapes[0].f1.size[0] - 1;
  for (c5_i5 = 0; c5_i5 <= c5_e_loop_ub; c5_i5++) {
    c5_b_varargin_1.vector.data[c5_i5] = c5_reshapes[0].f1.vector.data[c5_i5];
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_2,
    &c5_qc_emlrtRTEI, c5_reshapes[1].f1.size[0]);
  c5_f_loop_ub = c5_reshapes[1].f1.size[0] - 1;
  for (c5_i6 = 0; c5_i6 <= c5_f_loop_ub; c5_i6++) {
    c5_b_varargin_2.vector.data[c5_i6] = c5_reshapes[1].f1.vector.data[c5_i6];
  }

  c5_array_cell_wrap_36_2s_Destructo(chartInstance, c5_reshapes);
  c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, c5_localXY,
    &c5_rc_emlrtRTEI, c5_b_varargin_1.size[0], 2);
  c5_g_loop_ub = c5_b_varargin_1.size[0] - 1;
  for (c5_i7 = 0; c5_i7 <= c5_g_loop_ub; c5_i7++) {
    c5_localXY->vector.data[c5_i7] = c5_b_varargin_1.vector.data[c5_i7];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_b_varargin_1);
  c5_h_loop_ub = c5_b_varargin_2.size[0] - 1;
  for (c5_i8 = 0; c5_i8 <= c5_h_loop_ub; c5_i8++) {
    c5_localXY->vector.data[c5_i8 + c5_localXY->size[0]] =
      c5_b_varargin_2.vector.data[c5_i8];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_b_varargin_2);
  c5_i9 = c5_localXY->size[0] << 1;
  c5_st.site = &c5_xg_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_localXY, &c5_sc_emlrtRTEI,
    c5_localXY->size[0], 2);
  c5_i10 = c5_i9;
  c5_i_loop_ub = c5_i10 - 1;
  for (c5_i11 = 0; c5_i11 <= c5_i_loop_ub; c5_i11++) {
    c5_localXY->vector.data[c5_i11] += 0.05;
  }
}

static void c5_MapInterface_local2worldImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_localXY,
   c5_coder_array_real_T_2D *c5_worldXY)
{
  emlrtStack c5_st;
  real_T c5_locWorld[2];
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_locWorld[c5_i] = c5_obj->SharedProperties.LocalOriginInWorld[c5_i];
  }

  c5_st.site = &c5_ih_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_worldXY, &c5_tc_emlrtRTEI,
    c5_localXY->size[0], 2);
  for (c5_i1 = 0; c5_i1 < 2; c5_i1++) {
    c5_loop_ub = c5_localXY->size[0] - 1;
    for (c5_i2 = 0; c5_i2 <= c5_loop_ub; c5_i2++) {
      c5_worldXY->vector.data[c5_i2 + c5_worldXY->size[0] * c5_i1] =
        c5_localXY->vector.data[c5_i2 + c5_localXY->size[0] * c5_i1] +
        c5_locWorld[c5_i1];
    }
  }
}

static void c5_MapInterface_grid2world
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_idx,
   c5_coder_array_real_T_2D *c5_pos)
{
  static char_T c5_b_cv1[48] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't',
    't', 'r', 'i', 'b', 'u', 't', 'e', 's', 'i', 'n', 'c', 'o', 'r', 'r', 'e',
    'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  static char_T c5_b_cv[34] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'g', 'r', 'i',
    'd', '2', 'w', 'o', 'r', 'l', 'd', ':', 'i', 'n', 'c', 'o', 'r', 'r', 'e',
    'c', 't', 'N', 'u', 'm', 'c', 'o', 'l', 's' };

  c5_coder_array_real_T_2D c5_b_idx;
  emlrtStack c5_b_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  const mxArray *c5_h_y = NULL;
  const mxArray *c5_i_y = NULL;
  const mxArray *c5_j_y = NULL;
  const mxArray *c5_l_y = NULL;
  const mxArray *c5_m_y = NULL;
  const mxArray *c5_n_y = NULL;
  real_T c5_b_k;
  real_T c5_c_x;
  real_T c5_d;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_k_y;
  real_T c5_u;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_k;
  int32_T c5_loop_ub;
  boolean_T c5_b1;
  boolean_T c5_b2;
  boolean_T c5_b3;
  boolean_T c5_b4;
  boolean_T c5_b_b;
  boolean_T c5_b_p;
  boolean_T c5_c_b;
  boolean_T c5_c_p;
  boolean_T c5_d_b;
  boolean_T c5_e_b;
  boolean_T c5_exitg1;
  boolean_T c5_p;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_st.site = &c5_tg_emlrtRSI;
  c5_b_st.site = &c5_od_emlrtRSI;
  c5_p = true;
  c5_d = (real_T)(c5_idx->size[0] * c5_idx->size[1]);
  c5_i = (int32_T)c5_d - 1;
  c5_k = 0;
  c5_exitg1 = false;
  while ((!c5_exitg1) && (c5_k <= c5_i)) {
    c5_b_k = (real_T)c5_k + 1.0;
    c5_c_x = c5_idx->vector.data[(int32_T)c5_b_k - 1];
    c5_d_x = c5_c_x;
    c5_e_x = c5_d_x;
    c5_c_b = muDoubleScalarIsInf(c5_e_x);
    c5_b1 = !c5_c_b;
    c5_f_x = c5_d_x;
    c5_d_b = muDoubleScalarIsNaN(c5_f_x);
    c5_b4 = !c5_d_b;
    c5_e_b = (c5_b1 && c5_b4);
    if (c5_e_b) {
      c5_g_x = c5_c_x;
      c5_h_x = c5_g_x;
      c5_k_y = c5_h_x;
      c5_k_y = muDoubleScalarFloor(c5_k_y);
      if (c5_k_y == c5_c_x) {
        c5_b_p = true;
      } else {
        c5_b_p = false;
      }
    } else {
      c5_b_p = false;
    }

    c5_c_p = c5_b_p;
    if (c5_c_p) {
      c5_k++;
    } else {
      c5_p = false;
      c5_exitg1 = true;
    }
  }

  if (c5_p) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv9, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv1, 10, 0U, 1, 0U, 2, 1, 47),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 20),
                  false);
    sf_mex_call(&c5_b_st, &c5_p_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_f_y)));
  }

  c5_b_st.site = &c5_od_emlrtRSI;
  c5_b2 = (c5_idx->size[0] == 0);
  c5_b3 = (c5_idx->size[1] == 0);
  if ((!!c5_b2) || (!!c5_b3)) {
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv6, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c5_h_y = NULL;
    sf_mex_assign(&c5_h_y, sf_mex_create("y", c5_cv7, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c5_j_y = NULL;
    sf_mex_assign(&c5_j_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 20),
                  false);
    sf_mex_call(&c5_b_st, &c5_y_emlrtMCI, "error", 0U, 2U, 14, c5_g_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 2U, 14, c5_h_y, 14, c5_j_y)));
  }

  c5_b_st.site = &c5_od_emlrtRSI;
  if (!((real_T)c5_idx->size[1] == 2.0)) {
    c5_i_y = NULL;
    sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 34),
                  false);
    c5_l_y = NULL;
    sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_b_cv1, 10, 0U, 1, 0U, 2, 1, 48),
                  false);
    c5_m_y = NULL;
    sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_cv8, 10, 0U, 1, 0U, 2, 1, 20),
                  false);
    c5_u = 2.0;
    c5_n_y = NULL;
    sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_u, 0, 0U, 0, 0U, 0), false);
    sf_mex_call(&c5_b_st, &c5_bb_emlrtMCI, "error", 0U, 2U, 14, c5_i_y, 14,
                sf_mex_call(&c5_b_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_b_st, NULL, "message", 1U, 3U, 14, c5_l_y, 14, c5_m_y, 14, c5_n_y)));
  }

  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_idx);
  c5_st.site = &c5_ug_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_b_idx, &c5_uc_emlrtRTEI,
    c5_idx->size[0], c5_idx->size[1]);
  c5_loop_ub = c5_idx->size[0] * c5_idx->size[1] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_b_idx.vector.data[c5_i1] = c5_idx->vector.data[c5_i1];
  }

  c5_st.site = &c5_ug_emlrtRSI;
  c5_b_MapInterface_grid2worldImpl(chartInstance, &c5_st, c5_obj, &c5_b_idx,
    c5_pos);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_idx);
}

static void c5_b_MapInterface_grid2worldImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_worldXY)
{
  c5_coder_array_real_T_2D c5_b_gridInd;
  c5_coder_array_real_T_2D c5_localXY;
  emlrtStack c5_st;
  int32_T c5_i;
  int32_T c5_loop_ub;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_array_real_T_2D_Constructor(chartInstance, &c5_b_gridInd);
  c5_st.site = &c5_vg_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, &c5_b_gridInd,
    &c5_mc_emlrtRTEI, c5_gridInd->size[0], c5_gridInd->size[1]);
  c5_loop_ub = c5_gridInd->size[0] * c5_gridInd->size[1] - 1;
  for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
    c5_b_gridInd.vector.data[c5_i] = c5_gridInd->vector.data[c5_i];
  }

  c5_array_real_T_2D_Constructor(chartInstance, &c5_localXY);
  c5_st.site = &c5_vg_emlrtRSI;
  c5_b_MapInterface_grid2localImpl(chartInstance, &c5_st, c5_obj, &c5_b_gridInd,
    &c5_localXY);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_b_gridInd);
  c5_st.site = &c5_wg_emlrtRSI;
  c5_MapInterface_local2worldImpl(chartInstance, &c5_st, c5_obj, &c5_localXY,
    c5_worldXY);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_localXY);
}

static void c5_b_MapInterface_grid2localImpl
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_binaryOccupancyMap *c5_obj, c5_coder_array_real_T_2D *c5_gridInd,
   c5_coder_array_real_T_2D *c5_localXY)
{
  c5_cell_wrap_36 c5_reshapes[2];
  c5_coder_array_real_T c5_b_varargin_1;
  c5_coder_array_real_T c5_b_varargin_2;
  emlrtStack c5_b_st;
  emlrtStack c5_c_st;
  emlrtStack c5_st;
  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  const mxArray *c5_g_y = NULL;
  real_T c5_gOrig[2];
  real_T c5_xlimit[2];
  real_T c5_ylimit[2];
  real_T c5_b_xlimit;
  real_T c5_b_ylimit;
  int32_T c5_sizes[2];
  int32_T c5_b_loop_ub;
  int32_T c5_c_loop_ub;
  int32_T c5_d_loop_ub;
  int32_T c5_e_loop_ub;
  int32_T c5_expected;
  int32_T c5_f_loop_ub;
  int32_T c5_g_loop_ub;
  int32_T c5_h_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i_loop_ub;
  int32_T c5_loop_ub;
  int32_T c5_result;
  boolean_T c5_b_b;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  c5_b_st.prev = &c5_st;
  c5_b_st.tls = c5_st.tls;
  c5_c_st.prev = &c5_b_st;
  c5_c_st.tls = c5_b_st.tls;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_gOrig[c5_i] = c5_obj->SharedProperties.GridOriginInLocal[c5_i];
  }

  c5_xlimit[0] = c5_gOrig[0];
  c5_ylimit[0] = c5_gOrig[1];
  c5_i1 = c5_gridInd->size[1];
  c5_i2 = 2;
  if ((c5_i2 < 1) || (c5_i2 > c5_i1)) {
    emlrtDynamicBoundsCheckR2012b(c5_i2, 1, c5_i1, &c5_oe_emlrtBCI,
      (emlrtConstCTX)c5_sp);
  }

  c5_i3 = c5_gridInd->size[1];
  c5_i4 = 1;
  if ((c5_i4 < 1) || (c5_i4 > c5_i3)) {
    emlrtDynamicBoundsCheckR2012b(c5_i4, 1, c5_i3, &c5_pe_emlrtBCI,
      (emlrtConstCTX)c5_sp);
  }

  c5_st.site = &c5_xg_emlrtRSI;
  c5_b_xlimit = c5_xlimit[0];
  c5_array_real_T_Constructor(chartInstance, &c5_b_varargin_1);
  c5_b_st.site = &c5_xg_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_1,
    &c5_nc_emlrtRTEI, c5_gridInd->size[0]);
  c5_loop_ub = c5_gridInd->size[0] - 1;
  for (c5_i5 = 0; c5_i5 <= c5_loop_ub; c5_i5++) {
    c5_b_varargin_1.vector.data[c5_i5] = c5_b_xlimit + (c5_gridInd->
      vector.data[c5_i5 + c5_gridInd->size[0]] - 1.0) / 10.0;
  }

  c5_b_ylimit = c5_ylimit[0];
  c5_array_real_T_Constructor(chartInstance, &c5_b_varargin_2);
  c5_b_st.site = &c5_ch_emlrtRSI;
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_2,
    &c5_oc_emlrtRTEI, c5_gridInd->size[0]);
  c5_b_loop_ub = c5_gridInd->size[0] - 1;
  for (c5_i6 = 0; c5_i6 <= c5_b_loop_ub; c5_i6++) {
    c5_b_varargin_2.vector.data[c5_i6] = c5_b_ylimit + (410.0 -
      c5_gridInd->vector.data[c5_i6]) / 10.0;
  }

  c5_b_st.site = &c5_yg_emlrtRSI;
  c5_result = c5_b_varargin_1.size[0];
  c5_sizes[0] = c5_result;
  c5_c_st.site = &c5_ah_emlrtRSI;
  c5_expected = c5_sizes[0];
  if (c5_b_varargin_1.size[0] == c5_expected) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c5_c_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 1U, 14, c5_e_y)));
  }

  if (c5_b_varargin_2.size[0] == c5_expected) {
    c5_b_b = true;
  } else {
    c5_b_b = false;
  }

  if (!c5_b_b) {
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    c5_g_y = NULL;
    sf_mex_assign(&c5_g_y, sf_mex_create("y", c5_cv10, 10, 0U, 1, 0U, 2, 1, 39),
                  false);
    sf_mex_call(&c5_c_st, &c5_ab_emlrtMCI, "error", 0U, 2U, 14, c5_f_y, 14,
                sf_mex_call(&c5_c_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c5_c_st, NULL, "message", 1U, 1U, 14, c5_g_y)));
  }

  c5_array_cell_wrap_36_2s_Construct(chartInstance, c5_reshapes);
  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_reshapes[0].f1,
    &c5_pc_emlrtRTEI, c5_b_varargin_1.size[0]);
  c5_c_loop_ub = c5_b_varargin_1.size[0] - 1;
  for (c5_i7 = 0; c5_i7 <= c5_c_loop_ub; c5_i7++) {
    c5_reshapes[0].f1.vector.data[c5_i7] = c5_b_varargin_1.vector.data[c5_i7];
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_reshapes[1].f1,
    &c5_pc_emlrtRTEI, c5_b_varargin_2.size[0]);
  c5_d_loop_ub = c5_b_varargin_2.size[0] - 1;
  for (c5_i8 = 0; c5_i8 <= c5_d_loop_ub; c5_i8++) {
    c5_reshapes[1].f1.vector.data[c5_i8] = c5_b_varargin_2.vector.data[c5_i8];
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_1,
    &c5_qc_emlrtRTEI, c5_reshapes[0].f1.size[0]);
  c5_e_loop_ub = c5_reshapes[0].f1.size[0] - 1;
  for (c5_i9 = 0; c5_i9 <= c5_e_loop_ub; c5_i9++) {
    c5_b_varargin_1.vector.data[c5_i9] = c5_reshapes[0].f1.vector.data[c5_i9];
  }

  c5_array_real_T_SetSize(chartInstance, &c5_b_st, &c5_b_varargin_2,
    &c5_qc_emlrtRTEI, c5_reshapes[1].f1.size[0]);
  c5_f_loop_ub = c5_reshapes[1].f1.size[0] - 1;
  for (c5_i10 = 0; c5_i10 <= c5_f_loop_ub; c5_i10++) {
    c5_b_varargin_2.vector.data[c5_i10] = c5_reshapes[1].f1.vector.data[c5_i10];
  }

  c5_array_cell_wrap_36_2s_Destructo(chartInstance, c5_reshapes);
  c5_array_real_T_2D_SetSize(chartInstance, &c5_b_st, c5_localXY,
    &c5_rc_emlrtRTEI, c5_b_varargin_1.size[0], 2);
  c5_g_loop_ub = c5_b_varargin_1.size[0] - 1;
  for (c5_i11 = 0; c5_i11 <= c5_g_loop_ub; c5_i11++) {
    c5_localXY->vector.data[c5_i11] = c5_b_varargin_1.vector.data[c5_i11];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_b_varargin_1);
  c5_h_loop_ub = c5_b_varargin_2.size[0] - 1;
  for (c5_i12 = 0; c5_i12 <= c5_h_loop_ub; c5_i12++) {
    c5_localXY->vector.data[c5_i12 + c5_localXY->size[0]] =
      c5_b_varargin_2.vector.data[c5_i12];
  }

  c5_array_real_T_Destructor(chartInstance, &c5_b_varargin_2);
  c5_i13 = c5_localXY->size[0] << 1;
  c5_st.site = &c5_xg_emlrtRSI;
  c5_array_real_T_2D_SetSize(chartInstance, &c5_st, c5_localXY, &c5_sc_emlrtRTEI,
    c5_localXY->size[0], 2);
  c5_i14 = c5_i13;
  c5_i_loop_ub = c5_i14 - 1;
  for (c5_i15 = 0; c5_i15 <= c5_i_loop_ub; c5_i15++) {
    c5_localXY->vector.data[c5_i15] += 0.05;
  }
}

static void c5_b_path_gen(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, boolean_T c5_g_logical_map[213200],
  real_T c5_start[2], real_T c5_goal[2], c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_out_path)
{
  c5_coder_array_real_T_2D c5_grid_path;
  c5_coder_array_real_T_2D c5_path;
  emlrtStack c5_st;
  real_T c5_b_goal[2];
  real_T c5_b_start[2];
  real_T c5_path_goal[2];
  real_T c5_path_start[2];
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  c5_st.prev = c5_sp;
  c5_st.tls = c5_sp->tls;
  covrtEmlFcnEval(chartInstance->c5_covrtInstance, 14U, 0, 0);
  c5_st.site = &c5_m_emlrtRSI;
  for (c5_i = 0; c5_i < 213200; c5_i++) {
    chartInstance->c5_d_logical_map[c5_i] = c5_g_logical_map[c5_i];
  }

  c5_binaryOccupancyMap_binaryOccupancyMap(chartInstance,
    &chartInstance->c5_occupancy_map, chartInstance->c5_d_logical_map);
  c5_st.site = &c5_n_emlrtRSI;
  c5_binaryOccupancyMap_inflate(chartInstance, &c5_st,
    &chartInstance->c5_occupancy_map);
  c5_b_start[0] = c5_start[0];
  c5_b_start[1] = c5_start[1];
  c5_st.site = &c5_o_emlrtRSI;
  c5_b_MapInterface_world2grid(chartInstance, &chartInstance->c5_occupancy_map,
    c5_b_start, c5_path_start);
  c5_b_goal[0] = c5_goal[0];
  c5_b_goal[1] = c5_goal[1];
  c5_st.site = &c5_p_emlrtRSI;
  c5_b_MapInterface_world2grid(chartInstance, &chartInstance->c5_occupancy_map,
    c5_b_goal, c5_path_goal);
  c5_st.site = &c5_q_emlrtRSI;
  c5_plannerAStarGrid_plannerAStarGrid(chartInstance, &c5_st,
    &chartInstance->c5_planner, &chartInstance->c5_occupancy_map);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_grid_path);
  c5_st.site = &c5_r_emlrtRSI;
  c5_plannerAStarGrid_plan(chartInstance, &c5_st, &chartInstance->c5_planner,
    c5_path_start, c5_path_goal, &c5_grid_path);
  c5_array_real_T_2D_Constructor(chartInstance, &c5_path);
  c5_st.site = &c5_s_emlrtRSI;
  c5_MapInterface_grid2world(chartInstance, &c5_st,
    &chartInstance->c5_occupancy_map, &c5_grid_path, &c5_path);
  c5_array_real_T_2D_Destructor(chartInstance, &c5_grid_path);
  c5_array_real_T_SetSize(chartInstance, c5_sp, &c5_out_path->x, &c5_g_emlrtRTEI,
    c5_path.size[0]);
  c5_loop_ub = c5_path.size[0] - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_out_path->x.vector.data[c5_i1] = c5_path.vector.data[c5_i1];
  }

  c5_array_real_T_SetSize(chartInstance, c5_sp, &c5_out_path->y, &c5_h_emlrtRTEI,
    c5_path.size[0]);
  c5_b_loop_ub = c5_path.size[0] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
    c5_out_path->y.vector.data[c5_i2] = c5_path.vector.data[c5_i2 +
      c5_path.size[0]];
  }

  c5_array_real_T_2D_Destructor(chartInstance, &c5_path);
}

static void c5_handle_matlabCodegenDestructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_nav_algs_internal_PriorityQueue *c5_obj)
{
  c5_nav_algs_internal_PriorityQueue *c5_b_obj;
  (void)chartInstance;
  if (!c5_obj->matlabCodegenIsDeleted) {
    c5_obj->matlabCodegenIsDeleted = true;
    c5_b_obj = c5_obj;
    priorityqueuecodegen_destructPQ(c5_b_obj->PQInternal);
  }
}

static void c5_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c5_a__output_of_sprintf_, const char_T
  *c5_identifier, char_T c5_d_y[23])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_a__output_of_sprintf_),
                        &c5_thisId, c5_d_y);
  sf_mex_destroy(&c5_a__output_of_sprintf_);
}

static void c5_b_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  char_T c5_d_y[23])
{
  int32_T c5_i;
  char_T c5_b_cv[23];
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_b_cv, 1, 10, 0U, 1, 0U, 2, 1,
                23);
  for (c5_i = 0; c5_i < 23; c5_i++) {
    c5_d_y[c5_i] = c5_b_cv[c5_i];
  }

  sf_mex_destroy(&c5_u);
}

const mxArray *sf_c5_sl_groundvehicleDynamics_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  const char_T *c5_data[4] = {
    "789cc593cd4ec24010c71783c40bcac9a3e1090c21e8c19bc1f21515113cb906814e69b5bb5bbbdb529ec29bcfe43bf8304ae907a5c9a62428ce65f6dfffeefc"
    "66a72dcab56f7208a1431444a510e462a84b61de43eb91f673921cc53ecaaf9d8bfcf7304f1815e08940d01181f8a4ca884147540ce616201b38335d50978e66",
    "98303008f493e2d657a491b062e15bfebaaec3e4b5ef1064eb7cd5a19914f13c9e25f7cd67cc231de979a4f76dcb8bea1f487981638d843e9c02fd2d5e41ca0b"
    "1c9539631356f7fbdc92a74b79ebfea3f254bfc00f1c6c8e5f40d3700f2ce6cdcb5736b3c6ccc39dc5b3f24c3784c66c152bcd56ad768e61aa2fd2901b44a16e",
    "b552ade1c57208d4c5978e60fd391740b8bf319ae229c99ae3d186f792fd37c5f0bd7d9c7c2dad5df1beb1d5de252f8affe279927a9b7e97c7125e29e5bbe36b"
    "c5ecd933ebbed56d547bb473d67d1b34577ddc6570b2fa4012fdd7f57f0031dd6591", "" };

  c5_nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&c5_data[0], 1608U, &c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static real_T c5_c_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier)
{
  emlrtMsgIdentifier c5_thisId;
  real_T c5_d_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_d_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr),
    &c5_thisId);
  sf_mex_destroy(&c5_nullptr);
  return c5_d_y;
}

static real_T c5_d_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_d;
  real_T c5_d_y;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d, 1, 0, 0U, 0, 0U, 0);
  c5_d_y = c5_d;
  sf_mex_destroy(&c5_u);
  return c5_d_y;
}

static real_T c5_e_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_nullptr, const char_T *c5_identifier,
  boolean_T *c5_svPtr)
{
  emlrtMsgIdentifier c5_thisId;
  real_T c5_d_y;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_d_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nullptr),
    &c5_thisId, c5_svPtr);
  sf_mex_destroy(&c5_nullptr);
  return c5_d_y;
}

static real_T c5_f_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  boolean_T *c5_svPtr)
{
  real_T c5_d;
  real_T c5_d_y;
  (void)chartInstance;
  if (mxIsEmpty(c5_u)) {
    *c5_svPtr = false;
  } else {
    *c5_svPtr = true;
    sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d, 1, 0, 0U, 0, 0U, 0);
    c5_d_y = c5_d;
  }

  sf_mex_destroy(&c5_u);
  return c5_d_y;
}

static void c5_g_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_nullptr, const
  char_T *c5_identifier, boolean_T *c5_svPtr, c5_coder_array_real_T *c5_d_y)
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = (const char_T *)c5_identifier;
  c5_thisId.fParent = NULL;
  c5_thisId.bParentIsCell = false;
  c5_h_emlrt_marshallIn(chartInstance, c5_sp, sf_mex_dup(c5_nullptr), &c5_thisId,
                        c5_svPtr, c5_d_y);
  sf_mex_destroy(&c5_nullptr);
}

static void c5_h_emlrt_marshallIn(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_u, const
  emlrtMsgIdentifier *c5_parentId, boolean_T *c5_svPtr, c5_coder_array_real_T
  *c5_d_y)
{
  c5_coder_array_real_T c5_r;
  int32_T c5_iv[1];
  int32_T c5_i;
  int32_T c5_loop_ub;
  boolean_T c5_bv[1];
  c5_array_real_T_Constructor(chartInstance, &c5_r);
  c5_iv[0] = 213200;
  if (mxIsEmpty(c5_u)) {
    *c5_svPtr = false;
    c5_array_real_T_SetSize(chartInstance, c5_sp, c5_d_y, (emlrtRTEInfo *)NULL,
      0);
  } else {
    *c5_svPtr = true;
    c5_array_real_T_SetSize(chartInstance, c5_sp, &c5_r, (emlrtRTEInfo *)NULL,
      sf_mex_get_dimension(c5_u, 0));
    c5_bv[0] = true;
    sf_mex_import_vs(c5_parentId, sf_mex_dup(c5_u), c5_r.vector.data, 1, 0, 0U,
                     1, 0U, 1, c5_bv, c5_iv, c5_r.size);
    c5_array_real_T_SetSize(chartInstance, c5_sp, c5_d_y, (emlrtRTEInfo *)NULL,
      c5_r.size[0]);
    c5_loop_ub = c5_r.size[0] - 1;
    for (c5_i = 0; c5_i <= c5_loop_ub; c5_i++) {
      c5_d_y->vector.data[c5_i] = c5_r.vector.data[c5_i];
    }
  }

  sf_mex_destroy(&c5_u);
  c5_array_real_T_Destructor(chartInstance, &c5_r);
}

static void c5_slStringInitializeDynamicBuffers
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_chart_data_browse_helper
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, int32_T
   c5_ssIdNumber, const mxArray **c5_mxData, uint8_T *c5_isValueTooBig)
{
  real_T c5_d;
  real_T c5_d1;
  real_T c5_d2;
  real_T c5_d3;
  real_T c5_d4;
  real_T c5_d5;
  real_T c5_d6;
  real_T c5_d7;
  *c5_mxData = NULL;
  *c5_mxData = NULL;
  *c5_isValueTooBig = 0U;
  switch (c5_ssIdNumber) {
   case 25U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData",
      *chartInstance->c5_waypointsx, 0, 0U, 1, 0U, 1, 5), false);
    break;

   case 26U:
    sf_mex_assign(c5_mxData, sf_mex_create("mxData",
      *chartInstance->c5_waypointsy, 0, 0U, 1, 0U, 1, 5), false);
    break;

   case 24U:
    *c5_isValueTooBig = 1U;
    break;

   case 11U:
    c5_d = *chartInstance->c5_distance_from_wp;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 5U:
    c5_d1 = *chartInstance->c5_target_th;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d1, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 12U:
    c5_d2 = *chartInstance->c5_sigma_dist;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d2, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 7U:
    c5_d3 = *chartInstance->c5_b_x;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d3, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 8U:
    c5_d4 = *chartInstance->c5_c_y;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d4, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 28U:
    c5_d5 = *chartInstance->c5_wp_cap_dist;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d5, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 10U:
    c5_d6 = *chartInstance->c5_capture_distance;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d6, 0, 0U, 0, 0U, 0),
                  false);
    break;

   case 9U:
    c5_d7 = *chartInstance->c5_stop;
    sf_mex_assign(c5_mxData, sf_mex_create("mxData", &c5_d7, 0, 0U, 0, 0U, 0),
                  false);
    break;
  }
}

static const mxArray *c5_hold(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "hold", 0U, 1U, 14, sf_mex_dup
    (c5_input0)), false);
  sf_mex_destroy(&c5_input0);
  return c5_m;
}

static const mxArray *c5_plot(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1, const mxArray *c5_input2)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "plot", 0U, 3U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1), 14, sf_mex_dup(c5_input2)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  sf_mex_destroy(&c5_input2);
  return c5_m;
}

static const mxArray *c5_sprintf(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "sprintf", 1U, 2U, 14,
    sf_mex_dup(c5_input0), 14, sf_mex_dup(c5_input1)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  return c5_m;
}

static const mxArray *c5_feval(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1)
{
  const mxArray *c5_m = NULL;
  (void)chartInstance;
  c5_m = NULL;
  sf_mex_assign(&c5_m, sf_mex_call(c5_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c5_input0), 14, sf_mex_dup(c5_input1)), false);
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
  return c5_m;
}

static void c5_b_feval(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, const mxArray *c5_input0, const
  mxArray *c5_input1)
{
  (void)chartInstance;
  sf_mex_call(c5_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c5_input0), 14,
              sf_mex_dup(c5_input1));
  sf_mex_destroy(&c5_input0);
  sf_mex_destroy(&c5_input1);
}

static void c5_b_sqrt(SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                      const emlrtStack *c5_sp, real_T *c5_c_x)
{
  static char_T c5_b_cv[4] = { 's', 'q', 'r', 't' };

  const mxArray *c5_d_y = NULL;
  const mxArray *c5_e_y = NULL;
  const mxArray *c5_f_y = NULL;
  real_T c5_d_x;
  boolean_T c5_b_p;
  boolean_T c5_p;
  (void)chartInstance;
  c5_d_x = *c5_c_x;
  if (c5_d_x < 0.0) {
    c5_p = true;
  } else {
    c5_p = false;
  }

  c5_b_p = c5_p;
  if (c5_b_p) {
    c5_d_y = NULL;
    sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_e_y = NULL;
    sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_cv4, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c5_f_y = NULL;
    sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_b_cv, 10, 0U, 1, 0U, 2, 1, 4),
                  false);
    sf_mex_call(c5_sp, &c5_r_emlrtMCI, "error", 0U, 2U, 14, c5_d_y, 14,
                sf_mex_call(c5_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c5_sp, NULL, "message", 1U, 2U, 14, c5_e_y, 14, c5_f_y)));
  }

  *c5_c_x = muDoubleScalarSqrt(*c5_c_x);
}

static void c5_or(SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
                  boolean_T c5_in1_data[], int32_T c5_in1_size[2], boolean_T
                  c5_in2_data[], int32_T c5_in2_size[2])
{
  int32_T c5_b_in1_size[2];
  int32_T c5_aux_0_1;
  int32_T c5_aux_1_1;
  int32_T c5_b_loop_ub;
  int32_T c5_i;
  int32_T c5_i1;
  int32_T c5_i2;
  int32_T c5_loop_ub;
  int32_T c5_stride_0_1;
  int32_T c5_stride_1_1;
  boolean_T c5_b_in1_data[121];
  (void)chartInstance;
  if (c5_in2_size[1] == 1) {
    c5_b_in1_size[1] = c5_in1_size[1];
  } else {
    c5_b_in1_size[1] = c5_in2_size[1];
  }

  c5_stride_0_1 = (c5_in1_size[1] != 1);
  c5_stride_1_1 = (c5_in2_size[1] != 1);
  c5_aux_0_1 = 0;
  c5_aux_1_1 = 0;
  if (c5_in2_size[1] == 1) {
    c5_i = c5_in1_size[1];
  } else {
    c5_i = c5_in2_size[1];
  }

  c5_loop_ub = c5_i - 1;
  for (c5_i1 = 0; c5_i1 <= c5_loop_ub; c5_i1++) {
    c5_b_in1_data[c5_i1] = (c5_in1_data[c5_aux_0_1] || c5_in2_data[c5_aux_1_1]);
    c5_aux_1_1 += c5_stride_1_1;
    c5_aux_0_1 += c5_stride_0_1;
  }

  c5_in1_size[0] = 1;
  c5_in1_size[1] = c5_b_in1_size[1];
  c5_b_loop_ub = c5_b_in1_size[1] - 1;
  for (c5_i2 = 0; c5_i2 <= c5_b_loop_ub; c5_i2++) {
    c5_in1_data[c5_i2] = c5_b_in1_data[c5_i2];
  }
}

static void c5_array_real_T_SetSize(SFc5_sl_groundvehicleDynamicsInstanceStruct *
  chartInstance, const emlrtStack *c5_sp, c5_coder_array_real_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  real_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_int32_T_SetSize(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, const emlrtStack *c5_sp, c5_coder_array_int32_T *c5_coderArray,
  const emlrtRTEInfo *c5_srcLocation, int32_T c5_size0)
{
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  int32_T *c5_newData;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c5_coderArray->size[0], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real_T_2D_SetSize
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, const emlrtStack *
   c5_sp, c5_coder_array_real_T_2D *c5_coderArray, const emlrtRTEInfo
   *c5_srcLocation, int32_T c5_size0, int32_T c5_size1)
{
  real_T *c5_newData;
  int32_T c5_newCapacity;
  int32_T c5_newNumel;
  (void)chartInstance;
  c5_coderArray->size[0] = c5_size0;
  c5_coderArray->size[1] = c5_size1;
  c5_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c5_coderArray->size[0],
                       c5_srcLocation, (void *)c5_sp), (size_t)(uint32_T)
    c5_coderArray->size[1], c5_srcLocation, (void *)c5_sp);
  if (c5_newNumel > c5_coderArray->vector.allocated) {
    c5_newCapacity = c5_coderArray->vector.allocated;
    if (c5_newCapacity < 16) {
      c5_newCapacity = 16;
    }

    while (c5_newCapacity < c5_newNumel) {
      if (c5_newCapacity > 1073741823) {
        c5_newCapacity = MAX_int32_T;
      } else {
        c5_newCapacity <<= 1;
      }
    }

    c5_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c5_newCapacity);
    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if ((void *)c5_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c5_srcLocation, (void *)c5_sp);
    }

    if (c5_coderArray->vector.data != NULL) {
      memcpy(c5_newData, c5_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c5_coderArray->vector.numel);
      if (c5_coderArray->vector.owner) {
        emlrtFreeMex(c5_coderArray->vector.data);
      }
    }

    c5_coderArray->vector.data = c5_newData;
    c5_coderArray->vector.allocated = c5_newCapacity;
    c5_coderArray->vector.owner = true;
  }

  c5_coderArray->vector.numel = c5_newNumel;
}

static void c5_array_real_T_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (real_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_real_T_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_s_Y7g3XIg0UrmNkIXtokcBk_C
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_pStruct)
{
  c5_array_real_T_Constructor(chartInstance, &c5_pStruct->x);
  c5_array_real_T_Constructor(chartInstance, &c5_pStruct->y);
}

static void c5_array_s_Y7g3XIg0UrmNkIXtokcBk_D
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_s_Y7g3XIg0UrmNkIXtokcBk *c5_pStruct)
{
  c5_array_real_T_Destructor(chartInstance, &c5_pStruct->x);
  c5_array_real_T_Destructor(chartInstance, &c5_pStruct->y);
}

static void c5_array_real_T_2D_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (real_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
  c5_coderArray->size[1] = 0;
}

static void c5_array_real_T_2D_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_real_T_2D *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_int32_T_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_int32_T *c5_coderArray)
{
  (void)chartInstance;
  c5_coderArray->vector.data = (int32_T *)NULL;
  c5_coderArray->vector.numel = 0;
  c5_coderArray->vector.allocated = 0;
  c5_coderArray->vector.owner = true;
  c5_coderArray->size[0] = 0;
}

static void c5_array_int32_T_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance,
   c5_coder_array_int32_T *c5_coderArray)
{
  (void)chartInstance;
  if (c5_coderArray->vector.owner && (c5_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c5_coderArray->vector.data);
  }
}

static void c5_array_cell_wrap_36_2s_Construct
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   c5_pMatrix[2])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_array_cell_wrap_36_Constructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static void c5_array_cell_wrap_36_Constructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   *c5_pStruct)
{
  c5_array_real_T_Constructor(chartInstance, &c5_pStruct->f1);
}

static void c5_array_cell_wrap_36_2s_Destructo
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   c5_pMatrix[2])
{
  int32_T c5_i;
  for (c5_i = 0; c5_i < 2; c5_i++) {
    c5_array_cell_wrap_36_Destructor(chartInstance, &c5_pMatrix[c5_i]);
  }
}

static void c5_array_cell_wrap_36_Destructor
  (SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance, c5_cell_wrap_36
   *c5_pStruct)
{
  c5_array_real_T_Destructor(chartInstance, &c5_pStruct->f1);
}

static int32_T c5_div_nzp_s32(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc)
{
  int32_T c5_quotient;
  uint32_T c5_absDenominator;
  uint32_T c5_absNumerator;
  uint32_T c5_tempAbsQuotient;
  boolean_T c5_quotientNeedsNegation;
  (void)chartInstance;
  (void)c5_EMLOvCount_src_loc;
  (void)c5_ssid_src_loc;
  (void)c5_offset_src_loc;
  (void)c5_length_src_loc;
  if (c5_numerator < 0) {
    c5_absNumerator = ~(uint32_T)c5_numerator + 1U;
  } else {
    c5_absNumerator = (uint32_T)c5_numerator;
  }

  if (c5_denominator < 0) {
    c5_absDenominator = ~(uint32_T)c5_denominator + 1U;
  } else {
    c5_absDenominator = (uint32_T)c5_denominator;
  }

  c5_quotientNeedsNegation = ((c5_numerator < 0) != (c5_denominator < 0));
  c5_tempAbsQuotient = c5_absNumerator / c5_absDenominator;
  if (c5_quotientNeedsNegation) {
    c5_quotient = -(int32_T)c5_tempAbsQuotient;
  } else {
    c5_quotient = (int32_T)c5_tempAbsQuotient;
  }

  return c5_quotient;
}

static int32_T c5_div_s32_ndbzs(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance, int32_T c5_numerator, int32_T c5_denominator, int32_T
  c5_EMLOvCount_src_loc, uint32_T c5_ssid_src_loc, int32_T c5_offset_src_loc,
  int32_T c5_length_src_loc)
{
  int32_T c5_quotient;
  uint32_T c5_absDenominator;
  uint32_T c5_absNumerator;
  uint32_T c5_tempAbsQuotient;
  boolean_T c5_quotientNeedsNegation;
  (void)chartInstance;
  (void)c5_EMLOvCount_src_loc;
  (void)c5_ssid_src_loc;
  (void)c5_offset_src_loc;
  (void)c5_length_src_loc;
  if (c5_denominator == 0) {
    if (c5_numerator >= 0) {
      c5_quotient = MAX_int32_T;
    } else {
      c5_quotient = MIN_int32_T;
    }
  } else {
    if (c5_numerator < 0) {
      c5_absNumerator = ~(uint32_T)c5_numerator + 1U;
    } else {
      c5_absNumerator = (uint32_T)c5_numerator;
    }

    if (c5_denominator < 0) {
      c5_absDenominator = ~(uint32_T)c5_denominator + 1U;
    } else {
      c5_absDenominator = (uint32_T)c5_denominator;
    }

    c5_quotientNeedsNegation = ((c5_numerator < 0) != (c5_denominator < 0));
    c5_tempAbsQuotient = c5_absNumerator / c5_absDenominator;
    if (c5_quotientNeedsNegation) {
      c5_quotient = -(int32_T)c5_tempAbsQuotient;
    } else {
      c5_quotient = (int32_T)c5_tempAbsQuotient;
    }
  }

  return c5_quotient;
}

static void init_dsm_address_info(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_sl_groundvehicleDynamicsInstanceStruct
  *chartInstance)
{
  chartInstance->c5_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c5_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c5_waypointsx = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_waypointsy = (real_T (*)[5])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_f_logical_map = (boolean_T (*)[213200])
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c5_distance_from_wp = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_target_th = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_sigma_dist = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_b_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c5_c_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c5_wp_cap_dist = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c5_capture_distance = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c5_stop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c5_sl_groundvehicleDynamics_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3497570916U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1946702953U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2995922186U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3814323353U);
}

mxArray *sf_c5_sl_groundvehicleDynamics_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "nav.algs.internal.codegen.PriorityQueue"));
  return(mxcell3p);
}

mxArray *sf_c5_sl_groundvehicleDynamics_jit_fallback_info(void)
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

mxArray *sf_c5_sl_groundvehicleDynamics_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c5_sl_groundvehicleDynamics(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiBO4GFgYAPSHEDMxAABrFA+IxBzQmmIOAtcXAGISyoLUkHixUXJnilAOi8xF8x"
    "PLK3wzEvLB5tvwYAwnw2L+YxI5nNCxSHggz1l+tUcQPodkPSzYNEvgKRfAIpTMotLEvOSU+PTiv"
    "Jz48sL+KDyA+sfJbB/DAj4hwXFPywMxSX5g8T9IkTFBydafID4JYlF6akl8SUZSP6g3D8CDpTph"
    "9hPyD98aP4B8ZNLi4pS80qAKSs+M6UCInaBAX8+ZETLh0xQPkhPDkMmQwEW92DzDxOafwRgntHo"
    "cQDTM3qoEi5DJX540eIHxE8rLSktSoVHz+CInw/tkPiJ6BhW8WNBIH7Y0OIHxC9ILMmIHyz5piE"
    "PEi8O+aPxAoqXykESLxsKIPEiUDii4oUVLV5A/JLM3NSiwVKOKTRC4sWjcUTVM1xo8QLiAyuY5P"
    "zSvBJw5AyW+AmZAImfmglUix8AHwtjPQ=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_sl_groundvehicleDynamics_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sYpX5Bw9B2QLkw4oqm9PdLF";
}

static void sf_opaque_initialize_c5_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  initialize_params_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
  initialize_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_sl_groundvehicleDynamics(void *chartInstanceVar)
{
  enable_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_sl_groundvehicleDynamics(void *chartInstanceVar)
{
  disable_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_sl_groundvehicleDynamics(void *chartInstanceVar)
{
  sf_gateway_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_sl_groundvehicleDynamics
  (SimStruct* S)
{
  return get_sim_state_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_sl_groundvehicleDynamics(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_cleanup_runtime_resources_c5_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_sl_groundvehicleDynamicsInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_sl_groundvehicleDynamics_optimization_info();
    }

    mdl_cleanup_runtime_resources_c5_sl_groundvehicleDynamics
      ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c5_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  mdl_start_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo
      (((SFc5_sl_groundvehicleDynamicsInstanceStruct*)chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c5_sl_groundvehicleDynamics(void
  *chartInstanceVar)
{
  mdl_terminate_c5_sl_groundvehicleDynamics
    ((SFc5_sl_groundvehicleDynamicsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_sl_groundvehicleDynamics(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_sl_groundvehicleDynamics
      ((SFc5_sl_groundvehicleDynamicsInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c5_sl_groundvehicleDynamics_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [29] = {
    "eNrtWs1vG0UUX6dplFRJCBJQJBBEFap6ARU3QS1CkMQfiSuncWqnFDCY8e6sd8ju7GZm1h+IAz3",
    "BoRI9of4RHDjwH3DjBBdUiSP/QI/c4M3u2lk2Try7Dq3bspJjv13/5s17v/e16yiZ0rYCxyK8ti",
    "4qygy8z8JrSvGPs4GcCb3889PKe4FcOacoqoGYKFHdVpIfqq3hFqZVV9dJNyGWulYFMWTxFHops",
    "vBNzG3TFcSmyTZPqI4Zpios4NhMJNLLieWahO4XXapKzfxDg6hG1bBdU9uABZG2Q83ecXodV1RA",
    "Y54wrIoixpowmO22jKKJWid7gYlOzsDqPnetxL7iWFRdR5rKt11TEMfEhS5WS5QLBF7gI+ytCiR",
    "wTnQTRwjh1T7athyTIBrf1wbiVexAdAi852jwd8cV4L2YekFfk1AkbEaQWbDMnIzwmNiKCfvchr",
    "A2E/tZWCKPm26rRWhLepe5FqZgP8RJDF/pObuNGWrhHZowB6V1ha5H8CAu4+dgSYZlqhx0LZ8Vn",
    "grr6S20wUM8pd6iSnPINHkybM12yriNTU9/HgmUAuvrTwDmnGg1+xZiMgsSZpJLyYGLA2zOphqJ",
    "z3A7gvIK7g0onjHgxJIhhTVw82Drg4VGxaTLhW3lII3y5XJMfUexJSow05GKY9c+hgjHsGEvrhL",
    "q1QhHTVOiwUvCszL2Cpimhipcd2m+Y7N98HHSInvoK5kJydBYa+E8FtgrGAWI7lvIdGPu2eJQ4W",
    "R47HGoWMn0AlbmTyqwilQDa7KfEBNvYy4X4LHrM/SRdbC2TUQvj7nKiBM3k1yONWgk0ku1noP36",
    "D61O7TIbKsaTAQnxBXGUDUQo9AWNqAtsV4RNh9v1wwf1GRkpRnPLCRM1JSxsYkpdBZpq+yESIWs",
    "KlAY3WBD42Cr5Eto7ZQTLmCc6hW8HNC8efTlTLJ59PlAvjLIpRKvMWAKQRumMCmtN71hD9eIhb0",
    "TVQQzhS8Gh9R7WTnUOzd1st4p+JRJiVPGxFVCuOkh/nklhFsKZHW1wc1GCyZGqrUxzJ0mzvdgEC",
    "YqH7qf+Rh+7+N+PZOMr4VA/s67B4Ay3RWHg/lh5NsWxDsVMmUglIHBNsSHPHTic1cNCzekZBVDl",
    "waCvCQ/e42gCo2AGaEEMsPCET9E/ds/wv7t466O4GU2gpOyg4TRgJugOPiZCH7G85IL8e7rvz8C",
    "b0TwUv6k8Gnu3foex4zXv8C6Xt+F+5pubznPbKdpd+vX4dxyxyBCt5lWL2xuray8U8ctA94aMN8",
    "XaDt7ObtSh48NTNv1dVfY1R6ktMXlF/vWvWVF7XtuRJwsBOe/f+2PzDD/xsX/XXdK4+CVY/hNg9",
    "8awc9LEX6k3G6WC+Yu6zg3t3aK2V16fXXnoLbpr3cptF5myHrhOE3z/bS4qyfUtdkjdS04FxwSv",
    "xbCL0T0TUfwM4Gv/qQ/ffbDiw+yvxxcOP/bGz//Pk49X1pIVs8WA/nV/v3UYOJsHxnK4sTB+Ugc",
    "SJl/5Nxe3ehc28julvc7K/aBda2ilYveep/Pn7zfuch+++eX4SVkdZXrM7WkhUowcv179iifMyP",
    "8MfevuH/4wXj4i2vReBjmr6WIv5b8edx7QNHQYcxqdJzFY+Lz0dpzYW1Uf8mEYty3ZxpmT3tC9v",
    "9CLD7mInxIWSDWwqIhjCH1Jf1+ltbGw/v6R9mzGLFn0bt3YgzuEiGyGkTrBnOQkqxuTIX6uqkQx",
    "Rmyn2H2TEXs6c8gyqW7a977/bun4pcnhZ+FCD9S1l3hMjygZzL4efiNz8/tb58qftLMrd5kOCl5",
    "8zX1eVmz/+dF8tKbEF5+dHxelg6eKV7ORniRsoD7WDYpdWz5js/L1p1nqs+ci/AiZWgwqu3KR82",
    "H6zx2fmr3fH6+uneq/Dwpz8cmHXeafonznG42Je7MmM8FHxVuXPv+6+cok/b9tM83J82Ok+rT/B",
    "C7MpF1J9WuBwn7x+uB/P7gt+KcQUxtyK9VweUyRvqwq09JfP+V0H/9520F6b/gn10+vrJOkdnjx",
    "P9xoH+6wuT/WQwuMYz48N8AH0cfijvHzEfyW8odQjW7w998O7uaHaev/QO2B7rB",
    ""
  };

  static char newstr [2089] = "";
  newstr[0] = '\0';
  for (i = 0; i < 29; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c5_sl_groundvehicleDynamics(SimStruct *S)
{
  const char* newstr = sf_c5_sl_groundvehicleDynamics_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1588883171U));
  ssSetChecksum1(S,(853022124U));
  ssSetChecksum2(S,(388133322U));
  ssSetChecksum3(S,(3603113169U));
}

static void mdlRTW_c5_sl_groundvehicleDynamics(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c5_sl_groundvehicleDynamics(SimStruct *S)
{
  SFc5_sl_groundvehicleDynamicsInstanceStruct *chartInstance;
  chartInstance = (SFc5_sl_groundvehicleDynamicsInstanceStruct *)utMalloc(sizeof
    (SFc5_sl_groundvehicleDynamicsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc5_sl_groundvehicleDynamicsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlStart =
    sf_opaque_mdl_start_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_sl_groundvehicleDynamics;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_sl_groundvehicleDynamics;
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

  mdl_setup_runtime_resources_c5_sl_groundvehicleDynamics(chartInstance);
}

void c5_sl_groundvehicleDynamics_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c5_sl_groundvehicleDynamics(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_sl_groundvehicleDynamics(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_sl_groundvehicleDynamics(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_sl_groundvehicleDynamics_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
