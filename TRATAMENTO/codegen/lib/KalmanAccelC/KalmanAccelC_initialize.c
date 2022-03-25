/*
 * File: KalmanAccelC_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

/* Include Files */
#include "KalmanAccelC_initialize.h"
#include "KalmanAccelC_data.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void KalmanAccelC_initialize(void)
{
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_KalmanAccelC = true;
}

/*
 * File trailer for KalmanAccelC_initialize.c
 *
 * [EOF]
 */
