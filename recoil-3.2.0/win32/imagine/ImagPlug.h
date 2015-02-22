#ifndef _IMAGPLUG_H_
#define _IMAGPLUG_H_

typedef struct IMAGINEPLUGINFILEINFOTABLE IMAGINEPLUGINFILEINFOTABLE;
typedef struct IMAGINEPLUGINARCHIVEINFOTABLE IMAGINEPLUGINARCHIVEINFOTABLE;
typedef struct IMAGINEARCHIVE IMAGINEARCHIVE;

#define IMAGINEAPI __stdcall

#define IMAGINEPLUGININTERFACE_VERSION_NUMBER1 1
#define IMAGINEPLUGININTERFACE_VERSION_NUMBER2 0
#define IMAGINEPLUGININTERFACE_VERSION_NUMBER3 8
#define IMAGINEPLUGININTERFACE_VERSION_NUMBER4 0 // unused
#define IMAGINEPLUGININTERFACE_VERSION ((IMAGINEPLUGININTERFACE_VERSION_NUMBER1<<24)|(IMAGINEPLUGININTERFACE_VERSION_NUMBER2<<16)|(IMAGINEPLUGININTERFACE_VERSION_NUMBER3<<8)|(IMAGINEPLUGININTERFACE_VERSION_NUMBER4<<0))

#if (!defined(UNICODE))
	#define ImaginePluginGetInfo ImaginePluginGetInfoA
	#define IMAGINEPLUGIN_ENTRYPROCNAME "ImaginePluginGetInfoA"
#else
	#define ImaginePluginGetInfo ImaginePluginGetInfoW
	#define IMAGINEPLUGIN_ENTRYPROCNAME "ImaginePluginGetInfoW"
#endif

#if (defined(_WIN64))
	#define IMAGINEPLUGIN_EXTENSION "plg64"
#else
	#define IMAGINEPLUGIN_EXTENSION "plg"
#endif

#define IMAGINEERROR_NOERROR 0
#define IMAGINEERROR_UNSUPPORTEDTYPE 1
#define IMAGINEERROR_UNKNOWNERROR 2
#define IMAGINEERROR_OUTOFMEMORY 3
#define IMAGINEERROR_COLORNOTSUPPORTED 4
#define IMAGINEERROR_READERROR 5
#define IMAGINEERROR_WRITEERROR 6
#define IMAGINEERROR_INVALIDDATA 7
#define IMAGINEERROR_FILENOTFOUND 8
#define IMAGINEERROR_ABORTED 9
#define IMAGINEERROR_GRAYSCALEONLY 10
#define IMAGINEERROR_OTHERCOMPONENTSREQUIRED 11
#define IMAGINEERROR_SIZENOTSUPPORTED 12
#define IMAGINEERROR_GETINFONOTSUPPORTED 13

#define IMAGINECOMPRESSION_NONE 0
#define IMAGINECOMPRESSION_RLE 1
#define IMAGINECOMPRESSION_PACKBITS 2
#define IMAGINECOMPRESSION_LZW 3
#define IMAGINECOMPRESSION_ZIP 4
#define IMAGINECOMPRESSION_JPEG 5
#define IMAGINECOMPRESSION_WAVELET 6
#define IMAGINECOMPRESSION_HUFFMANRLE 7
#define IMAGINECOMPRESSION_FAX3 8
#define IMAGINECOMPRESSION_FAX4 9
#define IMAGINECOMPRESSION_JBIG 10
#define IMAGINECOMPRESSION_JPEGXR 11
#define IMAGINECOMPRESSION_VP8 12

#define IMAGINELOADPARAM_OPTION 1
#define IMAGINELOADPARAM_CALLBACK 2
#define IMAGINELOADPARAM_TEST 4
#define IMAGINELOADPARAM_FIRSTFRAMEONLY 8
#define IMAGINELOADPARAM_DETECTEXTENSION 16
#define IMAGINELOADPARAM_FIRSTPAGEONLY 32
#define IMAGINELOADPARAM_SPECIFYFILE_TYPE 64
#define IMAGINELOADPARAM_GETINFO 128
#define IMAGINELOADPARAM_CLEAR 256
#define IMAGINELOADPARAM_NEARESTSIZE 512
#define IMAGINELOADPARAM_ZOOM 1024
#define IMAGINELOADPARAM_GETFILETIME 2048
#define IMAGINELOADPARAM_GETEXIF 4096

#define IMAGINESAVEPARAM_OPTION 1
#define IMAGINESAVEPARAM_CALLBACK 2
#define IMAGINESAVEPARAM_TEST 4
#define IMAGINESAVEPARAM_FIRSTFRAMEONLY 8
#define IMAGINESAVEPARAM_ADJUSTCOLOR 16
#define IMAGINESAVEPARAM_FIRSTPAGEONLY 32

#define IMAGINECAPS_ZOOM 1
#define IMAGINECAPS_MULTIFRAME 2
#define IMAGINECAPS_MULTIPAGE 4
#define IMAGINECAPS_TRANSPARENCYCOLOR 8
#define IMAGINECAPS_TRANSPARENCYMASK 16
#define IMAGINECAPS_ALPHA 32
#define IMAGINECAPS_GRAYSCALE 64
#define IMAGINECAPS_INTERLACED 128
#define IMAGINECAPS_PROGRESSIVE 256
#define IMAGINECAPS_BOTTOMUP 512
#define IMAGINECAPS_NEARESTSIZE 1024
#define IMAGINECAPS_TEXTCALLBACK 2048

#define IMAGINETRANSMETHOD_NONE 0
#define IMAGINETRANSMETHOD_COLOR 1
#define IMAGINETRANSMETHOD_MASK 2
#define IMAGINETRANSMETHOD_ALPHABLEND 3

#define IMAGINEEQUALIZEPARAM_CALLBACK 1

#define IMAGINEOPTIONITEM_CHECKBOX 0
#define IMAGINEOPTIONITEM_SCROLLBAR 1
#define IMAGINEOPTIONITEM_EDIT 2
#define IMAGINEOPTIONITEM_COMBOBOX 3

#define IMAGINELOADERPARAM_QUITONDESTROY 1
#define IMAGINELOADERPARAM_CMDSHOW 2

#define IMAGINECHILDPARAM_I_AM_IN_LISTER 1

#define WM_IMAGINE_LOADEROPEN (WM_USER+0x108)
#define WM_IMAGINE_LOADERFITIMAGE (WM_USER+0x109)

typedef DWORD IMAGINECOLOR;

typedef LPVOID LPIMAGINEBITMAP;
typedef LPVOID LPIMAGINEPALETTE;

#define IMAGINECHILD_VIEWPARAM_SET_IMAGE_FIT_MODE 1
#define IMAGINECHILD_VIEWPARAM_SET_CENTER_IMAGE 2

typedef struct IMAGINECHILD_VIEWPARAM
{
	int flags;
	int imageFitMode;
	BOOL centerImage;
} IMAGINECHILD_VIEWPARAM;

typedef struct IMAGINECHILDCREATEPARAM
{
	int flags;
} IMAGINECHILDCREATEPARAM;

typedef struct IMAGINELOADERCREATEPARAM
{
	int flags;
	int cmdShow;

	LPCTSTR commandLine;
} IMAGINELOADERCREATEPARAM;

typedef struct IMAGINESMARTBUFFER
{
	int size;
	int additionalAllocUnitSize;
	char *buffer;
	char *current;
	char *tail;
} IMAGINESMARTBUFFER;

typedef struct IMAGINECALLBACKPARAM
{
	LPIMAGINEBITMAP dib;
	LPVOID param;
	int current;
	int overall;
	LPCSTR message;
} IMAGINECALLBACKPARAM;

typedef BOOL (IMAGINEAPI *IMAGINECALLBACKPROC)(IMAGINECALLBACKPARAM *callbackParam);

typedef struct IMAGINECALLBACK
{
	IMAGINECALLBACKPROC proc;
	LPVOID param;
} IMAGINECALLBACK;

typedef struct IMAGINELOADOPTION
{
	BYTE reserved[32];
} IMAGINELOADOPTION;

typedef struct IMAGINESAVEOPTION
{
	BYTE reserved[64];
} IMAGINESAVEOPTION;

#define IMAGINEADJUSTCOLORANSWER_NO 0
#define IMAGINEADJUSTCOLORANSWER_YES 1
#define IMAGINEADJUSTCOLORANSWER_CANCEL 2
#define IMAGINEADJUSTCOLORANSWER_CHOOSEANOTHER 3

typedef int (IMAGINEAPI *IMAGINESAVEADJUSTCOLORPROMPTPROC)(IMAGINECALLBACKPARAM *callbackParam);

typedef struct IMAGINESAVEADJUSTCOLORPROMPT
{
	IMAGINESAVEADJUSTCOLORPROMPTPROC proc;
	LPVOID param;
} IMAGINESAVEADJUSTCOLORPROMPT;

typedef struct IMAGINESAVEADJUSTCOLOR
{
	LPVOID saveBufferProc;
	IMAGINESAVEADJUSTCOLORPROMPT prompt;
	LPVOID quantizeInfoTable;
} IMAGINESAVEADJUSTCOLOR;

typedef struct IMAGINEZOOMPARAM
{
	int numerator;
	int denominator;
} IMAGINEZOOMPARAM;

typedef struct IMAGINELOADPARAM
{
	DWORD length;
	LPVOID buffer;
	LPVOID fileInfo;
	IMAGINELOADOPTION option;
	IMAGINEZOOMPARAM zoom;
	SIZE size;
	IMAGINECALLBACK callback;
	DWORD errorCode;
	DWORD caps;
	FILETIME fileTime;

	// Private
	LPCTSTR fileName;
} IMAGINELOADPARAM;

typedef struct IMAGINESAVEPARAM
{
	LPCTSTR fileType;
	IMAGINESAVEOPTION option;
	IMAGINECALLBACK callback;
	DWORD errorCode;
	DWORD caps;
	IMAGINESMARTBUFFER *sb;

	// Private
	LPVOID saveBufferProc;
	IMAGINESAVEADJUSTCOLOR adjustColor;
} IMAGINESAVEPARAM;

typedef struct IMAGINEFILTERPARAM
{
	LPCTSTR filterType;

	DWORD errorCode;
} IMAGINEFILTERPARAM;

typedef struct IMAGINEFILTERPROCESSINFO
{
	const LONG *kernel;
	LONG Ksize;
	LONG Kfactor;
	LONG Koffset;
} IMAGINEFILTERPROCESSINFO;

typedef struct IMAGINEFILTERPROCESSPARAM
{
	// Public
	const IMAGINEFILTERPROCESSINFO *info;

	DWORD errorCode;
} IMAGINEFILTERPROCESSPARAM;

typedef struct IMAGINEEQUALIZEPARAM
{
	IMAGINECALLBACK callback;

	DWORD errorCode;
} IMAGINEEQUALIZEPARAM;

typedef struct IMAGINEOPTIONITEMCOMBOBOX
{
	int itemCount;
	const LPCTSTR *itemString;
} IMAGINEOPTIONITEMCOMBOBOX;

typedef struct IMAGINEOPTIONITEMSCROLLBAR
{
	int min;
	int max;
} IMAGINEOPTIONITEMSCROLLBAR;

typedef union IMAGINEOPTIONITEMCUSTOM
{
	IMAGINEOPTIONITEMCOMBOBOX combobox;
	IMAGINEOPTIONITEMSCROLLBAR scrollbar;
} IMAGINEOPTIONITEMCUSTOM;

typedef struct IMAGINEOPTIONITEM
{
	int type;
	LPCTSTR text;
	DWORD dwDefault;
	const IMAGINEOPTIONITEMCUSTOM *custom;
} IMAGINEOPTIONITEM;

typedef struct IMAGINEOPTION
{
	int itemCount;
	const IMAGINEOPTIONITEM *item;
} IMAGINEOPTION;

typedef struct IMAGINEFILEINFOITEM
{
	BOOL (IMAGINEAPI *checkFileTypeProc)(IMAGINEPLUGINFILEINFOTABLE *table,IMAGINELOADPARAM *param,int flags);
	LPIMAGINEBITMAP (IMAGINEAPI *loadBufferProc)(IMAGINEPLUGINFILEINFOTABLE *table,IMAGINELOADPARAM *param,int flags);
	BOOL (IMAGINEAPI *saveBufferProc)(IMAGINEPLUGINFILEINFOTABLE *table,LPIMAGINEBITMAP bitmap,IMAGINESAVEPARAM *param,int flags);
	LPCTSTR fileType;
	LPCTSTR extension;
	LPVOID reserved;
	const IMAGINEOPTION *option;
} IMAGINEFILEINFOITEM;

typedef struct IMAGINEFILEINFO
{
	IMAGINEFILEINFOITEM item;

	BOOL isActive;
	struct IMAGINEFILEINFO *next;
	struct IMAGINEFILEINFO *prev;
} IMAGINEFILEINFO;

typedef struct IMAGINEFILTERINFOITEM
{
	IMAGINEFILTERPROCESSINFO info;
	LPIMAGINEBITMAP (IMAGINEAPI *Filter)(LPVOID table,LPIMAGINEBITMAP bitmap,IMAGINEFILTERPARAM *filterParam,int flags);
	LPCTSTR filterType;
} IMAGINEFILTERINFOITEM;

typedef struct IMAGINEFILTERINFO
{
	IMAGINEFILTERINFOITEM item;

	BOOL isActive;
	struct IMAGINEFILTERINFO *next;
	struct IMAGINEFILTERINFO *prev;
} IMAGINEFILTERINFO;

#define IMAGINEARCHIVE_PROCESS_OPERATION_SKIP 0
#define IMAGINEARCHIVE_PROCESS_OPERATION_EXTRACT 1

typedef struct IMAGINEARCHIVEINFOITEM
{
	LPCTSTR archiveType;
	LPCTSTR extension;
	BOOL (__stdcall *checkArchiveProc)(IMAGINEPLUGINARCHIVEINFOTABLE *archiveInfoTable,LPCTSTR fileName);
	BOOL (__stdcall *openArchiveProc)(IMAGINEPLUGINARCHIVEINFOTABLE *archiveInfoTable,IMAGINEARCHIVE *archive,LPCTSTR fileName);
	BOOL (__stdcall *readHeaderProc)(IMAGINEPLUGINARCHIVEINFOTABLE *archiveInfoTable,IMAGINEARCHIVE *archive,WIN32_FIND_DATA *wfd);
	BOOL (__stdcall *processFileProc)(IMAGINEPLUGINARCHIVEINFOTABLE *archiveInfoTable,IMAGINEARCHIVE *archive,int operation,LPVOID buffer,DWORD bufferLength);
	BOOL (__stdcall *closeArchiveProc)(IMAGINEPLUGINARCHIVEINFOTABLE *archiveInfoTable,IMAGINEARCHIVE *archive);
} IMAGINEARCHIVEINFOITEM;

typedef struct IMAGINEARCHIVEINFO
{
	IMAGINEARCHIVEINFOITEM item;

	BOOL isActive;
	struct IMAGINEARCHIVEINFO *next;
	struct IMAGINEARCHIVEINFO *prev;
} IMAGINEARCHIVEINFO;

struct IMAGINEARCHIVE
{
	IMAGINEARCHIVEINFO *archiveInfo;
	LPVOID lParam;
};

typedef struct IMAGINEPLUGININTERFACEVTBL
{
	IMAGINEFILEINFO *(IMAGINEAPI *RegisterFileType)(const IMAGINEFILEINFOITEM *item);
	LPIMAGINEBITMAP (IMAGINEAPI *Create)(LONG width,LONG height,LONG bitCount,int flags);
	LPIMAGINEBITMAP (IMAGINEAPI *CreateMask)(LONG width,LONG height);
	BOOL (IMAGINEAPI *Destroy)(LPIMAGINEBITMAP bitmap);
	LONG (IMAGINEAPI *GetWidth)(LPIMAGINEBITMAP bitmap);
	LONG (IMAGINEAPI *GetHeight)(LPIMAGINEBITMAP bitmap);
	LONG (IMAGINEAPI *GetBitCount)(LPIMAGINEBITMAP bitmap);
	LPVOID (IMAGINEAPI *GetBits)(LPIMAGINEBITMAP bitmap);
	LONG (IMAGINEAPI *GetWidthBytes)(LPIMAGINEBITMAP bitmap);
	LONG (IMAGINEAPI *GetPureWidthBytes)(LPIMAGINEBITMAP bitmap);
	LONG (IMAGINEAPI *GetLength)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *GetPalette)(LPIMAGINEBITMAP bitmap,LPPALETTEENTRY paletteEntry);
	BOOL (IMAGINEAPI *SetPalette)(LPIMAGINEBITMAP bitmap,LPPALETTEENTRY paletteEntry);
	IMAGINESMARTBUFFER *(IMAGINEAPI *sbAlloc)(int initialSize,int additionalAllocUnitSize);
	LPVOID (IMAGINEAPI *sbWrite)(IMAGINESMARTBUFFER *sb,LPVOID dest,LPCVOID src,int length);
	LPVOID (IMAGINEAPI *Alloc)(int size);
	VOID (IMAGINEAPI *Free)(LPVOID block);
	BOOL (IMAGINEAPI *UtilImportPalette)(LPPALETTEENTRY palette,LPVOID data,int entryCount,int entryType);
	BOOL (IMAGINEAPI *UtilExportPalette)(LPPALETTEENTRY palette,LPVOID data,int entryCount,int entryType);
	BOOL (IMAGINEAPI *UtilCreateGrayscalePalette)(LPPALETTEENTRY palette,int entryCount);
	LONG (IMAGINEAPI *UtilGetBitCountFromColorCount)(LONG nColorCount);
	int (IMAGINEAPI *Get16BitMode)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *Set16BitMode)(LPIMAGINEBITMAP bitmap,int mode);
	int (IMAGINEAPI *GetTransMethod)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *SetTransMethod)(LPIMAGINEBITMAP bitmap,int transMethod);
	IMAGINECOLOR (IMAGINEAPI *GetTransColor)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *SetTransColor)(LPIMAGINEBITMAP bitmap,IMAGINECOLOR color);
	LPIMAGINEBITMAP (IMAGINEAPI *GetTransMask)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *SetTransMask)(LPIMAGINEBITMAP bitmap,LPIMAGINEBITMAP mask);
	LPIMAGINEBITMAP (IMAGINEAPI *TransConvertMethod)(LPIMAGINEBITMAP bitmap,int transMethod);
	BOOL (IMAGINEAPI *PageAddFrame)(LPIMAGINEBITMAP bitmap,LPIMAGINEBITMAP prev);
	LPIMAGINEBITMAP (IMAGINEAPI *PageGetNext)(LPIMAGINEBITMAP bitmap);
	LPIMAGINEBITMAP (IMAGINEAPI *PageGetPrev)(LPIMAGINEBITMAP bitmap);
	DWORD (IMAGINEAPI *PageGetFrameCount)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *AnimAddFrame)(LPIMAGINEBITMAP bitmap,LPIMAGINEBITMAP prev);
	BOOL (IMAGINEAPI *AnimDeleteFrame)(LPIMAGINEBITMAP bitmap);
	LPIMAGINEBITMAP (IMAGINEAPI *AnimGetNext)(LPIMAGINEBITMAP bitmap);
	LPIMAGINEBITMAP (IMAGINEAPI *AnimGetPrev)(LPIMAGINEBITMAP bitmap);
	LPIMAGINEBITMAP (IMAGINEAPI *AnimGetHead)(LPIMAGINEBITMAP bitmap);
	LPIMAGINEBITMAP (IMAGINEAPI *AnimGetTail)(LPIMAGINEBITMAP bitmap);
	DWORD (IMAGINEAPI *AnimGetDelay)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *AnimSetDelay)(LPIMAGINEBITMAP bitmap,DWORD delay);
	DWORD (IMAGINEAPI *AnimGetFrameCount)(LPIMAGINEBITMAP bitmap);
	LPIMAGINEBITMAP (IMAGINEAPI *AnimGetFrame)(LPIMAGINEBITMAP bitmap,int frameNumber);
	int (IMAGINEAPI *AnimGetFrameNumber)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *GetFocus)(LPIMAGINEBITMAP bitmap,LPPOINT pt);
	BOOL (IMAGINEAPI *SetFocus)(LPIMAGINEBITMAP bitmap,LPPOINT pt);
	DWORD (IMAGINEAPI *GetCompression)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *SetCompression)(LPIMAGINEBITMAP bitmap,DWORD compression);
	IMAGINECOLOR (IMAGINEAPI *GetPixel)(LPIMAGINEBITMAP bitmap,int x,int y);
	BOOL (IMAGINEAPI *PutPixel)(LPIMAGINEBITMAP bitmap,int x,int y,IMAGINECOLOR color);
	IMAGINECOLOR (IMAGINEAPI *GetPixelColor)(LPIMAGINEBITMAP bitmap,int x,int y);
	BOOL (IMAGINEAPI *PutPixelColor)(LPIMAGINEBITMAP bitmap,int x,int y,IMAGINECOLOR color);
	LPIMAGINEPALETTE (IMAGINEAPI *PaletteCreate)(LPPALETTEENTRY entry,int entryCount);
	BOOL (IMAGINEAPI *PaletteDestroy)(LPIMAGINEPALETTE palette);
	int (IMAGINEAPI *PaletteGetEntryNumber)(LPIMAGINEPALETTE palette);
	LPPALETTEENTRY (IMAGINEAPI *PaletteGetEntry)(LPIMAGINEPALETTE palette,int entryNumber);
	int (IMAGINEAPI *PaletteGetNearestIndex)(LPIMAGINEPALETTE palette,LPPALETTEENTRY color);
	LPIMAGINEBITMAP (IMAGINEAPI *Copy)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *Flip)(LPIMAGINEBITMAP bitmap);
	IMAGINEFILTERINFO *(IMAGINEAPI *RegisterFilterType)(const IMAGINEFILTERINFOITEM *item);
	LPIMAGINEBITMAP (IMAGINEAPI *Filter)(LPIMAGINEBITMAP bitmap,IMAGINEFILTERPARAM *filterParam,int flags);
	LPIMAGINEBITMAP (IMAGINEAPI *FilterProcess)(LPIMAGINEBITMAP bitmap,IMAGINEFILTERPROCESSPARAM *filterProcessParam,int flags);
	LPIMAGINEBITMAP (IMAGINEAPI *LoadFile)(LPCTSTR fileName,IMAGINELOADPARAM *loadParam,int flags);
	DWORD (IMAGINEAPI *SaveFile)(LPIMAGINEBITMAP bitmap,LPCTSTR fileName,IMAGINESAVEPARAM *dsp,int flags);
	IMAGINEFILEINFO *(IMAGINEAPI *GetFileInfo)(LPIMAGINEBITMAP bitmap);
	IMAGINEFILEINFO *(IMAGINEAPI *GetFileType)(LPCTSTR fileType);
	BOOL (IMAGINEAPI *GetFileExtension)(IMAGINEFILEINFO *info,LPTSTR buffer,int extensionNumber);
	IMAGINEFILEINFO *(IMAGINEAPI *GetFileInfoWithExtension)(LPCTSTR extension);
	LPIMAGINEBITMAP (IMAGINEAPI *Equalize)(LPIMAGINEBITMAP bitmap,IMAGINEEQUALIZEPARAM *equalizeParam,int flags);
	BOOL (IMAGINEAPI *SaveAdjustColor)(IMAGINESAVEPARAM *saveParam,IMAGINESAVEADJUSTCOLORPROMPT *prompt);
	BOOL (IMAGINEAPI *SaveOptionLoad)(IMAGINEFILEINFO *info,IMAGINESAVEOPTION *saveOption,LPCTSTR fileName);
	LPVOID (IMAGINEAPI *BSearch)(LPCVOID key,LPCVOID base,int num,int width,int (__cdecl *compare)(LPCVOID,LPCVOID));
	VOID (IMAGINEAPI *QSort)(LPVOID base,int num,int width,int (__cdecl *compare)(LPCVOID,LPCVOID));
	BOOL (IMAGINEAPI *UtilCheckGrayscalePalette)(LPPALETTEENTRY palette,int entryCount);
	BOOL (IMAGINEAPI *PageGetMipMap)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *PageSetMipMap)(LPIMAGINEBITMAP bitmap,BOOL isMipMapAvailable);
	BOOL (IMAGINEAPI *TestFile)(LPCTSTR fileName);
	HWND (IMAGINEAPI *ChildCreate)(HWND hwnd,LPCTSTR fileName,IMAGINECHILDCREATEPARAM *createParam);
	HWND (IMAGINEAPI *LoaderCreate)(HWND hwnd,LPCTSTR commandLine,IMAGINELOADERCREATEPARAM *createParam);
	BOOL (IMAGINEAPI *CopyClipboard)(HWND hwnd);
	BOOL (IMAGINEAPI *Redraw)(HWND hwnd,BOOL eraseBackground);
	HBITMAP (IMAGINEAPI *GetPreviewBitmap)(LPCTSTR fileName,LONG width,LONG height);
	LPCTSTR (IMAGINEAPI *OptionGetFileName)(VOID);
	LPWINDOWPLACEMENT (IMAGINEAPI *LoaderGetPosition)(HWND hwnd);
	BOOL (IMAGINEAPI *PrintDialog)(HWND hwnd);
	LPVOID (IMAGINEAPI *GetLineBits)(LPIMAGINEBITMAP bitmap,int y);
	BOOL (IMAGINEAPI *ChildOpenFileName)(HWND hwnd,LPCTSTR fileName);
	BOOL (IMAGINEAPI *ChildViewSetParam)(HWND hwnd,IMAGINECHILD_VIEWPARAM *viewParam);
	BOOL (IMAGINEAPI *SlideShow)(HWND parent,LPVOID header);
	IMAGINEARCHIVEINFO *(IMAGINEAPI *RegisterArchiveType)(const IMAGINEARCHIVEINFOITEM *item);
	int (IMAGINEAPI *ANSIToUnicode)(LPWSTR unicodeString,int bufferCount,LPCSTR ansiString,int count);
	int (IMAGINEAPI *UnicodeToANSI)(LPSTR ansiString,int bufferCount,LPCWSTR unicodeString,int count);
	HANDLE (IMAGINEAPI *CreateFile)(LPCTSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDistribution,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
	BOOL (IMAGINEAPI *ReadFile)(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);
	BOOL (IMAGINEAPI *WriteFile)(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped);
	DWORD (IMAGINEAPI *SetFilePointer)(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod);
	BOOL (IMAGINEAPI *CloseHandle)(HANDLE hObject);
	VOID (IMAGINEAPI *sbFree)(IMAGINESMARTBUFFER *sb);
	BOOL (IMAGINEAPI *CreateMultipleFrameWindow)(HWND parent,LPVOID param);
	BOOL (IMAGINEAPI *SaveDialog)(HWND parent,LPVOID param);
	LPIMAGINEBITMAP (IMAGINEAPI *LoadBuffer)(IMAGINELOADPARAM *loadParam,int flags);
	BOOL (IMAGINEAPI *SetFileInfo)(LPIMAGINEBITMAP bitmap,const IMAGINEFILEINFO *fileInfo);
	BOOL (IMAGINEAPI *IsUnicode)(VOID);
	LPVOID (IMAGINEAPI *AllocUserBuffer)(LPIMAGINEBITMAP bitmap,DWORD length);
	LPCTSTR (IMAGINEAPI *GetCompressionText)(LPIMAGINEBITMAP bitmap);
	BOOL (IMAGINEAPI *SetCompressionText)(LPIMAGINEBITMAP bitmap,LPCTSTR compressionText);
	int (IMAGINEAPI *sbSeek)(IMAGINESMARTBUFFER *sb,long offset,int origin);
} IMAGINEPLUGININTERFACEVTBL;

typedef struct IMAGINEPLUGININTERFACE
{
	const IMAGINEPLUGININTERFACEVTBL *lpVtbl;
} IMAGINEPLUGININTERFACE;

struct IMAGINEPLUGINFILEINFOTABLE
{
	IMAGINEFILEINFO *head;
	IMAGINEFILEINFO *tail;
	const IMAGINEPLUGININTERFACE *iface;
};

struct IMAGINEPLUGINARCHIVEINFOTABLE
{
	IMAGINEARCHIVEINFO *head;
	IMAGINEARCHIVEINFO *tail;
	const IMAGINEPLUGININTERFACE *iface;
};

typedef BOOL (IMAGINEAPI *IMAGINEPLUGINREGISTERPROC)(const IMAGINEPLUGININTERFACE *iface);

typedef struct IMAGINEPLUGININFOA
{
	DWORD size;
	IMAGINEPLUGINREGISTERPROC registerProc;
	DWORD versionNumber;
	LPCSTR description;
	DWORD usedInterfaceVersionNumber;
} IMAGINEPLUGININFOA;

typedef struct IMAGINEPLUGININFOW
{
	DWORD size;
	IMAGINEPLUGINREGISTERPROC registerProc;
	DWORD versionNumber;
	LPCWSTR description;
	DWORD usedInterfaceVersionNumber;
} IMAGINEPLUGININFOW;

#if (defined(UNICODE))
	#define IMAGINEPLUGININFO IMAGINEPLUGININFOW
#else
	#define IMAGINEPLUGININFO IMAGINEPLUGININFOA
#endif

#endif