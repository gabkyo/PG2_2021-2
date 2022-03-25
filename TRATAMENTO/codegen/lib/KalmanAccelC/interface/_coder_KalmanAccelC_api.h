/*
 * File: _coder_KalmanAccelC_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

#ifndef _CODER_KALMANACCELC_API_H
#define _CODER_KALMANACCELC_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_c_matlab_internal_coder_tabular
#define typedef_c_matlab_internal_coder_tabular
typedef struct {
  real_T length;
} c_matlab_internal_coder_tabular;
#endif /* typedef_c_matlab_internal_coder_tabular */

#ifndef typedef_d_matlab_internal_coder_tabular
#define typedef_d_matlab_internal_coder_tabular
typedef struct {
  real_T length;
} d_matlab_internal_coder_tabular;
#endif /* typedef_d_matlab_internal_coder_tabular */

#ifndef enum_e_matlab_internal_coder_tabular
#define enum_e_matlab_internal_coder_tabular
enum e_matlab_internal_coder_tabular
{
  unset = 0, /* Default value */
  continuous,
  step,
  event
};
#endif /* enum_e_matlab_internal_coder_tabular */
#ifndef typedef_e_matlab_internal_coder_tabular
#define typedef_e_matlab_internal_coder_tabular
typedef enum e_matlab_internal_coder_tabular e_matlab_internal_coder_tabular;
#endif /* typedef_e_matlab_internal_coder_tabular */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_cell_wrap_4
#define typedef_cell_wrap_4
typedef struct {
  emxArray_real_T *f1;
} cell_wrap_4;
#endif /* typedef_cell_wrap_4 */

#ifndef struct_emxArray_char_T_1x0
#define struct_emxArray_char_T_1x0
struct emxArray_char_T_1x0 {
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x0 */
#ifndef typedef_emxArray_char_T_1x0
#define typedef_emxArray_char_T_1x0
typedef struct emxArray_char_T_1x0 emxArray_char_T_1x0;
#endif /* typedef_emxArray_char_T_1x0 */

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  emxArray_char_T_1x0 f1;
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  emxArray_char_T_1x0 Description;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_f_matlab_internal_coder_tabular
#define typedef_f_matlab_internal_coder_tabular
typedef struct {
  real_T length;
  cell_wrap_3 descrs[3];
  cell_wrap_3 units[3];
  e_matlab_internal_coder_tabular continuity[3];
  boolean_T hasDescrs;
  boolean_T hasUnits;
  boolean_T hasContinuity;
  boolean_T hasCustomProps;
} f_matlab_internal_coder_tabular;
#endif /* typedef_f_matlab_internal_coder_tabular */

#ifndef typedef_table
#define typedef_table
typedef struct {
  c_matlab_internal_coder_tabular metaDim;
  d_matlab_internal_coder_tabular rowDim;
  f_matlab_internal_coder_tabular varDim;
  cell_wrap_4 data[3];
  struct0_T arrayProps;
} table;
#endif /* typedef_table */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void KalmanAccelC(real_T dT, real_T tamanho, emxArray_real_T *f, table *dados);

void KalmanAccelC_api(const mxArray *const prhs[3], const mxArray **plhs);

void KalmanAccelC_atexit(void);

void KalmanAccelC_initialize(void);

void KalmanAccelC_terminate(void);

void KalmanAccelC_xil_shutdown(void);

void KalmanAccelC_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_KalmanAccelC_api.h
 *
 * [EOF]
 */
