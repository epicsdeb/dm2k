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

/** \file XrtPDSImageObjP.h
 * Private XrtPDSImage object header..
 * \version 2.8
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * There are no user accessable function or data in this header.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */


#ifndef XRTIMAGE_OBJECT_P_H
#define XRTIMAGE_OBJECT_P_H


#if defined(XRT_IMAGE_OBJECT) && defined(NDEBUG)
static char sccsid_h[] = "@(#)XrtPDSImageObjP.h	2.8	01/04/04	Sitraka Inc.";
#endif

#include "x_object.h"
#include "XrtPDSImageObj.h"

/** Motif Image object structure. */
typedef struct {
	XrtPDSGenericObjectClass	 class;
	Pixmap						 pixmap;
	Pixmap						 clip_mask;
	Boolean						 clipmask_set;
	int							 height;
	int							 width;
	int							 bit_depth;
	String						 source_file;
	Display						*display;
	Pixel					   **pixels;
	Pixel					   **mask_pixels;
} XrtPDSImageObject;

#if defined(__cplusplus)
extern "C" {
#endif

extern XrtPDSImage 	xrtpds_image_create(
#ifndef _NO_PROTO
   Pixmap pixmap, Display *display, int width, int height
#endif
);

extern XrtPDSImage 	xrtpds_image_copy(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern void			xrtpds_image_free(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern void			xrtpds_image_replaceImageNoFree(
#ifndef _NO_PROTO
   XrtPDSImage image_object, Pixmap new_image
#endif
);

extern Boolean 		xrtpds_image_isSet(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern int 			xrtpds_image_getBitDepth(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern Boolean 		xrtpds_image_setBitDepth(
#ifndef _NO_PROTO
   XrtPDSImage image_object, int depth
#endif
);

extern String 		xrtpds_image_getFilename(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern Boolean 		xrtpds_image_setFilename(
#ifndef _NO_PROTO
   XrtPDSImage image_object, String name
#endif
);

extern int 			xrtpds_image_getHeight(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern Boolean 		xrtpds_image_isClipMaskSet(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern Pixmap 		xrtpds_image_getClipMask(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern Boolean 		xrtpds_image_setClipMask(
#ifndef _NO_PROTO
   XrtPDSImage image_object, Pixmap clip
#endif
);

extern Pixmap 		xrtpds_image_getPixmap(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern int 			xrtpds_image_getWidth(
#ifndef _NO_PROTO
   XrtPDSImage image_object
#endif
);

extern	XrtPDSImage	xrtpds_image_createSquareImage(
#ifndef _NO_PROTO	
	XrtPDSImage input
#endif	
);

extern	Boolean     xrtpds_image_rotateImage(
#ifndef _NO_PROTO
	XrtPDSImage input, XrtPDSImage output, double angle
#endif
);

extern  Boolean     xrtpds_image_flipImageVert(
#ifndef _NO_PROTO
	XrtPDSImage input, XrtPDSImage output
#endif
);

extern  Boolean     xrtpds_image_flipImageHoriz(
#ifndef _NO_PROTO
	XrtPDSImage input, XrtPDSImage output
#endif
);

#if defined(__cplusplus)
}
#endif

#endif /* ifndef XRTIMAGE_OBJECT_P_H */
