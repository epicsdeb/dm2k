#	Makefile.Host  for  base/src/sample
#
#
#	Sample Makefile.Host showing all possible entries
#	that are allowed using RULES.Host.
#

TOP = ../../..
include $(TOP)/configure/CONFIG

USR_VPATH += ../..

##### Variables to control build of dm2k
### 
### XRTHOME		holds the directory of the XRT/graph installation.
###			If this variable is set, dm2k is built with
###			XRT/graph support instead of JPT.
###
### STATIC_BUILD	controls whether to build dm2k statically or with
### 			shared libraries. The default setting is somewhere
### 			in your local/global config-directory.
###
### PURIFY		To debug dm2k with purify, set this variable to the
###			command-name to prepend to the linker-call
###			(e.g. "purify"). Setting PURIFY automatically sets
###			STATIC_BUILD to YES!
###
### The name of the produced binary is constructed the following way.
###
### 	+ The stem is always "dm2k"
###	+ if dm2k is built with cdev-support, "_cdev" is appended
###	+ if dm2k is built statically, ".static" is appended
###	+ if dm2k is to be debugged with purify ".pure" is appended


CMPLR = STRICT
# ANSI = GCC

#	Add-on CFLAGS that are needed by this Makefile.
#	(If possible, all system specific flags should be
#	 defined in CONFIG.Host.$(ARCH_CLASS))
#
#       These CFLAGS rules also apply to these Makefile-variables:
#		CXXFLAGS    C++ flags
#		LDFLAGS     link flags
#
#	This is used on all systems:
#USR_CFLAGS	  += -G
USR_CFLAGS        += -I../../../graphX -I../../../xc -I..
USR_CFLAGS	  += -DCONFIG_NO_TEAR_OFF
# If you want to be asked `Do you really want to Exit?' you have to define this
# USR_CFLAGS	  += -DPROMPT_TO_EXIT=1
# instead of
USR_CFLAGS	  += -DPROMPT_TO_EXIT=0

dm2k_CFLAGS += -DBUILT_AT="\"$(shell date)\"" -DBUILT_BY="\"$(USER)\"" -DXRT_DOCSTR="\"XRT/graph version 4.2.0\""

USR_CXXFLAGS := $(USR_CFLAGS)

# if SHARED_LIBRARIES is YES then shared and archive libraries will
#	both be built 
# SHARED_LIBRARIES = YES
SHARED_LIBRARIES = NO

# --------------------------------------------------------------------
#	defining products (executable programs)
# --------------------------------------------------------------------
#
#	if SRCS is undefined, it defaults to $(PROD).c 
SRCS=	actions.c \
	amDialog.c \
	callbacks.c \
	channelPalette.c \
	colorPalette.c \
	display.c \
	dmInit.c \
	eventHandlers.c \
	faceplateBase.c \
	faceplateGUI.c \
	faceplateGUICallback.c \
	faceplateDm2k.c \
	getArchiveData.c \
	help.c \
	dm2k.c \
	dm2kArc.c \
	dm2kBar.c \
	dm2kByte.c \
	dm2kCA.c \
	dm2kCartesianPlot.c \
	dm2kChoiceButtons.c \
	dm2kCommon.c \
	dm2kComposite.c \
	dm2kControl.c \
	dm2kDelay.c \
	dm2kDynSymbol.c \
	dm2kImage.c \
	dm2kIndicator.c \
	dm2kMenu.c \
	dm2kMessageButton.c \
	dm2kMeter.c \
	dm2kMonitor.c \
	dm2kOval.c \
	dm2kPixmap.c \
	dm2kPolygon.c \
	dm2kPolyline.c \
	dm2kRectangle.c \
	dm2kRelatedDisplay.c \
	dm2kShellCommand.c \
	dm2kStripChart.c \
	dm2kText.c \
	dm2kTextEntry.c \
	dm2kTextUpdate.c \
	dm2kValuator.c \
	dm2kWidget.c \
	objectPalette.c \
	productDescription.c \
	resourcePalette.c \
	shared.c \
	updateMonitors.c \
	utils.c \
	xgif.c \
	clipbd.c

PROD = dm2k-xrt

ifeq ($(STATIC_BUILD),YES)
 PROD := $(PROD).static
 ifneq ($(T_A),solaris)
  LDFLAGS += -Wl,-a,archive
 endif
endif

ifdef PURIFY
  PROD := $(PROD).pure
endif

XRT_CFLAGS = -DUSE_XRT -DUSE_XPM -I$(TOP)/xrt/include/Xm
USR_CFLAGS += $(XRT_CFLAGS)

dm2k-xrt_LIBS += xrtm pdsutil
xrtm_DIR = $(TOP)/xrt/lib
pdsutil_DIR = $(TOP)/xrt/lib

dm2k-jpt_LIBS += Jpt
Jpt_DIR = $(INSTALL_LIB)

PROD_LIBS += ca Com
ca_DIR = $(EPICS_BASE_LIB)
Com_DIR = $(EPICS_BASE_LIB)

#	system libs needed to link PROD, TESTPROD and sharable library
#
# for all systems:
SYS_PROD_LIBS += Mrm Xm Xt X11 Xext Xmu Xp Xpm
SYS_PROD_LIBS += m

#	other libs needed to link PROD, TESTPROD and sharable library
#
# for all systems:
PROD_LIBS += Unix ANLwidgets PrintUtils GraphX 
Unix_DIR = $(INSTALL_LIB)

HOST_OPT=NO

build: enums.h

include $(TOP)/configure/RULES

enums.h: ../../enums
	perl ../../makeEnums.pl < ../../enums > enums.h
