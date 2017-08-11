#ifndef _NPY_NUMPYOS_H_
#define _NPY_NUMPYOS_H_

NPY_NO_EXPORT char*
NumPyOS_ascii_formatd(char *buffer, size_t buf_size,
                      const char *format,
                      double val, int decimal);

NPY_NO_EXPORT char*
NumPyOS_ascii_formatf(char *buffer, size_t buf_size,
                      const char *format,
                      float val, int decimal);

NPY_NO_EXPORT char*
NumPyOS_ascii_formatl(char *buffer, size_t buf_size,
                      const char *format,
                      long double val, int decimal);

NPY_NO_EXPORT char*
NumPyOS_ascii_formatf32(char *buffer, size_t buf_size,
                      const char *format,
                      _Float32 val, int decimal);

NPY_NO_EXPORT char*
NumPyOS_ascii_formatf64(char *buffer, size_t buf_size,
                      const char *format,
                      _Float64 val, int decimal);

NPY_NO_EXPORT char*
NumPyOS_ascii_formatf128(char *buffer, size_t buf_size,
                      const char *format,
                      _Float128 val, int decimal);

NPY_NO_EXPORT double
NumPyOS_ascii_strtod(const char *s, char** endptr);

NPY_NO_EXPORT long double
NumPyOS_ascii_strtold(const char *s, char** endptr);

NPY_NO_EXPORT int
NumPyOS_ascii_ftolf(FILE *fp, double *value);

NPY_NO_EXPORT int
NumPyOS_ascii_ftoLf(FILE *fp, long double *value);

NPY_NO_EXPORT int
NumPyOS_ascii_ftof32(FILE *fp, _Float32 *value);

NPY_NO_EXPORT int
NumPyOS_ascii_ftof64(FILE *fp, _Float64 *value);

NPY_NO_EXPORT int
NumPyOS_ascii_ftof128(FILE *fp, _Float128 *value);

NPY_NO_EXPORT int
NumPyOS_ascii_isspace(int c);

#endif
