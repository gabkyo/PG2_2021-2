/*
 * File: KalmanAccelC_types.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

#ifndef KALMANACCELC_TYPES_H
#define KALMANACCELC_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef enum_c_matlab_internal_coder_tabular
#define enum_c_matlab_internal_coder_tabular
enum c_matlab_internal_coder_tabular
{
  unset = 0, /* Default value */
  continuous,
  step,
  event
};
#endif /* enum_c_matlab_internal_coder_tabular */
#ifndef typedef_c_matlab_internal_coder_tabular
#define typedef_c_matlab_internal_coder_tabular
typedef enum c_matlab_internal_coder_tabular c_matlab_internal_coder_tabular;
#endif /* typedef_c_matlab_internal_coder_tabular */

#ifndef typedef_d_matlab_internal_coder_tabular
#define typedef_d_matlab_internal_coder_tabular
typedef struct {
  double length;
} d_matlab_internal_coder_tabular;
#endif /* typedef_d_matlab_internal_coder_tabular */

#ifndef typedef_e_matlab_internal_coder_tabular
#define typedef_e_matlab_internal_coder_tabular
typedef struct {
  double length;
} e_matlab_internal_coder_tabular;
#endif /* typedef_e_matlab_internal_coder_tabular */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  int size[2];
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
  double length;
  cell_wrap_3 descrs[3];
  cell_wrap_3 units[3];
  c_matlab_internal_coder_tabular continuity[3];
  boolean_T hasDescrs;
  boolean_T hasUnits;
  boolean_T hasContinuity;
  boolean_T hasCustomProps;
} f_matlab_internal_coder_tabular;
#endif /* typedef_f_matlab_internal_coder_tabular */

#ifndef typedef_table
#define typedef_table
typedef struct {
  d_matlab_internal_coder_tabular metaDim;
  e_matlab_internal_coder_tabular rowDim;
  f_matlab_internal_coder_tabular varDim;
  cell_wrap_4 data[3];
  struct0_T arrayProps;
} table;
#endif /* typedef_table */

#endif
/*
 * File trailer for KalmanAccelC_types.h
 *
 * [EOF]
 */
