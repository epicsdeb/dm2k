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

#ifndef __XRT_GRAPH_PROP_H
#define __XRT_GRAPH_PROP_H

#if defined(XRT_PP_DIALOG) && defined(NDEBUG)
static char	sccsid_h2[] = "@(#)XrtGraphProp.h	4.3	01/04/04	Sitraka Inc.";
#endif

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef _NO_PROTO
extern Boolean	XrtUpdatePropertyEditor(Widget);
extern Boolean	XrtPopupPropertyEditor(Widget, char *, Boolean);
extern Boolean	XrtPopdownPropertyEditor(Widget, Boolean);
#else
extern Boolean	XrtUpdatePropertyEditor();
extern Boolean	XrtPopupPropertyEditor();
extern Boolean	XrtPopdownPropertyEditor();
#endif

#if defined(__cplusplus)
}
#endif

#endif /* __XRT_GRAPH_PROP_H */
