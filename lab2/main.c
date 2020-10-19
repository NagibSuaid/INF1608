#include "raiz.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define G 9.8
#define C 15
#define T 9

double f1(double x)
{
    return cos(x)-(x*x*x)+x;
}
double f2(double x)
{
    double sinx=sin(x);
    double x3 = x*x*x;
    return exp(sinx*sinx*sinx)+x3*x3-x3*x+x3-1;
}

double vmenos35(double m)
{
    return ((G * m)/C) * (1-exp(-C*T/m)) - 35.0;
}

int main()
{
    double r;

    int its = bissecao(0.0,2.0,7,f1,&r);
    printf("-----*Bi-f1-[0,2]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);
    its = IQI(0.0,2.0,7,f1,&r);
    printf("-----*IQI-f1-[0,2]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);

    its = bissecao(-2.0,-1.0,7,f2,&r);
    printf("-----*Bi-f2-[-2,-1]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);
    its = IQI(-2.0,-1.0,7,f2,&r);
    printf("-----*IQI-f2-[-2,-1]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);

    its = bissecao(-1.0,2.0,7,f2,&r);
    printf("-----*Bi-f2-[-1,2]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);
    its = IQI(-1.0,2.0,7,f2,&r);
    printf("-----*IQI-f2-[-1,2]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);

    its = bissecao(45.0,110.0,7,vmenos35,&r);
    printf("-----*Bi-massa-[45,110]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);
    its = IQI(45.0,110.0,7,vmenos35,&r);
    printf("-----*IQI-massa-[45,110]*-----\nRaiz encontrada: %.7g\nIteracoes: %d\n",r,its);    
}