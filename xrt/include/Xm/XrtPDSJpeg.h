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

/** \file XrtPDSJpeg.h
 * Functions to read and write JPEG files.
 * \version 2.7
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */

#ifndef XRTJPEG_H
#define XRTJPEG_H

#if defined(NDEBUG)
static char sccsid_h_XrtPDSJpeg[] = "@(#)XrtPDSJpeg.h	2.7	01/04/04	Sitraka Inc.";
#endif

#include "XrtPDSImageObj.h"

/*----------------------------------------------------------------------------
 * Jpeg Image functions
 */

#if defined(__cplusplus)
extern "C" {
#endif


extern Boolean XrtPDSImageCheckJpegName(
#ifndef _NO_PROTO
   String file_name
#endif
);

extern Boolean XrtPDSImageCheckJpegHeader(
#ifndef _NO_PROTO
   char *buffer
#endif
);

extern XrtPDSImage XrtPDSImageCreateFromJpegFile(
#ifndef _NO_PROTO
    Widget w, String file_name
#endif
);

#if !defined(__alpha) && !defined(ultrix)
extern Boolean XrtPDSOutputJpeg(
#ifndef _NO_PROTO
    Widget w, XImage *image, String filename, Boolean color, String msg
#endif
);
#endif

extern XrtPDSImageFuncs *XrtPDSJpegImageUtils;

#if defined(__cplusplus)
}
#endif


#endif /* ifndef XRTJPEG_H */
