#ifndef __NPY_MATH_C99_H_
#define __NPY_MATH_C99_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#ifdef __SUNPRO_CC
#include <sunmath.h>
#endif
#ifdef HAVE_NPY_CONFIG_H
#include <npy_config.h>
#endif
#include <numpy/npy_common.h>

/* By adding static inline specifiers to npy_math function definitions when
   appropriate, compiler is given the opportunity to optimize */
#if NPY_INLINE_MATH
#define NPY_INPLACE NPY_INLINE static
#else
#define NPY_INPLACE
#endif


/*
 * NAN and INFINITY like macros (same behavior as glibc for NAN, same as C99
 * for INFINITY)
 *
 * XXX: I should test whether INFINITY and NAN are available on the platform
 */
NPY_INLINE static float __npy_inff(void)
{
    const union { npy_uint32 __i; float __f;} __bint = {0x7f800000UL};
    return __bint.__f;
}

NPY_INLINE static float __npy_nanf(void)
{
    const union { npy_uint32 __i; float __f;} __bint = {0x7fc00000UL};
    return __bint.__f;
}

NPY_INLINE static float __npy_pzerof(void)
{
    const union { npy_uint32 __i; float __f;} __bint = {0x00000000UL};
    return __bint.__f;
}

NPY_INLINE static float __npy_nzerof(void)
{
    const union { npy_uint32 __i; float __f;} __bint = {0x80000000UL};
    return __bint.__f;
}

#define NPY_INFINITYF __npy_inff()
#define NPY_NANF __npy_nanf()
#define NPY_PZEROF __npy_pzerof()
#define NPY_NZEROF __npy_nzerof()

#define NPY_INFINITY ((npy_double)NPY_INFINITYF)
#define NPY_NAN ((npy_double)NPY_NANF)
#define NPY_PZERO ((npy_double)NPY_PZEROF)
#define NPY_NZERO ((npy_double)NPY_NZEROF)

#define NPY_INFINITYL ((npy_longdouble)NPY_INFINITYF)
#define NPY_NANL ((npy_longdouble)NPY_NANF)
#define NPY_PZEROL ((npy_longdouble)NPY_PZEROF)
#define NPY_NZEROL ((npy_longdouble)NPY_NZEROF)

#define NPY_INFINITYF32 ((npy_binary32)NPY_INFINITYF)
#define NPY_NANF32 ((npy_binary32)NPY_NANF)
#define NPY_PZEROF32 ((npy_binary32)NPY_PZEROF)
#define NPY_NZEROF32 ((npy_binary32)NPY_NZEROF)

#define NPY_INFINITYF64 ((npy_binary64)NPY_INFINITYF)
#define NPY_NANF64 ((npy_binary64)NPY_NANF)
#define NPY_PZEROF64 ((npy_binary64)NPY_PZEROF)
#define NPY_NZEROF64 ((npy_binary64)NPY_NZEROF)

#define NPY_INFINITYF128 ((npy_binary128)NPY_INFINITYF)
#define NPY_NANF128 ((npy_binary128)NPY_NANF)
#define NPY_PZEROF128 ((npy_binary128)NPY_PZEROF)
#define NPY_NZEROF128 ((npy_binary128)NPY_NZEROF)

/*
 * Useful constants
 */
#define NPY_E         2.718281828459045235360287471352662498  /* e */
#define NPY_LOG2E     1.442695040888963407359924681001892137  /* log_2 e */
#define NPY_LOG10E    0.434294481903251827651128918916605082  /* log_10 e */
#define NPY_LOGE2     0.693147180559945309417232121458176568  /* log_e 2 */
#define NPY_LOGE10    2.302585092994045684017991454684364208  /* log_e 10 */
#define NPY_PI        3.141592653589793238462643383279502884  /* pi */
#define NPY_PI_2      1.570796326794896619231321691639751442  /* pi/2 */
#define NPY_PI_4      0.785398163397448309615660845819875721  /* pi/4 */
#define NPY_1_PI      0.318309886183790671537767526745028724  /* 1/pi */
#define NPY_2_PI      0.636619772367581343075535053490057448  /* 2/pi */
#define NPY_EULER     0.577215664901532860606512090082402431  /* Euler constant */
#define NPY_SQRT2     1.414213562373095048801688724209698079  /* sqrt(2) */
#define NPY_SQRT1_2   0.707106781186547524400844362104849039  /* 1/sqrt(2) */

#define NPY_Ef        2.718281828459045235360287471352662498F /* e */
#define NPY_LOG2Ef    1.442695040888963407359924681001892137F /* log_2 e */
#define NPY_LOG10Ef   0.434294481903251827651128918916605082F /* log_10 e */
#define NPY_LOGE2f    0.693147180559945309417232121458176568F /* log_e 2 */
#define NPY_LOGE10f   2.302585092994045684017991454684364208F /* log_e 10 */
#define NPY_PIf       3.141592653589793238462643383279502884F /* pi */
#define NPY_PI_2f     1.570796326794896619231321691639751442F /* pi/2 */
#define NPY_PI_4f     0.785398163397448309615660845819875721F /* pi/4 */
#define NPY_1_PIf     0.318309886183790671537767526745028724F /* 1/pi */
#define NPY_2_PIf     0.636619772367581343075535053490057448F /* 2/pi */
#define NPY_EULERf    0.577215664901532860606512090082402431F /* Euler constant */
#define NPY_SQRT2f    1.414213562373095048801688724209698079F /* sqrt(2) */
#define NPY_SQRT1_2f  0.707106781186547524400844362104849039F /* 1/sqrt(2) */

#define NPY_El        2.718281828459045235360287471352662498L /* e */
#define NPY_LOG2El    1.442695040888963407359924681001892137L /* log_2 e */
#define NPY_LOG10El   0.434294481903251827651128918916605082L /* log_10 e */
#define NPY_LOGE2l    0.693147180559945309417232121458176568L /* log_e 2 */
#define NPY_LOGE10l   2.302585092994045684017991454684364208L /* log_e 10 */
#define NPY_PIl       3.141592653589793238462643383279502884L /* pi */
#define NPY_PI_2l     1.570796326794896619231321691639751442L /* pi/2 */
#define NPY_PI_4l     0.785398163397448309615660845819875721L /* pi/4 */
#define NPY_1_PIl     0.318309886183790671537767526745028724L /* 1/pi */
#define NPY_2_PIl     0.636619772367581343075535053490057448L /* 2/pi */
#define NPY_EULERl    0.577215664901532860606512090082402431L /* Euler constant */
#define NPY_SQRT2l    1.414213562373095048801688724209698079L /* sqrt(2) */
#define NPY_SQRT1_2l  0.707106781186547524400844362104849039L /* 1/sqrt(2) */

#define NPY_Ef32        2.718281828459045235360287471352662498f32 /* e */
#define NPY_LOG2Ef32    1.442695040888963407359924681001892137f32 /* log_2 e */
#define NPY_LOG10Ef32   0.434294481903251827651128918916605082f32 /* log_10 e */
#define NPY_LOGE2f32    0.693147180559945309417232121458176568f32 /* log_e 2 */
#define NPY_LOGE10f32   2.302585092994045684017991454684364208f32 /* log_e 10 */
#define NPY_PIf32       3.141592653589793238462643383279502884f32 /* pi */
#define NPY_PI_2f32     1.570796326794896619231321691639751442f32 /* pi/2 */
#define NPY_PI_4f32     0.785398163397448309615660845819875721f32 /* pi/4 */
#define NPY_1_PIf32     0.318309886183790671537767526745028724f32 /* 1/pi */
#define NPY_2_PIf32     0.636619772367581343075535053490057448f32 /* 2/pi */
#define NPY_EULERf32    0.577215664901532860606512090082402431f32 /* Euler constant */
#define NPY_SQRT2f32    1.414213562373095048801688724209698079f32 /* sqrt(2) */
#define NPY_SQRT1_2f32  0.707106781186547524400844362104849039f32 /* 1/sqrt(2) */

#define NPY_Ef64        2.718281828459045235360287471352662498f64 /* e */
#define NPY_LOG2Ef64    1.442695040888963407359924681001892137f64 /* log_2 e */
#define NPY_LOG10Ef64   0.434294481903251827651128918916605082f64 /* log_10 e */
#define NPY_LOGE2f64    0.693147180559945309417232121458176568f64 /* log_e 2 */
#define NPY_LOGE10f64   2.302585092994045684017991454684364208f64 /* log_e 10 */
#define NPY_PIf64       3.141592653589793238462643383279502884f64 /* pi */
#define NPY_PI_2f64     1.570796326794896619231321691639751442f64 /* pi/2 */
#define NPY_PI_4f64     0.785398163397448309615660845819875721f64 /* pi/4 */
#define NPY_1_PIf64     0.318309886183790671537767526745028724f64 /* 1/pi */
#define NPY_2_PIf64     0.636619772367581343075535053490057448f64 /* 2/pi */
#define NPY_EULERf64    0.577215664901532860606512090082402431f64 /* Euler constant */
#define NPY_SQRT2f64    1.414213562373095048801688724209698079f64 /* sqrt(2) */
#define NPY_SQRT1_2f64  0.707106781186547524400844362104849039f64 /* 1/sqrt(2) */

#define NPY_Ef128        2.718281828459045235360287471352662498f128 /* e */
#define NPY_LOG2Ef128    1.442695040888963407359924681001892137f128 /* log_2 e */
#define NPY_LOG10Ef128   0.434294481903251827651128918916605082f128 /* log_10 e */
#define NPY_LOGE2f128    0.693147180559945309417232121458176568f128 /* log_e 2 */
#define NPY_LOGE10f128   2.302585092994045684017991454684364208f128 /* log_e 10 */
#define NPY_PIf128       3.141592653589793238462643383279502884f128 /* pi */
#define NPY_PI_2f128     1.570796326794896619231321691639751442f128 /* pi/2 */
#define NPY_PI_4f128     0.785398163397448309615660845819875721f128 /* pi/4 */
#define NPY_1_PIf128     0.318309886183790671537767526745028724f128 /* 1/pi */
#define NPY_2_PIf128     0.636619772367581343075535053490057448f128 /* 2/pi */
#define NPY_EULERf128    0.577215664901532860606512090082402431f128 /* Euler constant */
#define NPY_SQRT2f128    1.414213562373095048801688724209698079f128 /* sqrt(2) */
#define NPY_SQRT1_2f128  0.707106781186547524400844362104849039f128 /* 1/sqrt(2) */

/*
 * C99 double math funcs
 */
NPY_INPLACE double npy_sin(double x);
NPY_INPLACE double npy_cos(double x);
NPY_INPLACE double npy_tan(double x);
NPY_INPLACE double npy_sinh(double x);
NPY_INPLACE double npy_cosh(double x);
NPY_INPLACE double npy_tanh(double x);

NPY_INPLACE double npy_asin(double x);
NPY_INPLACE double npy_acos(double x);
NPY_INPLACE double npy_atan(double x);

NPY_INPLACE double npy_log(double x);
NPY_INPLACE double npy_log10(double x);
NPY_INPLACE double npy_exp(double x);
NPY_INPLACE double npy_sqrt(double x);
NPY_INPLACE double npy_cbrt(double x);

NPY_INPLACE double npy_fabs(double x);
NPY_INPLACE double npy_ceil(double x);
NPY_INPLACE double npy_fmod(double x, double y);
NPY_INPLACE double npy_floor(double x);

NPY_INPLACE double npy_expm1(double x);
NPY_INPLACE double npy_log1p(double x);
NPY_INPLACE double npy_hypot(double x, double y);
NPY_INPLACE double npy_acosh(double x);
NPY_INPLACE double npy_asinh(double xx);
NPY_INPLACE double npy_atanh(double x);
NPY_INPLACE double npy_rint(double x);
NPY_INPLACE double npy_trunc(double x);
NPY_INPLACE double npy_exp2(double x);
NPY_INPLACE double npy_log2(double x);

NPY_INPLACE double npy_atan2(double x, double y);
NPY_INPLACE double npy_pow(double x, double y);
NPY_INPLACE double npy_modf(double x, double* y);
NPY_INPLACE double npy_frexp(double x, int* y);
NPY_INPLACE double npy_ldexp(double n, int y);

NPY_INPLACE double npy_copysign(double x, double y);
double npy_nextafter(double x, double y);
double npy_spacing(double x);

/*
 * IEEE 754 fpu handling. Those are guaranteed to be macros
 */

/* use builtins to avoid function calls in tight loops
 * only available if npy_config.h is available (= numpys own build) */
#if HAVE___BUILTIN_ISNAN
    #define npy_isnan(x) __builtin_isnan(x)
#else
    #ifndef NPY_HAVE_DECL_ISNAN
        #define npy_isnan(x) ((x) != (x))
    #else
        #if defined(_MSC_VER) && (_MSC_VER < 1900)
            #define npy_isnan(x) _isnan((x))
        #else
            #define npy_isnan(x) isnan(x)
        #endif
    #endif
#endif


/* only available if npy_config.h is available (= numpys own build) */
#if HAVE___BUILTIN_ISFINITE
    #define npy_isfinite(x) __builtin_isfinite(x)
#else
    #ifndef NPY_HAVE_DECL_ISFINITE
        #ifdef _MSC_VER
            #define npy_isfinite(x) _finite((x))
        #else
            #define npy_isfinite(x) !npy_isnan((x) + (-x))
        #endif
    #else
        #define npy_isfinite(x) isfinite((x))
    #endif
#endif

/* only available if npy_config.h is available (= numpys own build) */
#if HAVE___BUILTIN_ISINF
    #define npy_isinf(x) __builtin_isinf(x)
#else
    #ifndef NPY_HAVE_DECL_ISINF
        #define npy_isinf(x) (!npy_isfinite(x) && !npy_isnan(x))
    #else
        #if defined(_MSC_VER) && (_MSC_VER < 1900)
            #define npy_isinf(x) (!_finite((x)) && !_isnan((x)))
        #else
            #define npy_isinf(x) isinf((x))
        #endif
    #endif
#endif

#ifndef NPY_HAVE_DECL_SIGNBIT
    int _npy_signbit_f(float x);
    int _npy_signbit_d(double x);
    int _npy_signbit_ld(long double x);
    #define npy_signbit(x) \
        (sizeof (x) == sizeof (long double) ? _npy_signbit_ld (x) \
         : sizeof (x) == sizeof (double) ? _npy_signbit_d (x) \
         : _npy_signbit_f (x))
#else
    #define npy_signbit(x) signbit((x))
#endif

/*
 * float C99 math functions
 */
NPY_INPLACE float npy_sinf(float x);
NPY_INPLACE float npy_cosf(float x);
NPY_INPLACE float npy_tanf(float x);
NPY_INPLACE float npy_sinhf(float x);
NPY_INPLACE float npy_coshf(float x);
NPY_INPLACE float npy_tanhf(float x);
NPY_INPLACE float npy_fabsf(float x);
NPY_INPLACE float npy_floorf(float x);
NPY_INPLACE float npy_ceilf(float x);
NPY_INPLACE float npy_rintf(float x);
NPY_INPLACE float npy_truncf(float x);
NPY_INPLACE float npy_sqrtf(float x);
NPY_INPLACE float npy_cbrtf(float x);
NPY_INPLACE float npy_log10f(float x);
NPY_INPLACE float npy_logf(float x);
NPY_INPLACE float npy_expf(float x);
NPY_INPLACE float npy_expm1f(float x);
NPY_INPLACE float npy_asinf(float x);
NPY_INPLACE float npy_acosf(float x);
NPY_INPLACE float npy_atanf(float x);
NPY_INPLACE float npy_asinhf(float x);
NPY_INPLACE float npy_acoshf(float x);
NPY_INPLACE float npy_atanhf(float x);
NPY_INPLACE float npy_log1pf(float x);
NPY_INPLACE float npy_exp2f(float x);
NPY_INPLACE float npy_log2f(float x);

NPY_INPLACE float npy_atan2f(float x, float y);
NPY_INPLACE float npy_hypotf(float x, float y);
NPY_INPLACE float npy_powf(float x, float y);
NPY_INPLACE float npy_fmodf(float x, float y);

NPY_INPLACE float npy_modff(float x, float* y);
NPY_INPLACE float npy_frexpf(float x, int* y);
NPY_INPLACE float npy_ldexpf(float x, int y);

NPY_INPLACE float npy_copysignf(float x, float y);
float npy_nextafterf(float x, float y);
float npy_spacingf(float x);

/*
 * long double C99 math functions
 */
NPY_INPLACE npy_longdouble npy_sinl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_cosl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_tanl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_sinhl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_coshl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_tanhl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_fabsl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_floorl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_ceill(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_rintl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_truncl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_sqrtl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_cbrtl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_log10l(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_logl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_expl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_expm1l(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_asinl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_acosl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_atanl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_asinhl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_acoshl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_atanhl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_log1pl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_exp2l(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_log2l(npy_longdouble x);

NPY_INPLACE npy_longdouble npy_atan2l(npy_longdouble x, npy_longdouble y);
NPY_INPLACE npy_longdouble npy_hypotl(npy_longdouble x, npy_longdouble y);
NPY_INPLACE npy_longdouble npy_powl(npy_longdouble x, npy_longdouble y);
NPY_INPLACE npy_longdouble npy_fmodl(npy_longdouble x, npy_longdouble y);

NPY_INPLACE npy_longdouble npy_modfl(npy_longdouble x, npy_longdouble* y);
NPY_INPLACE npy_longdouble npy_frexpl(npy_longdouble x, int* y);
NPY_INPLACE npy_longdouble npy_ldexpl(npy_longdouble x, int y);

NPY_INPLACE npy_longdouble npy_copysignl(npy_longdouble x, npy_longdouble y);
npy_longdouble npy_nextafterl(npy_longdouble x, npy_longdouble y);
npy_longdouble npy_spacingl(npy_longdouble x);

NPY_INPLACE npy_binary32 npy_sinf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_cosf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_tanf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_sinhf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_coshf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_tanhf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_fabsf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_floorf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_ceilf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_rintf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_truncf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_sqrtf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_cbrtf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_log10f32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_logf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_expf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_expm1f32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_asinf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_acosf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_atanf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_asinhf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_acoshf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_atanhf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_log1pf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_exp2f32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_log2f32(npy_binary32 x);

NPY_INPLACE npy_binary32 npy_atan2f32(npy_binary32 x, npy_binary32 y);
NPY_INPLACE npy_binary32 npy_hypotf32(npy_binary32 x, npy_binary32 y);
NPY_INPLACE npy_binary32 npy_powf32(npy_binary32 x, npy_binary32 y);
NPY_INPLACE npy_binary32 npy_fmodf32(npy_binary32 x, npy_binary32 y);

NPY_INPLACE npy_binary32 npy_modff32(npy_binary32 x, npy_binary32* y);
NPY_INPLACE npy_binary32 npy_frexpf32(npy_binary32 x, int* y);
NPY_INPLACE npy_binary32 npy_ldexpf32(npy_binary32 x, int y);

NPY_INPLACE npy_binary32 npy_copysignf32(npy_binary32 x, npy_binary32 y);
npy_binary32 npy_nextafterf32(npy_binary32 x, npy_binary32 y);
npy_binary32 npy_spacingf32(npy_binary32 x);

NPY_INPLACE npy_binary64 npy_sinf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_cosf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_tanf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_sinhf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_coshf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_tanhf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_fabsf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_floorf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_ceilf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_rintf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_truncf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_sqrtf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_cbrtf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_log10f64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_logf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_expf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_expm1f64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_asinf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_acosf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_atanf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_asinhf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_acoshf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_atanhf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_log1pf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_exp2f64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_log2f64(npy_binary64 x);

NPY_INPLACE npy_binary64 npy_atan2f64(npy_binary64 x, npy_binary64 y);
NPY_INPLACE npy_binary64 npy_hypotf64(npy_binary64 x, npy_binary64 y);
NPY_INPLACE npy_binary64 npy_powf64(npy_binary64 x, npy_binary64 y);
NPY_INPLACE npy_binary64 npy_fmodf64(npy_binary64 x, npy_binary64 y);

NPY_INPLACE npy_binary64 npy_modff64(npy_binary64 x, npy_binary64* y);
NPY_INPLACE npy_binary64 npy_frexpf64(npy_binary64 x, int* y);
NPY_INPLACE npy_binary64 npy_ldexpf64(npy_binary64 x, int y);

NPY_INPLACE npy_binary64 npy_copysignf64(npy_binary64 x, npy_binary64 y);
npy_binary64 npy_nextafterf64(npy_binary64 x, npy_binary64 y);
npy_binary64 npy_spacingf64(npy_binary64 x);

NPY_INPLACE npy_binary128 npy_sinf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_cosf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_tanf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_sinhf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_coshf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_tanhf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_fabsf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_floorf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_ceilf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_rintf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_truncf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_sqrtf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_cbrtf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_log10f128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_logf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_expf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_expm1f128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_asinf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_acosf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_atanf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_asinhf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_acoshf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_atanhf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_log1pf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_exp2f128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_log2f128(npy_binary128 x);

NPY_INPLACE npy_binary128 npy_atan2f128(npy_binary128 x, npy_binary128 y);
NPY_INPLACE npy_binary128 npy_hypotf128(npy_binary128 x, npy_binary128 y);
NPY_INPLACE npy_binary128 npy_powf128(npy_binary128 x, npy_binary128 y);
NPY_INPLACE npy_binary128 npy_fmodf128(npy_binary128 x, npy_binary128 y);

NPY_INPLACE npy_binary128 npy_modff128(npy_binary128 x, npy_binary128* y);
NPY_INPLACE npy_binary128 npy_frexpf128(npy_binary128 x, int* y);
NPY_INPLACE npy_binary128 npy_ldexpf128(npy_binary128 x, int y);

NPY_INPLACE npy_binary128 npy_copysignf128(npy_binary128 x, npy_binary128 y);
npy_binary128 npy_nextafterf128(npy_binary128 x, npy_binary128 y);
npy_binary128 npy_spacingf128(npy_binary128 x);
/*
 * Non standard functions
 */
NPY_INPLACE double npy_deg2rad(double x);
NPY_INPLACE double npy_rad2deg(double x);
NPY_INPLACE double npy_logaddexp(double x, double y);
NPY_INPLACE double npy_logaddexp2(double x, double y);
NPY_INPLACE double npy_divmod(double x, double y, double *modulus);
NPY_INPLACE double npy_heaviside(double x, double h0);

NPY_INPLACE float npy_deg2radf(float x);
NPY_INPLACE float npy_rad2degf(float x);
NPY_INPLACE float npy_logaddexpf(float x, float y);
NPY_INPLACE float npy_logaddexp2f(float x, float y);
NPY_INPLACE float npy_divmodf(float x, float y, float *modulus);
NPY_INPLACE float npy_heavisidef(float x, float h0);

NPY_INPLACE npy_longdouble npy_deg2radl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_rad2degl(npy_longdouble x);
NPY_INPLACE npy_longdouble npy_logaddexpl(npy_longdouble x, npy_longdouble y);
NPY_INPLACE npy_longdouble npy_logaddexp2l(npy_longdouble x, npy_longdouble y);
NPY_INPLACE npy_longdouble npy_divmodl(npy_longdouble x, npy_longdouble y,
                           npy_longdouble *modulus);
NPY_INPLACE npy_longdouble npy_heavisidel(npy_longdouble x, npy_longdouble h0);

NPY_INPLACE npy_binary32 npy_deg2radf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_rad2degf32(npy_binary32 x);
NPY_INPLACE npy_binary32 npy_logaddexpf32(npy_binary32 x, npy_binary32 y);
NPY_INPLACE npy_binary32 npy_logaddexp2f32(npy_binary32 x, npy_binary32 y);
NPY_INPLACE npy_binary32 npy_divmodf32(npy_binary32 x, npy_binary32 y,
                           npy_binary32 *modulus);
NPY_INPLACE npy_binary32 npy_heavisidef32(npy_binary32 x, npy_binary32 h0);

NPY_INPLACE npy_binary64 npy_deg2radf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_rad2degf64(npy_binary64 x);
NPY_INPLACE npy_binary64 npy_logaddexpf64(npy_binary64 x, npy_binary64 y);
NPY_INPLACE npy_binary64 npy_logaddexp2f64(npy_binary64 x, npy_binary64 y);
NPY_INPLACE npy_binary64 npy_divmodf64(npy_binary64 x, npy_binary64 y,
                           npy_binary64 *modulus);
NPY_INPLACE npy_binary64 npy_heavisidef64(npy_binary64 x, npy_binary64 h0);

NPY_INPLACE npy_binary128 npy_deg2radf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_rad2degf128(npy_binary128 x);
NPY_INPLACE npy_binary128 npy_logaddexpf128(npy_binary128 x, npy_binary128 y);
NPY_INPLACE npy_binary128 npy_logaddexp2f128(npy_binary128 x, npy_binary128 y);
NPY_INPLACE npy_binary128 npy_divmodf128(npy_binary128 x, npy_binary128 y,
                           npy_binary128 *modulus);
NPY_INPLACE npy_binary128 npy_heavisidef128(npy_binary128 x, npy_binary128 h0);

#define npy_degrees npy_rad2deg
#define npy_degreesf npy_rad2degf
#define npy_degreesl npy_rad2degl

#define npy_radians npy_deg2rad
#define npy_radiansf npy_deg2radf
#define npy_radiansl npy_deg2radl

/*
 * Complex declarations
 */

/*
 * C99 specifies that complex numbers have the same representation as
 * an array of two elements, where the first element is the real part
 * and the second element is the imaginary part.
 */
#define __NPY_CPACK_IMP(x, y, type, ctype)   \
    union {                                  \
        ctype z;                             \
        type a[2];                           \
    } z1;;                                   \
                                             \
    z1.a[0] = (x);                           \
    z1.a[1] = (y);                           \
                                             \
    return z1.z;

static NPY_INLINE npy_cdouble npy_cpack(double x, double y)
{
    __NPY_CPACK_IMP(x, y, double, npy_cdouble);
}

static NPY_INLINE npy_cfloat npy_cpackf(float x, float y)
{
    __NPY_CPACK_IMP(x, y, float, npy_cfloat);
}

static NPY_INLINE npy_clongdouble npy_cpackl(npy_longdouble x, npy_longdouble y)
{
    __NPY_CPACK_IMP(x, y, npy_longdouble, npy_clongdouble);
}

static NPY_INLINE npy_cbinary64 npy_cpackf32(npy_binary32 x, npy_binary32 y)
{
    __NPY_CPACK_IMP(x, y, npy_binary32, npy_cbinary64);
}

static NPY_INLINE npy_cbinary128 npy_cpackf64(npy_binary64 x, npy_binary64 y)
{
    __NPY_CPACK_IMP(x, y, npy_binary64, npy_cbinary128);
}

static NPY_INLINE npy_cbinary256 npy_cpackf128(npy_binary128 x, npy_binary128 y)
{
    __NPY_CPACK_IMP(x, y, npy_binary128, npy_cbinary256);
}
#undef __NPY_CPACK_IMP

/*
 * Same remark as above, but in the other direction: extract first/second
 * member of complex number, assuming a C99-compatible representation
 *
 * Those are defineds as static inline, and such as a reasonable compiler would
 * most likely compile this to one or two instructions (on CISC at least)
 */
#define __NPY_CEXTRACT_IMP(z, index, type, ctype)   \
    union {                                         \
        ctype z;                                    \
        type a[2];                                  \
    } __z_repr;                                     \
    __z_repr.z = z;                                 \
                                                    \
    return __z_repr.a[index];

static NPY_INLINE double npy_creal(npy_cdouble z)
{
    __NPY_CEXTRACT_IMP(z, 0, double, npy_cdouble);
}

static NPY_INLINE double npy_cimag(npy_cdouble z)
{
    __NPY_CEXTRACT_IMP(z, 1, double, npy_cdouble);
}

static NPY_INLINE float npy_crealf(npy_cfloat z)
{
    __NPY_CEXTRACT_IMP(z, 0, float, npy_cfloat);
}

static NPY_INLINE float npy_cimagf(npy_cfloat z)
{
    __NPY_CEXTRACT_IMP(z, 1, float, npy_cfloat);
}

static NPY_INLINE npy_longdouble npy_creall(npy_clongdouble z)
{
    __NPY_CEXTRACT_IMP(z, 0, npy_longdouble, npy_clongdouble);
}

static NPY_INLINE npy_longdouble npy_cimagl(npy_clongdouble z)
{
    __NPY_CEXTRACT_IMP(z, 1, npy_longdouble, npy_clongdouble);
}

static NPY_INLINE npy_binary32 npy_crealf32(npy_cbinary64 z)
{
    __NPY_CEXTRACT_IMP(z, 0, npy_binary32, npy_cbinary64);
}

static NPY_INLINE npy_binary32 npy_cimagf32(npy_cbinary64 z)
{
    __NPY_CEXTRACT_IMP(z, 1, npy_binary32, npy_cbinary64);
}

static NPY_INLINE npy_binary64 npy_crealf64(npy_cbinary128 z)
{
    __NPY_CEXTRACT_IMP(z, 0, npy_binary64, npy_cbinary128);
}

static NPY_INLINE npy_binary64 npy_cimagf64(npy_cbinary128 z)
{
    __NPY_CEXTRACT_IMP(z, 1, npy_binary64, npy_cbinary128);
}

static NPY_INLINE npy_binary128 npy_crealf128(npy_cbinary256 z)
{
    __NPY_CEXTRACT_IMP(z, 0, npy_binary128, npy_cbinary256);
}

static NPY_INLINE npy_binary128 npy_cimagf128(npy_cbinary256 z)
{
    __NPY_CEXTRACT_IMP(z, 1, npy_binary128, npy_cbinary256);
}
#undef __NPY_CEXTRACT_IMP

/*
 * Double precision complex functions
 */
double npy_cabs(npy_cdouble z);
double npy_carg(npy_cdouble z);

npy_cdouble npy_cexp(npy_cdouble z);
npy_cdouble npy_clog(npy_cdouble z);
npy_cdouble npy_cpow(npy_cdouble x, npy_cdouble y);

npy_cdouble npy_csqrt(npy_cdouble z);

npy_cdouble npy_ccos(npy_cdouble z);
npy_cdouble npy_csin(npy_cdouble z);
npy_cdouble npy_ctan(npy_cdouble z);

npy_cdouble npy_ccosh(npy_cdouble z);
npy_cdouble npy_csinh(npy_cdouble z);
npy_cdouble npy_ctanh(npy_cdouble z);

npy_cdouble npy_cacos(npy_cdouble z);
npy_cdouble npy_casin(npy_cdouble z);
npy_cdouble npy_catan(npy_cdouble z);

npy_cdouble npy_cacosh(npy_cdouble z);
npy_cdouble npy_casinh(npy_cdouble z);
npy_cdouble npy_catanh(npy_cdouble z);

/*
 * Single precision complex functions
 */
float npy_cabsf(npy_cfloat z);
float npy_cargf(npy_cfloat z);

npy_cfloat npy_cexpf(npy_cfloat z);
npy_cfloat npy_clogf(npy_cfloat z);
npy_cfloat npy_cpowf(npy_cfloat x, npy_cfloat y);

npy_cfloat npy_csqrtf(npy_cfloat z);

npy_cfloat npy_ccosf(npy_cfloat z);
npy_cfloat npy_csinf(npy_cfloat z);
npy_cfloat npy_ctanf(npy_cfloat z);

npy_cfloat npy_ccoshf(npy_cfloat z);
npy_cfloat npy_csinhf(npy_cfloat z);
npy_cfloat npy_ctanhf(npy_cfloat z);

npy_cfloat npy_cacosf(npy_cfloat z);
npy_cfloat npy_casinf(npy_cfloat z);
npy_cfloat npy_catanf(npy_cfloat z);

npy_cfloat npy_cacoshf(npy_cfloat z);
npy_cfloat npy_casinhf(npy_cfloat z);
npy_cfloat npy_catanhf(npy_cfloat z);


/*
 * Extended precision complex functions
 */
npy_longdouble npy_cabsl(npy_clongdouble z);
npy_longdouble npy_cargl(npy_clongdouble z);

npy_clongdouble npy_cexpl(npy_clongdouble z);
npy_clongdouble npy_clogl(npy_clongdouble z);
npy_clongdouble npy_cpowl(npy_clongdouble x, npy_clongdouble y);

npy_clongdouble npy_csqrtl(npy_clongdouble z);

npy_clongdouble npy_ccosl(npy_clongdouble z);
npy_clongdouble npy_csinl(npy_clongdouble z);
npy_clongdouble npy_ctanl(npy_clongdouble z);

npy_clongdouble npy_ccoshl(npy_clongdouble z);
npy_clongdouble npy_csinhl(npy_clongdouble z);
npy_clongdouble npy_ctanhl(npy_clongdouble z);

npy_clongdouble npy_cacosl(npy_clongdouble z);
npy_clongdouble npy_casinl(npy_clongdouble z);
npy_clongdouble npy_catanl(npy_clongdouble z);

npy_clongdouble npy_cacoshl(npy_clongdouble z);
npy_clongdouble npy_casinhl(npy_clongdouble z);
npy_clongdouble npy_catanhl(npy_clongdouble z);

npy_binary32 npy_cabsf32(npy_cbinary64 z);
npy_binary32 npy_cargf32(npy_cbinary64 z);

npy_cbinary64 npy_cexpf32(npy_cbinary64 z);
npy_cbinary64 npy_clogf32(npy_cbinary64 z);
npy_cbinary64 npy_cpowf32(npy_cbinary64 x, npy_cbinary64 y);

npy_cbinary64 npy_csqrtf32(npy_cbinary64 z);

npy_cbinary64 npy_ccosf32(npy_cbinary64 z);
npy_cbinary64 npy_csinf32(npy_cbinary64 z);
npy_cbinary64 npy_ctanf32(npy_cbinary64 z);

npy_cbinary64 npy_ccoshf32(npy_cbinary64 z);
npy_cbinary64 npy_csinhf32(npy_cbinary64 z);
npy_cbinary64 npy_ctanhf32(npy_cbinary64 z);

npy_cbinary64 npy_cacosf32(npy_cbinary64 z);
npy_cbinary64 npy_casinf32(npy_cbinary64 z);
npy_cbinary64 npy_catanf32(npy_cbinary64 z);

npy_cbinary64 npy_cacoshf32(npy_cbinary64 z);
npy_cbinary64 npy_casinhf32(npy_cbinary64 z);
npy_cbinary64 npy_catanhf32(npy_cbinary64 z);

npy_binary32 npy_cabsf32(npy_cbinary64 z);
npy_binary32 npy_cargf32(npy_cbinary64 z);

npy_cbinary128 npy_cexpf64(npy_cbinary128 z);
npy_cbinary128 npy_clogf64(npy_cbinary128 z);
npy_cbinary128 npy_cpowf64(npy_cbinary128 x, npy_cbinary128 y);

npy_cbinary128 npy_csqrtf64(npy_cbinary128 z);

npy_cbinary128 npy_ccosf64(npy_cbinary128 z);
npy_cbinary128 npy_csinf64(npy_cbinary128 z);
npy_cbinary128 npy_ctanf64(npy_cbinary128 z);

npy_cbinary128 npy_ccoshf64(npy_cbinary128 z);
npy_cbinary128 npy_csinhf64(npy_cbinary128 z);
npy_cbinary128 npy_ctanhf64(npy_cbinary128 z);

npy_cbinary128 npy_cacosf64(npy_cbinary128 z);
npy_cbinary128 npy_casinf64(npy_cbinary128 z);
npy_cbinary128 npy_catanf64(npy_cbinary128 z);

npy_cbinary128 npy_cacoshf64(npy_cbinary128 z);
npy_cbinary128 npy_casinhf64(npy_cbinary128 z);
npy_cbinary128 npy_catanhf64(npy_cbinary128 z);

npy_binary128 npy_cabsf128(npy_cbinary256 z);
npy_binary128 npy_cargf128(npy_cbinary256 z);

npy_cbinary256 npy_cexpf128(npy_cbinary256 z);
npy_cbinary256 npy_clogf128(npy_cbinary256 z);
npy_cbinary256 npy_cpowf128(npy_cbinary256 x, npy_cbinary256 y);

npy_cbinary256 npy_csqrtf128(npy_cbinary256 z);

npy_cbinary256 npy_ccosf128(npy_cbinary256 z);
npy_cbinary256 npy_csinf128(npy_cbinary256 z);
npy_cbinary256 npy_ctanf128(npy_cbinary256 z);

npy_cbinary256 npy_ccoshf128(npy_cbinary256 z);
npy_cbinary256 npy_csinhf128(npy_cbinary256 z);
npy_cbinary256 npy_ctanhf128(npy_cbinary256 z);

npy_cbinary256 npy_cacosf128(npy_cbinary256 z);
npy_cbinary256 npy_casinf128(npy_cbinary256 z);
npy_cbinary256 npy_catanf128(npy_cbinary256 z);

npy_cbinary256 npy_cacoshf128(npy_cbinary256 z);
npy_cbinary256 npy_casinhf128(npy_cbinary256 z);
npy_cbinary256 npy_catanhf128(npy_cbinary256 z);

/*
 * Functions that set the floating point error
 * status word.
 */

/*
 * platform-dependent code translates floating point
 * status to an integer sum of these values
 */
#define NPY_FPE_DIVIDEBYZERO  1
#define NPY_FPE_OVERFLOW      2
#define NPY_FPE_UNDERFLOW     4
#define NPY_FPE_INVALID       8

int npy_get_floatstatus(void);
int npy_clear_floatstatus(void);
void npy_set_floatstatus_divbyzero(void);
void npy_set_floatstatus_overflow(void);
void npy_set_floatstatus_underflow(void);
void npy_set_floatstatus_invalid(void);

#ifdef __cplusplus
}
#endif

#if NPY_INLINE_MATH
#include "npy_math_internal.h"
#endif

#endif
