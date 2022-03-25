/*
 * File: KalmanAccelC_emxAPI.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

#ifndef KALMANACCELC_EMXAPI_H
#define KALMANACCELC_EMXAPI_H

/* Include Files */
#include "KalmanAccelC_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);

extern emxArray_real_T *
emxCreateWrapperND_real_T(double *data, int numDimensions, const int *size);

extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows,
                                                int cols);

extern emxArray_real_T *emxCreate_real_T(int rows, int cols);

extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);

extern void emxDestroy_table(table emxArray);

extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_table(table *pStruct);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for KalmanAccelC_emxAPI.h
 *
 * [EOF]
 */
