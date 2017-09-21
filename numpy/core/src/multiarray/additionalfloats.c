#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
#define __STDC_WANT_IEC_60559_BFP_EXT__
#endif

#include <stdlib.h>

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

/*#ifndef HAVE_STRFROMF32
NPY_NO_EXPORT int strfromf32(char *restrict str, size_t n, const char *restrict format, _Float32 fp)
{
    return strfromf(str, n, format, (float) fp);
}
#endif

#ifndef HAVE_STRFROMF64
NPY_NO_EXPORT int strfromf64(char *restrict str, size_t n, const char *restrict format, _Float64 fp)
{
    return strfromd(str, n, format, (double) fp);
}
#endif*/

#ifndef HAVE_STRFROMF128
#include <quadmath.h>
NPY_NO_EXPORT int strfromf128(char *restrict str, size_t n, const char *restrict format, _Float128 fp)
{
    int len = strlen(format);
    char new_format[len + 2];
    for (int i = 0; i < len - 1; i++) {
        new_format[i] = format[i];
    }
    new_format[len - 1] = 'Q';
    new_format[len] = format[len - 1];
    new_format[len + 1] = '\0';
    return quadmath_snprintf(str, n, new_format, fp);
}
#endif
