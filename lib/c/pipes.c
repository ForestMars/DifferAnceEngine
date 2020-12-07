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

#define __PYX_HAVE__pipes
#define __PYX_HAVE_API__pipes
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
  "pipes.py",
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

/* PyCFunctionFastCall.proto */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
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

/* PyObjectCall.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif

/* PyObjectCall2Args.proto */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);

/* PyObjectCallMethO.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif

/* PyObjectCallOneArg.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);

/* ArgTypeTest.proto */
#define __Pyx_ArgTypeTest(obj, type, none_allowed, name, exact)\
    ((likely((Py_TYPE(obj) == type) | (none_allowed && (obj == Py_None)))) ? 1 :\
        __Pyx__ArgTypeTest(obj, type, name, exact))
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact);

/* IterFinish.proto */
static CYTHON_INLINE int __Pyx_IterFinish(void);

/* PyObjectCallNoArg.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif

/* PyObjectGetMethod.proto */
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);

/* PyObjectCallMethod0.proto */
static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name);

/* RaiseNeedMoreValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index);

/* RaiseTooManyValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected);

/* UnpackItemEndCheck.proto */
static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected);

/* RaiseNoneIterError.proto */
static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void);

/* UnpackTupleError.proto */
static void __Pyx_UnpackTupleError(PyObject *, Py_ssize_t index);

/* UnpackTuple2.proto */
#define __Pyx_unpack_tuple2(tuple, value1, value2, is_tuple, has_known_size, decref_tuple)\
    (likely(is_tuple || PyTuple_Check(tuple)) ?\
        (likely(has_known_size || PyTuple_GET_SIZE(tuple) == 2) ?\
            __Pyx_unpack_tuple2_exact(tuple, value1, value2, decref_tuple) :\
            (__Pyx_UnpackTupleError(tuple, 2), -1)) :\
        __Pyx_unpack_tuple2_generic(tuple, value1, value2, has_known_size, decref_tuple))
static CYTHON_INLINE int __Pyx_unpack_tuple2_exact(
    PyObject* tuple, PyObject** value1, PyObject** value2, int decref_tuple);
static int __Pyx_unpack_tuple2_generic(
    PyObject* tuple, PyObject** value1, PyObject** value2, int has_known_size, int decref_tuple);

/* dict_iter.proto */
static CYTHON_INLINE PyObject* __Pyx_dict_iterator(PyObject* dict, int is_dict, PyObject* method_name,
                                                   Py_ssize_t* p_orig_length, int* p_is_dict);
static CYTHON_INLINE int __Pyx_dict_iter_next(PyObject* dict_or_iter, Py_ssize_t orig_length, Py_ssize_t* ppos,
                                              PyObject** pkey, PyObject** pvalue, PyObject** pitem, int is_dict);

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

/* SetItemInt.proto */
#define __Pyx_SetItemInt(o, i, v, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_SetItemInt_Fast(o, (Py_ssize_t)i, v, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list assignment index out of range"), -1) :\
               __Pyx_SetItemInt_Generic(o, to_py_func(i), v)))
static int __Pyx_SetItemInt_Generic(PyObject *o, PyObject *j, PyObject *v);
static CYTHON_INLINE int __Pyx_SetItemInt_Fast(PyObject *o, Py_ssize_t i, PyObject *v,
                                               int is_list, int wraparound, int boundscheck);

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

/* Globals.proto */
static PyObject* __Pyx_Globals(void);

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


/* Module declarations from 'pipes' */
#define __Pyx_MODULE_NAME "pipes"
extern int __pyx_module_is_main_pipes;
int __pyx_module_is_main_pipes = 0;

/* Implementation of 'pipes' */
static PyObject *__pyx_builtin_object;
static PyObject *__pyx_builtin_eval;
static PyObject *__pyx_builtin_enumerate;
static const char __pyx_k_[] = "*";
static const char __pyx_k_e[] = "e";
static const char __pyx_k_f[] = "f";
static const char __pyx_k_i[] = "i";
static const char __pyx_k_p[] = "p";
static const char __pyx_k_v[] = "v";
static const char __pyx_k_x[] = "x";
static const char __pyx_k_FU[] = "FU";
static const char __pyx_k_bt[] = "bt";
static const char __pyx_k_cc[] = "cc";
static const char __pyx_k_cv[] = "cv";
static const char __pyx_k_cw[] = "cw";
static const char __pyx_k_fu[] = "fu";
static const char __pyx_k_lp[] = "lp";
static const char __pyx_k_ns[] = "ns";
static const char __pyx_k_sl[] = "sl";
static const char __pyx_k_PCA[] = "PCA";
static const char __pyx_k_awl[] = "awl";
static const char __pyx_k_clf[] = "clf";
static const char __pyx_k_cls[] = "cls";
static const char __pyx_k_col[] = "col";
static const char __pyx_k_doc[] = "__doc__";
static const char __pyx_k_len[] = "len";
static const char __pyx_k_raw[] = "raw";
static const char __pyx_k_tar[] = "tar";
static const char __pyx_k_vec[] = "vec";
static const char __pyx_k_Pipe[] = "Pipe";
static const char __pyx_k_SEED[] = "SEED";
static const char __pyx_k_dict[] = "__dict__";
static const char __pyx_k_eval[] = "eval";
static const char __pyx_k_init[] = "__init__";
static const char __pyx_k_list[] = "list";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_norm[] = "{}_norm";
static const char __pyx_k_pipe[] = "_pipe";
static const char __pyx_k_self[] = "self";
static const char __pyx_k_step[] = "step";
static const char __pyx_k_tar1[] = "tar1";
static const char __pyx_k_tar2[] = "tar2";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_STOPS[] = "STOPS";
static const char __pyx_k_Trans[] = "Trans";
static const char __pyx_k_feats[] = "feats";
static const char __pyx_k_items[] = "items";
static const char __pyx_k_pipel[] = "pipel";
static const char __pyx_k_pipes[] = "pipes";
static const char __pyx_k_steps[] = "steps";
static const char __pyx_k_tfidf[] = "tfidf";
static const char __pyx_k_utils[] = "utils";
static const char __pyx_k_words[] = "words";
static const char __pyx_k_MAX_DF[] = "MAX_DF";
static const char __pyx_k_MIN_DF[] = "MIN_DF";
static const char __pyx_k_commas[] = "commas";
static const char __pyx_k_common[] = "common";
static const char __pyx_k_dict_2[] = "dict";
static const char __pyx_k_format[] = "format";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_max_df[] = "max_df";
static const char __pyx_k_min_df[] = "min_df";
static const char __pyx_k_module[] = "__module__";
static const char __pyx_k_object[] = "object";
static const char __pyx_k_params[] = "params";
static const char __pyx_k_pipe_2[] = "pipe";
static const char __pyx_k_return[] = "return";
static const char __pyx_k_FU_pipe[] = "FU_pipe";
static const char __pyx_k_col_nom[] = "col_nom";
static const char __pyx_k_convert[] = "convert";
static const char __pyx_k_english[] = "english";
static const char __pyx_k_missing[] = "missing";
static const char __pyx_k_normies[] = "normies";
static const char __pyx_k_prepare[] = "__prepare__";
static const char __pyx_k_sen_len[] = "sen_len";
static const char __pyx_k_tvector[] = "tvector";
static const char __pyx_k_unicode[] = "unicode";
static const char __pyx_k_Pipeline[] = "Pipeline";
static const char __pyx_k_clf_pipe[] = "clf_pipe";
static const char __pyx_k_md5_hash[] = "md5_hash";
static const char __pyx_k_notstops[] = "notstops";
static const char __pyx_k_pipeline[] = "pipeline";
static const char __pyx_k_pipename[] = "pipename";
static const char __pyx_k_pipes_py[] = "pipes.py";
static const char __pyx_k_qualname[] = "__qualname__";
static const char __pyx_k_selector[] = "selector";
static const char __pyx_k_standard[] = "standard";
static const char __pyx_k_cpu_count[] = "cpu_count";
static const char __pyx_k_enumerate[] = "enumerate";
static const char __pyx_k_hash_pipe[] = "hash_pipe";
static const char __pyx_k_load_pipe[] = "load_pipe";
static const char __pyx_k_make_pipe[] = "make_pipe";
static const char __pyx_k_metaclass[] = "__metaclass__";
static const char __pyx_k_norm_pipe[] = "norm_pipe";
static const char __pyx_k_not_stops[] = "not_stops";
static const char __pyx_k_num_feats[] = "num_feats";
static const char __pyx_k_pipenames[] = "pipenames";
static const char __pyx_k_sentences[] = "sentences";
static const char __pyx_k_stopWords[] = "stopWords";
static const char __pyx_k_stopwords[] = "stopwords";
static const char __pyx_k_CountWords[] = "CountWords";
static const char __pyx_k_classifier[] = "classifier";
static const char __pyx_k_drop_feats[] = "drop_feats";
static const char __pyx_k_input_feat[] = "input_feat";
static const char __pyx_k_norm_feats[] = "norm_feats";
static const char __pyx_k_pipe_names[] = "pipe_names";
static const char __pyx_k_set_params[] = "set_params";
static const char __pyx_k_stop_words[] = "stop_words";
static const char __pyx_k_tfidf_pipe[] = "tfidf_pipe";
static const char __pyx_k_Classifiers[] = "Classifiers";
static const char __pyx_k_CountCommas[] = "CountCommas";
static const char __pyx_k_MissingData[] = "MissingData";
static const char __pyx_k_Pipe___init[] = "Pipe.__init__";
static const char __pyx_k_chain_pipes[] = "chain_pipes";
static const char __pyx_k_count_words[] = "count_words";
static const char __pyx_k_make_normie[] = "make_normie";
static const char __pyx_k_named_pipes[] = "named_pipes";
static const char __pyx_k_nltk_corpus[] = "nltk.corpus";
static const char __pyx_k_normie_pipe[] = "normie_pipe";
static const char __pyx_k_set_fu_feat[] = "set_fu_feat";
static const char __pyx_k_DropFeatures[] = "DropFeatures";
static const char __pyx_k_FeatureUnion[] = "FeatureUnion";
static const char __pyx_k_MAX_FEATURES[] = "MAX_FEATURES";
static const char __pyx_k_TextSelector[] = "TextSelector";
static const char __pyx_k_avg_word_len[] = "avg_word_len";
static const char __pyx_k_count_commas[] = "count_commas";
static const char __pyx_k_make_FU_pipe[] = "make_FU_pipe_";
static const char __pyx_k_max_features[] = "max_features";
static const char __pyx_k_select_feats[] = "select_feats";
static const char __pyx_k_sen_len_pipe[] = "sen_len_pipe";
static const char __pyx_k_CommaLenRatio[] = "CommaLenRatio";
static const char __pyx_k_add_num_feats[] = "add_num_feats";
static const char __pyx_k_commalenratio[] = "commalenratio";
static const char __pyx_k_features_pipe[] = "features_pipe";
static const char __pyx_k_input_feature[] = "input_feature";
static const char __pyx_k_BooleanTargets[] = "BooleanTargets";
static const char __pyx_k_ConvertTargets[] = "ConvertTargets";
static const char __pyx_k_NumberSelector[] = "NumberSelector";
static const char __pyx_k_Pipe_hash_pipe[] = "Pipe.hash_pipe";
static const char __pyx_k_Pipe_load_pipe[] = "Pipe.load_pipe";
static const char __pyx_k_Pipe_make_pipe[] = "Pipe.make_pipe";
static const char __pyx_k_SentenceLength[] = "SentenceLength";
static const char __pyx_k_StandardScaler[] = "StandardScaler";
static const char __pyx_k_add_norm_feats[] = "add_norm_feats";
static const char __pyx_k_chain_FU_pipes[] = "chain_FU_pipes";
static const char __pyx_k_chain_fu_pipes[] = "chain_fu_pipes";
static const char __pyx_k_make_FU_pipe_2[] = "make_FU_pipe";
static const char __pyx_k_not_stops_pipe[] = "not_stops_pipe";
static const char __pyx_k_num_feats_pipe[] = "num_feats_pipe";
static const char __pyx_k_set_input_feat[] = "set_input_feat";
static const char __pyx_k_tfidf_col_pipe[] = "tfidf_col_pipe";
static const char __pyx_k_ClassifierPipes[] = "ClassifierPipes";
static const char __pyx_k_CountVectorizer[] = "CountVectorizer";
static const char __pyx_k_FeatureSelector[] = "FeatureSelector";
static const char __pyx_k_TfidfVectorizer[] = "TfidfVectorizer";
static const char __pyx_k_build_src_trans[] = "build.src.trans";
static const char __pyx_k_comma_len_ratio[] = "comma_len_ratio";
static const char __pyx_k_multiprocessing[] = "multiprocessing";
static const char __pyx_k_norm_feats_pipe[] = "norm_feats_pipe";
static const char __pyx_k_Pipe_chain_pipes[] = "Pipe.chain_pipes";
static const char __pyx_k_Pipe_make_normie[] = "Pipe.make_normie";
static const char __pyx_k_Pipe_set_fu_feat[] = "Pipe.set_fu_feat";
static const char __pyx_k_TfidfTransformer[] = "TfidfTransformer";
static const char __pyx_k_build_src_models[] = "build.src.models";
static const char __pyx_k_count_words_pipe[] = "count_words_pipe";
static const char __pyx_k_sklearn_pipeline[] = "sklearn.pipeline";
static const char __pyx_k_word_vector_pipe[] = "word_vector_pipe";
static const char __pyx_k_Pipe_make_FU_pipe[] = "Pipe.make_FU_pipe_";
static const char __pyx_k_avg_word_len_pipe[] = "avg_word_len_pipe";
static const char __pyx_k_build_scalar_pipe[] = "build_scalar_pipe";
static const char __pyx_k_count_commas_pipe[] = "count_commas_pipe";
static const char __pyx_k_missing_data_pipe[] = "missing_data_pipe";
static const char __pyx_k_sen_len_norm_pipe[] = "sen_len_norm_pipe";
static const char __pyx_k_Pipe_add_num_feats[] = "Pipe.add_num_feats";
static const char __pyx_k_build_feature_pipe[] = "build_feature_pipe";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_combine_feats_pipe[] = "combine_feats_pipe";
static const char __pyx_k_drop_features_pipe[] = "drop_features_pipe";
static const char __pyx_k_numeric_feats_pipe[] = "numeric_feats_pipe";
static const char __pyx_k_ClassifierPipes_clf[] = "ClassifierPipes.clf";
static const char __pyx_k_NotStopsTransformer[] = "NotStopsTransformer";
static const char __pyx_k_Pipe_add_norm_feats[] = "Pipe.add_norm_feats";
static const char __pyx_k_Pipe_chain_fu_pipes[] = "Pipe.chain_fu_pipes";
static const char __pyx_k_Pipe_make_FU_pipe_2[] = "Pipe.make_FU_pipe";
static const char __pyx_k_Pipe_set_input_feat[] = "Pipe.set_input_feat";
static const char __pyx_k_not_stops_norm_pipe[] = "not_stops_norm_pipe";
static const char __pyx_k_boolean_targets_pipe[] = "boolean_targets_pipe";
static const char __pyx_k_comma_len_ratio_pipe[] = "comma_len_ratio_pipe";
static const char __pyx_k_AvgWordLenTransformer[] = "AvgWordLenTransformer";
static const char __pyx_k_count_words_norm_pipe[] = "count_words_norm_pipe";
static const char __pyx_k_sklearn_decomposition[] = "sklearn.decomposition";
static const char __pyx_k_sklearn_preprocessing[] = "sklearn.preprocessing";
static const char __pyx_k_ClassifierPipes___init[] = "ClassifierPipes.__init__";
static const char __pyx_k_Pipe_build_scalar_pipe[] = "Pipe.build_scalar_pipe";
static const char __pyx_k_avg_word_len_norm_pipe[] = "avg_word_len_norm_pipe";
static const char __pyx_k_count_commas_norm_pipe[] = "count_commas_norm_pipe";
static const char __pyx_k_Pipe_build_feature_pipe[] = "Pipe.build_feature_pipe";
static const char __pyx_k_targets_str_to_int_pipe[] = "targets_str_to_int_pipe";
static const char __pyx_k_comma_len_ratio_norm_pipe[] = "comma_len_ratio_norm_pipe";
static const char __pyx_k_Class_with_all_methods_needed_t[] = " Class with all methods needed to dynamically build pipes at runtime. ";
static const char __pyx_k_Pipe_factory_for_single_step_cl[] = " Pipe factory for single step classifier pipes. ";
static const char __pyx_k_sklearn_feature_extraction_text[] = "sklearn.feature_extraction.text";
static PyObject *__pyx_n_s_;
static PyObject *__pyx_n_s_AvgWordLenTransformer;
static PyObject *__pyx_n_s_BooleanTargets;
static PyObject *__pyx_kp_s_Class_with_all_methods_needed_t;
static PyObject *__pyx_n_s_ClassifierPipes;
static PyObject *__pyx_n_s_ClassifierPipes___init;
static PyObject *__pyx_n_s_ClassifierPipes_clf;
static PyObject *__pyx_n_s_Classifiers;
static PyObject *__pyx_n_s_CommaLenRatio;
static PyObject *__pyx_n_s_ConvertTargets;
static PyObject *__pyx_n_s_CountCommas;
static PyObject *__pyx_n_s_CountVectorizer;
static PyObject *__pyx_n_s_CountWords;
static PyObject *__pyx_n_s_DropFeatures;
static PyObject *__pyx_n_u_FU;
static PyObject *__pyx_n_s_FU_pipe;
static PyObject *__pyx_n_s_FeatureSelector;
static PyObject *__pyx_n_s_FeatureUnion;
static PyObject *__pyx_n_s_MAX_DF;
static PyObject *__pyx_n_s_MAX_FEATURES;
static PyObject *__pyx_n_s_MIN_DF;
static PyObject *__pyx_n_s_MissingData;
static PyObject *__pyx_n_s_NotStopsTransformer;
static PyObject *__pyx_n_s_NumberSelector;
static PyObject *__pyx_n_s_PCA;
static PyObject *__pyx_n_s_Pipe;
static PyObject *__pyx_n_s_Pipe___init;
static PyObject *__pyx_n_s_Pipe_add_norm_feats;
static PyObject *__pyx_n_s_Pipe_add_num_feats;
static PyObject *__pyx_n_s_Pipe_build_feature_pipe;
static PyObject *__pyx_n_s_Pipe_build_scalar_pipe;
static PyObject *__pyx_n_s_Pipe_chain_fu_pipes;
static PyObject *__pyx_n_s_Pipe_chain_pipes;
static PyObject *__pyx_kp_s_Pipe_factory_for_single_step_cl;
static PyObject *__pyx_n_s_Pipe_hash_pipe;
static PyObject *__pyx_n_s_Pipe_load_pipe;
static PyObject *__pyx_n_s_Pipe_make_FU_pipe;
static PyObject *__pyx_n_s_Pipe_make_FU_pipe_2;
static PyObject *__pyx_n_s_Pipe_make_normie;
static PyObject *__pyx_n_s_Pipe_make_pipe;
static PyObject *__pyx_n_s_Pipe_set_fu_feat;
static PyObject *__pyx_n_s_Pipe_set_input_feat;
static PyObject *__pyx_n_s_Pipeline;
static PyObject *__pyx_n_s_SEED;
static PyObject *__pyx_n_s_STOPS;
static PyObject *__pyx_n_s_SentenceLength;
static PyObject *__pyx_n_s_StandardScaler;
static PyObject *__pyx_n_s_TextSelector;
static PyObject *__pyx_n_s_TfidfTransformer;
static PyObject *__pyx_n_s_TfidfVectorizer;
static PyObject *__pyx_n_s_Trans;
static PyObject *__pyx_n_s_add_norm_feats;
static PyObject *__pyx_n_s_add_num_feats;
static PyObject *__pyx_n_u_avg_word_len;
static PyObject *__pyx_n_s_avg_word_len_norm_pipe;
static PyObject *__pyx_n_s_avg_word_len_pipe;
static PyObject *__pyx_n_u_awl;
static PyObject *__pyx_n_s_boolean_targets_pipe;
static PyObject *__pyx_n_u_bt;
static PyObject *__pyx_n_s_build_feature_pipe;
static PyObject *__pyx_n_s_build_scalar_pipe;
static PyObject *__pyx_n_s_build_src_models;
static PyObject *__pyx_n_s_build_src_trans;
static PyObject *__pyx_n_u_cc;
static PyObject *__pyx_n_s_chain_FU_pipes;
static PyObject *__pyx_n_s_chain_fu_pipes;
static PyObject *__pyx_n_s_chain_pipes;
static PyObject *__pyx_n_s_classifier;
static PyObject *__pyx_n_s_clf;
static PyObject *__pyx_n_s_clf_pipe;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_cls;
static PyObject *__pyx_n_s_col;
static PyObject *__pyx_n_u_col;
static PyObject *__pyx_n_s_col_nom;
static PyObject *__pyx_n_s_combine_feats_pipe;
static PyObject *__pyx_n_u_comma_len_ratio;
static PyObject *__pyx_n_s_comma_len_ratio_norm_pipe;
static PyObject *__pyx_n_s_comma_len_ratio_pipe;
static PyObject *__pyx_n_u_commalenratio;
static PyObject *__pyx_n_u_commas;
static PyObject *__pyx_n_s_common;
static PyObject *__pyx_n_u_convert;
static PyObject *__pyx_n_u_count_commas;
static PyObject *__pyx_n_s_count_commas_norm_pipe;
static PyObject *__pyx_n_s_count_commas_pipe;
static PyObject *__pyx_n_u_count_words;
static PyObject *__pyx_n_s_count_words_norm_pipe;
static PyObject *__pyx_n_s_count_words_pipe;
static PyObject *__pyx_n_s_cpu_count;
static PyObject *__pyx_n_u_cv;
static PyObject *__pyx_n_u_cw;
static PyObject *__pyx_n_s_dict;
static PyObject *__pyx_n_u_dict_2;
static PyObject *__pyx_n_s_doc;
static PyObject *__pyx_n_u_drop_feats;
static PyObject *__pyx_n_s_drop_features_pipe;
static PyObject *__pyx_n_s_e;
static PyObject *__pyx_n_u_english;
static PyObject *__pyx_n_s_enumerate;
static PyObject *__pyx_n_s_eval;
static PyObject *__pyx_n_s_f;
static PyObject *__pyx_n_s_feats;
static PyObject *__pyx_n_s_features_pipe;
static PyObject *__pyx_n_s_format;
static PyObject *__pyx_n_s_fu;
static PyObject *__pyx_n_s_hash_pipe;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_init;
static PyObject *__pyx_n_s_input_feat;
static PyObject *__pyx_n_u_input_feat;
static PyObject *__pyx_n_s_input_feature;
static PyObject *__pyx_n_s_items;
static PyObject *__pyx_n_s_len;
static PyObject *__pyx_n_u_list;
static PyObject *__pyx_n_s_load_pipe;
static PyObject *__pyx_n_u_lp;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_s_make_FU_pipe;
static PyObject *__pyx_n_s_make_FU_pipe_2;
static PyObject *__pyx_n_s_make_normie;
static PyObject *__pyx_n_s_make_pipe;
static PyObject *__pyx_n_s_max_df;
static PyObject *__pyx_n_s_max_features;
static PyObject *__pyx_n_s_md5_hash;
static PyObject *__pyx_n_u_md5_hash;
static PyObject *__pyx_n_s_metaclass;
static PyObject *__pyx_n_s_min_df;
static PyObject *__pyx_n_u_missing;
static PyObject *__pyx_n_s_missing_data_pipe;
static PyObject *__pyx_n_s_module;
static PyObject *__pyx_n_s_multiprocessing;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_named_pipes;
static PyObject *__pyx_n_s_nltk_corpus;
static PyObject *__pyx_kp_u_norm;
static PyObject *__pyx_n_s_norm_feats;
static PyObject *__pyx_n_s_norm_feats_pipe;
static PyObject *__pyx_n_s_norm_pipe;
static PyObject *__pyx_n_s_normie_pipe;
static PyObject *__pyx_n_u_normies;
static PyObject *__pyx_n_u_not_stops;
static PyObject *__pyx_n_s_not_stops_norm_pipe;
static PyObject *__pyx_n_s_not_stops_pipe;
static PyObject *__pyx_n_u_notstops;
static PyObject *__pyx_n_u_ns;
static PyObject *__pyx_n_s_num_feats;
static PyObject *__pyx_n_s_num_feats_pipe;
static PyObject *__pyx_n_s_numeric_feats_pipe;
static PyObject *__pyx_n_s_object;
static PyObject *__pyx_n_s_p;
static PyObject *__pyx_n_s_params;
static PyObject *__pyx_n_u_pipe;
static PyObject *__pyx_n_s_pipe_2;
static PyObject *__pyx_n_s_pipe_names;
static PyObject *__pyx_n_s_pipel;
static PyObject *__pyx_n_s_pipeline;
static PyObject *__pyx_n_s_pipename;
static PyObject *__pyx_n_s_pipenames;
static PyObject *__pyx_n_s_pipes;
static PyObject *__pyx_kp_s_pipes_py;
static PyObject *__pyx_n_s_prepare;
static PyObject *__pyx_n_s_qualname;
static PyObject *__pyx_n_u_raw;
static PyObject *__pyx_n_s_return;
static PyObject *__pyx_n_u_select_feats;
static PyObject *__pyx_n_u_selector;
static PyObject *__pyx_n_s_self;
static PyObject *__pyx_n_u_sen_len;
static PyObject *__pyx_n_s_sen_len_norm_pipe;
static PyObject *__pyx_n_s_sen_len_pipe;
static PyObject *__pyx_n_u_sentences;
static PyObject *__pyx_n_s_set_fu_feat;
static PyObject *__pyx_n_s_set_input_feat;
static PyObject *__pyx_n_s_set_params;
static PyObject *__pyx_n_s_sklearn_decomposition;
static PyObject *__pyx_n_s_sklearn_feature_extraction_text;
static PyObject *__pyx_n_s_sklearn_pipeline;
static PyObject *__pyx_n_s_sklearn_preprocessing;
static PyObject *__pyx_n_u_sl;
static PyObject *__pyx_n_u_standard;
static PyObject *__pyx_n_s_step;
static PyObject *__pyx_n_s_steps;
static PyObject *__pyx_n_u_steps;
static PyObject *__pyx_n_s_stopWords;
static PyObject *__pyx_n_s_stop_words;
static PyObject *__pyx_n_s_stopwords;
static PyObject *__pyx_n_u_tar;
static PyObject *__pyx_n_s_tar1;
static PyObject *__pyx_n_s_tar2;
static PyObject *__pyx_n_s_targets_str_to_int_pipe;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_u_tfidf;
static PyObject *__pyx_n_s_tfidf_col_pipe;
static PyObject *__pyx_n_s_tfidf_pipe;
static PyObject *__pyx_n_u_tvector;
static PyObject *__pyx_n_u_unicode;
static PyObject *__pyx_n_s_utils;
static PyObject *__pyx_n_s_v;
static PyObject *__pyx_n_u_vec;
static PyObject *__pyx_n_s_word_vector_pipe;
static PyObject *__pyx_n_s_words;
static PyObject *__pyx_n_u_words;
static PyObject *__pyx_n_s_x;
static PyObject *__pyx_pf_5pipes_15ClassifierPipes___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_5pipes_15ClassifierPipes_2clf(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_classifier); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_2load_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipename); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_4make_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipename, PyObject *__pyx_v_params); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_6make_normie(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_col_nom); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_8chain_pipes(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipes); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_10chain_fu_pipes(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipename, PyObject *__pyx_v_pipes); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_12hash_pipe(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipe, PyObject *__pyx_v_len); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_14set_fu_feat(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipel, CYTHON_UNUSED PyObject *__pyx_v_input_feat); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_16set_input_feat(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipel, PyObject *__pyx_v_input_feat); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_18build_feature_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_input_feat, PyObject *__pyx_v_pipe_names); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_20add_num_feats(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_input_feature, PyObject *__pyx_v_num_feats); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_22add_norm_feats(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_num_feats); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_24build_scalar_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipe_names); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_26make_FU_pipe_(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipes); /* proto */
static PyObject *__pyx_pf_5pipes_4Pipe_28make_FU_pipe(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipenames); /* proto */
static PyObject *__pyx_float_0_8;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_8;
static PyObject *__pyx_int_42;
static PyObject *__pyx_int_2000;
static PyObject *__pyx_tuple__2;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__4;
static PyObject *__pyx_tuple__6;
static PyObject *__pyx_tuple__8;
static PyObject *__pyx_tuple__9;
static PyObject *__pyx_tuple__11;
static PyObject *__pyx_tuple__13;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__17;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__21;
static PyObject *__pyx_tuple__23;
static PyObject *__pyx_tuple__24;
static PyObject *__pyx_tuple__26;
static PyObject *__pyx_tuple__28;
static PyObject *__pyx_tuple__29;
static PyObject *__pyx_tuple__31;
static PyObject *__pyx_tuple__33;
static PyObject *__pyx_tuple__35;
static PyObject *__pyx_tuple__37;
static PyObject *__pyx_tuple__39;
static PyObject *__pyx_codeobj__5;
static PyObject *__pyx_codeobj__7;
static PyObject *__pyx_codeobj__10;
static PyObject *__pyx_codeobj__12;
static PyObject *__pyx_codeobj__14;
static PyObject *__pyx_codeobj__16;
static PyObject *__pyx_codeobj__18;
static PyObject *__pyx_codeobj__20;
static PyObject *__pyx_codeobj__22;
static PyObject *__pyx_codeobj__25;
static PyObject *__pyx_codeobj__27;
static PyObject *__pyx_codeobj__30;
static PyObject *__pyx_codeobj__32;
static PyObject *__pyx_codeobj__34;
static PyObject *__pyx_codeobj__36;
static PyObject *__pyx_codeobj__38;
static PyObject *__pyx_codeobj__40;
/* Late includes */

/* "pipes.py":36
 * class ClassifierPipes(object):
 *     """ Pipe factory for single step classifier pipes. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_15ClassifierPipes_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_5pipes_15ClassifierPipes_1__init__ = {"__init__", (PyCFunction)__pyx_pw_5pipes_15ClassifierPipes_1__init__, METH_O, 0};
static PyObject *__pyx_pw_5pipes_15ClassifierPipes_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_5pipes_15ClassifierPipes___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_15ClassifierPipes___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":39
 *         pass
 *
 *     def clf(self, classifier):             # <<<<<<<<<<<<<<
 *         pipename = classifier + '_pipe'
 *         pipe = getattr(cls, classifier)
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_15ClassifierPipes_3clf(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5pipes_15ClassifierPipes_3clf = {"clf", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_15ClassifierPipes_3clf, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5pipes_15ClassifierPipes_3clf(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_classifier = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("clf (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_classifier,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_classifier)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("clf", 1, 2, 2, 1); __PYX_ERR(0, 39, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "clf") < 0)) __PYX_ERR(0, 39, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_classifier = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("clf", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 39, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.ClassifierPipes.clf", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_15ClassifierPipes_2clf(__pyx_self, __pyx_v_self, __pyx_v_classifier);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_15ClassifierPipes_2clf(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_classifier) {
  PyObject *__pyx_v_pipename = NULL;
  PyObject *__pyx_v_pipe = NULL;
  PyObject *__pyx_v_clf_pipe = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("clf", 0);

  /* "pipes.py":40
 *
 *     def clf(self, classifier):
 *         pipename = classifier + '_pipe'             # <<<<<<<<<<<<<<
 *         pipe = getattr(cls, classifier)
 *         clf_pipe = Pipeline([
 */
  __pyx_t_1 = PyNumber_Add(__pyx_v_classifier, __pyx_n_u_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_pipename = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "pipes.py":41
 *     def clf(self, classifier):
 *         pipename = classifier + '_pipe'
 *         pipe = getattr(cls, classifier)             # <<<<<<<<<<<<<<
 *         clf_pipe = Pipeline([
 *             (pipename, pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_cls); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetAttr(__pyx_t_1, __pyx_v_classifier); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_pipe = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "pipes.py":42
 *         pipename = classifier + '_pipe'
 *         pipe = getattr(cls, classifier)
 *         clf_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *             (pipename, pipe),
 *         ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "pipes.py":43
 *         pipe = getattr(cls, classifier)
 *         clf_pipe = Pipeline([
 *             (pipename, pipe),             # <<<<<<<<<<<<<<
 *         ])
 *
 */
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 43, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_v_pipename);
  __Pyx_GIVEREF(__pyx_v_pipename);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_pipename);
  __Pyx_INCREF(__pyx_v_pipe);
  __Pyx_GIVEREF(__pyx_v_pipe);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_v_pipe);

  /* "pipes.py":42
 *         pipename = classifier + '_pipe'
 *         pipe = getattr(cls, classifier)
 *         clf_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *             (pipename, pipe),
 *         ])
 */
  __pyx_t_4 = PyList_New(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_t_3);
  __pyx_t_3 = 0;
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
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_3, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_4);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_clf_pipe = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "pipes.py":46
 *         ])
 *
 *         return clf_pipe             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_clf_pipe);
  __pyx_r = __pyx_v_clf_pipe;
  goto __pyx_L0;

  /* "pipes.py":39
 *         pass
 *
 *     def clf(self, classifier):             # <<<<<<<<<<<<<<
 *         pipename = classifier + '_pipe'
 *         pipe = getattr(cls, classifier)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("pipes.ClassifierPipes.clf", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_pipename);
  __Pyx_XDECREF(__pyx_v_pipe);
  __Pyx_XDECREF(__pyx_v_clf_pipe);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":53
 * class Pipe(object):
 *     """ Class with all methods needed to dynamically build pipes at runtime. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_5pipes_4Pipe_1__init__ = {"__init__", (PyCFunction)__pyx_pw_5pipes_4Pipe_1__init__, METH_O, 0};
static PyObject *__pyx_pw_5pipes_4Pipe_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_5pipes_4Pipe___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":56
 *         pass
 *
 *     def load_pipe(self, pipename: str):             # <<<<<<<<<<<<<<
 *         """ Returns a single (defined) pipe when asked for by name. """
 *         return eval(pipename)
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_3load_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_2load_pipe[] = " Returns a single (defined) pipe when asked for by name. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_3load_pipe = {"load_pipe", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_3load_pipe, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_2load_pipe};
static PyObject *__pyx_pw_5pipes_4Pipe_3load_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipename = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("load_pipe (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipename,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipename)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("load_pipe", 1, 2, 2, 1); __PYX_ERR(0, 56, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "load_pipe") < 0)) __PYX_ERR(0, 56, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipename = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("load_pipe", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 56, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.load_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_pipename), (&PyUnicode_Type), 1, "pipename", 1))) __PYX_ERR(0, 56, __pyx_L1_error)
  __pyx_r = __pyx_pf_5pipes_4Pipe_2load_pipe(__pyx_self, __pyx_v_self, __pyx_v_pipename);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_2load_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipename) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("load_pipe", 0);

  /* "pipes.py":58
 *     def load_pipe(self, pipename: str):
 *         """ Returns a single (defined) pipe when asked for by name. """
 *         return eval(pipename)             # <<<<<<<<<<<<<<
 *
 *     def make_pipe(self, pipename: str, params: dict):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_Globals(); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__pyx_v_pipename) {
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_pipename, __pyx_v_pipename) < 0) __PYX_ERR(0, 58, __pyx_L1_error)
  }
  if (__pyx_v_self) {
    if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_self, __pyx_v_self) < 0) __PYX_ERR(0, 58, __pyx_L1_error)
  }
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_v_pipename);
  __Pyx_GIVEREF(__pyx_v_pipename);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_pipename);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_t_2);
  __pyx_t_1 = 0;
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_eval, __pyx_t_3, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* "pipes.py":56
 *         pass
 *
 *     def load_pipe(self, pipename: str):             # <<<<<<<<<<<<<<
 *         """ Returns a single (defined) pipe when asked for by name. """
 *         return eval(pipename)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("pipes.Pipe.load_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":60
 *         return eval(pipename)
 *
 *     def make_pipe(self, pipename: str, params: dict):             # <<<<<<<<<<<<<<
 *         """ Creates a single step pipe with optional params. """
 *         step = (pipename, eval(pipename+'_pipe'))
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_5make_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_4make_pipe[] = " Creates a single step pipe with optional params. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_5make_pipe = {"make_pipe", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_5make_pipe, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_4make_pipe};
static PyObject *__pyx_pw_5pipes_4Pipe_5make_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipename = 0;
  PyObject *__pyx_v_params = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("make_pipe (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipename,&__pyx_n_s_params,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipename)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("make_pipe", 1, 3, 3, 1); __PYX_ERR(0, 60, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_params)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("make_pipe", 1, 3, 3, 2); __PYX_ERR(0, 60, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "make_pipe") < 0)) __PYX_ERR(0, 60, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipename = ((PyObject*)values[1]);
    __pyx_v_params = ((PyObject*)values[2]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("make_pipe", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 60, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.make_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_pipename), (&PyUnicode_Type), 1, "pipename", 1))) __PYX_ERR(0, 60, __pyx_L1_error)
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_params), (&PyDict_Type), 1, "params", 1))) __PYX_ERR(0, 60, __pyx_L1_error)
  __pyx_r = __pyx_pf_5pipes_4Pipe_4make_pipe(__pyx_self, __pyx_v_self, __pyx_v_pipename, __pyx_v_params);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_4make_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipename, PyObject *__pyx_v_params) {
  PyObject *__pyx_v_step = NULL;
  PyObject *__pyx_v_pipe = NULL;
  PyObject *__pyx_v_p = NULL;
  PyObject *__pyx_v_v = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  Py_ssize_t __pyx_t_5;
  Py_ssize_t __pyx_t_6;
  int __pyx_t_7;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *(*__pyx_t_10)(PyObject *);
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("make_pipe", 0);

  /* "pipes.py":62
 *     def make_pipe(self, pipename: str, params: dict):
 *         """ Creates a single step pipe with optional params. """
 *         step = (pipename, eval(pipename+'_pipe'))             # <<<<<<<<<<<<<<
 *         pipe = Pipeline(step)
 *         for p, v in params:
 */
  __pyx_t_1 = __Pyx_PyUnicode_ConcatSafe(__pyx_v_pipename, __pyx_n_u_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Globals(); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(7); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__pyx_v_p) {
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_p, __pyx_v_p) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  }
  if (__pyx_v_params) {
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_params, __pyx_v_params) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  }
  if (__pyx_v_pipe) {
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_pipe_2, __pyx_v_pipe) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  }
  if (__pyx_v_pipename) {
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_pipename, __pyx_v_pipename) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  }
  if (__pyx_v_self) {
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_self, __pyx_v_self) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  }
  if (__pyx_v_step) {
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_step, __pyx_v_step) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  }
  if (__pyx_v_v) {
    if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_v, __pyx_v_v) < 0) __PYX_ERR(0, 62, __pyx_L1_error)
  }
  __pyx_t_4 = PyTuple_New(3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_4, 2, __pyx_t_3);
  __pyx_t_1 = 0;
  __pyx_t_2 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_eval, __pyx_t_4, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_v_pipename);
  __Pyx_GIVEREF(__pyx_v_pipename);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_v_pipename);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_v_step = ((PyObject*)__pyx_t_4);
  __pyx_t_4 = 0;

  /* "pipes.py":63
 *         """ Creates a single step pipe with optional params. """
 *         step = (pipename, eval(pipename+'_pipe'))
 *         pipe = Pipeline(step)             # <<<<<<<<<<<<<<
 *         for p, v in params:
 *             pipe.set_params(p=v)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_4 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_v_step) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_step);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_pipe = __pyx_t_4;
  __pyx_t_4 = 0;

  /* "pipes.py":64
 *         step = (pipename, eval(pipename+'_pipe'))
 *         pipe = Pipeline(step)
 *         for p, v in params:             # <<<<<<<<<<<<<<
 *             pipe.set_params(p=v)
 *
 */
  __pyx_t_5 = 0;
  if (unlikely(__pyx_v_params == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(0, 64, __pyx_L1_error)
  }
  __pyx_t_3 = __Pyx_dict_iterator(__pyx_v_params, 1, ((PyObject *)NULL), (&__pyx_t_6), (&__pyx_t_7)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __pyx_t_4 = __pyx_t_3;
  __pyx_t_3 = 0;
  while (1) {
    __pyx_t_8 = __Pyx_dict_iter_next(__pyx_t_4, __pyx_t_6, &__pyx_t_5, &__pyx_t_3, NULL, NULL, __pyx_t_7);
    if (unlikely(__pyx_t_8 == 0)) break;
    if (unlikely(__pyx_t_8 == -1)) __PYX_ERR(0, 64, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if ((likely(PyTuple_CheckExact(__pyx_t_3))) || (PyList_CheckExact(__pyx_t_3))) {
      PyObject* sequence = __pyx_t_3;
      Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
      if (unlikely(size != 2)) {
        if (size > 2) __Pyx_RaiseTooManyValuesError(2);
        else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
        __PYX_ERR(0, 64, __pyx_L1_error)
      }
      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
      if (likely(PyTuple_CheckExact(sequence))) {
        __pyx_t_2 = PyTuple_GET_ITEM(sequence, 0);
        __pyx_t_1 = PyTuple_GET_ITEM(sequence, 1);
      } else {
        __pyx_t_2 = PyList_GET_ITEM(sequence, 0);
        __pyx_t_1 = PyList_GET_ITEM(sequence, 1);
      }
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_1);
      #else
      __pyx_t_2 = PySequence_ITEM(sequence, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 64, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_1 = PySequence_ITEM(sequence, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 64, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      #endif
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    } else {
      Py_ssize_t index = -1;
      __pyx_t_9 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 64, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_10 = Py_TYPE(__pyx_t_9)->tp_iternext;
      index = 0; __pyx_t_2 = __pyx_t_10(__pyx_t_9); if (unlikely(!__pyx_t_2)) goto __pyx_L5_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_2);
      index = 1; __pyx_t_1 = __pyx_t_10(__pyx_t_9); if (unlikely(!__pyx_t_1)) goto __pyx_L5_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_1);
      if (__Pyx_IternextUnpackEndCheck(__pyx_t_10(__pyx_t_9), 2) < 0) __PYX_ERR(0, 64, __pyx_L1_error)
      __pyx_t_10 = NULL;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      goto __pyx_L6_unpacking_done;
      __pyx_L5_unpacking_failed:;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_10 = NULL;
      if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
      __PYX_ERR(0, 64, __pyx_L1_error)
      __pyx_L6_unpacking_done:;
    }
    __Pyx_XDECREF_SET(__pyx_v_p, __pyx_t_2);
    __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_v, __pyx_t_1);
    __pyx_t_1 = 0;

    /* "pipes.py":65
 *         pipe = Pipeline(step)
 *         for p, v in params:
 *             pipe.set_params(p=v)             # <<<<<<<<<<<<<<
 *
 *         return pipe
 */
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_pipe, __pyx_n_s_set_params); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 65, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 65, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_p, __pyx_v_v) < 0) __PYX_ERR(0, 65, __pyx_L1_error)
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 65, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "pipes.py":67
 *             pipe.set_params(p=v)
 *
 *         return pipe             # <<<<<<<<<<<<<<
 *         #return Pipeline(pipe)
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_pipe);
  __pyx_r = __pyx_v_pipe;
  goto __pyx_L0;

  /* "pipes.py":60
 *         return eval(pipename)
 *
 *     def make_pipe(self, pipename: str, params: dict):             # <<<<<<<<<<<<<<
 *         """ Creates a single step pipe with optional params. """
 *         step = (pipename, eval(pipename+'_pipe'))
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("pipes.Pipe.make_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_step);
  __Pyx_XDECREF(__pyx_v_pipe);
  __Pyx_XDECREF(__pyx_v_p);
  __Pyx_XDECREF(__pyx_v_v);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":70
 *         #return Pipeline(pipe)
 *
 *     def make_normie(self, col_nom: str):             # <<<<<<<<<<<<<<
 *         """ Sselector pipe to normalize a given numeric column.
 *         input: dataframe containing the target column.
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_7make_normie(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_6make_normie[] = " Sselector pipe to normalize a given numeric column.\n        input: dataframe containing the target column.\n        output: normalised matrix representation of column. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_7make_normie = {"make_normie", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_7make_normie, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_6make_normie};
static PyObject *__pyx_pw_5pipes_4Pipe_7make_normie(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col_nom = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("make_normie (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col_nom,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col_nom)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("make_normie", 1, 2, 2, 1); __PYX_ERR(0, 70, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "make_normie") < 0)) __PYX_ERR(0, 70, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_col_nom = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("make_normie", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 70, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.make_normie", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_col_nom), (&PyUnicode_Type), 1, "col_nom", 1))) __PYX_ERR(0, 70, __pyx_L1_error)
  __pyx_r = __pyx_pf_5pipes_4Pipe_6make_normie(__pyx_self, __pyx_v_self, __pyx_v_col_nom);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_6make_normie(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_col_nom) {
  PyObject *__pyx_v_norm_pipe = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("make_normie", 0);

  /* "pipes.py":75
 *         output: normalised matrix representation of column. """
 *         #step = [ (x, eval(x+'_pipe')) for x in pipe_names ]
 *         norm_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *             ('selector', Trans.NumberSelector(col=col_nom)),
 *             ('standard', StandardScaler()),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "pipes.py":76
 *         #step = [ (x, eval(x+'_pipe')) for x in pipe_names ]
 *         norm_pipe = Pipeline([
 *             ('selector', Trans.NumberSelector(col=col_nom)),             # <<<<<<<<<<<<<<
 *             ('standard', StandardScaler()),
 *             ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Trans); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_NumberSelector); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_col, __pyx_v_col_nom) < 0) __PYX_ERR(0, 76, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":77
 *         norm_pipe = Pipeline([
 *             ('selector', Trans.NumberSelector(col=col_nom)),
 *             ('standard', StandardScaler()),             # <<<<<<<<<<<<<<
 *             ])
 *         norm_pipe[0].set_params(col=col_nom)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_5 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":75
 *         output: normalised matrix representation of column. """
 *         #step = [ (x, eval(x+'_pipe')) for x in pipe_names ]
 *         norm_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *             ('selector', Trans.NumberSelector(col=col_nom)),
 *             ('standard', StandardScaler()),
 */
  __pyx_t_5 = PyList_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_5, 1, __pyx_t_4);
  __pyx_t_3 = 0;
  __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 75, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_norm_pipe = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "pipes.py":79
 *             ('standard', StandardScaler()),
 *             ])
 *         norm_pipe[0].set_params(col=col_nom)             # <<<<<<<<<<<<<<
 *         #norm_pipe.set_params(verbose=True)
 *         return norm_pipe
 */
  __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_norm_pipe, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_set_params); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_col, __pyx_v_col_nom) < 0) __PYX_ERR(0, 79, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "pipes.py":81
 *         norm_pipe[0].set_params(col=col_nom)
 *         #norm_pipe.set_params(verbose=True)
 *         return norm_pipe             # <<<<<<<<<<<<<<
 *
 *     # @Deprecated
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_norm_pipe);
  __pyx_r = __pyx_v_norm_pipe;
  goto __pyx_L0;

  /* "pipes.py":70
 *         #return Pipeline(pipe)
 *
 *     def make_normie(self, col_nom: str):             # <<<<<<<<<<<<<<
 *         """ Sselector pipe to normalize a given numeric column.
 *         input: dataframe containing the target column.
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("pipes.Pipe.make_normie", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_norm_pipe);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":89
 *     #    return Pipeline(features)
 *
 *     def chain_pipes(self, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a mixed list of pipes and pipe names, returns a Pipeline of fully named pipes.
 *         :param pipes: a list which may contain both pipes and pipe names.
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_9chain_pipes(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_8chain_pipes[] = " Given a mixed list of pipes and pipe names, returns a Pipeline of fully named pipes.\n        :param pipes: a list which may contain both pipes and pipe names.\n        This ofc has the effect of converting the pipename into a pipe for any runtime reference to this pipename, even tho pipename is a primitive, not a class, bc Python is pass by object reference. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_9chain_pipes = {"chain_pipes", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_9chain_pipes, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_8chain_pipes};
static PyObject *__pyx_pw_5pipes_4Pipe_9chain_pipes(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipes = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("chain_pipes (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipes,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipes)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("chain_pipes", 1, 2, 2, 1); __PYX_ERR(0, 89, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "chain_pipes") < 0)) __PYX_ERR(0, 89, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipes = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("chain_pipes", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 89, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.chain_pipes", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_pipes), (&PyList_Type), 1, "pipes", 1))) __PYX_ERR(0, 89, __pyx_L1_error)
  __pyx_r = __pyx_pf_5pipes_4Pipe_8chain_pipes(__pyx_self, __pyx_v_self, __pyx_v_pipes);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_8chain_pipes(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipes) {
  Py_ssize_t __pyx_v_e;
  PyObject *__pyx_v_p = NULL;
  PyObject *__pyx_v_steps = NULL;
  PyObject *__pyx_7genexpr__pyx_v_p = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  Py_ssize_t __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("chain_pipes", 0);

  /* "pipes.py":93
 *         :param pipes: a list which may contain both pipes and pipe names.
 *         This ofc has the effect of converting the pipename into a pipe for any runtime reference to this pipename, even tho pipename is a primitive, not a class, bc Python is pass by object reference. """
 *         for e, p in enumerate(pipes):             # <<<<<<<<<<<<<<
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')
 */
  __pyx_t_1 = 0;
  __pyx_t_2 = __pyx_v_pipes; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
  for (;;) {
    if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_4 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_4); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 93, __pyx_L1_error)
    #else
    __pyx_t_4 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 93, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    #endif
    __Pyx_XDECREF_SET(__pyx_v_p, __pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_v_e = __pyx_t_1;
    __pyx_t_1 = (__pyx_t_1 + 1);

    /* "pipes.py":94
 *         This ofc has the effect of converting the pipename into a pipe for any runtime reference to this pipename, even tho pipename is a primitive, not a class, bc Python is pass by object reference. """
 *         for e, p in enumerate(pipes):
 *             if type(p) == str:             # <<<<<<<<<<<<<<
 *                 pipes[e] = eval(p+'_pipe')
 *         #for p in pipes:
 */
    __pyx_t_4 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_p)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 94, __pyx_L1_error)
    __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 94, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__pyx_t_5) {

      /* "pipes.py":95
 *         for e, p in enumerate(pipes):
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')             # <<<<<<<<<<<<<<
 *         #for p in pipes:
 *         #    foo = self.hash_pipe(p) ## ???
 */
      __pyx_t_4 = PyNumber_Add(__pyx_v_p, __pyx_n_u_pipe); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 95, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_6 = __Pyx_Globals(); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 95, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_7 = __Pyx_PyDict_NewPresized(5); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 95, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_8 = PyInt_FromSsize_t(__pyx_v_e); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 95, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (__pyx_t_8) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_e, __pyx_t_8) < 0) __PYX_ERR(0, 95, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      if (__pyx_v_p) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_p, __pyx_v_p) < 0) __PYX_ERR(0, 95, __pyx_L1_error)
      }
      if (__pyx_v_pipes) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_pipes, __pyx_v_pipes) < 0) __PYX_ERR(0, 95, __pyx_L1_error)
      }
      if (__pyx_v_self) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_self, __pyx_v_self) < 0) __PYX_ERR(0, 95, __pyx_L1_error)
      }
      if (__pyx_v_steps) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_steps, __pyx_v_steps) < 0) __PYX_ERR(0, 95, __pyx_L1_error)
      }
      __pyx_t_8 = PyTuple_New(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 95, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_GIVEREF(__pyx_t_4);
      PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_4);
      __Pyx_GIVEREF(__pyx_t_6);
      PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_6);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_t_7);
      __pyx_t_4 = 0;
      __pyx_t_6 = 0;
      __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_Call(__pyx_builtin_eval, __pyx_t_8, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 95, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      if (unlikely(__pyx_v_pipes == Py_None)) {
        PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
        __PYX_ERR(0, 95, __pyx_L1_error)
      }
      if (unlikely(__Pyx_SetItemInt(__pyx_v_pipes, __pyx_v_e, __pyx_t_7, Py_ssize_t, 1, PyInt_FromSsize_t, 1, 1, 1) < 0)) __PYX_ERR(0, 95, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

      /* "pipes.py":94
 *         This ofc has the effect of converting the pipename into a pipe for any runtime reference to this pipename, even tho pipename is a primitive, not a class, bc Python is pass by object reference. """
 *         for e, p in enumerate(pipes):
 *             if type(p) == str:             # <<<<<<<<<<<<<<
 *                 pipes[e] = eval(p+'_pipe')
 *         #for p in pipes:
 */
    }

    /* "pipes.py":93
 *         :param pipes: a list which may contain both pipes and pipe names.
 *         This ofc has the effect of converting the pipename into a pipe for any runtime reference to this pipename, even tho pipename is a primitive, not a class, bc Python is pass by object reference. """
 *         for e, p in enumerate(pipes):             # <<<<<<<<<<<<<<
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')
 */
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":98
 *         #for p in pipes:
 *         #    foo = self.hash_pipe(p) ## ???
 *         steps = [ (self.hash_pipe(p), p) for p in pipes ]             # <<<<<<<<<<<<<<
 *
 *         return Pipeline(steps)
 */
  { /* enter inner scope */
    __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 98, __pyx_L8_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (unlikely(__pyx_v_pipes == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
      __PYX_ERR(0, 98, __pyx_L8_error)
    }
    __pyx_t_7 = __pyx_v_pipes; __Pyx_INCREF(__pyx_t_7); __pyx_t_1 = 0;
    for (;;) {
      if (__pyx_t_1 >= PyList_GET_SIZE(__pyx_t_7)) break;
      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
      __pyx_t_8 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_1); __Pyx_INCREF(__pyx_t_8); __pyx_t_1++; if (unlikely(0 < 0)) __PYX_ERR(0, 98, __pyx_L8_error)
      #else
      __pyx_t_8 = PySequence_ITEM(__pyx_t_7, __pyx_t_1); __pyx_t_1++; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 98, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_8);
      #endif
      __Pyx_XDECREF_SET(__pyx_7genexpr__pyx_v_p, __pyx_t_8);
      __pyx_t_8 = 0;
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_pipe); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 98, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_4 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
        __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_6);
        if (likely(__pyx_t_4)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
          __Pyx_INCREF(__pyx_t_4);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_6, function);
        }
      }
      __pyx_t_8 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_4, __pyx_7genexpr__pyx_v_p) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_7genexpr__pyx_v_p);
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 98, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 98, __pyx_L8_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GIVEREF(__pyx_t_8);
      PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_8);
      __Pyx_INCREF(__pyx_7genexpr__pyx_v_p);
      __Pyx_GIVEREF(__pyx_7genexpr__pyx_v_p);
      PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_7genexpr__pyx_v_p);
      __pyx_t_8 = 0;
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_2, (PyObject*)__pyx_t_6))) __PYX_ERR(0, 98, __pyx_L8_error)
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    }
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_7genexpr__pyx_v_p); __pyx_7genexpr__pyx_v_p = 0;
    goto __pyx_L11_exit_scope;
    __pyx_L8_error:;
    __Pyx_XDECREF(__pyx_7genexpr__pyx_v_p); __pyx_7genexpr__pyx_v_p = 0;
    goto __pyx_L1_error;
    __pyx_L11_exit_scope:;
  } /* exit inner scope */
  __pyx_v_steps = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":100
 *         steps = [ (self.hash_pipe(p), p) for p in pipes ]
 *
 *         return Pipeline(steps)             # <<<<<<<<<<<<<<
 *
 *     def chain_fu_pipes(self, pipename: str, pipes: list) -> Pipeline:
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_7);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_7, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_6, __pyx_v_steps) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_v_steps);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 100, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* "pipes.py":89
 *     #    return Pipeline(features)
 *
 *     def chain_pipes(self, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a mixed list of pipes and pipe names, returns a Pipeline of fully named pipes.
 *         :param pipes: a list which may contain both pipes and pipe names.
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("pipes.Pipe.chain_pipes", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_p);
  __Pyx_XDECREF(__pyx_v_steps);
  __Pyx_XDECREF(__pyx_7genexpr__pyx_v_p);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":102
 *         return Pipeline(steps)
 *
 *     def chain_fu_pipes(self, pipename: str, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a list of pipes, returns a FeatureUnion of named pipes.
 *         Sub-pipe names are automatically generated as a hash of their steps.
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_11chain_fu_pipes(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_10chain_fu_pipes[] = " Given a list of pipes, returns a FeatureUnion of named pipes.\n        Sub-pipe names are automatically generated as a hash of their steps.\n        :param pipename: name for this FeatureUnion pipe.\n        :param pipes: a list of pipes. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_11chain_fu_pipes = {"chain_fu_pipes", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_11chain_fu_pipes, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_10chain_fu_pipes};
static PyObject *__pyx_pw_5pipes_4Pipe_11chain_fu_pipes(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipename = 0;
  PyObject *__pyx_v_pipes = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("chain_fu_pipes (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipename,&__pyx_n_s_pipes,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipename)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("chain_fu_pipes", 1, 3, 3, 1); __PYX_ERR(0, 102, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipes)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("chain_fu_pipes", 1, 3, 3, 2); __PYX_ERR(0, 102, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "chain_fu_pipes") < 0)) __PYX_ERR(0, 102, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipename = ((PyObject*)values[1]);
    __pyx_v_pipes = ((PyObject*)values[2]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("chain_fu_pipes", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 102, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.chain_fu_pipes", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_pipename), (&PyUnicode_Type), 1, "pipename", 1))) __PYX_ERR(0, 102, __pyx_L1_error)
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_pipes), (&PyList_Type), 1, "pipes", 1))) __PYX_ERR(0, 102, __pyx_L1_error)
  __pyx_r = __pyx_pf_5pipes_4Pipe_10chain_fu_pipes(__pyx_self, __pyx_v_self, __pyx_v_pipename, __pyx_v_pipes);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_10chain_fu_pipes(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipename, PyObject *__pyx_v_pipes) {
  Py_ssize_t __pyx_v_e;
  PyObject *__pyx_v_p = NULL;
  PyObject *__pyx_v_feats = NULL;
  PyObject *__pyx_v_fu = NULL;
  PyObject *__pyx_8genexpr1__pyx_v_x = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  Py_ssize_t __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("chain_fu_pipes", 0);

  /* "pipes.py":107
 *         :param pipename: name for this FeatureUnion pipe.
 *         :param pipes: a list of pipes. """
 *         for e, p in enumerate(pipes):             # <<<<<<<<<<<<<<
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')
 */
  __pyx_t_1 = 0;
  __pyx_t_2 = __pyx_v_pipes; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
  for (;;) {
    if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_4 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_4); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 107, __pyx_L1_error)
    #else
    __pyx_t_4 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 107, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    #endif
    __Pyx_XDECREF_SET(__pyx_v_p, __pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_v_e = __pyx_t_1;
    __pyx_t_1 = (__pyx_t_1 + 1);

    /* "pipes.py":108
 *         :param pipes: a list of pipes. """
 *         for e, p in enumerate(pipes):
 *             if type(p) == str:             # <<<<<<<<<<<<<<
 *                 pipes[e] = eval(p+'_pipe')
 *         if len(pipes) > 0:
 */
    __pyx_t_4 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_p)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 108, __pyx_L1_error)
    __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 108, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__pyx_t_5) {

      /* "pipes.py":109
 *         for e, p in enumerate(pipes):
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')             # <<<<<<<<<<<<<<
 *         if len(pipes) > 0:
 *             feats = [ (self.hash_pipe(x), x) for x in pipes ]
 */
      __pyx_t_4 = PyNumber_Add(__pyx_v_p, __pyx_n_u_pipe); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 109, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_6 = __Pyx_Globals(); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 109, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_7 = __Pyx_PyDict_NewPresized(7); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 109, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_8 = PyInt_FromSsize_t(__pyx_v_e); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 109, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      if (__pyx_t_8) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_e, __pyx_t_8) < 0) __PYX_ERR(0, 109, __pyx_L1_error)
      }
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      if (__pyx_v_feats) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_feats, __pyx_v_feats) < 0) __PYX_ERR(0, 109, __pyx_L1_error)
      }
      if (__pyx_v_fu) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_fu, __pyx_v_fu) < 0) __PYX_ERR(0, 109, __pyx_L1_error)
      }
      if (__pyx_v_p) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_p, __pyx_v_p) < 0) __PYX_ERR(0, 109, __pyx_L1_error)
      }
      if (__pyx_v_pipename) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_pipename, __pyx_v_pipename) < 0) __PYX_ERR(0, 109, __pyx_L1_error)
      }
      if (__pyx_v_pipes) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_pipes, __pyx_v_pipes) < 0) __PYX_ERR(0, 109, __pyx_L1_error)
      }
      if (__pyx_v_self) {
        if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_self, __pyx_v_self) < 0) __PYX_ERR(0, 109, __pyx_L1_error)
      }
      __pyx_t_8 = PyTuple_New(3); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 109, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_GIVEREF(__pyx_t_4);
      PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_4);
      __Pyx_GIVEREF(__pyx_t_6);
      PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_6);
      __Pyx_GIVEREF(__pyx_t_7);
      PyTuple_SET_ITEM(__pyx_t_8, 2, __pyx_t_7);
      __pyx_t_4 = 0;
      __pyx_t_6 = 0;
      __pyx_t_7 = 0;
      __pyx_t_7 = __Pyx_PyObject_Call(__pyx_builtin_eval, __pyx_t_8, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 109, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      if (unlikely(__pyx_v_pipes == Py_None)) {
        PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
        __PYX_ERR(0, 109, __pyx_L1_error)
      }
      if (unlikely(__Pyx_SetItemInt(__pyx_v_pipes, __pyx_v_e, __pyx_t_7, Py_ssize_t, 1, PyInt_FromSsize_t, 1, 1, 1) < 0)) __PYX_ERR(0, 109, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

      /* "pipes.py":108
 *         :param pipes: a list of pipes. """
 *         for e, p in enumerate(pipes):
 *             if type(p) == str:             # <<<<<<<<<<<<<<
 *                 pipes[e] = eval(p+'_pipe')
 *         if len(pipes) > 0:
 */
    }

    /* "pipes.py":107
 *         :param pipename: name for this FeatureUnion pipe.
 *         :param pipes: a list of pipes. """
 *         for e, p in enumerate(pipes):             # <<<<<<<<<<<<<<
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')
 */
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":110
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')
 *         if len(pipes) > 0:             # <<<<<<<<<<<<<<
 *             feats = [ (self.hash_pipe(x), x) for x in pipes ]
 *             fu = FeatureUnion(feats)
 */
  if (unlikely(__pyx_v_pipes == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "object of type 'NoneType' has no len()");
    __PYX_ERR(0, 110, __pyx_L1_error)
  }
  __pyx_t_1 = PyList_GET_SIZE(__pyx_v_pipes); if (unlikely(__pyx_t_1 == ((Py_ssize_t)-1))) __PYX_ERR(0, 110, __pyx_L1_error)
  __pyx_t_5 = ((__pyx_t_1 > 0) != 0);
  if (__pyx_t_5) {

    /* "pipes.py":111
 *                 pipes[e] = eval(p+'_pipe')
 *         if len(pipes) > 0:
 *             feats = [ (self.hash_pipe(x), x) for x in pipes ]             # <<<<<<<<<<<<<<
 *             fu = FeatureUnion(feats)
 *
 */
    { /* enter inner scope */
      __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 111, __pyx_L9_error)
      __Pyx_GOTREF(__pyx_t_2);
      if (unlikely(__pyx_v_pipes == Py_None)) {
        PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
        __PYX_ERR(0, 111, __pyx_L9_error)
      }
      __pyx_t_7 = __pyx_v_pipes; __Pyx_INCREF(__pyx_t_7); __pyx_t_1 = 0;
      for (;;) {
        if (__pyx_t_1 >= PyList_GET_SIZE(__pyx_t_7)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_8 = PyList_GET_ITEM(__pyx_t_7, __pyx_t_1); __Pyx_INCREF(__pyx_t_8); __pyx_t_1++; if (unlikely(0 < 0)) __PYX_ERR(0, 111, __pyx_L9_error)
        #else
        __pyx_t_8 = PySequence_ITEM(__pyx_t_7, __pyx_t_1); __pyx_t_1++; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 111, __pyx_L9_error)
        __Pyx_GOTREF(__pyx_t_8);
        #endif
        __Pyx_XDECREF_SET(__pyx_8genexpr1__pyx_v_x, __pyx_t_8);
        __pyx_t_8 = 0;
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_pipe); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 111, __pyx_L9_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_4 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
          __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_6);
          if (likely(__pyx_t_4)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
            __Pyx_INCREF(__pyx_t_4);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_6, function);
          }
        }
        __pyx_t_8 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_4, __pyx_8genexpr1__pyx_v_x) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_8genexpr1__pyx_v_x);
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 111, __pyx_L9_error)
        __Pyx_GOTREF(__pyx_t_8);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 111, __pyx_L9_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_GIVEREF(__pyx_t_8);
        PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_8);
        __Pyx_INCREF(__pyx_8genexpr1__pyx_v_x);
        __Pyx_GIVEREF(__pyx_8genexpr1__pyx_v_x);
        PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_8genexpr1__pyx_v_x);
        __pyx_t_8 = 0;
        if (unlikely(__Pyx_ListComp_Append(__pyx_t_2, (PyObject*)__pyx_t_6))) __PYX_ERR(0, 111, __pyx_L9_error)
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      }
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x); __pyx_8genexpr1__pyx_v_x = 0;
      goto __pyx_L12_exit_scope;
      __pyx_L9_error:;
      __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x); __pyx_8genexpr1__pyx_v_x = 0;
      goto __pyx_L1_error;
      __pyx_L12_exit_scope:;
    } /* exit inner scope */
    __pyx_v_feats = ((PyObject*)__pyx_t_2);
    __pyx_t_2 = 0;

    /* "pipes.py":112
 *         if len(pipes) > 0:
 *             feats = [ (self.hash_pipe(x), x) for x in pipes ]
 *             fu = FeatureUnion(feats)             # <<<<<<<<<<<<<<
 *
 *             return Pipeline([(pipename, fu)]) # needs better error handling, thx.
 */
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 112, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_6 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_6, __pyx_v_feats) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_v_feats);
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 112, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_v_fu = __pyx_t_2;
    __pyx_t_2 = 0;

    /* "pipes.py":114
 *             fu = FeatureUnion(feats)
 *
 *             return Pipeline([(pipename, fu)]) # needs better error handling, thx.             # <<<<<<<<<<<<<<
 *
 *     """
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_INCREF(__pyx_v_pipename);
    __Pyx_GIVEREF(__pyx_v_pipename);
    PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_v_pipename);
    __Pyx_INCREF(__pyx_v_fu);
    __Pyx_GIVEREF(__pyx_v_fu);
    PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_v_fu);
    __pyx_t_8 = PyList_New(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __Pyx_GIVEREF(__pyx_t_6);
    PyList_SET_ITEM(__pyx_t_8, 0, __pyx_t_6);
    __pyx_t_6 = 0;
    __pyx_t_6 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_6, __pyx_t_8) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_8);
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_r = __pyx_t_2;
    __pyx_t_2 = 0;
    goto __pyx_L0;

    /* "pipes.py":110
 *             if type(p) == str:
 *                 pipes[e] = eval(p+'_pipe')
 *         if len(pipes) > 0:             # <<<<<<<<<<<<<<
 *             feats = [ (self.hash_pipe(x), x) for x in pipes ]
 *             fu = FeatureUnion(feats)
 */
  }

  /* "pipes.py":102
 *         return Pipeline(steps)
 *
 *     def chain_fu_pipes(self, pipename: str, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a list of pipes, returns a FeatureUnion of named pipes.
 *         Sub-pipe names are automatically generated as a hash of their steps.
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("pipes.Pipe.chain_fu_pipes", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_p);
  __Pyx_XDECREF(__pyx_v_feats);
  __Pyx_XDECREF(__pyx_v_fu);
  __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_x);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":129
 *     """
 *
 *     def hash_pipe(self, pipe, len=8) ->'md5_hash':             # <<<<<<<<<<<<<<
 *         """ Generate a handle for a given pipe by taking the hash of its steps. """
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_13hash_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_12hash_pipe[] = " Generate a handle for a given pipe by taking the hash of its steps. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_13hash_pipe = {"hash_pipe", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_13hash_pipe, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_12hash_pipe};
static PyObject *__pyx_pw_5pipes_4Pipe_13hash_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipe = 0;
  PyObject *__pyx_v_len = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("hash_pipe (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipe_2,&__pyx_n_s_len,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)__pyx_int_8));
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipe_2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("hash_pipe", 0, 2, 3, 1); __PYX_ERR(0, 129, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_len);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "hash_pipe") < 0)) __PYX_ERR(0, 129, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_pipe = values[1];
    __pyx_v_len = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("hash_pipe", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 129, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.hash_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_4Pipe_12hash_pipe(__pyx_self, __pyx_v_self, __pyx_v_pipe, __pyx_v_len);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_12hash_pipe(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipe, PyObject *__pyx_v_len) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("hash_pipe", 0);

  /* "pipes.py":131
 *     def hash_pipe(self, pipe, len=8) ->'md5_hash':
 *         """ Generate a handle for a given pipe by taking the hash of its steps. """
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)             # <<<<<<<<<<<<<<
 *
 *     def set_fu_feat(self, pipel, input_feat):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_utils); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_md5_hash); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_pipe, __pyx_n_s_dict); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_steps); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 131, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  __pyx_t_5 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
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
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_v_len};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_v_len};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  {
    __pyx_t_6 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    if (__pyx_t_4) {
      __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_4); __pyx_t_4 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_5, __pyx_t_2);
    __Pyx_INCREF(__pyx_v_len);
    __Pyx_GIVEREF(__pyx_v_len);
    PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_5, __pyx_v_len);
    __pyx_t_2 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 131, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "pipes.py":129
 *     """
 *
 *     def hash_pipe(self, pipe, len=8) ->'md5_hash':             # <<<<<<<<<<<<<<
 *         """ Generate a handle for a given pipe by taking the hash of its steps. """
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("pipes.Pipe.hash_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":133
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 *
 *     def set_fu_feat(self, pipel, input_feat):             # <<<<<<<<<<<<<<
 *         for p in pipel:
 *             p[0].set_params(col='input_feat')
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_15set_fu_feat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5pipes_4Pipe_15set_fu_feat = {"set_fu_feat", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_15set_fu_feat, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5pipes_4Pipe_15set_fu_feat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipel = 0;
  CYTHON_UNUSED PyObject *__pyx_v_input_feat = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("set_fu_feat (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipel,&__pyx_n_s_input_feat,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipel)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("set_fu_feat", 1, 3, 3, 1); __PYX_ERR(0, 133, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_input_feat)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("set_fu_feat", 1, 3, 3, 2); __PYX_ERR(0, 133, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "set_fu_feat") < 0)) __PYX_ERR(0, 133, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipel = values[1];
    __pyx_v_input_feat = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("set_fu_feat", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 133, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.set_fu_feat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_4Pipe_14set_fu_feat(__pyx_self, __pyx_v_self, __pyx_v_pipel, __pyx_v_input_feat);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_14set_fu_feat(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipel, CYTHON_UNUSED PyObject *__pyx_v_input_feat) {
  PyObject *__pyx_v_p = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *(*__pyx_t_3)(PyObject *);
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("set_fu_feat", 0);

  /* "pipes.py":134
 *
 *     def set_fu_feat(self, pipel, input_feat):
 *         for p in pipel:             # <<<<<<<<<<<<<<
 *             p[0].set_params(col='input_feat')
 *
 */
  if (likely(PyList_CheckExact(__pyx_v_pipel)) || PyTuple_CheckExact(__pyx_v_pipel)) {
    __pyx_t_1 = __pyx_v_pipel; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_pipel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 134, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 134, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 134, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 134, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 134, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 134, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 134, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XDECREF_SET(__pyx_v_p, __pyx_t_4);
    __pyx_t_4 = 0;

    /* "pipes.py":135
 *     def set_fu_feat(self, pipel, input_feat):
 *         for p in pipel:
 *             p[0].set_params(col='input_feat')             # <<<<<<<<<<<<<<
 *
 *         return pipel
 */
    __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_p, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 135, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_set_params); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 135, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 135, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_col, __pyx_n_u_input_feat) < 0) __PYX_ERR(0, 135, __pyx_L1_error)
    __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_4); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 135, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

    /* "pipes.py":134
 *
 *     def set_fu_feat(self, pipel, input_feat):
 *         for p in pipel:             # <<<<<<<<<<<<<<
 *             p[0].set_params(col='input_feat')
 *
 */
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":137
 *             p[0].set_params(col='input_feat')
 *
 *         return pipel             # <<<<<<<<<<<<<<
 *
 *     def set_input_feat(self, pipel, input_feat='raw'):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_pipel);
  __pyx_r = __pyx_v_pipel;
  goto __pyx_L0;

  /* "pipes.py":133
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 *
 *     def set_fu_feat(self, pipel, input_feat):             # <<<<<<<<<<<<<<
 *         for p in pipel:
 *             p[0].set_params(col='input_feat')
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("pipes.Pipe.set_fu_feat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_p);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":139
 *         return pipel
 *
 *     def set_input_feat(self, pipel, input_feat='raw'):             # <<<<<<<<<<<<<<
 *         """ Sets the input feature for a given pipe. This is usually a dataframe column. """
 *         #pipel.set_params(col=input_feat)
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_17set_input_feat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_16set_input_feat[] = " Sets the input feature for a given pipe. This is usually a dataframe column. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_17set_input_feat = {"set_input_feat", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_17set_input_feat, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_16set_input_feat};
static PyObject *__pyx_pw_5pipes_4Pipe_17set_input_feat(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipel = 0;
  PyObject *__pyx_v_input_feat = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("set_input_feat (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipel,&__pyx_n_s_input_feat,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject*)__pyx_n_u_raw));
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipel)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("set_input_feat", 0, 2, 3, 1); __PYX_ERR(0, 139, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_input_feat);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "set_input_feat") < 0)) __PYX_ERR(0, 139, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_pipel = values[1];
    __pyx_v_input_feat = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("set_input_feat", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 139, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.set_input_feat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_4Pipe_16set_input_feat(__pyx_self, __pyx_v_self, __pyx_v_pipel, __pyx_v_input_feat);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_16set_input_feat(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipel, PyObject *__pyx_v_input_feat) {
  PyObject *__pyx_v_x = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *(*__pyx_t_3)(PyObject *);
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("set_input_feat", 0);

  /* "pipes.py":142
 *         """ Sets the input feature for a given pipe. This is usually a dataframe column. """
 *         #pipel.set_params(col=input_feat)
 *         for x in pipel:             # <<<<<<<<<<<<<<
 *             x[0].set_params(col=input_feat)
 *
 */
  if (likely(PyList_CheckExact(__pyx_v_pipel)) || PyTuple_CheckExact(__pyx_v_pipel)) {
    __pyx_t_1 = __pyx_v_pipel; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_pipel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 142, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 142, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 142, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 142, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 142, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 142, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 142, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XDECREF_SET(__pyx_v_x, __pyx_t_4);
    __pyx_t_4 = 0;

    /* "pipes.py":143
 *         #pipel.set_params(col=input_feat)
 *         for x in pipel:
 *             x[0].set_params(col=input_feat)             # <<<<<<<<<<<<<<
 *
 *         return pipel
 */
    __pyx_t_4 = __Pyx_GetItemInt(__pyx_v_x, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 143, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_set_params); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 143, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 143, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_col, __pyx_v_input_feat) < 0) __PYX_ERR(0, 143, __pyx_L1_error)
    __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_4); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 143, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

    /* "pipes.py":142
 *         """ Sets the input feature for a given pipe. This is usually a dataframe column. """
 *         #pipel.set_params(col=input_feat)
 *         for x in pipel:             # <<<<<<<<<<<<<<
 *             x[0].set_params(col=input_feat)
 *
 */
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":145
 *             x[0].set_params(col=input_feat)
 *
 *         return pipel             # <<<<<<<<<<<<<<
 *
 *     def build_feature_pipe(self, input_feat, pipe_names):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_pipel);
  __pyx_r = __pyx_v_pipel;
  goto __pyx_L0;

  /* "pipes.py":139
 *         return pipel
 *
 *     def set_input_feat(self, pipel, input_feat='raw'):             # <<<<<<<<<<<<<<
 *         """ Sets the input feature for a given pipe. This is usually a dataframe column. """
 *         #pipel.set_params(col=input_feat)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("pipes.Pipe.set_input_feat", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_x);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":147
 *         return pipel
 *
 *     def build_feature_pipe(self, input_feat, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained feature pipeline when given a feature and a list of pipes. """
 *         pipeline = self.chain_pipes(pipe_names)
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_19build_feature_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_18build_feature_pipe[] = " Returns a chained feature pipeline when given a feature and a list of pipes. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_19build_feature_pipe = {"build_feature_pipe", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_19build_feature_pipe, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_18build_feature_pipe};
static PyObject *__pyx_pw_5pipes_4Pipe_19build_feature_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_input_feat = 0;
  PyObject *__pyx_v_pipe_names = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("build_feature_pipe (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_input_feat,&__pyx_n_s_pipe_names,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_input_feat)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("build_feature_pipe", 1, 3, 3, 1); __PYX_ERR(0, 147, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipe_names)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("build_feature_pipe", 1, 3, 3, 2); __PYX_ERR(0, 147, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "build_feature_pipe") < 0)) __PYX_ERR(0, 147, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_input_feat = values[1];
    __pyx_v_pipe_names = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("build_feature_pipe", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 147, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.build_feature_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_4Pipe_18build_feature_pipe(__pyx_self, __pyx_v_self, __pyx_v_input_feat, __pyx_v_pipe_names);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_18build_feature_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_input_feat, PyObject *__pyx_v_pipe_names) {
  PyObject *__pyx_v_pipeline = NULL;
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
  __Pyx_RefNannySetupContext("build_feature_pipe", 0);

  /* "pipes.py":149
 *     def build_feature_pipe(self, input_feat, pipe_names):
 *         """ Returns a chained feature pipeline when given a feature and a list of pipes. """
 *         pipeline = self.chain_pipes(pipe_names)             # <<<<<<<<<<<<<<
 *         pipeline = self.set_input_feat(pipeline, input_feat)
 *
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_chain_pipes); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 149, __pyx_L1_error)
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
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_pipe_names) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_pipe_names);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_pipeline = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "pipes.py":150
 *         """ Returns a chained feature pipeline when given a feature and a list of pipes. """
 *         pipeline = self.chain_pipes(pipe_names)
 *         pipeline = self.set_input_feat(pipeline, input_feat)             # <<<<<<<<<<<<<<
 *
 *         return pipeline
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_set_input_feat); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 150, __pyx_L1_error)
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
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_pipeline, __pyx_v_input_feat};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_pipeline, __pyx_v_input_feat};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 150, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_pipeline);
    __Pyx_GIVEREF(__pyx_v_pipeline);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_pipeline);
    __Pyx_INCREF(__pyx_v_input_feat);
    __Pyx_GIVEREF(__pyx_v_input_feat);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_input_feat);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 150, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF_SET(__pyx_v_pipeline, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":152
 *         pipeline = self.set_input_feat(pipeline, input_feat)
 *
 *         return pipeline             # <<<<<<<<<<<<<<
 *
 *     def add_num_feats(self, input_feature, num_feats):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_pipeline);
  __pyx_r = __pyx_v_pipeline;
  goto __pyx_L0;

  /* "pipes.py":147
 *         return pipel
 *
 *     def build_feature_pipe(self, input_feat, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained feature pipeline when given a feature and a list of pipes. """
 *         pipeline = self.chain_pipes(pipe_names)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("pipes.Pipe.build_feature_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_pipeline);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":154
 *         return pipeline
 *
 *     def add_num_feats(self, input_feature, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to generate them. """
 *         num_feats_pipe = self.build_feature_pipe(input_feature, num_feats)
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_21add_num_feats(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_20add_num_feats[] = " Given a list of numeric features, builds a pipe to generate them. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_21add_num_feats = {"add_num_feats", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_21add_num_feats, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_20add_num_feats};
static PyObject *__pyx_pw_5pipes_4Pipe_21add_num_feats(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_input_feature = 0;
  PyObject *__pyx_v_num_feats = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("add_num_feats (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_input_feature,&__pyx_n_s_num_feats,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_input_feature)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("add_num_feats", 1, 3, 3, 1); __PYX_ERR(0, 154, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_num_feats)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("add_num_feats", 1, 3, 3, 2); __PYX_ERR(0, 154, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "add_num_feats") < 0)) __PYX_ERR(0, 154, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_input_feature = values[1];
    __pyx_v_num_feats = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("add_num_feats", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 154, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.add_num_feats", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_4Pipe_20add_num_feats(__pyx_self, __pyx_v_self, __pyx_v_input_feature, __pyx_v_num_feats);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_20add_num_feats(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_input_feature, PyObject *__pyx_v_num_feats) {
  PyObject *__pyx_v_num_feats_pipe = NULL;
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
  __Pyx_RefNannySetupContext("add_num_feats", 0);

  /* "pipes.py":156
 *     def add_num_feats(self, input_feature, num_feats):
 *         """ Given a list of numeric features, builds a pipe to generate them. """
 *         num_feats_pipe = self.build_feature_pipe(input_feature, num_feats)             # <<<<<<<<<<<<<<
 *
 *         return num_feats_pipe
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_build_feature_pipe); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 156, __pyx_L1_error)
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
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_input_feature, __pyx_v_num_feats};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
    PyObject *__pyx_temp[3] = {__pyx_t_3, __pyx_v_input_feature, __pyx_v_num_feats};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_3) {
      __Pyx_GIVEREF(__pyx_t_3); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3); __pyx_t_3 = NULL;
    }
    __Pyx_INCREF(__pyx_v_input_feature);
    __Pyx_GIVEREF(__pyx_v_input_feature);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_v_input_feature);
    __Pyx_INCREF(__pyx_v_num_feats);
    __Pyx_GIVEREF(__pyx_v_num_feats);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_v_num_feats);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_num_feats_pipe = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "pipes.py":158
 *         num_feats_pipe = self.build_feature_pipe(input_feature, num_feats)
 *
 *         return num_feats_pipe             # <<<<<<<<<<<<<<
 *
 *     def add_norm_feats(self, num_feats):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_num_feats_pipe);
  __pyx_r = __pyx_v_num_feats_pipe;
  goto __pyx_L0;

  /* "pipes.py":154
 *         return pipeline
 *
 *     def add_num_feats(self, input_feature, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to generate them. """
 *         num_feats_pipe = self.build_feature_pipe(input_feature, num_feats)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("pipes.Pipe.add_num_feats", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_num_feats_pipe);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":160
 *         return num_feats_pipe
 *
 *     def add_norm_feats(self, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to normalize them. """
 *         norm_feats = [ '{}_norm'.format(f) for f in num_feats ]
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_23add_norm_feats(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_22add_norm_feats[] = " Given a list of numeric features, builds a pipe to normalize them. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_23add_norm_feats = {"add_norm_feats", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_23add_norm_feats, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_22add_norm_feats};
static PyObject *__pyx_pw_5pipes_4Pipe_23add_norm_feats(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_num_feats = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("add_norm_feats (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_num_feats,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_num_feats)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("add_norm_feats", 1, 2, 2, 1); __PYX_ERR(0, 160, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "add_norm_feats") < 0)) __PYX_ERR(0, 160, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_num_feats = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("add_norm_feats", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 160, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.add_norm_feats", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_4Pipe_22add_norm_feats(__pyx_self, __pyx_v_self, __pyx_v_num_feats);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_22add_norm_feats(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_num_feats) {
  PyObject *__pyx_v_norm_feats = NULL;
  PyObject *__pyx_8genexpr2__pyx_v_f = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *(*__pyx_t_4)(PyObject *);
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("add_norm_feats", 0);

  /* "pipes.py":162
 *     def add_norm_feats(self, num_feats):
 *         """ Given a list of numeric features, builds a pipe to normalize them. """
 *         norm_feats = [ '{}_norm'.format(f) for f in num_feats ]             # <<<<<<<<<<<<<<
 *
 *         return self.build_scalar_pipe(norm_feats)
 */
  { /* enter inner scope */
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 162, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (likely(PyList_CheckExact(__pyx_v_num_feats)) || PyTuple_CheckExact(__pyx_v_num_feats)) {
      __pyx_t_2 = __pyx_v_num_feats; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
      __pyx_t_4 = NULL;
    } else {
      __pyx_t_3 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_v_num_feats); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 162, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_4 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 162, __pyx_L5_error)
    }
    for (;;) {
      if (likely(!__pyx_t_4)) {
        if (likely(PyList_CheckExact(__pyx_t_2))) {
          if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_5 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_5); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 162, __pyx_L5_error)
          #else
          __pyx_t_5 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 162, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_5);
          #endif
        } else {
          if (__pyx_t_3 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_5 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_5); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 162, __pyx_L5_error)
          #else
          __pyx_t_5 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 162, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_5);
          #endif
        }
      } else {
        __pyx_t_5 = __pyx_t_4(__pyx_t_2);
        if (unlikely(!__pyx_t_5)) {
          PyObject* exc_type = PyErr_Occurred();
          if (exc_type) {
            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
            else __PYX_ERR(0, 162, __pyx_L5_error)
          }
          break;
        }
        __Pyx_GOTREF(__pyx_t_5);
      }
      __Pyx_XDECREF_SET(__pyx_8genexpr2__pyx_v_f, __pyx_t_5);
      __pyx_t_5 = 0;
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_kp_u_norm, __pyx_n_s_format); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 162, __pyx_L5_error)
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
      __pyx_t_5 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_7, __pyx_8genexpr2__pyx_v_f) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_8genexpr2__pyx_v_f);
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 162, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_t_5))) __PYX_ERR(0, 162, __pyx_L5_error)
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_f); __pyx_8genexpr2__pyx_v_f = 0;
    goto __pyx_L8_exit_scope;
    __pyx_L5_error:;
    __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_f); __pyx_8genexpr2__pyx_v_f = 0;
    goto __pyx_L1_error;
    __pyx_L8_exit_scope:;
  } /* exit inner scope */
  __pyx_v_norm_feats = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":164
 *         norm_feats = [ '{}_norm'.format(f) for f in num_feats ]
 *
 *         return self.build_scalar_pipe(norm_feats)             # <<<<<<<<<<<<<<
 *
 *     def build_scalar_pipe(self, pipe_names):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_build_scalar_pipe); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_v_norm_feats) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_norm_feats);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "pipes.py":160
 *         return num_feats_pipe
 *
 *     def add_norm_feats(self, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to normalize them. """
 *         norm_feats = [ '{}_norm'.format(f) for f in num_feats ]
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("pipes.Pipe.add_norm_feats", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_norm_feats);
  __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_f);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":166
 *         return self.build_scalar_pipe(norm_feats)
 *
 *     def build_scalar_pipe(self, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained scalar pipeline when given a list of pipes. """
 *         pipeline = self.chain_FU_pipes(pipe_names)
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_25build_scalar_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_24build_scalar_pipe[] = " Returns a chained scalar pipeline when given a list of pipes. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_25build_scalar_pipe = {"build_scalar_pipe", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_25build_scalar_pipe, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_24build_scalar_pipe};
static PyObject *__pyx_pw_5pipes_4Pipe_25build_scalar_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipe_names = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("build_scalar_pipe (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipe_names,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipe_names)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("build_scalar_pipe", 1, 2, 2, 1); __PYX_ERR(0, 166, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "build_scalar_pipe") < 0)) __PYX_ERR(0, 166, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipe_names = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("build_scalar_pipe", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 166, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.build_scalar_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5pipes_4Pipe_24build_scalar_pipe(__pyx_self, __pyx_v_self, __pyx_v_pipe_names);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_24build_scalar_pipe(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_pipe_names) {
  PyObject *__pyx_v_pipeline = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("build_scalar_pipe", 0);

  /* "pipes.py":168
 *     def build_scalar_pipe(self, pipe_names):
 *         """ Returns a chained scalar pipeline when given a list of pipes. """
 *         pipeline = self.chain_FU_pipes(pipe_names)             # <<<<<<<<<<<<<<
 *
 *         return pipeline
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_chain_FU_pipes); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 168, __pyx_L1_error)
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
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_pipe_names) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_pipe_names);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 168, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_pipeline = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "pipes.py":170
 *         pipeline = self.chain_FU_pipes(pipe_names)
 *
 *         return pipeline             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_pipeline);
  __pyx_r = __pyx_v_pipeline;
  goto __pyx_L0;

  /* "pipes.py":166
 *         return self.build_scalar_pipe(norm_feats)
 *
 *     def build_scalar_pipe(self, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained scalar pipeline when given a list of pipes. """
 *         pipeline = self.chain_FU_pipes(pipe_names)
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("pipes.Pipe.build_scalar_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_pipeline);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":174
 *
 *     # Can be killed.
 *     def make_FU_pipe_(self, pipes: dict):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipes. """
 *         named_pipes = [ (p, i) for p, i in pipes.items() ]
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_27make_FU_pipe_(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_26make_FU_pipe_[] = " Returns a FeatureUnion from a list of pipes. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_27make_FU_pipe_ = {"make_FU_pipe_", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_27make_FU_pipe_, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_26make_FU_pipe_};
static PyObject *__pyx_pw_5pipes_4Pipe_27make_FU_pipe_(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipes = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("make_FU_pipe_ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipes,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipes)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("make_FU_pipe_", 1, 2, 2, 1); __PYX_ERR(0, 174, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "make_FU_pipe_") < 0)) __PYX_ERR(0, 174, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipes = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("make_FU_pipe_", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 174, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.make_FU_pipe_", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_pipes), (&PyDict_Type), 1, "pipes", 1))) __PYX_ERR(0, 174, __pyx_L1_error)
  __pyx_r = __pyx_pf_5pipes_4Pipe_26make_FU_pipe_(__pyx_self, __pyx_v_self, __pyx_v_pipes);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_26make_FU_pipe_(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipes) {
  PyObject *__pyx_v_named_pipes = NULL;
  PyObject *__pyx_8genexpr3__pyx_v_p = NULL;
  PyObject *__pyx_8genexpr3__pyx_v_i = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  Py_ssize_t __pyx_t_4;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("make_FU_pipe_", 0);

  /* "pipes.py":176
 *     def make_FU_pipe_(self, pipes: dict):
 *         """ Returns a FeatureUnion from a list of pipes. """
 *         named_pipes = [ (p, i) for p, i in pipes.items() ]             # <<<<<<<<<<<<<<
 *
 *         return Pipeline([('FU', FeatureUnion(named_pipes))])
 */
  { /* enter inner scope */
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 176, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = 0;
    if (unlikely(__pyx_v_pipes == Py_None)) {
      PyErr_Format(PyExc_AttributeError, "'NoneType' object has no attribute '%.30s'", "items");
      __PYX_ERR(0, 176, __pyx_L5_error)
    }
    __pyx_t_6 = __Pyx_dict_iterator(__pyx_v_pipes, 1, __pyx_n_s_items, (&__pyx_t_4), (&__pyx_t_5)); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 176, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_XDECREF(__pyx_t_2);
    __pyx_t_2 = __pyx_t_6;
    __pyx_t_6 = 0;
    while (1) {
      __pyx_t_8 = __Pyx_dict_iter_next(__pyx_t_2, __pyx_t_4, &__pyx_t_3, &__pyx_t_6, &__pyx_t_7, NULL, __pyx_t_5);
      if (unlikely(__pyx_t_8 == 0)) break;
      if (unlikely(__pyx_t_8 == -1)) __PYX_ERR(0, 176, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_XDECREF_SET(__pyx_8genexpr3__pyx_v_p, __pyx_t_6);
      __pyx_t_6 = 0;
      __Pyx_XDECREF_SET(__pyx_8genexpr3__pyx_v_i, __pyx_t_7);
      __pyx_t_7 = 0;
      __pyx_t_7 = PyTuple_New(2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 176, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_INCREF(__pyx_8genexpr3__pyx_v_p);
      __Pyx_GIVEREF(__pyx_8genexpr3__pyx_v_p);
      PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_8genexpr3__pyx_v_p);
      __Pyx_INCREF(__pyx_8genexpr3__pyx_v_i);
      __Pyx_GIVEREF(__pyx_8genexpr3__pyx_v_i);
      PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_8genexpr3__pyx_v_i);
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_t_7))) __PYX_ERR(0, 176, __pyx_L5_error)
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_i); __pyx_8genexpr3__pyx_v_i = 0;
    __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_p); __pyx_8genexpr3__pyx_v_p = 0;
    goto __pyx_L8_exit_scope;
    __pyx_L5_error:;
    __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_i); __pyx_8genexpr3__pyx_v_i = 0;
    __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_p); __pyx_8genexpr3__pyx_v_p = 0;
    goto __pyx_L1_error;
    __pyx_L8_exit_scope:;
  } /* exit inner scope */
  __pyx_v_named_pipes = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":178
 *         named_pipes = [ (p, i) for p, i in pipes.items() ]
 *
 *         return Pipeline([('FU', FeatureUnion(named_pipes))])             # <<<<<<<<<<<<<<
 *
 *     def make_FU_pipe(self, pipenames: list):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_9 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_7 = (__pyx_t_9) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_9, __pyx_v_named_pipes) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_v_named_pipes);
  __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_INCREF(__pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_n_u_FU);
  PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_7);
  __pyx_t_7 = 0;
  __pyx_t_7 = PyList_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_6);
  PyList_SET_ITEM(__pyx_t_7, 0, __pyx_t_6);
  __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_6, __pyx_t_7) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_7);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 178, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "pipes.py":174
 *
 *     # Can be killed.
 *     def make_FU_pipe_(self, pipes: dict):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipes. """
 *         named_pipes = [ (p, i) for p, i in pipes.items() ]
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("pipes.Pipe.make_FU_pipe_", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_named_pipes);
  __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_p);
  __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_i);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "pipes.py":180
 *         return Pipeline([('FU', FeatureUnion(named_pipes))])
 *
 *     def make_FU_pipe(self, pipenames: list):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipenames. """
 *         named_pipes = [ (p, eval(p)) for p in pipenames ]
 */

/* Python wrapper */
static PyObject *__pyx_pw_5pipes_4Pipe_29make_FU_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static char __pyx_doc_5pipes_4Pipe_28make_FU_pipe[] = " Returns a FeatureUnion from a list of pipenames. ";
static PyMethodDef __pyx_mdef_5pipes_4Pipe_29make_FU_pipe = {"make_FU_pipe", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5pipes_4Pipe_29make_FU_pipe, METH_VARARGS|METH_KEYWORDS, __pyx_doc_5pipes_4Pipe_28make_FU_pipe};
static PyObject *__pyx_pw_5pipes_4Pipe_29make_FU_pipe(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_pipenames = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("make_FU_pipe (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_pipenames,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_pipenames)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("make_FU_pipe", 1, 2, 2, 1); __PYX_ERR(0, 180, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "make_FU_pipe") < 0)) __PYX_ERR(0, 180, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_pipenames = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("make_FU_pipe", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 180, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("pipes.Pipe.make_FU_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_pipenames), (&PyList_Type), 1, "pipenames", 1))) __PYX_ERR(0, 180, __pyx_L1_error)
  __pyx_r = __pyx_pf_5pipes_4Pipe_28make_FU_pipe(__pyx_self, __pyx_v_self, __pyx_v_pipenames);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5pipes_4Pipe_28make_FU_pipe(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_pipenames) {
  CYTHON_UNUSED PyObject *__pyx_v_named_pipes = NULL;
  CYTHON_UNUSED PyObject *__pyx_v_FU_pipe = NULL;
  PyObject *__pyx_8genexpr4__pyx_v_p = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("make_FU_pipe", 0);

  /* "pipes.py":182
 *     def make_FU_pipe(self, pipenames: list):
 *         """ Returns a FeatureUnion from a list of pipenames. """
 *         named_pipes = [ (p, eval(p)) for p in pipenames ]             # <<<<<<<<<<<<<<
 *
 *         FU_pipe = Pipeline([
 */
  { /* enter inner scope */
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 182, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_1);
    if (unlikely(__pyx_v_pipenames == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
      __PYX_ERR(0, 182, __pyx_L5_error)
    }
    __pyx_t_2 = __pyx_v_pipenames; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
    for (;;) {
      if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
      __pyx_t_4 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_4); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 182, __pyx_L5_error)
      #else
      __pyx_t_4 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 182, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_4);
      #endif
      __Pyx_XDECREF_SET(__pyx_8genexpr4__pyx_v_p, __pyx_t_4);
      __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_Globals(); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 182, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 182, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (__pyx_8genexpr4__pyx_v_p) {
        if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_p, __pyx_8genexpr4__pyx_v_p) < 0) __PYX_ERR(0, 182, __pyx_L5_error)
      }
      __pyx_t_6 = PyTuple_New(3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 182, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_8genexpr4__pyx_v_p);
      __Pyx_GIVEREF(__pyx_8genexpr4__pyx_v_p);
      PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_8genexpr4__pyx_v_p);
      __Pyx_GIVEREF(__pyx_t_4);
      PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_4);
      __Pyx_GIVEREF(__pyx_t_5);
      PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_t_5);
      __pyx_t_4 = 0;
      __pyx_t_5 = 0;
      __pyx_t_5 = __Pyx_PyObject_Call(__pyx_builtin_eval, __pyx_t_6, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 182, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 182, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_8genexpr4__pyx_v_p);
      __Pyx_GIVEREF(__pyx_8genexpr4__pyx_v_p);
      PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_8genexpr4__pyx_v_p);
      __Pyx_GIVEREF(__pyx_t_5);
      PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_5);
      __pyx_t_5 = 0;
      if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_t_6))) __PYX_ERR(0, 182, __pyx_L5_error)
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_8genexpr4__pyx_v_p); __pyx_8genexpr4__pyx_v_p = 0;
    goto __pyx_L8_exit_scope;
    __pyx_L5_error:;
    __Pyx_XDECREF(__pyx_8genexpr4__pyx_v_p); __pyx_8genexpr4__pyx_v_p = 0;
    goto __pyx_L1_error;
    __pyx_L8_exit_scope:;
  } /* exit inner scope */
  __pyx_v_named_pipes = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":184
 *         named_pipes = [ (p, eval(p)) for p in pipenames ]
 *
 *         FU_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *             ('FU', FeatureUnion([
 *                 ('normies', norm_feats_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "pipes.py":185
 *
 *         FU_pipe = Pipeline([
 *             ('FU', FeatureUnion([             # <<<<<<<<<<<<<<
 *                 ('normies', norm_feats_pipe),
 *                 #('cvector', vector_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "pipes.py":186
 *         FU_pipe = Pipeline([
 *             ('FU', FeatureUnion([
 *                 ('normies', norm_feats_pipe),             # <<<<<<<<<<<<<<
 *                 #('cvector', vector_pipe),
 *                 ('tvector', tfidf_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_norm_feats_pipe); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 186, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = PyTuple_New(2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 186, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_INCREF(__pyx_n_u_normies);
  __Pyx_GIVEREF(__pyx_n_u_normies);
  PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_n_u_normies);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_4);
  __pyx_t_4 = 0;

  /* "pipes.py":188
 *                 ('normies', norm_feats_pipe),
 *                 #('cvector', vector_pipe),
 *                 ('tvector', tfidf_pipe),             # <<<<<<<<<<<<<<
 *                 ]))
 *             ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_tfidf_pipe); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_8 = PyTuple_New(2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_INCREF(__pyx_n_u_tvector);
  __Pyx_GIVEREF(__pyx_n_u_tvector);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_n_u_tvector);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_4);
  __pyx_t_4 = 0;

  /* "pipes.py":185
 *
 *         FU_pipe = Pipeline([
 *             ('FU', FeatureUnion([             # <<<<<<<<<<<<<<
 *                 ('normies', norm_feats_pipe),
 *                 #('cvector', vector_pipe),
 */
  __pyx_t_4 = PyList_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_7);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_8);
  PyList_SET_ITEM(__pyx_t_4, 1, __pyx_t_8);
  __pyx_t_7 = 0;
  __pyx_t_8 = 0;
  __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_6 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_8, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_4);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 185, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_n_u_FU);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_t_6);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_6);
  __pyx_t_6 = 0;

  /* "pipes.py":184
 *         named_pipes = [ (p, eval(p)) for p in pipenames ]
 *
 *         FU_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *             ('FU', FeatureUnion([
 *                 ('normies', norm_feats_pipe),
 */
  __pyx_t_6 = PyList_New(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_6, 0, __pyx_t_5);
  __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_5, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_6);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_FU_pipe = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "pipes.py":180
 *         return Pipeline([('FU', FeatureUnion(named_pipes))])
 *
 *     def make_FU_pipe(self, pipenames: list):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipenames. """
 *         named_pipes = [ (p, eval(p)) for p in pipenames ]
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("pipes.Pipe.make_FU_pipe", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_named_pipes);
  __Pyx_XDECREF(__pyx_v_FU_pipe);
  __Pyx_XDECREF(__pyx_8genexpr4__pyx_v_p);
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
static int __pyx_pymod_exec_pipes(PyObject* module); /*proto*/
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_pipes},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "pipes",
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
  {&__pyx_n_s_, __pyx_k_, sizeof(__pyx_k_), 0, 0, 1, 1},
  {&__pyx_n_s_AvgWordLenTransformer, __pyx_k_AvgWordLenTransformer, sizeof(__pyx_k_AvgWordLenTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_BooleanTargets, __pyx_k_BooleanTargets, sizeof(__pyx_k_BooleanTargets), 0, 0, 1, 1},
  {&__pyx_kp_s_Class_with_all_methods_needed_t, __pyx_k_Class_with_all_methods_needed_t, sizeof(__pyx_k_Class_with_all_methods_needed_t), 0, 0, 1, 0},
  {&__pyx_n_s_ClassifierPipes, __pyx_k_ClassifierPipes, sizeof(__pyx_k_ClassifierPipes), 0, 0, 1, 1},
  {&__pyx_n_s_ClassifierPipes___init, __pyx_k_ClassifierPipes___init, sizeof(__pyx_k_ClassifierPipes___init), 0, 0, 1, 1},
  {&__pyx_n_s_ClassifierPipes_clf, __pyx_k_ClassifierPipes_clf, sizeof(__pyx_k_ClassifierPipes_clf), 0, 0, 1, 1},
  {&__pyx_n_s_Classifiers, __pyx_k_Classifiers, sizeof(__pyx_k_Classifiers), 0, 0, 1, 1},
  {&__pyx_n_s_CommaLenRatio, __pyx_k_CommaLenRatio, sizeof(__pyx_k_CommaLenRatio), 0, 0, 1, 1},
  {&__pyx_n_s_ConvertTargets, __pyx_k_ConvertTargets, sizeof(__pyx_k_ConvertTargets), 0, 0, 1, 1},
  {&__pyx_n_s_CountCommas, __pyx_k_CountCommas, sizeof(__pyx_k_CountCommas), 0, 0, 1, 1},
  {&__pyx_n_s_CountVectorizer, __pyx_k_CountVectorizer, sizeof(__pyx_k_CountVectorizer), 0, 0, 1, 1},
  {&__pyx_n_s_CountWords, __pyx_k_CountWords, sizeof(__pyx_k_CountWords), 0, 0, 1, 1},
  {&__pyx_n_s_DropFeatures, __pyx_k_DropFeatures, sizeof(__pyx_k_DropFeatures), 0, 0, 1, 1},
  {&__pyx_n_u_FU, __pyx_k_FU, sizeof(__pyx_k_FU), 0, 1, 0, 1},
  {&__pyx_n_s_FU_pipe, __pyx_k_FU_pipe, sizeof(__pyx_k_FU_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_FeatureSelector, __pyx_k_FeatureSelector, sizeof(__pyx_k_FeatureSelector), 0, 0, 1, 1},
  {&__pyx_n_s_FeatureUnion, __pyx_k_FeatureUnion, sizeof(__pyx_k_FeatureUnion), 0, 0, 1, 1},
  {&__pyx_n_s_MAX_DF, __pyx_k_MAX_DF, sizeof(__pyx_k_MAX_DF), 0, 0, 1, 1},
  {&__pyx_n_s_MAX_FEATURES, __pyx_k_MAX_FEATURES, sizeof(__pyx_k_MAX_FEATURES), 0, 0, 1, 1},
  {&__pyx_n_s_MIN_DF, __pyx_k_MIN_DF, sizeof(__pyx_k_MIN_DF), 0, 0, 1, 1},
  {&__pyx_n_s_MissingData, __pyx_k_MissingData, sizeof(__pyx_k_MissingData), 0, 0, 1, 1},
  {&__pyx_n_s_NotStopsTransformer, __pyx_k_NotStopsTransformer, sizeof(__pyx_k_NotStopsTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_NumberSelector, __pyx_k_NumberSelector, sizeof(__pyx_k_NumberSelector), 0, 0, 1, 1},
  {&__pyx_n_s_PCA, __pyx_k_PCA, sizeof(__pyx_k_PCA), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe, __pyx_k_Pipe, sizeof(__pyx_k_Pipe), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe___init, __pyx_k_Pipe___init, sizeof(__pyx_k_Pipe___init), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_add_norm_feats, __pyx_k_Pipe_add_norm_feats, sizeof(__pyx_k_Pipe_add_norm_feats), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_add_num_feats, __pyx_k_Pipe_add_num_feats, sizeof(__pyx_k_Pipe_add_num_feats), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_build_feature_pipe, __pyx_k_Pipe_build_feature_pipe, sizeof(__pyx_k_Pipe_build_feature_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_build_scalar_pipe, __pyx_k_Pipe_build_scalar_pipe, sizeof(__pyx_k_Pipe_build_scalar_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_chain_fu_pipes, __pyx_k_Pipe_chain_fu_pipes, sizeof(__pyx_k_Pipe_chain_fu_pipes), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_chain_pipes, __pyx_k_Pipe_chain_pipes, sizeof(__pyx_k_Pipe_chain_pipes), 0, 0, 1, 1},
  {&__pyx_kp_s_Pipe_factory_for_single_step_cl, __pyx_k_Pipe_factory_for_single_step_cl, sizeof(__pyx_k_Pipe_factory_for_single_step_cl), 0, 0, 1, 0},
  {&__pyx_n_s_Pipe_hash_pipe, __pyx_k_Pipe_hash_pipe, sizeof(__pyx_k_Pipe_hash_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_load_pipe, __pyx_k_Pipe_load_pipe, sizeof(__pyx_k_Pipe_load_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_make_FU_pipe, __pyx_k_Pipe_make_FU_pipe, sizeof(__pyx_k_Pipe_make_FU_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_make_FU_pipe_2, __pyx_k_Pipe_make_FU_pipe_2, sizeof(__pyx_k_Pipe_make_FU_pipe_2), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_make_normie, __pyx_k_Pipe_make_normie, sizeof(__pyx_k_Pipe_make_normie), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_make_pipe, __pyx_k_Pipe_make_pipe, sizeof(__pyx_k_Pipe_make_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_set_fu_feat, __pyx_k_Pipe_set_fu_feat, sizeof(__pyx_k_Pipe_set_fu_feat), 0, 0, 1, 1},
  {&__pyx_n_s_Pipe_set_input_feat, __pyx_k_Pipe_set_input_feat, sizeof(__pyx_k_Pipe_set_input_feat), 0, 0, 1, 1},
  {&__pyx_n_s_Pipeline, __pyx_k_Pipeline, sizeof(__pyx_k_Pipeline), 0, 0, 1, 1},
  {&__pyx_n_s_SEED, __pyx_k_SEED, sizeof(__pyx_k_SEED), 0, 0, 1, 1},
  {&__pyx_n_s_STOPS, __pyx_k_STOPS, sizeof(__pyx_k_STOPS), 0, 0, 1, 1},
  {&__pyx_n_s_SentenceLength, __pyx_k_SentenceLength, sizeof(__pyx_k_SentenceLength), 0, 0, 1, 1},
  {&__pyx_n_s_StandardScaler, __pyx_k_StandardScaler, sizeof(__pyx_k_StandardScaler), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelector, __pyx_k_TextSelector, sizeof(__pyx_k_TextSelector), 0, 0, 1, 1},
  {&__pyx_n_s_TfidfTransformer, __pyx_k_TfidfTransformer, sizeof(__pyx_k_TfidfTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_TfidfVectorizer, __pyx_k_TfidfVectorizer, sizeof(__pyx_k_TfidfVectorizer), 0, 0, 1, 1},
  {&__pyx_n_s_Trans, __pyx_k_Trans, sizeof(__pyx_k_Trans), 0, 0, 1, 1},
  {&__pyx_n_s_add_norm_feats, __pyx_k_add_norm_feats, sizeof(__pyx_k_add_norm_feats), 0, 0, 1, 1},
  {&__pyx_n_s_add_num_feats, __pyx_k_add_num_feats, sizeof(__pyx_k_add_num_feats), 0, 0, 1, 1},
  {&__pyx_n_u_avg_word_len, __pyx_k_avg_word_len, sizeof(__pyx_k_avg_word_len), 0, 1, 0, 1},
  {&__pyx_n_s_avg_word_len_norm_pipe, __pyx_k_avg_word_len_norm_pipe, sizeof(__pyx_k_avg_word_len_norm_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_avg_word_len_pipe, __pyx_k_avg_word_len_pipe, sizeof(__pyx_k_avg_word_len_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_awl, __pyx_k_awl, sizeof(__pyx_k_awl), 0, 1, 0, 1},
  {&__pyx_n_s_boolean_targets_pipe, __pyx_k_boolean_targets_pipe, sizeof(__pyx_k_boolean_targets_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_bt, __pyx_k_bt, sizeof(__pyx_k_bt), 0, 1, 0, 1},
  {&__pyx_n_s_build_feature_pipe, __pyx_k_build_feature_pipe, sizeof(__pyx_k_build_feature_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_build_scalar_pipe, __pyx_k_build_scalar_pipe, sizeof(__pyx_k_build_scalar_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_build_src_models, __pyx_k_build_src_models, sizeof(__pyx_k_build_src_models), 0, 0, 1, 1},
  {&__pyx_n_s_build_src_trans, __pyx_k_build_src_trans, sizeof(__pyx_k_build_src_trans), 0, 0, 1, 1},
  {&__pyx_n_u_cc, __pyx_k_cc, sizeof(__pyx_k_cc), 0, 1, 0, 1},
  {&__pyx_n_s_chain_FU_pipes, __pyx_k_chain_FU_pipes, sizeof(__pyx_k_chain_FU_pipes), 0, 0, 1, 1},
  {&__pyx_n_s_chain_fu_pipes, __pyx_k_chain_fu_pipes, sizeof(__pyx_k_chain_fu_pipes), 0, 0, 1, 1},
  {&__pyx_n_s_chain_pipes, __pyx_k_chain_pipes, sizeof(__pyx_k_chain_pipes), 0, 0, 1, 1},
  {&__pyx_n_s_classifier, __pyx_k_classifier, sizeof(__pyx_k_classifier), 0, 0, 1, 1},
  {&__pyx_n_s_clf, __pyx_k_clf, sizeof(__pyx_k_clf), 0, 0, 1, 1},
  {&__pyx_n_s_clf_pipe, __pyx_k_clf_pipe, sizeof(__pyx_k_clf_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_cls, __pyx_k_cls, sizeof(__pyx_k_cls), 0, 0, 1, 1},
  {&__pyx_n_s_col, __pyx_k_col, sizeof(__pyx_k_col), 0, 0, 1, 1},
  {&__pyx_n_u_col, __pyx_k_col, sizeof(__pyx_k_col), 0, 1, 0, 1},
  {&__pyx_n_s_col_nom, __pyx_k_col_nom, sizeof(__pyx_k_col_nom), 0, 0, 1, 1},
  {&__pyx_n_s_combine_feats_pipe, __pyx_k_combine_feats_pipe, sizeof(__pyx_k_combine_feats_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_comma_len_ratio, __pyx_k_comma_len_ratio, sizeof(__pyx_k_comma_len_ratio), 0, 1, 0, 1},
  {&__pyx_n_s_comma_len_ratio_norm_pipe, __pyx_k_comma_len_ratio_norm_pipe, sizeof(__pyx_k_comma_len_ratio_norm_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_comma_len_ratio_pipe, __pyx_k_comma_len_ratio_pipe, sizeof(__pyx_k_comma_len_ratio_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_commalenratio, __pyx_k_commalenratio, sizeof(__pyx_k_commalenratio), 0, 1, 0, 1},
  {&__pyx_n_u_commas, __pyx_k_commas, sizeof(__pyx_k_commas), 0, 1, 0, 1},
  {&__pyx_n_s_common, __pyx_k_common, sizeof(__pyx_k_common), 0, 0, 1, 1},
  {&__pyx_n_u_convert, __pyx_k_convert, sizeof(__pyx_k_convert), 0, 1, 0, 1},
  {&__pyx_n_u_count_commas, __pyx_k_count_commas, sizeof(__pyx_k_count_commas), 0, 1, 0, 1},
  {&__pyx_n_s_count_commas_norm_pipe, __pyx_k_count_commas_norm_pipe, sizeof(__pyx_k_count_commas_norm_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_count_commas_pipe, __pyx_k_count_commas_pipe, sizeof(__pyx_k_count_commas_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_count_words, __pyx_k_count_words, sizeof(__pyx_k_count_words), 0, 1, 0, 1},
  {&__pyx_n_s_count_words_norm_pipe, __pyx_k_count_words_norm_pipe, sizeof(__pyx_k_count_words_norm_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_count_words_pipe, __pyx_k_count_words_pipe, sizeof(__pyx_k_count_words_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_cpu_count, __pyx_k_cpu_count, sizeof(__pyx_k_cpu_count), 0, 0, 1, 1},
  {&__pyx_n_u_cv, __pyx_k_cv, sizeof(__pyx_k_cv), 0, 1, 0, 1},
  {&__pyx_n_u_cw, __pyx_k_cw, sizeof(__pyx_k_cw), 0, 1, 0, 1},
  {&__pyx_n_s_dict, __pyx_k_dict, sizeof(__pyx_k_dict), 0, 0, 1, 1},
  {&__pyx_n_u_dict_2, __pyx_k_dict_2, sizeof(__pyx_k_dict_2), 0, 1, 0, 1},
  {&__pyx_n_s_doc, __pyx_k_doc, sizeof(__pyx_k_doc), 0, 0, 1, 1},
  {&__pyx_n_u_drop_feats, __pyx_k_drop_feats, sizeof(__pyx_k_drop_feats), 0, 1, 0, 1},
  {&__pyx_n_s_drop_features_pipe, __pyx_k_drop_features_pipe, sizeof(__pyx_k_drop_features_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_e, __pyx_k_e, sizeof(__pyx_k_e), 0, 0, 1, 1},
  {&__pyx_n_u_english, __pyx_k_english, sizeof(__pyx_k_english), 0, 1, 0, 1},
  {&__pyx_n_s_enumerate, __pyx_k_enumerate, sizeof(__pyx_k_enumerate), 0, 0, 1, 1},
  {&__pyx_n_s_eval, __pyx_k_eval, sizeof(__pyx_k_eval), 0, 0, 1, 1},
  {&__pyx_n_s_f, __pyx_k_f, sizeof(__pyx_k_f), 0, 0, 1, 1},
  {&__pyx_n_s_feats, __pyx_k_feats, sizeof(__pyx_k_feats), 0, 0, 1, 1},
  {&__pyx_n_s_features_pipe, __pyx_k_features_pipe, sizeof(__pyx_k_features_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_format, __pyx_k_format, sizeof(__pyx_k_format), 0, 0, 1, 1},
  {&__pyx_n_s_fu, __pyx_k_fu, sizeof(__pyx_k_fu), 0, 0, 1, 1},
  {&__pyx_n_s_hash_pipe, __pyx_k_hash_pipe, sizeof(__pyx_k_hash_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_init, __pyx_k_init, sizeof(__pyx_k_init), 0, 0, 1, 1},
  {&__pyx_n_s_input_feat, __pyx_k_input_feat, sizeof(__pyx_k_input_feat), 0, 0, 1, 1},
  {&__pyx_n_u_input_feat, __pyx_k_input_feat, sizeof(__pyx_k_input_feat), 0, 1, 0, 1},
  {&__pyx_n_s_input_feature, __pyx_k_input_feature, sizeof(__pyx_k_input_feature), 0, 0, 1, 1},
  {&__pyx_n_s_items, __pyx_k_items, sizeof(__pyx_k_items), 0, 0, 1, 1},
  {&__pyx_n_s_len, __pyx_k_len, sizeof(__pyx_k_len), 0, 0, 1, 1},
  {&__pyx_n_u_list, __pyx_k_list, sizeof(__pyx_k_list), 0, 1, 0, 1},
  {&__pyx_n_s_load_pipe, __pyx_k_load_pipe, sizeof(__pyx_k_load_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_lp, __pyx_k_lp, sizeof(__pyx_k_lp), 0, 1, 0, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_s_make_FU_pipe, __pyx_k_make_FU_pipe, sizeof(__pyx_k_make_FU_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_make_FU_pipe_2, __pyx_k_make_FU_pipe_2, sizeof(__pyx_k_make_FU_pipe_2), 0, 0, 1, 1},
  {&__pyx_n_s_make_normie, __pyx_k_make_normie, sizeof(__pyx_k_make_normie), 0, 0, 1, 1},
  {&__pyx_n_s_make_pipe, __pyx_k_make_pipe, sizeof(__pyx_k_make_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_max_df, __pyx_k_max_df, sizeof(__pyx_k_max_df), 0, 0, 1, 1},
  {&__pyx_n_s_max_features, __pyx_k_max_features, sizeof(__pyx_k_max_features), 0, 0, 1, 1},
  {&__pyx_n_s_md5_hash, __pyx_k_md5_hash, sizeof(__pyx_k_md5_hash), 0, 0, 1, 1},
  {&__pyx_n_u_md5_hash, __pyx_k_md5_hash, sizeof(__pyx_k_md5_hash), 0, 1, 0, 1},
  {&__pyx_n_s_metaclass, __pyx_k_metaclass, sizeof(__pyx_k_metaclass), 0, 0, 1, 1},
  {&__pyx_n_s_min_df, __pyx_k_min_df, sizeof(__pyx_k_min_df), 0, 0, 1, 1},
  {&__pyx_n_u_missing, __pyx_k_missing, sizeof(__pyx_k_missing), 0, 1, 0, 1},
  {&__pyx_n_s_missing_data_pipe, __pyx_k_missing_data_pipe, sizeof(__pyx_k_missing_data_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_module, __pyx_k_module, sizeof(__pyx_k_module), 0, 0, 1, 1},
  {&__pyx_n_s_multiprocessing, __pyx_k_multiprocessing, sizeof(__pyx_k_multiprocessing), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_named_pipes, __pyx_k_named_pipes, sizeof(__pyx_k_named_pipes), 0, 0, 1, 1},
  {&__pyx_n_s_nltk_corpus, __pyx_k_nltk_corpus, sizeof(__pyx_k_nltk_corpus), 0, 0, 1, 1},
  {&__pyx_kp_u_norm, __pyx_k_norm, sizeof(__pyx_k_norm), 0, 1, 0, 0},
  {&__pyx_n_s_norm_feats, __pyx_k_norm_feats, sizeof(__pyx_k_norm_feats), 0, 0, 1, 1},
  {&__pyx_n_s_norm_feats_pipe, __pyx_k_norm_feats_pipe, sizeof(__pyx_k_norm_feats_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_norm_pipe, __pyx_k_norm_pipe, sizeof(__pyx_k_norm_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_normie_pipe, __pyx_k_normie_pipe, sizeof(__pyx_k_normie_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_normies, __pyx_k_normies, sizeof(__pyx_k_normies), 0, 1, 0, 1},
  {&__pyx_n_u_not_stops, __pyx_k_not_stops, sizeof(__pyx_k_not_stops), 0, 1, 0, 1},
  {&__pyx_n_s_not_stops_norm_pipe, __pyx_k_not_stops_norm_pipe, sizeof(__pyx_k_not_stops_norm_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_not_stops_pipe, __pyx_k_not_stops_pipe, sizeof(__pyx_k_not_stops_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_notstops, __pyx_k_notstops, sizeof(__pyx_k_notstops), 0, 1, 0, 1},
  {&__pyx_n_u_ns, __pyx_k_ns, sizeof(__pyx_k_ns), 0, 1, 0, 1},
  {&__pyx_n_s_num_feats, __pyx_k_num_feats, sizeof(__pyx_k_num_feats), 0, 0, 1, 1},
  {&__pyx_n_s_num_feats_pipe, __pyx_k_num_feats_pipe, sizeof(__pyx_k_num_feats_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_numeric_feats_pipe, __pyx_k_numeric_feats_pipe, sizeof(__pyx_k_numeric_feats_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_object, __pyx_k_object, sizeof(__pyx_k_object), 0, 0, 1, 1},
  {&__pyx_n_s_p, __pyx_k_p, sizeof(__pyx_k_p), 0, 0, 1, 1},
  {&__pyx_n_s_params, __pyx_k_params, sizeof(__pyx_k_params), 0, 0, 1, 1},
  {&__pyx_n_u_pipe, __pyx_k_pipe, sizeof(__pyx_k_pipe), 0, 1, 0, 1},
  {&__pyx_n_s_pipe_2, __pyx_k_pipe_2, sizeof(__pyx_k_pipe_2), 0, 0, 1, 1},
  {&__pyx_n_s_pipe_names, __pyx_k_pipe_names, sizeof(__pyx_k_pipe_names), 0, 0, 1, 1},
  {&__pyx_n_s_pipel, __pyx_k_pipel, sizeof(__pyx_k_pipel), 0, 0, 1, 1},
  {&__pyx_n_s_pipeline, __pyx_k_pipeline, sizeof(__pyx_k_pipeline), 0, 0, 1, 1},
  {&__pyx_n_s_pipename, __pyx_k_pipename, sizeof(__pyx_k_pipename), 0, 0, 1, 1},
  {&__pyx_n_s_pipenames, __pyx_k_pipenames, sizeof(__pyx_k_pipenames), 0, 0, 1, 1},
  {&__pyx_n_s_pipes, __pyx_k_pipes, sizeof(__pyx_k_pipes), 0, 0, 1, 1},
  {&__pyx_kp_s_pipes_py, __pyx_k_pipes_py, sizeof(__pyx_k_pipes_py), 0, 0, 1, 0},
  {&__pyx_n_s_prepare, __pyx_k_prepare, sizeof(__pyx_k_prepare), 0, 0, 1, 1},
  {&__pyx_n_s_qualname, __pyx_k_qualname, sizeof(__pyx_k_qualname), 0, 0, 1, 1},
  {&__pyx_n_u_raw, __pyx_k_raw, sizeof(__pyx_k_raw), 0, 1, 0, 1},
  {&__pyx_n_s_return, __pyx_k_return, sizeof(__pyx_k_return), 0, 0, 1, 1},
  {&__pyx_n_u_select_feats, __pyx_k_select_feats, sizeof(__pyx_k_select_feats), 0, 1, 0, 1},
  {&__pyx_n_u_selector, __pyx_k_selector, sizeof(__pyx_k_selector), 0, 1, 0, 1},
  {&__pyx_n_s_self, __pyx_k_self, sizeof(__pyx_k_self), 0, 0, 1, 1},
  {&__pyx_n_u_sen_len, __pyx_k_sen_len, sizeof(__pyx_k_sen_len), 0, 1, 0, 1},
  {&__pyx_n_s_sen_len_norm_pipe, __pyx_k_sen_len_norm_pipe, sizeof(__pyx_k_sen_len_norm_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_sen_len_pipe, __pyx_k_sen_len_pipe, sizeof(__pyx_k_sen_len_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_sentences, __pyx_k_sentences, sizeof(__pyx_k_sentences), 0, 1, 0, 1},
  {&__pyx_n_s_set_fu_feat, __pyx_k_set_fu_feat, sizeof(__pyx_k_set_fu_feat), 0, 0, 1, 1},
  {&__pyx_n_s_set_input_feat, __pyx_k_set_input_feat, sizeof(__pyx_k_set_input_feat), 0, 0, 1, 1},
  {&__pyx_n_s_set_params, __pyx_k_set_params, sizeof(__pyx_k_set_params), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_decomposition, __pyx_k_sklearn_decomposition, sizeof(__pyx_k_sklearn_decomposition), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_feature_extraction_text, __pyx_k_sklearn_feature_extraction_text, sizeof(__pyx_k_sklearn_feature_extraction_text), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_pipeline, __pyx_k_sklearn_pipeline, sizeof(__pyx_k_sklearn_pipeline), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_preprocessing, __pyx_k_sklearn_preprocessing, sizeof(__pyx_k_sklearn_preprocessing), 0, 0, 1, 1},
  {&__pyx_n_u_sl, __pyx_k_sl, sizeof(__pyx_k_sl), 0, 1, 0, 1},
  {&__pyx_n_u_standard, __pyx_k_standard, sizeof(__pyx_k_standard), 0, 1, 0, 1},
  {&__pyx_n_s_step, __pyx_k_step, sizeof(__pyx_k_step), 0, 0, 1, 1},
  {&__pyx_n_s_steps, __pyx_k_steps, sizeof(__pyx_k_steps), 0, 0, 1, 1},
  {&__pyx_n_u_steps, __pyx_k_steps, sizeof(__pyx_k_steps), 0, 1, 0, 1},
  {&__pyx_n_s_stopWords, __pyx_k_stopWords, sizeof(__pyx_k_stopWords), 0, 0, 1, 1},
  {&__pyx_n_s_stop_words, __pyx_k_stop_words, sizeof(__pyx_k_stop_words), 0, 0, 1, 1},
  {&__pyx_n_s_stopwords, __pyx_k_stopwords, sizeof(__pyx_k_stopwords), 0, 0, 1, 1},
  {&__pyx_n_u_tar, __pyx_k_tar, sizeof(__pyx_k_tar), 0, 1, 0, 1},
  {&__pyx_n_s_tar1, __pyx_k_tar1, sizeof(__pyx_k_tar1), 0, 0, 1, 1},
  {&__pyx_n_s_tar2, __pyx_k_tar2, sizeof(__pyx_k_tar2), 0, 0, 1, 1},
  {&__pyx_n_s_targets_str_to_int_pipe, __pyx_k_targets_str_to_int_pipe, sizeof(__pyx_k_targets_str_to_int_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_u_tfidf, __pyx_k_tfidf, sizeof(__pyx_k_tfidf), 0, 1, 0, 1},
  {&__pyx_n_s_tfidf_col_pipe, __pyx_k_tfidf_col_pipe, sizeof(__pyx_k_tfidf_col_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_tfidf_pipe, __pyx_k_tfidf_pipe, sizeof(__pyx_k_tfidf_pipe), 0, 0, 1, 1},
  {&__pyx_n_u_tvector, __pyx_k_tvector, sizeof(__pyx_k_tvector), 0, 1, 0, 1},
  {&__pyx_n_u_unicode, __pyx_k_unicode, sizeof(__pyx_k_unicode), 0, 1, 0, 1},
  {&__pyx_n_s_utils, __pyx_k_utils, sizeof(__pyx_k_utils), 0, 0, 1, 1},
  {&__pyx_n_s_v, __pyx_k_v, sizeof(__pyx_k_v), 0, 0, 1, 1},
  {&__pyx_n_u_vec, __pyx_k_vec, sizeof(__pyx_k_vec), 0, 1, 0, 1},
  {&__pyx_n_s_word_vector_pipe, __pyx_k_word_vector_pipe, sizeof(__pyx_k_word_vector_pipe), 0, 0, 1, 1},
  {&__pyx_n_s_words, __pyx_k_words, sizeof(__pyx_k_words), 0, 0, 1, 1},
  {&__pyx_n_u_words, __pyx_k_words, sizeof(__pyx_k_words), 0, 1, 0, 1},
  {&__pyx_n_s_x, __pyx_k_x, sizeof(__pyx_k_x), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_object = __Pyx_GetBuiltinName(__pyx_n_s_object); if (!__pyx_builtin_object) __PYX_ERR(0, 34, __pyx_L1_error)
  __pyx_builtin_eval = __Pyx_GetBuiltinName(__pyx_n_s_eval); if (!__pyx_builtin_eval) __PYX_ERR(0, 58, __pyx_L1_error)
  __pyx_builtin_enumerate = __Pyx_GetBuiltinName(__pyx_n_s_enumerate); if (!__pyx_builtin_enumerate) __PYX_ERR(0, 93, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  /* "pipes.py":26
 *
 * # @FIXME: This seems out of place in pipes module.
 * stopWords = set(stopwords.words('english'))             # <<<<<<<<<<<<<<
 * STOPS=stopwords.words('english')
 *
 */
  __pyx_tuple__2 = PyTuple_Pack(1, __pyx_n_u_english); if (unlikely(!__pyx_tuple__2)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__2);
  __Pyx_GIVEREF(__pyx_tuple__2);

  /* "pipes.py":34
 * cls= Classifiers()
 *
 * class ClassifierPipes(object):             # <<<<<<<<<<<<<<
 *     """ Pipe factory for single step classifier pipes. """
 *     def __init__(self):
 */
  __pyx_tuple__3 = PyTuple_Pack(1, __pyx_builtin_object); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);

  /* "pipes.py":36
 * class ClassifierPipes(object):
 *     """ Pipe factory for single step classifier pipes. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__4 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__4)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__4);
  __Pyx_GIVEREF(__pyx_tuple__4);
  __pyx_codeobj__5 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__4, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_init, 36, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__5)) __PYX_ERR(0, 36, __pyx_L1_error)

  /* "pipes.py":39
 *         pass
 *
 *     def clf(self, classifier):             # <<<<<<<<<<<<<<
 *         pipename = classifier + '_pipe'
 *         pipe = getattr(cls, classifier)
 */
  __pyx_tuple__6 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_classifier, __pyx_n_s_pipename, __pyx_n_s_pipe_2, __pyx_n_s_clf_pipe); if (unlikely(!__pyx_tuple__6)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__6);
  __Pyx_GIVEREF(__pyx_tuple__6);
  __pyx_codeobj__7 = (PyObject*)__Pyx_PyCode_New(2, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__6, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_clf, 39, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__7)) __PYX_ERR(0, 39, __pyx_L1_error)

  /* "pipes.py":51
 * ## Pipe builder methods
 *
 * class Pipe(object):             # <<<<<<<<<<<<<<
 *     """ Class with all methods needed to dynamically build pipes at runtime. """
 *     def __init__(self):
 */
  __pyx_tuple__8 = PyTuple_Pack(1, __pyx_builtin_object); if (unlikely(!__pyx_tuple__8)) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__8);
  __Pyx_GIVEREF(__pyx_tuple__8);

  /* "pipes.py":53
 * class Pipe(object):
 *     """ Class with all methods needed to dynamically build pipes at runtime. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__9 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__9)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__9);
  __Pyx_GIVEREF(__pyx_tuple__9);
  __pyx_codeobj__10 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__9, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_init, 53, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__10)) __PYX_ERR(0, 53, __pyx_L1_error)

  /* "pipes.py":56
 *         pass
 *
 *     def load_pipe(self, pipename: str):             # <<<<<<<<<<<<<<
 *         """ Returns a single (defined) pipe when asked for by name. """
 *         return eval(pipename)
 */
  __pyx_tuple__11 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_pipename); if (unlikely(!__pyx_tuple__11)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__11);
  __Pyx_GIVEREF(__pyx_tuple__11);
  __pyx_codeobj__12 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__11, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_load_pipe, 56, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__12)) __PYX_ERR(0, 56, __pyx_L1_error)

  /* "pipes.py":60
 *         return eval(pipename)
 *
 *     def make_pipe(self, pipename: str, params: dict):             # <<<<<<<<<<<<<<
 *         """ Creates a single step pipe with optional params. """
 *         step = (pipename, eval(pipename+'_pipe'))
 */
  __pyx_tuple__13 = PyTuple_Pack(7, __pyx_n_s_self, __pyx_n_s_pipename, __pyx_n_s_params, __pyx_n_s_step, __pyx_n_s_pipe_2, __pyx_n_s_p, __pyx_n_s_v); if (unlikely(!__pyx_tuple__13)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__13);
  __Pyx_GIVEREF(__pyx_tuple__13);
  __pyx_codeobj__14 = (PyObject*)__Pyx_PyCode_New(3, 0, 7, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__13, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_make_pipe, 60, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__14)) __PYX_ERR(0, 60, __pyx_L1_error)

  /* "pipes.py":70
 *         #return Pipeline(pipe)
 *
 *     def make_normie(self, col_nom: str):             # <<<<<<<<<<<<<<
 *         """ Sselector pipe to normalize a given numeric column.
 *         input: dataframe containing the target column.
 */
  __pyx_tuple__15 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_col_nom, __pyx_n_s_norm_pipe); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);
  __pyx_codeobj__16 = (PyObject*)__Pyx_PyCode_New(2, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__15, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_make_normie, 70, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__16)) __PYX_ERR(0, 70, __pyx_L1_error)

  /* "pipes.py":89
 *     #    return Pipeline(features)
 *
 *     def chain_pipes(self, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a mixed list of pipes and pipe names, returns a Pipeline of fully named pipes.
 *         :param pipes: a list which may contain both pipes and pipe names.
 */
  __pyx_tuple__17 = PyTuple_Pack(6, __pyx_n_s_self, __pyx_n_s_pipes, __pyx_n_s_e, __pyx_n_s_p, __pyx_n_s_steps, __pyx_n_s_p); if (unlikely(!__pyx_tuple__17)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__17);
  __Pyx_GIVEREF(__pyx_tuple__17);
  __pyx_codeobj__18 = (PyObject*)__Pyx_PyCode_New(2, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__17, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_chain_pipes, 89, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__18)) __PYX_ERR(0, 89, __pyx_L1_error)

  /* "pipes.py":102
 *         return Pipeline(steps)
 *
 *     def chain_fu_pipes(self, pipename: str, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a list of pipes, returns a FeatureUnion of named pipes.
 *         Sub-pipe names are automatically generated as a hash of their steps.
 */
  __pyx_tuple__19 = PyTuple_Pack(8, __pyx_n_s_self, __pyx_n_s_pipename, __pyx_n_s_pipes, __pyx_n_s_e, __pyx_n_s_p, __pyx_n_s_feats, __pyx_n_s_fu, __pyx_n_s_x); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);
  __pyx_codeobj__20 = (PyObject*)__Pyx_PyCode_New(3, 0, 8, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__19, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_chain_fu_pipes, 102, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__20)) __PYX_ERR(0, 102, __pyx_L1_error)

  /* "pipes.py":129
 *     """
 *
 *     def hash_pipe(self, pipe, len=8) ->'md5_hash':             # <<<<<<<<<<<<<<
 *         """ Generate a handle for a given pipe by taking the hash of its steps. """
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 */
  __pyx_tuple__21 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_pipe_2, __pyx_n_s_len); if (unlikely(!__pyx_tuple__21)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__21);
  __Pyx_GIVEREF(__pyx_tuple__21);
  __pyx_codeobj__22 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__21, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_hash_pipe, 129, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__22)) __PYX_ERR(0, 129, __pyx_L1_error)
  __pyx_tuple__23 = PyTuple_Pack(1, ((PyObject *)__pyx_int_8)); if (unlikely(!__pyx_tuple__23)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__23);
  __Pyx_GIVEREF(__pyx_tuple__23);

  /* "pipes.py":133
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 *
 *     def set_fu_feat(self, pipel, input_feat):             # <<<<<<<<<<<<<<
 *         for p in pipel:
 *             p[0].set_params(col='input_feat')
 */
  __pyx_tuple__24 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_pipel, __pyx_n_s_input_feat, __pyx_n_s_p); if (unlikely(!__pyx_tuple__24)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__24);
  __Pyx_GIVEREF(__pyx_tuple__24);
  __pyx_codeobj__25 = (PyObject*)__Pyx_PyCode_New(3, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__24, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_set_fu_feat, 133, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__25)) __PYX_ERR(0, 133, __pyx_L1_error)

  /* "pipes.py":139
 *         return pipel
 *
 *     def set_input_feat(self, pipel, input_feat='raw'):             # <<<<<<<<<<<<<<
 *         """ Sets the input feature for a given pipe. This is usually a dataframe column. """
 *         #pipel.set_params(col=input_feat)
 */
  __pyx_tuple__26 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_pipel, __pyx_n_s_input_feat, __pyx_n_s_x); if (unlikely(!__pyx_tuple__26)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__26);
  __Pyx_GIVEREF(__pyx_tuple__26);
  __pyx_codeobj__27 = (PyObject*)__Pyx_PyCode_New(3, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__26, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_set_input_feat, 139, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__27)) __PYX_ERR(0, 139, __pyx_L1_error)
  __pyx_tuple__28 = PyTuple_Pack(1, ((PyObject*)__pyx_n_u_raw)); if (unlikely(!__pyx_tuple__28)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__28);
  __Pyx_GIVEREF(__pyx_tuple__28);

  /* "pipes.py":147
 *         return pipel
 *
 *     def build_feature_pipe(self, input_feat, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained feature pipeline when given a feature and a list of pipes. """
 *         pipeline = self.chain_pipes(pipe_names)
 */
  __pyx_tuple__29 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_input_feat, __pyx_n_s_pipe_names, __pyx_n_s_pipeline); if (unlikely(!__pyx_tuple__29)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__29);
  __Pyx_GIVEREF(__pyx_tuple__29);
  __pyx_codeobj__30 = (PyObject*)__Pyx_PyCode_New(3, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__29, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_build_feature_pipe, 147, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__30)) __PYX_ERR(0, 147, __pyx_L1_error)

  /* "pipes.py":154
 *         return pipeline
 *
 *     def add_num_feats(self, input_feature, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to generate them. """
 *         num_feats_pipe = self.build_feature_pipe(input_feature, num_feats)
 */
  __pyx_tuple__31 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_input_feature, __pyx_n_s_num_feats, __pyx_n_s_num_feats_pipe); if (unlikely(!__pyx_tuple__31)) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__31);
  __Pyx_GIVEREF(__pyx_tuple__31);
  __pyx_codeobj__32 = (PyObject*)__Pyx_PyCode_New(3, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__31, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_add_num_feats, 154, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__32)) __PYX_ERR(0, 154, __pyx_L1_error)

  /* "pipes.py":160
 *         return num_feats_pipe
 *
 *     def add_norm_feats(self, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to normalize them. """
 *         norm_feats = [ '{}_norm'.format(f) for f in num_feats ]
 */
  __pyx_tuple__33 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_num_feats, __pyx_n_s_norm_feats, __pyx_n_s_f); if (unlikely(!__pyx_tuple__33)) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__33);
  __Pyx_GIVEREF(__pyx_tuple__33);
  __pyx_codeobj__34 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__33, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_add_norm_feats, 160, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__34)) __PYX_ERR(0, 160, __pyx_L1_error)

  /* "pipes.py":166
 *         return self.build_scalar_pipe(norm_feats)
 *
 *     def build_scalar_pipe(self, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained scalar pipeline when given a list of pipes. """
 *         pipeline = self.chain_FU_pipes(pipe_names)
 */
  __pyx_tuple__35 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_pipe_names, __pyx_n_s_pipeline); if (unlikely(!__pyx_tuple__35)) __PYX_ERR(0, 166, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__35);
  __Pyx_GIVEREF(__pyx_tuple__35);
  __pyx_codeobj__36 = (PyObject*)__Pyx_PyCode_New(2, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__35, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_build_scalar_pipe, 166, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__36)) __PYX_ERR(0, 166, __pyx_L1_error)

  /* "pipes.py":174
 *
 *     # Can be killed.
 *     def make_FU_pipe_(self, pipes: dict):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipes. """
 *         named_pipes = [ (p, i) for p, i in pipes.items() ]
 */
  __pyx_tuple__37 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_pipes, __pyx_n_s_named_pipes, __pyx_n_s_p, __pyx_n_s_i); if (unlikely(!__pyx_tuple__37)) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__37);
  __Pyx_GIVEREF(__pyx_tuple__37);
  __pyx_codeobj__38 = (PyObject*)__Pyx_PyCode_New(2, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__37, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_make_FU_pipe, 174, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__38)) __PYX_ERR(0, 174, __pyx_L1_error)

  /* "pipes.py":180
 *         return Pipeline([('FU', FeatureUnion(named_pipes))])
 *
 *     def make_FU_pipe(self, pipenames: list):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipenames. """
 *         named_pipes = [ (p, eval(p)) for p in pipenames ]
 */
  __pyx_tuple__39 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_pipenames, __pyx_n_s_named_pipes, __pyx_n_s_FU_pipe, __pyx_n_s_p); if (unlikely(!__pyx_tuple__39)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__39);
  __Pyx_GIVEREF(__pyx_tuple__39);
  __pyx_codeobj__40 = (PyObject*)__Pyx_PyCode_New(2, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__39, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_pipes_py, __pyx_n_s_make_FU_pipe_2, 180, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__40)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_float_0_8 = PyFloat_FromDouble(0.8); if (unlikely(!__pyx_float_0_8)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_8 = PyInt_FromLong(8); if (unlikely(!__pyx_int_8)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_42 = PyInt_FromLong(42); if (unlikely(!__pyx_int_42)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_2000 = PyInt_FromLong(2000); if (unlikely(!__pyx_int_2000)) __PYX_ERR(0, 1, __pyx_L1_error)
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
__Pyx_PyMODINIT_FUNC initpipes(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC initpipes(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_pipes(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC PyInit_pipes(void)
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


static CYTHON_SMALL_CODE int __pyx_pymod_exec_pipes(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'pipes' has already been imported. Re-initialisation is not supported.");
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
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_pipes(void)", 0);
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
  __pyx_m = Py_InitModule4("pipes", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
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
  if (__pyx_module_is_main_pipes) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "pipes")) {
      if (unlikely(PyDict_SetItemString(modules, "pipes", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
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

  /* "pipes.py":4
 * # @TODO: Redis integration
 *
 * from multiprocessing import cpu_count             # <<<<<<<<<<<<<<
 *
 * from nltk.corpus import stopwords
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_cpu_count);
  __Pyx_GIVEREF(__pyx_n_s_cpu_count);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_cpu_count);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_multiprocessing, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_cpu_count); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_cpu_count, __pyx_t_1) < 0) __PYX_ERR(0, 4, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":6
 * from multiprocessing import cpu_count
 *
 * from nltk.corpus import stopwords             # <<<<<<<<<<<<<<
 *
 * from sklearn.pipeline import Pipeline, FeatureUnion
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_stopwords);
  __Pyx_GIVEREF(__pyx_n_s_stopwords);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_stopwords);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_nltk_corpus, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_stopwords, __pyx_t_2) < 0) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":8
 * from nltk.corpus import stopwords
 *
 * from sklearn.pipeline import Pipeline, FeatureUnion             # <<<<<<<<<<<<<<
 * from sklearn.preprocessing import StandardScaler
 * from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer, TfidfTransformer
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Pipeline);
  __Pyx_GIVEREF(__pyx_n_s_Pipeline);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Pipeline);
  __Pyx_INCREF(__pyx_n_s_FeatureUnion);
  __Pyx_GIVEREF(__pyx_n_s_FeatureUnion);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_FeatureUnion);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_pipeline, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Pipeline, __pyx_t_1) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_FeatureUnion, __pyx_t_1) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":9
 *
 * from sklearn.pipeline import Pipeline, FeatureUnion
 * from sklearn.preprocessing import StandardScaler             # <<<<<<<<<<<<<<
 * from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer, TfidfTransformer
 * from sklearn.decomposition import PCA
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_StandardScaler);
  __Pyx_GIVEREF(__pyx_n_s_StandardScaler);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_StandardScaler);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_preprocessing, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_StandardScaler, __pyx_t_2) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":10
 * from sklearn.pipeline import Pipeline, FeatureUnion
 * from sklearn.preprocessing import StandardScaler
 * from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer, TfidfTransformer             # <<<<<<<<<<<<<<
 * from sklearn.decomposition import PCA
 * #from sklearn import svm
 */
  __pyx_t_1 = PyList_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_CountVectorizer);
  __Pyx_GIVEREF(__pyx_n_s_CountVectorizer);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_CountVectorizer);
  __Pyx_INCREF(__pyx_n_s_TfidfVectorizer);
  __Pyx_GIVEREF(__pyx_n_s_TfidfVectorizer);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_TfidfVectorizer);
  __Pyx_INCREF(__pyx_n_s_TfidfTransformer);
  __Pyx_GIVEREF(__pyx_n_s_TfidfTransformer);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_n_s_TfidfTransformer);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_feature_extraction_text, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_CountVectorizer); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CountVectorizer, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_TfidfVectorizer); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TfidfVectorizer, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_TfidfTransformer); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TfidfTransformer, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":11
 * from sklearn.preprocessing import StandardScaler
 * from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer, TfidfTransformer
 * from sklearn.decomposition import PCA             # <<<<<<<<<<<<<<
 * #from sklearn import svm
 * #from sklearn.svm import SVC
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_PCA);
  __Pyx_GIVEREF(__pyx_n_s_PCA);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_PCA);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_decomposition, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_PCA); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_PCA, __pyx_t_2) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":15
 * #from sklearn.svm import SVC
 *
 * from build.src.models import Classifiers             # <<<<<<<<<<<<<<
 * import build.src.trans as Trans
 * from common import utils
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Classifiers);
  __Pyx_GIVEREF(__pyx_n_s_Classifiers);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Classifiers);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_build_src_models, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Classifiers); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Classifiers, __pyx_t_1) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":16
 *
 * from build.src.models import Classifiers
 * import build.src.trans as Trans             # <<<<<<<<<<<<<<
 * from common import utils
 *
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_);
  __Pyx_GIVEREF(__pyx_n_s_);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_build_src_trans, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Trans, __pyx_t_1) < 0) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":17
 * from build.src.models import Classifiers
 * import build.src.trans as Trans
 * from common import utils             # <<<<<<<<<<<<<<
 *
 * # kill with fire.
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_utils);
  __Pyx_GIVEREF(__pyx_n_s_utils);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_utils);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_common, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_utils); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_utils, __pyx_t_1) < 0) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":20
 *
 * # kill with fire.
 * MAX_FEATURES=2000             # <<<<<<<<<<<<<<
 * MIN_DF=1
 * MAX_DF=0.8
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MAX_FEATURES, __pyx_int_2000) < 0) __PYX_ERR(0, 20, __pyx_L1_error)

  /* "pipes.py":21
 * # kill with fire.
 * MAX_FEATURES=2000
 * MIN_DF=1             # <<<<<<<<<<<<<<
 * MAX_DF=0.8
 * SEED=42
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MIN_DF, __pyx_int_1) < 0) __PYX_ERR(0, 21, __pyx_L1_error)

  /* "pipes.py":22
 * MAX_FEATURES=2000
 * MIN_DF=1
 * MAX_DF=0.8             # <<<<<<<<<<<<<<
 * SEED=42
 *
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MAX_DF, __pyx_float_0_8) < 0) __PYX_ERR(0, 22, __pyx_L1_error)

  /* "pipes.py":23
 * MIN_DF=1
 * MAX_DF=0.8
 * SEED=42             # <<<<<<<<<<<<<<
 *
 * # @FIXME: This seems out of place in pipes module.
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_SEED, __pyx_int_42) < 0) __PYX_ERR(0, 23, __pyx_L1_error)

  /* "pipes.py":26
 *
 * # @FIXME: This seems out of place in pipes module.
 * stopWords = set(stopwords.words('english'))             # <<<<<<<<<<<<<<
 * STOPS=stopwords.words('english')
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_words); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PySet_New(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_stopWords, __pyx_t_1) < 0) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":27
 * # @FIXME: This seems out of place in pipes module.
 * stopWords = set(stopwords.words('english'))
 * STOPS=stopwords.words('english')             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_words); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_STOPS, __pyx_t_1) < 0) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":32
 * ## Estimator pipe factory
 *
 * cls= Classifiers()             # <<<<<<<<<<<<<<
 *
 * class ClassifierPipes(object):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Classifiers); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_cls, __pyx_t_2) < 0) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":34
 * cls= Classifiers()
 *
 * class ClassifierPipes(object):             # <<<<<<<<<<<<<<
 *     """ Pipe factory for single step classifier pipes. """
 *     def __init__(self):
 */
  __pyx_t_2 = __Pyx_CalculateMetaclass(NULL, __pyx_tuple__3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_2, __pyx_tuple__3, __pyx_n_s_ClassifierPipes, __pyx_n_s_ClassifierPipes, (PyObject *) NULL, __pyx_n_s_pipes, __pyx_kp_s_Pipe_factory_for_single_step_cl); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "pipes.py":36
 * class ClassifierPipes(object):
 *     """ Pipe factory for single step classifier pipes. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_15ClassifierPipes_1__init__, 0, __pyx_n_s_ClassifierPipes___init, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__5)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_3) < 0) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":39
 *         pass
 *
 *     def clf(self, classifier):             # <<<<<<<<<<<<<<
 *         pipename = classifier + '_pipe'
 *         pipe = getattr(cls, classifier)
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_15ClassifierPipes_3clf, 0, __pyx_n_s_ClassifierPipes_clf, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__7)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_clf, __pyx_t_3) < 0) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":34
 * cls= Classifiers()
 *
 * class ClassifierPipes(object):             # <<<<<<<<<<<<<<
 *     """ Pipe factory for single step classifier pipes. """
 *     def __init__(self):
 */
  __pyx_t_3 = __Pyx_Py3ClassCreate(__pyx_t_2, __pyx_n_s_ClassifierPipes, __pyx_tuple__3, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ClassifierPipes, __pyx_t_3) < 0) __PYX_ERR(0, 34, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":51
 * ## Pipe builder methods
 *
 * class Pipe(object):             # <<<<<<<<<<<<<<
 *     """ Class with all methods needed to dynamically build pipes at runtime. """
 *     def __init__(self):
 */
  __pyx_t_2 = __Pyx_CalculateMetaclass(NULL, __pyx_tuple__8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_2, __pyx_tuple__8, __pyx_n_s_Pipe, __pyx_n_s_Pipe, (PyObject *) NULL, __pyx_n_s_pipes, __pyx_kp_s_Class_with_all_methods_needed_t); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "pipes.py":53
 * class Pipe(object):
 *     """ Class with all methods needed to dynamically build pipes at runtime. """
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_1__init__, 0, __pyx_n_s_Pipe___init, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__10)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_3) < 0) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":56
 *         pass
 *
 *     def load_pipe(self, pipename: str):             # <<<<<<<<<<<<<<
 *         """ Returns a single (defined) pipe when asked for by name. """
 *         return eval(pipename)
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_pipename, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 56, __pyx_L1_error)
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_3load_pipe, 0, __pyx_n_s_Pipe_load_pipe, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__12)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_load_pipe, __pyx_t_4) < 0) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "pipes.py":60
 *         return eval(pipename)
 *
 *     def make_pipe(self, pipename: str, params: dict):             # <<<<<<<<<<<<<<
 *         """ Creates a single step pipe with optional params. """
 *         step = (pipename, eval(pipename+'_pipe'))
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_pipename, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 60, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_params, __pyx_n_u_dict_2) < 0) __PYX_ERR(0, 60, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_5make_pipe, 0, __pyx_n_s_Pipe_make_pipe, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__14)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_make_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 60, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":70
 *         #return Pipeline(pipe)
 *
 *     def make_normie(self, col_nom: str):             # <<<<<<<<<<<<<<
 *         """ Sselector pipe to normalize a given numeric column.
 *         input: dataframe containing the target column.
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_col_nom, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 70, __pyx_L1_error)
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_7make_normie, 0, __pyx_n_s_Pipe_make_normie, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__16)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_make_normie, __pyx_t_4) < 0) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "pipes.py":89
 *     #    return Pipeline(features)
 *
 *     def chain_pipes(self, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a mixed list of pipes and pipe names, returns a Pipeline of fully named pipes.
 *         :param pipes: a list which may contain both pipes and pipe names.
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_pipes, __pyx_n_u_list) < 0) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_return, __pyx_t_3) < 0) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_9chain_pipes, 0, __pyx_n_s_Pipe_chain_pipes, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__18)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_chain_pipes, __pyx_t_3) < 0) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":102
 *         return Pipeline(steps)
 *
 *     def chain_fu_pipes(self, pipename: str, pipes: list) -> Pipeline:             # <<<<<<<<<<<<<<
 *         """ Given a list of pipes, returns a FeatureUnion of named pipes.
 *         Sub-pipe names are automatically generated as a hash of their steps.
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_pipename, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 102, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_pipes, __pyx_n_u_list) < 0) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_t_4) < 0) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_11chain_fu_pipes, 0, __pyx_n_s_Pipe_chain_fu_pipes, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__20)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_chain_fu_pipes, __pyx_t_4) < 0) __PYX_ERR(0, 102, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "pipes.py":129
 *     """
 *
 *     def hash_pipe(self, pipe, len=8) ->'md5_hash':             # <<<<<<<<<<<<<<
 *         """ Generate a handle for a given pipe by taking the hash of its steps. """
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_return, __pyx_n_u_md5_hash) < 0) __PYX_ERR(0, 129, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_13hash_pipe, 0, __pyx_n_s_Pipe_hash_pipe, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__22)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_3, __pyx_tuple__23);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_hash_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":133
 *         return utils.md5_hash(str(pipe.__dict__['steps']),len)
 *
 *     def set_fu_feat(self, pipel, input_feat):             # <<<<<<<<<<<<<<
 *         for p in pipel:
 *             p[0].set_params(col='input_feat')
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_15set_fu_feat, 0, __pyx_n_s_Pipe_set_fu_feat, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__25)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_set_fu_feat, __pyx_t_3) < 0) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":139
 *         return pipel
 *
 *     def set_input_feat(self, pipel, input_feat='raw'):             # <<<<<<<<<<<<<<
 *         """ Sets the input feature for a given pipe. This is usually a dataframe column. """
 *         #pipel.set_params(col=input_feat)
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_17set_input_feat, 0, __pyx_n_s_Pipe_set_input_feat, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__27)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_3, __pyx_tuple__28);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_set_input_feat, __pyx_t_3) < 0) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":147
 *         return pipel
 *
 *     def build_feature_pipe(self, input_feat, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained feature pipeline when given a feature and a list of pipes. """
 *         pipeline = self.chain_pipes(pipe_names)
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_19build_feature_pipe, 0, __pyx_n_s_Pipe_build_feature_pipe, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__30)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_build_feature_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":154
 *         return pipeline
 *
 *     def add_num_feats(self, input_feature, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to generate them. """
 *         num_feats_pipe = self.build_feature_pipe(input_feature, num_feats)
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_21add_num_feats, 0, __pyx_n_s_Pipe_add_num_feats, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__32)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_add_num_feats, __pyx_t_3) < 0) __PYX_ERR(0, 154, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":160
 *         return num_feats_pipe
 *
 *     def add_norm_feats(self, num_feats):             # <<<<<<<<<<<<<<
 *         """ Given a list of numeric features, builds a pipe to normalize them. """
 *         norm_feats = [ '{}_norm'.format(f) for f in num_feats ]
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_23add_norm_feats, 0, __pyx_n_s_Pipe_add_norm_feats, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__34)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_add_norm_feats, __pyx_t_3) < 0) __PYX_ERR(0, 160, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":166
 *         return self.build_scalar_pipe(norm_feats)
 *
 *     def build_scalar_pipe(self, pipe_names):             # <<<<<<<<<<<<<<
 *         """ Returns a chained scalar pipeline when given a list of pipes. """
 *         pipeline = self.chain_FU_pipes(pipe_names)
 */
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_25build_scalar_pipe, 0, __pyx_n_s_Pipe_build_scalar_pipe, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__36)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 166, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_build_scalar_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 166, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":174
 *
 *     # Can be killed.
 *     def make_FU_pipe_(self, pipes: dict):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipes. """
 *         named_pipes = [ (p, i) for p, i in pipes.items() ]
 */
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_pipes, __pyx_n_u_dict_2) < 0) __PYX_ERR(0, 174, __pyx_L1_error)
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_27make_FU_pipe_, 0, __pyx_n_s_Pipe_make_FU_pipe, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__38)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_make_FU_pipe, __pyx_t_4) < 0) __PYX_ERR(0, 174, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "pipes.py":180
 *         return Pipeline([('FU', FeatureUnion(named_pipes))])
 *
 *     def make_FU_pipe(self, pipenames: list):             # <<<<<<<<<<<<<<
 *         """ Returns a FeatureUnion from a list of pipenames. """
 *         named_pipes = [ (p, eval(p)) for p in pipenames ]
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_pipenames, __pyx_n_u_list) < 0) __PYX_ERR(0, 180, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5pipes_4Pipe_29make_FU_pipe, 0, __pyx_n_s_Pipe_make_FU_pipe_2, NULL, __pyx_n_s_pipes, __pyx_d, ((PyObject *)__pyx_codeobj__40)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_make_FU_pipe_2, __pyx_t_3) < 0) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":51
 * ## Pipe builder methods
 *
 * class Pipe(object):             # <<<<<<<<<<<<<<
 *     """ Class with all methods needed to dynamically build pipes at runtime. """
 *     def __init__(self):
 */
  __pyx_t_3 = __Pyx_Py3ClassCreate(__pyx_t_2, __pyx_n_s_Pipe, __pyx_tuple__8, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Pipe, __pyx_t_3) < 0) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":198
 *
 * # Imputation stub
 * missing_data_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     #('selector', Trans.NumberSelector()),
 *     ('missing', Trans.MissingData()),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "pipes.py":200
 * missing_data_pipe = Pipeline([
 *     #('selector', Trans.NumberSelector()),
 *     ('missing', Trans.MissingData()),             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_MissingData); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 200, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_missing);
  __Pyx_GIVEREF(__pyx_n_u_missing);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_missing);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":198
 *
 * # Imputation stub
 * missing_data_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     #('selector', Trans.NumberSelector()),
 *     ('missing', Trans.MissingData()),
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_missing_data_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":206
 * ## Vector pipes
 *
 * word_vector_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.TextSelector(col='raw')),
 *     ('cv', CountVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words='english')),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":207
 *
 * word_vector_pipe = Pipeline([
 *     ('selector', Trans.TextSelector(col='raw')),             # <<<<<<<<<<<<<<
 *     ('cv', CountVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words='english')),
 *     ('tfidf', TfidfTransformer()),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_TextSelector); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_col, __pyx_n_u_raw) < 0) __PYX_ERR(0, 207, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_4);
  __pyx_t_4 = 0;

  /* "pipes.py":208
 * word_vector_pipe = Pipeline([
 *     ('selector', Trans.TextSelector(col='raw')),
 *     ('cv', CountVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words='english')),             # <<<<<<<<<<<<<<
 *     ('tfidf', TfidfTransformer()),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_CountVectorizer); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_MAX_FEATURES); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_max_features, __pyx_t_5) < 0) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_MIN_DF); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_min_df, __pyx_t_5) < 0) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_MAX_DF); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_max_df, __pyx_t_5) < 0) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_stop_words, __pyx_n_u_english) < 0) __PYX_ERR(0, 208, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_u_cv);
  __Pyx_GIVEREF(__pyx_n_u_cv);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_n_u_cv);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":209
 *     ('selector', Trans.TextSelector(col='raw')),
 *     ('cv', CountVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words='english')),
 *     ('tfidf', TfidfTransformer()),             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_TfidfTransformer); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_4 = __Pyx_PyObject_CallNoArg(__pyx_t_5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_tfidf);
  __Pyx_GIVEREF(__pyx_n_u_tfidf);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_tfidf);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_4);
  __pyx_t_4 = 0;

  /* "pipes.py":206
 * ## Vector pipes
 *
 * word_vector_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.TextSelector(col='raw')),
 *     ('cv', CountVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words='english')),
 */
  __pyx_t_4 = PyList_New(3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_4, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_4, 1, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_4, 2, __pyx_t_5);
  __pyx_t_1 = 0;
  __pyx_t_2 = 0;
  __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_word_vector_pipe, __pyx_t_5) < 0) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "pipes.py":212
 *     ])
 *
 * tfidf_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('vec', TfidfVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words=stopwords.words('english'))),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "pipes.py":213
 *
 * tfidf_pipe = Pipeline([
 *     ('vec', TfidfVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words=stopwords.words('english'))),             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_TfidfVectorizer); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_MAX_FEATURES); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_max_features, __pyx_t_2) < 0) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_MIN_DF); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_min_df, __pyx_t_2) < 0) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_MAX_DF); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_max_df, __pyx_t_2) < 0) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_words); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_stop_words, __pyx_t_2) < 0) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_vec);
  __Pyx_GIVEREF(__pyx_n_u_vec);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_vec);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":212
 *     ])
 *
 * tfidf_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('vec', TfidfVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words=stopwords.words('english'))),
 *     ])
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_tfidf_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":216
 *     ])
 *
 * tfidf_col_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.TextSelector(col='raw')),
 *     ('vec', TfidfVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words=stopwords.words('english'))),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 216, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":217
 *
 * tfidf_col_pipe = Pipeline([
 *     ('selector', Trans.TextSelector(col='raw')),             # <<<<<<<<<<<<<<
 *     ('vec', TfidfVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words=stopwords.words('english'))),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Trans); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_TextSelector); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_col, __pyx_n_u_raw) < 0) __PYX_ERR(0, 217, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_4);
  __pyx_t_4 = 0;

  /* "pipes.py":218
 * tfidf_col_pipe = Pipeline([
 *     ('selector', Trans.TextSelector(col='raw')),
 *     ('vec', TfidfVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words=stopwords.words('english'))),             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_TfidfVectorizer); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_MAX_FEATURES); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_max_features, __pyx_t_1) < 0) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_MIN_DF); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_min_df, __pyx_t_1) < 0) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_MAX_DF); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_max_df, __pyx_t_1) < 0) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_words); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_stop_words, __pyx_t_1) < 0) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 218, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_vec);
  __Pyx_GIVEREF(__pyx_n_u_vec);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_vec);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":216
 *     ])
 *
 * tfidf_col_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.TextSelector(col='raw')),
 *     ('vec', TfidfVectorizer(max_features=MAX_FEATURES, min_df=MIN_DF, max_df=MAX_DF, stop_words=stopwords.words('english'))),
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 216, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_5);
  __pyx_t_2 = 0;
  __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 216, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_tfidf_col_pipe, __pyx_t_5) < 0) __PYX_ERR(0, 216, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "pipes.py":226
 *
 * # A pipe to select only the features passed in set_params()
 * features_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('select_feats', Trans.FeatureSelector())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "pipes.py":227
 * # A pipe to select only the features passed in set_params()
 * features_pipe = Pipeline([
 *     ('select_feats', Trans.FeatureSelector())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_FeatureSelector); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_select_feats);
  __Pyx_GIVEREF(__pyx_n_u_select_feats);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_select_feats);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":226
 *
 * # A pipe to select only the features passed in set_params()
 * features_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('select_feats', Trans.FeatureSelector())
 *     ])
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_features_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":231
 *
 * # A pipe to drop any features passed with set params()
 * drop_features_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('drop_feats', Trans.DropFeatures())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":232
 * # A pipe to drop any features passed with set params()
 * drop_features_pipe = Pipeline([
 *     ('drop_feats', Trans.DropFeatures())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_DropFeatures); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 232, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_drop_feats);
  __Pyx_GIVEREF(__pyx_n_u_drop_feats);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_drop_feats);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":231
 *
 * # A pipe to drop any features passed with set params()
 * drop_features_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('drop_feats', Trans.DropFeatures())
 *     ])
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
  __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_drop_features_pipe, __pyx_t_5) < 0) __PYX_ERR(0, 231, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "pipes.py":237
 * # Converts a single category from strs to ints when passed target list with set_params()
 * # Or just use LabelEncoder()
 * targets_str_to_int_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('convert', Trans.ConvertTargets())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "pipes.py":238
 * # Or just use LabelEncoder()
 * targets_str_to_int_pipe = Pipeline([
 *     ('convert', Trans.ConvertTargets())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_ConvertTargets); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 238, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_convert);
  __Pyx_GIVEREF(__pyx_n_u_convert);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_convert);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":237
 * # Converts a single category from strs to ints when passed target list with set_params()
 * # Or just use LabelEncoder()
 * targets_str_to_int_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('convert', Trans.ConvertTargets())
 *     ])
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_targets_str_to_int_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":241
 *     ])
 *
 * boolean_targets_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('bt', Trans.BooleanTargets(col='col', tar1='tar', tar2='tar')), # placeholder gbdg
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":242
 *
 * boolean_targets_pipe = Pipeline([
 *     ('bt', Trans.BooleanTargets(col='col', tar1='tar', tar2='tar')), # placeholder gbdg             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_BooleanTargets); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_col, __pyx_n_u_col) < 0) __PYX_ERR(0, 242, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_tar1, __pyx_n_u_tar) < 0) __PYX_ERR(0, 242, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_tar2, __pyx_n_u_tar) < 0) __PYX_ERR(0, 242, __pyx_L1_error)
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_bt);
  __Pyx_GIVEREF(__pyx_n_u_bt);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_bt);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":241
 *     ])
 *
 * boolean_targets_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('bt', Trans.BooleanTargets(col='col', tar1='tar', tar2='tar')), # placeholder gbdg
 *     ])
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_boolean_targets_pipe, __pyx_t_1) < 0) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":251
 *
 * # Normalized sentence length.
 * sen_len_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('sentences', Trans.SentenceLength())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "pipes.py":252
 * # Normalized sentence length.
 * sen_len_pipe =  Pipeline([
 *     ('sentences', Trans.SentenceLength())             # <<<<<<<<<<<<<<
 *     ])
 * sen_len_norm_pipe =  Pipeline([
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Trans); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_SentenceLength); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_sentences);
  __Pyx_GIVEREF(__pyx_n_u_sentences);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_sentences);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":251
 *
 * # Normalized sentence length.
 * sen_len_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('sentences', Trans.SentenceLength())
 *     ])
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sen_len_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":254
 *     ('sentences', Trans.SentenceLength())
 *     ])
 * sen_len_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='sen_len')),
 *     ('standard', StandardScaler())
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":255
 *     ])
 * sen_len_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='sen_len')),             # <<<<<<<<<<<<<<
 *     ('standard', StandardScaler())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Trans); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_NumberSelector); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_col, __pyx_n_u_sen_len) < 0) __PYX_ERR(0, 255, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":256
 * sen_len_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='sen_len')),
 *     ('standard', StandardScaler())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":254
 *     ('sentences', Trans.SentenceLength())
 *     ])
 * sen_len_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='sen_len')),
 *     ('standard', StandardScaler())
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_5);
  __pyx_t_2 = 0;
  __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sen_len_norm_pipe, __pyx_t_5) < 0) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "pipes.py":259
 *     ])
 *
 * count_commas_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('commas', Trans.CountCommas()),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 259, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "pipes.py":260
 *
 * count_commas_pipe = Pipeline([
 *     ('commas', Trans.CountCommas()),             # <<<<<<<<<<<<<<
 *     ])
 * count_commas_norm_pipe =  Pipeline([
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 260, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_CountCommas); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 260, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 260, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 260, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_commas);
  __Pyx_GIVEREF(__pyx_n_u_commas);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_commas);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":259
 *     ])
 *
 * count_commas_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('commas', Trans.CountCommas()),
 *     ])
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 259, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 259, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_count_commas_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 259, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":262
 *     ('commas', Trans.CountCommas()),
 *     ])
 * count_commas_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='count_commas')),
 *     ('standard', StandardScaler())
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":263
 *     ])
 * count_commas_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='count_commas')),             # <<<<<<<<<<<<<<
 *     ('standard', StandardScaler())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 263, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_NumberSelector); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 263, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 263, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_col, __pyx_n_u_count_commas) < 0) __PYX_ERR(0, 263, __pyx_L1_error)
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 263, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 263, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":264
 * count_commas_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='count_commas')),
 *     ('standard', StandardScaler())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 264, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 264, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 264, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":262
 *     ('commas', Trans.CountCommas()),
 *     ])
 * count_commas_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='count_commas')),
 *     ('standard', StandardScaler())
 */
  __pyx_t_5 = PyList_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_5, 1, __pyx_t_2);
  __pyx_t_1 = 0;
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_count_commas_norm_pipe, __pyx_t_2) < 0) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":267
 *     ])
 *
 * count_words_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('words', Trans.CountWords()),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "pipes.py":268
 *
 * count_words_pipe = Pipeline([
 *     ('words', Trans.CountWords()),             # <<<<<<<<<<<<<<
 *     ])
 * count_words_norm_pipe =  Pipeline([
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Trans); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_CountWords); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_words);
  __Pyx_GIVEREF(__pyx_n_u_words);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_words);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":267
 *     ])
 *
 * count_words_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('words', Trans.CountWords()),
 *     ])
 */
  __pyx_t_5 = PyList_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_count_words_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":270
 *     ('words', Trans.CountWords()),
 *     ])
 * count_words_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='count_words')),
 *     ('standard', StandardScaler())
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 270, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":271
 *     ])
 * count_words_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='count_words')),             # <<<<<<<<<<<<<<
 *     ('standard', StandardScaler())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Trans); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 271, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_NumberSelector); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 271, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 271, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_col, __pyx_n_u_count_words) < 0) __PYX_ERR(0, 271, __pyx_L1_error)
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 271, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 271, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":272
 * count_words_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='count_words')),
 *     ('standard', StandardScaler())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":270
 *     ('words', Trans.CountWords()),
 *     ])
 * count_words_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='count_words')),
 *     ('standard', StandardScaler())
 */
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 270, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_5 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 270, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_count_words_norm_pipe, __pyx_t_1) < 0) __PYX_ERR(0, 270, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":275
 *     ])
 *
 * avg_word_len_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('awl', Trans.AvgWordLenTransformer())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 275, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "pipes.py":276
 *
 * avg_word_len_pipe =  Pipeline([
 *     ('awl', Trans.AvgWordLenTransformer())             # <<<<<<<<<<<<<<
 *     ])
 * avg_word_len_norm_pipe =  Pipeline([
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Trans); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_AvgWordLenTransformer); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_awl);
  __Pyx_GIVEREF(__pyx_n_u_awl);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_awl);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":275
 *     ])
 *
 * avg_word_len_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('awl', Trans.AvgWordLenTransformer())
 *     ])
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 275, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 275, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_avg_word_len_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 275, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":278
 *     ('awl', Trans.AvgWordLenTransformer())
 *     ])
 * avg_word_len_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='avg_word_len')),
 *     ('standard', StandardScaler())
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":279
 *     ])
 * avg_word_len_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='avg_word_len')),             # <<<<<<<<<<<<<<
 *     ('standard', StandardScaler())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Trans); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 279, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_NumberSelector); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 279, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 279, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_col, __pyx_n_u_avg_word_len) < 0) __PYX_ERR(0, 279, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 279, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 279, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":280
 * avg_word_len_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='avg_word_len')),
 *     ('standard', StandardScaler())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 280, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 280, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 280, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":278
 *     ('awl', Trans.AvgWordLenTransformer())
 *     ])
 * avg_word_len_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='avg_word_len')),
 *     ('standard', StandardScaler())
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_5);
  __pyx_t_2 = 0;
  __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_avg_word_len_norm_pipe, __pyx_t_5) < 0) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "pipes.py":283
 *     ])
 *
 * not_stops_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('notstops', Trans.NotStopsTransformer()),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 283, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);

  /* "pipes.py":284
 *
 * not_stops_pipe = Pipeline([
 *     ('notstops', Trans.NotStopsTransformer()),             # <<<<<<<<<<<<<<
 *     ])
 * not_stops_norm_pipe =  Pipeline([
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_NotStopsTransformer); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_notstops);
  __Pyx_GIVEREF(__pyx_n_u_notstops);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_notstops);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":283
 *     ])
 *
 * not_stops_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('notstops', Trans.NotStopsTransformer()),
 *     ])
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 283, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 283, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_not_stops_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 283, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":286
 *     ('notstops', Trans.NotStopsTransformer()),
 *     ])
 * not_stops_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='not_stops')),
 *     ('standard', StandardScaler())
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 286, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":287
 *     ])
 * not_stops_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='not_stops')),             # <<<<<<<<<<<<<<
 *     ('standard', StandardScaler())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Trans); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_NumberSelector); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_col, __pyx_n_u_not_stops) < 0) __PYX_ERR(0, 287, __pyx_L1_error)
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_empty_tuple, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":288
 * not_stops_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='not_stops')),
 *     ('standard', StandardScaler())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 288, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 288, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 288, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":286
 *     ('notstops', Trans.NotStopsTransformer()),
 *     ])
 * not_stops_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='not_stops')),
 *     ('standard', StandardScaler())
 */
  __pyx_t_5 = PyList_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 286, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_5, 1, __pyx_t_2);
  __pyx_t_1 = 0;
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 286, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_not_stops_norm_pipe, __pyx_t_2) < 0) __PYX_ERR(0, 286, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "pipes.py":291
 *     ])
 *
 * comma_len_ratio_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('commalenratio', Trans.CommaLenRatio()),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 291, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "pipes.py":292
 *
 * comma_len_ratio_pipe = Pipeline([
 *     ('commalenratio', Trans.CommaLenRatio()),             # <<<<<<<<<<<<<<
 *     ])
 * comma_len_ratio_norm_pipe =  Pipeline([
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Trans); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_CommaLenRatio); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_commalenratio);
  __Pyx_GIVEREF(__pyx_n_u_commalenratio);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_commalenratio);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_5);
  __pyx_t_5 = 0;

  /* "pipes.py":291
 *     ])
 *
 * comma_len_ratio_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('commalenratio', Trans.CommaLenRatio()),
 *     ])
 */
  __pyx_t_5 = PyList_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 291, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 291, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_comma_len_ratio_pipe, __pyx_t_3) < 0) __PYX_ERR(0, 291, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "pipes.py":294
 *     ('commalenratio', Trans.CommaLenRatio()),
 *     ])
 * comma_len_ratio_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='comma_len_ratio')),
 *     ('standard', StandardScaler())
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "pipes.py":295
 *     ])
 * comma_len_ratio_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='comma_len_ratio')),             # <<<<<<<<<<<<<<
 *     ('standard', StandardScaler())
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_Trans); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 295, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_NumberSelector); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 295, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 295, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_col, __pyx_n_u_comma_len_ratio) < 0) __PYX_ERR(0, 295, __pyx_L1_error)
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 295, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 295, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_n_u_selector);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_selector);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":296
 * comma_len_ratio_norm_pipe =  Pipeline([
 *     ('selector', Trans.NumberSelector(col='comma_len_ratio')),
 *     ('standard', StandardScaler())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 296, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":294
 *     ('commalenratio', Trans.CommaLenRatio()),
 *     ])
 * comma_len_ratio_norm_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     ('selector', Trans.NumberSelector(col='comma_len_ratio')),
 *     ('standard', StandardScaler())
 */
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_5 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_comma_len_ratio_norm_pipe, __pyx_t_1) < 0) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":304
 *
 * # Not normalized.
 * numeric_feats_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('sl', sen_len_pipe),
 *     ('cc', count_commas_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "pipes.py":305
 * # Not normalized.
 * numeric_feats_pipe = Pipeline([
 *     ('sl', sen_len_pipe),             # <<<<<<<<<<<<<<
 *     ('cc', count_commas_pipe),
 *     ('cw', count_words_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sen_len_pipe); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_sl);
  __Pyx_GIVEREF(__pyx_n_u_sl);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_sl);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":306
 * numeric_feats_pipe = Pipeline([
 *     ('sl', sen_len_pipe),
 *     ('cc', count_commas_pipe),             # <<<<<<<<<<<<<<
 *     ('cw', count_words_pipe),
 *     ('awl', avg_word_len_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_count_commas_pipe); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 306, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 306, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_cc);
  __Pyx_GIVEREF(__pyx_n_u_cc);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_cc);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":307
 *     ('sl', sen_len_pipe),
 *     ('cc', count_commas_pipe),
 *     ('cw', count_words_pipe),             # <<<<<<<<<<<<<<
 *     ('awl', avg_word_len_pipe),
 *     ('ns', not_stops_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_count_words_pipe); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 307, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 307, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_n_u_cw);
  __Pyx_GIVEREF(__pyx_n_u_cw);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_n_u_cw);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":308
 *     ('cc', count_commas_pipe),
 *     ('cw', count_words_pipe),
 *     ('awl', avg_word_len_pipe),             # <<<<<<<<<<<<<<
 *     ('ns', not_stops_pipe),
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_avg_word_len_pipe); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 308, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 308, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_INCREF(__pyx_n_u_awl);
  __Pyx_GIVEREF(__pyx_n_u_awl);
  PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_n_u_awl);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":309
 *     ('cw', count_words_pipe),
 *     ('awl', avg_word_len_pipe),
 *     ('ns', not_stops_pipe),             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_not_stops_pipe); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_7 = PyTuple_New(2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_INCREF(__pyx_n_u_ns);
  __Pyx_GIVEREF(__pyx_n_u_ns);
  PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_n_u_ns);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_2);
  __pyx_t_2 = 0;

  /* "pipes.py":304
 *
 * # Not normalized.
 * numeric_feats_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('sl', sen_len_pipe),
 *     ('cc', count_commas_pipe),
 */
  __pyx_t_2 = PyList_New(5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_6);
  PyList_SET_ITEM(__pyx_t_2, 3, __pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_7);
  PyList_SET_ITEM(__pyx_t_2, 4, __pyx_t_7);
  __pyx_t_3 = 0;
  __pyx_t_5 = 0;
  __pyx_t_4 = 0;
  __pyx_t_6 = 0;
  __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_numeric_feats_pipe, __pyx_t_7) < 0) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  /* "pipes.py":312
 *     ])
 *
 * norm_feats_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('FU', FeatureUnion([
 *         ('lp', sen_len_norm_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 312, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);

  /* "pipes.py":313
 *
 * norm_feats_pipe = Pipeline([
 *     ('FU', FeatureUnion([             # <<<<<<<<<<<<<<
 *         ('lp', sen_len_norm_pipe),
 *         ('cc', count_commas_norm_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 313, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "pipes.py":314
 * norm_feats_pipe = Pipeline([
 *     ('FU', FeatureUnion([
 *         ('lp', sen_len_norm_pipe),             # <<<<<<<<<<<<<<
 *         ('cc', count_commas_norm_pipe),
 *         ('cw', count_words_norm_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sen_len_norm_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 314, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = PyTuple_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 314, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_INCREF(__pyx_n_u_lp);
  __Pyx_GIVEREF(__pyx_n_u_lp);
  PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_n_u_lp);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":315
 *     ('FU', FeatureUnion([
 *         ('lp', sen_len_norm_pipe),
 *         ('cc', count_commas_norm_pipe),             # <<<<<<<<<<<<<<
 *         ('cw', count_words_norm_pipe),
 *         ('awl', avg_word_len_norm_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_count_commas_norm_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 315, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 315, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_INCREF(__pyx_n_u_cc);
  __Pyx_GIVEREF(__pyx_n_u_cc);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_n_u_cc);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":316
 *         ('lp', sen_len_norm_pipe),
 *         ('cc', count_commas_norm_pipe),
 *         ('cw', count_words_norm_pipe),             # <<<<<<<<<<<<<<
 *         ('awl', avg_word_len_norm_pipe),
 *         ('ns', not_stops_norm_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_count_words_norm_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 316, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 316, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_INCREF(__pyx_n_u_cw);
  __Pyx_GIVEREF(__pyx_n_u_cw);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_n_u_cw);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":317
 *         ('cc', count_commas_norm_pipe),
 *         ('cw', count_words_norm_pipe),
 *         ('awl', avg_word_len_norm_pipe),             # <<<<<<<<<<<<<<
 *         ('ns', not_stops_norm_pipe),
 *         ]))
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_avg_word_len_norm_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 317, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 317, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_awl);
  __Pyx_GIVEREF(__pyx_n_u_awl);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_awl);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":318
 *         ('cw', count_words_norm_pipe),
 *         ('awl', avg_word_len_norm_pipe),
 *         ('ns', not_stops_norm_pipe),             # <<<<<<<<<<<<<<
 *         ]))
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_not_stops_norm_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 318, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_8 = PyTuple_New(2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 318, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_INCREF(__pyx_n_u_ns);
  __Pyx_GIVEREF(__pyx_n_u_ns);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_n_u_ns);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":313
 *
 * norm_feats_pipe = Pipeline([
 *     ('FU', FeatureUnion([             # <<<<<<<<<<<<<<
 *         ('lp', sen_len_norm_pipe),
 *         ('cc', count_commas_norm_pipe),
 */
  __pyx_t_1 = PyList_New(5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 313, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_6);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_6);
  __Pyx_GIVEREF(__pyx_t_4);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_5);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 3, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_8);
  PyList_SET_ITEM(__pyx_t_1, 4, __pyx_t_8);
  __pyx_t_6 = 0;
  __pyx_t_4 = 0;
  __pyx_t_5 = 0;
  __pyx_t_3 = 0;
  __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 313, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 313, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_n_u_FU);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_8);
  __pyx_t_8 = 0;

  /* "pipes.py":312
 *     ])
 *
 * norm_feats_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('FU', FeatureUnion([
 *         ('lp', sen_len_norm_pipe),
 */
  __pyx_t_8 = PyList_New(1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 312, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_8, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_8); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 312, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_norm_feats_pipe, __pyx_t_1) < 0) __PYX_ERR(0, 312, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":322
 *     ])
 *
 * normie_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     #('selector', Trans.NumberSelector()),
 *     ('standard', StandardScaler())
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 322, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "pipes.py":324
 * normie_pipe =  Pipeline([
 *     #('selector', Trans.NumberSelector()),
 *     ('standard', StandardScaler())             # <<<<<<<<<<<<<<
 *     ])
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_StandardScaler); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 324, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_7 = __Pyx_PyObject_CallNoArg(__pyx_t_8); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 324, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = PyTuple_New(2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 324, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_INCREF(__pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_n_u_standard);
  PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_n_u_standard);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_8, 1, __pyx_t_7);
  __pyx_t_7 = 0;

  /* "pipes.py":322
 *     ])
 *
 * normie_pipe =  Pipeline([             # <<<<<<<<<<<<<<
 *     #('selector', Trans.NumberSelector()),
 *     ('standard', StandardScaler())
 */
  __pyx_t_7 = PyList_New(1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 322, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_8);
  PyList_SET_ITEM(__pyx_t_7, 0, __pyx_t_8);
  __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 322, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_normie_pipe, __pyx_t_8) < 0) __PYX_ERR(0, 322, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  /* "pipes.py":328
 *
 * # Combine dense and sparse features, returns scipy array.
 * combine_feats_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('FU', FeatureUnion([
 *         ('normies', norm_feats_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_Pipeline); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 328, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);

  /* "pipes.py":329
 * # Combine dense and sparse features, returns scipy array.
 * combine_feats_pipe = Pipeline([
 *     ('FU', FeatureUnion([             # <<<<<<<<<<<<<<
 *         ('normies', norm_feats_pipe),
 *         #('cvector', vector_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);

  /* "pipes.py":330
 * combine_feats_pipe = Pipeline([
 *     ('FU', FeatureUnion([
 *         ('normies', norm_feats_pipe),             # <<<<<<<<<<<<<<
 *         #('cvector', vector_pipe),
 *         ('tvector', tfidf_pipe),
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_norm_feats_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 330, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 330, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_u_normies);
  __Pyx_GIVEREF(__pyx_n_u_normies);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_n_u_normies);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":332
 *         ('normies', norm_feats_pipe),
 *         #('cvector', vector_pipe),
 *         ('tvector', tfidf_pipe),             # <<<<<<<<<<<<<<
 *         ]))
 *     ])
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_tfidf_pipe); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 332, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 332, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_n_u_tvector);
  __Pyx_GIVEREF(__pyx_n_u_tvector);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_n_u_tvector);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_1 = 0;

  /* "pipes.py":329
 * # Combine dense and sparse features, returns scipy array.
 * combine_feats_pipe = Pipeline([
 *     ('FU', FeatureUnion([             # <<<<<<<<<<<<<<
 *         ('normies', norm_feats_pipe),
 *         #('cvector', vector_pipe),
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_2 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_n_u_FU);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_FU);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_3 = 0;

  /* "pipes.py":328
 *
 * # Combine dense and sparse features, returns scipy array.
 * combine_feats_pipe = Pipeline([             # <<<<<<<<<<<<<<
 *     ('FU', FeatureUnion([
 *         ('normies', norm_feats_pipe),
 */
  __pyx_t_3 = PyList_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 328, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 328, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_combine_feats_pipe, __pyx_t_1) < 0) __PYX_ERR(0, 328, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "pipes.py":1
 * # pipes.py - Pipe builder class and some generally useful legacy pipes.             # <<<<<<<<<<<<<<
 * # @TODO: Redis integration
 *
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
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init pipes", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init pipes");
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

/* ArgTypeTest */
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact)
{
    if (unlikely(!type)) {
        PyErr_SetString(PyExc_SystemError, "Missing type object");
        return 0;
    }
    else if (exact) {
        #if PY_MAJOR_VERSION == 2
        if ((type == &PyBaseString_Type) && likely(__Pyx_PyBaseString_CheckExact(obj))) return 1;
        #endif
    }
    else {
        if (likely(__Pyx_TypeCheck(obj, type))) return 1;
    }
    PyErr_Format(PyExc_TypeError,
        "Argument '%.200s' has incorrect type (expected %.200s, got %.200s)",
        name, type->tp_name, Py_TYPE(obj)->tp_name);
    return 0;
}

/* IterFinish */
static CYTHON_INLINE int __Pyx_IterFinish(void) {
#if CYTHON_FAST_THREAD_STATE
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject* exc_type = tstate->curexc_type;
    if (unlikely(exc_type)) {
        if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) {
            PyObject *exc_value, *exc_tb;
            exc_value = tstate->curexc_value;
            exc_tb = tstate->curexc_traceback;
            tstate->curexc_type = 0;
            tstate->curexc_value = 0;
            tstate->curexc_traceback = 0;
            Py_DECREF(exc_type);
            Py_XDECREF(exc_value);
            Py_XDECREF(exc_tb);
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#else
    if (unlikely(PyErr_Occurred())) {
        if (likely(PyErr_ExceptionMatches(PyExc_StopIteration))) {
            PyErr_Clear();
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#endif
}

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

/* PyObjectGetMethod */
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}

/* PyObjectCallMethod0 */
static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name) {
    PyObject *method = NULL, *result = NULL;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_CallOneArg(method, obj);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) goto bad;
    result = __Pyx_PyObject_CallNoArg(method);
    Py_DECREF(method);
bad:
    return result;
}

/* RaiseNeedMoreValuesToUnpack */
static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
    PyErr_Format(PyExc_ValueError,
                 "need more than %" CYTHON_FORMAT_SSIZE_T "d value%.1s to unpack",
                 index, (index == 1) ? "" : "s");
}

/* RaiseTooManyValuesToUnpack */
static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected) {
    PyErr_Format(PyExc_ValueError,
                 "too many values to unpack (expected %" CYTHON_FORMAT_SSIZE_T "d)", expected);
}

/* UnpackItemEndCheck */
static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected) {
    if (unlikely(retval)) {
        Py_DECREF(retval);
        __Pyx_RaiseTooManyValuesError(expected);
        return -1;
    } else {
        return __Pyx_IterFinish();
    }
    return 0;
}

/* RaiseNoneIterError */
static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
}

/* UnpackTupleError */
static void __Pyx_UnpackTupleError(PyObject *t, Py_ssize_t index) {
    if (t == Py_None) {
      __Pyx_RaiseNoneNotIterableError();
    } else if (PyTuple_GET_SIZE(t) < index) {
      __Pyx_RaiseNeedMoreValuesError(PyTuple_GET_SIZE(t));
    } else {
      __Pyx_RaiseTooManyValuesError(index);
    }
}

/* UnpackTuple2 */
static CYTHON_INLINE int __Pyx_unpack_tuple2_exact(
        PyObject* tuple, PyObject** pvalue1, PyObject** pvalue2, int decref_tuple) {
    PyObject *value1 = NULL, *value2 = NULL;
#if CYTHON_COMPILING_IN_PYPY
    value1 = PySequence_ITEM(tuple, 0);  if (unlikely(!value1)) goto bad;
    value2 = PySequence_ITEM(tuple, 1);  if (unlikely(!value2)) goto bad;
#else
    value1 = PyTuple_GET_ITEM(tuple, 0);  Py_INCREF(value1);
    value2 = PyTuple_GET_ITEM(tuple, 1);  Py_INCREF(value2);
#endif
    if (decref_tuple) {
        Py_DECREF(tuple);
    }
    *pvalue1 = value1;
    *pvalue2 = value2;
    return 0;
#if CYTHON_COMPILING_IN_PYPY
bad:
    Py_XDECREF(value1);
    Py_XDECREF(value2);
    if (decref_tuple) { Py_XDECREF(tuple); }
    return -1;
#endif
}
static int __Pyx_unpack_tuple2_generic(PyObject* tuple, PyObject** pvalue1, PyObject** pvalue2,
                                       int has_known_size, int decref_tuple) {
    Py_ssize_t index;
    PyObject *value1 = NULL, *value2 = NULL, *iter = NULL;
    iternextfunc iternext;
    iter = PyObject_GetIter(tuple);
    if (unlikely(!iter)) goto bad;
    if (decref_tuple) { Py_DECREF(tuple); tuple = NULL; }
    iternext = Py_TYPE(iter)->tp_iternext;
    value1 = iternext(iter); if (unlikely(!value1)) { index = 0; goto unpacking_failed; }
    value2 = iternext(iter); if (unlikely(!value2)) { index = 1; goto unpacking_failed; }
    if (!has_known_size && unlikely(__Pyx_IternextUnpackEndCheck(iternext(iter), 2))) goto bad;
    Py_DECREF(iter);
    *pvalue1 = value1;
    *pvalue2 = value2;
    return 0;
unpacking_failed:
    if (!has_known_size && __Pyx_IterFinish() == 0)
        __Pyx_RaiseNeedMoreValuesError(index);
bad:
    Py_XDECREF(iter);
    Py_XDECREF(value1);
    Py_XDECREF(value2);
    if (decref_tuple) { Py_XDECREF(tuple); }
    return -1;
}

/* dict_iter */
static CYTHON_INLINE PyObject* __Pyx_dict_iterator(PyObject* iterable, int is_dict, PyObject* method_name,
                                                   Py_ssize_t* p_orig_length, int* p_source_is_dict) {
    is_dict = is_dict || likely(PyDict_CheckExact(iterable));
    *p_source_is_dict = is_dict;
    if (is_dict) {
#if !CYTHON_COMPILING_IN_PYPY
        *p_orig_length = PyDict_Size(iterable);
        Py_INCREF(iterable);
        return iterable;
#elif PY_MAJOR_VERSION >= 3
        static PyObject *py_items = NULL, *py_keys = NULL, *py_values = NULL;
        PyObject **pp = NULL;
        if (method_name) {
            const char *name = PyUnicode_AsUTF8(method_name);
            if (strcmp(name, "iteritems") == 0) pp = &py_items;
            else if (strcmp(name, "iterkeys") == 0) pp = &py_keys;
            else if (strcmp(name, "itervalues") == 0) pp = &py_values;
            if (pp) {
                if (!*pp) {
                    *pp = PyUnicode_FromString(name + 4);
                    if (!*pp)
                        return NULL;
                }
                method_name = *pp;
            }
        }
#endif
    }
    *p_orig_length = 0;
    if (method_name) {
        PyObject* iter;
        iterable = __Pyx_PyObject_CallMethod0(iterable, method_name);
        if (!iterable)
            return NULL;
#if !CYTHON_COMPILING_IN_PYPY
        if (PyTuple_CheckExact(iterable) || PyList_CheckExact(iterable))
            return iterable;
#endif
        iter = PyObject_GetIter(iterable);
        Py_DECREF(iterable);
        return iter;
    }
    return PyObject_GetIter(iterable);
}
static CYTHON_INLINE int __Pyx_dict_iter_next(
        PyObject* iter_obj, CYTHON_NCP_UNUSED Py_ssize_t orig_length, CYTHON_NCP_UNUSED Py_ssize_t* ppos,
        PyObject** pkey, PyObject** pvalue, PyObject** pitem, int source_is_dict) {
    PyObject* next_item;
#if !CYTHON_COMPILING_IN_PYPY
    if (source_is_dict) {
        PyObject *key, *value;
        if (unlikely(orig_length != PyDict_Size(iter_obj))) {
            PyErr_SetString(PyExc_RuntimeError, "dictionary changed size during iteration");
            return -1;
        }
        if (unlikely(!PyDict_Next(iter_obj, ppos, &key, &value))) {
            return 0;
        }
        if (pitem) {
            PyObject* tuple = PyTuple_New(2);
            if (unlikely(!tuple)) {
                return -1;
            }
            Py_INCREF(key);
            Py_INCREF(value);
            PyTuple_SET_ITEM(tuple, 0, key);
            PyTuple_SET_ITEM(tuple, 1, value);
            *pitem = tuple;
        } else {
            if (pkey) {
                Py_INCREF(key);
                *pkey = key;
            }
            if (pvalue) {
                Py_INCREF(value);
                *pvalue = value;
            }
        }
        return 1;
    } else if (PyTuple_CheckExact(iter_obj)) {
        Py_ssize_t pos = *ppos;
        if (unlikely(pos >= PyTuple_GET_SIZE(iter_obj))) return 0;
        *ppos = pos + 1;
        next_item = PyTuple_GET_ITEM(iter_obj, pos);
        Py_INCREF(next_item);
    } else if (PyList_CheckExact(iter_obj)) {
        Py_ssize_t pos = *ppos;
        if (unlikely(pos >= PyList_GET_SIZE(iter_obj))) return 0;
        *ppos = pos + 1;
        next_item = PyList_GET_ITEM(iter_obj, pos);
        Py_INCREF(next_item);
    } else
#endif
    {
        next_item = PyIter_Next(iter_obj);
        if (unlikely(!next_item)) {
            return __Pyx_IterFinish();
        }
    }
    if (pitem) {
        *pitem = next_item;
    } else if (pkey && pvalue) {
        if (__Pyx_unpack_tuple2(next_item, pkey, pvalue, source_is_dict, source_is_dict, 1))
            return -1;
    } else if (pkey) {
        *pkey = next_item;
    } else {
        *pvalue = next_item;
    }
    return 1;
}

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

/* SetItemInt */
static int __Pyx_SetItemInt_Generic(PyObject *o, PyObject *j, PyObject *v) {
    int r;
    if (!j) return -1;
    r = PyObject_SetItem(o, j, v);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE int __Pyx_SetItemInt_Fast(PyObject *o, Py_ssize_t i, PyObject *v, int is_list,
                                               CYTHON_NCP_UNUSED int wraparound, CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = (!wraparound) ? i : ((likely(i >= 0)) ? i : i + PyList_GET_SIZE(o));
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o)))) {
            PyObject* old = PyList_GET_ITEM(o, n);
            Py_INCREF(v);
            PyList_SET_ITEM(o, n, v);
            Py_DECREF(old);
            return 1;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_ass_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return -1;
                    PyErr_Clear();
                }
            }
            return m->sq_ass_item(o, i, v);
        }
    }
#else
#if CYTHON_COMPILING_IN_PYPY
    if (is_list || (PySequence_Check(o) && !PyDict_Check(o)))
#else
    if (is_list || PySequence_Check(o))
#endif
    {
        return PySequence_SetItem(o, i, v);
    }
#endif
    return __Pyx_SetItemInt_Generic(o, PyInt_FromSsize_t(i), v);
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

/* Globals */
static PyObject* __Pyx_Globals(void) {
    Py_ssize_t i;
    PyObject *names;
    PyObject *globals = __pyx_d;
    Py_INCREF(globals);
    names = PyObject_Dir(__pyx_m);
    if (!names)
        goto bad;
    for (i = PyList_GET_SIZE(names)-1; i >= 0; i--) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject* name = PySequence_ITEM(names, i);
        if (!name)
            goto bad;
#else
        PyObject* name = PyList_GET_ITEM(names, i);
#endif
        if (!PyDict_Contains(globals, name)) {
            PyObject* value = __Pyx_GetAttr(__pyx_m, name);
            if (!value) {
#if CYTHON_COMPILING_IN_PYPY
                Py_DECREF(name);
#endif
                goto bad;
            }
            if (PyDict_SetItem(globals, name, value) < 0) {
#if CYTHON_COMPILING_IN_PYPY
                Py_DECREF(name);
#endif
                Py_DECREF(value);
                goto bad;
            }
        }
#if CYTHON_COMPILING_IN_PYPY
        Py_DECREF(name);
#endif
    }
    Py_DECREF(names);
    return globals;
bad:
    Py_XDECREF(names);
    Py_XDECREF(globals);
    return NULL;
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
