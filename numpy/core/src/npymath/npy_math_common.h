/*
 * Common headers needed by every npy math compilation unit
 */
#ifndef __STDC_WANT_IEC_60559_TYPES_EXT__
#define __STDC_WANT_IEC_60559_TYPES_EXT__
#endif
#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
#define __STDC_WANT_IEC_60559_BFP_EXT__
#endif
#ifndef __STDC_WANT_IEC_60559_FUNCS_EXT__
#define __STDC_WANT_IEC_60559_FUNCS_EXT__
#endif
#include <Python.h>
#include <math.h>
#include <float.h>

#include "npy_config.h"
#include "numpy/npy_math.h"
