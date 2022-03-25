/*
 * File: KalmanAccelC_emxutil.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

#ifndef KALMANACCELC_EMXUTIL_H
#define KALMANACCELC_EMXUTIL_H

/* Include Files */
#include "KalmanAccelC_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
c_emxInitStruct_matlab_internal(f_matlab_internal_coder_tabular *pStruct);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFreeMatrix_cell_wrap_4(cell_wrap_4 pMatrix[3]);

extern void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct);

extern void emxFreeStruct_table(table *pStruct);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInitMatrix_cell_wrap_3(cell_wrap_3 pMatrix[3]);

extern void emxInitMatrix_cell_wrap_4(cell_wrap_4 pMatrix[3]);

extern void emxInitStruct_cell_wrap_3(cell_wrap_3 *pStruct);

extern void emxInitStruct_cell_wrap_4(cell_wrap_4 *pStruct);

extern void emxInitStruct_struct0_T(struct0_T *pStruct);

extern void emxInitStruct_table(table *pStruct);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for KalmanAccelC_emxutil.h
 *
 * [EOF]
 */
