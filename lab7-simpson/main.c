#include<stdio.h>
#include <math.h>
#include "simpson.h"

double f1(double x)
{
    return x/sqrt(x*x+9);
}
double f2(double x)
{
    return exp(-1*x*x);
}
double f3(double x)
{
    return log(cos(x)+sin(x));
}

int main()
{

    printf("Probabilidade com Simpson:     %.9g\n",probabilidade(1));
    printf("Probabilidade com Quadraturas: %.9g\n",probabilidade2(1));
    printf("Integral 1 com Simpson:        %.9g\n",adaptsimpson(0,1,f1,5e-9));
    printf("Integral 1 com Quadraturas:    %.9g\n",quadraturagauss(0,1,f1));
    printf("Integral 2 com Simpson:        %.9g\n",adaptsimpson(0,3,f2,5e-9)*2/sqrt(M_PI));
    printf("Integral 2 com Quadraturas:    %.9g\n",quadraturagauss(0,3,f2)*2/sqrt(M_PI));
    printf("Integral 3 com Simpson:        %.9g\n",adaptsimpson(0,M_PI/2.0,f3,5e-9));
    printf("Integral 3 com Quadraturas:    %.9g\n",quadraturagauss(0,M_PI/2.0,f3));
}