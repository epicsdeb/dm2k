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

/** \file XrtPDSListP.h
 * Private header for the XrtPDSList object..
 * \version 2.4
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * The are no user-accessable functions or data in this header.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */


#ifndef _listP_h_
#define _listP_h_

#include <X11/Intrinsic.h>
#include "XrtPDSList.h"

#ifdef _list_c
#ifdef NDEBUG
static char	sccsid_h[] = "@(#)XrtPDSListP.h	2.4	01/04/04	Sitraka Inc.";
#endif
#endif

#define LIST_COOKIE 0xffef
typedef void (*dummy_func_proto)();
typedef struct {
    int                         cookie;
    /* Public resources */
    XrtPDSListItemCompareProc	compare_proc;
	XrtPDSListItemDestroyProc  	destroy_proc;
	XrtPDSListChangedProc		changed_proc;
	XtPointer		  	user_data;
    int              	item_count;
    XtPointer        	items;
    size_t           	item_size;
    Boolean            	sorted;
    /* Private Variables */
    int					list_size; /**< This is the internal actual size
									 of the allocated list. */
    XtPointer			item_buffer;
} XrtPDSListStruct;

#endif /* _listP_h_*/


