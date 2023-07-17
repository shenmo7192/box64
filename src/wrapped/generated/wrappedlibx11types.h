/*******************************************************************
 * File automatically generated by rebuild_wrappers.py (v2.2.0.18) *
 *******************************************************************/
#ifndef __wrappedlibx11TYPES_H_
#define __wrappedlibx11TYPES_H_

#ifndef LIBNAME
#error You should only #include this file inside a wrapped*.c file
#endif
#ifndef ADDED_FUNCTIONS
#define ADDED_FUNCTIONS() 
#endif

typedef int32_t (*iFp_t)(void*);
typedef void* (*pFp_t)(void*);
typedef void (*vFpp_t)(void*, void*);
typedef void* (*pFiV_t)(int32_t, ...);
typedef void* (*pFpi_t)(void*, int32_t);
typedef void* (*pFpp_t)(void*, void*);
typedef void* (*pFpV_t)(void*, ...);
typedef int32_t (*iFppp_t)(void*, void*, void*);
typedef void* (*pFpip_t)(void*, int32_t, void*);
typedef int32_t (*iFpppp_t)(void*, void*, void*, void*);
typedef int32_t (*iFppppp_t)(void*, void*, void*, void*, void*);
typedef int32_t (*iFpppppp_t)(void*, void*, void*, void*, void*, void*);
typedef void* (*pFppiiuuLi_t)(void*, void*, int32_t, int32_t, uint32_t, uint32_t, uintptr_t, int32_t);
typedef int32_t (*iFppppiiiiuu_t)(void*, void*, void*, void*, int32_t, int32_t, int32_t, int32_t, uint32_t, uint32_t);
typedef void* (*pFppuiipuuii_t)(void*, void*, uint32_t, int32_t, int32_t, void*, uint32_t, uint32_t, int32_t, int32_t);
typedef void* (*pFppiiuuuipii_t)(void*, void*, int32_t, int32_t, uint32_t, uint32_t, uint32_t, int32_t, void*, int32_t, int32_t);

#define SUPER() ADDED_FUNCTIONS() \
	GO(XDestroyImage, iFp_t) \
	GO(XInitImage, iFp_t) \
	GO(XOpenDisplay, pFp_t) \
	GO(XSetErrorHandler, pFp_t) \
	GO(XSetIOErrorHandler, pFp_t) \
	GO(_XDeqAsyncHandler, vFpp_t) \
	GO(XVaCreateNestedList, pFiV_t) \
	GO(XSynchronize, pFpi_t) \
	GO(XSetAfterFunction, pFpp_t) \
	GO(XCreateIC, pFpV_t) \
	GO(XSetICValues, pFpV_t) \
	GO(XSetIMValues, pFpV_t) \
	GO(XAddConnectionWatch, iFppp_t) \
	GO(XRemoveConnectionWatch, iFppp_t) \
	GO(XESetCloseDisplay, pFpip_t) \
	GO(XESetError, pFpip_t) \
	GO(XESetEventToWire, pFpip_t) \
	GO(XESetWireToEvent, pFpip_t) \
	GO(XCheckIfEvent, iFpppp_t) \
	GO(XIfEvent, iFpppp_t) \
	GO(XPeekIfEvent, iFpppp_t) \
	GO(XQueryExtension, iFppppp_t) \
	GO(XRegisterIMInstantiateCallback, iFpppppp_t) \
	GO(XUnregisterIMInstantiateCallback, iFpppppp_t) \
	GO(XGetImage, pFppiiuuLi_t) \
	GO(XPutImage, iFppppiiiiuu_t) \
	GO(XCreateImage, pFppuiipuuii_t) \
	GO(XGetSubImage, pFppiiuuuipii_t)

#endif // __wrappedlibx11TYPES_H_
