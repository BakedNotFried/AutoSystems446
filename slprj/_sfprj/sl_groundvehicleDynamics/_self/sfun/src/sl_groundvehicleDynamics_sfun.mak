# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL     = sl_groundvehicleDynamics
TARGET      = sfun
MODULE_SRCS   = c5_sl_groundvehicleDynamics.c half_type.c
MODEL_SRC  = sl_groundvehicleDynamics_sfun.c
MODEL_REG = sl_groundvehicleDynamics_sfun_registry.c
MAKEFILE    = sl_groundvehicleDynamics_sfun.mak
MATLAB_ROOT  = C:\Program Files\MATLAB\R2024a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   =  /I "C:\Users\jeff\qepoxy dropbox\jeff whitford\EGH446\egh446_simenv2024\sim_env\autosystems446\slprj\_sfprj\sl_groundvehicledynamics\_self\sfun\src" /I "C:\Users\jeff\qepoxy dropbox\jeff whitford\EGH446\egh446_simenv2024\sim_env\autosystems446" /I "C:\Users\jeff\qepoxy dropbox\jeff whitford\EGH446\egh446_simenv2024\sim_env\autosystems446\toolboxes\ground_robot"
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "C:\Program Files\MATLAB\R2024a\extern\include" \
    /I "C:\Program Files\MATLAB\R2024a\simulink\include" \
    /I "C:\Program Files\MATLAB\R2024a\simulink\include\sf_runtime" \
    /I "C:\Program Files\MATLAB\R2024a\stateflow\c\mex\include" \
    /I "C:\Program Files\MATLAB\R2024a\rtw\c\src" \
    /I "C:\Users\jeff\Qepoxy Dropbox\Jeff whitford\EGH446\egh446_simEnv2024\sim_env\AutoSystems446\slprj\_sfprj\sl_groundvehicleDynamics\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "C:\Program Files\MATLAB\R2024a\extern\include\nav"
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD  
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS)

USER_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS     = \
     "c_mexapi_version.obj" \
     "priorityqueue_api.obj" \

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = sl_groundvehicleDynamics_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(DSP_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


c_mexapi_version.obj :  "C:\Program Files\MATLAB\R2024a\extern\version\c_mexapi_version.c"
	@echo ### Compiling "C:\Program Files\MATLAB\R2024a\extern\version\c_mexapi_version.c"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2024a\extern\version\c_mexapi_version.c"
priorityqueue_api.obj :  "c:\program files\matlab\r2024a\toolbox\nav\navalgs2\builtins\libsrc\priorityqueuecodegen\priorityqueue_api.cpp"
	@echo ### Compiling "c:\program files\matlab\r2024a\toolbox\nav\navalgs2\builtins\libsrc\priorityqueuecodegen\priorityqueue_api.cpp"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\program files\matlab\r2024a\toolbox\nav\navalgs2\builtins\libsrc\priorityqueuecodegen\priorityqueue_api.cpp"
