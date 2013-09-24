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

/** \file XrtPDSPng.h
 * Functions to read and write PNG files.
 * \version 2.7
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * This header file is meant to be used with \c libxrtpng.a library
 * provided in \c $XRTHOME/lib
 *
 * Copyright (c) 2001, SITRAKA INC.  All Rights Reserved.
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 *
 */

#ifndef XRTPNG_H
#define XRTPNG_H

#if defined(NDEBUG)
static char sccsid_h_XrtPDSPng[] = "@(#)XrtPDSPng.h	2.7	01/04/04	Sitraka Inc.";
#endif

#include "XrtPDSImageObj.h"

/*----------------------------------------------------------------------------
 * Png Image functions
 */

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * Verifies that the provided file name if a valid PNG filename.
 * The filename is considered valid if it has the extension ".png".
 * @param file_name The name of the file to check.
 * @return True is the file name has the extension ".png" and
 *         False otherwise
 */
extern Boolean XrtPDSImageCheckPngName(
#ifndef _NO_PROTO
  String file_name
#endif
);

/**
 * Check to see if the PNG magic number(s) is present at the
 * beginning of the provided buffer.
 * @param buffer A buffer of <b>at least</b> 4 bytes containing the
 *        header information to check. This buffer is generally the first
 *        section read from a PNG image file.
 * @return True is the buffer contains the PNG magic header and False if it
 *         does not.
 */
extern Boolean XrtPDSImageCheckPngHeader(
#ifndef _NO_PROTO
char *buffer
#endif
);

/**
 * Creates an XrtPDSImage from the file named \c file_name.
 * The file name is first checked to see if it is a valid PNG file name,
 * If it is not, then the file is opened and scanned for the PNG magic
 * header. If this is not found then the function returns NULL.
 * @param file_name The name of the file containing the PNG image that is
 *        is to be converted to an XrtPDSImage.
 * @return The XrtPDSImage that was created from the PNG file, or NULL
 *         if the file was not a PNG file or could not be converted.
 *
 * The returned image should be freed with XrtPDSImageDestroy() when it is
 * no longer needed.
 * \sa XrtPDSImageCheckPngHeader() and XrtPDSImageCheckPngName()
 */
extern XrtPDSImage XrtPDSImageCreateFromPngFile(
#ifndef _NO_PROTO
Widget w, String file_name
#endif
);

/**
 * Convert the provided XImage to a PNG format and save it to the file \c filename.
 * A widget is required because the function has to be able to convert the XImage
 * pixel values to their red, green and blue components and this requires a
 * connection to the \c XmDisplay through the provided Widget.
 * @param w Any widget in the application
 * @param image A pointer to the XImage to be converted.
 * @param color Whether to save the PNG as color or grey scale.
 * @param msg A 256 character message buffer (which may be NULL) to return any
 *  	  error messages in. If the buffer is NULL, error messages are printed to
 *        \c stdout or \c stderr.
 * @return True is the image was successfully converted and saved and Fasle
 *         if it was not.
 */
extern Boolean XrtPDSOutputPng(
#ifndef _NO_PROTO
Widget w, XImage *image, String filename, Boolean color, String msg
#endif
);

/**
 * The XrtPDSImageFuncs structure containing all the PNG routines.
 * This structure is passed to the image enable functions of the XRT widgets
 * to register the PNG image conversion routines.
 */
extern XrtPDSImageFuncs *XrtPDSPngImageUtils;

#if defined(__cplusplus)
}
#endif


#endif /* ifndef XRTPNG_H */
