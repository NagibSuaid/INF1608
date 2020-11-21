#ifndef IMPORTED_GRADCONJ
#define IMPORTED_GRADCONJ

int GradConj (int n, double** A, double* b, double* x, double tol);

int GradConjPreCond (int n, double** A, double* b, double* x, double tol);

#endif