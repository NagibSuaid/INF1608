#include "interp.h"
#include "matriz.h"
#include <math.h>

#define PI 3.14159265358979323846

void regular (int n, double a, double b, double* xi)
{
    xi[0]=a;
    xi[n-1]=b;
    double step=(b-a)/(n-1);

    for(int i=1; i<n-1; i++)
    {
        xi[i]=xi[i-1]+step;
    }
}

void chebyshev (int n, double a, double b, double* xi)
{
    double aplusbon2 = (a+b)/2.0;
    double bminusaon2 = (b-a)/2.0;
    for(int i=0, beta=1;i<n;i++, beta+=2)
    {
        xi[i]=aplusbon2;
        xi[i]+= (cos(beta* PI/(2*(n+1)))) * bminusaon2;

    }
}

static double diferenca(int i, int j, double (*f) (double), double* xi, double **cache)
{
    //cache[j][i] ===>  F[Xi...Xj]
    if(isnan(cache[j][i]))
    {
        if(i==j)
        {
            cache[j][i]=f(xi[i]);
        }
        else
        {
            double dif1 = diferenca(i+1,j,f,xi,cache);
            double dif2 = diferenca(i,j-1,f,xi,cache);
            cache[j][i] =( (dif1) - (dif2) ) / (xi[j]-xi[i]);
        }
    }

    return cache[j][i];
    
}

void coeficientes (int n, double* xi, double (*f) (double), double* bi)
{
    
    double **cache = criamattri(n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cache[i][j]=NAN;
        }
    }

    for(int i=0; i<n; i++)
    {
        bi[i]=diferenca(0,i,f,xi,cache);
    }

    liberamat(n, cache);
}

double avalia (int n, double* xi, double* bi, double x)
{
    double fator = 1.0;
    double total = 0.0;

    for(int i=0;i<n;i++)
    {
        total+=bi[i] * fator;
        fator*=(x - xi[i]);
    }
    return total;
}
