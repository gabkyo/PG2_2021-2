/*
 * File: _coder_KalmanAccelC_api.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

/* Include Files */
#include "_coder_KalmanAccelC_api.h"
#include "_coder_KalmanAccelC_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "KalmanAccelC",                                       /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const cell_wrap_3 u[3]);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *f,
                               const char_T *identifier, emxArray_real_T *y);

static void
c_emxInitStruct_matlab_internal(f_matlab_internal_coder_tabular *pStruct);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *dT,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const table *u);

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel);

static void emxFreeMatrix_cell_wrap_4(cell_wrap_4 pMatrix[3]);

static void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct);

static void emxFreeStruct_table(table *pStruct);

static void emxFree_real_T(emxArray_real_T **pEmxArray);

static void emxInitMatrix_cell_wrap_3(cell_wrap_3 pMatrix[3]);

static void emxInitMatrix_cell_wrap_4(const emlrtStack *sp,
                                      cell_wrap_4 pMatrix[3], boolean_T doPush);

static void emxInitStruct_cell_wrap_3(cell_wrap_3 *pStruct);

static void emxInitStruct_cell_wrap_4(const emlrtStack *sp,
                                      cell_wrap_4 *pStruct, boolean_T doPush);

static void emxInitStruct_struct0_T(struct0_T *pStruct);

static void emxInitStruct_table(const emlrtStack *sp, table *pStruct,
                                boolean_T doPush);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions, boolean_T doPush);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const cell_wrap_3 u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const cell_wrap_3 u[3])
{
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  y = NULL;
  iv[0] = 1;
  iv[1] = 3;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  for (i = 0; i < 3; i++) {
    b_y = NULL;
    iv[0] = u[i].f1.size[0];
    iv[1] = 0;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtCTX)sp, 0, m, NULL);
    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
  }
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *f
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *f,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(f), &thisId, y);
  emlrtDestroyArray(&f);
}

/*
 * Arguments    : f_matlab_internal_coder_tabular *pStruct
 * Return Type  : void
 */
static void
c_emxInitStruct_matlab_internal(f_matlab_internal_coder_tabular *pStruct)
{
  emxInitMatrix_cell_wrap_3(pStruct->descrs);
  emxInitMatrix_cell_wrap_3(pStruct->units);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  f_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *dT
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *dT,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(dT), &thisId);
  emlrtDestroyArray(&dT);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const table *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const table *u)
{
  static const int32_T enumValues[4] = {0, 1, 2, 3};
  static const int32_T iv1[2] = {1, 3};
  static const int32_T iv2[2] = {1, 9};
  static const int32_T iv3[2] = {1, 5};
  static const int32_T iv4[2] = {1, 10};
  static const int32_T iv5[2] = {1, 12};
  static const int32_T iv6[2] = {1, 3};
  static const int32_T iv7[2] = {0, 0};
  static const char_T f_u[12] = {'D', 'e', 's', 'l', 'o', 'c',
                                 'a', 'm', 'e', 'n', 't', 'o'};
  static const char_T e_u[10] = {'V', 'e', 'l', 'o', 'c',
                                 'i', 'd', 'a', 'd', 'e'};
  static const char_T c_u[9] = {'V', 'a', 'r', 'i', 'a', 'b', 'l', 'e', 's'};
  static const char_T d_u[5] = {'A', 'c', 'c', 'e', 'l'};
  static const char_T *enumNames[4] = {"unset", "continuous", "step", "event"};
  static const char_T b_u[3] = {'R', 'o', 'w'};
  static const char_T *sv[2] = {"Description", "UserData"};
  emxArray_real_T *g_u;
  const mxArray *c_propValues[10];
  const mxArray *b_propValues[5];
  const mxArray *propValues[2];
  const mxArray *ab_y;
  const mxArray *b_y;
  const mxArray *bb_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m10;
  const mxArray *m11;
  const mxArray *m12;
  const mxArray *m13;
  const mxArray *m14;
  const mxArray *m15;
  const mxArray *m16;
  const mxArray *m17;
  const mxArray *m18;
  const mxArray *m19;
  const mxArray *m2;
  const mxArray *m20;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *m9;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  const mxArray *w_y;
  const mxArray *x_y;
  const mxArray *y;
  const mxArray *y_y;
  real_T *b_pData;
  int32_T iv[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T *pData;
  const char_T *c_propClasses[10] = {
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim",
      "matlab.internal.coder.tabular.private.varNamesDim"};
  const char_T *c_propNames[10] = {
      "labels",        "length",        "descrs",    "units",
      "continuity",    "customProps",   "hasDescrs", "hasUnits",
      "hasContinuity", "hasCustomProps"};
  const char_T *d_propClasses[5] = {
      "matlab.internal.coder.table", "matlab.internal.coder.table",
      "matlab.internal.coder.table", "matlab.internal.coder.table",
      "matlab.internal.coder.table"};
  const char_T *d_propNames[5] = {"metaDim", "rowDim", "varDim", "data",
                                  "arrayProps"};
  const char_T *b_propClasses[2] = {
      "matlab.internal.coder.tabular.private.rowNamesDim",
      "matlab.internal.coder.tabular.private.rowNamesDim"};
  const char_T *b_propNames[2] = {"labels", "length"};
  const char_T *propClasses[2] = {
      "matlab.internal.coder.tabular.private.metaDim",
      "matlab.internal.coder.tabular.private.metaDim"};
  const char_T *propNames[2] = {"labels", "length"};
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  y = NULL;
  m = NULL;
  m1 = NULL;
  m2 = NULL;
  m3 = NULL;
  m4 = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance(
                      (const char_T *)"matlab.internal.coder.table"));
  m = NULL;
  b_y = NULL;
  m5 = NULL;
  m6 = NULL;
  emlrtAssign(
      &b_y,
      emlrtCreateClassInstance(
          (const char_T *)"matlab.internal.coder.tabular.private.metaDim"));
  m5 = NULL;
  c_y = NULL;
  iv[0] = 1;
  iv[1] = 2;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  d_y = NULL;
  m7 = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 3, m7, &b_u[0]);
  emlrtAssign(&d_y, m7);
  emlrtSetCell(c_y, 0, d_y);
  e_y = NULL;
  m7 = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 9, m7, &c_u[0]);
  emlrtAssign(&e_y, m7);
  emlrtSetCell(c_y, 1, e_y);
  emlrtAssign(&m5, c_y);
  propValues[0] = m5;
  m6 = NULL;
  f_y = NULL;
  m7 = emlrtCreateDoubleScalar(u->metaDim.length);
  emlrtAssign(&f_y, m7);
  emlrtAssign(&m6, f_y);
  propValues[1] = m6;
  emlrtSetAllProperties((emlrtCTX)sp, &b_y, 0, 2,
                        (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(
      &b_y,
      emlrtConvertInstanceToRedirectSource(
          (emlrtCTX)sp, b_y, 0,
          (const char_T *)"matlab.internal.coder.tabular.private.metaDim"));
  emlrtAssign(&m, b_y);
  b_propValues[0] = m;
  m1 = NULL;
  g_y = NULL;
  m8 = NULL;
  m9 = NULL;
  emlrtAssign(
      &g_y,
      emlrtCreateClassInstance(
          (const char_T *)"matlab.internal.coder.tabular.private.rowNamesDim"));
  m8 = NULL;
  h_y = NULL;
  iv[0] = 0;
  iv[1] = 0;
  emlrtAssign(&h_y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  emlrtAssign(&m8, h_y);
  propValues[0] = m8;
  m9 = NULL;
  i_y = NULL;
  m7 = emlrtCreateDoubleScalar(u->rowDim.length);
  emlrtAssign(&i_y, m7);
  emlrtAssign(&m9, i_y);
  propValues[1] = m9;
  emlrtSetAllProperties((emlrtCTX)sp, &g_y, 0, 2,
                        (const char_T **)&b_propNames[0],
                        (const char_T **)&b_propClasses[0], &propValues[0]);
  emlrtAssign(
      &g_y,
      emlrtConvertInstanceToRedirectSource(
          (emlrtCTX)sp, g_y, 0,
          (const char_T *)"matlab.internal.coder.tabular.private.rowNamesDim"));
  emlrtAssign(&m1, g_y);
  b_propValues[1] = m1;
  m2 = NULL;
  j_y = NULL;
  m10 = NULL;
  m11 = NULL;
  m12 = NULL;
  m13 = NULL;
  m14 = NULL;
  m15 = NULL;
  m16 = NULL;
  m17 = NULL;
  m18 = NULL;
  m19 = NULL;
  emlrtAssign(
      &j_y,
      emlrtCreateClassInstance(
          (const char_T *)"matlab.internal.coder.tabular.private.varNamesDim"));
  m10 = NULL;
  k_y = NULL;
  iv[0] = 1;
  iv[1] = 3;
  emlrtAssign(&k_y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  l_y = NULL;
  m7 = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 5, m7, &d_u[0]);
  emlrtAssign(&l_y, m7);
  emlrtSetCell(k_y, 0, l_y);
  m_y = NULL;
  m7 = emlrtCreateCharArray(2, &iv4[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 10, m7, &e_u[0]);
  emlrtAssign(&m_y, m7);
  emlrtSetCell(k_y, 1, m_y);
  n_y = NULL;
  m7 = emlrtCreateCharArray(2, &iv5[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 12, m7, &f_u[0]);
  emlrtAssign(&n_y, m7);
  emlrtSetCell(k_y, 2, n_y);
  emlrtAssign(&m10, k_y);
  c_propValues[0] = m10;
  m11 = NULL;
  o_y = NULL;
  m7 = emlrtCreateDoubleScalar(u->varDim.length);
  emlrtAssign(&o_y, m7);
  emlrtAssign(&m11, o_y);
  c_propValues[1] = m11;
  m12 = NULL;
  emlrtAssign(&m12, b_emlrt_marshallOut(sp, u->varDim.descrs));
  c_propValues[2] = m12;
  m13 = NULL;
  emlrtAssign(&m13, b_emlrt_marshallOut(sp, u->varDim.units));
  c_propValues[3] = m13;
  m14 = NULL;
  p_y = NULL;
  m20 = NULL;
  emlrtCheckEnumR2012b(
      (emlrtCTX)sp, (const char_T *)"matlab.internal.coder.tabular.Continuity",
      4, (const char_T **)&enumNames[0], &enumValues[0]);
  q_y = NULL;
  m7 = emlrtCreateNumericArray(2, (const void *)&iv6[0], mxINT32_CLASS, mxREAL);
  pData = (int32_T *)emlrtMxGetData(m7);
  *pData = (int32_T)u->varDim.continuity[0];
  pData[1] = (int32_T)u->varDim.continuity[1];
  pData[2] = (int32_T)u->varDim.continuity[2];
  emlrtAssign(&q_y, m7);
  emlrtAssign(&m20, q_y);
  emlrtAssign(&p_y,
              emlrtCreateEnumR2012b(
                  (emlrtCTX)sp,
                  (const char_T *)"matlab.internal.coder.tabular.Continuity",
                  m20));
  emlrtDestroyArray(&m20);
  emlrtAssign(&m14, p_y);
  c_propValues[4] = m14;
  m15 = NULL;
  r_y = NULL;
  emlrtAssign(&r_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  emlrtAssign(&m15, r_y);
  c_propValues[5] = m15;
  m16 = NULL;
  s_y = NULL;
  m7 = emlrtCreateLogicalScalar(u->varDim.hasDescrs);
  emlrtAssign(&s_y, m7);
  emlrtAssign(&m16, s_y);
  c_propValues[6] = m16;
  m17 = NULL;
  t_y = NULL;
  m7 = emlrtCreateLogicalScalar(u->varDim.hasUnits);
  emlrtAssign(&t_y, m7);
  emlrtAssign(&m17, t_y);
  c_propValues[7] = m17;
  m18 = NULL;
  u_y = NULL;
  m7 = emlrtCreateLogicalScalar(u->varDim.hasContinuity);
  emlrtAssign(&u_y, m7);
  emlrtAssign(&m18, u_y);
  c_propValues[8] = m18;
  m19 = NULL;
  v_y = NULL;
  m7 = emlrtCreateLogicalScalar(u->varDim.hasCustomProps);
  emlrtAssign(&v_y, m7);
  emlrtAssign(&m19, v_y);
  c_propValues[9] = m19;
  emlrtSetAllProperties((emlrtCTX)sp, &j_y, 0, 10,
                        (const char_T **)&c_propNames[0],
                        (const char_T **)&c_propClasses[0], &c_propValues[0]);
  emlrtAssign(
      &j_y,
      emlrtConvertInstanceToRedirectSource(
          (emlrtCTX)sp, j_y, 0,
          (const char_T *)"matlab.internal.coder.tabular.private.varNamesDim"));
  emlrtAssign(&m2, j_y);
  b_propValues[2] = m2;
  m3 = NULL;
  w_y = NULL;
  iv[0] = 1;
  iv[1] = 3;
  emlrtAssign(&w_y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  emxInit_real_T(sp, &g_u, 1, true);
  for (i = 0; i < 3; i++) {
    loop_ub = u->data[i].f1->size[0];
    i1 = g_u->size[0];
    g_u->size[0] = u->data[i].f1->size[0];
    emxEnsureCapacity_real_T(g_u, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      g_u->data[i1] = u->data[i].f1->data[i1];
    }
    ab_y = NULL;
    i1 = g_u->size[0];
    m7 = emlrtCreateNumericArray(1, &i1, mxDOUBLE_CLASS, mxREAL);
    b_pData = emlrtMxGetPr(m7);
    i1 = 0;
    for (loop_ub = 0; loop_ub < g_u->size[0]; loop_ub++) {
      b_pData[i1] = g_u->data[loop_ub];
      i1++;
    }
    emlrtAssign(&ab_y, m7);
    emlrtSetCell(w_y, i, ab_y);
  }
  emxFree_real_T(&g_u);
  emlrtAssign(&m3, w_y);
  b_propValues[3] = m3;
  m4 = NULL;
  x_y = NULL;
  emlrtAssign(&x_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  y_y = NULL;
  iv[0] = 1;
  iv[1] = 0;
  m7 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 0, m7, NULL);
  emlrtAssign(&y_y, m7);
  emlrtSetFieldR2017b(x_y, 0, (const char_T *)"Description", y_y, 0);
  bb_y = NULL;
  m7 =
      emlrtCreateNumericArray(2, (const void *)&iv7[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&bb_y, m7);
  emlrtSetFieldR2017b(x_y, 0, (const char_T *)"UserData", bb_y, 1);
  emlrtAssign(&m4, x_y);
  b_propValues[4] = m4;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 5,
                        (const char_T **)&d_propNames[0],
                        (const char_T **)&d_propClasses[0], &b_propValues[0]);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(
                      (emlrtCTX)sp, y, 0,
                      (const char_T *)"matlab.internal.coder.table"));
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return y;
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
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
    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : cell_wrap_4 pMatrix[3]
 * Return Type  : void
 */
static void emxFreeMatrix_cell_wrap_4(cell_wrap_4 pMatrix[3])
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxFreeStruct_cell_wrap_4(&pMatrix[i]);
  }
}

/*
 * Arguments    : cell_wrap_4 *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_cell_wrap_4(cell_wrap_4 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

/*
 * Arguments    : table *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_table(table *pStruct)
{
  emxFreeMatrix_cell_wrap_4(pStruct->data);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : cell_wrap_3 pMatrix[3]
 * Return Type  : void
 */
static void emxInitMatrix_cell_wrap_3(cell_wrap_3 pMatrix[3])
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_3(&pMatrix[i]);
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                cell_wrap_4 pMatrix[3]
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitMatrix_cell_wrap_4(const emlrtStack *sp,
                                      cell_wrap_4 pMatrix[3], boolean_T doPush)
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_4(sp, &pMatrix[i], doPush);
  }
}

/*
 * Arguments    : cell_wrap_3 *pStruct
 * Return Type  : void
 */
static void emxInitStruct_cell_wrap_3(cell_wrap_3 *pStruct)
{
  pStruct->f1.size[0] = 0;
  pStruct->f1.size[1] = 0;
}

/*
 * Arguments    : const emlrtStack *sp
 *                cell_wrap_4 *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_cell_wrap_4(const emlrtStack *sp,
                                      cell_wrap_4 *pStruct, boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->f1, 1, doPush);
}

/*
 * Arguments    : struct0_T *pStruct
 * Return Type  : void
 */
static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  pStruct->Description.size[0] = 0;
  pStruct->Description.size[1] = 0;
}

/*
 * Arguments    : const emlrtStack *sp
 *                table *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_table(const emlrtStack *sp, table *pStruct,
                                boolean_T doPush)
{
  c_emxInitStruct_matlab_internal(&pStruct->varDim);
  emxInitMatrix_cell_wrap_4(sp, pStruct->data, doPush);
  emxInitStruct_struct0_T(&pStruct->arrayProps);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray **plhs
 * Return Type  : void
 */
void KalmanAccelC_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *f;
  table dados;
  real_T dT;
  real_T tamanho;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &f, 2, true);
  emxInitStruct_table(&st, &dados, true);
  /* Marshall function inputs */
  dT = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "dT");
  tamanho = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "tamanho");
  f->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "f", f);
  /* Invoke the target function */
  KalmanAccelC(dT, tamanho, f, &dados);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, &dados);
  emxFreeStruct_table(&dados);
  emxFree_real_T(&f);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void KalmanAccelC_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  KalmanAccelC_xil_terminate();
  KalmanAccelC_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void KalmanAccelC_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void KalmanAccelC_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_KalmanAccelC_api.c
 *
 * [EOF]
 */
