/********************************************************************
* Project: LiteCAD DLL
* Copyright (c) 2009-2016, Oleg Kolbaskin.
* All rights reserved.
*
* API definitions and external functions
********************************************************************/
#include <windows.h>
#ifndef _LCAPI_H
#define _LCAPI_H

#define LC_FALSE    0  
#define LC_TRUE     1 

// LiteCAD window styles ( lcCreateWindow )
#define LC_WS_HSCROLL     1    // Window has a horizontal scroll bar
#define LC_WS_VSCROLL     2    // Window has a vertical scroll bar
#define LC_WS_BORDER      4    // Window has a thin-line border
#define LC_WS_CLIENTEDGE  8    
#define LC_WS_SUNKEN      8    // Window has a border with a sunken edge
#define LC_WS_STATICEDGE  16   // Window has a three-dimensional border style
#define LC_WS_VIEWTABS    256  // Window has View Tabs (border frame automatically added)
#define LC_WS_RULERS      512  // Window has rulers
#define LC_WS_DEFAULT     3    // Combination of LC_WS_VSCROLL and LC_WS_HSCROLL styles

// Flags of lc2_Create
#define LC_WS2_PROPWND    1    //
#define LC_WS2_RULERS     2    //
#define LC_WS2_SCROLLS    4    //
#define LC_WS2_STATBAR    8    //
#define LC_WS2_COORDS     16   //
#define LC_WS2_TOOLBAR    32   //
#define LC_WS2_DEFAULT    47   // all except LC_WS2_COORDS

#define LC_MRU_IMAGE_W  246
#define LC_MRU_IMAGE_H  190

// Pen Styles ( lcPenCreate )
#define LC_PS_SOLID           0
#define LC_PS_DASH            1       // ------- 
#define LC_PS_DOT             2       // ....... 
#define LC_PS_DASHDOT         3       // _._._._ 
#define LC_PS_DASHDOTDOT      4       // _.._.._ 

// Line width display mmode ( LC_PROP_WND_LWMODE )
#define LC_LW_THIN   0
#define LC_LW_REAL   1
#define LC_LW_PIXEL  2   // depends on LC_PROP_WND_LWSCALE

// Filling type ( LC_PROP_FILL_TYPE, lcBrushCreate )
#define LC_FILL_SOLID        0
#define LC_FILL_BDIAGONAL    1
#define LC_FILL_CROSS        2
#define LC_FILL_DIAGCROSS    3
#define LC_FILL_FDIAGONAL    4
#define LC_FILL_HORIZONTAL   5
#define LC_FILL_VERTICAL     6
#define LC_FILL_NONE         100
#define LC_FILL_LINES        101   // LaserDraw type hatch
#define LC_FILL_HATCH        102   // AutoCAD type hatch

// ResizeFilter types ( lcImageResize & lcWndToRaster )
#define LC_IMGRES_BOX         0  // Box, pulse, Fourier window, 1st order (constant) B-Spline
#define LC_IMGRES_BILINEAR    1  // Bilinear filter
#define LC_IMGRES_BSPLINE     2  // 4th order (cubic) B-Spline
#define LC_IMGRES_BICUBIC     3  // Mitchell and Netravali's two-param cubic filter
#define LC_IMGRES_CATMULLROM  4  // Catmull-Rom spline, Overhauser spline
#define LC_IMGRES_LANCZOS3    5  // Lanczos-windowed sinc filter

// Grip type ( lcGripAdd )
#define LC_GRIP_POINT    0
#define LC_GRIP_CENROT   1   // center of rotation
#define LC_GRIP_ANGLE    2
#define LC_GRIP_ANGLE2   3   // same as LC_GRIP_ANGLE but more offset
#define LC_GRIP_BEZIER   4
#define LC_GRIP_BEZIER0  5
#define LC_GRIP_ARCRAD   6

// Barcode type ( lcMpgonAddBarcode, LC_PROP_BARC_TYPE )
// Must be same values as BARC_TYPE_... in BaseLibs\Barcode\Barcode.h
#define LC_BARTYPE_CODE39    0
#define LC_BARTYPE_CODE93    1
#define LC_BARTYPE_CODE128   6
#define LC_BARTYPE_EAN13     7
#define LC_BARTYPE_ITF       8
#define LC_BARTYPE_EAN8      9
#define LC_BARTYPE_QR        21
#define LC_BARTYPE_MQR       22
#define LC_BARTYPE_DMATRIX   23
#define LC_BARTYPE_DM        23
#define LC_BARTYPE_DMATRIXR  24
#define LC_BARTYPE_DMR       24

// QR-code Error Correction Level (SetECLevel(), LC_PROP_G_BARC_ECL)
// Must be same values as BARC_QRECL_... in BaseLibs\Barcode\Barcode.h
#define LC_BARC_QRECL_L   0  // 01
#define LC_BARC_QRECL_M   1  // 00
#define LC_BARC_QRECL_Q   2  // 11
#define LC_BARC_QRECL_H   3  // 10

// Leader text alignment flags
#define LC_LEADER_TCENTER     0
#define LC_LEADER_TLEFT       1
#define LC_LEADER_TRIGHT      2
// Leader line attachment flags
#define LC_LEADER_VERT        1
#define LC_LEADER_CORNER      2

// commands for lcVportLayerCmd
#define LC_VPL_CLEAR          1  // delete all layers override
#define LC_VPL_ADD            2  // add viewport layer override
#define LC_VPL_DELETE         3  // delete viewport layer override
#define LC_VPL_PROP_BEGIN     4  // begin to edit layer properties
#define LC_VPL_PROP_END       5  // end to edit layer properties


// Radian -> Degree
#define LC_RAD_TO_DEG  57.2957795130823208768  // F
// Degree -> Radian
#define LC_DEG_TO_RAD   0.01745329251994329577  // F

// angles in radians
#define LC_PI      3.14159265358979323846  // F
#define LC_PI2     1.57079632679489661923  // F
#define LC_PI4     0.78539816339744830962  // F
#define LC_2PI     6.28318530717958647692  // F

// angles in degrees
#define LC_DEG1    0.01745329251994329577  // F
#define LC_DEG2    0.03490658503988659154  // F
#define LC_DEG3    0.05235987755982988731  // F
#define LC_DEG4    0.06981317007977318308  // F
#define LC_DEG5    0.08726646259971647885  // F
#define LC_DEG6    0.10471975511965977462  // F
#define LC_DEG7    0.12217304763960307038  // F
#define LC_DEG8    0.13962634015954636615  // F
#define LC_DEG9    0.15707963267948966192  // F
#define LC_DEG10   0.17453292519943295769  // F
#define LC_DEG20   0.34906585039886591538  // F
#define LC_DEG30   0.52359877559829887308  // F
#define LC_DEG40   0.69813170079773183077  // F
#define LC_DEG45   0.78539816339744830962  // F
#define LC_DEG50   0.87266462599716478846  // F
#define LC_DEG60   1.04719755119659774615  // F
#define LC_DEG70   1.22173047639603070385  // F
#define LC_DEG80   1.39626340159546366154  // F
#define LC_DEG90   1.57079632679489661923  // F
#define LC_DEG180  3.14159265358979323846  // F
#define LC_DEG270  4.71238898038468985769  // F
#define LC_DEG360  6.28318530717958647692  // F

// Drawing's units
#define LC_INSUNIT_UNDEFINED     0    // Undefined
#define LC_INSUNIT_INCHES        1    // Inches
#define LC_INSUNIT_FEET          2    // Feet
#define LC_INSUNIT_MILES         3    // Miles
#define LC_INSUNIT_MILLIMETERS   4    // Millimeters
#define LC_INSUNIT_CENTIMETERS   5    // Centimeters
#define LC_INSUNIT_METERS        6    // Meters
#define LC_INSUNIT_KILOMETERS    7    // Kilometers
#define LC_INSUNIT_MICROINCHES   8    // Microinches
#define LC_INSUNIT_MILS          9    // Mils
#define LC_INSUNIT_YARDS         10   // Yards
#define LC_INSUNIT_ANGSTROMS     11   // Angstroms
#define LC_INSUNIT_NANOMETERS    12   // Nanometers
#define LC_INSUNIT_MICRONS       13   // Microns
#define LC_INSUNIT_DECIMETERS    14   // Decimeters
#define LC_INSUNIT_DEKAMETERS    15   // Dekameters
#define LC_INSUNIT_HECTOMETERS   16   // Hectometers
#define LC_INSUNIT_GIGAMETERS    17   // Gigameters
#define LC_INSUNIT_ASTRONOMICAL  18   // Astronomical
#define LC_INSUNIT_LIGHTYEARS    19   // Lightyears
#define LC_INSUNIT_PARSECS       20   // Parsecs

#define LC_LUNIT_SCIEN  1  // Scientific
#define LC_LUNIT_DECIM  2  // Decimal
#define LC_LUNIT_ENGIN  3  // Engineering
#define LC_LUNIT_ARCHI  4  // Architectural
#define LC_LUNIT_FRACT  5  // Fractional

// Angle units used with GUI and API (variants for LC_PROP_G_ANGLE property)
#define LC_AUNIT_DEGREE  0  // Decimal degrees
#define LC_AUNIT_DMS     1  // Degrees/minutes/seconds
#define LC_AUNIT_GRAD    2  // Grads
#define LC_AUNIT_RADIAN  3  // Radians
#define LC_AUNIT_SURVEY  4  // Surveyor's units
// same
#define LC_ANGLE_DEGREE  0  // Decimal degrees
#define LC_ANGLE_DMS     1  // Degrees/minutes/seconds
#define LC_ANGLE_GRAD    2  // Grads
#define LC_ANGLE_RADIAN  3  // Radians
#define LC_ANGLE_SURVEY  4  // Surveyor's units

// paper size ( lcWndPaperSetSize )
#define LC_PAPER_CUSTOM     0
#define LC_PAPER_USER       0
#define LC_PAPER_A0         1
#define LC_PAPER_A1         2
#define LC_PAPER_A2         3
#define LC_PAPER_A3         4
#define LC_PAPER_A4         5
#define LC_PAPER_A5         6
#define LC_PAPER_A6         7
#define LC_PAPER_B0         11
#define LC_PAPER_B1         12
#define LC_PAPER_B2         13
#define LC_PAPER_B3         14
#define LC_PAPER_B4         15
#define LC_PAPER_B5         16
#define LC_PAPER_B6         17
#define LC_PAPER_C0         21
#define LC_PAPER_C1         22
#define LC_PAPER_C2         23
#define LC_PAPER_C3         24
#define LC_PAPER_C4         25
#define LC_PAPER_C5         26
#define LC_PAPER_C6         27
#define LC_PAPER_ANSI_A     31
#define LC_PAPER_ANSI_B     32
#define LC_PAPER_ANSI_C     33
#define LC_PAPER_ANSI_D     34
#define LC_PAPER_ANSI_E     35
#define LC_PAPER_LETTER     36
#define LC_PAPER_LEGAL      37
#define LC_PAPER_EXECUTIVE  38
#define LC_PAPER_LEDGER     39
#define LC_PAPER_UNLIMITED  100

// Printer paper orientation
#define LC_PAPER_PORTRAIT     0
#define LC_PAPER_BOOK         0
#define LC_PAPER_LANDSCAPE    1
#define LC_PAPER_ALBUM        1

// text alignment types (LC_PROP_G_TEXT_ALIGN)
#define LC_TA_LEFBOT          0   // Align by left bottom corner
#define LC_TA_CENBOT          1   // Align by center of bottom line
#define LC_TA_RIGBOT          2   // Align by right bottom corner
#define LC_TA_LEFCEN          3   // Align by left side of vertical center line
#define LC_TA_CENTER          4   // Align by center of text
#define LC_TA_RIGCEN          5   // Align by right side of vertical center line
#define LC_TA_LEFTOP          6   // Align by left top corner
#define LC_TA_CENTOP          7   // Align by center of top line
#define LC_TA_RIGTOP          8   // Align by right tom corner
#define LC_TA_ALIGNED         11  // Fit text between 2 points (Adjust Height)
#define LC_TA_FIT             12  // Fit text between 2 points (Adjust Width scale)

// text flags for LC_TEXTPRM::Generation
#define LC_TEXT_BACKWARD      2 
#define LC_TEXT_UPDOWN        4

// text alignment types for arc text
#define LC_ATA_LEFT           0   // Align by left side of text
#define LC_ATA_CENTER         1   // Align by center of text
#define LC_ATA_RIGHT          2   // Align by right side of text

// text alignment types for barcode text
#define LC_BTA_LEFT           0   // Align by left side of text
#define LC_BTA_CENTER         1   // Align by center of text
#define LC_BTA_RIGHT          2   // Align by right side of text

// Polyline fit types ( lcPtbufInterpolate )
#define LC_PLFIT_BULGE        0      // linear with bulges
#define LC_PLFIT_NONE         0
#define LC_PLFIT_QUAD         5      // Quadratic B-spline
#define LC_PLFIT_CUBIC        6      // Cubic B-spline
#define LC_PLFIT_BEZIER       7      // Bezier spline
#define LC_PLFIT_SPLINE       99     // spline fitted to vertices
#define LC_PLFIT_ROUND        101    // rounded vertices
#define LC_PLFIT_LINQUAD      102    // mixed linear and quadratic segments

// Point modes ( lcPaint_DrawPoint, lcBlockAddPoint2 )
#define LC_POINT_PIXEL        0     // Pixel
#define LC_POINT_NONE         1     // None
#define LC_POINT_PLUS         2     // "Plus" sign through the point.
#define LC_POINT_X            3     // "X" through the point
#define LC_POINT_TICK         4     // Vertical tick mark upward from the point.
// additional elements     
#define LC_POINT_CIRCLE       32    // Circle 
#define LC_POINT_SQUARE       64    // Square
#define LC_POINT_RHOMB        128   // Rhomb
#define LC_POINT_FILLED       256   // Filled shape
// extra
#define LC_POINT_BEAM0        10000
#define LC_POINT_BEAM1        10001

// values for parameter 'Mode' of lcBlockSelBlock (LcBlkCreate::m_Mode)
#define LC_BLK_ENT_RETAIN    0    // retain original entities, don't insert the block
#define LC_BLK_ENT_CONVERT   1    // delete selected entities, insert the block
#define LC_BLK_ENT_DELETE    2    // delete selected entities, don't insert the block

// Mouse buttons
#define LC_LBUTTON  1   // Left button is pressed
#define LC_RBUTTON  2   // right button is pressed
#define LC_MBUTTON  4   // middle button is pressed

// Key state
#define LC_SHIFT  1   // SHIFT key is pressed
#define LC_CTRL   2   // CTRL key is pressed
#define LC_ALT    4   // ALT key is pressed

// keyboard type
#define LC_KBD_QWERTY  0  // QWERTY
#define LC_KBD_AZERTY  1  // AZERTY
#define LC_KBD_QWERTZ  2  // QWERTZ

// LiteCAD window cursor, to use in lcPropPutInt(0, LC_PROP_WND_CURSORARROW, Val)
#define LC_CURSOR_NULL    0    // no cursor
#define LC_CURSOR_ARROW   1    // Standard arrow
#define LC_CURSOR_CROSS   2    // Crosshair
#define LC_CURSOR_HAND    3    // Hand
#define LC_CURSOR_HELP    4    // Arrow and question mark
#define LC_CURSOR_NO      5    // Slashed circle
#define LC_CURSOR_WAIT    6    // Hourglass
#define LC_CURSOR_PAN1    7    // Pan start cursor
#define LC_CURSOR_PAN2    8    // Pan move cursor

// flags for lcExpEntity
#define LC_EXP_OUTLINE    1
#define LC_EXP_HATCH      2
#define LC_EXP_ALL        3
#define LC_EXP_MAXRESOL   4

// values for lcWndEmulator
#define LC_EMUL_START     0
#define LC_EMUL_STOP      1
#define LC_EMUL_PARAMS    2

// magnifier zoom values
#define LC_MAG_ZOOM_4     0
#define LC_MAG_ZOOM_6     1
#define LC_MAG_ZOOM_8     2
#define LC_MAG_ZOOM_10    3
#define LC_MAG_ZOOM_12    4
#define LC_MAG_ZOOM_14    5
// magnifier flags
#define LC_MAG_CENTER     1  // draw center cross


// Mode for lcDrwExplode
#define LC_DRWEXP_PLINES  0   // explode to polylines
#define LC_DRWEXP_LINES   1   // explode to lines
#define LC_DRWEXP_LARCS   2   // explode to lines and arcs
#define LC_DRWEXP_LCA     3   // explode to lines, circles and arcs

// ID of help file topic
#define LC_HELP_DG_PRINT        1
#define LC_HELP_DG_RASTER       2
#define LC_HELP_DG_GBR_APERS    4
#define LC_HELP_DG_GBR_BITMAP   5
#define LC_HELP_DG_COLOR        6
#define LC_HELP_DG_LAYERS       7
#define LC_HELP_DG_SELLTYPE     8
#define LC_HELP_DG_LINETYPES    9
#define LC_HELP_DG_LOADLINETYPE 10 
#define LC_HELP_DG_TEXTSTYLES   11
#define LC_HELP_DG_PNTSTYLES    12
#define LC_HELP_DG_DIMSTYLES    13
#define LC_HELP_DG_HATSTYLES    14
#define LC_HELP_DG_SELBLOCK     15
#define LC_HELP_DG_SELTSTYLE    16
#define LC_HELP_DG_SELPTYPE     17
#define LC_HELP_DG_CREBLOCK     18 
#define LC_HELP_DG_BLOCKS       19
#define LC_HELP_DG_LAYOUTS      20
#define LC_HELP_DG_PAGEPROP     21
#define LC_HELP_DG_IMAGES       22
#define LC_HELP_DG_IMAGEINSERT  23
#define LC_HELP_DG_SELFONT      24
#define LC_HELP_DG_TEXT         25
#define LC_HELP_DG_ARCTEXT      26
#define LC_HELP_DG_INPUTCOORD   27
#define LC_HELP_DG_WORKFIELD    28
#define LC_HELP_DG_CRBITMAP     29
#define LC_HELP_DG_INSERT       30
#define LC_HELP_DG_TSP          31
#define LC_HELP_DG_ARRAY        32
#define LC_HELP_DG_ARRAYARC     33
#define LC_HELP_DG_HATCH        34
#define LC_HELP_DG_GRID         41
#define LC_HELP_DG_PTRACK       42
#define LC_HELP_DG_OSNAP        43
#define LC_HELP_DG_KBMOVE       44
#define LC_HELP_DG_DRWPROPS     45
#define LC_HELP_DG_SYSPROPS     46
#define LC_HELP_DG_SELECTION    47
#define LC_HELP_DG_RPOLYGON     48
#define LC_HELP_DG_LIMITS       49

#define LC_UNDO_BEGIN  0   // begin record
#define LC_UNDO_END    1   // end record

// Error codes
#define LC_ERR_OBJTYPE        1   // wrong type of object
#define LC_ERR_NOTAG          2   // string tag is not found
#define LC_ERR_USERCANCEL     3   // user have clicked "Cancel" button
#define LC_ERR_FILENAME       4   // wrong filename
#define LC_ERR_FILELOAD       5   // can't load a file
#define LC_ERR_FILESAVE       6   // can't save a file
#define LC_ERR_UNRESBLOCKREF  7   // unresolved block reference
#define LC_ERR_UNRESVIEWREF   8   // unresolved view reference
#define LC_ERR_UNRESHATCH     9   // unresolved hatch 



// Non-graphical objects (Named)
#define LC_OBJ_LAYER       1    // Layer
#define LC_OBJ_LINETYPE    2    // Linetype
#define LC_OBJ_TEXTSTYLE   3    // Text style
#define LC_OBJ_DIMSTYLE    4    // Dimension style
#define LC_OBJ_PNTSTYLE    5    // Point style
#define LC_OBJ_IMAGE       6    // Image
#define LC_OBJ_MLSTYLE     8    // Multiline style
#define LC_OBJ_FILLING     9    // Filling
#define LC_OBJ_BLOCK       10   // Block
#define LC_OBJ_LAYOUT      11   // Layout block (Model or Paper space)

// Graphic objects
#define LC_ENT_LINE        101  // Line
#define LC_ENT_POLYLINE    102  // Polyline
#define LC_ENT_CIRCLE      103  // Circle
#define LC_ENT_ARC         104  // Arc
#define LC_ENT_BLOCKREF    105  // Block Reference
#define LC_ENT_POINT       107  // Point
#define LC_ENT_XLINE       108  // Construction line or ray
#define LC_ENT_ELLIPSE     109  // Ellipse or elliptical arc
#define LC_ENT_TEXT        110  // Text
#define LC_ENT_TEXTWIN     111  // Text by GDI TextOut
#define LC_ENT_IMAGEREF    115  // Image Reference
#define LC_ENT_VIEWPORT    116  // Viewport
#define LC_ENT_CLIPRECT    117  // Clip area
#define LC_ENT_RECT        118  // Rectangle
#define LC_ENT_ATTRIB      120  // Attribute
#define LC_ENT_ECW         121  // ECW image
#define LC_ENT_MTEXT       122  // Multiline Text
#define LC_ENT_ARCTEXT     123  // Arc Text
#define LC_ENT_HATCH       124  // Hatch
#define LC_ENT_FACE        126  // 3D Face
#define LC_ENT_MLINE       127  // multiline polyline
#define LC_ENT_DIMROT      131  // Dimension Linear 
#define LC_ENT_DIMLIN      131  // Dimension Linear
#define LC_ENT_DIMALI      132  // Dimension Aligned
#define LC_ENT_DIMORD      133  // Dimension Ordinate
#define LC_ENT_DIMRAD      134  // Dimension Radial
#define LC_ENT_DIMDIA      135  // Dimension Diametric
#define LC_ENT_DIMANG      136  // Dimension Angular
#define LC_ENT_LEADER      137  // Leader
#define LC_ENT_RPLAN       141  // Road plan
#define LC_ENT_TIN         142  // Triangulated Irregular Network
#define LC_ENT_BARCODE     150  // Barcode
#define LC_ENT_SHAPE       160  // Shape
#define LC_ENT_XREF        199  // External Reference
#define LC_ENT_ARROW       301  // Arrow
#define LC_ENT_SPIRAL      302  // Spiral
#define LC_ENT_CAMERA      303  // Camera
#define LC_ENT_PTARRAY     304  // points array      
#define LC_ENT_CUSTOM      1000
#define LC_ENT_ALL         32767   // used for bulk properties

// Lineweights
#define LC_LWEIGHT_DEFAULT  -3     // Default lineweight. Width is controlled by LC_PROP_DRW_LWDEFAULT property.
#define LC_LWEIGHT_BYBLOCK  -2     // Only for entities contained in block. Universal lineweight specified within a BlockRef entity.
#define LC_LWEIGHT_BYLAYER  -1     // Only for entities. Universal lineweight specified in the entity's layer.
#define LC_LWIDTH_DEFAULT   -3     
#define LC_LWIDTH_BYBLOCK   -2     
#define LC_LWIDTH_BYLAYER   -1     

// variants for LC_PROP_G_COLOR property
#define LC_COLOR_RGB        0  // RGB value (COLORREF)
#define LC_COLOR_INDEX      1  // AutoCAD Color Index (ACI)

// defined ACI Colors
#define LC_COLOR_RED          1  // Red
#define LC_COLOR_YELLOW       2  // Yellow
#define LC_COLOR_GREEN        3  // Green
#define LC_COLOR_CYAN         4  // Cyan
#define LC_COLOR_BLUE         5  // Blue
#define LC_COLOR_MAGENTA      6  // Magenta
#define LC_COLOR_FOREGROUND   7  // Foreground (contrast to background color)
#define LC_COLOR_GRAY         8  // Gray
#define LC_COLOR_LTGRAY       9  // Light gray
// logical colors for entities
#define LC_COLOR_BYBLOCK      0     // entity's color by block
#define LC_COLOR_BYLAYER      256   // entity's color by layer

// options for LC_PROP_DRW_SELPENMODE
#define LC_SELPEN_COLOR  0  // dotted pen, color by m_SelPenColor and m_SelPenColorBk
#define LC_SELPEN_BYENT  1  // dottet pen, color by entity

// Multiline justification 0 = Top; 1 = Middle; 2 = Bottom
#define LC_MLINE_TOP          0
#define LC_MLINE_MIDDLE       1
#define LC_MLINE_BOTTOM       2

#define LC_TABLE_IDSET     349000349

// Plugin Interface Types
// Do not change this values, because it must be the same in plugin DLLs
#define LC_PLUG_IMPDRW        2   // load a drawing from a file into LiteCAD database (in memory)
#define LC_PLUG_EXPDRW        3   // save a drawing from LiteCAD database into a file
#define LC_PLUG_IMGDIB        4   // load an image from a file into LiteCAD DIB

// values for the F_FIOPROGRESS Mode
#define LC_FP_FLOAD           0   // szFileName - a file is being loaded
#define LC_FP_FSAVE           1   // szFileName - a file is being saved
#define LC_FP_NITEMS          2   // IntVal - number of items
#define LC_FP_ITEM            3  

// Snap modes ( LC_PROP_WND_OSNAP )
#define LC_OSNAP_NULL          0      //0x00000 no snap at all
#define LC_OSNAP_NODE          1      //0x00001 to a Point object, dimension definition point, or dimension text origin.
#define LC_OSNAP_ENDPOINT      2      //0x00002 to the closest endpoint of an Arc, Elliptical Arc, Line, Multiline, Polyline segment, Ray
#define LC_OSNAP_MIDPOINT      4      //0x00004 to the midpoint of an arc, ellipse, elliptical arc, line, multiline, polyline segment, region, solid, spline, or xline.
#define LC_OSNAP_CENTER        8      //0x00008 to the center of an arc, circle, ellipse, or elliptical arc.
#define LC_OSNAP_NEAREST       16     //0x00010 to the nearest point on an arc, circle, ellipse, elliptical arc, line, multiline, point, polyline, ray, spline, or xline.
#define LC_OSNAP_INTER         32     //0x00020 to the intersection of an arc, circle, ellipse, elliptical arc, line, multiline, polyline, ray, region, spline, or xline.
#define LC_OSNAP_PERPEND       64     //0x00040 to a point perpendicular to an arc, circle, ellipse, elliptical arc, line, multiline, polyline, ray, region, solid, spline, or xline
#define LC_OSNAP_TANGENT       128    //0x00080 to the tangent of an arc, circle, ellipse, elliptical arc, or spline.
#define LC_OSNAP_QUADRANT      256    //0x00100 to a quadrant point of an arc, circle, ellipse, or elliptical arc.
#define LC_OSNAP_INSERT        512    //0x00200 to the insertion point of an attribute, a block, a shape, or text.
#define LC_OSNAP_NONE          1024   //0x00400 temporary disable object snap
#define LC_OSNAP_ALL           1023   //0x003FF all modes

// Attribute flags
#define LC_ATTRIB_HIDDEN      1
#define LC_ATTRIB_CONST       2
#define LC_ATTRIB_VERIFY      4
#define LC_ATTRIB_PRESET      8
#define LC_ATTRIB_LOCK        16
#define LC_ATTRIB_MTEXT       32

// 3D Face flags (must be the same as in "..\odt\ad2.h"
#define LC_FACE_EDGE1INVIS     1
#define LC_FACE_EDGE2INVIS     2
#define LC_FACE_EDGE3INVIS     4
#define LC_FACE_EDGE4INVIS     8
#define LC_FACE_EDGE1HIDDEN    1
#define LC_FACE_EDGE2HIDDEN    2
#define LC_FACE_EDGE3HIDDEN    4
#define LC_FACE_EDGE4HIDDEN    8

// block overwrite mode
#define LC_BLOCK_OVERWRITENO   0
#define LC_BLOCK_OVERWRITEYES  1
#define LC_BLOCK_OVERWRITEDLG  2

// arrowhead types (for dimensions)         
#define LC_ARROW_CLOSEDF      0    // Closed filled
#define LC_ARROW_CLOSEDB      1    // Closed blank
#define LC_ARROW_CLOSED       2    // Closed
#define LC_ARROW_DOT          3    // Dot
#define LC_ARROW_ARCHTICK     4    // Architectural tick
#define LC_ARROW_OBLIQUE      5    // Oblique
#define LC_ARROW_OPEN         6    // Open
#define LC_ARROW_ORIGIN       7    // Origin indicator
#define LC_ARROW_ORIGIN2      8    // Origin indicator 2
#define LC_ARROW_OPEN90       9    // Right angle
#define LC_ARROW_OPEN30       10   // Open 30
#define LC_ARROW_DOTSMALL     11   // Dot small
#define LC_ARROW_DOTB         12   // Dot blank
#define LC_ARROW_DOTSMALLB    13   // Dot small blank
#define LC_ARROW_BOX          14   // Box
#define LC_ARROW_BOXF         15   // Box filled
#define LC_ARROW_DATUM        16   // Datum triangle
#define LC_ARROW_DATUMF       17   // Datum triangle filled
#define LC_ARROW_INTEGRAL     18   // Integral
#define LC_ARROW_NONE         19   // None


//-----------------------------------------------
// LiteCAD commands (for lcWndExeCommand)
//-----------------------------------------------

// File I/O commands
#define LC_CMD_FILESAVE       1    // Save drawing to file. Call dialog "Save As" if filename is undefined
#define LC_CMD_FILESAVEAS     2    // Call dialog "Save File As"
#define LC_CMD_PRINT          3    // Call dialog "Print"
#define LC_CMD_RASTERIZE      4    // Call dialog "Export to raster image"
#define LC_CMD_FILENEW        5
#define LC_CMD_FILEOPEN       6
#define LC_CMD_FILERECENT     7
#define LC_CMD_FILEINSERT     8

// Display a drawing in design window
#define LC_CMD_VIEW__MIN      401  //------- 1-step view commands until LC_CMD_VIEWEND
#define LC_CMD_ZOOM_IN        401  // Enlarge drawing's view
#define LC_CMD_ZOOM_OUT       402  // Diminish drawing's view
#define LC_CMD_ZOOM_EXT       403  // Zoom on drawing's extents
#define LC_CMD_ZOOM_PAGE      404  // Zoom on paper sheet (only for "Paper Space" view)
#define LC_CMD_ZOOM_PREV      405  // Display the previous view
#define LC_CMD_ZOOM_LIM       406  // Zoom on limits rect
#define LC_CMD_PAN_LEFT       407  // Shift drawing to the left
#define LC_CMD_PAN_RIGHT      408  // Shift drawing to the right
#define LC_CMD_PAN_UP         409  // Shift drawing upward
#define LC_CMD_PAN_DOWN       410  // Shift drawing downward
#define LC_CMD_VIEW__MAX      410  //------------------------------------------
#define LC_CMD_ZOOM_WIN       421  // Zoom drawing using the Zoom rectangle (Zoom Box)
#define LC_CMD_ZOOM_RECT      421  // same as LC_CMD_ZOOM_WIN
#define LC_CMD_ZOOM_SEL       422  // Zoom on selected entities
#define LC_CMD_PAGENEXT       423  // Display next layout
#define LC_CMD_PAGEPREV       424  // Display previous layout
#define LC_CMD_PAGEMODEL      425  // Display "Model Space" layout
#define LC_CMD_PAGEVPORT      426  // Display layout of active viewport (called by popup menu on AVP)
#define LC_CMD_VP_ACT         427  // activate viewport
#define LC_CMD_VP_DEACT       428  // deactivate viewport
#define LC_CMD_MAG__MIN       431  //------------------------------------------
#define LC_CMD_MAGON          431  // magnifier ON
#define LC_CMD_MAGOFF         432  // magnifier OFF
#define LC_CMD_MAGPRM         433  // magnifier parameters  
#define LC_CMD_MAGZOOM4       434  //
#define LC_CMD_MAGZOOM6       435  //
#define LC_CMD_MAGZOOM8       436  //
#define LC_CMD_MAGZOOM10      437  //
#define LC_CMD_MAGZOOM12      438  //
#define LC_CMD_MAGZOOM14      439  //
#define LC_CMD_MAG__MAX       439  //------------------------------------------

// Miscellaneous 
#define LC_CMD_GRID           101  // Call dialog "Coordinate Grid"
#define LC_CMD_OSNAP          102  // Call dialog "Object Snap"
#define LC_CMD_PTRACK         103  // Call dialog "Polar Tracking"
#define LC_CMD_SELOPTS        104  // Call dialog "Selection Options"
#define LC_CMD_QSELECT        105
#define LC_CMD_KBMOVE         106   // move entities by keyboard
#define LC_CMD_DIST           111
#define LC_CMD_AREA           112
#define LC_CMD_WORKFIELD      113  // switch "WorkField" mode
#define LC_CMD_WORKFIELDPRM   114  // WorkField parameters
#define LC_CMD_JUMPLINES      115
#define LC_CMD_TSP2           116
#define LC_CMD_LIMITS         117   // Call dialog "Limits"
#define LC_CMD_SAVESTR        118   // save original strings into LNG file
#define LC_CMD_DELDUPVER      119   // delete duplicate vertices
#define LC_CMD_DELEXVER       120   // delete extra vertices (Coarse polyline)
#define LC_CMD_PLSEP          121   // separate polyline paths
#define LC_CMD_PLPATH         122   // make multipath polyline
#define LC_CMD_SAVECONT       131   // save contours file (Andreas Reitz)
#define LC_CMD_MARKADD        132   // add marker (see LC_PROP_DRW_MARKADD)
#define LC_CMD_MARKVIEW       133   // enable view markers (see LC_PROP_DRW_MARKVIEW)
#define LC_CMD_MARKEDIT       134   // enable snap to markers (see LC_PROP_DRW_MARKEDIT)
#define LC_CMD_HELP           1001  // Display Context Help
#define LC_CMD_RESET          1003  // Cancel currently active command, de-select all entities, redraw drawing

// Add entities
#define LC_CMD_POINT          201   // Draw Point
#define LC_CMD_LINE           202   // Draw Line
#define LC_LINE_SERIAL        1     //   serial lines
#define LC_LINE_SEPARATE      2     //   separate lines
#define LC_CMD_XLINE          203   // Draw Construction Line
#define LC_XLINE_BASE         1     //   basepoint
#define LC_XLINE_ANG          2     //   angular lines (preset by LC_PROP_WND_XLINEANG)
#define LC_XLINE_SEP          3     //   separate 2-point lines
#define LC_XLINE_RAY          4     //   select ray
#define LC_XLINE_XLINE        5     //   select xline
#define LC_CMD_POLYLINE       205   // Draw Polyline
#define LC_CMD_PLINE          205   //   same as LC_CMD_POLYLINE
#define LC_CMD_SPLINE         206   // Draw Spline (polyline with FitType=LC_PLFIT_SPLINE)
#define LC_CMD_RPOLYGON       207   // Draw regular polygon
#define LC_CMD_RECT           208   // Draw Rectangle
#define LC_RECT_2P            1     //   2 points
#define LC_RECT_3P            2     //   3 points
#define LC_RECT_CSA           3     //   Center, Size, Angle
#define LC_CMD_CIRCLE         209   // Draw Circle
#define LC_CIRCLE_CR          1     //   Center, Radius
#define LC_CIRCLE_2P          2     //   2 points
#define LC_CIRCLE_3P          3     //   3 points
#define LC_CMD_ARC            210   // Draw Arc
#define LC_ARC_SME            1     //   Start, Middle, End
#define LC_ARC_SEM            2     //   Start, End, Middle
#define LC_ARC_SEC            3     //   Start, End, Center
#define LC_ARC_SED            4     //   Start, End, Direction
#define LC_ARC_CSE            5     //   Center, Start, End
#define LC_ARC_CONT           6     //   Continue
#define LC_CMD_ELLIPSE        211   // Draw Ellipse
#define LC_ELL_AX             1     //   Axis, End
#define LC_ELL_CEN            2     //   Center
#define LC_ELL_RECT           3     //   By Rectangle
#define LC_CMD_TEXT           212   // Draw Text
#define LC_CMD_ATEXT          213   // Draw Arc Text
#define LC_CMD_ARCTEXT        213   // Draw Arc Text (same as LC_CMD_ATEXT)
#define LC_CMD_MTEXT          214   // Draw Multiline Text
#define LC_CMD_INSERT         216   // Insert a block
#define LC_CMD_BLOCKREF       216   // Insert a block (same as LC_CMD_INSERT)
#define LC_INSERT_DLG         1 
#define LC_INSERT_NODLG       2
#define LC_INSERT_RESET       3
#define LC_CMD_BARCODE        217   // Draw Barcode
#define LC_BARCODE_39         1
#define LC_BARCODE_93         2   
#define LC_BARCODE_128        3   
#define LC_BARCODE_EAN13      4   
#define LC_BARCODE_EAN8       5   
#define LC_BARCODE_ITF        6   
#define LC_BARCODE_MQR        7   
#define LC_BARCODE_QR         8   
#define LC_BARCODE_DMATRIX    9   
#define LC_BARCODE_DM         9   
#define LC_BARCODE_DMATRIXR   10   
#define LC_BARCODE_DMR        10   
#define LC_CMD_DIMLIN         221   // Draw dimension linear
#define LC_CMD_DIMROT         222   // same as LC_CMD_DIMLIN
#define LC_CMD_DIMALI         223   // Draw dimension aligned
#define LC_CMD_DIMORD         224   // Draw dimension ordinate
#define LC_CMD_DIMRAD         225   // Draw dimension radius
#define LC_CMD_DIMDIA         226   // Draw dimension diameter
#define LC_CMD_DIMANG         227   // Draw dimension angular
#define LC_CMD_LEADER         228   // Draw leader
#define LC_CMD_ARROW          231   // Draw arrow
#define LC_CMD_SPIRAL         232   // Draw spiral
#define LC_CMD_HATCH          233   // Draw Hatch
#define LC_CMD_ECW            234   // Insert ECW image
#define LC_CMD_VPORT          235   // Draw viewport
#define LC_CMD_VIEWPORT       235   // Draw viewport (same as LC_CMD_VPORT)
#define LC_CMD_PTARRAY        236   // Insert points array
#define LC_CMD_FACE           238   // Draw 3d face
#define LC_CMD_SHAPE          239   // Create Shape from selected entities

#define LC_CMD_CLRECT         251   // Draw ClipRect
#define LC_CMD_CLRECT_DEL     252   // delete selected ClipRects
#define LC_CMD_CLRECT_DIV     253   // add cliprects by divide workfield
#define LC_CMD_CLRECT_CBCOPY  254   // copy contents of selected cliprect to clipboard
#define LC_CMD_CLRECT_BITMAP  255   // export contents of selected cliprect to bitmap
#define LC_CMD_CLRECT_BITMAP2 256   // export contents of cliprects to bitmaps
#define LC_CMD_CLRECT_HIDE    257   // toggle frag "Hide clip rects when not active"

#define LC_CMD_SW_GRID        1011  // Toggles "Show coordinate grid" mode
#define LC_CMD_SW_GRIDSNAP    1012  // Toggles "Snap to coordinate grid" mode
#define LC_CMD_SW_OSNAP       1014  // Toggles "Object Snap" mode
#define LC_CMD_SW_PTRACK      1015  // Toggles "Polar tracking" mode
#define LC_CMD_SW_POLAR       1015 
#define LC_CMD_SW_ORTHO       1016  // Toggles "Ortho" mode

// Edit operations
#define LC_CMD_CBCUT          301  // Cut entities to clipboard
#define LC_CMD_CBCOPY         302  // Copy entities to clipboard
#define LC_CMD_CBPASTE        303  // Paste entities from clipboard
#define LC_CMD_UNDO           304  // Undo last change
#define LC_CMD_REDO           305  // Reverse last "undo"
#define LC_CMD_COPY           306  // Copy entities
#define LC_COPY_MOVE          1
#define LC_COPY_ROTATE        2
#define LC_COPY_SCALE         3
#define LC_COPY_MIRROR        4
#define LC_COPY_ARRRECT       5
#define LC_COPY_ARRCIRC       6
#define LC_CMD_ERASE          307  // Erase entities
#define LC_CMD_MOVE           308  // Move entities
#define LC_CMD_ROTATE         309  // Rotate entities
#define LC_CMD_SCALE          310  // Scale entities
#define LC_CMD_MIRROR         311  // Mirror entities
#define LC_CMD_EXPLODE        312  // Explode entities
#define LC_CMD_JOIN           314  // Join entities
#define LC_CMD_DEP            315  // delete extra points   // undoc
#define LC_CMD_ORDER          316  // change draw order
#define LC_ORDER_FRONT        1 
#define LC_ORDER_BACK         2 
#define LC_ORDER_ABOVE        3 
#define LC_ORDER_UNDER        4 
#define LC_ORDER_SWAP         5
#define LC_ORDER_SEQUENCE     6
#define LC_CMD_ALIGN          317  // align entities
#define LC_ALIGN_LEFT         1
#define LC_ALIGN_RIGHT        2
#define LC_ALIGN_TOP          3
#define LC_ALIGN_BOTTOM       4
#define LC_ALIGN_CENTER       5
#define LC_ALIGN_CENX         6
#define LC_ALIGN_CENY         7
#define LC_CMD_CLOSEBLOCK     318  // Close Block Editor
#define LC_CMD_BASEPOINT      319  // set block's basepoint 
#define LC_CMD_TRIM           320  // Trim
#define LC_CMD_EXTEND         321  // Extend
#define LC_CMD_OFFSET         322  // Offset
#define LC_CMD_OFFSET_POINT   0 
#define LC_CMD_OFFSET_DIST    1
#define LC_CMD_BREAK          323  // Break
#define LC_CMD_STRETCH        324  // Stretch
#define LC_CMD_FILLET         325  // make fillet for 2 lines
#define LC_CMD_IMGRES         343  // Change Image Resolution
#define LC_CMD_IMGPOS         344  // Set Image Position

// Format 
#define LC_CMD_LAYER          501  // Call dialog "Layers"
#define LC_CMD_LAYERORD       502  // Call dialog "Layers order"
#define LC_CMD_COLOR          503  // Call dialog "Color", CmdPrm: LC_PROP_DRW_COLOR, LC_PROP_DRW_FCOLOR, LC_PROP_ENT_COLOR, LC_PROP_ENT_FCOLOR
#define LC_CMD_FCOLOR         504  // Call dialog "Filling Color"
#define LC_CMD_LINETYPE       505  // Call dialog "Linetypes"
#define LC_CMD_TEXTSTYLE      507  // Call dialog "Text Styles"
#define LC_CMD_BLOCK          508  // Call dialog "Create Block"
#define LC_CMD_CREBLOCK       508  // same as LC_CMD_BLOCK
#define LC_CMD_BLOCKS         509  // Call dialog "Blocks"
#define LC_CMD_IMAGE          510  // Call dialog "Image Manager"
#define LC_CMD_PNTSTYLE       511  // Call dialog "Point Style"
#define LC_CMD_DIMSTYLE       512  // Call dialog "Dimension Styles"
#define LC_CMD_MLSTYLE        513  // Call dialog "Multiline Styles"
#define LC_CMD_FILLING        515  // Call dialog "Filling Styles"
#define LC_CMD_LAYOUT         516  // Call dialog "Layouts"
#define LC_CMD_XREFS          517  // Call dialog "Xrefs"
#define LC_CMD_UNITS          521  // Call dialog "Drawing Units"
#define LC_CMD_DRWPRM         522  // Call dialog "Drawing properties"
#define LC_CMD_SYSPRM         523  // Call dialog "System properties"

#define LC_CMDBLOCK_EDIT      32191
#define LC_CMDBLOCK_ATT       32192
#define LC_CMD_EDITSHAPE      32193

#define LC_CMD_GBR_APERTURES  9001
#define LC_CMD_GBR_BITMAP     9002


#define LC_CMD_CUSTOM   30000   // offset for custom commands


//-----------------------------------------------
//  Objects Properties
//-----------------------------------------------

// Global properties
#define LC_PROP_G_REGCODE       1    //  W string; registration code
#define LC_PROP_G_VERSION       2    // R  string; Litecad version
#define LC_PROP_G_MSGTITLE      3    // RW string; title for messages (default "LiteCAD")
#define LC_PROP_G_HELPFILE      10   // RW string; name of help file ("Litecad.chm" by default)
#define LC_PROP_G_DIRDLL        11   // R  string; directory of Litecad.dll
#define LC_PROP_G_DIRFONTS      13   // RW string; directory of font files (*.lcf), by default <LC_PROP_G_DIRDLL>\Fonts
#define LC_PROP_G_DIRLNG        14   // RW string; directory of LNG files, by default <LC_PROP_G_DIRDLL>\Languages
#define LC_PROP_G_DIRTPL        16   // RW string; directory of "New File" templates (*.lcd), by default <LC_PROP_G_DIRDLL>\Templates
#define LC_PROP_G_DIRCFG        17   // RW string; directory of config files (the directory must have write permit), by default <LC_PROP_G_DIRDLL>\Config
#define LC_PROP_G_SAVECFG       18   // RW bool; defines if save config or not
#define LC_PROP_G_ICON16        20   // RW string|handle|int; replaces icon for dialogs
#define LC_PROP_G_ICON32        21   // RW string|handle|int; replaces icon for dialogs
#define LC_PROP_G_RULERBMP      22   // W handle; bitmap for rulers corner
#define LC_PROP_G_DLGVAL        23   // RW string; dialog value for lcDgGetValue
#define LC_PROP_G_STR           24   // RW string; g_PropStr
#define LC_PROP_G_PRNUSEBMP     25   // RW bool; use bitmap for printing
#define LC_PROP_G_PRNBMPFILE    26   // RW string; file to save the print bitmap
#define LC_PROP_G_PNTPIXSIZE    27   // RW bool; meaning of negative PtSize parameter of lcPaint_DrawPoint function, if TRUE - size in pixels, FALSE - % of window height  // undoc
#define LC_PROP_G_GETDELENT     28   // RW bool; controls if lcBlockGetEnt... function will retrieve deleted entities or not
#define LC_PROP_G_SBARHEIGHT    29   // R  bool; StatusBar default height
#define LC_PROP_G_SOLIDBARC     30   // RW bool; draw barcode without filling option
#define LC_PROP_G_FILEPROGRESS  31   // RW bool; Display progress box during file load/save
#define LC_PROP_G_GBRBMPFILE    32   // RW string; filename of bitmap for Gerber file

#define LC_PROP_G_PICKADD       51   // RW bool; Controls whether subsequent selections replace the current selection set or add to 
#define LC_PROP_G_PICKBYRECT    52   // RW bool; Implied windowing for objects selection (AutoCAD PICKAUTO)
#define LC_PROP_G_PICKDRAG      53   // RW bool; Selection Rect: Press and Drag (same as AutoCAD PICKDRAG system variable)
#define LC_PROP_G_PICKBOXSIZE   54   // RW int; Half-size of selecting square, in pixels

#define LC_PROP_G_GRIPSIZE      55   // RW int; Size of grip square, in pixels
#define LC_PROP_G_GRIPCOLORF    56   // RW int; Grips filling color  (COLORREF)
#define LC_PROP_G_GRIPCOLORB    57   // RW int; Grips border color (COLORREF)

#define LC_PROP_G_CAMERA_COUNT  71   // R  int; number of camera devices
#define LC_PROP_G_CAMERA_I      72   // RW int; set camera index
#define LC_PROP_G_CAMERA_NAME   73   // R  string; name of camera by index (LC_PROP_G_CAMERA_I)
#define LC_PROP_G_CAMERA_ON     74   // R  bool; TRUE if camera is connected
#define LC_PROP_G_CAMERA_TIME   75   // RW int; interval between camera shots (msec)
#define LC_PROP_G_CAMERA_WIDTH  76   // R  int; width of camera image (pixels)
#define LC_PROP_G_CAMERA_HEIGHT 77   // R  int; height of camera image (pixels)
#define LC_PROP_G_CAMERA_BITS   78   // R  handle|int; pointer to image bits
#define LC_PROP_G_CAMERA_BPROW  79   // R  int; bytes per row

#define LC_PROP_G_WF_LEFT       80   // RW float; work field Xmin
#define LC_PROP_G_WF_BOTTOM     81   // RW float; work field Ymin
#define LC_PROP_G_WF_WIDTH      82   // RW float; work field Width
#define LC_PROP_G_WF_HEIGHT     83   // RW float; work field Height


#define LC_PROP_G_PTBUFNEWPTS   131  // R  int; number of last added points
#define LC_PROP_G_PTBUFCLR      132  // RW bool; auto clear Ptbuf after draw
#define LC_PROP_G_MPGONCLR      133  // RW bool; auto clear Mpgon after draw

#define LC_PROP_G_TEXT_ALIGN    141  // RW int; LC_TA_LEFBOT, LC_TA_CENBOT, etc
#define LC_PROP_G_TEXT_H        142  // RW float; Text height 
#define LC_PROP_G_TEXT_WS       143  // RW float; Width scale coefficient (0.1 - 10.0)
#define LC_PROP_G_TEXT_CSPACE   144  // RW float; Charspace coefficient (0.0 - 3.0) 
#define LC_PROP_G_TEXT_ANG      145  // RW float; Rotation angle 
#define LC_PROP_G_TEXT_OBL      146  // RW float; Oblique angle 
#define LC_PROP_G_TEXT_UPDOWN   147  // RW bool; Upside-down direction
#define LC_PROP_G_TEXT_BACK     148  // RW bool; Backward direction 
#define LC_PROP_G_TEXT_FILL     149  // RW bool;
#define LC_PROP_G_TEXT_BORDER   150  // RW bool;

#define LC_PROP_G_BARC_CENTER   161  // RW bool; if TRUE - basepoint is a center, FALSE - left bottom corner
#define LC_PROP_G_BARC_ANGLE    162  // RW float; rotation angle around base point
#define LC_PROP_G_BARC_BELOW    163  // RW float; height below baseline (for EAN8, EAN13)
#define LC_PROP_G_BARC_QZONE    164  // RW float; size of quiet space
#define LC_PROP_G_BARC_CHKSUM   165  // RW bool; add checksum digit at the end
#define LC_PROP_G_BARC_ECL      166  // RW int; error correction level (LC_BARC_QRECL_M or other)
#define LC_PROP_G_BARC_INVERT   167  // RW bool; negative filling
#define LC_PROP_G_BARC_WRATIO   168  // RW float; <wide bar> / <narrow bar> (varies from 2.0 to 3.0)
#define LC_PROP_G_BARC_LINEW    169  // RW float; compensation of line width

// lcBlockAddPointTopo

#define LC_PROP_G_BEAMCOLOR0D   191  // RW int; lcPaint_DrawPoint with PtMode=LC_POINT_BEAM1
#define LC_PROP_G_BEAMCOLOR1D   192  // RW int; 
#define LC_PROP_G_BEAMCOLOR2D   193  // RW int; 
#define LC_PROP_G_BEAMCOLOR0U   194  // RW int; lcPaint_DrawPoint with PtMode=LC_POINT_BEAM0
#define LC_PROP_G_BEAMCOLOR1U   195  // RW int; 
#define LC_PROP_G_BEAMCOLOR2U   196  // RW int; 


// Design window
#define LC_PROP_WND__MIN            301
#define LC_PROP_WND_ID              301    // RW int; identifier
#define LC_PROP_WND_WIDTH           302    // R  int; Window's width (pixels)
#define LC_PROP_WND_HEIGHT          303    // R  int; Window's height (pixels)
#define LC_PROP_WND_PIXELSIZE       304    // R  float; Current scale of the drawing in the window, units per pixel
#define LC_PROP_WND_PICKBOXSIZE     305    // R  float; Half-size of selecting square (drawing's units)
#define LC_PROP_WND_CURSORX         306    // R  int|float; Cursor position X (pixels)|Cursor position X (drawing's units)
#define LC_PROP_WND_CURX            306    //    LC_PROP_WND_CURSORX
#define LC_PROP_WND_CURSORY         307    // R  int|float; Cursor position Y (pixels)|Cursor position Y (drawing's units)
#define LC_PROP_WND_CURY            307    // R  LC_PROP_WND_CURSORY
#define LC_PROP_WND_CURLEF          308    // R  float; left side of selecting square, in drawing units
#define LC_PROP_WND_CURBOT          309    // R  float; bottom side of selecting square, in drawing units
#define LC_PROP_WND_CURRIG          310    // R  float; right side of selecting square, in drawing units
#define LC_PROP_WND_CURTOP          311    // R  float; top side of selecting square, in drawing units
#define LC_PROP_WND_XMIN            312    // R  float;
#define LC_PROP_WND_YMIN            313    // R  float;
#define LC_PROP_WND_XMAX            314    // R  float;
#define LC_PROP_WND_YMAX            315    // R  float;
#define LC_PROP_WND_XCEN            316    // R  float;
#define LC_PROP_WND_YCEN            317    // R  float;
#define LC_PROP_WND_DX              318    // R  float;
#define LC_PROP_WND_DY              319    // R  float;
#define LC_PROP_WND_RULERS          320    // RW bool;
#define LC_PROP_WND_SELECT          321    // RW bool; enable/disable to select objects
#define LC_PROP_WND_SELBYRECT       322    // RW bool; Implied Windowing (same as AutoCAD PICKAUTO system variable)
#define LC_PROP_WND_VIEWBLOCK       323    // R  handle; Handle to active block
#define LC_PROP_WND_BLOCK           323    //  same as LC_PROP_WND_VIEWBLOCK
#define LC_PROP_WND_DRW             324    // R  handle; Handle to active drawing
#define LC_PROP_WND_HWND            325    // R  handle; WinAPI handle (HWND)
#define LC_PROP_WND_HASFOCUS        326    // R  bool; Indication "Has focus"
#define LC_PROP_WND_WORKFIELD       327    // RW bool; display work field and clip rects
#define LC_PROP_WND_CLRHIDE         328    // RW bool; hide cliprects when not active
#define LC_PROP_WND_JUMPLINES       329    // RW bool; display jump lines
#define LC_PROP_WND_MAGNIFIER       330    // RW bool; display magnifier at window rig-bot corner
#define LC_PROP_WND_COLORBG         331    // RW int; background color
#define LC_PROP_WND_COLORCURSOR     332    // RW int; cursor color
#define LC_PROP_WND_COLORFORE       333    // RW int; foreground color
#define LC_PROP_WND_COLORINFBG      334    // RW int; info box background color
#define LC_PROP_WND_COLORINFBORD    335    // RW int; info box border color
#define LC_PROP_WND_COLORINFTEXT    336    // RW int; info box text color
#define LC_PROP_WND_CURSORSYS       338    //    same as LC_PROP_WND_CURSORARROW
#define LC_PROP_WND_CURSORARROW     338    // RW bool|int|handle; Enable arrow cursor | set cursor (LC_CURSOR_ARROW or other)
#define LC_PROP_WND_CURSORCROSS     339    // RW bool; Enable crosshair cursor
#define LC_PROP_WND_CURSORSIZE      340    // RW int; Size of crosshair cursor, % of screen, if negative - size in pixels
#define LC_PROP_WND_COORDS          341    // RW bool; display cursor coords at left-bottom corner
#define LC_PROP_WND_LWMODE          345    // RW int;  line width mode (LC_LW_THIN, LC_LW_REAL, LC_LW_PIXEL)
#define LC_PROP_WND_LWSCALE         346    // RW float; line width screen scale, mm / pixel
#define LC_PROP_WND_BREAKPOINTS     347    // RW bool; display breakpoints
#define LC_PROP_WND_BREAKPTNUMS     348    // RW bool; display numbers of breakpoints
#define LC_PROP_WND_ALPHABLEND      350    // RW bool; enable alpha blend (transparent filling)
#define LC_PROP_WND_STDBLKFRAME     351    // RW bool; draw red frame around the window if standard block is active
#define LC_PROP_WND_SIZE            352    // R  string; window size, pixels (format "%d x %d", PSWidth(), PSHeight() )
#define LC_PROP_WND_DTIME           353    // R  int; redraw time, milliseconds
#define LC_PROP_WND_DRAWPAPER       355    // RW bool; draw paper sheet for "Paper space" blocks
#define LC_PROP_WND_FROZEN          356    // RW bool; "Frozen" mode
#define LC_PROP_WND_COMMAND         357    // R  int|handle|bool; Id of active command | handle to active command | TRUE if has active command
#define LC_PROP_WND_CMD             357    // same as LC_PROP_WND_COMMAND
#define LC_PROP_WND_CMDENT1         358    // RW bool; TRUE - only one entity added by command, FALSE - several entities
#define LC_PROP_WND_OSNAP           359    // RW int|bool; object snap mode  LC_OSNAP_NODE and others | On/Off

#define LC_PROP_WND_GRIDSNAP        370    // RW bool; 
#define LC_PROP_WND_GRIDSHOW        371    // RW bool; Display coordinate grid
#define LC_PROP_WND_GRIDDX          372    // RW float; Grid & snap step
#define LC_PROP_WND_GRIDDY          373    // RW float;
#define LC_PROP_WND_GRIDX0          374    // RW float; Origin point
#define LC_PROP_WND_GRIDY0          375    // RW float;
#define LC_PROP_WND_GRIDBOLDX       376    // RW int; Bold step X
#define LC_PROP_WND_GRIDBOLDY       377    // RW int; Bold step Y
#define LC_PROP_WND_GRIDCOLOR       378    // RW int; Line color
#define LC_PROP_WND_GRIDDOTTED      379    // RW bool; Line is dotted
#define LC_PROP_WND_GRIDCOLOR2      380    // RW int; Bold Line color
#define LC_PROP_WND_GRIDDOTTED2     381    // RW bool; Bold Line is dotted
#define LC_PROP_WND_PANSTEP         390    // RW int; Minimal step, pixels
#define LC_PROP_WND_PANLW           391    // RW bool; optimize line width (draw as 1pix size)
#define LC_PROP_WND_PANIMAGE        392    // RW bool; optimize raster images (draw as hatch)
#define LC_PROP_WND_PANFILL         393    // RW bool; optimize polygon filling (don't fill)
#define LC_PROP_WND_PANPIXSZ        394    // RW bool; reduce resolution (increase pixel size)
#define LC_PROP_WND_MEASCOLORPNT    400    // RW int; COLORREF for points of DIST, AREA tools
#define LC_PROP_WND_MEASCOLORLINE   401    // RW int; COLORREF for lines of DIST, AREA tools
#define LC_PROP_WND_MEASLINESIZE    402    // RW int; line size for DIST, AREA tools
#define LC_PROP_WND_MEASFONTSIZE    403    // RW int; font size
#define LC_PROP_WND_MEASFILLAREA    404    // RW int; fill area polygons with hatch
#define LC_PROP_WND_GBRNLAYERS      421    // R  int; number of loaded gerber files
#define LC_PROP_WND_GBRCLAYER       422    // RW int; index of current gerber file
#define LC_PROP_WND_GBRFILENAME     423    // R  string; name of current gerber file
#define LC_PROP_WND_XLINEANG        424    // RW float; direction angle for command LC_CMD_XLINE
#define LC_PROP_WND__MAX            499

// Font
#define LC_PROP_FONT__MIN           601  
#define LC_PROP_FONT_FILENAME       601    // R  string;  
#define LC_PROP_FONT_NAME           602    // R  string;  
#define LC_PROP_FONT_LCF            603    // R  bool;
#define LC_PROP_FONT_HEIGHT         604    // R  float;  
#define LC_PROP_FONT_FILLED         605    // R  bool;  
#define LC_PROP_FONT_TTF            606    // R  bool;  
#define LC_PROP_FONT_NCHARS         607    // R  int; number of chars in a font 
#define LC_PROP_FONT__MAX           629

// Multipolygon
#define LC_PROP_MPGON__MIN          631    
#define LC_PROP_MPGON_XMIN          631    // R  float; Xmin
#define LC_PROP_MPGON_YMIN          632    // R  float; Ymin
#define LC_PROP_MPGON_XMAX          633    // R  float; Xmax 
#define LC_PROP_MPGON_YMAX          634    // R  float; Ymax
#define LC_PROP_MPGON_XCEN          635    // R  float; X of extents center
#define LC_PROP_MPGON_YCEN          636    // R  float; Y of extents center
#define LC_PROP_MPGON_W             637    // R  float; Width of extents rect
#define LC_PROP_MPGON_H             638    // R  float; Height of extents rect
#define LC_PROP_MPGON__MAX          649

// Triangulated Irregular Network (TIN)
#define LC_PROP_TIN__MIN         1831
#define LC_PROP_TIN_FILENAME     1831  // R  string; model filename
#define LC_PROP_TIN_EMBEDDED     1832  // R  bool;
#define LC_PROP_TIN_XMIN         1835  // R  float; Xmin
#define LC_PROP_TIN_XMAX         1836  // R  float; Xmax
#define LC_PROP_TIN_YMIN         1837  // R  float; Ymin
#define LC_PROP_TIN_YMAX         1838  // R  float; Ymax
#define LC_PROP_TIN_ZMIN         1839  // R  float; Zmin
#define LC_PROP_TIN_ZMAX         1840  // R  float; Zmax
#define LC_PROP_TIN_DX           1841  // R  float; delta X
#define LC_PROP_TIN_DY           1842  // R  float; delta Y
#define LC_PROP_TIN_DZ           1843  // R  float; delta Z
#define LC_PROP_TIN_NPOINTS      1844  // R  int
#define LC_PROP_TIN_NTRIANS      1845  // R  int
#define LC_PROP_TIN_VIEWPT       1851  // RW bool; point
#define LC_PROP_TIN_VIEWPTN      1852  // RW bool; point type name
#define LC_PROP_TIN_VIEWPTI      1853  // RW bool; point index
#define LC_PROP_TIN_VIEWPTZ      1854  // RW bool; point Z
#define LC_PROP_TIN_VIEWTR       1855  // RW bool; triangle
#define LC_PROP_TIN_VIEWTRF      1856  // RW bool; triangle filling
#define LC_PROP_TIN_VIEWTRI      1857  // RW bool; triangle's index
#define LC_PROP_TIN_VIEWTRV      1858  // RW bool; triangle's waterflow vector
#define LC_PROP_TIN_VIEWISO      1859  // RW bool; isolines
#define LC_PROP_TIN_COLPNT       1860  // RW int; default color for points (COLORREF)
#define LC_PROP_TIN_COLTR        1861  // RW int; color for triangle's edges (COLORREF)
#define LC_PROP_TIN_COLTRI       1862  // RW int; color for triangle's index (COLORREF)
#define LC_PROP_TIN_COLTRV       1863  // RW int; color for triangle's vector (COLORREF)
#define LC_PROP_TIN_COLISO       1864  // RW int; color for isolines (COLORREF)
#define LC_PROP_TIN_COLISOB      1865  // RW int; color for bold isolines (COLORREF)
#define LC_PROP_TIN_ISOSTEP      1870  // RW float; Z step of isolines 
#define LC_PROP_TIN_ISOBOLD      1871  // RW int; interval for bold isolined 
#define LC_PROP_TIN_ISOBASE      1872  // RW float; start Z for isoline step
#define LC_PROP_TIN__MAX         1880  

// Grid (by lcGrid... functions)
#define LC_PROP_GRID__MIN        1881
#define LC_PROP_GRID_XMIN        1882  // R  float; Xmin
#define LC_PROP_GRID_XMAX        1883  // R  float; Xmax
#define LC_PROP_GRID_YMIN        1884  // R  float; Ymin
#define LC_PROP_GRID_YMAX        1885  // R  float; Ymax
#define LC_PROP_GRID_W           1886  // R  float; delta X
#define LC_PROP_GRID_H           1887  // R  float; delta Y
#define LC_PROP_GRID_NCELLX      1888  // R  int; number of cells by X
#define LC_PROP_GRID_NCELLY      1889  // R  int; number of cells by Y
#define LC_PROP_GRID__MAX        1900  

// Custom command
#define LC_PROP_CMD__MIN         2001
#define LC_PROP_CMD_ID           2001  // R  int; command identifier LC_CMD_CUSTOM+n
#define LC_PROP_CMD_PARAM        2002  // R  int; parameter passed by lcWndWndCommand
#define LC_PROP_CMD_STEP         2003  // RW int; command step
#define LC_PROP_CMD_LCWND        2004  // R  handle; design window
#define LC_PROP_CMD_HWND         2005  // R  handle; HWND window handle 
#define LC_PROP_CMD_DRW          2006  // R  handle; drawing 
#define LC_PROP_CMD_BLOCK        2007  // R  handle; block 
#define LC_PROP_CMD_CURSORCROSS  2008  // RW bool; Enable crosshair cursor
#define LC_PROP_CMD_INT0         2010  // RW int; user value
#define LC_PROP_CMD_INT1         2011  // RW int; user value
#define LC_PROP_CMD_INT2         2012  // RW int; user value
#define LC_PROP_CMD_INT3         2013  // RW int; user value
#define LC_PROP_CMD_INT4         2014  // RW int; user value
#define LC_PROP_CMD_INT5         2015  // RW int; user value
#define LC_PROP_CMD_FLOAT0       2020  // RW float; user value
#define LC_PROP_CMD_FLOAT1       2021  // RW float; user value
#define LC_PROP_CMD_FLOAT2       2022  // RW float; user value
#define LC_PROP_CMD_FLOAT3       2023  // RW float; user value
#define LC_PROP_CMD_FLOAT4       2024  // RW float; user value
#define LC_PROP_CMD_FLOAT5       2025  // RW float; user value
#define LC_PROP_CMD_HAND0        2030  // RW handle; user value
#define LC_PROP_CMD_HAND1        2031  // RW handle; user value
#define LC_PROP_CMD_HAND2        2032  // RW handle; user value
#define LC_PROP_CMD_HAND3        2033  // RW handle; user value
#define LC_PROP_CMD_HAND4        2034  // RW handle; user value
#define LC_PROP_CMD_HAND5        2035  // RW handle; user value
#define LC_PROP_CMD_STR          2040  // RW string; user value
#define LC_PROP_CMD__MAX         2050

//-----------------------------------------------
// Drawing
//-----------------------------------------------
#define LC_PROP_DRW__MIN            3001
#define LC_PROP_DRW_UID             3001    // R  string; Drawing's Unique Identifier
#define LC_PROP_DRW_FILENAME        3002    // RW string; Drawing's filename
#define LC_PROP_DRW_DESCR           3003    // RW string; drawing's description
#define LC_PROP_DRW_COMMENT         3003    // sane as LC_PROP_DRW_DESCR  
#define LC_PROP_DRW_READONLY        3004    // RW bool; "Readonly" flag
#define LC_PROP_DRW_DIRTY           3005    // RW bool; "Drawing was modified" flag
#define LC_PROP_DRW_IDMAX           3006    // R  int64|string; max Unique Identifier    // undoc
#define LC_PROP_DRW_SYNCZOOM        3011    // RW bool; "Synchronize Layouts zoom" flag
#define LC_PROP_DRW_HASALPHABLEND   3013    // R  bool; true is used alpha blend (transparent filling)

// Background, foreground and cursor colors 
#define LC_PROP_DRW_COLORBACKM      3031    // RW int; background color for Model Space
#define LC_PROP_DRW_COLORBACKP      3032    // RW int; background color for Paper Space
#define LC_PROP_DRW_COLORFOREM      3033    // RW int; foreground color on Model Space
#define LC_PROP_DRW_COLORFOREP      3034    // RW int; foreground color on Paper Space
#define LC_PROP_DRW_COLORCURSORM    3035    // RW int; cursor color on Model Space
#define LC_PROP_DRW_COLORCURSORP    3036    // RW int; cursor color on Paper Space
#define LC_PROP_DRW_COLORPAPER      3037    // RW int; color of paper sheet on Paper Space

// Active objects and parameters, used on creating new entities 
#define LC_PROP_DRW_LAYER           3051    // RW handle|string; Handle to active layer|Name of active layer
#define LC_PROP_DRW_LINETYPE        3052    // RW handle|string; Handle to active linetype|Name of active linetype
#define LC_PROP_DRW_LTSCALE         3053    // RW float; active linetype scale
#define LC_PROP_DRW_TEXTSTYLE       3054    // RW handle|string; Handle to active text style|Name of active text style
#define LC_PROP_DRW_DIMSTYLE        3055    // RW handle|string; Handle to active dim style|Name of active dim style
#define LC_PROP_DRW_PNTSTYLE        3056    // RW handle|string; Handle to active point style|Name of active point style
#define LC_PROP_DRW_MLSTYLE         3057    // RW handle|string; Handle to active mline style|Name of active mline style
#define LC_PROP_DRW_FILLING         3058    // RW handle|string; Handle to active filling|Name of active filling
#define LC_PROP_DRW_BLOCK           3059    // RW handle|string; Handle to active block|Name of active block
#define LC_PROP_DRW_VISBLOCK        3060    // RW handle|string; Handle to currently visible block|Name of currently visible block
#define LC_PROP_DRW_BARTYPE         3061    // RW int; active barcode type, LC_BARTYPE_CODE39 and others
#define LC_PROP_DRW_LWMODE          3062    // RW int;  line width mode (LC_LW_THIN, LC_LW_REAL, LC_LW_PIXEL)
#define LC_PROP_DRW_LWSCALE         3063    // RW float; line width screen scale, mm / pixel
#define LC_PROP_DRW_LWIDTH          3064    // RW int; active Linewidth (for new entities)
#define LC_PROP_DRW_LWDEFAULT       3065    // RW int; Default linewidth (if linewidth==LC_LWIDTH_DEFAULT)

// Active outline color 
#define LC_PROP_DRW_COLOR           3081    // RW string; Active color
#define LC_PROP_DRW_COLORBYLAYER    3082    // RW bool; Color "ByLayer"
#define LC_PROP_DRW_COLORBYBLOCK    3083    // RW bool; Color "ByBlock"
#define LC_PROP_DRW_COLORI          3084    // RW int; R bool; Active Color Index
#define LC_PROP_DRW_COLORT          3085    // RW int; R bool; Active True Color

// Active fill color 
#define LC_PROP_DRW_FCOLOR          3086    // RW string; Active filling color
#define LC_PROP_DRW_FCOLORBYLAYER   3087    // RW bool; filling Color "ByLayer"
#define LC_PROP_DRW_FCOLORBYBLOCK   3088    // RW bool; filling Color "ByBlock"
#define LC_PROP_DRW_FCOLORI         3089    // RW int; R bool; Active filling Color Index
#define LC_PROP_DRW_FCOLORT         3090    // RW int; R bool; Active filling True Color

// Selection 
#define LC_PROP_DRW_SELPENMODE      3101    // RW int; LC_SELPEN_COLOR or other
#define LC_PROP_DRW_SELCOLOR        3102    // RW int; Color of selected entities
#define LC_PROP_DRW_SELCOLOR2       3103    // RW int; BkColor of selected entities
#define LC_PROP_DRW_SELBYLAYER      3104    // RW bool; Select entities only on active layer
#define LC_PROP_DRW_SELINPGON       3105    // RW bool; Select polygons by click on inner area
#define LC_PROP_DRW_SELINPGONF      3106    // RW bool; -/- Only filled polygons
#define LC_PROP_DRW_SELINIMG        3107    // RW bool; Select images by click on inner area
#define LC_PROP_DRW_LOCKSEL         3108    // RW bool; enable selection on locked layers

// Grips
#define LC_PROP_DRW_ENABLEGRIPS     3121    // RW bool; 
#define LC_PROP_DRW_GRIPSLIMIT      3122    // RW int; Max number of selected entities to display grips
#define LC_PROP_DRW_GRIPCOLORF      3123    // RW int; Color of grip filling
#define LC_PROP_DRW_GRIPCOLORB      3124    // RW int; Color of grip border

// Explode options 
#define LC_PROP_DRW_EXPLODEARC      3131    // RW bool; enable exploding of arcs, circles, ellipses
#define LC_PROP_DRW_EXPPLINELA      3132    // RW bool; explode bulge polylines: TRUE-to lines and arcs, FALSE-to lines
#define LC_PROP_DRW_EXPSIMPLINE     3133    // RW bool; explode simple polylines to lines
#define LC_PROP_DRW_EXPTEXTSPLINE   3134    // RW bool; explode TT text to splines (FALSE - to lines)

// Default named objects 
#define LC_PROP_DRW_BLOCK_MODEL     3151    // R  handle; Handle to "*Model_Space" block
#define LC_PROP_DRW_LAYER_0         3152    // R  handle; Handle to layer "0"
#define LC_PROP_DRW_LINETYPE_CONT   3153    // R  handle; Handle to linetype "Continuous"
#define LC_PROP_DRW_LINETYPE_BYLAY  3154    // R  handle; Handle to linetype "ByLayer"
#define LC_PROP_DRW_LINETYPE_BYBLK  3155    // R  handle; Handle to linetype "ByBlock"
#define LC_PROP_DRW_TEXTSTYLE_STD   3156    // R  handle; Handle to text style "Standard"
#define LC_PROP_DRW_TSTYLE_STD      3156    // same as LC_PROP_DRW_TEXTSTYLE_STD
#define LC_PROP_DRW_PNTSTYLE_STD    3157    // R  handle; Handle to point style "Standard"
#define LC_PROP_DRW_DIMSTYLE_STD    3158    // R  handle; Handle to dim style "Standard"
#define LC_PROP_DRW_MLSTYLE_STD     3159    // R  handle; Handle to mline style "Standard"
#define LC_PROP_DRW_FILL_NONE       3160    // R  handle; Handle to filling type "None"
#define LC_PROP_DRW_FILL_SOLID      3161    // R  handle; Handle to filling type "Solid"

// Default resolution 
#define LC_PROP_DRW_RESOLARC        3171    // RW int; default resolution for arc/circle/ellipse/bulge
#define LC_PROP_DRW_RESOLSPLINE     3172    // RW int; default resolution for splines
#define LC_PROP_DRW_RESOLTEXT       3173    // RW int; default resolution for TTF text 

// Limits (also lcDrwSetLimits )
#define LC_PROP_DRW_LIM_MIXPIXSIZE  3181    // RW float; minimal pixel size (drawing units)
#define LC_PROP_DRW_LIM_MAXLEF      3182    // RW float; Xmin of limits rect
#define LC_PROP_DRW_LIM_MAXBOT      3183    // RW float; Ymin of limits rect
#define LC_PROP_DRW_LIM_MAXRIG      3184    // RW float; Xmax of limits rect
#define LC_PROP_DRW_LIM_MAXTOP      3185    // RW float; Ymax of limits rect
#define LC_PROP_DRW_LIM_MAXON       3186    // RW bool; enable max limits

// Markers
#define LC_PROP_DRW_MARKVIEW        3191    // RW bool; markers visibility (see LC_CMD_MARKVIEW)
#define LC_PROP_DRW_MARKADD         3192    // RW bool; can add markers (see LC_CMD_MARKADD)
#define LC_PROP_DRW_MARKEDIT        3193    // RW bool; can edit markers (also snap LC_CMD_MARKEDIT)

// work field
#define LC_PROP_DRW_WF_LEFT         3231    // RW float; work field Xmin
#define LC_PROP_DRW_WF_BOTTOM       3232    // RW float; work field Ymin
#define LC_PROP_DRW_WF_WIDTH        3233    // RW float; work field Width
#define LC_PROP_DRW_WF_HEIGHT       3234    // RW float; work field Height
#define LC_PROP_DRW_WF_HIDE         3235    // RW bool; hide cliprects when not active
#define LC_PROP_DRW_WF_NUMCRECTS    3236    // R  int; number of cliprects
#define LC_PROP_DRW_WF_COLOR        3237    // RW int; string; background color
#define LC_PROP_DRW_WF_COLORCR      3238    // RW int; string; cliprects color
#define LC_PROP_DRW_WF_TEXTSIZE     3239    // RW float; cliprect text size, relative to cliprect height

// User specific data 
#define LC_PROP_DRW_XDATASIZE       3251    // RW int; size of extra data (bytes)     
#define LC_PROP_DRW_XDATA           3252    // RW handle; pointer to extra data       
#define LC_PROP_DRW_INT0            3260    // RW int;   
#define LC_PROP_DRW_INT1            3261    // RW int;   
#define LC_PROP_DRW_INT2            3262    // RW int;   
#define LC_PROP_DRW_INT3            3263    // RW int;   
#define LC_PROP_DRW_INT4            3264    // RW int;   
#define LC_PROP_DRW_INT5            3265    // RW int;   
#define LC_PROP_DRW_INT6            3266    // RW int;   
#define LC_PROP_DRW_INT7            3267    // RW int;   
#define LC_PROP_DRW_INT8            3268    // RW int;   
#define LC_PROP_DRW_INT9            3269    // RW int;   
#define LC_PROP_DRW_FLOAT0          3270    // RW float; 
#define LC_PROP_DRW_FLOAT1          3271    // RW float; 
#define LC_PROP_DRW_FLOAT2          3272    // RW float; 
#define LC_PROP_DRW_FLOAT3          3273    // RW float; 
#define LC_PROP_DRW_FLOAT4          3274    // RW float; 
#define LC_PROP_DRW_FLOAT5          3275    // RW float; 
#define LC_PROP_DRW_FLOAT6          3276    // RW float; 
#define LC_PROP_DRW_FLOAT7          3277    // RW float; 
#define LC_PROP_DRW_FLOAT8          3278    // RW float; 
#define LC_PROP_DRW_FLOAT9          3279    // RW float; 
#define LC_PROP_DRW_STR0            3280    // RW string;
#define LC_PROP_DRW_STR1            3281    // RW string;
#define LC_PROP_DRW_STR2            3282    // RW string;
#define LC_PROP_DRW_STR3            3283    // RW string;
#define LC_PROP_DRW_STR4            3284    // RW string;
#define LC_PROP_DRW_STR5            3285    // RW string;
#define LC_PROP_DRW_STR6            3286    // RW string;
#define LC_PROP_DRW_STR7            3287    // RW string;
#define LC_PROP_DRW_STR8            3288    // RW string;
#define LC_PROP_DRW_STR9            3289    // RW string;
#define LC_PROP_DRW__MAX            3299

//-----------------------------------------------
// Drawing's Tables
//-----------------------------------------------
#define LC_PROP_TABLE__MIN          4000 

// Common properties for tables
#define LC_PROP_TABLE_ID            4001  // R  int64|string; Unique Identifier
#define LC_PROP_TABLE_NAME          4002  // R  string; Table name      
#define LC_PROP_TABLE_DESC          4003  // RW string; Description     
#define LC_PROP_TABLE_DESCR         4003  // RW string; Description     
#define LC_PROP_TABLE_DRW           4004  // R  handle; Handler to owner drawing 
#define LC_PROP_TABLE_DELETED       4005  // R  bool; "Deleted" flag    
#define LC_PROP_TABLE_ODHANDLE      4010  // RW string; used to save DWGdirect handle  // undoc
#define LC_PROP_TABLE_TYPE          4011  // R  int; object type (LC_OBJ_LAYER and others)    
#define LC_PROP_TABLE_PRIORITY      4012  // RW int; priority for sorting   
#define LC_PROP_TABLE_NREFS         4013  // R  int; number of references to a table
#define LC_PROP_TABLE_XDATASIZE     4051  // RW int; size of extra data (bytes)
#define LC_PROP_TABLE_XDATA         4052  // RW handle; pointer to extra data  
#define LC_PROP_TABLE_XSTR          4053  // RW string; user string (uses XDATA buffer) 
#define LC_PROP_TABLE_INT0          4060  // RW int; user value  
#define LC_PROP_TABLE_INT1          4061  // RW int; user value  
#define LC_PROP_TABLE_INT2          4062  // RW int; user value  
#define LC_PROP_TABLE_INT3          4063  // RW int; user value  
#define LC_PROP_TABLE_INT4          4064  // RW int; user value  
#define LC_PROP_TABLE_FLOAT0        4070  // RW float; user value
#define LC_PROP_TABLE_FLOAT1        4071  // RW float; user value
#define LC_PROP_TABLE_FLOAT2        4072  // RW float; user value
#define LC_PROP_TABLE_FLOAT3        4073  // RW float; user value
#define LC_PROP_TABLE_FLOAT4        4074  // RW float; user value
#define LC_PROP_TABLEBASE__MAX      4100

// Layer ----------------------------------------
#define LC_PROP_LAYER_ID            4001  // R  int64|string; Unique Identifier,  same as LC_PROP_TABLE_ID
#define LC_PROP_LAYER_NAME          4002  // RW string; Layer Name,  same as LC_PROP_TABLE_NAME
#define LC_PROP_LAYER_DESC          4003  // RW string; Description, same as LC_PROP_TABLE_DESC
#define LC_PROP_LAYER_DESCR         4003  // RW string; Description
#define LC_PROP_LAYER_DRW           4004  // R  handle; Handle to owner drawing~
#define LC_PROP_LAYER_DELETED       4005  // R  bool; "Deleted" flag
#define LC_PROP_LAYER_COLOR         4101  // RW string; Color
#define LC_PROP_LAYER_COLORI        4102  // RW int; R bool; Color Index
#define LC_PROP_LAYER_COLORT        4103  // RW int; R bool; True Color
#define LC_PROP_LAYER_FCOLOR        4104  // RW string; Filling Color  
#define LC_PROP_LAYER_FCOLORI       4105  // RW int; R bool; Filling Color Index
#define LC_PROP_LAYER_FCOLORT       4106  // RW int; R bool; Filling True Color
#define LC_PROP_LAYER_LINETYPE      4111  // RW handle|string; Handle to Linetype|Name of Linetype
#define LC_PROP_LAYER_LWEIGHT       4112  // RW int; Linewidth
#define LC_PROP_LAYER_LWIDTH        4112  // same as LC_PROP_LAYER_LWEIGHT
#define LC_PROP_LAYER_LOCKED        4113  // RW bool; "No edit" flag
#define LC_PROP_LAYER_NOPRINT       4114  // RW bool; "Not printed" flag
#define LC_PROP_LAYER_VISIBLE       4115  // RW bool; "Visible"; flag
#define LC_PROP_LAYER_0             4116  // R  bool; "Layer 0" flag
#define LC_PROP_LAYER_NODLG         4117  // RW bool; not displayed in the "Layers" dialog 


// Linetype -------------------------------------
#define LC_PROP_LINETYPE_ID         4001  // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_LINETYPE_NAME       4002  // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_LINETYPE_DESC       4003  // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_LINETYPE_DESCR      4003  // RW string; Description
#define LC_PROP_LINETYPE_DRW        4004  // R  handle; Handle to owner drawing~
#define LC_PROP_LINETYPE_DELETED    4005  // R  bool; "Deleted" flag
#define LC_PROP_LINETYPE_DATA       4145  // RW string; Linetype data in text form
#define LC_PROP_LINETYPE_SCALE      4146  // RW float; Global scale for this linetype
#define LC_PROP_LINETYPE_CONTINUOUS 4147  // R  bool; "Continuous" flag
#define LC_PROP_LINETYPE_BYLAYER    4148  // R  bool; "By Layer" flag
#define LC_PROP_LINETYPE_BYBLOCK    4149  // R  bool; "By Block" flag
#define LC_PROP_LINETYPE_STD        4150  // R  bool; standard linetype ("Continuous" or "By Layer" or "By Block")     // undoc
#define LC_PROP_LINETYPE_PATLEN     4151  // R  float; Pattern length
#define LC_PROP_LINETYPE_NELEM      4153  // R  int; number of elements
#define LC_PROP_LINETYPE_IELEM      4154  //  W int; set index of active element
#define LC_PROP_LTELEM_LEN          4155  // R  float; segment length
#define LC_PROP_LTELEM_COMPLEX      4156  // R  bool; TRUE - element contains shape or text
#define LC_PROP_LTELEM_SHAPE        4157  // R  bool; TRUE - text style is used, FALSE - draw only szText[0] and fontfile is used
#define LC_PROP_LTELEM_TEXT         4158  // R  string; Text
#define LC_PROP_LTELEM_STYLE        4159  // R  handle; text style (valid if LC_PROP_LTELEM_SHAPE is FALSE)
#define LC_PROP_LTELEM_FONTNAME     4160  // R  string; fontname (valid if LC_PROP_LTELEM_SHAPE is TRUE)
#define LC_PROP_LTELEM_SCALE        4161  // R  float; shape scale
#define LC_PROP_LTELEM_ANGLE        4162  // R  float; rotation angle in radians for a text element in the linetype
#define LC_PROP_LTELEM_ABSANGLE     4163  // R  bool; if TRUE - RotAngle is absolute 
#define LC_PROP_LTELEM_X            4164  // R  float; x offset of a shape
#define LC_PROP_LTELEM_Y            4165  // R  float; y offset of a shape

// Text style
#define LC_PROP_TSTYLE_ID           4001  // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_TSTYLE_NAME         4002  // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_TSTYLE_DESC         4003  // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_TSTYLE_DESCR        4003  // RW string; Description
#define LC_PROP_TSTYLE_DRW          4004  // R  handle; Handle to owner drawing
#define LC_PROP_TSTYLE_DELETED      4005  // R  bool; "Deleted" flag
#define LC_PROP_TSTYLE_FONT         4175  // RW string; Font filename
#define LC_PROP_TSTYLE_HFONT        4176  // R  handle; Handle to font
#define LC_PROP_TSTYLE_HEIGHT       4177  // RW float; Default height
#define LC_PROP_TSTYLE_WSCALE       4178  // RW float; Default width scale
#define LC_PROP_TSTYLE_OBLIQUE      4179  // RW float; Default obluque angle
#define LC_PROP_TSTYLE_ANGLE        4180  // RW float; Default rotation angle
#define LC_PROP_TSTYLE_ALIGN        4181  // RW int; Default alignment
#define LC_PROP_TSTYLE_UPDOWN       4182  // RW bool; "Upside down" flag
#define LC_PROP_TSTYLE_BACKWARD     4183  // RW bool; "Backward" flag
#define LC_PROP_TSTYLE_LINESPACE    4184  // RW float; Default linespace
#define LC_PROP_TSTYLE_CHARSPACE    4185  // RW float; Default charspace
#define LC_PROP_TSTYLE_STANDARD     4186  // R  bool; "Standard" flag
#define LC_PROP_TSTYLE_SHAPES       4187  // R  bool; "Shapes" flag
#define LC_PROP_TSTYLE_WINFONT      4188  // R  bool; if TRUE - Windows True Type font is used
#define LC_PROP_TSTYLE_SOLID        4189  // RW bool; Solid text
#define LC_PROP_TSTYLE_BOLD         4191  // RW bool; "Bold" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_ITALIC       4192  // RW bool; "Italic" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_UNDERLINE    4193  // RW bool; "Underline" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_STRIKEOUT    4194  // RW bool; "Strikeout" flag (for LC_ENT_TEXTWIN)

// Dimension style
#define LC_PROP_DIMST_ID            4001  // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_DIMST_NAME          4002  // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_DIMST_DESC          4003  // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_DIMST_DESCR         4003  // RW string;
#define LC_PROP_DIMST_DRW           4004  // R  handle;
#define LC_PROP_DIMST_DELETED       4005  // R  bool;
#define LC_PROP_DIMST_STANDARD      4205  // R  bool;
#define LC_PROP_DIMST_ADEC          4211  // RW int; Number of precision places displayed in angular dimensions
#define LC_PROP_DIMST_ASZ           4212  // RW float; Controls dimension arrowhead size and hookline size
#define LC_PROP_DIMST_AUNIT         4213  // RW int; Controls the angle format for angular dimensions
#define LC_PROP_DIMST_AZIN          4214  // RW int; Controls suppression of zeros for angular dimensions
#define LC_PROP_DIMST_BLK1          4215  // RW int|string; arrow1 type
#define LC_PROP_DIMST_BLK2          4216  // RW int|string; arrow2 type
#define LC_PROP_DIMST_CEN           4217  // RW float; Determines style of center marks for arcs or circles being dimensioned
#define LC_PROP_DIMST_CLRD          4218  // RW int; Sets color for dimension leader lines, arrowheads, dimension lines and leaders
#define LC_PROP_DIMST_CLRE          4219  // RW int; Sets color for dimension extension lines
#define LC_PROP_DIMST_CLRT          4220  // RW int; Sets color for dimension text
#define LC_PROP_DIMST_DEC           4221  // RW int; Controls the precision for a primary units dimension's tolerance values
#define LC_PROP_DIMST_DSEP          4222  // RW int; Single-character decimal separator used when creating dimensions whose unit format is decimal
#define LC_PROP_DIMST_EXE           4223  // RW float; Controls extension of extension line beyond dimension line
#define LC_PROP_DIMST_EXO           4224  // RW float; Offset of extension lines from origin points
#define LC_PROP_DIMST_GAP           4225  // RW float; Determines the gap around dimension text when the dimension line is broken to fit the text
#define LC_PROP_DIMST_LDRBLK        4226  // RW int|string; leader arrow type
#define LC_PROP_DIMST_LFAC          4227  // RW float; Global scale factor for linear dimensioning measurements
#define LC_PROP_DIMST_LWD           4228  // RW int; Dimension line lineweight 
#define LC_PROP_DIMST_LWE           4229  // RW int; Extension line lineweight
#define LC_PROP_DIMST_POST          4230  // RW string; Sets a dimension prefix or suffix for the measurement text
#define LC_PROP_DIMST_RND           4231  // RW float; Sets a rounding value for dimensions.
#define LC_PROP_DIMST_SCALE         4232  // RW float; Overall scale factor applied to dimension variables for sizes, distances and offsets
#define LC_PROP_DIMST_TAD           4233  // RW int; Determines text vertical position relative to the dimension line
#define LC_PROP_DIMST_TIH           4234  // RW int; If 1, text between extension lines is always drawn horizontally
#define LC_PROP_DIMST_TXT           4235  // RW float; Dimension text height if the current dimstyle has no fixed text height
#define LC_PROP_DIMST_TXSTY         4236  // RW handle|string; Text style      
#define LC_PROP_DIMST_TSTYLE        4236  //    LC_PROP_DIMST_TXSTY
#define LC_PROP_DIMST_LUNIT         4237  // RW int; Sets units for all dimension types except Angular
#define LC_PROP_DIMST_ZIN           4238  // RW int; Controls the suppression of zeros in the primary unit value

// Point style
#define LC_PROP_PSTYLE_ID           4001  // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_PSTYLE_NAME         4002  // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_PSTYLE_DESC         4003  // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_PSTYLE_DESCR        4003  // RW string;
#define LC_PROP_PSTYLE_DRW          4004  // R  handle;
#define LC_PROP_PSTYLE_DELETED      4005  // R  bool;
#define LC_PROP_PSTYLE_STANDARD     4265  // R  bool;
#define LC_PROP_PSTYLE_BLOCK        4266  // RW handle|string;
#define LC_PROP_PSTYLE_BSCALE       4267  // RW float;
#define LC_PROP_PSTYLE_TSTYLE       4268  // RW handle|string;
#define LC_PROP_PSTYLE_TH           4269  // RW float;
#define LC_PROP_PSTYLE_TWS          4270  // RW float;
#define LC_PROP_PSTYLE_PTMODE       4271  // RW int;  LC_POINT_PIXEL and others
#define LC_PROP_PSTYLE_PTSIZE       4272  // RW float;
#define LC_PROP_PSTYLE_SNAP         4273  // RW bool;
#define LC_PROP_PSTYLE_FIXED        4274  // RW bool;

// Multiline style
#define LC_PROP_MLSTYLE_ID          4001  // R  int64|string; Unique Identifier
#define LC_PROP_MLSTYLE_NAME        4002  // RW string;
#define LC_PROP_MLSTYLE_DESC        4003  // RW string;
#define LC_PROP_MLSTYLE_DESCR       4003  // RW string;
#define LC_PROP_MLSTYLE_DRW         4004  // R  handle; Handle to owner drawing 
#define LC_PROP_MLSTYLE_DELETED     4005  // R  bool;
#define LC_PROP_MLSTYLE_STANDARD    4281  // R  bool;
#define LC_PROP_MLSTYLE_JOINTS      4282  // RW bool; draw joins
#define LC_PROP_MLSTYLE_STARTLINE   4283  // RW bool; draw start line
#define LC_PROP_MLSTYLE_STARTARC    4284  // RW bool; draw start arc
#define LC_PROP_MLSTYLE_ENDLINE     4285  // RW bool; draw end line
#define LC_PROP_MLSTYLE_ENDARC      4286  // RW bool; draw end arc
#define LC_PROP_MLSTYLE_NLINES      4287  // R int; number of lines
#define LC_PROP_MLSTYLE_ILINE       4288  // RW int; index of current line
#define LC_PROP_MLSTYLE_OFFSET      4289  // RW float; offset of current line
#define LC_PROP_MLSTYLE_LTYPE       4290  // RW handle; linetype of current line
#define LC_PROP_MLSTYLE_COLOR       4291  // RW string; color of current line

// Raster image
#define LC_PROP_IMAGE_ID            4001  // R  int; Unique Identifier
#define LC_PROP_IMAGE_NAME          4002  // RW string; Image name 
#define LC_PROP_IMAGE_DESC          4003  // RW string; Image description 
#define LC_PROP_IMAGE_DESCR         4003  // RW string; Image description 
#define LC_PROP_IMAGE_DRW           4004  // R  handle; Handle to owner drawing 
#define LC_PROP_IMAGE_DELETED       4005  // R  bool;
#define LC_PROP_IMAGE_FILENAME      4401  // RW string; Image filename 
#define LC_PROP_IMAGE_SIZE          4402  // R  int;    Image size, bytes 
#define LC_PROP_IMAGE_WPIX          4403  // R  int;    Image width (pixels) 
#define LC_PROP_IMAGE_W             4404
#define LC_PROP_IMAGE_HPIX          4405  // R  int;    Image height (pixels) 
#define LC_PROP_IMAGE_H             4406
#define LC_PROP_IMAGE_CBIT          4407  // R  int;    Color bits 
#define LC_PROP_IMAGE_RGB           4408  // R  bool;   RGB/Palette colors 
#define LC_PROP_IMAGE_EMBEDDED      4409  // RW bool;  saved inside a drawing   
#define LC_PROP_IMAGE_CREATED       4410  // R  bool;  // undoc
#define LC_PROP_IMAGE_COLORS        4411  // RW handle;  pointer to palette memory
#define LC_PROP_IMAGE_BITS          4412  // RW handle;  pointer to points memory 
#define LC_PROP_IMAGE_DIB           4413  // R  handle;

// Filling style
#define LC_PROP_FILL_ID             4001  // R  int64|string; Unique Identifier
#define LC_PROP_FILL_NAME           4002  // RW string;
#define LC_PROP_FILL_DESC           4003  // RW string;
#define LC_PROP_FILL_DESCR          4003  // RW string;
#define LC_PROP_FILL_DRW            4004  // R  handle; Handle to owner drawing 
#define LC_PROP_FILL_DELETED        4005  // R  bool;
#define LC_PROP_FILL_NONE           4501  // R  bool;
#define LC_PROP_FILL_SOLID          4502  // R  bool;
#define LC_PROP_FILL_TYPE           4503  // RW int;

//-----------------------------------------------
// Block
//-----------------------------------------------
#define LC_PROP_BLOCK_ID             4001  // R  int64|string; same as LC_PROP_TABLE_ID
#define LC_PROP_BLOCK_NAME           4002  // RW string; same as LC_PROP_TABLE_NAME
#define LC_PROP_BLOCK_DESC           4003  // RW string; same as LC_PROP_TABLE_DESC
#define LC_PROP_BLOCK_DESCR          4003  // RW string;
#define LC_PROP_BLOCK_DRW            4004  // R  handle; Handle to owner drawing
#define LC_PROP_BLOCK_DELETED        4005  // R  bool;
#define LC_PROP_BLOCK_X              4801  // RW float;
#define LC_PROP_BLOCK_Y              4802  // RW float;
#define LC_PROP_BLOCK_UFSCALING      4803  // RW bool;
#define LC_PROP_BLOCK_UNITS          4804  // RW int;   LC_INSUNIT_UNDEFINED and other
#define LC_PROP_BLOCK_UNITSCALE      4810  // R  float;
#define LC_PROP_BLOCK_MODEL          4811  // R  bool;
#define LC_PROP_BLOCK_PAPER          4812  // R  bool;
#define LC_PROP_BLOCK_LAYOUT         4813  // R  bool;  MODEL or  PAPER
#define LC_PROP_BLOCK_STANDARD       4814  // R  bool;
#define LC_PROP_BLOCK_LAYOUTNAME     4815  // RW string;
#define LC_PROP_BLOCK_LAYOUTODHANDLE 4816  // RW string; used to save DWGdirect handle  // undoc
#define LC_PROP_BLOCK_LAYOUTORDER    4817  // RW int; value used for window tabs order  // undoc
#define LC_PROP_BLOCK_HIDDEN         4818  // R  bool;
#define LC_PROP_BLOCK_DIM            4819  // R  bool;
#define LC_PROP_BLOCK_HATCH          4820  // R  bool;
#define LC_PROP_BLOCK_NOBJ           4821  // R  int; number of graphic objects (not deleted) in the block
#define LC_PROP_BLOCK_NENTS          4821  // R  int; number of graphic objects (not deleted) in the block
#define LC_PROP_BLOCK_NSELOBJ        4822  // R  int; number of selected objects
#define LC_PROP_BLOCK_NSELENTS       4822  // R  int; number of selected objects
#define LC_PROP_BLOCK_ATTRIBS        4827  // R  bool;  "Block has attributes" flag
#define LC_PROP_BLOCK_XMIN           4831  // R  float;
#define LC_PROP_BLOCK_YMIN           4832  // R  float;
#define LC_PROP_BLOCK_XMAX           4833  // R  float;
#define LC_PROP_BLOCK_YMAX           4834  // R  float;
#define LC_PROP_BLOCK_XCEN           4835  // R  float;
#define LC_PROP_BLOCK_YCEN           4836  // R  float;
#define LC_PROP_BLOCK_DX             4837  // R  float;
#define LC_PROP_BLOCK_DY             4838  // R  float;
#define LC_PROP_BLOCK_VISLEF         4839  // R  float; Visible rect
#define LC_PROP_BLOCK_VISBOT         4840  // R  float; Visible rect
#define LC_PROP_BLOCK_VISRIG         4841  // R  float; Visible rect
#define LC_PROP_BLOCK_VISTOP         4842  // R  float; Visible rect
#define LC_PROP_BLOCK_SELXMIN        4843  // R  float; Selection rect
#define LC_PROP_BLOCK_SELYMIN        4844  // R  float;
#define LC_PROP_BLOCK_SELXMAX        4845  // R  float;
#define LC_PROP_BLOCK_SELYMAX        4846  // R  float;
#define LC_PROP_BLOCK_SELXCEN        4847  // R  float;
#define LC_PROP_BLOCK_SELYCEN        4848  // R  float;
#define LC_PROP_PAPER__MIN           4851  // 
#define LC_PROP_PAPER_INCH           4851  // RW bool; original paper units (used when import drawing from DWG)
#define LC_PROP_PAPER_X0             4852  // RW float; X coordinate of paper left-bottom corner 
#define LC_PROP_PAPER_Y0             4853  // RW float; Y coordinate of paper left-bottom corner 
#define LC_PROP_PAPER_SIZE           4854  // R  int; Paper size (LC_PAPER_A0 and others)
#define LC_PROP_PAPER_ORIENT         4855  // R  int; Paper orientation (LC_PAPER_BOOK and others)
#define LC_PROP_PAPER_W              4856  // R  float; Paper width, mm 
#define LC_PROP_PAPER_H              4857  // R  float; Paper height, mm 

#define LC_PROP_TABLE__MAX          4999 

// Entities (properties)
#define LC_PROP_ENT__MIN          5001  // until LC_PROP_ENT__MAX  9999

#define LC_PROP_ENT_ID            5001  // R  int64|string; Unique Identifier
#define LC_PROP_ENT_KEY           5002  // RW int; User value
#define LC_PROP_ENT_COLOR         5003  // RW string|int; Color name | RGB color
#define LC_PROP_ENT_COLORI        5004  // RW int; R bool; Color Index
#define LC_PROP_ENT_COLORT        5005  // RW int; R bool; True Color
#define LC_PROP_ENT_COLORBYLAYER  5006  // RW bool; Color "ByLayer"
#define LC_PROP_ENT_COLORBYBLOCK  5007  // RW bool; Color "ByBlock"
#define LC_PROP_ENT_FILLING       5018  // RW handle|string; Handle to filling type|Name of filling type
#define LC_PROP_ENT_FILLED        5019  // R  bool;
#define LC_PROP_ENT_SOLIDFILL     5021  // RW bool;
#define LC_PROP_ENT_FCOLOR        5008  // RW string|int; Filling Color | RGB color
#define LC_PROP_ENT_FCOLORI       5009  // RW int; R bool; Filling Color Index
#define LC_PROP_ENT_FCOLORT       5010  // RW int; R bool; Filling True Color
#define LC_PROP_ENT_FCOLORBYLAYER 5011  // RW bool; Filling Color "ByLayer"
#define LC_PROP_ENT_FCOLORBYBLOCK 5012  // RW bool; Filling Color "ByBlock"
#define LC_PROP_ENT_FALPHA        5013  // RW int; Filling Color alpha value
#define LC_PROP_ENT_LAYER         5014  // RW handle|string; Handle to Layer|Name of Layer
#define LC_PROP_ENT_LINETYPE      5015  // RW handle|string; Handle to Linetype|Name of Linetype
#define LC_PROP_ENT_LTSCALE       5016  // RW float; Linetype scale
#define LC_PROP_ENT_LWEIGHT       5017  // RW int; Lineweight
#define LC_PROP_ENT_LWIDTH        5017  // same as LC_PROP_ENT_LWEIGHT
#define LC_PROP_ENT_BLOCK         5022  // R  handle|string; Handle to Block|Name of Block
#define LC_PROP_ENT_DRW           5023  // R  handle; Handle to drawing
#define LC_PROP_ENT_LOCKED        5024  // R  bool;
#define LC_PROP_ENT_VISIBLE       5025  // R  bool;
#define LC_PROP_ENT_HIDDEN        5026  // RW bool;
#define LC_PROP_ENT_BLINK         5027  // RW bool;  ???
#define LC_PROP_ENT_TYPE          5028  // R  int;
#define LC_PROP_ENT_DELETED       5029  // RW bool;
#define LC_PROP_ENT_IMMORTAL      5030  // RW bool; can't be deleted
#define LC_PROP_ENT_SELECTED      5031  // R  bool; TRUE if entity is selected
#define LC_PROP_ENT_PRIORITY      5040  // RW int64|string; priority for sorting
#define LC_PROP_ENT_XDATASIZE     5041  // RW int; size of extra data (bytes)
#define LC_PROP_ENT_XDATA         5042  // RW handle; pointer to extra data  
#define LC_PROP_ENT_XSTR          5043  // RW string; user string (uses XDATA buffer) 
#define LC_PROP_ENT_Z             5045  // RW float; Z coord for 2D objects
#define LC_PROP_ENT_XMIN          5046  // R  float; Xmin of entity extents
#define LC_PROP_ENT_YMIN          5047  // R  float; Ymin of entity extents
#define LC_PROP_ENT_XMAX          5048  // R  float; Xmax of entity extents
#define LC_PROP_ENT_YMAX          5049  // R  float; Ymax of entity extents
#define LC_PROP_ENT_XCEN          5050  // R  float; X center of entity
#define LC_PROP_ENT_YCEN          5051  // R  float; Y center of entity
                                  
#define LC_PROP_ENTBASE__MAX      5100

// Point
#define LC_PROP_POINT_STYLE      5101  // RW handle|string; Handle to Point Style|Name of Point Style
#define LC_PROP_POINT_X          5102  // RW float;
#define LC_PROP_POINT_Y          5103  // RW float;
#define LC_PROP_POINT_SIZE       5104  // RW float;
#define LC_PROP_POINT_MODE       5105  // RW int;
#define LC_PROP_POINT_BANGLE     5106  // RW float;
#define LC_PROP_POINT_TDX        5107  // RW float;
#define LC_PROP_POINT_TDY        5108  // RW float;
#define LC_PROP_POINT_TANGLE     5109  // RW float;
#define LC_PROP_POINT_TEXT       5110  // RW string;
#define LC_PROP_POINT_TEXTLEN    5111  // R  int;

// Points array
#define LC_PROP_PTARR_FILENAME   5112  // R  string; full filename (with path)
#define LC_PROP_PTARR_FNAME      5113  // R  string; only filename (without path)
#define LC_PROP_PTARR_DIR        5114  // R  string; file directory
#define LC_PROP_PTARR_LOADED     5115  // R  bool; TRUE if file is loaded
#define LC_PROP_PTARR_NUM        5116  // R  int; number of points
#define LC_PROP_PTARR_NUMVIS     5117  // R  int; number of currently visible points
#define LC_PROP_PTARR_TEXTVLIM   5118  // RW float; text view limit
#define LC_PROP_PTARR_VLIM10     5119  // RW float; view limit 1/10
#define LC_PROP_PTARR_VLIM100    5120  // RW float; view limit 1/100

// Line
#define LC_PROP_LINE_X0          5131  // RW float; Start point X
#define LC_PROP_LINE_Y0          5132  // RW float; Start point Y
#define LC_PROP_LINE_Z0          5133  // RW float; Start point Z
#define LC_PROP_LINE_X1          5134  // RW float; End point X
#define LC_PROP_LINE_Y1          5135  // RW float; End point Y
#define LC_PROP_LINE_Z1          5136  // RW float; End point Z
#define LC_PROP_LINE_DX          5137  // RW float; Delta X
#define LC_PROP_LINE_DY          5138  // RW float; Delta Y
#define LC_PROP_LINE_DZ          5139  // RW float; Delta Z
#define LC_PROP_LINE_ANG         5140  // RW float; Angle 
#define LC_PROP_LINE_LEN         5141  // RW float; Length
#define LC_PROP_LINE_DSARROW0    5142  // RW handle; Dim.style for start arrow
#define LC_PROP_LINE_DSARROW1    5143  // RW handle; Dim.style for end arrow

// Construction Line
#define LC_PROP_XLINE_X0         5151  // RW float; Base point X
#define LC_PROP_XLINE_Y0         5152  // RW float; Base point Y
#define LC_PROP_XLINE_ANG        5154  // RW float; Direction angle
#define LC_PROP_XLINE_DIRX       5155  // R  float; Direction vector X
#define LC_PROP_XLINE_DIRY       5156  // R  float; Direction vector Y
#define LC_PROP_XLINE_RAY        5157  // RW bool; Ray mode

// Circle
#define LC_PROP_CIRCLE_X         5201  // RW float; Center point X
#define LC_PROP_CIRCLE_Y         5202  // RW float; Center point Y
#define LC_PROP_CIRCLE_R         5204  // RW float; Radius
#define LC_PROP_CIRCLE_RAD       5204  // RW float; Radius
#define LC_PROP_CIRCLE_RADIUS    5204  // RW float; Radius
#define LC_PROP_CIRCLE_DIAM      5205  // RW float; Diameter
#define LC_PROP_CIRCLE_LEN       5206  // RW float; Circumference length
#define LC_PROP_CIRCLE_AREA      5207  // RW float; Area
#define LC_PROP_CIRCLE_ANG0      5208  // RW float; start angle
#define LC_PROP_CIRCLE_DIRCW     5209  // RW bool; direction, 1-CW, 0-CCW
#define LC_PROP_CIRCLE_RESOL     5210  // RW int; resolution
#define LC_PROP_CIRC_X           5201  // RW float; Center point X
#define LC_PROP_CIRC_Y           5202  // RW float; Center point Y
#define LC_PROP_CIRC_R           5204  // RW float; Radius
#define LC_PROP_CIRC_RAD         5204  // RW float; Radius
#define LC_PROP_CIRC_RADIUS      5204  // RW float; Radius
#define LC_PROP_CIRC_DIAM        5205  // RW float; Diameter
#define LC_PROP_CIRC_LEN         5206  // RW float; Circumference length
#define LC_PROP_CIRC_AREA        5207  // RW float; Area
#define LC_PROP_CIRC_ANG0        5208  // RW float; start angle
#define LC_PROP_CIRC_DIRCW       5209  // RW bool; direction, 1-CW, 0-CCW
#define LC_PROP_CIRC_RESOL       5210  // RW int; resolution

// Arc
#define LC_PROP_ARC_X            5231  // RW float; Center point X
#define LC_PROP_ARC_Y            5232  // RW float; Center point Y
#define LC_PROP_ARC_R            5234  // RW float; Radius
#define LC_PROP_ARC_RAD          5234  // RW float; Radius
#define LC_PROP_ARC_RADIUS       5234  // RW float; Radius
#define LC_PROP_ARC_ANG0         5235  // RW float; Start angle
#define LC_PROP_ARC_ANGARC       5236  // RW float; Arc included angle
#define LC_PROP_ARC_ANGEND       5237  // R  float; End angle
#define LC_PROP_ARC_X0           5238  // R  float; Start point X
#define LC_PROP_ARC_Y0           5239  // R  float; Start point Y
#define LC_PROP_ARC_XEND         5241  // R  float; End point X
#define LC_PROP_ARC_YEND         5242  // R  float; End point Y
#define LC_PROP_ARC_LEN          5244  // R  float; Length
#define LC_PROP_ARC_CHLEN        5245  // R  float; Chord length
#define LC_PROP_ARC_AREA         5246  // R  float; Area
#define LC_PROP_ARC_CCW          5247  // R  bool; "Counter-ClockWise direction" flag
#define LC_PROP_ARC_SECTOR       5250  // RW bool; Draw as sector
#define LC_PROP_ARC_RESOL        5251  // RW int; resolution

// Ellipse
#define LC_PROP_ELL_X            5261  // RW float; Center point X 
#define LC_PROP_ELL_Y            5262  // RW float; Center point Y 
#define LC_PROP_ELL_R1           5264  // RW float; Radius first 
#define LC_PROP_ELL_R2           5265  // RW float; Radius second 
#define LC_PROP_ELL_RATIO        5266  // RW float; R2/R1
#define LC_PROP_ELL_ANGLE        5267  // RW float; Rotation angle 
#define LC_PROP_ELL_ANG0         5268  // RW float; Start angle (for elliptical arc) 
#define LC_PROP_ELL_ANGARC       5269  // RW float; Arc included angle. Positive - counter-clockwise,
#define LC_PROP_ELL_ANGEND       5270  // R  float; End angle
#define LC_PROP_ELL_X0           5271  // R  float; Start point X
#define LC_PROP_ELL_Y0           5272  // R  float; Start point Y
#define LC_PROP_ELL_XEND         5273  // R  float; End point X
#define LC_PROP_ELL_YEND         5274  // R  float; End point Y
#define LC_PROP_ELL_LEN          5276  // R  float; Length 
#define LC_PROP_ELL_AREA         5277  // R  float; Area 
#define LC_PROP_ELL_FULL         5278  // R  bool;  "Full ellipse" flag 
#define LC_PROP_ELL_CCW          5279  // R  bool;  "CounterClockWise direction" flag 
#define LC_PROP_ELL_SECTOR       5282  // RW bool;  "Draw as sector" flag 
#define LC_PROP_ELL_RESOL        5283  // RW int; resolution
#define LC_PROP_ELL__MAX         5299

// Lightweight Polyline 
#define LC_PROP_PLINE_FIT        5301  // RW int; Fit type
#define LC_PROP_PLINE_CLOSED     5302  // RW bool; Closed polyline
#define LC_PROP_PLINE_NVERS      5303  // R  int; Number of vertices
#define LC_PROP_PLINE_NPATHS     5304  // R  int; Number of paths
#define LC_PROP_PLINE_WIDTH      5305  // RW float|bool; Constant width | Has const width
#define LC_PROP_PLINE_LEN        5306  // R  float; Length
#define LC_PROP_PLINE_AREA       5307  // R  float; Area
#define LC_PROP_PLINE_CW         5308  // R  bool; "ClockWise direction" flag
#define LC_PROP_PLINE_CCW        5309  // R  bool; "Counter-ClockWise direction" flag
#define LC_PROP_PLINE_Z          5310  // RW float; Evevalion (Z)
#define LC_PROP_PLINE_CONSTZ     5311  // R  bool; all vertices have same Z
#define LC_PROP_PLINE_RESOLA     5312  // RW int; resolution for arc segments
#define LC_PROP_PLINE_RESOLS     5313  // RW int; resolution for spline segments
#define LC_PROP_PLINE_RADIUS     5314  // RW float|bool; Constant radius (for rounded polyline) | Has const radius
#define LC_PROP_PLINE_CHAMFER    5315  // RW bool; Chamfer or arc (for rounded polyline)
#define LC_PROP_PLINE_HASANG0    5316  // RW bool; Has start angle (for fit spline)
#define LC_PROP_PLINE_ANG0       5317  // RW float; Start angle (for fit spline)
#define LC_PROP_PLINE_HASANG2    5318  // RW bool; Has end angle (for fit spline)
#define LC_PROP_PLINE_ANG2       5319  // RW float; End angle (for fit spline)

// Multiline Polyline 
#define LC_PROP_MLINE_STYLE      5351  // RW handle|string; Handle to mline style|Name of mline style
#define LC_PROP_MLINE_JUST       5352  // RW int; justification LC_MLINE_TOP and other
#define LC_PROP_MLINE_SCALE      5353  // RW float; mline scale
#define LC_PROP_MLINE_NVERS      5354  // R  int; Number of vertices
#define LC_PROP_MLINE_CLOSED     5355  // RW bool; closed polyline
#define LC_PROP_MLINE_FIT        5356  // RW int; Fit type
#define LC_PROP_MLINE_LEN        5357  // R  float; Length
#define LC_PROP_MLINE_AREA       5358  // R  float; Area

// Rectangle
#define LC_PROP_RECT_X           5371  // RW float; Center X
#define LC_PROP_RECT_Y           5372  // RW float; Center Y 
#define LC_PROP_RECT_W           5374  // RW float; Width 
#define LC_PROP_RECT_H           5375  // RW float; Height 
#define LC_PROP_RECT_ANGLE       5376  // RW float; Rotation angle 
#define LC_PROP_RECT_R           5377  // RW float; Corners radius 
#define LC_PROP_RECT_RAD         5377  // RW float; Corners radius 
#define LC_PROP_RECT_RADIUS      5377  // RW float; Corners radius 
#define LC_PROP_RECT_CHAMFER     5378  // RW bool; Chamfer at corners 
#define LC_PROP_RECT_DIRCW       5379  // RW bool; Clockwise direction
#define LC_PROP_RECT_LEN         5381  // R  float; Perimeter 
#define LC_PROP_RECT_AREA        5382  // R  float; Area 
#define LC_PROP_RECT_RESOL       5383  //

// Clip Rectangle (on Model Space)
#define LC_PROP_CLRECT_ID        5390  // RW int; Identifier
#define LC_PROP_CLRECT_NAME      5391  // RW string; Name
#define LC_PROP_CLRECT_X         5392  // RW float; Center X
#define LC_PROP_CLRECT_Y         5393  // RW float; Center Y 
#define LC_PROP_CLRECT_W         5394  // RW float; Width 
#define LC_PROP_CLRECT_H         5395  // RW float; Height 
#define LC_PROP_CLRECT_ANGLE     5396  // RW float; Rotation angle 
#define LC_PROP_CLRECT_LEN       5398  // R  float; Perimeter 
#define LC_PROP_CLRECT_AREA      5399  // R  float; Area 

// Text (LC_ENT_TEXT)
#define LC_PROP_TEXT_STYLE       5401  // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_TEXT_STR         5402  // RW string; Text content
#define LC_PROP_TEXT_STRT        5403  // R  string; Text content (with translated codes)
#define LC_PROP_TEXT_LEN         5404  // R  int; Number of characters in the Text string
#define LC_PROP_TEXT_ALIGN       5405  // RW int; Alignment type (LC_TA_LEFBOT and others)
#define LC_PROP_TEXT_H           5406  // RW float; Height (0-ByStyle, <0-pixel height, -1-default GUI size) 
#define LC_PROP_TEXT_X           5407  // RW float; Insertion point X
#define LC_PROP_TEXT_Y           5408  // RW float; Insertion point Y
#define LC_PROP_TEXT_DX          5409  // RW int; Offset X (valid if Pixel Height is true)
#define LC_PROP_TEXT_DY          5410  // RW int; Offset Y (valid if Pixel Height is true)
#define LC_PROP_TEXT_WSCALE      5412  // RW float; Width factor (horisontal scale)
#define LC_PROP_TEXT_ANGLE       5413  // RW float; Rotation angle
#define LC_PROP_TEXT_OBLIQUE     5414  // RW float; Oblique angle
#define LC_PROP_TEXT_CHARSPACE   5415  // RW float;
#define LC_PROP_TEXT_WRECT       5416  // R  float; Width of a text bounding rectange
#define LC_PROP_TEXT_X0          5417  // R  float; X coordinate of left-bottom corner
#define LC_PROP_TEXT_Y0          5418  // R  float; Y coordinate of left-bottom corner
#define LC_PROP_TEXT_XFIT        5419  // RW float; 
#define LC_PROP_TEXT_YFIT        5420  // RW float;
#define LC_PROP_TEXT_UPDOWN      5421  // RW bool; Indication "Upside-down text"
#define LC_PROP_TEXT_BACKWARD    5422  // RW bool; Indication "Backward text"
#define LC_PROP_TEXT_RESOL       5423  // RW int; Resolution

// TextWin (LC_ENT_TEXTWIN)

// Multitine Text (LC_ENT_MTEXT)
#define LC_PROP_MTEXT__MIN       5451
#define LC_PROP_MTEXT_STYLE      5451  // RW handle|string;
#define LC_PROP_MTEXT_STR        5452  // RW string;
#define LC_PROP_MTEXT_LEN        5453  // R  int;
#define LC_PROP_MTEXT_ALIGN      5454  // RW int;
#define LC_PROP_MTEXT_X          5455  // RW float;
#define LC_PROP_MTEXT_Y          5456  // RW float;
#define LC_PROP_MTEXT_H          5458  // RW float;
#define LC_PROP_MTEXT_WSCALE     5459  // RW float;
#define LC_PROP_MTEXT_ANGLE      5460  // RW float;
#define LC_PROP_MTEXT_OBLIQUE    5461  // RW float;
#define LC_PROP_MTEXT_WRECT      5462  // R  float;
#define LC_PROP_MTEXT_HRECT      5463  // R  float;
#define LC_PROP_MTEXT_WRAPWIDTH  5464  // RW float;
#define LC_PROP_MTEXT_LINESPACE  5465  // RW float;
#define LC_PROP_MTEXT_CHARSPACE  5466  // RW float;
#define LC_PROP_MTEXT_MIRROR     5467  // RW bool;
#define LC_PROP_MTEXT_RESOL      5468  // RW int; Resolution
#define LC_PROP_MTEXT__MAX       5470

// Arc Text (LC_ENT_ARCTEXT)
#define LC_PROP_ATEXT__MIN       5481
#define LC_PROP_ATEXT_STYLE      5481  // RW handle|string; Text style
#define LC_PROP_ATEXT_STR        5482  // RW string;
#define LC_PROP_ATEXT_STRT       5483  // R  string; Text content (with translated codes)
#define LC_PROP_ATEXT_LEN        5484  // R  int;
#define LC_PROP_ATEXT_X          5485  // RW float; Center X
#define LC_PROP_ATEXT_Y          5486  // RW float; Center Y
#define LC_PROP_ATEXT_R          5487  // RW float; Radius
#define LC_PROP_ATEXT_RAD        5487  // RW float; Radius
#define LC_PROP_ATEXT_RADIUS     5487  // RW float; Radius
#define LC_PROP_ATEXT_ANGLE      5488  // RW float; text Angle
#define LC_PROP_ATEXT_ANGSTA     5489  // R  float; Start angle
#define LC_PROP_ATEXT_ANGEND     5490  // R  float; End angle
#define LC_PROP_ATEXT_CW         5491  // RW bool; Clockwise direction
#define LC_PROP_ATEXT_H          5492  // RW float; Height
#define LC_PROP_ATEXT_WSCALE     5493  // RW float; Width scale
#define LC_PROP_ATEXT_CHARSPACE  5494  // RW float; Charspace
#define LC_PROP_ATEXT_ALIGN      5495  // RW int;
#define LC_PROP_ATEXT_RESOL      5496  // RW int; Resolution
#define LC_PROP_ATEXT__MAX       5499

// Attribute definition & Attribute
#define LC_PROP_ATT_MODE         5501  // RW int; 
#define LC_PROP_ATT_TSTYLE       5502  // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_ATT_TAG          5503  // RW string;
#define LC_PROP_ATT_PROMPT       5504  // RW string;
#define LC_PROP_ATT_DEFVAL       5505  // RW string;
#define LC_PROP_ATT_ALIGN        5506  // RW int; Alignment type
#define LC_PROP_ATT_X            5507  // RW float; Insertion point X
#define LC_PROP_ATT_Y            5508  // RW float; Insertion point Y
#define LC_PROP_ATT_Z            5509  // RW float; Insertion point Z
#define LC_PROP_ATT_H            5510  // RW float; Height
#define LC_PROP_ATT_WSCALE       5511  // RW float; Width factor (horisontal scale)
#define LC_PROP_ATT_ANGLE        5512  // RW float; Rotation angle
#define LC_PROP_ATT_OBLIQUE      5513  // RW float; Oblique angle
#define LC_PROP_ATT_X0           5514  // R  float; X coordinate of left-bottom corner
#define LC_PROP_ATT_Y0           5515  // R  float; Y coordinate of left-bottom corner
#define LC_PROP_ATT_XFIT         5516  // RW float; 
#define LC_PROP_ATT_YFIT         5517  // RW float;
#define LC_PROP_ATT_UPDOWN       5518  // RW bool; Indication "Upside-down text"
#define LC_PROP_ATT_BACKWARD     5519  // RW bool; Indication "Backward text"
#define LC_PROP_ATT_POS          5520  //   for event
#define LC_PROP_ATT_FIT          5521  //   for event

// Block Reference
#define LC_PROP_BLKREF_BLOCK     5531  // RW handle|string; Handle to Block|Name of Block
#define LC_PROP_BLKREF_X         5532  // RW float; Insertion point X
#define LC_PROP_BLKREF_Y         5533  // RW float; Insertion point Y
#define LC_PROP_BLKREF_SCALE     5534  // RW float;
#define LC_PROP_BLKREF_SCX       5535  // RW float;
#define LC_PROP_BLKREF_SCY       5536  // RW float;
#define LC_PROP_BLKREF_UFSCALE   5537  // R  bool;
#define LC_PROP_BLKREF_ANGLE     5538  // RW float;
#define LC_PROP_BLKREF_ARNX      5539  // RW int;
#define LC_PROP_BLKREF_ARDX      5540  // RW float;
#define LC_PROP_BLKREF_ARNY      5541  // RW int;
#define LC_PROP_BLKREF_ARDY      5542  // RW float;
#define LC_PROP_BLKREF_ARANG     5543  // RW float;
#define LC_PROP_BLKREF_ATTRIBS   5544  // R  bool;  "Block has attributes" flag
// only for using with LC_CMD_INSERT
#define LC_PROP_BLKREF_ONS_XY    5545  // RW bool; Specify position on-screen
#define LC_PROP_BLKREF_ONS_SCALE 5546  // RW bool; Specify scale on-screen
#define LC_PROP_BLKREF_ONS_ANGLE 5547  // RW bool; Specify rotation angle on-screen
#define LC_PROP_BLKREF_RETURN    5548  // R  handle; Handle to inserted object (block reference) after  execution

// Raster Image reference
#define LC_PROP_IMGREF_IMAGE     5551  // RW handle|string;  Handle to Image | Name of Image 
#define LC_PROP_IMGREF_XC        5552  // RW float; X coordinate of center point 
#define LC_PROP_IMGREF_YC        5553  // RW float; Y coordinate of center point
#define LC_PROP_IMGREF_W         5554  // RW float; Width 
#define LC_PROP_IMGREF_H         5555  // RW float; Height 
#define LC_PROP_IMGREF_WPIX      5556  // R  int; Image width in pixels
#define LC_PROP_IMGREF_HPIX      5557  // R  int; Image height in pixels 
#define LC_PROP_IMGREF_SCALE     5558  // RW float; uniform scale, units per pixel 
#define LC_PROP_IMGREF_PIXELSIZE 5558  // same as LC_PROP_IMGREF_SCALE
#define LC_PROP_IMGREF_SCALEX    5560  // RW float; X scale, units per pixel 
#define LC_PROP_IMGREF_SCALEY    5561  // RW float; Y scale, units per pixel
#define LC_PROP_IMGREF_SQPIX     5562  // RW bool; if TRUE - uniform scale for puxel
#define LC_PROP_IMGREF_ANGLE     5564  // RW float; rotation angle, around left-bottom corner 
#define LC_PROP_IMGREF_BORDER    5565  // RW bool;  "Draw a border" flag 
#define LC_PROP_IMGREF_TRANSP    5566  // RW int; transparency: 0-none, 1-TransColor, 2-AlphaValue
#define LC_PROP_IMGREF_TRCOLOR   5567  // RW int; transparent color (COLORREF)
#define LC_PROP_IMGREF_TRALPHA   5568  // RW int; alpha value (0-255)
#define LC_PROP_IMGREF_GREY      5569  // RW bool;
#define LC_PROP_IMGREF_FLIPHOR   5570  // RW bool;
#define LC_PROP_IMGREF_FLIPVER   5571  // RW bool;
#define LC_PROP_IMGREF_PATH      5573  // R  string; image full filename
#define LC_PROP_IMGREF_GP_X      5574  // R  float; result of lcImgRefGetPixel
#define LC_PROP_IMGREF_GP_Y      5575  // R  float; result of lcImgRefGetPixel
#define LC_PROP_IMGREF_GP_COLOR  5576  // R  int; result of lcImgRefGetPixel
#define LC_PROP_IMGREF_GP_GRAY   5577  // RW bool; color mode for lcImgRefGetPixel

// ECW / Jpeg2000 Image
#define LC_PROP_ECW_FILENAME     5581  // R  string; Image filename
#define LC_PROP_ECW_LOADED       5582  // R  bool; "Image is loaded" flag 
#define LC_PROP_ECW_WPIX         5589  // R  int; Width (pixels)
#define LC_PROP_ECW_HPIX         5590  // R  int; Height (pixels)
#define LC_PROP_ECW_CBIT         5591  // R  int; Color bits
#define LC_PROP_ECW_XMIN         5583  // R  float; X coordinate of left-bottom corner
#define LC_PROP_ECW_YMIN         5584  // R  float; Y coordinate of left-bottom corner
#define LC_PROP_ECW_XMAX         5585  // R  float; X coordinate of right-top corner
#define LC_PROP_ECW_YMAX         5586  // R  float; Y coordinate of right-top corner
#define LC_PROP_ECW_W            5587  // R  float; Width (drawing units)
#define LC_PROP_ECW_H            5588  // R  float; Height (drawing units)
#define LC_PROP_ECW_SCALEX       5592  // R  float;
#define LC_PROP_ECW_SCALEY       5593  // R  float;
#define LC_PROP_ECW_BORDER       5594  // RW bool; "Draw a border" flag 

// Camera view
#define LC_PROP_CAMERA_X         5601  // RW float; left of camera view rect
#define LC_PROP_CAMERA_Y         5602  // RW float; bottom of camera view rect
#define LC_PROP_CAMERA_W         5603  // RW float; width of camera view rect
#define LC_PROP_CAMERA_H         5604  // RW float; height of camera view rect

// Hatch
#define LC_PROP_HATCH_NAME       5631  // RW string; Pattern name or "SOLID"
#define LC_PROP_HATCH_PATTERN    5632  // RW string; Pattern data for custom pattern
#define LC_PROP_HATCH_SCALE      5633  // RW float; Hatch scale 
#define LC_PROP_HATCH_ANGLE      5634  // RW float; Rotation angle 
#define LC_PROP_HATCH_SIZE       5635  // R  float; Pattern size
#define LC_PROP_HATCH_ASSOC      5636  // RW bool; "Associative hatch" flag 
#define LC_PROP_HATCH_SOLID      5637  // RW bool; Solid fill
#define LC_PROP_HATCH_CUSTOM     5638  // R  bool; Custom pattern
#define LC_PROP_HATCH_NPT        5639  // R  int; number of points
#define LC_PROP_HATCH_NLOOP      5640  // R  int; number of loops
#define LC_PROP_HATCH_NHPL       5641  // R  int; number of pattern lines
#define LC_PROP_HATCH_IHPL       5642  // W  int; set index of active pattern line
#define LC_PROP_HATCH_FALPHA     5643  // RW int; transparency alpha value (only for Solid hatch)
#define LC_PROP_HPL_ANGLE        5651  // R  float;
#define LC_PROP_HPL_X0           5652  // R  float;
#define LC_PROP_HPL_Y0           5653  // R  float;
#define LC_PROP_HPL_DX           5654  // R  float;
#define LC_PROP_HPL_DY           5655  // R  float;
#define LC_PROP_HPL_NDASH        5656  // R  int;
#define LC_PROP_HPL_DASH1        5657  // R  float;
#define LC_PROP_HPL_DASH2        5658  // R  float;
#define LC_PROP_HPL_DASH3        5659  // R  float;
#define LC_PROP_HPL_DASH4        5660  // R  float;
#define LC_PROP_HPL_DASH5        5661  // R  float;
#define LC_PROP_HPL_DASH6        5662  // R  float;
#define LC_PROP_HPL_DASH7        5663  // R  float;
#define LC_PROP_HPL_DASH8        5664  // R  float;

// Viewport on Paper Space
#define LC_PROP_VPORT_LEF        5703  // RW float; Left side
#define LC_PROP_VPORT_BOT        5704  // RW float; Bottom side
#define LC_PROP_VPORT_RIG        5705  //
#define LC_PROP_VPORT_TOP        5706  //
#define LC_PROP_VPORT_BORDER     5707  // RW bool; display border line
#define LC_PROP_VPORT_W          5711  // RW float; Width
#define LC_PROP_VPORT_H          5712  // RW float; Height
#define LC_PROP_VPORT_VX         5713  // RW float; View center X on the projection
#define LC_PROP_VPORT_VY         5714  // RW float; View center Y on the projection
#define LC_PROP_VPORT_VSCALE     5715  // RW float; View scale
#define LC_PROP_VPORT_VANGLE     5716  // RW float; View rotation angle
#define LC_PROP_VPORT_FIXSCALE   5717  // RW bool; fixed scale

// Barcode
#define LC_PROP_BARC_XC          5751  // RW float; Center point X
#define LC_PROP_BARC_X           5751  //  same as LC_PROP_BARC_XC
#define LC_PROP_BARC_YC          5752  // RW float; Center point Y
#define LC_PROP_BARC_Y           5752  //  same as LC_PROP_BARC_YC
#define LC_PROP_BARC_W           5753  // RW float; Width
#define LC_PROP_BARC_H           5754  // RW float; Height
#define LC_PROP_BARC_ANG         5755  // RW float; Rotation angle
#define LC_PROP_BARC_TYPE        5756  // RW int; barcode type, LC_BARTYPE_CODE39 and others
#define LC_PROP_BARC_CODE        5757  // RW string;
#define LC_PROP_BARC_TEXT        5757  // RW string; same as LC_PROP_BARC_CODE
#define LC_PROP_BARC_CHECKSUM    5758  // RW bool; add checksum
#define LC_PROP_BARC_NCHARS      5759  // R  int;
#define LC_PROP_BARC_NUBITS      5760  // R  int; number of unused bits (free bits)
#define LC_PROP_BARC_NARSIZE     5761  // R  float;
#define LC_PROP_BARC_WIDERATIO   5762  // RW float;
#define LC_PROP_BARC_QZONE       5763  // RW float;
#define LC_PROP_BARC_OFFSET      5764  // RW float;
#define LC_PROP_BARC_INVERT      5765  // RW bool;
#define LC_PROP_BARC_HIDETEXT    5766  // RW bool; do not display text
#define LC_PROP_BARC_TSTYLE      5767  // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_BARC_TEXTH       5768  // RW float; text height
#define LC_PROP_BARC_TEXTW       5769  // RW float; text width scale
#define LC_PROP_BARC_TEXTCS      5770  // RW float; text charspace
#define LC_PROP_BARC_TEXTALIGN   5771  // RW int; text alignment
#define LC_PROP_BARC_TEXTRES     5772  // RW int; Resolution (if 0 then use LC_PROP_DRW_RESOLTEXT)
#define LC_PROP_BARC_ECLEVEL     5773  // RW int; error correction level
#define LC_PROP_BARC_MASKPAT     5774  // R  int; mask pattern (0-7)
#define LC_PROP_BARC_SIZE        5775  // R  int|string; size of 2D barcode, H x W, dots
#define LC_PROP_BARC_NBARS       5776  // R  int; same as LC_PROP_BARC_NMODX (for 1D - number of bars)
#define LC_PROP_BARC_NMODX       5776  // R  int; number of horizontal modules
#define LC_PROP_BARC_NMODY       5777  // R  int; number of vertical modules

// Arrow
#define LC_PROP_ARR_X0           5801  // RW float; Start point X
#define LC_PROP_ARR_Y0           5802  // RW float; Start point Y
#define LC_PROP_ARR_X1           5803  // RW float; End point X
#define LC_PROP_ARR_Y1           5804  // RW float; End point Y
#define LC_PROP_ARR_ANG          5805  // RW float; Angle from start to end
#define LC_PROP_ARR_LEN          5806  // RW float; Distance from start to end
#define LC_PROP_ARR_W            5807  // RW float; Width coefficient
#define LC_PROP_ARR_SW           5808  // RW float; Arrow width coef.
#define LC_PROP_ARR_SL           5809  // RW float; Arrow length coef.
#define LC_PROP_ARR_TIME         5810  // RW int; Time
#define LC_PROP_ARR_SHARP        5811  // RW bool; sharp start

// Spiral
#define LC_PROP_SPIR_X           5821  // RW float;
#define LC_PROP_SPIR_Y           5822  // RW float;
#define LC_PROP_SPIR_R           5823  // RW float; radius
#define LC_PROP_SPIR_RADIUS      5823  // RW float; radius
#define LC_PROP_SPIR_R2          5824  // RW float;
#define LC_PROP_SPIR_RATIO       5825  // RW float;
#define LC_PROP_SPIR_ANGLE       5826  // RW float;
#define LC_PROP_SPIR_TURNS       5827  // RW float;
#define LC_PROP_SPIR_DIRCW       5829  // RW bool;
#define LC_PROP_SPIR_CLOSED      5830  // RW bool; TRUE - draw outer corcle
#define LC_PROP_SPIR_DSTEP       5831  // R  float; distance between spiral turns
#define LC_PROP_SPIR_RESOL       5832  // RW int; resolution

// Xref
#define LC_PROP_XREF_FILENAME    5841  // RW string; full Filename (with path)
#define LC_PROP_XREF_FNAME       5842  // RW string; short Filename (without path)
#define LC_PROP_XREF_PATH        5843  // RW string; Path to the Filename
#define LC_PROP_XREF_X           5844  // RW float;
#define LC_PROP_XREF_Y           5845  // RW float;
#define LC_PROP_XREF_SCX         5846  // RW float;
#define LC_PROP_XREF_SCY         5847  // RW float;
#define LC_PROP_XREF_ANGLE       5848  // RW float;

// Dimension
#define LC_PROP_DIM_STYLE        6001  // RW handle|string; Handle to dim style|Name of dim style
#define LC_PROP_DIM_MEAS         6003  // R  float; measured value
#define LC_PROP_DIM_TEXT         6004  // RW string; 

#define LC_PROP_DIMANG_STYLE     6001  
#define LC_PROP_DIMANG_MEAS      6003  
#define LC_PROP_DIMANG_TEXT      6004  

#define LC_PROP_DIMALI_STYLE     6001  
#define LC_PROP_DIMALI_MEAS      6003  
#define LC_PROP_DIMALI_TEXT      6004  

#define LC_PROP_DIMDIA_STYLE     6001
#define LC_PROP_DIMDIA_MEAS      6003
#define LC_PROP_DIMDIA_TEXT      6004

#define LC_PROP_DIMRAD_STYLE     6001
#define LC_PROP_DIMRAD_MEAS      6003
#define LC_PROP_DIMRAD_TEXT      6004

#define LC_PROP_DIMORD_STYLE     6001
#define LC_PROP_DIMORD_MEAS      6003
#define LC_PROP_DIMORD_TEXT      6004

#define LC_PROP_DIMROT_STYLE     6001
#define LC_PROP_DIMROT_MEAS      6003
#define LC_PROP_DIMROT_TEXT      6004
#define LC_PROP_DIMLIN_STYLE     6001
#define LC_PROP_DIMLIN_MEAS      6003
#define LC_PROP_DIMLIN_TEXT      6004

#define LC_PROP_DIMANG__MIN      6011
#define LC_PROP_DIMANG_3PNT      6011  // R  bool; "3 points" mode
#define LC_PROP_DIMANG_2LINE     6012  // R  bool; "2 lines" mode
#define LC_PROP_DIMANG_CPX       6013  // RW float; center point 1
#define LC_PROP_DIMANG_CPY       6014  // RW float; 
#define LC_PROP_DIMANG_DP1X      6015  // RW float; definition point 1
#define LC_PROP_DIMANG_DP1Y      6016  // RW float; 
#define LC_PROP_DIMANG_DP2X      6017  // RW float; definition point 2
#define LC_PROP_DIMANG_DP2Y      6018  // RW float; 
#define LC_PROP_DIMANG_L1P1X     6021  // RW float; line 1 def.point 1
#define LC_PROP_DIMANG_L1P1Y     6022  // RW float; 
#define LC_PROP_DIMANG_L1P2X     6023  // RW float; line 1 def.point 2
#define LC_PROP_DIMANG_L1P2Y     6024  // RW float; 
#define LC_PROP_DIMANG_DP3X      6023
#define LC_PROP_DIMANG_DP3Y      6024
#define LC_PROP_DIMANG_L2P1X     6025  // RW float; line 2 def.point 1
#define LC_PROP_DIMANG_L2P1Y     6026  // RW float; 
#define LC_PROP_DIMANG_L2P2X     6027  // RW float; line 2 def.point 2
#define LC_PROP_DIMANG_L2P2Y     6028  // RW float; 
#define LC_PROP_DIMANG_DP4X      6027
#define LC_PROP_DIMANG_DP4Y      6028
#define LC_PROP_DIMANG_APX       6029  // RW float; arc point X
#define LC_PROP_DIMANG_APY       6030  // RW float; arc point Y
#define LC_PROP_DIMANG_EXT1      6031  // RW bool; visibility of extention line 1
#define LC_PROP_DIMANG_EXT2      6032  // RW bool; visibility of extention line 2
#define LC_PROP_DIMANG_RAD       6033  // R  float; radius of dim arc
#define LC_PROP_DIMANG_TPOS      6034  // RW float; text position on arc
#define LC_PROP_DIMANG__MAX      6050

#define LC_PROP_DIMALI__MIN      6051
#define LC_PROP_DIMALI_DP1X      6051  // RW float; def point 1
#define LC_PROP_DIMALI_DP1Y      6052  // RW float;
#define LC_PROP_DIMALI_DP2X      6053  // RW float; def point 2
#define LC_PROP_DIMALI_DP2Y      6054  // RW float;
#define LC_PROP_DIMALI_TPX       6055  // RW float; text point
#define LC_PROP_DIMALI_TPY       6056  // RW float;
#define LC_PROP_DIMALI__MAX      6069

#define LC_PROP_DIMDIA__MIN      6071
#define LC_PROP_DIMDIA_CPX       6071  // RW float; center point
#define LC_PROP_DIMDIA_CPY       6072  // RW float;
#define LC_PROP_DIMDIA_RPX       6073  // RW float; radial point
#define LC_PROP_DIMDIA_RPY       6074  // RW float;
#define LC_PROP_DIMDIA_FPX       6075  // R  float; far radial point
#define LC_PROP_DIMDIA_FPY       6076  // R  float;
#define LC_PROP_DIMDIA_TPX       6077  // RW float; text point
#define LC_PROP_DIMDIA_TPY       6078  // RW float;
#define LC_PROP_DIMDIA__MAX      6085

#define LC_PROP_DIMRAD__MIN      6086
#define LC_PROP_DIMRAD_CPX       6086  // RW float; center point
#define LC_PROP_DIMRAD_CPY       6087  // RW float;
#define LC_PROP_DIMRAD_RPX       6088  // RW float; radial point
#define LC_PROP_DIMRAD_RPY       6089  // RW float;
#define LC_PROP_DIMRAD_TPX       6090  // RW float; text point
#define LC_PROP_DIMRAD_TPY       6091  // RW float;
#define LC_PROP_DIMRAD__MAX      6099

#define LC_PROP_DIMORD__MIN      6101 
#define LC_PROP_DIMORD_XORD      6101  // RW bool; TRUE - X ordinate, FALSE - Y ordinate
#define LC_PROP_DIMORD_DPX       6102  // RW float; def point
#define LC_PROP_DIMORD_DPY       6103  // RW float; 
#define LC_PROP_DIMORD_TPX       6104  // RW float; text point
#define LC_PROP_DIMORD_TPY       6105  // RW float;
#define LC_PROP_DIMORD__MAX      6119

#define LC_PROP_DIMROT__MIN      6121
#define LC_PROP_DIMROT_ANGLE     6121  // RW float; rotation angle
#define LC_PROP_DIMROT_DP1X      6122  // RW float; def point 1
#define LC_PROP_DIMROT_DP1Y      6123  // RW float;
#define LC_PROP_DIMROT_DP2X      6124  // RW float; def point 2
#define LC_PROP_DIMROT_DP2Y      6125  // RW float;
#define LC_PROP_DIMROT_TPX       6126  // RW float; text point
#define LC_PROP_DIMROT_TPY       6127  // RW float;
#define LC_PROP_DIMROT__MAX      6139

#define LC_PROP_DIMLIN__MIN      6121
#define LC_PROP_DIMLIN_ANGLE     6121  // RW float; rotation angle
#define LC_PROP_DIMLIN_DP1X      6122  // RW float; def point 1
#define LC_PROP_DIMLIN_DP1Y      6123  // RW float;
#define LC_PROP_DIMLIN_DP2X      6124  // RW float; def point 2
#define LC_PROP_DIMLIN_DP2Y      6125  // RW float;
#define LC_PROP_DIMLIN_TPX       6126  // RW float; text point
#define LC_PROP_DIMLIN_TPY       6127  // RW float;
#define LC_PROP_DIMLIN__MAX      6139

// Leader
#define LC_PROP_LEADER_STYLE     6202  // RW handle|string; Handle to dim style|Name of dim style
#define LC_PROP_LEADER_TEXT      6203  // RW string; 
#define LC_PROP_LEADER_ALIGN     6204  // RW int; text alignment (LC_LEADER_TLEFT and other)
#define LC_PROP_LEADER_TPX       6205  // RW float; text center X
#define LC_PROP_LEADER_TPY       6206  // RW float; text center Y
#define LC_PROP_LEADER_APX       6207  // RW float; arrow endpoint X
#define LC_PROP_LEADER_APY       6208  // RW float; arrow endpoint Y
#define LC_PROP_LEADER_P1X       6209  // R  float; land point X
#define LC_PROP_LEADER_P1Y       6210  // R  float; land point Y
#define LC_PROP_LEADER_P0X       6211  // R  float; start point X
#define LC_PROP_LEADER_P0Y       6212  // R  float; start point Y
#define LC_PROP_LEADER_LDIST     6213  // RW float; landing distance
#define LC_PROP_LEADER_VERT      6214  // RW bool; vertical line
#define LC_PROP_LEADER_CORNER    6215  // RW bool; attachment at corner
#define LC_PROP_LEADER_TBW       6216  // R  float; text box width
#define LC_PROP_LEADER_TBH       6217  // R  float; text box height

// 3D face
#define LC_PROP_FACE_X0          6281  // RW float; 1st point X 
#define LC_PROP_FACE_Y0          6282  // RW float; 1st point Y 
#define LC_PROP_FACE_Z0          6283  // RW float; 1st point Z 
#define LC_PROP_FACE_X1          6284  // RW float; 2nd point X 
#define LC_PROP_FACE_Y1          6285  // RW float; 2nd point Y 
#define LC_PROP_FACE_Z1          6286  // RW float; 2nd point Z 
#define LC_PROP_FACE_X2          6287  // RW float; 3rd point X 
#define LC_PROP_FACE_Y2          6288  // RW float; 3rd point Y 
#define LC_PROP_FACE_Z2          6289  // RW float; 3rd point Z 
#define LC_PROP_FACE_X3          6290  // RW float; 4th point X 
#define LC_PROP_FACE_Y3          6291  // RW float; 4th point Y 
#define LC_PROP_FACE_Z3          6292  // RW float; 4th point Z 
#define LC_PROP_FACE_EDGE1       6293  // RW bool; 1st edge visibility
#define LC_PROP_FACE_EDGE2       6294  // RW bool; 2nd edge visibility
#define LC_PROP_FACE_EDGE3       6295  // RW bool; 3rd edge visibility
#define LC_PROP_FACE_EDGE4       6296  // RW bool; 4th edge visibility
#define LC_PROP_FACE_EDGE        6297  // RW int; A combination of LC_FACE_EDGE1INVIS ... constants

// Road Plan
#define LC_PROP_RPLAN_LEN        6301  // R  float;
#define LC_PROP_RPLAN_MARKARC    6302  // RW bool;
#define LC_PROP_RPLAN_MARKSIZE   6303  // RW float;
#define LC_PROP_RPLAN_NVERS      6311  // R  int;
#define LC_PROP_RPLAN_IVER       6312  // RW int;
#define LC_PROP_RPVER__MIN       6313   
#define LC_PROP_RPVER_X          6313  // R  float;
#define LC_PROP_RPVER_Y          6314  // R  float;
#define LC_PROP_RPVER_ANGLE      6315  // R  float;
#define LC_PROP_RPVER_DIRANG     6316  // R  float;
#define LC_PROP_RPVER_R          6317  // R  float;
#define LC_PROP_RPVER_L1         6318  // R  float;
#define LC_PROP_RPVER_L2         6319  // R  float;
#define LC_PROP_RPVER_ANGL1      6320  // R  float;
#define LC_PROP_RPVER_ANGARC     6321  // R  float;
#define LC_PROP_RPVER_ANGL2      6322  // R  float;
#define LC_PROP_RPVER_BISEC      6323  // R  float;
#define LC_PROP_RPVER_ARCLEN     6324  // R  float;
#define LC_PROP_RPVER_CURLEN     6325  // R  float;
#define LC_PROP_RPVER_LINE1      6326  // R  float;
#define LC_PROP_RPVER_T1         6327  // R  float;
#define LC_PROP_RPVER_T2         6328  // R  float;
#define LC_PROP_RPVER_LINE2      6329  // R  float;
#define LC_PROP_RPVER_DIST1      6330  // R  float;
#define LC_PROP_RPVER_DIST2      6331  // R  float;

// Shape
#define LC_PROP_SHAPE_NENTS      6341  // R  int; Number of entities
#define LC_PROP_SHAPE_NPATHS     6342  // R  int; Number of paths

#define LC_PROP_ENT__MAX         9999    // from LC_PROP_ENT__MIN 5001

// Polyline Vertex 
#define LC_PROP_VER__MIN         10001
#define LC_PROP_VER_X            10001  // RW float; Coordinate X~
#define LC_PROP_VER_Y            10002  // RW float; Coordinate Y~
#define LC_PROP_VER_Z            10003  // RW float; Coordinate Y~
#define LC_PROP_VER_ENDPATH      10005  // RW bool; "End of path" flag. Used for multipath polyline.
#define LC_PROP_VER_FIX          10006  // RW bool; "Fixed vertex" flag (for LC_PLFIT_LINQUAD). 
#define LC_PROP_VER_RADIUS       10007  // RW float; Radius value~
#define LC_PROP_VER_WEIGHT       10008  // RW float; point weight
#define LC_PROP_VER_INDEX        10009  // R  int; index of the vertex 
#define LC_PROP_VER_FIRST        10010  // R  bool; TRUE if first vertex
#define LC_PROP_VER_LAST         10011  // R  bool; TRUE if last vertex
// for segment from current to next vertex
#define LC_PROP_VER_W0           10012  // RW float; Start width
#define LC_PROP_VER_W1           10013  // RW float; End width
#define LC_PROP_VER_SEGDX        10014  // RW float; dx
#define LC_PROP_VER_SEGDY        10015  // RW float; dy
#define LC_PROP_VER_SEGANG       10016  // RW float; angle
#define LC_PROP_VER_SEGLEN       10017  // RW float; length
#define LC_PROP_VER_BULGE        10021  // RW float; Bulge value
#define LC_PROP_VER_SEGARCANG    10022  // RW float; included angle of arc segment
#define LC_PROP_VER_SEGARCH      10023  // RW float; height of arc segment
#define LC_PROP_VER_SEGARCLEN    10024  // R  float; length of arc segment 
#define LC_PROP_VER_SEGARCRAD    10025  // R  float; radius of arc segment 
#define LC_PROP_VER__MAX         10040

// Other
#define LC_PROP_OTHER__MIN       11001
#define LC_PROP_PROPWND_ENABLE   11002    // RW bool; Properties window is enabled
#define LC_PROP_PROPWND_DIVCOEF  11003    // RW float; ratio of the name/value columns widths
#define LC_PROP_OTHER__MAX       11999

// event parameters
#define LC_PROP_EVENT__MIN       12001
#define LC_PROP_EVENT_TYPE       12001   // R  int; event type LC_EVENT_HELP and others
#define LC_PROP_EVENT_APPPRM1    12002   // R  int;    application parameter1
#define LC_PROP_EVENT_APPPRM2    12003   // R  handle; application parameter2
#define LC_PROP_EVENT_WND        12004   // R  handle; Window 
#define LC_PROP_EVENT_DRW        12005   // R  handle; Drawing
#define LC_PROP_EVENT_BLOCK      12006   // R  handle; Visible block
#define LC_PROP_EVENT_ENTITY     12007   // R  handle; entity's handle
#define LC_PROP_EVENT_ENT        12007   //    LC_PROP_EVENT_ENTITY
#define LC_PROP_EVENT_HCMD       12008   // R  handle; custom command object
#define LC_PROP_EVENT_HDC        12009   // R  handle; device context (for LC_EVENT_PAINT)
#define LC_PROP_EVENT_MODE       12010   // RW int;
#define LC_PROP_EVENT_INT1       12021   // RW int;
#define LC_PROP_EVENT_INT2       12022   // RW int;
#define LC_PROP_EVENT_INT3       12023   // RW int;
#define LC_PROP_EVENT_INT4       12024   // RW int;
#define LC_PROP_EVENT_INT5       12025   // RW int;
#define LC_PROP_EVENT_INT6       12026   // RW int;
#define LC_PROP_EVENT_FLOAT1     12031   // RW float;
#define LC_PROP_EVENT_FLOAT2     12032   // RW float;
#define LC_PROP_EVENT_FLOAT3     12033   // RW float;
#define LC_PROP_EVENT_FLOAT4     12034   // RW float;
#define LC_PROP_EVENT_FLOAT5     12035   // RW float;
#define LC_PROP_EVENT_FLOAT6     12036   // RW float;
#define LC_PROP_EVENT_STR1       12041   // R  string;
#define LC_PROP_EVENT_STR2       12042   // R  string;
#define LC_PROP_EVENT__MAX       12999


// events
#define LC_EVENT_HELP            101
#define LC_EVENT_PAINT           102
#define LC_EVENT_WNDVIEW         103
#define LC_EVENT_MOUSEMOVE       105
#define LC_EVENT_LBDOWN          106
#define LC_EVENT_LBUP            107
#define LC_EVENT_LBDBLCLK        108
#define LC_EVENT_RBDOWN          109 
#define LC_EVENT_RBUP            110
#define LC_EVENT_KEYDOWN         111
#define LC_EVENT_VIEWBLOCK       112
#define LC_EVENT_EXTENTS         113
#define LC_EVENT_SNAP            114
#define LC_EVENT_MAGNIFIER       115

#define LC_EVENT_FILE            131
#define LC_EVENT_ADDENTITY       132
#define LC_EVENT_ENTPROP         133
#define LC_EVENT_DRWPROP         134
#define LC_EVENT_WNDPROP         135
#define LC_EVENT_SELECT          136
#define LC_EVENT_PICKENT         137
#define LC_EVENT_ADDSTR          138
#define LC_EVENT_ADDCMD          139
#define LC_EVENT_CCMD            140

#define LC_EVENT_SELENT1         161    // undoc
#define LC_EVENT_SELENTS         162    // undoc
#define LC_EVENT_GRIPMOVE        163
#define LC_EVENT_GRIPDRAG        164
#define LC_EVENT_GRIPPAINT       165
#define LC_EVENT_DRAWCURSOR      166
#define LC_EVENT_RULERCORNER     167
#define LC_EVENT_WNDTAB          171
#define LC_EVENT_CMD1            212    // undoc
#define LC_EVENT_LAYERS          303    // undoc

// parameter LC_PROP_EVENT_MODE of LC_EVENT_CCMD
#define LC_CCMD_CREATE      1
#define LC_CCMD_DESTROY     2
#define LC_CCMD_START       3
#define LC_CCMD_FINISH      4
#define LC_CCMD_LBDOWN      5
#define LC_CCMD_LBUP        6
#define LC_CCMD_RBDOWN      7
#define LC_CCMD_RBUP        8
#define LC_CCMD_MOUSEMOVE   9
#define LC_CCMD_PAINT       10
#define LC_CCMD_SNAP        11

/*
#define LC_EVENT_CMDCREATE       201    // undoc
#define LC_EVENT_CMDDESTROY      202    // undoc
#define LC_EVENT_CMDSTART        203    // undoc
#define LC_EVENT_CMDFINISH       204    // undoc
#define LC_EVENT_CMDLBDOWN       205    // undoc
#define LC_EVENT_CMDLBUP         206    // undoc
#define LC_EVENT_CMDRBDOWN       207    // undoc
#define LC_EVENT_CMDRBUP         208    // undoc
#define LC_EVENT_CMDMOUSEMOVE    209    // undoc
#define LC_EVENT_CMDPAINT        210    // undoc
#define LC_EVENT_CMDSNAP         211    // undoc
*/



//*****************************************************************************
//*****************************************************************************
//
//                        LITECAD FUNCTIONS
//
//*****************************************************************************
//*****************************************************************************
#define LCAPI _stdcall 

typedef void (CALLBACK* F_LCEVENT) (HANDLE hEvent);

void LCAPI lcEventSetProc (int EventType, F_LCEVENT pFunc, int Prm1, HANDLE Prm2);
void LCAPI lcEventReturnCode (int code);
BOOL LCAPI lcEventsEnable (BOOL b);

// Initialization
BOOL    LCAPI lcInitialize    ();
BOOL    LCAPI lcUninitialize  (BOOL bSaveConfig);

// GUI strings
BOOL    LCAPI lcStrAdd        (LPCWSTR szTag, LPCWSTR szText); 
BOOL    LCAPI lcStrSet        (LPCWSTR szTag, LPCWSTR szText);
LPCWSTR LCAPI lcStrGet        (LPCWSTR szTag);                   
BOOL    LCAPI lcStrFileLoad   (LPCWSTR szFileName);
BOOL    LCAPI lcStrFileSave   (LPCWSTR szFileName, LPCWSTR szLanguage); 

// Objects properties
BOOL    LCAPI lcPropGetBool   (HANDLE hObject, int idProp);
int     LCAPI lcPropGetInt    (HANDLE hObject, int idProp);
double  LCAPI lcPropGetFloat  (HANDLE hObject, int idProp);
LPCWSTR LCAPI lcPropGetStr    (HANDLE hObject, int idProp);
int     LCAPI lcPropGetStr2   (HANDLE hObject, int idProp);
int     LCAPI lcPropGetChar   (int iChar);
HANDLE  LCAPI lcPropGetHandle (HANDLE hObject, int idProp);
BOOL    LCAPI lcPropPutBool   (HANDLE hObject, int idProp, BOOL bValue);
BOOL    LCAPI lcPropPutInt    (HANDLE hObject, int idProp, int Value);
BOOL    LCAPI lcPropPutFloat  (HANDLE hObject, int idProp, double Value);
BOOL    LCAPI lcPropPutStr    (HANDLE hObject, int idProp, LPCWSTR szValue);
BOOL    LCAPI lcPropPutHandle (HANDLE hObject, int idProp, HANDLE hValue);

// Design window
HANDLE LCAPI lcCreateWindow      (HWND hWndParent, int Style);
BOOL   LCAPI lcDeleteWindow      (HANDLE hLcWnd);
BOOL   LCAPI lcWndResize         (HANDLE hLcWnd, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcWndRedraw         (HANDLE hLcWnd);
BOOL   LCAPI lcWndSetFocus       (HANDLE hLcWnd);
BOOL   LCAPI lcWndSetExtents     (HANDLE hLcWnd, double Xmin, double Ymin, double Xmax, double Ymax);
BOOL   LCAPI lcWndZoomRect       (HANDLE hLcWnd, double Left, double Bottom, double Right, double Top);
BOOL   LCAPI lcWndZoomScale      (HANDLE hLcWnd, double Scal);
BOOL   LCAPI lcWndZoomMove       (HANDLE hLcWnd, double DX, double DY);
BOOL   LCAPI lcWndGetCursorCoord (HANDLE hLcWnd, int* pXwin, int* pYwin, double* pXdrw, double* pYdrw);
BOOL   LCAPI lcWndExeCommand     (HANDLE hLcWnd, int Command, int CmdParam);
BOOL   LCAPI lcWndOnClose        (HANDLE hLcWnd);
BOOL   LCAPI lcWndSetBlock       (HANDLE hLcWnd, HANDLE hBlock);
BOOL   LCAPI lcWndSetProps       (HANDLE hLcWnd, HANDLE hPropWnd);
HANDLE LCAPI lcWndGetEntByPoint  (HANDLE hLcWnd, int Xwin, int Ywin);
HANDLE LCAPI lcWndGetEntByPoint2 (HANDLE hLcWnd, double X, double Y, double Delta);
int    LCAPI lcWndGetEntsByRect  (HANDLE hLcWnd, double Lef, double Bot, double Rig, double Top, BOOL bCross, int nMaxEnts);
HANDLE LCAPI lcWndGetEntity      (int iEnt);
//HANDLE LCAPI lcWndGetEntByID     (HANDLE hLcWnd, int Id);
//HANDLE LCAPI lcWndGetEntByIDH    (HANDLE hLcWnd, LPCWSTR szId);
//HANDLE LCAPI lcWndGetEntByKey    (HANDLE hLcWnd, int Key);
//BOOL   LCAPI lcWndEmulator       (HANDLE hLcWnd, int Mode);
//BOOL   LCAPI lcWndMagnifier      (HANDLE hLcWnd, BOOL bOn, int Width, int Height, int Zoom, int Flags);

// Coordinate convertions
BOOL   LCAPI lcWndCoordFromDrw   (HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwin, int* pYwin);
BOOL   LCAPI lcWndCoordToDrw     (HANDLE hLcWnd, int Xwin, int Ywin, double* pXdrw, double* pYdrw);
BOOL   LCAPI lcCoordDrwToWnd     (HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwnd, int* pYwnd);
BOOL   LCAPI lcCoordWndToDrw     (HANDLE hLcWnd, int Xwnd, int Ywnd, double* pXdrw, double* pYdrw);


// Font functions
HANDLE LCAPI lcFontGetFirst ();
HANDLE LCAPI lcFontGetNext  (HANDLE hFont);
HANDLE LCAPI lcFontAddRes   (LPCWSTR szFontName, HANDLE hModule, int idResource);
HANDLE LCAPI lcFontAddFile  (LPCWSTR szFontName, LPCWSTR szFilename);
HANDLE LCAPI lcFontAddBin   (LPCWSTR szFontName, HANDLE hData);
HANDLE LCAPI lcFontGetChar  (HANDLE hFont, int CharCode);

// Progress indicator
BOOL   LCAPI lcProgressCreate  (HANDLE hLcWnd, int W, int H, LPCWSTR szTitle);
BOOL   LCAPI lcProgressSetText (LPCWSTR szText);
BOOL   LCAPI lcProgressStart   (int MinVal, int MaxVal);
BOOL   LCAPI lcProgressSetPos  (int Val);
BOOL   LCAPI lcProgressInc     ();
BOOL   LCAPI lcProgressDelete  ();

// Quadrangle point coordinates
HANDLE LCAPI lcQuadCreate      ();
BOOL   LCAPI lcQuadDelete      (HANDLE hQuad);
BOOL   LCAPI lcQuadSet         (HANDLE hQuad, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3);
BOOL   LCAPI lcQuadTransXYtoUV (HANDLE hQuad, double X, double Y, double* pU, double* pV);
BOOL   LCAPI lcQuadTransUVtoXY (HANDLE hQuad, double U, double V, double* pX, double* pY);
BOOL   LCAPI lcQuadContains    (HANDLE hQuad, double X, double Y);

HANDLE LCAPI lcGridCreate  ();
BOOL   LCAPI lcGridDelete  (HANDLE hGrid);
BOOL   LCAPI lcGridSet     (HANDLE hGrid, double X0, double Y0, double W, double H, int Nx, int Ny);
BOOL   LCAPI lcGridSetDest (HANDLE hGrid, int Ix, int Iy, double X, double Y);
BOOL   LCAPI lcGridUpdate  (HANDLE hGrid);
BOOL   LCAPI lcGridTrans   (HANDLE hGrid, double X, double Y, double* pXdest, double* pYdest);
BOOL   LCAPI lcGridGetNode (HANDLE hGrid, BOOL bDest, int Ix, int Iy, double* pX, double* pY);
BOOL   LCAPI lcGridGetCell (HANDLE hGrid, double X, double Y, int* pIx, int* pIy);
BOOL   LCAPI lcGridSetView (HANDLE hGrid, int Mode, HANDLE hLcWnd, COLORREF ColLine, COLORREF ColNode);  // Mode: 0-disable, 1-original, 2-destination

// TIN object
HANDLE LCAPI lcTIN_Create        (int Id);
BOOL   LCAPI lcTIN_Delete        (HANDLE hTIN);
BOOL   LCAPI lcTIN_Load          (HANDLE hTIN, LPCWSTR szFileName, HANDLE hWnd);
BOOL   LCAPI lcTIN_GetZ          (HANDLE hTIN, double X, double Y, double* pZ);
int    LCAPI lcTIN_InterLine     (HANDLE hTIN, double X0, double Y0, double X1, double Y1);
BOOL   LCAPI lcTIN_InterGetPoint (HANDLE hTIN, int iPnt, double* pX, double* pY, double* pZ);

// Properties Window
HANDLE LCAPI lcCreateProps (HWND hWndParent);
BOOL   LCAPI lcDeleteProps (HANDLE hPropWnd);
BOOL   LCAPI lcPropsResize (HANDLE hPropWnd, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcPropsUpdate (HANDLE hPropWnd, BOOL bSelChanged);

// Status Bar
HANDLE LCAPI lcCreateStatbar (HWND hWndParent);
BOOL   LCAPI lcDeleteStatbar (HANDLE hStatbar);
BOOL   LCAPI lcStatbarResize (HANDLE hStatbar, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcStatbarCell   (HANDLE hStatbar, int Id, int Pos);
BOOL   LCAPI lcStatbarText   (HANDLE hStatbar, int Id, LPCWSTR szText);
BOOL   LCAPI lcStatbarRedraw (HANDLE hStatbar);

// utility functions
BOOL    LCAPI lcDgGetValue    (HANDLE hWnd, int Lef, int Top, LPCWSTR szTitle, LPCWSTR szPrompt);
BOOL    LCAPI lcHelp          (LPCWSTR szTopic);
void    LCAPI lcGetPolarPoint (double x0, double y0, double Angle, double Dist, double* pOutX, double* pOutY);
void    LCAPI lcGetPolarPrm   (double x1, double y1, double x2, double y2, double* pAngle, double* pDist);
BOOL    LCAPI lcGetClientSize (HWND hWnd, int* pWidth, int* pHeight);
int     LCAPI lcGetErrorCode  ();
LPCWSTR LCAPI lcGetErrorStr   ();

// Custom command interface
HANDLE LCAPI lcCreateCommand  (HANDLE hLcWnd, int Id, LPCWSTR szTitle);
BOOL   LCAPI lcCmdExit        (HANDLE hCmd);
BOOL   LCAPI lcCmdCursorText  (HANDLE hCmd, LPCWSTR szText);
BOOL   LCAPI lcCmdMessage     (HANDLE hCmd, LPCWSTR szText, int IconType);
BOOL   LCAPI lcCmdResetLastPt (HANDLE hCmd);

BOOL LCAPI lcCameraConnect     (LPCWSTR szName);  // LC_PROP_G_CAMERA_COUNT
BOOL LCAPI lcCameraDisconnect  ();
BOOL LCAPI lcCameraShot        ();


//-----------------------------------------------------------------------------
// Drawing
//-----------------------------------------------------------------------------
HANDLE LCAPI lcCreateDrawing      ();
BOOL   LCAPI lcDeleteDrawing      (HANDLE hDrw);
BOOL   LCAPI lcDrwNew             (HANDLE hDrw, LPCWSTR szFileName, HANDLE hLcWnd);
BOOL   LCAPI lcDrwLoad            (HANDLE hDrw, LPCWSTR szFileName, HANDLE hLcWnd);
BOOL   LCAPI lcDrwLoadMem         (HANDLE hDrw, HANDLE hMem, HANDLE hLcWnd);
BOOL   LCAPI lcDrwInsert          (HANDLE hDrw, LPCWSTR szFileName, int Overwrite, HANDLE hLcWnd);
BOOL   LCAPI lcDrwCopy            (HANDLE hDrw, HANDLE hDrwSrc);
BOOL   LCAPI lcDrwSave            (HANDLE hDrw, LPCWSTR szFileName, BOOL bBak, HANDLE hLcWnd); 
int    LCAPI lcDrwSaveMem         (HANDLE hDrw, HANDLE hMem, int MemSize); 

HANDLE LCAPI lcDrwAddLayer        (HANDLE hDrw, LPCWSTR szName, LPCWSTR szColor, HANDLE hLtype, int Lwidth);
HANDLE LCAPI lcDrwAddLinetype     (HANDLE hDrw, LPCWSTR szName, LPCWSTR szDefinition);
HANDLE LCAPI lcDrwAddLinetypeF    (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, LPCWSTR szLtypeName);
HANDLE LCAPI lcDrwAddTextStyle    (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFontName, BOOL bWinFont);
HANDLE LCAPI lcDrwAddDimStyle     (HANDLE hDrw, LPCWSTR szName);
HANDLE LCAPI lcDrwAddMlineStyle   (HANDLE hDrw, LPCWSTR szName);
HANDLE LCAPI lcDrwAddPntStyle     (HANDLE hDrw, LPCWSTR szName, HANDLE hBlock, double BlockScale, HANDLE hTStyle, double TextHeight, double TextWidth);
HANDLE LCAPI lcDrwAddImage        (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName);
HANDLE LCAPI lcDrwAddImage2       (HANDLE hDrw, LPCWSTR szName, int Width, int Height, int nBits);
HANDLE LCAPI lcDrwAddImage3       (HANDLE hDrw, LPCWSTR szName, HANDLE hMem);
HANDLE LCAPI lcDrwAddBlock        (HANDLE hDrw, LPCWSTR szName, double X, double Y);
HANDLE LCAPI lcDrwAddBlockFromFile (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent); 
HANDLE LCAPI lcDrwAddBlockFromDrw (HANDLE hDrw, LPCWSTR szName, HANDLE hDrw2, int Overwrite, HWND hwParent);
HANDLE LCAPI lcDrwAddBlockFile    (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent);
HANDLE LCAPI lcDrwAddBlockPaper   (HANDLE hDrw, LPCWSTR szName, int PaperSize, int Orient, double Width, double Height);
HANDLE LCAPI lcDrwAddBlockCopy    (HANDLE hDrw, LPCWSTR szName, HANDLE hSrcBlock); 

BOOL   LCAPI lcDrwDeleteObject    (HANDLE hDrw, HANDLE hObject);
int    LCAPI lcDrwDeleteUnused    (HANDLE hDrw, int ObjType);    // undoc
int    LCAPI lcDrwCountObjects    (HANDLE hDrw, int ObjType);
BOOL   LCAPI lcDrwSortObjects     (HANDLE hDrw, int ObjType);

HANDLE LCAPI lcDrwGetFirstObject  (HANDLE hDrw, int ObjType);
HANDLE LCAPI lcDrwGetNextObject   (HANDLE hDrw, HANDLE hObject);
HANDLE LCAPI lcDrwGetObjectByID   (HANDLE hDrw, int ObjType, int Id);
HANDLE LCAPI lcDrwGetObjectByIDH  (HANDLE hDrw, int ObjType, LPCWSTR szId);
HANDLE LCAPI lcDrwGetObjectByName (HANDLE hDrw, int ObjType, LPCWSTR szName);
HANDLE LCAPI lcDrwGetEntByID      (HANDLE hDrw, int Id);
HANDLE LCAPI lcDrwGetEntByIDH     (HANDLE hDrw, LPCWSTR szId);
HANDLE LCAPI lcDrwGetEntByKey     (HANDLE hDrw, int Key);

BOOL   LCAPI lcDrwClearXData      (HANDLE hDrw, int ObjType, int Mode);
BOOL   LCAPI lcDrwPurge           (HANDLE hDrw);
BOOL   LCAPI lcDrwExplode         (HANDLE hDrw, int Mode);
//BOOL   LCAPI lcDrwSetLimits       (HANDLE hDrw, double Xmin, double Ymin, double Xmax, double Ymax);

BOOL   LCAPI lcDrwUndoRecord      (HANDLE hDrw, int Mode); 
BOOL   LCAPI lcDrwUndo            (HANDLE hDrw, BOOL bRedo);

// Block
BOOL   LCAPI lcBlockSetViewRect  (HANDLE hBlock, double Xcen, double Ycen, double Width, double Height);
BOOL   LCAPI lcBlockSetViewRect2 (HANDLE hBlock, double Lef, double Bot, double Rig, double Top);
BOOL   LCAPI lcBlockSetPaperSize (HANDLE hBlock, int PaperSize, int Orient, double Width, double Height);
BOOL   LCAPI lcBlockRasterize    (HANDLE hBlock, LPCWSTR szFileName, double Xmin, double Ymin, double Xmax, double Ymax, int ImgW, int ImgH);
BOOL   LCAPI lcBlockUpdate       (HANDLE hBlock, BOOL bUpdEnts, HANDLE hNewEnt);
BOOL   LCAPI lcBlockScale        (HANDLE hBlock, double Scale);

// Add graphic objects into a block
BOOL   LCAPI lcBlockClear       (HANDLE hBlock, HANDLE hLayer);
BOOL   LCAPI lcBlockPurge       (HANDLE hBlock);
BOOL   LCAPI lcBlockSortEnts    (HANDLE hBlock, BOOL bByLayers, HWND hWnd);
HANDLE LCAPI lcBlockAddPoint    (HANDLE hBlock, double X, double Y);
HANDLE LCAPI lcBlockAddPoint2   (HANDLE hBlock, double X, double Y, int PtMode, double PtSize);
//HANDLE LCAPI lcBlockAddPtArray  (HANDLE hBlock, LPCWSTR szFileName, HWND hWnd);
HANDLE LCAPI lcBlockAddXline    (HANDLE hBlock, double X, double Y, double Angle, BOOL bRay);
HANDLE LCAPI lcBlockAddXline2P  (HANDLE hBlock, double X, double Y, double X2, double Y2, BOOL bRay);
HANDLE LCAPI lcBlockAddLine     (HANDLE hBlock, double X1, double Y1, double X2, double Y2);
HANDLE LCAPI lcBlockAddLineDir  (HANDLE hBlock, double X, double Y, double Angle, double Dist);
HANDLE LCAPI lcBlockAddLineTan  (HANDLE hBlock, HANDLE hEnt1, HANDLE hEnt2, int Mode);
HANDLE LCAPI lcBlockAddPolyline (HANDLE hBlock, int FitType, BOOL bClosed, BOOL bFilled);
HANDLE LCAPI lcBlockAddSpline   (HANDLE hBlock, BOOL bClosed, BOOL bFilled);
HANDLE LCAPI lcBlockAddMline    (HANDLE hBlock, int FitType, BOOL bClosed);
HANDLE LCAPI lcBlockAddRect     (HANDLE hBlock, double Xc, double Yc, double Width, double Height, double Angle, BOOL bFilled);
HANDLE LCAPI lcBlockAddRect2    (HANDLE hBlock, double Left, double Bottom, double Width, double Height, double Rad, BOOL bFilled);
HANDLE LCAPI lcBlockAddCircle   (HANDLE hBlock, double X, double Y, double Radius, BOOL bFilled);
HANDLE LCAPI lcBlockAddArc      (HANDLE hBlock, double X, double Y, double Radius, double StartAngle, double ArcAngle);
HANDLE LCAPI lcBlockAddArc3P    (HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3);
HANDLE LCAPI lcBlockAddEllipse  (HANDLE hBlock, double X, double Y, double R1, double R2, double RotAngle, double StartAngle, double ArcAngle);
HANDLE LCAPI lcBlockAddText     (HANDLE hBlock, LPCWSTR szText, double X, double Y);
HANDLE LCAPI lcBlockAddText2    (HANDLE hBlock, LPCWSTR szText, double X, double Y, int Align, double H, double WScale, double RotAngle, double Oblique);
HANDLE LCAPI lcBlockAddText3    (HANDLE hBlock, LPCWSTR szText, double X1, double Y1, double X2, double Y2, int Align, double HW, double Oblique);
HANDLE LCAPI lcBlockAddMText    (HANDLE hBlock, LPCWSTR szText, double X, double Y, double WrapWidth, int Align, double RotAngle, double H, double WScale);
HANDLE LCAPI lcBlockAddArcText  (HANDLE hBlock, LPCWSTR szText, double X, double Y, double Radius, double StartAngle, BOOL bClockwise, double H, double WScale, int Align);
HANDLE LCAPI lcBlockAddBlockRef (HANDLE hBlock, HANDLE hRefBlock, double X, double Y, double Scal, double Angle);
HANDLE LCAPI lcBlockAddBlockRefID  (HANDLE hBlock, int idRefBlock, double X, double Y, double Scal, double Angle);  // undoc
HANDLE LCAPI lcBlockAddBlockRefIDH (HANDLE hBlock, LPCWSTR szIdRefBlock, double X, double Y, double Scal, double Angle);  // undoc
//HANDLE LCAPI lcBlockAddXref     (HANDLE hBlock, LPCWSTR szFileName, double X, double Y, double ScalX, double ScalY, double Angle);
HANDLE LCAPI lcBlockAddImageRef (HANDLE hBlock, HANDLE hImage, double X, double Y, double Width, double Height, BOOL bBorder);
HANDLE LCAPI lcBlockAddEcw      (HANDLE hBlock, LPCWSTR szFileName);
HANDLE LCAPI lcBlockAddBarcode  (HANDLE hBlock, int BarType, double Xc, double Yc, double Width, double Height, LPCWSTR szText);
HANDLE LCAPI lcBlockAddHatch    (HANDLE hBlock, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle);
HANDLE LCAPI lcBlockAddViewport (HANDLE hBlock, double Lef, double Bot, double Width, double Height, double DrwPntX, double DrwPntY, double DrwScale, double DrwAngle);
HANDLE LCAPI lcBlockAddFace     (HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2);
HANDLE LCAPI lcBlockAddFace4    (HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
HANDLE LCAPI lcBlockAddLeader   (HANDLE hBlock, LPCWSTR szText, double Xt, double Yt, double LandDist, double Xa, double Ya, int Attach, int Align);
HANDLE LCAPI lcBlockAddDimLin   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, double Angle, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimHor   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimVer   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAli   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAli2  (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Dt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimOrd   (HANDLE hBlock, double Xd, double Yd, double Xt, double Yt, BOOL bX, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimRad   (HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimRad2  (HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimDia   (HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimDia2  (HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAng   (HANDLE hBlock, double Xc, double Yc, double X1, double Y1, double X2, double Y2, double Xa, double Ya, double TextPos, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAng2  (HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3, double X4, double Y4, double Xa, double Ya, double TextPos, LPCWSTR szText);
HANDLE LCAPI lcBlockAddRPlan    (HANDLE hBlock);
HANDLE LCAPI lcBlockAddArrow    (HANDLE hBlock, double X1, double Y1, double X2, double Y2);
HANDLE LCAPI lcBlockAddSpiral   (HANDLE hBlock, double Xc, double Yc, double R, double Turns, BOOL bDirCW, BOOL bClosed);
HANDLE LCAPI lcBlockAddCamview  (HANDLE hBlock, double Lef, double Bot, double Width, double Height); 
HANDLE LCAPI lcBlockAddClone    (HANDLE hBlock, HANDLE hEnt); 

// Retrieve graphic objects from a block
HANDLE LCAPI lcBlockGetFirstEnt (HANDLE hBlock);
HANDLE LCAPI lcBlockGetNextEnt  (HANDLE hBlock, HANDLE hEnt);
HANDLE LCAPI lcBlockGetLastEnt  (HANDLE hBlock);
HANDLE LCAPI lcBlockGetPrevEnt  (HANDLE hBlock, HANDLE hEnt);
HANDLE LCAPI lcBlockGetEntByID  (HANDLE hBlock, int Id);
HANDLE LCAPI lcBlockGetEntByIDH (HANDLE hBlock, LPCWSTR szId);
HANDLE LCAPI lcBlockGetEntByKey (HANDLE hBlock, int Key);

// Selection
BOOL   LCAPI lcBlockUnselect    (HANDLE hBlock);
BOOL   LCAPI lcBlockSelectEnt   (HANDLE hBlock, HANDLE hEntity, BOOL bSelect);
BOOL   LCAPI lcBlockSelErase    (HANDLE hBlock);
BOOL   LCAPI lcBlockSelMove     (HANDLE hBlock, double dX, double dY, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelScale    (HANDLE hBlock, double X0, double Y0, double Scal, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelRotate   (HANDLE hBlock, double X0, double Y0, double Angle, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelMirror   (HANDLE hBlock, double X1, double Y1, double X2, double Y2, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelExplode  (HANDLE hBlock);
HANDLE LCAPI lcBlockSelJoin     (HANDLE hBlock, double Delta);
BOOL   LCAPI lcBlockSelAlign    (HANDLE hBlock, int Mode, double X, double Y);
//HANDLE LCAPI lcBlockSelBlock    (HANDLE hBlock, LPCWSTR szName, double X, double Y, int Mode, BOOL bOverwrite);
HANDLE LCAPI lcBlockGetFirstSel (HANDLE hBlock);
HANDLE LCAPI lcBlockGetNextSel  (HANDLE hBlock);

// change entities order by layer
BOOL   LCAPI lcBlockOrderByLayers (HANDLE hBlock, HWND hWnd);
BOOL   LCAPI lcBlockSortTSP     (HANDLE hBlock, HANDLE hLayer, HWND hWnd);
double LCAPI lcBlockGetJumpsLen (HANDLE hBlock, HANDLE hLayer, HWND hWnd);

// remove entities of specified layer from a block (all blocks if hBlock=0)
BOOL   LCAPI lcLayerClear  (HANDLE hLayer, HANDLE hBlock);

// Graphic object modify
BOOL   LCAPI lcEntErase     (HANDLE hEnt, BOOL bErase); 
BOOL   LCAPI lcEntMove      (HANDLE hEnt, double dX, double dY); 
BOOL   LCAPI lcEntScale     (HANDLE hEnt, double X0, double Y0, double Scal); 
BOOL   LCAPI lcEntRotate    (HANDLE hEnt, double X0, double Y0, double Angle);
BOOL   LCAPI lcEntMirror    (HANDLE hEnt, double X1, double Y1, double X2, double Y2);
BOOL   LCAPI lcEntExplode   (HANDLE hEnt, BOOL bSelect);
BOOL   LCAPI lcEntOffset    (HANDLE hEnt, double Dist); 
BOOL   LCAPI lcEntToTop     (HANDLE hEnt);
BOOL   LCAPI lcEntToBottom  (HANDLE hEnt);
BOOL   LCAPI lcEntToAbove   (HANDLE hEnt, HANDLE hEnt2);
BOOL   LCAPI lcEntToUnder   (HANDLE hEnt, HANDLE hEnt2);
BOOL   LCAPI lcEntGetGrip   (HANDLE hEnt, int iGrip, double* pX, double* pY); 
BOOL   LCAPI lcEntPutGrip   (HANDLE hEnt, int iGrip, double X, double Y);
BOOL   LCAPI lcEntUpdate    (HANDLE hEnt);      
BOOL   LCAPI lcEntCopyBase  (HANDLE hEnt, HANDLE hEntFrom);

int    LCAPI lcIntersection   (HANDLE hEnt, HANDLE hEnt2);  // undoc
BOOL   LCAPI lcInterGetPoint  (int iPoint, double* pX, double* pY);  // undoc

// Polyline Vertices
HANDLE LCAPI lcPlineAddVer      (HANDLE hPline, HANDLE hVer, double X, double Y);
HANDLE LCAPI lcPlineAddVer2     (HANDLE hPline, HANDLE hVer, double X, double Y, double Param, double W0, double W1);
HANDLE LCAPI lcPlineAddVerDir   (HANDLE hPline, HANDLE hVer, double Ang, double Length);
BOOL   LCAPI lcPlineEnd         (HANDLE hPline);
//BOOL   LCAPI lcPlineFromPtbuf   (HANDLE hPline, HANDLE hPtbuf);
//BOOL   LCAPI lcPlineFromMpgon   (HANDLE hPline, HANDLE hMpgon);
BOOL   LCAPI lcPlineDeleteVer   (HANDLE hPline, HANDLE hVer);
HANDLE LCAPI lcPlineGetFirstVer (HANDLE hPline);
HANDLE LCAPI lcPlineGetNextVer  (HANDLE hPline, HANDLE hVer);
HANDLE LCAPI lcPlineGetLastVer  (HANDLE hPline);
HANDLE LCAPI lcPlineGetPrevVer  (HANDLE hPline, HANDLE hVer);
HANDLE LCAPI lcPlineGetVer      (HANDLE hPline, int Index);
HANDLE LCAPI lcPlineGetVerPt    (HANDLE hPline, double X, double Y, double Delta);
HANDLE LCAPI lcPlineGetSeg      (HANDLE hPline, double X, double Y, double Delta);
BOOL   LCAPI lcPlineReverse     (HANDLE hPline);
//BOOL   LCAPI lcPlineReverse     (HANDLE hPline);
int    LCAPI lcPlineContainPoint(HANDLE hPline, double X, double Y);
BOOL   LCAPI lcPlineGetRoundPrm (HANDLE hPline, HANDLE hVer, double* px0, double* py0, double* pBulge, double* px1, double* py1);   // undoc (dwg plugin)

// Construction line
BOOL   LCAPI lcXlinePutDir  (HANDLE hXline, double X, double Y);

// Rectangle
int    LCAPI lcRectGetPolyline   (HANDLE hRect, double* pX, double* pY, double* pBulge);

// Image reference 
BOOL   LCAPI lcImgRefGetPixel (HANDLE hImgRef, int iX, int iY, double* pX, double* pY, int* pColor);
//BOOL   LCAPI lcImgRefResize   (HANDLE hImgRef, int NewWidth, int NewHeight, int Method);

// Hatch
BOOL   LCAPI lcHatchSetPattern   (HANDLE hHatch, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle);
BOOL   LCAPI lcHatchBoundStart   (HANDLE hHatch);
BOOL   LCAPI lcHatchBoundPoint   (HANDLE hHatch, double X, double Y);
//BOOL   LCAPI lcHatchBoundEntity  (HANDLE hHatch, HANDLE hEnt);
BOOL   LCAPI lcHatchBoundEndLoop (HANDLE hHatch); 
BOOL   LCAPI lcHatchBoundEnd     (HANDLE hHatch); 
BOOL   LCAPI lcHatchPatStart     (HANDLE hHatch); 
BOOL   LCAPI lcHatchPatLine      (HANDLE hHatch, double Angle, double x0, double y0, double dx, double dy, int nDash, double L0, double L1, double L2, double L3, double L4, double L5, double L6, double L7);
BOOL   LCAPI lcHatchPatEnd       (HANDLE hHatch);
int    LCAPI lcHatchGetLoopSize  (HANDLE hHatch, int iLoop);
BOOL   LCAPI lcHatchGetPoint     (HANDLE hHatch, int iPnt, double* pX, double* pY);

// RPlan functions
HANDLE LCAPI lcRPlanAddVer      (HANDLE hRPlan, double X, double Y);
BOOL   LCAPI lcRPlanSetCurve    (HANDLE hVer, double Radius, double LenClot1, double LenClot2);
BOOL   LCAPI lcRPlanSetPos      (HANDLE hVer, double X, double Y);
BOOL   LCAPI lcRPlanDeleteVer   (HANDLE hRPlan, HANDLE hVer);
HANDLE LCAPI lcRPlanGetFirstVer (HANDLE hRPlan);
HANDLE LCAPI lcRPlanGetNextVer  (HANDLE hRPlan, HANDLE hVer);
HANDLE LCAPI lcRPlanGetLastVer  (HANDLE hRPlan);
HANDLE LCAPI lcRPlanGetPrevVer  (HANDLE hRPlan, HANDLE hVer);
HANDLE LCAPI lcRPlanGetVer      (HANDLE hRPlan, int Index);
BOOL   LCAPI lcRPlanGetPoint    (HANDLE hRPlan, double Dist, double* pX, double* pY, double* pAngle, int* pSide);
BOOL   LCAPI lcRPlanGetDist     (HANDLE hRPlan, double X, double Y, double* pX2, double* pY2, double* pDist, double* pOffset);

// Viewport
BOOL   LCAPI lcVportSetView     (HANDLE hVport, double Xcen, double Ycen, double Scal, double Angle);
//BOOL   LCAPI lcVportLayerDlg    (HANDLE hVport, HANDLE hLcWnd);
//BOOL   LCAPI lcVportLayerCmd    (HANDLE hVport, int Cmd, HANDLE hLayer);

// Color from string
BOOL   LCAPI lcColorIsRGB      (LPCWSTR szColor);
int    LCAPI lcColorGetRed     (LPCWSTR szColor); 
int    LCAPI lcColorGetGreen   (LPCWSTR szColor);
int    LCAPI lcColorGetBlue    (LPCWSTR szColor);
int    LCAPI lcColorGetIndex   (LPCWSTR szColor);
BOOL   LCAPI lcColorToVal      (LPCWSTR szColor, int* pbRGB, int* pIndex, int* pR,int* pG,int* pB);
// Color palette
BOOL   LCAPI lcColorSetPalette (int Index, int R,int G,int B);
BOOL   LCAPI lcColorGetPalette (int Index, int* pR,int* pG,int* pB);

// Image
BOOL   LCAPI lcImageSetPixelRGB (HANDLE hImage, int X, int Y, int Red, int Green, int Blue);      
BOOL   LCAPI lcImageSetPixelI   (HANDLE hImage, int X, int Y, int iColor);                        
BOOL   LCAPI lcImageGetPixelRGB (HANDLE hImage, int X, int Y, int* pRed, int* pGreen, int* pBlue);
BOOL   LCAPI lcImageGetPixelI   (HANDLE hImage, int X, int Y, int* piColor);                      
BOOL   LCAPI lcImageSetPalColor (HANDLE hImage, int iColor, int Red, int Green, int Blue);        
BOOL   LCAPI lcImageGetPalColor (HANDLE hImage, int iColor, int* pRed, int* pGreen, int* pBlue);  
BOOL   LCAPI lcImageLoad        (HANDLE hImage, LPCWSTR szFilename, HANDLE hWnd);
BOOL   LCAPI lcImageLoadDIB     (HANDLE hImage, HANDLE hDib2);  // undoc
BOOL   LCAPI lcImageCopyQuad    (HANDLE hImage, HANDLE hImageSrc, UINT W, UINT H, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3);  // undoc


// Toolbar Window

// Misc
BOOL   LCAPI lcFilletSetLines  (double L1x0, double L1y0, double L1x1, double L1y1, double L2x0, double L2y0, double L2x1, double L2y1);
BOOL   LCAPI lcFillet          (double Rad, double Bis, double Tang);
BOOL   LCAPI lcFilletGetPoint  (int iPnt, double* pX, double* pY);

// work field
BOOL   LCAPI lcWFieldSet      (HANDLE hDrw, double Lef, double Bot, double Width, double Height);
BOOL   LCAPI lcWFieldClear    (HANDLE hDrw);
int    LCAPI lcWFieldDivide   (HANDLE hDrw, int NumX, int NumY, BOOL bClearExist);
BOOL   LCAPI lcWFieldAddCR    (HANDLE hDrw, int ID, double Lef, double Bot, double Width, double Height);
BOOL   LCAPI lcWFieldSetCR    (HANDLE hDrw, int ID, double Lef, double Bot, double Width, double Height);
BOOL   LCAPI lcWFieldDeleteCR (HANDLE hDrw, int ID);
BOOL   LCAPI lcWFieldActiveCR (HANDLE hDrw, int ID);
BOOL   LCAPI lcWFieldSave     (HANDLE hDrw, LPCWSTR szFileName);
BOOL   LCAPI lcWFieldLoad     (HANDLE hDrw, LPCWSTR szFileName);
HANDLE LCAPI lcWFieldFirstCR  (HANDLE hDrw);
HANDLE LCAPI lcWFieldNextCR   (HANDLE hDrw, HANDLE hEnt);

// explode entity to polylines, Flags is LC_EXP_ALL or other
int    LCAPI lcExpEntity    (HANDLE hEnt, int Flags, BOOL bUnrotate);
int    LCAPI lcExpGetPline  (double Delta);
BOOL   LCAPI lcExpGetVertex (double* pX, double* pY);

BOOL LCAPI lcGbrLoad  (HANDLE hLcWnd, LPCWSTR szFileName0);
BOOL LCAPI lcGbrClose (HANDLE hLcWnd);

LPCWSTR LCAPI lcPlugGetOption  (LPCWSTR szFileName, LPCWSTR szKey);
BOOL    LCAPI lcPlugGetOption2 (LPCWSTR szFileName, LPCWSTR szKey);
BOOL    LCAPI lcPlugSetOption  (LPCWSTR szFileName, LPCWSTR szKey, LPCWSTR szValue, BOOL bSave);

//BOOL LCAPI lcPrintSetup  (HANDLE hWnd);
//BOOL LCAPI lcPrintLayout (HANDLE hBlock);
//BOOL LCAPI lcPrintBlock  (HANDLE hBlock, double X, double Y, double W, double H, double Scale, double PapLef, double PapTop);


///////////////////////////////////////////////////////////////////////////////
// ZenithTech specific
BOOL   LCAPI lc2_Initialize   ();
BOOL   LCAPI lc2_Uninitialize ();
HANDLE LCAPI lc2_Create    (HWND hWndParent, int Flags);
BOOL   LCAPI lc2_Delete    (HANDLE hFrame);
BOOL   LCAPI lc2_OnClose   (HANDLE hFrame);
BOOL   LCAPI lc2_Position  (HANDLE hFrame, int Left, int Top, int Width, int Height);
BOOL   LCAPI lc2_Command   (HANDLE hFrame, int Command, int CmdParam);
HANDLE LCAPI lc2_GetWnd    (HANDLE hFrame);
HANDLE LCAPI lc2_GetDrw    (HANDLE hFrame);
HANDLE LCAPI lc2_GetBlock  (HANDLE hFrame);
BOOL   LCAPI lc2_FileLoad  (HANDLE hFrame, LPCWSTR szFileName);
BOOL   LCAPI lc2_FileSave  (HANDLE hFrame, LPCWSTR szFileName, BOOL bBak);
BOOL   LCAPI lc2_WFieldSave   (HANDLE hFrame, LPCWSTR szFileName);
BOOL   LCAPI lc2_WFieldLoad   (HANDLE hFrame, LPCWSTR szFileName);
int    LCAPI lc2_ExpStart     (HANDLE hFrame, int Mode);
int    LCAPI lc2_ExpGetPline  (HANDLE hFrame);
HANDLE LCAPI lc2_ExpGetEntity (HANDLE hFrame);
BOOL   LCAPI lc2_ExpGetVertex (HANDLE hFrame, double* pX, double* pY);
BOOL   LCAPI lc2_ExpGetPoint  (HANDLE hFrame);
BOOL   LCAPI lc2_CbCopy  (HANDLE hFrame, double Lef, double Bot, double W, double H);
BOOL   LCAPI lc2_CbCopy2 (HANDLE hFrame, int idClipRect, BOOL bUnrotate);
BOOL   LCAPI lc2_CbPaste (HANDLE hFrame, double Lef, double Bot);

BOOL LCAPI lcMru_EnableFileExt (LPCWSTR szFileExt);
BOOL LCAPI lcMru_Load          (LPCWSTR szFileName);
BOOL LCAPI lcMru_Save          ();
BOOL LCAPI lcMru_AddFile       (LPCWSTR szFileName, BOOL bFileHasView);
BOOL LCAPI lcMru_SetImage      (LPCWSTR szFileName, BYTE* pImgBuf, int ImgSize);
BOOL LCAPI lcMru_HasImage      (LPCWSTR szFileName);
BOOL LCAPI lcMru_SetViewRect   (LPCWSTR szFileName, double Xmin, double Ymin, double Xmax, double Ymax);
BOOL LCAPI lcMru_GetViewRect   (LPCWSTR szFileName, double* pXmin, double* pYmin, double* pXmax, double* pYmax);
BOOL LCAPI lcMru_Dialog        (HWND hWnd, HANDLE hIcon, WCHAR* szFileName);


// NoDB mode ////////////////////////////////////////////////////////////////////////////////////////

// Window Tabs
BOOL   LCAPI lcWndTabClear  (HANDLE hLcWnd);
BOOL   LCAPI lcWndTabAdd    (HANDLE hLcWnd, int TabID, LPCWSTR szLabel, LPCWSTR szTipText, HANDLE hObject);
BOOL   LCAPI lcWndTabSelect (HANDLE hLcWnd, int TabID);

// Paper
BOOL   LCAPI lcWndPaperEnable   (HANDLE hLcWnd, BOOL bEnable);
BOOL   LCAPI lcWndPaperSetSize  (HANDLE hLcWnd, int Size, int Orient);
BOOL   LCAPI lcWndPaperSetSize2 (HANDLE hLcWnd, double Width, double Height);
BOOL   LCAPI lcWndPaperSetPos   (HANDLE hLcWnd, double Left, double Bottom);

// Grips
BOOL   LCAPI lcGripClear   (HANDLE hLcWnd);
BOOL   LCAPI lcGripAdd     (HANDLE hLcWnd, HANDLE hObj, int iGrip, int Typ, double X, double Y, double Ang, double X0, double Y0);
BOOL   LCAPI lcGripSet     (HANDLE hLcWnd, HANDLE hObj, int iGrip, double X, double Y, double Ang, double X0, double Y0);

// to draw inside of Paint event procedure
HANDLE LCAPI lcPaint_PenCreate     (HANDLE hLcWnd, int Id, COLORREF Color, double Width, int PenStyle);
BOOL   LCAPI lcPaint_PenSelect     (HANDLE hLcWnd, HANDLE hPen);
BOOL   LCAPI lcPaint_PenSelectID   (HANDLE hLcWnd, int IdPen);
HANDLE LCAPI lcPaint_BrushCreate   (HANDLE hLcWnd, int Id, COLORREF Color, int Pattern, int Alpha);
BOOL   LCAPI lcPaint_BrushSelect   (HANDLE hLcWnd, HANDLE hBrush);
BOOL   LCAPI lcPaint_BrushSelectID (HANDLE hLcWnd, int IdBrush);

BOOL   LCAPI lcPaint_DrawPtbuf   (HANDLE hLcWnd, HANDLE hPtbuf, BOOL bClosed);
BOOL   LCAPI lcPaint_DrawMpgon   (HANDLE hLcWnd, HANDLE hMpgon, BOOL bFill, BOOL bBorder);
BOOL   LCAPI lcPaint_DrawImage   (HANDLE hLcWnd, HANDLE hImage, double X, double Y, double PixelSize, int Transp, int TVal, HANDLE hPtbuf);
BOOL   LCAPI lcPaint_DrawImage2  (HANDLE hLcWnd, HANDLE hImage, double X, double Y, double W, double H, int Transp, int TVal, HANDLE hPtbuf);
BOOL   LCAPI lcPaint_DrawText    (HANDLE hLcWnd, double X, double Y, LPCWSTR szText);
BOOL   LCAPI lcPaint_DrawText2   (HANDLE hLcWnd, double X1, double Y1, double X2, double Y2, int Align, LPCWSTR szText);
BOOL   LCAPI lcPaint_DrawTextBC  (HANDLE hLcWnd, HANDLE hMpgon, double Gap, double Height, int Align, LPCWSTR szText);
BOOL   LCAPI lcPaint_DrawArcText (HANDLE hLcWnd, LPCWSTR szText, double X, double Y, double Rad, double Ang0, BOOL bCW, double H, double WScale, int Align); 
BOOL   LCAPI lcPaint_DrawHatch   (HANDLE hLcWnd, HANDLE hHatch);
BOOL   LCAPI lcPaint_DrawPoint   (HANDLE hLcWnd, double X, double Y, int PtMode, double PtSize); 
BOOL   LCAPI lcPaint_DrawLine    (HANDLE hLcWnd, double X1, double Y1, double X2, double Y2); 
BOOL   LCAPI lcPaint_DrawXline   (HANDLE hLcWnd, double X, double Y, double Angle, BOOL bRay);
BOOL   LCAPI lcPaint_DrawRect    (HANDLE hLcWnd, double Xc, double Yc, double Width, double Height);
BOOL   LCAPI lcPaint_DrawRect2   (HANDLE hLcWnd, double X1, double Y1, double X2, double Y2);
//BOOL   LCAPI lcPaint_DrawPickBox (HANDLE hLcWnd);
BOOL   LCAPI lcPaint_DrawTIN     (HANDLE hLcWnd, HANDLE hTIN);
BOOL   LCAPI lcPaint_DrawGrid    (HANDLE hLcWnd, HANDLE hGrid, BOOL bDest, COLORREF ColLine, COLORREF ColNode);
BOOL   LCAPI lcPaint_DrawCPrompt (HANDLE hLcWnd, int X, int Y, int Align, LPCWSTR szText);
//void   LCAPI lcPaint_SetPixel    (HANDLE hDC, int X, int Y, COLORREF Color);


// Points buffer 
HANDLE LCAPI lcPaint_CreatePtbuf     ();
BOOL   LCAPI lcPaint_DeletePtbuf     (HANDLE hPtbuf);
BOOL   LCAPI lcPaint_PtbufClear      (HANDLE hPtbuf);
BOOL   LCAPI lcPaint_PtbufAddPoint   (HANDLE hPtbuf, double X, double Y, double Prm1, double Prm2, int IntPrm);
BOOL   LCAPI lcPaint_PtbufAddPoint2  (HANDLE hPtbuf, double X, double Y);
BOOL   LCAPI lcPaint_PtbufAddPointP  (HANDLE hPtbuf, double Angle, double Dist);
BOOL   LCAPI lcPaint_PtbufAddLine    (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2);
BOOL   LCAPI lcPaint_PtbufAddLineP   (HANDLE hPtbuf, double X, double Y, double Angle, double Dist);
BOOL   LCAPI lcPaint_PtbufAddCircle  (HANDLE hPtbuf, double Xc, double Yc, double R, int Resol);
BOOL   LCAPI lcPaint_PtbufAddCircle2 (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, int Resol);
BOOL   LCAPI lcPaint_PtbufAddCircle3 (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double X3, double Y3, BOOL bInside, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArc     (HANDLE hPtbuf, double Xc, double Yc, double R, double StartAngle, double ArcAngle, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArc3p   (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double X3, double Y3, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcSDE  (HANDLE hPtbuf, double Xs, double Ys, double DirAng, double Xe, double Ye, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcSDAR (HANDLE hPtbuf, double Xs, double Ys, double DirAng, double AngArc, double R, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcSER  (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double Radius, BOOL bClockwise, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcSEL  (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double ArcLen, BOOL bClockwise, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcSEA  (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double AngArc, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcSEB  (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double Bulge, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcCSE  (HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double Xe, double Ye, BOOL bClockwise, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcCSA  (HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double AngArc, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcCSL  (HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double ChordLen, BOOL bClockwise, int Resol);
BOOL   LCAPI lcPaint_PtbufAddArcCRAA (HANDLE hPtbuf, double Xc, double Yc, double R, double AngStart, double AngEnd, BOOL bClockwise, int Resol);
BOOL   LCAPI lcPaint_PtbufAddEllipse (HANDLE hPtbuf, double Xc, double Yc, double Rmaj, double Rmin, double RotAng, double StartAng, double ArcAng, int Resol);
BOOL   LCAPI lcPaint_PtbufAddEllipse2(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, int Resol);
BOOL   LCAPI lcPaint_PtbufAddRect    (HANDLE hPtbuf, double Xc, double Yc, double W, double H, double Angle, double R, int Resol);
BOOL   LCAPI lcPaint_PtbufAddRect2   (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double R, int Resol);
BOOL   LCAPI lcPaint_PtbufAddRect3   (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double W, int Align, double R, int Resol);
BOOL   LCAPI lcPaint_PtbufAddWline   (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double W, int Align, BOOL bArc, int Resol);
BOOL   LCAPI lcPaint_PtbufAddPtbuf   (HANDLE hPtbuf, HANDLE hPtbuf2);
BOOL   LCAPI lcPaint_PtbufGetPoint   (HANDLE hPtbuf, int Mode, double* pX, double* pY);
BOOL   LCAPI lcPaint_PtbufGetPoint2  (HANDLE hPtbuf, int Mode, double* pX, double* pY, double* pPrm1, double* pPrm2, int* pIntPrm);
BOOL   LCAPI lcPaint_PtbufInterpolate(HANDLE hPtbuf, BOOL bClosed, HANDLE hPtbufDest, int Mode, int Resol);
BOOL   LCAPI lcPaint_PtbufMove       (HANDLE hPtbuf, double dx, double dy);
BOOL   LCAPI lcPaint_PtbufRotate     (HANDLE hPtbuf, double Xc, double Yc, double Angle);
BOOL   LCAPI lcPaint_PtbufScale      (HANDLE hPtbuf, double Xc, double Yc, double ScaleX, double ScaleY);
BOOL   LCAPI lcPaint_PtbufMirror     (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2);
BOOL   LCAPI lcPaint_PtbufCopy       (HANDLE hPtbuf, HANDLE hPtbufDest);

// Multipolygon 
HANDLE LCAPI lcPaint_CreateMpgon    ();
BOOL   LCAPI lcPaint_DeleteMpgon    (HANDLE hMpgon);
BOOL   LCAPI lcPaint_MpgonClear     (HANDLE hMpgon);
BOOL   LCAPI lcPaint_MpgonAddPgon   (HANDLE hMpgon, HANDLE hPtbuf);
BOOL   LCAPI lcPaint_MpgonAddText   (HANDLE hMpgon, HANDLE hFont, double X, double Y, LPCWSTR szText, int Resol);
BOOL   LCAPI lcPaint_MpgonAddBarcode(HANDLE hMpgon, int BarType, double Xc, double Yc, double Width, double Height, LPCWSTR szText);
BOOL   LCAPI lcPaint_MpgonMove      (HANDLE hMpgon, double dx, double dy);
BOOL   LCAPI lcPaint_MpgonRotate    (HANDLE hMpgon, double Xc, double Yc, double Angle);
BOOL   LCAPI lcPaint_MpgonScale     (HANDLE hMpgon, double Xc, double Yc, double ScaleX, double ScaleY);
BOOL   LCAPI lcPaint_MpgonMirror    (HANDLE hMpgon, double X1, double Y1, double X2, double Y2);
BOOL   LCAPI lcPaint_MpgonCopy      (HANDLE hMpgon, HANDLE hMpgonDest);

BOOL   LCAPI lcPaint_HatchGen (HANDLE hMpgon, HANDLE hHatch, double Dist, double Angle, double W, double Beamc1, double Beamc2, double StartOff, double EndOff);

// Image 
HANDLE LCAPI lcPaint_ImageAdd      (int Id);
BOOL   LCAPI lcPaint_ImageDelete   (HANDLE hImage);      
HANDLE LCAPI lcPaint_ImageGetFirst ();
HANDLE LCAPI lcPaint_ImageGetNext  (HANDLE hImage);
HANDLE LCAPI lcPaint_ImageGetByID  (int Id);
BOOL   LCAPI lcPaint_ImageLoad     (HANDLE hImage, LPCWSTR szFileName);
BOOL   LCAPI lcPaint_ImageCopy     (HANDLE hImage, HANDLE hImageDest);
BOOL   LCAPI lcPaint_ImageCreate   (HANDLE hImage, int Width, int Height);
BOOL   LCAPI lcPaint_ImageSetPixel (HANDLE hImage, int X, int Y, int R, int G, int B);
BOOL   LCAPI lcPaint_ImageFlip     (HANDLE hImage, BOOL bHor, BOOL bVert);
BOOL   LCAPI lcPaint_ImageRotate   (HANDLE hImage, double Angle);
BOOL   LCAPI lcPaint_ImageGray     (HANDLE hImage);
BOOL   LCAPI lcPaint_ImageResize   (HANDLE hImage, int NewWidth, int NewHeight, int ResizeFilter);
HANDLE LCAPI lcPaint_ImageGetPtbuf (HANDLE hImage, double RotAngle);

HANDLE LCAPI lcPaint_FontOpenLC (LPCWSTR szFontName);
HANDLE LCAPI lcPaint_FontOpenTT (LPCWSTR szFontName, BOOL bBold, BOOL bItalic);
BOOL   LCAPI lcPaint_FontClose  (HANDLE hFont);
BOOL   LCAPI lcPaint_FontSelect (HANDLE hLcWnd, HANDLE hFont);


BOOL lcLoadLib ();
BOOL lcLoadLib64 ();
void lcFreeLib ();

#endif
