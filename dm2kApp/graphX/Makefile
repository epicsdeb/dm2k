#	Makefile.Host  for  base/src/sample
#
#
#	Sample Makefile.Host showing all possible entries
#	that are allowed using RULES.Host.
#

TOP = ../..
include $(TOP)/configure/CONFIG

CMPLR = STRICT
# This is NOT the correct way to do what's needed, but...
ifeq ($(T_A),hp700)
USR_CFLAGS += +DAportable
endif
#ANSI = GCC

#	Add-on CFLAGS that are needed by this Makefile.
#	(If possible, all system specific flags should be
#	 defined in CONFIG.Host.$(ARCH_CLASS))
#
#       These CFLAGS rules also apply to these Makefile-variables:
#		CXXFLAGS    C++ flags
#		LDFLAGS     link flags
#
#	This is used on all systems:
USR_CFLAGS += -I$(X11_INC) -I$(MOTIF_INC)
#USR_CFLAGS         = -DVAR=value -Ddefine_for_all_systems
#	This is added to the above, but only for ARCH_CLASS=BSD:
#USR_CFLAGS_BSD     = -DVERSION='Berkeley enhanced'
#	..only for WIN32:
#USR_CFLAGS_WIN32   = -DVERSION='WIN32 port'
#
#	-nil- is special:
#	if USR_CFLAGS_SYSV was undefined or empty, .._DEFAULT would have
#	been used.
#	To indicate
#		"yes, there is a special USR_CFLAGS for SYSV, but it's empty"
#	you have to set it to -nil-:
#USR_CFLAGS_SYSV    = -nil-
#	.. for all other arch classes:
#USR_CFLAGS_DEFAULT = -DVERSION='generic Unix'

#	CFLAGS that are only used to compile a_file.c or a_file.cc:
#
#a_file_CFLAGS      = -DIN_A_FILE
#a_file_CFLAGS_WIN32   = -DVERSION='WIN32 port'

#	---------------------------------------------------------
#	general rule for all .c .cc .h .hh files and scripts:
#
#	In here you supply just the filename without '../' etc.
#	While building in an O.xxx subdir, the
#	sources are extracted from either the
#	             '..'
#	dir or - if it exists - the dir
#	             '../$(ARCH_CLASS)'
#	is preferred.
#	---------------------------------------------------------


#	includes to install from this Makefile
#
#	again: if INC_$(ARCH_CLASS) is defined, it is added to INC,
#	otherwise INC_DEFAULT (if defined) is added:
#
#INC_DEFAULT = for_all_but_WIN32_or_hp700.h
#INC_WIN32   = only_for_WIN32.h
#INC_hp700   = -nil-		# hp700 uses no special include
#INC         = file.h

# --------------------------------------------------------------------
#	defining a library
# --------------------------------------------------------------------
#
#	Contents of a library are specified via LIBSRCS.
#	From this the platform specific object names (.o, .obj, ...)
#	are derived automatically.
#
#	Platform specific objects:
#	use LIBOBJS_$(ARCH_CLASS)  or  .._DEFAULT
#
#	Platform specific files can also be put in
#	separate os/ARCH_CLASS directories!
#
#	For almost every file the seach order is:
#	./os/ARCH_CLASS
#	./os/generic
#	.
#	So usually only LIBSRCS should be sufficient!
#
LIBSRCS         = 	algorithms.c \
	graph.c \
	graph3d.c \
	graphInteraction.c \
	seql.c seqlInteraction.c \
	strip.c \
	surface.c \
	surfaceInternals.c \
	utils.c

#LIBSRCS_DEFAULT = posix.c
#LIBSRCS_WIN32   = win32_special.c
#LIBSRCS_BSD     = -nil-

#	Library to build:
#	lib$(LIBRARY).a  or   ..dll/..exp/..lib
#
#	Currently you can build only one (1) lib per Makefile.Host!
#	
LIBRARY=GraphX

# if SHARED_LIBRARIES is YES then shared and archive libraries will
#	both be built 
#SHARED_LIBRARIES = YES
#
#	Library version
#SHRLIB_VERSION = 
#	On WIN32 results in /version:$(SHRLIB_VERSION) link option
#	On Unix type hosts .$(SHRLIB_VERSION) is appended to library name  

# --------------------------------------------------------------------
#	defining products (executable programs)
# --------------------------------------------------------------------
#
#	if SRCS is undefined, it defaults to $(PROD).c 
#SRCS=a.c b.c c.c

#	SRCS that are only used for PROD a_file
#
#a_file_SRCS = aa.c bb.c

#	EPICS libs needed to link PROD, TESTPROD and sharable library
#
#	note that DLL_LIBS (the libraries needed to link a shareable
#	library) is created by default from the PROD/SYS libraries specified 
#	below minus the name of the sharable library (LIBRARY)
#	
#
# for all systems:
#PROD_LIBS         = Com Ca
# for most systems:
#PROD_LIBS_DEFAULT = mathlib
#PROD_LIBS_WIN32   = -nil-

#	system libs needed to link PROD, TESTPROD and sharable library
#
# for all systems:
#SYS_PROD_LIBS     = m
# for most systems:
#SYS_PROD_LIBS_DEFAULT = foolib
#SYS_PROD_LIBS_WIN32   = -nil-

#	other libs needed to link PROD, TESTPROD and sharable library
#
# for all systems:
#USR_LIBS     = Xm Xt X11
#Xm_DIR = $(MOTIF_LIB)
#Xt_DIR = $(X11_LIB)
#X11_DIR = $(X11_LIB)

LIB_SYS_LIBS += Xm Xt X11
LIB_LIBS += PrintUtils

# for most systems:
#USR_LIBS_DEFAULT = foolib
#USR_LIBS_WIN32   = -nil-
#foolib_DIR = $(FOO_LIB)

#	Product,
#	may be   caRepeater.o -> caRepeater
#	or       caRepeater.obj -> caRepeater.exe
#PROD         = prod
#PROD_DEFAULT = product_for_rest
#PROD_WIN32   = product_only_for_WIN32
#PROD_BSD     = product_only_for_BSD
#PROD_SYSV    = product_only_for_SYSV

#	Product version
#PROD_VERSION = 
#	On WIN32 results in /version:$(SHRLIB_VERSION) link option
#	On Unix type hosts PROD_VERSION) is ignored

#	Scripts to install
#
#	If there is  both  ../$(SCRIPT) and  ../$(ARCH_CLASS)/$(SCRIPT),
#	the latter, system specific version will be installed!
#
#SCRIPTS_DEFAULT = script_for_rest
#SCRIPTS_WIN32   = script_only_for_WIN32
#SCRIPTS_BSD     = script_only_for_BSD
#SCRIPTS         = script

#	if you want to build products locally without installing:
# TESTPROD = test

# put all definitions before the following include line
# put all rules after the following include line

include $(TOP)/configure/RULES

#	EOF Makefile.Host
