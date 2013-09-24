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

/** \file XrtGraph.h
 * The main include file for XRT/graph.
 * \version 4.6
 * \date 01/04/04
 * \author Sitraka Inc.
 *
 * This file defines all the public API functions for the XRT/graph
 * widget and also provides the definition of the widget itself.
 * This is the only header file you should need to include when creating
 * and XRT/graph application.
 *
 * <A HREF="http://www.sitraka.com">http://www.sitraka.com<A>
 */


#ifndef _XtXrtGraph_h
#define _XtXrtGraph_h

#include <Xm/Xm.h>

#include "xrtgfcom.h"

#if defined(INTRINSICS_XRT) && defined(NDEBUG)
static char	sccsid_h1_xrtgraph[] = "@(#)XrtGraph.h	4.6 01/04/04 Sitraka Inc.";
#endif


/*
 *
 *  Resource names, in alphabetical order
 *
 */

#define XtNxrtAngleUnit                     "xrtAngleUnit"
#define XtNxrtAxisBoundingBox               "xrtAxisBoundingBox"
#define XtNxrtAxisFont                      "xrtAxisFont"
#define XtNxrtBackgroundColor               "xrtBackgroundColor"
#define XtNxrtBarClusterOverlap             "xrtBarClusterOverlap"
#define XtNxrtBarClusterWidth               "xrtBarClusterWidth"
#define XtNxrtBorder                        "xrtBorder"
#define XtNxrtBubbleMax                     "xrtBubbleMax"
#define XtNxrtBubbleMethod                  "xrtBubbleMethod"
#define XtNxrtBubbleMin                     "xrtBubbleMin"
#define XtNxrtCandleComplex                 "xrtCandleComplex"
#define XtNxrtColorFunc   					"xrtColorFunc"
#define XtNxrtData                          "xrtData"
#define XtNxrtData2                         "xrtData2"
#define XtNxrtDataStyles                    "xrtDataStyles"
#define XtNxrtDataStyles2                   "xrtDataStyles2"
#define XtNxrtDataStylesUseDefault          "xrtDataStylesUseDefault"
#define XtNxrtDataStyles2UseDefault         "xrtDataStyles2UseDefault"
#define XtNxrtDebug                         "xrtDebug"
#define XtNxrtDoubleBuffer                  "xrtDoubleBuffer"
#define XtNxrtExposeCallback                "xrtExposeCallback"
#define XtNxrtExtraDefaultDataStyles        "xrtExtraDefaultDataStyles"
#define XtNxrtFooterAdjust                  "xrtFooterAdjust"
#define XtNxrtFooterBackgroundColor         "xrtFooterBackgroundColor"
#define XtNxrtFooterBorder                  "xrtFooterBorder"
#define XtNxrtFooterBorderWidth             "xrtFooterBorderWidth"
#define XtNxrtFooterFont                    "xrtFooterFont"
#define XtNxrtFooterForegroundColor         "xrtFooterForegroundColor"
#define XtNxrtFooterHeight                  "xrtFooterHeight"
#define XtNxrtFooterImage                   "xrtFooterImage"
#define XtNxrtFooterImageLayout             "xrtFooterImageLayout"
#define XtNxrtFooterImageMinimumSize        "xrtFooterImageMinimumSize"
#define XtNxrtFooterStrings                 "xrtFooterStrings"
#define XtNxrtFooterWidth                   "xrtFooterWidth"
#define XtNxrtFooterX                       "xrtFooterX"
#define XtNxrtFooterXUseDefault             "xrtFooterXUseDefault"
#define XtNxrtFooterY                       "xrtFooterY"
#define XtNxrtFooterYUseDefault             "xrtFooterYUseDefault"
#define XtNxrtForegroundColor               "xrtForegroundColor"
#define XtNxrtFrontDataset                  "xrtFrontDataset"
#define XtNxrtDataAreaBackgroundColor       "xrtDataAreaBackgroundColor"
#define XtNxrtDataAreaForegroundColor       "xrtDataAreaForegroundColor"
#define XtNxrtDataAreaImage                 "xrtDataAreaImage"
#define XtNxrtDataAreaImageLayout           "xrtDataAreaImageLayout"
#define XtNxrtGraph3dShading                "xrtGraph3dShading"
#define XtNxrtGraphBackgroundColor          "xrtGraphBackgroundColor"
#define XtNxrtGraphBorder                   "xrtGraphBorder"
#define XtNxrtGraphBorderWidth              "xrtGraphBorderWidth"
#define XtNxrtGraphDepth                    "xrtGraphDepth"
#define XtNxrtGraphForegroundColor          "xrtGraphForegroundColor"
#define XtNxrtGraphHeight                   "xrtGraphHeight"
#define XtNxrtGraphHeightUseDefault         "xrtGraphHeightUseDefault"
#define XtNxrtGraphImage                    "xrtGraphImage"
#define XtNxrtGraphImageLayout              "xrtGraphImageLayout"
#define XtNxrtGraphInclination              "xrtGraphInclination"
#define XtNxrtGraphMarginBottom             "xrtGraphMarginBottom"
#define XtNxrtGraphMarginBottomUseDefault   "xrtGraphMarginBottomUseDefault"
#define XtNxrtGraphMarginLeft               "xrtGraphMarginLeft"
#define XtNxrtGraphMarginLeftUseDefault     "xrtGraphMarginLeftUseDefault"
#define XtNxrtGraphMarginRight              "xrtGraphMarginRight"
#define XtNxrtGraphMarginRightUseDefault    "xrtGraphMarginRightUseDefault"
#define XtNxrtGraphMarginTop                "xrtGraphMarginTop"
#define XtNxrtGraphMarginTopUseDefault      "xrtGraphMarginTopUseDefault"
#define XtNxrtGraphRotation                 "xrtGraphRotation"
#define XtNxrtGraphShowOutlines             "xrtGraphShowOutlines"
#define XtNxrtGraphWidth                    "xrtGraphWidth"
#define XtNxrtGraphWidthUseDefault          "xrtGraphWidthUseDefault"
#define XtNxrtGraphX                        "xrtGraphX"
#define XtNxrtGraphXUseDefault              "xrtGraphXUseDefault"
#define XtNxrtGraphY                        "xrtGraphY"
#define XtNxrtGraphYUseDefault              "xrtGraphYUseDefault"
#define XtNxrtHeaderAdjust                  "xrtHeaderAdjust"
#define XtNxrtHeaderBackgroundColor         "xrtHeaderBackgroundColor"
#define XtNxrtHeaderBorder                  "xrtHeaderBorder"
#define XtNxrtHeaderBorderWidth             "xrtHeaderBorderWidth"
#define XtNxrtHeaderFont                    "xrtHeaderFont"
#define XtNxrtHeaderForegroundColor         "xrtHeaderForegroundColor"
#define XtNxrtHeaderHeight                  "xrtHeaderHeight"
#define XtNxrtHeaderImage                   "xrtHeaderImage"
#define XtNxrtHeaderImageLayout             "xrtHeaderImageLayout"
#define XtNxrtHeaderImageMinimumSize        "xrtHeaderImageMinimumSize"
#define XtNxrtHeaderStrings                 "xrtHeaderStrings"
#define XtNxrtHeaderWidth                   "xrtHeaderWidth"
#define XtNxrtHeaderX                       "xrtHeaderX"
#define XtNxrtHeaderXUseDefault             "xrtHeaderXUseDefault"
#define XtNxrtHeaderY                       "xrtHeaderY"
#define XtNxrtHeaderYUseDefault             "xrtHeaderYUseDefault"
#define XtNxrtHiLoCloseShow                 "xrtHiLoCloseShow"
#define XtNxrtHiLoOpenCloseFullWidth        "xrtHiLoOpenCloseFullWidth"
#define XtNxrtHiLoOpenShow                  "xrtHiLoOpenShow"
#define XtNxrtImage                         "xrtImage"
#define XtNxrtImageLayout                   "xrtImageLayout"
#define XtNxrtInvertOrientation             "xrtInvertOrientation"
#define XtNxrtIsStacked                     "xrtIsStacked"
#define XtNxrtIsStacked2                    "xrtIsStacked2"
#define XtNxrtLegendAnchor                  "xrtLegendAnchor"
#define XtNxrtLegendBackgroundColor         "xrtLegendBackgroundColor"
#define XtNxrtLegendBorder                  "xrtLegendBorder"
#define XtNxrtLegendBorderWidth             "xrtLegendBorderWidth"
#define XtNxrtLegendFont                    "xrtLegendFont"
#define XtNxrtLegendForegroundColor         "xrtLegendForegroundColor"
#define XtNxrtLegendHeight                  "xrtLegendHeight"
#define XtNxrtLegendImage                   "xrtLegendImage"
#define XtNxrtLegendImageLayout             "xrtLegendImageLayout"
#define XtNxrtLegendOrientation             "xrtLegendOrientation"
#define XtNxrtLegendReversed                "xrtLegendReversed"
#define XtNxrtLegendShow                    "xrtLegendShow"
#define XtNxrtLegendTitle                   "xrtLegendTitle"
#define XtNxrtLegendWidth                   "xrtLegendWidth"
#define XtNxrtLegendX                       "xrtLegendX"
#define XtNxrtLegendXUseDefault             "xrtLegendXUseDefault"
#define XtNxrtLegendY                       "xrtLegendY"
#define XtNxrtLegendYUseDefault             "xrtLegendYUseDefault"
#define XtNxrtMapCallback                   "xrtMapCallback"
#define XtNxrtMarkerDataStyle               "xrtMarkerDataStyle"
#define XtNxrtMarkerDataStyleUseDefault     "xrtMarkerDataStyleUseDefault"
#define XtNxrtMarkerDataset                 "xrtMarkerDataset"
#define XtNxrtModifyCallback                "xrtModifyCallback"
#define XtNxrtOtherDataStyle                "xrtOtherDataStyle"
#define XtNxrtOtherDataStyleUseDefault      "xrtOtherDataStyleUseDefault"
#define XtNxrtOtherLabel                    "xrtOtherLabel"
#define XtNxrtPickCallback                  "xrtPickCallback"
#define XtNxrtPieMergeMissingSlices         "xrtPieMergeMissingSlices"
#define XtNxrtPieMinSlices                  "xrtPieMinSlices"
#define XtNxrtPieOrder                      "xrtPieOrder"
#define XtNxrtPieStartAngle                 "xrtPieStartAngle"
#define XtNxrtPieThresholdMethod            "xrtPieThresholdMethod"
#define XtNxrtPieThresholdValue             "xrtPieThresholdValue"
#define XtNxrtPointLabels                   "xrtPointLabels"
#define XtNxrtPointLabels2                  "xrtPointLabels2"
#define XtNxrtPolarAxisAllowNegatives       "xrtPolarAxisAllowNegatives"
#define XtNxrtPolarHalfRange                "xrtPolarHalfRange"
#define XtNxrtRepaint                       "xrtRepaint"
#define XtNxrtResizeCallback                "xrtResizeCallback"
#define XtNxrtRotateCallback                "xrtRotateCallback"
#define XtNxrtSetLabels                     "xrtSetLabels"
#define XtNxrtSetLabels2                    "xrtSetLabels2"
#define XtNxrtTimeUnit                      "xrtTimeUnit"
#define XtNxrtTimeBase                      "xrtTimeBase"
#define XtNxrtTimeFormat                    "xrtTimeFormat"
#define XtNxrtTimeFormatUseDefault          "xrtTimeFormatUseDefault"
#define XtNxrtTransformCallback             "xrtTransformCallback"
#define XtNxrtType                          "xrtType"
#define XtNxrtType2                         "xrtType2"
#define XtNxrtXAnnoPlacement                "xrtXAnnoPlacement"
#define XtNxrtXAnnotationMethod             "xrtXAnnotationMethod"
#define XtNxrtXAnnotationRotation           "xrtXAnnotationRotation"
#define XtNxrtXAxisDataStyle                "xrtXAxisDataStyle"
#define XtNxrtXAxisDataStyleUseDefault      "xrtXAxisDataStyleUseDefault"
#define XtNxrtXAxisLabelFormat              "xrtXAxisLabelFormat"
#define XtNxrtXAxisLogarithmic              "xrtXAxisLogarithmic"
#define XtNxrtXAxisMax                      "xrtXAxisMax"
#define XtNxrtXAxisMaxUseDefault            "xrtXAxisMaxUseDefault"
#define XtNxrtXAxisMin                      "xrtXAxisMin"
#define XtNxrtXAxisMinUseDefault            "xrtXAxisMinUseDefault"
#define XtNxrtXAxisShow                     "xrtXAxisShow"
#define XtNxrtXAxisReversed                 "xrtXAxisReversed"
#define XtNxrtXGrid                         "xrtXGrid"
#define XtNxrtXGridDataStyle                "xrtXGridDataStyle"
#define XtNxrtXGridDataStyleUseDefault      "xrtXGridDataStyleUseDefault"
#define XtNxrtXGridUseDefault               "xrtXGridUseDefault"
#define XtNxrtXLabels                       "xrtXLabels"
#define XtNxrtXMarker                       "xrtXMarker"
#define XtNxrtXMarkerDataStyle              "xrtXMarkerDataStyle"
#define XtNxrtXMarkerDataStyleUseDefault    "xrtXMarkerDataStyleUseDefault"
#define XtNxrtXMarkerMethod                 "xrtXMarkerMethod"
#define XtNxrtXMarkerPoint                  "xrtXMarkerPoint"
#define XtNxrtXMarkerSet                    "xrtXMarkerSet"
#define XtNxrtXMarkerShow                   "xrtXMarkerShow"
#define XtNxrtXMax                          "xrtXMax"
#define XtNxrtXMaxUseDefault                "xrtXMaxUseDefault"
#define XtNxrtXMin                          "xrtXMin"
#define XtNxrtXMinUseDefault                "xrtXMinUseDefault"
#define XtNxrtXNum                          "xrtXNum"
#define XtNxrtXNumMethod                    "xrtXNumMethod"
#define XtNxrtXNumUseDefault                "xrtXNumUseDefault"
#define XtNxrtXOrigin                       "xrtXOrigin"
#define XtNxrtXOriginBase                   "xrtXOriginBase"
#define XtNxrtXOriginPlacement              "xrtXOriginPlacement"
#define XtNxrtXOriginUseDefault             "xrtXOriginUseDefault"
#define XtNxrtXPrecision                    "xrtXPrecision"
#define XtNxrtXPrecisionUseDefault          "xrtXPrecisionUseDefault"
#define XtNxrtXTick                         "xrtXTick"
#define XtNxrtXTickUseDefault               "xrtXTickUseDefault"
#define XtNxrtXTitle                        "xrtXTitle"
#define XtNxrtXTitleRotation                "xrtXTitleRotation"
#define XtNxrtY2AnnoPlacement               "xrtY2AnnoPlacement"
#define XtNxrtY2AnnotationAngle             "xrtY2AnnotationAngle"
#define XtNxrtY2AnnotationAngleUseDefault   "xrtY2AnnotationAngleUseDefault"
#define XtNxrtY2AnnotationMethod            "xrtY2AnnotationMethod"
#define XtNxrtY2AnnotationRotation          "xrtY2AnnotationRotation"
#define XtNxrtY2Axis100Percent              "xrtY2Axis100Percent"
#define XtNxrtY2AxisDataStyle               "xrtY2AxisDataStyle"
#define XtNxrtY2AxisDataStyleUseDefault     "xrtY2AxisDataStyleUseDefault"
#define XtNxrtY2AxisLabelFormat             "xrtY2AxisLabelFormat"
#define XtNxrtY2AxisLogarithmic             "xrtY2AxisLogarithmic"
#define XtNxrtY2AxisMax                     "xrtY2AxisMax"
#define XtNxrtY2AxisMaxUseDefault           "xrtY2AxisMaxUseDefault"
#define XtNxrtY2AxisMin                     "xrtY2AxisMin"
#define XtNxrtY2AxisMinUseDefault           "xrtY2AxisMinUseDefault"
#define XtNxrtY2AxisShow                    "xrtY2AxisShow"
#define XtNxrtY2Grid                        "xrtY2Grid"
#define XtNxrtY2GridDataStyle               "xrtY2GridDataStyle"
#define XtNxrtY2GridDataStyleUseDefault     "xrtY2GridDataStyleUseDefault"
#define XtNxrtY2GridUseDefault              "xrtY2GridUseDefault"
#define XtNxrtY2Labels                      "xrtY2Labels"
#define XtNxrtY2Max                         "xrtY2Max"
#define XtNxrtY2MaxUseDefault               "xrtY2MaxUseDefault"
#define XtNxrtY2Min                         "xrtY2Min"
#define XtNxrtY2MinUseDefault               "xrtY2MinUseDefault"
#define XtNxrtY2Num                         "xrtY2Num"
#define XtNxrtY2NumMethod                   "xrtY2NumMethod"
#define XtNxrtY2NumUseDefault               "xrtY2NumUseDefault"
#define XtNxrtY2Origin                      "xrtY2Origin"
#define XtNxrtY2OriginPlacement             "xrtY2OriginPlacement"
#define XtNxrtY2OriginUseDefault            "xrtY2OriginUseDefault"
#define XtNxrtY2Precision                   "xrtY2Precision"
#define XtNxrtY2PrecisionUseDefault         "xrtY2PrecisionUseDefault"
#define XtNxrtY2AxisReversed                "xrtY2AxisReversed"
#define XtNxrtY2Tick                        "xrtY2Tick"
#define XtNxrtY2TickUseDefault              "xrtY2TickUseDefault"
#define XtNxrtY2Title                       "xrtY2Title"
#define XtNxrtY2TitleRotation               "xrtY2TitleRotation"
#define XtNxrtYAnnoPlacement                "xrtYAnnoPlacement"
#define XtNxrtYAnnotationAngle              "xrtYAnnotationAngle"
#define XtNxrtYAnnotationAngleUseDefault    "xrtYAnnotationAngleUseDefault"
#define XtNxrtYAnnotationMethod             "xrtYAnnotationMethod"
#define XtNxrtYAnnotationRotation           "xrtYAnnotationRotation"
#define XtNxrtYAxis100Percent               "xrtYAxis100Percent"
#define XtNxrtYAxisConst                    "xrtYAxisConst"
#define XtNxrtYAxisDataStyle                "xrtYAxisDataStyle"
#define XtNxrtYAxisDataStyleUseDefault      "xrtYAxisDataStyleUseDefault"
#define XtNxrtYAxisLabelFormat              "xrtYAxisLabelFormat"
#define XtNxrtYAxisLogarithmic              "xrtYAxisLogarithmic"
#define XtNxrtYAxisMax                      "xrtYAxisMax"
#define XtNxrtYAxisMaxUseDefault            "xrtYAxisMaxUseDefault"
#define XtNxrtYAxisMin                      "xrtYAxisMin"
#define XtNxrtYAxisMinUseDefault            "xrtYAxisMinUseDefault"
#define XtNxrtYAxisMult                     "xrtYAxisMult"
#define XtNxrtYAxisReversed                 "xrtYAxisReversed"
#define XtNxrtYAxisShow                     "xrtYAxisShow"
#define XtNxrtYGrid                         "xrtYGrid"
#define XtNxrtYGridDataStyle                "xrtYGridDataStyle"
#define XtNxrtYGridDataStyleUseDefault      "xrtYGridDataStyleUseDefault"
#define XtNxrtYGridUseDefault               "xrtYGridUseDefault"
#define XtNxrtYLabels                       "xrtYLabels"
#define XtNxrtYMarker                       "xrtYMarker"
#define XtNxrtYMarkerDataStyle              "xrtYMarkerDataStyle"
#define XtNxrtYMarkerDataStyleUseDefault    "xrtYMarkerDataStyleUseDefault"
#define XtNxrtYMarkerShow                   "xrtYMarkerShow"
#define XtNxrtYMax                          "xrtYMax"
#define XtNxrtYMaxUseDefault                "xrtYMaxUseDefault"
#define XtNxrtYMin                          "xrtYMin"
#define XtNxrtYMinUseDefault                "xrtYMinUseDefault"
#define XtNxrtYNum                          "xrtYNum"
#define XtNxrtYNumMethod                    "xrtYNumMethod"
#define XtNxrtYNumUseDefault                "xrtYNumUseDefault"
#define XtNxrtYOrigin                       "xrtYOrigin"
#define XtNxrtYOriginPlacement              "xrtYOriginPlacement"
#define XtNxrtYOriginUseDefault             "xrtYOriginUseDefault"
#define XtNxrtYPrecision                    "xrtYPrecision"
#define XtNxrtYPrecisionUseDefault          "xrtYPrecisionUseDefault"
#define XtNxrtYTick                         "xrtYTick"
#define XtNxrtYTickUseDefault               "xrtYTickUseDefault"
#define XtNxrtYTitle                        "xrtYTitle"
#define XtNxrtYTitleRotation                "xrtYTitleRotation"
#define XtNxrtZoomAxisCallback              "xrtZoomAxisCallback"

/*
 *
 *  Class types, in alphabetical order
 *
*/

#define XtCXrtAdjust                        "XrtAdjust"
#define XtCXrtAlign                         "XrtAlign"
#define XtCXrtAnchor                        "XrtAnchor"
#define XtCXrtAngleUnit                     "XrtAngleUnit"
#define XtCXrtAnnoPlacement                 "XrtAnnoPlacement"
#define XtCXrtAnnotationMethod              "XrtAnnotationMethod"
#define XtCXrtAxisBounds                    "XrtAxisBounds"
#define XtCXrtAxisBoundsUseDefault          "XrtAxisBoundsUseDefault"
#define XtCXrtAxisConst                     "XrtAxisConst"
#define XtCXrtAxisLabelFormat               "XrtAxisLabelFormat"
#define XtCXrtAxisLogarithmic               "XrtAxisLogarithmic"
#define XtCXrtAxisMult                      "XrtAxisMult"
#define XtCXrtAxisParams                    "XrtAxisParams"
#define XtCXrtAxisParamsUseDefault          "XrtAxisParamsUseDefault"
#define XtCXrtAxisReversed                  "XrtAxisReversed"
#define XtCXrtAxisShow                      "XrtAxisShow"
#define XtCXrtBackgroundColor               "XrtBackgroundColor"
#define XtCXrtBarClusterOverlap             "XrtBarClusterOverlap"
#define XtCXrtBarClusterWidth               "XrtBarClusterWidth"
#define XtCXrtBorder                        "XrtBorder"
#define XtCXrtBorderWidth                   "XrtBorderWidth"
#define XtCXrtBubbleBounds                  "XrtBubbleBounds"
#define XtCXrtBubbleMethod                  "XrtBubbleMethod"
#define XtCXrtCallback                      "XrtCallback"
#define XtCXrtCandleOption                  "XrtCandleOption"
#define XtCXrtData                          "XrtData"
#define XtCXrtDataStyle                     "XrtDataStyle"
#define XtCXrtDataStyles                    "XrtDataStyles"
#define XtCXrtDataStylesUseDefault          "XrtDataStylesUseDefault"
#define XtCXrtDataset                       "XrtDataset"
#define XtCXrtDebug                         "XrtDebug"
#define XtCXrtDimension                     "XrtDimension"
#define XtCXrtDimensionUseDefault           "XrtDimensionUseDefault"
#define XtCXrtDoubleBuffer                  "XrtDoubleBuffer"
#define XtCXrtDrawOption                    "XrtDrawOption"
#define XtCXrtForegroundColor               "XrtForegroundColor"
#define XtCXrtFunction				    	"XrtFunction"
#define XtCXrtGraph3dShading                "XrtGraph3dShading"
#define XtCXrtGraphDepth                    "XrtGraphDepth"
#define XtCXrtGraphInclination              "XrtGraphInclination"
#define XtCXrtGraphMargin                   "XrtGraphMargin"
#define XtCXrtGraphMarginUseDefault         "XrtGraphMarginUseDefault"
#define XtCXrtGraphOption                   "XrtGraphOption"
#define XtCXrtGraphRotation                 "XrtGraphRotation"
#define XtCXrtGrid                          "XrtGrid"
#define XtCXrtGridUseDefault                "XrtGridUseDefault"
#define XtCXrtHiLoOption                    "XrtHiLoOption"
#define XtCXrtImage                         "XrtImage"
#define XtCXrtImageLayout                   "XrtImageLayout"
#define XtCXrtImageMinimumSize              "XrtImageMinimumSize"
#define XtCXrtIsStacked                     "XrtIsStacked"
#define XtCXrtMarker                        "XrtMarker"
#define XtCXrtMarkerMethod                  "XrtMarkerMethod"
#define XtCXrtMarkerPoint                   "XrtMarkerPoint"
#define XtCXrtMarkerSet                     "XrtMarkerSet"
#define XtCXrtMarkerShow                    "XrtMarkerShow"
#define XtCXrtNumMethod                     "XrtNumMethod"
#define XtCXrtOtherLabel                    "XrtOtherLabel"
#define XtCXrtOriginPlacement               "XrtOriginPlacement"
#define XtCXrtPieMinSlices                  "XrtPieMinSlices"
#define XtCXrtPieSlices                     "XrtPieSlices"
#define XtCXrtPieOrder                      "XrtPieOrder"
#define XtCXrtPieStartAngle                 "XrtPieStartAngle"
#define XtCXrtPieThresholdMethod            "XrtPieThresholdMethod"
#define XtCXrtPieThresholdValue             "XrtPieThresholdValue"
#define XtCXrtPointLabels                   "XrtPointLabels"
#define XtCXrtPolarOption                   "XrtPolarOption"
#define XtCXrtPosition                      "XrtPosition"
#define XtCXrtPositionUseDefault            "XrtPositionUseDefault"
#define XtCXrtPrecision                     "XrtPrecision"
#define XtCXrtPrecisionUseDefault           "XrtPrecisionUseDefault"
#define XtCXrtRepaint                       "XrtRepaint"
#define XtCXrtRotation                      "XrtRotation"
#define XtCXrtSetLabels                     "XrtSetLabels"
#define XtCXrtStrings                       "XrtStrings"
#define XtCXrtTimeBase                      "XrtTimeBase"
#define XtCXrtTimeFormat                    "XrtTimeFormat"
#define XtCXrtTimeFormatUseDefault          "XrtTimeFormatUseDefault"
#define XtCXrtTimeUnit                      "XrtTimeUnit"
#define XtCXrtTitle                         "XrtTitle"
#define XtCXrtType                          "XrtType"
#define XtCXrtValueLabels                   "XrtValueLabels"

/*
 *
 *  Representation types, in alphabetical order
 *
 */

#define XtRXrtAdjust                        "XrtAdjust"
#define XtRXrtAlign                         "XrtAlign"
#define XtRXrtAnchor                        "XrtAnchor"
#define XtRXrtAngleUnit                     "XrtAngleUnit"
#define XtRXrtAnnotationMethod              "XrtAnnotationMethod"
#define XtRXrtAnnoPlacement                 "XrtAnnoPlacement"
#define XtRXrtBorder                        "XrtBorder"
#define XtRXrtBubbleMethod                  "XrtBubbleMethod"
#define XtRXrtColor                         "XrtColor"
#define XtRXrtData                          "XrtData"
#define XtRXrtDataStyle                     "XrtDataStyle"
#define XtRXrtDataStyles                    "XrtDataStyles"
#define XtRXrtDouble                        "XrtDouble"
#define XtRXrtImage                         "XrtImage"
#define XtRXrtImageLayout                   "XrtImageLayout"
#define XtRXrtMarkerMethod                  "XrtMarkerMethod"
#define XtRXrtNumMethod                     "XrtNumMethod"
#define XtRXrtOriginPlacement               "XrtOriginPlacement"
#define XtRXrtPieOrder                      "XrtPieOrder"
#define XtRXrtPieThresholdMethod            "XrtPieThresholdMethod"
#define XtRXrtRotate                        "XrtRotate"
#define XtRXrtShading                       "XrtShading"
#define XtRXrtString                        "XrtString"
#define XtRXrtStrings                       "XrtStrings"
#define XtRXrtType                          "XrtType"
#define XtRXrtValueLabels                   "XrtValueLabels"
#define XtRXrtTimeUnit                      "XrtTimeUnit"
#ifndef XtRLong
#define XtRLong                             "Long"
#endif

/* For backwards compatibility we need these */

#define XtRXrtXLabels                       XtRXrtValueLabels
#define XtRXrtXMethod                       XtRXrtAnnotationMethod

/*
 *  XrtGraph Widget
 */

/**
 * Externally visible definition of the XRT/graph widget class.
 */
externalref WidgetClass xtXrtGraphWidgetClass;

typedef struct _XtXrtGraphClassRec * XtXrtGraphWidgetClass;
typedef struct _XtXrtGraphRec      * XtXrtGraphWidget;

#ifndef XtIsXrtGraph
/**
 * Macro to test if \c w is an XRT/graph widget or is subclassed
 * from an XRT/graph widget.
 */
#define XtIsXrtGraph(w) XtIsSubclass(w, xtXrtGraphWidgetClass)
#endif /* XtIsXrtGraph */

/*
 *  XrtGraph externs for application accessible functions
 */

#if defined(_NO_PROTO) || defined(ultrix)

extern float            	XrtArgValToFloat();
extern int              	XrtArrCheckAxisBounds();
extern int              	XrtArrDataAppendPts();
extern int              	XrtArrDataFastUpdate();
extern int              	XrtArrDataRemovePts();
extern int              	XrtArrDataShiftPts();
extern int              	XrtCustomFormatValidate();
extern XrtDataHandle    	XrtDataConcat();
extern XrtDataHandle    	XrtDataCopy();
extern XrtDataHandle    	XrtDataConvertToHandle();
extern XrtDataHandle    	XrtDataCreate();
extern XrtDataHandle    	XrtDataCreateFromFile();
extern void             	XrtDataDestroy();
extern XrtDataHandle    	XrtDataExtractSet();
XrtDisplay              	XrtDataGetDisplay();
int                     	XrtDataGetFirstPoint();
int                     	XrtDataGetFirstSet();
double                  	XrtDataGetHole();
int                     	XrtDataGetLastPoint();
int                     	XrtDataGetLastSet();
int                     	XrtDataGetNPoints();
int                     	XrtDataGetNSets();
XrtDataType             	XrtDataGetType();
float    *              	XrtDataGetXData();
double                  	XrtDataGetXElement();
float    *              	XrtDataGetYData();
double                  	XrtDataGetYElement();
extern int              	XrtDataRelease();
extern int              	XrtDataRemoveSet();
extern int              	XrtDataSaveToFile();
int                     	XrtDataSetDisplay();
int                     	XrtDataSetFirstPoint();
int                     	XrtDataSetFirstSet();
int                     	XrtDataSetHole();
int                     	XrtDataSetLastPoint();
int                     	XrtDataSetLastSet();
int                     	XrtDataSetNPoints();
int                     	XrtDataSetNSets();
int                     	XrtDataSetType();
int                     	XrtDataSetXData();
int                     	XrtDataSetXElement();
int                     	XrtDataSetYData();
int                     	XrtDataSetYElement();
extern int              	XrtDataSort();
extern XrtDataHandle    	XrtDataTranspose();
extern int              	XrtDataUpdateDataValue();
extern Boolean          	XrtDeletePointLabel();
extern Boolean          	XrtDeletePointLabel2();
extern Boolean          	XrtDeleteSetLabel();
extern Boolean          	XrtDeleteSetLabel2();
extern void             	XrtDestroyData();
extern int              	XrtDrawPS();
extern XrtDataStyle **  	XrtDupDataStyles();
extern char **          	XrtDupStrings();
extern XrtValueLabel ** 	XrtDupValueLabels();
extern Boolean				XrtEnableImageType();
extern XtArgVal         	XrtFloatToArgVal();
extern void             	XrtFreeDataStyles();
extern void             	XrtFreePropString();
extern void             	XrtFreeStrings();
extern void             	XrtFreeTextHandles();
extern void             	XrtFreeValueLabels();
extern int              	XrtGenCheckAxisBounds();
extern int              	XrtGenDataAppendPt();
extern int              	XrtGenDataFastUpdate();
extern int              	XrtGenDataRemovePt();
extern int              	XrtGenDataShiftPts();
extern XImage *         	XrtGetImage();
extern XrtDataStyle *   	XrtGetNthDataStyle();
extern XrtDataStyle *   	XrtGetNthDataStyle2();
extern char *           	XrtGetNthFooterString();
extern char *           	XrtGetNthHeaderString();
extern String           	XrtGetNthPointLabel();
extern String           	XrtGetNthPointLabel2();
extern String           	XrtGetNthSetLabel();
extern String           	XrtGetNthSetLabel2();
extern int *            	XrtGetOtherSliceSets();
extern Boolean          	XrtGetPropString();
extern int              	XrtGetTextHandles();
extern XrtValueLabel *  	XrtGetValueLabel();
extern void             	XrtGetValues();
extern XrtXLabel *      	XrtGetXLabel();
extern int              	XrtInsertNthDataStyle();
extern Boolean          	XrtInsertPointLabel();
extern Boolean          	XrtInsertPointLabel2();
extern Boolean          	XrtInsertSetLabel();
extern Boolean          	XrtInsertSetLabel2();
extern XrtData *        	XrtMakeData();
extern XrtData *        	XrtMakeDataFromFile();
extern long             	XrtMakeTime();
extern XrtRegion        	XrtMap();
extern int              	XrtMrmInitialize();
extern int              	XrtOutputPS();
extern int              	XrtOutputRaster();
extern int              	XrtOutputXwd();
extern XrtRegion        	XrtPick();
extern XrtPointStyleHandle	XrtPointStyleCreate();
extern void                	XrtPointStyleDestroy();
extern void					XrtPointStyleGetValues();
extern XrtPointStyleHandle	XrtPointStyleFindExact();
extern void					XrtPointStyleSetValues();
#ifdef ultrix
extern Boolean          	XrtPropertyEditorEnable(Widget, char, char *,
													char, char);
#else
extern Boolean          	XrtPropertyEditorEnable();
#endif
extern int              	XrtRemoveNthDataStyle();
extern unsigned long		XrtSampleColorFunction();
extern Boolean				XrtSaveImageAsJpeg();
extern Boolean              XrtSaveImageAsPng();
extern Boolean              XrtSaveImageGeneric();
extern int              	XrtSaveDataToFile();
extern void             	XrtSetNthDataStyle();
extern void             	XrtSetNthDataStyle2();
extern void             	XrtSetNthFooterString();
extern void             	XrtSetNthHeaderString();
extern void             	XrtSetNthPointLabel();
extern void             	XrtSetNthPointLabel2();
extern void             	XrtSetNthSetLabel();
extern void             	XrtSetNthSetLabel2();
extern Boolean          	XrtSetPropString();
extern void             	XrtSetReverseConverters();
extern void             	XrtSetValueLabel();
extern void             	XrtSetValues();
extern void             	XrtSetXLabel();
extern XrtTextHandle    	XrtTextAreaCreate();
extern void             	XrtTextAreaDestroy();
extern Boolean          	XrtTextAreaGetPropString();
extern void             	XrtTextAreaGetValues();
extern Boolean          	XrtTextAreaSetPropString();
extern void             	XrtTextAreaSetValues();
extern void             	XrtTextAttach();
extern XrtTextHandle    	XrtTextCreate();
extern void             	XrtTextDestroy();
extern void             	XrtTextDetach();
extern int              	XrtTextDetail();
extern void             	XrtTextUpdate();
extern void             	XrtUnmap();
extern void             	XrtUnpick();
extern Widget           	XtCreateXrtGraph();


#else /* _NO_PROTO */

#include <stdio.h>      /* needed for FILE below */

#if defined(__cplusplus)
extern "C" {
#endif
/**
 * Converts an \c XtArgVal to a \c float. This procedure is the opposite of
 * XrtFloatToArgVal().
 * \param value The XrtArgValue to convert.
 * \return The \c float representation of the \c XtArgVal.
 * \sa XrtFloatToArgVal().
 */
extern float            	XrtArgValToFloat(XtArgVal);
extern int              	XrtArrCheckAxisBounds(Widget, int, int);
extern int              	XrtArrDataAppendPts(XrtDataHandle, double,
												float    *);
extern int              	XrtArrDataFastUpdate(Widget, int, int);
extern int              	XrtArrDataRemovePts(XrtDataHandle, int);
extern int              	XrtArrDataShiftPts(XrtDataHandle, int, int, int);
extern int              	XrtCustomFormatValidate(char* format);
extern XrtDataHandle    	XrtDataConcat(XrtDataHandle, XrtDataHandle);
extern XrtDataHandle    	XrtDataCopy(XrtDataHandle);
extern XrtDataHandle    	XrtDataConvertToHandle(XrtData * data);
extern XrtDataHandle    	XrtDataCreate(XrtDataType, int, int);
extern XrtDataHandle    	XrtDataCreateFromFile(char *, char *);
extern void             	XrtDataDestroy(XrtDataHandle);
extern XrtDataHandle    	XrtDataExtractSet(XrtDataHandle, int);
XrtDisplay              	XrtDataGetDisplay(XrtDataHandle, int);
int                     	XrtDataGetFirstPoint(XrtDataHandle, int);
int                     	XrtDataGetFirstSet(XrtDataHandle);
double                  	XrtDataGetHole(XrtDataHandle);
int                     	XrtDataGetLastPoint(XrtDataHandle, int);
int                     	XrtDataGetLastSet(XrtDataHandle);
int                     	XrtDataGetNPoints(XrtDataHandle, int);
int                     	XrtDataGetNSets(XrtDataHandle);
XrtDataType             	XrtDataGetType(XrtDataHandle);
float    *              	XrtDataGetXData(XrtDataHandle, int);
double                  	XrtDataGetXElement(XrtDataHandle, int, int);
float    *              	XrtDataGetYData(XrtDataHandle, int);
double                  	XrtDataGetYElement(XrtDataHandle, int, int);
extern int              	XrtDataRelease(XrtDataHandle);
extern int              	XrtDataRemoveSet(XrtDataHandle, int);
extern int              	XrtDataSaveToFile(XrtDataHandle, char *, char *);
int                     	XrtDataSetDisplay(XrtDataHandle, int, XrtDisplay);
int                     	XrtDataSetFirstPoint(XrtDataHandle, int, int);
int                     	XrtDataSetFirstSet(XrtDataHandle, int);
int                     	XrtDataSetHole(XrtDataHandle, double);
int                     	XrtDataSetLastPoint(XrtDataHandle, int, int);
int                     	XrtDataSetLastSet(XrtDataHandle, int);
int                     	XrtDataSetNPoints(XrtDataHandle, int, int);
int                     	XrtDataSetNSets(XrtDataHandle, int);
int                     	XrtDataSetType(XrtDataHandle, XrtDataType);
int                     	XrtDataSetXData(XrtDataHandle, int, float    *,
											int, int);
int                     	XrtDataSetXElement(XrtDataHandle, int, int, double);
int                     	XrtDataSetYData(XrtDataHandle, int, float    *,
											int, int);
int                     	XrtDataSetYElement(XrtDataHandle, int, int, double);
extern int              	XrtDataSort(XrtDataHandle);
extern XrtDataHandle    	XrtDataTranspose(XrtDataHandle);
extern int              	XrtDataUpdateDataValue(XrtDataHandle,
												   double, double);
extern Boolean          	XrtDeletePointLabel(Widget, int);
extern Boolean          	XrtDeletePointLabel2(Widget, int);
extern Boolean          	XrtDeleteSetLabel(Widget, int);
extern Boolean          	XrtDeleteSetLabel2(Widget, int);
extern void             	XrtDestroyData(XrtData *, int);
extern int              	XrtDrawPS(Widget, FILE *, char *, int, double,
									  double, double, int, double, double,
									  double, double, char *, int, char *,
									  int, char *, int, char *, int, int,
									  int, int);
extern XrtDataStyle **  	XrtDupDataStyles(XrtDataStyle **);
extern char **          	XrtDupStrings(char **);
extern XrtValueLabel ** 	XrtDupValueLabels(XrtValueLabel **);
extern Boolean				XrtEnableImageType(XtPointer, XtPointer);
extern XtArgVal         	XrtFloatToArgVal(double);
extern void             	XrtFreeDataStyles(XrtDataStyle **);
extern void             	XrtFreePropString(char *);
extern void             	XrtFreeStrings(char **);
extern void             	XrtFreeTextHandles(XrtTextHandle *);
extern void             	XrtFreeValueLabels(XrtValueLabel **);
extern int              	XrtGenCheckAxisBounds(Widget, int, int, int);
extern int              	XrtGenDataAppendPt(XrtDataHandle, int,
											   double, double);
extern int              	XrtGenDataFastUpdate(Widget, int, int, int);
extern int              	XrtGenDataRemovePt(XrtDataHandle, int, int);
extern int              	XrtGenDataShiftPts(XrtDataHandle, int, int,
											   int, int);
extern XImage *         	XrtGetImage(Widget);
extern XrtDataStyle *   	XrtGetNthDataStyle(Widget, int);
extern XrtDataStyle *   	XrtGetNthDataStyle2(Widget, int);
extern char *           	XrtGetNthFooterString(Widget, int);
extern char *           	XrtGetNthHeaderString(Widget, int);
extern String           	XrtGetNthPointLabel(Widget, int);
extern String           	XrtGetNthPointLabel2(Widget, int);
extern String           	XrtGetNthSetLabel(Widget, int);
extern String           	XrtGetNthSetLabel2(Widget, int);
extern int *            	XrtGetOtherSliceSets(Widget, int, int);
extern Boolean          	XrtGetPropString(Widget, XrtProperty, char **);
extern int              	XrtGetTextHandles(Widget, XrtTextHandle **);
extern XrtValueLabel *  	XrtGetValueLabel(Widget, XrtAxis, XrtValueLabel *);
extern void             	XrtGetValues(Widget, ... );
extern XrtXLabel *      	XrtGetXLabel(Widget, XrtXLabel *);
extern int              	XrtInsertNthDataStyle(Widget, int, XrtDataStyle *,
												  int);
extern Boolean          	XrtInsertPointLabel(Widget, int, String);
extern Boolean          	XrtInsertPointLabel2(Widget, int, String);
extern Boolean          	XrtInsertSetLabel(Widget, int, String);
extern Boolean          	XrtInsertSetLabel2(Widget, int, String);
extern XrtData *        	XrtMakeData(XrtDataType, int, int, int);
extern XrtData *        	XrtMakeDataFromFile(char *, char *);
extern long             	XrtMakeTime(int, int, int, int, int, int);
extern XrtRegion        	XrtMap(Widget, int, int, int, XrtMapResult *);
extern int              	XrtMrmInitialize(void);
extern int              	XrtOutputPS(Widget, FILE *, int, char *);
extern int              	XrtOutputRaster(Widget, FILE *, char *);
extern int              	XrtOutputXwd(Widget, FILE *, char *);
extern XrtRegion        	XrtPick(Widget, int, int, int, XrtPickResult *,
									XrtFocus);
extern XrtPointStyleHandle	XrtPointStyleCreate(Widget);
extern void                	XrtPointStyleDestroy(XrtPointStyleHandle);
extern void					XrtPointStyleGetValues(XrtPointStyleHandle, ... );
extern XrtPointStyleHandle	XrtPointStyleFindExact(Widget, int, int, int);
extern void					XrtPointStyleSetValues(XrtPointStyleHandle, ... );
extern Boolean          	XrtPropertyEditorEnable(Widget, Boolean, char *,
													Boolean, Boolean);
extern int              	XrtRemoveNthDataStyle(Widget, int, int);
extern unsigned long		XrtSampleColorFunction(Display *, int, Colormap,
												   XColor *, Boolean);
extern int              	XrtSaveDataToFile(XrtData *, char *, char *);
extern Boolean				XrtSaveImageAsJpeg(Widget, String, String);
extern Boolean              XrtSaveImageAsPng(Widget, String, String);
extern Boolean              XrtSaveImageGeneric(Widget, int, String, String);
extern void             	XrtSetNthDataStyle(Widget, int, XrtDataStyle *);
extern void             	XrtSetNthDataStyle2(Widget, int, XrtDataStyle *);
extern void             	XrtSetNthFooterString(Widget, int, char *);
extern void             	XrtSetNthHeaderString(Widget, int, char *);
extern void             	XrtSetNthPointLabel(Widget, int, String);
extern void             	XrtSetNthPointLabel2(Widget, int, String);
extern void             	XrtSetNthSetLabel(Widget, int, String);
extern void             	XrtSetNthSetLabel2(Widget, int, String);
extern Boolean          	XrtSetPropString(Widget, XrtProperty, char *);
extern void             	XrtSetReverseConverters(void);
extern void             	XrtSetValueLabel(Widget, XrtAxis, XrtValueLabel *);
extern void             	XrtSetValues(Widget, ... );
extern void             	XrtSetXLabel(Widget, XrtXLabel *);
extern XrtTextHandle    	XrtTextAreaCreate(Widget);
extern void             	XrtTextAreaDestroy(XrtTextHandle);
extern Boolean          	XrtTextAreaGetPropString(XrtTextHandle, XrtProperty,
													 char **);
extern void             	XrtTextAreaGetValues(XrtTextHandle, ... );
extern Boolean          	XrtTextAreaSetPropString(XrtTextHandle, XrtProperty,
													 char *);
extern void             	XrtTextAreaSetValues(XrtTextHandle, ... );
extern void             	XrtTextAttach(Widget, XrtTextHandle);
extern XrtTextHandle    	XrtTextCreate(Widget, XrtTextDesc *);
extern void             	XrtTextDestroy(Widget, XrtTextHandle);
extern void             	XrtTextDetach(Widget, XrtTextHandle);
extern int              	XrtTextDetail(Widget, XrtTextHandle, XrtTextDesc *);
extern void             	XrtTextUpdate(Widget, XrtTextHandle, XrtTextDesc *);
extern void             	XrtUnmap(Widget, int, double, double,
									 XrtMapResult *);
extern void             	XrtUnpick(Widget, int, int, int, XrtPickResult *);
extern Widget           	XtCreateXrtGraph(Widget, char *, ArgList, Cardinal);


#if defined(__cplusplus)
}
#endif

#endif /* _NO_PROTO */

#define XrtDupXLabels       XrtDupValueLabels
#define XrtFreeXLabels      XrtFreeValueLabels

#endif /* _XtXrtGraph_h */
/* DON'T ADD ANYTHING AFTER THIS #endif */
