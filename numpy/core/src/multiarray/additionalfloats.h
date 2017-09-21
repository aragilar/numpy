#ifndef _NPY_ADDITIONALFLOATS_H_
#define _NPY_ADDITIONALFLOATS_H_

#ifndef HAVE_STRTOF32
NPY_NO_EXPORT _Float32 strtof32(const char * restrict nptr, char ** restrict endptr);
#endif

#ifndef HAVE_STRTOF64
NPY_NO_EXPORT _Float64 strtof64(const char * restrict nptr, char ** restrict endptr);
#endif

#ifndef HAVE_STRTOF128
NPY_NO_EXPORT _Float128 strtof128(const char * restrict nptr, char ** restrict endptr);
#endif

/*#ifndef HAVE_STRFROMF32
NPY_NO_EXPORT int strfromf32(char *restrict str, size_t n, const char *restrict format, _Float32 fp);
#endif

#ifndef HAVE_STRFROMF64
NPY_NO_EXPORT int strfromf64(char *restrict str, size_t n, const char *restrict format, _Float64 fp);
#endif*/

#ifndef HAVE_STRFROMF128
NPY_NO_EXPORT int strfromf128(char *restrict str, size_t n, const char *restrict format, _Float128 fp);
#endif

#endif
