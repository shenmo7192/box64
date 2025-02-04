#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <dlfcn.h>

#include "wrappedlibs.h"

#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x64emu.h"
#include "emu/x64emu_private.h"
#include "callback.h"
#include "librarian.h"
#include "box64context.h"
#include "emu/x64emu_private.h"
#include "myalign.h"
#include "gtkclass.h"
#include "fileutils.h"

const char* gstreamerName = "libgstreamer-1.0.so.0";
#define LIBNAME gstreamer

typedef void*   (*pFppA_t)(void*, void*, va_list);
typedef void*   (*pFv_t)();
typedef size_t  (*LFv_t)();
typedef void*   (*pFp_t)(void*);
typedef void    (*vFpp_t)(void*, void*);
typedef int     (*iFpp_t)(void*, void*);

#define ADDED_FUNCTIONS()                   \
    GO(gst_object_get_type, LFv_t)          \
    GO(gst_allocator_get_type, LFv_t)       \
    GO(gst_task_pool_get_type, LFv_t)       \
    GO(gst_structure_new_valist, pFppA_t)   \
    GO(gst_structure_new_empty, pFp_t)      \
    GO(gst_caps_new_empty, pFv_t)           \
    GO(gst_caps_replace, iFpp_t)            \
    GO(gst_caps_append_structure, vFpp_t)   \
    GO(gst_bin_add, iFpp_t)                 \
    GO(gst_element_link, iFpp_t)            \

#include "generated/wrappedgstreamertypes.h"

#include "wrappercallback.h"

#define SUPER() \
GO(0)   \
GO(1)   \
GO(2)   \
GO(3)   \

// GDestroyFunc ...
#define GO(A)   \
static uintptr_t my_destroyfunc_fct_##A = 0;                                \
static int my_destroyfunc_##A(void* a, void* b)                             \
{                                                                           \
    return RunFunctionFmt(my_destroyfunc_fct_##A, "pp", a, b);  \
}
SUPER()
#undef GO
static void* findDestroyFct(void* fct)
{
    if(!fct) return fct;
    void* p;
    if((p = GetNativeFnc((uintptr_t)fct))) return p;
    if(GetNativeFnc((uintptr_t)fct))  return GetNativeFnc((uintptr_t)fct);
    #define GO(A) if(my_destroyfunc_fct_##A == (uintptr_t)fct) return my_destroyfunc_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_destroyfunc_fct_##A == 0) {my_destroyfunc_fct_##A = (uintptr_t)fct; return my_destroyfunc_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GDestroyNotify callback\n");
    return NULL;
}
//GstPadActivateModeFunction
#define GO(A)   \
static uintptr_t my_GstPadActivateModeFunction_fct_##A = 0;                                             \
static int my_GstPadActivateModeFunction_##A(void* a, void* b, int c, int d)                            \
{                                                                                                       \
    return (int)RunFunctionFmt(my_GstPadActivateModeFunction_fct_##A, "ppii", a, b, c, d);  \
}
SUPER()
#undef GO
static void* findGstPadActivateModeFunctionFct(void* fct)
{
    if(!fct) return fct;
    void* p;
    if((p = GetNativeFnc((uintptr_t)fct))) return p;
    #define GO(A) if(my_GstPadActivateModeFunction_fct_##A == (uintptr_t)fct) return my_GstPadActivateModeFunction_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstPadActivateModeFunction_fct_##A == 0) {my_GstPadActivateModeFunction_fct_##A = (uintptr_t)fct; return my_GstPadActivateModeFunction_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstPadActivateModeFunction callback\n");
    return NULL;
}
//GstPadQueryFunction
#define GO(A)   \
static uintptr_t my_GstPadQueryFunction_fct_##A = 0;                                        \
static int my_GstPadQueryFunction_##A(void* a, void* b, void* c)                            \
{                                                                                           \
    return (int)RunFunctionFmt(my_GstPadQueryFunction_fct_##A, "ppp", a, b, c); \
}
SUPER()
#undef GO
static void* findGstPadQueryFunctionFct(void* fct)
{
    if(!fct) return fct;
    void* p;
    if((p = GetNativeFnc((uintptr_t)fct))) return p;
    #define GO(A) if(my_GstPadQueryFunction_fct_##A == (uintptr_t)fct) return my_GstPadQueryFunction_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstPadQueryFunction_fct_##A == 0) {my_GstPadQueryFunction_fct_##A = (uintptr_t)fct; return my_GstPadQueryFunction_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstPadQueryFunction callback\n");
    return NULL;
}
//GstPadGetRangeFunction
#define GO(A)   \
static uintptr_t my_GstPadGetRangeFunction_fct_##A = 0;                                                 \
static int my_GstPadGetRangeFunction_##A(void* a, void* b, uint64_t c, uint32_t d, void* e)             \
{                                                                                                       \
    return (int)RunFunctionFmt(my_GstPadGetRangeFunction_fct_##A, "ppUup", a, b, c, d, e);  \
}
SUPER()
#undef GO
static void* findGstPadGetRangeFunctionFct(void* fct)
{
    if(!fct) return fct;
    void* p;
    if((p = GetNativeFnc((uintptr_t)fct))) return p;
    #define GO(A) if(my_GstPadGetRangeFunction_fct_##A == (uintptr_t)fct) return my_GstPadGetRangeFunction_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstPadGetRangeFunction_fct_##A == 0) {my_GstPadGetRangeFunction_fct_##A = (uintptr_t)fct; return my_GstPadGetRangeFunction_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstPadGetRangeFunction callback\n");
    return NULL;
}
//GstPadChainFunction
#define GO(A)   \
static uintptr_t my_GstPadChainFunction_fct_##A = 0;                                        \
static int my_GstPadChainFunction_##A(void* a, void* b, void* c)                            \
{                                                                                           \
    return (int)RunFunctionFmt(my_GstPadChainFunction_fct_##A, "ppp", a, b, c); \
}
SUPER()
#undef GO
static void* findGstPadChainFunctionFct(void* fct)
{
    if(!fct) return fct;
    void* p;
    if((p = GetNativeFnc((uintptr_t)fct))) return p;
    #define GO(A) if(my_GstPadChainFunction_fct_##A == (uintptr_t)fct) return my_GstPadChainFunction_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstPadChainFunction_fct_##A == 0) {my_GstPadChainFunction_fct_##A = (uintptr_t)fct; return my_GstPadChainFunction_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstPadChainFunction callback\n");
    return NULL;
}
//GstPadEventFunction
#define GO(A)   \
static uintptr_t my_GstPadEventFunction_fct_##A = 0;                                        \
static int my_GstPadEventFunction_##A(void* a, void* b, void* c)                            \
{                                                                                           \
    return (int)RunFunctionFmt(my_GstPadEventFunction_fct_##A, "ppp", a, b, c); \
}
SUPER()
#undef GO
static void* findGstPadEventFunctionFct(void* fct)
{
    if(!fct) return fct;
    #define GO(A) if(my_GstPadEventFunction_fct_##A == (uintptr_t)fct) return my_GstPadEventFunction_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstPadEventFunction_fct_##A == 0) {my_GstPadEventFunction_fct_##A = (uintptr_t)fct; return my_GstPadEventFunction_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstPadEventFunction callback\n");
    return NULL;
}
//GstBusSyncHandler
#define GO(A)   \
static uintptr_t my_GstBusSyncHandler_fct_##A = 0;                                          \
static int my_GstBusSyncHandler_##A(void* a, void* b, void* c)                              \
{                                                                                           \
    return (int)RunFunctionFmt(my_GstBusSyncHandler_fct_##A, "ppp", a, b, c);   \
}
SUPER()
#undef GO
static void* findGstBusSyncHandlerFct(void* fct)
{
    if(!fct) return fct;
    #define GO(A) if(my_GstBusSyncHandler_fct_##A == (uintptr_t)fct) return my_GstBusSyncHandler_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstBusSyncHandler_fct_##A == 0) {my_GstBusSyncHandler_fct_##A = (uintptr_t)fct; return my_GstBusSyncHandler_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstBusSyncHandler callback\n");
    return NULL;
}
//GstBusFunc
#define GO(A)   \
static uintptr_t my_GstBusFunc_fct_##A = 0;                             \
static int my_GstBusFunc_##A(void* a, void* b, void* c)                 \
{                                                                       \
    return (int)RunFunctionFmt(my_GstBusFunc_fct_##A, "ppp", a, b, c);  \
}
SUPER()
#undef GO
static void* findGstBusFuncFct(void* fct)
{
    if(!fct) return fct;
    #define GO(A) if(my_GstBusFunc_fct_##A == (uintptr_t)fct) return my_GstBusFunc_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstBusFunc_fct_##A == 0) {my_GstBusFunc_fct_##A = (uintptr_t)fct; return my_GstBusFunc_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstBusFunc callback\n");
    return NULL;
}

//GstPluginFeatureFilter
#define GO(A)   \
static uintptr_t my_GstPluginFeatureFilter_fct_##A = 0;                                     \
static int my_GstPluginFeatureFilter_##A(void* a, void* b)                                  \
{                                                                                           \
    return (int)RunFunctionFmt(my_GstPluginFeatureFilter_fct_##A, "pp", a, b);  \
}
SUPER()
#undef GO
static void* findGstPluginFeatureFilterFct(void* fct)
{
    if(!fct) return fct;
    #define GO(A) if(my_GstPluginFeatureFilter_fct_##A == (uintptr_t)fct) return my_GstPluginFeatureFilter_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstPluginFeatureFilter_fct_##A == 0) {my_GstPluginFeatureFilter_fct_##A = (uintptr_t)fct; return my_GstPluginFeatureFilter_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstPluginFeatureFilter callback\n");
    return NULL;
}

//GstCapsFilterMapFunc
#define GO(A)   \
static uintptr_t my_GstCapsFilterMapFunc_fct_##A = 0;                                           \
static int my_GstCapsFilterMapFunc_##A(void* a, void* b, void* c)                               \
{                                                                                               \
    return (int)RunFunctionFmt(my_GstCapsFilterMapFunc_fct_##A, "ppp", a, b, c);    \
}
SUPER()
#undef GO
static void* findGstCapsFilterMapFuncFct(void* fct)
{
    if(!fct) return fct;
    #define GO(A) if(my_GstCapsFilterMapFunc_fct_##A == (uintptr_t)fct) return my_GstCapsFilterMapFunc_##A;
    SUPER()
    #undef GO
    #define GO(A) if(my_GstCapsFilterMapFunc_fct_##A == 0) {my_GstCapsFilterMapFunc_fct_##A = (uintptr_t)fct; return my_GstCapsFilterMapFunc_##A; }
    SUPER()
    #undef GO
    printf_log(LOG_NONE, "Warning, no more slot for gstreamer GstCapsFilterMapFunc callback\n");
    return NULL;
}

#undef SUPER

EXPORT void my_gst_caps_set_simple(x64emu_t* emu, void* caps, void* field, void* b) {

    CREATE_VALIST_FROM_VAARG(b, emu->scratch, 2);
    my->gst_caps_set_simple_valist(caps, field, VARARGS);
}

EXPORT void my_gst_caps_set_simple_valist(x64emu_t* emu, void* caps, void* field, x64_va_list_t V) {
    #ifdef CONVERT_VALIST
    CONVERT_VALIST(V);
    #else
    CREATE_VALIST_FROM_VALIST(V, emu->scratch);
    #endif
    my->gst_caps_set_simple_valist(caps, field, VARARGS);
}

EXPORT void my_gst_structure_remove_fields(x64emu_t* emu, void* structure, void* field, void* b) {

    CREATE_VALIST_FROM_VAARG(b, emu->scratch, 2);
    my->gst_structure_remove_fields_valist(structure, field, VARARGS);
}

EXPORT void my_gst_structure_remove_fields_valist(x64emu_t* emu, void* structure, void* field, x64_va_list_t V) {
    #ifdef CONVERT_VALIST
    CONVERT_VALIST(V);
    #else
    CREATE_VALIST_FROM_VALIST(V, emu->scratch);
    #endif
    my->gst_structure_remove_fields_valist(structure, field, VARARGS);
}

EXPORT void my_gst_debug_log(x64emu_t* emu, void* cat, int level, void* file, void* func, int line, void* obj, void* fmt, void* b) {

    myStackAlign(emu, (const char*)fmt, b, emu->scratch, R_EAX, 7);
    PREPARE_VALIST;
    my->gst_debug_log_valist(cat, level, file, func, line, obj, fmt, VARARGS);
}

EXPORT void my_gst_debug_log_valist(x64emu_t* emu, void* cat, int level, void* file, void* func, int line, void* obj, void* fmt, x64_va_list_t V) {

    #ifdef CONVERT_VALIST
    CONVERT_VALIST(V);
    #else
    myStackAlignValist(emu, (const char*)fmt, emu->scratch, V);
    PREPARE_VALIST;
    #endif
    my->gst_debug_log_valist(cat, level, file, func, line, obj, fmt, VARARGS);
}

EXPORT int my_gst_structure_get(x64emu_t* emu, void* structure, void* field, void* b) {

    CREATE_VALIST_FROM_VAARG(b, emu->scratch, 2);
    return my->gst_structure_get_valist(structure, field, VARARGS);
}

EXPORT int my_gst_structure_get_valist(x64emu_t* emu, void* structure, void* field, x64_va_list_t V) {
    #ifdef CONVERT_VALIST
    CONVERT_VALIST(V);
    #else
    CREATE_VALIST_FROM_VALIST(V, emu->scratch);
    #endif
    return my->gst_structure_get_valist(structure, field, VARARGS);
}


EXPORT void my_gst_pad_set_activatemode_function_full(x64emu_t* emu, void* pad, void* f, void* data, void* d)
{
    my->gst_pad_set_activatemode_function_full(pad, findGstPadActivateModeFunctionFct(f), data, findDestroyFct(d));
}

EXPORT void my_gst_pad_set_query_function_full(x64emu_t* emu, void* pad, void* f, void* data, void* d)
{
    my->gst_pad_set_query_function_full(pad, findGstPadQueryFunctionFct(f), data, findDestroyFct(d));
}

EXPORT void my_gst_pad_set_getrange_function_full(x64emu_t* emu, void* pad, void* f, void* data, void* d)
{
    my->gst_pad_set_getrange_function_full(pad, findGstPadGetRangeFunctionFct(f), data, findDestroyFct(d));
}

EXPORT void my_gst_pad_set_chain_function_full(x64emu_t* emu, void* pad, void* f, void* data, void* d)
{
    my->gst_pad_set_chain_function_full(pad, findGstPadChainFunctionFct(f), data, findDestroyFct(d));
}

EXPORT void my_gst_pad_set_event_function_full(x64emu_t* emu, void* pad, void* f, void* data, void* d)
{
    my->gst_pad_set_event_function_full(pad, findGstPadEventFunctionFct(f), data, findDestroyFct(d));
}

EXPORT void my_gst_bus_set_sync_handler(x64emu_t* emu, void* bus, void* f, void* data, void* d)
{
    my->gst_bus_set_sync_handler(bus, findGstBusSyncHandlerFct(f), data, findDestroyFct(d));
}

EXPORT void* my_gst_buffer_new_wrapped_full(x64emu_t* emu, uint32_t f, void* data, size_t maxsize, size_t offset, size_t size, void* user, void* d)
{
    return my->gst_buffer_new_wrapped_full(f, data, maxsize, offset, size, user, findDestroyFct(d));
}

EXPORT void* my_gst_structure_new(x64emu_t* emu, void* name, void* first, uint64_t* b)
{
    if(!first)
        return my->gst_structure_new_empty(name);
    CREATE_VALIST_FROM_VAARG(b, emu->scratch, 2);
    return my->gst_structure_new_valist(name, first, VARARGS);
}

EXPORT void my_gst_mini_object_set_qdata(x64emu_t* emu, void* object, void* quark, void* data, void* d)
{
    my->gst_mini_object_set_qdata(object, quark, data, findDestroyFct(d));
}

EXPORT void* my_gst_caps_new_simple(x64emu_t* emu, void* type, void* name, void* b)
{
    // need to unroll the function here, there is no direct VA equivalent
    CREATE_VALIST_FROM_VAARG(b, emu->scratch, 2);
    void* caps = my->gst_caps_new_empty();
    void* structure = my->gst_structure_new_valist(type, name, VARARGS);
    if (structure)
        my->gst_caps_append_structure(caps, structure);
    else
        my->gst_caps_replace(&caps, NULL);

    return caps;
}

EXPORT void* my_gst_registry_feature_filter(x64emu_t* emu, void* reg, void* filter, int first, void* data)
{
    return my->gst_registry_feature_filter(reg, findGstPluginFeatureFilterFct(filter), first, data);
}

EXPORT int my_gst_caps_foreach(x64emu_t* emu, void* caps, void* f, void* data)
{
    return my->gst_caps_foreach(caps, findGstCapsFilterMapFuncFct(f), data);
}

EXPORT uint32_t my_gst_bus_add_watch(x64emu_t* emu, void* bus, void* f, void* data)
{
    return my->gst_bus_add_watch(bus, findGstBusFuncFct(f), data);
}

EXPORT uint32_t my_gst_bus_add_watch_full(x64emu_t* emu, void* bus, int priority, void* f, void* data, void* d)
{
    return my->gst_bus_add_watch_full(bus, priority, findGstBusFuncFct(f), data, findDestroyFct(d));
}

EXPORT int my_gst_bin_add_many(x64emu_t* emu, void* bin, void* first, void** b)
{
    int ret = my->gst_bin_add(bin, first);
    while(ret && *b) {
        ret = my->gst_bin_add(bin, *b);
        ++b;
    }
    return ret;
}

EXPORT int my_gst_element_link_many(x64emu_t* emu, void* e1, void* e2, void** b)
{
    int ret = my->gst_element_link(e1, e2);
    void* a = e2;
    while(ret && *b) {
        ret = my->gst_element_link(a, *b);
        a = *b;
        ++b;
    }
    return ret;
}
/*
EXPORT void* my_gst_plugin_load_file(x64emu_t* emu, const char* filename, void** error)
{
printf_log(LOG_INFO, "using gst_plugin_load_file, file %s (is x86_64=%d)\n", filename, FileIsX64ELF(filename));
    return my->gst_plugin_load_file((void*)filename, error);
}

EXPORT int my_gst_init_check(x64emu_t* emu, int* argc, char*** argv, void** error)
{
printf_log(LOG_INFO, "will call gst_init_check(%o, %p, %p)\n", argc, argv, error);
if(argc && argv) {
    printf_log(LOG_INFO, " argc=%d, argv=[", *argc);
    for(int i=0; i<*argc; ++i)
        printf_log(LOG_INFO, "%s\"%s\"", i?", ":"", (*argv)[i]);
    printf_log(LOG_INFO, "]");
}
if(getenv("GST_PLUGIN_LOADING_WHITELIST"))
    printf_log(LOG_INFO, "\nGST_PLUGIN_LOADING_WHITELIST=%s", getenv("GST_PLUGIN_LOADING_WHITELIST"));
printf_log(LOG_INFO, "\n");
    int ret = my->gst_init_check(argc, argv, error);
printf_log(LOG_INFO, "gst_init_check(...) return = %d\n", ret);
    return ret;
}
*/
#define PRE_INIT    \
    if(box64_nogtk) \
        return -1;

#define CUSTOM_INIT \
    getMy(lib);     \
    SetGstObjectID(my->gst_object_get_type());                 \
    SetGstAllocatorID(my->gst_allocator_get_type());           \
    SetGstTaskPoolID(my->gst_task_pool_get_type());            \
    setNeededLibs(lib, 1, "libgtk-3.so.0");

#define CUSTOM_FINI \
    freeMy();

#include "wrappedlib_init.h"
