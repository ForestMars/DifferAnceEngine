#define PY_SSIZE_T_CLEAN
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_21"
#define CYTHON_HEX_VERSION 0x001D15F0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #if defined(PyUnicode_IS_READY) && defined(PyUnicode_GET_SIZE)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
  #else
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #endif
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? ((void)(klass), PyMethod_New(func, self)) : __Pyx_NewRef(func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__models
#define __PYX_HAVE_API__models
/* Early includes */
#ifdef _OPENMP
#include <omp.h>
#endif /* _OPENMP */

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif


/* Test for GCC > 2.95 */
#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else /* !__GNUC__ or GCC < 2.95 */
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif /* __GNUC__ */
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "models.py",
};

/*--- Type declarations ---*/

/* --- Runtime support code (head) --- */
/* Refnanny.proto */
#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)

/* PyObjectGetAttrStr.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif

/* GetBuiltinName.proto */
static PyObject *__Pyx_GetBuiltinName(PyObject *name);

/* PyDictVersioning.proto */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif

/* GetModuleGlobalName.proto */
#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var, name)  {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif

/* PyObjectCall.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif

/* PyObjectSetAttrStr.proto */
#if CYTHON_USE_TYPE_SLOTS
#define __Pyx_PyObject_DelAttrStr(o,n) __Pyx_PyObject_SetAttrStr(o, n, NULL)
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value);
#else
#define __Pyx_PyObject_DelAttrStr(o,n)   PyObject_DelAttr(o,n)
#define __Pyx_PyObject_SetAttrStr(o,n,v) PyObject_SetAttr(o,n,v)
#endif

/* PyFunctionFastCall.proto */
#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif

/* PyObjectCallMethO.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif

/* PyObjectCallNoArg.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif

/* PyCFunctionFastCall.proto */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif

/* PyObjectCallOneArg.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);

/* RaiseArgTupleInvalid.proto */
static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);

/* RaiseDoubleKeywords.proto */
static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);

/* ParseKeywords.proto */
static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);

/* GetAttr.proto */
static CYTHON_INLINE PyObject *__Pyx_GetAttr(PyObject *, PyObject *);

/* ListCompAppend.proto */
#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_ListComp_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len)) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_ListComp_Append(L,x) PyList_Append(L,x)
#endif

/* ListAppend.proto */
#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_PyList_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len) & likely(len > (L->allocated >> 1))) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_PyList_Append(L,x) PyList_Append(L,x)
#endif

/* PyObjectCall2Args.proto */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);

/* DictGetItem.proto */
#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key);
#define __Pyx_PyObject_Dict_GetItem(obj, name)\
    (likely(PyDict_CheckExact(obj)) ?\
     __Pyx_PyDict_GetItem(obj, name) : PyObject_GetItem(obj, name))
#else
#define __Pyx_PyDict_GetItem(d, key) PyObject_GetItem(d, key)
#define __Pyx_PyObject_Dict_GetItem(obj, name)  PyObject_GetItem(obj, name)
#endif

/* GetItemInt.proto */
#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);

/* ObjectGetItem.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key);
#else
#define __Pyx_PyObject_GetItem(obj, key)  PyObject_GetItem(obj, key)
#endif

/* PyIntCompare.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, long intval, long inplace);

/* PyIntBinop.proto */
#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_RemainderObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_RemainderObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceRemainder(op1, op2) : PyNumber_Remainder(op1, op2))
#endif

/* PyObjectFormatSimple.proto */
#if CYTHON_COMPILING_IN_PYPY
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#elif PY_MAJOR_VERSION < 3
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyString_CheckExact(s)) ? PyUnicode_FromEncodedObject(s, NULL, "strict") :\
        PyObject_Format(s, f))
#elif CYTHON_USE_TYPE_SLOTS
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyLong_CheckExact(s)) ? PyLong_Type.tp_str(s) :\
        likely(PyFloat_CheckExact(s)) ? PyFloat_Type.tp_str(s) :\
        PyObject_Format(s, f))
#else
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#endif

/* IncludeStringH.proto */
#include <string.h>

/* JoinPyUnicode.proto */
static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      Py_UCS4 max_char);

/* Import.proto */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);

/* ImportFrom.proto */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);

/* CalculateMetaclass.proto */
static PyObject *__Pyx_CalculateMetaclass(PyTypeObject *metaclass, PyObject *bases);

/* FetchCommonType.proto */
static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);

/* CythonFunctionShared.proto */
#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f)\
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;  // used by FusedFunction for copying defaults
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj)  (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);

/* CythonFunction.proto */
static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);

/* SetNameInClass.proto */
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
#define __Pyx_SetNameInClass(ns, name, value)\
    (likely(PyDict_CheckExact(ns)) ? _PyDict_SetItem_KnownHash(ns, name, value, ((PyASCIIObject *) name)->hash) : PyObject_SetItem(ns, name, value))
#elif CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_SetNameInClass(ns, name, value)\
    (likely(PyDict_CheckExact(ns)) ? PyDict_SetItem(ns, name, value) : PyObject_SetItem(ns, name, value))
#else
#define __Pyx_SetNameInClass(ns, name, value)  PyObject_SetItem(ns, name, value)
#endif

/* Py3ClassCreate.proto */
static PyObject *__Pyx_Py3MetaclassPrepare(PyObject *metaclass, PyObject *bases, PyObject *name, PyObject *qualname,
                                           PyObject *mkw, PyObject *modname, PyObject *doc);
static PyObject *__Pyx_Py3ClassCreate(PyObject *metaclass, PyObject *name, PyObject *bases, PyObject *dict,
                                      PyObject *mkw, int calculate_metaclass, int allow_py2_metaclass);

/* PyFloatBinop.proto */
#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyFloat_TrueDivideObjC(PyObject *op1, PyObject *op2, double floatval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyFloat_TrueDivideObjC(op1, op2, floatval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceTrueDivide(op1, op2) : PyNumber_TrueDivide(op1, op2))
#endif

/* PyThreadStateGet.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif

/* PyErrFetchRestore.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif

/* CLineInTraceback.proto */
#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif

/* CodeObjectCache.proto */
typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);

/* AddTraceback.proto */
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);

/* CIntFromPy.proto */
static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);

/* CIntFromPy.proto */
static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);

/* FastTypeChecks.proto */
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)

/* CheckBinaryVersion.proto */
static int __Pyx_check_binary_version(void);

/* InitStrings.proto */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);


/* Module declarations from 'models' */
static PyObject *__pyx_8genexpr2__pyx_v_6models_i;
#define __Pyx_MODULE_NAME "models"
extern int __pyx_module_is_main_models;
int __pyx_module_is_main_models = 0;

/* Implementation of 'models' */
static PyObject *__pyx_builtin_object;
static PyObject *__pyx_builtin_range;
static PyObject *__pyx_builtin_print;
static const char __pyx_k_C[] = "C";
static const char __pyx_k_N[] = "N";
static const char __pyx_k_T[] = "T";
static const char __pyx_k_X[] = "X";
static const char __pyx_k_b[] = "b";
static const char __pyx_k_e[] = "e";
static const char __pyx_k_f[] = "f";
static const char __pyx_k_i[] = "i";
static const char __pyx_k_w[] = "w";
static const char __pyx_k_x[] = "x";
static const char __pyx_k_y[] = "y";
static const char __pyx_k_LR[] = "LR";
static const char __pyx_k_Xi[] = "Xi";
static const char __pyx_k__4[] = ")";
static const char __pyx_k__8[] = "";
static const char __pyx_k_np[] = "np";
static const char __pyx_k_os[] = "os";
static const char __pyx_k_pd[] = "pd";
static const char __pyx_k_re[] = "re";
static const char __pyx_k_yi[] = "yi";
static const char __pyx_k_SVC[] = "SVC";
static const char __pyx_k_ada[] = "ada";
static const char __pyx_k_bnb[] = "bnb";
static const char __pyx_k_cat[] = "cat";
static const char __pyx_k_clf[] = "clf";
static const char __pyx_k_doc[] = "__doc__";
static const char __pyx_k_dot[] = "dot";
static const char __pyx_k_est[] = "est";
static const char __pyx_k_fit[] = "fit";
static const char __pyx_k_gbc[] = "gbc";
static const char __pyx_k_get[] = "get";
static const char __pyx_k_gnb[] = "gnb";
static const char __pyx_k_knn[] = "knn";
static const char __pyx_k_lda[] = "lda";
static const char __pyx_k_low[] = "low";
static const char __pyx_k_mnb[] = "mnb";
static const char __pyx_k_num[] = "num";
static const char __pyx_k_pav[] = "pav";
static const char __pyx_k_qda[] = "qda";
static const char __pyx_k_rfc[] = "rfc";
static const char __pyx_k_sgd[] = "sgd";
static const char __pyx_k_sum[] = "sum";
static const char __pyx_k_svm[] = "svm";
static const char __pyx_k_xgb[] = "xgb";
static const char __pyx_k_Loss[] = ", Loss: ";
static const char __pyx_k_SEED[] = "SEED";
static const char __pyx_k_auto[] = "auto";
static const char __pyx_k_cats[] = "cats";
static const char __pyx_k_gini[] = "gini";
static const char __pyx_k_grid[] = "grid";
static const char __pyx_k_high[] = "high";
static const char __pyx_k_init[] = "__init__";
static const char __pyx_k_lgbm[] = "lgbm";
static const char __pyx_k_loss[] = "loss";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_self[] = "self";
static const char __pyx_k_sqrt[] = "sqrt";
static const char __pyx_k_stop[] = "stop";
static const char __pyx_k_svml[] = "svml";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_xgbp[] = "xgbp";
static const char __pyx_k_Epoch[] = "Epoch: ";
static const char __pyx_k_N_EST[] = "N_EST";
static const char __pyx_k_array[] = "array";
static const char __pyx_k_codes[] = "codes";
static const char __pyx_k_numpy[] = "numpy";
static const char __pyx_k_param[] = "param";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_shape[] = "shape";
static const char __pyx_k_start[] = "start";
static const char __pyx_k_tfidf[] = "tfidf";
static const char __pyx_k_Params[] = "Params";
static const char __pyx_k_epochs[] = "epochs";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_kernel[] = "kernel";
static const char __pyx_k_linear[] = "linear";
static const char __pyx_k_max_df[] = "max_df";
static const char __pyx_k_models[] = "models";
static const char __pyx_k_module[] = "__module__";
static const char __pyx_k_n_jobs[] = "n_jobs";
static const char __pyx_k_object[] = "object";
static const char __pyx_k_pandas[] = "pandas";
static const char __pyx_k_pprint[] = "pprint";
static const char __pyx_k_target[] = "target";
static const char __pyx_k_values[] = "values";
static const char __pyx_k_history[] = "history";
static const char __pyx_k_predict[] = "predict";
static const char __pyx_k_prepare[] = "__prepare__";
static const char __pyx_k_reshape[] = "reshape";
static const char __pyx_k_sklearn[] = "sklearn";
static const char __pyx_k_svm_SVC[] = "svm.SVC";
static const char __pyx_k_verbose[] = "verbose";
static const char __pyx_k_gettattr[] = "gettattr";
static const char __pyx_k_linspace[] = "linspace";
static const char __pyx_k_qualname[] = "__qualname__";
static const char __pyx_k_to_frame[] = "to_frame";
static const char __pyx_k_LR___init[] = "LR.__init__";
static const char __pyx_k_TEST_SIZE[] = "TEST_SIZE";
static const char __pyx_k_bootstrap[] = "bootstrap";
static const char __pyx_k_criterion[] = "criterion";
static const char __pyx_k_max_depth[] = "max_depth";
static const char __pyx_k_metaclass[] = "__metaclass__";
static const char __pyx_k_models_py[] = "models.py";
static const char __pyx_k_oob_score[] = "oob_score";
static const char __pyx_k_subsample[] = "subsample";
static const char __pyx_k_GaussianNB[] = "GaussianNB";
static const char __pyx_k_HyperSpace[] = "HyperSpace";
static const char __pyx_k_Params_get[] = "Params.get";
static const char __pyx_k_Params_rfc[] = "Params.rfc";
static const char __pyx_k_warm_start[] = "warm_start";
static const char __pyx_k_BernoulliNB[] = "BernoulliNB";
static const char __pyx_k_Categorical[] = "Categorical";
static const char __pyx_k_Classifiers[] = "Classifiers";
static const char __pyx_k_extra_trees[] = "extra_trees";
static const char __pyx_k_sklearn_svm[] = "sklearn.svm";
static const char __pyx_k_MinMaxScaler[] = "MinMaxScaler";
static const char __pyx_k_bernoulli_nb[] = "bernoulli_nb";
static const char __pyx_k_class_weight[] = "class_weight";
static const char __pyx_k_max_features[] = "max_features";
static const char __pyx_k_n_estimators[] = "n_estimators";
static const char __pyx_k_random_state[] = "random_state";
static const char __pyx_k_sklearn_tree[] = "sklearn.tree";
static const char __pyx_k_MultinomialNB[] = "MultinomialNB";
static const char __pyx_k_Params___init[] = "Params.__init__";
static const char __pyx_k_decision_tree[] = "decision_tree";
static const char __pyx_k_fit_intercept[] = "fit_intercept";
static const char __pyx_k_learning_rate[] = "learning_rate";
static const char __pyx_k_xg_param_grid[] = "xg_param_grid";
static const char __pyx_k_HyperSpace_gbc[] = "HyperSpace.gbc";
static const char __pyx_k_HyperSpace_rfc[] = "HyperSpace.rfc";
static const char __pyx_k_StandardScaler[] = "StandardScaler";
static const char __pyx_k_max_leaf_nodes[] = "max_leaf_nodes";
static const char __pyx_k_GradientDescent[] = "GradientDescent";
static const char __pyx_k_HyperSpace_grid[] = "HyperSpace.grid";
static const char __pyx_k_sklearn_metrics[] = "sklearn.metrics";
static const char __pyx_k_HyperSpace_tfidf[] = "HyperSpace.tfidf";
static const char __pyx_k_min_samples_leaf[] = "min_samples_leaf";
static const char __pyx_k_sklearn_ensemble[] = "sklearn.ensemble";
static const char __pyx_k_HyperSpace___init[] = "HyperSpace.__init__";
static const char __pyx_k_LighGradientBoost[] = "LighGradientBoost";
static const char __pyx_k_Needs_Refactoring[] = " Needs Refactoring. ";
static const char __pyx_k_min_samples_split[] = "min_samples_split";
static const char __pyx_k_sklearn_neighbors[] = "sklearn.neighbors";
static const char __pyx_k_tfidf_hyperparams[] = "tfidf_hyperparams";
static const char __pyx_k_AdaBoostClassifier[] = "AdaBoostClassifier";
static const char __pyx_k_Classifiers___init[] = "Classifiers.__init__";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_mean_squared_error[] = "mean_squared_error";
static const char __pyx_k_min_impurity_split[] = "min_impurity_split";
static const char __pyx_k_reshape_cat_series[] = "reshape_cat_series";
static const char __pyx_k_GradientDescent_fit[] = "GradientDescent.fit";
static const char __pyx_k_sklearn_naive_bayes[] = "sklearn.naive_bayes";
static const char __pyx_k_BatchGradientDescent[] = "BatchGradientDescent";
static const char __pyx_k_KNeighborsClassifier[] = "KNeighborsClassifier";
static const char __pyx_k_sklearn_linear_model[] = "sklearn.linear_model";
static const char __pyx_k_clf__colsample_bytree[] = "clf__colsample_bytree";
static const char __pyx_k_sklearn_preprocessing[] = "sklearn.preprocessing";
static const char __pyx_k_svm_SVC_linear_kernel[] = "svm.SVC (linear kernel)";
static const char __pyx_k_DecisionTreeClassifier[] = "DecisionTreeClassifier";
static const char __pyx_k_GradientDescent___init[] = "GradientDescent.__init__";
static const char __pyx_k_RandomForestClassifier[] = "RandomForestClassifier";
static const char __pyx_k_GradientDescent_predict[] = "GradientDescent.predict";
static const char __pyx_k_update_hyperparam_range[] = "update_hyperparam_range";
static const char __pyx_k_BatchGradientDescent_fit[] = "BatchGradientDescent.fit";
static const char __pyx_k_min_weight_fraction_leaf[] = "min_weight_fraction_leaf";
static const char __pyx_k_GradientBoostingClassifier[] = "GradientBoostingClassifier";
static const char __pyx_k_LinearDiscriminantAnalysis[] = "LinearDiscriminantAnalysis";
static const char __pyx_k_BatchGradientDescent___init[] = "BatchGradientDescent.__init__";
static const char __pyx_k_PassiveAggressiveClassifier[] = "PassiveAggressiveClassifier";
static const char __pyx_k_BatchGradientDescent_predict[] = "BatchGradientDescent.predict";
static const char __pyx_k_QuadraticDiscriminantAnalysis[] = "QuadraticDiscriminantAnalysis";
static const char __pyx_k_sklearn_discriminant_analysis[] = "sklearn.discriminant_analysis";
static const char __pyx_k_Provides_default_parameters_for[] = " Provides default parameters for a given model. ";
static const char __pyx_k_Registry_class_providing_hyperp[] = " Registry class providing hyperparameter search space.\n    @TODO: Provide private method to update a grid param range. ";
static const char __pyx_k_GradientDescent_reshape_cat_seri[] = "GradientDescent.reshape_cat_series";
static const char __pyx_k_HyperSpace_update_hyperparam_ran[] = "HyperSpace.update_hyperparam_range";
static PyObject *__pyx_n_s_AdaBoostClassifier;
static PyObject *__pyx_n_u_AdaBoostClassifier;
static PyObject *__pyx_n_s_BatchGradientDescent;
static PyObject *__pyx_n_s_BatchGradientDescent___init;
static PyObject *__pyx_n_s_BatchGradientDescent_fit;
static PyObject *__pyx_n_s_BatchGradientDescent_predict;
static PyObject *__pyx_n_s_BernoulliNB;
static PyObject *__pyx_n_u_BernoulliNB;
static PyObject *__pyx_n_s_C;
static PyObject *__pyx_n_s_Categorical;
static PyObject *__pyx_n_s_Classifiers;
static PyObject *__pyx_n_s_Classifiers___init;
static PyObject *__pyx_n_s_DecisionTreeClassifier;
static PyObject *__pyx_kp_u_Epoch;
static PyObject *__pyx_n_s_GaussianNB;
static PyObject *__pyx_n_u_GaussianNB;
static PyObject *__pyx_n_s_GradientBoostingClassifier;
static PyObject *__pyx_n_u_GradientBoostingClassifier;
static PyObject *__pyx_n_s_GradientDescent;
static PyObject *__pyx_n_u_GradientDescent;
static PyObject *__pyx_n_s_GradientDescent___init;
static PyObject *__pyx_n_s_GradientDescent_fit;
static PyObject *__pyx_n_s_GradientDescent_predict;
static PyObject *__pyx_n_s_GradientDescent_reshape_cat_seri;
static PyObject *__pyx_n_s_HyperSpace;
static PyObject *__pyx_n_s_HyperSpace___init;
static PyObject *__pyx_n_s_HyperSpace_gbc;
static PyObject *__pyx_n_s_HyperSpace_grid;
static PyObject *__pyx_n_s_HyperSpace_rfc;
static PyObject *__pyx_n_s_HyperSpace_tfidf;
static PyObject *__pyx_n_s_HyperSpace_update_hyperparam_ran;
static PyObject *__pyx_n_s_KNeighborsClassifier;
static PyObject *__pyx_n_u_KNeighborsClassifier;
static PyObject *__pyx_n_s_LR;
static PyObject *__pyx_n_s_LR___init;
static PyObject *__pyx_n_u_LighGradientBoost;
static PyObject *__pyx_n_s_LinearDiscriminantAnalysis;
static PyObject *__pyx_n_u_LinearDiscriminantAnalysis;
static PyObject *__pyx_kp_u_Loss;
static PyObject *__pyx_n_s_MinMaxScaler;
static PyObject *__pyx_n_s_MultinomialNB;
static PyObject *__pyx_n_u_MultinomialNB;
static PyObject *__pyx_n_s_N;
static PyObject *__pyx_n_s_N_EST;
static PyObject *__pyx_kp_s_Needs_Refactoring;
static PyObject *__pyx_n_s_Params;
static PyObject *__pyx_n_s_Params___init;
static PyObject *__pyx_n_s_Params_get;
static PyObject *__pyx_n_s_Params_rfc;
static PyObject *__pyx_n_s_PassiveAggressiveClassifier;
static PyObject *__pyx_n_u_PassiveAggressiveClassifier;
static PyObject *__pyx_kp_s_Provides_default_parameters_for;
static PyObject *__pyx_n_s_QuadraticDiscriminantAnalysis;
static PyObject *__pyx_n_u_QuadraticDiscriminantAnalysis;
static PyObject *__pyx_n_s_RandomForestClassifier;
static PyObject *__pyx_n_u_RandomForestClassifier;
static PyObject *__pyx_kp_s_Registry_class_providing_hyperp;
static PyObject *__pyx_n_s_SEED;
static PyObject *__pyx_n_s_SVC;
static PyObject *__pyx_n_s_StandardScaler;
static PyObject *__pyx_n_s_T;
static PyObject *__pyx_n_s_TEST_SIZE;
static PyObject *__pyx_n_s_X;
static PyObject *__pyx_n_s_Xi;
static PyObject *__pyx_kp_u__4;
static PyObject *__pyx_kp_u__8;
static PyObject *__pyx_n_s_ada;
static PyObject *__pyx_n_u_ada;
static PyObject *__pyx_n_s_array;
static PyObject *__pyx_n_u_auto;
static PyObject *__pyx_n_s_b;
static PyObject *__pyx_n_u_bernoulli_nb;
static PyObject *__pyx_n_s_bnb;
static PyObject *__pyx_n_s_bootstrap;
static PyObject *__pyx_n_u_bootstrap;
static PyObject *__pyx_n_s_cat;
static PyObject *__pyx_n_u_cats;
static PyObject *__pyx_n_s_class_weight;
static PyObject *__pyx_n_s_clf;
static PyObject *__pyx_n_u_clf__colsample_bytree;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_codes;
static PyObject *__pyx_n_s_criterion;
static PyObject *__pyx_n_u_decision_tree;
static PyObject *__pyx_n_s_doc;
static PyObject *__pyx_n_s_dot;
static PyObject *__pyx_n_s_e;
static PyObject *__pyx_n_s_epochs;
static PyObject *__pyx_n_s_est;
static PyObject *__pyx_n_u_extra_trees;
static PyObject *__pyx_n_s_f;
static PyObject *__pyx_n_s_fit;
static PyObject *__pyx_n_s_fit_intercept;
static PyObject *__pyx_n_s_gbc;
static PyObject *__pyx_n_u_gbc;
static PyObject *__pyx_n_s_get;
static PyObject *__pyx_n_s_gettattr;
static PyObject *__pyx_n_u_gini;
static PyObject *__pyx_n_s_gnb;
static PyObject *__pyx_n_u_gnb;
static PyObject *__pyx_n_s_grid;
static PyObject *__pyx_n_s_high;
static PyObject *__pyx_n_s_history;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_init;
static PyObject *__pyx_n_s_kernel;
static PyObject *__pyx_n_s_knn;
static PyObject *__pyx_n_u_knn;
static PyObject *__pyx_n_s_lda;
static PyObject *__pyx_n_u_lda;
static PyObject *__pyx_n_s_learning_rate;
static PyObject *__pyx_n_u_learning_rate;
static PyObject *__pyx_n_u_lgbm;
static PyObject *__pyx_n_u_linear;
static PyObject *__pyx_n_s_linspace;
static PyObject *__pyx_n_s_loss;
static PyObject *__pyx_n_s_low;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_s_max_depth;
static PyObject *__pyx_n_u_max_depth;
static PyObject *__pyx_n_u_max_df;
static PyObject *__pyx_n_s_max_features;
static PyObject *__pyx_n_u_max_features;
static PyObject *__pyx_n_s_max_leaf_nodes;
static PyObject *__pyx_n_s_mean_squared_error;
static PyObject *__pyx_n_s_metaclass;
static PyObject *__pyx_n_s_min_impurity_split;
static PyObject *__pyx_n_s_min_samples_leaf;
static PyObject *__pyx_n_u_min_samples_leaf;
static PyObject *__pyx_n_s_min_samples_split;
static PyObject *__pyx_n_u_min_samples_split;
static PyObject *__pyx_n_s_min_weight_fraction_leaf;
static PyObject *__pyx_n_s_mnb;
static PyObject *__pyx_n_u_mnb;
static PyObject *__pyx_n_s_models;
static PyObject *__pyx_kp_s_models_py;
static PyObject *__pyx_n_s_module;
static PyObject *__pyx_n_s_n_estimators;
static PyObject *__pyx_n_u_n_estimators;
static PyObject *__pyx_n_s_n_jobs;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_np;
static PyObject *__pyx_n_s_num;
static PyObject *__pyx_n_s_numpy;
static PyObject *__pyx_n_s_object;
static PyObject *__pyx_n_s_oob_score;
static PyObject *__pyx_n_s_os;
static PyObject *__pyx_n_s_pandas;
static PyObject *__pyx_n_s_param;
static PyObject *__pyx_n_s_pav;
static PyObject *__pyx_n_u_pav;
static PyObject *__pyx_n_s_pd;
static PyObject *__pyx_n_s_pprint;
static PyObject *__pyx_n_s_predict;
static PyObject *__pyx_n_s_prepare;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_s_qda;
static PyObject *__pyx_n_u_qda;
static PyObject *__pyx_n_s_qualname;
static PyObject *__pyx_n_s_random_state;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_re;
static PyObject *__pyx_n_s_reshape;
static PyObject *__pyx_n_s_reshape_cat_series;
static PyObject *__pyx_n_s_rfc;
static PyObject *__pyx_n_u_rfc;
static PyObject *__pyx_n_s_self;
static PyObject *__pyx_n_s_sgd;
static PyObject *__pyx_n_u_sgd;
static PyObject *__pyx_n_s_shape;
static PyObject *__pyx_n_s_sklearn;
static PyObject *__pyx_n_s_sklearn_discriminant_analysis;
static PyObject *__pyx_n_s_sklearn_ensemble;
static PyObject *__pyx_n_s_sklearn_linear_model;
static PyObject *__pyx_n_s_sklearn_metrics;
static PyObject *__pyx_n_s_sklearn_naive_bayes;
static PyObject *__pyx_n_s_sklearn_neighbors;
static PyObject *__pyx_n_s_sklearn_preprocessing;
static PyObject *__pyx_n_s_sklearn_svm;
static PyObject *__pyx_n_s_sklearn_tree;
static PyObject *__pyx_n_u_sqrt;
static PyObject *__pyx_n_s_start;
static PyObject *__pyx_n_s_stop;
static PyObject *__pyx_n_u_subsample;
static PyObject *__pyx_n_s_sum;
static PyObject *__pyx_n_s_svm;
static PyObject *__pyx_n_u_svm;
static PyObject *__pyx_kp_u_svm_SVC;
static PyObject *__pyx_kp_u_svm_SVC_linear_kernel;
static PyObject *__pyx_n_s_svml;
static PyObject *__pyx_n_u_svml;
static PyObject *__pyx_n_s_target;
static PyObject *__pyx_n_u_target;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_tfidf;
static PyObject *__pyx_n_s_tfidf_hyperparams;
static PyObject *__pyx_n_s_to_frame;
static PyObject *__pyx_n_s_update_hyperparam_range;
static PyObject *__pyx_n_s_values;
static PyObject *__pyx_n_s_verbose;
static PyObject *__pyx_n_s_w;
static PyObject *__pyx_n_s_warm_start;
static PyObject *__pyx_n_s_x;
static PyObject *__pyx_n_s_xg_param_grid;
static PyObject *__pyx_n_u_xgb;
static PyObject *__pyx_n_u_xgbp;
static PyObject *__pyx_n_s_y;
static PyObject *__pyx_n_s_yi;
static PyObject *__pyx_pf_6models_11Classifiers___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_6models_10HyperSpace___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_6models_10HyperSpace_2grid(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_est); /* proto */
static PyObject *__pyx_pf_6models_10HyperSpace_4update_hyperparam_range(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_est, CYTHON_UNUSED PyObject *__pyx_v_param, CYTHON_UNUSED PyObject *__pyx_v_high, CYTHON_UNUSED PyObject *__pyx_v_low); /* proto */
static PyObject *__pyx_pf_6models_10HyperSpace_6tfidf(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_6models_10HyperSpace_8rfc(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_6models_10HyperSpace_10gbc(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_6models_6Params___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_6models_6Params_2get(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_est); /* proto */
static PyObject *__pyx_pf_6models_6Params_4rfc(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_6models_15GradientDescent___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_learning_rate); /* proto */
static PyObject *__pyx_pf_6models_15GradientDescent_2reshape_cat_series(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_6models_15GradientDescent_4fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y, PyObject *__pyx_v_epochs); /* proto */
static PyObject *__pyx_pf_6models_15GradientDescent_6predict(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_6models_20BatchGradientDescent___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_learning_rate); /* proto */
static PyObject *__pyx_pf_6models_20BatchGradientDescent_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y, PyObject *__pyx_v_epochs); /* proto */
static PyObject *__pyx_pf_6models_20BatchGradientDescent_4predict(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_6models_2LR___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_float_0_0;
static PyObject *__pyx_float_0_2;
static PyObject *__pyx_float_0_5;
static PyObject *__pyx_float_0_7;
static PyObject *__pyx_float_0_9;
static PyObject *__pyx_float_1_0;
static PyObject *__pyx_float_0_01;
static PyObject *__pyx_float_0_02;
static PyObject *__pyx_float_0_03;
static PyObject *__pyx_float_0_95;
static PyObject *__pyx_float_10_0;
static PyObject *__pyx_float_1eneg_07;
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_2;
static PyObject *__pyx_int_4;
static PyObject *__pyx_int_5;
static PyObject *__pyx_int_6;
static PyObject *__pyx_int_8;
static PyObject *__pyx_int_10;
static PyObject *__pyx_int_11;
static PyObject *__pyx_int_42;
static PyObject *__pyx_int_50;
static PyObject *__pyx_int_100;
static PyObject *__pyx_int_110;
static PyObject *__pyx_int_200;
static PyObject *__pyx_int_500;
static PyObject *__pyx_int_1000;
static PyObject *__pyx_int_2000;
static PyObject *__pyx_int_neg_1;
static PyObject *__pyx_int_neg_2;
static PyObject *__pyx_tuple_;
static PyObject *__pyx_slice__3;
static PyObject *__pyx_tuple__2;
static PyObject *__pyx_tuple__5;
static PyObject *__pyx_tuple__6;
static PyObject *__pyx_tuple__9;
static PyObject *__pyx_tuple__11;
static PyObject *__pyx_tuple__13;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__17;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__21;
static PyObject *__pyx_tuple__22;
static PyObject *__pyx_tuple__24;
static PyObject *__pyx_tuple__26;
static PyObject *__pyx_tuple__28;
static PyObject *__pyx_tuple__29;
static PyObject *__pyx_tuple__31;
static PyObject *__pyx_tuple__32;
static PyObject *__pyx_tuple__34;
static PyObject *__pyx_tuple__36;
static PyObject *__pyx_tuple__37;
static PyObject *__pyx_tuple__39;
static PyObject *__pyx_tuple__41;
static PyObject *__pyx_tuple__42;
static PyObject *__pyx_tuple__44;
static PyObject *__pyx_tuple__45;
static PyObject *__pyx_tuple__47;
static PyObject *__pyx_codeobj__7;
static PyObject *__pyx_codeobj__10;
static PyObject *__pyx_codeobj__12;
static PyObject *__pyx_codeobj__14;
static PyObject *__pyx_codeobj__16;
static PyObject *__pyx_codeobj__18;
static PyObject *__pyx_codeobj__20;
static PyObject *__pyx_codeobj__23;
static PyObject *__pyx_codeobj__25;
static PyObject *__pyx_codeobj__27;
static PyObject *__pyx_codeobj__30;
static PyObject *__pyx_codeobj__33;
static PyObject *__pyx_codeobj__35;
static PyObject *__pyx_codeobj__38;
static PyObject *__pyx_codeobj__40;
static PyObject *__pyx_codeobj__43;
static PyObject *__pyx_codeobj__46;
static PyObject *__pyx_codeobj__48;
/* Late includes */

/* "models.py":31
 * # TODO: Refactor
 * class Classifiers(object):
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 *         #self.adt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1), n_estimators=N_EST),
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_11Classifiers_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_6models_11Classifiers_1__init__ = {"__init__", (PyCFunction)__pyx_pw_6models_11Classifiers_1__init__, METH_O, 0};
static PyObject *__pyx_pw_6models_11Classifiers_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_6models_11Classifiers___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_11Classifiers___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "models.py":32
 * class Classifiers(object):
 *     def __init__(self):
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)             # <<<<<<<<<<<<<<
 *         #self.adt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1), n_estimators=N_EST),
 *         self.bnb = BernoulliNB()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_AdaBoostClassifier); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_N_EST); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_n_estimators, __pyx_t_3) < 0) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_learning_rate, __pyx_int_1) < 0) __PYX_ERR(0, 32, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_ada, __pyx_t_3) < 0) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":34
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 *         #self.adt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1), n_estimators=N_EST),
 *         self.bnb = BernoulliNB()             # <<<<<<<<<<<<<<
 *         self.gbc = GradientBoostingClassifier(n_estimators=2000)
 *         self.gnb = GaussianNB()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BernoulliNB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_bnb, __pyx_t_3) < 0) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":35
 *         #self.adt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1), n_estimators=N_EST),
 *         self.bnb = BernoulliNB()
 *         self.gbc = GradientBoostingClassifier(n_estimators=2000)             # <<<<<<<<<<<<<<
 *         self.gnb = GaussianNB()
 *         self.knn = KNeighborsClassifier()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_GradientBoostingClassifier); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_n_estimators, __pyx_int_2000) < 0) __PYX_ERR(0, 35, __pyx_L1_error)
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_gbc, __pyx_t_1) < 0) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":36
 *         self.bnb = BernoulliNB()
 *         self.gbc = GradientBoostingClassifier(n_estimators=2000)
 *         self.gnb = GaussianNB()             # <<<<<<<<<<<<<<
 *         self.knn = KNeighborsClassifier()
 *         self.lda = LinearDiscriminantAnalysis()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_GaussianNB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_gnb, __pyx_t_1) < 0) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":37
 *         self.gbc = GradientBoostingClassifier(n_estimators=2000)
 *         self.gnb = GaussianNB()
 *         self.knn = KNeighborsClassifier()             # <<<<<<<<<<<<<<
 *         self.lda = LinearDiscriminantAnalysis()
 *         self.mnb = MultinomialNB()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_KNeighborsClassifier); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 37, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 37, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_knn, __pyx_t_1) < 0) __PYX_ERR(0, 37, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":38
 *         self.gnb = GaussianNB()
 *         self.knn = KNeighborsClassifier()
 *         self.lda = LinearDiscriminantAnalysis()             # <<<<<<<<<<<<<<
 *         self.mnb = MultinomialNB()
 *         self.pav = PassiveAggressiveClassifier()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_LinearDiscriminantAnalysis); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_lda, __pyx_t_1) < 0) __PYX_ERR(0, 38, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":39
 *         self.knn = KNeighborsClassifier()
 *         self.lda = LinearDiscriminantAnalysis()
 *         self.mnb = MultinomialNB()             # <<<<<<<<<<<<<<
 *         self.pav = PassiveAggressiveClassifier()
 *         self.qda = QuadraticDiscriminantAnalysis()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_MultinomialNB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_mnb, __pyx_t_1) < 0) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":40
 *         self.lda = LinearDiscriminantAnalysis()
 *         self.mnb = MultinomialNB()
 *         self.pav = PassiveAggressiveClassifier()             # <<<<<<<<<<<<<<
 *         self.qda = QuadraticDiscriminantAnalysis()
 *         self.rfc = RandomForestClassifier(warm_start=False, n_estimators=1000, min_samples_split=2, min_samples_leaf=1, max_features='auto', max_depth=50, bootstrap=False)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_PassiveAggressiveClassifier); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_pav, __pyx_t_1) < 0) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":41
 *         self.mnb = MultinomialNB()
 *         self.pav = PassiveAggressiveClassifier()
 *         self.qda = QuadraticDiscriminantAnalysis()             # <<<<<<<<<<<<<<
 *         self.rfc = RandomForestClassifier(warm_start=False, n_estimators=1000, min_samples_split=2, min_samples_leaf=1, max_features='auto', max_depth=50, bootstrap=False)
 *         self.svm = svm.SVC(random_state=SEED)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_QuadraticDiscriminantAnalysis); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_qda, __pyx_t_1) < 0) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":42
 *         self.pav = PassiveAggressiveClassifier()
 *         self.qda = QuadraticDiscriminantAnalysis()
 *         self.rfc = RandomForestClassifier(warm_start=False, n_estimators=1000, min_samples_split=2, min_samples_leaf=1, max_features='auto', max_depth=50, bootstrap=False)             # <<<<<<<<<<<<<<
 *         self.svm = svm.SVC(random_state=SEED)
 *         self.svml = svm.SVC(kernel='linear', C = 1.0, random_state=SEED)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_RandomForestClassifier); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_warm_start, Py_False) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_n_estimators, __pyx_int_1000) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_min_samples_split, __pyx_int_2) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_min_samples_leaf, __pyx_int_1) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_max_features, __pyx_n_u_auto) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_max_depth, __pyx_int_50) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_bootstrap, Py_False) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_rfc, __pyx_t_3) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":43
 *         self.qda = QuadraticDiscriminantAnalysis()
 *         self.rfc = RandomForestClassifier(warm_start=False, n_estimators=1000, min_samples_split=2, min_samples_leaf=1, max_features='auto', max_depth=50, bootstrap=False)
 *         self.svm = svm.SVC(random_state=SEED)             # <<<<<<<<<<<<<<
 *         self.svml = svm.SVC(kernel='linear', C = 1.0, random_state=SEED)
 *         self.sgd = GradientDescent()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_svm); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_SVC); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_SEED); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_random_state, __pyx_t_1) < 0) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_svm, __pyx_t_1) < 0) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":44
 *         self.rfc = RandomForestClassifier(warm_start=False, n_estimators=1000, min_samples_split=2, min_samples_leaf=1, max_features='auto', max_depth=50, bootstrap=False)
 *         self.svm = svm.SVC(random_state=SEED)
 *         self.svml = svm.SVC(kernel='linear', C = 1.0, random_state=SEED)             # <<<<<<<<<<<<<<
 *         self.sgd = GradientDescent()
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_svm); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_SVC); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_kernel, __pyx_n_u_linear) < 0) __PYX_ERR(0, 44, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_C, __pyx_float_1_0) < 0) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_SEED); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_random_state, __pyx_t_2) < 0) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_svml, __pyx_t_2) < 0) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":45
 *         self.svm = svm.SVC(random_state=SEED)
 *         self.svml = svm.SVC(kernel='linear', C = 1.0, random_state=SEED)
 *         self.sgd = GradientDescent()             # <<<<<<<<<<<<<<
 *
 *     clf = {
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_GradientDescent); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_sgd, __pyx_t_2) < 0) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":31
 * # TODO: Refactor
 * class Classifiers(object):
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 *         #self.adt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1), n_estimators=N_EST),
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("models.Classifiers.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":72
 *     """ Registry class providing hyperparameter search space.
 *     @TODO: Provide private method to update a grid param range. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_10HyperSpace_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_6models_10HyperSpace_1__init__ = {"__init__", (PyCFunction)__pyx_pw_6models_10HyperSpace_1__init__, METH_O, 0};
static PyObject *__pyx_pw_6models_10HyperSpace_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_6models_10HyperSpace___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_10HyperSpace___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":75
 *         pass
 *
 *     def grid(self, est):             # <<<<<<<<<<<<<<
 *         return getattr(self, est)()
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_10HyperSpace_3grid(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_10HyperSpace_3grid = {"grid", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_10HyperSpace_3grid, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_10HyperSpace_3grid(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_est = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("grid (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_est,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_est)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("grid", 1, 2, 2, 1); __PYX_ERR(0, 75, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "grid") < 0)) __PYX_ERR(0, 75, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_est = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("grid", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 75, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.HyperSpace.grid", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_10HyperSpace_2grid(__pyx_self, __pyx_v_self, __pyx_v_est);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_10HyperSpace_2grid(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_est) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("grid", 0);

  /* "models.py":76
 *
 *     def grid(self, est):
 *         return getattr(self, est)()             # <<<<<<<<<<<<<<
 *
 *     def update_hyperparam_range(self, est, param, high, low):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_GetAttr(__pyx_v_self, __pyx_v_est); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "models.py":75
 *         pass
 *
 *     def grid(self, est):             # <<<<<<<<<<<<<<
 *         return getattr(self, est)()
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("models.HyperSpace.grid", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":78
 *         return getattr(self, est)()
 *
 *     def update_hyperparam_range(self, est, param, high, low):             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_10HyperSpace_5update_hyperparam_range(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_10HyperSpace_5update_hyperparam_range = {"update_hyperparam_range", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_10HyperSpace_5update_hyperparam_range, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_10HyperSpace_5update_hyperparam_range(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_est = 0;
  CYTHON_UNUSED PyObject *__pyx_v_param = 0;
  CYTHON_UNUSED PyObject *__pyx_v_high = 0;
  CYTHON_UNUSED PyObject *__pyx_v_low = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("update_hyperparam_range (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_est,&__pyx_n_s_param,&__pyx_n_s_high,&__pyx_n_s_low,0};
    PyObject* values[5] = {0,0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
        CYTHON_FALLTHROUGH;
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_est)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("update_hyperparam_range", 1, 5, 5, 1); __PYX_ERR(0, 78, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_param)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("update_hyperparam_range", 1, 5, 5, 2); __PYX_ERR(0, 78, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_high)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("update_hyperparam_range", 1, 5, 5, 3); __PYX_ERR(0, 78, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  4:
        if (likely((values[4] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_low)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("update_hyperparam_range", 1, 5, 5, 4); __PYX_ERR(0, 78, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "update_hyperparam_range") < 0)) __PYX_ERR(0, 78, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 5) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
      values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
    }
    __pyx_v_self = values[0];
    __pyx_v_est = values[1];
    __pyx_v_param = values[2];
    __pyx_v_high = values[3];
    __pyx_v_low = values[4];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("update_hyperparam_range", 1, 5, 5, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 78, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.HyperSpace.update_hyperparam_range", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_10HyperSpace_4update_hyperparam_range(__pyx_self, __pyx_v_self, __pyx_v_est, __pyx_v_param, __pyx_v_high, __pyx_v_low);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_10HyperSpace_4update_hyperparam_range(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_est, CYTHON_UNUSED PyObject *__pyx_v_param, CYTHON_UNUSED PyObject *__pyx_v_high, CYTHON_UNUSED PyObject *__pyx_v_low) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("update_hyperparam_range", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":81
 *         pass
 *
 *     def tfidf(self):             # <<<<<<<<<<<<<<
 *
 *         tfidf_hyperparams = {
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_10HyperSpace_7tfidf(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_6models_10HyperSpace_7tfidf = {"tfidf", (PyCFunction)__pyx_pw_6models_10HyperSpace_7tfidf, METH_O, 0};
static PyObject *__pyx_pw_6models_10HyperSpace_7tfidf(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("tfidf (wrapper)", 0);
  __pyx_r = __pyx_pf_6models_10HyperSpace_6tfidf(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_10HyperSpace_6tfidf(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_v_tfidf_hyperparams = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("tfidf", 0);

  /* "models.py":85
 *         tfidf_hyperparams = {
 *             #'both__tvector__tf__vec__max_df':   [0.9, 0.95],
 *             'max_df':   [0.9, 0.95],             # <<<<<<<<<<<<<<
 *             #'features__raw__tfidf__max_df': [0.9, 0.95],
 *             #'features__raw__tfidf__ngram_range': [(1,1), (1,2)],
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_float_0_9);
  __Pyx_GIVEREF(__pyx_float_0_9);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_float_0_9);
  __Pyx_INCREF(__pyx_float_0_95);
  __Pyx_GIVEREF(__pyx_float_0_95);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_float_0_95);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_max_df, __pyx_t_2) < 0) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_tfidf_hyperparams = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":92
 *             }
 *
 *         return tfidf_hyperparams             # <<<<<<<<<<<<<<
 *
 *     def rfc(self):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_tfidf_hyperparams);
  __pyx_r = __pyx_v_tfidf_hyperparams;
  goto __pyx_L0;

  /* "models.py":81
 *         pass
 *
 *     def tfidf(self):             # <<<<<<<<<<<<<<
 *
 *         tfidf_hyperparams = {
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("models.HyperSpace.tfidf", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_tfidf_hyperparams);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":94
 *         return tfidf_hyperparams
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_10HyperSpace_9rfc(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_6models_10HyperSpace_9rfc = {"rfc", (PyCFunction)__pyx_pw_6models_10HyperSpace_9rfc, METH_O, 0};
static PyObject *__pyx_pw_6models_10HyperSpace_9rfc(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("rfc (wrapper)", 0);
  __pyx_r = __pyx_pf_6models_10HyperSpace_8rfc(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_10HyperSpace_8rfc(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_v_n_estimators = NULL;
  PyObject *__pyx_v_max_features = NULL;
  PyObject *__pyx_v_max_depth = NULL;
  PyObject *__pyx_v_min_samples_split = NULL;
  PyObject *__pyx_v_min_samples_leaf = NULL;
  PyObject *__pyx_v_bootstrap = NULL;
  PyObject *__pyx_v_grid = NULL;
  PyObject *__pyx_7genexpr__pyx_v_x = NULL;
  PyObject *__pyx_8genexpr1__pyx_v_x = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  Py_ssize_t __pyx_t_5;
  PyObject *(*__pyx_t_6)(PyObject *);
  int __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("rfc", 0);

  /* "models.py":96
 *     def rfc(self):
 *
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]             # <<<<<<<<<<<<<<
 *         max_features = ['auto', 'sqrt']
 *         max_depth = [int(x) for x in np.linspace(10, 110, num = 11)]
 */
  { /* enter inner scope */
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 96, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_np); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 96, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_linspace); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 96, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 96, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_start, __pyx_int_200) < 0) __PYX_ERR(0, 96, __pyx_L5_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_stop, __pyx_int_2000) < 0) __PYX_ERR(0, 96, __pyx_L5_error)
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_num, __pyx_int_10) < 0) __PYX_ERR(0, 96, __pyx_L5_error)
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 96, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (likely(PyList_CheckExact(__pyx_t_4)) || PyTuple_CheckExact(__pyx_t_4)) {
      __pyx_t_2 = __pyx_t_4; __Pyx_INCREF(__pyx_t_2); __pyx_t_5 = 0;
      __pyx_t_6 = NULL;
    } else {
      __pyx_t_5 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 96, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_6 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 96, __pyx_L5_error)
    }
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    for (;;) {
      if (likely(!__pyx_t_6)) {
        if (likely(PyList_CheckExact(__pyx_t_2))) {
          if (__pyx_t_5 >= PyList_GET_SIZE(__pyx_t_2)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_4 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_5); __Pyx_INCREF(__pyx_t_4); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 96, __pyx_L5_error)
          #else
          __pyx_t_4 = PySequence_ITEM(__pyx_t_2, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 96, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_4);
          #endif
        } else {
          if (__pyx_t_5 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_5); __Pyx_INCREF(__pyx_t_4); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 96, __pyx_L5_error)
          #else
          __pyx_t_4 = PySequence_ITEM(__pyx_t_2, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 96, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_4);
          #endif
        }
      } else {
        __pyx_t_4 = __pyx_t_6(__pyx_t_2);
        if (unlikely(!__pyx_t_4)) {
          PyObject* exc_type = PyErr_Occurred();
          if (exc_type) {
            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
            else __PYX_ERR(0, 96, __pyx_L5_error)
          }
          break;
        }
        __Pyx_GOTREF(__pyx_t_4);
      }
      __Pyx_XDECREF_SET(__pyx_7genexpr__pyx_v_x, __pyx_t_4);
      __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_PyNumber_Int(__pyx_7genexpr__pyx_v_x); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 96, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_t_4))) __PYX_ERR(0, 96, __pyx_L5_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_7genexpr__pyx_v_x); __pyx_7genexpr__pyx_v_x = 0;
    goto __pyx_L8_exit_scope;
    __pyx_L5_error:;
    __Pyx_XDECREF(__pyx_7genexpr__pyx_v_x); __pyx_7genexpr__pyx_v_x = 0;
    goto __pyx_L1_error;
    __pyx_L8_exit_scope:;
  } /* exit inner scope */
  __pyx_v_n_estimators = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":97
 *
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]
 *         max_features = ['auto', 'sqrt']             # <<<<<<<<<<<<<<
 *         max_depth = [int(x) for x in np.linspace(10, 110, num = 11)]
 *         max_depth.append(None)
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_auto);
  __Pyx_GIVEREF(__pyx_n_u_auto);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_auto);
  __Pyx_INCREF(__pyx_n_u_sqrt);
  __Pyx_GIVEREF(__pyx_n_u_sqrt);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_sqrt);
  __pyx_v_max_features = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":98
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]
 *         max_features = ['auto', 'sqrt']
 *         max_depth = [int(x) for x in np.linspace(10, 110, num = 11)]             # <<<<<<<<<<<<<<
 *         max_depth.append(None)
 *         min_samples_split = [2, 5, 10]
 */
  { /* enter inner scope */
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 98, __pyx_L11_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_np); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 98, __pyx_L11_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_linspace); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 98, __pyx_L11_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 98, __pyx_L11_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_num, __pyx_int_11) < 0) __PYX_ERR(0, 98, __pyx_L11_error)
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_tuple_, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 98, __pyx_L11_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (likely(PyList_CheckExact(__pyx_t_3)) || PyTuple_CheckExact(__pyx_t_3)) {
      __pyx_t_2 = __pyx_t_3; __Pyx_INCREF(__pyx_t_2); __pyx_t_5 = 0;
      __pyx_t_6 = NULL;
    } else {
      __pyx_t_5 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 98, __pyx_L11_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_6 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 98, __pyx_L11_error)
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    for (;;) {
      if (likely(!__pyx_t_6)) {
        if (likely(PyList_CheckExact(__pyx_t_2))) {
          if (__pyx_t_5 >= PyList_GET_SIZE(__pyx_t_2)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_3 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_5); __Pyx_INCREF(__pyx_t_3); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 98, __pyx_L11_error)
          #else
          __pyx_t_3 = PySequence_ITEM(__pyx_t_2, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 98, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_3);
          #endif
        } else {
          if (__pyx_t_5 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_5); __Pyx_INCREF(__pyx_t_3); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 98, __pyx_L11_error)
          #else
          __pyx_t_3 = PySequence_ITEM(__pyx_t_2, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 98, __pyx_L11_error)
          __Pyx_GOTREF(__pyx_t_3);
          #endif
        }
      } else {
        __pyx_t_3 = __pyx_t_6(__pyx_t_2);
        if (unlikely(!__pyx_t_3)) {
          PyObject* exc_type = PyErr_Occurred();
          if (exc_type) {
            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
            else __PYX_ERR(0, 98, __pyx_L11_error)
          }
          break;
        }
        __Pyx_GOTREF(__pyx_t_3);
      }
      __Pyx_XDECREF_SET(__pyx_8genexpr1__pyx_v_x, __pyx_t_3);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyNumber_Int(__pyx_8genexpr1__pyx_v_x); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 98, __pyx_L11_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_t_3))) __PYX_ERR(0, 98, __pyx_L11_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x); __pyx_8genexpr1__pyx_v_x = 0;
    goto __pyx_L14_exit_scope;
    __pyx_L11_error:;
    __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x); __pyx_8genexpr1__pyx_v_x = 0;
    goto __pyx_L1_error;
    __pyx_L14_exit_scope:;
  } /* exit inner scope */
  __pyx_v_max_depth = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":99
 *         max_features = ['auto', 'sqrt']
 *         max_depth = [int(x) for x in np.linspace(10, 110, num = 11)]
 *         max_depth.append(None)             # <<<<<<<<<<<<<<
 *         min_samples_split = [2, 5, 10]
 *         min_samples_leaf = [1, 2, 4]
 */
  __pyx_t_7 = __Pyx_PyList_Append(__pyx_v_max_depth, Py_None); if (unlikely(__pyx_t_7 == ((int)-1))) __PYX_ERR(0, 99, __pyx_L1_error)

  /* "models.py":100
 *         max_depth = [int(x) for x in np.linspace(10, 110, num = 11)]
 *         max_depth.append(None)
 *         min_samples_split = [2, 5, 10]             # <<<<<<<<<<<<<<
 *         min_samples_leaf = [1, 2, 4]
 *         bootstrap = [True, False]
 */
  __pyx_t_1 = PyList_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_2);
  __Pyx_GIVEREF(__pyx_int_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_2);
  __Pyx_INCREF(__pyx_int_5);
  __Pyx_GIVEREF(__pyx_int_5);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_5);
  __Pyx_INCREF(__pyx_int_10);
  __Pyx_GIVEREF(__pyx_int_10);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_int_10);
  __pyx_v_min_samples_split = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":101
 *         max_depth.append(None)
 *         min_samples_split = [2, 5, 10]
 *         min_samples_leaf = [1, 2, 4]             # <<<<<<<<<<<<<<
 *         bootstrap = [True, False]
 *
 */
  __pyx_t_1 = PyList_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 101, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_1);
  __Pyx_GIVEREF(__pyx_int_1);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_int_1);
  __Pyx_INCREF(__pyx_int_2);
  __Pyx_GIVEREF(__pyx_int_2);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_int_2);
  __Pyx_INCREF(__pyx_int_4);
  __Pyx_GIVEREF(__pyx_int_4);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_int_4);
  __pyx_v_min_samples_leaf = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":102
 *         min_samples_split = [2, 5, 10]
 *         min_samples_leaf = [1, 2, 4]
 *         bootstrap = [True, False]             # <<<<<<<<<<<<<<
 *
 *         grid = {'n_estimators': n_estimators,
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(Py_True);
  __Pyx_GIVEREF(Py_True);
  PyList_SET_ITEM(__pyx_t_1, 0, Py_True);
  __Pyx_INCREF(Py_False);
  __Pyx_GIVEREF(Py_False);
  PyList_SET_ITEM(__pyx_t_1, 1, Py_False);
  __pyx_v_bootstrap = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":104
 *         bootstrap = [True, False]
 *
 *         grid = {'n_estimators': n_estimators,             # <<<<<<<<<<<<<<
 *            'max_features': max_features,
 *            'max_depth': max_depth,
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 104, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_n_estimators, __pyx_v_n_estimators) < 0) __PYX_ERR(0, 104, __pyx_L1_error)

  /* "models.py":105
 *
 *         grid = {'n_estimators': n_estimators,
 *            'max_features': max_features,             # <<<<<<<<<<<<<<
 *            'max_depth': max_depth,
 *            'min_samples_split': min_samples_split,
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_max_features, __pyx_v_max_features) < 0) __PYX_ERR(0, 104, __pyx_L1_error)

  /* "models.py":106
 *         grid = {'n_estimators': n_estimators,
 *            'max_features': max_features,
 *            'max_depth': max_depth,             # <<<<<<<<<<<<<<
 *            'min_samples_split': min_samples_split,
 *            'min_samples_leaf': min_samples_leaf,
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_max_depth, __pyx_v_max_depth) < 0) __PYX_ERR(0, 104, __pyx_L1_error)

  /* "models.py":107
 *            'max_features': max_features,
 *            'max_depth': max_depth,
 *            'min_samples_split': min_samples_split,             # <<<<<<<<<<<<<<
 *            'min_samples_leaf': min_samples_leaf,
 *            'bootstrap': bootstrap}
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_min_samples_split, __pyx_v_min_samples_split) < 0) __PYX_ERR(0, 104, __pyx_L1_error)

  /* "models.py":108
 *            'max_depth': max_depth,
 *            'min_samples_split': min_samples_split,
 *            'min_samples_leaf': min_samples_leaf,             # <<<<<<<<<<<<<<
 *            'bootstrap': bootstrap}
 *
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_min_samples_leaf, __pyx_v_min_samples_leaf) < 0) __PYX_ERR(0, 104, __pyx_L1_error)

  /* "models.py":109
 *            'min_samples_split': min_samples_split,
 *            'min_samples_leaf': min_samples_leaf,
 *            'bootstrap': bootstrap}             # <<<<<<<<<<<<<<
 *
 *         return grid
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_bootstrap, __pyx_v_bootstrap) < 0) __PYX_ERR(0, 104, __pyx_L1_error)
  __pyx_v_grid = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":111
 *            'bootstrap': bootstrap}
 *
 *         return grid             # <<<<<<<<<<<<<<
 *         """
 *         {'bootstrap': [True, False],
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_grid);
  __pyx_r = __pyx_v_grid;
  goto __pyx_L0;

  /* "models.py":94
 *         return tfidf_hyperparams
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("models.HyperSpace.rfc", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_n_estimators);
  __Pyx_XDECREF(__pyx_v_max_features);
  __Pyx_XDECREF(__pyx_v_max_depth);
  __Pyx_XDECREF(__pyx_v_min_samples_split);
  __Pyx_XDECREF(__pyx_v_min_samples_leaf);
  __Pyx_XDECREF(__pyx_v_bootstrap);
  __Pyx_XDECREF(__pyx_v_grid);
  __Pyx_XDECREF(__pyx_7genexpr__pyx_v_x);
  __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":121
 *         """
 *
 *     def gbc(self):             # <<<<<<<<<<<<<<
 *         grid = {'learning_rate': [0.01,0.02,0.03],
 *             'subsample'    : [0.9, 0.5, 0.2],
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_10HyperSpace_11gbc(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_6models_10HyperSpace_11gbc = {"gbc", (PyCFunction)__pyx_pw_6models_10HyperSpace_11gbc, METH_O, 0};
static PyObject *__pyx_pw_6models_10HyperSpace_11gbc(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("gbc (wrapper)", 0);
  __pyx_r = __pyx_pf_6models_10HyperSpace_10gbc(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_10HyperSpace_10gbc(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_v_grid = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("gbc", 0);

  /* "models.py":122
 *
 *     def gbc(self):
 *         grid = {'learning_rate': [0.01,0.02,0.03],             # <<<<<<<<<<<<<<
 *             'subsample'    : [0.9, 0.5, 0.2],
 *             'n_estimators' : [100,500,1000],
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_float_0_01);
  __Pyx_GIVEREF(__pyx_float_0_01);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_float_0_01);
  __Pyx_INCREF(__pyx_float_0_02);
  __Pyx_GIVEREF(__pyx_float_0_02);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_float_0_02);
  __Pyx_INCREF(__pyx_float_0_03);
  __Pyx_GIVEREF(__pyx_float_0_03);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_float_0_03);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_learning_rate, __pyx_t_2) < 0) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":123
 *     def gbc(self):
 *         grid = {'learning_rate': [0.01,0.02,0.03],
 *             'subsample'    : [0.9, 0.5, 0.2],             # <<<<<<<<<<<<<<
 *             'n_estimators' : [100,500,1000],
 *             'max_depth'    : [4,6,8]
 */
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 123, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_float_0_9);
  __Pyx_GIVEREF(__pyx_float_0_9);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_float_0_9);
  __Pyx_INCREF(__pyx_float_0_5);
  __Pyx_GIVEREF(__pyx_float_0_5);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_float_0_5);
  __Pyx_INCREF(__pyx_float_0_2);
  __Pyx_GIVEREF(__pyx_float_0_2);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_float_0_2);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_subsample, __pyx_t_2) < 0) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":124
 *         grid = {'learning_rate': [0.01,0.02,0.03],
 *             'subsample'    : [0.9, 0.5, 0.2],
 *             'n_estimators' : [100,500,1000],             # <<<<<<<<<<<<<<
 *             'max_depth'    : [4,6,8]
 *             }
 */
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 124, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_int_100);
  __Pyx_GIVEREF(__pyx_int_100);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_int_100);
  __Pyx_INCREF(__pyx_int_500);
  __Pyx_GIVEREF(__pyx_int_500);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_int_500);
  __Pyx_INCREF(__pyx_int_1000);
  __Pyx_GIVEREF(__pyx_int_1000);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_int_1000);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_n_estimators, __pyx_t_2) < 0) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":125
 *             'subsample'    : [0.9, 0.5, 0.2],
 *             'n_estimators' : [100,500,1000],
 *             'max_depth'    : [4,6,8]             # <<<<<<<<<<<<<<
 *             }
 *
 */
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_int_4);
  __Pyx_GIVEREF(__pyx_int_4);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_int_4);
  __Pyx_INCREF(__pyx_int_6);
  __Pyx_GIVEREF(__pyx_int_6);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_int_6);
  __Pyx_INCREF(__pyx_int_8);
  __Pyx_GIVEREF(__pyx_int_8);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_int_8);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_max_depth, __pyx_t_2) < 0) __PYX_ERR(0, 122, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_grid = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":128
 *             }
 *
 *         return grid             # <<<<<<<<<<<<<<
 *         """
 *         {'ccp_alpha': 0.0,
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_grid);
  __pyx_r = __pyx_v_grid;
  goto __pyx_L0;

  /* "models.py":121
 *         """
 *
 *     def gbc(self):             # <<<<<<<<<<<<<<
 *         grid = {'learning_rate': [0.01,0.02,0.03],
 *             'subsample'    : [0.9, 0.5, 0.2],
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("models.HyperSpace.gbc", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_grid);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":156
 * class Params(object):
 *     """ Provides default parameters for a given model. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_6Params_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_6models_6Params_1__init__ = {"__init__", (PyCFunction)__pyx_pw_6models_6Params_1__init__, METH_O, 0};
static PyObject *__pyx_pw_6models_6Params_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_6models_6Params___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_6Params___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":159
 *         pass
 *
 *     def get(self, est):             # <<<<<<<<<<<<<<
 *         return self.gettattr(self, est)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_6Params_3get(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_6Params_3get = {"get", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_6Params_3get, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_6Params_3get(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_est = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("get (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_est,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_est)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("get", 1, 2, 2, 1); __PYX_ERR(0, 159, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "get") < 0)) __PYX_ERR(0, 159, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_est = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("get", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 159, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.Params.get", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_6Params_2get(__pyx_self, __pyx_v_self, __pyx_v_est);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_6Params_2get(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_est) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("get", 0);

  /* "models.py":160
 *
 *     def get(self, est):
 *         return self.gettattr(self, est)             # <<<<<<<<<<<<<<
 *
 *     def rfc(self):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_gettattr); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_self, __pyx_v_est};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_self, __pyx_v_est};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_self);
    __Pyx_GIVEREF(__pyx_v_self);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_self);
    __Pyx_INCREF(__pyx_v_est);
    __Pyx_GIVEREF(__pyx_v_est);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_est);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "models.py":159
 *         pass
 *
 *     def get(self, est):             # <<<<<<<<<<<<<<
 *         return self.gettattr(self, est)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("models.Params.get", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":162
 *         return self.gettattr(self, est)
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *         return dict(
 *             bootstrap=True,
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_6Params_5rfc(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_6models_6Params_5rfc = {"rfc", (PyCFunction)__pyx_pw_6models_6Params_5rfc, METH_O, 0};
static PyObject *__pyx_pw_6models_6Params_5rfc(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("rfc (wrapper)", 0);
  __pyx_r = __pyx_pf_6models_6Params_4rfc(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_6Params_4rfc(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("rfc", 0);

  /* "models.py":163
 *
 *     def rfc(self):
 *         return dict(             # <<<<<<<<<<<<<<
 *             bootstrap=True,
 *             class_weight=None,
 */
  __Pyx_XDECREF(__pyx_r);

  /* "models.py":164
 *     def rfc(self):
 *         return dict(
 *             bootstrap=True,             # <<<<<<<<<<<<<<
 *             class_weight=None,
 *             criterion='gini',
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(16); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_bootstrap, Py_True) < 0) __PYX_ERR(0, 164, __pyx_L1_error)

  /* "models.py":165
 *         return dict(
 *             bootstrap=True,
 *             class_weight=None,             # <<<<<<<<<<<<<<
 *             criterion='gini',
 *             max_depth=None,
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_class_weight, Py_None) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_criterion, __pyx_n_u_gini) < 0) __PYX_ERR(0, 164, __pyx_L1_error)

  /* "models.py":167
 *             class_weight=None,
 *             criterion='gini',
 *             max_depth=None,             # <<<<<<<<<<<<<<
 *             max_features='auto',
 *             max_leaf_nodes=None,
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_max_depth, Py_None) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_max_features, __pyx_n_u_auto) < 0) __PYX_ERR(0, 164, __pyx_L1_error)

  /* "models.py":169
 *             max_depth=None,
 *             max_features='auto',
 *             max_leaf_nodes=None,             # <<<<<<<<<<<<<<
 *             min_impurity_split=1e-07,
 *             min_samples_leaf=1,
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_max_leaf_nodes, Py_None) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_min_impurity_split, __pyx_float_1eneg_07) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_min_samples_leaf, __pyx_int_1) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_min_samples_split, __pyx_int_2) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_min_weight_fraction_leaf, __pyx_float_0_0) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_n_estimators, __pyx_int_10) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_n_jobs, __pyx_int_1) < 0) __PYX_ERR(0, 164, __pyx_L1_error)

  /* "models.py":176
 *             n_estimators=10,
 *             n_jobs=1,
 *             oob_score=False,             # <<<<<<<<<<<<<<
 *             random_state=None,
 *             verbose=0,
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_oob_score, Py_False) < 0) __PYX_ERR(0, 164, __pyx_L1_error)

  /* "models.py":177
 *             n_jobs=1,
 *             oob_score=False,
 *             random_state=None,             # <<<<<<<<<<<<<<
 *             verbose=0,
 *             warm_start=False
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_random_state, Py_None) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_verbose, __pyx_int_0) < 0) __PYX_ERR(0, 164, __pyx_L1_error)

  /* "models.py":179
 *             random_state=None,
 *             verbose=0,
 *             warm_start=False             # <<<<<<<<<<<<<<
 *             )
 *
 */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_warm_start, Py_False) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "models.py":162
 *         return self.gettattr(self, est)
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *         return dict(
 *             bootstrap=True,
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("models.Params.rfc", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":189
 * class GradientDescent(object):
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_15GradientDescent_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_15GradientDescent_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_15GradientDescent_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_15GradientDescent_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_learning_rate = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_learning_rate,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject*)__pyx_float_0_01));
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_learning_rate);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 189, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_learning_rate = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 189, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.GradientDescent.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_15GradientDescent___init__(__pyx_self, __pyx_v_self, __pyx_v_learning_rate);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_15GradientDescent___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_learning_rate) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "models.py":190
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):
 *         self.learning_rate = learning_rate             # <<<<<<<<<<<<<<
 *         self.w = 0
 *         self.b = 0
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_learning_rate, __pyx_v_learning_rate) < 0) __PYX_ERR(0, 190, __pyx_L1_error)

  /* "models.py":191
 *     def __init__(self, learning_rate=0.01):
 *         self.learning_rate = learning_rate
 *         self.w = 0             # <<<<<<<<<<<<<<
 *         self.b = 0
 *
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_w, __pyx_int_0) < 0) __PYX_ERR(0, 191, __pyx_L1_error)

  /* "models.py":192
 *         self.learning_rate = learning_rate
 *         self.w = 0
 *         self.b = 0             # <<<<<<<<<<<<<<
 *
 *     def reshape_cat_series(self, y):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_b, __pyx_int_0) < 0) __PYX_ERR(0, 192, __pyx_L1_error)

  /* "models.py":189
 * class GradientDescent(object):
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("models.GradientDescent.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":194
 *         self.b = 0
 *
 *     def reshape_cat_series(self, y):             # <<<<<<<<<<<<<<
 *         """ If we get passed a series of strings, convert to matrix of int values.
 *             Obviously, this is a workaround (here) and needs to be refactored. """
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_15GradientDescent_3reshape_cat_series(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_6models_15GradientDescent_2reshape_cat_series[] = " If we get passed a series of strings, convert to matrix of int values.\n            Obviously, this is a workaround (here) and needs to be refactored. ";
static PyMethodDef __pyx_mdef_6models_15GradientDescent_3reshape_cat_series = {"reshape_cat_series", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_15GradientDescent_3reshape_cat_series, METH_VARARGS|METH_KEYWORDS, __pyx_doc_6models_15GradientDescent_2reshape_cat_series};
static PyObject *__pyx_pw_6models_15GradientDescent_3reshape_cat_series(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("reshape_cat_series (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_y,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("reshape_cat_series", 1, 2, 2, 1); __PYX_ERR(0, 194, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "reshape_cat_series") < 0)) __PYX_ERR(0, 194, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_y = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("reshape_cat_series", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 194, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.GradientDescent.reshape_cat_series", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_15GradientDescent_2reshape_cat_series(__pyx_self, __pyx_v_self, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_15GradientDescent_2reshape_cat_series(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("reshape_cat_series", 0);
  __Pyx_INCREF(__pyx_v_y);

  /* "models.py":197
 *         """ If we get passed a series of strings, convert to matrix of int values.
 *             Obviously, this is a workaround (here) and needs to be refactored. """
 *         y = y.to_frame()             # <<<<<<<<<<<<<<
 *         y.target = pd.Categorical(y.target)
 *         y['cats'] = y['target'].cat.codes
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_y, __pyx_n_s_to_frame); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 197, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF_SET(__pyx_v_y, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "models.py":198
 *             Obviously, this is a workaround (here) and needs to be refactored. """
 *         y = y.to_frame()
 *         y.target = pd.Categorical(y.target)             # <<<<<<<<<<<<<<
 *         y['cats'] = y['target'].cat.codes
 *         y = y['cats'].values
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_pd); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Categorical); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_y, __pyx_n_s_target); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_y, __pyx_n_s_target, __pyx_t_1) < 0) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":199
 *         y = y.to_frame()
 *         y.target = pd.Categorical(y.target)
 *         y['cats'] = y['target'].cat.codes             # <<<<<<<<<<<<<<
 *         y = y['cats'].values
 *         y = np.reshape(np.array(y), (-1, 1)) # (bc we're passing a frame.)
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_y, __pyx_n_u_target); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_cat); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_codes); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(PyObject_SetItem(__pyx_v_y, __pyx_n_u_cats, __pyx_t_1) < 0)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":200
 *         y.target = pd.Categorical(y.target)
 *         y['cats'] = y['target'].cat.codes
 *         y = y['cats'].values             # <<<<<<<<<<<<<<
 *         y = np.reshape(np.array(y), (-1, 1)) # (bc we're passing a frame.)
 *
 */
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_v_y, __pyx_n_u_cats); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_values); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF_SET(__pyx_v_y, __pyx_t_3);
  __pyx_t_3 = 0;

  /* "models.py":201
 *         y['cats'] = y['target'].cat.codes
 *         y = y['cats'].values
 *         y = np.reshape(np.array(y), (-1, 1)) # (bc we're passing a frame.)             # <<<<<<<<<<<<<<
 *
 *         return y
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_np); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_reshape); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_np); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_array); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_4, __pyx_v_y) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_v_y);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  __pyx_t_6 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
      __pyx_t_6 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_1, __pyx_tuple__2};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 201, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_t_1, __pyx_tuple__2};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 201, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  } else
  #endif
  {
    __pyx_t_4 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 201, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (__pyx_t_5) {
      __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_5); __pyx_t_5 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_4, 0+__pyx_t_6, __pyx_t_1);
    __Pyx_INCREF(__pyx_tuple__2);
    __Pyx_GIVEREF(__pyx_tuple__2);
    PyTuple_SET_ITEM(__pyx_t_4, 1+__pyx_t_6, __pyx_tuple__2);
    __pyx_t_1 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_4, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 201, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF_SET(__pyx_v_y, __pyx_t_3);
  __pyx_t_3 = 0;

  /* "models.py":203
 *         y = np.reshape(np.array(y), (-1, 1)) # (bc we're passing a frame.)
 *
 *         return y             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y, epochs = 2):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_y);
  __pyx_r = __pyx_v_y;
  goto __pyx_L0;

  /* "models.py":194
 *         self.b = 0
 *
 *     def reshape_cat_series(self, y):             # <<<<<<<<<<<<<<
 *         """ If we get passed a series of strings, convert to matrix of int values.
 *             Obviously, this is a workaround (here) and needs to be refactored. """
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("models.GradientDescent.reshape_cat_series", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_y);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":205
 *         return y
 *
 *     def fit(self, X, y, epochs = 2):             # <<<<<<<<<<<<<<
 *         """
 *         :param X: scipy.sparse.csr.csr_matrix
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_15GradientDescent_5fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_6models_15GradientDescent_4fit[] = "\n        :param X: scipy.sparse.csr.csr_matrix\n        :param y: pandas.core.series.Series ";
static PyMethodDef __pyx_mdef_6models_15GradientDescent_5fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_15GradientDescent_5fit, METH_VARARGS|METH_KEYWORDS, __pyx_doc_6models_15GradientDescent_4fit};
static PyObject *__pyx_pw_6models_15GradientDescent_5fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_epochs = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,&__pyx_n_s_epochs,0};
    PyObject* values[4] = {0,0,0,0};
    values[3] = ((PyObject *)((PyObject *)__pyx_int_2));
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_X)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("fit", 0, 3, 4, 1); __PYX_ERR(0, 205, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("fit", 0, 3, 4, 2); __PYX_ERR(0, 205, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_epochs);
          if (value) { values[3] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 205, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
    __pyx_v_epochs = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 3, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 205, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.GradientDescent.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_15GradientDescent_4fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y, __pyx_v_epochs);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_15GradientDescent_4fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y, PyObject *__pyx_v_epochs) {
  PyObject *__pyx_v_N = NULL;
  PyObject *__pyx_v_history = NULL;
  PyObject *__pyx_v_e = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_Xi = NULL;
  PyObject *__pyx_v_yi = NULL;
  PyObject *__pyx_v_f = NULL;
  PyObject *__pyx_v_loss = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  Py_ssize_t __pyx_t_6;
  PyObject *(*__pyx_t_7)(PyObject *);
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_t_14;
  int __pyx_t_15;
  Py_UCS4 __pyx_t_16;
  int __pyx_t_17;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("fit", 0);
  __Pyx_INCREF(__pyx_v_y);

  /* "models.py":209
 *         :param X: scipy.sparse.csr.csr_matrix
 *         :param y: pandas.core.series.Series """
 *         N = X.shape[0]             # <<<<<<<<<<<<<<
 *         y = self.reshape_cat_series(y) # W/A
 *
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_shape); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_N = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "models.py":210
 *         :param y: pandas.core.series.Series """
 *         N = X.shape[0]
 *         y = self.reshape_cat_series(y) # W/A             # <<<<<<<<<<<<<<
 *
 *         history = []
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_reshape_cat_series); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_3, __pyx_v_y) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_v_y);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF_SET(__pyx_v_y, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "models.py":212
 *         y = self.reshape_cat_series(y) # W/A
 *
 *         history = []             # <<<<<<<<<<<<<<
 *
 *         for e in range(epochs):
 */
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_history = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  /* "models.py":214
 *         history = []
 *
 *         for e in range(epochs):             # <<<<<<<<<<<<<<
 *
 *             for i in range(N):
 */
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_v_epochs); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
    __pyx_t_1 = __pyx_t_2; __Pyx_INCREF(__pyx_t_1); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_5 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 214, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 214, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 214, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_4); __Pyx_INCREF(__pyx_t_2); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 214, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_1, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 214, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_5(__pyx_t_1);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 214, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XDECREF_SET(__pyx_v_e, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "models.py":216
 *         for e in range(epochs):
 *
 *             for i in range(N):             # <<<<<<<<<<<<<<
 *                 Xi = X[i, :]
 *                 yi = y[i, :]
 */
    __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_v_N); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 216, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
      __pyx_t_3 = __pyx_t_2; __Pyx_INCREF(__pyx_t_3); __pyx_t_6 = 0;
      __pyx_t_7 = NULL;
    } else {
      __pyx_t_6 = -1; __pyx_t_3 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 216, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_7 = Py_TYPE(__pyx_t_3)->tp_iternext; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 216, __pyx_L1_error)
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    for (;;) {
      if (likely(!__pyx_t_7)) {
        if (likely(PyList_CheckExact(__pyx_t_3))) {
          if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_3)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_2 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_6); __Pyx_INCREF(__pyx_t_2); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 216, __pyx_L1_error)
          #else
          __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 216, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          #endif
        } else {
          if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_3)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_3, __pyx_t_6); __Pyx_INCREF(__pyx_t_2); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 216, __pyx_L1_error)
          #else
          __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 216, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          #endif
        }
      } else {
        __pyx_t_2 = __pyx_t_7(__pyx_t_3);
        if (unlikely(!__pyx_t_2)) {
          PyObject* exc_type = PyErr_Occurred();
          if (exc_type) {
            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
            else __PYX_ERR(0, 216, __pyx_L1_error)
          }
          break;
        }
        __Pyx_GOTREF(__pyx_t_2);
      }
      __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_2);
      __pyx_t_2 = 0;

      /* "models.py":217
 *
 *             for i in range(N):
 *                 Xi = X[i, :]             # <<<<<<<<<<<<<<
 *                 yi = y[i, :]
 *
 */
      __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_INCREF(__pyx_v_i);
      __Pyx_GIVEREF(__pyx_v_i);
      PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_i);
      __Pyx_INCREF(__pyx_slice__3);
      __Pyx_GIVEREF(__pyx_slice__3);
      PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_slice__3);
      __pyx_t_8 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 217, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF_SET(__pyx_v_Xi, __pyx_t_8);
      __pyx_t_8 = 0;

      /* "models.py":218
 *             for i in range(N):
 *                 Xi = X[i, :]
 *                 yi = y[i, :]             # <<<<<<<<<<<<<<
 *
 *                 f = yi - (self.w * Xi + self.b)
 */
      __pyx_t_8 = PyTuple_New(2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 218, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_INCREF(__pyx_v_i);
      __Pyx_GIVEREF(__pyx_v_i);
      PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_v_i);
      __Pyx_INCREF(__pyx_slice__3);
      __Pyx_GIVEREF(__pyx_slice__3);
      PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_slice__3);
      __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_y, __pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 218, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_XDECREF_SET(__pyx_v_yi, __pyx_t_2);
      __pyx_t_2 = 0;

      /* "models.py":220
 *                 yi = y[i, :]
 *
 *                 f = yi - (self.w * Xi + self.b)             # <<<<<<<<<<<<<<
 *
 *                 self.w -= self.learning_rate * (-2 * Xi.dot(f.T).sum() / N)
 */
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 220, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_8 = PyNumber_Multiply(__pyx_t_2, __pyx_v_Xi); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 220, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 220, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = PyNumber_Add(__pyx_t_8, __pyx_t_2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 220, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = PyNumber_Subtract(__pyx_v_yi, __pyx_t_9); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 220, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_XDECREF_SET(__pyx_v_f, __pyx_t_2);
      __pyx_t_2 = 0;

      /* "models.py":222
 *                 f = yi - (self.w * Xi + self.b)
 *
 *                 self.w -= self.learning_rate * (-2 * Xi.dot(f.T).sum() / N)             # <<<<<<<<<<<<<<
 *                 self.b -= self.learning_rate * (-2 * f.sum() / N)
 *
 */
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_learning_rate); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_v_Xi, __pyx_n_s_dot); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_11);
      __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_v_f, __pyx_n_s_T); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_12);
      __pyx_t_13 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_11))) {
        __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_11);
        if (likely(__pyx_t_13)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
          __Pyx_INCREF(__pyx_t_13);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_11, function);
        }
      }
      __pyx_t_10 = (__pyx_t_13) ? __Pyx_PyObject_Call2Args(__pyx_t_11, __pyx_t_13, __pyx_t_12) : __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_12);
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
      if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_sum); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_11);
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __pyx_t_10 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_11))) {
        __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_11);
        if (likely(__pyx_t_10)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
          __Pyx_INCREF(__pyx_t_10);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_11, function);
        }
      }
      __pyx_t_8 = (__pyx_t_10) ? __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_10) : __Pyx_PyObject_CallNoArg(__pyx_t_11);
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __pyx_t_11 = PyNumber_Multiply(__pyx_int_neg_2, __pyx_t_8); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_11);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __pyx_t_8 = __Pyx_PyNumber_Divide(__pyx_t_11, __pyx_v_N); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __pyx_t_11 = PyNumber_Multiply(__pyx_t_9, __pyx_t_8); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_11);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __pyx_t_8 = PyNumber_InPlaceSubtract(__pyx_t_2, __pyx_t_11); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_w, __pyx_t_8) < 0) __PYX_ERR(0, 222, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

      /* "models.py":223
 *
 *                 self.w -= self.learning_rate * (-2 * Xi.dot(f.T).sum() / N)
 *                 self.b -= self.learning_rate * (-2 * f.sum() / N)             # <<<<<<<<<<<<<<
 *
 *                 #self.b = 0.0 # W/A for non-zero scalar.
 */
      __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_learning_rate); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_11);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_v_f, __pyx_n_s_sum); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_10 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_10)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_10);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
        }
      }
      __pyx_t_2 = (__pyx_t_10) ? __Pyx_PyObject_CallOneArg(__pyx_t_9, __pyx_t_10) : __Pyx_PyObject_CallNoArg(__pyx_t_9);
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = PyNumber_Multiply(__pyx_int_neg_2, __pyx_t_2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyNumber_Divide(__pyx_t_9, __pyx_v_N); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = PyNumber_Multiply(__pyx_t_11, __pyx_t_2); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = PyNumber_InPlaceSubtract(__pyx_t_8, __pyx_t_9); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_b, __pyx_t_2) < 0) __PYX_ERR(0, 223, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      /* "models.py":216
 *         for e in range(epochs):
 *
 *             for i in range(N):             # <<<<<<<<<<<<<<
 *                 Xi = X[i, :]
 *                 yi = y[i, :]
 */
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    /* "models.py":228
 *             #X = X.toarray() # W/A for dense, not sparse matrix needed.
 *
 *             loss = mean_squared_error(y, (self.w * X + self.b))             # <<<<<<<<<<<<<<
 *
 *             if e % 100 == 0:
 */
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_mean_squared_error); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 228, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 228, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __pyx_t_8 = PyNumber_Multiply(__pyx_t_9, __pyx_v_X); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 228, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 228, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __pyx_t_11 = PyNumber_Add(__pyx_t_8, __pyx_t_9); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 228, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    __pyx_t_9 = NULL;
    __pyx_t_14 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_9)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_9);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
        __pyx_t_14 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_v_y, __pyx_t_11};
      __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_14, 2+__pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 228, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_v_y, __pyx_t_11};
      __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_14, 2+__pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 228, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
    } else
    #endif
    {
      __pyx_t_8 = PyTuple_New(2+__pyx_t_14); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 228, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (__pyx_t_9) {
        __Pyx_GIVEREF(__pyx_t_9); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_9); __pyx_t_9 = NULL;
      }
      __Pyx_INCREF(__pyx_v_y);
      __Pyx_GIVEREF(__pyx_v_y);
      PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_14, __pyx_v_y);
      __Pyx_GIVEREF(__pyx_t_11);
      PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_14, __pyx_t_11);
      __pyx_t_11 = 0;
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_8, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 228, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_loss, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "models.py":230
 *             loss = mean_squared_error(y, (self.w * X + self.b))
 *
 *             if e % 100 == 0:             # <<<<<<<<<<<<<<
 *                 print(f"Epoch: {e}, Loss: {loss})")
 *
 */
    __pyx_t_3 = __Pyx_PyInt_RemainderObjC(__pyx_v_e, __pyx_int_100, 0x64, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_2 = __Pyx_PyInt_EqObjC(__pyx_t_3, __pyx_int_0, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_15 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_15 < 0)) __PYX_ERR(0, 230, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (__pyx_t_15) {

      /* "models.py":231
 *
 *             if e % 100 == 0:
 *                 print(f"Epoch: {e}, Loss: {loss})")             # <<<<<<<<<<<<<<
 *
 *             history.append(loss)
 */
      __pyx_t_2 = PyTuple_New(5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 231, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_6 = 0;
      __pyx_t_16 = 127;
      __Pyx_INCREF(__pyx_kp_u_Epoch);
      __pyx_t_6 += 7;
      __Pyx_GIVEREF(__pyx_kp_u_Epoch);
      PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_kp_u_Epoch);
      __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_v_e, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 231, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_16 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) > __pyx_t_16) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) : __pyx_t_16;
      __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_3);
      __pyx_t_3 = 0;
      __Pyx_INCREF(__pyx_kp_u_Loss);
      __pyx_t_6 += 8;
      __Pyx_GIVEREF(__pyx_kp_u_Loss);
      PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_kp_u_Loss);
      __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_v_loss, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 231, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_16 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) > __pyx_t_16) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) : __pyx_t_16;
      __pyx_t_6 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_2, 3, __pyx_t_3);
      __pyx_t_3 = 0;
      __Pyx_INCREF(__pyx_kp_u__4);
      __pyx_t_6 += 1;
      __Pyx_GIVEREF(__pyx_kp_u__4);
      PyTuple_SET_ITEM(__pyx_t_2, 4, __pyx_kp_u__4);
      __pyx_t_3 = __Pyx_PyUnicode_Join(__pyx_t_2, 5, __pyx_t_6, __pyx_t_16); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 231, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 231, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      /* "models.py":230
 *             loss = mean_squared_error(y, (self.w * X + self.b))
 *
 *             if e % 100 == 0:             # <<<<<<<<<<<<<<
 *                 print(f"Epoch: {e}, Loss: {loss})")
 *
 */
    }

    /* "models.py":233
 *                 print(f"Epoch: {e}, Loss: {loss})")
 *
 *             history.append(loss)             # <<<<<<<<<<<<<<
 *
 *         return history
 */
    __pyx_t_17 = __Pyx_PyList_Append(__pyx_v_history, __pyx_v_loss); if (unlikely(__pyx_t_17 == ((int)-1))) __PYX_ERR(0, 233, __pyx_L1_error)

    /* "models.py":214
 *         history = []
 *
 *         for e in range(epochs):             # <<<<<<<<<<<<<<
 *
 *             for i in range(N):
 */
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":235
 *             history.append(loss)
 *
 *         return history             # <<<<<<<<<<<<<<
 *
 *     def predict(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_history);
  __pyx_r = __pyx_v_history;
  goto __pyx_L0;

  /* "models.py":205
 *         return y
 *
 *     def fit(self, X, y, epochs = 2):             # <<<<<<<<<<<<<<
 *         """
 *         :param X: scipy.sparse.csr.csr_matrix
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_AddTraceback("models.GradientDescent.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_N);
  __Pyx_XDECREF(__pyx_v_history);
  __Pyx_XDECREF(__pyx_v_e);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_Xi);
  __Pyx_XDECREF(__pyx_v_yi);
  __Pyx_XDECREF(__pyx_v_f);
  __Pyx_XDECREF(__pyx_v_loss);
  __Pyx_XDECREF(__pyx_v_y);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":237
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_15GradientDescent_7predict(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_15GradientDescent_7predict = {"predict", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_15GradientDescent_7predict, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_15GradientDescent_7predict(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("predict (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_X)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("predict", 1, 2, 2, 1); __PYX_ERR(0, 237, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "predict") < 0)) __PYX_ERR(0, 237, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_X = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("predict", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 237, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.GradientDescent.predict", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_15GradientDescent_6predict(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_15GradientDescent_6predict(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("predict", 0);

  /* "models.py":238
 *
 *     def predict(self, X):
 *         return self.w * X + self.b             # <<<<<<<<<<<<<<
 *
 * class BatchGradientDescent():
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_1, __pyx_v_X); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "models.py":237
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("models.GradientDescent.predict", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":241
 *
 * class BatchGradientDescent():
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_20BatchGradientDescent_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_20BatchGradientDescent_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_20BatchGradientDescent_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_20BatchGradientDescent_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_learning_rate = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_learning_rate,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject*)__pyx_float_0_01));
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_learning_rate);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 241, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_learning_rate = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 241, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.BatchGradientDescent.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_20BatchGradientDescent___init__(__pyx_self, __pyx_v_self, __pyx_v_learning_rate);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_20BatchGradientDescent___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_learning_rate) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "models.py":242
 * class BatchGradientDescent():
 *     def __init__(self, learning_rate=0.01):
 *         self.learning_rate = learning_rate             # <<<<<<<<<<<<<<
 *         self.w = 0
 *         self.b = 0
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_learning_rate, __pyx_v_learning_rate) < 0) __PYX_ERR(0, 242, __pyx_L1_error)

  /* "models.py":243
 *     def __init__(self, learning_rate=0.01):
 *         self.learning_rate = learning_rate
 *         self.w = 0             # <<<<<<<<<<<<<<
 *         self.b = 0
 *
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_w, __pyx_int_0) < 0) __PYX_ERR(0, 243, __pyx_L1_error)

  /* "models.py":244
 *         self.learning_rate = learning_rate
 *         self.w = 0
 *         self.b = 0             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y, epochs = 100):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_b, __pyx_int_0) < 0) __PYX_ERR(0, 244, __pyx_L1_error)

  /* "models.py":241
 *
 * class BatchGradientDescent():
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("models.BatchGradientDescent.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":246
 *         self.b = 0
 *
 *     def fit(self, X, y, epochs = 100):             # <<<<<<<<<<<<<<
 *         N = len(X)
 *         history = []
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_20BatchGradientDescent_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_20BatchGradientDescent_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_20BatchGradientDescent_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_20BatchGradientDescent_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_epochs = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,&__pyx_n_s_epochs,0};
    PyObject* values[4] = {0,0,0,0};
    values[3] = ((PyObject *)((PyObject *)__pyx_int_100));
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_X)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("fit", 0, 3, 4, 1); __PYX_ERR(0, 246, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("fit", 0, 3, 4, 2); __PYX_ERR(0, 246, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_epochs);
          if (value) { values[3] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 246, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
    __pyx_v_epochs = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 3, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 246, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.BatchGradientDescent.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_20BatchGradientDescent_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y, __pyx_v_epochs);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_20BatchGradientDescent_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y, PyObject *__pyx_v_epochs) {
  PyObject *__pyx_v_N = NULL;
  PyObject *__pyx_v_history = NULL;
  PyObject *__pyx_v_e = NULL;
  PyObject *__pyx_v_f = NULL;
  PyObject *__pyx_v_loss = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  Py_ssize_t __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *(*__pyx_t_4)(PyObject *);
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  int __pyx_t_12;
  Py_ssize_t __pyx_t_13;
  Py_UCS4 __pyx_t_14;
  int __pyx_t_15;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("fit", 0);

  /* "models.py":247
 *
 *     def fit(self, X, y, epochs = 100):
 *         N = len(X)             # <<<<<<<<<<<<<<
 *         history = []
 *
 */
  __pyx_t_1 = PyObject_Length(__pyx_v_X); if (unlikely(__pyx_t_1 == ((Py_ssize_t)-1))) __PYX_ERR(0, 247, __pyx_L1_error)
  __pyx_t_2 = PyInt_FromSsize_t(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 247, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_N = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "models.py":248
 *     def fit(self, X, y, epochs = 100):
 *         N = len(X)
 *         history = []             # <<<<<<<<<<<<<<
 *
 *         for e in range(epochs):
 */
  __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 248, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_history = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  /* "models.py":250
 *         history = []
 *
 *         for e in range(epochs):             # <<<<<<<<<<<<<<
 *             f = y - (self.w * X + self.b)
 *
 */
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_v_epochs); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 250, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
    __pyx_t_3 = __pyx_t_2; __Pyx_INCREF(__pyx_t_3); __pyx_t_1 = 0;
    __pyx_t_4 = NULL;
  } else {
    __pyx_t_1 = -1; __pyx_t_3 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 250, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = Py_TYPE(__pyx_t_3)->tp_iternext; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 250, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  for (;;) {
    if (likely(!__pyx_t_4)) {
      if (likely(PyList_CheckExact(__pyx_t_3))) {
        if (__pyx_t_1 >= PyList_GET_SIZE(__pyx_t_3)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_1); __Pyx_INCREF(__pyx_t_2); __pyx_t_1++; if (unlikely(0 < 0)) __PYX_ERR(0, 250, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_1); __pyx_t_1++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 250, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      } else {
        if (__pyx_t_1 >= PyTuple_GET_SIZE(__pyx_t_3)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_3, __pyx_t_1); __Pyx_INCREF(__pyx_t_2); __pyx_t_1++; if (unlikely(0 < 0)) __PYX_ERR(0, 250, __pyx_L1_error)
        #else
        __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_1); __pyx_t_1++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 250, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        #endif
      }
    } else {
      __pyx_t_2 = __pyx_t_4(__pyx_t_3);
      if (unlikely(!__pyx_t_2)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 250, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_2);
    }
    __Pyx_XDECREF_SET(__pyx_v_e, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "models.py":251
 *
 *         for e in range(epochs):
 *             f = y - (self.w * X + self.b)             # <<<<<<<<<<<<<<
 *
 *             self.w -= self.learning_rate * (-2 * X.dot(f.T).sum() / N)
 */
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 251, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = PyNumber_Multiply(__pyx_t_2, __pyx_v_X); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 251, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 251, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = PyNumber_Add(__pyx_t_5, __pyx_t_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 251, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyNumber_Subtract(__pyx_v_y, __pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 251, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF_SET(__pyx_v_f, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "models.py":253
 *             f = y - (self.w * X + self.b)
 *
 *             self.w -= self.learning_rate * (-2 * X.dot(f.T).sum() / N)             # <<<<<<<<<<<<<<
 *             self.b -= self.learning_rate * (-2 * f.sum() / N)
 *
 */
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_learning_rate); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_dot); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_v_f, __pyx_n_s_T); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __pyx_t_10 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
      __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_8);
      if (likely(__pyx_t_10)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
        __Pyx_INCREF(__pyx_t_10);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_8, function);
      }
    }
    __pyx_t_7 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_10, __pyx_t_9) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_9);
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
    if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_sum); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_8))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_8);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_8, function);
      }
    }
    __pyx_t_5 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_8);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = PyNumber_Multiply(__pyx_int_neg_2, __pyx_t_5); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyNumber_Divide(__pyx_t_8, __pyx_v_N); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __pyx_t_8 = PyNumber_Multiply(__pyx_t_6, __pyx_t_5); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyNumber_InPlaceSubtract(__pyx_t_2, __pyx_t_8); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_w, __pyx_t_5) < 0) __PYX_ERR(0, 253, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "models.py":254
 *
 *             self.w -= self.learning_rate * (-2 * X.dot(f.T).sum() / N)
 *             self.b -= self.learning_rate * (-2 * f.sum() / N)             # <<<<<<<<<<<<<<
 *
 *             loss = mean_squared_error(y, (self.w * X + self.b))
 */
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_learning_rate); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_f, __pyx_n_s_sum); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_6);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_6, function);
      }
    }
    __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_6 = PyNumber_Multiply(__pyx_int_neg_2, __pyx_t_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyNumber_Divide(__pyx_t_6, __pyx_v_N); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_6 = PyNumber_Multiply(__pyx_t_8, __pyx_t_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyNumber_InPlaceSubtract(__pyx_t_5, __pyx_t_6); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_b, __pyx_t_2) < 0) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    /* "models.py":256
 *             self.b -= self.learning_rate * (-2 * f.sum() / N)
 *
 *             loss = mean_squared_error(y, (self.w * X + self.b))             # <<<<<<<<<<<<<<
 *
 *             if e % 100 == 0:
 */
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_mean_squared_error); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_8 = PyNumber_Multiply(__pyx_t_5, __pyx_v_X); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_7 = PyNumber_Add(__pyx_t_8, __pyx_t_5); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = NULL;
    __pyx_t_11 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_6);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_6, function);
        __pyx_t_11 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_6)) {
      PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_y, __pyx_t_7};
      __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_11, 2+__pyx_t_11); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
      PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_v_y, __pyx_t_7};
      __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_11, 2+__pyx_t_11); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    } else
    #endif
    {
      __pyx_t_8 = PyTuple_New(2+__pyx_t_11); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (__pyx_t_5) {
        __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_5); __pyx_t_5 = NULL;
      }
      __Pyx_INCREF(__pyx_v_y);
      __Pyx_GIVEREF(__pyx_v_y);
      PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_11, __pyx_v_y);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_11, __pyx_t_7);
      __pyx_t_7 = 0;
      __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_8, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 256, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    }
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF_SET(__pyx_v_loss, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "models.py":258
 *             loss = mean_squared_error(y, (self.w * X + self.b))
 *
 *             if e % 100 == 0:             # <<<<<<<<<<<<<<
 *                 print(f"Epoch: {e}, Loss: {loss})")
 *
 */
    __pyx_t_2 = __Pyx_PyInt_RemainderObjC(__pyx_v_e, __pyx_int_100, 0x64, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_6 = __Pyx_PyInt_EqObjC(__pyx_t_2, __pyx_int_0, 0, 0); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_12 = __Pyx_PyObject_IsTrue(__pyx_t_6); if (unlikely(__pyx_t_12 < 0)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (__pyx_t_12) {

      /* "models.py":259
 *
 *             if e % 100 == 0:
 *                 print(f"Epoch: {e}, Loss: {loss})")             # <<<<<<<<<<<<<<
 *
 *             history.append(loss)
 */
      __pyx_t_6 = PyTuple_New(5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 259, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_13 = 0;
      __pyx_t_14 = 127;
      __Pyx_INCREF(__pyx_kp_u_Epoch);
      __pyx_t_13 += 7;
      __Pyx_GIVEREF(__pyx_kp_u_Epoch);
      PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_kp_u_Epoch);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_e, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 259, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_14;
      __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_INCREF(__pyx_kp_u_Loss);
      __pyx_t_13 += 8;
      __Pyx_GIVEREF(__pyx_kp_u_Loss);
      PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_kp_u_Loss);
      __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_v_loss, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 259, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_2) : __pyx_t_14;
      __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_2);
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_6, 3, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_INCREF(__pyx_kp_u__4);
      __pyx_t_13 += 1;
      __Pyx_GIVEREF(__pyx_kp_u__4);
      PyTuple_SET_ITEM(__pyx_t_6, 4, __pyx_kp_u__4);
      __pyx_t_2 = __Pyx_PyUnicode_Join(__pyx_t_6, 5, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 259, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 259, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

      /* "models.py":258
 *             loss = mean_squared_error(y, (self.w * X + self.b))
 *
 *             if e % 100 == 0:             # <<<<<<<<<<<<<<
 *                 print(f"Epoch: {e}, Loss: {loss})")
 *
 */
    }

    /* "models.py":261
 *                 print(f"Epoch: {e}, Loss: {loss})")
 *
 *             history.append(loss)             # <<<<<<<<<<<<<<
 *
 *         return history
 */
    __pyx_t_15 = __Pyx_PyList_Append(__pyx_v_history, __pyx_v_loss); if (unlikely(__pyx_t_15 == ((int)-1))) __PYX_ERR(0, 261, __pyx_L1_error)

    /* "models.py":250
 *         history = []
 *
 *         for e in range(epochs):             # <<<<<<<<<<<<<<
 *             f = y - (self.w * X + self.b)
 *
 */
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":263
 *             history.append(loss)
 *
 *         return history             # <<<<<<<<<<<<<<
 *
 *     def predict(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_history);
  __pyx_r = __pyx_v_history;
  goto __pyx_L0;

  /* "models.py":246
 *         self.b = 0
 *
 *     def fit(self, X, y, epochs = 100):             # <<<<<<<<<<<<<<
 *         N = len(X)
 *         history = []
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_AddTraceback("models.BatchGradientDescent.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_N);
  __Pyx_XDECREF(__pyx_v_history);
  __Pyx_XDECREF(__pyx_v_e);
  __Pyx_XDECREF(__pyx_v_f);
  __Pyx_XDECREF(__pyx_v_loss);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":265
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_20BatchGradientDescent_5predict(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_20BatchGradientDescent_5predict = {"predict", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_20BatchGradientDescent_5predict, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_20BatchGradientDescent_5predict(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("predict (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_X)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("predict", 1, 2, 2, 1); __PYX_ERR(0, 265, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "predict") < 0)) __PYX_ERR(0, 265, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_X = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("predict", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 265, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.BatchGradientDescent.predict", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_20BatchGradientDescent_4predict(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_20BatchGradientDescent_4predict(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("predict", 0);

  /* "models.py":266
 *
 *     def predict(self, X):
 *         return self.w * X + self.b             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_w); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 266, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Multiply(__pyx_t_1, __pyx_v_X); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 266, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 266, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 266, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "models.py":265
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("models.BatchGradientDescent.predict", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "models.py":360
 *
 * class LR():
 *     def __init__(self, X, y):             # <<<<<<<<<<<<<<
 *         return LR(fit_intercept=False).fit(X,y)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_6models_2LR_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6models_2LR_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6models_2LR_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6models_2LR_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_X)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 3, 3, 1); __PYX_ERR(0, 360, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 3, 3, 2); __PYX_ERR(0, 360, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 360, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 360, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("models.LR.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6models_2LR___init__(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6models_2LR___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "models.py":361
 * class LR():
 *     def __init__(self, X, y):
 *         return LR(fit_intercept=False).fit(X,y)             # <<<<<<<<<<<<<<
 *
 * """
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_LR); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 361, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 361, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_fit_intercept, Py_False) < 0) __PYX_ERR(0, 361, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 361, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_fit); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 361, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  __pyx_t_5 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
      __pyx_t_5 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_v_X, __pyx_v_y};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 361, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_v_X, __pyx_v_y};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 361, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_2 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 361, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (__pyx_t_4) {
      __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_4); __pyx_t_4 = NULL;
    }
    __Pyx_INCREF(__pyx_v_X);
    __Pyx_GIVEREF(__pyx_v_X);
    PyTuple_SET_ITEM(__pyx_t_2, 0+__pyx_t_5, __pyx_v_X);
    __Pyx_INCREF(__pyx_v_y);
    __Pyx_GIVEREF(__pyx_v_y);
    PyTuple_SET_ITEM(__pyx_t_2, 1+__pyx_t_5, __pyx_v_y);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 361, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "models.py":360
 *
 * class LR():
 *     def __init__(self, X, y):             # <<<<<<<<<<<<<<
 *         return LR(fit_intercept=False).fit(X,y)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("models.LR.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); /*proto*/
static int __pyx_pymod_exec_models(PyObject* module); /*proto*/
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_models},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "models",
    0, /* m_doc */
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, /* m_size */
  #else
    -1, /* m_size */
  #endif
    __pyx_methods /* m_methods */,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, /* m_slots */
  #else
    NULL, /* m_reload */
  #endif
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL /* m_free */
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_n_s_AdaBoostClassifier, __pyx_k_AdaBoostClassifier, sizeof(__pyx_k_AdaBoostClassifier), 0, 0, 1, 1},
  {&__pyx_n_u_AdaBoostClassifier, __pyx_k_AdaBoostClassifier, sizeof(__pyx_k_AdaBoostClassifier), 0, 1, 0, 1},
  {&__pyx_n_s_BatchGradientDescent, __pyx_k_BatchGradientDescent, sizeof(__pyx_k_BatchGradientDescent), 0, 0, 1, 1},
  {&__pyx_n_s_BatchGradientDescent___init, __pyx_k_BatchGradientDescent___init, sizeof(__pyx_k_BatchGradientDescent___init), 0, 0, 1, 1},
  {&__pyx_n_s_BatchGradientDescent_fit, __pyx_k_BatchGradientDescent_fit, sizeof(__pyx_k_BatchGradientDescent_fit), 0, 0, 1, 1},
  {&__pyx_n_s_BatchGradientDescent_predict, __pyx_k_BatchGradientDescent_predict, sizeof(__pyx_k_BatchGradientDescent_predict), 0, 0, 1, 1},
  {&__pyx_n_s_BernoulliNB, __pyx_k_BernoulliNB, sizeof(__pyx_k_BernoulliNB), 0, 0, 1, 1},
  {&__pyx_n_u_BernoulliNB, __pyx_k_BernoulliNB, sizeof(__pyx_k_BernoulliNB), 0, 1, 0, 1},
  {&__pyx_n_s_C, __pyx_k_C, sizeof(__pyx_k_C), 0, 0, 1, 1},
  {&__pyx_n_s_Categorical, __pyx_k_Categorical, sizeof(__pyx_k_Categorical), 0, 0, 1, 1},
  {&__pyx_n_s_Classifiers, __pyx_k_Classifiers, sizeof(__pyx_k_Classifiers), 0, 0, 1, 1},
  {&__pyx_n_s_Classifiers___init, __pyx_k_Classifiers___init, sizeof(__pyx_k_Classifiers___init), 0, 0, 1, 1},
  {&__pyx_n_s_DecisionTreeClassifier, __pyx_k_DecisionTreeClassifier, sizeof(__pyx_k_DecisionTreeClassifier), 0, 0, 1, 1},
  {&__pyx_kp_u_Epoch, __pyx_k_Epoch, sizeof(__pyx_k_Epoch), 0, 1, 0, 0},
  {&__pyx_n_s_GaussianNB, __pyx_k_GaussianNB, sizeof(__pyx_k_GaussianNB), 0, 0, 1, 1},
  {&__pyx_n_u_GaussianNB, __pyx_k_GaussianNB, sizeof(__pyx_k_GaussianNB), 0, 1, 0, 1},
  {&__pyx_n_s_GradientBoostingClassifier, __pyx_k_GradientBoostingClassifier, sizeof(__pyx_k_GradientBoostingClassifier), 0, 0, 1, 1},
  {&__pyx_n_u_GradientBoostingClassifier, __pyx_k_GradientBoostingClassifier, sizeof(__pyx_k_GradientBoostingClassifier), 0, 1, 0, 1},
  {&__pyx_n_s_GradientDescent, __pyx_k_GradientDescent, sizeof(__pyx_k_GradientDescent), 0, 0, 1, 1},
  {&__pyx_n_u_GradientDescent, __pyx_k_GradientDescent, sizeof(__pyx_k_GradientDescent), 0, 1, 0, 1},
  {&__pyx_n_s_GradientDescent___init, __pyx_k_GradientDescent___init, sizeof(__pyx_k_GradientDescent___init), 0, 0, 1, 1},
  {&__pyx_n_s_GradientDescent_fit, __pyx_k_GradientDescent_fit, sizeof(__pyx_k_GradientDescent_fit), 0, 0, 1, 1},
  {&__pyx_n_s_GradientDescent_predict, __pyx_k_GradientDescent_predict, sizeof(__pyx_k_GradientDescent_predict), 0, 0, 1, 1},
  {&__pyx_n_s_GradientDescent_reshape_cat_seri, __pyx_k_GradientDescent_reshape_cat_seri, sizeof(__pyx_k_GradientDescent_reshape_cat_seri), 0, 0, 1, 1},
  {&__pyx_n_s_HyperSpace, __pyx_k_HyperSpace, sizeof(__pyx_k_HyperSpace), 0, 0, 1, 1},
  {&__pyx_n_s_HyperSpace___init, __pyx_k_HyperSpace___init, sizeof(__pyx_k_HyperSpace___init), 0, 0, 1, 1},
  {&__pyx_n_s_HyperSpace_gbc, __pyx_k_HyperSpace_gbc, sizeof(__pyx_k_HyperSpace_gbc), 0, 0, 1, 1},
  {&__pyx_n_s_HyperSpace_grid, __pyx_k_HyperSpace_grid, sizeof(__pyx_k_HyperSpace_grid), 0, 0, 1, 1},
  {&__pyx_n_s_HyperSpace_rfc, __pyx_k_HyperSpace_rfc, sizeof(__pyx_k_HyperSpace_rfc), 0, 0, 1, 1},
  {&__pyx_n_s_HyperSpace_tfidf, __pyx_k_HyperSpace_tfidf, sizeof(__pyx_k_HyperSpace_tfidf), 0, 0, 1, 1},
  {&__pyx_n_s_HyperSpace_update_hyperparam_ran, __pyx_k_HyperSpace_update_hyperparam_ran, sizeof(__pyx_k_HyperSpace_update_hyperparam_ran), 0, 0, 1, 1},
  {&__pyx_n_s_KNeighborsClassifier, __pyx_k_KNeighborsClassifier, sizeof(__pyx_k_KNeighborsClassifier), 0, 0, 1, 1},
  {&__pyx_n_u_KNeighborsClassifier, __pyx_k_KNeighborsClassifier, sizeof(__pyx_k_KNeighborsClassifier), 0, 1, 0, 1},
  {&__pyx_n_s_LR, __pyx_k_LR, sizeof(__pyx_k_LR), 0, 0, 1, 1},
  {&__pyx_n_s_LR___init, __pyx_k_LR___init, sizeof(__pyx_k_LR___init), 0, 0, 1, 1},
  {&__pyx_n_u_LighGradientBoost, __pyx_k_LighGradientBoost, sizeof(__pyx_k_LighGradientBoost), 0, 1, 0, 1},
  {&__pyx_n_s_LinearDiscriminantAnalysis, __pyx_k_LinearDiscriminantAnalysis, sizeof(__pyx_k_LinearDiscriminantAnalysis), 0, 0, 1, 1},
  {&__pyx_n_u_LinearDiscriminantAnalysis, __pyx_k_LinearDiscriminantAnalysis, sizeof(__pyx_k_LinearDiscriminantAnalysis), 0, 1, 0, 1},
  {&__pyx_kp_u_Loss, __pyx_k_Loss, sizeof(__pyx_k_Loss), 0, 1, 0, 0},
  {&__pyx_n_s_MinMaxScaler, __pyx_k_MinMaxScaler, sizeof(__pyx_k_MinMaxScaler), 0, 0, 1, 1},
  {&__pyx_n_s_MultinomialNB, __pyx_k_MultinomialNB, sizeof(__pyx_k_MultinomialNB), 0, 0, 1, 1},
  {&__pyx_n_u_MultinomialNB, __pyx_k_MultinomialNB, sizeof(__pyx_k_MultinomialNB), 0, 1, 0, 1},
  {&__pyx_n_s_N, __pyx_k_N, sizeof(__pyx_k_N), 0, 0, 1, 1},
  {&__pyx_n_s_N_EST, __pyx_k_N_EST, sizeof(__pyx_k_N_EST), 0, 0, 1, 1},
  {&__pyx_kp_s_Needs_Refactoring, __pyx_k_Needs_Refactoring, sizeof(__pyx_k_Needs_Refactoring), 0, 0, 1, 0},
  {&__pyx_n_s_Params, __pyx_k_Params, sizeof(__pyx_k_Params), 0, 0, 1, 1},
  {&__pyx_n_s_Params___init, __pyx_k_Params___init, sizeof(__pyx_k_Params___init), 0, 0, 1, 1},
  {&__pyx_n_s_Params_get, __pyx_k_Params_get, sizeof(__pyx_k_Params_get), 0, 0, 1, 1},
  {&__pyx_n_s_Params_rfc, __pyx_k_Params_rfc, sizeof(__pyx_k_Params_rfc), 0, 0, 1, 1},
  {&__pyx_n_s_PassiveAggressiveClassifier, __pyx_k_PassiveAggressiveClassifier, sizeof(__pyx_k_PassiveAggressiveClassifier), 0, 0, 1, 1},
  {&__pyx_n_u_PassiveAggressiveClassifier, __pyx_k_PassiveAggressiveClassifier, sizeof(__pyx_k_PassiveAggressiveClassifier), 0, 1, 0, 1},
  {&__pyx_kp_s_Provides_default_parameters_for, __pyx_k_Provides_default_parameters_for, sizeof(__pyx_k_Provides_default_parameters_for), 0, 0, 1, 0},
  {&__pyx_n_s_QuadraticDiscriminantAnalysis, __pyx_k_QuadraticDiscriminantAnalysis, sizeof(__pyx_k_QuadraticDiscriminantAnalysis), 0, 0, 1, 1},
  {&__pyx_n_u_QuadraticDiscriminantAnalysis, __pyx_k_QuadraticDiscriminantAnalysis, sizeof(__pyx_k_QuadraticDiscriminantAnalysis), 0, 1, 0, 1},
  {&__pyx_n_s_RandomForestClassifier, __pyx_k_RandomForestClassifier, sizeof(__pyx_k_RandomForestClassifier), 0, 0, 1, 1},
  {&__pyx_n_u_RandomForestClassifier, __pyx_k_RandomForestClassifier, sizeof(__pyx_k_RandomForestClassifier), 0, 1, 0, 1},
  {&__pyx_kp_s_Registry_class_providing_hyperp, __pyx_k_Registry_class_providing_hyperp, sizeof(__pyx_k_Registry_class_providing_hyperp), 0, 0, 1, 0},
  {&__pyx_n_s_SEED, __pyx_k_SEED, sizeof(__pyx_k_SEED), 0, 0, 1, 1},
  {&__pyx_n_s_SVC, __pyx_k_SVC, sizeof(__pyx_k_SVC), 0, 0, 1, 1},
  {&__pyx_n_s_StandardScaler, __pyx_k_StandardScaler, sizeof(__pyx_k_StandardScaler), 0, 0, 1, 1},
  {&__pyx_n_s_T, __pyx_k_T, sizeof(__pyx_k_T), 0, 0, 1, 1},
  {&__pyx_n_s_TEST_SIZE, __pyx_k_TEST_SIZE, sizeof(__pyx_k_TEST_SIZE), 0, 0, 1, 1},
  {&__pyx_n_s_X, __pyx_k_X, sizeof(__pyx_k_X), 0, 0, 1, 1},
  {&__pyx_n_s_Xi, __pyx_k_Xi, sizeof(__pyx_k_Xi), 0, 0, 1, 1},
  {&__pyx_kp_u__4, __pyx_k__4, sizeof(__pyx_k__4), 0, 1, 0, 0},
  {&__pyx_kp_u__8, __pyx_k__8, sizeof(__pyx_k__8), 0, 1, 0, 0},
  {&__pyx_n_s_ada, __pyx_k_ada, sizeof(__pyx_k_ada), 0, 0, 1, 1},
  {&__pyx_n_u_ada, __pyx_k_ada, sizeof(__pyx_k_ada), 0, 1, 0, 1},
  {&__pyx_n_s_array, __pyx_k_array, sizeof(__pyx_k_array), 0, 0, 1, 1},
  {&__pyx_n_u_auto, __pyx_k_auto, sizeof(__pyx_k_auto), 0, 1, 0, 1},
  {&__pyx_n_s_b, __pyx_k_b, sizeof(__pyx_k_b), 0, 0, 1, 1},
  {&__pyx_n_u_bernoulli_nb, __pyx_k_bernoulli_nb, sizeof(__pyx_k_bernoulli_nb), 0, 1, 0, 1},
  {&__pyx_n_s_bnb, __pyx_k_bnb, sizeof(__pyx_k_bnb), 0, 0, 1, 1},
  {&__pyx_n_s_bootstrap, __pyx_k_bootstrap, sizeof(__pyx_k_bootstrap), 0, 0, 1, 1},
  {&__pyx_n_u_bootstrap, __pyx_k_bootstrap, sizeof(__pyx_k_bootstrap), 0, 1, 0, 1},
  {&__pyx_n_s_cat, __pyx_k_cat, sizeof(__pyx_k_cat), 0, 0, 1, 1},
  {&__pyx_n_u_cats, __pyx_k_cats, sizeof(__pyx_k_cats), 0, 1, 0, 1},
  {&__pyx_n_s_class_weight, __pyx_k_class_weight, sizeof(__pyx_k_class_weight), 0, 0, 1, 1},
  {&__pyx_n_s_clf, __pyx_k_clf, sizeof(__pyx_k_clf), 0, 0, 1, 1},
  {&__pyx_n_u_clf__colsample_bytree, __pyx_k_clf__colsample_bytree, sizeof(__pyx_k_clf__colsample_bytree), 0, 1, 0, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_codes, __pyx_k_codes, sizeof(__pyx_k_codes), 0, 0, 1, 1},
  {&__pyx_n_s_criterion, __pyx_k_criterion, sizeof(__pyx_k_criterion), 0, 0, 1, 1},
  {&__pyx_n_u_decision_tree, __pyx_k_decision_tree, sizeof(__pyx_k_decision_tree), 0, 1, 0, 1},
  {&__pyx_n_s_doc, __pyx_k_doc, sizeof(__pyx_k_doc), 0, 0, 1, 1},
  {&__pyx_n_s_dot, __pyx_k_dot, sizeof(__pyx_k_dot), 0, 0, 1, 1},
  {&__pyx_n_s_e, __pyx_k_e, sizeof(__pyx_k_e), 0, 0, 1, 1},
  {&__pyx_n_s_epochs, __pyx_k_epochs, sizeof(__pyx_k_epochs), 0, 0, 1, 1},
  {&__pyx_n_s_est, __pyx_k_est, sizeof(__pyx_k_est), 0, 0, 1, 1},
  {&__pyx_n_u_extra_trees, __pyx_k_extra_trees, sizeof(__pyx_k_extra_trees), 0, 1, 0, 1},
  {&__pyx_n_s_f, __pyx_k_f, sizeof(__pyx_k_f), 0, 0, 1, 1},
  {&__pyx_n_s_fit, __pyx_k_fit, sizeof(__pyx_k_fit), 0, 0, 1, 1},
  {&__pyx_n_s_fit_intercept, __pyx_k_fit_intercept, sizeof(__pyx_k_fit_intercept), 0, 0, 1, 1},
  {&__pyx_n_s_gbc, __pyx_k_gbc, sizeof(__pyx_k_gbc), 0, 0, 1, 1},
  {&__pyx_n_u_gbc, __pyx_k_gbc, sizeof(__pyx_k_gbc), 0, 1, 0, 1},
  {&__pyx_n_s_get, __pyx_k_get, sizeof(__pyx_k_get), 0, 0, 1, 1},
  {&__pyx_n_s_gettattr, __pyx_k_gettattr, sizeof(__pyx_k_gettattr), 0, 0, 1, 1},
  {&__pyx_n_u_gini, __pyx_k_gini, sizeof(__pyx_k_gini), 0, 1, 0, 1},
  {&__pyx_n_s_gnb, __pyx_k_gnb, sizeof(__pyx_k_gnb), 0, 0, 1, 1},
  {&__pyx_n_u_gnb, __pyx_k_gnb, sizeof(__pyx_k_gnb), 0, 1, 0, 1},
  {&__pyx_n_s_grid, __pyx_k_grid, sizeof(__pyx_k_grid), 0, 0, 1, 1},
  {&__pyx_n_s_high, __pyx_k_high, sizeof(__pyx_k_high), 0, 0, 1, 1},
  {&__pyx_n_s_history, __pyx_k_history, sizeof(__pyx_k_history), 0, 0, 1, 1},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_init, __pyx_k_init, sizeof(__pyx_k_init), 0, 0, 1, 1},
  {&__pyx_n_s_kernel, __pyx_k_kernel, sizeof(__pyx_k_kernel), 0, 0, 1, 1},
  {&__pyx_n_s_knn, __pyx_k_knn, sizeof(__pyx_k_knn), 0, 0, 1, 1},
  {&__pyx_n_u_knn, __pyx_k_knn, sizeof(__pyx_k_knn), 0, 1, 0, 1},
  {&__pyx_n_s_lda, __pyx_k_lda, sizeof(__pyx_k_lda), 0, 0, 1, 1},
  {&__pyx_n_u_lda, __pyx_k_lda, sizeof(__pyx_k_lda), 0, 1, 0, 1},
  {&__pyx_n_s_learning_rate, __pyx_k_learning_rate, sizeof(__pyx_k_learning_rate), 0, 0, 1, 1},
  {&__pyx_n_u_learning_rate, __pyx_k_learning_rate, sizeof(__pyx_k_learning_rate), 0, 1, 0, 1},
  {&__pyx_n_u_lgbm, __pyx_k_lgbm, sizeof(__pyx_k_lgbm), 0, 1, 0, 1},
  {&__pyx_n_u_linear, __pyx_k_linear, sizeof(__pyx_k_linear), 0, 1, 0, 1},
  {&__pyx_n_s_linspace, __pyx_k_linspace, sizeof(__pyx_k_linspace), 0, 0, 1, 1},
  {&__pyx_n_s_loss, __pyx_k_loss, sizeof(__pyx_k_loss), 0, 0, 1, 1},
  {&__pyx_n_s_low, __pyx_k_low, sizeof(__pyx_k_low), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_s_max_depth, __pyx_k_max_depth, sizeof(__pyx_k_max_depth), 0, 0, 1, 1},
  {&__pyx_n_u_max_depth, __pyx_k_max_depth, sizeof(__pyx_k_max_depth), 0, 1, 0, 1},
  {&__pyx_n_u_max_df, __pyx_k_max_df, sizeof(__pyx_k_max_df), 0, 1, 0, 1},
  {&__pyx_n_s_max_features, __pyx_k_max_features, sizeof(__pyx_k_max_features), 0, 0, 1, 1},
  {&__pyx_n_u_max_features, __pyx_k_max_features, sizeof(__pyx_k_max_features), 0, 1, 0, 1},
  {&__pyx_n_s_max_leaf_nodes, __pyx_k_max_leaf_nodes, sizeof(__pyx_k_max_leaf_nodes), 0, 0, 1, 1},
  {&__pyx_n_s_mean_squared_error, __pyx_k_mean_squared_error, sizeof(__pyx_k_mean_squared_error), 0, 0, 1, 1},
  {&__pyx_n_s_metaclass, __pyx_k_metaclass, sizeof(__pyx_k_metaclass), 0, 0, 1, 1},
  {&__pyx_n_s_min_impurity_split, __pyx_k_min_impurity_split, sizeof(__pyx_k_min_impurity_split), 0, 0, 1, 1},
  {&__pyx_n_s_min_samples_leaf, __pyx_k_min_samples_leaf, sizeof(__pyx_k_min_samples_leaf), 0, 0, 1, 1},
  {&__pyx_n_u_min_samples_leaf, __pyx_k_min_samples_leaf, sizeof(__pyx_k_min_samples_leaf), 0, 1, 0, 1},
  {&__pyx_n_s_min_samples_split, __pyx_k_min_samples_split, sizeof(__pyx_k_min_samples_split), 0, 0, 1, 1},
  {&__pyx_n_u_min_samples_split, __pyx_k_min_samples_split, sizeof(__pyx_k_min_samples_split), 0, 1, 0, 1},
  {&__pyx_n_s_min_weight_fraction_leaf, __pyx_k_min_weight_fraction_leaf, sizeof(__pyx_k_min_weight_fraction_leaf), 0, 0, 1, 1},
  {&__pyx_n_s_mnb, __pyx_k_mnb, sizeof(__pyx_k_mnb), 0, 0, 1, 1},
  {&__pyx_n_u_mnb, __pyx_k_mnb, sizeof(__pyx_k_mnb), 0, 1, 0, 1},
  {&__pyx_n_s_models, __pyx_k_models, sizeof(__pyx_k_models), 0, 0, 1, 1},
  {&__pyx_kp_s_models_py, __pyx_k_models_py, sizeof(__pyx_k_models_py), 0, 0, 1, 0},
  {&__pyx_n_s_module, __pyx_k_module, sizeof(__pyx_k_module), 0, 0, 1, 1},
  {&__pyx_n_s_n_estimators, __pyx_k_n_estimators, sizeof(__pyx_k_n_estimators), 0, 0, 1, 1},
  {&__pyx_n_u_n_estimators, __pyx_k_n_estimators, sizeof(__pyx_k_n_estimators), 0, 1, 0, 1},
  {&__pyx_n_s_n_jobs, __pyx_k_n_jobs, sizeof(__pyx_k_n_jobs), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_np, __pyx_k_np, sizeof(__pyx_k_np), 0, 0, 1, 1},
  {&__pyx_n_s_num, __pyx_k_num, sizeof(__pyx_k_num), 0, 0, 1, 1},
  {&__pyx_n_s_numpy, __pyx_k_numpy, sizeof(__pyx_k_numpy), 0, 0, 1, 1},
  {&__pyx_n_s_object, __pyx_k_object, sizeof(__pyx_k_object), 0, 0, 1, 1},
  {&__pyx_n_s_oob_score, __pyx_k_oob_score, sizeof(__pyx_k_oob_score), 0, 0, 1, 1},
  {&__pyx_n_s_os, __pyx_k_os, sizeof(__pyx_k_os), 0, 0, 1, 1},
  {&__pyx_n_s_pandas, __pyx_k_pandas, sizeof(__pyx_k_pandas), 0, 0, 1, 1},
  {&__pyx_n_s_param, __pyx_k_param, sizeof(__pyx_k_param), 0, 0, 1, 1},
  {&__pyx_n_s_pav, __pyx_k_pav, sizeof(__pyx_k_pav), 0, 0, 1, 1},
  {&__pyx_n_u_pav, __pyx_k_pav, sizeof(__pyx_k_pav), 0, 1, 0, 1},
  {&__pyx_n_s_pd, __pyx_k_pd, sizeof(__pyx_k_pd), 0, 0, 1, 1},
  {&__pyx_n_s_pprint, __pyx_k_pprint, sizeof(__pyx_k_pprint), 0, 0, 1, 1},
  {&__pyx_n_s_predict, __pyx_k_predict, sizeof(__pyx_k_predict), 0, 0, 1, 1},
  {&__pyx_n_s_prepare, __pyx_k_prepare, sizeof(__pyx_k_prepare), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_s_qda, __pyx_k_qda, sizeof(__pyx_k_qda), 0, 0, 1, 1},
  {&__pyx_n_u_qda, __pyx_k_qda, sizeof(__pyx_k_qda), 0, 1, 0, 1},
  {&__pyx_n_s_qualname, __pyx_k_qualname, sizeof(__pyx_k_qualname), 0, 0, 1, 1},
  {&__pyx_n_s_random_state, __pyx_k_random_state, sizeof(__pyx_k_random_state), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_re, __pyx_k_re, sizeof(__pyx_k_re), 0, 0, 1, 1},
  {&__pyx_n_s_reshape, __pyx_k_reshape, sizeof(__pyx_k_reshape), 0, 0, 1, 1},
  {&__pyx_n_s_reshape_cat_series, __pyx_k_reshape_cat_series, sizeof(__pyx_k_reshape_cat_series), 0, 0, 1, 1},
  {&__pyx_n_s_rfc, __pyx_k_rfc, sizeof(__pyx_k_rfc), 0, 0, 1, 1},
  {&__pyx_n_u_rfc, __pyx_k_rfc, sizeof(__pyx_k_rfc), 0, 1, 0, 1},
  {&__pyx_n_s_self, __pyx_k_self, sizeof(__pyx_k_self), 0, 0, 1, 1},
  {&__pyx_n_s_sgd, __pyx_k_sgd, sizeof(__pyx_k_sgd), 0, 0, 1, 1},
  {&__pyx_n_u_sgd, __pyx_k_sgd, sizeof(__pyx_k_sgd), 0, 1, 0, 1},
  {&__pyx_n_s_shape, __pyx_k_shape, sizeof(__pyx_k_shape), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn, __pyx_k_sklearn, sizeof(__pyx_k_sklearn), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_discriminant_analysis, __pyx_k_sklearn_discriminant_analysis, sizeof(__pyx_k_sklearn_discriminant_analysis), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_ensemble, __pyx_k_sklearn_ensemble, sizeof(__pyx_k_sklearn_ensemble), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_linear_model, __pyx_k_sklearn_linear_model, sizeof(__pyx_k_sklearn_linear_model), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_metrics, __pyx_k_sklearn_metrics, sizeof(__pyx_k_sklearn_metrics), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_naive_bayes, __pyx_k_sklearn_naive_bayes, sizeof(__pyx_k_sklearn_naive_bayes), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_neighbors, __pyx_k_sklearn_neighbors, sizeof(__pyx_k_sklearn_neighbors), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_preprocessing, __pyx_k_sklearn_preprocessing, sizeof(__pyx_k_sklearn_preprocessing), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_svm, __pyx_k_sklearn_svm, sizeof(__pyx_k_sklearn_svm), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_tree, __pyx_k_sklearn_tree, sizeof(__pyx_k_sklearn_tree), 0, 0, 1, 1},
  {&__pyx_n_u_sqrt, __pyx_k_sqrt, sizeof(__pyx_k_sqrt), 0, 1, 0, 1},
  {&__pyx_n_s_start, __pyx_k_start, sizeof(__pyx_k_start), 0, 0, 1, 1},
  {&__pyx_n_s_stop, __pyx_k_stop, sizeof(__pyx_k_stop), 0, 0, 1, 1},
  {&__pyx_n_u_subsample, __pyx_k_subsample, sizeof(__pyx_k_subsample), 0, 1, 0, 1},
  {&__pyx_n_s_sum, __pyx_k_sum, sizeof(__pyx_k_sum), 0, 0, 1, 1},
  {&__pyx_n_s_svm, __pyx_k_svm, sizeof(__pyx_k_svm), 0, 0, 1, 1},
  {&__pyx_n_u_svm, __pyx_k_svm, sizeof(__pyx_k_svm), 0, 1, 0, 1},
  {&__pyx_kp_u_svm_SVC, __pyx_k_svm_SVC, sizeof(__pyx_k_svm_SVC), 0, 1, 0, 0},
  {&__pyx_kp_u_svm_SVC_linear_kernel, __pyx_k_svm_SVC_linear_kernel, sizeof(__pyx_k_svm_SVC_linear_kernel), 0, 1, 0, 0},
  {&__pyx_n_s_svml, __pyx_k_svml, sizeof(__pyx_k_svml), 0, 0, 1, 1},
  {&__pyx_n_u_svml, __pyx_k_svml, sizeof(__pyx_k_svml), 0, 1, 0, 1},
  {&__pyx_n_s_target, __pyx_k_target, sizeof(__pyx_k_target), 0, 0, 1, 1},
  {&__pyx_n_u_target, __pyx_k_target, sizeof(__pyx_k_target), 0, 1, 0, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_tfidf, __pyx_k_tfidf, sizeof(__pyx_k_tfidf), 0, 0, 1, 1},
  {&__pyx_n_s_tfidf_hyperparams, __pyx_k_tfidf_hyperparams, sizeof(__pyx_k_tfidf_hyperparams), 0, 0, 1, 1},
  {&__pyx_n_s_to_frame, __pyx_k_to_frame, sizeof(__pyx_k_to_frame), 0, 0, 1, 1},
  {&__pyx_n_s_update_hyperparam_range, __pyx_k_update_hyperparam_range, sizeof(__pyx_k_update_hyperparam_range), 0, 0, 1, 1},
  {&__pyx_n_s_values, __pyx_k_values, sizeof(__pyx_k_values), 0, 0, 1, 1},
  {&__pyx_n_s_verbose, __pyx_k_verbose, sizeof(__pyx_k_verbose), 0, 0, 1, 1},
  {&__pyx_n_s_w, __pyx_k_w, sizeof(__pyx_k_w), 0, 0, 1, 1},
  {&__pyx_n_s_warm_start, __pyx_k_warm_start, sizeof(__pyx_k_warm_start), 0, 0, 1, 1},
  {&__pyx_n_s_x, __pyx_k_x, sizeof(__pyx_k_x), 0, 0, 1, 1},
  {&__pyx_n_s_xg_param_grid, __pyx_k_xg_param_grid, sizeof(__pyx_k_xg_param_grid), 0, 0, 1, 1},
  {&__pyx_n_u_xgb, __pyx_k_xgb, sizeof(__pyx_k_xgb), 0, 1, 0, 1},
  {&__pyx_n_u_xgbp, __pyx_k_xgbp, sizeof(__pyx_k_xgbp), 0, 1, 0, 1},
  {&__pyx_n_s_y, __pyx_k_y, sizeof(__pyx_k_y), 0, 0, 1, 1},
  {&__pyx_n_s_yi, __pyx_k_yi, sizeof(__pyx_k_yi), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_object = __Pyx_GetBuiltinName(__pyx_n_s_object); if (!__pyx_builtin_object) __PYX_ERR(0, 30, __pyx_L1_error)
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 214, __pyx_L1_error)
  __pyx_builtin_print = __Pyx_GetBuiltinName(__pyx_n_s_print); if (!__pyx_builtin_print) __PYX_ERR(0, 231, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  /* "models.py":98
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]
 *         max_features = ['auto', 'sqrt']
 *         max_depth = [int(x) for x in np.linspace(10, 110, num = 11)]             # <<<<<<<<<<<<<<
 *         max_depth.append(None)
 *         min_samples_split = [2, 5, 10]
 */
  __pyx_tuple_ = PyTuple_Pack(2, __pyx_int_10, __pyx_int_110); if (unlikely(!__pyx_tuple_)) __PYX_ERR(0, 98, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple_);
  __Pyx_GIVEREF(__pyx_tuple_);

  /* "models.py":201
 *         y['cats'] = y['target'].cat.codes
 *         y = y['cats'].values
 *         y = np.reshape(np.array(y), (-1, 1)) # (bc we're passing a frame.)             # <<<<<<<<<<<<<<
 *
 *         return y
 */
  __pyx_tuple__2 = PyTuple_Pack(2, __pyx_int_neg_1, __pyx_int_1); if (unlikely(!__pyx_tuple__2)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__2);
  __Pyx_GIVEREF(__pyx_tuple__2);

  /* "models.py":217
 *
 *             for i in range(N):
 *                 Xi = X[i, :]             # <<<<<<<<<<<<<<
 *                 yi = y[i, :]
 *
 */
  __pyx_slice__3 = PySlice_New(Py_None, Py_None, Py_None); if (unlikely(!__pyx_slice__3)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__3);
  __Pyx_GIVEREF(__pyx_slice__3);

  /* "models.py":30
 *
 * # TODO: Refactor
 * class Classifiers(object):             # <<<<<<<<<<<<<<
 *     def __init__(self):
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 */
  __pyx_tuple__5 = PyTuple_Pack(1, __pyx_builtin_object); if (unlikely(!__pyx_tuple__5)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__5);
  __Pyx_GIVEREF(__pyx_tuple__5);

  /* "models.py":31
 * # TODO: Refactor
 * class Classifiers(object):
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 *         #self.adt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1), n_estimators=N_EST),
 */
  __pyx_tuple__6 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__6)) __PYX_ERR(0, 31, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__6);
  __Pyx_GIVEREF(__pyx_tuple__6);
  __pyx_codeobj__7 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__6, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_init, 31, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__7)) __PYX_ERR(0, 31, __pyx_L1_error)

  /* "models.py":72
 *     """ Registry class providing hyperparameter search space.
 *     @TODO: Provide private method to update a grid param range. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__9 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__9)) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__9);
  __Pyx_GIVEREF(__pyx_tuple__9);
  __pyx_codeobj__10 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__9, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_init, 72, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__10)) __PYX_ERR(0, 72, __pyx_L1_error)

  /* "models.py":75
 *         pass
 *
 *     def grid(self, est):             # <<<<<<<<<<<<<<
 *         return getattr(self, est)()
 *
 */
  __pyx_tuple__11 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_est); if (unlikely(!__pyx_tuple__11)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__11);
  __Pyx_GIVEREF(__pyx_tuple__11);
  __pyx_codeobj__12 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__11, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_grid, 75, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__12)) __PYX_ERR(0, 75, __pyx_L1_error)

  /* "models.py":78
 *         return getattr(self, est)()
 *
 *     def update_hyperparam_range(self, est, param, high, low):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__13 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_est, __pyx_n_s_param, __pyx_n_s_high, __pyx_n_s_low); if (unlikely(!__pyx_tuple__13)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__13);
  __Pyx_GIVEREF(__pyx_tuple__13);
  __pyx_codeobj__14 = (PyObject*)__Pyx_PyCode_New(5, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__13, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_update_hyperparam_range, 78, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__14)) __PYX_ERR(0, 78, __pyx_L1_error)

  /* "models.py":81
 *         pass
 *
 *     def tfidf(self):             # <<<<<<<<<<<<<<
 *
 *         tfidf_hyperparams = {
 */
  __pyx_tuple__15 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_tfidf_hyperparams); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 81, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);
  __pyx_codeobj__16 = (PyObject*)__Pyx_PyCode_New(1, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__15, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_tfidf, 81, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__16)) __PYX_ERR(0, 81, __pyx_L1_error)

  /* "models.py":94
 *         return tfidf_hyperparams
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]
 */
  __pyx_tuple__17 = PyTuple_Pack(10, __pyx_n_s_self, __pyx_n_s_n_estimators, __pyx_n_s_max_features, __pyx_n_s_max_depth, __pyx_n_s_min_samples_split, __pyx_n_s_min_samples_leaf, __pyx_n_s_bootstrap, __pyx_n_s_grid, __pyx_n_s_x, __pyx_n_s_x); if (unlikely(!__pyx_tuple__17)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__17);
  __Pyx_GIVEREF(__pyx_tuple__17);
  __pyx_codeobj__18 = (PyObject*)__Pyx_PyCode_New(1, 0, 10, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__17, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_rfc, 94, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__18)) __PYX_ERR(0, 94, __pyx_L1_error)

  /* "models.py":121
 *         """
 *
 *     def gbc(self):             # <<<<<<<<<<<<<<
 *         grid = {'learning_rate': [0.01,0.02,0.03],
 *             'subsample'    : [0.9, 0.5, 0.2],
 */
  __pyx_tuple__19 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_grid); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);
  __pyx_codeobj__20 = (PyObject*)__Pyx_PyCode_New(1, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__19, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_gbc, 121, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__20)) __PYX_ERR(0, 121, __pyx_L1_error)

  /* "models.py":154
 *         """
 *
 * class Params(object):             # <<<<<<<<<<<<<<
 *     """ Provides default parameters for a given model. """
 *     def __init__(self):
 */
  __pyx_tuple__21 = PyTuple_Pack(1, __pyx_builtin_object); if (unlikely(!__pyx_tuple__21)) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__21);
  __Pyx_GIVEREF(__pyx_tuple__21);

  /* "models.py":156
 * class Params(object):
 *     """ Provides default parameters for a given model. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__22 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__22)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__22);
  __Pyx_GIVEREF(__pyx_tuple__22);
  __pyx_codeobj__23 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__22, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_init, 156, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__23)) __PYX_ERR(0, 156, __pyx_L1_error)

  /* "models.py":159
 *         pass
 *
 *     def get(self, est):             # <<<<<<<<<<<<<<
 *         return self.gettattr(self, est)
 *
 */
  __pyx_tuple__24 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_est); if (unlikely(!__pyx_tuple__24)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__24);
  __Pyx_GIVEREF(__pyx_tuple__24);
  __pyx_codeobj__25 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__24, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_get, 159, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__25)) __PYX_ERR(0, 159, __pyx_L1_error)

  /* "models.py":162
 *         return self.gettattr(self, est)
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *         return dict(
 *             bootstrap=True,
 */
  __pyx_tuple__26 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__26)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__26);
  __Pyx_GIVEREF(__pyx_tuple__26);
  __pyx_codeobj__27 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__26, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_rfc, 162, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__27)) __PYX_ERR(0, 162, __pyx_L1_error)

  /* "models.py":187
 * import pandas as pd
 * from sklearn.metrics import mean_squared_error
 * class GradientDescent(object):             # <<<<<<<<<<<<<<
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):
 */
  __pyx_tuple__28 = PyTuple_Pack(1, __pyx_builtin_object); if (unlikely(!__pyx_tuple__28)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__28);
  __Pyx_GIVEREF(__pyx_tuple__28);

  /* "models.py":189
 * class GradientDescent(object):
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */
  __pyx_tuple__29 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_learning_rate); if (unlikely(!__pyx_tuple__29)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__29);
  __Pyx_GIVEREF(__pyx_tuple__29);
  __pyx_codeobj__30 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__29, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_init, 189, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__30)) __PYX_ERR(0, 189, __pyx_L1_error)
  __pyx_tuple__31 = PyTuple_Pack(1, ((PyObject*)__pyx_float_0_01)); if (unlikely(!__pyx_tuple__31)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__31);
  __Pyx_GIVEREF(__pyx_tuple__31);

  /* "models.py":194
 *         self.b = 0
 *
 *     def reshape_cat_series(self, y):             # <<<<<<<<<<<<<<
 *         """ If we get passed a series of strings, convert to matrix of int values.
 *             Obviously, this is a workaround (here) and needs to be refactored. """
 */
  __pyx_tuple__32 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_y); if (unlikely(!__pyx_tuple__32)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__32);
  __Pyx_GIVEREF(__pyx_tuple__32);
  __pyx_codeobj__33 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__32, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_reshape_cat_series, 194, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__33)) __PYX_ERR(0, 194, __pyx_L1_error)

  /* "models.py":205
 *         return y
 *
 *     def fit(self, X, y, epochs = 2):             # <<<<<<<<<<<<<<
 *         """
 *         :param X: scipy.sparse.csr.csr_matrix
 */
  __pyx_tuple__34 = PyTuple_Pack(12, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y, __pyx_n_s_epochs, __pyx_n_s_N, __pyx_n_s_history, __pyx_n_s_e, __pyx_n_s_i, __pyx_n_s_Xi, __pyx_n_s_yi, __pyx_n_s_f, __pyx_n_s_loss); if (unlikely(!__pyx_tuple__34)) __PYX_ERR(0, 205, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__34);
  __Pyx_GIVEREF(__pyx_tuple__34);
  __pyx_codeobj__35 = (PyObject*)__Pyx_PyCode_New(4, 0, 12, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__34, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_fit, 205, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__35)) __PYX_ERR(0, 205, __pyx_L1_error)
  __pyx_tuple__36 = PyTuple_Pack(1, ((PyObject *)__pyx_int_2)); if (unlikely(!__pyx_tuple__36)) __PYX_ERR(0, 205, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__36);
  __Pyx_GIVEREF(__pyx_tuple__36);

  /* "models.py":237
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */
  __pyx_tuple__37 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__37)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__37);
  __Pyx_GIVEREF(__pyx_tuple__37);
  __pyx_codeobj__38 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__37, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_predict, 237, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__38)) __PYX_ERR(0, 237, __pyx_L1_error)

  /* "models.py":241
 *
 * class BatchGradientDescent():
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */
  __pyx_tuple__39 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_learning_rate); if (unlikely(!__pyx_tuple__39)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__39);
  __Pyx_GIVEREF(__pyx_tuple__39);
  __pyx_codeobj__40 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__39, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_init, 241, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__40)) __PYX_ERR(0, 241, __pyx_L1_error)
  __pyx_tuple__41 = PyTuple_Pack(1, ((PyObject*)__pyx_float_0_01)); if (unlikely(!__pyx_tuple__41)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__41);
  __Pyx_GIVEREF(__pyx_tuple__41);

  /* "models.py":246
 *         self.b = 0
 *
 *     def fit(self, X, y, epochs = 100):             # <<<<<<<<<<<<<<
 *         N = len(X)
 *         history = []
 */
  __pyx_tuple__42 = PyTuple_Pack(9, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y, __pyx_n_s_epochs, __pyx_n_s_N, __pyx_n_s_history, __pyx_n_s_e, __pyx_n_s_f, __pyx_n_s_loss); if (unlikely(!__pyx_tuple__42)) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__42);
  __Pyx_GIVEREF(__pyx_tuple__42);
  __pyx_codeobj__43 = (PyObject*)__Pyx_PyCode_New(4, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__42, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_fit, 246, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__43)) __PYX_ERR(0, 246, __pyx_L1_error)
  __pyx_tuple__44 = PyTuple_Pack(1, ((PyObject *)__pyx_int_100)); if (unlikely(!__pyx_tuple__44)) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__44);
  __Pyx_GIVEREF(__pyx_tuple__44);

  /* "models.py":265
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */
  __pyx_tuple__45 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__45)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__45);
  __Pyx_GIVEREF(__pyx_tuple__45);
  __pyx_codeobj__46 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__45, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_predict, 265, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__46)) __PYX_ERR(0, 265, __pyx_L1_error)

  /* "models.py":360
 *
 * class LR():
 *     def __init__(self, X, y):             # <<<<<<<<<<<<<<
 *         return LR(fit_intercept=False).fit(X,y)
 *
 */
  __pyx_tuple__47 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__47)) __PYX_ERR(0, 360, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__47);
  __Pyx_GIVEREF(__pyx_tuple__47);
  __pyx_codeobj__48 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__47, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_models_py, __pyx_n_s_init, 360, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__48)) __PYX_ERR(0, 360, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_float_0_0 = PyFloat_FromDouble(0.0); if (unlikely(!__pyx_float_0_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_2 = PyFloat_FromDouble(0.2); if (unlikely(!__pyx_float_0_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_5 = PyFloat_FromDouble(0.5); if (unlikely(!__pyx_float_0_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_7 = PyFloat_FromDouble(0.7); if (unlikely(!__pyx_float_0_7)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_9 = PyFloat_FromDouble(0.9); if (unlikely(!__pyx_float_0_9)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_1_0 = PyFloat_FromDouble(1.0); if (unlikely(!__pyx_float_1_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_01 = PyFloat_FromDouble(0.01); if (unlikely(!__pyx_float_0_01)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_02 = PyFloat_FromDouble(0.02); if (unlikely(!__pyx_float_0_02)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_03 = PyFloat_FromDouble(0.03); if (unlikely(!__pyx_float_0_03)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_0_95 = PyFloat_FromDouble(0.95); if (unlikely(!__pyx_float_0_95)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_10_0 = PyFloat_FromDouble(10.0); if (unlikely(!__pyx_float_10_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_1eneg_07 = PyFloat_FromDouble(1e-07); if (unlikely(!__pyx_float_1eneg_07)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_2 = PyInt_FromLong(2); if (unlikely(!__pyx_int_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4 = PyInt_FromLong(4); if (unlikely(!__pyx_int_4)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_5 = PyInt_FromLong(5); if (unlikely(!__pyx_int_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_6 = PyInt_FromLong(6); if (unlikely(!__pyx_int_6)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_8 = PyInt_FromLong(8); if (unlikely(!__pyx_int_8)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_10 = PyInt_FromLong(10); if (unlikely(!__pyx_int_10)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_11 = PyInt_FromLong(11); if (unlikely(!__pyx_int_11)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_42 = PyInt_FromLong(42); if (unlikely(!__pyx_int_42)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_50 = PyInt_FromLong(50); if (unlikely(!__pyx_int_50)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_100 = PyInt_FromLong(100); if (unlikely(!__pyx_int_100)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_110 = PyInt_FromLong(110); if (unlikely(!__pyx_int_110)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_200 = PyInt_FromLong(200); if (unlikely(!__pyx_int_200)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_500 = PyInt_FromLong(500); if (unlikely(!__pyx_int_500)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1000 = PyInt_FromLong(1000); if (unlikely(!__pyx_int_1000)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_2000 = PyInt_FromLong(2000); if (unlikely(!__pyx_int_2000)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_neg_1 = PyInt_FromLong(-1); if (unlikely(!__pyx_int_neg_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_neg_2 = PyInt_FromLong(-2); if (unlikely(!__pyx_int_neg_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); /*proto*/

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  /*--- Global init code ---*/
  __pyx_8genexpr2__pyx_v_6models_i = Py_None; Py_INCREF(Py_None);
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  /*--- Variable export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  /*--- Function export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  /*--- Type init code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  /*--- Type import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  /*--- Variable import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  /*--- Function import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initmodels(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC initmodels(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_models(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC PyInit_models(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_models(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  long __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'models' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_models(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  /*--- Library function declarations ---*/
  /*--- Threads initialization code ---*/
  #if defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  #ifdef WITH_THREAD /* Python build with threading support? */
  PyEval_InitThreads();
  #endif
  #endif
  /*--- Module creation code ---*/
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("models", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  /*--- Initialize various global constants etc. ---*/
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_models) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "models")) {
      if (unlikely(PyDict_SetItemString(modules, "models", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  /*--- Builtin init code ---*/
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Constants init code ---*/
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Global type/function init code ---*/
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  (void)__Pyx_modinit_type_init_code();
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  /*--- Execution code ---*/
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  /* "models.py":3
 * #lib/ext/models.py -  Pre-parameterised models for quick exploration
 *
 * import os             # <<<<<<<<<<<<<<
 * import re
 * import pprint
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_os, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_os, __pyx_t_1) < 0) __PYX_ERR(0, 3, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":4
 *
 * import os
 * import re             # <<<<<<<<<<<<<<
 * import pprint
 *
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_re, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_re, __pyx_t_1) < 0) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":5
 * import os
 * import re
 * import pprint             # <<<<<<<<<<<<<<
 *
 * import numpy as np
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_pprint, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_pprint, __pyx_t_1) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":7
 * import pprint
 *
 * import numpy as np             # <<<<<<<<<<<<<<
 * from sklearn.preprocessing import StandardScaler, MinMaxScaler
 * from sklearn.neighbors import KNeighborsClassifier
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_numpy, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_np, __pyx_t_1) < 0) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":8
 *
 * import numpy as np
 * from sklearn.preprocessing import StandardScaler, MinMaxScaler             # <<<<<<<<<<<<<<
 * from sklearn.neighbors import KNeighborsClassifier
 * from sklearn.ensemble import AdaBoostClassifier, GradientBoostingClassifier, RandomForestClassifier
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_StandardScaler);
  __Pyx_GIVEREF(__pyx_n_s_StandardScaler);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_StandardScaler);
  __Pyx_INCREF(__pyx_n_s_MinMaxScaler);
  __Pyx_GIVEREF(__pyx_n_s_MinMaxScaler);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_MinMaxScaler);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_preprocessing, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_StandardScaler, __pyx_t_1) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_MinMaxScaler); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MinMaxScaler, __pyx_t_1) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":9
 * import numpy as np
 * from sklearn.preprocessing import StandardScaler, MinMaxScaler
 * from sklearn.neighbors import KNeighborsClassifier             # <<<<<<<<<<<<<<
 * from sklearn.ensemble import AdaBoostClassifier, GradientBoostingClassifier, RandomForestClassifier
 * from sklearn.naive_bayes import BernoulliNB, GaussianNB, MultinomialNB
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_KNeighborsClassifier);
  __Pyx_GIVEREF(__pyx_n_s_KNeighborsClassifier);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_KNeighborsClassifier);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_neighbors, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_KNeighborsClassifier); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_KNeighborsClassifier, __pyx_t_2) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":10
 * from sklearn.preprocessing import StandardScaler, MinMaxScaler
 * from sklearn.neighbors import KNeighborsClassifier
 * from sklearn.ensemble import AdaBoostClassifier, GradientBoostingClassifier, RandomForestClassifier             # <<<<<<<<<<<<<<
 * from sklearn.naive_bayes import BernoulliNB, GaussianNB, MultinomialNB
 * from sklearn.tree import DecisionTreeClassifier
 */
  __pyx_t_1 = PyList_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_AdaBoostClassifier);
  __Pyx_GIVEREF(__pyx_n_s_AdaBoostClassifier);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_AdaBoostClassifier);
  __Pyx_INCREF(__pyx_n_s_GradientBoostingClassifier);
  __Pyx_GIVEREF(__pyx_n_s_GradientBoostingClassifier);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_GradientBoostingClassifier);
  __Pyx_INCREF(__pyx_n_s_RandomForestClassifier);
  __Pyx_GIVEREF(__pyx_n_s_RandomForestClassifier);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_n_s_RandomForestClassifier);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_ensemble, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_AdaBoostClassifier); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_AdaBoostClassifier, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_GradientBoostingClassifier); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_GradientBoostingClassifier, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_RandomForestClassifier); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_RandomForestClassifier, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":11
 * from sklearn.neighbors import KNeighborsClassifier
 * from sklearn.ensemble import AdaBoostClassifier, GradientBoostingClassifier, RandomForestClassifier
 * from sklearn.naive_bayes import BernoulliNB, GaussianNB, MultinomialNB             # <<<<<<<<<<<<<<
 * from sklearn.tree import DecisionTreeClassifier
 * from sklearn.linear_model import PassiveAggressiveClassifier
 */
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_BernoulliNB);
  __Pyx_GIVEREF(__pyx_n_s_BernoulliNB);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_BernoulliNB);
  __Pyx_INCREF(__pyx_n_s_GaussianNB);
  __Pyx_GIVEREF(__pyx_n_s_GaussianNB);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_n_s_GaussianNB);
  __Pyx_INCREF(__pyx_n_s_MultinomialNB);
  __Pyx_GIVEREF(__pyx_n_s_MultinomialNB);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_n_s_MultinomialNB);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_naive_bayes, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_BernoulliNB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_BernoulliNB, __pyx_t_2) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_GaussianNB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_GaussianNB, __pyx_t_2) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_MultinomialNB); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MultinomialNB, __pyx_t_2) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":12
 * from sklearn.ensemble import AdaBoostClassifier, GradientBoostingClassifier, RandomForestClassifier
 * from sklearn.naive_bayes import BernoulliNB, GaussianNB, MultinomialNB
 * from sklearn.tree import DecisionTreeClassifier             # <<<<<<<<<<<<<<
 * from sklearn.linear_model import PassiveAggressiveClassifier
 * from sklearn.discriminant_analysis import LinearDiscriminantAnalysis, QuadraticDiscriminantAnalysis
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_DecisionTreeClassifier);
  __Pyx_GIVEREF(__pyx_n_s_DecisionTreeClassifier);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_DecisionTreeClassifier);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_tree, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_DecisionTreeClassifier); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_DecisionTreeClassifier, __pyx_t_1) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":13
 * from sklearn.naive_bayes import BernoulliNB, GaussianNB, MultinomialNB
 * from sklearn.tree import DecisionTreeClassifier
 * from sklearn.linear_model import PassiveAggressiveClassifier             # <<<<<<<<<<<<<<
 * from sklearn.discriminant_analysis import LinearDiscriminantAnalysis, QuadraticDiscriminantAnalysis
 * from sklearn import svm
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_PassiveAggressiveClassifier);
  __Pyx_GIVEREF(__pyx_n_s_PassiveAggressiveClassifier);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_PassiveAggressiveClassifier);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_linear_model, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_PassiveAggressiveClassifier); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_PassiveAggressiveClassifier, __pyx_t_2) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":14
 * from sklearn.tree import DecisionTreeClassifier
 * from sklearn.linear_model import PassiveAggressiveClassifier
 * from sklearn.discriminant_analysis import LinearDiscriminantAnalysis, QuadraticDiscriminantAnalysis             # <<<<<<<<<<<<<<
 * from sklearn import svm
 * from sklearn.svm import SVC
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_LinearDiscriminantAnalysis);
  __Pyx_GIVEREF(__pyx_n_s_LinearDiscriminantAnalysis);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_LinearDiscriminantAnalysis);
  __Pyx_INCREF(__pyx_n_s_QuadraticDiscriminantAnalysis);
  __Pyx_GIVEREF(__pyx_n_s_QuadraticDiscriminantAnalysis);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_QuadraticDiscriminantAnalysis);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_discriminant_analysis, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_LinearDiscriminantAnalysis); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_LinearDiscriminantAnalysis, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_QuadraticDiscriminantAnalysis); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_QuadraticDiscriminantAnalysis, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":15
 * from sklearn.linear_model import PassiveAggressiveClassifier
 * from sklearn.discriminant_analysis import LinearDiscriminantAnalysis, QuadraticDiscriminantAnalysis
 * from sklearn import svm             # <<<<<<<<<<<<<<
 * from sklearn.svm import SVC
 * # from xgboost.sklearn import XGBClassifier # Not natively supported on MacOS? (Clang)
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_svm);
  __Pyx_GIVEREF(__pyx_n_s_svm);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_svm);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_svm); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_svm, __pyx_t_2) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":16
 * from sklearn.discriminant_analysis import LinearDiscriminantAnalysis, QuadraticDiscriminantAnalysis
 * from sklearn import svm
 * from sklearn.svm import SVC             # <<<<<<<<<<<<<<
 * # from xgboost.sklearn import XGBClassifier # Not natively supported on MacOS? (Clang)
 * # from sklearn.preprocessing import LabelEncoder
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_SVC);
  __Pyx_GIVEREF(__pyx_n_s_SVC);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_SVC);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_svm, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_SVC); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_SVC, __pyx_t_1) < 0) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":24
 *
 * # Please kill.
 * TEST_SIZE=0.7             # <<<<<<<<<<<<<<
 * N_EST=100
 * SEED=42
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TEST_SIZE, __pyx_float_0_7) < 0) __PYX_ERR(0, 24, __pyx_L1_error)

  /* "models.py":25
 * # Please kill.
 * TEST_SIZE=0.7
 * N_EST=100             # <<<<<<<<<<<<<<
 * SEED=42
 *
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_N_EST, __pyx_int_100) < 0) __PYX_ERR(0, 25, __pyx_L1_error)

  /* "models.py":26
 * TEST_SIZE=0.7
 * N_EST=100
 * SEED=42             # <<<<<<<<<<<<<<
 *
 *
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_SEED, __pyx_int_42) < 0) __PYX_ERR(0, 26, __pyx_L1_error)

  /* "models.py":30
 *
 * # TODO: Refactor
 * class Classifiers(object):             # <<<<<<<<<<<<<<
 *     def __init__(self):
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 */
  __pyx_t_2 = __Pyx_CalculateMetaclass(NULL, __pyx_tuple__5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_2, __pyx_tuple__5, __pyx_n_s_Classifiers, __pyx_n_s_Classifiers, (PyObject *) NULL, __pyx_n_s_models, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "models.py":31
 * # TODO: Refactor
 * class Classifiers(object):
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 *         #self.adt = AdaBoostClassifier(DecisionTreeClassifier(max_depth=1), n_estimators=N_EST),
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_11Classifiers_1__init__, 0, __pyx_n_s_Classifiers___init, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__7)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 31, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_3) < 0) __PYX_ERR(0, 31, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":48
 *
 *     clf = {
 *         'ada': 'AdaBoostClassifier',             # <<<<<<<<<<<<<<
 *         'bernoulli_nb': 'BernoulliNB',
 *         'decision_tree': '',
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(18); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_ada, __pyx_n_u_AdaBoostClassifier) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_bernoulli_nb, __pyx_n_u_BernoulliNB) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_decision_tree, __pyx_kp_u__8) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_extra_trees, __pyx_kp_u__8) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_gnb, __pyx_n_u_GaussianNB) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_gbc, __pyx_n_u_GradientBoostingClassifier) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_knn, __pyx_n_u_KNeighborsClassifier) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_lda, __pyx_n_u_LinearDiscriminantAnalysis) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_lgbm, __pyx_n_u_LighGradientBoost) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_mnb, __pyx_n_u_MultinomialNB) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_pav, __pyx_n_u_PassiveAggressiveClassifier) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_qda, __pyx_n_u_QuadraticDiscriminantAnalysis) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_rfc, __pyx_n_u_RandomForestClassifier) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_sgd, __pyx_n_u_GradientDescent) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_svm, __pyx_kp_u_svm_SVC) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_svml, __pyx_kp_u_svm_SVC_linear_kernel) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_xgb, __pyx_kp_u__8) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_u_xgbp, __pyx_kp_u__8) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_clf, __pyx_t_3) < 0) __PYX_ERR(0, 47, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":30
 *
 * # TODO: Refactor
 * class Classifiers(object):             # <<<<<<<<<<<<<<
 *     def __init__(self):
 *         self.ada = AdaBoostClassifier(n_estimators=N_EST, learning_rate=1)
 */
  __pyx_t_3 = __Pyx_Py3ClassCreate(__pyx_t_2, __pyx_n_s_Classifiers, __pyx_tuple__5, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Classifiers, __pyx_t_3) < 0) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":69
 *
 *
 * class HyperSpace():             # <<<<<<<<<<<<<<
 *     """ Registry class providing hyperparameter search space.
 *     @TODO: Provide private method to update a grid param range. """
 */
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_HyperSpace, __pyx_n_s_HyperSpace, (PyObject *) NULL, __pyx_n_s_models, __pyx_kp_s_Registry_class_providing_hyperp); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 69, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "models.py":72
 *     """ Registry class providing hyperparameter search space.
 *     @TODO: Provide private method to update a grid param range. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6models_10HyperSpace_1__init__, 0, __pyx_n_s_HyperSpace___init, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__10)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_1) < 0) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":75
 *         pass
 *
 *     def grid(self, est):             # <<<<<<<<<<<<<<
 *         return getattr(self, est)()
 *
 */
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6models_10HyperSpace_3grid, 0, __pyx_n_s_HyperSpace_grid, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__12)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_grid, __pyx_t_1) < 0) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":78
 *         return getattr(self, est)()
 *
 *     def update_hyperparam_range(self, est, param, high, low):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6models_10HyperSpace_5update_hyperparam_range, 0, __pyx_n_s_HyperSpace_update_hyperparam_ran, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__14)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_update_hyperparam_range, __pyx_t_1) < 0) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":81
 *         pass
 *
 *     def tfidf(self):             # <<<<<<<<<<<<<<
 *
 *         tfidf_hyperparams = {
 */
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6models_10HyperSpace_7tfidf, 0, __pyx_n_s_HyperSpace_tfidf, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__16)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 81, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_tfidf, __pyx_t_1) < 0) __PYX_ERR(0, 81, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":94
 *         return tfidf_hyperparams
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *
 *         n_estimators = [int(x) for x in np.linspace(start = 200, stop = 2000, num = 10)]
 */
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6models_10HyperSpace_9rfc, 0, __pyx_n_s_HyperSpace_rfc, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__18)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_rfc, __pyx_t_1) < 0) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":121
 *         """
 *
 *     def gbc(self):             # <<<<<<<<<<<<<<
 *         grid = {'learning_rate': [0.01,0.02,0.03],
 *             'subsample'    : [0.9, 0.5, 0.2],
 */
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6models_10HyperSpace_11gbc, 0, __pyx_n_s_HyperSpace_gbc, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__20)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_gbc, __pyx_t_1) < 0) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":69
 *
 *
 * class HyperSpace():             # <<<<<<<<<<<<<<
 *     """ Registry class providing hyperparameter search space.
 *     @TODO: Provide private method to update a grid param range. """
 */
  __pyx_t_1 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_HyperSpace, __pyx_empty_tuple, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 69, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_HyperSpace, __pyx_t_1) < 0) __PYX_ERR(0, 69, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":154
 *         """
 *
 * class Params(object):             # <<<<<<<<<<<<<<
 *     """ Provides default parameters for a given model. """
 *     def __init__(self):
 */
  __pyx_t_2 = __Pyx_CalculateMetaclass(NULL, __pyx_tuple__21); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_2, __pyx_tuple__21, __pyx_n_s_Params, __pyx_n_s_Params, (PyObject *) NULL, __pyx_n_s_models, __pyx_kp_s_Provides_default_parameters_for); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "models.py":156
 * class Params(object):
 *     """ Provides default parameters for a given model. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_6Params_1__init__, 0, __pyx_n_s_Params___init, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__23)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_3) < 0) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":159
 *         pass
 *
 *     def get(self, est):             # <<<<<<<<<<<<<<
 *         return self.gettattr(self, est)
 *
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_6Params_3get, 0, __pyx_n_s_Params_get, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__25)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_get, __pyx_t_3) < 0) __PYX_ERR(0, 159, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":162
 *         return self.gettattr(self, est)
 *
 *     def rfc(self):             # <<<<<<<<<<<<<<
 *         return dict(
 *             bootstrap=True,
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_6Params_5rfc, 0, __pyx_n_s_Params_rfc, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__27)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_rfc, __pyx_t_3) < 0) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":154
 *         """
 *
 * class Params(object):             # <<<<<<<<<<<<<<
 *     """ Provides default parameters for a given model. """
 *     def __init__(self):
 */
  __pyx_t_3 = __Pyx_Py3ClassCreate(__pyx_t_2, __pyx_n_s_Params, __pyx_tuple__21, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Params, __pyx_t_3) < 0) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":185
 * ## Gradient Descent
 *
 * import pandas as pd             # <<<<<<<<<<<<<<
 * from sklearn.metrics import mean_squared_error
 * class GradientDescent(object):
 */
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_pandas, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_pd, __pyx_t_2) < 0) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":186
 *
 * import pandas as pd
 * from sklearn.metrics import mean_squared_error             # <<<<<<<<<<<<<<
 * class GradientDescent(object):
 *     """ Needs Refactoring. """
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 186, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_mean_squared_error);
  __Pyx_GIVEREF(__pyx_n_s_mean_squared_error);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_mean_squared_error);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_metrics, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 186, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_mean_squared_error); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 186, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_mean_squared_error, __pyx_t_2) < 0) __PYX_ERR(0, 186, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":187
 * import pandas as pd
 * from sklearn.metrics import mean_squared_error
 * class GradientDescent(object):             # <<<<<<<<<<<<<<
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):
 */
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_tuple__28); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_tuple__28, __pyx_n_s_GradientDescent, __pyx_n_s_GradientDescent, (PyObject *) NULL, __pyx_n_s_models, __pyx_kp_s_Needs_Refactoring); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "models.py":189
 * class GradientDescent(object):
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_15GradientDescent_1__init__, 0, __pyx_n_s_GradientDescent___init, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__30)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_3, __pyx_tuple__31);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_3) < 0) __PYX_ERR(0, 189, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":194
 *         self.b = 0
 *
 *     def reshape_cat_series(self, y):             # <<<<<<<<<<<<<<
 *         """ If we get passed a series of strings, convert to matrix of int values.
 *             Obviously, this is a workaround (here) and needs to be refactored. """
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_15GradientDescent_3reshape_cat_series, 0, __pyx_n_s_GradientDescent_reshape_cat_seri, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__33)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_reshape_cat_series, __pyx_t_3) < 0) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":205
 *         return y
 *
 *     def fit(self, X, y, epochs = 2):             # <<<<<<<<<<<<<<
 *         """
 *         :param X: scipy.sparse.csr.csr_matrix
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_15GradientDescent_5fit, 0, __pyx_n_s_GradientDescent_fit, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__35)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 205, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_3, __pyx_tuple__36);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_3) < 0) __PYX_ERR(0, 205, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":237
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6models_15GradientDescent_7predict, 0, __pyx_n_s_GradientDescent_predict, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__38)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_predict, __pyx_t_3) < 0) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "models.py":187
 * import pandas as pd
 * from sklearn.metrics import mean_squared_error
 * class GradientDescent(object):             # <<<<<<<<<<<<<<
 *     """ Needs Refactoring. """
 *     def __init__(self, learning_rate=0.01):
 */
  __pyx_t_3 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_GradientDescent, __pyx_tuple__28, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_GradientDescent, __pyx_t_3) < 0) __PYX_ERR(0, 187, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":240
 *         return self.w * X + self.b
 *
 * class BatchGradientDescent():             # <<<<<<<<<<<<<<
 *     def __init__(self, learning_rate=0.01):
 *         self.learning_rate = learning_rate
 */
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_BatchGradientDescent, __pyx_n_s_BatchGradientDescent, (PyObject *) NULL, __pyx_n_s_models, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "models.py":241
 *
 * class BatchGradientDescent():
 *     def __init__(self, learning_rate=0.01):             # <<<<<<<<<<<<<<
 *         self.learning_rate = learning_rate
 *         self.w = 0
 */
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6models_20BatchGradientDescent_1__init__, 0, __pyx_n_s_BatchGradientDescent___init, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__40)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_2, __pyx_tuple__41);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_2) < 0) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":246
 *         self.b = 0
 *
 *     def fit(self, X, y, epochs = 100):             # <<<<<<<<<<<<<<
 *         N = len(X)
 *         history = []
 */
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6models_20BatchGradientDescent_3fit, 0, __pyx_n_s_BatchGradientDescent_fit, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__43)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_2, __pyx_tuple__44);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_fit, __pyx_t_2) < 0) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":265
 *         return history
 *
 *     def predict(self, X):             # <<<<<<<<<<<<<<
 *         return self.w * X + self.b
 *
 */
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6models_20BatchGradientDescent_5predict, 0, __pyx_n_s_BatchGradientDescent_predict, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__46)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_predict, __pyx_t_2) < 0) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":240
 *         return self.w * X + self.b
 *
 * class BatchGradientDescent():             # <<<<<<<<<<<<<<
 *     def __init__(self, learning_rate=0.01):
 *         self.learning_rate = learning_rate
 */
  __pyx_t_2 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_BatchGradientDescent, __pyx_empty_tuple, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_BatchGradientDescent, __pyx_t_2) < 0) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":327
 * ## XGB
 * xg_param_grid = {
 *     'clf__colsample_bytree': [i/10.0 for i in range(8,10)],             # <<<<<<<<<<<<<<
 *     #"clf__subsample"  : [i/10.0 for i in range(5,10)],
 *     #'clf__max_depth':range(5,15,1),
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 327, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  { /* enter inner scope */
    __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 327, __pyx_L4_error)
    __Pyx_GOTREF(__pyx_t_2);
    for (__pyx_t_4 = 8; __pyx_t_4 < 10; __pyx_t_4+=1) {
      __pyx_t_3 = __Pyx_PyInt_From_long(__pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 327, __pyx_L4_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_XGOTREF(__pyx_8genexpr2__pyx_v_6models_i);
      __Pyx_DECREF_SET(__pyx_8genexpr2__pyx_v_6models_i, __pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_3);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyFloat_TrueDivideObjC(__pyx_8genexpr2__pyx_v_6models_i, __pyx_float_10_0, 10.0, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 327, __pyx_L4_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_2, (PyObject*)__pyx_t_3))) __PYX_ERR(0, 327, __pyx_L4_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    }
    __Pyx_GOTREF(__pyx_8genexpr2__pyx_v_6models_i);
    __Pyx_DECREF_SET(__pyx_8genexpr2__pyx_v_6models_i, Py_None);
    goto __pyx_L7_exit_scope;
    __pyx_L4_error:;
    __Pyx_GOTREF(__pyx_8genexpr2__pyx_v_6models_i);
    __Pyx_DECREF_SET(__pyx_8genexpr2__pyx_v_6models_i, Py_None);
    goto __pyx_L1_error;
    __pyx_L7_exit_scope:;
  } /* exit inner scope */
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u_clf__colsample_bytree, __pyx_t_2) < 0) __PYX_ERR(0, 327, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_xg_param_grid, __pyx_t_1) < 0) __PYX_ERR(0, 326, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":359
 *
 *
 * class LR():             # <<<<<<<<<<<<<<
 *     def __init__(self, X, y):
 *         return LR(fit_intercept=False).fit(X,y)
 */
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_LR, __pyx_n_s_LR, (PyObject *) NULL, __pyx_n_s_models, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 359, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "models.py":360
 *
 * class LR():
 *     def __init__(self, X, y):             # <<<<<<<<<<<<<<
 *         return LR(fit_intercept=False).fit(X,y)
 *
 */
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6models_2LR_1__init__, 0, __pyx_n_s_LR___init, NULL, __pyx_n_s_models, __pyx_d, ((PyObject *)__pyx_codeobj__48)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 360, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_2) < 0) __PYX_ERR(0, 360, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "models.py":359
 *
 *
 * class LR():             # <<<<<<<<<<<<<<
 *     def __init__(self, X, y):
 *         return LR(fit_intercept=False).fit(X,y)
 */
  __pyx_t_2 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_LR, __pyx_empty_tuple, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 359, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_LR, __pyx_t_2) < 0) __PYX_ERR(0, 359, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "models.py":1
 * #lib/ext/models.py -  Pre-parameterised models for quick exploration             # <<<<<<<<<<<<<<
 *
 * import os
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /*--- Wrapped vars code ---*/

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init models", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init models");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}

/* --- Runtime support code --- */
/* Refnanny */
#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif

/* PyObjectGetAttrStr */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif

/* GetBuiltinName */
static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}

/* PyDictVersioning */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif

/* GetModuleGlobalName */
#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}

/* PyObjectCall */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = func->ob_type->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectSetAttrStr */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_setattro))
        return tp->tp_setattro(obj, attr_name, value);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_setattr))
        return tp->tp_setattr(obj, PyString_AS_STRING(attr_name), value);
#endif
    return PyObject_SetAttr(obj, attr_name, value);
}
#endif

/* PyFunctionFastCall */
#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif

/* PyObjectCallMethO */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCallNoArg */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#ifdef __Pyx_CyFunction_USED
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif

/* PyCFunctionFastCall */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif

/* PyObjectCallOneArg */
#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (PyCFunction_GET_FLAGS(func) & METH_FASTCALL) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif

/* RaiseArgTupleInvalid */
static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}

/* RaiseDoubleKeywords */
static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}

/* ParseKeywords */
static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}

/* GetAttr */
static CYTHON_INLINE PyObject *__Pyx_GetAttr(PyObject *o, PyObject *n) {
#if CYTHON_USE_TYPE_SLOTS
#if PY_MAJOR_VERSION >= 3
    if (likely(PyUnicode_Check(n)))
#else
    if (likely(PyString_Check(n)))
#endif
        return __Pyx_PyObject_GetAttrStr(o, n);
#endif
    return PyObject_GetAttr(o, n);
}

/* PyObjectCall2Args */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}

/* DictGetItem */
#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key) {
    PyObject *value;
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (!PyErr_Occurred()) {
            if (unlikely(PyTuple_Check(key))) {
                PyObject* args = PyTuple_Pack(1, key);
                if (likely(args)) {
                    PyErr_SetObject(PyExc_KeyError, args);
                    Py_DECREF(args);
                }
            } else {
                PyErr_SetObject(PyExc_KeyError, key);
            }
        }
        return NULL;
    }
    Py_INCREF(value);
    return value;
}
#endif

/* GetItemInt */
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}

/* ObjectGetItem */
#if CYTHON_USE_TYPE_SLOTS
static PyObject *__Pyx_PyObject_GetIndex(PyObject *obj, PyObject* index) {
    PyObject *runerr;
    Py_ssize_t key_value;
    PySequenceMethods *m = Py_TYPE(obj)->tp_as_sequence;
    if (unlikely(!(m && m->sq_item))) {
        PyErr_Format(PyExc_TypeError, "'%.200s' object is not subscriptable", Py_TYPE(obj)->tp_name);
        return NULL;
    }
    key_value = __Pyx_PyIndex_AsSsize_t(index);
    if (likely(key_value != -1 || !(runerr = PyErr_Occurred()))) {
        return __Pyx_GetItemInt_Fast(obj, key_value, 0, 1, 1);
    }
    if (PyErr_GivenExceptionMatches(runerr, PyExc_OverflowError)) {
        PyErr_Clear();
        PyErr_Format(PyExc_IndexError, "cannot fit '%.200s' into an index-sized integer", Py_TYPE(index)->tp_name);
    }
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key) {
    PyMappingMethods *m = Py_TYPE(obj)->tp_as_mapping;
    if (likely(m && m->mp_subscript)) {
        return m->mp_subscript(obj, key);
    }
    return __Pyx_PyObject_GetIndex(obj, key);
}
#endif

/* PyIntCompare */
static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, CYTHON_UNUSED long inplace) {
    if (op1 == op2) {
        Py_RETURN_TRUE;
    }
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long a = PyInt_AS_LONG(op1);
        if (a == b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        int unequal;
        unsigned long uintval;
        Py_ssize_t size = Py_SIZE(op1);
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        if (intval == 0) {
            if (size == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
        } else if (intval < 0) {
            if (size >= 0)
                Py_RETURN_FALSE;
            intval = -intval;
            size = -size;
        } else {
            if (size <= 0)
                Py_RETURN_FALSE;
        }
        uintval = (unsigned long) intval;
#if PyLong_SHIFT * 4 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 4)) {
            unequal = (size != 5) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[4] != ((uintval >> (4 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 3 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 3)) {
            unequal = (size != 4) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 2 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 2)) {
            unequal = (size != 3) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 1 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 1)) {
            unequal = (size != 2) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
            unequal = (size != 1) || (((unsigned long) digits[0]) != (uintval & (unsigned long) PyLong_MASK));
        if (unequal == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
        if ((double)a == (double)b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    return (
        PyObject_RichCompare(op1, op2, Py_EQ));
}

/* PyIntBinop */
#if !CYTHON_COMPILING_IN_PYPY
#if PY_MAJOR_VERSION < 3 || CYTHON_USE_PYLONG_INTERNALS
#define __Pyx_PyInt_RemainderObjC_ZeroDivisionError(operand)\
    if (unlikely(zerodivision_check && ((operand) == 0))) {\
        PyErr_SetString(PyExc_ZeroDivisionError, "integer division or modulo by zero");\
        return NULL;\
    }
#endif
static PyObject* __Pyx_PyInt_RemainderObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            __Pyx_PyInt_RemainderObjC_ZeroDivisionError(b)
            x = a % b;
            x += ((x != 0) & ((x ^ b) < 0)) * b;
            return PyInt_FromLong(x);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_remainder(op1, op2);
            }
        }
                __Pyx_PyInt_RemainderObjC_ZeroDivisionError(b)
                x = a % b;
                x += ((x != 0) & ((x ^ b) < 0)) * b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla % llb;
                llx += ((llx != 0) & ((llx ^ llb) < 0)) * llb;
            return PyLong_FromLongLong(llx);
#endif


    }
    #endif
    return (inplace ? PyNumber_InPlaceRemainder : PyNumber_Remainder)(op1, op2);
}
#endif

/* JoinPyUnicode */
static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      CYTHON_UNUSED Py_UCS4 max_char) {
#if CYTHON_USE_UNICODE_INTERNALS && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    PyObject *result_uval;
    int result_ukind;
    Py_ssize_t i, char_pos;
    void *result_udata;
#if CYTHON_PEP393_ENABLED
    result_uval = PyUnicode_New(result_ulength, max_char);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = (max_char <= 255) ? PyUnicode_1BYTE_KIND : (max_char <= 65535) ? PyUnicode_2BYTE_KIND : PyUnicode_4BYTE_KIND;
    result_udata = PyUnicode_DATA(result_uval);
#else
    result_uval = PyUnicode_FromUnicode(NULL, result_ulength);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = sizeof(Py_UNICODE);
    result_udata = PyUnicode_AS_UNICODE(result_uval);
#endif
    char_pos = 0;
    for (i=0; i < value_count; i++) {
        int ukind;
        Py_ssize_t ulength;
        void *udata;
        PyObject *uval = PyTuple_GET_ITEM(value_tuple, i);
        if (unlikely(__Pyx_PyUnicode_READY(uval)))
            goto bad;
        ulength = __Pyx_PyUnicode_GET_LENGTH(uval);
        if (unlikely(!ulength))
            continue;
        if (unlikely(char_pos + ulength < 0))
            goto overflow;
        ukind = __Pyx_PyUnicode_KIND(uval);
        udata = __Pyx_PyUnicode_DATA(uval);
        if (!CYTHON_PEP393_ENABLED || ukind == result_ukind) {
            memcpy((char *)result_udata + char_pos * result_ukind, udata, (size_t) (ulength * result_ukind));
        } else {
            #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030300F0 || defined(_PyUnicode_FastCopyCharacters)
            _PyUnicode_FastCopyCharacters(result_uval, char_pos, uval, 0, ulength);
            #else
            Py_ssize_t j;
            for (j=0; j < ulength; j++) {
                Py_UCS4 uchar = __Pyx_PyUnicode_READ(ukind, udata, j);
                __Pyx_PyUnicode_WRITE(result_ukind, result_udata, char_pos+j, uchar);
            }
            #endif
        }
        char_pos += ulength;
    }
    return result_uval;
overflow:
    PyErr_SetString(PyExc_OverflowError, "join() result is too long for a Python string");
bad:
    Py_DECREF(result_uval);
    return NULL;
#else
    result_ulength++;
    value_count++;
    return PyUnicode_Join(__pyx_empty_unicode, value_tuple);
#endif
}

/* Import */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}

/* ImportFrom */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name) {
    PyObject* value = __Pyx_PyObject_GetAttrStr(module, name);
    if (unlikely(!value) && PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Format(PyExc_ImportError,
        #if PY_MAJOR_VERSION < 3
            "cannot import name %.230s", PyString_AS_STRING(name));
        #else
            "cannot import name %S", name);
        #endif
    }
    return value;
}

/* CalculateMetaclass */
static PyObject *__Pyx_CalculateMetaclass(PyTypeObject *metaclass, PyObject *bases) {
    Py_ssize_t i, nbases = PyTuple_GET_SIZE(bases);
    for (i=0; i < nbases; i++) {
        PyTypeObject *tmptype;
        PyObject *tmp = PyTuple_GET_ITEM(bases, i);
        tmptype = Py_TYPE(tmp);
#if PY_MAJOR_VERSION < 3
        if (tmptype == &PyClass_Type)
            continue;
#endif
        if (!metaclass) {
            metaclass = tmptype;
            continue;
        }
        if (PyType_IsSubtype(metaclass, tmptype))
            continue;
        if (PyType_IsSubtype(tmptype, metaclass)) {
            metaclass = tmptype;
            continue;
        }
        PyErr_SetString(PyExc_TypeError,
                        "metaclass conflict: "
                        "the metaclass of a derived class "
                        "must be a (non-strict) subclass "
                        "of the metaclasses of all its bases");
        return NULL;
    }
    if (!metaclass) {
#if PY_MAJOR_VERSION < 3
        metaclass = &PyClass_Type;
#else
        metaclass = &PyType_Type;
#endif
    }
    Py_INCREF((PyObject*) metaclass);
    return (PyObject*) metaclass;
}

/* FetchCommonType */
static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}

/* CythonFunctionShared */
#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromString(m->func.m_ml->ml_name);
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    if (unlikely(op == NULL))
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults_size = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
#if PY_MAJOR_VERSION < 3
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
#endif
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}

/* CythonFunction */
static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}

/* Py3ClassCreate */
static PyObject *__Pyx_Py3MetaclassPrepare(PyObject *metaclass, PyObject *bases, PyObject *name,
                                           PyObject *qualname, PyObject *mkw, PyObject *modname, PyObject *doc) {
    PyObject *ns;
    if (metaclass) {
        PyObject *prep = __Pyx_PyObject_GetAttrStr(metaclass, __pyx_n_s_prepare);
        if (prep) {
            PyObject *pargs = PyTuple_Pack(2, name, bases);
            if (unlikely(!pargs)) {
                Py_DECREF(prep);
                return NULL;
            }
            ns = PyObject_Call(prep, pargs, mkw);
            Py_DECREF(prep);
            Py_DECREF(pargs);
        } else {
            if (unlikely(!PyErr_ExceptionMatches(PyExc_AttributeError)))
                return NULL;
            PyErr_Clear();
            ns = PyDict_New();
        }
    } else {
        ns = PyDict_New();
    }
    if (unlikely(!ns))
        return NULL;
    if (unlikely(PyObject_SetItem(ns, __pyx_n_s_module, modname) < 0)) goto bad;
    if (unlikely(PyObject_SetItem(ns, __pyx_n_s_qualname, qualname) < 0)) goto bad;
    if (unlikely(doc && PyObject_SetItem(ns, __pyx_n_s_doc, doc) < 0)) goto bad;
    return ns;
bad:
    Py_DECREF(ns);
    return NULL;
}
static PyObject *__Pyx_Py3ClassCreate(PyObject *metaclass, PyObject *name, PyObject *bases,
                                      PyObject *dict, PyObject *mkw,
                                      int calculate_metaclass, int allow_py2_metaclass) {
    PyObject *result, *margs;
    PyObject *owned_metaclass = NULL;
    if (allow_py2_metaclass) {
        owned_metaclass = PyObject_GetItem(dict, __pyx_n_s_metaclass);
        if (owned_metaclass) {
            metaclass = owned_metaclass;
        } else if (likely(PyErr_ExceptionMatches(PyExc_KeyError))) {
            PyErr_Clear();
        } else {
            return NULL;
        }
    }
    if (calculate_metaclass && (!metaclass || PyType_Check(metaclass))) {
        metaclass = __Pyx_CalculateMetaclass((PyTypeObject*) metaclass, bases);
        Py_XDECREF(owned_metaclass);
        if (unlikely(!metaclass))
            return NULL;
        owned_metaclass = metaclass;
    }
    margs = PyTuple_Pack(3, name, bases, dict);
    if (unlikely(!margs)) {
        result = NULL;
    } else {
        result = PyObject_Call(metaclass, margs, mkw);
        Py_DECREF(margs);
    }
    Py_XDECREF(owned_metaclass);
    return result;
}

/* PyFloatBinop */
#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyFloat_TrueDivideObjC(PyObject *op1, PyObject *op2, double floatval, int inplace, int zerodivision_check) {
    const double b = floatval;
    double a, result;
    (void)inplace;
    (void)zerodivision_check;
    if (likely(PyFloat_CheckExact(op1))) {
        a = PyFloat_AS_DOUBLE(op1);

    } else
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        a = (double) PyInt_AS_LONG(op1);

    } else
    #endif
    if (likely(PyLong_CheckExact(op1))) {
        #if CYTHON_USE_PYLONG_INTERNALS
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        switch (size) {
            case  0: a = 0.0; break;
            case -1: a = -(double) digits[0]; break;
            case  1: a = (double) digits[0]; break;
            case -2:
            case 2:
                if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT && ((8 * sizeof(unsigned long) < 53) || (1 * PyLong_SHIFT < 53))) {
                    a = (double) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if ((8 * sizeof(unsigned long) < 53) || (2 * PyLong_SHIFT < 53) || (a < (double) ((PY_LONG_LONG)1 << 53))) {
                        if (size == -2)
                            a = -a;
                        break;
                    }
                }
                CYTHON_FALLTHROUGH;
            case -3:
            case 3:
                if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT && ((8 * sizeof(unsigned long) < 53) || (2 * PyLong_SHIFT < 53))) {
                    a = (double) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if ((8 * sizeof(unsigned long) < 53) || (3 * PyLong_SHIFT < 53) || (a < (double) ((PY_LONG_LONG)1 << 53))) {
                        if (size == -3)
                            a = -a;
                        break;
                    }
                }
                CYTHON_FALLTHROUGH;
            case -4:
            case 4:
                if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT && ((8 * sizeof(unsigned long) < 53) || (3 * PyLong_SHIFT < 53))) {
                    a = (double) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                    if ((8 * sizeof(unsigned long) < 53) || (4 * PyLong_SHIFT < 53) || (a < (double) ((PY_LONG_LONG)1 << 53))) {
                        if (size == -4)
                            a = -a;
                        break;
                    }
                }
                CYTHON_FALLTHROUGH;
            default:
        #else
        {
        #endif
            a = PyLong_AsDouble(op1);
            if (unlikely(a == -1.0 && PyErr_Occurred())) return NULL;

        }
    } else {
        return (inplace ? PyNumber_InPlaceTrueDivide : PyNumber_TrueDivide)(op1, op2);
    }

        PyFPE_START_PROTECT("divide", return NULL)
        result = a / b;
        PyFPE_END_PROTECT(result)
        return PyFloat_FromDouble(result);
}
#endif

/* PyErrFetchRestore */
  #if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif

/* CLineInTraceback */
  #ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_NCP_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif

/* CodeObjectCache */
  static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}

/* AddTraceback */
  #include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, /*PyObject *code,*/
        __pyx_empty_tuple, /*PyObject *consts,*/
        __pyx_empty_tuple, /*PyObject *names,*/
        __pyx_empty_tuple, /*PyObject *varnames,*/
        __pyx_empty_tuple, /*PyObject *freevars,*/
        __pyx_empty_tuple, /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        py_line,
        __pyx_empty_bytes  /*PyObject *lnotab*/
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            /*PyThreadState *tstate,*/
        py_code,           /*PyCodeObject *code,*/
        __pyx_d,    /*PyObject *globals,*/
        0                  /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

/* CIntToPy */
  static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}

/* CIntFromPyVerify */
  #define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }

/* CIntFromPy */
  static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}

/* CIntFromPy */
  static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
    const int neg_one = (int) ((int) 0 - (int) 1), const_zero = (int) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}

/* FastTypeChecks */
  #if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif

/* CheckBinaryVersion */
  static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}

/* InitStrings */
  static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif /* Py_PYTHON_H */
