#ifndef IMPORTED_SISTLINEAR
#define IMPORTED_SISTLINEAR

/*preenche o vetor x com a solução do sistema Ax=b
utilizando eliminacao de Gauss com pivotamento*/
void gauss (int n, double** A, double* b, double* x);


void cholesky (int n, double** A);

void substituicoes (int n, double** A, double* b, double* x);

#endif