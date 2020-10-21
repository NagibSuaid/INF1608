#ifndef IMPORT_SIMPSON
#define IMPORT_SIMPSON

#ifndef M_PI
#define M_PI 3.14159265358979323846  
#endif

double adaptsimpson (double a, double b, double (*f) (double x), double tol);

double probabilidade (double sigma);

double quadraturagauss (double a, double b, double (*f) (double x));

double probabilidade2 (double sigma);

#endif