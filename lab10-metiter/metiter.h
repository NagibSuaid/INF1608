#ifndef IMPORTED_METITER
#define IMPORTED_METITER

int Jacobi (int n, double** A, double* b, double* x, double tol);

int GaussSeidel (int n, double** A, double* b, double* x, double tol);

int SOR (int n, double** A, double* b, double* x, double tol, double w);

#endif