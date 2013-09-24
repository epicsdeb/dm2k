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

/** \file XrtPDSImageObj.h
 * Opaque image object for XRT widgets.
 * \version 2.4
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * Copyright (c) 2001, SITRAKA INC.  All Rights Reserved.
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 *
 */

#ifndef XRTIMAGE_OBJECT_H
#define XRTIMAGE_OBJECT_H

#if defined(XRT_IMAGE_OBJECT) && defined(NDEBUG)
static char sccsid_h[] = "@(#)XrtPDSImageObj.h	2.4	01/04/04	Sitraka Inc.";
#endif

#include <X11/Xlib.h>
#include <X11/Intrinsic.h>

/**
 * The definition of an XrtPDSImage. This is opaque to the outside world
 * and can therefore be changed without breaking source code compatibility.
 */
typedef XtPointer XrtPDSImage;

/**
 * Type of function used to check that a file name has the
 * expected extension.
 */
typedef Boolean (*XrtPDSImageNameCompareProc) (
#ifndef _NO_PROTO
	String file_name
#endif
);

/**
 * Type of function used to check that a buffer contains the expect image
 * magic number(s).
 */
typedef Boolean (*XrtPDSImageHeaderCompareProc) (
#ifndef _NO_PROTO
	char *buffer
#endif
);

/**
 * Type of function used to create an XrtPDSImage from the provided image file.
 */
typedef XrtPDSImage (*XrtPDSImageCreateProc) (
#ifndef _NO_PROTO
	Widget w, String file_name
#endif
);

/**
 * Used to diferentiate image types in arrays of XrtPDSImageFuncs structures.
 */
typedef int XrtPDSImageType;

/**
 * Type of function used to convert an XImage to the required image type and
 * save it to a file.
 */
typedef Boolean (*XrtPDSImageOutputProc)(
#ifndef _NO_PROTO
	Widget w, XImage *image,
	String filename, Boolean color,
	String msg
#endif
);

/** Image converter list entry */
typedef struct {
	/** Verifies that the filename matches the expected format. */
	XrtPDSImageNameCompareProc		check_name;	
	/** Verifies that the file starts with the expect magic number(s). */
	XrtPDSImageHeaderCompareProc	check_header;
	/** Reads in the image file and converts it to an XrtPDSImage */
	XrtPDSImageCreateProc			create_image;
	/** The type of image this structure deals with */
	XrtPDSImageType					type;
	/** Converts and XImage to this image type and writes it to a file. */
	XrtPDSImageOutputProc			output;
} XrtPDSImageFuncs;


/*----------------------------------------------------------------------------
 * Public Function Prototypes
 */

extern XrtPDSImage XrtPDSImageCopy(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern void XrtPDSImageDestroy(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern String XrtPDSImageGetFilename(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern int XrtPDSImageGetWidth(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern int XrtPDSImageGetHeight(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern int XrtPDSImageGetColorDepth(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern Pixmap XrtPDSImageGetClipMask(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern Pixmap XrtPDSImageGetImage(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern Boolean XrtPDSImageIsSet(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern Boolean XrtPDSImageIsClipMaskSet(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern Boolean XrtPDSImageIsImage(
#ifndef _NO_PROTO
	XrtPDSImage image
#endif
);

extern XrtPDSImage XrtPDSImageCreate(
#ifndef _NO_PROTO
	Pixmap pixmap, Display *display, int width, int height
#endif
);

#endif /* ifndef XRTIMAGE_OBJECT_H */
