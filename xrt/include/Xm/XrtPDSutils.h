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

/** \file XrtPDSutils.h
 * Utility functions used by the PDS libraries..
 * \version 2.6
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */

#ifndef _XRTPDS_UTILS_H
#define _XRTPDS_UTILS_H

#if defined(XRTPDS_UTILS_C) && defined(NDEBUG)
static char sccsid_h[] = "@(#)XrtPDSutils.h	2.6	01/04/04	Sitraka Inc.";
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/**	
 * Calls xrtpds_WarningMsgWidget() with the provided params.
 * If \c num_params < 0, \c params is considered to be a single String
 * rather than an array of Strings and a list is created internally to be passed
 * to xrtpds_WarningMsgWidget().
 */
extern void
xrtpds_WarningMsg(
#ifndef _NO_PROTO
	Widget w, String name, String type, String default_text,
	String *params, Cardinal *num_params
#endif				
);

/**
 * Calls XtAppWarningMsg() or XtWarningMsg() with the provided params.
 * XtAppWarningMsg() is called if the widget \c w exists and is realized,
 * XtWarningMsg() is called otherwise. It is recommended that you provide
 * a valid, realized widget as calling XtWarningMsg() is deprecated.
 */
extern void
xrtpds_WarningMsgWidget(
#ifndef _NO_PROTO
	Widget w, String name, String type,
	String default_text, String *params, Cardinal *num_params
#endif
);

/**
 * Calls XtAppErrorMsg() or XtErrorMsg() with the provided params.
 * XtAppErrorMsg() is called if the widget \c w exists and is realized,
 * XtErrorMsg() is called otherwise. It is recommended that you provide
 * a valid, realized widget as calling XtErrorMsg() is deprecated.
 * <P>
 * \b NOTE: Both XtAppErrorMsg() and XtErrorMsg() will eventually call exit().
 */
extern void
xrtpds_ErrorMsg(
#ifndef _NO_PROTO	
	Widget w, String name, String type,
	String default_text, String *params, Cardinal *num_params
#endif
);

/**
 * A variable argument version of  xrtpds_WarningMsgWidget(). It simple
 * turns the variable arument list into a list + num_elements pair and calls
 * xrtpds_WarningMsgWidget().
 */
#if !defined(_NO_PROTO) && __STDC__ && !defined(UNPROTOIZE) || defined(ultrix)
extern void
xrtpds_VaWarningMsg(Widget w, String name, String type, String default_text, ...);
#else
extern void
xrtpds_VaWarningMsg();
#endif

#if defined(__cplusplus)
}
#endif


#endif /* _XRTPDS_UTILS_H */
