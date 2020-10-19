#include "raiz.h"
#include "stdio.h"
#include <math.h>

#define TOL 0.0000000000000001

int bissecao (double a, double b, int p, double (*f) (double x), double* r)
{
    double fa=f(a);
    double c = (a+b)/2.0;
    double fc;
    double max_error = 0.5*pow(10,-p);
    int iters = ceil(log2(fabs(b-a)/max_error))-1;
    int i;
    
    for(i=0; i<iters; i++)
    {
        fc = f(c);
        if(fabs(fc) < TOL)
        {
            break;
        }

        if((fa*fc) < 0)
        {
            b=c;
        }
        else
        {
            a=c;
            fa=fc;
        }
        c=(a+b)/2.0;

    }
    *r=(a+b)/2.0;
    return i+1;
}


int IQI (double x0, double x1, int p, double (*f) (double x), double* r)
{
    double x2 = (x0+x1)/2.0;
    double tol = 0.5*pow(10,-p);
    double fx0 = f(x0);
    double fx1 = f(x1);
    double fx2 = f(x2);
    int calls = 3;
    do
    {
        if(calls>=53)
        {
            /*Alg nao convergiu*/
            return 0;
        }

    double x3 = 0.0;
    /*Formula de interpolação de Lagrange*/
    x3+= (fx1*fx2*x0)/((fx0-fx1)*(fx0-fx2));
    x3+= (fx0*fx2*x1)/((fx1-fx0)*(fx1-fx2));
    x3+= (fx0*fx1*x2)/((fx2-fx0)*(fx2-fx1));

    double fx3 = f(x3);
    calls+=1;

    /*Cicla iteracoes anteriores*/
    x0=x1;
    fx0=fx1;

    x1=x2;
    fx1=fx2;

    x2=x3;
    fx2=fx3;

    } while (fabs(fx2)>=tol);

    *r=x2;
    return calls;
}
