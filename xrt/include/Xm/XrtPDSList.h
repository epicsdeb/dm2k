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

/** \file XrtPDSList.h
 * Contains the public interface to the XrtPDSList object.
 * \version 2.5
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */


#ifndef _xrtpds_list_h_
#define _xrtpds_list_h_

#include <X11/Intrinsic.h>

#ifdef _list_c
#ifdef NDEBUG
static char	sccsid_h[] = "@(#)XrtPDSList.h	2.5	01/04/04	Sitraka Inc.";
#endif
#endif


typedef enum {
	XRT_REASON_LIST_ADD = 0,
	XRT_REASON_LIST_DELETED,
	XRT_REASON_LIST_MOVE,
	XRT_REASON_LIST_PENDING_DELETE,
	XRT_REASON_LIST_SET
} XrtPDSListReason;

#define XRT_LIST_INVALID_POSITION -1
#define XRT_LIST_ITEM_NOT_FOUND   -2

#define XRT_REASON_LIST
#define BUFFER_LEAP    10

/**
 * The externally visible definition of an XrtPDSList. This is intended
 * as a opaque pointer so that we can modify the internals of the list
 * without breaking source or binary compatibility.
 */
typedef XtPointer XrtPDSList;
typedef int (*compar)();

/**
 * Callback structure that is passed the the XrtPDSListChangedProc().
 */
typedef struct {
	XrtPDSListReason	reason; /**< ADD, DELETE, MOVE, PENDING_DELETE to SET */
	XtPointer 	  		user_data; /**< Any user data that was registered */
	XtPointer	  		modified_item; /**< Pointer to the modified item */
	int 		  		position; /**< position of change */
} XrtPDSListChangedCallbackStruct;

typedef void (*XrtPDSListChangedProc) (
#ifndef _NO_PROTO
	XrtPDSList list,
	XrtPDSListChangedCallbackStruct *call_data
#endif
);

typedef int (*XrtPDSListItemCompareProc) (
#ifndef _NO_PROTO
	XtPointer item1, XtPointer item2
#endif
);

typedef void (*XrtPDSListItemDestroyProc) (
#ifndef _NO_PROTO
	XrtPDSList object, XtPointer item, XtPointer user_data
#endif
);

#if defined(__cplusplus)
extern "C" {
#endif

extern int XrtPDSListAdd(
#ifndef _NO_PROTO
    XrtPDSList list_object, XtPointer item
#endif
);

extern int XrtPDSListAppend(
#ifndef _NO_PROTO
    XrtPDSList list_object, XtPointer item
#endif
);

extern XrtPDSList XrtPDSListCreate(
#ifndef _NO_PROTO
    size_t size
#endif
);

extern int XrtPDSListDelete(
#ifndef _NO_PROTO
    XrtPDSList list_object, int position
#endif
);

extern void XrtPDSListDeleteItems(
#ifndef _NO_PROTO								
	XrtPDSList list_object, int start, int num
#endif
);

extern void XrtPDSListDeleteAll(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern void XrtPDSListDestroy(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern void XrtPDSListDestroyXtPointer(
#ifndef _NO_PROTO
	XrtPDSList list_object, XtPointer *item
#endif
);

extern XrtPDSList XrtPDSListDuplicate(
#ifndef _NO_PROTO
XrtPDSList list_object
#endif
);

extern int XrtPDSListFind(
#ifndef _NO_PROTO
    XrtPDSList list_object, XtPointer item
#endif
);

extern XrtPDSListChangedProc XrtPDSListGetChangedProc(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern XrtPDSListItemCompareProc XrtPDSListGetCompareProc(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);


extern XtPointer XrtPDSListGetItem(
#ifndef _NO_PROTO
    XrtPDSList list_object, int position
#endif
);

extern XtPointer XrtPDSListGetItems(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern int XrtPDSListGetItemCount(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern int XrtPDSListGetItemSize(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern XtPointer XrtPDSListGetUserData(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern int XrtPDSListInsertAfter(
#ifndef _NO_PROTO
    XrtPDSList list_object, int position, XtPointer item
#endif
);

extern int XrtPDSListInsertBefore(
#ifndef _NO_PROTO
    XrtPDSList list_object, int position, XtPointer item
#endif
);

extern Boolean XrtPDSListIsList(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern int XrtPDSListIsSorted(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern int XrtPDSListLookupItem(
#ifndef _NO_PROTO
    XrtPDSList list_object, XtPointer item
#endif
);

extern Boolean XrtPDSListMoveItemsAfter(
#ifndef _NO_PROTO
    XrtPDSList list_object,
	int target_position, int source_position, int number_of_items_to_move
#endif
);

extern Boolean XrtPDSListMoveItemsBefore(
#ifndef _NO_PROTO
    XrtPDSList list_object,
	int target_position, int source_position, int number_of_items_to_move
#endif
);

extern void XrtPDSListSetChangedProc(
#ifndef _NO_PROTO
    XrtPDSList list_object,
	XrtPDSListChangedProc changed_proc
#endif
);

extern void XrtPDSListSetCompareProc(
#ifndef _NO_PROTO
    XrtPDSList list_object, XrtPDSListItemCompareProc compare_proc
#endif
);

extern int XrtPDSCmpStrings(
#ifndef _NO_PROTO
	XtPointer string1, XtPointer string2
#endif
);

extern int XrtPDSCmpStringsIgnoreCase(
#ifndef _NO_PROTO
	XtPointer string1, XtPointer string2
#endif
);

extern int XrtPDSCmpInts(
#ifndef _NO_PROTO
	XtPointer int1, XtPointer int2
#endif
);

extern int XrtPDSCmpFloats(
#ifndef _NO_PROTO
	XtPointer float1, XtPointer float2
#endif
);

extern int XrtPDSCmpDoubles(
#ifndef _NO_PROTO
	XtPointer double1, XtPointer double2
#endif
);

extern void XrtPDSListSetDestroyProc(
#ifndef _NO_PROTO
    XrtPDSList list_object, XrtPDSListItemDestroyProc destroy_proc
#endif
);

extern XrtPDSListItemDestroyProc
XrtPDSListGetDestroyProc(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif	
);

extern Boolean XrtPDSListSetItem(
#ifndef _NO_PROTO
	XrtPDSList list_object, int position, XtPointer item
#endif
);

extern void XrtPDSListSetUserData(
#ifndef _NO_PROTO
    XrtPDSList list_object,
	XtPointer
#endif
);

extern int XrtPDSListSearchForward(
#ifndef _NO_PROTO
     XrtPDSList list_object, int start_position, XtPointer item
#endif
);

extern int XrtPDSListRemove(
#ifndef _NO_PROTO
    XrtPDSList list_object, int position
#endif
);

extern void XrtPDSListRemoveAll(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

extern int XrtPDSListSearchReverse(
#ifndef _NO_PROTO
    XrtPDSList list_object, int start_position, XtPointer item
#endif
);

extern Boolean XrtPDSListSetItem(
#ifndef _NO_PROTO
    XrtPDSList list_object, int position, XtPointer item
#endif
);

extern void XrtPDSListSort(
#ifndef _NO_PROTO
    XrtPDSList list_object
#endif
);

#if defined(__cplusplus)
}
#endif

#endif /* _list_h_*/


