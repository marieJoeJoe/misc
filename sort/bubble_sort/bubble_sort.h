#ifndef __EIGENV_H__
#define __EIGENV_H__

#define DBL_EPSILON 2.2204460492503131e-16

void   Multiply_Matrix_by_Vector(double u[], double *A, int nrows, int ncols, double v[]);
double Inner_Product(double u[], double v[], int n);
double Vector_L2_Norm(double v[], int n);
void   Divide_Vector_by_Scalar(double v[], double x, int n);

#endif
