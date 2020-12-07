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

#define __PYX_HAVE__trans
#define __PYX_HAVE_API__trans
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
  "trans.py",
};

/*--- Type declarations ---*/
struct __pyx_obj_5trans___pyx_scope_struct__transform;
struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr;
struct __pyx_obj_5trans___pyx_scope_struct_2_transform;
struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform;
struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr;
struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr;
struct __pyx_obj_5trans___pyx_scope_struct_6_transform;
struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr;
struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr;

/* "trans.py":111
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         missing = ['', None]
 *         for y in X.columns:
 */
struct __pyx_obj_5trans___pyx_scope_struct__transform {
  PyObject_HEAD
  PyObject *__pyx_v_X;
  PyObject *__pyx_v_missing;
  PyObject *__pyx_v_y;
};


/* "trans.py":114
 *         missing = ['', None]
 *         for y in X.columns:
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.             # <<<<<<<<<<<<<<
 *         return X
 *
 */
struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr {
  PyObject_HEAD
  struct __pyx_obj_5trans___pyx_scope_struct__transform *__pyx_outer_scope;
  PyObject *__pyx_v_z;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
  PyObject *(*__pyx_t_2)(PyObject *);
};


/* "trans.py":202
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)
 *
 */
struct __pyx_obj_5trans___pyx_scope_struct_2_transform {
  PyObject_HEAD
  PyObject *__pyx_v_self;
};


/* "trans.py":242
 * class PandasFeatureUnion(FeatureUnion):
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 */
struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform {
  PyObject_HEAD
  PyObject *__pyx_v_X;
  PyObject *__pyx_v_Xs;
  PyObject *__pyx_v_fit_params;
  PyObject *__pyx_v_self;
  PyObject *__pyx_v_y;
};


/* "trans.py":245
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr {
  PyObject_HEAD
  struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *__pyx_outer_scope;
  PyObject *__pyx_v_name;
  PyObject *__pyx_v_trans;
  PyObject *__pyx_v_weight;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
  PyObject *(*__pyx_t_2)(PyObject *);
};


/* "trans.py":258
 *         Xs, transformers = zip(*result)
 *         self._update_transformer_list(transformers)
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */
struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr {
  PyObject_HEAD
  struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *__pyx_outer_scope;
  PyObject *__pyx_v_f;
};


/* "trans.py":267
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(
 */
struct __pyx_obj_5trans___pyx_scope_struct_6_transform {
  PyObject_HEAD
  PyObject *__pyx_v_X;
  PyObject *__pyx_v_Xs;
  PyObject *__pyx_v_self;
};


/* "trans.py":269
 *     def transform(self, X):
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr {
  PyObject_HEAD
  struct __pyx_obj_5trans___pyx_scope_struct_6_transform *__pyx_outer_scope;
  PyObject *__pyx_v_name;
  PyObject *__pyx_v_trans;
  PyObject *__pyx_v_weight;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
  PyObject *(*__pyx_t_2)(PyObject *);
};


/* "trans.py":278
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */
struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr {
  PyObject_HEAD
  struct __pyx_obj_5trans___pyx_scope_struct_6_transform *__pyx_outer_scope;
  PyObject *__pyx_v_f;
};


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

/* RaiseDoubleKeywords.proto */
static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);

/* ParseKeywords.proto */
static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);

/* RaiseArgTupleInvalid.proto */
static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);

/* PyObjectSetAttrStr.proto */
#if CYTHON_USE_TYPE_SLOTS
#define __Pyx_PyObject_DelAttrStr(o,n) __Pyx_PyObject_SetAttrStr(o, n, NULL)
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value);
#else
#define __Pyx_PyObject_DelAttrStr(o,n)   PyObject_DelAttr(o,n)
#define __Pyx_PyObject_SetAttrStr(o,n,v) PyObject_SetAttr(o,n,v)
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

/* ArgTypeTest.proto */
#define __Pyx_ArgTypeTest(obj, type, none_allowed, name, exact)\
    ((likely((Py_TYPE(obj) == type) | (none_allowed && (obj == Py_None)))) ? 1 :\
        __Pyx__ArgTypeTest(obj, type, name, exact))
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact);

/* PyObjectCall.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif

/* None.proto */
static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname);

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

/* PyObjectCall2Args.proto */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);

/* PySequenceContains.proto */
static CYTHON_INLINE int __Pyx_PySequence_ContainsTF(PyObject* item, PyObject* seq, int eq) {
    int result = PySequence_Contains(seq, item);
    return unlikely(result < 0) ? result : (result == (eq == Py_EQ));
}

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

/* PyIntCompare.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_NeObjC(PyObject *op1, PyObject *op2, long intval, long inplace);

/* RaiseTooManyValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected);

/* RaiseNeedMoreValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index);

/* IterFinish.proto */
static CYTHON_INLINE int __Pyx_IterFinish(void);

/* UnpackItemEndCheck.proto */
static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected);

/* PyObjectGetMethod.proto */
static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);

/* PyObjectCallMethod0.proto */
static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name);

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

/* MergeKeywords.proto */
static int __Pyx_MergeKeywords(PyObject *kwdict, PyObject *source_mapping);

/* IncludeStringH.proto */
#include <string.h>

/* PyObject_GenericGetAttrNoDict.proto */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttrNoDict PyObject_GenericGetAttr
#endif

/* Import.proto */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);

/* ImportFrom.proto */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);

/* CalculateMetaclass.proto */
static PyObject *__Pyx_CalculateMetaclass(PyTypeObject *metaclass, PyObject *bases);

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

/* RaiseException.proto */
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);

/* GetTopmostException.proto */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif

/* SaveResetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif

/* SwapException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif

/* PyObjectCallMethod1.proto */
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);

/* CoroutineBase.proto */
typedef PyObject *(*__pyx_coroutine_body_t)(PyObject *, PyThreadState *, PyObject *);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_ExcInfoStruct  _PyErr_StackItem
#else
typedef struct {
    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;
} __Pyx_ExcInfoStruct;
#endif
typedef struct {
    PyObject_HEAD
    __pyx_coroutine_body_t body;
    PyObject *closure;
    __Pyx_ExcInfoStruct gi_exc_state;
    PyObject *gi_weakreflist;
    PyObject *classobj;
    PyObject *yieldfrom;
    PyObject *gi_name;
    PyObject *gi_qualname;
    PyObject *gi_modulename;
    PyObject *gi_code;
    int resume_label;
    char is_running;
} __pyx_CoroutineObject;
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
    PyTypeObject *type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
    PyObject *name, PyObject *qualname, PyObject *module_name);
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name);
static CYTHON_INLINE void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *self);
static int __Pyx_Coroutine_clear(PyObject *self);
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value);
static PyObject *__Pyx_Coroutine_Close(PyObject *self);
static PyObject *__Pyx_Coroutine_Throw(PyObject *gen, PyObject *args);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_Coroutine_SwapException(self)
#define __Pyx_Coroutine_ResetAndClearException(self)  __Pyx_Coroutine_ExceptionClear(&(self)->gi_exc_state)
#else
#define __Pyx_Coroutine_SwapException(self) {\
    __Pyx_ExceptionSwap(&(self)->gi_exc_state.exc_type, &(self)->gi_exc_state.exc_value, &(self)->gi_exc_state.exc_traceback);\
    __Pyx_Coroutine_ResetFrameBackpointer(&(self)->gi_exc_state);\
    }
#define __Pyx_Coroutine_ResetAndClearException(self) {\
    __Pyx_ExceptionReset((self)->gi_exc_state.exc_type, (self)->gi_exc_state.exc_value, (self)->gi_exc_state.exc_traceback);\
    (self)->gi_exc_state.exc_type = (self)->gi_exc_state.exc_value = (self)->gi_exc_state.exc_traceback = NULL;\
    }
#endif
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__pyx_tstate, pvalue)
#else
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, pvalue)
#endif
static int __Pyx_PyGen__FetchStopIterationValue(PyThreadState *tstate, PyObject **pvalue);
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state);

/* PatchModuleWithCoroutine.proto */
static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code);

/* PatchGeneratorABC.proto */
static int __Pyx_patch_abc(void);

/* Generator.proto */
#define __Pyx_Generator_USED
static PyTypeObject *__pyx_GeneratorType = 0;
#define __Pyx_Generator_CheckExact(obj) (Py_TYPE(obj) == __pyx_GeneratorType)
#define __Pyx_Generator_New(body, code, closure, name, qualname, module_name)\
    __Pyx__Coroutine_New(__pyx_GeneratorType, body, code, closure, name, qualname, module_name)
static PyObject *__Pyx_Generator_Next(PyObject *self);
static int __pyx_Generator_init(void);

/* CheckBinaryVersion.proto */
static int __Pyx_check_binary_version(void);

/* InitStrings.proto */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);


/* Module declarations from 'trans' */
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct__transform = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_1_genexpr = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_2_transform = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_3_fit_transform = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_4_genexpr = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_5_genexpr = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_6_transform = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_7_genexpr = 0;
static PyTypeObject *__pyx_ptype_5trans___pyx_scope_struct_8_genexpr = 0;
#define __Pyx_MODULE_NAME "trans"
extern int __pyx_module_is_main_trans;
int __pyx_module_is_main_trans = 0;

/* Implementation of 'trans' */
static PyObject *__pyx_builtin_zip;
static PyObject *__pyx_builtin_super;
static const char __pyx_k_[] = " ";
static const char __pyx_k_X[] = "X";
static const char __pyx_k_a[] = "a";
static const char __pyx_k_b[] = "b";
static const char __pyx_k_x[] = "x";
static const char __pyx_k_y[] = "y";
static const char __pyx_k_Xs[] = "Xs";
static const char __pyx_k__2[] = "";
static const char __pyx_k__4[] = ",";
static const char __pyx_k_fn[] = "fn";
static const char __pyx_k_np[] = "np";
static const char __pyx_k_pd[] = "pd";
static const char __pyx_k_Wat[] = "Wat";
static const char __pyx_k_ann[] = "ann";
static const char __pyx_k_col[] = "col";
static const char __pyx_k_doc[] = "__doc__";
static const char __pyx_k_fit[] = "fit";
static const char __pyx_k_fun[] = "fun";
static const char __pyx_k_key[] = "key";
static const char __pyx_k_loc[] = "loc";
static const char __pyx_k_max[] = "max";
static const char __pyx_k_min[] = "min";
static const char __pyx_k_raw[] = "raw";
static const char __pyx_k_sys[] = "sys";
static const char __pyx_k_zip[] = "zip";
static const char __pyx_k_args[] = "args";
static const char __pyx_k_axis[] = "axis";
static const char __pyx_k_copy[] = "copy";
static const char __pyx_k_drop[] = "drop";
static const char __pyx_k_init[] = "__init__";
static const char __pyx_k_iter[] = "_iter";
static const char __pyx_k_keys[] = "keys";
static const char __pyx_k_list[] = "list";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_mean[] = "mean";
static const char __pyx_k_mode[] = "mode";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_self[] = "self";
static const char __pyx_k_send[] = "send";
static const char __pyx_k_tar1[] = "tar1";
static const char __pyx_k_tar2[] = "tar2";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_0_0_1[] = "0.0.1";
static const char __pyx_k_apply[] = "apply";
static const char __pyx_k_close[] = "close";
static const char __pyx_k_count[] = "count";
static const char __pyx_k_feats[] = "feats";
static const char __pyx_k_items[] = "items";
static const char __pyx_k_numpy[] = "numpy";
static const char __pyx_k_scipy[] = "scipy";
static const char __pyx_k_shape[] = "shape";
static const char __pyx_k_split[] = "split";
static const char __pyx_k_super[] = "super";
static const char __pyx_k_throw[] = "throw";
static const char __pyx_k_tocsr[] = "tocsr";
static const char __pyx_k_trans[] = "trans";
static const char __pyx_k_words[] = "words";
static const char __pyx_k_zeros[] = "zeros";
static const char __pyx_k_concat[] = "concat";
static const char __pyx_k_divide[] = "divide";
static const char __pyx_k_hstack[] = "hstack";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_joblib[] = "joblib";
static const char __pyx_k_kwargs[] = "kwargs";
static const char __pyx_k_module[] = "__module__";
static const char __pyx_k_n_jobs[] = "n_jobs";
static const char __pyx_k_pandas[] = "pandas";
static const char __pyx_k_result[] = "result";
static const char __pyx_k_sparse[] = "sparse";
static const char __pyx_k_target[] = "target";
static const char __pyx_k_weight[] = "weight";
static const char __pyx_k_Wat_fit[] = "Wat.fit";
static const char __pyx_k_columns[] = "columns";
static const char __pyx_k_delayed[] = "delayed";
static const char __pyx_k_english[] = "english";
static const char __pyx_k_genexpr[] = "genexpr";
static const char __pyx_k_missing[] = "missing";
static const char __pyx_k_options[] = "options";
static const char __pyx_k_predict[] = "predict";
static const char __pyx_k_prepare[] = "__prepare__";
static const char __pyx_k_replace[] = "replace";
static const char __pyx_k_sen_len[] = "sen_len";
static const char __pyx_k_targets[] = "targets";
static const char __pyx_k_todense[] = "todense";
static const char __pyx_k_version[] = "__version__";
static const char __pyx_k_Parallel[] = "Parallel";
static const char __pyx_k_issparse[] = "issparse";
static const char __pyx_k_qualname[] = "__qualname__";
static const char __pyx_k_trans_py[] = "trans.py";
static const char __pyx_k_metaclass[] = "__metaclass__";
static const char __pyx_k_not_stops[] = "not_stops";
static const char __pyx_k_stopwords[] = "stopwords_";
static const char __pyx_k_transform[] = "transform";
static const char __pyx_k_CountWords[] = "CountWords";
static const char __pyx_k_Wat___init[] = "Wat.__init__";
static const char __pyx_k_fit_params[] = "fit_params";
static const char __pyx_k_CountCommas[] = "CountCommas";
static const char __pyx_k_MissingData[] = "MissingData";
static const char __pyx_k_count_words[] = "count_words";
static const char __pyx_k_nltk_corpus[] = "nltk.corpus";
static const char __pyx_k_stopwords_2[] = "stopwords";
static const char __pyx_k_transformer[] = "transformer";
static const char __pyx_k_DropFeatures[] = "DropFeatures";
static const char __pyx_k_FeatureUnion[] = "FeatureUnion";
static const char __pyx_k_TextSelector[] = "TextSelector";
static const char __pyx_k_avg_word_len[] = "avg_word_len";
static const char __pyx_k_count_commas[] = "count_commas";
static const char __pyx_k_sklearn_base[] = "sklearn.base";
static const char __pyx_k_transformers[] = "transformers";
static const char __pyx_k_BaseEstimator[] = "BaseEstimator";
static const char __pyx_k_CommaLenRatio[] = "CommaLenRatio";
static const char __pyx_k_NNTransformer[] = "NNTransformer";
static const char __pyx_k_TestTransform[] = "TestTransform";
static const char __pyx_k_Wat_transform[] = "Wat.transform";
static const char __pyx_k_fit_transform[] = "fit_transform";
static const char __pyx_k_transform_one[] = "_transform_one";
static const char __pyx_k_BooleanTargets[] = "BooleanTargets";
static const char __pyx_k_ConvertTargets[] = "ConvertTargets";
static const char __pyx_k_CountWords_fit[] = "CountWords.fit";
static const char __pyx_k_NumberSelector[] = "NumberSelector";
static const char __pyx_k_SentenceLength[] = "SentenceLength";
static const char __pyx_k_ClassifierMixin[] = "ClassifierMixin";
static const char __pyx_k_CountCommas_fit[] = "CountCommas.fit";
static const char __pyx_k_CountVectorizer[] = "CountVectorizer";
static const char __pyx_k_FeatureSelector[] = "FeatureSelector";
static const char __pyx_k_MissingData_fit[] = "MissingData.fit";
static const char __pyx_k_comma_len_ratio[] = "comma_len_ratio";
static const char __pyx_k_DenseTransformer[] = "DenseTransformer";
static const char __pyx_k_DropFeatures_fit[] = "DropFeatures.fit";
static const char __pyx_k_TextSelector_fit[] = "TextSelector.fit";
static const char __pyx_k_TransformerMixin[] = "TransformerMixin";
static const char __pyx_k_sklearn_pipeline[] = "sklearn.pipeline";
static const char __pyx_k_CommaLenRatio_fit[] = "CommaLenRatio.fit";
static const char __pyx_k_CountWords___init[] = "CountWords.__init__";
static const char __pyx_k_NNTransformer_fit[] = "NNTransformer.fit";
static const char __pyx_k_PandasTransformer[] = "PandasTransformer";
static const char __pyx_k_TestTransform_fit[] = "TestTransform.fit";
static const char __pyx_k_TestTransform_fun[] = "TestTransform.fun";
static const char __pyx_k_TextSelectorMulti[] = "TextSelectorMulti";
static const char __pyx_k_fit_transform_one[] = "_fit_transform_one";
static const char __pyx_k_BooleanTargets_fit[] = "BooleanTargets.fit";
static const char __pyx_k_ConvertTargets_fit[] = "ConvertTargets.fit";
static const char __pyx_k_CountCommas___init[] = "CountCommas.__init__";
static const char __pyx_k_MissingData___init[] = "MissingData.__init__";
static const char __pyx_k_NumberSelector_fit[] = "NumberSelector.fit";
static const char __pyx_k_PandasFeatureUnion[] = "PandasFeatureUnion";
static const char __pyx_k_SentenceLength_fit[] = "SentenceLength.fit";
static const char __pyx_k_chained_assignment[] = "chained_assignment";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_ConvertListToSeries[] = "ConvertListToSeries";
static const char __pyx_k_DropFeatures___init[] = "DropFeatures.__init__";
static const char __pyx_k_FeatureSelector_fit[] = "FeatureSelector.fit";
static const char __pyx_k_NotStopsTransformer[] = "NotStopsTransformer";
static const char __pyx_k_TextSelector___init[] = "TextSelector.__init__";
static const char __pyx_k_TransformerTemplate[] = "TransformerTemplate";
static const char __pyx_k_WordVectorTransform[] = "WordVectorTransform";
static const char __pyx_k_CommaLenRatio___init[] = "CommaLenRatio.__init__";
static const char __pyx_k_CommaLenRatio_divide[] = "CommaLenRatio.divide";
static const char __pyx_k_CountWords_transform[] = "CountWords.transform";
static const char __pyx_k_DenseTransformer_fit[] = "DenseTransformer.fit";
static const char __pyx_k_NNTransformer___init[] = "NNTransformer.__init__";
static const char __pyx_k_TestTransform___init[] = "TestTransform.__init__";
static const char __pyx_k_AvgWordLenTransformer[] = "AvgWordLenTransformer";
static const char __pyx_k_BooleanTargets___init[] = "BooleanTargets.__init__";
static const char __pyx_k_ConvertTargets___init[] = "ConvertTargets.__init__";
static const char __pyx_k_CountCommas_transform[] = "CountCommas.transform";
static const char __pyx_k_MissingData_transform[] = "MissingData.transform";
static const char __pyx_k_NumberSelector___init[] = "NumberSelector.__init__";
static const char __pyx_k_PandasTransformer_fit[] = "PandasTransformer.fit";
static const char __pyx_k_SentenceLength___init[] = "SentenceLength.__init__";
static const char __pyx_k_TextSelectorMulti_fit[] = "TextSelectorMulti.fit";
static const char __pyx_k_validate_transformers[] = "_validate_transformers";
static const char __pyx_k_DropFeatures_transform[] = "DropFeatures.transform";
static const char __pyx_k_FeatureSelector___init[] = "FeatureSelector.__init__";
static const char __pyx_k_TextSelector_transform[] = "TextSelector.transform";
static const char __pyx_k_CommaLenRatio_transform[] = "CommaLenRatio.transform";
static const char __pyx_k_NNTransformer_transform[] = "NNTransformer.transform";
static const char __pyx_k_NotStopsTransformer_fit[] = "NotStopsTransformer.fit";
static const char __pyx_k_TestTransform_transform[] = "TestTransform.transform";
static const char __pyx_k_TransformerTemplate_fit[] = "TransformerTemplate.fit";
static const char __pyx_k_update_transformer_list[] = "_update_transformer_list";
static const char __pyx_k_BooleanTargets_transform[] = "BooleanTargets.transform";
static const char __pyx_k_ConvertTargets_transform[] = "ConvertTargets.transform";
static const char __pyx_k_NumberSelector_transform[] = "NumberSelector.transform";
static const char __pyx_k_PandasTransformer___init[] = "PandasTransformer.__init__";
static const char __pyx_k_SentenceLength_transform[] = "SentenceLength.transform";
static const char __pyx_k_TextSelectorMulti___init[] = "TextSelectorMulti.__init__";
static const char __pyx_k_AvgWordLenTransformer_fit[] = "AvgWordLenTransformer.fit";
static const char __pyx_k_FeatureSelector_transform[] = "FeatureSelector.transform";
static const char __pyx_k_DenseTransformer_transform[] = "DenseTransformer.transform";
static const char __pyx_k_NotStopsTransformer___init[] = "NotStopsTransformer.__init__";
static const char __pyx_k_TransformerTemplate___init[] = "TransformerTemplate.__init__";
static const char __pyx_k_WordVectorTransform___init[] = "WordVectorTransform.__init__";
static const char __pyx_k_merge_dataframes_by_column[] = "merge_dataframes_by_column";
static const char __pyx_k_PandasTransformer_transform[] = "PandasTransformer.transform";
static const char __pyx_k_TextSelectorMulti_transform[] = "TextSelectorMulti.transform";
static const char __pyx_k_AvgWordLenTransformer___init[] = "AvgWordLenTransformer.__init__";
static const char __pyx_k_Convert_a_list_to_series_t_k[] = " Convert a list to series. t/k ";
static const char __pyx_k_Count_words_in_a_text_series[] = " Count words in a text series. ";
static const char __pyx_k_PandasFeatureUnion_transform[] = "PandasFeatureUnion.transform";
static const char __pyx_k_Count_commas_in_a_text_series[] = " Count commas in a text series. ";
static const char __pyx_k_NotStopsTransformer_transform[] = "NotStopsTransformer.transform";
static const char __pyx_k_TransformerTemplate_transform[] = "TransformerTemplate.transform";
static const char __pyx_k_Converts_binary_classification[] = " Converts binary classification labels to boolean values. (In place, does not add new column.) ";
static const char __pyx_k_Select_a_single_numeric_column[] = " Select a single numeric column from the data frame on which to perform transformations. ";
static const char __pyx_k_AvgWordLenTransformer_transform[] = "AvgWordLenTransformer.transform.<locals>.<lambda>";
static const char __pyx_k_Convert_target_categories_to_in[] = " Convert target categories to int. ";
static const char __pyx_k_Drop_any_features_passed_via_se[] = " Drop any features passed via set_params. ";
static const char __pyx_k_Examines_dataset_for_missing_va[] = " Examines dataset for missing values, smh. ";
static const char __pyx_k_Hard_coded_experimental_feature[] = " Hard-coded experimental feature. N.B. This is an entropy source. ";
static const char __pyx_k_Neural_Network_tranformation_pi[] = " Neural Network tranformation pipe ";
static const char __pyx_k_Non_stop_words_in_a_text_series[] = " Non-stop words in a text series. ";
static const char __pyx_k_Select_a_single_text_column_fro[] = " Select a single text column from the data frame on which to perform transformations. ";
static const char __pyx_k_Select_multiple_text_columns_fr[] = " Select multiple text columns from the data frame on which to perform transformations. ";
static const char __pyx_k_Select_only_the_features_passed[] = " Select only the features passed via set_params. ";
static const char __pyx_k_SentenceLength_transform_locals[] = "SentenceLength.transform.<locals>.<lambda>";
static const char __pyx_k_TODO_cleanup_non_overridden_met[] = " @TODO: cleanup non-overridden methods with .super() ";
static const char __pyx_k_Transformer_to_calculate_averag[] = " Transformer to calculate average word length. ";
static const char __pyx_k_Wrapper_for_vector_functions_to[] = " Wrapper for vector functions to handle DataFrames. ";
static const char __pyx_k_sklearn_feature_extraction_text[] = "sklearn.feature_extraction.text";
static const char __pyx_k_A_template_for_a_custom_transfor[] = "A template for a custom transformer. (TransformerMixin is for .fit_transform method.) ";
static const char __pyx_k_CommaLenRatio_transform_locals_l[] = "CommaLenRatio.transform.<locals>.<lambda>";
static const char __pyx_k_CountCommas_transform_locals_lam[] = "CountCommas.transform.<locals>.<lambda>";
static const char __pyx_k_CountWords_transform_locals_lamb[] = "CountWords.transform.<locals>.<lambda>";
static const char __pyx_k_MissingData_transform_locals_gen[] = "MissingData.transform.<locals>.genexpr";
static const char __pyx_k_NotStopsTransformer_transform_lo[] = "NotStopsTransformer.transform.<locals>.<lambda>";
static const char __pyx_k_PandasFeatureUnion_fit_transform[] = "PandasFeatureUnion.fit_transform.<locals>.genexpr";
static const char __pyx_k_PandasFeatureUnion_merge_datafra[] = "PandasFeatureUnion.merge_dataframes_by_column";
static const char __pyx_k_PandasFeatureUnion_transform_loc[] = "PandasFeatureUnion.transform.<locals>.genexpr";
static const char __pyx_k_AvgWordLenTransformer_transform_2[] = "AvgWordLenTransformer.transform";
static const char __pyx_k_MissingData_transform_locals_gen_2[] = "MissingData.transform.<locals>.genexpr.<locals>.<lambda>";
static const char __pyx_k_PandasFeatureUnion_fit_transform_2[] = "PandasFeatureUnion.fit_transform";
static PyObject *__pyx_kp_u_;
static PyObject *__pyx_kp_u_0_0_1;
static PyObject *__pyx_kp_s_A_template_for_a_custom_transfor;
static PyObject *__pyx_n_s_AvgWordLenTransformer;
static PyObject *__pyx_n_s_AvgWordLenTransformer___init;
static PyObject *__pyx_n_s_AvgWordLenTransformer_fit;
static PyObject *__pyx_n_s_AvgWordLenTransformer_transform;
static PyObject *__pyx_n_s_AvgWordLenTransformer_transform_2;
static PyObject *__pyx_n_s_BaseEstimator;
static PyObject *__pyx_n_s_BooleanTargets;
static PyObject *__pyx_n_s_BooleanTargets___init;
static PyObject *__pyx_n_s_BooleanTargets_fit;
static PyObject *__pyx_n_s_BooleanTargets_transform;
static PyObject *__pyx_n_s_ClassifierMixin;
static PyObject *__pyx_n_s_CommaLenRatio;
static PyObject *__pyx_n_s_CommaLenRatio___init;
static PyObject *__pyx_n_s_CommaLenRatio_divide;
static PyObject *__pyx_n_s_CommaLenRatio_fit;
static PyObject *__pyx_n_s_CommaLenRatio_transform;
static PyObject *__pyx_n_s_CommaLenRatio_transform_locals_l;
static PyObject *__pyx_n_s_ConvertListToSeries;
static PyObject *__pyx_n_s_ConvertTargets;
static PyObject *__pyx_n_s_ConvertTargets___init;
static PyObject *__pyx_n_s_ConvertTargets_fit;
static PyObject *__pyx_n_s_ConvertTargets_transform;
static PyObject *__pyx_kp_s_Convert_a_list_to_series_t_k;
static PyObject *__pyx_kp_s_Convert_target_categories_to_in;
static PyObject *__pyx_kp_s_Converts_binary_classification;
static PyObject *__pyx_n_s_CountCommas;
static PyObject *__pyx_n_s_CountCommas___init;
static PyObject *__pyx_n_s_CountCommas_fit;
static PyObject *__pyx_n_s_CountCommas_transform;
static PyObject *__pyx_n_s_CountCommas_transform_locals_lam;
static PyObject *__pyx_n_s_CountVectorizer;
static PyObject *__pyx_n_s_CountWords;
static PyObject *__pyx_n_s_CountWords___init;
static PyObject *__pyx_n_s_CountWords_fit;
static PyObject *__pyx_n_s_CountWords_transform;
static PyObject *__pyx_n_s_CountWords_transform_locals_lamb;
static PyObject *__pyx_kp_s_Count_commas_in_a_text_series;
static PyObject *__pyx_kp_s_Count_words_in_a_text_series;
static PyObject *__pyx_n_s_DenseTransformer;
static PyObject *__pyx_n_s_DenseTransformer_fit;
static PyObject *__pyx_n_s_DenseTransformer_transform;
static PyObject *__pyx_n_s_DropFeatures;
static PyObject *__pyx_n_s_DropFeatures___init;
static PyObject *__pyx_n_s_DropFeatures_fit;
static PyObject *__pyx_n_s_DropFeatures_transform;
static PyObject *__pyx_kp_s_Drop_any_features_passed_via_se;
static PyObject *__pyx_kp_s_Examines_dataset_for_missing_va;
static PyObject *__pyx_n_s_FeatureSelector;
static PyObject *__pyx_n_s_FeatureSelector___init;
static PyObject *__pyx_n_s_FeatureSelector_fit;
static PyObject *__pyx_n_s_FeatureSelector_transform;
static PyObject *__pyx_n_s_FeatureUnion;
static PyObject *__pyx_kp_s_Hard_coded_experimental_feature;
static PyObject *__pyx_n_s_MissingData;
static PyObject *__pyx_n_s_MissingData___init;
static PyObject *__pyx_n_s_MissingData_fit;
static PyObject *__pyx_n_s_MissingData_transform;
static PyObject *__pyx_n_s_MissingData_transform_locals_gen;
static PyObject *__pyx_n_s_MissingData_transform_locals_gen_2;
static PyObject *__pyx_n_s_NNTransformer;
static PyObject *__pyx_n_s_NNTransformer___init;
static PyObject *__pyx_n_s_NNTransformer_fit;
static PyObject *__pyx_n_s_NNTransformer_transform;
static PyObject *__pyx_kp_s_Neural_Network_tranformation_pi;
static PyObject *__pyx_kp_s_Non_stop_words_in_a_text_series;
static PyObject *__pyx_n_s_NotStopsTransformer;
static PyObject *__pyx_n_s_NotStopsTransformer___init;
static PyObject *__pyx_n_s_NotStopsTransformer_fit;
static PyObject *__pyx_n_s_NotStopsTransformer_transform;
static PyObject *__pyx_n_s_NotStopsTransformer_transform_lo;
static PyObject *__pyx_n_s_NumberSelector;
static PyObject *__pyx_n_s_NumberSelector___init;
static PyObject *__pyx_n_s_NumberSelector_fit;
static PyObject *__pyx_n_s_NumberSelector_transform;
static PyObject *__pyx_n_s_PandasFeatureUnion;
static PyObject *__pyx_n_s_PandasFeatureUnion_fit_transform;
static PyObject *__pyx_n_s_PandasFeatureUnion_fit_transform_2;
static PyObject *__pyx_n_s_PandasFeatureUnion_merge_datafra;
static PyObject *__pyx_n_s_PandasFeatureUnion_transform;
static PyObject *__pyx_n_s_PandasFeatureUnion_transform_loc;
static PyObject *__pyx_n_s_PandasTransformer;
static PyObject *__pyx_n_s_PandasTransformer___init;
static PyObject *__pyx_n_s_PandasTransformer_fit;
static PyObject *__pyx_n_s_PandasTransformer_transform;
static PyObject *__pyx_n_s_Parallel;
static PyObject *__pyx_kp_s_Select_a_single_numeric_column;
static PyObject *__pyx_kp_s_Select_a_single_text_column_fro;
static PyObject *__pyx_kp_s_Select_multiple_text_columns_fr;
static PyObject *__pyx_kp_s_Select_only_the_features_passed;
static PyObject *__pyx_n_s_SentenceLength;
static PyObject *__pyx_n_s_SentenceLength___init;
static PyObject *__pyx_n_s_SentenceLength_fit;
static PyObject *__pyx_n_s_SentenceLength_transform;
static PyObject *__pyx_n_s_SentenceLength_transform_locals;
static PyObject *__pyx_kp_s_TODO_cleanup_non_overridden_met;
static PyObject *__pyx_n_s_TestTransform;
static PyObject *__pyx_n_s_TestTransform___init;
static PyObject *__pyx_n_s_TestTransform_fit;
static PyObject *__pyx_n_s_TestTransform_fun;
static PyObject *__pyx_n_s_TestTransform_transform;
static PyObject *__pyx_n_s_TextSelector;
static PyObject *__pyx_n_s_TextSelectorMulti;
static PyObject *__pyx_n_s_TextSelectorMulti___init;
static PyObject *__pyx_n_s_TextSelectorMulti_fit;
static PyObject *__pyx_n_s_TextSelectorMulti_transform;
static PyObject *__pyx_n_s_TextSelector___init;
static PyObject *__pyx_n_s_TextSelector_fit;
static PyObject *__pyx_n_s_TextSelector_transform;
static PyObject *__pyx_n_s_TransformerMixin;
static PyObject *__pyx_n_s_TransformerTemplate;
static PyObject *__pyx_n_s_TransformerTemplate___init;
static PyObject *__pyx_n_s_TransformerTemplate_fit;
static PyObject *__pyx_n_s_TransformerTemplate_transform;
static PyObject *__pyx_kp_s_Transformer_to_calculate_averag;
static PyObject *__pyx_n_s_Wat;
static PyObject *__pyx_n_s_Wat___init;
static PyObject *__pyx_n_s_Wat_fit;
static PyObject *__pyx_n_s_Wat_transform;
static PyObject *__pyx_n_s_WordVectorTransform;
static PyObject *__pyx_n_s_WordVectorTransform___init;
static PyObject *__pyx_kp_s_Wrapper_for_vector_functions_to;
static PyObject *__pyx_n_s_X;
static PyObject *__pyx_n_s_Xs;
static PyObject *__pyx_kp_u__2;
static PyObject *__pyx_kp_u__4;
static PyObject *__pyx_n_s_a;
static PyObject *__pyx_n_s_ann;
static PyObject *__pyx_n_s_apply;
static PyObject *__pyx_n_s_args;
static PyObject *__pyx_n_u_avg_word_len;
static PyObject *__pyx_n_s_axis;
static PyObject *__pyx_n_s_b;
static PyObject *__pyx_n_s_chained_assignment;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_close;
static PyObject *__pyx_n_s_col;
static PyObject *__pyx_n_s_columns;
static PyObject *__pyx_n_u_columns;
static PyObject *__pyx_n_u_comma_len_ratio;
static PyObject *__pyx_n_s_concat;
static PyObject *__pyx_n_s_copy;
static PyObject *__pyx_n_s_count;
static PyObject *__pyx_n_u_count_commas;
static PyObject *__pyx_n_u_count_words;
static PyObject *__pyx_n_s_delayed;
static PyObject *__pyx_n_s_divide;
static PyObject *__pyx_n_s_doc;
static PyObject *__pyx_n_s_drop;
static PyObject *__pyx_n_u_english;
static PyObject *__pyx_n_s_feats;
static PyObject *__pyx_n_s_fit;
static PyObject *__pyx_n_s_fit_params;
static PyObject *__pyx_n_s_fit_transform;
static PyObject *__pyx_n_s_fit_transform_one;
static PyObject *__pyx_n_s_fn;
static PyObject *__pyx_n_s_fun;
static PyObject *__pyx_n_s_genexpr;
static PyObject *__pyx_n_s_hstack;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_init;
static PyObject *__pyx_n_s_issparse;
static PyObject *__pyx_n_s_items;
static PyObject *__pyx_n_s_iter;
static PyObject *__pyx_n_s_joblib;
static PyObject *__pyx_n_s_key;
static PyObject *__pyx_n_s_keys;
static PyObject *__pyx_n_s_kwargs;
static PyObject *__pyx_n_u_list;
static PyObject *__pyx_n_s_loc;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_s_max;
static PyObject *__pyx_n_s_mean;
static PyObject *__pyx_n_s_merge_dataframes_by_column;
static PyObject *__pyx_n_s_metaclass;
static PyObject *__pyx_n_s_min;
static PyObject *__pyx_n_s_missing;
static PyObject *__pyx_n_s_mode;
static PyObject *__pyx_n_s_module;
static PyObject *__pyx_n_s_n_jobs;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_nltk_corpus;
static PyObject *__pyx_n_u_not_stops;
static PyObject *__pyx_n_s_np;
static PyObject *__pyx_n_s_numpy;
static PyObject *__pyx_n_s_options;
static PyObject *__pyx_n_s_pandas;
static PyObject *__pyx_n_s_pd;
static PyObject *__pyx_n_s_predict;
static PyObject *__pyx_n_s_prepare;
static PyObject *__pyx_n_s_qualname;
static PyObject *__pyx_n_u_raw;
static PyObject *__pyx_n_s_replace;
static PyObject *__pyx_n_s_result;
static PyObject *__pyx_n_s_scipy;
static PyObject *__pyx_n_s_self;
static PyObject *__pyx_n_u_sen_len;
static PyObject *__pyx_n_s_send;
static PyObject *__pyx_n_s_shape;
static PyObject *__pyx_n_s_sklearn_base;
static PyObject *__pyx_n_s_sklearn_feature_extraction_text;
static PyObject *__pyx_n_s_sklearn_pipeline;
static PyObject *__pyx_n_s_sparse;
static PyObject *__pyx_n_s_split;
static PyObject *__pyx_n_s_stopwords;
static PyObject *__pyx_n_s_stopwords_2;
static PyObject *__pyx_n_s_super;
static PyObject *__pyx_n_s_sys;
static PyObject *__pyx_n_s_tar1;
static PyObject *__pyx_n_s_tar2;
static PyObject *__pyx_n_s_target;
static PyObject *__pyx_n_s_targets;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_throw;
static PyObject *__pyx_n_s_tocsr;
static PyObject *__pyx_n_s_todense;
static PyObject *__pyx_n_s_trans;
static PyObject *__pyx_kp_s_trans_py;
static PyObject *__pyx_n_s_transform;
static PyObject *__pyx_n_s_transform_one;
static PyObject *__pyx_n_s_transformer;
static PyObject *__pyx_n_s_transformers;
static PyObject *__pyx_n_s_update_transformer_list;
static PyObject *__pyx_n_s_validate_transformers;
static PyObject *__pyx_n_s_version;
static PyObject *__pyx_n_s_weight;
static PyObject *__pyx_n_s_words;
static PyObject *__pyx_n_s_x;
static PyObject *__pyx_n_s_y;
static PyObject *__pyx_n_s_zeros;
static PyObject *__pyx_n_s_zip;
static PyObject *__pyx_pf_5trans_12TextSelector___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_12TextSelector_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_12TextSelector_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_17TextSelectorMulti___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_keys); /* proto */
static PyObject *__pyx_pf_5trans_17TextSelectorMulti_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_17TextSelectorMulti_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_14NumberSelector___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_14NumberSelector_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_14NumberSelector_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_15FeatureSelector___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_feats); /* proto */
static PyObject *__pyx_pf_5trans_15FeatureSelector_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_15FeatureSelector_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_12DropFeatures___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_feats); /* proto */
static PyObject *__pyx_pf_5trans_12DropFeatures_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_12DropFeatures_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_14ConvertTargets___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_targets); /* proto */
static PyObject *__pyx_pf_5trans_14ConvertTargets_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_14ConvertTargets_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_11MissingData___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_11MissingData_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_lambda_funcdef_lambda1(PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_x); /* proto */
static PyObject *__pyx_pf_5trans_11MissingData_9transform_genexpr(PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_5trans_11MissingData_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_14SentenceLength___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_14SentenceLength_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_lambda_funcdef_lambda2(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x); /* proto */
static PyObject *__pyx_pf_5trans_14SentenceLength_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_11CountCommas___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_11CountCommas_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_lambda_funcdef_lambda3(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x); /* proto */
static PyObject *__pyx_pf_5trans_11CountCommas_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_10CountWords___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_10CountWords_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_lambda_funcdef_lambda4(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x); /* proto */
static PyObject *__pyx_pf_5trans_10CountWords_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_21AvgWordLenTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_21AvgWordLenTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_lambda_funcdef_lambda5(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x); /* proto */
static PyObject *__pyx_pf_5trans_21AvgWordLenTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_19NotStopsTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_19NotStopsTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_lambda_funcdef_lambda6(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x); /* proto */
static PyObject *__pyx_pf_5trans_19NotStopsTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_13CommaLenRatio___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_col); /* proto */
static PyObject *__pyx_pf_5trans_13CommaLenRatio_2divide(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_x, PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_13CommaLenRatio_4fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_lambda_funcdef_lambda7(PyObject *__pyx_self, PyObject *__pyx_v_x); /* proto */
static PyObject *__pyx_pf_5trans_13CommaLenRatio_6transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_14BooleanTargets___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col, PyObject *__pyx_v_tar1, PyObject *__pyx_v_tar2); /* proto */
static PyObject *__pyx_pf_5trans_14BooleanTargets_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_14BooleanTargets_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_17PandasTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_fn); /* proto */
static PyObject *__pyx_pf_5trans_17PandasTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_17PandasTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_copy); /* proto */
static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_13fit_transform_genexpr(PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_13fit_transform_3genexpr(PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_fit_transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y, PyObject *__pyx_v_fit_params); /* proto */
static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_2merge_dataframes_by_column(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_Xs); /* proto */
static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_9transform_genexpr(PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_9transform_3genexpr(PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_16DenseTransformer_fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_fit_params); /* proto */
static PyObject *__pyx_pf_5trans_16DenseTransformer_2transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_fit_params); /* proto */
static PyObject *__pyx_pf_5trans_19WordVectorTransform___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_args, PyObject *__pyx_v_kwargs); /* proto */
static PyObject *__pyx_pf_5trans_13NNTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_ann); /* proto */
static PyObject *__pyx_pf_5trans_13NNTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_13NNTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_13TestTransform___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_fn); /* proto */
static PyObject *__pyx_pf_5trans_13TestTransform_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_13TestTransform_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_copy); /* proto */
static PyObject *__pyx_pf_5trans_13TestTransform_6fun(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_19TransformerTemplate___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_5trans_19TransformerTemplate_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_19TransformerTemplate_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_pf_5trans_3Wat___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self); /* proto */
static PyObject *__pyx_pf_5trans_3Wat_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y); /* proto */
static PyObject *__pyx_pf_5trans_3Wat_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X); /* proto */
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct__transform(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_1_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_2_transform(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_3_fit_transform(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_4_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_5_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_6_transform(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_7_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_8_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_slice__5;
static PyObject *__pyx_slice__6;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__7;
static PyObject *__pyx_tuple__8;
static PyObject *__pyx_tuple__9;
static PyObject *__pyx_tuple__11;
static PyObject *__pyx_tuple__12;
static PyObject *__pyx_tuple__14;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__17;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__21;
static PyObject *__pyx_tuple__22;
static PyObject *__pyx_tuple__24;
static PyObject *__pyx_tuple__26;
static PyObject *__pyx_tuple__27;
static PyObject *__pyx_tuple__29;
static PyObject *__pyx_tuple__30;
static PyObject *__pyx_tuple__32;
static PyObject *__pyx_tuple__34;
static PyObject *__pyx_tuple__35;
static PyObject *__pyx_tuple__37;
static PyObject *__pyx_tuple__38;
static PyObject *__pyx_tuple__40;
static PyObject *__pyx_tuple__42;
static PyObject *__pyx_tuple__43;
static PyObject *__pyx_tuple__45;
static PyObject *__pyx_tuple__46;
static PyObject *__pyx_tuple__48;
static PyObject *__pyx_tuple__50;
static PyObject *__pyx_tuple__51;
static PyObject *__pyx_tuple__53;
static PyObject *__pyx_tuple__54;
static PyObject *__pyx_tuple__56;
static PyObject *__pyx_tuple__58;
static PyObject *__pyx_tuple__59;
static PyObject *__pyx_tuple__61;
static PyObject *__pyx_tuple__62;
static PyObject *__pyx_tuple__64;
static PyObject *__pyx_tuple__66;
static PyObject *__pyx_tuple__67;
static PyObject *__pyx_tuple__69;
static PyObject *__pyx_tuple__70;
static PyObject *__pyx_tuple__72;
static PyObject *__pyx_tuple__74;
static PyObject *__pyx_tuple__75;
static PyObject *__pyx_tuple__77;
static PyObject *__pyx_tuple__78;
static PyObject *__pyx_tuple__80;
static PyObject *__pyx_tuple__82;
static PyObject *__pyx_tuple__83;
static PyObject *__pyx_tuple__85;
static PyObject *__pyx_tuple__86;
static PyObject *__pyx_tuple__88;
static PyObject *__pyx_tuple__90;
static PyObject *__pyx_tuple__91;
static PyObject *__pyx_tuple__93;
static PyObject *__pyx_tuple__94;
static PyObject *__pyx_tuple__96;
static PyObject *__pyx_tuple__98;
static PyObject *__pyx_tuple__99;
static PyObject *__pyx_tuple__101;
static PyObject *__pyx_tuple__102;
static PyObject *__pyx_tuple__104;
static PyObject *__pyx_tuple__106;
static PyObject *__pyx_tuple__107;
static PyObject *__pyx_tuple__109;
static PyObject *__pyx_tuple__111;
static PyObject *__pyx_tuple__112;
static PyObject *__pyx_tuple__114;
static PyObject *__pyx_tuple__116;
static PyObject *__pyx_tuple__118;
static PyObject *__pyx_tuple__119;
static PyObject *__pyx_tuple__121;
static PyObject *__pyx_tuple__123;
static PyObject *__pyx_tuple__125;
static PyObject *__pyx_tuple__126;
static PyObject *__pyx_tuple__128;
static PyObject *__pyx_tuple__129;
static PyObject *__pyx_tuple__131;
static PyObject *__pyx_tuple__132;
static PyObject *__pyx_tuple__134;
static PyObject *__pyx_tuple__136;
static PyObject *__pyx_tuple__138;
static PyObject *__pyx_tuple__139;
static PyObject *__pyx_tuple__141;
static PyObject *__pyx_tuple__142;
static PyObject *__pyx_tuple__144;
static PyObject *__pyx_tuple__146;
static PyObject *__pyx_tuple__148;
static PyObject *__pyx_tuple__150;
static PyObject *__pyx_tuple__152;
static PyObject *__pyx_tuple__154;
static PyObject *__pyx_tuple__155;
static PyObject *__pyx_tuple__157;
static PyObject *__pyx_tuple__158;
static PyObject *__pyx_tuple__160;
static PyObject *__pyx_tuple__162;
static PyObject *__pyx_tuple__164;
static PyObject *__pyx_tuple__165;
static PyObject *__pyx_tuple__167;
static PyObject *__pyx_tuple__169;
static PyObject *__pyx_tuple__171;
static PyObject *__pyx_tuple__172;
static PyObject *__pyx_codeobj__10;
static PyObject *__pyx_codeobj__13;
static PyObject *__pyx_codeobj__16;
static PyObject *__pyx_codeobj__18;
static PyObject *__pyx_codeobj__20;
static PyObject *__pyx_codeobj__23;
static PyObject *__pyx_codeobj__25;
static PyObject *__pyx_codeobj__28;
static PyObject *__pyx_codeobj__31;
static PyObject *__pyx_codeobj__33;
static PyObject *__pyx_codeobj__36;
static PyObject *__pyx_codeobj__39;
static PyObject *__pyx_codeobj__41;
static PyObject *__pyx_codeobj__44;
static PyObject *__pyx_codeobj__47;
static PyObject *__pyx_codeobj__49;
static PyObject *__pyx_codeobj__52;
static PyObject *__pyx_codeobj__55;
static PyObject *__pyx_codeobj__57;
static PyObject *__pyx_codeobj__60;
static PyObject *__pyx_codeobj__63;
static PyObject *__pyx_codeobj__65;
static PyObject *__pyx_codeobj__68;
static PyObject *__pyx_codeobj__71;
static PyObject *__pyx_codeobj__73;
static PyObject *__pyx_codeobj__76;
static PyObject *__pyx_codeobj__79;
static PyObject *__pyx_codeobj__81;
static PyObject *__pyx_codeobj__84;
static PyObject *__pyx_codeobj__87;
static PyObject *__pyx_codeobj__89;
static PyObject *__pyx_codeobj__92;
static PyObject *__pyx_codeobj__95;
static PyObject *__pyx_codeobj__97;
static PyObject *__pyx_codeobj__100;
static PyObject *__pyx_codeobj__103;
static PyObject *__pyx_codeobj__105;
static PyObject *__pyx_codeobj__108;
static PyObject *__pyx_codeobj__110;
static PyObject *__pyx_codeobj__113;
static PyObject *__pyx_codeobj__115;
static PyObject *__pyx_codeobj__117;
static PyObject *__pyx_codeobj__120;
static PyObject *__pyx_codeobj__122;
static PyObject *__pyx_codeobj__124;
static PyObject *__pyx_codeobj__127;
static PyObject *__pyx_codeobj__130;
static PyObject *__pyx_codeobj__133;
static PyObject *__pyx_codeobj__135;
static PyObject *__pyx_codeobj__137;
static PyObject *__pyx_codeobj__140;
static PyObject *__pyx_codeobj__143;
static PyObject *__pyx_codeobj__145;
static PyObject *__pyx_codeobj__147;
static PyObject *__pyx_codeobj__149;
static PyObject *__pyx_codeobj__151;
static PyObject *__pyx_codeobj__153;
static PyObject *__pyx_codeobj__156;
static PyObject *__pyx_codeobj__159;
static PyObject *__pyx_codeobj__161;
static PyObject *__pyx_codeobj__163;
static PyObject *__pyx_codeobj__166;
static PyObject *__pyx_codeobj__168;
static PyObject *__pyx_codeobj__170;
static PyObject *__pyx_codeobj__173;
/* Late includes */

/* "trans.py":29
 * class TextSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single text column from the data frame on which to perform transformations. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_12TextSelector_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_12TextSelector_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_12TextSelector_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_12TextSelector_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject*)__pyx_n_u_raw));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 29, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 29, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TextSelector.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_12TextSelector___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_12TextSelector___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":30
 *     """ Select a single text column from the data frame on which to perform transformations. """
 *     def __init__(self, col='raw'):
 *         self.key = col             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_key, __pyx_v_col) < 0) __PYX_ERR(0, 30, __pyx_L1_error)

  /* "trans.py":29
 * class TextSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single text column from the data frame on which to perform transformations. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.TextSelector.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":32
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_12TextSelector_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_12TextSelector_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_12TextSelector_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_12TextSelector_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 32, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 32, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 32, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TextSelector.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_12TextSelector_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_12TextSelector_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":33
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":32
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":35
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.key]
 *         #return X[self]
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_12TextSelector_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_12TextSelector_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_12TextSelector_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_12TextSelector_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 35, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 35, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 35, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TextSelector.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_12TextSelector_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_12TextSelector_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":36
 *
 *     def transform(self, X):
 *         return X[self.key]             # <<<<<<<<<<<<<<
 *         #return X[self]
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_key); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 36, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* "trans.py":35
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.key]
 *         #return X[self]
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("trans.TextSelector.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":42
 * class TextSelectorMulti(BaseEstimator, TransformerMixin):
 *     """ Select multiple text columns from the data frame on which to perform transformations. """
 *     def __init__(self, keys: list):             # <<<<<<<<<<<<<<
 *         self.keys = keys
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_17TextSelectorMulti_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_17TextSelectorMulti_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_17TextSelectorMulti_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_17TextSelectorMulti_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_keys = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_keys,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_keys)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, 1); __PYX_ERR(0, 42, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 42, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_keys = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 42, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TextSelectorMulti.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_keys), (&PyList_Type), 1, "keys", 1))) __PYX_ERR(0, 42, __pyx_L1_error)
  __pyx_r = __pyx_pf_5trans_17TextSelectorMulti___init__(__pyx_self, __pyx_v_self, __pyx_v_keys);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_17TextSelectorMulti___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_keys) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":43
 *     """ Select multiple text columns from the data frame on which to perform transformations. """
 *     def __init__(self, keys: list):
 *         self.keys = keys             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_keys, __pyx_v_keys) < 0) __PYX_ERR(0, 43, __pyx_L1_error)

  /* "trans.py":42
 * class TextSelectorMulti(BaseEstimator, TransformerMixin):
 *     """ Select multiple text columns from the data frame on which to perform transformations. """
 *     def __init__(self, keys: list):             # <<<<<<<<<<<<<<
 *         self.keys = keys
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.TextSelectorMulti.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":45
 *         self.keys = keys
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_17TextSelectorMulti_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_17TextSelectorMulti_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_17TextSelectorMulti_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_17TextSelectorMulti_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 45, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 45, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 45, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TextSelectorMulti.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_17TextSelectorMulti_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_17TextSelectorMulti_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":46
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":45
 *         self.keys = keys
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":48
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.keys]
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_17TextSelectorMulti_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_17TextSelectorMulti_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_17TextSelectorMulti_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_17TextSelectorMulti_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 48, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 48, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 48, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TextSelectorMulti.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_17TextSelectorMulti_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_17TextSelectorMulti_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":49
 *
 *     def transform(self, X):
 *         return X[self.keys]             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_keys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* "trans.py":48
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.keys]
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("trans.TextSelectorMulti.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":55
 * class NumberSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single numeric column from the data frame on which to perform transformations. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14NumberSelector_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14NumberSelector_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14NumberSelector_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14NumberSelector_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 55, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 55, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NumberSelector.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14NumberSelector___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14NumberSelector___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":56
 *     """ Select a single numeric column from the data frame on which to perform transformations. """
 *     def __init__(self, col=None):
 *         self.key = col             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_key, __pyx_v_col) < 0) __PYX_ERR(0, 56, __pyx_L1_error)

  /* "trans.py":55
 * class NumberSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single numeric column from the data frame on which to perform transformations. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.NumberSelector.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":58
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14NumberSelector_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14NumberSelector_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14NumberSelector_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14NumberSelector_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 58, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 58, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 58, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NumberSelector.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14NumberSelector_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14NumberSelector_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":59
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":58
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":61
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[[self.key]]
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14NumberSelector_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14NumberSelector_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14NumberSelector_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14NumberSelector_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 61, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 61, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 61, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NumberSelector.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14NumberSelector_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14NumberSelector_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":62
 *
 *     def transform(self, X):
 *         return X[[self.key]]             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_key); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 62, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "trans.py":61
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[[self.key]]
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("trans.NumberSelector.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":67
 * class FeatureSelector(BaseEstimator, TransformerMixin):
 *     """ Select only the features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_15FeatureSelector_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_15FeatureSelector_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_15FeatureSelector_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_15FeatureSelector_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_feats = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_feats,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject*)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_feats);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 67, __pyx_L3_error)
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
    __pyx_v_feats = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 67, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.FeatureSelector.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_feats), (&PyList_Type), 1, "feats", 1))) __PYX_ERR(0, 67, __pyx_L1_error)
  __pyx_r = __pyx_pf_5trans_15FeatureSelector___init__(__pyx_self, __pyx_v_self, __pyx_v_feats);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_15FeatureSelector___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_feats) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":68
 *     """ Select only the features passed via set_params. """
 *     def __init__(self, feats: list=None):
 *         self.feats = feats             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_feats, __pyx_v_feats) < 0) __PYX_ERR(0, 68, __pyx_L1_error)

  /* "trans.py":67
 * class FeatureSelector(BaseEstimator, TransformerMixin):
 *     """ Select only the features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.FeatureSelector.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":70
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_15FeatureSelector_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_15FeatureSelector_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_15FeatureSelector_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_15FeatureSelector_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 70, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 70, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 70, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.FeatureSelector.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_15FeatureSelector_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_15FeatureSelector_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":71
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":70
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":73
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.feats]
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_15FeatureSelector_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_15FeatureSelector_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_15FeatureSelector_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_15FeatureSelector_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 73, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 73, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 73, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.FeatureSelector.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_15FeatureSelector_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_15FeatureSelector_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":74
 *
 *     def transform(self, X):
 *         return X[self.feats]             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_feats); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 74, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 74, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* "trans.py":73
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.feats]
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("trans.FeatureSelector.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":79
 * class DropFeatures(BaseEstimator, TransformerMixin):
 *     """ Drop any features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_12DropFeatures_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_12DropFeatures_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_12DropFeatures_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_12DropFeatures_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_feats = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_feats,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject*)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_feats);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 79, __pyx_L3_error)
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
    __pyx_v_feats = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 79, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.DropFeatures.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_feats), (&PyList_Type), 1, "feats", 1))) __PYX_ERR(0, 79, __pyx_L1_error)
  __pyx_r = __pyx_pf_5trans_12DropFeatures___init__(__pyx_self, __pyx_v_self, __pyx_v_feats);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_12DropFeatures___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_feats) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":80
 *     """ Drop any features passed via set_params. """
 *     def __init__(self, feats: list=None):
 *         self.feats = feats             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_feats, __pyx_v_feats) < 0) __PYX_ERR(0, 80, __pyx_L1_error)

  /* "trans.py":79
 * class DropFeatures(BaseEstimator, TransformerMixin):
 *     """ Drop any features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.DropFeatures.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":82
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_12DropFeatures_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_12DropFeatures_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_12DropFeatures_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_12DropFeatures_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 82, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 82, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 82, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.DropFeatures.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_12DropFeatures_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_12DropFeatures_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":83
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":82
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":85
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X.drop(self.feats, axis=1)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_12DropFeatures_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_12DropFeatures_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_12DropFeatures_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_12DropFeatures_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 85, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 85, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 85, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.DropFeatures.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_12DropFeatures_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_12DropFeatures_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":86
 *
 *     def transform(self, X):
 *         return X.drop(self.feats, axis=1)             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_drop); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_feats); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_axis, __pyx_int_1) < 0) __PYX_ERR(0, 86, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_4;
  __pyx_t_4 = 0;
  goto __pyx_L0;

  /* "trans.py":85
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X.drop(self.feats, axis=1)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.DropFeatures.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":91
 * class ConvertTargets(BaseEstimator, TransformerMixin):
 *     """ Convert target categories to int. """
 *     def __init__(self, targets: list=None):             # <<<<<<<<<<<<<<
 *         self.targets = targets
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14ConvertTargets_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14ConvertTargets_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14ConvertTargets_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14ConvertTargets_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_targets = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_targets,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject*)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_targets);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 91, __pyx_L3_error)
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
    __pyx_v_targets = ((PyObject*)values[1]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 91, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.ConvertTargets.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_targets), (&PyList_Type), 1, "targets", 1))) __PYX_ERR(0, 91, __pyx_L1_error)
  __pyx_r = __pyx_pf_5trans_14ConvertTargets___init__(__pyx_self, __pyx_v_self, __pyx_v_targets);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14ConvertTargets___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_targets) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":92
 *     """ Convert target categories to int. """
 *     def __init__(self, targets: list=None):
 *         self.targets = targets             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_targets, __pyx_v_targets) < 0) __PYX_ERR(0, 92, __pyx_L1_error)

  /* "trans.py":91
 * class ConvertTargets(BaseEstimator, TransformerMixin):
 *     """ Convert target categories to int. """
 *     def __init__(self, targets: list=None):             # <<<<<<<<<<<<<<
 *         self.targets = targets
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.ConvertTargets.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":94
 *         self.targets = targets
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14ConvertTargets_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14ConvertTargets_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14ConvertTargets_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14ConvertTargets_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 94, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 94, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 94, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.ConvertTargets.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14ConvertTargets_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14ConvertTargets_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":95
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":94
 *         self.targets = targets
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":97
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return # @TODO
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14ConvertTargets_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14ConvertTargets_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14ConvertTargets_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14ConvertTargets_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 97, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 97, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 97, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.ConvertTargets.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14ConvertTargets_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14ConvertTargets_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":98
 *
 *     def transform(self, X):
 *         return # @TODO             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;

  /* "trans.py":97
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return # @TODO
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":105
 * class MissingData(BaseEstimator, TransformerMixin):
 *     """ Examines dataset for missing values, smh. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11MissingData_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11MissingData_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_11MissingData_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_11MissingData_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject*)__pyx_n_u_raw));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 105, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 105, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.MissingData.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_11MissingData___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_11MissingData___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":106
 *     """ Examines dataset for missing values, smh. """
 *     def __init__(self, col='raw'):
 *         self.key = col             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_key, __pyx_v_col) < 0) __PYX_ERR(0, 106, __pyx_L1_error)

  /* "trans.py":105
 * class MissingData(BaseEstimator, TransformerMixin):
 *     """ Examines dataset for missing values, smh. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.MissingData.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":108
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11MissingData_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11MissingData_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_11MissingData_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_11MissingData_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 108, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 108, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 108, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.MissingData.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_11MissingData_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_11MissingData_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":109
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":108
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":111
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         missing = ['', None]
 *         for y in X.columns:
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11MissingData_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11MissingData_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_11MissingData_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_11MissingData_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 111, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 111, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 111, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.MissingData.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_11MissingData_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_5trans_11MissingData_9transform_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); /* proto */

/* "trans.py":114
 *         missing = ['', None]
 *         for y in X.columns:
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.             # <<<<<<<<<<<<<<
 *         return X
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11MissingData_9transform_7genexpr_lambda1(PyObject *__pyx_self, PyObject *__pyx_v_x); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11MissingData_9transform_7genexpr_lambda1 = {"lambda1", (PyCFunction)__pyx_pw_5trans_11MissingData_9transform_7genexpr_lambda1, METH_O, 0};
static PyObject *__pyx_pw_5trans_11MissingData_9transform_7genexpr_lambda1(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("lambda1 (wrapper)", 0);
  __pyx_r = __pyx_lambda_funcdef_lambda1(__pyx_self, ((PyObject *)__pyx_v_x));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_lambda_funcdef_lambda1(PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_x) {
  struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *__pyx_cur_scope;
  struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *__pyx_outer_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("lambda1", 0);
  __pyx_outer_scope = (struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;
  __Pyx_XDECREF(__pyx_r);
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_X)) { __Pyx_RaiseClosureNameError("X"); __PYX_ERR(0, 114, __pyx_L1_error) }
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_y)) { __Pyx_RaiseClosureNameError("y"); __PYX_ERR(0, 114, __pyx_L1_error) }
  __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_X, __pyx_cur_scope->__pyx_outer_scope->__pyx_v_y); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_mean); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.MissingData.transform.genexpr.lambda1", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_11MissingData_9transform_genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *)__pyx_tp_new_5trans___pyx_scope_struct_1_genexpr(__pyx_ptype_5trans___pyx_scope_struct_1_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 114, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_5trans___pyx_scope_struct__transform *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_5trans_11MissingData_9transform_2generator, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_MissingData_transform_locals_gen, __pyx_n_s_trans); if (unlikely(!gen)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.MissingData.transform.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_5trans_11MissingData_9transform_2generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) /* generator body */
{
  struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *__pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  int __pyx_t_6;
  int __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L7_resume_from_yield;
    default: /* CPython raises the right error here */
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 114, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_X)) { __Pyx_RaiseClosureNameError("X"); __PYX_ERR(0, 114, __pyx_L1_error) }
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_X, __pyx_n_s_split); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 114, __pyx_L1_error)
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
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_kp_u_) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_u_);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 114, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 114, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 114, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_5(__pyx_t_2);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 114, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_z);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_z, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_z, __pyx_n_s_replace); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_missing)) { __Pyx_RaiseClosureNameError("missing"); __PYX_ERR(0, 114, __pyx_L1_error) }
    __pyx_t_6 = (__Pyx_PySequence_ContainsTF(__pyx_t_3, __pyx_cur_scope->__pyx_outer_scope->__pyx_v_missing, Py_EQ)); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_7 = (__pyx_t_6 != 0);
    if (__pyx_t_7) {
      __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11MissingData_9transform_7genexpr_lambda1, 0, __pyx_n_s_MissingData_transform_locals_gen_2, ((PyObject*)__pyx_cur_scope), __pyx_n_s_trans, __pyx_d, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 114, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_r = __pyx_t_3;
      __pyx_t_3 = 0;
      __Pyx_XGIVEREF(__pyx_t_2);
      __pyx_cur_scope->__pyx_t_0 = __pyx_t_2;
      __pyx_cur_scope->__pyx_t_1 = __pyx_t_4;
      __pyx_cur_scope->__pyx_t_2 = __pyx_t_5;
      __Pyx_XGIVEREF(__pyx_r);
      __Pyx_RefNannyFinishContext();
      __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
      /* return from generator, yielding value */
      __pyx_generator->resume_label = 1;
      return __pyx_r;
      __pyx_L7_resume_from_yield:;
      __pyx_t_2 = __pyx_cur_scope->__pyx_t_0;
      __pyx_cur_scope->__pyx_t_0 = 0;
      __Pyx_XGOTREF(__pyx_t_2);
      __pyx_t_4 = __pyx_cur_scope->__pyx_t_1;
      __pyx_t_5 = __pyx_cur_scope->__pyx_t_2;
      if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 114, __pyx_L1_error)
    }
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  /* function exit code */
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":111
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         missing = ['', None]
 *         for y in X.columns:
 */

static PyObject *__pyx_pf_5trans_11MissingData_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  struct __pyx_obj_5trans___pyx_scope_struct__transform *__pyx_cur_scope;
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
  __Pyx_RefNannySetupContext("transform", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct__transform *)__pyx_tp_new_5trans___pyx_scope_struct__transform(__pyx_ptype_5trans___pyx_scope_struct__transform, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct__transform *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 111, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_X = __pyx_v_X;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_X);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_X);

  /* "trans.py":112
 *
 *     def transform(self, X):
 *         missing = ['', None]             # <<<<<<<<<<<<<<
 *         for y in X.columns:
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 112, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_kp_u__2);
  __Pyx_GIVEREF(__pyx_kp_u__2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u__2);
  __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(Py_None);
  PyList_SET_ITEM(__pyx_t_1, 1, Py_None);
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_missing = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  /* "trans.py":113
 *     def transform(self, X):
 *         missing = ['', None]
 *         for y in X.columns:             # <<<<<<<<<<<<<<
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.
 *         return X
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_X, __pyx_n_s_columns); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 113, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
    __pyx_t_4 = NULL;
  } else {
    __pyx_t_3 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 113, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 113, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_4)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 113, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 113, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_3 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 113, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 113, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_4(__pyx_t_2);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 113, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_y);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_y, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;

    /* "trans.py":114
 *         missing = ['', None]
 *         for y in X.columns:
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.             # <<<<<<<<<<<<<<
 *         return X
 *
 */
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_cur_scope->__pyx_v_X, __pyx_cur_scope->__pyx_v_y); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_apply); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __pyx_pf_5trans_11MissingData_9transform_genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
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
    __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_7, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_5);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    /* "trans.py":113
 *     def transform(self, X):
 *         missing = ['', None]
 *         for y in X.columns:             # <<<<<<<<<<<<<<
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.
 *         return X
 */
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":115
 *         for y in X.columns:
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.
 *         return X             # <<<<<<<<<<<<<<
 *
 * # Numeric text measurements.
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_X);
  __pyx_r = __pyx_cur_scope->__pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":111
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         missing = ['', None]
 *         for y in X.columns:
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("trans.MissingData.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":121
 * class SentenceLength(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14SentenceLength_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14SentenceLength_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14SentenceLength_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14SentenceLength_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 121, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 121, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.SentenceLength.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14SentenceLength___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14SentenceLength___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":122
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):
 *         self.col = col             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_col, __pyx_v_col) < 0) __PYX_ERR(0, 122, __pyx_L1_error)

  /* "trans.py":121
 * class SentenceLength(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.SentenceLength.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":125
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14SentenceLength_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14SentenceLength_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14SentenceLength_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14SentenceLength_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 125, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 125, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 125, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.SentenceLength.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14SentenceLength_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14SentenceLength_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":126
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":125
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":128
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))
 *         return X
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14SentenceLength_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14SentenceLength_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14SentenceLength_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14SentenceLength_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 128, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 128, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 128, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.SentenceLength.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14SentenceLength_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":129
 *
 *     def transform(self, X):
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))             # <<<<<<<<<<<<<<
 *         return X
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14SentenceLength_9transform_lambda2(PyObject *__pyx_self, PyObject *__pyx_v_x); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14SentenceLength_9transform_lambda2 = {"lambda2", (PyCFunction)__pyx_pw_5trans_14SentenceLength_9transform_lambda2, METH_O, 0};
static PyObject *__pyx_pw_5trans_14SentenceLength_9transform_lambda2(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("lambda2 (wrapper)", 0);
  __pyx_r = __pyx_lambda_funcdef_lambda2(__pyx_self, ((PyObject *)__pyx_v_x));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_lambda_funcdef_lambda2(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  Py_ssize_t __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("lambda2", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyObject_Length(__pyx_v_x); if (unlikely(__pyx_t_1 == ((Py_ssize_t)-1))) __PYX_ERR(0, 129, __pyx_L1_error)
  __pyx_t_2 = PyInt_FromSsize_t(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_r = __pyx_t_2;
  __pyx_t_2 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("trans.SentenceLength.transform.lambda2", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":128
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))
 *         return X
 */

static PyObject *__pyx_pf_5trans_14SentenceLength_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":129
 *
 *     def transform(self, X):
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))             # <<<<<<<<<<<<<<
 *         return X
 *
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_col); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_apply); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14SentenceLength_9transform_lambda2, 0, __pyx_n_s_SentenceLength_transform_locals, NULL, __pyx_n_s_trans, __pyx_d, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(PyObject_SetItem(__pyx_v_X, __pyx_n_u_sen_len, __pyx_t_1) < 0)) __PYX_ERR(0, 129, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":130
 *     def transform(self, X):
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":128
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))
 *         return X
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.SentenceLength.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":135
 * class CountCommas(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11CountCommas_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11CountCommas_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_11CountCommas_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_11CountCommas_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 135, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 135, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CountCommas.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_11CountCommas___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_11CountCommas___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":136
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):
 *         self.col = col             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_col, __pyx_v_col) < 0) __PYX_ERR(0, 136, __pyx_L1_error)

  /* "trans.py":135
 * class CountCommas(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.CountCommas.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":139
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11CountCommas_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11CountCommas_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_11CountCommas_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_11CountCommas_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 139, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 139, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 139, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CountCommas.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_11CountCommas_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_11CountCommas_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":140
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":139
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":142
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))
 *         return X
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11CountCommas_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11CountCommas_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_11CountCommas_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_11CountCommas_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 142, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 142, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 142, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CountCommas.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_11CountCommas_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":143
 *
 *     def transform(self, X):
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))             # <<<<<<<<<<<<<<
 *         return X
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_11CountCommas_9transform_lambda3(PyObject *__pyx_self, PyObject *__pyx_v_x); /*proto*/
static PyMethodDef __pyx_mdef_5trans_11CountCommas_9transform_lambda3 = {"lambda3", (PyCFunction)__pyx_pw_5trans_11CountCommas_9transform_lambda3, METH_O, 0};
static PyObject *__pyx_pw_5trans_11CountCommas_9transform_lambda3(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("lambda3 (wrapper)", 0);
  __pyx_r = __pyx_lambda_funcdef_lambda3(__pyx_self, ((PyObject *)__pyx_v_x));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_lambda_funcdef_lambda3(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("lambda3", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_x, __pyx_n_s_count); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 143, __pyx_L1_error)
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
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_kp_u__4) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_u__4);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 143, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.CountCommas.transform.lambda3", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":142
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))
 *         return X
 */

static PyObject *__pyx_pf_5trans_11CountCommas_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":143
 *
 *     def transform(self, X):
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))             # <<<<<<<<<<<<<<
 *         return X
 *
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_col); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 143, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 143, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_apply); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 143, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11CountCommas_9transform_lambda3, 0, __pyx_n_s_CountCommas_transform_locals_lam, NULL, __pyx_n_s_trans, __pyx_d, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 143, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 143, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(PyObject_SetItem(__pyx_v_X, __pyx_n_u_count_commas, __pyx_t_1) < 0)) __PYX_ERR(0, 143, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":144
 *     def transform(self, X):
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":142
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))
 *         return X
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.CountCommas.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":149
 * class CountWords(BaseEstimator, TransformerMixin):
 *     """ Count words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_10CountWords_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_10CountWords_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_10CountWords_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_10CountWords_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 149, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 149, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CountWords.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_10CountWords___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_10CountWords___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":150
 *     """ Count words in a text series. """
 *     def __init__(self, col=None):
 *         self.col = col             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_col, __pyx_v_col) < 0) __PYX_ERR(0, 150, __pyx_L1_error)

  /* "trans.py":149
 * class CountWords(BaseEstimator, TransformerMixin):
 *     """ Count words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.CountWords.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":152
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_10CountWords_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_10CountWords_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_10CountWords_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_10CountWords_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 152, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 152, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 152, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CountWords.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_10CountWords_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_10CountWords_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":153
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":152
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":155
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))
 *         #X = X.apply(lambda x: len(x.split(' ')))
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_10CountWords_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_10CountWords_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_10CountWords_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_10CountWords_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 155, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 155, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 155, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CountWords.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_10CountWords_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":156
 *
 *     def transform(self, X):
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))             # <<<<<<<<<<<<<<
 *         #X = X.apply(lambda x: len(x.split(' ')))
 *         return X
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_10CountWords_9transform_lambda4(PyObject *__pyx_self, PyObject *__pyx_v_x); /*proto*/
static PyMethodDef __pyx_mdef_5trans_10CountWords_9transform_lambda4 = {"lambda4", (PyCFunction)__pyx_pw_5trans_10CountWords_9transform_lambda4, METH_O, 0};
static PyObject *__pyx_pw_5trans_10CountWords_9transform_lambda4(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("lambda4 (wrapper)", 0);
  __pyx_r = __pyx_lambda_funcdef_lambda4(__pyx_self, ((PyObject *)__pyx_v_x));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_lambda_funcdef_lambda4(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("lambda4", 0);
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_x, __pyx_n_s_split); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 156, __pyx_L1_error)
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
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_kp_u_) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_kp_u_);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = PyObject_Length(__pyx_t_1); if (unlikely(__pyx_t_4 == ((Py_ssize_t)-1))) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyInt_FromSsize_t(__pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.CountWords.transform.lambda4", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":155
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))
 *         #X = X.apply(lambda x: len(x.split(' ')))
 */

static PyObject *__pyx_pf_5trans_10CountWords_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":156
 *
 *     def transform(self, X):
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))             # <<<<<<<<<<<<<<
 *         #X = X.apply(lambda x: len(x.split(' ')))
 *         return X
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_col); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_apply); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_10CountWords_9transform_lambda4, 0, __pyx_n_s_CountWords_transform_locals_lamb, NULL, __pyx_n_s_trans, __pyx_d, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(PyObject_SetItem(__pyx_v_X, __pyx_n_u_count_words, __pyx_t_1) < 0)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":158
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))
 *         #X = X.apply(lambda x: len(x.split(' ')))
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":155
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))
 *         #X = X.apply(lambda x: len(x.split(' ')))
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.CountWords.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":164
 *     """ Transformer to calculate average word length. """
 *
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_21AvgWordLenTransformer_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_21AvgWordLenTransformer_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 164, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 164, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.AvgWordLenTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_21AvgWordLenTransformer___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_21AvgWordLenTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":165
 *
 *     def __init__(self, col=None):
 *         self.col = col             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_col, __pyx_v_col) < 0) __PYX_ERR(0, 165, __pyx_L1_error)

  /* "trans.py":164
 *     """ Transformer to calculate average word length. """
 *
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.AvgWordLenTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":167
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_21AvgWordLenTransformer_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_21AvgWordLenTransformer_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 167, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 167, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 167, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.AvgWordLenTransformer.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_21AvgWordLenTransformer_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_21AvgWordLenTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":168
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":167
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":170
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)
 *         return X
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_21AvgWordLenTransformer_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_21AvgWordLenTransformer_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 170, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 170, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 170, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.AvgWordLenTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_21AvgWordLenTransformer_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":171
 *
 *     def transform(self, X):
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)             # <<<<<<<<<<<<<<
 *         return X
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_9transform_lambda5(PyObject *__pyx_self, PyObject *__pyx_v_x); /*proto*/
static PyMethodDef __pyx_mdef_5trans_21AvgWordLenTransformer_9transform_lambda5 = {"lambda5", (PyCFunction)__pyx_pw_5trans_21AvgWordLenTransformer_9transform_lambda5, METH_O, 0};
static PyObject *__pyx_pw_5trans_21AvgWordLenTransformer_9transform_lambda5(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("lambda5 (wrapper)", 0);
  __pyx_r = __pyx_lambda_funcdef_lambda5(__pyx_self, ((PyObject *)__pyx_v_x));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_lambda_funcdef_lambda5(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_8genexpr1__pyx_v_t = NULL;
  PyObject *__pyx_8genexpr2__pyx_v_t = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  PyObject *(*__pyx_t_7)(PyObject *);
  int __pyx_t_8;
  int __pyx_t_9;
  Py_ssize_t __pyx_t_10;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  Py_ssize_t __pyx_t_13;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("lambda5", 0);
  __Pyx_XDECREF(__pyx_r);
  { /* enter inner scope */
    __pyx_t_2 = PyList_New(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 171, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_x, __pyx_n_s_split); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 171, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_4);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_4, function);
      }
    }
    __pyx_t_3 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_5, __pyx_kp_u_) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_kp_u_);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (likely(PyList_CheckExact(__pyx_t_3)) || PyTuple_CheckExact(__pyx_t_3)) {
      __pyx_t_4 = __pyx_t_3; __Pyx_INCREF(__pyx_t_4); __pyx_t_6 = 0;
      __pyx_t_7 = NULL;
    } else {
      __pyx_t_6 = -1; __pyx_t_4 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 171, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_7 = Py_TYPE(__pyx_t_4)->tp_iternext; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 171, __pyx_L5_error)
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    for (;;) {
      if (likely(!__pyx_t_7)) {
        if (likely(PyList_CheckExact(__pyx_t_4))) {
          if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_4)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_3 = PyList_GET_ITEM(__pyx_t_4, __pyx_t_6); __Pyx_INCREF(__pyx_t_3); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 171, __pyx_L5_error)
          #else
          __pyx_t_3 = PySequence_ITEM(__pyx_t_4, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_3);
          #endif
        } else {
          if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_4)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_4, __pyx_t_6); __Pyx_INCREF(__pyx_t_3); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 171, __pyx_L5_error)
          #else
          __pyx_t_3 = PySequence_ITEM(__pyx_t_4, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_3);
          #endif
        }
      } else {
        __pyx_t_3 = __pyx_t_7(__pyx_t_4);
        if (unlikely(!__pyx_t_3)) {
          PyObject* exc_type = PyErr_Occurred();
          if (exc_type) {
            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
            else __PYX_ERR(0, 171, __pyx_L5_error)
          }
          break;
        }
        __Pyx_GOTREF(__pyx_t_3);
      }
      __Pyx_XDECREF_SET(__pyx_8genexpr1__pyx_v_t, __pyx_t_3);
      __pyx_t_3 = 0;
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_8 = (__Pyx_PySequence_ContainsTF(__pyx_8genexpr1__pyx_v_t, __pyx_t_3, Py_NE)); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 171, __pyx_L5_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_9 = (__pyx_t_8 != 0);
      if (__pyx_t_9) {
        __pyx_t_10 = PyObject_Length(__pyx_8genexpr1__pyx_v_t); if (unlikely(__pyx_t_10 == ((Py_ssize_t)-1))) __PYX_ERR(0, 171, __pyx_L5_error)
        __pyx_t_3 = PyInt_FromSsize_t(__pyx_t_10); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L5_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (unlikely(__Pyx_ListComp_Append(__pyx_t_2, (PyObject*)__pyx_t_3))) __PYX_ERR(0, 171, __pyx_L5_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      }
    }
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_t); __pyx_8genexpr1__pyx_v_t = 0;
    goto __pyx_L9_exit_scope;
    __pyx_L5_error:;
    __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_t); __pyx_8genexpr1__pyx_v_t = 0;
    goto __pyx_L1_error;
    __pyx_L9_exit_scope:;
  } /* exit inner scope */
  __pyx_t_6 = PyList_GET_SIZE(__pyx_t_2); if (unlikely(__pyx_t_6 == ((Py_ssize_t)-1))) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (((__pyx_t_6 > 0) != 0)) {
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_np); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 171, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_mean); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    { /* enter inner scope */
      __pyx_t_4 = PyList_New(0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 171, __pyx_L12_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_v_x, __pyx_n_s_split); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 171, __pyx_L12_error)
      __Pyx_GOTREF(__pyx_t_11);
      __pyx_t_12 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_11))) {
        __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_11);
        if (likely(__pyx_t_12)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
          __Pyx_INCREF(__pyx_t_12);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_11, function);
        }
      }
      __pyx_t_5 = (__pyx_t_12) ? __Pyx_PyObject_Call2Args(__pyx_t_11, __pyx_t_12, __pyx_kp_u_) : __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_kp_u_);
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 171, __pyx_L12_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      if (likely(PyList_CheckExact(__pyx_t_5)) || PyTuple_CheckExact(__pyx_t_5)) {
        __pyx_t_11 = __pyx_t_5; __Pyx_INCREF(__pyx_t_11); __pyx_t_10 = 0;
        __pyx_t_7 = NULL;
      } else {
        __pyx_t_10 = -1; __pyx_t_11 = PyObject_GetIter(__pyx_t_5); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 171, __pyx_L12_error)
        __Pyx_GOTREF(__pyx_t_11);
        __pyx_t_7 = Py_TYPE(__pyx_t_11)->tp_iternext; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 171, __pyx_L12_error)
      }
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      for (;;) {
        if (likely(!__pyx_t_7)) {
          if (likely(PyList_CheckExact(__pyx_t_11))) {
            if (__pyx_t_10 >= PyList_GET_SIZE(__pyx_t_11)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_5 = PyList_GET_ITEM(__pyx_t_11, __pyx_t_10); __Pyx_INCREF(__pyx_t_5); __pyx_t_10++; if (unlikely(0 < 0)) __PYX_ERR(0, 171, __pyx_L12_error)
            #else
            __pyx_t_5 = PySequence_ITEM(__pyx_t_11, __pyx_t_10); __pyx_t_10++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 171, __pyx_L12_error)
            __Pyx_GOTREF(__pyx_t_5);
            #endif
          } else {
            if (__pyx_t_10 >= PyTuple_GET_SIZE(__pyx_t_11)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_5 = PyTuple_GET_ITEM(__pyx_t_11, __pyx_t_10); __Pyx_INCREF(__pyx_t_5); __pyx_t_10++; if (unlikely(0 < 0)) __PYX_ERR(0, 171, __pyx_L12_error)
            #else
            __pyx_t_5 = PySequence_ITEM(__pyx_t_11, __pyx_t_10); __pyx_t_10++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 171, __pyx_L12_error)
            __Pyx_GOTREF(__pyx_t_5);
            #endif
          }
        } else {
          __pyx_t_5 = __pyx_t_7(__pyx_t_11);
          if (unlikely(!__pyx_t_5)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 171, __pyx_L12_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_5);
        }
        __Pyx_XDECREF_SET(__pyx_8genexpr2__pyx_v_t, __pyx_t_5);
        __pyx_t_5 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 171, __pyx_L12_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_9 = (__Pyx_PySequence_ContainsTF(__pyx_8genexpr2__pyx_v_t, __pyx_t_5, Py_NE)); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 171, __pyx_L12_error)
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_t_8 = (__pyx_t_9 != 0);
        if (__pyx_t_8) {
          __pyx_t_13 = PyObject_Length(__pyx_8genexpr2__pyx_v_t); if (unlikely(__pyx_t_13 == ((Py_ssize_t)-1))) __PYX_ERR(0, 171, __pyx_L12_error)
          __pyx_t_5 = PyInt_FromSsize_t(__pyx_t_13); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 171, __pyx_L12_error)
          __Pyx_GOTREF(__pyx_t_5);
          if (unlikely(__Pyx_ListComp_Append(__pyx_t_4, (PyObject*)__pyx_t_5))) __PYX_ERR(0, 171, __pyx_L12_error)
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        }
      }
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_t); __pyx_8genexpr2__pyx_v_t = 0;
      goto __pyx_L16_exit_scope;
      __pyx_L12_error:;
      __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_t); __pyx_8genexpr2__pyx_v_t = 0;
      goto __pyx_L1_error;
      __pyx_L16_exit_scope:;
    } /* exit inner scope */
    __pyx_t_11 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_11)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_11);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_11, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4);
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 171, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_1 = __pyx_t_2;
    __pyx_t_2 = 0;
  } else {
    __Pyx_INCREF(__pyx_int_0);
    __pyx_t_1 = __pyx_int_0;
  }
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("trans.AvgWordLenTransformer.transform.lambda5", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_t);
  __Pyx_XDECREF(__pyx_8genexpr2__pyx_v_t);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":170
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)
 *         return X
 */

static PyObject *__pyx_pf_5trans_21AvgWordLenTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":171
 *
 *     def transform(self, X):
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)             # <<<<<<<<<<<<<<
 *         return X
 *
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_col); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_apply); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_21AvgWordLenTransformer_9transform_lambda5, 0, __pyx_n_s_AvgWordLenTransformer_transform, NULL, __pyx_n_s_trans, __pyx_d, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(PyObject_SetItem(__pyx_v_X, __pyx_n_u_avg_word_len, __pyx_t_1) < 0)) __PYX_ERR(0, 171, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":172
 *     def transform(self, X):
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":170
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)
 *         return X
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.AvgWordLenTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":177
 * class NotStopsTransformer(BaseEstimator, TransformerMixin):
 *     """ Non-stop words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19NotStopsTransformer_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_19NotStopsTransformer_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 177, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 177, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NotStopsTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_19NotStopsTransformer___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_19NotStopsTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":178
 *     """ Non-stop words in a text series. """
 *     def __init__(self, col=None):
 *         self.col = col             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_col, __pyx_v_col) < 0) __PYX_ERR(0, 178, __pyx_L1_error)

  /* "trans.py":177
 * class NotStopsTransformer(BaseEstimator, TransformerMixin):
 *     """ Non-stop words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.NotStopsTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":180
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19NotStopsTransformer_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_19NotStopsTransformer_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 180, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 180, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 180, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NotStopsTransformer.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_19NotStopsTransformer_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_19NotStopsTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":181
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":180
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":183
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))
 *         return X
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19NotStopsTransformer_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_19NotStopsTransformer_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 183, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 183, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 183, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NotStopsTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_19NotStopsTransformer_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":184
 *
 *     def transform(self, X):
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))             # <<<<<<<<<<<<<<
 *         return X
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_9transform_lambda6(PyObject *__pyx_self, PyObject *__pyx_v_x); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19NotStopsTransformer_9transform_lambda6 = {"lambda6", (PyCFunction)__pyx_pw_5trans_19NotStopsTransformer_9transform_lambda6, METH_O, 0};
static PyObject *__pyx_pw_5trans_19NotStopsTransformer_9transform_lambda6(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("lambda6 (wrapper)", 0);
  __pyx_r = __pyx_lambda_funcdef_lambda6(__pyx_self, ((PyObject *)__pyx_v_x));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_lambda_funcdef_lambda6(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_8genexpr3__pyx_v_t = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  Py_ssize_t __pyx_t_5;
  PyObject *(*__pyx_t_6)(PyObject *);
  int __pyx_t_7;
  int __pyx_t_8;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("lambda6", 0);
  __Pyx_XDECREF(__pyx_r);
  { /* enter inner scope */
    __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 184, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_x, __pyx_n_s_split); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 184, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_4, __pyx_kp_u_) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_u_);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L5_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (likely(PyList_CheckExact(__pyx_t_2)) || PyTuple_CheckExact(__pyx_t_2)) {
      __pyx_t_3 = __pyx_t_2; __Pyx_INCREF(__pyx_t_3); __pyx_t_5 = 0;
      __pyx_t_6 = NULL;
    } else {
      __pyx_t_5 = -1; __pyx_t_3 = PyObject_GetIter(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 184, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_6 = Py_TYPE(__pyx_t_3)->tp_iternext; if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 184, __pyx_L5_error)
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    for (;;) {
      if (likely(!__pyx_t_6)) {
        if (likely(PyList_CheckExact(__pyx_t_3))) {
          if (__pyx_t_5 >= PyList_GET_SIZE(__pyx_t_3)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_2 = PyList_GET_ITEM(__pyx_t_3, __pyx_t_5); __Pyx_INCREF(__pyx_t_2); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 184, __pyx_L5_error)
          #else
          __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_2);
          #endif
        } else {
          if (__pyx_t_5 >= PyTuple_GET_SIZE(__pyx_t_3)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_3, __pyx_t_5); __Pyx_INCREF(__pyx_t_2); __pyx_t_5++; if (unlikely(0 < 0)) __PYX_ERR(0, 184, __pyx_L5_error)
          #else
          __pyx_t_2 = PySequence_ITEM(__pyx_t_3, __pyx_t_5); __pyx_t_5++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L5_error)
          __Pyx_GOTREF(__pyx_t_2);
          #endif
        }
      } else {
        __pyx_t_2 = __pyx_t_6(__pyx_t_3);
        if (unlikely(!__pyx_t_2)) {
          PyObject* exc_type = PyErr_Occurred();
          if (exc_type) {
            if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
            else __PYX_ERR(0, 184, __pyx_L5_error)
          }
          break;
        }
        __Pyx_GOTREF(__pyx_t_2);
      }
      __Pyx_XDECREF_SET(__pyx_8genexpr3__pyx_v_t, __pyx_t_2);
      __pyx_t_2 = 0;
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_stopwords); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_2);
      __pyx_t_7 = (__Pyx_PySequence_ContainsTF(__pyx_8genexpr3__pyx_v_t, __pyx_t_2, Py_NE)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 184, __pyx_L5_error)
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __pyx_t_8 = (__pyx_t_7 != 0);
      if (__pyx_t_8) {
        if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_8genexpr3__pyx_v_t))) __PYX_ERR(0, 184, __pyx_L5_error)
      }
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_t); __pyx_8genexpr3__pyx_v_t = 0;
    goto __pyx_L9_exit_scope;
    __pyx_L5_error:;
    __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_t); __pyx_8genexpr3__pyx_v_t = 0;
    goto __pyx_L1_error;
    __pyx_L9_exit_scope:;
  } /* exit inner scope */
  __pyx_t_5 = PyList_GET_SIZE(__pyx_t_1); if (unlikely(__pyx_t_5 == ((Py_ssize_t)-1))) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyInt_FromSsize_t(__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.NotStopsTransformer.transform.lambda6", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_8genexpr3__pyx_v_t);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":183
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))
 *         return X
 */

static PyObject *__pyx_pf_5trans_19NotStopsTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":184
 *
 *     def transform(self, X):
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))             # <<<<<<<<<<<<<<
 *         return X
 *
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_col); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_apply); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19NotStopsTransformer_9transform_lambda6, 0, __pyx_n_s_NotStopsTransformer_transform_lo, NULL, __pyx_n_s_trans, __pyx_d, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(PyObject_SetItem(__pyx_v_X, __pyx_n_u_not_stops, __pyx_t_1) < 0)) __PYX_ERR(0, 184, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":185
 *     def transform(self, X):
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":183
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))
 *         return X
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.NotStopsTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":190
 * class CommaLenRatio(BaseEstimator, TransformerMixin):
 *     """ Hard-coded experimental feature. N.B. This is an entropy source. """
 *     def __init__(self, col=None): # text col is ignored in non-measured feature.             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13CommaLenRatio_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13CommaLenRatio_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13CommaLenRatio_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13CommaLenRatio_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_col = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,0};
    PyObject* values[2] = {0,0};
    values[1] = ((PyObject *)((PyObject *)Py_None));
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
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col);
          if (value) { values[1] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 190, __pyx_L3_error)
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
    __pyx_v_col = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 190, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CommaLenRatio.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13CommaLenRatio___init__(__pyx_self, __pyx_v_self, __pyx_v_col);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13CommaLenRatio___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_col) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":193
 *         pass
 *
 *     def divide(self, x, y):             # <<<<<<<<<<<<<<
 *         if y != 0:
 *             return x//y
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13CommaLenRatio_3divide(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13CommaLenRatio_3divide = {"divide", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13CommaLenRatio_3divide, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13CommaLenRatio_3divide(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_x = 0;
  PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("divide (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_x,&__pyx_n_s_y,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_x)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("divide", 1, 3, 3, 1); __PYX_ERR(0, 193, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("divide", 1, 3, 3, 2); __PYX_ERR(0, 193, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "divide") < 0)) __PYX_ERR(0, 193, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 3) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
    }
    __pyx_v_self = values[0];
    __pyx_v_x = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("divide", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 193, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CommaLenRatio.divide", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13CommaLenRatio_2divide(__pyx_self, __pyx_v_self, __pyx_v_x, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13CommaLenRatio_2divide(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_x, PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("divide", 0);

  /* "trans.py":194
 *
 *     def divide(self, x, y):
 *         if y != 0:             # <<<<<<<<<<<<<<
 *             return x//y
 *         else:
 */
  __pyx_t_1 = __Pyx_PyInt_NeObjC(__pyx_v_y, __pyx_int_0, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_2) {

    /* "trans.py":195
 *     def divide(self, x, y):
 *         if y != 0:
 *             return x//y             # <<<<<<<<<<<<<<
 *         else:
 *             return 0
 */
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_1 = PyNumber_FloorDivide(__pyx_v_x, __pyx_v_y); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 195, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    /* "trans.py":194
 *
 *     def divide(self, x, y):
 *         if y != 0:             # <<<<<<<<<<<<<<
 *             return x//y
 *         else:
 */
  }

  /* "trans.py":197
 *             return x//y
 *         else:
 *             return 0             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  /*else*/ {
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(__pyx_int_0);
    __pyx_r = __pyx_int_0;
    goto __pyx_L0;
  }

  /* "trans.py":193
 *         pass
 *
 *     def divide(self, x, y):             # <<<<<<<<<<<<<<
 *         if y != 0:
 *             return x//y
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("trans.CommaLenRatio.divide", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":199
 *             return 0
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13CommaLenRatio_5fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13CommaLenRatio_5fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13CommaLenRatio_5fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13CommaLenRatio_5fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 199, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 199, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 199, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CommaLenRatio.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13CommaLenRatio_4fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13CommaLenRatio_4fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":200
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":199
 *             return 0
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":202
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13CommaLenRatio_7transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13CommaLenRatio_7transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13CommaLenRatio_7transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13CommaLenRatio_7transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 202, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 202, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 202, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.CommaLenRatio.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13CommaLenRatio_6transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":203
 *
 *     def transform(self, X):
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)             # <<<<<<<<<<<<<<
 *
 *         return X
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13CommaLenRatio_9transform_lambda7(PyObject *__pyx_self, PyObject *__pyx_v_x); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13CommaLenRatio_9transform_lambda7 = {"lambda7", (PyCFunction)__pyx_pw_5trans_13CommaLenRatio_9transform_lambda7, METH_O, 0};
static PyObject *__pyx_pw_5trans_13CommaLenRatio_9transform_lambda7(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("lambda7 (wrapper)", 0);
  __pyx_r = __pyx_lambda_funcdef_lambda7(__pyx_self, ((PyObject *)__pyx_v_x));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_lambda_funcdef_lambda7(PyObject *__pyx_self, PyObject *__pyx_v_x) {
  struct __pyx_obj_5trans___pyx_scope_struct_2_transform *__pyx_cur_scope;
  struct __pyx_obj_5trans___pyx_scope_struct_2_transform *__pyx_outer_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("lambda7", 0);
  __pyx_outer_scope = (struct __pyx_obj_5trans___pyx_scope_struct_2_transform *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;
  __Pyx_XDECREF(__pyx_r);
  if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 203, __pyx_L1_error) }
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_divide); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PySequence_Tuple(__pyx_v_x); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_2, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.CommaLenRatio.transform.lambda7", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":202
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)
 *
 */

static PyObject *__pyx_pf_5trans_13CommaLenRatio_6transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  struct __pyx_obj_5trans___pyx_scope_struct_2_transform *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_2_transform *)__pyx_tp_new_5trans___pyx_scope_struct_2_transform(__pyx_ptype_5trans___pyx_scope_struct_2_transform, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_2_transform *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 202, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_self = __pyx_v_self;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_self);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_self);

  /* "trans.py":203
 *
 *     def transform(self, X):
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)             # <<<<<<<<<<<<<<
 *
 *         return X
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_sen_len);
  __Pyx_GIVEREF(__pyx_n_u_sen_len);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_u_sen_len);
  __Pyx_INCREF(__pyx_n_u_count_commas);
  __Pyx_GIVEREF(__pyx_n_u_count_commas);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_count_commas);
  __pyx_t_2 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_apply); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13CommaLenRatio_9transform_lambda7, 0, __pyx_n_s_CommaLenRatio_transform_locals_l, ((PyObject*)__pyx_cur_scope), __pyx_n_s_trans, __pyx_d, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_axis, __pyx_int_1) < 0) __PYX_ERR(0, 203, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(PyObject_SetItem(__pyx_v_X, __pyx_n_u_comma_len_ratio, __pyx_t_4) < 0)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":205
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)
 *
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":202
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.CommaLenRatio.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":212
 * class BooleanTargets(BaseEstimator, TransformerMixin):
 *     """ Converts binary classification labels to boolean values. (In place, does not add new column.) """
 *     def __init__(self, col, tar1, tar2):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         self.a = tar1
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14BooleanTargets_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14BooleanTargets_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14BooleanTargets_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14BooleanTargets_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_col = 0;
  PyObject *__pyx_v_tar1 = 0;
  PyObject *__pyx_v_tar2 = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_col,&__pyx_n_s_tar1,&__pyx_n_s_tar2,0};
    PyObject* values[4] = {0,0,0,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_col)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, 1); __PYX_ERR(0, 212, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_tar1)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, 2); __PYX_ERR(0, 212, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_tar2)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, 3); __PYX_ERR(0, 212, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 212, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 4) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
    }
    __pyx_v_self = values[0];
    __pyx_v_col = values[1];
    __pyx_v_tar1 = values[2];
    __pyx_v_tar2 = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 212, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.BooleanTargets.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14BooleanTargets___init__(__pyx_self, __pyx_v_self, __pyx_v_col, __pyx_v_tar1, __pyx_v_tar2);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14BooleanTargets___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_col, PyObject *__pyx_v_tar1, PyObject *__pyx_v_tar2) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":213
 *     """ Converts binary classification labels to boolean values. (In place, does not add new column.) """
 *     def __init__(self, col, tar1, tar2):
 *         self.col = col             # <<<<<<<<<<<<<<
 *         self.a = tar1
 *         self.b = tar2
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_col, __pyx_v_col) < 0) __PYX_ERR(0, 213, __pyx_L1_error)

  /* "trans.py":214
 *     def __init__(self, col, tar1, tar2):
 *         self.col = col
 *         self.a = tar1             # <<<<<<<<<<<<<<
 *         self.b = tar2
 *
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_a, __pyx_v_tar1) < 0) __PYX_ERR(0, 214, __pyx_L1_error)

  /* "trans.py":215
 *         self.col = col
 *         self.a = tar1
 *         self.b = tar2             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_b, __pyx_v_tar2) < 0) __PYX_ERR(0, 215, __pyx_L1_error)

  /* "trans.py":212
 * class BooleanTargets(BaseEstimator, TransformerMixin):
 *     """ Converts binary classification labels to boolean values. (In place, does not add new column.) """
 *     def __init__(self, col, tar1, tar2):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         self.a = tar1
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.BooleanTargets.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":217
 *         self.b = tar2
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14BooleanTargets_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14BooleanTargets_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14BooleanTargets_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14BooleanTargets_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 217, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 217, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 217, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.BooleanTargets.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14BooleanTargets_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14BooleanTargets_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":218
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":217
 *         self.b = tar2
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":220
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         target = self.col
 *         X.loc[(X.target == self.a), target] = 0
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_14BooleanTargets_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_14BooleanTargets_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_14BooleanTargets_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_14BooleanTargets_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 220, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 220, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 220, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.BooleanTargets.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_14BooleanTargets_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_14BooleanTargets_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_v_target = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":221
 *
 *     def transform(self, X):
 *         target = self.col             # <<<<<<<<<<<<<<
 *         X.loc[(X.target == self.a), target] = 0
 *         X.loc[(X.target == self.b), target] = 1
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_col); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 221, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_target = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "trans.py":222
 *     def transform(self, X):
 *         target = self.col
 *         X.loc[(X.target == self.a), target] = 0             # <<<<<<<<<<<<<<
 *         X.loc[(X.target == self.b), target] = 1
 *         return X
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_loc); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_target); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_a); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = PyObject_RichCompare(__pyx_t_2, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_4);
  __Pyx_INCREF(__pyx_v_target);
  __Pyx_GIVEREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_v_target);
  __pyx_t_4 = 0;
  if (unlikely(PyObject_SetItem(__pyx_t_1, __pyx_t_3, __pyx_int_0) < 0)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":223
 *         target = self.col
 *         X.loc[(X.target == self.a), target] = 0
 *         X.loc[(X.target == self.b), target] = 1             # <<<<<<<<<<<<<<
 *         return X
 *
 */
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_loc); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_target); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_b); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = PyObject_RichCompare(__pyx_t_1, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_2);
  __Pyx_INCREF(__pyx_v_target);
  __Pyx_GIVEREF(__pyx_v_target);
  PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_v_target);
  __pyx_t_2 = 0;
  if (unlikely(PyObject_SetItem(__pyx_t_3, __pyx_t_4, __pyx_int_1) < 0)) __PYX_ERR(0, 223, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":224
 *         X.loc[(X.target == self.a), target] = 0
 *         X.loc[(X.target == self.b), target] = 1
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":220
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         target = self.col
 *         X.loc[(X.target == self.a), target] = 0
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.BooleanTargets.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_target);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":230
 *
 * class PandasTransformer(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_17PandasTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_17PandasTransformer_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_17PandasTransformer_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_17PandasTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_fn = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_fn,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_fn)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, 1); __PYX_ERR(0, 230, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 230, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_fn = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 230, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.PandasTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_17PandasTransformer___init__(__pyx_self, __pyx_v_self, __pyx_v_fn);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_17PandasTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_fn) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":231
 * class PandasTransformer(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):
 *         self.fn = fn             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_fn, __pyx_v_fn) < 0) __PYX_ERR(0, 231, __pyx_L1_error)

  /* "trans.py":230
 *
 * class PandasTransformer(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.PandasTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":233
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_17PandasTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_17PandasTransformer_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_17PandasTransformer_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_17PandasTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 233, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 233, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 233, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.PandasTransformer.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_17PandasTransformer_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_17PandasTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":234
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X, y=None, copy=None):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":233
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":236
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fn(X)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_17PandasTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_17PandasTransformer_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_17PandasTransformer_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_17PandasTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  CYTHON_UNUSED PyObject *__pyx_v_copy = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,&__pyx_n_s_copy,0};
    PyObject* values[4] = {0,0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
    values[3] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("transform", 0, 2, 4, 1); __PYX_ERR(0, 236, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_copy);
          if (value) { values[3] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 236, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
    __pyx_v_copy = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("transform", 0, 2, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 236, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.PandasTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_17PandasTransformer_4transform(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y, __pyx_v_copy);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_17PandasTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_copy) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":237
 *
 *     def transform(self, X, y=None, copy=None):
 *         return self.fn(X)             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_fn); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 237, __pyx_L1_error)
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
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_X) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_X);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 237, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "trans.py":236
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fn(X)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.PandasTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":242
 * class PandasFeatureUnion(FeatureUnion):
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_18PandasFeatureUnion_1fit_transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_18PandasFeatureUnion_1fit_transform = {"fit_transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_18PandasFeatureUnion_1fit_transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_18PandasFeatureUnion_1fit_transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  PyObject *__pyx_v_y = 0;
  PyObject *__pyx_v_fit_params = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit_transform (wrapper)", 0);
  __pyx_v_fit_params = PyDict_New(); if (unlikely(!__pyx_v_fit_params)) return NULL;
  __Pyx_GOTREF(__pyx_v_fit_params);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit_transform", 0, 2, 3, 1); __PYX_ERR(0, 242, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, __pyx_v_fit_params, values, pos_args, "fit_transform") < 0)) __PYX_ERR(0, 242, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit_transform", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 242, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_CLEAR(__pyx_v_fit_params);
  __Pyx_AddTraceback("trans.PandasFeatureUnion.fit_transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_18PandasFeatureUnion_fit_transform(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y, __pyx_v_fit_params);

  /* function exit code */
  __Pyx_XDECREF(__pyx_v_fit_params);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_13fit_transform_2generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); /* proto */

/* "trans.py":245
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */

static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_13fit_transform_genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *)__pyx_tp_new_5trans___pyx_scope_struct_4_genexpr(__pyx_ptype_5trans___pyx_scope_struct_4_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 245, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_5trans_18PandasFeatureUnion_13fit_transform_2generator1, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_PandasFeatureUnion_fit_transform, __pyx_n_s_trans); if (unlikely(!gen)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.PandasFeatureUnion.fit_transform.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_13fit_transform_2generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) /* generator body */
{
  struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *__pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *(*__pyx_t_9)(PyObject *);
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L8_resume_from_yield;
    default: /* CPython raises the right error here */
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 245, __pyx_L1_error)

  /* "trans.py":251
 *                 weight=weight,
 *                 **fit_params)
 *             for name, trans, weight in self._iter())             # <<<<<<<<<<<<<<
 *
 *         if not result:
 */
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 251, __pyx_L1_error) }
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_self, __pyx_n_s_iter); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 251, __pyx_L1_error)
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
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 251, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 251, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 251, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 251, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 251, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 251, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_5(__pyx_t_2);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 251, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    if ((likely(PyTuple_CheckExact(__pyx_t_1))) || (PyList_CheckExact(__pyx_t_1))) {
      PyObject* sequence = __pyx_t_1;
      Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
      if (unlikely(size != 3)) {
        if (size > 3) __Pyx_RaiseTooManyValuesError(3);
        else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
        __PYX_ERR(0, 251, __pyx_L1_error)
      }
      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
      if (likely(PyTuple_CheckExact(sequence))) {
        __pyx_t_3 = PyTuple_GET_ITEM(sequence, 0);
        __pyx_t_6 = PyTuple_GET_ITEM(sequence, 1);
        __pyx_t_7 = PyTuple_GET_ITEM(sequence, 2);
      } else {
        __pyx_t_3 = PyList_GET_ITEM(sequence, 0);
        __pyx_t_6 = PyList_GET_ITEM(sequence, 1);
        __pyx_t_7 = PyList_GET_ITEM(sequence, 2);
      }
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      #else
      __pyx_t_3 = PySequence_ITEM(sequence, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 251, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_6 = PySequence_ITEM(sequence, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 251, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_7 = PySequence_ITEM(sequence, 2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 251, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      #endif
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    } else {
      Py_ssize_t index = -1;
      __pyx_t_8 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 251, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_9 = Py_TYPE(__pyx_t_8)->tp_iternext;
      index = 0; __pyx_t_3 = __pyx_t_9(__pyx_t_8); if (unlikely(!__pyx_t_3)) goto __pyx_L6_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_3);
      index = 1; __pyx_t_6 = __pyx_t_9(__pyx_t_8); if (unlikely(!__pyx_t_6)) goto __pyx_L6_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_6);
      index = 2; __pyx_t_7 = __pyx_t_9(__pyx_t_8); if (unlikely(!__pyx_t_7)) goto __pyx_L6_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_7);
      if (__Pyx_IternextUnpackEndCheck(__pyx_t_9(__pyx_t_8), 3) < 0) __PYX_ERR(0, 251, __pyx_L1_error)
      __pyx_t_9 = NULL;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      goto __pyx_L7_unpacking_done;
      __pyx_L6_unpacking_failed:;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __pyx_t_9 = NULL;
      if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
      __PYX_ERR(0, 251, __pyx_L1_error)
      __pyx_L7_unpacking_done:;
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_name);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_name, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_trans);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_trans, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_6);
    __pyx_t_6 = 0;
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_weight);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_weight, __pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    __pyx_t_7 = 0;

    /* "trans.py":245
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_delayed); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_fit_transform_one); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_3 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_3, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_6);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

    /* "trans.py":246
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(
 *                 transformer=trans,             # <<<<<<<<<<<<<<
 *                 X=X,
 *                 y=y,
 */
    __pyx_t_6 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 246, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_transformer, __pyx_cur_scope->__pyx_v_trans) < 0) __PYX_ERR(0, 246, __pyx_L1_error)

    /* "trans.py":247
 *             delayed(_fit_transform_one)(
 *                 transformer=trans,
 *                 X=X,             # <<<<<<<<<<<<<<
 *                 y=y,
 *                 weight=weight,
 */
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_X)) { __Pyx_RaiseClosureNameError("X"); __PYX_ERR(0, 247, __pyx_L1_error) }
    if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_X, __pyx_cur_scope->__pyx_outer_scope->__pyx_v_X) < 0) __PYX_ERR(0, 246, __pyx_L1_error)

    /* "trans.py":248
 *                 transformer=trans,
 *                 X=X,
 *                 y=y,             # <<<<<<<<<<<<<<
 *                 weight=weight,
 *                 **fit_params)
 */
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_y)) { __Pyx_RaiseClosureNameError("y"); __PYX_ERR(0, 248, __pyx_L1_error) }
    if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_y, __pyx_cur_scope->__pyx_outer_scope->__pyx_v_y) < 0) __PYX_ERR(0, 246, __pyx_L1_error)

    /* "trans.py":249
 *                 X=X,
 *                 y=y,
 *                 weight=weight,             # <<<<<<<<<<<<<<
 *                 **fit_params)
 *             for name, trans, weight in self._iter())
 */
    if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_weight, __pyx_cur_scope->__pyx_v_weight) < 0) __PYX_ERR(0, 246, __pyx_L1_error)
    __pyx_t_7 = __pyx_t_6;
    __pyx_t_6 = 0;

    /* "trans.py":250
 *                 y=y,
 *                 weight=weight,
 *                 **fit_params)             # <<<<<<<<<<<<<<
 *             for name, trans, weight in self._iter())
 *
 */
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_fit_params)) { __Pyx_RaiseClosureNameError("fit_params"); __PYX_ERR(0, 250, __pyx_L1_error) }
    if (unlikely(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_fit_params == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "argument after ** must be a mapping, not NoneType");
      __PYX_ERR(0, 250, __pyx_L1_error)
    }
    if (__Pyx_MergeKeywords(__pyx_t_7, __pyx_cur_scope->__pyx_outer_scope->__pyx_v_fit_params) < 0) __PYX_ERR(0, 250, __pyx_L1_error)

    /* "trans.py":245
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
    __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_7); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_r = __pyx_t_6;
    __pyx_t_6 = 0;
    __Pyx_XGIVEREF(__pyx_t_2);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_2;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_4;
    __pyx_cur_scope->__pyx_t_2 = __pyx_t_5;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    /* return from generator, yielding value */
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L8_resume_from_yield:;
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_2);
    __pyx_t_4 = __pyx_cur_scope->__pyx_t_1;
    __pyx_t_5 = __pyx_cur_scope->__pyx_t_2;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 245, __pyx_L1_error)

    /* "trans.py":251
 *                 weight=weight,
 *                 **fit_params)
 *             for name, trans, weight in self._iter())             # <<<<<<<<<<<<<<
 *
 *         if not result:
 */
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  /* "trans.py":245
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */

  /* function exit code */
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_13fit_transform_5generator2(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); /* proto */

/* "trans.py":258
 *         Xs, transformers = zip(*result)
 *         self._update_transformer_list(transformers)
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */

static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_13fit_transform_3genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *)__pyx_tp_new_5trans___pyx_scope_struct_5_genexpr(__pyx_ptype_5trans___pyx_scope_struct_5_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 258, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_5trans_18PandasFeatureUnion_13fit_transform_5generator2, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_PandasFeatureUnion_fit_transform, __pyx_n_s_trans); if (unlikely(!gen)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.PandasFeatureUnion.fit_transform.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_13fit_transform_5generator2(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) /* generator body */
{
  struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *__pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *(*__pyx_t_3)(PyObject *);
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    default: /* CPython raises the right error here */
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 258, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs)) { __Pyx_RaiseClosureNameError("Xs"); __PYX_ERR(0, 258, __pyx_L1_error) }
  if (likely(PyList_CheckExact(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs)) || PyTuple_CheckExact(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs)) {
    __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 258, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 258, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 258, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 258, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 258, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 258, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_f);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_f, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_sparse); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_issparse); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_6);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_6, function);
      }
    }
    __pyx_t_4 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_5, __pyx_cur_scope->__pyx_v_f) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_cur_scope->__pyx_v_f);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__pyx_t_7) {
      __Pyx_XDECREF(__pyx_r);
      __Pyx_INCREF(Py_True);
      __pyx_r = Py_True;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L0;
    }
  }
  /*else*/ {
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(Py_False);
    __pyx_r = Py_False;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    goto __pyx_L0;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":242
 * class PandasFeatureUnion(FeatureUnion):
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 */

static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_fit_transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, PyObject *__pyx_v_y, PyObject *__pyx_v_fit_params) {
  struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *__pyx_cur_scope;
  PyObject *__pyx_v_result = NULL;
  PyObject *__pyx_v_transformers = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  int __pyx_t_6;
  PyObject *(*__pyx_t_7)(PyObject *);
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("fit_transform", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *)__pyx_tp_new_5trans___pyx_scope_struct_3_fit_transform(__pyx_ptype_5trans___pyx_scope_struct_3_fit_transform, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 242, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_self = __pyx_v_self;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_self);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_self);
  __pyx_cur_scope->__pyx_v_X = __pyx_v_X;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_X);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_X);
  __pyx_cur_scope->__pyx_v_y = __pyx_v_y;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_y);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_y);
  __pyx_cur_scope->__pyx_v_fit_params = __pyx_v_fit_params;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_fit_params);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_fit_params);

  /* "trans.py":243
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):
 *         self._validate_transformers()             # <<<<<<<<<<<<<<
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_validate_transformers); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 243, __pyx_L1_error)
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
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 243, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":244
 *     def fit_transform(self, X, y=None, **fit_params):
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(             # <<<<<<<<<<<<<<
 *             delayed(_fit_transform_one)(
 *                 transformer=trans,
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Parallel); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_n_jobs); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_n_jobs, __pyx_t_4) < 0) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":245
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_fit_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
  __pyx_t_3 = __pyx_pf_5trans_18PandasFeatureUnion_13fit_transform_genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_result = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "trans.py":253
 *             for name, trans, weight in self._iter())
 *
 *         if not result:             # <<<<<<<<<<<<<<
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 */
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_v_result); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 253, __pyx_L1_error)
  __pyx_t_6 = ((!__pyx_t_5) != 0);
  if (__pyx_t_6) {

    /* "trans.py":255
 *         if not result:
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))             # <<<<<<<<<<<<<<
 *         Xs, transformers = zip(*result)
 *         self._update_transformer_list(transformers)
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_np); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 255, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_zeros); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 255, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_X, __pyx_n_s_shape); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 255, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 255, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 255, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_2);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_int_0);
    __pyx_t_2 = 0;
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
    __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 255, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    /* "trans.py":253
 *             for name, trans, weight in self._iter())
 *
 *         if not result:             # <<<<<<<<<<<<<<
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 */
  }

  /* "trans.py":256
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 *         Xs, transformers = zip(*result)             # <<<<<<<<<<<<<<
 *         self._update_transformer_list(transformers)
 *         if any(sparse.issparse(f) for f in Xs):
 */
  __pyx_t_1 = __Pyx_PySequence_Tuple(__pyx_v_result); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_zip, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if ((likely(PyTuple_CheckExact(__pyx_t_3))) || (PyList_CheckExact(__pyx_t_3))) {
    PyObject* sequence = __pyx_t_3;
    Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
    if (unlikely(size != 2)) {
      if (size > 2) __Pyx_RaiseTooManyValuesError(2);
      else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
      __PYX_ERR(0, 256, __pyx_L1_error)
    }
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    if (likely(PyTuple_CheckExact(sequence))) {
      __pyx_t_1 = PyTuple_GET_ITEM(sequence, 0);
      __pyx_t_4 = PyTuple_GET_ITEM(sequence, 1);
    } else {
      __pyx_t_1 = PyList_GET_ITEM(sequence, 0);
      __pyx_t_4 = PyList_GET_ITEM(sequence, 1);
    }
    __Pyx_INCREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_t_4);
    #else
    __pyx_t_1 = PySequence_ITEM(sequence, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_4 = PySequence_ITEM(sequence, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    #endif
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else {
    Py_ssize_t index = -1;
    __pyx_t_2 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 256, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_7 = Py_TYPE(__pyx_t_2)->tp_iternext;
    index = 0; __pyx_t_1 = __pyx_t_7(__pyx_t_2); if (unlikely(!__pyx_t_1)) goto __pyx_L4_unpacking_failed;
    __Pyx_GOTREF(__pyx_t_1);
    index = 1; __pyx_t_4 = __pyx_t_7(__pyx_t_2); if (unlikely(!__pyx_t_4)) goto __pyx_L4_unpacking_failed;
    __Pyx_GOTREF(__pyx_t_4);
    if (__Pyx_IternextUnpackEndCheck(__pyx_t_7(__pyx_t_2), 2) < 0) __PYX_ERR(0, 256, __pyx_L1_error)
    __pyx_t_7 = NULL;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    goto __pyx_L5_unpacking_done;
    __pyx_L4_unpacking_failed:;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_7 = NULL;
    if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
    __PYX_ERR(0, 256, __pyx_L1_error)
    __pyx_L5_unpacking_done:;
  }
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_Xs = __pyx_t_1;
  __pyx_t_1 = 0;
  __pyx_v_transformers = __pyx_t_4;
  __pyx_t_4 = 0;

  /* "trans.py":257
 *             return np.zeros((X.shape[0], 0))
 *         Xs, transformers = zip(*result)
 *         self._update_transformer_list(transformers)             # <<<<<<<<<<<<<<
 *         if any(sparse.issparse(f) for f in Xs):
 *             Xs = sparse.hstack(Xs).tocsr()
 */
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_update_transformer_list); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 257, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_1, __pyx_v_transformers) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_transformers);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 257, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":258
 *         Xs, transformers = zip(*result)
 *         self._update_transformer_list(transformers)
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */
  __pyx_t_3 = __pyx_pf_5trans_18PandasFeatureUnion_13fit_transform_3genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 258, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_Generator_Next(__pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 258, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 258, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__pyx_t_6) {

    /* "trans.py":259
 *         self._update_transformer_list(transformers)
 *         if any(sparse.issparse(f) for f in Xs):
 *             Xs = sparse.hstack(Xs).tocsr()             # <<<<<<<<<<<<<<
 *         else:
 *             Xs = self.merge_dataframes_by_column(Xs)
 */
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sparse); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 259, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_hstack); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 259, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
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
    __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_1, __pyx_cur_scope->__pyx_v_Xs) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_cur_scope->__pyx_v_Xs);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 259, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_tocsr); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 259, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
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
    __pyx_t_4 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 259, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_Xs);
    __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_Xs, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    __pyx_t_4 = 0;

    /* "trans.py":258
 *         Xs, transformers = zip(*result)
 *         self._update_transformer_list(transformers)
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */
    goto __pyx_L6;
  }

  /* "trans.py":261
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 *             Xs = self.merge_dataframes_by_column(Xs)             # <<<<<<<<<<<<<<
 *         return Xs
 *
 */
  /*else*/ {
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_merge_dataframes_by_column); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 261, __pyx_L1_error)
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
    __pyx_t_4 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_cur_scope->__pyx_v_Xs) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_cur_scope->__pyx_v_Xs);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 261, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_Xs);
    __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_Xs, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    __pyx_t_4 = 0;
  }
  __pyx_L6:;

  /* "trans.py":262
 *         else:
 *             Xs = self.merge_dataframes_by_column(Xs)
 *         return Xs             # <<<<<<<<<<<<<<
 *
 *     def merge_dataframes_by_column(self, Xs):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_Xs);
  __pyx_r = __pyx_cur_scope->__pyx_v_Xs;
  goto __pyx_L0;

  /* "trans.py":242
 * class PandasFeatureUnion(FeatureUnion):
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.PandasFeatureUnion.fit_transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_result);
  __Pyx_XDECREF(__pyx_v_transformers);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":264
 *         return Xs
 *
 *     def merge_dataframes_by_column(self, Xs):             # <<<<<<<<<<<<<<
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_18PandasFeatureUnion_3merge_dataframes_by_column(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_18PandasFeatureUnion_3merge_dataframes_by_column = {"merge_dataframes_by_column", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_18PandasFeatureUnion_3merge_dataframes_by_column, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_18PandasFeatureUnion_3merge_dataframes_by_column(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_Xs = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("merge_dataframes_by_column (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_Xs,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_Xs)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("merge_dataframes_by_column", 1, 2, 2, 1); __PYX_ERR(0, 264, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "merge_dataframes_by_column") < 0)) __PYX_ERR(0, 264, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_Xs = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("merge_dataframes_by_column", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 264, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.PandasFeatureUnion.merge_dataframes_by_column", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_18PandasFeatureUnion_2merge_dataframes_by_column(__pyx_self, __pyx_v_self, __pyx_v_Xs);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_2merge_dataframes_by_column(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_Xs) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("merge_dataframes_by_column", 0);

  /* "trans.py":265
 *
 *     def merge_dataframes_by_column(self, Xs):
 *         return pd.concat(Xs, axis="columns", copy=False)             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_pd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_concat); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_Xs);
  __Pyx_GIVEREF(__pyx_v_Xs);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_Xs);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_axis, __pyx_n_u_columns) < 0) __PYX_ERR(0, 265, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_copy, Py_False) < 0) __PYX_ERR(0, 265, __pyx_L1_error)
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_4;
  __pyx_t_4 = 0;
  goto __pyx_L0;

  /* "trans.py":264
 *         return Xs
 *
 *     def merge_dataframes_by_column(self, Xs):             # <<<<<<<<<<<<<<
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.PandasFeatureUnion.merge_dataframes_by_column", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":267
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_18PandasFeatureUnion_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_18PandasFeatureUnion_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_18PandasFeatureUnion_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_18PandasFeatureUnion_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 267, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 267, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 267, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.PandasFeatureUnion.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_18PandasFeatureUnion_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_9transform_2generator3(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); /* proto */

/* "trans.py":269
 *     def transform(self, X):
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */

static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_9transform_genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *)__pyx_tp_new_5trans___pyx_scope_struct_7_genexpr(__pyx_ptype_5trans___pyx_scope_struct_7_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 269, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_5trans___pyx_scope_struct_6_transform *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_5trans_18PandasFeatureUnion_9transform_2generator3, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_PandasFeatureUnion_transform_loc, __pyx_n_s_trans); if (unlikely(!gen)) __PYX_ERR(0, 269, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.PandasFeatureUnion.transform.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_9transform_2generator3(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) /* generator body */
{
  struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *__pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  Py_ssize_t __pyx_t_4;
  PyObject *(*__pyx_t_5)(PyObject *);
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *(*__pyx_t_9)(PyObject *);
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L8_resume_from_yield;
    default: /* CPython raises the right error here */
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 269, __pyx_L1_error)

  /* "trans.py":274
 *                 y=None,
 *                 weight=weight)
 *             for name, trans, weight in self._iter())             # <<<<<<<<<<<<<<
 *         if not Xs:
 *             # All transformers are None
 */
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 274, __pyx_L1_error) }
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_self, __pyx_n_s_iter); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 274, __pyx_L1_error)
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
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_4 = 0;
    __pyx_t_5 = NULL;
  } else {
    __pyx_t_4 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 274, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_5 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 274, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_5)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_4 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 274, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 274, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_4 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_4); __Pyx_INCREF(__pyx_t_1); __pyx_t_4++; if (unlikely(0 < 0)) __PYX_ERR(0, 274, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_4); __pyx_t_4++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 274, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_5(__pyx_t_2);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 274, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    if ((likely(PyTuple_CheckExact(__pyx_t_1))) || (PyList_CheckExact(__pyx_t_1))) {
      PyObject* sequence = __pyx_t_1;
      Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
      if (unlikely(size != 3)) {
        if (size > 3) __Pyx_RaiseTooManyValuesError(3);
        else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
        __PYX_ERR(0, 274, __pyx_L1_error)
      }
      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
      if (likely(PyTuple_CheckExact(sequence))) {
        __pyx_t_3 = PyTuple_GET_ITEM(sequence, 0);
        __pyx_t_6 = PyTuple_GET_ITEM(sequence, 1);
        __pyx_t_7 = PyTuple_GET_ITEM(sequence, 2);
      } else {
        __pyx_t_3 = PyList_GET_ITEM(sequence, 0);
        __pyx_t_6 = PyList_GET_ITEM(sequence, 1);
        __pyx_t_7 = PyList_GET_ITEM(sequence, 2);
      }
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      #else
      __pyx_t_3 = PySequence_ITEM(sequence, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 274, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_6 = PySequence_ITEM(sequence, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 274, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_7 = PySequence_ITEM(sequence, 2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 274, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      #endif
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    } else {
      Py_ssize_t index = -1;
      __pyx_t_8 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 274, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_9 = Py_TYPE(__pyx_t_8)->tp_iternext;
      index = 0; __pyx_t_3 = __pyx_t_9(__pyx_t_8); if (unlikely(!__pyx_t_3)) goto __pyx_L6_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_3);
      index = 1; __pyx_t_6 = __pyx_t_9(__pyx_t_8); if (unlikely(!__pyx_t_6)) goto __pyx_L6_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_6);
      index = 2; __pyx_t_7 = __pyx_t_9(__pyx_t_8); if (unlikely(!__pyx_t_7)) goto __pyx_L6_unpacking_failed;
      __Pyx_GOTREF(__pyx_t_7);
      if (__Pyx_IternextUnpackEndCheck(__pyx_t_9(__pyx_t_8), 3) < 0) __PYX_ERR(0, 274, __pyx_L1_error)
      __pyx_t_9 = NULL;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      goto __pyx_L7_unpacking_done;
      __pyx_L6_unpacking_failed:;
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __pyx_t_9 = NULL;
      if (__Pyx_IterFinish() == 0) __Pyx_RaiseNeedMoreValuesError(index);
      __PYX_ERR(0, 274, __pyx_L1_error)
      __pyx_L7_unpacking_done:;
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_name);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_name, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_trans);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_trans, __pyx_t_6);
    __Pyx_GIVEREF(__pyx_t_6);
    __pyx_t_6 = 0;
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_weight);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_weight, __pyx_t_7);
    __Pyx_GIVEREF(__pyx_t_7);
    __pyx_t_7 = 0;

    /* "trans.py":269
 *     def transform(self, X):
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
    __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_delayed); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 269, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_transform_one); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 269, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_3 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_3, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_6);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 269, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

    /* "trans.py":270
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(
 *                 transformer=trans,             # <<<<<<<<<<<<<<
 *                 X=X,
 *                 y=None,
 */
    __pyx_t_7 = __Pyx_PyDict_NewPresized(4); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 270, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_transformer, __pyx_cur_scope->__pyx_v_trans) < 0) __PYX_ERR(0, 270, __pyx_L1_error)

    /* "trans.py":271
 *             delayed(_transform_one)(
 *                 transformer=trans,
 *                 X=X,             # <<<<<<<<<<<<<<
 *                 y=None,
 *                 weight=weight)
 */
    if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_X)) { __Pyx_RaiseClosureNameError("X"); __PYX_ERR(0, 271, __pyx_L1_error) }
    if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_X, __pyx_cur_scope->__pyx_outer_scope->__pyx_v_X) < 0) __PYX_ERR(0, 270, __pyx_L1_error)

    /* "trans.py":272
 *                 transformer=trans,
 *                 X=X,
 *                 y=None,             # <<<<<<<<<<<<<<
 *                 weight=weight)
 *             for name, trans, weight in self._iter())
 */
    if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_y, Py_None) < 0) __PYX_ERR(0, 270, __pyx_L1_error)

    /* "trans.py":273
 *                 X=X,
 *                 y=None,
 *                 weight=weight)             # <<<<<<<<<<<<<<
 *             for name, trans, weight in self._iter())
 *         if not Xs:
 */
    if (PyDict_SetItem(__pyx_t_7, __pyx_n_s_weight, __pyx_cur_scope->__pyx_v_weight) < 0) __PYX_ERR(0, 270, __pyx_L1_error)

    /* "trans.py":269
 *     def transform(self, X):
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
    __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_empty_tuple, __pyx_t_7); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 269, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __pyx_r = __pyx_t_6;
    __pyx_t_6 = 0;
    __Pyx_XGIVEREF(__pyx_t_2);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_2;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_4;
    __pyx_cur_scope->__pyx_t_2 = __pyx_t_5;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    /* return from generator, yielding value */
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L8_resume_from_yield:;
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_2);
    __pyx_t_4 = __pyx_cur_scope->__pyx_t_1;
    __pyx_t_5 = __pyx_cur_scope->__pyx_t_2;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 269, __pyx_L1_error)

    /* "trans.py":274
 *                 y=None,
 *                 weight=weight)
 *             for name, trans, weight in self._iter())             # <<<<<<<<<<<<<<
 *         if not Xs:
 *             # All transformers are None
 */
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  /* "trans.py":269
 *     def transform(self, X):
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */

  /* function exit code */
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_9transform_5generator4(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); /* proto */

/* "trans.py":278
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */

static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_9transform_3genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *)__pyx_tp_new_5trans___pyx_scope_struct_8_genexpr(__pyx_ptype_5trans___pyx_scope_struct_8_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 278, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_5trans___pyx_scope_struct_6_transform *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_5trans_18PandasFeatureUnion_9transform_5generator4, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_PandasFeatureUnion_transform_loc, __pyx_n_s_trans); if (unlikely(!gen)) __PYX_ERR(0, 278, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.PandasFeatureUnion.transform.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_5trans_18PandasFeatureUnion_9transform_5generator4(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) /* generator body */
{
  struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *__pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *(*__pyx_t_3)(PyObject *);
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    default: /* CPython raises the right error here */
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 278, __pyx_L1_error)
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs)) { __Pyx_RaiseClosureNameError("Xs"); __PYX_ERR(0, 278, __pyx_L1_error) }
  if (likely(PyList_CheckExact(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs)) || PyTuple_CheckExact(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs)) {
    __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_Xs); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 278, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 278, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 278, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 278, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 278, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 278, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 278, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_f);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_f, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    __pyx_t_4 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_sparse); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 278, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_issparse); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 278, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_6);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_6, function);
      }
    }
    __pyx_t_4 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_5, __pyx_cur_scope->__pyx_v_f) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_cur_scope->__pyx_v_f);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 278, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 278, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__pyx_t_7) {
      __Pyx_XDECREF(__pyx_r);
      __Pyx_INCREF(Py_True);
      __pyx_r = Py_True;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      goto __pyx_L0;
    }
  }
  /*else*/ {
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(Py_False);
    __pyx_r = Py_False;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    goto __pyx_L0;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":267
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(
 */

static PyObject *__pyx_pf_5trans_18PandasFeatureUnion_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  struct __pyx_obj_5trans___pyx_scope_struct_6_transform *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  int __pyx_t_6;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);
  __pyx_cur_scope = (struct __pyx_obj_5trans___pyx_scope_struct_6_transform *)__pyx_tp_new_5trans___pyx_scope_struct_6_transform(__pyx_ptype_5trans___pyx_scope_struct_6_transform, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_5trans___pyx_scope_struct_6_transform *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 267, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_self = __pyx_v_self;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_self);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_self);
  __pyx_cur_scope->__pyx_v_X = __pyx_v_X;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_X);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_X);

  /* "trans.py":268
 *
 *     def transform(self, X):
 *         Xs = Parallel(n_jobs=self.n_jobs)(             # <<<<<<<<<<<<<<
 *             delayed(_transform_one)(
 *                 transformer=trans,
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Parallel); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_n_jobs); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_n_jobs, __pyx_t_4) < 0) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":269
 *     def transform(self, X):
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(             # <<<<<<<<<<<<<<
 *                 transformer=trans,
 *                 X=X,
 */
  __pyx_t_3 = __pyx_pf_5trans_18PandasFeatureUnion_9transform_genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 269, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 268, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_Xs = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "trans.py":275
 *                 weight=weight)
 *             for name, trans, weight in self._iter())
 *         if not Xs:             # <<<<<<<<<<<<<<
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 */
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_cur_scope->__pyx_v_Xs); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 275, __pyx_L1_error)
  __pyx_t_6 = ((!__pyx_t_5) != 0);
  if (__pyx_t_6) {

    /* "trans.py":277
 *         if not Xs:
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))             # <<<<<<<<<<<<<<
 *         if any(sparse.issparse(f) for f in Xs):
 *             Xs = sparse.hstack(Xs).tocsr()
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_np); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_zeros); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_X, __pyx_n_s_shape); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_2);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_int_0);
    __pyx_t_2 = 0;
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
    __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_r = __pyx_t_1;
    __pyx_t_1 = 0;
    goto __pyx_L0;

    /* "trans.py":275
 *                 weight=weight)
 *             for name, trans, weight in self._iter())
 *         if not Xs:             # <<<<<<<<<<<<<<
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 */
  }

  /* "trans.py":278
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */
  __pyx_t_1 = __pyx_pf_5trans_18PandasFeatureUnion_9transform_3genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Generator_Next(__pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 278, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__pyx_t_6) {

    /* "trans.py":279
 *             return np.zeros((X.shape[0], 0))
 *         if any(sparse.issparse(f) for f in Xs):
 *             Xs = sparse.hstack(Xs).tocsr()             # <<<<<<<<<<<<<<
 *         else:
 *             Xs = self.merge_dataframes_by_column(Xs)
 */
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_sparse); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 279, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_hstack); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 279, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
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
    __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_cur_scope->__pyx_v_Xs) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_cur_scope->__pyx_v_Xs);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 279, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_tocsr); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 279, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
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
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 279, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_Xs);
    __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_Xs, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;

    /* "trans.py":278
 *             # All transformers are None
 *             return np.zeros((X.shape[0], 0))
 *         if any(sparse.issparse(f) for f in Xs):             # <<<<<<<<<<<<<<
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 */
    goto __pyx_L4;
  }

  /* "trans.py":281
 *             Xs = sparse.hstack(Xs).tocsr()
 *         else:
 *             Xs = self.merge_dataframes_by_column(Xs)             # <<<<<<<<<<<<<<
 *         return Xs
 *
 */
  /*else*/ {
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_merge_dataframes_by_column); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 281, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_1, __pyx_cur_scope->__pyx_v_Xs) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_cur_scope->__pyx_v_Xs);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 281, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_Xs);
    __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_Xs, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;
  }
  __pyx_L4:;

  /* "trans.py":282
 *         else:
 *             Xs = self.merge_dataframes_by_column(Xs)
 *         return Xs             # <<<<<<<<<<<<<<
 *
 * class ConvertListToSeries(TransformerMixin, BaseEstimator):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_Xs);
  __pyx_r = __pyx_cur_scope->__pyx_v_Xs;
  goto __pyx_L0;

  /* "trans.py":267
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("trans.PandasFeatureUnion.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":294
 * class DenseTransformer(TransformerMixin):
 *
 *     def fit(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_16DenseTransformer_1fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_16DenseTransformer_1fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_16DenseTransformer_1fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_16DenseTransformer_1fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  CYTHON_UNUSED PyObject *__pyx_v_fit_params = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  __pyx_v_fit_params = PyDict_New(); if (unlikely(!__pyx_v_fit_params)) return NULL;
  __Pyx_GOTREF(__pyx_v_fit_params);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 294, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, __pyx_v_fit_params, values, pos_args, "fit") < 0)) __PYX_ERR(0, 294, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 294, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_DECREF(__pyx_v_fit_params); __pyx_v_fit_params = 0;
  __Pyx_AddTraceback("trans.DenseTransformer.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_16DenseTransformer_fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y, __pyx_v_fit_params);

  /* function exit code */
  __Pyx_XDECREF(__pyx_v_fit_params);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_16DenseTransformer_fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_fit_params) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":295
 *
 *     def fit(self, X, y=None, **fit_params):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X, y=None, **fit_params):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":294
 * class DenseTransformer(TransformerMixin):
 *
 *     def fit(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":297
 *         return self
 *
 *     def transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return X.todense()
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_16DenseTransformer_3transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_16DenseTransformer_3transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_16DenseTransformer_3transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_16DenseTransformer_3transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  CYTHON_UNUSED PyObject *__pyx_v_fit_params = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
  __pyx_v_fit_params = PyDict_New(); if (unlikely(!__pyx_v_fit_params)) return NULL;
  __Pyx_GOTREF(__pyx_v_fit_params);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("transform", 0, 2, 3, 1); __PYX_ERR(0, 297, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, __pyx_v_fit_params, values, pos_args, "transform") < 0)) __PYX_ERR(0, 297, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("transform", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 297, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_DECREF(__pyx_v_fit_params); __pyx_v_fit_params = 0;
  __Pyx_AddTraceback("trans.DenseTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_16DenseTransformer_2transform(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y, __pyx_v_fit_params);

  /* function exit code */
  __Pyx_XDECREF(__pyx_v_fit_params);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_16DenseTransformer_2transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_fit_params) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":298
 *
 *     def transform(self, X, y=None, **fit_params):
 *         return X.todense()             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_X, __pyx_n_s_todense); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 298, __pyx_L1_error)
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
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 298, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "trans.py":297
 *         return self
 *
 *     def transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return X.todense()
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.DenseTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":304
 *     """ Wrapper for vector functions to handle DataFrames. """
 *
 *     def __init__(self, *args, **kwargs):             # <<<<<<<<<<<<<<
 *         super(WordVectorTransform, self).__init__(*args, **kwargs)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19WordVectorTransform_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19WordVectorTransform_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_19WordVectorTransform_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_19WordVectorTransform_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_v_kwargs = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_v_kwargs = PyDict_New(); if (unlikely(!__pyx_v_kwargs)) return NULL;
  __Pyx_GOTREF(__pyx_v_kwargs);
  if (PyTuple_GET_SIZE(__pyx_args) > 1) {
    __pyx_v_args = PyTuple_GetSlice(__pyx_args, 1, PyTuple_GET_SIZE(__pyx_args));
    if (unlikely(!__pyx_v_args)) {
      __Pyx_DECREF(__pyx_v_kwargs); __pyx_v_kwargs = 0;
      __Pyx_RefNannyFinishContext();
      return NULL;
    }
    __Pyx_GOTREF(__pyx_v_args);
  } else {
    __pyx_v_args = __pyx_empty_tuple; __Pyx_INCREF(__pyx_empty_tuple);
  }
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,0};
    PyObject* values[1] = {0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        default:
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
      }
      if (unlikely(kw_args > 0)) {
        const Py_ssize_t used_pos_args = (pos_args < 1) ? pos_args : 1;
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, __pyx_v_kwargs, values, used_pos_args, "__init__") < 0)) __PYX_ERR(0, 304, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) < 1) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
    }
    __pyx_v_self = values[0];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 0, 1, 1, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 304, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_DECREF(__pyx_v_args); __pyx_v_args = 0;
  __Pyx_DECREF(__pyx_v_kwargs); __pyx_v_kwargs = 0;
  __Pyx_AddTraceback("trans.WordVectorTransform.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_19WordVectorTransform___init__(__pyx_self, __pyx_v_self, __pyx_v_args, __pyx_v_kwargs);

  /* function exit code */
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_XDECREF(__pyx_v_kwargs);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_19WordVectorTransform___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_args, PyObject *__pyx_v_kwargs) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":305
 *
 *     def __init__(self, *args, **kwargs):
 *         super(WordVectorTransform, self).__init__(*args, **kwargs)             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_WordVectorTransform); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(__pyx_v_self);
  __Pyx_GIVEREF(__pyx_v_self);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_v_self);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_super, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_init); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_v_args, __pyx_v_kwargs); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 305, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":304
 *     """ Wrapper for vector functions to handle DataFrames. """
 *
 *     def __init__(self, *args, **kwargs):             # <<<<<<<<<<<<<<
 *         super(WordVectorTransform, self).__init__(*args, **kwargs)
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("trans.WordVectorTransform.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":312
 *     """ Neural Network tranformation pipe """
 *
 *     def __init__(self, ann):             # <<<<<<<<<<<<<<
 *         self.ann = ann
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13NNTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13NNTransformer_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13NNTransformer_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13NNTransformer_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_ann = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_ann,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_ann)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, 1); __PYX_ERR(0, 312, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 312, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_ann = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 312, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NNTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13NNTransformer___init__(__pyx_self, __pyx_v_self, __pyx_v_ann);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13NNTransformer___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_ann) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":313
 *
 *     def __init__(self, ann):
 *         self.ann = ann             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_ann, __pyx_v_ann) < 0) __PYX_ERR(0, 313, __pyx_L1_error)

  /* "trans.py":312
 *     """ Neural Network tranformation pipe """
 *
 *     def __init__(self, ann):             # <<<<<<<<<<<<<<
 *         self.ann = ann
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.NNTransformer.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":315
 *         self.ann = ann
 *
 *     def fit(self, X, y):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13NNTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13NNTransformer_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13NNTransformer_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13NNTransformer_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("fit", 1, 3, 3, 1); __PYX_ERR(0, 315, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("fit", 1, 3, 3, 2); __PYX_ERR(0, 315, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 315, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("fit", 1, 3, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 315, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NNTransformer.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13NNTransformer_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13NNTransformer_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":316
 *
 *     def fit(self, X, y):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":315
 *         self.ann = ann
 *
 *     def fit(self, X, y):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":318
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return self.ann.predict(X)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13NNTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13NNTransformer_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13NNTransformer_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13NNTransformer_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 318, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 318, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 318, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.NNTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13NNTransformer_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13NNTransformer_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":319
 *
 *     def transform(self, X):
 *         return self.ann.predict(X)             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_ann); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 319, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_predict); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 319, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_v_X) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_X);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 319, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "trans.py":318
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return self.ann.predict(X)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.NNTransformer.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":326
 * # If you need a sanity check, and don't have a d20 handy.
 * class TestTransform(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13TestTransform_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13TestTransform_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13TestTransform_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13TestTransform_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_fn = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_fn,0};
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
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_fn)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, 1); __PYX_ERR(0, 326, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 326, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_self = values[0];
    __pyx_v_fn = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 326, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TestTransform.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13TestTransform___init__(__pyx_self, __pyx_v_self, __pyx_v_fn);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13TestTransform___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_fn) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  /* "trans.py":327
 * class TestTransform(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):
 *         self.fn = fn             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None):
 */
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_fn, __pyx_v_fn) < 0) __PYX_ERR(0, 327, __pyx_L1_error)

  /* "trans.py":326
 * # If you need a sanity check, and don't have a d20 handy.
 * class TestTransform(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_AddTraceback("trans.TestTransform.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":329
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13TestTransform_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13TestTransform_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13TestTransform_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13TestTransform_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 329, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 329, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 329, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TestTransform.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13TestTransform_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13TestTransform_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":330
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X, y=None, copy=None):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":329
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":332
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fun(X)
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13TestTransform_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13TestTransform_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13TestTransform_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13TestTransform_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  CYTHON_UNUSED PyObject *__pyx_v_copy = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,&__pyx_n_s_copy,0};
    PyObject* values[4] = {0,0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
    values[3] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("transform", 0, 2, 4, 1); __PYX_ERR(0, 332, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_copy);
          if (value) { values[3] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 332, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_self = values[0];
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
    __pyx_v_copy = values[3];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("transform", 0, 2, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 332, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TestTransform.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13TestTransform_4transform(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y, __pyx_v_copy);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13TestTransform_4transform(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y, CYTHON_UNUSED PyObject *__pyx_v_copy) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":333
 *
 *     def transform(self, X, y=None, copy=None):
 *         return self.fun(X)             # <<<<<<<<<<<<<<
 *
 *     def fun(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_fun); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 333, __pyx_L1_error)
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
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_X) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_X);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 333, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "trans.py":332
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fun(X)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("trans.TestTransform.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":335
 *         return self.fun(X)
 *
 *     def fun(self, X):             # <<<<<<<<<<<<<<
 *         #X = X + 11
 *         X = (X - np.mean(X)) / (np.max(X) - np.min(X))
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_13TestTransform_7fun(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_13TestTransform_7fun = {"fun", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_13TestTransform_7fun, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_13TestTransform_7fun(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fun (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("fun", 1, 2, 2, 1); __PYX_ERR(0, 335, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fun") < 0)) __PYX_ERR(0, 335, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("fun", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 335, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TestTransform.fun", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_13TestTransform_6fun(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_13TestTransform_6fun(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("fun", 0);
  __Pyx_INCREF(__pyx_v_X);

  /* "trans.py":337
 *     def fun(self, X):
 *         #X = X + 11
 *         X = (X - np.mean(X)) / (np.max(X) - np.min(X))             # <<<<<<<<<<<<<<
 *         return(X)
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_np); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_mean); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
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
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_v_X) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_X);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Subtract(__pyx_v_X, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_np); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_max); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_v_X) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_v_X);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_np); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_min); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_4 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_2, __pyx_v_X) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_v_X);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyNumber_Subtract(__pyx_t_1, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyNumber_Divide(__pyx_t_3, __pyx_t_5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 337, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF_SET(__pyx_v_X, __pyx_t_4);
  __pyx_t_4 = 0;

  /* "trans.py":338
 *         #X = X + 11
 *         X = (X - np.mean(X)) / (np.max(X) - np.min(X))
 *         return(X)             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":335
 *         return self.fun(X)
 *
 *     def fun(self, X):             # <<<<<<<<<<<<<<
 *         #X = X + 11
 *         X = (X - np.mean(X)) / (np.max(X) - np.min(X))
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("trans.TestTransform.fun", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_X);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":344
 *     """A template for a custom transformer. (TransformerMixin is for .fit_transform method.) """
 *
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19TransformerTemplate_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19TransformerTemplate_1__init__ = {"__init__", (PyCFunction)__pyx_pw_5trans_19TransformerTemplate_1__init__, METH_O, 0};
static PyObject *__pyx_pw_5trans_19TransformerTemplate_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_5trans_19TransformerTemplate___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_19TransformerTemplate___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":347
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19TransformerTemplate_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19TransformerTemplate_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_19TransformerTemplate_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_19TransformerTemplate_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 347, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 347, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 347, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TransformerTemplate.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_19TransformerTemplate_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_19TransformerTemplate_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":348
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":347
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":350
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         # transform X via code or additional methods
 *         return X
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_19TransformerTemplate_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_19TransformerTemplate_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_19TransformerTemplate_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_19TransformerTemplate_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 350, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 350, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 350, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.TransformerTemplate.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_19TransformerTemplate_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_19TransformerTemplate_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":352
 *     def transform(self, X):
 *         # transform X via code or additional methods
 *         return X             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_X);
  __pyx_r = __pyx_v_X;
  goto __pyx_L0;

  /* "trans.py":350
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         # transform X via code or additional methods
 *         return X
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":356
 *
 * class Wat(TransformerMixin, BaseEstimator):
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_3Wat_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self); /*proto*/
static PyMethodDef __pyx_mdef_5trans_3Wat_1__init__ = {"__init__", (PyCFunction)__pyx_pw_5trans_3Wat_1__init__, METH_O, 0};
static PyObject *__pyx_pw_5trans_3Wat_1__init__(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  __pyx_r = __pyx_pf_5trans_3Wat___init__(__pyx_self, ((PyObject *)__pyx_v_self));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_3Wat___init__(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__", 0);

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":359
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_3Wat_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_3Wat_3fit = {"fit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_3Wat_3fit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_3Wat_3fit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  CYTHON_UNUSED PyObject *__pyx_v_X = 0;
  CYTHON_UNUSED PyObject *__pyx_v_y = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_X,&__pyx_n_s_y,0};
    PyObject* values[3] = {0,0,0};
    values[2] = ((PyObject *)((PyObject *)Py_None));
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
          __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, 1); __PYX_ERR(0, 359, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_y);
          if (value) { values[2] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "fit") < 0)) __PYX_ERR(0, 359, __pyx_L3_error)
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
    __pyx_v_X = values[1];
    __pyx_v_y = values[2];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("fit", 0, 2, 3, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 359, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.Wat.fit", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_3Wat_2fit(__pyx_self, __pyx_v_self, __pyx_v_X, __pyx_v_y);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_3Wat_2fit(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, CYTHON_UNUSED PyObject *__pyx_v_X, CYTHON_UNUSED PyObject *__pyx_v_y) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("fit", 0);

  /* "trans.py":360
 *
 *     def fit(self, X, y=None):
 *         return self             # <<<<<<<<<<<<<<
 *
 *     def transform(self, X):
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_self);
  __pyx_r = __pyx_v_self;
  goto __pyx_L0;

  /* "trans.py":359
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "trans.py":362
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[:, 1:]
 */

/* Python wrapper */
static PyObject *__pyx_pw_5trans_3Wat_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_5trans_3Wat_5transform = {"transform", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_5trans_3Wat_5transform, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_5trans_3Wat_5transform(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_X = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("transform (wrapper)", 0);
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
          __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, 1); __PYX_ERR(0, 362, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "transform") < 0)) __PYX_ERR(0, 362, __pyx_L3_error)
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
  __Pyx_RaiseArgtupleInvalid("transform", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 362, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("trans.Wat.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_5trans_3Wat_4transform(__pyx_self, __pyx_v_self, __pyx_v_X);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_5trans_3Wat_4transform(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_self, PyObject *__pyx_v_X) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("transform", 0);

  /* "trans.py":363
 *
 *     def transform(self, X):
 *         return X[:, 1:]             # <<<<<<<<<<<<<<
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_X, __pyx_tuple__7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 363, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "trans.py":362
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[:, 1:]
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("trans.Wat.transform", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static struct __pyx_obj_5trans___pyx_scope_struct__transform *__pyx_freelist_5trans___pyx_scope_struct__transform[8];
static int __pyx_freecount_5trans___pyx_scope_struct__transform = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct__transform(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct__transform > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct__transform)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct__transform[--__pyx_freecount_5trans___pyx_scope_struct__transform];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct__transform));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct__transform(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct__transform *p = (struct __pyx_obj_5trans___pyx_scope_struct__transform *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_X);
  Py_CLEAR(p->__pyx_v_missing);
  Py_CLEAR(p->__pyx_v_y);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct__transform < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct__transform)))) {
    __pyx_freelist_5trans___pyx_scope_struct__transform[__pyx_freecount_5trans___pyx_scope_struct__transform++] = ((struct __pyx_obj_5trans___pyx_scope_struct__transform *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct__transform(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct__transform *p = (struct __pyx_obj_5trans___pyx_scope_struct__transform *)o;
  if (p->__pyx_v_X) {
    e = (*v)(p->__pyx_v_X, a); if (e) return e;
  }
  if (p->__pyx_v_missing) {
    e = (*v)(p->__pyx_v_missing, a); if (e) return e;
  }
  if (p->__pyx_v_y) {
    e = (*v)(p->__pyx_v_y, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_5trans___pyx_scope_struct__transform(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_5trans___pyx_scope_struct__transform *p = (struct __pyx_obj_5trans___pyx_scope_struct__transform *)o;
  tmp = ((PyObject*)p->__pyx_v_X);
  p->__pyx_v_X = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_missing);
  p->__pyx_v_missing = ((PyObject*)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_y);
  p->__pyx_v_y = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct__transform = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct__transform", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct__transform), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct__transform, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct__transform, /*tp_traverse*/
  __pyx_tp_clear_5trans___pyx_scope_struct__transform, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct__transform, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *__pyx_freelist_5trans___pyx_scope_struct_1_genexpr[8];
static int __pyx_freecount_5trans___pyx_scope_struct_1_genexpr = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_1_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_1_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_1_genexpr[--__pyx_freecount_5trans___pyx_scope_struct_1_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_1_genexpr(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_z);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_1_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr)))) {
    __pyx_freelist_5trans___pyx_scope_struct_1_genexpr[__pyx_freecount_5trans___pyx_scope_struct_1_genexpr++] = ((struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_1_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_z) {
    e = (*v)(p->__pyx_v_z, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_1_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_1_genexpr", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_1_genexpr), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_1_genexpr, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_1_genexpr, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_1_genexpr, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_2_transform *__pyx_freelist_5trans___pyx_scope_struct_2_transform[8];
static int __pyx_freecount_5trans___pyx_scope_struct_2_transform = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_2_transform(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_2_transform > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_2_transform)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_2_transform[--__pyx_freecount_5trans___pyx_scope_struct_2_transform];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_2_transform));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_2_transform(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_2_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_2_transform *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_self);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_2_transform < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_2_transform)))) {
    __pyx_freelist_5trans___pyx_scope_struct_2_transform[__pyx_freecount_5trans___pyx_scope_struct_2_transform++] = ((struct __pyx_obj_5trans___pyx_scope_struct_2_transform *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_2_transform(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_2_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_2_transform *)o;
  if (p->__pyx_v_self) {
    e = (*v)(p->__pyx_v_self, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_5trans___pyx_scope_struct_2_transform(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_5trans___pyx_scope_struct_2_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_2_transform *)o;
  tmp = ((PyObject*)p->__pyx_v_self);
  p->__pyx_v_self = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_2_transform = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_2_transform", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_2_transform), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_2_transform, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_2_transform, /*tp_traverse*/
  __pyx_tp_clear_5trans___pyx_scope_struct_2_transform, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_2_transform, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *__pyx_freelist_5trans___pyx_scope_struct_3_fit_transform[8];
static int __pyx_freecount_5trans___pyx_scope_struct_3_fit_transform = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_3_fit_transform(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_3_fit_transform > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_3_fit_transform[--__pyx_freecount_5trans___pyx_scope_struct_3_fit_transform];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_3_fit_transform(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_X);
  Py_CLEAR(p->__pyx_v_Xs);
  Py_CLEAR(p->__pyx_v_fit_params);
  Py_CLEAR(p->__pyx_v_self);
  Py_CLEAR(p->__pyx_v_y);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_3_fit_transform < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform)))) {
    __pyx_freelist_5trans___pyx_scope_struct_3_fit_transform[__pyx_freecount_5trans___pyx_scope_struct_3_fit_transform++] = ((struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_3_fit_transform(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *)o;
  if (p->__pyx_v_X) {
    e = (*v)(p->__pyx_v_X, a); if (e) return e;
  }
  if (p->__pyx_v_Xs) {
    e = (*v)(p->__pyx_v_Xs, a); if (e) return e;
  }
  if (p->__pyx_v_fit_params) {
    e = (*v)(p->__pyx_v_fit_params, a); if (e) return e;
  }
  if (p->__pyx_v_self) {
    e = (*v)(p->__pyx_v_self, a); if (e) return e;
  }
  if (p->__pyx_v_y) {
    e = (*v)(p->__pyx_v_y, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_5trans___pyx_scope_struct_3_fit_transform(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform *)o;
  tmp = ((PyObject*)p->__pyx_v_X);
  p->__pyx_v_X = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_Xs);
  p->__pyx_v_Xs = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_fit_params);
  p->__pyx_v_fit_params = ((PyObject*)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_self);
  p->__pyx_v_self = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_y);
  p->__pyx_v_y = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_3_fit_transform = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_3_fit_transform", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_3_fit_transform), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_3_fit_transform, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_3_fit_transform, /*tp_traverse*/
  __pyx_tp_clear_5trans___pyx_scope_struct_3_fit_transform, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_3_fit_transform, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *__pyx_freelist_5trans___pyx_scope_struct_4_genexpr[8];
static int __pyx_freecount_5trans___pyx_scope_struct_4_genexpr = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_4_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_4_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_4_genexpr[--__pyx_freecount_5trans___pyx_scope_struct_4_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_4_genexpr(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_name);
  Py_CLEAR(p->__pyx_v_trans);
  Py_CLEAR(p->__pyx_v_weight);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_4_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr)))) {
    __pyx_freelist_5trans___pyx_scope_struct_4_genexpr[__pyx_freecount_5trans___pyx_scope_struct_4_genexpr++] = ((struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_4_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_name) {
    e = (*v)(p->__pyx_v_name, a); if (e) return e;
  }
  if (p->__pyx_v_trans) {
    e = (*v)(p->__pyx_v_trans, a); if (e) return e;
  }
  if (p->__pyx_v_weight) {
    e = (*v)(p->__pyx_v_weight, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_4_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_4_genexpr", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_4_genexpr), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_4_genexpr, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_4_genexpr, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_4_genexpr, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *__pyx_freelist_5trans___pyx_scope_struct_5_genexpr[8];
static int __pyx_freecount_5trans___pyx_scope_struct_5_genexpr = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_5_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_5_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_5_genexpr[--__pyx_freecount_5trans___pyx_scope_struct_5_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_5_genexpr(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_f);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_5_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr)))) {
    __pyx_freelist_5trans___pyx_scope_struct_5_genexpr[__pyx_freecount_5trans___pyx_scope_struct_5_genexpr++] = ((struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_5_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_f) {
    e = (*v)(p->__pyx_v_f, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_5_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_5_genexpr", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_5_genexpr), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_5_genexpr, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_5_genexpr, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_5_genexpr, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_6_transform *__pyx_freelist_5trans___pyx_scope_struct_6_transform[8];
static int __pyx_freecount_5trans___pyx_scope_struct_6_transform = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_6_transform(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_6_transform > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_6_transform)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_6_transform[--__pyx_freecount_5trans___pyx_scope_struct_6_transform];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_6_transform));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_6_transform(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_6_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_6_transform *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_X);
  Py_CLEAR(p->__pyx_v_Xs);
  Py_CLEAR(p->__pyx_v_self);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_6_transform < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_6_transform)))) {
    __pyx_freelist_5trans___pyx_scope_struct_6_transform[__pyx_freecount_5trans___pyx_scope_struct_6_transform++] = ((struct __pyx_obj_5trans___pyx_scope_struct_6_transform *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_6_transform(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_6_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_6_transform *)o;
  if (p->__pyx_v_X) {
    e = (*v)(p->__pyx_v_X, a); if (e) return e;
  }
  if (p->__pyx_v_Xs) {
    e = (*v)(p->__pyx_v_Xs, a); if (e) return e;
  }
  if (p->__pyx_v_self) {
    e = (*v)(p->__pyx_v_self, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_5trans___pyx_scope_struct_6_transform(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_5trans___pyx_scope_struct_6_transform *p = (struct __pyx_obj_5trans___pyx_scope_struct_6_transform *)o;
  tmp = ((PyObject*)p->__pyx_v_X);
  p->__pyx_v_X = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_Xs);
  p->__pyx_v_Xs = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_self);
  p->__pyx_v_self = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_6_transform = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_6_transform", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_6_transform), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_6_transform, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_6_transform, /*tp_traverse*/
  __pyx_tp_clear_5trans___pyx_scope_struct_6_transform, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_6_transform, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *__pyx_freelist_5trans___pyx_scope_struct_7_genexpr[8];
static int __pyx_freecount_5trans___pyx_scope_struct_7_genexpr = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_7_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_7_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_7_genexpr[--__pyx_freecount_5trans___pyx_scope_struct_7_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_7_genexpr(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_name);
  Py_CLEAR(p->__pyx_v_trans);
  Py_CLEAR(p->__pyx_v_weight);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_7_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr)))) {
    __pyx_freelist_5trans___pyx_scope_struct_7_genexpr[__pyx_freecount_5trans___pyx_scope_struct_7_genexpr++] = ((struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_7_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_name) {
    e = (*v)(p->__pyx_v_name, a); if (e) return e;
  }
  if (p->__pyx_v_trans) {
    e = (*v)(p->__pyx_v_trans, a); if (e) return e;
  }
  if (p->__pyx_v_weight) {
    e = (*v)(p->__pyx_v_weight, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_7_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_7_genexpr", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_7_genexpr), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_7_genexpr, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_7_genexpr, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_7_genexpr, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *__pyx_freelist_5trans___pyx_scope_struct_8_genexpr[8];
static int __pyx_freecount_5trans___pyx_scope_struct_8_genexpr = 0;

static PyObject *__pyx_tp_new_5trans___pyx_scope_struct_8_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_5trans___pyx_scope_struct_8_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr)))) {
    o = (PyObject*)__pyx_freelist_5trans___pyx_scope_struct_8_genexpr[--__pyx_freecount_5trans___pyx_scope_struct_8_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_5trans___pyx_scope_struct_8_genexpr(PyObject *o) {
  struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_f);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_5trans___pyx_scope_struct_8_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr)))) {
    __pyx_freelist_5trans___pyx_scope_struct_8_genexpr[__pyx_freecount_5trans___pyx_scope_struct_8_genexpr++] = ((struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_5trans___pyx_scope_struct_8_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *p = (struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_f) {
    e = (*v)(p->__pyx_v_f, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_5trans___pyx_scope_struct_8_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "trans.__pyx_scope_struct_8_genexpr", /*tp_name*/
  sizeof(struct __pyx_obj_5trans___pyx_scope_struct_8_genexpr), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_5trans___pyx_scope_struct_8_genexpr, /*tp_dealloc*/
  #if PY_VERSION_HEX < 0x030800b4
  0, /*tp_print*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, /*tp_vectorcall_offset*/
  #endif
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, /*tp_flags*/
  0, /*tp_doc*/
  __pyx_tp_traverse_5trans___pyx_scope_struct_8_genexpr, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_5trans___pyx_scope_struct_8_genexpr, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, /*tp_print*/
  #endif
};

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); /*proto*/
static int __pyx_pymod_exec_trans(PyObject* module); /*proto*/
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_trans},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "trans",
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
  {&__pyx_kp_u_, __pyx_k_, sizeof(__pyx_k_), 0, 1, 0, 0},
  {&__pyx_kp_u_0_0_1, __pyx_k_0_0_1, sizeof(__pyx_k_0_0_1), 0, 1, 0, 0},
  {&__pyx_kp_s_A_template_for_a_custom_transfor, __pyx_k_A_template_for_a_custom_transfor, sizeof(__pyx_k_A_template_for_a_custom_transfor), 0, 0, 1, 0},
  {&__pyx_n_s_AvgWordLenTransformer, __pyx_k_AvgWordLenTransformer, sizeof(__pyx_k_AvgWordLenTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_AvgWordLenTransformer___init, __pyx_k_AvgWordLenTransformer___init, sizeof(__pyx_k_AvgWordLenTransformer___init), 0, 0, 1, 1},
  {&__pyx_n_s_AvgWordLenTransformer_fit, __pyx_k_AvgWordLenTransformer_fit, sizeof(__pyx_k_AvgWordLenTransformer_fit), 0, 0, 1, 1},
  {&__pyx_n_s_AvgWordLenTransformer_transform, __pyx_k_AvgWordLenTransformer_transform, sizeof(__pyx_k_AvgWordLenTransformer_transform), 0, 0, 1, 1},
  {&__pyx_n_s_AvgWordLenTransformer_transform_2, __pyx_k_AvgWordLenTransformer_transform_2, sizeof(__pyx_k_AvgWordLenTransformer_transform_2), 0, 0, 1, 1},
  {&__pyx_n_s_BaseEstimator, __pyx_k_BaseEstimator, sizeof(__pyx_k_BaseEstimator), 0, 0, 1, 1},
  {&__pyx_n_s_BooleanTargets, __pyx_k_BooleanTargets, sizeof(__pyx_k_BooleanTargets), 0, 0, 1, 1},
  {&__pyx_n_s_BooleanTargets___init, __pyx_k_BooleanTargets___init, sizeof(__pyx_k_BooleanTargets___init), 0, 0, 1, 1},
  {&__pyx_n_s_BooleanTargets_fit, __pyx_k_BooleanTargets_fit, sizeof(__pyx_k_BooleanTargets_fit), 0, 0, 1, 1},
  {&__pyx_n_s_BooleanTargets_transform, __pyx_k_BooleanTargets_transform, sizeof(__pyx_k_BooleanTargets_transform), 0, 0, 1, 1},
  {&__pyx_n_s_ClassifierMixin, __pyx_k_ClassifierMixin, sizeof(__pyx_k_ClassifierMixin), 0, 0, 1, 1},
  {&__pyx_n_s_CommaLenRatio, __pyx_k_CommaLenRatio, sizeof(__pyx_k_CommaLenRatio), 0, 0, 1, 1},
  {&__pyx_n_s_CommaLenRatio___init, __pyx_k_CommaLenRatio___init, sizeof(__pyx_k_CommaLenRatio___init), 0, 0, 1, 1},
  {&__pyx_n_s_CommaLenRatio_divide, __pyx_k_CommaLenRatio_divide, sizeof(__pyx_k_CommaLenRatio_divide), 0, 0, 1, 1},
  {&__pyx_n_s_CommaLenRatio_fit, __pyx_k_CommaLenRatio_fit, sizeof(__pyx_k_CommaLenRatio_fit), 0, 0, 1, 1},
  {&__pyx_n_s_CommaLenRatio_transform, __pyx_k_CommaLenRatio_transform, sizeof(__pyx_k_CommaLenRatio_transform), 0, 0, 1, 1},
  {&__pyx_n_s_CommaLenRatio_transform_locals_l, __pyx_k_CommaLenRatio_transform_locals_l, sizeof(__pyx_k_CommaLenRatio_transform_locals_l), 0, 0, 1, 1},
  {&__pyx_n_s_ConvertListToSeries, __pyx_k_ConvertListToSeries, sizeof(__pyx_k_ConvertListToSeries), 0, 0, 1, 1},
  {&__pyx_n_s_ConvertTargets, __pyx_k_ConvertTargets, sizeof(__pyx_k_ConvertTargets), 0, 0, 1, 1},
  {&__pyx_n_s_ConvertTargets___init, __pyx_k_ConvertTargets___init, sizeof(__pyx_k_ConvertTargets___init), 0, 0, 1, 1},
  {&__pyx_n_s_ConvertTargets_fit, __pyx_k_ConvertTargets_fit, sizeof(__pyx_k_ConvertTargets_fit), 0, 0, 1, 1},
  {&__pyx_n_s_ConvertTargets_transform, __pyx_k_ConvertTargets_transform, sizeof(__pyx_k_ConvertTargets_transform), 0, 0, 1, 1},
  {&__pyx_kp_s_Convert_a_list_to_series_t_k, __pyx_k_Convert_a_list_to_series_t_k, sizeof(__pyx_k_Convert_a_list_to_series_t_k), 0, 0, 1, 0},
  {&__pyx_kp_s_Convert_target_categories_to_in, __pyx_k_Convert_target_categories_to_in, sizeof(__pyx_k_Convert_target_categories_to_in), 0, 0, 1, 0},
  {&__pyx_kp_s_Converts_binary_classification, __pyx_k_Converts_binary_classification, sizeof(__pyx_k_Converts_binary_classification), 0, 0, 1, 0},
  {&__pyx_n_s_CountCommas, __pyx_k_CountCommas, sizeof(__pyx_k_CountCommas), 0, 0, 1, 1},
  {&__pyx_n_s_CountCommas___init, __pyx_k_CountCommas___init, sizeof(__pyx_k_CountCommas___init), 0, 0, 1, 1},
  {&__pyx_n_s_CountCommas_fit, __pyx_k_CountCommas_fit, sizeof(__pyx_k_CountCommas_fit), 0, 0, 1, 1},
  {&__pyx_n_s_CountCommas_transform, __pyx_k_CountCommas_transform, sizeof(__pyx_k_CountCommas_transform), 0, 0, 1, 1},
  {&__pyx_n_s_CountCommas_transform_locals_lam, __pyx_k_CountCommas_transform_locals_lam, sizeof(__pyx_k_CountCommas_transform_locals_lam), 0, 0, 1, 1},
  {&__pyx_n_s_CountVectorizer, __pyx_k_CountVectorizer, sizeof(__pyx_k_CountVectorizer), 0, 0, 1, 1},
  {&__pyx_n_s_CountWords, __pyx_k_CountWords, sizeof(__pyx_k_CountWords), 0, 0, 1, 1},
  {&__pyx_n_s_CountWords___init, __pyx_k_CountWords___init, sizeof(__pyx_k_CountWords___init), 0, 0, 1, 1},
  {&__pyx_n_s_CountWords_fit, __pyx_k_CountWords_fit, sizeof(__pyx_k_CountWords_fit), 0, 0, 1, 1},
  {&__pyx_n_s_CountWords_transform, __pyx_k_CountWords_transform, sizeof(__pyx_k_CountWords_transform), 0, 0, 1, 1},
  {&__pyx_n_s_CountWords_transform_locals_lamb, __pyx_k_CountWords_transform_locals_lamb, sizeof(__pyx_k_CountWords_transform_locals_lamb), 0, 0, 1, 1},
  {&__pyx_kp_s_Count_commas_in_a_text_series, __pyx_k_Count_commas_in_a_text_series, sizeof(__pyx_k_Count_commas_in_a_text_series), 0, 0, 1, 0},
  {&__pyx_kp_s_Count_words_in_a_text_series, __pyx_k_Count_words_in_a_text_series, sizeof(__pyx_k_Count_words_in_a_text_series), 0, 0, 1, 0},
  {&__pyx_n_s_DenseTransformer, __pyx_k_DenseTransformer, sizeof(__pyx_k_DenseTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_DenseTransformer_fit, __pyx_k_DenseTransformer_fit, sizeof(__pyx_k_DenseTransformer_fit), 0, 0, 1, 1},
  {&__pyx_n_s_DenseTransformer_transform, __pyx_k_DenseTransformer_transform, sizeof(__pyx_k_DenseTransformer_transform), 0, 0, 1, 1},
  {&__pyx_n_s_DropFeatures, __pyx_k_DropFeatures, sizeof(__pyx_k_DropFeatures), 0, 0, 1, 1},
  {&__pyx_n_s_DropFeatures___init, __pyx_k_DropFeatures___init, sizeof(__pyx_k_DropFeatures___init), 0, 0, 1, 1},
  {&__pyx_n_s_DropFeatures_fit, __pyx_k_DropFeatures_fit, sizeof(__pyx_k_DropFeatures_fit), 0, 0, 1, 1},
  {&__pyx_n_s_DropFeatures_transform, __pyx_k_DropFeatures_transform, sizeof(__pyx_k_DropFeatures_transform), 0, 0, 1, 1},
  {&__pyx_kp_s_Drop_any_features_passed_via_se, __pyx_k_Drop_any_features_passed_via_se, sizeof(__pyx_k_Drop_any_features_passed_via_se), 0, 0, 1, 0},
  {&__pyx_kp_s_Examines_dataset_for_missing_va, __pyx_k_Examines_dataset_for_missing_va, sizeof(__pyx_k_Examines_dataset_for_missing_va), 0, 0, 1, 0},
  {&__pyx_n_s_FeatureSelector, __pyx_k_FeatureSelector, sizeof(__pyx_k_FeatureSelector), 0, 0, 1, 1},
  {&__pyx_n_s_FeatureSelector___init, __pyx_k_FeatureSelector___init, sizeof(__pyx_k_FeatureSelector___init), 0, 0, 1, 1},
  {&__pyx_n_s_FeatureSelector_fit, __pyx_k_FeatureSelector_fit, sizeof(__pyx_k_FeatureSelector_fit), 0, 0, 1, 1},
  {&__pyx_n_s_FeatureSelector_transform, __pyx_k_FeatureSelector_transform, sizeof(__pyx_k_FeatureSelector_transform), 0, 0, 1, 1},
  {&__pyx_n_s_FeatureUnion, __pyx_k_FeatureUnion, sizeof(__pyx_k_FeatureUnion), 0, 0, 1, 1},
  {&__pyx_kp_s_Hard_coded_experimental_feature, __pyx_k_Hard_coded_experimental_feature, sizeof(__pyx_k_Hard_coded_experimental_feature), 0, 0, 1, 0},
  {&__pyx_n_s_MissingData, __pyx_k_MissingData, sizeof(__pyx_k_MissingData), 0, 0, 1, 1},
  {&__pyx_n_s_MissingData___init, __pyx_k_MissingData___init, sizeof(__pyx_k_MissingData___init), 0, 0, 1, 1},
  {&__pyx_n_s_MissingData_fit, __pyx_k_MissingData_fit, sizeof(__pyx_k_MissingData_fit), 0, 0, 1, 1},
  {&__pyx_n_s_MissingData_transform, __pyx_k_MissingData_transform, sizeof(__pyx_k_MissingData_transform), 0, 0, 1, 1},
  {&__pyx_n_s_MissingData_transform_locals_gen, __pyx_k_MissingData_transform_locals_gen, sizeof(__pyx_k_MissingData_transform_locals_gen), 0, 0, 1, 1},
  {&__pyx_n_s_MissingData_transform_locals_gen_2, __pyx_k_MissingData_transform_locals_gen_2, sizeof(__pyx_k_MissingData_transform_locals_gen_2), 0, 0, 1, 1},
  {&__pyx_n_s_NNTransformer, __pyx_k_NNTransformer, sizeof(__pyx_k_NNTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_NNTransformer___init, __pyx_k_NNTransformer___init, sizeof(__pyx_k_NNTransformer___init), 0, 0, 1, 1},
  {&__pyx_n_s_NNTransformer_fit, __pyx_k_NNTransformer_fit, sizeof(__pyx_k_NNTransformer_fit), 0, 0, 1, 1},
  {&__pyx_n_s_NNTransformer_transform, __pyx_k_NNTransformer_transform, sizeof(__pyx_k_NNTransformer_transform), 0, 0, 1, 1},
  {&__pyx_kp_s_Neural_Network_tranformation_pi, __pyx_k_Neural_Network_tranformation_pi, sizeof(__pyx_k_Neural_Network_tranformation_pi), 0, 0, 1, 0},
  {&__pyx_kp_s_Non_stop_words_in_a_text_series, __pyx_k_Non_stop_words_in_a_text_series, sizeof(__pyx_k_Non_stop_words_in_a_text_series), 0, 0, 1, 0},
  {&__pyx_n_s_NotStopsTransformer, __pyx_k_NotStopsTransformer, sizeof(__pyx_k_NotStopsTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_NotStopsTransformer___init, __pyx_k_NotStopsTransformer___init, sizeof(__pyx_k_NotStopsTransformer___init), 0, 0, 1, 1},
  {&__pyx_n_s_NotStopsTransformer_fit, __pyx_k_NotStopsTransformer_fit, sizeof(__pyx_k_NotStopsTransformer_fit), 0, 0, 1, 1},
  {&__pyx_n_s_NotStopsTransformer_transform, __pyx_k_NotStopsTransformer_transform, sizeof(__pyx_k_NotStopsTransformer_transform), 0, 0, 1, 1},
  {&__pyx_n_s_NotStopsTransformer_transform_lo, __pyx_k_NotStopsTransformer_transform_lo, sizeof(__pyx_k_NotStopsTransformer_transform_lo), 0, 0, 1, 1},
  {&__pyx_n_s_NumberSelector, __pyx_k_NumberSelector, sizeof(__pyx_k_NumberSelector), 0, 0, 1, 1},
  {&__pyx_n_s_NumberSelector___init, __pyx_k_NumberSelector___init, sizeof(__pyx_k_NumberSelector___init), 0, 0, 1, 1},
  {&__pyx_n_s_NumberSelector_fit, __pyx_k_NumberSelector_fit, sizeof(__pyx_k_NumberSelector_fit), 0, 0, 1, 1},
  {&__pyx_n_s_NumberSelector_transform, __pyx_k_NumberSelector_transform, sizeof(__pyx_k_NumberSelector_transform), 0, 0, 1, 1},
  {&__pyx_n_s_PandasFeatureUnion, __pyx_k_PandasFeatureUnion, sizeof(__pyx_k_PandasFeatureUnion), 0, 0, 1, 1},
  {&__pyx_n_s_PandasFeatureUnion_fit_transform, __pyx_k_PandasFeatureUnion_fit_transform, sizeof(__pyx_k_PandasFeatureUnion_fit_transform), 0, 0, 1, 1},
  {&__pyx_n_s_PandasFeatureUnion_fit_transform_2, __pyx_k_PandasFeatureUnion_fit_transform_2, sizeof(__pyx_k_PandasFeatureUnion_fit_transform_2), 0, 0, 1, 1},
  {&__pyx_n_s_PandasFeatureUnion_merge_datafra, __pyx_k_PandasFeatureUnion_merge_datafra, sizeof(__pyx_k_PandasFeatureUnion_merge_datafra), 0, 0, 1, 1},
  {&__pyx_n_s_PandasFeatureUnion_transform, __pyx_k_PandasFeatureUnion_transform, sizeof(__pyx_k_PandasFeatureUnion_transform), 0, 0, 1, 1},
  {&__pyx_n_s_PandasFeatureUnion_transform_loc, __pyx_k_PandasFeatureUnion_transform_loc, sizeof(__pyx_k_PandasFeatureUnion_transform_loc), 0, 0, 1, 1},
  {&__pyx_n_s_PandasTransformer, __pyx_k_PandasTransformer, sizeof(__pyx_k_PandasTransformer), 0, 0, 1, 1},
  {&__pyx_n_s_PandasTransformer___init, __pyx_k_PandasTransformer___init, sizeof(__pyx_k_PandasTransformer___init), 0, 0, 1, 1},
  {&__pyx_n_s_PandasTransformer_fit, __pyx_k_PandasTransformer_fit, sizeof(__pyx_k_PandasTransformer_fit), 0, 0, 1, 1},
  {&__pyx_n_s_PandasTransformer_transform, __pyx_k_PandasTransformer_transform, sizeof(__pyx_k_PandasTransformer_transform), 0, 0, 1, 1},
  {&__pyx_n_s_Parallel, __pyx_k_Parallel, sizeof(__pyx_k_Parallel), 0, 0, 1, 1},
  {&__pyx_kp_s_Select_a_single_numeric_column, __pyx_k_Select_a_single_numeric_column, sizeof(__pyx_k_Select_a_single_numeric_column), 0, 0, 1, 0},
  {&__pyx_kp_s_Select_a_single_text_column_fro, __pyx_k_Select_a_single_text_column_fro, sizeof(__pyx_k_Select_a_single_text_column_fro), 0, 0, 1, 0},
  {&__pyx_kp_s_Select_multiple_text_columns_fr, __pyx_k_Select_multiple_text_columns_fr, sizeof(__pyx_k_Select_multiple_text_columns_fr), 0, 0, 1, 0},
  {&__pyx_kp_s_Select_only_the_features_passed, __pyx_k_Select_only_the_features_passed, sizeof(__pyx_k_Select_only_the_features_passed), 0, 0, 1, 0},
  {&__pyx_n_s_SentenceLength, __pyx_k_SentenceLength, sizeof(__pyx_k_SentenceLength), 0, 0, 1, 1},
  {&__pyx_n_s_SentenceLength___init, __pyx_k_SentenceLength___init, sizeof(__pyx_k_SentenceLength___init), 0, 0, 1, 1},
  {&__pyx_n_s_SentenceLength_fit, __pyx_k_SentenceLength_fit, sizeof(__pyx_k_SentenceLength_fit), 0, 0, 1, 1},
  {&__pyx_n_s_SentenceLength_transform, __pyx_k_SentenceLength_transform, sizeof(__pyx_k_SentenceLength_transform), 0, 0, 1, 1},
  {&__pyx_n_s_SentenceLength_transform_locals, __pyx_k_SentenceLength_transform_locals, sizeof(__pyx_k_SentenceLength_transform_locals), 0, 0, 1, 1},
  {&__pyx_kp_s_TODO_cleanup_non_overridden_met, __pyx_k_TODO_cleanup_non_overridden_met, sizeof(__pyx_k_TODO_cleanup_non_overridden_met), 0, 0, 1, 0},
  {&__pyx_n_s_TestTransform, __pyx_k_TestTransform, sizeof(__pyx_k_TestTransform), 0, 0, 1, 1},
  {&__pyx_n_s_TestTransform___init, __pyx_k_TestTransform___init, sizeof(__pyx_k_TestTransform___init), 0, 0, 1, 1},
  {&__pyx_n_s_TestTransform_fit, __pyx_k_TestTransform_fit, sizeof(__pyx_k_TestTransform_fit), 0, 0, 1, 1},
  {&__pyx_n_s_TestTransform_fun, __pyx_k_TestTransform_fun, sizeof(__pyx_k_TestTransform_fun), 0, 0, 1, 1},
  {&__pyx_n_s_TestTransform_transform, __pyx_k_TestTransform_transform, sizeof(__pyx_k_TestTransform_transform), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelector, __pyx_k_TextSelector, sizeof(__pyx_k_TextSelector), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelectorMulti, __pyx_k_TextSelectorMulti, sizeof(__pyx_k_TextSelectorMulti), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelectorMulti___init, __pyx_k_TextSelectorMulti___init, sizeof(__pyx_k_TextSelectorMulti___init), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelectorMulti_fit, __pyx_k_TextSelectorMulti_fit, sizeof(__pyx_k_TextSelectorMulti_fit), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelectorMulti_transform, __pyx_k_TextSelectorMulti_transform, sizeof(__pyx_k_TextSelectorMulti_transform), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelector___init, __pyx_k_TextSelector___init, sizeof(__pyx_k_TextSelector___init), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelector_fit, __pyx_k_TextSelector_fit, sizeof(__pyx_k_TextSelector_fit), 0, 0, 1, 1},
  {&__pyx_n_s_TextSelector_transform, __pyx_k_TextSelector_transform, sizeof(__pyx_k_TextSelector_transform), 0, 0, 1, 1},
  {&__pyx_n_s_TransformerMixin, __pyx_k_TransformerMixin, sizeof(__pyx_k_TransformerMixin), 0, 0, 1, 1},
  {&__pyx_n_s_TransformerTemplate, __pyx_k_TransformerTemplate, sizeof(__pyx_k_TransformerTemplate), 0, 0, 1, 1},
  {&__pyx_n_s_TransformerTemplate___init, __pyx_k_TransformerTemplate___init, sizeof(__pyx_k_TransformerTemplate___init), 0, 0, 1, 1},
  {&__pyx_n_s_TransformerTemplate_fit, __pyx_k_TransformerTemplate_fit, sizeof(__pyx_k_TransformerTemplate_fit), 0, 0, 1, 1},
  {&__pyx_n_s_TransformerTemplate_transform, __pyx_k_TransformerTemplate_transform, sizeof(__pyx_k_TransformerTemplate_transform), 0, 0, 1, 1},
  {&__pyx_kp_s_Transformer_to_calculate_averag, __pyx_k_Transformer_to_calculate_averag, sizeof(__pyx_k_Transformer_to_calculate_averag), 0, 0, 1, 0},
  {&__pyx_n_s_Wat, __pyx_k_Wat, sizeof(__pyx_k_Wat), 0, 0, 1, 1},
  {&__pyx_n_s_Wat___init, __pyx_k_Wat___init, sizeof(__pyx_k_Wat___init), 0, 0, 1, 1},
  {&__pyx_n_s_Wat_fit, __pyx_k_Wat_fit, sizeof(__pyx_k_Wat_fit), 0, 0, 1, 1},
  {&__pyx_n_s_Wat_transform, __pyx_k_Wat_transform, sizeof(__pyx_k_Wat_transform), 0, 0, 1, 1},
  {&__pyx_n_s_WordVectorTransform, __pyx_k_WordVectorTransform, sizeof(__pyx_k_WordVectorTransform), 0, 0, 1, 1},
  {&__pyx_n_s_WordVectorTransform___init, __pyx_k_WordVectorTransform___init, sizeof(__pyx_k_WordVectorTransform___init), 0, 0, 1, 1},
  {&__pyx_kp_s_Wrapper_for_vector_functions_to, __pyx_k_Wrapper_for_vector_functions_to, sizeof(__pyx_k_Wrapper_for_vector_functions_to), 0, 0, 1, 0},
  {&__pyx_n_s_X, __pyx_k_X, sizeof(__pyx_k_X), 0, 0, 1, 1},
  {&__pyx_n_s_Xs, __pyx_k_Xs, sizeof(__pyx_k_Xs), 0, 0, 1, 1},
  {&__pyx_kp_u__2, __pyx_k__2, sizeof(__pyx_k__2), 0, 1, 0, 0},
  {&__pyx_kp_u__4, __pyx_k__4, sizeof(__pyx_k__4), 0, 1, 0, 0},
  {&__pyx_n_s_a, __pyx_k_a, sizeof(__pyx_k_a), 0, 0, 1, 1},
  {&__pyx_n_s_ann, __pyx_k_ann, sizeof(__pyx_k_ann), 0, 0, 1, 1},
  {&__pyx_n_s_apply, __pyx_k_apply, sizeof(__pyx_k_apply), 0, 0, 1, 1},
  {&__pyx_n_s_args, __pyx_k_args, sizeof(__pyx_k_args), 0, 0, 1, 1},
  {&__pyx_n_u_avg_word_len, __pyx_k_avg_word_len, sizeof(__pyx_k_avg_word_len), 0, 1, 0, 1},
  {&__pyx_n_s_axis, __pyx_k_axis, sizeof(__pyx_k_axis), 0, 0, 1, 1},
  {&__pyx_n_s_b, __pyx_k_b, sizeof(__pyx_k_b), 0, 0, 1, 1},
  {&__pyx_n_s_chained_assignment, __pyx_k_chained_assignment, sizeof(__pyx_k_chained_assignment), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_close, __pyx_k_close, sizeof(__pyx_k_close), 0, 0, 1, 1},
  {&__pyx_n_s_col, __pyx_k_col, sizeof(__pyx_k_col), 0, 0, 1, 1},
  {&__pyx_n_s_columns, __pyx_k_columns, sizeof(__pyx_k_columns), 0, 0, 1, 1},
  {&__pyx_n_u_columns, __pyx_k_columns, sizeof(__pyx_k_columns), 0, 1, 0, 1},
  {&__pyx_n_u_comma_len_ratio, __pyx_k_comma_len_ratio, sizeof(__pyx_k_comma_len_ratio), 0, 1, 0, 1},
  {&__pyx_n_s_concat, __pyx_k_concat, sizeof(__pyx_k_concat), 0, 0, 1, 1},
  {&__pyx_n_s_copy, __pyx_k_copy, sizeof(__pyx_k_copy), 0, 0, 1, 1},
  {&__pyx_n_s_count, __pyx_k_count, sizeof(__pyx_k_count), 0, 0, 1, 1},
  {&__pyx_n_u_count_commas, __pyx_k_count_commas, sizeof(__pyx_k_count_commas), 0, 1, 0, 1},
  {&__pyx_n_u_count_words, __pyx_k_count_words, sizeof(__pyx_k_count_words), 0, 1, 0, 1},
  {&__pyx_n_s_delayed, __pyx_k_delayed, sizeof(__pyx_k_delayed), 0, 0, 1, 1},
  {&__pyx_n_s_divide, __pyx_k_divide, sizeof(__pyx_k_divide), 0, 0, 1, 1},
  {&__pyx_n_s_doc, __pyx_k_doc, sizeof(__pyx_k_doc), 0, 0, 1, 1},
  {&__pyx_n_s_drop, __pyx_k_drop, sizeof(__pyx_k_drop), 0, 0, 1, 1},
  {&__pyx_n_u_english, __pyx_k_english, sizeof(__pyx_k_english), 0, 1, 0, 1},
  {&__pyx_n_s_feats, __pyx_k_feats, sizeof(__pyx_k_feats), 0, 0, 1, 1},
  {&__pyx_n_s_fit, __pyx_k_fit, sizeof(__pyx_k_fit), 0, 0, 1, 1},
  {&__pyx_n_s_fit_params, __pyx_k_fit_params, sizeof(__pyx_k_fit_params), 0, 0, 1, 1},
  {&__pyx_n_s_fit_transform, __pyx_k_fit_transform, sizeof(__pyx_k_fit_transform), 0, 0, 1, 1},
  {&__pyx_n_s_fit_transform_one, __pyx_k_fit_transform_one, sizeof(__pyx_k_fit_transform_one), 0, 0, 1, 1},
  {&__pyx_n_s_fn, __pyx_k_fn, sizeof(__pyx_k_fn), 0, 0, 1, 1},
  {&__pyx_n_s_fun, __pyx_k_fun, sizeof(__pyx_k_fun), 0, 0, 1, 1},
  {&__pyx_n_s_genexpr, __pyx_k_genexpr, sizeof(__pyx_k_genexpr), 0, 0, 1, 1},
  {&__pyx_n_s_hstack, __pyx_k_hstack, sizeof(__pyx_k_hstack), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_init, __pyx_k_init, sizeof(__pyx_k_init), 0, 0, 1, 1},
  {&__pyx_n_s_issparse, __pyx_k_issparse, sizeof(__pyx_k_issparse), 0, 0, 1, 1},
  {&__pyx_n_s_items, __pyx_k_items, sizeof(__pyx_k_items), 0, 0, 1, 1},
  {&__pyx_n_s_iter, __pyx_k_iter, sizeof(__pyx_k_iter), 0, 0, 1, 1},
  {&__pyx_n_s_joblib, __pyx_k_joblib, sizeof(__pyx_k_joblib), 0, 0, 1, 1},
  {&__pyx_n_s_key, __pyx_k_key, sizeof(__pyx_k_key), 0, 0, 1, 1},
  {&__pyx_n_s_keys, __pyx_k_keys, sizeof(__pyx_k_keys), 0, 0, 1, 1},
  {&__pyx_n_s_kwargs, __pyx_k_kwargs, sizeof(__pyx_k_kwargs), 0, 0, 1, 1},
  {&__pyx_n_u_list, __pyx_k_list, sizeof(__pyx_k_list), 0, 1, 0, 1},
  {&__pyx_n_s_loc, __pyx_k_loc, sizeof(__pyx_k_loc), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_s_max, __pyx_k_max, sizeof(__pyx_k_max), 0, 0, 1, 1},
  {&__pyx_n_s_mean, __pyx_k_mean, sizeof(__pyx_k_mean), 0, 0, 1, 1},
  {&__pyx_n_s_merge_dataframes_by_column, __pyx_k_merge_dataframes_by_column, sizeof(__pyx_k_merge_dataframes_by_column), 0, 0, 1, 1},
  {&__pyx_n_s_metaclass, __pyx_k_metaclass, sizeof(__pyx_k_metaclass), 0, 0, 1, 1},
  {&__pyx_n_s_min, __pyx_k_min, sizeof(__pyx_k_min), 0, 0, 1, 1},
  {&__pyx_n_s_missing, __pyx_k_missing, sizeof(__pyx_k_missing), 0, 0, 1, 1},
  {&__pyx_n_s_mode, __pyx_k_mode, sizeof(__pyx_k_mode), 0, 0, 1, 1},
  {&__pyx_n_s_module, __pyx_k_module, sizeof(__pyx_k_module), 0, 0, 1, 1},
  {&__pyx_n_s_n_jobs, __pyx_k_n_jobs, sizeof(__pyx_k_n_jobs), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_nltk_corpus, __pyx_k_nltk_corpus, sizeof(__pyx_k_nltk_corpus), 0, 0, 1, 1},
  {&__pyx_n_u_not_stops, __pyx_k_not_stops, sizeof(__pyx_k_not_stops), 0, 1, 0, 1},
  {&__pyx_n_s_np, __pyx_k_np, sizeof(__pyx_k_np), 0, 0, 1, 1},
  {&__pyx_n_s_numpy, __pyx_k_numpy, sizeof(__pyx_k_numpy), 0, 0, 1, 1},
  {&__pyx_n_s_options, __pyx_k_options, sizeof(__pyx_k_options), 0, 0, 1, 1},
  {&__pyx_n_s_pandas, __pyx_k_pandas, sizeof(__pyx_k_pandas), 0, 0, 1, 1},
  {&__pyx_n_s_pd, __pyx_k_pd, sizeof(__pyx_k_pd), 0, 0, 1, 1},
  {&__pyx_n_s_predict, __pyx_k_predict, sizeof(__pyx_k_predict), 0, 0, 1, 1},
  {&__pyx_n_s_prepare, __pyx_k_prepare, sizeof(__pyx_k_prepare), 0, 0, 1, 1},
  {&__pyx_n_s_qualname, __pyx_k_qualname, sizeof(__pyx_k_qualname), 0, 0, 1, 1},
  {&__pyx_n_u_raw, __pyx_k_raw, sizeof(__pyx_k_raw), 0, 1, 0, 1},
  {&__pyx_n_s_replace, __pyx_k_replace, sizeof(__pyx_k_replace), 0, 0, 1, 1},
  {&__pyx_n_s_result, __pyx_k_result, sizeof(__pyx_k_result), 0, 0, 1, 1},
  {&__pyx_n_s_scipy, __pyx_k_scipy, sizeof(__pyx_k_scipy), 0, 0, 1, 1},
  {&__pyx_n_s_self, __pyx_k_self, sizeof(__pyx_k_self), 0, 0, 1, 1},
  {&__pyx_n_u_sen_len, __pyx_k_sen_len, sizeof(__pyx_k_sen_len), 0, 1, 0, 1},
  {&__pyx_n_s_send, __pyx_k_send, sizeof(__pyx_k_send), 0, 0, 1, 1},
  {&__pyx_n_s_shape, __pyx_k_shape, sizeof(__pyx_k_shape), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_base, __pyx_k_sklearn_base, sizeof(__pyx_k_sklearn_base), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_feature_extraction_text, __pyx_k_sklearn_feature_extraction_text, sizeof(__pyx_k_sklearn_feature_extraction_text), 0, 0, 1, 1},
  {&__pyx_n_s_sklearn_pipeline, __pyx_k_sklearn_pipeline, sizeof(__pyx_k_sklearn_pipeline), 0, 0, 1, 1},
  {&__pyx_n_s_sparse, __pyx_k_sparse, sizeof(__pyx_k_sparse), 0, 0, 1, 1},
  {&__pyx_n_s_split, __pyx_k_split, sizeof(__pyx_k_split), 0, 0, 1, 1},
  {&__pyx_n_s_stopwords, __pyx_k_stopwords, sizeof(__pyx_k_stopwords), 0, 0, 1, 1},
  {&__pyx_n_s_stopwords_2, __pyx_k_stopwords_2, sizeof(__pyx_k_stopwords_2), 0, 0, 1, 1},
  {&__pyx_n_s_super, __pyx_k_super, sizeof(__pyx_k_super), 0, 0, 1, 1},
  {&__pyx_n_s_sys, __pyx_k_sys, sizeof(__pyx_k_sys), 0, 0, 1, 1},
  {&__pyx_n_s_tar1, __pyx_k_tar1, sizeof(__pyx_k_tar1), 0, 0, 1, 1},
  {&__pyx_n_s_tar2, __pyx_k_tar2, sizeof(__pyx_k_tar2), 0, 0, 1, 1},
  {&__pyx_n_s_target, __pyx_k_target, sizeof(__pyx_k_target), 0, 0, 1, 1},
  {&__pyx_n_s_targets, __pyx_k_targets, sizeof(__pyx_k_targets), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_throw, __pyx_k_throw, sizeof(__pyx_k_throw), 0, 0, 1, 1},
  {&__pyx_n_s_tocsr, __pyx_k_tocsr, sizeof(__pyx_k_tocsr), 0, 0, 1, 1},
  {&__pyx_n_s_todense, __pyx_k_todense, sizeof(__pyx_k_todense), 0, 0, 1, 1},
  {&__pyx_n_s_trans, __pyx_k_trans, sizeof(__pyx_k_trans), 0, 0, 1, 1},
  {&__pyx_kp_s_trans_py, __pyx_k_trans_py, sizeof(__pyx_k_trans_py), 0, 0, 1, 0},
  {&__pyx_n_s_transform, __pyx_k_transform, sizeof(__pyx_k_transform), 0, 0, 1, 1},
  {&__pyx_n_s_transform_one, __pyx_k_transform_one, sizeof(__pyx_k_transform_one), 0, 0, 1, 1},
  {&__pyx_n_s_transformer, __pyx_k_transformer, sizeof(__pyx_k_transformer), 0, 0, 1, 1},
  {&__pyx_n_s_transformers, __pyx_k_transformers, sizeof(__pyx_k_transformers), 0, 0, 1, 1},
  {&__pyx_n_s_update_transformer_list, __pyx_k_update_transformer_list, sizeof(__pyx_k_update_transformer_list), 0, 0, 1, 1},
  {&__pyx_n_s_validate_transformers, __pyx_k_validate_transformers, sizeof(__pyx_k_validate_transformers), 0, 0, 1, 1},
  {&__pyx_n_s_version, __pyx_k_version, sizeof(__pyx_k_version), 0, 0, 1, 1},
  {&__pyx_n_s_weight, __pyx_k_weight, sizeof(__pyx_k_weight), 0, 0, 1, 1},
  {&__pyx_n_s_words, __pyx_k_words, sizeof(__pyx_k_words), 0, 0, 1, 1},
  {&__pyx_n_s_x, __pyx_k_x, sizeof(__pyx_k_x), 0, 0, 1, 1},
  {&__pyx_n_s_y, __pyx_k_y, sizeof(__pyx_k_y), 0, 0, 1, 1},
  {&__pyx_n_s_zeros, __pyx_k_zeros, sizeof(__pyx_k_zeros), 0, 0, 1, 1},
  {&__pyx_n_s_zip, __pyx_k_zip, sizeof(__pyx_k_zip), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_zip = __Pyx_GetBuiltinName(__pyx_n_s_zip); if (!__pyx_builtin_zip) __PYX_ERR(0, 256, __pyx_L1_error)
  __pyx_builtin_super = __Pyx_GetBuiltinName(__pyx_n_s_super); if (!__pyx_builtin_super) __PYX_ERR(0, 305, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  /* "trans.py":114
 *         missing = ['', None]
 *         for y in X.columns:
 *             X[y].apply(lambda x: X[y].mean() for z in X.split(' ') if z.replace(' ','') in missing) # Please don't code and drink.             # <<<<<<<<<<<<<<
 *         return X
 *
 */
  __pyx_tuple__3 = PyTuple_Pack(2, __pyx_kp_u_, __pyx_kp_u__2); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);

  /* "trans.py":363
 *
 *     def transform(self, X):
 *         return X[:, 1:]             # <<<<<<<<<<<<<<
 */
  __pyx_slice__5 = PySlice_New(Py_None, Py_None, Py_None); if (unlikely(!__pyx_slice__5)) __PYX_ERR(0, 363, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__5);
  __Pyx_GIVEREF(__pyx_slice__5);
  __pyx_slice__6 = PySlice_New(__pyx_int_1, Py_None, Py_None); if (unlikely(!__pyx_slice__6)) __PYX_ERR(0, 363, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__6);
  __Pyx_GIVEREF(__pyx_slice__6);
  __pyx_tuple__7 = PyTuple_Pack(2, __pyx_slice__5, __pyx_slice__6); if (unlikely(!__pyx_tuple__7)) __PYX_ERR(0, 363, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__7);
  __Pyx_GIVEREF(__pyx_tuple__7);

  /* "trans.py":21
 * #logger = logging.getLogger()
 * pd.options.mode.chained_assignment = None
 * stopwords_ = set(stopwords.words('english'))             # <<<<<<<<<<<<<<
 *
 *
 */
  __pyx_tuple__8 = PyTuple_Pack(1, __pyx_n_u_english); if (unlikely(!__pyx_tuple__8)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__8);
  __Pyx_GIVEREF(__pyx_tuple__8);

  /* "trans.py":29
 * class TextSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single text column from the data frame on which to perform transformations. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */
  __pyx_tuple__9 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__9)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__9);
  __Pyx_GIVEREF(__pyx_tuple__9);
  __pyx_codeobj__10 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__9, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 29, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__10)) __PYX_ERR(0, 29, __pyx_L1_error)
  __pyx_tuple__11 = PyTuple_Pack(1, ((PyObject*)__pyx_n_u_raw)); if (unlikely(!__pyx_tuple__11)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__11);
  __Pyx_GIVEREF(__pyx_tuple__11);

  /* "trans.py":32
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__12 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__12)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__12);
  __Pyx_GIVEREF(__pyx_tuple__12);
  __pyx_codeobj__13 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__12, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 32, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__13)) __PYX_ERR(0, 32, __pyx_L1_error)
  __pyx_tuple__14 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__14)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__14);
  __Pyx_GIVEREF(__pyx_tuple__14);

  /* "trans.py":35
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.key]
 *         #return X[self]
 */
  __pyx_tuple__15 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);
  __pyx_codeobj__16 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__15, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 35, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__16)) __PYX_ERR(0, 35, __pyx_L1_error)

  /* "trans.py":42
 * class TextSelectorMulti(BaseEstimator, TransformerMixin):
 *     """ Select multiple text columns from the data frame on which to perform transformations. """
 *     def __init__(self, keys: list):             # <<<<<<<<<<<<<<
 *         self.keys = keys
 *
 */
  __pyx_tuple__17 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_keys); if (unlikely(!__pyx_tuple__17)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__17);
  __Pyx_GIVEREF(__pyx_tuple__17);
  __pyx_codeobj__18 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__17, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 42, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__18)) __PYX_ERR(0, 42, __pyx_L1_error)

  /* "trans.py":45
 *         self.keys = keys
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__19 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);
  __pyx_codeobj__20 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__19, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 45, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__20)) __PYX_ERR(0, 45, __pyx_L1_error)
  __pyx_tuple__21 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__21)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__21);
  __Pyx_GIVEREF(__pyx_tuple__21);

  /* "trans.py":48
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.keys]
 *
 */
  __pyx_tuple__22 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__22)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__22);
  __Pyx_GIVEREF(__pyx_tuple__22);
  __pyx_codeobj__23 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__22, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 48, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__23)) __PYX_ERR(0, 48, __pyx_L1_error)

  /* "trans.py":55
 * class NumberSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single numeric column from the data frame on which to perform transformations. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */
  __pyx_tuple__24 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__24)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__24);
  __Pyx_GIVEREF(__pyx_tuple__24);
  __pyx_codeobj__25 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__24, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 55, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__25)) __PYX_ERR(0, 55, __pyx_L1_error)
  __pyx_tuple__26 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__26)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__26);
  __Pyx_GIVEREF(__pyx_tuple__26);

  /* "trans.py":58
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__27 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__27)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__27);
  __Pyx_GIVEREF(__pyx_tuple__27);
  __pyx_codeobj__28 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__27, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 58, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__28)) __PYX_ERR(0, 58, __pyx_L1_error)
  __pyx_tuple__29 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__29)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__29);
  __Pyx_GIVEREF(__pyx_tuple__29);

  /* "trans.py":61
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[[self.key]]
 *
 */
  __pyx_tuple__30 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__30)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__30);
  __Pyx_GIVEREF(__pyx_tuple__30);
  __pyx_codeobj__31 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__30, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 61, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__31)) __PYX_ERR(0, 61, __pyx_L1_error)

  /* "trans.py":67
 * class FeatureSelector(BaseEstimator, TransformerMixin):
 *     """ Select only the features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */
  __pyx_tuple__32 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_feats); if (unlikely(!__pyx_tuple__32)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__32);
  __Pyx_GIVEREF(__pyx_tuple__32);
  __pyx_codeobj__33 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__32, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 67, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__33)) __PYX_ERR(0, 67, __pyx_L1_error)
  __pyx_tuple__34 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__34)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__34);
  __Pyx_GIVEREF(__pyx_tuple__34);

  /* "trans.py":70
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__35 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__35)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__35);
  __Pyx_GIVEREF(__pyx_tuple__35);
  __pyx_codeobj__36 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__35, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 70, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__36)) __PYX_ERR(0, 70, __pyx_L1_error)
  __pyx_tuple__37 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__37)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__37);
  __Pyx_GIVEREF(__pyx_tuple__37);

  /* "trans.py":73
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.feats]
 *
 */
  __pyx_tuple__38 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__38)) __PYX_ERR(0, 73, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__38);
  __Pyx_GIVEREF(__pyx_tuple__38);
  __pyx_codeobj__39 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__38, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 73, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__39)) __PYX_ERR(0, 73, __pyx_L1_error)

  /* "trans.py":79
 * class DropFeatures(BaseEstimator, TransformerMixin):
 *     """ Drop any features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */
  __pyx_tuple__40 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_feats); if (unlikely(!__pyx_tuple__40)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__40);
  __Pyx_GIVEREF(__pyx_tuple__40);
  __pyx_codeobj__41 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__40, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 79, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__41)) __PYX_ERR(0, 79, __pyx_L1_error)
  __pyx_tuple__42 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__42)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__42);
  __Pyx_GIVEREF(__pyx_tuple__42);

  /* "trans.py":82
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__43 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__43)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__43);
  __Pyx_GIVEREF(__pyx_tuple__43);
  __pyx_codeobj__44 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__43, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 82, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__44)) __PYX_ERR(0, 82, __pyx_L1_error)
  __pyx_tuple__45 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__45)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__45);
  __Pyx_GIVEREF(__pyx_tuple__45);

  /* "trans.py":85
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X.drop(self.feats, axis=1)
 *
 */
  __pyx_tuple__46 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__46)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__46);
  __Pyx_GIVEREF(__pyx_tuple__46);
  __pyx_codeobj__47 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__46, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 85, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__47)) __PYX_ERR(0, 85, __pyx_L1_error)

  /* "trans.py":91
 * class ConvertTargets(BaseEstimator, TransformerMixin):
 *     """ Convert target categories to int. """
 *     def __init__(self, targets: list=None):             # <<<<<<<<<<<<<<
 *         self.targets = targets
 *
 */
  __pyx_tuple__48 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_targets); if (unlikely(!__pyx_tuple__48)) __PYX_ERR(0, 91, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__48);
  __Pyx_GIVEREF(__pyx_tuple__48);
  __pyx_codeobj__49 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__48, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 91, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__49)) __PYX_ERR(0, 91, __pyx_L1_error)
  __pyx_tuple__50 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__50)) __PYX_ERR(0, 91, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__50);
  __Pyx_GIVEREF(__pyx_tuple__50);

  /* "trans.py":94
 *         self.targets = targets
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__51 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__51)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__51);
  __Pyx_GIVEREF(__pyx_tuple__51);
  __pyx_codeobj__52 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__51, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 94, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__52)) __PYX_ERR(0, 94, __pyx_L1_error)
  __pyx_tuple__53 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__53)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__53);
  __Pyx_GIVEREF(__pyx_tuple__53);

  /* "trans.py":97
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return # @TODO
 *
 */
  __pyx_tuple__54 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__54)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__54);
  __Pyx_GIVEREF(__pyx_tuple__54);
  __pyx_codeobj__55 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__54, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 97, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__55)) __PYX_ERR(0, 97, __pyx_L1_error)

  /* "trans.py":105
 * class MissingData(BaseEstimator, TransformerMixin):
 *     """ Examines dataset for missing values, smh. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */
  __pyx_tuple__56 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__56)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__56);
  __Pyx_GIVEREF(__pyx_tuple__56);
  __pyx_codeobj__57 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__56, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 105, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__57)) __PYX_ERR(0, 105, __pyx_L1_error)
  __pyx_tuple__58 = PyTuple_Pack(1, ((PyObject*)__pyx_n_u_raw)); if (unlikely(!__pyx_tuple__58)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__58);
  __Pyx_GIVEREF(__pyx_tuple__58);

  /* "trans.py":108
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__59 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__59)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__59);
  __Pyx_GIVEREF(__pyx_tuple__59);
  __pyx_codeobj__60 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__59, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 108, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__60)) __PYX_ERR(0, 108, __pyx_L1_error)
  __pyx_tuple__61 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__61)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__61);
  __Pyx_GIVEREF(__pyx_tuple__61);

  /* "trans.py":111
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         missing = ['', None]
 *         for y in X.columns:
 */
  __pyx_tuple__62 = PyTuple_Pack(6, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_missing, __pyx_n_s_y, __pyx_n_s_genexpr, __pyx_n_s_genexpr); if (unlikely(!__pyx_tuple__62)) __PYX_ERR(0, 111, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__62);
  __Pyx_GIVEREF(__pyx_tuple__62);
  __pyx_codeobj__63 = (PyObject*)__Pyx_PyCode_New(2, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__62, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 111, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__63)) __PYX_ERR(0, 111, __pyx_L1_error)

  /* "trans.py":121
 * class SentenceLength(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */
  __pyx_tuple__64 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__64)) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__64);
  __Pyx_GIVEREF(__pyx_tuple__64);
  __pyx_codeobj__65 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__64, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 121, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__65)) __PYX_ERR(0, 121, __pyx_L1_error)
  __pyx_tuple__66 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__66)) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__66);
  __Pyx_GIVEREF(__pyx_tuple__66);

  /* "trans.py":125
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__67 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__67)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__67);
  __Pyx_GIVEREF(__pyx_tuple__67);
  __pyx_codeobj__68 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__67, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 125, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__68)) __PYX_ERR(0, 125, __pyx_L1_error)
  __pyx_tuple__69 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__69)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__69);
  __Pyx_GIVEREF(__pyx_tuple__69);

  /* "trans.py":128
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))
 *         return X
 */
  __pyx_tuple__70 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__70)) __PYX_ERR(0, 128, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__70);
  __Pyx_GIVEREF(__pyx_tuple__70);
  __pyx_codeobj__71 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__70, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 128, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__71)) __PYX_ERR(0, 128, __pyx_L1_error)

  /* "trans.py":135
 * class CountCommas(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */
  __pyx_tuple__72 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__72)) __PYX_ERR(0, 135, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__72);
  __Pyx_GIVEREF(__pyx_tuple__72);
  __pyx_codeobj__73 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__72, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 135, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__73)) __PYX_ERR(0, 135, __pyx_L1_error)
  __pyx_tuple__74 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__74)) __PYX_ERR(0, 135, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__74);
  __Pyx_GIVEREF(__pyx_tuple__74);

  /* "trans.py":139
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__75 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__75)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__75);
  __Pyx_GIVEREF(__pyx_tuple__75);
  __pyx_codeobj__76 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__75, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 139, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__76)) __PYX_ERR(0, 139, __pyx_L1_error)
  __pyx_tuple__77 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__77)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__77);
  __Pyx_GIVEREF(__pyx_tuple__77);

  /* "trans.py":142
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))
 *         return X
 */
  __pyx_tuple__78 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__78)) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__78);
  __Pyx_GIVEREF(__pyx_tuple__78);
  __pyx_codeobj__79 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__78, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 142, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__79)) __PYX_ERR(0, 142, __pyx_L1_error)

  /* "trans.py":149
 * class CountWords(BaseEstimator, TransformerMixin):
 *     """ Count words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */
  __pyx_tuple__80 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__80)) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__80);
  __Pyx_GIVEREF(__pyx_tuple__80);
  __pyx_codeobj__81 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__80, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 149, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__81)) __PYX_ERR(0, 149, __pyx_L1_error)
  __pyx_tuple__82 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__82)) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__82);
  __Pyx_GIVEREF(__pyx_tuple__82);

  /* "trans.py":152
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__83 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__83)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__83);
  __Pyx_GIVEREF(__pyx_tuple__83);
  __pyx_codeobj__84 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__83, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 152, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__84)) __PYX_ERR(0, 152, __pyx_L1_error)
  __pyx_tuple__85 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__85)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__85);
  __Pyx_GIVEREF(__pyx_tuple__85);

  /* "trans.py":155
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))
 *         #X = X.apply(lambda x: len(x.split(' ')))
 */
  __pyx_tuple__86 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__86)) __PYX_ERR(0, 155, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__86);
  __Pyx_GIVEREF(__pyx_tuple__86);
  __pyx_codeobj__87 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__86, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 155, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__87)) __PYX_ERR(0, 155, __pyx_L1_error)

  /* "trans.py":164
 *     """ Transformer to calculate average word length. """
 *
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */
  __pyx_tuple__88 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__88)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__88);
  __Pyx_GIVEREF(__pyx_tuple__88);
  __pyx_codeobj__89 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__88, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 164, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__89)) __PYX_ERR(0, 164, __pyx_L1_error)
  __pyx_tuple__90 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__90)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__90);
  __Pyx_GIVEREF(__pyx_tuple__90);

  /* "trans.py":167
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__91 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__91)) __PYX_ERR(0, 167, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__91);
  __Pyx_GIVEREF(__pyx_tuple__91);
  __pyx_codeobj__92 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__91, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 167, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__92)) __PYX_ERR(0, 167, __pyx_L1_error)
  __pyx_tuple__93 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__93)) __PYX_ERR(0, 167, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__93);
  __Pyx_GIVEREF(__pyx_tuple__93);

  /* "trans.py":170
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)
 *         return X
 */
  __pyx_tuple__94 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__94)) __PYX_ERR(0, 170, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__94);
  __Pyx_GIVEREF(__pyx_tuple__94);
  __pyx_codeobj__95 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__94, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 170, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__95)) __PYX_ERR(0, 170, __pyx_L1_error)

  /* "trans.py":177
 * class NotStopsTransformer(BaseEstimator, TransformerMixin):
 *     """ Non-stop words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */
  __pyx_tuple__96 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__96)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__96);
  __Pyx_GIVEREF(__pyx_tuple__96);
  __pyx_codeobj__97 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__96, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 177, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__97)) __PYX_ERR(0, 177, __pyx_L1_error)
  __pyx_tuple__98 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__98)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__98);
  __Pyx_GIVEREF(__pyx_tuple__98);

  /* "trans.py":180
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__99 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__99)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__99);
  __Pyx_GIVEREF(__pyx_tuple__99);
  __pyx_codeobj__100 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__99, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 180, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__100)) __PYX_ERR(0, 180, __pyx_L1_error)
  __pyx_tuple__101 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__101)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__101);
  __Pyx_GIVEREF(__pyx_tuple__101);

  /* "trans.py":183
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))
 *         return X
 */
  __pyx_tuple__102 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__102)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__102);
  __Pyx_GIVEREF(__pyx_tuple__102);
  __pyx_codeobj__103 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__102, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 183, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__103)) __PYX_ERR(0, 183, __pyx_L1_error)

  /* "trans.py":190
 * class CommaLenRatio(BaseEstimator, TransformerMixin):
 *     """ Hard-coded experimental feature. N.B. This is an entropy source. """
 *     def __init__(self, col=None): # text col is ignored in non-measured feature.             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__104 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_col); if (unlikely(!__pyx_tuple__104)) __PYX_ERR(0, 190, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__104);
  __Pyx_GIVEREF(__pyx_tuple__104);
  __pyx_codeobj__105 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__104, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 190, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__105)) __PYX_ERR(0, 190, __pyx_L1_error)
  __pyx_tuple__106 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__106)) __PYX_ERR(0, 190, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__106);
  __Pyx_GIVEREF(__pyx_tuple__106);

  /* "trans.py":193
 *         pass
 *
 *     def divide(self, x, y):             # <<<<<<<<<<<<<<
 *         if y != 0:
 *             return x//y
 */
  __pyx_tuple__107 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_x, __pyx_n_s_y); if (unlikely(!__pyx_tuple__107)) __PYX_ERR(0, 193, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__107);
  __Pyx_GIVEREF(__pyx_tuple__107);
  __pyx_codeobj__108 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__107, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_divide, 193, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__108)) __PYX_ERR(0, 193, __pyx_L1_error)

  /* "trans.py":199
 *             return 0
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__109 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__109)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__109);
  __Pyx_GIVEREF(__pyx_tuple__109);
  __pyx_codeobj__110 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__109, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 199, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__110)) __PYX_ERR(0, 199, __pyx_L1_error)
  __pyx_tuple__111 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__111)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__111);
  __Pyx_GIVEREF(__pyx_tuple__111);

  /* "trans.py":202
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)
 *
 */
  __pyx_tuple__112 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__112)) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__112);
  __Pyx_GIVEREF(__pyx_tuple__112);
  __pyx_codeobj__113 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__112, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 202, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__113)) __PYX_ERR(0, 202, __pyx_L1_error)

  /* "trans.py":212
 * class BooleanTargets(BaseEstimator, TransformerMixin):
 *     """ Converts binary classification labels to boolean values. (In place, does not add new column.) """
 *     def __init__(self, col, tar1, tar2):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         self.a = tar1
 */
  __pyx_tuple__114 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_col, __pyx_n_s_tar1, __pyx_n_s_tar2); if (unlikely(!__pyx_tuple__114)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__114);
  __Pyx_GIVEREF(__pyx_tuple__114);
  __pyx_codeobj__115 = (PyObject*)__Pyx_PyCode_New(4, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__114, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 212, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__115)) __PYX_ERR(0, 212, __pyx_L1_error)

  /* "trans.py":217
 *         self.b = tar2
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__116 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__116)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__116);
  __Pyx_GIVEREF(__pyx_tuple__116);
  __pyx_codeobj__117 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__116, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 217, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__117)) __PYX_ERR(0, 217, __pyx_L1_error)
  __pyx_tuple__118 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__118)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__118);
  __Pyx_GIVEREF(__pyx_tuple__118);

  /* "trans.py":220
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         target = self.col
 *         X.loc[(X.target == self.a), target] = 0
 */
  __pyx_tuple__119 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_target); if (unlikely(!__pyx_tuple__119)) __PYX_ERR(0, 220, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__119);
  __Pyx_GIVEREF(__pyx_tuple__119);
  __pyx_codeobj__120 = (PyObject*)__Pyx_PyCode_New(2, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__119, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 220, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__120)) __PYX_ERR(0, 220, __pyx_L1_error)

  /* "trans.py":230
 *
 * class PandasTransformer(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */
  __pyx_tuple__121 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_fn); if (unlikely(!__pyx_tuple__121)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__121);
  __Pyx_GIVEREF(__pyx_tuple__121);
  __pyx_codeobj__122 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__121, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 230, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__122)) __PYX_ERR(0, 230, __pyx_L1_error)

  /* "trans.py":233
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__123 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__123)) __PYX_ERR(0, 233, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__123);
  __Pyx_GIVEREF(__pyx_tuple__123);
  __pyx_codeobj__124 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__123, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 233, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__124)) __PYX_ERR(0, 233, __pyx_L1_error)
  __pyx_tuple__125 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__125)) __PYX_ERR(0, 233, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__125);
  __Pyx_GIVEREF(__pyx_tuple__125);

  /* "trans.py":236
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fn(X)
 *
 */
  __pyx_tuple__126 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y, __pyx_n_s_copy); if (unlikely(!__pyx_tuple__126)) __PYX_ERR(0, 236, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__126);
  __Pyx_GIVEREF(__pyx_tuple__126);
  __pyx_codeobj__127 = (PyObject*)__Pyx_PyCode_New(4, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__126, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 236, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__127)) __PYX_ERR(0, 236, __pyx_L1_error)
  __pyx_tuple__128 = PyTuple_Pack(2, ((PyObject *)Py_None), ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__128)) __PYX_ERR(0, 236, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__128);
  __Pyx_GIVEREF(__pyx_tuple__128);

  /* "trans.py":242
 * class PandasFeatureUnion(FeatureUnion):
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 */
  __pyx_tuple__129 = PyTuple_Pack(10, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y, __pyx_n_s_fit_params, __pyx_n_s_result, __pyx_n_s_Xs, __pyx_n_s_transformers, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr); if (unlikely(!__pyx_tuple__129)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__129);
  __Pyx_GIVEREF(__pyx_tuple__129);
  __pyx_codeobj__130 = (PyObject*)__Pyx_PyCode_New(3, 0, 10, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARKEYWORDS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__129, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit_transform, 242, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__130)) __PYX_ERR(0, 242, __pyx_L1_error)
  __pyx_tuple__131 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__131)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__131);
  __Pyx_GIVEREF(__pyx_tuple__131);

  /* "trans.py":264
 *         return Xs
 *
 *     def merge_dataframes_by_column(self, Xs):             # <<<<<<<<<<<<<<
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 */
  __pyx_tuple__132 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_Xs); if (unlikely(!__pyx_tuple__132)) __PYX_ERR(0, 264, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__132);
  __Pyx_GIVEREF(__pyx_tuple__132);
  __pyx_codeobj__133 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__132, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_merge_dataframes_by_column, 264, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__133)) __PYX_ERR(0, 264, __pyx_L1_error)

  /* "trans.py":267
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(
 */
  __pyx_tuple__134 = PyTuple_Pack(6, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_Xs, __pyx_n_s_genexpr, __pyx_n_s_genexpr, __pyx_n_s_genexpr); if (unlikely(!__pyx_tuple__134)) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__134);
  __Pyx_GIVEREF(__pyx_tuple__134);
  __pyx_codeobj__135 = (PyObject*)__Pyx_PyCode_New(2, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__134, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 267, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__135)) __PYX_ERR(0, 267, __pyx_L1_error)

  /* "trans.py":294
 * class DenseTransformer(TransformerMixin):
 *
 *     def fit(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__136 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y, __pyx_n_s_fit_params); if (unlikely(!__pyx_tuple__136)) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__136);
  __Pyx_GIVEREF(__pyx_tuple__136);
  __pyx_codeobj__137 = (PyObject*)__Pyx_PyCode_New(3, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARKEYWORDS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__136, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 294, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__137)) __PYX_ERR(0, 294, __pyx_L1_error)
  __pyx_tuple__138 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__138)) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__138);
  __Pyx_GIVEREF(__pyx_tuple__138);

  /* "trans.py":297
 *         return self
 *
 *     def transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return X.todense()
 *
 */
  __pyx_tuple__139 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y, __pyx_n_s_fit_params); if (unlikely(!__pyx_tuple__139)) __PYX_ERR(0, 297, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__139);
  __Pyx_GIVEREF(__pyx_tuple__139);
  __pyx_codeobj__140 = (PyObject*)__Pyx_PyCode_New(3, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARKEYWORDS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__139, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 297, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__140)) __PYX_ERR(0, 297, __pyx_L1_error)
  __pyx_tuple__141 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__141)) __PYX_ERR(0, 297, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__141);
  __Pyx_GIVEREF(__pyx_tuple__141);

  /* "trans.py":304
 *     """ Wrapper for vector functions to handle DataFrames. """
 *
 *     def __init__(self, *args, **kwargs):             # <<<<<<<<<<<<<<
 *         super(WordVectorTransform, self).__init__(*args, **kwargs)
 *
 */
  __pyx_tuple__142 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_args, __pyx_n_s_kwargs); if (unlikely(!__pyx_tuple__142)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__142);
  __Pyx_GIVEREF(__pyx_tuple__142);
  __pyx_codeobj__143 = (PyObject*)__Pyx_PyCode_New(1, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS|CO_VARKEYWORDS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__142, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 304, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__143)) __PYX_ERR(0, 304, __pyx_L1_error)

  /* "trans.py":312
 *     """ Neural Network tranformation pipe """
 *
 *     def __init__(self, ann):             # <<<<<<<<<<<<<<
 *         self.ann = ann
 *
 */
  __pyx_tuple__144 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_ann); if (unlikely(!__pyx_tuple__144)) __PYX_ERR(0, 312, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__144);
  __Pyx_GIVEREF(__pyx_tuple__144);
  __pyx_codeobj__145 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__144, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 312, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__145)) __PYX_ERR(0, 312, __pyx_L1_error)

  /* "trans.py":315
 *         self.ann = ann
 *
 *     def fit(self, X, y):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__146 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__146)) __PYX_ERR(0, 315, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__146);
  __Pyx_GIVEREF(__pyx_tuple__146);
  __pyx_codeobj__147 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__146, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 315, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__147)) __PYX_ERR(0, 315, __pyx_L1_error)

  /* "trans.py":318
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return self.ann.predict(X)
 *
 */
  __pyx_tuple__148 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__148)) __PYX_ERR(0, 318, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__148);
  __Pyx_GIVEREF(__pyx_tuple__148);
  __pyx_codeobj__149 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__148, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 318, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__149)) __PYX_ERR(0, 318, __pyx_L1_error)

  /* "trans.py":326
 * # If you need a sanity check, and don't have a d20 handy.
 * class TestTransform(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */
  __pyx_tuple__150 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_fn); if (unlikely(!__pyx_tuple__150)) __PYX_ERR(0, 326, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__150);
  __Pyx_GIVEREF(__pyx_tuple__150);
  __pyx_codeobj__151 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__150, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 326, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__151)) __PYX_ERR(0, 326, __pyx_L1_error)

  /* "trans.py":329
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__152 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__152)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__152);
  __Pyx_GIVEREF(__pyx_tuple__152);
  __pyx_codeobj__153 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__152, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 329, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__153)) __PYX_ERR(0, 329, __pyx_L1_error)
  __pyx_tuple__154 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__154)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__154);
  __Pyx_GIVEREF(__pyx_tuple__154);

  /* "trans.py":332
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fun(X)
 *
 */
  __pyx_tuple__155 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y, __pyx_n_s_copy); if (unlikely(!__pyx_tuple__155)) __PYX_ERR(0, 332, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__155);
  __Pyx_GIVEREF(__pyx_tuple__155);
  __pyx_codeobj__156 = (PyObject*)__Pyx_PyCode_New(4, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__155, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 332, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__156)) __PYX_ERR(0, 332, __pyx_L1_error)
  __pyx_tuple__157 = PyTuple_Pack(2, ((PyObject *)Py_None), ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__157)) __PYX_ERR(0, 332, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__157);
  __Pyx_GIVEREF(__pyx_tuple__157);

  /* "trans.py":335
 *         return self.fun(X)
 *
 *     def fun(self, X):             # <<<<<<<<<<<<<<
 *         #X = X + 11
 *         X = (X - np.mean(X)) / (np.max(X) - np.min(X))
 */
  __pyx_tuple__158 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__158)) __PYX_ERR(0, 335, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__158);
  __Pyx_GIVEREF(__pyx_tuple__158);
  __pyx_codeobj__159 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__158, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fun, 335, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__159)) __PYX_ERR(0, 335, __pyx_L1_error)

  /* "trans.py":344
 *     """A template for a custom transformer. (TransformerMixin is for .fit_transform method.) """
 *
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__160 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__160)) __PYX_ERR(0, 344, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__160);
  __Pyx_GIVEREF(__pyx_tuple__160);
  __pyx_codeobj__161 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__160, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 344, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__161)) __PYX_ERR(0, 344, __pyx_L1_error)

  /* "trans.py":347
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__162 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__162)) __PYX_ERR(0, 347, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__162);
  __Pyx_GIVEREF(__pyx_tuple__162);
  __pyx_codeobj__163 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__162, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 347, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__163)) __PYX_ERR(0, 347, __pyx_L1_error)
  __pyx_tuple__164 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__164)) __PYX_ERR(0, 347, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__164);
  __Pyx_GIVEREF(__pyx_tuple__164);

  /* "trans.py":350
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         # transform X via code or additional methods
 *         return X
 */
  __pyx_tuple__165 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__165)) __PYX_ERR(0, 350, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__165);
  __Pyx_GIVEREF(__pyx_tuple__165);
  __pyx_codeobj__166 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__165, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 350, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__166)) __PYX_ERR(0, 350, __pyx_L1_error)

  /* "trans.py":356
 *
 * class Wat(TransformerMixin, BaseEstimator):
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_tuple__167 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__167)) __PYX_ERR(0, 356, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__167);
  __Pyx_GIVEREF(__pyx_tuple__167);
  __pyx_codeobj__168 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__167, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_init, 356, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__168)) __PYX_ERR(0, 356, __pyx_L1_error)

  /* "trans.py":359
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_tuple__169 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_X, __pyx_n_s_y); if (unlikely(!__pyx_tuple__169)) __PYX_ERR(0, 359, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__169);
  __Pyx_GIVEREF(__pyx_tuple__169);
  __pyx_codeobj__170 = (PyObject*)__Pyx_PyCode_New(3, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__169, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_fit, 359, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__170)) __PYX_ERR(0, 359, __pyx_L1_error)
  __pyx_tuple__171 = PyTuple_Pack(1, ((PyObject *)Py_None)); if (unlikely(!__pyx_tuple__171)) __PYX_ERR(0, 359, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__171);
  __Pyx_GIVEREF(__pyx_tuple__171);

  /* "trans.py":362
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[:, 1:]
 */
  __pyx_tuple__172 = PyTuple_Pack(2, __pyx_n_s_self, __pyx_n_s_X); if (unlikely(!__pyx_tuple__172)) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__172);
  __Pyx_GIVEREF(__pyx_tuple__172);
  __pyx_codeobj__173 = (PyObject*)__Pyx_PyCode_New(2, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__172, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_trans_py, __pyx_n_s_transform, 362, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__173)) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
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
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  /*--- Type init code ---*/
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct__transform) < 0) __PYX_ERR(0, 111, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct__transform.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct__transform.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct__transform.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct__transform.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct__transform = &__pyx_type_5trans___pyx_scope_struct__transform;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_1_genexpr) < 0) __PYX_ERR(0, 114, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_1_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_1_genexpr.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_1_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_1_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_1_genexpr = &__pyx_type_5trans___pyx_scope_struct_1_genexpr;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_2_transform) < 0) __PYX_ERR(0, 202, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_2_transform.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_2_transform.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_2_transform.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_2_transform.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_2_transform = &__pyx_type_5trans___pyx_scope_struct_2_transform;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_3_fit_transform) < 0) __PYX_ERR(0, 242, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_3_fit_transform.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_3_fit_transform.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_3_fit_transform.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_3_fit_transform.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_3_fit_transform = &__pyx_type_5trans___pyx_scope_struct_3_fit_transform;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_4_genexpr) < 0) __PYX_ERR(0, 245, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_4_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_4_genexpr.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_4_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_4_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_4_genexpr = &__pyx_type_5trans___pyx_scope_struct_4_genexpr;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_5_genexpr) < 0) __PYX_ERR(0, 258, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_5_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_5_genexpr.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_5_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_5_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_5_genexpr = &__pyx_type_5trans___pyx_scope_struct_5_genexpr;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_6_transform) < 0) __PYX_ERR(0, 267, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_6_transform.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_6_transform.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_6_transform.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_6_transform.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_6_transform = &__pyx_type_5trans___pyx_scope_struct_6_transform;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_7_genexpr) < 0) __PYX_ERR(0, 269, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_7_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_7_genexpr.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_7_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_7_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_7_genexpr = &__pyx_type_5trans___pyx_scope_struct_7_genexpr;
  if (PyType_Ready(&__pyx_type_5trans___pyx_scope_struct_8_genexpr) < 0) __PYX_ERR(0, 278, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_5trans___pyx_scope_struct_8_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_5trans___pyx_scope_struct_8_genexpr.tp_dictoffset && __pyx_type_5trans___pyx_scope_struct_8_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_5trans___pyx_scope_struct_8_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_5trans___pyx_scope_struct_8_genexpr = &__pyx_type_5trans___pyx_scope_struct_8_genexpr;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
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
__Pyx_PyMODINIT_FUNC inittrans(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC inittrans(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_trans(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC PyInit_trans(void)
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


static CYTHON_SMALL_CODE int __pyx_pymod_exec_trans(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'trans' has already been imported. Re-initialisation is not supported.");
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
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_trans(void)", 0);
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
  __pyx_m = Py_InitModule4("trans", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
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
  if (__pyx_module_is_main_trans) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "trans")) {
      if (unlikely(PyDict_SetItemString(modules, "trans", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
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
  if (unlikely(__Pyx_modinit_type_init_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  /*--- Execution code ---*/
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  /* "trans.py":3
 * #!/usr/bin/env python
 * # trans.py - Transform builder class and assorted transformer defitions
 * __version__ = '0.0.1'             # <<<<<<<<<<<<<<
 *
 * import sys
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_version, __pyx_kp_u_0_0_1) < 0) __PYX_ERR(0, 3, __pyx_L1_error)

  /* "trans.py":5
 * __version__ = '0.0.1'
 *
 * import sys             # <<<<<<<<<<<<<<
 *
 * import numpy as np
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sys, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sys, __pyx_t_1) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":7
 * import sys
 *
 * import numpy as np             # <<<<<<<<<<<<<<
 * import pandas as pd
 * from nltk.corpus import stopwords
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_numpy, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_np, __pyx_t_1) < 0) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":8
 *
 * import numpy as np
 * import pandas as pd             # <<<<<<<<<<<<<<
 * from nltk.corpus import stopwords
 * from scipy import sparse
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_pandas, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_pd, __pyx_t_1) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":9
 * import numpy as np
 * import pandas as pd
 * from nltk.corpus import stopwords             # <<<<<<<<<<<<<<
 * from scipy import sparse
 * from sklearn.base import BaseEstimator, TransformerMixin, ClassifierMixin
 */
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_stopwords_2);
  __Pyx_GIVEREF(__pyx_n_s_stopwords_2);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_stopwords_2);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_nltk_corpus, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_stopwords_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_stopwords_2, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":10
 * import pandas as pd
 * from nltk.corpus import stopwords
 * from scipy import sparse             # <<<<<<<<<<<<<<
 * from sklearn.base import BaseEstimator, TransformerMixin, ClassifierMixin
 * from sklearn.pipeline import FeatureUnion, _fit_transform_one, _transform_one
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_sparse);
  __Pyx_GIVEREF(__pyx_n_s_sparse);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_sparse);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_scipy, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_sparse); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sparse, __pyx_t_2) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":11
 * from nltk.corpus import stopwords
 * from scipy import sparse
 * from sklearn.base import BaseEstimator, TransformerMixin, ClassifierMixin             # <<<<<<<<<<<<<<
 * from sklearn.pipeline import FeatureUnion, _fit_transform_one, _transform_one
 * from joblib import Parallel, delayed
 */
  __pyx_t_1 = PyList_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_BaseEstimator);
  __Pyx_GIVEREF(__pyx_n_s_BaseEstimator);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_BaseEstimator);
  __Pyx_INCREF(__pyx_n_s_TransformerMixin);
  __Pyx_GIVEREF(__pyx_n_s_TransformerMixin);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_TransformerMixin);
  __Pyx_INCREF(__pyx_n_s_ClassifierMixin);
  __Pyx_GIVEREF(__pyx_n_s_ClassifierMixin);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_n_s_ClassifierMixin);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_sklearn_base, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_BaseEstimator, __pyx_t_1) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TransformerMixin, __pyx_t_1) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_ClassifierMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ClassifierMixin, __pyx_t_1) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":12
 * from scipy import sparse
 * from sklearn.base import BaseEstimator, TransformerMixin, ClassifierMixin
 * from sklearn.pipeline import FeatureUnion, _fit_transform_one, _transform_one             # <<<<<<<<<<<<<<
 * from joblib import Parallel, delayed
 * from sklearn.feature_extraction.text import CountVectorizer # experimental
 */
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_FeatureUnion);
  __Pyx_GIVEREF(__pyx_n_s_FeatureUnion);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_FeatureUnion);
  __Pyx_INCREF(__pyx_n_s_fit_transform_one);
  __Pyx_GIVEREF(__pyx_n_s_fit_transform_one);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_n_s_fit_transform_one);
  __Pyx_INCREF(__pyx_n_s_transform_one);
  __Pyx_GIVEREF(__pyx_n_s_transform_one);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_n_s_transform_one);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_pipeline, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_FeatureUnion, __pyx_t_2) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_fit_transform_one); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_fit_transform_one, __pyx_t_2) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_transform_one); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_transform_one, __pyx_t_2) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":13
 * from sklearn.base import BaseEstimator, TransformerMixin, ClassifierMixin
 * from sklearn.pipeline import FeatureUnion, _fit_transform_one, _transform_one
 * from joblib import Parallel, delayed             # <<<<<<<<<<<<<<
 * from sklearn.feature_extraction.text import CountVectorizer # experimental
 *
 */
  __pyx_t_1 = PyList_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Parallel);
  __Pyx_GIVEREF(__pyx_n_s_Parallel);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Parallel);
  __Pyx_INCREF(__pyx_n_s_delayed);
  __Pyx_GIVEREF(__pyx_n_s_delayed);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_s_delayed);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_joblib, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Parallel); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Parallel, __pyx_t_1) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_delayed); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_delayed, __pyx_t_1) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":14
 * from sklearn.pipeline import FeatureUnion, _fit_transform_one, _transform_one
 * from joblib import Parallel, delayed
 * from sklearn.feature_extraction.text import CountVectorizer # experimental             # <<<<<<<<<<<<<<
 *
 * #import build.src.fetch
 */
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_CountVectorizer);
  __Pyx_GIVEREF(__pyx_n_s_CountVectorizer);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_CountVectorizer);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sklearn_feature_extraction_text, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_CountVectorizer); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CountVectorizer, __pyx_t_2) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":20
 *
 * #logger = logging.getLogger()
 * pd.options.mode.chained_assignment = None             # <<<<<<<<<<<<<<
 * stopwords_ = set(stopwords.words('english'))
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_pd); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_options); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_mode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__Pyx_PyObject_SetAttrStr(__pyx_t_1, __pyx_n_s_chained_assignment, Py_None) < 0) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":21
 * #logger = logging.getLogger()
 * pd.options.mode.chained_assignment = None
 * stopwords_ = set(stopwords.words('english'))             # <<<<<<<<<<<<<<
 *
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_stopwords_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_words); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__8, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PySet_New(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_stopwords, __pyx_t_2) < 0) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":27
 *
 * # This is really a ColumnSectector.
 * class TextSelector(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select a single text column from the data frame on which to perform transformations. """
 *     def __init__(self, col='raw'):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_TextSelector, __pyx_n_s_TextSelector, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Select_a_single_text_column_fro); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":29
 * class TextSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single text column from the data frame on which to perform transformations. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_12TextSelector_1__init__, 0, __pyx_n_s_TextSelector___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__10)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__11);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":32
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_12TextSelector_3fit, 0, __pyx_n_s_TextSelector_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__13)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__14);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":35
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.key]
 *         #return X[self]
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_12TextSelector_5transform, 0, __pyx_n_s_TextSelector_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__16)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 35, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":27
 *
 * # This is really a ColumnSectector.
 * class TextSelector(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select a single text column from the data frame on which to perform transformations. """
 *     def __init__(self, col='raw'):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_TextSelector, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TextSelector, __pyx_t_4) < 0) __PYX_ERR(0, 27, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":40
 *
 *
 * class TextSelectorMulti(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select multiple text columns from the data frame on which to perform transformations. """
 *     def __init__(self, keys: list):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_2, __pyx_n_s_TextSelectorMulti, __pyx_n_s_TextSelectorMulti, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Select_multiple_text_columns_fr); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "trans.py":42
 * class TextSelectorMulti(BaseEstimator, TransformerMixin):
 *     """ Select multiple text columns from the data frame on which to perform transformations. """
 *     def __init__(self, keys: list):             # <<<<<<<<<<<<<<
 *         self.keys = keys
 *
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_keys, __pyx_n_u_list) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_17TextSelectorMulti_1__init__, 0, __pyx_n_s_TextSelectorMulti___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__18)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_5, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_init, __pyx_t_5) < 0) __PYX_ERR(0, 42, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":45
 *         self.keys = keys
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_17TextSelectorMulti_3fit, 0, __pyx_n_s_TextSelectorMulti_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__20)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_5, __pyx_tuple__21);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_fit, __pyx_t_5) < 0) __PYX_ERR(0, 45, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":48
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.keys]
 *
 */
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_17TextSelectorMulti_5transform, 0, __pyx_n_s_TextSelectorMulti_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__23)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_transform, __pyx_t_5) < 0) __PYX_ERR(0, 48, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":40
 *
 *
 * class TextSelectorMulti(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select multiple text columns from the data frame on which to perform transformations. """
 *     def __init__(self, keys: list):
 */
  __pyx_t_5 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_TextSelectorMulti, __pyx_t_2, __pyx_t_3, NULL, 0, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TextSelectorMulti, __pyx_t_5) < 0) __PYX_ERR(0, 40, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":53
 *
 * # This is completely redundant. Remove or I will remove it for you.
 * class NumberSelector(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select a single numeric column from the data frame on which to perform transformations. """
 *     def __init__(self, col=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_NumberSelector, __pyx_n_s_NumberSelector, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Select_a_single_numeric_column); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":55
 * class NumberSelector(BaseEstimator, TransformerMixin):
 *     """ Select a single numeric column from the data frame on which to perform transformations. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14NumberSelector_1__init__, 0, __pyx_n_s_NumberSelector___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__25)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_5, __pyx_tuple__26);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_5) < 0) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":58
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14NumberSelector_3fit, 0, __pyx_n_s_NumberSelector_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__28)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_5, __pyx_tuple__29);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_5) < 0) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":61
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[[self.key]]
 *
 */
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14NumberSelector_5transform, 0, __pyx_n_s_NumberSelector_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__31)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_5) < 0) __PYX_ERR(0, 61, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":53
 *
 * # This is completely redundant. Remove or I will remove it for you.
 * class NumberSelector(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select a single numeric column from the data frame on which to perform transformations. """
 *     def __init__(self, col=None):
 */
  __pyx_t_5 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_NumberSelector, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_NumberSelector, __pyx_t_5) < 0) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":65
 *
 *
 * class FeatureSelector(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select only the features passed via set_params. """
 *     def __init__(self, feats: list=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_2, __pyx_n_s_FeatureSelector, __pyx_n_s_FeatureSelector, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Select_only_the_features_passed); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "trans.py":67
 * class FeatureSelector(BaseEstimator, TransformerMixin):
 *     """ Select only the features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_feats, __pyx_n_u_list) < 0) __PYX_ERR(0, 67, __pyx_L1_error)
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_15FeatureSelector_1__init__, 0, __pyx_n_s_FeatureSelector___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__33)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__34);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_5);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 67, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":70
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_15FeatureSelector_3fit, 0, __pyx_n_s_FeatureSelector_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__36)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__37);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":73
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[self.feats]
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_15FeatureSelector_5transform, 0, __pyx_n_s_FeatureSelector_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__39)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 73, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 73, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":65
 *
 *
 * class FeatureSelector(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Select only the features passed via set_params. """
 *     def __init__(self, feats: list=None):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_FeatureSelector, __pyx_t_2, __pyx_t_3, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_FeatureSelector, __pyx_t_4) < 0) __PYX_ERR(0, 65, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":77
 *
 *
 * class DropFeatures(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Drop any features passed via set_params. """
 *     def __init__(self, feats: list=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_DropFeatures, __pyx_n_s_DropFeatures, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Drop_any_features_passed_via_se); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":79
 * class DropFeatures(BaseEstimator, TransformerMixin):
 *     """ Drop any features passed via set_params. """
 *     def __init__(self, feats: list=None):             # <<<<<<<<<<<<<<
 *         self.feats = feats
 *
 */
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_feats, __pyx_n_u_list) < 0) __PYX_ERR(0, 79, __pyx_L1_error)
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_12DropFeatures_1__init__, 0, __pyx_n_s_DropFeatures___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__41)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_5, __pyx_tuple__42);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_5, __pyx_t_4);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_5) < 0) __PYX_ERR(0, 79, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":82
 *         self.feats = feats
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_12DropFeatures_3fit, 0, __pyx_n_s_DropFeatures_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__44)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_5, __pyx_tuple__45);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_5) < 0) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":85
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X.drop(self.feats, axis=1)
 *
 */
  __pyx_t_5 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_12DropFeatures_5transform, 0, __pyx_n_s_DropFeatures_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__47)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_5) < 0) __PYX_ERR(0, 85, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  /* "trans.py":77
 *
 *
 * class DropFeatures(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Drop any features passed via set_params. """
 *     def __init__(self, feats: list=None):
 */
  __pyx_t_5 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_DropFeatures, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_DropFeatures, __pyx_t_5) < 0) __PYX_ERR(0, 77, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":89
 *
 *
 * class ConvertTargets(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Convert target categories to int. """
 *     def __init__(self, targets: list=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_2, __pyx_n_s_ConvertTargets, __pyx_n_s_ConvertTargets, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Convert_target_categories_to_in); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "trans.py":91
 * class ConvertTargets(BaseEstimator, TransformerMixin):
 *     """ Convert target categories to int. """
 *     def __init__(self, targets: list=None):             # <<<<<<<<<<<<<<
 *         self.targets = targets
 *
 */
  __pyx_t_5 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 91, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  if (PyDict_SetItem(__pyx_t_5, __pyx_n_s_targets, __pyx_n_u_list) < 0) __PYX_ERR(0, 91, __pyx_L1_error)
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14ConvertTargets_1__init__, 0, __pyx_n_s_ConvertTargets___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__49)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 91, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__50);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_4, __pyx_t_5);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 91, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":94
 *         self.targets = targets
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14ConvertTargets_3fit, 0, __pyx_n_s_ConvertTargets_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__52)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__53);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":97
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return # @TODO
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14ConvertTargets_5transform, 0, __pyx_n_s_ConvertTargets_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__55)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 97, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":89
 *
 *
 * class ConvertTargets(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Convert target categories to int. """
 *     def __init__(self, targets: list=None):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_ConvertTargets, __pyx_t_2, __pyx_t_3, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ConvertTargets, __pyx_t_4) < 0) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":103
 * # Preprocessors
 *
 * class MissingData(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Examines dataset for missing values, smh. """
 *     def __init__(self, col='raw'):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_MissingData, __pyx_n_s_MissingData, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Examines_dataset_for_missing_va); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":105
 * class MissingData(BaseEstimator, TransformerMixin):
 *     """ Examines dataset for missing values, smh. """
 *     def __init__(self, col='raw'):             # <<<<<<<<<<<<<<
 *         self.key = col
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11MissingData_1__init__, 0, __pyx_n_s_MissingData___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__57)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__58);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":108
 *         self.key = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11MissingData_3fit, 0, __pyx_n_s_MissingData_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__60)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__61);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":111
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         missing = ['', None]
 *         for y in X.columns:
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11MissingData_5transform, 0, __pyx_n_s_MissingData_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__63)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 111, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 111, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":103
 * # Preprocessors
 *
 * class MissingData(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Examines dataset for missing values, smh. """
 *     def __init__(self, col='raw'):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_MissingData, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MissingData, __pyx_t_4) < 0) __PYX_ERR(0, 103, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":119
 * # Numeric text measurements.
 *
 * class SentenceLength(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_2, __pyx_n_s_SentenceLength, __pyx_n_s_SentenceLength, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Count_commas_in_a_text_series); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "trans.py":121
 * class SentenceLength(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14SentenceLength_1__init__, 0, __pyx_n_s_SentenceLength___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__65)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__66);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 121, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":125
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14SentenceLength_3fit, 0, __pyx_n_s_SentenceLength_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__68)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__69);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 125, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":128
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['sen_len'] = X[self.col].apply(lambda x: len(x))
 *         return X
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14SentenceLength_5transform, 0, __pyx_n_s_SentenceLength_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__71)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 128, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 128, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":119
 * # Numeric text measurements.
 *
 * class SentenceLength(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_SentenceLength, __pyx_t_2, __pyx_t_3, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_SentenceLength, __pyx_t_4) < 0) __PYX_ERR(0, 119, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":133
 *
 *
 * class CountCommas(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_CountCommas, __pyx_n_s_CountCommas, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Count_commas_in_a_text_series); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":135
 * class CountCommas(BaseEstimator, TransformerMixin):
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         pass
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11CountCommas_1__init__, 0, __pyx_n_s_CountCommas___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__73)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 135, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__74);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 135, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":139
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11CountCommas_3fit, 0, __pyx_n_s_CountCommas_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__76)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__77);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":142
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_commas'] = X[self.col].apply(lambda x: x.count(','))
 *         return X
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_11CountCommas_5transform, 0, __pyx_n_s_CountCommas_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__79)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 142, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":133
 *
 *
 * class CountCommas(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Count commas in a text series. """
 *     def __init__(self, col=None):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_CountCommas, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CountCommas, __pyx_t_4) < 0) __PYX_ERR(0, 133, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":147
 *
 *
 * class CountWords(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Count words in a text series. """
 *     def __init__(self, col=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_2, __pyx_n_s_CountWords, __pyx_n_s_CountWords, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Count_words_in_a_text_series); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "trans.py":149
 * class CountWords(BaseEstimator, TransformerMixin):
 *     """ Count words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_10CountWords_1__init__, 0, __pyx_n_s_CountWords___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__81)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__82);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 149, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":152
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_10CountWords_3fit, 0, __pyx_n_s_CountWords_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__84)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__85);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":155
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['count_words'] = X[self.col].apply(lambda x: len(x.split(' ')))
 *         #X = X.apply(lambda x: len(x.split(' ')))
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_10CountWords_5transform, 0, __pyx_n_s_CountWords_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__87)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 155, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 155, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":147
 *
 *
 * class CountWords(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Count words in a text series. """
 *     def __init__(self, col=None):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_CountWords, __pyx_t_2, __pyx_t_3, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CountWords, __pyx_t_4) < 0) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":161
 *
 *
 * class AvgWordLenTransformer(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     """ Transformer to calculate average word length. """
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_AvgWordLenTransformer, __pyx_n_s_AvgWordLenTransformer, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Transformer_to_calculate_averag); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":164
 *     """ Transformer to calculate average word length. """
 *
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_21AvgWordLenTransformer_1__init__, 0, __pyx_n_s_AvgWordLenTransformer___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__89)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__90);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":167
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_21AvgWordLenTransformer_3fit, 0, __pyx_n_s_AvgWordLenTransformer_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__92)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 167, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__93);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 167, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":170
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['avg_word_len'] = X[self.col].apply(lambda x: np.mean([len(t) for t in x.split(' ') if t not in stopwords_]) if len([len(t) for t in x.split(' ') if t not in stopwords_]) > 0 else 0)
 *         return X
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_21AvgWordLenTransformer_5transform, 0, __pyx_n_s_AvgWordLenTransformer_transform_2, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__95)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 170, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 170, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":161
 *
 *
 * class AvgWordLenTransformer(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     """ Transformer to calculate average word length. """
 *
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_AvgWordLenTransformer, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_AvgWordLenTransformer, __pyx_t_4) < 0) __PYX_ERR(0, 161, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":175
 *
 *
 * class NotStopsTransformer(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Non-stop words in a text series. """
 *     def __init__(self, col=None):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_2, __pyx_n_s_NotStopsTransformer, __pyx_n_s_NotStopsTransformer, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Non_stop_words_in_a_text_series); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "trans.py":177
 * class NotStopsTransformer(BaseEstimator, TransformerMixin):
 *     """ Non-stop words in a text series. """
 *     def __init__(self, col=None):             # <<<<<<<<<<<<<<
 *         self.col = col
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19NotStopsTransformer_1__init__, 0, __pyx_n_s_NotStopsTransformer___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__97)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__98);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 177, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":180
 *         self.col = col
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19NotStopsTransformer_3fit, 0, __pyx_n_s_NotStopsTransformer_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__100)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__101);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 180, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":183
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['not_stops'] = X[self.col].apply(lambda x: len([t for t in x.split(' ') if t not in stopwords_]))
 *         return X
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19NotStopsTransformer_5transform, 0, __pyx_n_s_NotStopsTransformer_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__103)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 183, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":175
 *
 *
 * class NotStopsTransformer(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Non-stop words in a text series. """
 *     def __init__(self, col=None):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_NotStopsTransformer, __pyx_t_2, __pyx_t_3, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_NotStopsTransformer, __pyx_t_4) < 0) __PYX_ERR(0, 175, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":188
 *
 *
 * class CommaLenRatio(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Hard-coded experimental feature. N.B. This is an entropy source. """
 *     def __init__(self, col=None): # text col is ignored in non-measured feature.
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_CommaLenRatio, __pyx_n_s_CommaLenRatio, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Hard_coded_experimental_feature); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":190
 * class CommaLenRatio(BaseEstimator, TransformerMixin):
 *     """ Hard-coded experimental feature. N.B. This is an entropy source. """
 *     def __init__(self, col=None): # text col is ignored in non-measured feature.             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13CommaLenRatio_1__init__, 0, __pyx_n_s_CommaLenRatio___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__105)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 190, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__106);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 190, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":193
 *         pass
 *
 *     def divide(self, x, y):             # <<<<<<<<<<<<<<
 *         if y != 0:
 *             return x//y
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13CommaLenRatio_3divide, 0, __pyx_n_s_CommaLenRatio_divide, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__108)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 193, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_divide, __pyx_t_4) < 0) __PYX_ERR(0, 193, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":199
 *             return 0
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13CommaLenRatio_5fit, 0, __pyx_n_s_CommaLenRatio_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__110)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__111);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":202
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         X['comma_len_ratio'] = X[['sen_len', 'count_commas']].apply(lambda x: self.divide(*x), axis=1)
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13CommaLenRatio_7transform, 0, __pyx_n_s_CommaLenRatio_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__113)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":188
 *
 *
 * class CommaLenRatio(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Hard-coded experimental feature. N.B. This is an entropy source. """
 *     def __init__(self, col=None): # text col is ignored in non-measured feature.
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_CommaLenRatio, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CommaLenRatio, __pyx_t_4) < 0) __PYX_ERR(0, 188, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":210
 * # Categorical transforms
 *
 * class BooleanTargets(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Converts binary classification labels to boolean values. (In place, does not add new column.) """
 *     def __init__(self, col, tar1, tar2):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_1);
  __pyx_t_3 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_2, __pyx_n_s_BooleanTargets, __pyx_n_s_BooleanTargets, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Converts_binary_classification); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  /* "trans.py":212
 * class BooleanTargets(BaseEstimator, TransformerMixin):
 *     """ Converts binary classification labels to boolean values. (In place, does not add new column.) """
 *     def __init__(self, col, tar1, tar2):             # <<<<<<<<<<<<<<
 *         self.col = col
 *         self.a = tar1
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14BooleanTargets_1__init__, 0, __pyx_n_s_BooleanTargets___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__115)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 212, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":217
 *         self.b = tar2
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14BooleanTargets_3fit, 0, __pyx_n_s_BooleanTargets_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__117)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__118);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":220
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         target = self.col
 *         X.loc[(X.target == self.a), target] = 0
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_14BooleanTargets_5transform, 0, __pyx_n_s_BooleanTargets_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__120)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 220, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_3, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 220, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":210
 * # Categorical transforms
 *
 * class BooleanTargets(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Converts binary classification labels to boolean values. (In place, does not add new column.) """
 *     def __init__(self, col, tar1, tar2):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_BooleanTargets, __pyx_t_2, __pyx_t_3, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_BooleanTargets, __pyx_t_4) < 0) __PYX_ERR(0, 210, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":229
 * ## Pandas Mixins
 *
 * class PandasTransformer(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     def __init__(self, fn):
 *         self.fn = fn
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_1, __pyx_t_3, __pyx_n_s_PandasTransformer, __pyx_n_s_PandasTransformer, (PyObject *) NULL, __pyx_n_s_trans, (PyObject *) NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":230
 *
 * class PandasTransformer(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_17PandasTransformer_1__init__, 0, __pyx_n_s_PandasTransformer___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__122)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 230, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":233
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_17PandasTransformer_3fit, 0, __pyx_n_s_PandasTransformer_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__124)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 233, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__125);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 233, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":236
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fn(X)
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_17PandasTransformer_5transform, 0, __pyx_n_s_PandasTransformer_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__127)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 236, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__128);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 236, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":229
 * ## Pandas Mixins
 *
 * class PandasTransformer(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     def __init__(self, fn):
 *         self.fn = fn
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_1, __pyx_n_s_PandasTransformer, __pyx_t_3, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_PandasTransformer, __pyx_t_4) < 0) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":240
 *
 *
 * class PandasFeatureUnion(FeatureUnion):             # <<<<<<<<<<<<<<
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_FeatureUnion); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CalculateMetaclass(NULL, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_3, __pyx_t_1, __pyx_n_s_PandasFeatureUnion, __pyx_n_s_PandasFeatureUnion, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_TODO_cleanup_non_overridden_met); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":242
 * class PandasFeatureUnion(FeatureUnion):
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         self._validate_transformers()
 *         result = Parallel(n_jobs=self.n_jobs)(
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_18PandasFeatureUnion_1fit_transform, 0, __pyx_n_s_PandasFeatureUnion_fit_transform_2, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__130)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__131);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit_transform, __pyx_t_4) < 0) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":264
 *         return Xs
 *
 *     def merge_dataframes_by_column(self, Xs):             # <<<<<<<<<<<<<<
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_18PandasFeatureUnion_3merge_dataframes_by_column, 0, __pyx_n_s_PandasFeatureUnion_merge_datafra, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__133)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 264, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_merge_dataframes_by_column, __pyx_t_4) < 0) __PYX_ERR(0, 264, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":267
 *         return pd.concat(Xs, axis="columns", copy=False)
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         Xs = Parallel(n_jobs=self.n_jobs)(
 *             delayed(_transform_one)(
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_18PandasFeatureUnion_5transform, 0, __pyx_n_s_PandasFeatureUnion_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__135)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 267, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":240
 *
 *
 * class PandasFeatureUnion(FeatureUnion):             # <<<<<<<<<<<<<<
 *     """ @TODO: cleanup non-overridden methods with .super() """
 *     def fit_transform(self, X, y=None, **fit_params):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_3, __pyx_n_s_PandasFeatureUnion, __pyx_t_1, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_PandasFeatureUnion, __pyx_t_4) < 0) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":284
 *         return Xs
 *
 * class ConvertListToSeries(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     """ Convert a list to series. t/k """
 *     pass
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_3);
  __pyx_t_1 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_3, __pyx_t_2, __pyx_n_s_ConvertListToSeries, __pyx_n_s_ConvertListToSeries, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Convert_a_list_to_series_t_k); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_3, __pyx_n_s_ConvertListToSeries, __pyx_t_2, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ConvertListToSeries, __pyx_t_4) < 0) __PYX_ERR(0, 284, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":292
 *
 * # N.B. Dense Transform will greatly increase memory requirements.
 * class DenseTransformer(TransformerMixin):             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None, **fit_params):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_CalculateMetaclass(NULL, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_2, __pyx_t_3, __pyx_n_s_DenseTransformer, __pyx_n_s_DenseTransformer, (PyObject *) NULL, __pyx_n_s_trans, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "trans.py":294
 * class DenseTransformer(TransformerMixin):
 *
 *     def fit(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_16DenseTransformer_1fit, 0, __pyx_n_s_DenseTransformer_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__137)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__138);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 294, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":297
 *         return self
 *
 *     def transform(self, X, y=None, **fit_params):             # <<<<<<<<<<<<<<
 *         return X.todense()
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_16DenseTransformer_3transform, 0, __pyx_n_s_DenseTransformer_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__140)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 297, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__141);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 297, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":292
 *
 * # N.B. Dense Transform will greatly increase memory requirements.
 * class DenseTransformer(TransformerMixin):             # <<<<<<<<<<<<<<
 *
 *     def fit(self, X, y=None, **fit_params):
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_2, __pyx_n_s_DenseTransformer, __pyx_t_3, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_DenseTransformer, __pyx_t_4) < 0) __PYX_ERR(0, 292, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "trans.py":301
 *
 *
 * class WordVectorTransform(CountVectorizer):             # <<<<<<<<<<<<<<
 *     """ Wrapper for vector functions to handle DataFrames. """
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_CountVectorizer); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_3, __pyx_t_2, __pyx_n_s_WordVectorTransform, __pyx_n_s_WordVectorTransform, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Wrapper_for_vector_functions_to); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "trans.py":304
 *     """ Wrapper for vector functions to handle DataFrames. """
 *
 *     def __init__(self, *args, **kwargs):             # <<<<<<<<<<<<<<
 *         super(WordVectorTransform, self).__init__(*args, **kwargs)
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19WordVectorTransform_1__init__, 0, __pyx_n_s_WordVectorTransform___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__143)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 304, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":301
 *
 *
 * class WordVectorTransform(CountVectorizer):             # <<<<<<<<<<<<<<
 *     """ Wrapper for vector functions to handle DataFrames. """
 *
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_3, __pyx_n_s_WordVectorTransform, __pyx_t_2, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_WordVectorTransform, __pyx_t_4) < 0) __PYX_ERR(0, 301, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":309
 *
 * # ANN = "Arbitrary Neural Net"
 * class NNTransformer(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Neural Network tranformation pipe """
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_2 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CalculateMetaclass(NULL, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_3, __pyx_t_1, __pyx_n_s_NNTransformer, __pyx_n_s_NNTransformer, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_Neural_Network_tranformation_pi); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":312
 *     """ Neural Network tranformation pipe """
 *
 *     def __init__(self, ann):             # <<<<<<<<<<<<<<
 *         self.ann = ann
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13NNTransformer_1__init__, 0, __pyx_n_s_NNTransformer___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__145)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 312, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 312, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":315
 *         self.ann = ann
 *
 *     def fit(self, X, y):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13NNTransformer_3fit, 0, __pyx_n_s_NNTransformer_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__147)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 315, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 315, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":318
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return self.ann.predict(X)
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13NNTransformer_5transform, 0, __pyx_n_s_NNTransformer_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__149)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 318, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 318, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":309
 *
 * # ANN = "Arbitrary Neural Net"
 * class NNTransformer(BaseEstimator, TransformerMixin):             # <<<<<<<<<<<<<<
 *     """ Neural Network tranformation pipe """
 *
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_3, __pyx_n_s_NNTransformer, __pyx_t_1, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_NNTransformer, __pyx_t_4) < 0) __PYX_ERR(0, 309, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":325
 *
 * # If you need a sanity check, and don't have a d20 handy.
 * class TestTransform(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     def __init__(self, fn):
 *         self.fn = fn
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 325, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 325, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 325, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_3);
  __pyx_t_1 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 325, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_3, __pyx_t_2, __pyx_n_s_TestTransform, __pyx_n_s_TestTransform, (PyObject *) NULL, __pyx_n_s_trans, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 325, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "trans.py":326
 * # If you need a sanity check, and don't have a d20 handy.
 * class TestTransform(TransformerMixin, BaseEstimator):
 *     def __init__(self, fn):             # <<<<<<<<<<<<<<
 *         self.fn = fn
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13TestTransform_1__init__, 0, __pyx_n_s_TestTransform___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__151)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 326, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 326, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":329
 *         self.fn = fn
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13TestTransform_3fit, 0, __pyx_n_s_TestTransform_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__153)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__154);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 329, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":332
 *         return self
 *
 *     def transform(self, X, y=None, copy=None):             # <<<<<<<<<<<<<<
 *         return self.fun(X)
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13TestTransform_5transform, 0, __pyx_n_s_TestTransform_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__156)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 332, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__157);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 332, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":335
 *         return self.fun(X)
 *
 *     def fun(self, X):             # <<<<<<<<<<<<<<
 *         #X = X + 11
 *         X = (X - np.mean(X)) / (np.max(X) - np.min(X))
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_13TestTransform_7fun, 0, __pyx_n_s_TestTransform_fun, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__159)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 335, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_fun, __pyx_t_4) < 0) __PYX_ERR(0, 335, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":325
 *
 * # If you need a sanity check, and don't have a d20 handy.
 * class TestTransform(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     def __init__(self, fn):
 *         self.fn = fn
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_3, __pyx_n_s_TestTransform, __pyx_t_2, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 325, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TestTransform, __pyx_t_4) < 0) __PYX_ERR(0, 325, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":341
 *
 *
 * class TransformerTemplate(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     """A template for a custom transformer. (TransformerMixin is for .fit_transform method.) """
 *
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_2 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CalculateMetaclass(NULL, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare(__pyx_t_3, __pyx_t_1, __pyx_n_s_TransformerTemplate, __pyx_n_s_TransformerTemplate, (PyObject *) NULL, __pyx_n_s_trans, __pyx_kp_s_A_template_for_a_custom_transfor); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  /* "trans.py":344
 *     """A template for a custom transformer. (TransformerMixin is for .fit_transform method.) """
 *
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19TransformerTemplate_1__init__, 0, __pyx_n_s_TransformerTemplate___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__161)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 344, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 344, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":347
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19TransformerTemplate_3fit, 0, __pyx_n_s_TransformerTemplate_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__163)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 347, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__164);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 347, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":350
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         # transform X via code or additional methods
 *         return X
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_19TransformerTemplate_5transform, 0, __pyx_n_s_TransformerTemplate_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__166)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 350, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 350, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":341
 *
 *
 * class TransformerTemplate(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     """A template for a custom transformer. (TransformerMixin is for .fit_transform method.) """
 *
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_3, __pyx_n_s_TransformerTemplate, __pyx_t_1, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_TransformerTemplate, __pyx_t_4) < 0) __PYX_ERR(0, 341, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "trans.py":355
 *
 *
 * class Wat(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     def __init__(self):
 *         pass
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_TransformerMixin); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 355, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_BaseEstimator); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 355, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 355, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_t_3);
  __pyx_t_1 = 0;
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_CalculateMetaclass(NULL, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 355, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare(__pyx_t_3, __pyx_t_2, __pyx_n_s_Wat, __pyx_n_s_Wat, (PyObject *) NULL, __pyx_n_s_trans, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 355, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  /* "trans.py":356
 *
 * class Wat(TransformerMixin, BaseEstimator):
 *     def __init__(self):             # <<<<<<<<<<<<<<
 *         pass
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_3Wat_1__init__, 0, __pyx_n_s_Wat___init, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__168)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 356, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_init, __pyx_t_4) < 0) __PYX_ERR(0, 356, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":359
 *         pass
 *
 *     def fit(self, X, y=None):             # <<<<<<<<<<<<<<
 *         return self
 *
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_3Wat_3fit, 0, __pyx_n_s_Wat_fit, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__170)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 359, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_CyFunction_SetDefaultsTuple(__pyx_t_4, __pyx_tuple__171);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_fit, __pyx_t_4) < 0) __PYX_ERR(0, 359, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":362
 *         return self
 *
 *     def transform(self, X):             # <<<<<<<<<<<<<<
 *         return X[:, 1:]
 */
  __pyx_t_4 = __Pyx_CyFunction_New(&__pyx_mdef_5trans_3Wat_5transform, 0, __pyx_n_s_Wat_transform, NULL, __pyx_n_s_trans, __pyx_d, ((PyObject *)__pyx_codeobj__173)); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_transform, __pyx_t_4) < 0) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "trans.py":355
 *
 *
 * class Wat(TransformerMixin, BaseEstimator):             # <<<<<<<<<<<<<<
 *     def __init__(self):
 *         pass
 */
  __pyx_t_4 = __Pyx_Py3ClassCreate(__pyx_t_3, __pyx_n_s_Wat, __pyx_t_2, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 355, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Wat, __pyx_t_4) < 0) __PYX_ERR(0, 355, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "trans.py":1
 * #!/usr/bin/env python             # <<<<<<<<<<<<<<
 * # trans.py - Transform builder class and assorted transformer defitions
 * __version__ = '0.0.1'
 */
  __pyx_t_2 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_2) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /*--- Wrapped vars code ---*/

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init trans", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init trans");
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

/* None */
static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname) {
    PyErr_Format(PyExc_NameError, "free variable '%s' referenced before assignment in enclosing scope", varname);
}

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

/* PyIntCompare */
static CYTHON_INLINE PyObject* __Pyx_PyInt_NeObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, CYTHON_UNUSED long inplace) {
    if (op1 == op2) {
        Py_RETURN_FALSE;
    }
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long a = PyInt_AS_LONG(op1);
        if (a != b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        int unequal;
        unsigned long uintval;
        Py_ssize_t size = Py_SIZE(op1);
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        if (intval == 0) {
            if (size != 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
        } else if (intval < 0) {
            if (size >= 0)
                Py_RETURN_TRUE;
            intval = -intval;
            size = -size;
        } else {
            if (size <= 0)
                Py_RETURN_TRUE;
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
        if (unequal != 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
        if ((double)a != (double)b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    return (
        PyObject_RichCompare(op1, op2, Py_NE));
}

/* RaiseTooManyValuesToUnpack */
static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected) {
    PyErr_Format(PyExc_ValueError,
                 "too many values to unpack (expected %" CYTHON_FORMAT_SSIZE_T "d)", expected);
}

/* RaiseNeedMoreValuesToUnpack */
static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
    PyErr_Format(PyExc_ValueError,
                 "need more than %" CYTHON_FORMAT_SSIZE_T "d value%.1s to unpack",
                 index, (index == 1) ? "" : "s");
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

/* MergeKeywords */
static int __Pyx_MergeKeywords(PyObject *kwdict, PyObject *source_mapping) {
    PyObject *iter, *key = NULL, *value = NULL;
    int source_is_dict, result;
    Py_ssize_t orig_length, ppos = 0;
    iter = __Pyx_dict_iterator(source_mapping, 0, __pyx_n_s_items, &orig_length, &source_is_dict);
    if (unlikely(!iter)) {
        PyObject *args;
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        args = PyTuple_Pack(1, source_mapping);
        if (likely(args)) {
            PyObject *fallback = PyObject_Call((PyObject*)&PyDict_Type, args, NULL);
            Py_DECREF(args);
            if (likely(fallback)) {
                iter = __Pyx_dict_iterator(fallback, 1, __pyx_n_s_items, &orig_length, &source_is_dict);
                Py_DECREF(fallback);
            }
        }
        if (unlikely(!iter)) goto bad;
    }
    while (1) {
        result = __Pyx_dict_iter_next(iter, orig_length, &ppos, &key, &value, NULL, source_is_dict);
        if (unlikely(result < 0)) goto bad;
        if (!result) break;
        if (unlikely(PyDict_Contains(kwdict, key))) {
            __Pyx_RaiseDoubleKeywordsError("function", key);
            result = -1;
        } else {
            result = PyDict_SetItem(kwdict, key, value);
        }
        Py_DECREF(key);
        Py_DECREF(value);
        if (unlikely(result < 0)) goto bad;
    }
    Py_XDECREF(iter);
    return 0;
bad:
    Py_XDECREF(iter);
    return -1;
}

/* PyObject_GenericGetAttrNoDict */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject *__Pyx_RaiseGenericGetAttributeError(PyTypeObject *tp, PyObject *attr_name) {
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, attr_name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(attr_name));
#endif
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name) {
    PyObject *descr;
    PyTypeObject *tp = Py_TYPE(obj);
    if (unlikely(!PyString_Check(attr_name))) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    assert(!tp->tp_dictoffset);
    descr = _PyType_Lookup(tp, attr_name);
    if (unlikely(!descr)) {
        return __Pyx_RaiseGenericGetAttributeError(tp, attr_name);
    }
    Py_INCREF(descr);
    #if PY_MAJOR_VERSION < 3
    if (likely(PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)))
    #endif
    {
        descrgetfunc f = Py_TYPE(descr)->tp_descr_get;
        if (unlikely(f)) {
            PyObject *res = f(descr, obj, (PyObject *)tp);
            Py_DECREF(descr);
            return res;
        }
    }
    return descr;
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

/* RaiseException */
#if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb,
                        CYTHON_UNUSED PyObject *cause) {
    __Pyx_PyThreadState_declare
    Py_XINCREF(type);
    if (!value || value == Py_None)
        value = NULL;
    else
        Py_INCREF(value);
    if (!tb || tb == Py_None)
        tb = NULL;
    else {
        Py_INCREF(tb);
        if (!PyTraceBack_Check(tb)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: arg 3 must be a traceback or None");
            goto raise_error;
        }
    }
    if (PyType_Check(type)) {
#if CYTHON_COMPILING_IN_PYPY
        if (!value) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#endif
        PyErr_NormalizeException(&type, &value, &tb);
    } else {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        value = type;
        type = (PyObject*) Py_TYPE(type);
        Py_INCREF(type);
        if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: exception class must be a subclass of BaseException");
            goto raise_error;
        }
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}
#else
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#else
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}
#endif

/* GetTopmostException */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif

/* SaveResetException */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif

/* SwapException */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif

/* PyObjectCallMethod1 */
static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}

/* CoroutineBase */
#include <structmember.h>
#include <frameobject.h>
#define __Pyx_Coroutine_Undelegate(gen) Py_CLEAR((gen)->yieldfrom)
static int __Pyx_PyGen__FetchStopIterationValue(CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject **pvalue) {
    PyObject *et, *ev, *tb;
    PyObject *value = NULL;
    __Pyx_ErrFetch(&et, &ev, &tb);
    if (!et) {
        Py_XDECREF(tb);
        Py_XDECREF(ev);
        Py_INCREF(Py_None);
        *pvalue = Py_None;
        return 0;
    }
    if (likely(et == PyExc_StopIteration)) {
        if (!ev) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#if PY_VERSION_HEX >= 0x030300A0
        else if (Py_TYPE(ev) == (PyTypeObject*)PyExc_StopIteration) {
            value = ((PyStopIterationObject *)ev)->value;
            Py_INCREF(value);
            Py_DECREF(ev);
        }
#endif
        else if (unlikely(PyTuple_Check(ev))) {
            if (PyTuple_GET_SIZE(ev) >= 1) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                value = PyTuple_GET_ITEM(ev, 0);
                Py_INCREF(value);
#else
                value = PySequence_ITEM(ev, 0);
#endif
            } else {
                Py_INCREF(Py_None);
                value = Py_None;
            }
            Py_DECREF(ev);
        }
        else if (!__Pyx_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration)) {
            value = ev;
        }
        if (likely(value)) {
            Py_XDECREF(tb);
            Py_DECREF(et);
            *pvalue = value;
            return 0;
        }
    } else if (!__Pyx_PyErr_GivenExceptionMatches(et, PyExc_StopIteration)) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    PyErr_NormalizeException(&et, &ev, &tb);
    if (unlikely(!PyObject_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration))) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    Py_XDECREF(tb);
    Py_DECREF(et);
#if PY_VERSION_HEX >= 0x030300A0
    value = ((PyStopIterationObject *)ev)->value;
    Py_INCREF(value);
    Py_DECREF(ev);
#else
    {
        PyObject* args = __Pyx_PyObject_GetAttrStr(ev, __pyx_n_s_args);
        Py_DECREF(ev);
        if (likely(args)) {
            value = PySequence_GetItem(args, 0);
            Py_DECREF(args);
        }
        if (unlikely(!value)) {
            __Pyx_ErrRestore(NULL, NULL, NULL);
            Py_INCREF(Py_None);
            value = Py_None;
        }
    }
#endif
    *pvalue = value;
    return 0;
}
static CYTHON_INLINE
void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *t, *v, *tb;
    t = exc_state->exc_type;
    v = exc_state->exc_value;
    tb = exc_state->exc_traceback;
    exc_state->exc_type = NULL;
    exc_state->exc_value = NULL;
    exc_state->exc_traceback = NULL;
    Py_XDECREF(t);
    Py_XDECREF(v);
    Py_XDECREF(tb);
}
#define __Pyx_Coroutine_AlreadyRunningError(gen)  (__Pyx__Coroutine_AlreadyRunningError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyRunningError(CYTHON_UNUSED __pyx_CoroutineObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check((PyObject*)gen)) {
        msg = "coroutine already executing";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact((PyObject*)gen)) {
        msg = "async generator already executing";
    #endif
    } else {
        msg = "generator already executing";
    }
    PyErr_SetString(PyExc_ValueError, msg);
}
#define __Pyx_Coroutine_NotStartedError(gen)  (__Pyx__Coroutine_NotStartedError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_NotStartedError(CYTHON_UNUSED PyObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check(gen)) {
        msg = "can't send non-None value to a just-started coroutine";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact(gen)) {
        msg = "can't send non-None value to a just-started async generator";
    #endif
    } else {
        msg = "can't send non-None value to a just-started generator";
    }
    PyErr_SetString(PyExc_TypeError, msg);
}
#define __Pyx_Coroutine_AlreadyTerminatedError(gen, value, closing)  (__Pyx__Coroutine_AlreadyTerminatedError(gen, value, closing), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyTerminatedError(CYTHON_UNUSED PyObject *gen, PyObject *value, CYTHON_UNUSED int closing) {
    #ifdef __Pyx_Coroutine_USED
    if (!closing && __Pyx_Coroutine_Check(gen)) {
        PyErr_SetString(PyExc_RuntimeError, "cannot reuse already awaited coroutine");
    } else
    #endif
    if (value) {
        #ifdef __Pyx_AsyncGen_USED
        if (__Pyx_AsyncGen_CheckExact(gen))
            PyErr_SetNone(__Pyx_PyExc_StopAsyncIteration);
        else
        #endif
        PyErr_SetNone(PyExc_StopIteration);
    }
}
static
PyObject *__Pyx_Coroutine_SendEx(__pyx_CoroutineObject *self, PyObject *value, int closing) {
    __Pyx_PyThreadState_declare
    PyThreadState *tstate;
    __Pyx_ExcInfoStruct *exc_state;
    PyObject *retval;
    assert(!self->is_running);
    if (unlikely(self->resume_label == 0)) {
        if (unlikely(value && value != Py_None)) {
            return __Pyx_Coroutine_NotStartedError((PyObject*)self);
        }
    }
    if (unlikely(self->resume_label == -1)) {
        return __Pyx_Coroutine_AlreadyTerminatedError((PyObject*)self, value, closing);
    }
#if CYTHON_FAST_THREAD_STATE
    __Pyx_PyThreadState_assign
    tstate = __pyx_tstate;
#else
    tstate = __Pyx_PyThreadState_Current;
#endif
    exc_state = &self->gi_exc_state;
    if (exc_state->exc_type) {
        #if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
        #else
        if (exc_state->exc_traceback) {
            PyTracebackObject *tb = (PyTracebackObject *) exc_state->exc_traceback;
            PyFrameObject *f = tb->tb_frame;
            Py_XINCREF(tstate->frame);
            assert(f->f_back == NULL);
            f->f_back = tstate->frame;
        }
        #endif
    }
#if CYTHON_USE_EXC_INFO_STACK
    exc_state->previous_item = tstate->exc_info;
    tstate->exc_info = exc_state;
#else
    if (exc_state->exc_type) {
        __Pyx_ExceptionSwap(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    } else {
        __Pyx_Coroutine_ExceptionClear(exc_state);
        __Pyx_ExceptionSave(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    }
#endif
    self->is_running = 1;
    retval = self->body((PyObject *) self, tstate, value);
    self->is_running = 0;
#if CYTHON_USE_EXC_INFO_STACK
    exc_state = &self->gi_exc_state;
    tstate->exc_info = exc_state->previous_item;
    exc_state->previous_item = NULL;
    __Pyx_Coroutine_ResetFrameBackpointer(exc_state);
#endif
    return retval;
}
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *exc_tb = exc_state->exc_traceback;
    if (likely(exc_tb)) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
#else
        PyTracebackObject *tb = (PyTracebackObject *) exc_tb;
        PyFrameObject *f = tb->tb_frame;
        Py_CLEAR(f->f_back);
#endif
    }
}
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_MethodReturn(CYTHON_UNUSED PyObject* gen, PyObject *retval) {
    if (unlikely(!retval)) {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        if (!__Pyx_PyErr_Occurred()) {
            PyObject *exc = PyExc_StopIteration;
            #ifdef __Pyx_AsyncGen_USED
            if (__Pyx_AsyncGen_CheckExact(gen))
                exc = __Pyx_PyExc_StopAsyncIteration;
            #endif
            __Pyx_PyErr_SetNone(exc);
        }
    }
    return retval;
}
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_FinishDelegation(__pyx_CoroutineObject *gen) {
    PyObject *ret;
    PyObject *val = NULL;
    __Pyx_Coroutine_Undelegate(gen);
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, &val);
    ret = __Pyx_Coroutine_SendEx(gen, val, 0);
    Py_XDECREF(val);
    return ret;
}
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value) {
    PyObject *retval;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_AsyncGen_USED
        if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
            ret = __Pyx_async_gen_asend_send(yf, value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = _PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03050000 && defined(PyCoro_CheckExact) && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyCoro_CheckExact(yf)) {
            ret = _PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        {
            if (value == Py_None)
                ret = Py_TYPE(yf)->tp_iternext(yf);
            else
                ret = __Pyx_PyObject_CallMethod1(yf, __pyx_n_s_send, value);
        }
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        retval = __Pyx_Coroutine_FinishDelegation(gen);
    } else {
        retval = __Pyx_Coroutine_SendEx(gen, value, 0);
    }
    return __Pyx_Coroutine_MethodReturn(self, retval);
}
static int __Pyx_Coroutine_CloseIter(__pyx_CoroutineObject *gen, PyObject *yf) {
    PyObject *retval = NULL;
    int err = 0;
    #ifdef __Pyx_Generator_USED
    if (__Pyx_Generator_CheckExact(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_Coroutine_USED
    if (__Pyx_Coroutine_Check(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    if (__Pyx_CoroutineAwait_CheckExact(yf)) {
        retval = __Pyx_CoroutineAwait_Close((__pyx_CoroutineAwaitObject*)yf, NULL);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_AsyncGen_USED
    if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
        retval = __Pyx_async_gen_asend_close(yf, NULL);
    } else
    if (__pyx_PyAsyncGenAThrow_CheckExact(yf)) {
        retval = __Pyx_async_gen_athrow_close(yf, NULL);
    } else
    #endif
    {
        PyObject *meth;
        gen->is_running = 1;
        meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_close);
        if (unlikely(!meth)) {
            if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                PyErr_WriteUnraisable(yf);
            }
            PyErr_Clear();
        } else {
            retval = PyObject_CallFunction(meth, NULL);
            Py_DECREF(meth);
            if (!retval)
                err = -1;
        }
        gen->is_running = 0;
    }
    Py_XDECREF(retval);
    return err;
}
static PyObject *__Pyx_Generator_Next(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Generator_Next(yf);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = _PyGen_Send((PyGenObject*)yf, NULL);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, Py_None);
        } else
        #endif
            ret = Py_TYPE(yf)->tp_iternext(yf);
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        return __Pyx_Coroutine_FinishDelegation(gen);
    }
    return __Pyx_Coroutine_SendEx(gen, Py_None, 0);
}
static PyObject *__Pyx_Coroutine_Close_Method(PyObject *self, CYTHON_UNUSED PyObject *arg) {
    return __Pyx_Coroutine_Close(self);
}
static PyObject *__Pyx_Coroutine_Close(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *retval, *raised_exception;
    PyObject *yf = gen->yieldfrom;
    int err = 0;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        Py_INCREF(yf);
        err = __Pyx_Coroutine_CloseIter(gen, yf);
        __Pyx_Coroutine_Undelegate(gen);
        Py_DECREF(yf);
    }
    if (err == 0)
        PyErr_SetNone(PyExc_GeneratorExit);
    retval = __Pyx_Coroutine_SendEx(gen, NULL, 1);
    if (unlikely(retval)) {
        const char *msg;
        Py_DECREF(retval);
        if ((0)) {
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_Coroutine_Check(self)) {
            msg = "coroutine ignored GeneratorExit";
        #endif
        #ifdef __Pyx_AsyncGen_USED
        } else if (__Pyx_AsyncGen_CheckExact(self)) {
#if PY_VERSION_HEX < 0x03060000
            msg = "async generator ignored GeneratorExit - might require Python 3.6+ finalisation (PEP 525)";
#else
            msg = "async generator ignored GeneratorExit";
#endif
        #endif
        } else {
            msg = "generator ignored GeneratorExit";
        }
        PyErr_SetString(PyExc_RuntimeError, msg);
        return NULL;
    }
    raised_exception = PyErr_Occurred();
    if (likely(!raised_exception || __Pyx_PyErr_GivenExceptionMatches2(raised_exception, PyExc_GeneratorExit, PyExc_StopIteration))) {
        if (raised_exception) PyErr_Clear();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
}
static PyObject *__Pyx__Coroutine_Throw(PyObject *self, PyObject *typ, PyObject *val, PyObject *tb,
                                        PyObject *args, int close_on_genexit) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        Py_INCREF(yf);
        if (__Pyx_PyErr_GivenExceptionMatches(typ, PyExc_GeneratorExit) && close_on_genexit) {
            int err = __Pyx_Coroutine_CloseIter(gen, yf);
            Py_DECREF(yf);
            __Pyx_Coroutine_Undelegate(gen);
            if (err < 0)
                return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
            goto throw_here;
        }
        gen->is_running = 1;
        if (0
        #ifdef __Pyx_Generator_USED
            || __Pyx_Generator_CheckExact(yf)
        #endif
        #ifdef __Pyx_Coroutine_USED
            || __Pyx_Coroutine_Check(yf)
        #endif
            ) {
            ret = __Pyx__Coroutine_Throw(yf, typ, val, tb, args, close_on_genexit);
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_CoroutineAwait_CheckExact(yf)) {
            ret = __Pyx__Coroutine_Throw(((__pyx_CoroutineAwaitObject*)yf)->coroutine, typ, val, tb, args, close_on_genexit);
        #endif
        } else {
            PyObject *meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_throw);
            if (unlikely(!meth)) {
                Py_DECREF(yf);
                if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                    gen->is_running = 0;
                    return NULL;
                }
                PyErr_Clear();
                __Pyx_Coroutine_Undelegate(gen);
                gen->is_running = 0;
                goto throw_here;
            }
            if (likely(args)) {
                ret = PyObject_CallObject(meth, args);
            } else {
                ret = PyObject_CallFunctionObjArgs(meth, typ, val, tb, NULL);
            }
            Py_DECREF(meth);
        }
        gen->is_running = 0;
        Py_DECREF(yf);
        if (!ret) {
            ret = __Pyx_Coroutine_FinishDelegation(gen);
        }
        return __Pyx_Coroutine_MethodReturn(self, ret);
    }
throw_here:
    __Pyx_Raise(typ, val, tb, NULL);
    return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
}
static PyObject *__Pyx_Coroutine_Throw(PyObject *self, PyObject *args) {
    PyObject *typ;
    PyObject *val = NULL;
    PyObject *tb = NULL;
    if (!PyArg_UnpackTuple(args, (char *)"throw", 1, 3, &typ, &val, &tb))
        return NULL;
    return __Pyx__Coroutine_Throw(self, typ, val, tb, args, 1);
}
static CYTHON_INLINE int __Pyx_Coroutine_traverse_excstate(__Pyx_ExcInfoStruct *exc_state, visitproc visit, void *arg) {
    Py_VISIT(exc_state->exc_type);
    Py_VISIT(exc_state->exc_value);
    Py_VISIT(exc_state->exc_traceback);
    return 0;
}
static int __Pyx_Coroutine_traverse(__pyx_CoroutineObject *gen, visitproc visit, void *arg) {
    Py_VISIT(gen->closure);
    Py_VISIT(gen->classobj);
    Py_VISIT(gen->yieldfrom);
    return __Pyx_Coroutine_traverse_excstate(&gen->gi_exc_state, visit, arg);
}
static int __Pyx_Coroutine_clear(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    Py_CLEAR(gen->closure);
    Py_CLEAR(gen->classobj);
    Py_CLEAR(gen->yieldfrom);
    __Pyx_Coroutine_ExceptionClear(&gen->gi_exc_state);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        Py_CLEAR(((__pyx_PyAsyncGenObject*)gen)->ag_finalizer);
    }
#endif
    Py_CLEAR(gen->gi_code);
    Py_CLEAR(gen->gi_name);
    Py_CLEAR(gen->gi_qualname);
    Py_CLEAR(gen->gi_modulename);
    return 0;
}
static void __Pyx_Coroutine_dealloc(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject_GC_UnTrack(gen);
    if (gen->gi_weakreflist != NULL)
        PyObject_ClearWeakRefs(self);
    if (gen->resume_label >= 0) {
        PyObject_GC_Track(self);
#if PY_VERSION_HEX >= 0x030400a1 && CYTHON_USE_TP_FINALIZE
        if (PyObject_CallFinalizerFromDealloc(self))
#else
        Py_TYPE(gen)->tp_del(self);
        if (self->ob_refcnt > 0)
#endif
        {
            return;
        }
        PyObject_GC_UnTrack(self);
    }
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        /* We have to handle this case for asynchronous generators
           right here, because this code has to be between UNTRACK
           and GC_Del. */
        Py_CLEAR(((__pyx_PyAsyncGenObject*)self)->ag_finalizer);
    }
#endif
    __Pyx_Coroutine_clear(self);
    PyObject_GC_Del(gen);
}
static void __Pyx_Coroutine_del(PyObject *self) {
    PyObject *error_type, *error_value, *error_traceback;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    __Pyx_PyThreadState_declare
    if (gen->resume_label < 0) {
        return;
    }
#if !CYTHON_USE_TP_FINALIZE
    assert(self->ob_refcnt == 0);
    self->ob_refcnt = 1;
#endif
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&error_type, &error_value, &error_traceback);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        __pyx_PyAsyncGenObject *agen = (__pyx_PyAsyncGenObject*)self;
        PyObject *finalizer = agen->ag_finalizer;
        if (finalizer && !agen->ag_closed) {
            PyObject *res = __Pyx_PyObject_CallOneArg(finalizer, self);
            if (unlikely(!res)) {
                PyErr_WriteUnraisable(self);
            } else {
                Py_DECREF(res);
            }
            __Pyx_ErrRestore(error_type, error_value, error_traceback);
            return;
        }
    }
#endif
    if (unlikely(gen->resume_label == 0 && !error_value)) {
#ifdef __Pyx_Coroutine_USED
#ifdef __Pyx_Generator_USED
    if (!__Pyx_Generator_CheckExact(self))
#endif
        {
        PyObject_GC_UnTrack(self);
#if PY_MAJOR_VERSION >= 3  || defined(PyErr_WarnFormat)
        if (unlikely(PyErr_WarnFormat(PyExc_RuntimeWarning, 1, "coroutine '%.50S' was never awaited", gen->gi_qualname) < 0))
            PyErr_WriteUnraisable(self);
#else
        {PyObject *msg;
        char *cmsg;
        #if CYTHON_COMPILING_IN_PYPY
        msg = NULL;
        cmsg = (char*) "coroutine was never awaited";
        #else
        char *cname;
        PyObject *qualname;
        qualname = gen->gi_qualname;
        cname = PyString_AS_STRING(qualname);
        msg = PyString_FromFormat("coroutine '%.50s' was never awaited", cname);
        if (unlikely(!msg)) {
            PyErr_Clear();
            cmsg = (char*) "coroutine was never awaited";
        } else {
            cmsg = PyString_AS_STRING(msg);
        }
        #endif
        if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, cmsg, 1) < 0))
            PyErr_WriteUnraisable(self);
        Py_XDECREF(msg);}
#endif
        PyObject_GC_Track(self);
        }
#endif
    } else {
        PyObject *res = __Pyx_Coroutine_Close(self);
        if (unlikely(!res)) {
            if (PyErr_Occurred())
                PyErr_WriteUnraisable(self);
        } else {
            Py_DECREF(res);
        }
    }
    __Pyx_ErrRestore(error_type, error_value, error_traceback);
#if !CYTHON_USE_TP_FINALIZE
    assert(self->ob_refcnt > 0);
    if (--self->ob_refcnt == 0) {
        return;
    }
    {
        Py_ssize_t refcnt = self->ob_refcnt;
        _Py_NewReference(self);
        self->ob_refcnt = refcnt;
    }
#if CYTHON_COMPILING_IN_CPYTHON
    assert(PyType_IS_GC(self->ob_type) &&
           _Py_AS_GC(self)->gc.gc_refs != _PyGC_REFS_UNTRACKED);
    _Py_DEC_REFTOTAL;
#endif
#ifdef COUNT_ALLOCS
    --Py_TYPE(self)->tp_frees;
    --Py_TYPE(self)->tp_allocs;
#endif
#endif
}
static PyObject *
__Pyx_Coroutine_get_name(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_name;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_name(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
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
    tmp = self->gi_name;
    Py_INCREF(value);
    self->gi_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_qualname(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_qualname;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_qualname(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
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
    tmp = self->gi_qualname;
    Py_INCREF(value);
    self->gi_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
            PyTypeObject* type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    __pyx_CoroutineObject *gen = PyObject_GC_New(__pyx_CoroutineObject, type);
    if (unlikely(!gen))
        return NULL;
    return __Pyx__Coroutine_NewInit(gen, body, code, closure, name, qualname, module_name);
}
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    gen->body = body;
    gen->closure = closure;
    Py_XINCREF(closure);
    gen->is_running = 0;
    gen->resume_label = 0;
    gen->classobj = NULL;
    gen->yieldfrom = NULL;
    gen->gi_exc_state.exc_type = NULL;
    gen->gi_exc_state.exc_value = NULL;
    gen->gi_exc_state.exc_traceback = NULL;
#if CYTHON_USE_EXC_INFO_STACK
    gen->gi_exc_state.previous_item = NULL;
#endif
    gen->gi_weakreflist = NULL;
    Py_XINCREF(qualname);
    gen->gi_qualname = qualname;
    Py_XINCREF(name);
    gen->gi_name = name;
    Py_XINCREF(module_name);
    gen->gi_modulename = module_name;
    Py_XINCREF(code);
    gen->gi_code = code;
    PyObject_GC_Track(gen);
    return gen;
}

/* PatchModuleWithCoroutine */
static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    int result;
    PyObject *globals, *result_obj;
    globals = PyDict_New();  if (unlikely(!globals)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_coroutine_type",
    #ifdef __Pyx_Coroutine_USED
        (PyObject*)__pyx_CoroutineType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_generator_type",
    #ifdef __Pyx_Generator_USED
        (PyObject*)__pyx_GeneratorType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "_module", module) < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "__builtins__", __pyx_b) < 0)) goto ignore;
    result_obj = PyRun_String(py_code, Py_file_input, globals, globals);
    if (unlikely(!result_obj)) goto ignore;
    Py_DECREF(result_obj);
    Py_DECREF(globals);
    return module;
ignore:
    Py_XDECREF(globals);
    PyErr_WriteUnraisable(module);
    if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, "Cython module failed to patch module with custom type", 1) < 0)) {
        Py_DECREF(module);
        module = NULL;
    }
#else
    py_code++;
#endif
    return module;
}

/* PatchGeneratorABC */
#ifndef CYTHON_REGISTER_ABCS
#define CYTHON_REGISTER_ABCS 1
#endif
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
static PyObject* __Pyx_patch_abc_module(PyObject *module);
static PyObject* __Pyx_patch_abc_module(PyObject *module) {
    module = __Pyx_Coroutine_patch_module(
        module, ""
"if _cython_generator_type is not None:\n"
"    try: Generator = _module.Generator\n"
"    except AttributeError: pass\n"
"    else: Generator.register(_cython_generator_type)\n"
"if _cython_coroutine_type is not None:\n"
"    try: Coroutine = _module.Coroutine\n"
"    except AttributeError: pass\n"
"    else: Coroutine.register(_cython_coroutine_type)\n"
    );
    return module;
}
#endif
static int __Pyx_patch_abc(void) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    static int abc_patched = 0;
    if (CYTHON_REGISTER_ABCS && !abc_patched) {
        PyObject *module;
        module = PyImport_ImportModule((PY_MAJOR_VERSION >= 3) ? "collections.abc" : "collections");
        if (!module) {
            PyErr_WriteUnraisable(NULL);
            if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning,
                    ((PY_MAJOR_VERSION >= 3) ?
                        "Cython module failed to register with collections.abc module" :
                        "Cython module failed to register with collections module"), 1) < 0)) {
                return -1;
            }
        } else {
            module = __Pyx_patch_abc_module(module);
            abc_patched = 1;
            if (unlikely(!module))
                return -1;
            Py_DECREF(module);
        }
        module = PyImport_ImportModule("backports_abc");
        if (module) {
            module = __Pyx_patch_abc_module(module);
            Py_XDECREF(module);
        }
        if (!module) {
            PyErr_Clear();
        }
    }
#else
    if ((0)) __Pyx_Coroutine_patch_module(NULL, NULL);
#endif
    return 0;
}

/* Generator */
static PyMethodDef __pyx_Generator_methods[] = {
    {"send", (PyCFunction) __Pyx_Coroutine_Send, METH_O,
     (char*) PyDoc_STR("send(arg) -> send 'arg' into generator,\nreturn next yielded value or raise StopIteration.")},
    {"throw", (PyCFunction) __Pyx_Coroutine_Throw, METH_VARARGS,
     (char*) PyDoc_STR("throw(typ[,val[,tb]]) -> raise exception in generator,\nreturn next yielded value or raise StopIteration.")},
    {"close", (PyCFunction) __Pyx_Coroutine_Close_Method, METH_NOARGS,
     (char*) PyDoc_STR("close() -> raise GeneratorExit inside generator.")},
    {0, 0, 0, 0}
};
static PyMemberDef __pyx_Generator_memberlist[] = {
    {(char *) "gi_running", T_BOOL, offsetof(__pyx_CoroutineObject, is_running), READONLY, NULL},
    {(char*) "gi_yieldfrom", T_OBJECT, offsetof(__pyx_CoroutineObject, yieldfrom), READONLY,
     (char*) PyDoc_STR("object being iterated by 'yield from', or None")},
    {(char*) "gi_code", T_OBJECT, offsetof(__pyx_CoroutineObject, gi_code), READONLY, NULL},
    {0, 0, 0, 0, 0}
};
static PyGetSetDef __pyx_Generator_getsets[] = {
    {(char *) "__name__", (getter)__Pyx_Coroutine_get_name, (setter)__Pyx_Coroutine_set_name,
     (char*) PyDoc_STR("name of the generator"), 0},
    {(char *) "__qualname__", (getter)__Pyx_Coroutine_get_qualname, (setter)__Pyx_Coroutine_set_qualname,
     (char*) PyDoc_STR("qualified name of the generator"), 0},
    {0, 0, 0, 0, 0}
};
static PyTypeObject __pyx_GeneratorType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "generator",
    sizeof(__pyx_CoroutineObject),
    0,
    (destructor) __Pyx_Coroutine_dealloc,
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
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_HAVE_FINALIZE,
    0,
    (traverseproc) __Pyx_Coroutine_traverse,
    0,
    0,
    offsetof(__pyx_CoroutineObject, gi_weakreflist),
    0,
    (iternextfunc) __Pyx_Generator_Next,
    __pyx_Generator_methods,
    __pyx_Generator_memberlist,
    __pyx_Generator_getsets,
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
    0,
    0,
    0,
#if CYTHON_USE_TP_FINALIZE
    0,
#else
    __Pyx_Coroutine_del,
#endif
    0,
#if CYTHON_USE_TP_FINALIZE
    __Pyx_Coroutine_del,
#elif PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_Generator_init(void) {
    __pyx_GeneratorType_type.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
    __pyx_GeneratorType_type.tp_iter = PyObject_SelfIter;
    __pyx_GeneratorType = __Pyx_FetchCommonType(&__pyx_GeneratorType_type);
    if (unlikely(!__pyx_GeneratorType)) {
        return -1;
    }
    return 0;
}

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
