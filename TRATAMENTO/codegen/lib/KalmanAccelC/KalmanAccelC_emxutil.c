/*
 * File: KalmanAccelC_emxutil.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

/* Include Files */
#include "KalmanAccelC_emxutil.h"
#include "KalmanAccelC_types.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : f_matlab_internal_coder_tabular *pStruct
 * Return Type  : void
 */
void c_emxInitStruct_matlab_internal(f_matlab_internal_coder_tabular *pStruct)
{
  emxInitMatrix_cell_wrap_3(pStruct->descrs);
  emxInitMatrix_cell_wrap_3(pStruct->units);
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : cell_wrap_4 pMatrix[3]
 * Return Type  : void
 */
void emxFreeMatrix_cell_wrap_4(cell_wrap_4 pMatrix[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    emxFreeStruct_cell_wrap_4(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_4 *pStruct
 * Return Type  : void
 */
void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

/*
 * Arguments    : table *pStruct
 * Return Type  : void
 */
void emxFreeStruct_table(table *pStruct)
{
  emxFreeMatrix_cell_wrap_4(pStruct->data);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : cell_wrap_3 pMatrix[3]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_3(cell_wrap_3 pMatrix[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_3(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_4 pMatrix[3]
 * Return Type  : void
 */
void emxInitMatrix_cell_wrap_4(cell_wrap_4 pMatrix[3])
{
  int i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_4(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_3 *pStruct
 * Return Type  : void
 */
void emxInitStruct_cell_wrap_3(cell_wrap_3 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

/*
 * Arguments    : cell_wrap_4 *pStruct
 * Return Type  : void
 */
void emxInitStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 1);
}

/*
 * Arguments    : struct0_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  pStruct->Description.size[0] = 0;
  pStruct->Description.size[1] = 0;
}

/*
 * Arguments    : table *pStruct
 * Return Type  : void
 */
void emxInitStruct_table(table *pStruct)
{
  c_emxInitStruct_matlab_internal(&pStruct->varDim);
  emxInitMatrix_cell_wrap_4(pStruct->data);
  emxInitStruct_struct0_T(&pStruct->arrayProps);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * File trailer for KalmanAccelC_emxutil.c
 *
 * [EOF]
 */
