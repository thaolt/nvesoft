/********************************************************************
* LiteCAD DLL version 3.0
* Copyright (c) 2009-2016, Oleg Kolbaskin.
* All rights reserved.
*
* This file makes dynamic linking with LiteCAD functions.
*
* Visual C++ applications can use litecad.lib instead of this file.
*
********************************************************************/
#include "Litecad.h"

typedef void (LCAPI *tflcEventSetProc)(int EventType, F_LCEVENT pFunc, int Prm1, HANDLE Prm2);
tflcEventSetProc pflcEventSetProc = 0;

typedef void (LCAPI *tflcEventReturnCode)(int code);
tflcEventReturnCode pflcEventReturnCode = 0;

typedef BOOL (LCAPI *tflcEventsEnable)(BOOL b);
tflcEventsEnable pflcEventsEnable = 0;

typedef BOOL (LCAPI *tflcInitialize)();
tflcInitialize pflcInitialize = 0;

typedef BOOL (LCAPI *tflcUninitialize)(BOOL bSaveConfig);
tflcUninitialize pflcUninitialize = 0;

typedef BOOL (LCAPI *tflcStrAdd)(LPCWSTR szTag, LPCWSTR szText);
tflcStrAdd pflcStrAdd = 0;

typedef BOOL (LCAPI *tflcStrSet)(LPCWSTR szTag, LPCWSTR szText);
tflcStrSet pflcStrSet = 0;

typedef LPCWSTR (LCAPI *tflcStrGet)(LPCWSTR szTag);
tflcStrGet pflcStrGet = 0;

typedef BOOL (LCAPI *tflcStrFileLoad)(LPCWSTR szFileName);
tflcStrFileLoad pflcStrFileLoad = 0;

typedef BOOL (LCAPI *tflcStrFileSave)(LPCWSTR szFileName, LPCWSTR szLanguage);
tflcStrFileSave pflcStrFileSave = 0;

typedef BOOL (LCAPI *tflcPropGetBool)(HANDLE hObject, int idProp);
tflcPropGetBool pflcPropGetBool = 0;

typedef int (LCAPI *tflcPropGetInt)(HANDLE hObject, int idProp);
tflcPropGetInt pflcPropGetInt = 0;

typedef double (LCAPI *tflcPropGetFloat)(HANDLE hObject, int idProp);
tflcPropGetFloat pflcPropGetFloat = 0;

typedef LPCWSTR (LCAPI *tflcPropGetStr)(HANDLE hObject, int idProp);
tflcPropGetStr pflcPropGetStr = 0;

typedef int (LCAPI *tflcPropGetStr2)(HANDLE hObject, int idProp);
tflcPropGetStr2 pflcPropGetStr2 = 0;

typedef int (LCAPI *tflcPropGetChar)(int iChar);
tflcPropGetChar pflcPropGetChar = 0;

typedef HANDLE (LCAPI *tflcPropGetHandle)(HANDLE hObject, int idProp);
tflcPropGetHandle pflcPropGetHandle = 0;

typedef BOOL (LCAPI *tflcPropPutBool)(HANDLE hObject, int idProp, BOOL bValue);
tflcPropPutBool pflcPropPutBool = 0;

typedef BOOL (LCAPI *tflcPropPutInt)(HANDLE hObject, int idProp, int Value);
tflcPropPutInt pflcPropPutInt = 0;

typedef BOOL (LCAPI *tflcPropPutFloat)(HANDLE hObject, int idProp, double Value);
tflcPropPutFloat pflcPropPutFloat = 0;

typedef BOOL (LCAPI *tflcPropPutStr)(HANDLE hObject, int idProp, LPCWSTR szValue);
tflcPropPutStr pflcPropPutStr = 0;

typedef BOOL (LCAPI *tflcPropPutHandle)(HANDLE hObject, int idProp, HANDLE hValue);
tflcPropPutHandle pflcPropPutHandle = 0;

typedef HANDLE (LCAPI *tflcCreateWindow)(HWND hWndParent, int Style);
tflcCreateWindow pflcCreateWindow = 0;

typedef BOOL (LCAPI *tflcDeleteWindow)(HANDLE hLcWnd);
tflcDeleteWindow pflcDeleteWindow = 0;

typedef BOOL (LCAPI *tflcWndResize)(HANDLE hLcWnd, int Left, int Top, int Width, int Height);
tflcWndResize pflcWndResize = 0;

typedef BOOL (LCAPI *tflcWndRedraw)(HANDLE hLcWnd);
tflcWndRedraw pflcWndRedraw = 0;

typedef BOOL (LCAPI *tflcWndSetFocus)(HANDLE hLcWnd);
tflcWndSetFocus pflcWndSetFocus = 0;

typedef BOOL (LCAPI *tflcWndSetExtents)(HANDLE hLcWnd, double Xmin, double Ymin, double Xmax, double Ymax);
tflcWndSetExtents pflcWndSetExtents = 0;

typedef BOOL (LCAPI *tflcWndZoomRect)(HANDLE hLcWnd, double Left, double Bottom, double Right, double Top);
tflcWndZoomRect pflcWndZoomRect = 0;

typedef BOOL (LCAPI *tflcWndZoomScale)(HANDLE hLcWnd, double Scal);
tflcWndZoomScale pflcWndZoomScale = 0;

typedef BOOL (LCAPI *tflcWndZoomMove)(HANDLE hLcWnd, double DX, double DY);
tflcWndZoomMove pflcWndZoomMove = 0;

typedef BOOL (LCAPI *tflcWndGetCursorCoord)(HANDLE hLcWnd, int* pXwin, int* pYwin, double* pXdrw, double* pYdrw);
tflcWndGetCursorCoord pflcWndGetCursorCoord = 0;

typedef BOOL (LCAPI *tflcWndExeCommand)(HANDLE hLcWnd, int Command, int CmdParam);
tflcWndExeCommand pflcWndExeCommand = 0;

typedef BOOL (LCAPI *tflcWndOnClose)(HANDLE hLcWnd);
tflcWndOnClose pflcWndOnClose = 0;

typedef BOOL (LCAPI *tflcWndSetBlock)(HANDLE hLcWnd, HANDLE hBlock);
tflcWndSetBlock pflcWndSetBlock = 0;

typedef BOOL (LCAPI *tflcWndSetProps)(HANDLE hLcWnd, HANDLE hPropWnd);
tflcWndSetProps pflcWndSetProps = 0;

typedef HANDLE (LCAPI *tflcWndGetEntByPoint)(HANDLE hLcWnd, int Xwin, int Ywin);
tflcWndGetEntByPoint pflcWndGetEntByPoint = 0;

typedef HANDLE (LCAPI *tflcWndGetEntByPoint2)(HANDLE hLcWnd, double X, double Y, double Delta);
tflcWndGetEntByPoint2 pflcWndGetEntByPoint2 = 0;

typedef int (LCAPI *tflcWndGetEntsByRect)(HANDLE hLcWnd, double Lef, double Bot, double Rig, double Top, BOOL bCross, int nMaxEnts);
tflcWndGetEntsByRect pflcWndGetEntsByRect = 0;

typedef HANDLE (LCAPI *tflcWndGetEntity)(int iEnt);
tflcWndGetEntity pflcWndGetEntity = 0;

//typedef HANDLE (LCAPI *tflcWndGetEntByID)(HANDLE hLcWnd, int Id);
//tflcWndGetEntByID pflcWndGetEntByID = 0;

//typedef HANDLE (LCAPI *tflcWndGetEntByIDH)(HANDLE hLcWnd, LPCWSTR szId);
//tflcWndGetEntByIDH pflcWndGetEntByIDH = 0;

//typedef HANDLE (LCAPI *tflcWndGetEntByKey)(HANDLE hLcWnd, int Key);
//tflcWndGetEntByKey pflcWndGetEntByKey = 0;

//typedef BOOL (LCAPI *tflcWndEmulator)(HANDLE hLcWnd, int Mode);
//tflcWndEmulator pflcWndEmulator = 0;

//typedef BOOL (LCAPI *tflcWndMagnifier)(HANDLE hLcWnd, BOOL bOn, int Width, int Height, int Zoom, int Flags);
//tflcWndMagnifier pflcWndMagnifier = 0;

typedef BOOL (LCAPI *tflcWndCoordFromDrw)(HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwin, int* pYwin);
tflcWndCoordFromDrw pflcWndCoordFromDrw = 0;

typedef BOOL (LCAPI *tflcWndCoordToDrw)(HANDLE hLcWnd, int Xwin, int Ywin, double* pXdrw, double* pYdrw);
tflcWndCoordToDrw pflcWndCoordToDrw = 0;

typedef BOOL (LCAPI *tflcCoordDrwToWnd)(HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwnd, int* pYwnd);
tflcCoordDrwToWnd pflcCoordDrwToWnd = 0;

typedef BOOL (LCAPI *tflcCoordWndToDrw)(HANDLE hLcWnd, int Xwnd, int Ywnd, double* pXdrw, double* pYdrw);
tflcCoordWndToDrw pflcCoordWndToDrw = 0;

typedef HANDLE (LCAPI *tflcFontGetFirst)();
tflcFontGetFirst pflcFontGetFirst = 0;

typedef HANDLE (LCAPI *tflcFontGetNext)(HANDLE hFont);
tflcFontGetNext pflcFontGetNext = 0;

typedef HANDLE (LCAPI *tflcFontAddRes)(LPCWSTR szFontName, HANDLE hModule, int idResource);
tflcFontAddRes pflcFontAddRes = 0;

typedef HANDLE (LCAPI *tflcFontAddFile)(LPCWSTR szFontName, LPCWSTR szFilename);
tflcFontAddFile pflcFontAddFile = 0;

typedef HANDLE (LCAPI *tflcFontAddBin)(LPCWSTR szFontName, HANDLE hData);
tflcFontAddBin pflcFontAddBin = 0;

typedef HANDLE (LCAPI *tflcFontGetChar)(HANDLE hFont, int CharCode);
tflcFontGetChar pflcFontGetChar = 0;

typedef BOOL (LCAPI *tflcProgressCreate)(HANDLE hLcWnd, int W, int H, LPCWSTR szTitle);
tflcProgressCreate pflcProgressCreate = 0;

typedef BOOL (LCAPI *tflcProgressSetText)(LPCWSTR szText);
tflcProgressSetText pflcProgressSetText = 0;

typedef BOOL (LCAPI *tflcProgressStart)(int MinVal, int MaxVal);
tflcProgressStart pflcProgressStart = 0;

typedef BOOL (LCAPI *tflcProgressSetPos)(int Val);
tflcProgressSetPos pflcProgressSetPos = 0;

typedef BOOL (LCAPI *tflcProgressInc)();
tflcProgressInc pflcProgressInc = 0;

typedef BOOL (LCAPI *tflcProgressDelete)();
tflcProgressDelete pflcProgressDelete = 0;

typedef HANDLE (LCAPI *tflcQuadCreate)();
tflcQuadCreate pflcQuadCreate = 0;

typedef BOOL (LCAPI *tflcQuadDelete)(HANDLE hQuad);
tflcQuadDelete pflcQuadDelete = 0;

typedef BOOL (LCAPI *tflcQuadSet)(HANDLE hQuad, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3);
tflcQuadSet pflcQuadSet = 0;

typedef BOOL (LCAPI *tflcQuadTransXYtoUV)(HANDLE hQuad, double X, double Y, double* pU, double* pV);
tflcQuadTransXYtoUV pflcQuadTransXYtoUV = 0;

typedef BOOL (LCAPI *tflcQuadTransUVtoXY)(HANDLE hQuad, double U, double V, double* pX, double* pY);
tflcQuadTransUVtoXY pflcQuadTransUVtoXY = 0;

typedef BOOL (LCAPI *tflcQuadContains)(HANDLE hQuad, double X, double Y);
tflcQuadContains pflcQuadContains = 0;

typedef HANDLE (LCAPI *tflcGridCreate)();
tflcGridCreate pflcGridCreate = 0;

typedef BOOL (LCAPI *tflcGridDelete)(HANDLE hGrid);
tflcGridDelete pflcGridDelete = 0;

typedef BOOL (LCAPI *tflcGridSet)(HANDLE hGrid, double X0, double Y0, double W, double H, int Nx, int Ny);
tflcGridSet pflcGridSet = 0;

typedef BOOL (LCAPI *tflcGridSetDest)(HANDLE hGrid, int Ix, int Iy, double X, double Y);
tflcGridSetDest pflcGridSetDest = 0;

typedef BOOL (LCAPI *tflcGridUpdate)(HANDLE hGrid);
tflcGridUpdate pflcGridUpdate = 0;

typedef BOOL (LCAPI *tflcGridTrans)(HANDLE hGrid, double X, double Y, double* pXdest, double* pYdest);
tflcGridTrans pflcGridTrans = 0;

typedef BOOL (LCAPI *tflcGridGetNode)(HANDLE hGrid, BOOL bDest, int Ix, int Iy, double* pX, double* pY);
tflcGridGetNode pflcGridGetNode = 0;

typedef BOOL (LCAPI *tflcGridGetCell)(HANDLE hGrid, double X, double Y, int* pIx, int* pIy);
tflcGridGetCell pflcGridGetCell = 0;

typedef BOOL (LCAPI *tflcGridSetView)(HANDLE hGrid, int Mode, HANDLE hLcWnd, COLORREF ColLine, COLORREF ColNode);
tflcGridSetView pflcGridSetView = 0;

typedef HANDLE (LCAPI *tflcTIN_Create)(int Id);
tflcTIN_Create pflcTIN_Create = 0;

typedef BOOL (LCAPI *tflcTIN_Delete)(HANDLE hTIN);
tflcTIN_Delete pflcTIN_Delete = 0;

typedef BOOL (LCAPI *tflcTIN_Load)(HANDLE hTIN, LPCWSTR szFileName, HANDLE hWnd);
tflcTIN_Load pflcTIN_Load = 0;

typedef BOOL (LCAPI *tflcTIN_GetZ)(HANDLE hTIN, double X, double Y, double* pZ);
tflcTIN_GetZ pflcTIN_GetZ = 0;

typedef int (LCAPI *tflcTIN_InterLine)(HANDLE hTIN, double X0, double Y0, double X1, double Y1);
tflcTIN_InterLine pflcTIN_InterLine = 0;

typedef BOOL (LCAPI *tflcTIN_InterGetPoint)(HANDLE hTIN, int iPnt, double* pX, double* pY, double* pZ);
tflcTIN_InterGetPoint pflcTIN_InterGetPoint = 0;

typedef HANDLE (LCAPI *tflcCreateProps)(HWND hWndParent);
tflcCreateProps pflcCreateProps = 0;

typedef BOOL (LCAPI *tflcDeleteProps)(HANDLE hPropWnd);
tflcDeleteProps pflcDeleteProps = 0;

typedef BOOL (LCAPI *tflcPropsResize)(HANDLE hPropWnd, int Left, int Top, int Width, int Height);
tflcPropsResize pflcPropsResize = 0;

typedef BOOL (LCAPI *tflcPropsUpdate)(HANDLE hPropWnd, BOOL bSelChanged);
tflcPropsUpdate pflcPropsUpdate = 0;

typedef HANDLE (LCAPI *tflcCreateStatbar)(HWND hWndParent);
tflcCreateStatbar pflcCreateStatbar = 0;

typedef BOOL (LCAPI *tflcDeleteStatbar)(HANDLE hStatbar);
tflcDeleteStatbar pflcDeleteStatbar = 0;

typedef BOOL (LCAPI *tflcStatbarResize)(HANDLE hStatbar, int Left, int Top, int Width, int Height);
tflcStatbarResize pflcStatbarResize = 0;

typedef BOOL (LCAPI *tflcStatbarCell)(HANDLE hStatbar, int Id, int Pos);
tflcStatbarCell pflcStatbarCell = 0;

typedef BOOL (LCAPI *tflcStatbarText)(HANDLE hStatbar, int Id, LPCWSTR szText);
tflcStatbarText pflcStatbarText = 0;

typedef BOOL (LCAPI *tflcStatbarRedraw)(HANDLE hStatbar);
tflcStatbarRedraw pflcStatbarRedraw = 0;

typedef BOOL (LCAPI *tflcDgGetValue)(HANDLE hWnd, int Lef, int Top, LPCWSTR szTitle, LPCWSTR szPrompt);
tflcDgGetValue pflcDgGetValue = 0;

typedef BOOL (LCAPI *tflcHelp)(LPCWSTR szTopic);
tflcHelp pflcHelp = 0;

typedef void (LCAPI *tflcGetPolarPoint)(double x0, double y0, double Angle, double Dist, double* pOutX, double* pOutY);
tflcGetPolarPoint pflcGetPolarPoint = 0;

typedef void (LCAPI *tflcGetPolarPrm)(double x1, double y1, double x2, double y2, double* pAngle, double* pDist);
tflcGetPolarPrm pflcGetPolarPrm = 0;

typedef BOOL (LCAPI *tflcGetClientSize)(HWND hWnd, int* pWidth, int* pHeight);
tflcGetClientSize pflcGetClientSize = 0;

typedef int (LCAPI *tflcGetErrorCode)();
tflcGetErrorCode pflcGetErrorCode = 0;

typedef LPCWSTR (LCAPI *tflcGetErrorStr)();
tflcGetErrorStr pflcGetErrorStr = 0;

typedef HANDLE (LCAPI *tflcCreateCommand)(HANDLE hLcWnd, int Id, LPCWSTR szTitle);
tflcCreateCommand pflcCreateCommand = 0;

typedef BOOL (LCAPI *tflcCmdExit)(HANDLE hCmd);
tflcCmdExit pflcCmdExit = 0;

typedef BOOL (LCAPI *tflcCmdCursorText)(HANDLE hCmd, LPCWSTR szText);
tflcCmdCursorText pflcCmdCursorText = 0;

typedef BOOL (LCAPI *tflcCmdMessage)(HANDLE hCmd, LPCWSTR szText, int IconType);
tflcCmdMessage pflcCmdMessage = 0;

typedef BOOL (LCAPI *tflcCmdResetLastPt)(HANDLE hCmd);
tflcCmdResetLastPt pflcCmdResetLastPt = 0;

typedef BOOL (LCAPI *tflcCameraConnect)(LPCWSTR szName);
tflcCameraConnect pflcCameraConnect = 0;

typedef BOOL (LCAPI *tflcCameraDisconnect)();
tflcCameraDisconnect pflcCameraDisconnect = 0;

typedef BOOL (LCAPI *tflcCameraShot)();
tflcCameraShot pflcCameraShot = 0;

typedef HANDLE (LCAPI *tflcCreateDrawing)();
tflcCreateDrawing pflcCreateDrawing = 0;

typedef BOOL (LCAPI *tflcDeleteDrawing)(HANDLE hDrw);
tflcDeleteDrawing pflcDeleteDrawing = 0;

typedef BOOL (LCAPI *tflcDrwNew)(HANDLE hDrw, LPCWSTR szFileName, HANDLE hLcWnd);
tflcDrwNew pflcDrwNew = 0;

typedef BOOL (LCAPI *tflcDrwLoad)(HANDLE hDrw, LPCWSTR szFileName, HANDLE hLcWnd);
tflcDrwLoad pflcDrwLoad = 0;

typedef BOOL (LCAPI *tflcDrwLoadMem)(HANDLE hDrw, HANDLE hMem, HANDLE hLcWnd);
tflcDrwLoadMem pflcDrwLoadMem = 0;

typedef BOOL (LCAPI *tflcDrwInsert)(HANDLE hDrw, LPCWSTR szFileName, int Overwrite, HANDLE hLcWnd);
tflcDrwInsert pflcDrwInsert = 0;

typedef BOOL (LCAPI *tflcDrwCopy)(HANDLE hDrw, HANDLE hDrwSrc);
tflcDrwCopy pflcDrwCopy = 0;

typedef BOOL (LCAPI *tflcDrwSave)(HANDLE hDrw, LPCWSTR szFileName, BOOL bBak, HANDLE hLcWnd);
tflcDrwSave pflcDrwSave = 0;

typedef int (LCAPI *tflcDrwSaveMem)(HANDLE hDrw, HANDLE hMem, int MemSize);
tflcDrwSaveMem pflcDrwSaveMem = 0;

typedef HANDLE (LCAPI *tflcDrwAddLayer)(HANDLE hDrw, LPCWSTR szName, LPCWSTR szColor, HANDLE hLtype, int Lwidth);
tflcDrwAddLayer pflcDrwAddLayer = 0;

typedef HANDLE (LCAPI *tflcDrwAddLinetype)(HANDLE hDrw, LPCWSTR szName, LPCWSTR szDefinition);
tflcDrwAddLinetype pflcDrwAddLinetype = 0;

typedef HANDLE (LCAPI *tflcDrwAddLinetypeF)(HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, LPCWSTR szLtypeName);
tflcDrwAddLinetypeF pflcDrwAddLinetypeF = 0;

typedef HANDLE (LCAPI *tflcDrwAddTextStyle)(HANDLE hDrw, LPCWSTR szName, LPCWSTR szFontName, BOOL bWinFont);
tflcDrwAddTextStyle pflcDrwAddTextStyle = 0;

typedef HANDLE (LCAPI *tflcDrwAddDimStyle)(HANDLE hDrw, LPCWSTR szName);
tflcDrwAddDimStyle pflcDrwAddDimStyle = 0;

typedef HANDLE (LCAPI *tflcDrwAddMlineStyle)(HANDLE hDrw, LPCWSTR szName);
tflcDrwAddMlineStyle pflcDrwAddMlineStyle = 0;

typedef HANDLE (LCAPI *tflcDrwAddPntStyle)(HANDLE hDrw, LPCWSTR szName, HANDLE hBlock, double BlockScale, HANDLE hTStyle, double TextHeight, double TextWidth);
tflcDrwAddPntStyle pflcDrwAddPntStyle = 0;

typedef HANDLE (LCAPI *tflcDrwAddImage)(HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName);
tflcDrwAddImage pflcDrwAddImage = 0;

typedef HANDLE (LCAPI *tflcDrwAddImage2)(HANDLE hDrw, LPCWSTR szName, int Width, int Height, int nBits);
tflcDrwAddImage2 pflcDrwAddImage2 = 0;

typedef HANDLE (LCAPI *tflcDrwAddImage3)(HANDLE hDrw, LPCWSTR szName, HANDLE hMem);
tflcDrwAddImage3 pflcDrwAddImage3 = 0;

typedef HANDLE (LCAPI *tflcDrwAddBlock)(HANDLE hDrw, LPCWSTR szName, double X, double Y);
tflcDrwAddBlock pflcDrwAddBlock = 0;

typedef HANDLE (LCAPI *tflcDrwAddBlockFromFile)(HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent);
tflcDrwAddBlockFromFile pflcDrwAddBlockFromFile = 0;

typedef HANDLE (LCAPI *tflcDrwAddBlockFromDrw)(HANDLE hDrw, LPCWSTR szName, HANDLE hDrw2, int Overwrite, HWND hwParent);
tflcDrwAddBlockFromDrw pflcDrwAddBlockFromDrw = 0;

typedef HANDLE (LCAPI *tflcDrwAddBlockFile)(HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent);
tflcDrwAddBlockFile pflcDrwAddBlockFile = 0;

typedef HANDLE (LCAPI *tflcDrwAddBlockPaper)(HANDLE hDrw, LPCWSTR szName, int PaperSize, int Orient, double Width, double Height);
tflcDrwAddBlockPaper pflcDrwAddBlockPaper = 0;

typedef HANDLE (LCAPI *tflcDrwAddBlockCopy)(HANDLE hDrw, LPCWSTR szName, HANDLE hSrcBlock);
tflcDrwAddBlockCopy pflcDrwAddBlockCopy = 0;

typedef BOOL (LCAPI *tflcDrwDeleteObject)(HANDLE hDrw, HANDLE hObject);
tflcDrwDeleteObject pflcDrwDeleteObject = 0;

typedef int (LCAPI *tflcDrwDeleteUnused)(HANDLE hDrw, int ObjType);
tflcDrwDeleteUnused pflcDrwDeleteUnused = 0;

typedef int (LCAPI *tflcDrwCountObjects)(HANDLE hDrw, int ObjType);
tflcDrwCountObjects pflcDrwCountObjects = 0;

typedef BOOL (LCAPI *tflcDrwSortObjects)(HANDLE hDrw, int ObjType);
tflcDrwSortObjects pflcDrwSortObjects = 0;

typedef HANDLE (LCAPI *tflcDrwGetFirstObject)(HANDLE hDrw, int ObjType);
tflcDrwGetFirstObject pflcDrwGetFirstObject = 0;

typedef HANDLE (LCAPI *tflcDrwGetNextObject)(HANDLE hDrw, HANDLE hObject);
tflcDrwGetNextObject pflcDrwGetNextObject = 0;

typedef HANDLE (LCAPI *tflcDrwGetObjectByID)(HANDLE hDrw, int ObjType, int Id);
tflcDrwGetObjectByID pflcDrwGetObjectByID = 0;

typedef HANDLE (LCAPI *tflcDrwGetObjectByIDH)(HANDLE hDrw, int ObjType, LPCWSTR szId);
tflcDrwGetObjectByIDH pflcDrwGetObjectByIDH = 0;

typedef HANDLE (LCAPI *tflcDrwGetObjectByName)(HANDLE hDrw, int ObjType, LPCWSTR szName);
tflcDrwGetObjectByName pflcDrwGetObjectByName = 0;

typedef HANDLE (LCAPI *tflcDrwGetEntByID)(HANDLE hDrw, int Id);
tflcDrwGetEntByID pflcDrwGetEntByID = 0;

typedef HANDLE (LCAPI *tflcDrwGetEntByIDH)(HANDLE hDrw, LPCWSTR szId);
tflcDrwGetEntByIDH pflcDrwGetEntByIDH = 0;

typedef HANDLE (LCAPI *tflcDrwGetEntByKey)(HANDLE hDrw, int Key);
tflcDrwGetEntByKey pflcDrwGetEntByKey = 0;

typedef BOOL (LCAPI *tflcDrwClearXData)(HANDLE hDrw, int ObjType, int Mode);
tflcDrwClearXData pflcDrwClearXData = 0;

typedef BOOL (LCAPI *tflcDrwPurge)(HANDLE hDrw);
tflcDrwPurge pflcDrwPurge = 0;

typedef BOOL (LCAPI *tflcDrwExplode)(HANDLE hDrw, int Mode);
tflcDrwExplode pflcDrwExplode = 0;

typedef BOOL (LCAPI *tflcDrwSetLimits)(HANDLE hDrw, double Xmin, double Ymin, double Xmax, double Ymax);
tflcDrwSetLimits pflcDrwSetLimits = 0;

typedef BOOL (LCAPI *tflcDrwUndoRecord)(HANDLE hDrw, int Mode);
tflcDrwUndoRecord pflcDrwUndoRecord = 0;

typedef BOOL (LCAPI *tflcDrwUndo)(HANDLE hDrw, BOOL bRedo);
tflcDrwUndo pflcDrwUndo = 0;

typedef BOOL (LCAPI *tflcBlockSetViewRect)(HANDLE hBlock, double Xcen, double Ycen, double Width, double Height);
tflcBlockSetViewRect pflcBlockSetViewRect = 0;

typedef BOOL (LCAPI *tflcBlockSetViewRect2)(HANDLE hBlock, double Lef, double Bot, double Rig, double Top);
tflcBlockSetViewRect2 pflcBlockSetViewRect2 = 0;

typedef BOOL (LCAPI *tflcBlockSetPaperSize)(HANDLE hBlock, int PaperSize, int Orient, double Width, double Height);
tflcBlockSetPaperSize pflcBlockSetPaperSize = 0;

typedef BOOL (LCAPI *tflcBlockRasterize)(HANDLE hBlock, LPCWSTR szFileName, double Xmin, double Ymin, double Xmax, double Ymax, int ImgW, int ImgH);
tflcBlockRasterize pflcBlockRasterize = 0;

typedef BOOL (LCAPI *tflcBlockUpdate)(HANDLE hBlock, BOOL bUpdEnts, HANDLE hNewEnt);
tflcBlockUpdate pflcBlockUpdate = 0;

typedef BOOL (LCAPI *tflcBlockScale)(HANDLE hBlock, double Scale);
tflcBlockScale pflcBlockScale = 0;

typedef BOOL (LCAPI *tflcBlockClear)(HANDLE hBlock, HANDLE hLayer);
tflcBlockClear pflcBlockClear = 0;

typedef BOOL (LCAPI *tflcBlockPurge)(HANDLE hBlock);
tflcBlockPurge pflcBlockPurge = 0;

typedef BOOL (LCAPI *tflcBlockSortEnts)(HANDLE hBlock, BOOL bByLayers, HWND hWnd);
tflcBlockSortEnts pflcBlockSortEnts = 0;

typedef HANDLE (LCAPI *tflcBlockAddPoint)(HANDLE hBlock, double X, double Y);
tflcBlockAddPoint pflcBlockAddPoint = 0;

typedef HANDLE (LCAPI *tflcBlockAddPoint2)(HANDLE hBlock, double X, double Y, int PtMode, double PtSize);
tflcBlockAddPoint2 pflcBlockAddPoint2 = 0;

//typedef HANDLE (LCAPI *tflcBlockAddPtArray)(HANDLE hBlock, LPCWSTR szFileName, HWND hWnd);
//tflcBlockAddPtArray pflcBlockAddPtArray = 0;

typedef HANDLE (LCAPI *tflcBlockAddXline)(HANDLE hBlock, double X, double Y, double Angle, BOOL bRay);
tflcBlockAddXline pflcBlockAddXline = 0;

typedef HANDLE (LCAPI *tflcBlockAddXline2P)(HANDLE hBlock, double X, double Y, double X2, double Y2, BOOL bRay);
tflcBlockAddXline2P pflcBlockAddXline2P = 0;

typedef HANDLE (LCAPI *tflcBlockAddLine)(HANDLE hBlock, double X1, double Y1, double X2, double Y2);
tflcBlockAddLine pflcBlockAddLine = 0;

typedef HANDLE (LCAPI *tflcBlockAddLineDir)(HANDLE hBlock, double X, double Y, double Angle, double Dist);
tflcBlockAddLineDir pflcBlockAddLineDir = 0;

typedef HANDLE (LCAPI *tflcBlockAddLineTan)(HANDLE hBlock, HANDLE hEnt1, HANDLE hEnt2, int Mode);
tflcBlockAddLineTan pflcBlockAddLineTan = 0;

typedef HANDLE (LCAPI *tflcBlockAddPolyline)(HANDLE hBlock, int FitType, BOOL bClosed, BOOL bFilled);
tflcBlockAddPolyline pflcBlockAddPolyline = 0;

typedef HANDLE (LCAPI *tflcBlockAddSpline)(HANDLE hBlock, BOOL bClosed, BOOL bFilled);
tflcBlockAddSpline pflcBlockAddSpline = 0;

typedef HANDLE (LCAPI *tflcBlockAddMline)(HANDLE hBlock, int FitType, BOOL bClosed);
tflcBlockAddMline pflcBlockAddMline = 0;

typedef HANDLE (LCAPI *tflcBlockAddRect)(HANDLE hBlock, double Xc, double Yc, double Width, double Height, double Angle, BOOL bFilled);
tflcBlockAddRect pflcBlockAddRect = 0;

typedef HANDLE (LCAPI *tflcBlockAddRect2)(HANDLE hBlock, double Left, double Bottom, double Width, double Height, double Rad, BOOL bFilled);
tflcBlockAddRect2 pflcBlockAddRect2 = 0;

typedef HANDLE (LCAPI *tflcBlockAddCircle)(HANDLE hBlock, double X, double Y, double Radius, BOOL bFilled);
tflcBlockAddCircle pflcBlockAddCircle = 0;

typedef HANDLE (LCAPI *tflcBlockAddArc)(HANDLE hBlock, double X, double Y, double Radius, double StartAngle, double ArcAngle);
tflcBlockAddArc pflcBlockAddArc = 0;

typedef HANDLE (LCAPI *tflcBlockAddArc3P)(HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3);
tflcBlockAddArc3P pflcBlockAddArc3P = 0;

typedef HANDLE (LCAPI *tflcBlockAddEllipse)(HANDLE hBlock, double X, double Y, double R1, double R2, double RotAngle, double StartAngle, double ArcAngle);
tflcBlockAddEllipse pflcBlockAddEllipse = 0;

typedef HANDLE (LCAPI *tflcBlockAddText)(HANDLE hBlock, LPCWSTR szText, double X, double Y);
tflcBlockAddText pflcBlockAddText = 0;

typedef HANDLE (LCAPI *tflcBlockAddText2)(HANDLE hBlock, LPCWSTR szText, double X, double Y, int Align, double H, double WScale, double RotAngle, double Oblique);
tflcBlockAddText2 pflcBlockAddText2 = 0;

typedef HANDLE (LCAPI *tflcBlockAddText3)(HANDLE hBlock, LPCWSTR szText, double X1, double Y1, double X2, double Y2, int Align, double HW, double Oblique);
tflcBlockAddText3 pflcBlockAddText3 = 0;

typedef HANDLE (LCAPI *tflcBlockAddMText)(HANDLE hBlock, LPCWSTR szText, double X, double Y, double WrapWidth, int Align, double RotAngle, double H, double WScale);
tflcBlockAddMText pflcBlockAddMText = 0;

typedef HANDLE (LCAPI *tflcBlockAddArcText)(HANDLE hBlock, LPCWSTR szText, double X, double Y, double Radius, double StartAngle, BOOL bClockwise, double H, double WScale, int Align);
tflcBlockAddArcText pflcBlockAddArcText = 0;

typedef HANDLE (LCAPI *tflcBlockAddBlockRef)(HANDLE hBlock, HANDLE hRefBlock, double X, double Y, double Scal, double Angle);
tflcBlockAddBlockRef pflcBlockAddBlockRef = 0;

typedef HANDLE (LCAPI *tflcBlockAddBlockRefID)(HANDLE hBlock, int idRefBlock, double X, double Y, double Scal, double Angle);
tflcBlockAddBlockRefID pflcBlockAddBlockRefID = 0;

typedef HANDLE (LCAPI *tflcBlockAddBlockRefIDH)(HANDLE hBlock, LPCWSTR szIdRefBlock, double X, double Y, double Scal, double Angle);
tflcBlockAddBlockRefIDH pflcBlockAddBlockRefIDH = 0;

//typedef HANDLE (LCAPI *tflcBlockAddXref)(HANDLE hBlock, LPCWSTR szFileName, double X, double Y, double ScalX, double ScalY, double Angle);
//tflcBlockAddXref pflcBlockAddXref = 0;

typedef HANDLE (LCAPI *tflcBlockAddImageRef)(HANDLE hBlock, HANDLE hImage, double X, double Y, double Width, double Height, BOOL bBorder);
tflcBlockAddImageRef pflcBlockAddImageRef = 0;

typedef HANDLE (LCAPI *tflcBlockAddEcw)(HANDLE hBlock, LPCWSTR szFileName);
tflcBlockAddEcw pflcBlockAddEcw = 0;

typedef HANDLE (LCAPI *tflcBlockAddBarcode)(HANDLE hBlock, int BarType, double Xc, double Yc, double Width, double Height, LPCWSTR szText);
tflcBlockAddBarcode pflcBlockAddBarcode = 0;

typedef HANDLE (LCAPI *tflcBlockAddHatch)(HANDLE hBlock, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle);
tflcBlockAddHatch pflcBlockAddHatch = 0;

typedef HANDLE (LCAPI *tflcBlockAddViewport)(HANDLE hBlock, double Lef, double Bot, double Width, double Height, double DrwPntX, double DrwPntY, double DrwScale, double DrwAngle);
tflcBlockAddViewport pflcBlockAddViewport = 0;

typedef HANDLE (LCAPI *tflcBlockAddFace)(HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2);
tflcBlockAddFace pflcBlockAddFace = 0;

typedef HANDLE (LCAPI *tflcBlockAddFace4)(HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
tflcBlockAddFace4 pflcBlockAddFace4 = 0;

typedef HANDLE (LCAPI *tflcBlockAddLeader)(HANDLE hBlock, LPCWSTR szText, double Xt, double Yt, double LandDist, double Xa, double Ya, int Attach, int Align);
tflcBlockAddLeader pflcBlockAddLeader = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimLin)(HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, double Angle, LPCWSTR szText);
tflcBlockAddDimLin pflcBlockAddDimLin = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimHor)(HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Yt, LPCWSTR szText);
tflcBlockAddDimHor pflcBlockAddDimHor = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimVer)(HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, LPCWSTR szText);
tflcBlockAddDimVer pflcBlockAddDimVer = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimAli)(HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, LPCWSTR szText);
tflcBlockAddDimAli pflcBlockAddDimAli = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimAli2)(HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Dt, LPCWSTR szText);
tflcBlockAddDimAli2 pflcBlockAddDimAli2 = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimOrd)(HANDLE hBlock, double Xd, double Yd, double Xt, double Yt, BOOL bX, LPCWSTR szText);
tflcBlockAddDimOrd pflcBlockAddDimOrd = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimRad)(HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText);
tflcBlockAddDimRad pflcBlockAddDimRad = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimRad2)(HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText);
tflcBlockAddDimRad2 pflcBlockAddDimRad2 = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimDia)(HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText);
tflcBlockAddDimDia pflcBlockAddDimDia = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimDia2)(HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText);
tflcBlockAddDimDia2 pflcBlockAddDimDia2 = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimAng)(HANDLE hBlock, double Xc, double Yc, double X1, double Y1, double X2, double Y2, double Xa, double Ya, double TextPos, LPCWSTR szText);
tflcBlockAddDimAng pflcBlockAddDimAng = 0;

typedef HANDLE (LCAPI *tflcBlockAddDimAng2)(HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3, double X4, double Y4, double Xa, double Ya, double TextPos, LPCWSTR szText);
tflcBlockAddDimAng2 pflcBlockAddDimAng2 = 0;

typedef HANDLE (LCAPI *tflcBlockAddRPlan)(HANDLE hBlock);
tflcBlockAddRPlan pflcBlockAddRPlan = 0;

typedef HANDLE (LCAPI *tflcBlockAddArrow)(HANDLE hBlock, double X1, double Y1, double X2, double Y2);
tflcBlockAddArrow pflcBlockAddArrow = 0;

typedef HANDLE (LCAPI *tflcBlockAddSpiral)(HANDLE hBlock, double Xc, double Yc, double R, double Turns, BOOL bDirCW, BOOL bClosed);
tflcBlockAddSpiral pflcBlockAddSpiral = 0;

typedef HANDLE (LCAPI *tflcBlockAddCamview)(HANDLE hBlock, double Lef, double Bot, double Width, double Height);
tflcBlockAddCamview pflcBlockAddCamview = 0;

typedef HANDLE (LCAPI *tflcBlockAddClone)(HANDLE hBlock, HANDLE hEnt);
tflcBlockAddClone pflcBlockAddClone = 0;

typedef HANDLE (LCAPI *tflcBlockGetFirstEnt)(HANDLE hBlock);
tflcBlockGetFirstEnt pflcBlockGetFirstEnt = 0;

typedef HANDLE (LCAPI *tflcBlockGetNextEnt)(HANDLE hBlock, HANDLE hEnt);
tflcBlockGetNextEnt pflcBlockGetNextEnt = 0;

typedef HANDLE (LCAPI *tflcBlockGetLastEnt)(HANDLE hBlock);
tflcBlockGetLastEnt pflcBlockGetLastEnt = 0;

typedef HANDLE (LCAPI *tflcBlockGetPrevEnt)(HANDLE hBlock, HANDLE hEnt);
tflcBlockGetPrevEnt pflcBlockGetPrevEnt = 0;

typedef HANDLE (LCAPI *tflcBlockGetEntByID)(HANDLE hBlock, int Id);
tflcBlockGetEntByID pflcBlockGetEntByID = 0;

typedef HANDLE (LCAPI *tflcBlockGetEntByIDH)(HANDLE hBlock, LPCWSTR szId);
tflcBlockGetEntByIDH pflcBlockGetEntByIDH = 0;

typedef HANDLE (LCAPI *tflcBlockGetEntByKey)(HANDLE hBlock, int Key);
tflcBlockGetEntByKey pflcBlockGetEntByKey = 0;

typedef BOOL (LCAPI *tflcBlockUnselect)(HANDLE hBlock);
tflcBlockUnselect pflcBlockUnselect = 0;

typedef BOOL (LCAPI *tflcBlockSelectEnt)(HANDLE hBlock, HANDLE hEntity, BOOL bSelect);
tflcBlockSelectEnt pflcBlockSelectEnt = 0;

typedef BOOL (LCAPI *tflcBlockSelErase)(HANDLE hBlock);
tflcBlockSelErase pflcBlockSelErase = 0;

typedef BOOL (LCAPI *tflcBlockSelMove)(HANDLE hBlock, double dX, double dY, BOOL bCopy, BOOL bNewSelect);
tflcBlockSelMove pflcBlockSelMove = 0;

typedef BOOL (LCAPI *tflcBlockSelScale)(HANDLE hBlock, double X0, double Y0, double Scal, BOOL bCopy, BOOL bNewSelect);
tflcBlockSelScale pflcBlockSelScale = 0;

typedef BOOL (LCAPI *tflcBlockSelRotate)(HANDLE hBlock, double X0, double Y0, double Angle, BOOL bCopy, BOOL bNewSelect);
tflcBlockSelRotate pflcBlockSelRotate = 0;

typedef BOOL (LCAPI *tflcBlockSelMirror)(HANDLE hBlock, double X1, double Y1, double X2, double Y2, BOOL bCopy, BOOL bNewSelect);
tflcBlockSelMirror pflcBlockSelMirror = 0;

typedef BOOL (LCAPI *tflcBlockSelExplode)(HANDLE hBlock);
tflcBlockSelExplode pflcBlockSelExplode = 0;

typedef HANDLE (LCAPI *tflcBlockSelJoin)(HANDLE hBlock, double Delta);
tflcBlockSelJoin pflcBlockSelJoin = 0;

typedef BOOL (LCAPI *tflcBlockSelAlign)(HANDLE hBlock, int Mode, double X, double Y);
tflcBlockSelAlign pflcBlockSelAlign = 0;

//typedef HANDLE (LCAPI *tflcBlockSelBlock)(HANDLE hBlock, LPCWSTR szName, double X, double Y, int Mode, BOOL bOverwrite);
//tflcBlockSelBlock pflcBlockSelBlock = 0;

typedef HANDLE (LCAPI *tflcBlockGetFirstSel)(HANDLE hBlock);
tflcBlockGetFirstSel pflcBlockGetFirstSel = 0;

typedef HANDLE (LCAPI *tflcBlockGetNextSel)(HANDLE hBlock);
tflcBlockGetNextSel pflcBlockGetNextSel = 0;

typedef BOOL (LCAPI *tflcBlockOrderByLayers)(HANDLE hBlock, HWND hWnd);
tflcBlockOrderByLayers pflcBlockOrderByLayers = 0;

typedef BOOL (LCAPI *tflcBlockSortTSP)(HANDLE hBlock, HANDLE hLayer, HWND hWnd);
tflcBlockSortTSP pflcBlockSortTSP = 0;

typedef double (LCAPI *tflcBlockGetJumpsLen)(HANDLE hBlock, HANDLE hLayer, HWND hWnd);
tflcBlockGetJumpsLen pflcBlockGetJumpsLen = 0;

typedef BOOL (LCAPI *tflcLayerClear)(HANDLE hLayer, HANDLE hBlock);
tflcLayerClear pflcLayerClear = 0;

typedef BOOL (LCAPI *tflcEntErase)(HANDLE hEnt, BOOL bErase);
tflcEntErase pflcEntErase = 0;

typedef BOOL (LCAPI *tflcEntMove)(HANDLE hEnt, double dX, double dY);
tflcEntMove pflcEntMove = 0;

typedef BOOL (LCAPI *tflcEntScale)(HANDLE hEnt, double X0, double Y0, double Scal);
tflcEntScale pflcEntScale = 0;

typedef BOOL (LCAPI *tflcEntRotate)(HANDLE hEnt, double X0, double Y0, double Angle);
tflcEntRotate pflcEntRotate = 0;

typedef BOOL (LCAPI *tflcEntMirror)(HANDLE hEnt, double X1, double Y1, double X2, double Y2);
tflcEntMirror pflcEntMirror = 0;

typedef BOOL (LCAPI *tflcEntExplode)(HANDLE hEnt, BOOL bSelect);
tflcEntExplode pflcEntExplode = 0;

typedef BOOL (LCAPI *tflcEntOffset)(HANDLE hEnt, double Dist);
tflcEntOffset pflcEntOffset = 0;

typedef BOOL (LCAPI *tflcEntToTop)(HANDLE hEnt);
tflcEntToTop pflcEntToTop = 0;

typedef BOOL (LCAPI *tflcEntToBottom)(HANDLE hEnt);
tflcEntToBottom pflcEntToBottom = 0;

typedef BOOL (LCAPI *tflcEntToAbove)(HANDLE hEnt, HANDLE hEnt2);
tflcEntToAbove pflcEntToAbove = 0;

typedef BOOL (LCAPI *tflcEntToUnder)(HANDLE hEnt, HANDLE hEnt2);
tflcEntToUnder pflcEntToUnder = 0;

typedef BOOL (LCAPI *tflcEntGetGrip)(HANDLE hEnt, int iGrip, double* pX, double* pY);
tflcEntGetGrip pflcEntGetGrip = 0;

typedef BOOL (LCAPI *tflcEntPutGrip)(HANDLE hEnt, int iGrip, double X, double Y);
tflcEntPutGrip pflcEntPutGrip = 0;

typedef BOOL (LCAPI *tflcEntUpdate)(HANDLE hEnt);
tflcEntUpdate pflcEntUpdate = 0;

typedef BOOL (LCAPI *tflcEntCopyBase)(HANDLE hEnt, HANDLE hEntFrom);
tflcEntCopyBase pflcEntCopyBase = 0;

typedef int (LCAPI *tflcIntersection)(HANDLE hEnt, HANDLE hEnt2);
tflcIntersection pflcIntersection = 0;

typedef BOOL (LCAPI *tflcInterGetPoint)(int iPoint, double* pX, double* pY);
tflcInterGetPoint pflcInterGetPoint = 0;

typedef HANDLE (LCAPI *tflcPlineAddVer)(HANDLE hPline, HANDLE hVer, double X, double Y);
tflcPlineAddVer pflcPlineAddVer = 0;

typedef HANDLE (LCAPI *tflcPlineAddVer2)(HANDLE hPline, HANDLE hVer, double X, double Y, double Param, double W0, double W1);
tflcPlineAddVer2 pflcPlineAddVer2 = 0;

typedef HANDLE (LCAPI *tflcPlineAddVerDir)(HANDLE hPline, HANDLE hVer, double Ang, double Length);
tflcPlineAddVerDir pflcPlineAddVerDir = 0;

typedef BOOL (LCAPI *tflcPlineEnd)(HANDLE hPline);
tflcPlineEnd pflcPlineEnd = 0;

//typedef BOOL (LCAPI *tflcPlineFromPtbuf)(HANDLE hPline, HANDLE hPtbuf);
//tflcPlineFromPtbuf pflcPlineFromPtbuf = 0;

//typedef BOOL (LCAPI *tflcPlineFromMpgon)(HANDLE hPline, HANDLE hMpgon);
//tflcPlineFromMpgon pflcPlineFromMpgon = 0;

typedef BOOL (LCAPI *tflcPlineDeleteVer)(HANDLE hPline, HANDLE hVer);
tflcPlineDeleteVer pflcPlineDeleteVer = 0;

typedef HANDLE (LCAPI *tflcPlineGetFirstVer)(HANDLE hPline);
tflcPlineGetFirstVer pflcPlineGetFirstVer = 0;

typedef HANDLE (LCAPI *tflcPlineGetNextVer)(HANDLE hPline, HANDLE hVer);
tflcPlineGetNextVer pflcPlineGetNextVer = 0;

typedef HANDLE (LCAPI *tflcPlineGetLastVer)(HANDLE hPline);
tflcPlineGetLastVer pflcPlineGetLastVer = 0;

typedef HANDLE (LCAPI *tflcPlineGetPrevVer)(HANDLE hPline, HANDLE hVer);
tflcPlineGetPrevVer pflcPlineGetPrevVer = 0;

typedef HANDLE (LCAPI *tflcPlineGetVer)(HANDLE hPline, int Index);
tflcPlineGetVer pflcPlineGetVer = 0;

typedef HANDLE (LCAPI *tflcPlineGetVerPt)(HANDLE hPline, double X, double Y, double Delta);
tflcPlineGetVerPt pflcPlineGetVerPt = 0;

typedef HANDLE (LCAPI *tflcPlineGetSeg)(HANDLE hPline, double X, double Y, double Delta);
tflcPlineGetSeg pflcPlineGetSeg = 0;

typedef BOOL (LCAPI *tflcPlineReverse)(HANDLE hPline);
tflcPlineReverse pflcPlineReverse = 0;

typedef int (LCAPI *tflcPlineContainPoint)(HANDLE hPline, double X, double Y);
tflcPlineContainPoint pflcPlineContainPoint = 0;

typedef BOOL (LCAPI *tflcPlineGetRoundPrm)(HANDLE hPline, HANDLE hVer, double* px0, double* py0, double* pBulge, double* px1, double* py1);
tflcPlineGetRoundPrm pflcPlineGetRoundPrm = 0;

typedef BOOL (LCAPI *tflcXlinePutDir)(HANDLE hXline, double X, double Y);
tflcXlinePutDir pflcXlinePutDir = 0;

typedef int (LCAPI *tflcRectGetPolyline)(HANDLE hRect, double* pX, double* pY, double* pBulge);
tflcRectGetPolyline pflcRectGetPolyline = 0;

typedef BOOL (LCAPI *tflcImgRefGetPixel)(HANDLE hImgRef, int iX, int iY, double* pX, double* pY, int* pColor);
tflcImgRefGetPixel pflcImgRefGetPixel = 0;

//typedef BOOL (LCAPI *tflcImgRefResize)(HANDLE hImgRef, int NewWidth, int NewHeight, int Method);
//tflcImgRefResize pflcImgRefResize = 0;

typedef BOOL (LCAPI *tflcHatchSetPattern)(HANDLE hHatch, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle);
tflcHatchSetPattern pflcHatchSetPattern = 0;

typedef BOOL (LCAPI *tflcHatchBoundStart)(HANDLE hHatch);
tflcHatchBoundStart pflcHatchBoundStart = 0;

typedef BOOL (LCAPI *tflcHatchBoundPoint)(HANDLE hHatch, double X, double Y);
tflcHatchBoundPoint pflcHatchBoundPoint = 0;

//typedef BOOL (LCAPI *tflcHatchBoundEntity)(HANDLE hHatch, HANDLE hEnt);
//tflcHatchBoundEntity pflcHatchBoundEntity = 0;

typedef BOOL (LCAPI *tflcHatchBoundEndLoop)(HANDLE hHatch);
tflcHatchBoundEndLoop pflcHatchBoundEndLoop = 0;

typedef BOOL (LCAPI *tflcHatchBoundEnd)(HANDLE hHatch);
tflcHatchBoundEnd pflcHatchBoundEnd = 0;

typedef BOOL (LCAPI *tflcHatchPatStart)(HANDLE hHatch);
tflcHatchPatStart pflcHatchPatStart = 0;

typedef BOOL (LCAPI *tflcHatchPatLine)(HANDLE hHatch, double Angle, double x0, double y0, double dx, double dy, int nDash, double L0, double L1, double L2, double L3, double L4, double L5, double L6, double L7);
tflcHatchPatLine pflcHatchPatLine = 0;

typedef BOOL (LCAPI *tflcHatchPatEnd)(HANDLE hHatch);
tflcHatchPatEnd pflcHatchPatEnd = 0;

typedef int (LCAPI *tflcHatchGetLoopSize)(HANDLE hHatch, int iLoop);
tflcHatchGetLoopSize pflcHatchGetLoopSize = 0;

typedef BOOL (LCAPI *tflcHatchGetPoint)(HANDLE hHatch, int iPnt, double* pX, double* pY);
tflcHatchGetPoint pflcHatchGetPoint = 0;

typedef HANDLE (LCAPI *tflcRPlanAddVer)(HANDLE hRPlan, double X, double Y);
tflcRPlanAddVer pflcRPlanAddVer = 0;

typedef BOOL (LCAPI *tflcRPlanSetCurve)(HANDLE hVer, double Radius, double LenClot1, double LenClot2);
tflcRPlanSetCurve pflcRPlanSetCurve = 0;

typedef BOOL (LCAPI *tflcRPlanSetPos)(HANDLE hVer, double X, double Y);
tflcRPlanSetPos pflcRPlanSetPos = 0;

typedef BOOL (LCAPI *tflcRPlanDeleteVer)(HANDLE hRPlan, HANDLE hVer);
tflcRPlanDeleteVer pflcRPlanDeleteVer = 0;

typedef HANDLE (LCAPI *tflcRPlanGetFirstVer)(HANDLE hRPlan);
tflcRPlanGetFirstVer pflcRPlanGetFirstVer = 0;

typedef HANDLE (LCAPI *tflcRPlanGetNextVer)(HANDLE hRPlan, HANDLE hVer);
tflcRPlanGetNextVer pflcRPlanGetNextVer = 0;

typedef HANDLE (LCAPI *tflcRPlanGetLastVer)(HANDLE hRPlan);
tflcRPlanGetLastVer pflcRPlanGetLastVer = 0;

typedef HANDLE (LCAPI *tflcRPlanGetPrevVer)(HANDLE hRPlan, HANDLE hVer);
tflcRPlanGetPrevVer pflcRPlanGetPrevVer = 0;

typedef HANDLE (LCAPI *tflcRPlanGetVer)(HANDLE hRPlan, int Index);
tflcRPlanGetVer pflcRPlanGetVer = 0;

typedef BOOL (LCAPI *tflcRPlanGetPoint)(HANDLE hRPlan, double Dist, double* pX, double* pY, double* pAngle, int* pSide);
tflcRPlanGetPoint pflcRPlanGetPoint = 0;

typedef BOOL (LCAPI *tflcRPlanGetDist)(HANDLE hRPlan, double X, double Y, double* pX2, double* pY2, double* pDist, double* pOffset);
tflcRPlanGetDist pflcRPlanGetDist = 0;

//typedef BOOL (LCAPI *tflcVportSetView)(HANDLE hVport, double Xcen, double Ycen, double Scal, double Angle);
//tflcVportSetView pflcVportSetView = 0;

//typedef BOOL (LCAPI *tflcVportLayerDlg)(HANDLE hVport, HANDLE hLcWnd);
//tflcVportLayerDlg pflcVportLayerDlg = 0;

//typedef BOOL (LCAPI *tflcVportLayerCmd)(HANDLE hVport, int Cmd, HANDLE hLayer);
//tflcVportLayerCmd pflcVportLayerCmd = 0;

typedef BOOL (LCAPI *tflcColorIsRGB)(LPCWSTR szColor);
tflcColorIsRGB pflcColorIsRGB = 0;

typedef int (LCAPI *tflcColorGetRed)(LPCWSTR szColor);
tflcColorGetRed pflcColorGetRed = 0;

typedef int (LCAPI *tflcColorGetGreen)(LPCWSTR szColor);
tflcColorGetGreen pflcColorGetGreen = 0;

typedef int (LCAPI *tflcColorGetBlue)(LPCWSTR szColor);
tflcColorGetBlue pflcColorGetBlue = 0;

typedef int (LCAPI *tflcColorGetIndex)(LPCWSTR szColor);
tflcColorGetIndex pflcColorGetIndex = 0;

typedef BOOL (LCAPI *tflcColorToVal)(LPCWSTR szColor, int* pbRGB, int* pIndex, int* pR, int* pG, int* pB);
tflcColorToVal pflcColorToVal = 0;

typedef BOOL (LCAPI *tflcColorSetPalette)(int Index, int R, int G, int B);
tflcColorSetPalette pflcColorSetPalette = 0;

typedef BOOL (LCAPI *tflcColorGetPalette)(int Index, int* pR, int* pG, int* pB);
tflcColorGetPalette pflcColorGetPalette = 0;

typedef BOOL (LCAPI *tflcImageSetPixelRGB)(HANDLE hImage, int X, int Y, int Red, int Green, int Blue);
tflcImageSetPixelRGB pflcImageSetPixelRGB = 0;

typedef BOOL (LCAPI *tflcImageSetPixelI)(HANDLE hImage, int X, int Y, int iColor);
tflcImageSetPixelI pflcImageSetPixelI = 0;

typedef BOOL (LCAPI *tflcImageGetPixelRGB)(HANDLE hImage, int X, int Y, int* pRed, int* pGreen, int* pBlue);
tflcImageGetPixelRGB pflcImageGetPixelRGB = 0;

typedef BOOL (LCAPI *tflcImageGetPixelI)(HANDLE hImage, int X, int Y, int* piColor);
tflcImageGetPixelI pflcImageGetPixelI = 0;

typedef BOOL (LCAPI *tflcImageSetPalColor)(HANDLE hImage, int iColor, int Red, int Green, int Blue);
tflcImageSetPalColor pflcImageSetPalColor = 0;

typedef BOOL (LCAPI *tflcImageGetPalColor)(HANDLE hImage, int iColor, int* pRed, int* pGreen, int* pBlue);
tflcImageGetPalColor pflcImageGetPalColor = 0;

typedef BOOL (LCAPI *tflcImageLoad)(HANDLE hImage, LPCWSTR szFilename, HANDLE hWnd);
tflcImageLoad pflcImageLoad = 0;

typedef BOOL (LCAPI *tflcImageLoadDIB)(HANDLE hImage, HANDLE hDib2);
tflcImageLoadDIB pflcImageLoadDIB = 0;

typedef BOOL (LCAPI *tflcImageCopyQuad)(HANDLE hImage, HANDLE hImageSrc, UINT W, UINT H, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3);
tflcImageCopyQuad pflcImageCopyQuad = 0;

typedef BOOL (LCAPI *tflcFilletSetLines)(double L1x0, double L1y0, double L1x1, double L1y1, double L2x0, double L2y0, double L2x1, double L2y1);
tflcFilletSetLines pflcFilletSetLines = 0;

typedef BOOL (LCAPI *tflcFillet)(double Rad, double Bis, double Tang);
tflcFillet pflcFillet = 0;

typedef BOOL (LCAPI *tflcFilletGetPoint)(int iPnt, double* pX, double* pY);
tflcFilletGetPoint pflcFilletGetPoint = 0;

typedef BOOL (LCAPI *tflcWFieldSet)(HANDLE hDrw, double Lef, double Bot, double Width, double Height);
tflcWFieldSet pflcWFieldSet = 0;

typedef BOOL (LCAPI *tflcWFieldClear)(HANDLE hDrw);
tflcWFieldClear pflcWFieldClear = 0;

typedef int (LCAPI *tflcWFieldDivide)(HANDLE hDrw, int NumX, int NumY, BOOL bClearExist);
tflcWFieldDivide pflcWFieldDivide = 0;

typedef BOOL (LCAPI *tflcWFieldAddCR)(HANDLE hDrw, int ID, double Lef, double Bot, double Width, double Height);
tflcWFieldAddCR pflcWFieldAddCR = 0;

typedef BOOL (LCAPI *tflcWFieldSetCR)(HANDLE hDrw, int ID, double Lef, double Bot, double Width, double Height);
tflcWFieldSetCR pflcWFieldSetCR = 0;

typedef BOOL (LCAPI *tflcWFieldDeleteCR)(HANDLE hDrw, int ID);
tflcWFieldDeleteCR pflcWFieldDeleteCR = 0;

typedef BOOL (LCAPI *tflcWFieldActiveCR)(HANDLE hDrw, int ID);
tflcWFieldActiveCR pflcWFieldActiveCR = 0;

typedef BOOL (LCAPI *tflcWFieldSave)(HANDLE hDrw, LPCWSTR szFileName);
tflcWFieldSave pflcWFieldSave = 0;

typedef BOOL (LCAPI *tflcWFieldLoad)(HANDLE hDrw, LPCWSTR szFileName);
tflcWFieldLoad pflcWFieldLoad = 0;

typedef HANDLE (LCAPI *tflcWFieldFirstCR)(HANDLE hDrw);
tflcWFieldFirstCR pflcWFieldFirstCR = 0;

typedef HANDLE (LCAPI *tflcWFieldNextCR)(HANDLE hDrw, HANDLE hEnt);
tflcWFieldNextCR pflcWFieldNextCR = 0;

typedef int (LCAPI *tflcExpEntity)(HANDLE hEnt, int Flags, BOOL bUnrotate);
tflcExpEntity pflcExpEntity = 0;

typedef int (LCAPI *tflcExpGetPline)(double Delta);
tflcExpGetPline pflcExpGetPline = 0;

typedef BOOL (LCAPI *tflcExpGetVertex)(double* pX, double* pY);
tflcExpGetVertex pflcExpGetVertex = 0;

typedef BOOL (LCAPI *tflcGbrLoad)(HANDLE hLcWnd, LPCWSTR szFileName0);
tflcGbrLoad pflcGbrLoad = 0;

typedef BOOL (LCAPI *tflcGbrClose)(HANDLE hLcWnd);
tflcGbrClose pflcGbrClose = 0;

typedef LPCWSTR (LCAPI *tflcPlugGetOption)(LPCWSTR szFileName, LPCWSTR szKey);
tflcPlugGetOption pflcPlugGetOption = 0;

typedef BOOL (LCAPI *tflcPlugGetOption2)(LPCWSTR szFileName, LPCWSTR szKey);
tflcPlugGetOption2 pflcPlugGetOption2 = 0;

typedef BOOL (LCAPI *tflcPlugSetOption)(LPCWSTR szFileName, LPCWSTR szKey, LPCWSTR szValue, BOOL bSave);
tflcPlugSetOption pflcPlugSetOption = 0;

//typedef BOOL (LCAPI *tflcPrintSetup)(HANDLE hWnd);
//tflcPrintSetup pflcPrintSetup = 0;

//typedef BOOL (LCAPI *tflcPrintLayout)(HANDLE hBlock);
//tflcPrintLayout pflcPrintLayout = 0;

//typedef BOOL (LCAPI *tflcPrintBlock)(HANDLE hBlock, double X, double Y, double W, double H, double Scale, double PapLef, double PapTop);
//tflcPrintBlock pflcPrintBlock = 0;

typedef BOOL (LCAPI *tflc2_Initialize)();
tflc2_Initialize pflc2_Initialize = 0;

typedef BOOL (LCAPI *tflc2_Uninitialize)();
tflc2_Uninitialize pflc2_Uninitialize = 0;

typedef HANDLE (LCAPI *tflc2_Create)(HWND hWndParent, int Flags);
tflc2_Create pflc2_Create = 0;

typedef BOOL (LCAPI *tflc2_Delete)(HANDLE hFrame);
tflc2_Delete pflc2_Delete = 0;

typedef BOOL (LCAPI *tflc2_OnClose)(HANDLE hFrame);
tflc2_OnClose pflc2_OnClose = 0;

typedef BOOL (LCAPI *tflc2_Position)(HANDLE hFrame, int Left, int Top, int Width, int Height);
tflc2_Position pflc2_Position = 0;

typedef BOOL (LCAPI *tflc2_Command)(HANDLE hFrame, int Command, int CmdParam);
tflc2_Command pflc2_Command = 0;

typedef HANDLE (LCAPI *tflc2_GetWnd)(HANDLE hFrame);
tflc2_GetWnd pflc2_GetWnd = 0;

typedef HANDLE (LCAPI *tflc2_GetDrw)(HANDLE hFrame);
tflc2_GetDrw pflc2_GetDrw = 0;

typedef HANDLE (LCAPI *tflc2_GetBlock)(HANDLE hFrame);
tflc2_GetBlock pflc2_GetBlock = 0;

typedef BOOL (LCAPI *tflc2_FileLoad)(HANDLE hFrame, LPCWSTR szFileName);
tflc2_FileLoad pflc2_FileLoad = 0;

typedef BOOL (LCAPI *tflc2_FileSave)(HANDLE hFrame, LPCWSTR szFileName, BOOL bBak);
tflc2_FileSave pflc2_FileSave = 0;

typedef BOOL (LCAPI *tflc2_WFieldSave)(HANDLE hFrame, LPCWSTR szFileName);
tflc2_WFieldSave pflc2_WFieldSave = 0;

typedef BOOL (LCAPI *tflc2_WFieldLoad)(HANDLE hFrame, LPCWSTR szFileName);
tflc2_WFieldLoad pflc2_WFieldLoad = 0;

typedef int (LCAPI *tflc2_ExpStart)(HANDLE hFrame, int Mode);
tflc2_ExpStart pflc2_ExpStart = 0;

typedef int (LCAPI *tflc2_ExpGetPline)(HANDLE hFrame);
tflc2_ExpGetPline pflc2_ExpGetPline = 0;

typedef HANDLE (LCAPI *tflc2_ExpGetEntity)(HANDLE hFrame);
tflc2_ExpGetEntity pflc2_ExpGetEntity = 0;

typedef BOOL (LCAPI *tflc2_ExpGetVertex)(HANDLE hFrame, double* pX, double* pY);
tflc2_ExpGetVertex pflc2_ExpGetVertex = 0;

typedef BOOL (LCAPI *tflc2_ExpGetPoint)(HANDLE hFrame);
tflc2_ExpGetPoint pflc2_ExpGetPoint = 0;

typedef BOOL (LCAPI *tflc2_CbCopy)(HANDLE hFrame, double Lef, double Bot, double W, double H);
tflc2_CbCopy pflc2_CbCopy = 0;

typedef BOOL (LCAPI *tflc2_CbCopy2)(HANDLE hFrame, int idClipRect, BOOL bUnrotate);
tflc2_CbCopy2 pflc2_CbCopy2 = 0;

typedef BOOL (LCAPI *tflc2_CbPaste)(HANDLE hFrame, double Lef, double Bot);
tflc2_CbPaste pflc2_CbPaste = 0;

typedef BOOL (LCAPI *tflcMru_EnableFileExt)(LPCWSTR szFileExt);
tflcMru_EnableFileExt pflcMru_EnableFileExt = 0;

typedef BOOL (LCAPI *tflcMru_Load)(LPCWSTR szFileName);
tflcMru_Load pflcMru_Load = 0;

typedef BOOL (LCAPI *tflcMru_Save)();
tflcMru_Save pflcMru_Save = 0;

typedef BOOL (LCAPI *tflcMru_AddFile)(LPCWSTR szFileName, BOOL bFileHasView);
tflcMru_AddFile pflcMru_AddFile = 0;

typedef BOOL (LCAPI *tflcMru_SetImage)(LPCWSTR szFileName, BYTE* pImgBuf, int ImgSize);
tflcMru_SetImage pflcMru_SetImage = 0;

typedef BOOL (LCAPI *tflcMru_HasImage)(LPCWSTR szFileName);
tflcMru_HasImage pflcMru_HasImage = 0;

typedef BOOL (LCAPI *tflcMru_SetViewRect)(LPCWSTR szFileName, double Xmin, double Ymin, double Xmax, double Ymax);
tflcMru_SetViewRect pflcMru_SetViewRect = 0;

typedef BOOL (LCAPI *tflcMru_GetViewRect)(LPCWSTR szFileName, double* pXmin, double* pYmin, double* pXmax, double* pYmax);
tflcMru_GetViewRect pflcMru_GetViewRect = 0;

typedef BOOL (LCAPI *tflcMru_Dialog)(HWND hWnd, HANDLE hIcon, WCHAR* szFileName);
tflcMru_Dialog pflcMru_Dialog = 0;

typedef BOOL (LCAPI *tflcWndTabClear)(HANDLE hLcWnd);
tflcWndTabClear pflcWndTabClear = 0;

typedef BOOL (LCAPI *tflcWndTabAdd)(HANDLE hLcWnd, int TabID, LPCWSTR szLabel, LPCWSTR szTipText, HANDLE hObject);
tflcWndTabAdd pflcWndTabAdd = 0;

typedef BOOL (LCAPI *tflcWndTabSelect)(HANDLE hLcWnd, int TabID);
tflcWndTabSelect pflcWndTabSelect = 0;

typedef BOOL (LCAPI *tflcWndPaperEnable)(HANDLE hLcWnd, BOOL bEnable);
tflcWndPaperEnable pflcWndPaperEnable = 0;

typedef BOOL (LCAPI *tflcWndPaperSetSize)(HANDLE hLcWnd, int Size, int Orient);
tflcWndPaperSetSize pflcWndPaperSetSize = 0;

typedef BOOL (LCAPI *tflcWndPaperSetSize2)(HANDLE hLcWnd, double Width, double Height);
tflcWndPaperSetSize2 pflcWndPaperSetSize2 = 0;

typedef BOOL (LCAPI *tflcWndPaperSetPos)(HANDLE hLcWnd, double Left, double Bottom);
tflcWndPaperSetPos pflcWndPaperSetPos = 0;

typedef BOOL (LCAPI *tflcGripClear)(HANDLE hLcWnd);
tflcGripClear pflcGripClear = 0;

typedef BOOL (LCAPI *tflcGripAdd)(HANDLE hLcWnd, HANDLE hObj, int iGrip, int Typ, double X, double Y, double Ang, double X0, double Y0);
tflcGripAdd pflcGripAdd = 0;

typedef BOOL (LCAPI *tflcGripSet)(HANDLE hLcWnd, HANDLE hObj, int iGrip, double X, double Y, double Ang, double X0, double Y0);
tflcGripSet pflcGripSet = 0;

typedef HANDLE (LCAPI *tflcPaint_PenCreate)(HANDLE hLcWnd, int Id, COLORREF Color, double Width, int PenStyle);
tflcPaint_PenCreate pflcPaint_PenCreate = 0;

typedef BOOL (LCAPI *tflcPaint_PenSelect)(HANDLE hLcWnd, HANDLE hPen);
tflcPaint_PenSelect pflcPaint_PenSelect = 0;

typedef BOOL (LCAPI *tflcPaint_PenSelectID)(HANDLE hLcWnd, int IdPen);
tflcPaint_PenSelectID pflcPaint_PenSelectID = 0;

typedef HANDLE (LCAPI *tflcPaint_BrushCreate)(HANDLE hLcWnd, int Id, COLORREF Color, int Pattern, int Alpha);
tflcPaint_BrushCreate pflcPaint_BrushCreate = 0;

typedef BOOL (LCAPI *tflcPaint_BrushSelect)(HANDLE hLcWnd, HANDLE hBrush);
tflcPaint_BrushSelect pflcPaint_BrushSelect = 0;

typedef BOOL (LCAPI *tflcPaint_BrushSelectID)(HANDLE hLcWnd, int IdBrush);
tflcPaint_BrushSelectID pflcPaint_BrushSelectID = 0;

typedef BOOL (LCAPI *tflcPaint_DrawPtbuf)(HANDLE hLcWnd, HANDLE hPtbuf, BOOL bClosed);
tflcPaint_DrawPtbuf pflcPaint_DrawPtbuf = 0;

typedef BOOL (LCAPI *tflcPaint_DrawMpgon)(HANDLE hLcWnd, HANDLE hMpgon, BOOL bFill, BOOL bBorder);
tflcPaint_DrawMpgon pflcPaint_DrawMpgon = 0;

typedef BOOL (LCAPI *tflcPaint_DrawImage)(HANDLE hLcWnd, HANDLE hImage, double X, double Y, double PixelSize, int Transp, int TVal, HANDLE hPtbuf);
tflcPaint_DrawImage pflcPaint_DrawImage = 0;

typedef BOOL (LCAPI *tflcPaint_DrawImage2)(HANDLE hLcWnd, HANDLE hImage, double X, double Y, double W, double H, int Transp, int TVal, HANDLE hPtbuf);
tflcPaint_DrawImage2 pflcPaint_DrawImage2 = 0;

typedef BOOL (LCAPI *tflcPaint_DrawText)(HANDLE hLcWnd, double X, double Y, LPCWSTR szText);
tflcPaint_DrawText pflcPaint_DrawText = 0;

typedef BOOL (LCAPI *tflcPaint_DrawText2)(HANDLE hLcWnd, double X1, double Y1, double X2, double Y2, int Align, LPCWSTR szText);
tflcPaint_DrawText2 pflcPaint_DrawText2 = 0;

typedef BOOL (LCAPI *tflcPaint_DrawTextBC)(HANDLE hLcWnd, HANDLE hMpgon, double Gap, double Height, int Align, LPCWSTR szText);
tflcPaint_DrawTextBC pflcPaint_DrawTextBC = 0;

typedef BOOL (LCAPI *tflcPaint_DrawArcText)(HANDLE hLcWnd, LPCWSTR szText, double X, double Y, double Rad, double Ang0, BOOL bCW, double H, double WScale, int Align);
tflcPaint_DrawArcText pflcPaint_DrawArcText = 0;

typedef BOOL (LCAPI *tflcPaint_DrawHatch)(HANDLE hLcWnd, HANDLE hHatch);
tflcPaint_DrawHatch pflcPaint_DrawHatch = 0;

typedef BOOL (LCAPI *tflcPaint_DrawPoint)(HANDLE hLcWnd, double X, double Y, int PtMode, double PtSize);
tflcPaint_DrawPoint pflcPaint_DrawPoint = 0;

typedef BOOL (LCAPI *tflcPaint_DrawLine)(HANDLE hLcWnd, double X1, double Y1, double X2, double Y2);
tflcPaint_DrawLine pflcPaint_DrawLine = 0;

typedef BOOL (LCAPI *tflcPaint_DrawXline)(HANDLE hLcWnd, double X, double Y, double Angle, BOOL bRay);
tflcPaint_DrawXline pflcPaint_DrawXline = 0;

typedef BOOL (LCAPI *tflcPaint_DrawRect)(HANDLE hLcWnd, double Xc, double Yc, double Width, double Height);
tflcPaint_DrawRect pflcPaint_DrawRect = 0;

typedef BOOL (LCAPI *tflcPaint_DrawRect2)(HANDLE hLcWnd, double X1, double Y1, double X2, double Y2);
tflcPaint_DrawRect2 pflcPaint_DrawRect2 = 0;

//typedef BOOL (LCAPI *tflcPaint_DrawPickBox)(HANDLE hLcWnd);
//tflcPaint_DrawPickBox pflcPaint_DrawPickBox = 0;

typedef BOOL (LCAPI *tflcPaint_DrawTIN)(HANDLE hLcWnd, HANDLE hTIN);
tflcPaint_DrawTIN pflcPaint_DrawTIN = 0;

typedef BOOL (LCAPI *tflcPaint_DrawGrid)(HANDLE hLcWnd, HANDLE hGrid, BOOL bDest, COLORREF ColLine, COLORREF ColNode);
tflcPaint_DrawGrid pflcPaint_DrawGrid = 0;

typedef BOOL (LCAPI *tflcPaint_DrawCPrompt)(HANDLE hLcWnd, int X, int Y, int Align, LPCWSTR szText);
tflcPaint_DrawCPrompt pflcPaint_DrawCPrompt = 0;

//typedef void (LCAPI *tflcPaint_SetPixel)(HANDLE hDC, int X, int Y, COLORREF Color);
//tflcPaint_SetPixel pflcPaint_SetPixel = 0;

typedef HANDLE (LCAPI *tflcPaint_CreatePtbuf)();
tflcPaint_CreatePtbuf pflcPaint_CreatePtbuf = 0;

typedef BOOL (LCAPI *tflcPaint_DeletePtbuf)(HANDLE hPtbuf);
tflcPaint_DeletePtbuf pflcPaint_DeletePtbuf = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufClear)(HANDLE hPtbuf);
tflcPaint_PtbufClear pflcPaint_PtbufClear = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddPoint)(HANDLE hPtbuf, double X, double Y, double Prm1, double Prm2, int IntPrm);
tflcPaint_PtbufAddPoint pflcPaint_PtbufAddPoint = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddPoint2)(HANDLE hPtbuf, double X, double Y);
tflcPaint_PtbufAddPoint2 pflcPaint_PtbufAddPoint2 = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddPointP)(HANDLE hPtbuf, double Angle, double Dist);
tflcPaint_PtbufAddPointP pflcPaint_PtbufAddPointP = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddLine)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2);
tflcPaint_PtbufAddLine pflcPaint_PtbufAddLine = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddLineP)(HANDLE hPtbuf, double X, double Y, double Angle, double Dist);
tflcPaint_PtbufAddLineP pflcPaint_PtbufAddLineP = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddCircle)(HANDLE hPtbuf, double Xc, double Yc, double R, int Resol);
tflcPaint_PtbufAddCircle pflcPaint_PtbufAddCircle = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddCircle2)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, int Resol);
tflcPaint_PtbufAddCircle2 pflcPaint_PtbufAddCircle2 = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddCircle3)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double X3, double Y3, BOOL bInside, int Resol);
tflcPaint_PtbufAddCircle3 pflcPaint_PtbufAddCircle3 = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArc)(HANDLE hPtbuf, double Xc, double Yc, double R, double StartAngle, double ArcAngle, int Resol);
tflcPaint_PtbufAddArc pflcPaint_PtbufAddArc = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArc3p)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double X3, double Y3, int Resol);
tflcPaint_PtbufAddArc3p pflcPaint_PtbufAddArc3p = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcSDE)(HANDLE hPtbuf, double Xs, double Ys, double DirAng, double Xe, double Ye, int Resol);
tflcPaint_PtbufAddArcSDE pflcPaint_PtbufAddArcSDE = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcSDAR)(HANDLE hPtbuf, double Xs, double Ys, double DirAng, double AngArc, double R, int Resol);
tflcPaint_PtbufAddArcSDAR pflcPaint_PtbufAddArcSDAR = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcSER)(HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double Radius, BOOL bClockwise, int Resol);
tflcPaint_PtbufAddArcSER pflcPaint_PtbufAddArcSER = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcSEL)(HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double ArcLen, BOOL bClockwise, int Resol);
tflcPaint_PtbufAddArcSEL pflcPaint_PtbufAddArcSEL = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcSEA)(HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double AngArc, int Resol);
tflcPaint_PtbufAddArcSEA pflcPaint_PtbufAddArcSEA = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcSEB)(HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double Bulge, int Resol);
tflcPaint_PtbufAddArcSEB pflcPaint_PtbufAddArcSEB = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcCSE)(HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double Xe, double Ye, BOOL bClockwise, int Resol);
tflcPaint_PtbufAddArcCSE pflcPaint_PtbufAddArcCSE = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcCSA)(HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double AngArc, int Resol);
tflcPaint_PtbufAddArcCSA pflcPaint_PtbufAddArcCSA = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcCSL)(HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double ChordLen, BOOL bClockwise, int Resol);
tflcPaint_PtbufAddArcCSL pflcPaint_PtbufAddArcCSL = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddArcCRAA)(HANDLE hPtbuf, double Xc, double Yc, double R, double AngStart, double AngEnd, BOOL bClockwise, int Resol);
tflcPaint_PtbufAddArcCRAA pflcPaint_PtbufAddArcCRAA = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddEllipse)(HANDLE hPtbuf, double Xc, double Yc, double Rmaj, double Rmin, double RotAng, double StartAng, double ArcAng, int Resol);
tflcPaint_PtbufAddEllipse pflcPaint_PtbufAddEllipse = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddEllipse2)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, int Resol);
tflcPaint_PtbufAddEllipse2 pflcPaint_PtbufAddEllipse2 = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddRect)(HANDLE hPtbuf, double Xc, double Yc, double W, double H, double Angle, double R, int Resol);
tflcPaint_PtbufAddRect pflcPaint_PtbufAddRect = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddRect2)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double R, int Resol);
tflcPaint_PtbufAddRect2 pflcPaint_PtbufAddRect2 = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddRect3)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double W, int Align, double R, int Resol);
tflcPaint_PtbufAddRect3 pflcPaint_PtbufAddRect3 = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddWline)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double W, int Align, BOOL bArc, int Resol);
tflcPaint_PtbufAddWline pflcPaint_PtbufAddWline = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufAddPtbuf)(HANDLE hPtbuf, HANDLE hPtbuf2);
tflcPaint_PtbufAddPtbuf pflcPaint_PtbufAddPtbuf = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufGetPoint)(HANDLE hPtbuf, int Mode, double* pX, double* pY);
tflcPaint_PtbufGetPoint pflcPaint_PtbufGetPoint = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufGetPoint2)(HANDLE hPtbuf, int Mode, double* pX, double* pY, double* pPrm1, double* pPrm2, int* pIntPrm);
tflcPaint_PtbufGetPoint2 pflcPaint_PtbufGetPoint2 = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufInterpolate)(HANDLE hPtbuf, BOOL bClosed, HANDLE hPtbufDest, int Mode, int Resol);
tflcPaint_PtbufInterpolate pflcPaint_PtbufInterpolate = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufMove)(HANDLE hPtbuf, double dx, double dy);
tflcPaint_PtbufMove pflcPaint_PtbufMove = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufRotate)(HANDLE hPtbuf, double Xc, double Yc, double Angle);
tflcPaint_PtbufRotate pflcPaint_PtbufRotate = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufScale)(HANDLE hPtbuf, double Xc, double Yc, double ScaleX, double ScaleY);
tflcPaint_PtbufScale pflcPaint_PtbufScale = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufMirror)(HANDLE hPtbuf, double X1, double Y1, double X2, double Y2);
tflcPaint_PtbufMirror pflcPaint_PtbufMirror = 0;

typedef BOOL (LCAPI *tflcPaint_PtbufCopy)(HANDLE hPtbuf, HANDLE hPtbufDest);
tflcPaint_PtbufCopy pflcPaint_PtbufCopy = 0;

typedef HANDLE (LCAPI *tflcPaint_CreateMpgon)();
tflcPaint_CreateMpgon pflcPaint_CreateMpgon = 0;

typedef BOOL (LCAPI *tflcPaint_DeleteMpgon)(HANDLE hMpgon);
tflcPaint_DeleteMpgon pflcPaint_DeleteMpgon = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonClear)(HANDLE hMpgon);
tflcPaint_MpgonClear pflcPaint_MpgonClear = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonAddPgon)(HANDLE hMpgon, HANDLE hPtbuf);
tflcPaint_MpgonAddPgon pflcPaint_MpgonAddPgon = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonAddText)(HANDLE hMpgon, HANDLE hFont, double X, double Y, LPCWSTR szText, int Resol);
tflcPaint_MpgonAddText pflcPaint_MpgonAddText = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonAddBarcode)(HANDLE hMpgon, int BarType, double Xc, double Yc, double Width, double Height, LPCWSTR szText);
tflcPaint_MpgonAddBarcode pflcPaint_MpgonAddBarcode = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonMove)(HANDLE hMpgon, double dx, double dy);
tflcPaint_MpgonMove pflcPaint_MpgonMove = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonRotate)(HANDLE hMpgon, double Xc, double Yc, double Angle);
tflcPaint_MpgonRotate pflcPaint_MpgonRotate = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonScale)(HANDLE hMpgon, double Xc, double Yc, double ScaleX, double ScaleY);
tflcPaint_MpgonScale pflcPaint_MpgonScale = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonMirror)(HANDLE hMpgon, double X1, double Y1, double X2, double Y2);
tflcPaint_MpgonMirror pflcPaint_MpgonMirror = 0;

typedef BOOL (LCAPI *tflcPaint_MpgonCopy)(HANDLE hMpgon, HANDLE hMpgonDest);
tflcPaint_MpgonCopy pflcPaint_MpgonCopy = 0;

typedef BOOL (LCAPI *tflcPaint_HatchGen)(HANDLE hMpgon, HANDLE hHatch, double Dist, double Angle, double W, double Beamc1, double Beamc2, double StartOff, double EndOff);
tflcPaint_HatchGen pflcPaint_HatchGen = 0;

typedef HANDLE (LCAPI *tflcPaint_ImageAdd)(int Id);
tflcPaint_ImageAdd pflcPaint_ImageAdd = 0;

typedef BOOL (LCAPI *tflcPaint_ImageDelete)(HANDLE hImage);
tflcPaint_ImageDelete pflcPaint_ImageDelete = 0;

typedef HANDLE (LCAPI *tflcPaint_ImageGetFirst)();
tflcPaint_ImageGetFirst pflcPaint_ImageGetFirst = 0;

typedef HANDLE (LCAPI *tflcPaint_ImageGetNext)(HANDLE hImage);
tflcPaint_ImageGetNext pflcPaint_ImageGetNext = 0;

typedef HANDLE (LCAPI *tflcPaint_ImageGetByID)(int Id);
tflcPaint_ImageGetByID pflcPaint_ImageGetByID = 0;

typedef BOOL (LCAPI *tflcPaint_ImageLoad)(HANDLE hImage, LPCWSTR szFileName);
tflcPaint_ImageLoad pflcPaint_ImageLoad = 0;

typedef BOOL (LCAPI *tflcPaint_ImageCopy)(HANDLE hImage, HANDLE hImageDest);
tflcPaint_ImageCopy pflcPaint_ImageCopy = 0;

typedef BOOL (LCAPI *tflcPaint_ImageCreate)(HANDLE hImage, int Width, int Height);
tflcPaint_ImageCreate pflcPaint_ImageCreate = 0;

typedef BOOL (LCAPI *tflcPaint_ImageSetPixel)(HANDLE hImage, int X, int Y, int R, int G, int B);
tflcPaint_ImageSetPixel pflcPaint_ImageSetPixel = 0;

typedef BOOL (LCAPI *tflcPaint_ImageFlip)(HANDLE hImage, BOOL bHor, BOOL bVert);
tflcPaint_ImageFlip pflcPaint_ImageFlip = 0;

typedef BOOL (LCAPI *tflcPaint_ImageRotate)(HANDLE hImage, double Angle);
tflcPaint_ImageRotate pflcPaint_ImageRotate = 0;

typedef BOOL (LCAPI *tflcPaint_ImageGray)(HANDLE hImage);
tflcPaint_ImageGray pflcPaint_ImageGray = 0;

typedef BOOL (LCAPI *tflcPaint_ImageResize)(HANDLE hImage, int NewWidth, int NewHeight, int ResizeFilter);
tflcPaint_ImageResize pflcPaint_ImageResize = 0;

typedef HANDLE (LCAPI *tflcPaint_ImageGetPtbuf)(HANDLE hImage, double RotAngle);
tflcPaint_ImageGetPtbuf pflcPaint_ImageGetPtbuf = 0;

typedef HANDLE (LCAPI *tflcPaint_FontOpenLC)(LPCWSTR szFontName);
tflcPaint_FontOpenLC pflcPaint_FontOpenLC = 0;

typedef HANDLE (LCAPI *tflcPaint_FontOpenTT)(LPCWSTR szFontName, BOOL bBold, BOOL bItalic);
tflcPaint_FontOpenTT pflcPaint_FontOpenTT = 0;

typedef BOOL (LCAPI *tflcPaint_FontClose)(HANDLE hFont);
tflcPaint_FontClose pflcPaint_FontClose = 0;

typedef BOOL (LCAPI *tflcPaint_FontSelect)(HANDLE hLcWnd, HANDLE hFont);
tflcPaint_FontSelect pflcPaint_FontSelect = 0;


static HINSTANCE ghLibInst=0;

//-------------------------------------------------
BOOL SetProcAddr ()
{
  char* szFuncName;
  szFuncName = "lcEventSetProc";
  pflcEventSetProc = (tflcEventSetProc)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEventSetProc == NULL){
    goto mErr;
  }
  szFuncName = "lcEventReturnCode";
  pflcEventReturnCode = (tflcEventReturnCode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEventReturnCode == NULL){
    goto mErr;
  }
  szFuncName = "lcEventsEnable";
  pflcEventsEnable = (tflcEventsEnable)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEventsEnable == NULL){
    goto mErr;
  }
  szFuncName = "lcInitialize";
  pflcInitialize = (tflcInitialize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcInitialize == NULL){
    goto mErr;
  }
  szFuncName = "lcUninitialize";
  pflcUninitialize = (tflcUninitialize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcUninitialize == NULL){
    goto mErr;
  }
  szFuncName = "lcStrAdd";
  pflcStrAdd = (tflcStrAdd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStrAdd == NULL){
    goto mErr;
  }
  szFuncName = "lcStrSet";
  pflcStrSet = (tflcStrSet)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStrSet == NULL){
    goto mErr;
  }
  szFuncName = "lcStrGet";
  pflcStrGet = (tflcStrGet)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStrGet == NULL){
    goto mErr;
  }
  szFuncName = "lcStrFileLoad";
  pflcStrFileLoad = (tflcStrFileLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStrFileLoad == NULL){
    goto mErr;
  }
  szFuncName = "lcStrFileSave";
  pflcStrFileSave = (tflcStrFileSave)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStrFileSave == NULL){
    goto mErr;
  }
  szFuncName = "lcPropGetBool";
  pflcPropGetBool = (tflcPropGetBool)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropGetBool == NULL){
    goto mErr;
  }
  szFuncName = "lcPropGetInt";
  pflcPropGetInt = (tflcPropGetInt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropGetInt == NULL){
    goto mErr;
  }
  szFuncName = "lcPropGetFloat";
  pflcPropGetFloat = (tflcPropGetFloat)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropGetFloat == NULL){
    goto mErr;
  }
  szFuncName = "lcPropGetStr";
  pflcPropGetStr = (tflcPropGetStr)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropGetStr == NULL){
    goto mErr;
  }
  szFuncName = "lcPropGetStr2";
  pflcPropGetStr2 = (tflcPropGetStr2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropGetStr2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPropGetChar";
  pflcPropGetChar = (tflcPropGetChar)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropGetChar == NULL){
    goto mErr;
  }
  szFuncName = "lcPropGetHandle";
  pflcPropGetHandle = (tflcPropGetHandle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropGetHandle == NULL){
    goto mErr;
  }
  szFuncName = "lcPropPutBool";
  pflcPropPutBool = (tflcPropPutBool)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropPutBool == NULL){
    goto mErr;
  }
  szFuncName = "lcPropPutInt";
  pflcPropPutInt = (tflcPropPutInt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropPutInt == NULL){
    goto mErr;
  }
  szFuncName = "lcPropPutFloat";
  pflcPropPutFloat = (tflcPropPutFloat)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropPutFloat == NULL){
    goto mErr;
  }
  szFuncName = "lcPropPutStr";
  pflcPropPutStr = (tflcPropPutStr)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropPutStr == NULL){
    goto mErr;
  }
  szFuncName = "lcPropPutHandle";
  pflcPropPutHandle = (tflcPropPutHandle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropPutHandle == NULL){
    goto mErr;
  }
  szFuncName = "lcCreateWindow";
  pflcCreateWindow = (tflcCreateWindow)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCreateWindow == NULL){
    goto mErr;
  }
  szFuncName = "lcDeleteWindow";
  pflcDeleteWindow = (tflcDeleteWindow)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDeleteWindow == NULL){
    goto mErr;
  }
  szFuncName = "lcWndResize";
  pflcWndResize = (tflcWndResize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndResize == NULL){
    goto mErr;
  }
  szFuncName = "lcWndRedraw";
  pflcWndRedraw = (tflcWndRedraw)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndRedraw == NULL){
    goto mErr;
  }
  szFuncName = "lcWndSetFocus";
  pflcWndSetFocus = (tflcWndSetFocus)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndSetFocus == NULL){
    goto mErr;
  }
  szFuncName = "lcWndSetExtents";
  pflcWndSetExtents = (tflcWndSetExtents)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndSetExtents == NULL){
    goto mErr;
  }
  szFuncName = "lcWndZoomRect";
  pflcWndZoomRect = (tflcWndZoomRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndZoomRect == NULL){
    goto mErr;
  }
  szFuncName = "lcWndZoomScale";
  pflcWndZoomScale = (tflcWndZoomScale)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndZoomScale == NULL){
    goto mErr;
  }
  szFuncName = "lcWndZoomMove";
  pflcWndZoomMove = (tflcWndZoomMove)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndZoomMove == NULL){
    goto mErr;
  }
  szFuncName = "lcWndGetCursorCoord";
  pflcWndGetCursorCoord = (tflcWndGetCursorCoord)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndGetCursorCoord == NULL){
    goto mErr;
  }
  szFuncName = "lcWndExeCommand";
  pflcWndExeCommand = (tflcWndExeCommand)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndExeCommand == NULL){
    goto mErr;
  }
  szFuncName = "lcWndOnClose";
  pflcWndOnClose = (tflcWndOnClose)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndOnClose == NULL){
    goto mErr;
  }
  szFuncName = "lcWndSetBlock";
  pflcWndSetBlock = (tflcWndSetBlock)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndSetBlock == NULL){
    goto mErr;
  }
  szFuncName = "lcWndSetProps";
  pflcWndSetProps = (tflcWndSetProps)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndSetProps == NULL){
    goto mErr;
  }
  szFuncName = "lcWndGetEntByPoint";
  pflcWndGetEntByPoint = (tflcWndGetEntByPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndGetEntByPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcWndGetEntByPoint2";
  pflcWndGetEntByPoint2 = (tflcWndGetEntByPoint2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndGetEntByPoint2 == NULL){
    goto mErr;
  }
  szFuncName = "lcWndGetEntsByRect";
  pflcWndGetEntsByRect = (tflcWndGetEntsByRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndGetEntsByRect == NULL){
    goto mErr;
  }
  szFuncName = "lcWndGetEntity";
  pflcWndGetEntity = (tflcWndGetEntity)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndGetEntity == NULL){
    goto mErr;
  }
//  szFuncName = "lcWndGetEntByID";
//  pflcWndGetEntByID = (tflcWndGetEntByID)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcWndGetEntByID == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcWndGetEntByIDH";
//  pflcWndGetEntByIDH = (tflcWndGetEntByIDH)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcWndGetEntByIDH == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcWndGetEntByKey";
//  pflcWndGetEntByKey = (tflcWndGetEntByKey)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcWndGetEntByKey == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcWndEmulator";
//  pflcWndEmulator = (tflcWndEmulator)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcWndEmulator == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcWndMagnifier";
//  pflcWndMagnifier = (tflcWndMagnifier)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcWndMagnifier == NULL){
//    goto mErr;
//  }
  szFuncName = "lcWndCoordFromDrw";
  pflcWndCoordFromDrw = (tflcWndCoordFromDrw)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndCoordFromDrw == NULL){
    goto mErr;
  }
  szFuncName = "lcWndCoordToDrw";
  pflcWndCoordToDrw = (tflcWndCoordToDrw)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndCoordToDrw == NULL){
    goto mErr;
  }
  szFuncName = "lcCoordDrwToWnd";
  pflcCoordDrwToWnd = (tflcCoordDrwToWnd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCoordDrwToWnd == NULL){
    goto mErr;
  }
  szFuncName = "lcCoordWndToDrw";
  pflcCoordWndToDrw = (tflcCoordWndToDrw)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCoordWndToDrw == NULL){
    goto mErr;
  }
  szFuncName = "lcFontGetFirst";
  pflcFontGetFirst = (tflcFontGetFirst)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFontGetFirst == NULL){
    goto mErr;
  }
  szFuncName = "lcFontGetNext";
  pflcFontGetNext = (tflcFontGetNext)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFontGetNext == NULL){
    goto mErr;
  }
  szFuncName = "lcFontAddRes";
  pflcFontAddRes = (tflcFontAddRes)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFontAddRes == NULL){
    goto mErr;
  }
  szFuncName = "lcFontAddFile";
  pflcFontAddFile = (tflcFontAddFile)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFontAddFile == NULL){
    goto mErr;
  }
  szFuncName = "lcFontAddBin";
  pflcFontAddBin = (tflcFontAddBin)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFontAddBin == NULL){
    goto mErr;
  }
  szFuncName = "lcFontGetChar";
  pflcFontGetChar = (tflcFontGetChar)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFontGetChar == NULL){
    goto mErr;
  }
  szFuncName = "lcProgressCreate";
  pflcProgressCreate = (tflcProgressCreate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcProgressCreate == NULL){
    goto mErr;
  }
  szFuncName = "lcProgressSetText";
  pflcProgressSetText = (tflcProgressSetText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcProgressSetText == NULL){
    goto mErr;
  }
  szFuncName = "lcProgressStart";
  pflcProgressStart = (tflcProgressStart)GetProcAddress( ghLibInst, szFuncName );
  if (pflcProgressStart == NULL){
    goto mErr;
  }
  szFuncName = "lcProgressSetPos";
  pflcProgressSetPos = (tflcProgressSetPos)GetProcAddress( ghLibInst, szFuncName );
  if (pflcProgressSetPos == NULL){
    goto mErr;
  }
  szFuncName = "lcProgressInc";
  pflcProgressInc = (tflcProgressInc)GetProcAddress( ghLibInst, szFuncName );
  if (pflcProgressInc == NULL){
    goto mErr;
  }
  szFuncName = "lcProgressDelete";
  pflcProgressDelete = (tflcProgressDelete)GetProcAddress( ghLibInst, szFuncName );
  if (pflcProgressDelete == NULL){
    goto mErr;
  }
  szFuncName = "lcQuadCreate";
  pflcQuadCreate = (tflcQuadCreate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcQuadCreate == NULL){
    goto mErr;
  }
  szFuncName = "lcQuadDelete";
  pflcQuadDelete = (tflcQuadDelete)GetProcAddress( ghLibInst, szFuncName );
  if (pflcQuadDelete == NULL){
    goto mErr;
  }
  szFuncName = "lcQuadSet";
  pflcQuadSet = (tflcQuadSet)GetProcAddress( ghLibInst, szFuncName );
  if (pflcQuadSet == NULL){
    goto mErr;
  }
  szFuncName = "lcQuadTransXYtoUV";
  pflcQuadTransXYtoUV = (tflcQuadTransXYtoUV)GetProcAddress( ghLibInst, szFuncName );
  if (pflcQuadTransXYtoUV == NULL){
    goto mErr;
  }
  szFuncName = "lcQuadTransUVtoXY";
  pflcQuadTransUVtoXY = (tflcQuadTransUVtoXY)GetProcAddress( ghLibInst, szFuncName );
  if (pflcQuadTransUVtoXY == NULL){
    goto mErr;
  }
  szFuncName = "lcQuadContains";
  pflcQuadContains = (tflcQuadContains)GetProcAddress( ghLibInst, szFuncName );
  if (pflcQuadContains == NULL){
    goto mErr;
  }
  szFuncName = "lcGridCreate";
  pflcGridCreate = (tflcGridCreate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridCreate == NULL){
    goto mErr;
  }
  szFuncName = "lcGridDelete";
  pflcGridDelete = (tflcGridDelete)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridDelete == NULL){
    goto mErr;
  }
  szFuncName = "lcGridSet";
  pflcGridSet = (tflcGridSet)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridSet == NULL){
    goto mErr;
  }
  szFuncName = "lcGridSetDest";
  pflcGridSetDest = (tflcGridSetDest)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridSetDest == NULL){
    goto mErr;
  }
  szFuncName = "lcGridUpdate";
  pflcGridUpdate = (tflcGridUpdate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridUpdate == NULL){
    goto mErr;
  }
  szFuncName = "lcGridTrans";
  pflcGridTrans = (tflcGridTrans)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridTrans == NULL){
    goto mErr;
  }
  szFuncName = "lcGridGetNode";
  pflcGridGetNode = (tflcGridGetNode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridGetNode == NULL){
    goto mErr;
  }
  szFuncName = "lcGridGetCell";
  pflcGridGetCell = (tflcGridGetCell)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridGetCell == NULL){
    goto mErr;
  }
  szFuncName = "lcGridSetView";
  pflcGridSetView = (tflcGridSetView)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGridSetView == NULL){
    goto mErr;
  }
  szFuncName = "lcTIN_Create";
  pflcTIN_Create = (tflcTIN_Create)GetProcAddress( ghLibInst, szFuncName );
  if (pflcTIN_Create == NULL){
    goto mErr;
  }
  szFuncName = "lcTIN_Delete";
  pflcTIN_Delete = (tflcTIN_Delete)GetProcAddress( ghLibInst, szFuncName );
  if (pflcTIN_Delete == NULL){
    goto mErr;
  }
  szFuncName = "lcTIN_Load";
  pflcTIN_Load = (tflcTIN_Load)GetProcAddress( ghLibInst, szFuncName );
  if (pflcTIN_Load == NULL){
    goto mErr;
  }
  szFuncName = "lcTIN_GetZ";
  pflcTIN_GetZ = (tflcTIN_GetZ)GetProcAddress( ghLibInst, szFuncName );
  if (pflcTIN_GetZ == NULL){
    goto mErr;
  }
  szFuncName = "lcTIN_InterLine";
  pflcTIN_InterLine = (tflcTIN_InterLine)GetProcAddress( ghLibInst, szFuncName );
  if (pflcTIN_InterLine == NULL){
    goto mErr;
  }
  szFuncName = "lcTIN_InterGetPoint";
  pflcTIN_InterGetPoint = (tflcTIN_InterGetPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcTIN_InterGetPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcCreateProps";
  pflcCreateProps = (tflcCreateProps)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCreateProps == NULL){
    goto mErr;
  }
  szFuncName = "lcDeleteProps";
  pflcDeleteProps = (tflcDeleteProps)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDeleteProps == NULL){
    goto mErr;
  }
  szFuncName = "lcPropsResize";
  pflcPropsResize = (tflcPropsResize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropsResize == NULL){
    goto mErr;
  }
  szFuncName = "lcPropsUpdate";
  pflcPropsUpdate = (tflcPropsUpdate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPropsUpdate == NULL){
    goto mErr;
  }
  szFuncName = "lcCreateStatbar";
  pflcCreateStatbar = (tflcCreateStatbar)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCreateStatbar == NULL){
    goto mErr;
  }
  szFuncName = "lcDeleteStatbar";
  pflcDeleteStatbar = (tflcDeleteStatbar)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDeleteStatbar == NULL){
    goto mErr;
  }
  szFuncName = "lcStatbarResize";
  pflcStatbarResize = (tflcStatbarResize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStatbarResize == NULL){
    goto mErr;
  }
  szFuncName = "lcStatbarCell";
  pflcStatbarCell = (tflcStatbarCell)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStatbarCell == NULL){
    goto mErr;
  }
  szFuncName = "lcStatbarText";
  pflcStatbarText = (tflcStatbarText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStatbarText == NULL){
    goto mErr;
  }
  szFuncName = "lcStatbarRedraw";
  pflcStatbarRedraw = (tflcStatbarRedraw)GetProcAddress( ghLibInst, szFuncName );
  if (pflcStatbarRedraw == NULL){
    goto mErr;
  }
  szFuncName = "lcDgGetValue";
  pflcDgGetValue = (tflcDgGetValue)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDgGetValue == NULL){
    goto mErr;
  }
  szFuncName = "lcHelp";
  pflcHelp = (tflcHelp)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHelp == NULL){
    goto mErr;
  }
  szFuncName = "lcGetPolarPoint";
  pflcGetPolarPoint = (tflcGetPolarPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGetPolarPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcGetPolarPrm";
  pflcGetPolarPrm = (tflcGetPolarPrm)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGetPolarPrm == NULL){
    goto mErr;
  }
  szFuncName = "lcGetClientSize";
  pflcGetClientSize = (tflcGetClientSize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGetClientSize == NULL){
    goto mErr;
  }
  szFuncName = "lcGetErrorCode";
  pflcGetErrorCode = (tflcGetErrorCode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGetErrorCode == NULL){
    goto mErr;
  }
  szFuncName = "lcGetErrorStr";
  pflcGetErrorStr = (tflcGetErrorStr)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGetErrorStr == NULL){
    goto mErr;
  }
  szFuncName = "lcCreateCommand";
  pflcCreateCommand = (tflcCreateCommand)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCreateCommand == NULL){
    goto mErr;
  }
  szFuncName = "lcCmdExit";
  pflcCmdExit = (tflcCmdExit)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCmdExit == NULL){
    goto mErr;
  }
  szFuncName = "lcCmdCursorText";
  pflcCmdCursorText = (tflcCmdCursorText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCmdCursorText == NULL){
    goto mErr;
  }
  szFuncName = "lcCmdMessage";
  pflcCmdMessage = (tflcCmdMessage)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCmdMessage == NULL){
    goto mErr;
  }
  szFuncName = "lcCmdResetLastPt";
  pflcCmdResetLastPt = (tflcCmdResetLastPt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCmdResetLastPt == NULL){
    goto mErr;
  }
  szFuncName = "lcCameraConnect";
  pflcCameraConnect = (tflcCameraConnect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCameraConnect == NULL){
    goto mErr;
  }
  szFuncName = "lcCameraDisconnect";
  pflcCameraDisconnect = (tflcCameraDisconnect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCameraDisconnect == NULL){
    goto mErr;
  }
  szFuncName = "lcCameraShot";
  pflcCameraShot = (tflcCameraShot)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCameraShot == NULL){
    goto mErr;
  }
  szFuncName = "lcCreateDrawing";
  pflcCreateDrawing = (tflcCreateDrawing)GetProcAddress( ghLibInst, szFuncName );
  if (pflcCreateDrawing == NULL){
    goto mErr;
  }
  szFuncName = "lcDeleteDrawing";
  pflcDeleteDrawing = (tflcDeleteDrawing)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDeleteDrawing == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwNew";
  pflcDrwNew = (tflcDrwNew)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwNew == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwLoad";
  pflcDrwLoad = (tflcDrwLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwLoad == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwLoadMem";
  pflcDrwLoadMem = (tflcDrwLoadMem)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwLoadMem == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwInsert";
  pflcDrwInsert = (tflcDrwInsert)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwInsert == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwCopy";
  pflcDrwCopy = (tflcDrwCopy)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwCopy == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwSave";
  pflcDrwSave = (tflcDrwSave)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwSave == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwSaveMem";
  pflcDrwSaveMem = (tflcDrwSaveMem)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwSaveMem == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddLayer";
  pflcDrwAddLayer = (tflcDrwAddLayer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddLayer == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddLinetype";
  pflcDrwAddLinetype = (tflcDrwAddLinetype)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddLinetype == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddLinetypeF";
  pflcDrwAddLinetypeF = (tflcDrwAddLinetypeF)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddLinetypeF == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddTextStyle";
  pflcDrwAddTextStyle = (tflcDrwAddTextStyle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddTextStyle == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddDimStyle";
  pflcDrwAddDimStyle = (tflcDrwAddDimStyle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddDimStyle == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddMlineStyle";
  pflcDrwAddMlineStyle = (tflcDrwAddMlineStyle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddMlineStyle == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddPntStyle";
  pflcDrwAddPntStyle = (tflcDrwAddPntStyle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddPntStyle == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddImage";
  pflcDrwAddImage = (tflcDrwAddImage)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddImage == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddImage2";
  pflcDrwAddImage2 = (tflcDrwAddImage2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddImage2 == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddImage3";
  pflcDrwAddImage3 = (tflcDrwAddImage3)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddImage3 == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddBlock";
  pflcDrwAddBlock = (tflcDrwAddBlock)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddBlock == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddBlockFromFile";
  pflcDrwAddBlockFromFile = (tflcDrwAddBlockFromFile)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddBlockFromFile == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddBlockFromDrw";
  pflcDrwAddBlockFromDrw = (tflcDrwAddBlockFromDrw)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddBlockFromDrw == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddBlockFile";
  pflcDrwAddBlockFile = (tflcDrwAddBlockFile)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddBlockFile == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddBlockPaper";
  pflcDrwAddBlockPaper = (tflcDrwAddBlockPaper)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddBlockPaper == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwAddBlockCopy";
  pflcDrwAddBlockCopy = (tflcDrwAddBlockCopy)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwAddBlockCopy == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwDeleteObject";
  pflcDrwDeleteObject = (tflcDrwDeleteObject)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwDeleteObject == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwDeleteUnused";
  pflcDrwDeleteUnused = (tflcDrwDeleteUnused)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwDeleteUnused == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwCountObjects";
  pflcDrwCountObjects = (tflcDrwCountObjects)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwCountObjects == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwSortObjects";
  pflcDrwSortObjects = (tflcDrwSortObjects)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwSortObjects == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetFirstObject";
  pflcDrwGetFirstObject = (tflcDrwGetFirstObject)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetFirstObject == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetNextObject";
  pflcDrwGetNextObject = (tflcDrwGetNextObject)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetNextObject == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetObjectByID";
  pflcDrwGetObjectByID = (tflcDrwGetObjectByID)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetObjectByID == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetObjectByIDH";
  pflcDrwGetObjectByIDH = (tflcDrwGetObjectByIDH)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetObjectByIDH == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetObjectByName";
  pflcDrwGetObjectByName = (tflcDrwGetObjectByName)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetObjectByName == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetEntByID";
  pflcDrwGetEntByID = (tflcDrwGetEntByID)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetEntByID == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetEntByIDH";
  pflcDrwGetEntByIDH = (tflcDrwGetEntByIDH)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetEntByIDH == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwGetEntByKey";
  pflcDrwGetEntByKey = (tflcDrwGetEntByKey)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwGetEntByKey == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwClearXData";
  pflcDrwClearXData = (tflcDrwClearXData)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwClearXData == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwPurge";
  pflcDrwPurge = (tflcDrwPurge)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwPurge == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwExplode";
  pflcDrwExplode = (tflcDrwExplode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwExplode == NULL){
    goto mErr;
  }
//  szFuncName = "lcDrwSetLimits";
//  pflcDrwSetLimits = (tflcDrwSetLimits)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcDrwSetLimits == NULL){
//    goto mErr;
//  }
  szFuncName = "lcDrwUndoRecord";
  pflcDrwUndoRecord = (tflcDrwUndoRecord)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwUndoRecord == NULL){
    goto mErr;
  }
  szFuncName = "lcDrwUndo";
  pflcDrwUndo = (tflcDrwUndo)GetProcAddress( ghLibInst, szFuncName );
  if (pflcDrwUndo == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSetViewRect";
  pflcBlockSetViewRect = (tflcBlockSetViewRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSetViewRect == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSetViewRect2";
  pflcBlockSetViewRect2 = (tflcBlockSetViewRect2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSetViewRect2 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSetPaperSize";
  pflcBlockSetPaperSize = (tflcBlockSetPaperSize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSetPaperSize == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockRasterize";
  pflcBlockRasterize = (tflcBlockRasterize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockRasterize == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockUpdate";
  pflcBlockUpdate = (tflcBlockUpdate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockUpdate == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockScale";
  pflcBlockScale = (tflcBlockScale)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockScale == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockClear";
  pflcBlockClear = (tflcBlockClear)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockClear == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockPurge";
  pflcBlockPurge = (tflcBlockPurge)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockPurge == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSortEnts";
  pflcBlockSortEnts = (tflcBlockSortEnts)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSortEnts == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddPoint";
  pflcBlockAddPoint = (tflcBlockAddPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddPoint2";
  pflcBlockAddPoint2 = (tflcBlockAddPoint2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddPoint2 == NULL){
    goto mErr;
  }
//  szFuncName = "lcBlockAddPtArray";
//  pflcBlockAddPtArray = (tflcBlockAddPtArray)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcBlockAddPtArray == NULL){
//    goto mErr;
//  }
  szFuncName = "lcBlockAddXline";
  pflcBlockAddXline = (tflcBlockAddXline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddXline == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddXline2P";
  pflcBlockAddXline2P = (tflcBlockAddXline2P)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddXline2P == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddLine";
  pflcBlockAddLine = (tflcBlockAddLine)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddLine == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddLineDir";
  pflcBlockAddLineDir = (tflcBlockAddLineDir)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddLineDir == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddLineTan";
  pflcBlockAddLineTan = (tflcBlockAddLineTan)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddLineTan == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddPolyline";
  pflcBlockAddPolyline = (tflcBlockAddPolyline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddPolyline == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddSpline";
  pflcBlockAddSpline = (tflcBlockAddSpline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddSpline == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddMline";
  pflcBlockAddMline = (tflcBlockAddMline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddMline == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddRect";
  pflcBlockAddRect = (tflcBlockAddRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddRect == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddRect2";
  pflcBlockAddRect2 = (tflcBlockAddRect2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddRect2 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddCircle";
  pflcBlockAddCircle = (tflcBlockAddCircle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddCircle == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddArc";
  pflcBlockAddArc = (tflcBlockAddArc)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddArc == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddArc3P";
  pflcBlockAddArc3P = (tflcBlockAddArc3P)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddArc3P == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddEllipse";
  pflcBlockAddEllipse = (tflcBlockAddEllipse)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddEllipse == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddText";
  pflcBlockAddText = (tflcBlockAddText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddText == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddText2";
  pflcBlockAddText2 = (tflcBlockAddText2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddText2 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddText3";
  pflcBlockAddText3 = (tflcBlockAddText3)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddText3 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddMText";
  pflcBlockAddMText = (tflcBlockAddMText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddMText == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddArcText";
  pflcBlockAddArcText = (tflcBlockAddArcText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddArcText == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddBlockRef";
  pflcBlockAddBlockRef = (tflcBlockAddBlockRef)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddBlockRef == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddBlockRefID";
  pflcBlockAddBlockRefID = (tflcBlockAddBlockRefID)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddBlockRefID == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddBlockRefIDH";
  pflcBlockAddBlockRefIDH = (tflcBlockAddBlockRefIDH)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddBlockRefIDH == NULL){
    goto mErr;
  }
//  szFuncName = "lcBlockAddXref";
//  pflcBlockAddXref = (tflcBlockAddXref)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcBlockAddXref == NULL){
//    goto mErr;
//  }
  szFuncName = "lcBlockAddImageRef";
  pflcBlockAddImageRef = (tflcBlockAddImageRef)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddImageRef == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddEcw";
  pflcBlockAddEcw = (tflcBlockAddEcw)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddEcw == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddBarcode";
  pflcBlockAddBarcode = (tflcBlockAddBarcode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddBarcode == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddHatch";
  pflcBlockAddHatch = (tflcBlockAddHatch)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddHatch == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddViewport";
  pflcBlockAddViewport = (tflcBlockAddViewport)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddViewport == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddFace";
  pflcBlockAddFace = (tflcBlockAddFace)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddFace == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddFace4";
  pflcBlockAddFace4 = (tflcBlockAddFace4)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddFace4 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddLeader";
  pflcBlockAddLeader = (tflcBlockAddLeader)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddLeader == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimLin";
  pflcBlockAddDimLin = (tflcBlockAddDimLin)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimLin == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimHor";
  pflcBlockAddDimHor = (tflcBlockAddDimHor)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimHor == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimVer";
  pflcBlockAddDimVer = (tflcBlockAddDimVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimVer == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimAli";
  pflcBlockAddDimAli = (tflcBlockAddDimAli)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimAli == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimAli2";
  pflcBlockAddDimAli2 = (tflcBlockAddDimAli2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimAli2 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimOrd";
  pflcBlockAddDimOrd = (tflcBlockAddDimOrd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimOrd == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimRad";
  pflcBlockAddDimRad = (tflcBlockAddDimRad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimRad == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimRad2";
  pflcBlockAddDimRad2 = (tflcBlockAddDimRad2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimRad2 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimDia";
  pflcBlockAddDimDia = (tflcBlockAddDimDia)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimDia == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimDia2";
  pflcBlockAddDimDia2 = (tflcBlockAddDimDia2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimDia2 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimAng";
  pflcBlockAddDimAng = (tflcBlockAddDimAng)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimAng == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddDimAng2";
  pflcBlockAddDimAng2 = (tflcBlockAddDimAng2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddDimAng2 == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddRPlan";
  pflcBlockAddRPlan = (tflcBlockAddRPlan)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddRPlan == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddArrow";
  pflcBlockAddArrow = (tflcBlockAddArrow)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddArrow == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddSpiral";
  pflcBlockAddSpiral = (tflcBlockAddSpiral)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddSpiral == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddCamview";
  pflcBlockAddCamview = (tflcBlockAddCamview)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddCamview == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockAddClone";
  pflcBlockAddClone = (tflcBlockAddClone)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockAddClone == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetFirstEnt";
  pflcBlockGetFirstEnt = (tflcBlockGetFirstEnt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetFirstEnt == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetNextEnt";
  pflcBlockGetNextEnt = (tflcBlockGetNextEnt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetNextEnt == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetLastEnt";
  pflcBlockGetLastEnt = (tflcBlockGetLastEnt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetLastEnt == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetPrevEnt";
  pflcBlockGetPrevEnt = (tflcBlockGetPrevEnt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetPrevEnt == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetEntByID";
  pflcBlockGetEntByID = (tflcBlockGetEntByID)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetEntByID == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetEntByIDH";
  pflcBlockGetEntByIDH = (tflcBlockGetEntByIDH)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetEntByIDH == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetEntByKey";
  pflcBlockGetEntByKey = (tflcBlockGetEntByKey)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetEntByKey == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockUnselect";
  pflcBlockUnselect = (tflcBlockUnselect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockUnselect == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelectEnt";
  pflcBlockSelectEnt = (tflcBlockSelectEnt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelectEnt == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelErase";
  pflcBlockSelErase = (tflcBlockSelErase)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelErase == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelMove";
  pflcBlockSelMove = (tflcBlockSelMove)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelMove == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelScale";
  pflcBlockSelScale = (tflcBlockSelScale)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelScale == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelRotate";
  pflcBlockSelRotate = (tflcBlockSelRotate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelRotate == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelMirror";
  pflcBlockSelMirror = (tflcBlockSelMirror)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelMirror == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelExplode";
  pflcBlockSelExplode = (tflcBlockSelExplode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelExplode == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelJoin";
  pflcBlockSelJoin = (tflcBlockSelJoin)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelJoin == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSelAlign";
  pflcBlockSelAlign = (tflcBlockSelAlign)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSelAlign == NULL){
    goto mErr;
  }
//  szFuncName = "lcBlockSelBlock";
//  pflcBlockSelBlock = (tflcBlockSelBlock)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcBlockSelBlock == NULL){
//    goto mErr;
//  }
  szFuncName = "lcBlockGetFirstSel";
  pflcBlockGetFirstSel = (tflcBlockGetFirstSel)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetFirstSel == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetNextSel";
  pflcBlockGetNextSel = (tflcBlockGetNextSel)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetNextSel == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockOrderByLayers";
  pflcBlockOrderByLayers = (tflcBlockOrderByLayers)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockOrderByLayers == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockSortTSP";
  pflcBlockSortTSP = (tflcBlockSortTSP)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockSortTSP == NULL){
    goto mErr;
  }
  szFuncName = "lcBlockGetJumpsLen";
  pflcBlockGetJumpsLen = (tflcBlockGetJumpsLen)GetProcAddress( ghLibInst, szFuncName );
  if (pflcBlockGetJumpsLen == NULL){
    goto mErr;
  }
  szFuncName = "lcLayerClear";
  pflcLayerClear = (tflcLayerClear)GetProcAddress( ghLibInst, szFuncName );
  if (pflcLayerClear == NULL){
    goto mErr;
  }
  szFuncName = "lcEntErase";
  pflcEntErase = (tflcEntErase)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntErase == NULL){
    goto mErr;
  }
  szFuncName = "lcEntMove";
  pflcEntMove = (tflcEntMove)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntMove == NULL){
    goto mErr;
  }
  szFuncName = "lcEntScale";
  pflcEntScale = (tflcEntScale)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntScale == NULL){
    goto mErr;
  }
  szFuncName = "lcEntRotate";
  pflcEntRotate = (tflcEntRotate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntRotate == NULL){
    goto mErr;
  }
  szFuncName = "lcEntMirror";
  pflcEntMirror = (tflcEntMirror)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntMirror == NULL){
    goto mErr;
  }
  szFuncName = "lcEntExplode";
  pflcEntExplode = (tflcEntExplode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntExplode == NULL){
    goto mErr;
  }
  szFuncName = "lcEntOffset";
  pflcEntOffset = (tflcEntOffset)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntOffset == NULL){
    goto mErr;
  }
  szFuncName = "lcEntToTop";
  pflcEntToTop = (tflcEntToTop)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntToTop == NULL){
    goto mErr;
  }
  szFuncName = "lcEntToBottom";
  pflcEntToBottom = (tflcEntToBottom)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntToBottom == NULL){
    goto mErr;
  }
  szFuncName = "lcEntToAbove";
  pflcEntToAbove = (tflcEntToAbove)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntToAbove == NULL){
    goto mErr;
  }
  szFuncName = "lcEntToUnder";
  pflcEntToUnder = (tflcEntToUnder)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntToUnder == NULL){
    goto mErr;
  }
  szFuncName = "lcEntGetGrip";
  pflcEntGetGrip = (tflcEntGetGrip)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntGetGrip == NULL){
    goto mErr;
  }
  szFuncName = "lcEntPutGrip";
  pflcEntPutGrip = (tflcEntPutGrip)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntPutGrip == NULL){
    goto mErr;
  }
  szFuncName = "lcEntUpdate";
  pflcEntUpdate = (tflcEntUpdate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntUpdate == NULL){
    goto mErr;
  }
  szFuncName = "lcEntCopyBase";
  pflcEntCopyBase = (tflcEntCopyBase)GetProcAddress( ghLibInst, szFuncName );
  if (pflcEntCopyBase == NULL){
    goto mErr;
  }
  szFuncName = "lcIntersection";
  pflcIntersection = (tflcIntersection)GetProcAddress( ghLibInst, szFuncName );
  if (pflcIntersection == NULL){
    goto mErr;
  }
  szFuncName = "lcInterGetPoint";
  pflcInterGetPoint = (tflcInterGetPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcInterGetPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineAddVer";
  pflcPlineAddVer = (tflcPlineAddVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineAddVer == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineAddVer2";
  pflcPlineAddVer2 = (tflcPlineAddVer2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineAddVer2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineAddVerDir";
  pflcPlineAddVerDir = (tflcPlineAddVerDir)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineAddVerDir == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineEnd";
  pflcPlineEnd = (tflcPlineEnd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineEnd == NULL){
    goto mErr;
  }
//  szFuncName = "lcPlineFromPtbuf";
//  pflcPlineFromPtbuf = (tflcPlineFromPtbuf)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcPlineFromPtbuf == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcPlineFromMpgon";
//  pflcPlineFromMpgon = (tflcPlineFromMpgon)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcPlineFromMpgon == NULL){
//    goto mErr;
//  }
  szFuncName = "lcPlineDeleteVer";
  pflcPlineDeleteVer = (tflcPlineDeleteVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineDeleteVer == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetFirstVer";
  pflcPlineGetFirstVer = (tflcPlineGetFirstVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetFirstVer == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetNextVer";
  pflcPlineGetNextVer = (tflcPlineGetNextVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetNextVer == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetLastVer";
  pflcPlineGetLastVer = (tflcPlineGetLastVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetLastVer == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetPrevVer";
  pflcPlineGetPrevVer = (tflcPlineGetPrevVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetPrevVer == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetVer";
  pflcPlineGetVer = (tflcPlineGetVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetVer == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetVerPt";
  pflcPlineGetVerPt = (tflcPlineGetVerPt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetVerPt == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetSeg";
  pflcPlineGetSeg = (tflcPlineGetSeg)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetSeg == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineReverse";
  pflcPlineReverse = (tflcPlineReverse)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineReverse == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineContainPoint";
  pflcPlineContainPoint = (tflcPlineContainPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineContainPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcPlineGetRoundPrm";
  pflcPlineGetRoundPrm = (tflcPlineGetRoundPrm)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlineGetRoundPrm == NULL){
    goto mErr;
  }
  szFuncName = "lcXlinePutDir";
  pflcXlinePutDir = (tflcXlinePutDir)GetProcAddress( ghLibInst, szFuncName );
  if (pflcXlinePutDir == NULL){
    goto mErr;
  }
  szFuncName = "lcRectGetPolyline";
  pflcRectGetPolyline = (tflcRectGetPolyline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRectGetPolyline == NULL){
    goto mErr;
  }
  szFuncName = "lcImgRefGetPixel";
  pflcImgRefGetPixel = (tflcImgRefGetPixel)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImgRefGetPixel == NULL){
    goto mErr;
  }
//  szFuncName = "lcImgRefResize";
//  pflcImgRefResize = (tflcImgRefResize)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcImgRefResize == NULL){
//    goto mErr;
//  }
  szFuncName = "lcHatchSetPattern";
  pflcHatchSetPattern = (tflcHatchSetPattern)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchSetPattern == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchBoundStart";
  pflcHatchBoundStart = (tflcHatchBoundStart)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchBoundStart == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchBoundPoint";
  pflcHatchBoundPoint = (tflcHatchBoundPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchBoundPoint == NULL){
    goto mErr;
  }
//  szFuncName = "lcHatchBoundEntity";
//  pflcHatchBoundEntity = (tflcHatchBoundEntity)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcHatchBoundEntity == NULL){
//    goto mErr;
//  }
  szFuncName = "lcHatchBoundEndLoop";
  pflcHatchBoundEndLoop = (tflcHatchBoundEndLoop)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchBoundEndLoop == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchBoundEnd";
  pflcHatchBoundEnd = (tflcHatchBoundEnd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchBoundEnd == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchPatStart";
  pflcHatchPatStart = (tflcHatchPatStart)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchPatStart == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchPatLine";
  pflcHatchPatLine = (tflcHatchPatLine)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchPatLine == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchPatEnd";
  pflcHatchPatEnd = (tflcHatchPatEnd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchPatEnd == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchGetLoopSize";
  pflcHatchGetLoopSize = (tflcHatchGetLoopSize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchGetLoopSize == NULL){
    goto mErr;
  }
  szFuncName = "lcHatchGetPoint";
  pflcHatchGetPoint = (tflcHatchGetPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcHatchGetPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanAddVer";
  pflcRPlanAddVer = (tflcRPlanAddVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanAddVer == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanSetCurve";
  pflcRPlanSetCurve = (tflcRPlanSetCurve)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanSetCurve == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanSetPos";
  pflcRPlanSetPos = (tflcRPlanSetPos)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanSetPos == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanDeleteVer";
  pflcRPlanDeleteVer = (tflcRPlanDeleteVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanDeleteVer == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanGetFirstVer";
  pflcRPlanGetFirstVer = (tflcRPlanGetFirstVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanGetFirstVer == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanGetNextVer";
  pflcRPlanGetNextVer = (tflcRPlanGetNextVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanGetNextVer == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanGetLastVer";
  pflcRPlanGetLastVer = (tflcRPlanGetLastVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanGetLastVer == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanGetPrevVer";
  pflcRPlanGetPrevVer = (tflcRPlanGetPrevVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanGetPrevVer == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanGetVer";
  pflcRPlanGetVer = (tflcRPlanGetVer)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanGetVer == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanGetPoint";
  pflcRPlanGetPoint = (tflcRPlanGetPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanGetPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcRPlanGetDist";
  pflcRPlanGetDist = (tflcRPlanGetDist)GetProcAddress( ghLibInst, szFuncName );
  if (pflcRPlanGetDist == NULL){
    goto mErr;
  }
//  szFuncName = "lcVportSetView";
//  pflcVportSetView = (tflcVportSetView)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcVportSetView == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcVportLayerDlg";
//  pflcVportLayerDlg = (tflcVportLayerDlg)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcVportLayerDlg == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcVportLayerCmd";
//  pflcVportLayerCmd = (tflcVportLayerCmd)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcVportLayerCmd == NULL){
//    goto mErr;
//  }
  szFuncName = "lcColorIsRGB";
  pflcColorIsRGB = (tflcColorIsRGB)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorIsRGB == NULL){
    goto mErr;
  }
  szFuncName = "lcColorGetRed";
  pflcColorGetRed = (tflcColorGetRed)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorGetRed == NULL){
    goto mErr;
  }
  szFuncName = "lcColorGetGreen";
  pflcColorGetGreen = (tflcColorGetGreen)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorGetGreen == NULL){
    goto mErr;
  }
  szFuncName = "lcColorGetBlue";
  pflcColorGetBlue = (tflcColorGetBlue)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorGetBlue == NULL){
    goto mErr;
  }
  szFuncName = "lcColorGetIndex";
  pflcColorGetIndex = (tflcColorGetIndex)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorGetIndex == NULL){
    goto mErr;
  }
  szFuncName = "lcColorToVal";
  pflcColorToVal = (tflcColorToVal)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorToVal == NULL){
    goto mErr;
  }
  szFuncName = "lcColorSetPalette";
  pflcColorSetPalette = (tflcColorSetPalette)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorSetPalette == NULL){
    goto mErr;
  }
  szFuncName = "lcColorGetPalette";
  pflcColorGetPalette = (tflcColorGetPalette)GetProcAddress( ghLibInst, szFuncName );
  if (pflcColorGetPalette == NULL){
    goto mErr;
  }
  szFuncName = "lcImageSetPixelRGB";
  pflcImageSetPixelRGB = (tflcImageSetPixelRGB)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageSetPixelRGB == NULL){
    goto mErr;
  }
  szFuncName = "lcImageSetPixelI";
  pflcImageSetPixelI = (tflcImageSetPixelI)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageSetPixelI == NULL){
    goto mErr;
  }
  szFuncName = "lcImageGetPixelRGB";
  pflcImageGetPixelRGB = (tflcImageGetPixelRGB)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageGetPixelRGB == NULL){
    goto mErr;
  }
  szFuncName = "lcImageGetPixelI";
  pflcImageGetPixelI = (tflcImageGetPixelI)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageGetPixelI == NULL){
    goto mErr;
  }
  szFuncName = "lcImageSetPalColor";
  pflcImageSetPalColor = (tflcImageSetPalColor)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageSetPalColor == NULL){
    goto mErr;
  }
  szFuncName = "lcImageGetPalColor";
  pflcImageGetPalColor = (tflcImageGetPalColor)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageGetPalColor == NULL){
    goto mErr;
  }
  szFuncName = "lcImageLoad";
  pflcImageLoad = (tflcImageLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageLoad == NULL){
    goto mErr;
  }
  szFuncName = "lcImageLoadDIB";
  pflcImageLoadDIB = (tflcImageLoadDIB)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageLoadDIB == NULL){
    goto mErr;
  }
  szFuncName = "lcImageCopyQuad";
  pflcImageCopyQuad = (tflcImageCopyQuad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcImageCopyQuad == NULL){
    goto mErr;
  }
  szFuncName = "lcFilletSetLines";
  pflcFilletSetLines = (tflcFilletSetLines)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFilletSetLines == NULL){
    goto mErr;
  }
  szFuncName = "lcFillet";
  pflcFillet = (tflcFillet)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFillet == NULL){
    goto mErr;
  }
  szFuncName = "lcFilletGetPoint";
  pflcFilletGetPoint = (tflcFilletGetPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcFilletGetPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldSet";
  pflcWFieldSet = (tflcWFieldSet)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldSet == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldClear";
  pflcWFieldClear = (tflcWFieldClear)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldClear == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldDivide";
  pflcWFieldDivide = (tflcWFieldDivide)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldDivide == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldAddCR";
  pflcWFieldAddCR = (tflcWFieldAddCR)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldAddCR == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldSetCR";
  pflcWFieldSetCR = (tflcWFieldSetCR)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldSetCR == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldDeleteCR";
  pflcWFieldDeleteCR = (tflcWFieldDeleteCR)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldDeleteCR == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldActiveCR";
  pflcWFieldActiveCR = (tflcWFieldActiveCR)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldActiveCR == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldSave";
  pflcWFieldSave = (tflcWFieldSave)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldSave == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldLoad";
  pflcWFieldLoad = (tflcWFieldLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldLoad == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldFirstCR";
  pflcWFieldFirstCR = (tflcWFieldFirstCR)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldFirstCR == NULL){
    goto mErr;
  }
  szFuncName = "lcWFieldNextCR";
  pflcWFieldNextCR = (tflcWFieldNextCR)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWFieldNextCR == NULL){
    goto mErr;
  }
  szFuncName = "lcExpEntity";
  pflcExpEntity = (tflcExpEntity)GetProcAddress( ghLibInst, szFuncName );
  if (pflcExpEntity == NULL){
    goto mErr;
  }
  szFuncName = "lcExpGetPline";
  pflcExpGetPline = (tflcExpGetPline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcExpGetPline == NULL){
    goto mErr;
  }
  szFuncName = "lcExpGetVertex";
  pflcExpGetVertex = (tflcExpGetVertex)GetProcAddress( ghLibInst, szFuncName );
  if (pflcExpGetVertex == NULL){
    goto mErr;
  }
  szFuncName = "lcGbrLoad";
  pflcGbrLoad = (tflcGbrLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGbrLoad == NULL){
    goto mErr;
  }
  szFuncName = "lcGbrClose";
  pflcGbrClose = (tflcGbrClose)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGbrClose == NULL){
    goto mErr;
  }
  szFuncName = "lcPlugGetOption";
  pflcPlugGetOption = (tflcPlugGetOption)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlugGetOption == NULL){
    goto mErr;
  }
  szFuncName = "lcPlugGetOption2";
  pflcPlugGetOption2 = (tflcPlugGetOption2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlugGetOption2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPlugSetOption";
  pflcPlugSetOption = (tflcPlugSetOption)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPlugSetOption == NULL){
    goto mErr;
  }
//  szFuncName = "lcPrintSetup";
//  pflcPrintSetup = (tflcPrintSetup)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcPrintSetup == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcPrintLayout";
//  pflcPrintLayout = (tflcPrintLayout)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcPrintLayout == NULL){
//    goto mErr;
//  }
//  szFuncName = "lcPrintBlock";
//  pflcPrintBlock = (tflcPrintBlock)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcPrintBlock == NULL){
//    goto mErr;
//  }
  szFuncName = "lc2_Initialize";
  pflc2_Initialize = (tflc2_Initialize)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_Initialize == NULL){
    goto mErr;
  }
  szFuncName = "lc2_Uninitialize";
  pflc2_Uninitialize = (tflc2_Uninitialize)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_Uninitialize == NULL){
    goto mErr;
  }
  szFuncName = "lc2_Create";
  pflc2_Create = (tflc2_Create)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_Create == NULL){
    goto mErr;
  }
  szFuncName = "lc2_Delete";
  pflc2_Delete = (tflc2_Delete)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_Delete == NULL){
    goto mErr;
  }
  szFuncName = "lc2_OnClose";
  pflc2_OnClose = (tflc2_OnClose)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_OnClose == NULL){
    goto mErr;
  }
  szFuncName = "lc2_Position";
  pflc2_Position = (tflc2_Position)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_Position == NULL){
    goto mErr;
  }
  szFuncName = "lc2_Command";
  pflc2_Command = (tflc2_Command)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_Command == NULL){
    goto mErr;
  }
  szFuncName = "lc2_GetWnd";
  pflc2_GetWnd = (tflc2_GetWnd)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_GetWnd == NULL){
    goto mErr;
  }
  szFuncName = "lc2_GetDrw";
  pflc2_GetDrw = (tflc2_GetDrw)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_GetDrw == NULL){
    goto mErr;
  }
  szFuncName = "lc2_GetBlock";
  pflc2_GetBlock = (tflc2_GetBlock)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_GetBlock == NULL){
    goto mErr;
  }
  szFuncName = "lc2_FileLoad";
  pflc2_FileLoad = (tflc2_FileLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_FileLoad == NULL){
    goto mErr;
  }
  szFuncName = "lc2_FileSave";
  pflc2_FileSave = (tflc2_FileSave)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_FileSave == NULL){
    goto mErr;
  }
  szFuncName = "lc2_WFieldSave";
  pflc2_WFieldSave = (tflc2_WFieldSave)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_WFieldSave == NULL){
    goto mErr;
  }
  szFuncName = "lc2_WFieldLoad";
  pflc2_WFieldLoad = (tflc2_WFieldLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_WFieldLoad == NULL){
    goto mErr;
  }
  szFuncName = "lc2_ExpStart";
  pflc2_ExpStart = (tflc2_ExpStart)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_ExpStart == NULL){
    goto mErr;
  }
  szFuncName = "lc2_ExpGetPline";
  pflc2_ExpGetPline = (tflc2_ExpGetPline)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_ExpGetPline == NULL){
    goto mErr;
  }
  szFuncName = "lc2_ExpGetEntity";
  pflc2_ExpGetEntity = (tflc2_ExpGetEntity)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_ExpGetEntity == NULL){
    goto mErr;
  }
  szFuncName = "lc2_ExpGetVertex";
  pflc2_ExpGetVertex = (tflc2_ExpGetVertex)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_ExpGetVertex == NULL){
    goto mErr;
  }
  szFuncName = "lc2_ExpGetPoint";
  pflc2_ExpGetPoint = (tflc2_ExpGetPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_ExpGetPoint == NULL){
    goto mErr;
  }
  szFuncName = "lc2_CbCopy";
  pflc2_CbCopy = (tflc2_CbCopy)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_CbCopy == NULL){
    goto mErr;
  }
  szFuncName = "lc2_CbCopy2";
  pflc2_CbCopy2 = (tflc2_CbCopy2)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_CbCopy2 == NULL){
    goto mErr;
  }
  szFuncName = "lc2_CbPaste";
  pflc2_CbPaste = (tflc2_CbPaste)GetProcAddress( ghLibInst, szFuncName );
  if (pflc2_CbPaste == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_EnableFileExt";
  pflcMru_EnableFileExt = (tflcMru_EnableFileExt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_EnableFileExt == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_Load";
  pflcMru_Load = (tflcMru_Load)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_Load == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_Save";
  pflcMru_Save = (tflcMru_Save)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_Save == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_AddFile";
  pflcMru_AddFile = (tflcMru_AddFile)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_AddFile == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_SetImage";
  pflcMru_SetImage = (tflcMru_SetImage)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_SetImage == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_HasImage";
  pflcMru_HasImage = (tflcMru_HasImage)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_HasImage == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_SetViewRect";
  pflcMru_SetViewRect = (tflcMru_SetViewRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_SetViewRect == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_GetViewRect";
  pflcMru_GetViewRect = (tflcMru_GetViewRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_GetViewRect == NULL){
    goto mErr;
  }
  szFuncName = "lcMru_Dialog";
  pflcMru_Dialog = (tflcMru_Dialog)GetProcAddress( ghLibInst, szFuncName );
  if (pflcMru_Dialog == NULL){
    goto mErr;
  }
  szFuncName = "lcWndTabClear";
  pflcWndTabClear = (tflcWndTabClear)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndTabClear == NULL){
    goto mErr;
  }
  szFuncName = "lcWndTabAdd";
  pflcWndTabAdd = (tflcWndTabAdd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndTabAdd == NULL){
    goto mErr;
  }
  szFuncName = "lcWndTabSelect";
  pflcWndTabSelect = (tflcWndTabSelect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndTabSelect == NULL){
    goto mErr;
  }
  szFuncName = "lcWndPaperEnable";
  pflcWndPaperEnable = (tflcWndPaperEnable)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndPaperEnable == NULL){
    goto mErr;
  }
  szFuncName = "lcWndPaperSetSize";
  pflcWndPaperSetSize = (tflcWndPaperSetSize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndPaperSetSize == NULL){
    goto mErr;
  }
  szFuncName = "lcWndPaperSetSize2";
  pflcWndPaperSetSize2 = (tflcWndPaperSetSize2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndPaperSetSize2 == NULL){
    goto mErr;
  }
  szFuncName = "lcWndPaperSetPos";
  pflcWndPaperSetPos = (tflcWndPaperSetPos)GetProcAddress( ghLibInst, szFuncName );
  if (pflcWndPaperSetPos == NULL){
    goto mErr;
  }
  szFuncName = "lcGripClear";
  pflcGripClear = (tflcGripClear)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGripClear == NULL){
    goto mErr;
  }
  szFuncName = "lcGripAdd";
  pflcGripAdd = (tflcGripAdd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGripAdd == NULL){
    goto mErr;
  }
  szFuncName = "lcGripSet";
  pflcGripSet = (tflcGripSet)GetProcAddress( ghLibInst, szFuncName );
  if (pflcGripSet == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PenCreate";
  pflcPaint_PenCreate = (tflcPaint_PenCreate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PenCreate == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PenSelect";
  pflcPaint_PenSelect = (tflcPaint_PenSelect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PenSelect == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PenSelectID";
  pflcPaint_PenSelectID = (tflcPaint_PenSelectID)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PenSelectID == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_BrushCreate";
  pflcPaint_BrushCreate = (tflcPaint_BrushCreate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_BrushCreate == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_BrushSelect";
  pflcPaint_BrushSelect = (tflcPaint_BrushSelect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_BrushSelect == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_BrushSelectID";
  pflcPaint_BrushSelectID = (tflcPaint_BrushSelectID)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_BrushSelectID == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawPtbuf";
  pflcPaint_DrawPtbuf = (tflcPaint_DrawPtbuf)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawPtbuf == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawMpgon";
  pflcPaint_DrawMpgon = (tflcPaint_DrawMpgon)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawMpgon == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawImage";
  pflcPaint_DrawImage = (tflcPaint_DrawImage)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawImage == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawImage2";
  pflcPaint_DrawImage2 = (tflcPaint_DrawImage2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawImage2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawText";
  pflcPaint_DrawText = (tflcPaint_DrawText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawText == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawText2";
  pflcPaint_DrawText2 = (tflcPaint_DrawText2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawText2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawTextBC";
  pflcPaint_DrawTextBC = (tflcPaint_DrawTextBC)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawTextBC == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawArcText";
  pflcPaint_DrawArcText = (tflcPaint_DrawArcText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawArcText == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawHatch";
  pflcPaint_DrawHatch = (tflcPaint_DrawHatch)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawHatch == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawPoint";
  pflcPaint_DrawPoint = (tflcPaint_DrawPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawLine";
  pflcPaint_DrawLine = (tflcPaint_DrawLine)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawLine == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawXline";
  pflcPaint_DrawXline = (tflcPaint_DrawXline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawXline == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawRect";
  pflcPaint_DrawRect = (tflcPaint_DrawRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawRect == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawRect2";
  pflcPaint_DrawRect2 = (tflcPaint_DrawRect2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawRect2 == NULL){
    goto mErr;
  }
//  szFuncName = "lcPaint_DrawPickBox";
//  pflcPaint_DrawPickBox = (tflcPaint_DrawPickBox)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcPaint_DrawPickBox == NULL){
//    goto mErr;
//  }
  szFuncName = "lcPaint_DrawTIN";
  pflcPaint_DrawTIN = (tflcPaint_DrawTIN)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawTIN == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawGrid";
  pflcPaint_DrawGrid = (tflcPaint_DrawGrid)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawGrid == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DrawCPrompt";
  pflcPaint_DrawCPrompt = (tflcPaint_DrawCPrompt)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DrawCPrompt == NULL){
    goto mErr;
  }
//  szFuncName = "lcPaint_SetPixel";
//  pflcPaint_SetPixel = (tflcPaint_SetPixel)GetProcAddress( ghLibInst, szFuncName );
//  if (pflcPaint_SetPixel == NULL){
//    goto mErr;
//  }
  szFuncName = "lcPaint_CreatePtbuf";
  pflcPaint_CreatePtbuf = (tflcPaint_CreatePtbuf)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_CreatePtbuf == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DeletePtbuf";
  pflcPaint_DeletePtbuf = (tflcPaint_DeletePtbuf)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DeletePtbuf == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufClear";
  pflcPaint_PtbufClear = (tflcPaint_PtbufClear)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufClear == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddPoint";
  pflcPaint_PtbufAddPoint = (tflcPaint_PtbufAddPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddPoint2";
  pflcPaint_PtbufAddPoint2 = (tflcPaint_PtbufAddPoint2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddPoint2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddPointP";
  pflcPaint_PtbufAddPointP = (tflcPaint_PtbufAddPointP)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddPointP == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddLine";
  pflcPaint_PtbufAddLine = (tflcPaint_PtbufAddLine)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddLine == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddLineP";
  pflcPaint_PtbufAddLineP = (tflcPaint_PtbufAddLineP)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddLineP == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddCircle";
  pflcPaint_PtbufAddCircle = (tflcPaint_PtbufAddCircle)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddCircle == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddCircle2";
  pflcPaint_PtbufAddCircle2 = (tflcPaint_PtbufAddCircle2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddCircle2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddCircle3";
  pflcPaint_PtbufAddCircle3 = (tflcPaint_PtbufAddCircle3)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddCircle3 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArc";
  pflcPaint_PtbufAddArc = (tflcPaint_PtbufAddArc)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArc == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArc3p";
  pflcPaint_PtbufAddArc3p = (tflcPaint_PtbufAddArc3p)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArc3p == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcSDE";
  pflcPaint_PtbufAddArcSDE = (tflcPaint_PtbufAddArcSDE)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcSDE == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcSDAR";
  pflcPaint_PtbufAddArcSDAR = (tflcPaint_PtbufAddArcSDAR)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcSDAR == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcSER";
  pflcPaint_PtbufAddArcSER = (tflcPaint_PtbufAddArcSER)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcSER == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcSEL";
  pflcPaint_PtbufAddArcSEL = (tflcPaint_PtbufAddArcSEL)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcSEL == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcSEA";
  pflcPaint_PtbufAddArcSEA = (tflcPaint_PtbufAddArcSEA)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcSEA == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcSEB";
  pflcPaint_PtbufAddArcSEB = (tflcPaint_PtbufAddArcSEB)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcSEB == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcCSE";
  pflcPaint_PtbufAddArcCSE = (tflcPaint_PtbufAddArcCSE)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcCSE == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcCSA";
  pflcPaint_PtbufAddArcCSA = (tflcPaint_PtbufAddArcCSA)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcCSA == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcCSL";
  pflcPaint_PtbufAddArcCSL = (tflcPaint_PtbufAddArcCSL)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcCSL == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddArcCRAA";
  pflcPaint_PtbufAddArcCRAA = (tflcPaint_PtbufAddArcCRAA)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddArcCRAA == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddEllipse";
  pflcPaint_PtbufAddEllipse = (tflcPaint_PtbufAddEllipse)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddEllipse == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddEllipse2";
  pflcPaint_PtbufAddEllipse2 = (tflcPaint_PtbufAddEllipse2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddEllipse2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddRect";
  pflcPaint_PtbufAddRect = (tflcPaint_PtbufAddRect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddRect == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddRect2";
  pflcPaint_PtbufAddRect2 = (tflcPaint_PtbufAddRect2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddRect2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddRect3";
  pflcPaint_PtbufAddRect3 = (tflcPaint_PtbufAddRect3)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddRect3 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddWline";
  pflcPaint_PtbufAddWline = (tflcPaint_PtbufAddWline)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddWline == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufAddPtbuf";
  pflcPaint_PtbufAddPtbuf = (tflcPaint_PtbufAddPtbuf)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufAddPtbuf == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufGetPoint";
  pflcPaint_PtbufGetPoint = (tflcPaint_PtbufGetPoint)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufGetPoint == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufGetPoint2";
  pflcPaint_PtbufGetPoint2 = (tflcPaint_PtbufGetPoint2)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufGetPoint2 == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufInterpolate";
  pflcPaint_PtbufInterpolate = (tflcPaint_PtbufInterpolate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufInterpolate == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufMove";
  pflcPaint_PtbufMove = (tflcPaint_PtbufMove)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufMove == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufRotate";
  pflcPaint_PtbufRotate = (tflcPaint_PtbufRotate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufRotate == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufScale";
  pflcPaint_PtbufScale = (tflcPaint_PtbufScale)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufScale == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufMirror";
  pflcPaint_PtbufMirror = (tflcPaint_PtbufMirror)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufMirror == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_PtbufCopy";
  pflcPaint_PtbufCopy = (tflcPaint_PtbufCopy)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_PtbufCopy == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_CreateMpgon";
  pflcPaint_CreateMpgon = (tflcPaint_CreateMpgon)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_CreateMpgon == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_DeleteMpgon";
  pflcPaint_DeleteMpgon = (tflcPaint_DeleteMpgon)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_DeleteMpgon == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonClear";
  pflcPaint_MpgonClear = (tflcPaint_MpgonClear)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonClear == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonAddPgon";
  pflcPaint_MpgonAddPgon = (tflcPaint_MpgonAddPgon)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonAddPgon == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonAddText";
  pflcPaint_MpgonAddText = (tflcPaint_MpgonAddText)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonAddText == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonAddBarcode";
  pflcPaint_MpgonAddBarcode = (tflcPaint_MpgonAddBarcode)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonAddBarcode == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonMove";
  pflcPaint_MpgonMove = (tflcPaint_MpgonMove)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonMove == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonRotate";
  pflcPaint_MpgonRotate = (tflcPaint_MpgonRotate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonRotate == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonScale";
  pflcPaint_MpgonScale = (tflcPaint_MpgonScale)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonScale == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonMirror";
  pflcPaint_MpgonMirror = (tflcPaint_MpgonMirror)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonMirror == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_MpgonCopy";
  pflcPaint_MpgonCopy = (tflcPaint_MpgonCopy)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_MpgonCopy == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_HatchGen";
  pflcPaint_HatchGen = (tflcPaint_HatchGen)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_HatchGen == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageAdd";
  pflcPaint_ImageAdd = (tflcPaint_ImageAdd)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageAdd == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageDelete";
  pflcPaint_ImageDelete = (tflcPaint_ImageDelete)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageDelete == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageGetFirst";
  pflcPaint_ImageGetFirst = (tflcPaint_ImageGetFirst)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageGetFirst == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageGetNext";
  pflcPaint_ImageGetNext = (tflcPaint_ImageGetNext)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageGetNext == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageGetByID";
  pflcPaint_ImageGetByID = (tflcPaint_ImageGetByID)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageGetByID == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageLoad";
  pflcPaint_ImageLoad = (tflcPaint_ImageLoad)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageLoad == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageCopy";
  pflcPaint_ImageCopy = (tflcPaint_ImageCopy)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageCopy == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageCreate";
  pflcPaint_ImageCreate = (tflcPaint_ImageCreate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageCreate == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageSetPixel";
  pflcPaint_ImageSetPixel = (tflcPaint_ImageSetPixel)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageSetPixel == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageFlip";
  pflcPaint_ImageFlip = (tflcPaint_ImageFlip)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageFlip == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageRotate";
  pflcPaint_ImageRotate = (tflcPaint_ImageRotate)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageRotate == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageGray";
  pflcPaint_ImageGray = (tflcPaint_ImageGray)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageGray == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageResize";
  pflcPaint_ImageResize = (tflcPaint_ImageResize)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageResize == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_ImageGetPtbuf";
  pflcPaint_ImageGetPtbuf = (tflcPaint_ImageGetPtbuf)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_ImageGetPtbuf == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_FontOpenLC";
  pflcPaint_FontOpenLC = (tflcPaint_FontOpenLC)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_FontOpenLC == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_FontOpenTT";
  pflcPaint_FontOpenTT = (tflcPaint_FontOpenTT)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_FontOpenTT == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_FontClose";
  pflcPaint_FontClose = (tflcPaint_FontClose)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_FontClose == NULL){
    goto mErr;
  }
  szFuncName = "lcPaint_FontSelect";
  pflcPaint_FontSelect = (tflcPaint_FontSelect)GetProcAddress( ghLibInst, szFuncName );
  if (pflcPaint_FontSelect == NULL){
    goto mErr;
  }
  return TRUE;
mErr:
  MessageBoxA( GetActiveWindow(), szFuncName, "Not found", MB_OK );
  return FALSE;
}

//-------------------------------------------------
BOOL lcLoadLib ()
{
  ghLibInst = LoadLibraryA( "LiteCAD.dll" );
  if (ghLibInst){
    if (SetProcAddr()){
      return TRUE;
    }
  }
  return FALSE;
}

//-------------------------------------------------
BOOL lcLoadLib64 ()
{
  ghLibInst = LoadLibraryA( "LiteCAD64.dll" );
  if (ghLibInst){
    if (SetProcAddr()){
      return TRUE;
    }
  }
  return FALSE;
}

//-------------------------------------------------
void lcFreeLib ()
{
  FreeLibrary( ghLibInst );
  ghLibInst = 0;
}


//--------------
void LCAPI lcEventSetProc (int EventType, F_LCEVENT pFunc, int Prm1, HANDLE Prm2)
{
  if (pflcEventSetProc){
    (*pflcEventSetProc)(EventType, pFunc, Prm1, Prm2);
  }
}


//--------------
void LCAPI lcEventReturnCode (int code)
{
  if (pflcEventReturnCode){
    (*pflcEventReturnCode)(code);
  }
}


//--------------
BOOL LCAPI lcEventsEnable (BOOL b)
{
  if (pflcEventsEnable){
    return (*pflcEventsEnable)(b);
  }
  return 0;
}


//--------------
BOOL LCAPI lcInitialize ()
{
  if (pflcInitialize){
    return (*pflcInitialize)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcUninitialize (BOOL bSaveConfig)
{
  if (pflcUninitialize){
    return (*pflcUninitialize)(bSaveConfig);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStrAdd (LPCWSTR szTag, LPCWSTR szText)
{
  if (pflcStrAdd){
    return (*pflcStrAdd)(szTag, szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStrSet (LPCWSTR szTag, LPCWSTR szText)
{
  if (pflcStrSet){
    return (*pflcStrSet)(szTag, szText);
  }
  return 0;
}


//--------------
LPCWSTR LCAPI lcStrGet (LPCWSTR szTag)
{
  if (pflcStrGet){
    return (*pflcStrGet)(szTag);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStrFileLoad (LPCWSTR szFileName)
{
  if (pflcStrFileLoad){
    return (*pflcStrFileLoad)(szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStrFileSave (LPCWSTR szFileName, LPCWSTR szLanguage)
{
  if (pflcStrFileSave){
    return (*pflcStrFileSave)(szFileName, szLanguage);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropGetBool (HANDLE hObject, int idProp)
{
  if (pflcPropGetBool){
    return (*pflcPropGetBool)(hObject, idProp);
  }
  return 0;
}


//--------------
int LCAPI lcPropGetInt (HANDLE hObject, int idProp)
{
  if (pflcPropGetInt){
    return (*pflcPropGetInt)(hObject, idProp);
  }
  return 0;
}


//--------------
double LCAPI lcPropGetFloat (HANDLE hObject, int idProp)
{
  if (pflcPropGetFloat){
    return (*pflcPropGetFloat)(hObject, idProp);
  }
  return 0;
}


//--------------
LPCWSTR LCAPI lcPropGetStr (HANDLE hObject, int idProp)
{
  if (pflcPropGetStr){
    return (*pflcPropGetStr)(hObject, idProp);
  }
  return 0;
}


//--------------
int LCAPI lcPropGetStr2 (HANDLE hObject, int idProp)
{
  if (pflcPropGetStr2){
    return (*pflcPropGetStr2)(hObject, idProp);
  }
  return 0;
}


//--------------
int LCAPI lcPropGetChar (int iChar)
{
  if (pflcPropGetChar){
    return (*pflcPropGetChar)(iChar);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPropGetHandle (HANDLE hObject, int idProp)
{
  if (pflcPropGetHandle){
    return (*pflcPropGetHandle)(hObject, idProp);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropPutBool (HANDLE hObject, int idProp, BOOL bValue)
{
  if (pflcPropPutBool){
    return (*pflcPropPutBool)(hObject, idProp, bValue);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropPutInt (HANDLE hObject, int idProp, int Value)
{
  if (pflcPropPutInt){
    return (*pflcPropPutInt)(hObject, idProp, Value);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropPutFloat (HANDLE hObject, int idProp, double Value)
{
  if (pflcPropPutFloat){
    return (*pflcPropPutFloat)(hObject, idProp, Value);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropPutStr (HANDLE hObject, int idProp, LPCWSTR szValue)
{
  if (pflcPropPutStr){
    return (*pflcPropPutStr)(hObject, idProp, szValue);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropPutHandle (HANDLE hObject, int idProp, HANDLE hValue)
{
  if (pflcPropPutHandle){
    return (*pflcPropPutHandle)(hObject, idProp, hValue);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcCreateWindow (HWND hWndParent, int Style)
{
  if (pflcCreateWindow){
    return (*pflcCreateWindow)(hWndParent, Style);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDeleteWindow (HANDLE hLcWnd)
{
  if (pflcDeleteWindow){
    return (*pflcDeleteWindow)(hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndResize (HANDLE hLcWnd, int Left, int Top, int Width, int Height)
{
  if (pflcWndResize){
    return (*pflcWndResize)(hLcWnd, Left, Top, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndRedraw (HANDLE hLcWnd)
{
  if (pflcWndRedraw){
    return (*pflcWndRedraw)(hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndSetFocus (HANDLE hLcWnd)
{
  if (pflcWndSetFocus){
    return (*pflcWndSetFocus)(hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndSetExtents (HANDLE hLcWnd, double Xmin, double Ymin, double Xmax, double Ymax)
{
  if (pflcWndSetExtents){
    return (*pflcWndSetExtents)(hLcWnd, Xmin, Ymin, Xmax, Ymax);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndZoomRect (HANDLE hLcWnd, double Left, double Bottom, double Right, double Top)
{
  if (pflcWndZoomRect){
    return (*pflcWndZoomRect)(hLcWnd, Left, Bottom, Right, Top);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndZoomScale (HANDLE hLcWnd, double Scal)
{
  if (pflcWndZoomScale){
    return (*pflcWndZoomScale)(hLcWnd, Scal);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndZoomMove (HANDLE hLcWnd, double DX, double DY)
{
  if (pflcWndZoomMove){
    return (*pflcWndZoomMove)(hLcWnd, DX, DY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndGetCursorCoord (HANDLE hLcWnd, int* pXwin, int* pYwin, double* pXdrw, double* pYdrw)
{
  if (pflcWndGetCursorCoord){
    return (*pflcWndGetCursorCoord)(hLcWnd, pXwin, pYwin, pXdrw, pYdrw);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndExeCommand (HANDLE hLcWnd, int Command, int CmdParam)
{
  if (pflcWndExeCommand){
    return (*pflcWndExeCommand)(hLcWnd, Command, CmdParam);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndOnClose (HANDLE hLcWnd)
{
  if (pflcWndOnClose){
    return (*pflcWndOnClose)(hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndSetBlock (HANDLE hLcWnd, HANDLE hBlock)
{
  if (pflcWndSetBlock){
    return (*pflcWndSetBlock)(hLcWnd, hBlock);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndSetProps (HANDLE hLcWnd, HANDLE hPropWnd)
{
  if (pflcWndSetProps){
    return (*pflcWndSetProps)(hLcWnd, hPropWnd);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcWndGetEntByPoint (HANDLE hLcWnd, int Xwin, int Ywin)
{
  if (pflcWndGetEntByPoint){
    return (*pflcWndGetEntByPoint)(hLcWnd, Xwin, Ywin);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcWndGetEntByPoint2 (HANDLE hLcWnd, double X, double Y, double Delta)
{
  if (pflcWndGetEntByPoint2){
    return (*pflcWndGetEntByPoint2)(hLcWnd, X, Y, Delta);
  }
  return 0;
}


//--------------
int LCAPI lcWndGetEntsByRect (HANDLE hLcWnd, double Lef, double Bot, double Rig, double Top, BOOL bCross, int nMaxEnts)
{
  if (pflcWndGetEntsByRect){
    return (*pflcWndGetEntsByRect)(hLcWnd, Lef, Bot, Rig, Top, bCross, nMaxEnts);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcWndGetEntity (int iEnt)
{
  if (pflcWndGetEntity){
    return (*pflcWndGetEntity)(iEnt);
  }
  return 0;
}


//--------------
//HANDLE LCAPI lcWndGetEntByID (HANDLE hLcWnd, int Id)
//{
//  if (pflcWndGetEntByID){
//    return (*pflcWndGetEntByID)(hLcWnd, Id);
//  }
//  return 0;
//}


//--------------
//HANDLE LCAPI lcWndGetEntByIDH (HANDLE hLcWnd, LPCWSTR szId)
//{
//  if (pflcWndGetEntByIDH){
//    return (*pflcWndGetEntByIDH)(hLcWnd, szId);
//  }
//  return 0;
//}


//--------------
//HANDLE LCAPI lcWndGetEntByKey (HANDLE hLcWnd, int Key)
//{
//  if (pflcWndGetEntByKey){
//    return (*pflcWndGetEntByKey)(hLcWnd, Key);
//  }
//  return 0;
//}


//--------------
//BOOL LCAPI lcWndEmulator (HANDLE hLcWnd, int Mode)
//{
//  if (pflcWndEmulator){
//    return (*pflcWndEmulator)(hLcWnd, Mode);
//  }
//  return 0;
//}


//--------------
//BOOL LCAPI lcWndMagnifier (HANDLE hLcWnd, BOOL bOn, int Width, int Height, int Zoom, int Flags)
//{
//  if (pflcWndMagnifier){
//    return (*pflcWndMagnifier)(hLcWnd, bOn, Width, Height, Zoom, Flags);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lcWndCoordFromDrw (HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwin, int* pYwin)
{
  if (pflcWndCoordFromDrw){
    return (*pflcWndCoordFromDrw)(hLcWnd, Xdrw, Ydrw, pXwin, pYwin);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndCoordToDrw (HANDLE hLcWnd, int Xwin, int Ywin, double* pXdrw, double* pYdrw)
{
  if (pflcWndCoordToDrw){
    return (*pflcWndCoordToDrw)(hLcWnd, Xwin, Ywin, pXdrw, pYdrw);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCoordDrwToWnd (HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwnd, int* pYwnd)
{
  if (pflcCoordDrwToWnd){
    return (*pflcCoordDrwToWnd)(hLcWnd, Xdrw, Ydrw, pXwnd, pYwnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCoordWndToDrw (HANDLE hLcWnd, int Xwnd, int Ywnd, double* pXdrw, double* pYdrw)
{
  if (pflcCoordWndToDrw){
    return (*pflcCoordWndToDrw)(hLcWnd, Xwnd, Ywnd, pXdrw, pYdrw);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcFontGetFirst ()
{
  if (pflcFontGetFirst){
    return (*pflcFontGetFirst)();
  }
  return 0;
}


//--------------
HANDLE LCAPI lcFontGetNext (HANDLE hFont)
{
  if (pflcFontGetNext){
    return (*pflcFontGetNext)(hFont);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcFontAddRes (LPCWSTR szFontName, HANDLE hModule, int idResource)
{
  if (pflcFontAddRes){
    return (*pflcFontAddRes)(szFontName, hModule, idResource);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcFontAddFile (LPCWSTR szFontName, LPCWSTR szFilename)
{
  if (pflcFontAddFile){
    return (*pflcFontAddFile)(szFontName, szFilename);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcFontAddBin (LPCWSTR szFontName, HANDLE hData)
{
  if (pflcFontAddBin){
    return (*pflcFontAddBin)(szFontName, hData);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcFontGetChar (HANDLE hFont, int CharCode)
{
  if (pflcFontGetChar){
    return (*pflcFontGetChar)(hFont, CharCode);
  }
  return 0;
}


//--------------
BOOL LCAPI lcProgressCreate (HANDLE hLcWnd, int W, int H, LPCWSTR szTitle)
{
  if (pflcProgressCreate){
    return (*pflcProgressCreate)(hLcWnd, W, H, szTitle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcProgressSetText (LPCWSTR szText)
{
  if (pflcProgressSetText){
    return (*pflcProgressSetText)(szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcProgressStart (int MinVal, int MaxVal)
{
  if (pflcProgressStart){
    return (*pflcProgressStart)(MinVal, MaxVal);
  }
  return 0;
}


//--------------
BOOL LCAPI lcProgressSetPos (int Val)
{
  if (pflcProgressSetPos){
    return (*pflcProgressSetPos)(Val);
  }
  return 0;
}


//--------------
BOOL LCAPI lcProgressInc ()
{
  if (pflcProgressInc){
    return (*pflcProgressInc)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcProgressDelete ()
{
  if (pflcProgressDelete){
    return (*pflcProgressDelete)();
  }
  return 0;
}


//--------------
HANDLE LCAPI lcQuadCreate ()
{
  if (pflcQuadCreate){
    return (*pflcQuadCreate)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcQuadDelete (HANDLE hQuad)
{
  if (pflcQuadDelete){
    return (*pflcQuadDelete)(hQuad);
  }
  return 0;
}


//--------------
BOOL LCAPI lcQuadSet (HANDLE hQuad, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
{
  if (pflcQuadSet){
    return (*pflcQuadSet)(hQuad, x0, y0, x1, y1, x2, y2, x3, y3);
  }
  return 0;
}


//--------------
BOOL LCAPI lcQuadTransXYtoUV (HANDLE hQuad, double X, double Y, double* pU, double* pV)
{
  if (pflcQuadTransXYtoUV){
    return (*pflcQuadTransXYtoUV)(hQuad, X, Y, pU, pV);
  }
  return 0;
}


//--------------
BOOL LCAPI lcQuadTransUVtoXY (HANDLE hQuad, double U, double V, double* pX, double* pY)
{
  if (pflcQuadTransUVtoXY){
    return (*pflcQuadTransUVtoXY)(hQuad, U, V, pX, pY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcQuadContains (HANDLE hQuad, double X, double Y)
{
  if (pflcQuadContains){
    return (*pflcQuadContains)(hQuad, X, Y);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcGridCreate ()
{
  if (pflcGridCreate){
    return (*pflcGridCreate)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridDelete (HANDLE hGrid)
{
  if (pflcGridDelete){
    return (*pflcGridDelete)(hGrid);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridSet (HANDLE hGrid, double X0, double Y0, double W, double H, int Nx, int Ny)
{
  if (pflcGridSet){
    return (*pflcGridSet)(hGrid, X0, Y0, W, H, Nx, Ny);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridSetDest (HANDLE hGrid, int Ix, int Iy, double X, double Y)
{
  if (pflcGridSetDest){
    return (*pflcGridSetDest)(hGrid, Ix, Iy, X, Y);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridUpdate (HANDLE hGrid)
{
  if (pflcGridUpdate){
    return (*pflcGridUpdate)(hGrid);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridTrans (HANDLE hGrid, double X, double Y, double* pXdest, double* pYdest)
{
  if (pflcGridTrans){
    return (*pflcGridTrans)(hGrid, X, Y, pXdest, pYdest);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridGetNode (HANDLE hGrid, BOOL bDest, int Ix, int Iy, double* pX, double* pY)
{
  if (pflcGridGetNode){
    return (*pflcGridGetNode)(hGrid, bDest, Ix, Iy, pX, pY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridGetCell (HANDLE hGrid, double X, double Y, int* pIx, int* pIy)
{
  if (pflcGridGetCell){
    return (*pflcGridGetCell)(hGrid, X, Y, pIx, pIy);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGridSetView (HANDLE hGrid, int Mode, HANDLE hLcWnd, COLORREF ColLine, COLORREF ColNode)
{
  if (pflcGridSetView){
    return (*pflcGridSetView)(hGrid, Mode, hLcWnd, ColLine, ColNode);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcTIN_Create (int Id)
{
  if (pflcTIN_Create){
    return (*pflcTIN_Create)(Id);
  }
  return 0;
}


//--------------
BOOL LCAPI lcTIN_Delete (HANDLE hTIN)
{
  if (pflcTIN_Delete){
    return (*pflcTIN_Delete)(hTIN);
  }
  return 0;
}


//--------------
BOOL LCAPI lcTIN_Load (HANDLE hTIN, LPCWSTR szFileName, HANDLE hWnd)
{
  if (pflcTIN_Load){
    return (*pflcTIN_Load)(hTIN, szFileName, hWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcTIN_GetZ (HANDLE hTIN, double X, double Y, double* pZ)
{
  if (pflcTIN_GetZ){
    return (*pflcTIN_GetZ)(hTIN, X, Y, pZ);
  }
  return 0;
}


//--------------
int LCAPI lcTIN_InterLine (HANDLE hTIN, double X0, double Y0, double X1, double Y1)
{
  if (pflcTIN_InterLine){
    return (*pflcTIN_InterLine)(hTIN, X0, Y0, X1, Y1);
  }
  return 0;
}


//--------------
BOOL LCAPI lcTIN_InterGetPoint (HANDLE hTIN, int iPnt, double* pX, double* pY, double* pZ)
{
  if (pflcTIN_InterGetPoint){
    return (*pflcTIN_InterGetPoint)(hTIN, iPnt, pX, pY, pZ);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcCreateProps (HWND hWndParent)
{
  if (pflcCreateProps){
    return (*pflcCreateProps)(hWndParent);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDeleteProps (HANDLE hPropWnd)
{
  if (pflcDeleteProps){
    return (*pflcDeleteProps)(hPropWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropsResize (HANDLE hPropWnd, int Left, int Top, int Width, int Height)
{
  if (pflcPropsResize){
    return (*pflcPropsResize)(hPropWnd, Left, Top, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPropsUpdate (HANDLE hPropWnd, BOOL bSelChanged)
{
  if (pflcPropsUpdate){
    return (*pflcPropsUpdate)(hPropWnd, bSelChanged);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcCreateStatbar (HWND hWndParent)
{
  if (pflcCreateStatbar){
    return (*pflcCreateStatbar)(hWndParent);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDeleteStatbar (HANDLE hStatbar)
{
  if (pflcDeleteStatbar){
    return (*pflcDeleteStatbar)(hStatbar);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStatbarResize (HANDLE hStatbar, int Left, int Top, int Width, int Height)
{
  if (pflcStatbarResize){
    return (*pflcStatbarResize)(hStatbar, Left, Top, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStatbarCell (HANDLE hStatbar, int Id, int Pos)
{
  if (pflcStatbarCell){
    return (*pflcStatbarCell)(hStatbar, Id, Pos);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStatbarText (HANDLE hStatbar, int Id, LPCWSTR szText)
{
  if (pflcStatbarText){
    return (*pflcStatbarText)(hStatbar, Id, szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcStatbarRedraw (HANDLE hStatbar)
{
  if (pflcStatbarRedraw){
    return (*pflcStatbarRedraw)(hStatbar);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDgGetValue (HANDLE hWnd, int Lef, int Top, LPCWSTR szTitle, LPCWSTR szPrompt)
{
  if (pflcDgGetValue){
    return (*pflcDgGetValue)(hWnd, Lef, Top, szTitle, szPrompt);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHelp (LPCWSTR szTopic)
{
  if (pflcHelp){
    return (*pflcHelp)(szTopic);
  }
  return 0;
}


//--------------
void LCAPI lcGetPolarPoint (double x0, double y0, double Angle, double Dist, double* pOutX, double* pOutY)
{
  if (pflcGetPolarPoint){
    (*pflcGetPolarPoint)(x0, y0, Angle, Dist, pOutX, pOutY);
  }
}


//--------------
void LCAPI lcGetPolarPrm (double x1, double y1, double x2, double y2, double* pAngle, double* pDist)
{
  if (pflcGetPolarPrm){
    (*pflcGetPolarPrm)(x1, y1, x2, y2, pAngle, pDist);
  }
}


//--------------
BOOL LCAPI lcGetClientSize (HWND hWnd, int* pWidth, int* pHeight)
{
  if (pflcGetClientSize){
    return (*pflcGetClientSize)(hWnd, pWidth, pHeight);
  }
  return 0;
}


//--------------
int LCAPI lcGetErrorCode ()
{
  if (pflcGetErrorCode){
    return (*pflcGetErrorCode)();
  }
  return 0;
}


//--------------
LPCWSTR LCAPI lcGetErrorStr ()
{
  if (pflcGetErrorStr){
    return (*pflcGetErrorStr)();
  }
  return 0;
}


//--------------
HANDLE LCAPI lcCreateCommand (HANDLE hLcWnd, int Id, LPCWSTR szTitle)
{
  if (pflcCreateCommand){
    return (*pflcCreateCommand)(hLcWnd, Id, szTitle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCmdExit (HANDLE hCmd)
{
  if (pflcCmdExit){
    return (*pflcCmdExit)(hCmd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCmdCursorText (HANDLE hCmd, LPCWSTR szText)
{
  if (pflcCmdCursorText){
    return (*pflcCmdCursorText)(hCmd, szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCmdMessage (HANDLE hCmd, LPCWSTR szText, int IconType)
{
  if (pflcCmdMessage){
    return (*pflcCmdMessage)(hCmd, szText, IconType);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCmdResetLastPt (HANDLE hCmd)
{
  if (pflcCmdResetLastPt){
    return (*pflcCmdResetLastPt)(hCmd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCameraConnect (LPCWSTR szName)
{
  if (pflcCameraConnect){
    return (*pflcCameraConnect)(szName);
  }
  return 0;
}


//--------------
BOOL LCAPI lcCameraDisconnect ()
{
  if (pflcCameraDisconnect){
    return (*pflcCameraDisconnect)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcCameraShot ()
{
  if (pflcCameraShot){
    return (*pflcCameraShot)();
  }
  return 0;
}


//--------------
HANDLE LCAPI lcCreateDrawing ()
{
  if (pflcCreateDrawing){
    return (*pflcCreateDrawing)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcDeleteDrawing (HANDLE hDrw)
{
  if (pflcDeleteDrawing){
    return (*pflcDeleteDrawing)(hDrw);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwNew (HANDLE hDrw, LPCWSTR szFileName, HANDLE hLcWnd)
{
  if (pflcDrwNew){
    return (*pflcDrwNew)(hDrw, szFileName, hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwLoad (HANDLE hDrw, LPCWSTR szFileName, HANDLE hLcWnd)
{
  if (pflcDrwLoad){
    return (*pflcDrwLoad)(hDrw, szFileName, hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwLoadMem (HANDLE hDrw, HANDLE hMem, HANDLE hLcWnd)
{
  if (pflcDrwLoadMem){
    return (*pflcDrwLoadMem)(hDrw, hMem, hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwInsert (HANDLE hDrw, LPCWSTR szFileName, int Overwrite, HANDLE hLcWnd)
{
  if (pflcDrwInsert){
    return (*pflcDrwInsert)(hDrw, szFileName, Overwrite, hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwCopy (HANDLE hDrw, HANDLE hDrwSrc)
{
  if (pflcDrwCopy){
    return (*pflcDrwCopy)(hDrw, hDrwSrc);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwSave (HANDLE hDrw, LPCWSTR szFileName, BOOL bBak, HANDLE hLcWnd)
{
  if (pflcDrwSave){
    return (*pflcDrwSave)(hDrw, szFileName, bBak, hLcWnd);
  }
  return 0;
}


//--------------
int LCAPI lcDrwSaveMem (HANDLE hDrw, HANDLE hMem, int MemSize)
{
  if (pflcDrwSaveMem){
    return (*pflcDrwSaveMem)(hDrw, hMem, MemSize);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddLayer (HANDLE hDrw, LPCWSTR szName, LPCWSTR szColor, HANDLE hLtype, int Lwidth)
{
  if (pflcDrwAddLayer){
    return (*pflcDrwAddLayer)(hDrw, szName, szColor, hLtype, Lwidth);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddLinetype (HANDLE hDrw, LPCWSTR szName, LPCWSTR szDefinition)
{
  if (pflcDrwAddLinetype){
    return (*pflcDrwAddLinetype)(hDrw, szName, szDefinition);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddLinetypeF (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, LPCWSTR szLtypeName)
{
  if (pflcDrwAddLinetypeF){
    return (*pflcDrwAddLinetypeF)(hDrw, szName, szFileName, szLtypeName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddTextStyle (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFontName, BOOL bWinFont)
{
  if (pflcDrwAddTextStyle){
    return (*pflcDrwAddTextStyle)(hDrw, szName, szFontName, bWinFont);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddDimStyle (HANDLE hDrw, LPCWSTR szName)
{
  if (pflcDrwAddDimStyle){
    return (*pflcDrwAddDimStyle)(hDrw, szName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddMlineStyle (HANDLE hDrw, LPCWSTR szName)
{
  if (pflcDrwAddMlineStyle){
    return (*pflcDrwAddMlineStyle)(hDrw, szName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddPntStyle (HANDLE hDrw, LPCWSTR szName, HANDLE hBlock, double BlockScale, HANDLE hTStyle, double TextHeight, double TextWidth)
{
  if (pflcDrwAddPntStyle){
    return (*pflcDrwAddPntStyle)(hDrw, szName, hBlock, BlockScale, hTStyle, TextHeight, TextWidth);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddImage (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName)
{
  if (pflcDrwAddImage){
    return (*pflcDrwAddImage)(hDrw, szName, szFileName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddImage2 (HANDLE hDrw, LPCWSTR szName, int Width, int Height, int nBits)
{
  if (pflcDrwAddImage2){
    return (*pflcDrwAddImage2)(hDrw, szName, Width, Height, nBits);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddImage3 (HANDLE hDrw, LPCWSTR szName, HANDLE hMem)
{
  if (pflcDrwAddImage3){
    return (*pflcDrwAddImage3)(hDrw, szName, hMem);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddBlock (HANDLE hDrw, LPCWSTR szName, double X, double Y)
{
  if (pflcDrwAddBlock){
    return (*pflcDrwAddBlock)(hDrw, szName, X, Y);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddBlockFromFile (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent)
{
  if (pflcDrwAddBlockFromFile){
    return (*pflcDrwAddBlockFromFile)(hDrw, szName, szFileName, Overwrite, hwParent);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddBlockFromDrw (HANDLE hDrw, LPCWSTR szName, HANDLE hDrw2, int Overwrite, HWND hwParent)
{
  if (pflcDrwAddBlockFromDrw){
    return (*pflcDrwAddBlockFromDrw)(hDrw, szName, hDrw2, Overwrite, hwParent);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddBlockFile (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent)
{
  if (pflcDrwAddBlockFile){
    return (*pflcDrwAddBlockFile)(hDrw, szName, szFileName, Overwrite, hwParent);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddBlockPaper (HANDLE hDrw, LPCWSTR szName, int PaperSize, int Orient, double Width, double Height)
{
  if (pflcDrwAddBlockPaper){
    return (*pflcDrwAddBlockPaper)(hDrw, szName, PaperSize, Orient, Width, Height);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwAddBlockCopy (HANDLE hDrw, LPCWSTR szName, HANDLE hSrcBlock)
{
  if (pflcDrwAddBlockCopy){
    return (*pflcDrwAddBlockCopy)(hDrw, szName, hSrcBlock);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwDeleteObject (HANDLE hDrw, HANDLE hObject)
{
  if (pflcDrwDeleteObject){
    return (*pflcDrwDeleteObject)(hDrw, hObject);
  }
  return 0;
}


//--------------
int LCAPI lcDrwDeleteUnused (HANDLE hDrw, int ObjType)
{
  if (pflcDrwDeleteUnused){
    return (*pflcDrwDeleteUnused)(hDrw, ObjType);
  }
  return 0;
}


//--------------
int LCAPI lcDrwCountObjects (HANDLE hDrw, int ObjType)
{
  if (pflcDrwCountObjects){
    return (*pflcDrwCountObjects)(hDrw, ObjType);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwSortObjects (HANDLE hDrw, int ObjType)
{
  if (pflcDrwSortObjects){
    return (*pflcDrwSortObjects)(hDrw, ObjType);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetFirstObject (HANDLE hDrw, int ObjType)
{
  if (pflcDrwGetFirstObject){
    return (*pflcDrwGetFirstObject)(hDrw, ObjType);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetNextObject (HANDLE hDrw, HANDLE hObject)
{
  if (pflcDrwGetNextObject){
    return (*pflcDrwGetNextObject)(hDrw, hObject);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetObjectByID (HANDLE hDrw, int ObjType, int Id)
{
  if (pflcDrwGetObjectByID){
    return (*pflcDrwGetObjectByID)(hDrw, ObjType, Id);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetObjectByIDH (HANDLE hDrw, int ObjType, LPCWSTR szId)
{
  if (pflcDrwGetObjectByIDH){
    return (*pflcDrwGetObjectByIDH)(hDrw, ObjType, szId);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetObjectByName (HANDLE hDrw, int ObjType, LPCWSTR szName)
{
  if (pflcDrwGetObjectByName){
    return (*pflcDrwGetObjectByName)(hDrw, ObjType, szName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetEntByID (HANDLE hDrw, int Id)
{
  if (pflcDrwGetEntByID){
    return (*pflcDrwGetEntByID)(hDrw, Id);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetEntByIDH (HANDLE hDrw, LPCWSTR szId)
{
  if (pflcDrwGetEntByIDH){
    return (*pflcDrwGetEntByIDH)(hDrw, szId);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcDrwGetEntByKey (HANDLE hDrw, int Key)
{
  if (pflcDrwGetEntByKey){
    return (*pflcDrwGetEntByKey)(hDrw, Key);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwClearXData (HANDLE hDrw, int ObjType, int Mode)
{
  if (pflcDrwClearXData){
    return (*pflcDrwClearXData)(hDrw, ObjType, Mode);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwPurge (HANDLE hDrw)
{
  if (pflcDrwPurge){
    return (*pflcDrwPurge)(hDrw);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwExplode (HANDLE hDrw, int Mode)
{
  if (pflcDrwExplode){
    return (*pflcDrwExplode)(hDrw, Mode);
  }
  return 0;
}


//--------------
//BOOL LCAPI lcDrwSetLimits (HANDLE hDrw, double Xmin, double Ymin, double Xmax, double Ymax)
//{
//  if (pflcDrwSetLimits){
//    return (*pflcDrwSetLimits)(hDrw, Xmin, Ymin, Xmax, Ymax);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lcDrwUndoRecord (HANDLE hDrw, int Mode)
{
  if (pflcDrwUndoRecord){
    return (*pflcDrwUndoRecord)(hDrw, Mode);
  }
  return 0;
}


//--------------
BOOL LCAPI lcDrwUndo (HANDLE hDrw, BOOL bRedo)
{
  if (pflcDrwUndo){
    return (*pflcDrwUndo)(hDrw, bRedo);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSetViewRect (HANDLE hBlock, double Xcen, double Ycen, double Width, double Height)
{
  if (pflcBlockSetViewRect){
    return (*pflcBlockSetViewRect)(hBlock, Xcen, Ycen, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSetViewRect2 (HANDLE hBlock, double Lef, double Bot, double Rig, double Top)
{
  if (pflcBlockSetViewRect2){
    return (*pflcBlockSetViewRect2)(hBlock, Lef, Bot, Rig, Top);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSetPaperSize (HANDLE hBlock, int PaperSize, int Orient, double Width, double Height)
{
  if (pflcBlockSetPaperSize){
    return (*pflcBlockSetPaperSize)(hBlock, PaperSize, Orient, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockRasterize (HANDLE hBlock, LPCWSTR szFileName, double Xmin, double Ymin, double Xmax, double Ymax, int ImgW, int ImgH)
{
  if (pflcBlockRasterize){
    return (*pflcBlockRasterize)(hBlock, szFileName, Xmin, Ymin, Xmax, Ymax, ImgW, ImgH);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockUpdate (HANDLE hBlock, BOOL bUpdEnts, HANDLE hNewEnt)
{
  if (pflcBlockUpdate){
    return (*pflcBlockUpdate)(hBlock, bUpdEnts, hNewEnt);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockScale (HANDLE hBlock, double Scale)
{
  if (pflcBlockScale){
    return (*pflcBlockScale)(hBlock, Scale);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockClear (HANDLE hBlock, HANDLE hLayer)
{
  if (pflcBlockClear){
    return (*pflcBlockClear)(hBlock, hLayer);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockPurge (HANDLE hBlock)
{
  if (pflcBlockPurge){
    return (*pflcBlockPurge)(hBlock);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSortEnts (HANDLE hBlock, BOOL bByLayers, HWND hWnd)
{
  if (pflcBlockSortEnts){
    return (*pflcBlockSortEnts)(hBlock, bByLayers, hWnd);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddPoint (HANDLE hBlock, double X, double Y)
{
  if (pflcBlockAddPoint){
    return (*pflcBlockAddPoint)(hBlock, X, Y);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddPoint2 (HANDLE hBlock, double X, double Y, int PtMode, double PtSize)
{
  if (pflcBlockAddPoint2){
    return (*pflcBlockAddPoint2)(hBlock, X, Y, PtMode, PtSize);
  }
  return 0;
}


//--------------
//HANDLE LCAPI lcBlockAddPtArray (HANDLE hBlock, LPCWSTR szFileName, HWND hWnd)
//{
//  if (pflcBlockAddPtArray){
//    return (*pflcBlockAddPtArray)(hBlock, szFileName, hWnd);
//  }
//  return 0;
//}


//--------------
HANDLE LCAPI lcBlockAddXline (HANDLE hBlock, double X, double Y, double Angle, BOOL bRay)
{
  if (pflcBlockAddXline){
    return (*pflcBlockAddXline)(hBlock, X, Y, Angle, bRay);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddXline2P (HANDLE hBlock, double X, double Y, double X2, double Y2, BOOL bRay)
{
  if (pflcBlockAddXline2P){
    return (*pflcBlockAddXline2P)(hBlock, X, Y, X2, Y2, bRay);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddLine (HANDLE hBlock, double X1, double Y1, double X2, double Y2)
{
  if (pflcBlockAddLine){
    return (*pflcBlockAddLine)(hBlock, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddLineDir (HANDLE hBlock, double X, double Y, double Angle, double Dist)
{
  if (pflcBlockAddLineDir){
    return (*pflcBlockAddLineDir)(hBlock, X, Y, Angle, Dist);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddLineTan (HANDLE hBlock, HANDLE hEnt1, HANDLE hEnt2, int Mode)
{
  if (pflcBlockAddLineTan){
    return (*pflcBlockAddLineTan)(hBlock, hEnt1, hEnt2, Mode);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddPolyline (HANDLE hBlock, int FitType, BOOL bClosed, BOOL bFilled)
{
  if (pflcBlockAddPolyline){
    return (*pflcBlockAddPolyline)(hBlock, FitType, bClosed, bFilled);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddSpline (HANDLE hBlock, BOOL bClosed, BOOL bFilled)
{
  if (pflcBlockAddSpline){
    return (*pflcBlockAddSpline)(hBlock, bClosed, bFilled);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddMline (HANDLE hBlock, int FitType, BOOL bClosed)
{
  if (pflcBlockAddMline){
    return (*pflcBlockAddMline)(hBlock, FitType, bClosed);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddRect (HANDLE hBlock, double Xc, double Yc, double Width, double Height, double Angle, BOOL bFilled)
{
  if (pflcBlockAddRect){
    return (*pflcBlockAddRect)(hBlock, Xc, Yc, Width, Height, Angle, bFilled);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddRect2 (HANDLE hBlock, double Left, double Bottom, double Width, double Height, double Rad, BOOL bFilled)
{
  if (pflcBlockAddRect2){
    return (*pflcBlockAddRect2)(hBlock, Left, Bottom, Width, Height, Rad, bFilled);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddCircle (HANDLE hBlock, double X, double Y, double Radius, BOOL bFilled)
{
  if (pflcBlockAddCircle){
    return (*pflcBlockAddCircle)(hBlock, X, Y, Radius, bFilled);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddArc (HANDLE hBlock, double X, double Y, double Radius, double StartAngle, double ArcAngle)
{
  if (pflcBlockAddArc){
    return (*pflcBlockAddArc)(hBlock, X, Y, Radius, StartAngle, ArcAngle);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddArc3P (HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3)
{
  if (pflcBlockAddArc3P){
    return (*pflcBlockAddArc3P)(hBlock, X1, Y1, X2, Y2, X3, Y3);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddEllipse (HANDLE hBlock, double X, double Y, double R1, double R2, double RotAngle, double StartAngle, double ArcAngle)
{
  if (pflcBlockAddEllipse){
    return (*pflcBlockAddEllipse)(hBlock, X, Y, R1, R2, RotAngle, StartAngle, ArcAngle);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddText (HANDLE hBlock, LPCWSTR szText, double X, double Y)
{
  if (pflcBlockAddText){
    return (*pflcBlockAddText)(hBlock, szText, X, Y);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddText2 (HANDLE hBlock, LPCWSTR szText, double X, double Y, int Align, double H, double WScale, double RotAngle, double Oblique)
{
  if (pflcBlockAddText2){
    return (*pflcBlockAddText2)(hBlock, szText, X, Y, Align, H, WScale, RotAngle, Oblique);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddText3 (HANDLE hBlock, LPCWSTR szText, double X1, double Y1, double X2, double Y2, int Align, double HW, double Oblique)
{
  if (pflcBlockAddText3){
    return (*pflcBlockAddText3)(hBlock, szText, X1, Y1, X2, Y2, Align, HW, Oblique);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddMText (HANDLE hBlock, LPCWSTR szText, double X, double Y, double WrapWidth, int Align, double RotAngle, double H, double WScale)
{
  if (pflcBlockAddMText){
    return (*pflcBlockAddMText)(hBlock, szText, X, Y, WrapWidth, Align, RotAngle, H, WScale);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddArcText (HANDLE hBlock, LPCWSTR szText, double X, double Y, double Radius, double StartAngle, BOOL bClockwise, double H, double WScale, int Align)
{
  if (pflcBlockAddArcText){
    return (*pflcBlockAddArcText)(hBlock, szText, X, Y, Radius, StartAngle, bClockwise, H, WScale, Align);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddBlockRef (HANDLE hBlock, HANDLE hRefBlock, double X, double Y, double Scal, double Angle)
{
  if (pflcBlockAddBlockRef){
    return (*pflcBlockAddBlockRef)(hBlock, hRefBlock, X, Y, Scal, Angle);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddBlockRefID (HANDLE hBlock, int idRefBlock, double X, double Y, double Scal, double Angle)
{
  if (pflcBlockAddBlockRefID){
    return (*pflcBlockAddBlockRefID)(hBlock, idRefBlock, X, Y, Scal, Angle);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddBlockRefIDH (HANDLE hBlock, LPCWSTR szIdRefBlock, double X, double Y, double Scal, double Angle)
{
  if (pflcBlockAddBlockRefIDH){
    return (*pflcBlockAddBlockRefIDH)(hBlock, szIdRefBlock, X, Y, Scal, Angle);
  }
  return 0;
}


//--------------
//HANDLE LCAPI lcBlockAddXref (HANDLE hBlock, LPCWSTR szFileName, double X, double Y, double ScalX, double ScalY, double Angle)
//{
//  if (pflcBlockAddXref){
//    return (*pflcBlockAddXref)(hBlock, szFileName, X, Y, ScalX, ScalY, Angle);
//  }
//  return 0;
//}


//--------------
HANDLE LCAPI lcBlockAddImageRef (HANDLE hBlock, HANDLE hImage, double X, double Y, double Width, double Height, BOOL bBorder)
{
  if (pflcBlockAddImageRef){
    return (*pflcBlockAddImageRef)(hBlock, hImage, X, Y, Width, Height, bBorder);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddEcw (HANDLE hBlock, LPCWSTR szFileName)
{
  if (pflcBlockAddEcw){
    return (*pflcBlockAddEcw)(hBlock, szFileName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddBarcode (HANDLE hBlock, int BarType, double Xc, double Yc, double Width, double Height, LPCWSTR szText)
{
  if (pflcBlockAddBarcode){
    return (*pflcBlockAddBarcode)(hBlock, BarType, Xc, Yc, Width, Height, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddHatch (HANDLE hBlock, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle)
{
  if (pflcBlockAddHatch){
    return (*pflcBlockAddHatch)(hBlock, szFileName, szPatName, Scal, Angle);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddViewport (HANDLE hBlock, double Lef, double Bot, double Width, double Height, double DrwPntX, double DrwPntY, double DrwScale, double DrwAngle)
{
  if (pflcBlockAddViewport){
    return (*pflcBlockAddViewport)(hBlock, Lef, Bot, Width, Height, DrwPntX, DrwPntY, DrwScale, DrwAngle);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddFace (HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2)
{
  if (pflcBlockAddFace){
    return (*pflcBlockAddFace)(hBlock, Flags, x0, y0, z0, x1, y1, z1, x2, y2, z2);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddFace4 (HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
  if (pflcBlockAddFace4){
    return (*pflcBlockAddFace4)(hBlock, Flags, x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddLeader (HANDLE hBlock, LPCWSTR szText, double Xt, double Yt, double LandDist, double Xa, double Ya, int Attach, int Align)
{
  if (pflcBlockAddLeader){
    return (*pflcBlockAddLeader)(hBlock, szText, Xt, Yt, LandDist, Xa, Ya, Attach, Align);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimLin (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, double Angle, LPCWSTR szText)
{
  if (pflcBlockAddDimLin){
    return (*pflcBlockAddDimLin)(hBlock, X0, Y0, X1, Y1, Xt, Yt, Angle, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimHor (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Yt, LPCWSTR szText)
{
  if (pflcBlockAddDimHor){
    return (*pflcBlockAddDimHor)(hBlock, X0, Y0, X1, Y1, Yt, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimVer (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, LPCWSTR szText)
{
  if (pflcBlockAddDimVer){
    return (*pflcBlockAddDimVer)(hBlock, X0, Y0, X1, Y1, Xt, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimAli (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, LPCWSTR szText)
{
  if (pflcBlockAddDimAli){
    return (*pflcBlockAddDimAli)(hBlock, X0, Y0, X1, Y1, Xt, Yt, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimAli2 (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Dt, LPCWSTR szText)
{
  if (pflcBlockAddDimAli2){
    return (*pflcBlockAddDimAli2)(hBlock, X0, Y0, X1, Y1, Dt, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimOrd (HANDLE hBlock, double Xd, double Yd, double Xt, double Yt, BOOL bX, LPCWSTR szText)
{
  if (pflcBlockAddDimOrd){
    return (*pflcBlockAddDimOrd)(hBlock, Xd, Yd, Xt, Yt, bX, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimRad (HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText)
{
  if (pflcBlockAddDimRad){
    return (*pflcBlockAddDimRad)(hBlock, Xc, Yc, Xr, Yr, Xt, Yt, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimRad2 (HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText)
{
  if (pflcBlockAddDimRad2){
    return (*pflcBlockAddDimRad2)(hBlock, Xc, Yc, R, Angle, TextOff, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimDia (HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText)
{
  if (pflcBlockAddDimDia){
    return (*pflcBlockAddDimDia)(hBlock, Xc, Yc, Xr, Yr, Xt, Yt, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimDia2 (HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText)
{
  if (pflcBlockAddDimDia2){
    return (*pflcBlockAddDimDia2)(hBlock, Xc, Yc, R, Angle, TextOff, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimAng (HANDLE hBlock, double Xc, double Yc, double X1, double Y1, double X2, double Y2, double Xa, double Ya, double TextPos, LPCWSTR szText)
{
  if (pflcBlockAddDimAng){
    return (*pflcBlockAddDimAng)(hBlock, Xc, Yc, X1, Y1, X2, Y2, Xa, Ya, TextPos, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddDimAng2 (HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3, double X4, double Y4, double Xa, double Ya, double TextPos, LPCWSTR szText)
{
  if (pflcBlockAddDimAng2){
    return (*pflcBlockAddDimAng2)(hBlock, X1, Y1, X2, Y2, X3, Y3, X4, Y4, Xa, Ya, TextPos, szText);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddRPlan (HANDLE hBlock)
{
  if (pflcBlockAddRPlan){
    return (*pflcBlockAddRPlan)(hBlock);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddArrow (HANDLE hBlock, double X1, double Y1, double X2, double Y2)
{
  if (pflcBlockAddArrow){
    return (*pflcBlockAddArrow)(hBlock, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddSpiral (HANDLE hBlock, double Xc, double Yc, double R, double Turns, BOOL bDirCW, BOOL bClosed)
{
  if (pflcBlockAddSpiral){
    return (*pflcBlockAddSpiral)(hBlock, Xc, Yc, R, Turns, bDirCW, bClosed);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddCamview (HANDLE hBlock, double Lef, double Bot, double Width, double Height)
{
  if (pflcBlockAddCamview){
    return (*pflcBlockAddCamview)(hBlock, Lef, Bot, Width, Height);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockAddClone (HANDLE hBlock, HANDLE hEnt)
{
  if (pflcBlockAddClone){
    return (*pflcBlockAddClone)(hBlock, hEnt);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetFirstEnt (HANDLE hBlock)
{
  if (pflcBlockGetFirstEnt){
    return (*pflcBlockGetFirstEnt)(hBlock);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetNextEnt (HANDLE hBlock, HANDLE hEnt)
{
  if (pflcBlockGetNextEnt){
    return (*pflcBlockGetNextEnt)(hBlock, hEnt);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetLastEnt (HANDLE hBlock)
{
  if (pflcBlockGetLastEnt){
    return (*pflcBlockGetLastEnt)(hBlock);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetPrevEnt (HANDLE hBlock, HANDLE hEnt)
{
  if (pflcBlockGetPrevEnt){
    return (*pflcBlockGetPrevEnt)(hBlock, hEnt);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetEntByID (HANDLE hBlock, int Id)
{
  if (pflcBlockGetEntByID){
    return (*pflcBlockGetEntByID)(hBlock, Id);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetEntByIDH (HANDLE hBlock, LPCWSTR szId)
{
  if (pflcBlockGetEntByIDH){
    return (*pflcBlockGetEntByIDH)(hBlock, szId);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetEntByKey (HANDLE hBlock, int Key)
{
  if (pflcBlockGetEntByKey){
    return (*pflcBlockGetEntByKey)(hBlock, Key);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockUnselect (HANDLE hBlock)
{
  if (pflcBlockUnselect){
    return (*pflcBlockUnselect)(hBlock);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelectEnt (HANDLE hBlock, HANDLE hEntity, BOOL bSelect)
{
  if (pflcBlockSelectEnt){
    return (*pflcBlockSelectEnt)(hBlock, hEntity, bSelect);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelErase (HANDLE hBlock)
{
  if (pflcBlockSelErase){
    return (*pflcBlockSelErase)(hBlock);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelMove (HANDLE hBlock, double dX, double dY, BOOL bCopy, BOOL bNewSelect)
{
  if (pflcBlockSelMove){
    return (*pflcBlockSelMove)(hBlock, dX, dY, bCopy, bNewSelect);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelScale (HANDLE hBlock, double X0, double Y0, double Scal, BOOL bCopy, BOOL bNewSelect)
{
  if (pflcBlockSelScale){
    return (*pflcBlockSelScale)(hBlock, X0, Y0, Scal, bCopy, bNewSelect);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelRotate (HANDLE hBlock, double X0, double Y0, double Angle, BOOL bCopy, BOOL bNewSelect)
{
  if (pflcBlockSelRotate){
    return (*pflcBlockSelRotate)(hBlock, X0, Y0, Angle, bCopy, bNewSelect);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelMirror (HANDLE hBlock, double X1, double Y1, double X2, double Y2, BOOL bCopy, BOOL bNewSelect)
{
  if (pflcBlockSelMirror){
    return (*pflcBlockSelMirror)(hBlock, X1, Y1, X2, Y2, bCopy, bNewSelect);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelExplode (HANDLE hBlock)
{
  if (pflcBlockSelExplode){
    return (*pflcBlockSelExplode)(hBlock);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockSelJoin (HANDLE hBlock, double Delta)
{
  if (pflcBlockSelJoin){
    return (*pflcBlockSelJoin)(hBlock, Delta);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSelAlign (HANDLE hBlock, int Mode, double X, double Y)
{
  if (pflcBlockSelAlign){
    return (*pflcBlockSelAlign)(hBlock, Mode, X, Y);
  }
  return 0;
}


//--------------
//HANDLE LCAPI lcBlockSelBlock (HANDLE hBlock, LPCWSTR szName, double X, double Y, int Mode, BOOL bOverwrite)
//{
//  if (pflcBlockSelBlock){
//    return (*pflcBlockSelBlock)(hBlock, szName, X, Y, Mode, bOverwrite);
//  }
//  return 0;
//}


//--------------
HANDLE LCAPI lcBlockGetFirstSel (HANDLE hBlock)
{
  if (pflcBlockGetFirstSel){
    return (*pflcBlockGetFirstSel)(hBlock);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcBlockGetNextSel (HANDLE hBlock)
{
  if (pflcBlockGetNextSel){
    return (*pflcBlockGetNextSel)(hBlock);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockOrderByLayers (HANDLE hBlock, HWND hWnd)
{
  if (pflcBlockOrderByLayers){
    return (*pflcBlockOrderByLayers)(hBlock, hWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcBlockSortTSP (HANDLE hBlock, HANDLE hLayer, HWND hWnd)
{
  if (pflcBlockSortTSP){
    return (*pflcBlockSortTSP)(hBlock, hLayer, hWnd);
  }
  return 0;
}


//--------------
double LCAPI lcBlockGetJumpsLen (HANDLE hBlock, HANDLE hLayer, HWND hWnd)
{
  if (pflcBlockGetJumpsLen){
    return (*pflcBlockGetJumpsLen)(hBlock, hLayer, hWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcLayerClear (HANDLE hLayer, HANDLE hBlock)
{
  if (pflcLayerClear){
    return (*pflcLayerClear)(hLayer, hBlock);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntErase (HANDLE hEnt, BOOL bErase)
{
  if (pflcEntErase){
    return (*pflcEntErase)(hEnt, bErase);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntMove (HANDLE hEnt, double dX, double dY)
{
  if (pflcEntMove){
    return (*pflcEntMove)(hEnt, dX, dY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntScale (HANDLE hEnt, double X0, double Y0, double Scal)
{
  if (pflcEntScale){
    return (*pflcEntScale)(hEnt, X0, Y0, Scal);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntRotate (HANDLE hEnt, double X0, double Y0, double Angle)
{
  if (pflcEntRotate){
    return (*pflcEntRotate)(hEnt, X0, Y0, Angle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntMirror (HANDLE hEnt, double X1, double Y1, double X2, double Y2)
{
  if (pflcEntMirror){
    return (*pflcEntMirror)(hEnt, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntExplode (HANDLE hEnt, BOOL bSelect)
{
  if (pflcEntExplode){
    return (*pflcEntExplode)(hEnt, bSelect);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntOffset (HANDLE hEnt, double Dist)
{
  if (pflcEntOffset){
    return (*pflcEntOffset)(hEnt, Dist);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntToTop (HANDLE hEnt)
{
  if (pflcEntToTop){
    return (*pflcEntToTop)(hEnt);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntToBottom (HANDLE hEnt)
{
  if (pflcEntToBottom){
    return (*pflcEntToBottom)(hEnt);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntToAbove (HANDLE hEnt, HANDLE hEnt2)
{
  if (pflcEntToAbove){
    return (*pflcEntToAbove)(hEnt, hEnt2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntToUnder (HANDLE hEnt, HANDLE hEnt2)
{
  if (pflcEntToUnder){
    return (*pflcEntToUnder)(hEnt, hEnt2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntGetGrip (HANDLE hEnt, int iGrip, double* pX, double* pY)
{
  if (pflcEntGetGrip){
    return (*pflcEntGetGrip)(hEnt, iGrip, pX, pY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntPutGrip (HANDLE hEnt, int iGrip, double X, double Y)
{
  if (pflcEntPutGrip){
    return (*pflcEntPutGrip)(hEnt, iGrip, X, Y);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntUpdate (HANDLE hEnt)
{
  if (pflcEntUpdate){
    return (*pflcEntUpdate)(hEnt);
  }
  return 0;
}


//--------------
BOOL LCAPI lcEntCopyBase (HANDLE hEnt, HANDLE hEntFrom)
{
  if (pflcEntCopyBase){
    return (*pflcEntCopyBase)(hEnt, hEntFrom);
  }
  return 0;
}


//--------------
int LCAPI lcIntersection (HANDLE hEnt, HANDLE hEnt2)
{
  if (pflcIntersection){
    return (*pflcIntersection)(hEnt, hEnt2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcInterGetPoint (int iPoint, double* pX, double* pY)
{
  if (pflcInterGetPoint){
    return (*pflcInterGetPoint)(iPoint, pX, pY);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineAddVer (HANDLE hPline, HANDLE hVer, double X, double Y)
{
  if (pflcPlineAddVer){
    return (*pflcPlineAddVer)(hPline, hVer, X, Y);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineAddVer2 (HANDLE hPline, HANDLE hVer, double X, double Y, double Param, double W0, double W1)
{
  if (pflcPlineAddVer2){
    return (*pflcPlineAddVer2)(hPline, hVer, X, Y, Param, W0, W1);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineAddVerDir (HANDLE hPline, HANDLE hVer, double Ang, double Length)
{
  if (pflcPlineAddVerDir){
    return (*pflcPlineAddVerDir)(hPline, hVer, Ang, Length);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPlineEnd (HANDLE hPline)
{
  if (pflcPlineEnd){
    return (*pflcPlineEnd)(hPline);
  }
  return 0;
}


//--------------
//BOOL LCAPI lcPlineFromPtbuf (HANDLE hPline, HANDLE hPtbuf)
//{
//  if (pflcPlineFromPtbuf){
//    return (*pflcPlineFromPtbuf)(hPline, hPtbuf);
//  }
//  return 0;
//}


//--------------
//BOOL LCAPI lcPlineFromMpgon (HANDLE hPline, HANDLE hMpgon)
//{
//  if (pflcPlineFromMpgon){
//    return (*pflcPlineFromMpgon)(hPline, hMpgon);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lcPlineDeleteVer (HANDLE hPline, HANDLE hVer)
{
  if (pflcPlineDeleteVer){
    return (*pflcPlineDeleteVer)(hPline, hVer);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineGetFirstVer (HANDLE hPline)
{
  if (pflcPlineGetFirstVer){
    return (*pflcPlineGetFirstVer)(hPline);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineGetNextVer (HANDLE hPline, HANDLE hVer)
{
  if (pflcPlineGetNextVer){
    return (*pflcPlineGetNextVer)(hPline, hVer);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineGetLastVer (HANDLE hPline)
{
  if (pflcPlineGetLastVer){
    return (*pflcPlineGetLastVer)(hPline);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineGetPrevVer (HANDLE hPline, HANDLE hVer)
{
  if (pflcPlineGetPrevVer){
    return (*pflcPlineGetPrevVer)(hPline, hVer);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineGetVer (HANDLE hPline, int Index)
{
  if (pflcPlineGetVer){
    return (*pflcPlineGetVer)(hPline, Index);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineGetVerPt (HANDLE hPline, double X, double Y, double Delta)
{
  if (pflcPlineGetVerPt){
    return (*pflcPlineGetVerPt)(hPline, X, Y, Delta);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPlineGetSeg (HANDLE hPline, double X, double Y, double Delta)
{
  if (pflcPlineGetSeg){
    return (*pflcPlineGetSeg)(hPline, X, Y, Delta);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPlineReverse (HANDLE hPline)
{
  if (pflcPlineReverse){
    return (*pflcPlineReverse)(hPline);
  }
  return 0;
}


//--------------
int LCAPI lcPlineContainPoint (HANDLE hPline, double X, double Y)
{
  if (pflcPlineContainPoint){
    return (*pflcPlineContainPoint)(hPline, X, Y);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPlineGetRoundPrm (HANDLE hPline, HANDLE hVer, double* px0, double* py0, double* pBulge, double* px1, double* py1)
{
  if (pflcPlineGetRoundPrm){
    return (*pflcPlineGetRoundPrm)(hPline, hVer, px0, py0, pBulge, px1, py1);
  }
  return 0;
}


//--------------
BOOL LCAPI lcXlinePutDir (HANDLE hXline, double X, double Y)
{
  if (pflcXlinePutDir){
    return (*pflcXlinePutDir)(hXline, X, Y);
  }
  return 0;
}


//--------------
int LCAPI lcRectGetPolyline (HANDLE hRect, double* pX, double* pY, double* pBulge)
{
  if (pflcRectGetPolyline){
    return (*pflcRectGetPolyline)(hRect, pX, pY, pBulge);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImgRefGetPixel (HANDLE hImgRef, int iX, int iY, double* pX, double* pY, int* pColor)
{
  if (pflcImgRefGetPixel){
    return (*pflcImgRefGetPixel)(hImgRef, iX, iY, pX, pY, pColor);
  }
  return 0;
}


//--------------
//BOOL LCAPI lcImgRefResize (HANDLE hImgRef, int NewWidth, int NewHeight, int Method)
//{
//  if (pflcImgRefResize){
//    return (*pflcImgRefResize)(hImgRef, NewWidth, NewHeight, Method);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lcHatchSetPattern (HANDLE hHatch, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle)
{
  if (pflcHatchSetPattern){
    return (*pflcHatchSetPattern)(hHatch, szFileName, szPatName, Scal, Angle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHatchBoundStart (HANDLE hHatch)
{
  if (pflcHatchBoundStart){
    return (*pflcHatchBoundStart)(hHatch);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHatchBoundPoint (HANDLE hHatch, double X, double Y)
{
  if (pflcHatchBoundPoint){
    return (*pflcHatchBoundPoint)(hHatch, X, Y);
  }
  return 0;
}


//--------------
//BOOL LCAPI lcHatchBoundEntity (HANDLE hHatch, HANDLE hEnt)
//{
//  if (pflcHatchBoundEntity){
//    return (*pflcHatchBoundEntity)(hHatch, hEnt);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lcHatchBoundEndLoop (HANDLE hHatch)
{
  if (pflcHatchBoundEndLoop){
    return (*pflcHatchBoundEndLoop)(hHatch);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHatchBoundEnd (HANDLE hHatch)
{
  if (pflcHatchBoundEnd){
    return (*pflcHatchBoundEnd)(hHatch);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHatchPatStart (HANDLE hHatch)
{
  if (pflcHatchPatStart){
    return (*pflcHatchPatStart)(hHatch);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHatchPatLine (HANDLE hHatch, double Angle, double x0, double y0, double dx, double dy, int nDash, double L0, double L1, double L2, double L3, double L4, double L5, double L6, double L7)
{
  if (pflcHatchPatLine){
    return (*pflcHatchPatLine)(hHatch, Angle, x0, y0, dx, dy, nDash, L0, L1, L2, L3, L4, L5, L6, L7);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHatchPatEnd (HANDLE hHatch)
{
  if (pflcHatchPatEnd){
    return (*pflcHatchPatEnd)(hHatch);
  }
  return 0;
}


//--------------
int LCAPI lcHatchGetLoopSize (HANDLE hHatch, int iLoop)
{
  if (pflcHatchGetLoopSize){
    return (*pflcHatchGetLoopSize)(hHatch, iLoop);
  }
  return 0;
}


//--------------
BOOL LCAPI lcHatchGetPoint (HANDLE hHatch, int iPnt, double* pX, double* pY)
{
  if (pflcHatchGetPoint){
    return (*pflcHatchGetPoint)(hHatch, iPnt, pX, pY);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcRPlanAddVer (HANDLE hRPlan, double X, double Y)
{
  if (pflcRPlanAddVer){
    return (*pflcRPlanAddVer)(hRPlan, X, Y);
  }
  return 0;
}


//--------------
BOOL LCAPI lcRPlanSetCurve (HANDLE hVer, double Radius, double LenClot1, double LenClot2)
{
  if (pflcRPlanSetCurve){
    return (*pflcRPlanSetCurve)(hVer, Radius, LenClot1, LenClot2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcRPlanSetPos (HANDLE hVer, double X, double Y)
{
  if (pflcRPlanSetPos){
    return (*pflcRPlanSetPos)(hVer, X, Y);
  }
  return 0;
}


//--------------
BOOL LCAPI lcRPlanDeleteVer (HANDLE hRPlan, HANDLE hVer)
{
  if (pflcRPlanDeleteVer){
    return (*pflcRPlanDeleteVer)(hRPlan, hVer);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcRPlanGetFirstVer (HANDLE hRPlan)
{
  if (pflcRPlanGetFirstVer){
    return (*pflcRPlanGetFirstVer)(hRPlan);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcRPlanGetNextVer (HANDLE hRPlan, HANDLE hVer)
{
  if (pflcRPlanGetNextVer){
    return (*pflcRPlanGetNextVer)(hRPlan, hVer);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcRPlanGetLastVer (HANDLE hRPlan)
{
  if (pflcRPlanGetLastVer){
    return (*pflcRPlanGetLastVer)(hRPlan);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcRPlanGetPrevVer (HANDLE hRPlan, HANDLE hVer)
{
  if (pflcRPlanGetPrevVer){
    return (*pflcRPlanGetPrevVer)(hRPlan, hVer);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcRPlanGetVer (HANDLE hRPlan, int Index)
{
  if (pflcRPlanGetVer){
    return (*pflcRPlanGetVer)(hRPlan, Index);
  }
  return 0;
}


//--------------
BOOL LCAPI lcRPlanGetPoint (HANDLE hRPlan, double Dist, double* pX, double* pY, double* pAngle, int* pSide)
{
  if (pflcRPlanGetPoint){
    return (*pflcRPlanGetPoint)(hRPlan, Dist, pX, pY, pAngle, pSide);
  }
  return 0;
}


//--------------
BOOL LCAPI lcRPlanGetDist (HANDLE hRPlan, double X, double Y, double* pX2, double* pY2, double* pDist, double* pOffset)
{
  if (pflcRPlanGetDist){
    return (*pflcRPlanGetDist)(hRPlan, X, Y, pX2, pY2, pDist, pOffset);
  }
  return 0;
}


//--------------
//BOOL LCAPI lcVportSetView (HANDLE hVport, double Xcen, double Ycen, double Scal, double Angle)
//{
//  if (pflcVportSetView){
//    return (*pflcVportSetView)(hVport, Xcen, Ycen, Scal, Angle);
//  }
//  return 0;
//}


//--------------
//BOOL LCAPI lcVportLayerDlg (HANDLE hVport, HANDLE hLcWnd)
//{
//  if (pflcVportLayerDlg){
//    return (*pflcVportLayerDlg)(hVport, hLcWnd);
//  }
//  return 0;
//}


//--------------
//BOOL LCAPI lcVportLayerCmd (HANDLE hVport, int Cmd, HANDLE hLayer)
//{
//  if (pflcVportLayerCmd){
//    return (*pflcVportLayerCmd)(hVport, Cmd, hLayer);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lcColorIsRGB (LPCWSTR szColor)
{
  if (pflcColorIsRGB){
    return (*pflcColorIsRGB)(szColor);
  }
  return 0;
}


//--------------
int LCAPI lcColorGetRed (LPCWSTR szColor)
{
  if (pflcColorGetRed){
    return (*pflcColorGetRed)(szColor);
  }
  return 0;
}


//--------------
int LCAPI lcColorGetGreen (LPCWSTR szColor)
{
  if (pflcColorGetGreen){
    return (*pflcColorGetGreen)(szColor);
  }
  return 0;
}


//--------------
int LCAPI lcColorGetBlue (LPCWSTR szColor)
{
  if (pflcColorGetBlue){
    return (*pflcColorGetBlue)(szColor);
  }
  return 0;
}


//--------------
int LCAPI lcColorGetIndex (LPCWSTR szColor)
{
  if (pflcColorGetIndex){
    return (*pflcColorGetIndex)(szColor);
  }
  return 0;
}


//--------------
BOOL LCAPI lcColorToVal (LPCWSTR szColor, int* pbRGB, int* pIndex, int* pR, int* pG, int* pB)
{
  if (pflcColorToVal){
    return (*pflcColorToVal)(szColor, pbRGB, pIndex, pR, pG, pB);
  }
  return 0;
}


//--------------
BOOL LCAPI lcColorSetPalette (int Index, int R, int G, int B)
{
  if (pflcColorSetPalette){
    return (*pflcColorSetPalette)(Index, R, G, B);
  }
  return 0;
}


//--------------
BOOL LCAPI lcColorGetPalette (int Index, int* pR, int* pG, int* pB)
{
  if (pflcColorGetPalette){
    return (*pflcColorGetPalette)(Index, pR, pG, pB);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageSetPixelRGB (HANDLE hImage, int X, int Y, int Red, int Green, int Blue)
{
  if (pflcImageSetPixelRGB){
    return (*pflcImageSetPixelRGB)(hImage, X, Y, Red, Green, Blue);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageSetPixelI (HANDLE hImage, int X, int Y, int iColor)
{
  if (pflcImageSetPixelI){
    return (*pflcImageSetPixelI)(hImage, X, Y, iColor);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageGetPixelRGB (HANDLE hImage, int X, int Y, int* pRed, int* pGreen, int* pBlue)
{
  if (pflcImageGetPixelRGB){
    return (*pflcImageGetPixelRGB)(hImage, X, Y, pRed, pGreen, pBlue);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageGetPixelI (HANDLE hImage, int X, int Y, int* piColor)
{
  if (pflcImageGetPixelI){
    return (*pflcImageGetPixelI)(hImage, X, Y, piColor);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageSetPalColor (HANDLE hImage, int iColor, int Red, int Green, int Blue)
{
  if (pflcImageSetPalColor){
    return (*pflcImageSetPalColor)(hImage, iColor, Red, Green, Blue);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageGetPalColor (HANDLE hImage, int iColor, int* pRed, int* pGreen, int* pBlue)
{
  if (pflcImageGetPalColor){
    return (*pflcImageGetPalColor)(hImage, iColor, pRed, pGreen, pBlue);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageLoad (HANDLE hImage, LPCWSTR szFilename, HANDLE hWnd)
{
  if (pflcImageLoad){
    return (*pflcImageLoad)(hImage, szFilename, hWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageLoadDIB (HANDLE hImage, HANDLE hDib2)
{
  if (pflcImageLoadDIB){
    return (*pflcImageLoadDIB)(hImage, hDib2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcImageCopyQuad (HANDLE hImage, HANDLE hImageSrc, UINT W, UINT H, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
{
  if (pflcImageCopyQuad){
    return (*pflcImageCopyQuad)(hImage, hImageSrc, W, H, x0, y0, x1, y1, x2, y2, x3, y3);
  }
  return 0;
}


//--------------
BOOL LCAPI lcFilletSetLines (double L1x0, double L1y0, double L1x1, double L1y1, double L2x0, double L2y0, double L2x1, double L2y1)
{
  if (pflcFilletSetLines){
    return (*pflcFilletSetLines)(L1x0, L1y0, L1x1, L1y1, L2x0, L2y0, L2x1, L2y1);
  }
  return 0;
}


//--------------
BOOL LCAPI lcFillet (double Rad, double Bis, double Tang)
{
  if (pflcFillet){
    return (*pflcFillet)(Rad, Bis, Tang);
  }
  return 0;
}


//--------------
BOOL LCAPI lcFilletGetPoint (int iPnt, double* pX, double* pY)
{
  if (pflcFilletGetPoint){
    return (*pflcFilletGetPoint)(iPnt, pX, pY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldSet (HANDLE hDrw, double Lef, double Bot, double Width, double Height)
{
  if (pflcWFieldSet){
    return (*pflcWFieldSet)(hDrw, Lef, Bot, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldClear (HANDLE hDrw)
{
  if (pflcWFieldClear){
    return (*pflcWFieldClear)(hDrw);
  }
  return 0;
}


//--------------
int LCAPI lcWFieldDivide (HANDLE hDrw, int NumX, int NumY, BOOL bClearExist)
{
  if (pflcWFieldDivide){
    return (*pflcWFieldDivide)(hDrw, NumX, NumY, bClearExist);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldAddCR (HANDLE hDrw, int ID, double Lef, double Bot, double Width, double Height)
{
  if (pflcWFieldAddCR){
    return (*pflcWFieldAddCR)(hDrw, ID, Lef, Bot, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldSetCR (HANDLE hDrw, int ID, double Lef, double Bot, double Width, double Height)
{
  if (pflcWFieldSetCR){
    return (*pflcWFieldSetCR)(hDrw, ID, Lef, Bot, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldDeleteCR (HANDLE hDrw, int ID)
{
  if (pflcWFieldDeleteCR){
    return (*pflcWFieldDeleteCR)(hDrw, ID);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldActiveCR (HANDLE hDrw, int ID)
{
  if (pflcWFieldActiveCR){
    return (*pflcWFieldActiveCR)(hDrw, ID);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldSave (HANDLE hDrw, LPCWSTR szFileName)
{
  if (pflcWFieldSave){
    return (*pflcWFieldSave)(hDrw, szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWFieldLoad (HANDLE hDrw, LPCWSTR szFileName)
{
  if (pflcWFieldLoad){
    return (*pflcWFieldLoad)(hDrw, szFileName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcWFieldFirstCR (HANDLE hDrw)
{
  if (pflcWFieldFirstCR){
    return (*pflcWFieldFirstCR)(hDrw);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcWFieldNextCR (HANDLE hDrw, HANDLE hEnt)
{
  if (pflcWFieldNextCR){
    return (*pflcWFieldNextCR)(hDrw, hEnt);
  }
  return 0;
}


//--------------
int LCAPI lcExpEntity (HANDLE hEnt, int Flags, BOOL bUnrotate)
{
  if (pflcExpEntity){
    return (*pflcExpEntity)(hEnt, Flags, bUnrotate);
  }
  return 0;
}


//--------------
int LCAPI lcExpGetPline (double Delta)
{
  if (pflcExpGetPline){
    return (*pflcExpGetPline)(Delta);
  }
  return 0;
}


//--------------
BOOL LCAPI lcExpGetVertex (double* pX, double* pY)
{
  if (pflcExpGetVertex){
    return (*pflcExpGetVertex)(pX, pY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGbrLoad (HANDLE hLcWnd, LPCWSTR szFileName0)
{
  if (pflcGbrLoad){
    return (*pflcGbrLoad)(hLcWnd, szFileName0);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGbrClose (HANDLE hLcWnd)
{
  if (pflcGbrClose){
    return (*pflcGbrClose)(hLcWnd);
  }
  return 0;
}


//--------------
LPCWSTR LCAPI lcPlugGetOption (LPCWSTR szFileName, LPCWSTR szKey)
{
  if (pflcPlugGetOption){
    return (*pflcPlugGetOption)(szFileName, szKey);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPlugGetOption2 (LPCWSTR szFileName, LPCWSTR szKey)
{
  if (pflcPlugGetOption2){
    return (*pflcPlugGetOption2)(szFileName, szKey);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPlugSetOption (LPCWSTR szFileName, LPCWSTR szKey, LPCWSTR szValue, BOOL bSave)
{
  if (pflcPlugSetOption){
    return (*pflcPlugSetOption)(szFileName, szKey, szValue, bSave);
  }
  return 0;
}


//--------------
//BOOL LCAPI lcPrintSetup (HANDLE hWnd)
//{
//  if (pflcPrintSetup){
//    return (*pflcPrintSetup)(hWnd);
//  }
//  return 0;
//}


//--------------
//BOOL LCAPI lcPrintLayout (HANDLE hBlock)
//{
//  if (pflcPrintLayout){
//    return (*pflcPrintLayout)(hBlock);
//  }
//  return 0;
//}


//--------------
//BOOL LCAPI lcPrintBlock (HANDLE hBlock, double X, double Y, double W, double H, double Scale, double PapLef, double PapTop)
//{
//  if (pflcPrintBlock){
//    return (*pflcPrintBlock)(hBlock, X, Y, W, H, Scale, PapLef, PapTop);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lc2_Initialize ()
{
  if (pflc2_Initialize){
    return (*pflc2_Initialize)();
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_Uninitialize ()
{
  if (pflc2_Uninitialize){
    return (*pflc2_Uninitialize)();
  }
  return 0;
}


//--------------
HANDLE LCAPI lc2_Create (HWND hWndParent, int Flags)
{
  if (pflc2_Create){
    return (*pflc2_Create)(hWndParent, Flags);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_Delete (HANDLE hFrame)
{
  if (pflc2_Delete){
    return (*pflc2_Delete)(hFrame);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_OnClose (HANDLE hFrame)
{
  if (pflc2_OnClose){
    return (*pflc2_OnClose)(hFrame);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_Position (HANDLE hFrame, int Left, int Top, int Width, int Height)
{
  if (pflc2_Position){
    return (*pflc2_Position)(hFrame, Left, Top, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_Command (HANDLE hFrame, int Command, int CmdParam)
{
  if (pflc2_Command){
    return (*pflc2_Command)(hFrame, Command, CmdParam);
  }
  return 0;
}


//--------------
HANDLE LCAPI lc2_GetWnd (HANDLE hFrame)
{
  if (pflc2_GetWnd){
    return (*pflc2_GetWnd)(hFrame);
  }
  return 0;
}


//--------------
HANDLE LCAPI lc2_GetDrw (HANDLE hFrame)
{
  if (pflc2_GetDrw){
    return (*pflc2_GetDrw)(hFrame);
  }
  return 0;
}


//--------------
HANDLE LCAPI lc2_GetBlock (HANDLE hFrame)
{
  if (pflc2_GetBlock){
    return (*pflc2_GetBlock)(hFrame);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_FileLoad (HANDLE hFrame, LPCWSTR szFileName)
{
  if (pflc2_FileLoad){
    return (*pflc2_FileLoad)(hFrame, szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_FileSave (HANDLE hFrame, LPCWSTR szFileName, BOOL bBak)
{
  if (pflc2_FileSave){
    return (*pflc2_FileSave)(hFrame, szFileName, bBak);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_WFieldSave (HANDLE hFrame, LPCWSTR szFileName)
{
  if (pflc2_WFieldSave){
    return (*pflc2_WFieldSave)(hFrame, szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_WFieldLoad (HANDLE hFrame, LPCWSTR szFileName)
{
  if (pflc2_WFieldLoad){
    return (*pflc2_WFieldLoad)(hFrame, szFileName);
  }
  return 0;
}


//--------------
int LCAPI lc2_ExpStart (HANDLE hFrame, int Mode)
{
  if (pflc2_ExpStart){
    return (*pflc2_ExpStart)(hFrame, Mode);
  }
  return 0;
}


//--------------
int LCAPI lc2_ExpGetPline (HANDLE hFrame)
{
  if (pflc2_ExpGetPline){
    return (*pflc2_ExpGetPline)(hFrame);
  }
  return 0;
}


//--------------
HANDLE LCAPI lc2_ExpGetEntity (HANDLE hFrame)
{
  if (pflc2_ExpGetEntity){
    return (*pflc2_ExpGetEntity)(hFrame);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_ExpGetVertex (HANDLE hFrame, double* pX, double* pY)
{
  if (pflc2_ExpGetVertex){
    return (*pflc2_ExpGetVertex)(hFrame, pX, pY);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_ExpGetPoint (HANDLE hFrame)
{
  if (pflc2_ExpGetPoint){
    return (*pflc2_ExpGetPoint)(hFrame);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_CbCopy (HANDLE hFrame, double Lef, double Bot, double W, double H)
{
  if (pflc2_CbCopy){
    return (*pflc2_CbCopy)(hFrame, Lef, Bot, W, H);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_CbCopy2 (HANDLE hFrame, int idClipRect, BOOL bUnrotate)
{
  if (pflc2_CbCopy2){
    return (*pflc2_CbCopy2)(hFrame, idClipRect, bUnrotate);
  }
  return 0;
}


//--------------
BOOL LCAPI lc2_CbPaste (HANDLE hFrame, double Lef, double Bot)
{
  if (pflc2_CbPaste){
    return (*pflc2_CbPaste)(hFrame, Lef, Bot);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_EnableFileExt (LPCWSTR szFileExt)
{
  if (pflcMru_EnableFileExt){
    return (*pflcMru_EnableFileExt)(szFileExt);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_Load (LPCWSTR szFileName)
{
  if (pflcMru_Load){
    return (*pflcMru_Load)(szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_Save ()
{
  if (pflcMru_Save){
    return (*pflcMru_Save)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_AddFile (LPCWSTR szFileName, BOOL bFileHasView)
{
  if (pflcMru_AddFile){
    return (*pflcMru_AddFile)(szFileName, bFileHasView);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_SetImage (LPCWSTR szFileName, BYTE* pImgBuf, int ImgSize)
{
  if (pflcMru_SetImage){
    return (*pflcMru_SetImage)(szFileName, pImgBuf, ImgSize);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_HasImage (LPCWSTR szFileName)
{
  if (pflcMru_HasImage){
    return (*pflcMru_HasImage)(szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_SetViewRect (LPCWSTR szFileName, double Xmin, double Ymin, double Xmax, double Ymax)
{
  if (pflcMru_SetViewRect){
    return (*pflcMru_SetViewRect)(szFileName, Xmin, Ymin, Xmax, Ymax);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_GetViewRect (LPCWSTR szFileName, double* pXmin, double* pYmin, double* pXmax, double* pYmax)
{
  if (pflcMru_GetViewRect){
    return (*pflcMru_GetViewRect)(szFileName, pXmin, pYmin, pXmax, pYmax);
  }
  return 0;
}


//--------------
BOOL LCAPI lcMru_Dialog (HWND hWnd, HANDLE hIcon, WCHAR* szFileName)
{
  if (pflcMru_Dialog){
    return (*pflcMru_Dialog)(hWnd, hIcon, szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndTabClear (HANDLE hLcWnd)
{
  if (pflcWndTabClear){
    return (*pflcWndTabClear)(hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndTabAdd (HANDLE hLcWnd, int TabID, LPCWSTR szLabel, LPCWSTR szTipText, HANDLE hObject)
{
  if (pflcWndTabAdd){
    return (*pflcWndTabAdd)(hLcWnd, TabID, szLabel, szTipText, hObject);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndTabSelect (HANDLE hLcWnd, int TabID)
{
  if (pflcWndTabSelect){
    return (*pflcWndTabSelect)(hLcWnd, TabID);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndPaperEnable (HANDLE hLcWnd, BOOL bEnable)
{
  if (pflcWndPaperEnable){
    return (*pflcWndPaperEnable)(hLcWnd, bEnable);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndPaperSetSize (HANDLE hLcWnd, int Size, int Orient)
{
  if (pflcWndPaperSetSize){
    return (*pflcWndPaperSetSize)(hLcWnd, Size, Orient);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndPaperSetSize2 (HANDLE hLcWnd, double Width, double Height)
{
  if (pflcWndPaperSetSize2){
    return (*pflcWndPaperSetSize2)(hLcWnd, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcWndPaperSetPos (HANDLE hLcWnd, double Left, double Bottom)
{
  if (pflcWndPaperSetPos){
    return (*pflcWndPaperSetPos)(hLcWnd, Left, Bottom);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGripClear (HANDLE hLcWnd)
{
  if (pflcGripClear){
    return (*pflcGripClear)(hLcWnd);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGripAdd (HANDLE hLcWnd, HANDLE hObj, int iGrip, int Typ, double X, double Y, double Ang, double X0, double Y0)
{
  if (pflcGripAdd){
    return (*pflcGripAdd)(hLcWnd, hObj, iGrip, Typ, X, Y, Ang, X0, Y0);
  }
  return 0;
}


//--------------
BOOL LCAPI lcGripSet (HANDLE hLcWnd, HANDLE hObj, int iGrip, double X, double Y, double Ang, double X0, double Y0)
{
  if (pflcGripSet){
    return (*pflcGripSet)(hLcWnd, hObj, iGrip, X, Y, Ang, X0, Y0);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_PenCreate (HANDLE hLcWnd, int Id, COLORREF Color, double Width, int PenStyle)
{
  if (pflcPaint_PenCreate){
    return (*pflcPaint_PenCreate)(hLcWnd, Id, Color, Width, PenStyle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PenSelect (HANDLE hLcWnd, HANDLE hPen)
{
  if (pflcPaint_PenSelect){
    return (*pflcPaint_PenSelect)(hLcWnd, hPen);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PenSelectID (HANDLE hLcWnd, int IdPen)
{
  if (pflcPaint_PenSelectID){
    return (*pflcPaint_PenSelectID)(hLcWnd, IdPen);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_BrushCreate (HANDLE hLcWnd, int Id, COLORREF Color, int Pattern, int Alpha)
{
  if (pflcPaint_BrushCreate){
    return (*pflcPaint_BrushCreate)(hLcWnd, Id, Color, Pattern, Alpha);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_BrushSelect (HANDLE hLcWnd, HANDLE hBrush)
{
  if (pflcPaint_BrushSelect){
    return (*pflcPaint_BrushSelect)(hLcWnd, hBrush);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_BrushSelectID (HANDLE hLcWnd, int IdBrush)
{
  if (pflcPaint_BrushSelectID){
    return (*pflcPaint_BrushSelectID)(hLcWnd, IdBrush);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawPtbuf (HANDLE hLcWnd, HANDLE hPtbuf, BOOL bClosed)
{
  if (pflcPaint_DrawPtbuf){
    return (*pflcPaint_DrawPtbuf)(hLcWnd, hPtbuf, bClosed);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawMpgon (HANDLE hLcWnd, HANDLE hMpgon, BOOL bFill, BOOL bBorder)
{
  if (pflcPaint_DrawMpgon){
    return (*pflcPaint_DrawMpgon)(hLcWnd, hMpgon, bFill, bBorder);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawImage (HANDLE hLcWnd, HANDLE hImage, double X, double Y, double PixelSize, int Transp, int TVal, HANDLE hPtbuf)
{
  if (pflcPaint_DrawImage){
    return (*pflcPaint_DrawImage)(hLcWnd, hImage, X, Y, PixelSize, Transp, TVal, hPtbuf);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawImage2 (HANDLE hLcWnd, HANDLE hImage, double X, double Y, double W, double H, int Transp, int TVal, HANDLE hPtbuf)
{
  if (pflcPaint_DrawImage2){
    return (*pflcPaint_DrawImage2)(hLcWnd, hImage, X, Y, W, H, Transp, TVal, hPtbuf);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawText (HANDLE hLcWnd, double X, double Y, LPCWSTR szText)
{
  if (pflcPaint_DrawText){
    return (*pflcPaint_DrawText)(hLcWnd, X, Y, szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawText2 (HANDLE hLcWnd, double X1, double Y1, double X2, double Y2, int Align, LPCWSTR szText)
{
  if (pflcPaint_DrawText2){
    return (*pflcPaint_DrawText2)(hLcWnd, X1, Y1, X2, Y2, Align, szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawTextBC (HANDLE hLcWnd, HANDLE hMpgon, double Gap, double Height, int Align, LPCWSTR szText)
{
  if (pflcPaint_DrawTextBC){
    return (*pflcPaint_DrawTextBC)(hLcWnd, hMpgon, Gap, Height, Align, szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawArcText (HANDLE hLcWnd, LPCWSTR szText, double X, double Y, double Rad, double Ang0, BOOL bCW, double H, double WScale, int Align)
{
  if (pflcPaint_DrawArcText){
    return (*pflcPaint_DrawArcText)(hLcWnd, szText, X, Y, Rad, Ang0, bCW, H, WScale, Align);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawHatch (HANDLE hLcWnd, HANDLE hHatch)
{
  if (pflcPaint_DrawHatch){
    return (*pflcPaint_DrawHatch)(hLcWnd, hHatch);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawPoint (HANDLE hLcWnd, double X, double Y, int PtMode, double PtSize)
{
  if (pflcPaint_DrawPoint){
    return (*pflcPaint_DrawPoint)(hLcWnd, X, Y, PtMode, PtSize);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawLine (HANDLE hLcWnd, double X1, double Y1, double X2, double Y2)
{
  if (pflcPaint_DrawLine){
    return (*pflcPaint_DrawLine)(hLcWnd, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawXline (HANDLE hLcWnd, double X, double Y, double Angle, BOOL bRay)
{
  if (pflcPaint_DrawXline){
    return (*pflcPaint_DrawXline)(hLcWnd, X, Y, Angle, bRay);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawRect (HANDLE hLcWnd, double Xc, double Yc, double Width, double Height)
{
  if (pflcPaint_DrawRect){
    return (*pflcPaint_DrawRect)(hLcWnd, Xc, Yc, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawRect2 (HANDLE hLcWnd, double X1, double Y1, double X2, double Y2)
{
  if (pflcPaint_DrawRect2){
    return (*pflcPaint_DrawRect2)(hLcWnd, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
//BOOL LCAPI lcPaint_DrawPickBox (HANDLE hLcWnd)
//{
//  if (pflcPaint_DrawPickBox){
//    return (*pflcPaint_DrawPickBox)(hLcWnd);
//  }
//  return 0;
//}


//--------------
BOOL LCAPI lcPaint_DrawTIN (HANDLE hLcWnd, HANDLE hTIN)
{
  if (pflcPaint_DrawTIN){
    return (*pflcPaint_DrawTIN)(hLcWnd, hTIN);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawGrid (HANDLE hLcWnd, HANDLE hGrid, BOOL bDest, COLORREF ColLine, COLORREF ColNode)
{
  if (pflcPaint_DrawGrid){
    return (*pflcPaint_DrawGrid)(hLcWnd, hGrid, bDest, ColLine, ColNode);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DrawCPrompt (HANDLE hLcWnd, int X, int Y, int Align, LPCWSTR szText)
{
  if (pflcPaint_DrawCPrompt){
    return (*pflcPaint_DrawCPrompt)(hLcWnd, X, Y, Align, szText);
  }
  return 0;
}


//--------------
//void LCAPI lcPaint_SetPixel (HANDLE hDC, int X, int Y, COLORREF Color)
//{
//  if (pflcPaint_SetPixel){
//    (*pflcPaint_SetPixel)(hDC, X, Y, Color);
//  }
//}


//--------------
HANDLE LCAPI lcPaint_CreatePtbuf ()
{
  if (pflcPaint_CreatePtbuf){
    return (*pflcPaint_CreatePtbuf)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DeletePtbuf (HANDLE hPtbuf)
{
  if (pflcPaint_DeletePtbuf){
    return (*pflcPaint_DeletePtbuf)(hPtbuf);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufClear (HANDLE hPtbuf)
{
  if (pflcPaint_PtbufClear){
    return (*pflcPaint_PtbufClear)(hPtbuf);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddPoint (HANDLE hPtbuf, double X, double Y, double Prm1, double Prm2, int IntPrm)
{
  if (pflcPaint_PtbufAddPoint){
    return (*pflcPaint_PtbufAddPoint)(hPtbuf, X, Y, Prm1, Prm2, IntPrm);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddPoint2 (HANDLE hPtbuf, double X, double Y)
{
  if (pflcPaint_PtbufAddPoint2){
    return (*pflcPaint_PtbufAddPoint2)(hPtbuf, X, Y);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddPointP (HANDLE hPtbuf, double Angle, double Dist)
{
  if (pflcPaint_PtbufAddPointP){
    return (*pflcPaint_PtbufAddPointP)(hPtbuf, Angle, Dist);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddLine (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2)
{
  if (pflcPaint_PtbufAddLine){
    return (*pflcPaint_PtbufAddLine)(hPtbuf, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddLineP (HANDLE hPtbuf, double X, double Y, double Angle, double Dist)
{
  if (pflcPaint_PtbufAddLineP){
    return (*pflcPaint_PtbufAddLineP)(hPtbuf, X, Y, Angle, Dist);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddCircle (HANDLE hPtbuf, double Xc, double Yc, double R, int Resol)
{
  if (pflcPaint_PtbufAddCircle){
    return (*pflcPaint_PtbufAddCircle)(hPtbuf, Xc, Yc, R, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddCircle2 (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, int Resol)
{
  if (pflcPaint_PtbufAddCircle2){
    return (*pflcPaint_PtbufAddCircle2)(hPtbuf, X1, Y1, X2, Y2, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddCircle3 (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double X3, double Y3, BOOL bInside, int Resol)
{
  if (pflcPaint_PtbufAddCircle3){
    return (*pflcPaint_PtbufAddCircle3)(hPtbuf, X1, Y1, X2, Y2, X3, Y3, bInside, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArc (HANDLE hPtbuf, double Xc, double Yc, double R, double StartAngle, double ArcAngle, int Resol)
{
  if (pflcPaint_PtbufAddArc){
    return (*pflcPaint_PtbufAddArc)(hPtbuf, Xc, Yc, R, StartAngle, ArcAngle, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArc3p (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double X3, double Y3, int Resol)
{
  if (pflcPaint_PtbufAddArc3p){
    return (*pflcPaint_PtbufAddArc3p)(hPtbuf, X1, Y1, X2, Y2, X3, Y3, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcSDE (HANDLE hPtbuf, double Xs, double Ys, double DirAng, double Xe, double Ye, int Resol)
{
  if (pflcPaint_PtbufAddArcSDE){
    return (*pflcPaint_PtbufAddArcSDE)(hPtbuf, Xs, Ys, DirAng, Xe, Ye, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcSDAR (HANDLE hPtbuf, double Xs, double Ys, double DirAng, double AngArc, double R, int Resol)
{
  if (pflcPaint_PtbufAddArcSDAR){
    return (*pflcPaint_PtbufAddArcSDAR)(hPtbuf, Xs, Ys, DirAng, AngArc, R, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcSER (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double Radius, BOOL bClockwise, int Resol)
{
  if (pflcPaint_PtbufAddArcSER){
    return (*pflcPaint_PtbufAddArcSER)(hPtbuf, Xs, Ys, Xe, Ye, Radius, bClockwise, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcSEL (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double ArcLen, BOOL bClockwise, int Resol)
{
  if (pflcPaint_PtbufAddArcSEL){
    return (*pflcPaint_PtbufAddArcSEL)(hPtbuf, Xs, Ys, Xe, Ye, ArcLen, bClockwise, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcSEA (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double AngArc, int Resol)
{
  if (pflcPaint_PtbufAddArcSEA){
    return (*pflcPaint_PtbufAddArcSEA)(hPtbuf, Xs, Ys, Xe, Ye, AngArc, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcSEB (HANDLE hPtbuf, double Xs, double Ys, double Xe, double Ye, double Bulge, int Resol)
{
  if (pflcPaint_PtbufAddArcSEB){
    return (*pflcPaint_PtbufAddArcSEB)(hPtbuf, Xs, Ys, Xe, Ye, Bulge, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcCSE (HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double Xe, double Ye, BOOL bClockwise, int Resol)
{
  if (pflcPaint_PtbufAddArcCSE){
    return (*pflcPaint_PtbufAddArcCSE)(hPtbuf, Xc, Yc, Xs, Ys, Xe, Ye, bClockwise, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcCSA (HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double AngArc, int Resol)
{
  if (pflcPaint_PtbufAddArcCSA){
    return (*pflcPaint_PtbufAddArcCSA)(hPtbuf, Xc, Yc, Xs, Ys, AngArc, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcCSL (HANDLE hPtbuf, double Xc, double Yc, double Xs, double Ys, double ChordLen, BOOL bClockwise, int Resol)
{
  if (pflcPaint_PtbufAddArcCSL){
    return (*pflcPaint_PtbufAddArcCSL)(hPtbuf, Xc, Yc, Xs, Ys, ChordLen, bClockwise, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddArcCRAA (HANDLE hPtbuf, double Xc, double Yc, double R, double AngStart, double AngEnd, BOOL bClockwise, int Resol)
{
  if (pflcPaint_PtbufAddArcCRAA){
    return (*pflcPaint_PtbufAddArcCRAA)(hPtbuf, Xc, Yc, R, AngStart, AngEnd, bClockwise, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddEllipse (HANDLE hPtbuf, double Xc, double Yc, double Rmaj, double Rmin, double RotAng, double StartAng, double ArcAng, int Resol)
{
  if (pflcPaint_PtbufAddEllipse){
    return (*pflcPaint_PtbufAddEllipse)(hPtbuf, Xc, Yc, Rmaj, Rmin, RotAng, StartAng, ArcAng, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddEllipse2 (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, int Resol)
{
  if (pflcPaint_PtbufAddEllipse2){
    return (*pflcPaint_PtbufAddEllipse2)(hPtbuf, X1, Y1, X2, Y2, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddRect (HANDLE hPtbuf, double Xc, double Yc, double W, double H, double Angle, double R, int Resol)
{
  if (pflcPaint_PtbufAddRect){
    return (*pflcPaint_PtbufAddRect)(hPtbuf, Xc, Yc, W, H, Angle, R, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddRect2 (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double R, int Resol)
{
  if (pflcPaint_PtbufAddRect2){
    return (*pflcPaint_PtbufAddRect2)(hPtbuf, X1, Y1, X2, Y2, R, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddRect3 (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double W, int Align, double R, int Resol)
{
  if (pflcPaint_PtbufAddRect3){
    return (*pflcPaint_PtbufAddRect3)(hPtbuf, X1, Y1, X2, Y2, W, Align, R, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddWline (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2, double W, int Align, BOOL bArc, int Resol)
{
  if (pflcPaint_PtbufAddWline){
    return (*pflcPaint_PtbufAddWline)(hPtbuf, X1, Y1, X2, Y2, W, Align, bArc, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufAddPtbuf (HANDLE hPtbuf, HANDLE hPtbuf2)
{
  if (pflcPaint_PtbufAddPtbuf){
    return (*pflcPaint_PtbufAddPtbuf)(hPtbuf, hPtbuf2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufGetPoint (HANDLE hPtbuf, int Mode, double* pX, double* pY)
{
  if (pflcPaint_PtbufGetPoint){
    return (*pflcPaint_PtbufGetPoint)(hPtbuf, Mode, pX, pY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufGetPoint2 (HANDLE hPtbuf, int Mode, double* pX, double* pY, double* pPrm1, double* pPrm2, int* pIntPrm)
{
  if (pflcPaint_PtbufGetPoint2){
    return (*pflcPaint_PtbufGetPoint2)(hPtbuf, Mode, pX, pY, pPrm1, pPrm2, pIntPrm);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufInterpolate (HANDLE hPtbuf, BOOL bClosed, HANDLE hPtbufDest, int Mode, int Resol)
{
  if (pflcPaint_PtbufInterpolate){
    return (*pflcPaint_PtbufInterpolate)(hPtbuf, bClosed, hPtbufDest, Mode, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufMove (HANDLE hPtbuf, double dx, double dy)
{
  if (pflcPaint_PtbufMove){
    return (*pflcPaint_PtbufMove)(hPtbuf, dx, dy);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufRotate (HANDLE hPtbuf, double Xc, double Yc, double Angle)
{
  if (pflcPaint_PtbufRotate){
    return (*pflcPaint_PtbufRotate)(hPtbuf, Xc, Yc, Angle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufScale (HANDLE hPtbuf, double Xc, double Yc, double ScaleX, double ScaleY)
{
  if (pflcPaint_PtbufScale){
    return (*pflcPaint_PtbufScale)(hPtbuf, Xc, Yc, ScaleX, ScaleY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufMirror (HANDLE hPtbuf, double X1, double Y1, double X2, double Y2)
{
  if (pflcPaint_PtbufMirror){
    return (*pflcPaint_PtbufMirror)(hPtbuf, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_PtbufCopy (HANDLE hPtbuf, HANDLE hPtbufDest)
{
  if (pflcPaint_PtbufCopy){
    return (*pflcPaint_PtbufCopy)(hPtbuf, hPtbufDest);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_CreateMpgon ()
{
  if (pflcPaint_CreateMpgon){
    return (*pflcPaint_CreateMpgon)();
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_DeleteMpgon (HANDLE hMpgon)
{
  if (pflcPaint_DeleteMpgon){
    return (*pflcPaint_DeleteMpgon)(hMpgon);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonClear (HANDLE hMpgon)
{
  if (pflcPaint_MpgonClear){
    return (*pflcPaint_MpgonClear)(hMpgon);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonAddPgon (HANDLE hMpgon, HANDLE hPtbuf)
{
  if (pflcPaint_MpgonAddPgon){
    return (*pflcPaint_MpgonAddPgon)(hMpgon, hPtbuf);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonAddText (HANDLE hMpgon, HANDLE hFont, double X, double Y, LPCWSTR szText, int Resol)
{
  if (pflcPaint_MpgonAddText){
    return (*pflcPaint_MpgonAddText)(hMpgon, hFont, X, Y, szText, Resol);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonAddBarcode (HANDLE hMpgon, int BarType, double Xc, double Yc, double Width, double Height, LPCWSTR szText)
{
  if (pflcPaint_MpgonAddBarcode){
    return (*pflcPaint_MpgonAddBarcode)(hMpgon, BarType, Xc, Yc, Width, Height, szText);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonMove (HANDLE hMpgon, double dx, double dy)
{
  if (pflcPaint_MpgonMove){
    return (*pflcPaint_MpgonMove)(hMpgon, dx, dy);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonRotate (HANDLE hMpgon, double Xc, double Yc, double Angle)
{
  if (pflcPaint_MpgonRotate){
    return (*pflcPaint_MpgonRotate)(hMpgon, Xc, Yc, Angle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonScale (HANDLE hMpgon, double Xc, double Yc, double ScaleX, double ScaleY)
{
  if (pflcPaint_MpgonScale){
    return (*pflcPaint_MpgonScale)(hMpgon, Xc, Yc, ScaleX, ScaleY);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonMirror (HANDLE hMpgon, double X1, double Y1, double X2, double Y2)
{
  if (pflcPaint_MpgonMirror){
    return (*pflcPaint_MpgonMirror)(hMpgon, X1, Y1, X2, Y2);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_MpgonCopy (HANDLE hMpgon, HANDLE hMpgonDest)
{
  if (pflcPaint_MpgonCopy){
    return (*pflcPaint_MpgonCopy)(hMpgon, hMpgonDest);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_HatchGen (HANDLE hMpgon, HANDLE hHatch, double Dist, double Angle, double W, double Beamc1, double Beamc2, double StartOff, double EndOff)
{
  if (pflcPaint_HatchGen){
    return (*pflcPaint_HatchGen)(hMpgon, hHatch, Dist, Angle, W, Beamc1, Beamc2, StartOff, EndOff);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_ImageAdd (int Id)
{
  if (pflcPaint_ImageAdd){
    return (*pflcPaint_ImageAdd)(Id);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageDelete (HANDLE hImage)
{
  if (pflcPaint_ImageDelete){
    return (*pflcPaint_ImageDelete)(hImage);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_ImageGetFirst ()
{
  if (pflcPaint_ImageGetFirst){
    return (*pflcPaint_ImageGetFirst)();
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_ImageGetNext (HANDLE hImage)
{
  if (pflcPaint_ImageGetNext){
    return (*pflcPaint_ImageGetNext)(hImage);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_ImageGetByID (int Id)
{
  if (pflcPaint_ImageGetByID){
    return (*pflcPaint_ImageGetByID)(Id);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageLoad (HANDLE hImage, LPCWSTR szFileName)
{
  if (pflcPaint_ImageLoad){
    return (*pflcPaint_ImageLoad)(hImage, szFileName);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageCopy (HANDLE hImage, HANDLE hImageDest)
{
  if (pflcPaint_ImageCopy){
    return (*pflcPaint_ImageCopy)(hImage, hImageDest);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageCreate (HANDLE hImage, int Width, int Height)
{
  if (pflcPaint_ImageCreate){
    return (*pflcPaint_ImageCreate)(hImage, Width, Height);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageSetPixel (HANDLE hImage, int X, int Y, int R, int G, int B)
{
  if (pflcPaint_ImageSetPixel){
    return (*pflcPaint_ImageSetPixel)(hImage, X, Y, R, G, B);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageFlip (HANDLE hImage, BOOL bHor, BOOL bVert)
{
  if (pflcPaint_ImageFlip){
    return (*pflcPaint_ImageFlip)(hImage, bHor, bVert);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageRotate (HANDLE hImage, double Angle)
{
  if (pflcPaint_ImageRotate){
    return (*pflcPaint_ImageRotate)(hImage, Angle);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageGray (HANDLE hImage)
{
  if (pflcPaint_ImageGray){
    return (*pflcPaint_ImageGray)(hImage);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_ImageResize (HANDLE hImage, int NewWidth, int NewHeight, int ResizeFilter)
{
  if (pflcPaint_ImageResize){
    return (*pflcPaint_ImageResize)(hImage, NewWidth, NewHeight, ResizeFilter);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_ImageGetPtbuf (HANDLE hImage, double RotAngle)
{
  if (pflcPaint_ImageGetPtbuf){
    return (*pflcPaint_ImageGetPtbuf)(hImage, RotAngle);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_FontOpenLC (LPCWSTR szFontName)
{
  if (pflcPaint_FontOpenLC){
    return (*pflcPaint_FontOpenLC)(szFontName);
  }
  return 0;
}


//--------------
HANDLE LCAPI lcPaint_FontOpenTT (LPCWSTR szFontName, BOOL bBold, BOOL bItalic)
{
  if (pflcPaint_FontOpenTT){
    return (*pflcPaint_FontOpenTT)(szFontName, bBold, bItalic);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_FontClose (HANDLE hFont)
{
  if (pflcPaint_FontClose){
    return (*pflcPaint_FontClose)(hFont);
  }
  return 0;
}


//--------------
BOOL LCAPI lcPaint_FontSelect (HANDLE hLcWnd, HANDLE hFont)
{
  if (pflcPaint_FontSelect){
    return (*pflcPaint_FontSelect)(hLcWnd, hFont);
  }
  return 0;
}

