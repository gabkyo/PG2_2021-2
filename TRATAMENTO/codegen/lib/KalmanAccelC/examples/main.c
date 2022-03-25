/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Mar-2022 13:26:23
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "KalmanAccelC.h"
#include "KalmanAccelC_emxAPI.h"
#include "KalmanAccelC_terminate.h"
#include "KalmanAccelC_types.h"

/* Function Declarations */
static emxArray_real_T *argInit_1xUnbounded_real_T(void);

static double argInit_real_T(void);

static void main_KalmanAccelC(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_1xUnbounded_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;
  /* Set the size of the array.
Change this size to the value that the application requires. */
  result = emxCreate_real_T(1, 2);
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result->data[idx1] = argInit_real_T();
    }
  }
  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_KalmanAccelC(void)
{
  emxArray_real_T *f;
  table dados;
  double dT_tmp;
  emxInit_table(&dados);
  /* Initialize function 'KalmanAccelC' input arguments. */
  dT_tmp = argInit_real_T();
  /* Initialize function input argument 'f'. */
  f = argInit_1xUnbounded_real_T();
  /* Call the entry-point 'KalmanAccelC'. */
  KalmanAccelC(dT_tmp, dT_tmp, f, &dados);
  emxDestroy_table(dados);
  emxDestroyArray_real_T(f);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_KalmanAccelC();
  /* Terminate the application.
You do not need to do this more than one time. */
  KalmanAccelC_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
