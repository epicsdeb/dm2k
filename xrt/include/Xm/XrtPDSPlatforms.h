/******************************************************************************
*
* Copyright (c) 2001, SITRAKA INC.  All Rights Reserved.
* http://www.sitraka.com
*
* This software is the confidential and proprietary information of Sitraka
* Inc. ("Confidential Information").  You shall not disclose such
* Confidential Information and shall use it only in accordance with the
* terms of the license agreement you entered into with Sitraka Software.
*
* SITRAKA SOFTWARE MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE 
* SUITABILITY OF THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT 
* NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR 
* A PARTICULAR PURPOSE, OR NON-INFRINGEMENT. SITRAKA SOFTWARE SHALL NOT 
* BE LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, 
* MODIFYING OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
*
******************************************************************************/

/** \file XrtPDSPlatforms.h
 * Pre-processor defines for all platforms.
 * \version 2.6
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * This file defines all the pre-processor macros needed to uniquely identify
 * all supported platforms for the XRT PDS package. Please see the section
 * \ref Platforms at the end of this file for detailed information on formatting
 * and conventions.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */

#ifndef XRTPDSPLATFORMS_H
#define XRTPDSPLATFORMS_H

#ifdef NDEBUG
static char sccsid_platforms_h[] = "@(#)XrtPDSPlatforms.h	2.6	01/04/04	Sitraka Inc.";
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * SPARC	Sunos 4.1.x
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined (sun) && !defined(SOLARIS) && !defined(SVR4) && !defined(__SVR4)
#	define XRT_SPARC						/* SPARC Processor */
#	define XRT_SPARC_SUNOS					/* SunOS 4.1.x on SPARC */
#	define XRT_CPU_NAME "Sun SPARC"			/* Name of CPU */
#	define XRT_OS_NAME "SunOS 4.1.x"		/* Name of OS */
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * SPARC	Solaris 2.4 -> 7.0
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined(sparc) && (defined(__SVR4) || defined(SVR4))
#	define XRT_SVR4
#	define XRT_SPARC
#	define XRT_SPARC_SOLARIS
#	define XRT_CPU_NAME "Sun SPARC"
#	if defined(__sparcv9)
#		define XRT_64BIT
#		define XRT_SPARC_SOLARIS_64BIT
#		define XRT_OS_NAME "Solaris 7.0 (64bit)"
#	else
#		define XRT_OS_NAME "Solaris 2.4 - 7.0"
#	endif
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * HPPA		HP-UX 9.x - 11.x
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#if defined (defined __hpux)
#	define XRT_HP700
#	define XRT_HP700_HPUX
#	define XRT_CPU_NAME "HP PA"
#	if defined (__LP64__)
#		define XRT_64BIT
#		define XRT_HP700_HPUX_64BIT
#		define XRT_OS_NAME "HP-UX 11.0 (64bit)"
#	else
#		if defined (XRT_HPUX_9)
#			define XRT_OS_NAME "HP-UX 9.07"
#		else
#			define XRT_OS_NAME "HP-UX 10.20 - 11.0"
#		endif
#	endif
#endif


/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * RS/6000		AIX 3.2.5 - 4.3.2
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined (_AIX)
#	define XRT_RS6000
#	define XRT_RS6000_AIX
#	define XRT_CPU_NAME "RS/6000"
#	if defined (XRT__64BIT__)
#		define XRT_64BIT
#		define XRT_RS6000_AIX_64BIT
#		define XRT_OS_NAME "AIX 4.3.2 (64bit)"
#	else
#		define XRT_OS_NAME "AIX 4.2 - 4.3.2"
#	endif
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * SGI		Irix 5.x - 6.x
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if	defined (__sgi)
#	define XRT_SGI
#	define XRT_SGI_IRIX
#	define XRT_CPU_NAME "SGI"
#	if defined ((XRT_IRIX_64BIT)
#		define XRT_64BIT
#		define XRT_SGI_IRIX_64BIT
#		define XRT_OS_NAME "IRIX 6.5 (64bit)"
#	else
#		define XRT_OS_NAME "IRIX 5.X - 6.X"
#	endif
#endif


/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * INTEL		Linux (ELF) with libc and Linux (ELF) with glibc
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined (__linux) && defined (__ELF__) && !defined(XRT_LINUX_GLIBC)
#	define XRT_INTEL
#	define XRT_CPU_NAME "Intel"
#	if !defined(XRT_LINUX_GLIBC)
#		define XRT_INTEL_LINUXELF
#		define XRT_OS_NAME "Linux, kernel version 2.0.18"
#	else
#		define XRT_INTEL_LINUXGLIBC
#		define XRT_OS_NAME "Linux, kernel version 2.0.32"
#	endif
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * INTEL		Interix for Windows NT
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if	defined (__OPENNT)
#	define XRT_INTEL
#	define XRT_INTEL_OPENNT
#	define XRT_CPU_NAME "Intel"
#	define XRT_OS_NAME "Interix 2.2+"
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * INTEL		ODT
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if	defined (sco)
#	define XRT_INTEL
#	define XRT_INTEL_SCO
#	define XRT_CPU_NAME "Intel"
#	define XRT_OS_NAME "ODT 3.0"
#endif


/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * INTEL		OpenServer
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if	defined (sco5)
#	define XRT_INTEL
#	define XRT_INTEL_SCO5
#	define XRT_CPU_NAME "Intel"
#	define XRT_OS_NAME "OpenServer 5"
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * INTEL		SVR4
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined ((SVR4) || (__SVR4)) && defined (i386)
#	define XRT_INTEL
#	define XRT_INTEL_SVR4
#	define XRT_CPU_NAME "Intel"
#	define XRT_OS_NAME "Solaris 251"
#endif


/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * INTEL		Unixware 7
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if	defined(__USLC__)
#	define XRT_INTEL
#	define XRT_INTEL_UNIXWARE7
#	define XRT_CPU_NAME "Intel"
#	define XRT_OS_NAME "Unixware 7"
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * INTEL		NuTCRACKER 4.0
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined(__NUTC__)
#	define XRT_INTEL
#	define XRT_INTEL_NUTCRACKER
#	define XRT_CPU_NAME "Intel"
#	define XRT_OS_NAME "NuTCRACKER 4.0"
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * DEC			Ultrix
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined(ultrix)
#	define XRT_DEC
#	define XRT_DEC_ULTRIX
#	define XRT_CPU_NAME "DEC"
#	define XRT_OS_NAME "Ultrix 4.4"
#endif


/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * Alpha	OSF (Digital Unix, Compaq Tru64 Unix etc)
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if (defined(__alpha) && defined(__osf__))
#	define XRT_ALPHA
#	define XRT_ALPHA_OSF
#	define XRT_CPU_NAME "Alpha"
#	define XRT_OS_NAME "OSF/1 3.0+"
#endif


/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * Alpha	VMS
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined(__VMS) && !defined(VAX)
#	define XRT_VMS
#   define XRT_ALPHA
#	define XRT_ALPHA_VMS
#	define XRT_OS_NAME	"VMS"
#	define XRT_CPU_NAME "Alpha"
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * VAX	VMS
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#if defined(__VMS) && defined(VAX)
#	define XRT_VMS
#	define XRT_VAX_VMS
#	define XRT_OS_NAME	"VMS"
#	define XRT_CPU_NAME "VAX"
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *
 * Common
 *
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
	
#ifdef SOURCE_CODE_DOCS
    This should never be compiled!	
	These are _only_ used to force inclusion of the related docs
#	define XRT_64BIT						/**< Generic 64-bit platform
												 (not including Alpha, LP64 only) */
#	define XRT_ALPHA_VMS					/**< VMS on an Alpha */
#	define XRT_CPU_NAME						/**< Name of CPU */
#	define XRT_OS_NAME 						/**< Name of OS */
#	define XRT_SPARC						/**< SPARC Processor */
#	define XRT_SPARC_SOLARIS				/**< Solaris 2.4 -> 7.0 on SPARC */
#	define XRT_SPARC_SOLARIS_64BIT			/**< 64-bit Solaris 7.x+ on SPARC */
#	define XRT_SPARC_SUNOS					/**< SunOS 4.1.x on SPARC */
#	define XRT_SVR4							/**< Any SVR4 Platform */
#	define XRT_HP700						/**< Any HP machine */
#	define XRT_HP700_HPUX                   /**< An HP machine running HPUX */
#	define XRT_HP700_HPUX_64BIT             /**< An HP machine running 64-bit HPUX (v11.00+)*/
#	define XRT_RS6000                       /**< Any IBM RS/6000 machine */
#	define XRT_RS6000_AIX                   /**< An RS/6000 running AIX */
#	define XRT_RS6000_AIX_64BIT             /**< An RS/6000 running 64-bit AIX (v4.3.1+) */
#	define XRT_SGI                          /**< Any Silicon Graphics machine */
#	define XRT_SGI_IRIX                     /**< An SGI running IRIX */
#	define XRT_SGI_IRIX_64BIT               /**< An SGI running 64-bit IRIX (6.5+)*/
#	define XRT_INTEL                        /**< Any Intel based machine */
#	define XRT_INTEL_LINUXELF               /**< Linux ELF (Redhat 4.x) running on Intel */
#	define XRT_INTEL_LINUXGLIBC             /**< Linux with glic (Redhat 5.x+) running on Intel */
#	define XRT_INTEL_OPENNT                 /**< Interix (OpenNT) version 2.2+ running on Intel */
#	define XRT_INTEL_SCO                    /**< SCO running on Intel */
#	define XRT_INTEL_SCO5                   /**< SCO OpenServer 5 running on Intel */
#	define XRT_INTEL_SVR4                   /**< Generic SVR4 (incl Solaris) running on Intel */
#	define XRT_INTEL_UNIXWARE7              /**< SCO Unixware 7.x+ running on Intel */
#	define XRT_INTEL_NUTCRACKER             /**< NutCRACKER (all versions) running on Intel */
#	define XRT_DEC                          /**< Any DEC machine */
#	define XRT_DEC_ULTRIX                   /**< A DEC machine running DEC-ULTRIX */
#	define XRT_ALPHA                        /**< Any Alpha machine (OSF and VMS) */
#	define XRT_ALPHA_OSF                    /**< Any Alpha running OSF/Digital Unix/Compaq Tru64 Unix/Nom du Jour */
#	define XRT_VMS							/**< Any VMS Platform */
#	define XRT_VAX_VMS						/**< VMS on a VAX */
#endif

#endif /* XRTPDSPLATFORMS_H */

/*----------------------------------------------------------------------------*/

/** \page Platforms Using The Pre-processor To Maintain Platform Specific Code

<H3>Rationale and History</H3>

This file exists to help clean up the source code of the XRT PDS products
and to centralize a lot of the logic involved in ifdef'ing code for different
platforms.

Hopefully it will make porting to a new platform or updating an existing platform
much simpler.

Previously you would have to write something like:

\verbatim
#if (defined(__mips) && !defined(SVR4)) || (defined(__alpha) && defined(__osf__))
	( Try and figure out which platforms this code is supposed to apply to )
#endif
\endverbatim

and now, all you would have to write is:

\verbatim
#if defined(XRT_ALPHA_OSF) || defined(XRT_DEC_ULTRIX) || defined(XRT_SGI)
	( No points for guessing this one ;-) )
#endif
\endverbatim

<H3>Conventions</H3>
<OL>
	<LI>Each platform gets its' own \b unique section. No combining platforms!</LI>
	<LI>Inside each section, the defines go from least to most specific.<BR>
	    e.g: \c XRT_SVR4 -> \c XRT_SPARC_SOLARIS_64BIT </LI>
	<LI>There will be some duplication among platforms, this is OK.<BR>
		e.g.: All SVR4 platfroms define \c XRT_SVR4 </LI>
	<LI>Each define if broken into sections in the following order:
		<UL>
			<LI>\c XRT_
			<LI>Type of CPU (e.g. \c SPARC or \c SGI )
			<LI>Operating System (e.g. \c SOLARIS or \c IRIX )
			<LI>Optional Extras (e.g. OS version, 64 bit)
		</UL>
	</LI>
	<LI>For documentation purposes, each define is duplicated in the section
		\c SOURCE_CODE_DOCS. See "Documentation" for an explanation.</LI>
	<LI>Each platform should define strings for \c XRT_OS_NAME and \c XRT_CPU_NAME
	    (they will probably come in handy at some time.</LI>
</OL>

<H3>Documentation</H3>

Because of the way the source code documentation is set up, each symbol that
you want to document has to be duplicated at the end of the file in a block
surounded with \c SOURCE_CODE_DOCS.

For example:
\verbatim
#ifdef SOURCE_CODE_DOCS
	This should never be compiled!	
	These are _only_ used to force inclusion of the related docs
#	define XRT_64BIT            /**< Generic 64-bit platform *\/
#	define XRT_ALPHA_VMS        /**< VMS on an Alpha *\/
	(etc)
#endif
\endverbatim

<H3>Examples</H3>

For our example, we will be looking at the section for SPARC Solaris line by
line. For reference, the complete section looks like:

\verbatim
1  #if defined(sparc) && (defined(__SVR4) || defined(SVR4))
2  #	define XRT_SVR4
3  #	define XRT_SPARC
4  #	define XRT_SPARC_SOLARIS
5  #	define XRT_CPU_NAME "Sun SPARC"
6  #	if defined(__sparcv9)
7  #		define XRT_64BIT
8  #		define XRT_SPARC_SOLARIS_64BIT
9  #		define XRT_OS_NAME "Solaris 7.0 (64bit)"
10 #	else
11 #		define XRT_OS_NAME "Solaris 2.4 - 7.0"
12 #	endif
13 #endif
\endverbatim

Here is the explanation of each line:

<OL>
	<LI>System and compiler 'define's that are \b unique to SPARC-Solaris</LI>
	<LI>Generic define for all SVR4 plaforms</LI>
	<LI>Generic define for all SPARC platforms</LI>
	<LI>Specific name for this platform ( \e required )</LI>
    <LI>String containing the name of the CPU vendor or type ( \e required )</LI>
	<LI>This is defined if we are compiling in 64-bit mode on Solaris 7</LI>
	<LI>Generic define for all 64-bit platforms (LP64 that is, not AlphaOSF)</LI>
	<LI>Extra specific define for 64-bit Solaris</LI>
	<LI>String containing the name of the operating system ( \e required )</LI>
	<LI>(closing)</LI>
	<LI>String containing the name of the operating system ( \e required )</LI>
	<LI>(closing)</LI>
	<LI>(closing)</LI>
</OL>

<H3>Notes on Usage</H3>

<UL>
	<LI>You can use the generic macros as well as the specific ones:<BR>
		e.g. \c XRT_SPARC for any OS on a SPARC chip (SunOS / Solaris / UltraPenguin)
	</LI>
</UL>

 */
