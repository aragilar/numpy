#include <stdio.h>

#define NPY_NO_DEPRECATED_API NPY_API_VERSION
#include <numpy/ndarraytypes.h>

#ifndef HAVE_STRTOF32
NPY_NO_EXPORT _Float32 strtof32(const char * restrict nptr, char ** restrict endptr)
{
    return (_Float32) strtof(nptr, endptr);
}
#endif

#ifndef HAVE_STRTOF64
NPY_NO_EXPORT _Float64 strtof64(const char * restrict nptr, char ** restrict endptr)
{
    return (_Float64) strtod(nptr, endptr);
}
#endif

#ifndef HAVE_STRTOF128
#include <quadmath.h>
NPY_NO_EXPORT _Float128 strtof128(const char * restrict nptr, char ** restrict endptr)
{
    return (_Float128) strtoflt128(nptr, endptr);
}
#endif
