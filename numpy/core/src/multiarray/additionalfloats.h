#ifndef _NPY_ADDITIONALFLOATS_H_
#define _NPY_ADDITIONALFLOATS_H_

NPY_NO_EXPORT _Float32 strtof32(const char * restrict nptr, char ** restrict endptr);
NPY_NO_EXPORT _Float64 strtof64(const char * restrict nptr, char ** restrict endptr);
NPY_NO_EXPORT _Float128 strtof128(const char * restrict nptr, char ** restrict endptr);

#endif
