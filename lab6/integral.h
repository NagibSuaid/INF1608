#ifndef IMPORTED_INTEGRAL
#define IMPORTED_INTEGRAL

double derivada (double (*f) (double x), double x, double h);

double h_otimo (double (*f) (double x), double (*fl) (double x), double x);

double richardson (double (*f) (double x), double x, double h);

double trapezio (double (*f) (double), double a, double b, int n);

double simpson (double (*f) (double), double a, double b, int n);


#endif
