/*
 * File: randn.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

/* Include Files */
#include "randn.h"
#include "KalmanAccelC_data.h"
#include "eml_rand_mt19937ar.h"

/* Function Definitions */
/*
 * Arguments    : double r[3]
 * Return Type  : void
 */
void b_randn(double r[3])
{
  r[0] = eml_rand_mt19937ar(state);
  r[1] = eml_rand_mt19937ar(state);
  r[2] = eml_rand_mt19937ar(state);
}

/*
 * Arguments    : void
 * Return Type  : double
 */
double randn(void)
{
  return eml_rand_mt19937ar(state);
}

/*
 * File trailer for randn.c
 *
 * [EOF]
 */
