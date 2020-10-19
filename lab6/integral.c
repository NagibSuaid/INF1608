#include "integral.h"
#include <math.h>

double derivada (double (*f) (double x), double x, double h)
{
    double nom=f(x+h)-f(x-h);
    double denom= 2*h;

    return nom/denom;
}

double h_otimo (double (*f) (double x), double (*fl) (double x), double x)
{
    double menor_erro = INFINITY;
    double melhor_h = NAN;
    double h=1e-1;
    for(double i=1; i<=12; i++,h/=10.0)
    {
        double erro = fabs(derivada(f,x,h)-fl(x));
        if(erro<menor_erro)
        {
            menor_erro=erro;
            melhor_h=h;
        }
    }
    return melhor_h;
}

double richardson (double (*f) (double x), double x, double h)
{
    return (((4*derivada(f,x,h/2.0))-derivada(f,x,h))/3.0);
}

double trapezio (double (*f) (double), double a, double b, int n)
{
    double h=(b-a)/n;
    double total = 0.0;
    for(int i=0; i<n; i++)
    {
        total+=(h/2.0)*( f(a+(i*h)) + f(a+((i+1)*h)) );
    }
    return total;
}

double simpson (double (*f) (double), double a, double b, int n)
{
    double h=(b-a)/n;
    double total = 0.0;
    for(int i=0; i<n; i++)
    {
        total+=(h/6.0)*(f(a+i*h) +
                       (4*f(a+(i+0.5)*h)) +
                       (f(a+(i+1)*h)) );
    }
    return total;
}