#ifndef IMPORT_INTERP
#define IMPORT_INTERP

/*Preenche o vet x1 com n amostras entre a e b igualmente espacadas*/
void regular (int n, double a, double b, double* xi);

/*Preenche o vet x1 com n amostras entre a e b com a distribuicao de chebyshev*/
void chebyshev (int n, double a, double b, double* xi);

/*Preenche o vetor bi com os n coeficientes das diferencas divididas de Newton*/
void coeficientes (int n, double* xi, double (*f) (double), double* bi);

/**/
double avalia (int n, double* xi, double* bi, double x);

#endif
