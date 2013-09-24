/******************************************************************************
*
* Copyright (c) 2001, SITRAKA INC.  All Rights Reserved.
* http://www.sitraka.com
*
* This file is provided for demonstration and educational uses only.
* Permission to use, copy, modify and distribute this file for
* any purpose and without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all
* copies, and that the name of Sitraka Software not be used in 
* advertising or publicity pertaining to this material without the 
* specific, prior written permission of an authorized representative of
* Sitraka Software.
*
* SITRAKA SOFTWARE MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE 
* SUITABILITY OF THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT 
* NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE, OR NON-INFRINGEMENT. SITRAKA SOFTWARE SHALL NOT BE 
* LIABLE FOR ANY DAMAGES SUFFERED BY USERS AS A RESULT OF USING, MODIFYING 
* OR DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
*
******************************************************************************/

/*
 * XrtGraph.hxx - XRT/graph widget C++ header file
 */
#ifndef _XrtGraph_hxx
#define _XrtGraph_hxx

#include <Xm/XrtGraph.h>

#ifdef XRTGRAPH_CXX
static char	sccsid_h[] = "@(#)XrtGraph.hxx	4.4 01/04/04 Sitraka Inc.";
#endif


// Token pasting macro:
// NOTE: If you are using older CC compiler from Sun, then use
// -DTOKEN_PASTING_BROKEN in the Makefile

#ifdef TOKEN_PASTING_BROKEN
#	define NAME2(a,b) a/**/b
#else
#	define NAME2(a,b) a##b
#endif

// Set resource
#define XRT_S_RES(NAME,TYPE) 	\
  void NAME2(set,NAME) (TYPE val) { \
    XtSetArg(args[0], NAME2(XtNxrt,NAME), val); \
	XtSetValues(widget, args, 1); \
  }

// Set resource
#define XRT_S_FLOAT_RES(NAME) 	\
  void NAME2(set,NAME) (float val) { \
    XtSetArg(args[0], NAME2(XtNxrt,NAME), XrtFloatToArgVal(val)); \
	XtSetValues(widget, args, 1); \
  }

// Get resource
#define XRT_G_RES(NAME,TYPE) 	\
  TYPE NAME2(get,NAME) (TYPE* val=0) { 	\
	TYPE gval; 	\
    TYPE *tmpval = &gval; \
    if (val) \
		tmpval=val; \
    XtSetArg(args[0], NAME2(XtNxrt,NAME), tmpval); \
  	XtGetValues(widget, args, 1); \
    return (*tmpval); \
  }									

#define XRT_SG_RES(NAME, TYPE) \
	XRT_S_RES(NAME, TYPE) \
	XRT_G_RES(NAME, TYPE)

#define XRT_SG_FLOAT_RES(NAME) \
	XRT_S_FLOAT_RES(NAME) \
	XRT_G_RES(NAME, float)



/****************************************************************
 * Class XrtGraphData
 ****************************************************************/

class XrtGraphData {
public:
	/* Constructors */
	XrtGraphData(XrtDataType type = XRT_ARRAY, int nsets=0, int npoints=0) {
		data = XrtDataCreate(type, nsets, npoints); }
	XrtGraphData(char *fname, char* error = NULL) {
		data = XrtDataCreateFromFile(fname, error); }
	XrtGraphData(XrtData *xrtData) {
		data = XrtDataConvertToHandle(xrtData); }
	XrtGraphData(const XrtGraphData& from) {
		data = XrtDataCopy(from.data); }
	XrtGraphData(XrtDataHandle handle) {
		data = handle; }

	/* Destructor */
	~XrtGraphData() { XrtDataDestroy(data); }

    // Operations
    XrtGraphData& operator =(const XrtGraphData& from) {
		XrtDataHandle handle;
		if(this != &from) {
			handle = XrtDataCopy(from.data);
			if(handle) {
				XrtDataDestroy(data);
				data = handle;
			}
		}
		return *this;
	}

    XrtGraphData operator +(const XrtGraphData data2) {
		return XrtDataConcat(data, data2.data); }
		
	// XrtData methods
	XrtGraphData extractSet(int set) {
		return XrtDataExtractSet(data, set); }
	XrtDisplay getDisplay(int set) {
		return XrtDataGetDisplay(data, set); }
	int getFirstPoint(int set) {
		return XrtDataGetFirstPoint(data, set); }
	int getFirstSet() {
		return XrtDataGetFirstSet(data); }
	double getHole() {
		return XrtDataGetHole(data); }
	int getLastPoint(int set) {
		return XrtDataGetLastPoint(data, set); }
	int getLastSet() {
		return XrtDataGetLastSet(data); }
	int getNPoints(int set) {
		return XrtDataGetNPoints(data, set); }
	int getNSets() {
		return XrtDataGetNSets(data); }
	XrtDataType getType() {
		return XrtDataGetType(data); }
	double  getXElement(int set, int point) {
		return XrtDataGetXElement(data, set, point); }
    double getYElement(int set, int point) {
		return XrtDataGetYElement(data, set, point); }
	int release() {
		return XrtDataRelease(data); }
	int removeSet(int set) {
		return XrtDataRemoveSet(data, set); }
	int saveToFile(char *filename, char *errbuf = NULL) {
		return XrtDataSaveToFile(data, filename, errbuf); }
	int setDisplay(int set, XrtDisplay display) {
		return XrtDataSetDisplay(data, set, display); }
	int setFirstPoint(int set, int point) {
		return XrtDataSetFirstPoint(data, set, point); }
	int setFirstSet(int set) {
		return XrtDataSetFirstSet(data, set); }
	int setHole(double hole) {
		return XrtDataSetHole(data, hole); }
	int setLastPoint(int set, int point) {
		return XrtDataSetLastPoint(data,  set,  point); }
	int setLastSet(int set) {
		return XrtDataSetLastSet(data,  set); }
	int setNPoints(int set, int npoints) {
		return XrtDataSetNPoints(data, set, npoints); }
	int setNSets(int nsets) {
		return XrtDataSetNSets(data, nsets); }
	int setType(XrtDataType type) {
		return XrtDataSetType(data, type); }
	int setXData(int set, float *xvalues, int n, int index) {
		return XrtDataSetXData(data, set, xvalues, n, index); }
	int setXElement(int set, int point, double x) {
		return XrtDataSetXElement(data,  set,  point, x); }
	int setYData(int set, float *yvalues, int n, int index) {
		return XrtDataSetYData(data,  set, yvalues,  n,  index); }
	int setYElement(int set, int point, double y) {
		return XrtDataSetYElement(data,  set,  point, y); }
	int sort() {
		return XrtDataSort(data); }
	XrtGraphData transpose() {
		return XrtDataTranspose(data); }
	int updateDataValue(double oldValue, double newValue) {
		return XrtDataUpdateDataValue(data, oldValue, newValue); }

	// Convenience methods
	XrtDataHandle getDataHandle() {
		return data;
	}
	
	Boolean isArrData() {
	  return (( getType() == XRT_DATA_ARRAY) ? True : False );
	}

	Boolean isGenData() {
	  return (( getType() == XRT_DATA_GENERAL) ? True : False );
	}

	//  XrtData object methods for data type Array
	int appendPts( double xval, float    *yvector) {
	  return ( isArrData() ? XrtArrDataAppendPts( data, xval, yvector) : 0 );
	}
	int removePts( int point) {
		return ( isArrData() ? XrtArrDataRemovePts(data, point) : 0 );
	}
	int shiftPts(int dest, int src, int npoints) {
		return ( isArrData() ? XrtArrDataShiftPts(data, dest, src, npoints) : 0 );
	}

	//  XrtData object methods for data type General
	int appendPts(int set, double xval, double yval) {
		return ( isGenData() ? XrtGenDataAppendPt(data, set, xval, yval) : 0 );
	}
	int removePts( int set, int point) {
		return ( isGenData() ? XrtGenDataRemovePt(data, set, point) : 0 );
	}
	int shiftPts(int set, int dest, int src, int npoints) {
		return ( isGenData() ? XrtGenDataShiftPts(data, set, dest, src, npoints) : 0 );
	}
	float    * getXData(int set) {
		return ( XrtDataGetXData(data, set) );
	}
	float    * getYData(int set) {
		return ( XrtDataGetYData(data, set) );
	}

 private:
	XrtDataHandle	data;

};


/****************************************************************
 *  Class XrtGraph
 ****************************************************************/

class XrtGraph {
public:

	// Constructor
	XrtGraph(Widget parent, char *name, Arg *arglist, int nargs)
	{
		widget = XtCreateXrtGraph(parent, name, arglist, nargs);
	}

	// Destructor
	~XrtGraph() { XtDestroyWidget(widget); }

	Widget getWidget() { return (widget); }

	// set and get resources (non-float)
	XRT_SG_RES(AngleUnit,XrtAngleUnit)
	XRT_SG_RES(AxisBoundingBox, Boolean)
	XRT_SG_RES(AxisFont, XmFontList)
	XRT_SG_RES(BackgroundColor, char *)
	XRT_SG_RES(BarClusterOverlap, int)
	XRT_SG_RES(BarClusterWidth, int)
	XRT_SG_RES(Border,XrtBorder)
	XRT_SG_RES(BubbleMethod,XrtBubbleMethod)
	XRT_SG_RES(CandleComplex,Boolean)
	XRT_SG_RES(Data, XrtDataHandle)
	XRT_SG_RES(Data2, XrtDataHandle)
	XRT_SG_RES(DataAreaBackgroundColor, char *)
	XRT_SG_RES(DataAreaForegroundColor,char *)
	XRT_SG_RES(DataAreaImage,XrtImage)
	XRT_SG_RES(DataAreaImageLayout,XrtImageLayout)
	XRT_SG_RES(DataStyles, XrtDataStyle **)
	XRT_SG_RES(DataStyles2, XrtDataStyle **)
	XRT_SG_RES(DataStyles2UseDefault, Boolean)
	XRT_SG_RES(DataStylesUseDefault, Boolean)
	XRT_SG_RES(Debug, Boolean)
	XRT_SG_RES(DoubleBuffer, Boolean)
	XRT_SG_RES(ExposeCallback, XtCallbackList)
	XRT_SG_RES(ExtraDefaultDataStyles,Boolean)
	XRT_SG_RES(FooterAdjust, XrtAdjust)
	XRT_SG_RES(FooterBackgroundColor, char *)
	XRT_SG_RES(FooterBorder, XrtBorder)
	XRT_SG_RES(FooterBorderWidth, Dimension)
	XRT_SG_RES(FooterFont, XmFontList)
	XRT_SG_RES(FooterForegroundColor, char *)
	XRT_SG_RES(FooterImage,XrtImage)
	XRT_SG_RES(FooterImageLayout,XrtImageLayout)
	XRT_SG_RES(FooterImageMinimumSize,Boolean)
	XRT_SG_RES(FooterStrings, char **)
	XRT_SG_RES(FooterX, short)
	XRT_SG_RES(FooterXUseDefault, Boolean)
	XRT_SG_RES(FooterY, short)
	XRT_SG_RES(FooterYUseDefault, Boolean)
	XRT_SG_RES(ForegroundColor, char *)
	XRT_SG_RES(FrontDataset, int)
	XRT_SG_RES(Graph3dShading,XrtShading)
	XRT_SG_RES(GraphBackgroundColor, char *)
	XRT_SG_RES(GraphBorder, XrtBorder)
	XRT_SG_RES(GraphBorderWidth, Dimension)
	XRT_SG_RES(GraphDepth, int)
	XRT_SG_RES(GraphForegroundColor, char *)
	XRT_SG_RES(GraphHeight, short)
	XRT_SG_RES(GraphHeightUseDefault, Boolean)
	XRT_SG_RES(GraphImage,XrtImage)
	XRT_SG_RES(GraphImageLayout,XrtImageLayout)
	XRT_SG_RES(GraphInclination, int)
	XRT_SG_RES(GraphMarginBottom, short)
	XRT_SG_RES(GraphMarginBottomUseDefault, Boolean)
	XRT_SG_RES(GraphMarginLeft, short)
	XRT_SG_RES(GraphMarginLeftUseDefault, Boolean)
	XRT_SG_RES(GraphMarginRight, short)
	XRT_SG_RES(GraphMarginRightUseDefault, Boolean)
	XRT_SG_RES(GraphMarginTop, short)
	XRT_SG_RES(GraphMarginTopUseDefault, Boolean)
	XRT_SG_RES(GraphRotation, int)
	XRT_SG_RES(GraphShowOutlines,Boolean)
	XRT_SG_RES(GraphWidth, short)
	XRT_SG_RES(GraphWidthUseDefault, Boolean)
	XRT_SG_RES(GraphX, short)
	XRT_SG_RES(GraphXUseDefault, Boolean)
	XRT_SG_RES(GraphY, short)
	XRT_SG_RES(GraphYUseDefault, Boolean)
	XRT_SG_RES(HeaderAdjust, XrtAdjust)
	XRT_SG_RES(HeaderBackgroundColor, char *)
	XRT_SG_RES(HeaderBorder, XrtBorder)
	XRT_SG_RES(HeaderBorderWidth, Dimension)
	XRT_SG_RES(HeaderFont, XmFontList)
	XRT_SG_RES(HeaderForegroundColor, char *)
	XRT_SG_RES(HeaderImage,XrtImage)
	XRT_SG_RES(HeaderImageLayout,XrtImageLayout)
	XRT_SG_RES(HeaderImageMinimumSize,Boolean)
	XRT_SG_RES(HeaderStrings, char **)
	XRT_SG_RES(HeaderX, short)
	XRT_SG_RES(HeaderXUseDefault, Boolean)
	XRT_SG_RES(HeaderY, short)
	XRT_SG_RES(HeaderYUseDefault, Boolean)
	XRT_SG_RES(HiLoCloseShow,Boolean)
	XRT_SG_RES(HiLoOpenCloseFullWidth,Boolean)
	XRT_SG_RES(HiLoOpenShow,Boolean)
	XRT_SG_RES(Image,XrtImage)
	XRT_SG_RES(ImageLayout,XrtImageLayout)
	XRT_SG_RES(InvertOrientation, Boolean)
	XRT_SG_RES(IsStacked,Boolean)
	XRT_SG_RES(IsStacked2,Boolean)
	XRT_SG_RES(LegendAnchor, XrtAnchor)
	XRT_SG_RES(LegendBackgroundColor, char *)
	XRT_SG_RES(LegendBorder, XrtBorder)
	XRT_SG_RES(LegendBorderWidth, Dimension)
	XRT_SG_RES(LegendFont, XmFontList)
	XRT_SG_RES(LegendForegroundColor, char *)
	XRT_SG_RES(LegendImage,XrtImage)
	XRT_SG_RES(LegendImageLayout,XrtImageLayout)
	XRT_SG_RES(LegendOrientation, XrtAlign)
	XRT_SG_RES(LegendReversed,Boolean)
	XRT_SG_RES(LegendShow, Boolean)
	XRT_SG_RES(LegendTitle,char)
	XRT_SG_RES(LegendX, short)
	XRT_SG_RES(LegendXUseDefault, Boolean)
	XRT_SG_RES(LegendY, short)
	XRT_SG_RES(LegendYUseDefault, Boolean)
	XRT_SG_RES(MarkerDataStyle, XrtDataStyle *)
	XRT_SG_RES(MarkerDataStyleUseDefault, Boolean)
	XRT_SG_RES(MarkerDataset, int)
	XRT_SG_RES(ModifyCallback, XtCallbackList)
	XRT_SG_RES(OtherDataStyle, XrtDataStyle *)
	XRT_SG_RES(OtherDataStyleUseDefault, Boolean)
	XRT_SG_RES(OtherLabel, char *)
	XRT_SG_RES(PieMergeMissingSlices,Boolean)
	XRT_SG_RES(PieMinSlices, int)
	XRT_SG_RES(PieOrder, XrtPieOrder)
	XRT_SG_RES(PieThresholdMethod, XrtPieThresholdMethod)
	XRT_SG_RES(PointLabels, char **)
	XRT_SG_RES(PointLabels2, char **)
	XRT_SG_RES(PolarAxisAllowNegatives,Boolean)
	XRT_SG_RES(PolarHalfRange,Boolean)
	XRT_SG_RES(Repaint, Boolean)
	XRT_SG_RES(ResizeCallback, XtCallbackList)
	XRT_SG_RES(RotateCallback, XtCallbackList)
	XRT_SG_RES(SetLabels, char **)
	XRT_SG_RES(SetLabels2, char **)
	XRT_SG_RES(TimeBase, long)
	XRT_SG_RES(TimeFormat, char *)
	XRT_SG_RES(TimeFormatUseDefault, Boolean)
	XRT_SG_RES(TimeUnit, XrtTimeUnit)
	XRT_SG_RES(TransformCallback, XtCallbackList)
	XRT_SG_RES(Type, XrtType)
	XRT_SG_RES(Type2, XrtType)
	XRT_SG_RES(XAnnoPlacement, XrtAnnoPlacement)
	XRT_SG_RES(XAnnotationMethod, XrtAnnoMethod)
	XRT_SG_RES(XAnnotationRotation, XrtRotate)
	XRT_SG_RES(XAxisDataStyle,XrtDataStyle *)
	XRT_SG_RES(XAxisDataStyleUseDefault,Boolean)
	XRT_SG_RES(XAxisLabelFormat,char *)
	XRT_SG_RES(XAxisLogarithmic, Boolean)
	XRT_SG_RES(XAxisMaxUseDefault, Boolean)
	XRT_SG_RES(XAxisMinUseDefault, Boolean)
	XRT_SG_RES(XAxisReversed, Boolean)
	XRT_SG_RES(XAxisShow, Boolean)
	XRT_SG_RES(XGridDataStyle, XrtDataStyle *)
	XRT_SG_RES(XGridDataStyleUseDefault, Boolean)
	XRT_SG_RES(XGridUseDefault, Boolean)
	XRT_SG_RES(XLabels, XrtValueLabel **)
	XRT_SG_RES(XMarkerDataStyle,XrtDataStyle *)
	XRT_SG_RES(XMarkerDataStyleUseDefault,Boolean)
	XRT_SG_RES(XMarkerMethod,XrtMarkerMethod)
	XRT_SG_RES(XMarkerPoint, int)
	XRT_SG_RES(XMarkerSet, int)
	XRT_SG_RES(XMarkerShow, Boolean)
	XRT_SG_RES(XMaxUseDefault, Boolean)
	XRT_SG_RES(XMinUseDefault, Boolean)
	XRT_SG_RES(XNumMethod, XrtNumMethod)
	XRT_SG_RES(XNumUseDefault, Boolean)
	XRT_SG_RES(XOriginPlacement, XrtOriginPlacement)
	XRT_SG_RES(XOriginUseDefault, Boolean)
	XRT_SG_RES(XPrecision, int)
	XRT_SG_RES(XPrecisionUseDefault, Boolean)
	XRT_SG_RES(XTickUseDefault, Boolean)
	XRT_SG_RES(XTitle, char *)
	XRT_SG_RES(XTitleRotation, XrtRotate)
	XRT_SG_RES(Y2AnnoPlacement,XrtAnnoPlacement)
	XRT_SG_RES(Y2AnnotationAngleUseDefault,Boolean)
	XRT_SG_RES(Y2AnnotationMethod, XrtAnnoMethod)
	XRT_SG_RES(Y2AnnotationRotation, XrtRotate)
	XRT_SG_RES(Y2Axis100Percent,Boolean)
	XRT_SG_RES(Y2AxisDataStyle,XrtDataStyle *)
	XRT_SG_RES(Y2AxisDataStyleUseDefault,Boolean)
	XRT_SG_RES(Y2AxisLabelFormat,char *)
	XRT_SG_RES(Y2AxisLogarithmic, Boolean)
	XRT_SG_RES(Y2AxisMaxUseDefault, Boolean)
	XRT_SG_RES(Y2AxisMinUseDefault, Boolean)
	XRT_SG_RES(Y2AxisReversed, Boolean)
	XRT_SG_RES(Y2AxisShow, Boolean)
	XRT_SG_RES(Y2GridDataStyle,XrtDataStyle *)
	XRT_SG_RES(Y2GridDataStyleUseDefault,Boolean)
	XRT_SG_RES(Y2GridUseDefault,Boolean)
	XRT_SG_RES(Y2Labels, XrtValueLabel **)
	XRT_SG_RES(Y2MaxUseDefault, Boolean)
	XRT_SG_RES(Y2MinUseDefault, Boolean)
	XRT_SG_RES(Y2NumMethod, XrtNumMethod)
	XRT_SG_RES(Y2NumUseDefault, Boolean)
	XRT_SG_RES(Y2OriginPlacement,XrtOriginPlacement)
	XRT_SG_RES(Y2OriginUseDefault,Boolean)
	XRT_SG_RES(Y2Precision, int)
	XRT_SG_RES(Y2PrecisionUseDefault, Boolean)
	XRT_SG_RES(Y2TickUseDefault, Boolean)
	XRT_SG_RES(Y2Title, char *)
	XRT_SG_RES(Y2TitleRotation, XrtRotate)
	XRT_SG_RES(YAnnoPlacement, XrtAnnoPlacement)
	XRT_SG_RES(YAnnotationAngleUseDefault,Boolean)
	XRT_SG_RES(YAnnotationMethod, XrtAnnoMethod)
	XRT_SG_RES(YAnnotationRotation, XrtRotate)
	XRT_SG_RES(YAxis100Percent,Boolean)
	XRT_SG_RES(YAxisDataStyle,XrtDataStyle *)
	XRT_SG_RES(YAxisDataStyleUseDefault,Boolean)
	XRT_SG_RES(YAxisLabelFormat,char *)
	XRT_SG_RES(YAxisLogarithmic, Boolean)
	XRT_SG_RES(YAxisMaxUseDefault, Boolean)
	XRT_SG_RES(YAxisMinUseDefault, Boolean)
	XRT_SG_RES(YAxisReversed, Boolean)
	XRT_SG_RES(YAxisShow, Boolean)
	XRT_SG_RES(YGridDataStyle, XrtDataStyle *)
	XRT_SG_RES(YGridDataStyleUseDefault, Boolean)
	XRT_SG_RES(YGridUseDefault, Boolean)
	XRT_SG_RES(YLabels, XrtValueLabel **)
	XRT_SG_RES(YMarkerDataStyle,XrtDataStyle *)
	XRT_SG_RES(YMarkerDataStyleUseDefault,Boolean)
	XRT_SG_RES(YMarkerShow, Boolean)
	XRT_SG_RES(YMaxUseDefault, Boolean)
	XRT_SG_RES(YMinUseDefault, Boolean)
	XRT_SG_RES(YNumMethod, XrtNumMethod)
	XRT_SG_RES(YNumUseDefault, Boolean)
	XRT_SG_RES(YOriginPlacement, XrtOriginPlacement)
	XRT_SG_RES(YOriginUseDefault, Boolean)
	XRT_SG_RES(YPrecision, int)
	XRT_SG_RES(YPrecisionUseDefault, Boolean)
	XRT_SG_RES(YTickUseDefault, Boolean)
	XRT_SG_RES(YTitle, char *)
	XRT_SG_RES(YTitleRotation, XrtRotate)
	XRT_SG_RES(ZoomAxisCallback, XtCallbackList)

	// set and get resources of type float
	XRT_SG_FLOAT_RES(BubbleMax)
	XRT_SG_FLOAT_RES(BubbleMin)
	XRT_SG_FLOAT_RES(PieThresholdValue)
	XRT_SG_FLOAT_RES(PieStartAngle)
	XRT_SG_FLOAT_RES(XAxisMax)
	XRT_SG_FLOAT_RES(XAxisMin)
	XRT_SG_FLOAT_RES(XGrid)
	XRT_SG_FLOAT_RES(XMarker)
	XRT_SG_FLOAT_RES(XMax)
	XRT_SG_FLOAT_RES(XMin)
	XRT_SG_FLOAT_RES(XNum)
	XRT_SG_FLOAT_RES(XOrigin)
	XRT_SG_FLOAT_RES(XOriginBase)
	XRT_SG_FLOAT_RES(XTick)
	XRT_SG_FLOAT_RES(Y2AnnotationAngle)
	XRT_SG_FLOAT_RES(Y2AxisMax)
	XRT_SG_FLOAT_RES(Y2AxisMin)
	XRT_SG_FLOAT_RES(Y2Grid)
	XRT_SG_FLOAT_RES(Y2Max)
	XRT_SG_FLOAT_RES(Y2Min)
	XRT_SG_FLOAT_RES(Y2Num)
	XRT_SG_FLOAT_RES(Y2Origin)
	XRT_SG_FLOAT_RES(Y2Tick)
	XRT_SG_FLOAT_RES(YAnnotationAngle)
	XRT_SG_FLOAT_RES(YAxisConst)
	XRT_SG_FLOAT_RES(YAxisMax)
	XRT_SG_FLOAT_RES(YAxisMin)
	XRT_SG_FLOAT_RES(YAxisMult)
	XRT_SG_FLOAT_RES(YGrid)
	XRT_SG_FLOAT_RES(YMarker)
	XRT_SG_FLOAT_RES(YMax)
	XRT_SG_FLOAT_RES(YMin)
	XRT_SG_FLOAT_RES(YNum)
	XRT_SG_FLOAT_RES(YOrigin)
	XRT_SG_FLOAT_RES(YTick)

	// gettable resources
	XRT_G_RES(FooterWidth, short)
	XRT_G_RES(FooterHeight, short)
	XRT_G_RES(HeaderWidth, short)
	XRT_G_RES(HeaderHeight, short)
	XRT_G_RES(LegendWidth, short)
	XRT_G_RES(LegendHeight, short)

	// widget methods
	void addCallback(String name, XtCallbackProc callback, XtPointer client_data)
	{
		XtAddCallback(widget, name, callback, client_data);
	}

	void destroy(void)			{ XtDestroyWidget(widget); }
	Display * getDisplay(void) 	{ return XtDisplay(widget); }
	String getName(void)		{ return XtName(widget); }
	Widget getParent(void)		{ return XtParent(widget); }
	Boolean isManaged(void)		{ return XtIsManaged(widget); }
	Boolean isRealized(void)	{ return XtIsRealized(widget); }
	void manageChild(void)		{ XtManageChild(widget); }

// Procedures

  int arrCheckAxisBounds(int dataset, int numpoints) {
	return XrtArrCheckAxisBounds( widget, dataset, numpoints);
  }
  int arrDataFastUpdate(int dataset, int numpoints) {
	return XrtArrDataFastUpdate( widget, dataset, numpoints);
  }
  int genCheckAxisBounds(int dataset, int set, int numpoints) {
	return XrtGenCheckAxisBounds( widget, dataset, set, numpoints);
  }
  int genDataFastUpdate(int dataset, int set, int numpoints) {
	return XrtGenDataFastUpdate( widget, dataset, set, numpoints);
  }
  Boolean deletePointLabel(int index) {
	return XrtDeletePointLabel(widget, index);
  }
  Boolean deletePointLabel2(int index) {
	return XrtDeletePointLabel2(widget, index);
  }
  Boolean deleteSetLabel(int index) {
	return XrtDeleteSetLabel(widget, index);
  }
  Boolean deleteSetLabel2(int index) {
	return XrtDeleteSetLabel2(widget, index);
  }
  int drawPS(FILE *fp, char *msg, int inches, double
			  paper_width, double paper_height, double margin, int landscape,
			  double x_offset, double y_offset, double width, double height,
			  char *header_font, int header_size, char *footer_font,
			  int footer_size, char *anno_font, int anno_size,char *legend_font,
			  int legend_size,int fill_background,int smart_mono,int showpage) {
	return XrtDrawPS( widget, fp, msg, inches, paper_width, paper_height, margin,
					  landscape, x_offset, y_offset, width, height, header_font,
					  header_size,footer_font,footer_size,anno_font,anno_size,
					  legend_font, legend_size, fill_background, smart_mono,
					  showpage );
  }
  XrtDataStyle ** dupDataStyles(XrtDataStyle **ds) {
	return XrtDupDataStyles(ds);
  }
  char ** dupStrings(char **s) {
	return XrtDupStrings(s);
  }
  XrtValueLabel ** dupValueLabels(XrtValueLabel **label) {
	return XrtDupValueLabels(label);
  }
  void freeDataStyles(XrtDataStyle **ds) {
	XrtFreeDataStyles(ds);
  }
  void freePropString(char * s) {
	XrtFreePropString(s);
  }
  void freeStrings(char ** s) {
	XrtFreeStrings(s);
  }
  void freeTextHandles(XrtTextHandle * list) {
	XrtFreeTextHandles(list);
  }
  void freeValueLabels(XrtValueLabel ** label) {
	XrtFreeValueLabels(label);
  }
  XImage * getImage(Widget graph) {
	return XrtGetImage(graph);
  }
  XrtDataStyle * getNthDataStyle(int index) {
	return XrtGetNthDataStyle(widget, index);
  }
  XrtDataStyle * getNthDataStyle2(int index) {
	return XrtGetNthDataStyle2(widget, index);
  }
  char * getNthFooterString(int index) {
	return XrtGetNthFooterString(widget, index);
  }
  char * getNthHeaderString(int index) {
	return XrtGetNthHeaderString(widget, index);
  }
  String getNthPointLabel(int index) {
	return XrtGetNthPointLabel(widget, index);
  }
  String getNthPointLabel2(int index) {
	return XrtGetNthPointLabel2(widget, index);
  }
  String getNthSetLabel(int index) {
	return XrtGetNthSetLabel(widget, index);
  }
  String getNthSetLabel2(int index) {
	return XrtGetNthSetLabel2(widget, index);
  }
  int * getOtherSliceSets(int point, int dataset) {
	return XrtGetOtherSliceSets( widget, point, dataset);
  }
  Boolean getPropString(XrtProperty res, char **str) {
	  return XrtGetPropString(widget, res, str);
  }
  int getTextHandles(XrtTextHandle **list) {
	return XrtGetTextHandles(widget, list);
  }
  XrtValueLabel * getValueLabel(XrtAxis axis,
								 XrtValueLabel *label ) {
	return XrtGetValueLabel( widget, axis, label );
  }
  XrtXLabel * getXLabel(XrtXLabel *label) {
	return XrtGetXLabel(widget, label);
  }
  int insertNthDataStyle(int index,XrtDataStyle *ds,int dataset) {
	return XrtInsertNthDataStyle(widget, index, ds, dataset);
  }
  Boolean insertPointLabel(int index, String s) {
	return XrtInsertPointLabel(widget, index, s);
  }
  Boolean insertPointLabel2(int index, String s) {
	return XrtInsertPointLabel2(widget, index, s);
  }
  Boolean insertSetLabel(int index, String s) {
	return XrtInsertSetLabel(widget, index, s);
  }
  Boolean insertSetLabel2(int index, String s) {
	return XrtInsertSetLabel2(widget, index, s);
  }
  long makeTime(int yr, int mon, int day, int hr, int min, int sec){
	return XrtMakeTime(yr, mon, day, hr, min, sec);
  }
  XrtRegion map(int yaxis,int pix_x,int pix_y,XrtMapResult *map ) {
	return XrtMap( widget, yaxis, pix_x, pix_y, map );
  }
  int outputPS(FILE *fp, Boolean color, char *msg ) {
	return XrtOutputPS( widget, fp, color, msg );
  }
#ifndef __VMS
  int outputRaster(FILE *fp, char *msg ) {
	return XrtOutputRaster( widget, fp, msg );
  }
#endif
  int outputXwd(FILE *fp, char *msg ) {
	return XrtOutputXwd( widget, fp, msg );
  }
  XrtRegion pick(XrtDsGroup ds_group, int pix_x, int pix_y,
				  XrtPickResult *pick, XrtFocus focus ) {
	return XrtPick( widget, ds_group, pix_x, pix_y, pick, focus );
  }
  Boolean propertyEditorEnable(Boolean enable,char *title_string,
							   Boolean allow_load_save, Boolean b ) {
	return XrtPropertyEditorEnable(widget,enable,title_string,allow_load_save,b);
  }
  void setNthDataStyle(int index, XrtDataStyle * style) {
	XrtSetNthDataStyle(widget, index, style);
  }
  void setNthDataStyle2(int index, XrtDataStyle * style) {
	XrtSetNthDataStyle2(widget, index, style);
  }
  void setNthFooterString(int index, char * s) {
	XrtSetNthFooterString(widget, index, s);
  }
  void setNthHeaderString(int index, char *s) {
	XrtSetNthHeaderString(widget, index, s);
  }
  void setNthPointLabel(int index, String s) {
	XrtSetNthPointLabel(widget, index, s);
  }
  void setNthPointLabel2(int index, String s) {
	XrtSetNthPointLabel2(widget, index, s);
  }
  void setNthSetLabel(int index, String s) {
	XrtSetNthSetLabel(widget, index, s);
  }
  void setNthSetLabel2(int index, String s) {
	XrtSetNthSetLabel2(widget, index, s);
  }
  Boolean setPropString(XrtProperty res, char *str) {
	return XrtSetPropString(widget, res, str);
  }
  void setValueLabel(XrtAxis axis, XrtValueLabel *label) {
	XrtSetValueLabel(widget, axis, label);
  }
  void setXLabel(XrtXLabel * label) {
	XrtSetXLabel(widget, label);
  }
  void unmap(int yaxis, double x, double y, XrtMapResult *map ) {
	XrtUnmap( widget, yaxis, x, y, map );
  }
  void unpick(int dataset, int set, int point, XrtPickResult *pick ) {
	XrtUnpick( widget, dataset, set, point, pick );
  }

	// Don't use this.  It remains for backwards compatibility.
	// This will make a copy of the data, set the copy on the widget,
	// and free the copy.  XRT/graph will use the freed copy!
  void setData( XrtGraphData data )
  {
    setData(data.getDataHandle());
  }

  void setData( XrtGraphData *data )
  {
    setData(data->getDataHandle());
  }

private:
  Widget widget;
  Arg args[1]; 	// Needed for inline methods XRT_SG_RES and XRT_G_RES
					
};


/****************************************************************
 *  Class XrtTextArea
 ****************************************************************/

class XrtTextArea	{

public:
	XrtTextArea(XrtGraph *graph) { text = XrtTextAreaCreate(graph->getWidget()); }
	~XrtTextArea()	{ XrtTextAreaDestroy(text); }

	Boolean getPropString(XrtProperty res, char **str) {
		return XrtTextAreaGetPropString(text, res, str);
	}
	Boolean setPropString(XrtProperty res, char *str) {
		return XrtTextAreaSetPropString(text, res, str);
	}

    // Get methods
    XrtAdjust getAdjust() {
		XrtAdjust val;
		XrtTextAreaGetValues(text, XRT_TEXT_ADJUST, &val, NULL);
		return(val); }
    XrtAnchor getAnchor() {
		XrtAnchor val;
		XrtTextAreaGetValues(text, XRT_TEXT_ANCHOR, &val, NULL);
		return(val); }
    int getAttachDataset() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_DATASET, &val, NULL);
		return(val); }
    int getAttachPixelX() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_PIXEL_X, &val, NULL);
		return(val); }
    int getAttachPixelY() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_PIXEL_Y, &val, NULL);
		return(val); }
    int getAttachPoint() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_POINT, &val, NULL);
		return(val); }
    int getAttachSet() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_SET, &val, NULL);
		return(val); }
    XrtAttachType getAttachType() {
		XrtAttachType val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_TYPE, &val, NULL);
		return(val); }
    double getAttachValueX() {
		double val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_VALUE_X, &val, NULL);
		return(val); }
    double getAttachValueY() {
		double val;
		XrtTextAreaGetValues(text, XRT_TEXT_ATTACH_VALUE_Y, &val, NULL);
		return(val); }
    char * getBackgroundColor() {
		char * val;
		XrtTextAreaGetValues(text, XRT_TEXT_BACKGROUND_COLOR, &val, NULL);
		return(val); }
    XrtBorder getBorder() {
		XrtBorder val;
		XrtTextAreaGetValues(text, XRT_TEXT_BORDER, &val, NULL);
		return(val); }
    int getBorderWidth() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_BORDER_WIDTH, &val, NULL);
		return(val); }
    XmFontList getFont() {
		XmFontList val;
		XrtTextAreaGetValues(text, XRT_TEXT_FONT, &val, NULL);
		return(val); }
    char * getForegroundColor() { char * val;
		XrtTextAreaGetValues(text, XRT_TEXT_FOREGROUND_COLOR, &val, NULL);
		return(val); }
    int getHeight() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_HEIGHT, &val, NULL);
		return(val); }
    XrtImage getImage() {
		XrtImage val;
		XrtTextAreaGetValues(text, XRT_TEXT_IMAGE, &val, NULL);
		return(val); }
    XrtImageLayout getImageLayout() {
		XrtImageLayout val;
		XrtTextAreaGetValues(text, XRT_TEXT_IMAGE_LAYOUT, &val, NULL);		
		return(val); }
    Boolean getImageMinimumSize() {
		Boolean val;
		XrtTextAreaGetValues(text, XRT_TEXT_IMAGE_MINIMUM_SIZE, &val, NULL);		
		return(val); }
    Boolean getIsConnected() {
		Boolean val;
		XrtTextAreaGetValues(text, XRT_TEXT_IS_CONNECTED, &val, NULL);
		return(val); }
    Boolean getIsShowing() {
		Boolean val;
		XrtTextAreaGetValues(text, XRT_TEXT_IS_SHOWING, &val, NULL);
		return(val); }
    char * getName() {
		char * val;
		XrtTextAreaGetValues(text, XRT_TEXT_NAME, &val, NULL);
		return(val); }
    int getOffset() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_OFFSET, &val, NULL);
		return(val); }
    XrtRotate getRotation() {
		XrtRotate val;
		XrtTextAreaGetValues(text, XRT_TEXT_ROTATION, &val, NULL);		
		return(val); }
    char ** getStrings() {
		char ** val;
		XrtTextAreaGetValues(text, XRT_TEXT_STRINGS, &val, NULL);
		return(val); }
    int getWidth() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_WIDTH, &val, NULL);
		return(val); }
    int getX() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_X, &val, NULL);
		return(val); }
    int getY() {
		int val;
		XrtTextAreaGetValues(text, XRT_TEXT_Y, &val, NULL);
		return(val); }

    // Set methods
    void setAdjust(XrtAdjust val) {
		XrtTextAreaSetValues(text, 	XRT_TEXT_ADJUST, val, NULL); }
    void setAnchor(XrtAnchor val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ANCHOR, val, NULL); }
    void setAttachDataset(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_DATASET, val, NULL); }
    void setAttachPixelX(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_PIXEL_X, val, NULL); }
    void setAttachPixelY(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_PIXEL_Y, val, NULL); }
    void setAttachPoint(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_POINT, val, NULL); }
    void setAttachSet(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_SET, val, NULL); }
    void setAttachType(XrtAttachType val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_TYPE, val, NULL); }
    void setAttachValueX(double val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_VALUE_X, val, NULL); }
    void setAttachValueY(double val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ATTACH_VALUE_Y, val, NULL); }
    void setBackgroundColor(char * val) {
		XrtTextAreaSetValues(text, XRT_TEXT_BACKGROUND_COLOR, val, NULL); }
    void setBorder(XrtBorder val) {
		XrtTextAreaSetValues(text, XRT_TEXT_BORDER, val, NULL); }
    void setBorderWidth(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_BORDER_WIDTH, val, NULL); }
    void setFont(XmFontList val) {
		XrtTextAreaSetValues(text, XRT_TEXT_FONT, (int)val, NULL); }
    void setForegroundColor(char * val) {
		XrtTextAreaSetValues(text, XRT_TEXT_FOREGROUND_COLOR, val, NULL); }
    void setHeight(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_HEIGHT, val, NULL); }
    void setImage(char * val) {
		XrtTextAreaSetValues(text, XRT_TEXT_IMAGE, val, NULL); }
    void setImageLayout(XrtImageLayout val) {
		XrtTextAreaSetValues(text, XRT_TEXT_IMAGE_LAYOUT, val, NULL); }
    void setImageMinimunSize(Boolean val) {
		XrtTextAreaSetValues(text, XRT_TEXT_IMAGE_MINIMUM_SIZE, val, NULL); }
    void setIsConnected(Boolean val) {
		XrtTextAreaSetValues(text, XRT_TEXT_IS_CONNECTED, val, NULL); }
    void setIsShowing(Boolean val) {
		XrtTextAreaSetValues(text, XRT_TEXT_IS_SHOWING, val, NULL); }
    void setName(char * val) {
		XrtTextAreaSetValues(text, XRT_TEXT_NAME, val, NULL); }
    void setOffset(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_OFFSET, val, NULL); }
    void setRotation(XrtRotate val) {
		XrtTextAreaSetValues(text, XRT_TEXT_ROTATION, val, NULL); }
    void setStrings(char ** val) {
		XrtTextAreaSetValues(text, XRT_TEXT_STRINGS, val, NULL); }
    void setWidth(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_WIDTH, val, NULL); }
    void setX(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_X, val, NULL); }
    void setY(int val) {
		XrtTextAreaSetValues(text, XRT_TEXT_Y, val, NULL); }

private:
	XrtTextHandle	text;
};


/****************************************************************
 *  Class XrtPointStyle
 ****************************************************************/

class XrtPointStyle	{
	
public:
	XrtPointStyle(XrtGraph *graph) {
		ps = XrtPointStyleCreate(graph->getWidget());
	}
	XrtPointStyle(XrtGraph *graph, int cg_id, int set, int point) {
		ps = XrtPointStyleFindExact(graph->getWidget(), cg_id, set, point);
	}
	~XrtPointStyle() {
		XrtPointStyleDestroy(ps);
	}

	/* Set methods */

	void setSet(int val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_SET, val, NULL);
	}
	void setPoint(int val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_POINT, val, NULL);
	}
	void setPatternBackgroundColor(XrtColor val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_PATTERN_BACKGROUND_COLOR, val, NULL);
	}
	void setDataset(int val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_DATASET, val, NULL);
	}
	void setDisplay(XrtDisplay val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_DISPLAY, val, NULL);
	}
	void setDataStyle(XrtDataStyle *val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_DATA_STYLE, val, NULL);
	}
	void setFillStyle(int val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_FILL_STYLE, val, NULL);
	}
	void setLineStyle(int val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_LINE_STYLE, val, NULL);
	}
	void setSymbolStyle(XrtColor val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_SYMBOL_STYLE, val, NULL);
	}
	void setSliceOffset(float    val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_SLICE_OFFSET, val, NULL);
	}
	void setUseDefault(Boolean val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_USE_DEFAULT, val, NULL);
	}
	void setDataStyleUseDefault(Boolean val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_DATA_STYLE_USE_DEFAULT, val, NULL);
	}
	void setFillStyleUseDefault(Boolean val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_FILL_STYLE_USE_DEFAULT, val, NULL);
	}
	void setLineStyleUseDefault(Boolean val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_LINE_STYLE_USE_DEFAULT, val, NULL);
	}
	void setSymbolStyleUseDefault(Boolean val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_SYMBOL_STYLE_USE_DEFAULT, val, NULL);
	}
	void setSliceOffsetUseDefault(Boolean val) {
		XrtPointStyleSetValues(ps, XRT_POINTSTYLE_SLICE_OFFSET_USE_DEFAULT, val, NULL);
	}

	/* Get methods */
	int getSet() {
		int val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_SET, &val, NULL);
		return val;
	}
	int getPoint() {
		int val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_POINT, &val, NULL);
		return val;
	}
	XrtColor getPatternBackgroundColor() {
		XrtColor val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_PATTERN_BACKGROUND_COLOR, &val, NULL);
		return val;
	}
	int getDataset() {
		int val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_DATASET, &val, NULL);
		return val;
	}
	XrtDisplay getDisplay() {
		XrtDisplay val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_DISPLAY, &val, NULL);
		return val;
	}
	XrtDataStyle *getDataStyle() {
		XrtDataStyle *val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_DATA_STYLE, &val, NULL);
		return val;
	}
	int getFillStyle() {
		int val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_FILL_STYLE, &val, NULL);
		return val;
	}
	int getLineStyle() {
		int val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_LINE_STYLE, &val, NULL);
		return val;
	}
	XrtColor getSymbolStyle() {
		XrtColor val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_SYMBOL_STYLE, &val, NULL);
		return val;
	}
	float    getSliceOffset() {
		float    val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_SLICE_OFFSET, &val, NULL);
		return val;
	}
	Boolean getUseDefault() {
		Boolean val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_USE_DEFAULT, &val, NULL);
		return val;
	}
	Boolean getDataStyleUseDefault() {
		Boolean val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_DATA_STYLE_USE_DEFAULT, &val, NULL);
		return val;
	}
	Boolean getFillStyleUseDefault() {
		Boolean val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_FILL_STYLE_USE_DEFAULT, &val, NULL);
		return val;
	}
	Boolean getLineStyleUseDefault() {
		Boolean val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_LINE_STYLE_USE_DEFAULT, &val, NULL);
		return val;
	}
	Boolean getSymbolStyleUseDefault() {
		Boolean val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_SYMBOL_STYLE_USE_DEFAULT, &val, NULL);
		return val;
	}
	Boolean getSliceOffsetUseDefault() {
		Boolean val;
		XrtPointStyleGetValues(ps, XRT_POINTSTYLE_SLICE_OFFSET_USE_DEFAULT, &val, NULL);
		return val;
	}

private:
	XrtPointStyleHandle ps;

};

#undef XRT_S_RES
#undef XRT_G_RES
#undef XRT_SG_RES
#undef XRT_SG_FLOAT_RES

#endif
