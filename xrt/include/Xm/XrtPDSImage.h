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

/** \file XrtPDSImage.h
 * Image Conversion Routines.
 * \version 2.5
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * This file defines the prototypes for the built in image conversion routines.
 * Specifically, the routines for Xpm. XWD and GIF images.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */

#ifndef XRTIMAGE_H
#define XRTIMAGE_H

#if defined(XRT_IMAGE_UTIL) && defined(NDEBUG)
static char sccsid_h[] = "@(#)XrtPDSImage.h	2.5	01/04/04	Sitraka Inc.";
#endif

#include "XrtPDSImageObj.h"

#define XRTPDS_XPM_IMAGE 0
#define XRTPDS_XWD_IMAGE 1
#define XRTPDS_GIF_IMAGE 2
#define XRTPDS_JPEG_IMAGE 3
#define XRTPDS_PNG_IMAGE 4

#if defined(__cplusplus)
extern "C" {
#endif

/*----------------------------------------------------------------------------
 * Xpm Image functions
 */
	
/**
 * Verifies that the provided file name if a valid XPM filename.
 * The filename is considered valid if it has the extension ".xpm".
 * @param file_name The name of the file to check.
 * @return True is the file name has the extension ".xpm" and
 *         False otherwise
 */
extern Boolean XrtPDSImageCheckXpmName(
#ifndef _NO_PROTO
   String file_name
#endif
);

/**
 * Check to see if the XPM magic string is present at the
 * beginning of the provided buffer.
 * @param buffer A buffer of <b>at least</b> 9 bytes containing the
 *        header information to check. This buffer is generally the first
 *        section read from a XPM image file.
 * @return True is the buffer contains the XPM magic string and False if it
 *         does not.
 */
extern Boolean XrtPDSImageCheckXpmHeader(
#ifndef _NO_PROTO
    char *buffer
#endif
);

/**
 * Creates an XrtPDSImage from the file named \c file_name.
 * The file name is first checked to see if it is a valid XPM file name,
 * If it is not, then the file is opened and scanned for the XPM magic
 * header. If this is not found then the function returns NULL.
 * @param file_name The name of the file containing the XPM image that is
 *        is to be converted to an XrtPDSImage.
 * @return The XrtPDSImage that was created from the XPM file, or NULL
 *         if the file was not a XPM file or could not be converted.
 *
 * The returned image should be freed with XrtPDSImageDestroy() when it is
 * no longer needed.
 * \sa XrtPDSImageCheckXpmHeader() and XrtPDSImageCheckXpmName()
 */
extern XrtPDSImage XrtPDSImageCreateFromXpmFile(
#ifndef _NO_PROTO
Widget w, String file_name
#endif
);

/**
 * Convert the provided XImage to a XPM format and save it to the file \c filename.
 * A widget is required because the function has to be able to convert the XImage
 * pixel values to their red, green and blue components and this requires a
 * connection to the \c XmDisplay through the provided Widget.
 * @param w Any widget in the application
 * @param image A pointer to the XImage to be converted.
 * @param color Whether to save the XPM as color or grey scale.
 * @param msg A 256 character message buffer (which may be NULL) to return any
 *  	  error messages in. If the buffer is NULL, error messages are printed to
 *        \c stdout or \c stderr.
 * @return True is the image was successfully converted and saved and False
 *         if it was not.
 */
extern XrtPDSImage XrtPDSImageCreateFromXpmData(
#ifndef _NO_PROTO
Widget w, char **buffer
#endif
);

/**
 * The XrtPDSImageFuncs structure containing all the XPM routines.
 * This structure is passed to the image enable functions of the XRT widgets
 * to register the XPM image conversion routines.
 */
extern XrtPDSImageFuncs *xrtpds_XpmImageUtils;


/*----------------------------------------------------------------------------
 * XWD Image Functions
 */

/**
 * Verifies that the provided file name if a valid XWD filename.
 * The filename is considered valid if it has the extension ".xwd".
 * @param file_name The name of the file to check.
 * @return True is the file name has the extension ".xwd" and
 *         False otherwise
 */
extern Boolean XrtPDSImageCheckXWDName(
#ifndef _NO_PROTO
   String file_name
#endif
);

/**
 * Check to see if the XWD magic string is present at the
 * beginning of the provided buffer.
 * @param buffer A buffer of <b>at least</b> 8 bytes containing the
 *        header information to check. This buffer is generally the first
 *        section read from a XWD image file.
 * @return True is the buffer contains the XWD magic string and False if it
 *         does not.
 */
extern Boolean XrtPDSImageCheckXWDHeader(
#ifndef _NO_PROTO
   char *buffer
#endif
);

/**
 * Creates an XrtPDSImage from the file named \c file_name.
 * The file name is first checked to see if it is a valid XWD file name,
 * If it is not, then the file is opened and scanned for the XWD magic
 * header. If this is not found then the function returns NULL.
 * @param file_name The name of the file containing the XWD image that is
 *        is to be converted to an XrtPDSImage.
 * @return The XrtPDSImage that was created from the XWD file, or NULL
 *         if the file was not a XWD file or could not be converted.
 *
 * The returned image should be freed with XrtPDSImageDestroy() when it is
 * no longer needed.
 * \sa XrtPDSImageCheckXWDHeader() and XrtPDSImageCheckXWDName()
 */
extern XrtPDSImage XrtPDSImageCreateFromXWDFile(
#ifndef _NO_PROTO
   Widget w, String file_name
#endif
);

/**
 * The XrtPDSImageFuncs structure containing all the XWD routines.
 * This structure is passed to the image enable functions of the XRT widgets
 * to register the XWD image conversion routines.
 */
extern XrtPDSImageFuncs *xrtpds_XWDImageUtils;


/*----------------------------------------------------------------------------
 * Gif Image Functions
 */

/**
 * Verifies that the provided file name if a valid GIF filename.
 * The filename is considered valid if it has the extension ".gif".
 * @param file_name The name of the file to check.
 * @return True is the file name has the extension ".gif" and
 *         False otherwise
 */
extern Boolean XrtPDSImageCheckGifName(
#ifndef _NO_PROTO
   String file_name
#endif
);

/**
 * Check to see if the GIF magic string is present at the
 * beginning of the provided buffer.
 * @param buffer A buffer of <b>at least</b> 5 bytes containing the
 *        header information to check. This buffer is generally the first
 *        section read from a GIF image file.
 * @return True is the buffer contains the GIF magic string and False if it
 *         does not.
 */
extern Boolean XrtPDSImageCheckGifHeader(
#ifndef _NO_PROTO
   char *buffer
#endif
);

/**
 * Creates an XrtPDSImage from the file named \c file_name.
 * The file name is first checked to see if it is a valid GIF file name,
 * If it is not, then the file is opened and scanned for the GIF magic
 * header. If this is not found then the function returns NULL.
 * @param file_name The name of the file containing the GIF image that is
 *        is to be converted to an XrtPDSImage.
 * @return The XrtPDSImage that was created from the GIF file, or NULL
 *         if the file was not a GIF file or could not be converted.
 *
 * The returned image should be freed with XrtPDSImageDestroy() when it is
 * no longer needed.
 * \sa XrtPDSImageCheckGifHeader() and XrtPDSImageCheckGifName()
 */
extern XrtPDSImage XrtPDSImageCreateFromGifFile(
#ifndef _NO_PROTO
   Widget w, String file_name
#endif
);

/**
 * The XrtPDSImageFuncs structure containing all the GIF routines.
 * This structure is passed to the image enable functions of the XRT widgets
 * to register the GIF image conversion routines.
 */
extern XrtPDSImageFuncs *xrtpds_GifImageUtils;

#if defined(__cplusplus)
}
#endif


#endif /* ifndef XRTIMAGE_H */
