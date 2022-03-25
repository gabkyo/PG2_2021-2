/*
 * File: KalmanAccelC.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

/* Include Files */
#include "KalmanAccelC.h"
#include "KalmanAccelC_data.h"
#include "KalmanAccelC_emxutil.h"
#include "KalmanAccelC_initialize.h"
#include "KalmanAccelC_types.h"
#include "randn.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * kalman 1d com integração
 * incializa
 * xk=[a;v;p]
 *
 * Arguments    : double dT
 *                double tamanho
 *                const emxArray_real_T *f
 *                table *dados
 * Return Type  : void
 */
void KalmanAccelC(double dT, double tamanho, const emxArray_real_T *f,
                  table *dados)
{
  static const signed char b_I[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  static const signed char b[3] = {1, 0, 0};
  static const signed char iv[3] = {1, 0, 0};
  emxArray_real_T *Xk;
  emxArray_real_T *x;
  double A[9];
  double Pk[9];
  double Q[9];
  double b_A[9];
  double dv[9];
  double X_pred[3];
  double Xk_prev[3];
  double w[3];
  double wvar[3];
  double A_tmp;
  double R;
  double d;
  double v;
  double vvar;
  double y;
  int b_A_tmp;
  int b_i;
  int i;
  int i1;
  int k;
  if (!isInitialized_KalmanAccelC) {
    KalmanAccelC_initialize();
  }
  emxInit_real_T(&Xk, 2);
  i = Xk->size[0] * Xk->size[1];
  Xk->size[0] = 3;
  i1 = (int)tamanho;
  Xk->size[1] = (int)tamanho;
  emxEnsureCapacity_real_T(Xk, i);
  Xk_prev[0] = 0.0;
  A[0] = 1.0;
  Xk_prev[1] = 0.0;
  A[3] = 0.0;
  Xk_prev[2] = 0.0;
  A[6] = 0.0;
  A[1] = dT;
  A[4] = 1.0;
  A[7] = 0.0;
  A_tmp = dT * dT;
  A[2] = A_tmp / 2.0;
  A[5] = dT;
  A[8] = 1.0;
  memset(&Pk[0], 0, 9U * sizeof(double));
  vvar = 0.0039239999999999995 * sqrt(dT);
  wvar[0] = vvar;
  wvar[1] = vvar * dT;
  wvar[2] = vvar * A_tmp / 2.0;
  for (k = 0; k < 3; k++) {
    Pk[k + 3 * k] = 1.0;
    Q[3 * k] = vvar * wvar[k];
    Q[3 * k + 1] = wvar[1] * wvar[k];
    Q[3 * k + 2] = wvar[2] * wvar[k];
  }
  for (i = 0; i < 9; i++) {
    Q[i] *= dT;
  }
  R = vvar * vvar;
  for (b_i = 0; b_i < i1; b_i++) {
    v = randn() * vvar;
    b_randn(w);
    /* predicao */
    for (i = 0; i < 3; i++) {
      A_tmp = w[i] * wvar[i];
      w[i] = A_tmp;
      y = 0.0;
      for (b_A_tmp = 0; b_A_tmp < 3; b_A_tmp++) {
        k = i + 3 * b_A_tmp;
        y += A[k] * Xk_prev[b_A_tmp];
        b_A[k] = (A[i] * Pk[3 * b_A_tmp] + A[i + 3] * Pk[3 * b_A_tmp + 1]) +
                 A[i + 6] * Pk[3 * b_A_tmp + 2];
      }
      X_pred[i] = y + A_tmp;
    }
    for (i = 0; i < 3; i++) {
      A_tmp = b_A[i];
      y = b_A[i + 3];
      d = b_A[i + 6];
      for (b_A_tmp = 0; b_A_tmp < 3; b_A_tmp++) {
        k = i + 3 * b_A_tmp;
        Pk[k] =
            ((A_tmp * A[b_A_tmp] + y * A[b_A_tmp + 3]) + d * A[b_A_tmp + 6]) +
            Q[k];
      }
    }
    /* atualização */
    A_tmp = 0.0;
    for (i = 0; i < 3; i++) {
      A_tmp += ((Pk[3 * i] + 0.0 * Pk[3 * i + 1]) + 0.0 * Pk[3 * i + 2]) *
               (double)iv[i];
    }
    y = A_tmp + R;
    A_tmp = 0.0;
    for (i = 0; i < 3; i++) {
      Xk_prev[i] = ((Pk[i] + Pk[i + 3] * 0.0) + Pk[i + 6] * 0.0) / y;
      A_tmp += (double)b[i] * X_pred[i];
    }
    A_tmp = (f->data[b_i] - A_tmp) - v;
    for (i = 0; i < 3; i++) {
      Xk->data[i + 3 * b_i] = X_pred[i] + Xk_prev[i] * A_tmp;
      k = b[i];
      b_A[3 * i] = (double)b_I[3 * i] - Xk_prev[0] * (double)k;
      b_A_tmp = 3 * i + 1;
      b_A[b_A_tmp] = (double)b_I[b_A_tmp] - Xk_prev[1] * (double)k;
      b_A_tmp = 3 * i + 2;
      b_A[b_A_tmp] = (double)b_I[b_A_tmp] - Xk_prev[2] * (double)k;
    }
    for (i = 0; i < 3; i++) {
      A_tmp = b_A[i];
      y = b_A[i + 3];
      d = b_A[i + 6];
      for (b_A_tmp = 0; b_A_tmp < 3; b_A_tmp++) {
        dv[i + 3 * b_A_tmp] =
            (A_tmp * Pk[3 * b_A_tmp] + y * Pk[3 * b_A_tmp + 1]) +
            d * Pk[3 * b_A_tmp + 2];
      }
    }
    for (i = 0; i < 3; i++) {
      A_tmp = dv[i];
      y = dv[i + 3];
      d = dv[i + 6];
      for (b_A_tmp = 0; b_A_tmp < 3; b_A_tmp++) {
        Pk[i + 3 * b_A_tmp] = (A_tmp * b_A[b_A_tmp] + y * b_A[b_A_tmp + 3]) +
                              d * b_A[b_A_tmp + 6];
      }
    }
    for (i = 0; i < 3; i++) {
      b_A[3 * i] = Xk_prev[0] * R * Xk_prev[i];
      b_A[3 * i + 1] = Xk_prev[1] * R * Xk_prev[i];
      b_A[3 * i + 2] = Xk_prev[2] * R * Xk_prev[i];
    }
    for (i = 0; i < 9; i++) {
      Pk[i] += b_A[i];
    }
    Xk_prev[0] = Xk->data[3 * b_i];
    Xk_prev[1] = Xk->data[3 * b_i + 1];
    Xk_prev[2] = Xk->data[3 * b_i + 2];
    /* anteriores */
  }
  emxInit_real_T(&x, 2);
  i = x->size[0] * x->size[1];
  x->size[0] = Xk->size[1];
  x->size[1] = 3;
  emxEnsureCapacity_real_T(x, i);
  k = Xk->size[1];
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < k; i1++) {
      x->data[i1 + x->size[0] * i] = Xk->data[i + 3 * i1];
    }
  }
  emxFree_real_T(&Xk);
  k = x->size[0];
  i = dados->data[0].f1->size[0];
  dados->data[0].f1->size[0] = x->size[0];
  emxEnsureCapacity_real_T(dados->data[0].f1, i);
  for (i = 0; i < k; i++) {
    dados->data[0].f1->data[i] = x->data[i];
  }
  k = x->size[0];
  i = dados->data[1].f1->size[0];
  dados->data[1].f1->size[0] = x->size[0];
  emxEnsureCapacity_real_T(dados->data[1].f1, i);
  for (i = 0; i < k; i++) {
    dados->data[1].f1->data[i] = x->data[i + x->size[0]];
  }
  k = x->size[0];
  i = dados->data[2].f1->size[0];
  dados->data[2].f1->size[0] = x->size[0];
  emxEnsureCapacity_real_T(dados->data[2].f1, i);
  for (i = 0; i < k; i++) {
    dados->data[2].f1->data[i] = x->data[i + x->size[0] * 2];
  }
  dados->rowDim.length = x->size[0];
  dados->varDim.length = 3.0;
  dados->varDim.hasUnits = false;
  dados->varDim.units[0].f1.size[0] = 1;
  dados->varDim.units[0].f1.size[1] = 0;
  dados->varDim.units[1].f1.size[0] = 1;
  dados->varDim.units[1].f1.size[1] = 0;
  dados->varDim.units[2].f1.size[0] = 1;
  dados->varDim.units[2].f1.size[1] = 0;
  dados->varDim.hasDescrs = false;
  dados->varDim.descrs[0].f1.size[0] = 1;
  dados->varDim.descrs[0].f1.size[1] = 0;
  dados->varDim.descrs[1].f1.size[0] = 1;
  dados->varDim.descrs[1].f1.size[1] = 0;
  dados->varDim.descrs[2].f1.size[0] = 1;
  dados->varDim.descrs[2].f1.size[1] = 0;
  dados->varDim.hasContinuity = false;
  dados->varDim.continuity[0] = unset;
  dados->varDim.continuity[1] = unset;
  dados->varDim.continuity[2] = unset;
  dados->varDim.hasCustomProps = false;
  dados->metaDim.length = 2.0;
  dados->arrayProps.Description.size[0] = 1;
  dados->arrayProps.Description.size[1] = 0;
  emxFree_real_T(&x);
}

/*
 * File trailer for KalmanAccelC.c
 *
 * [EOF]
 */
