#include "simpson.h"
#include <math.h>


static double simpson(double a, double b, double (*f) (double x))
{
    double h=(b-a);
    double total;

    total = (h/6.0)*
            (
                f(a) +
                (4*f((a+b)/2.0)) +
                f(b)
            );
    return total;
}

double adaptsimpson (double a, double b, double (*f) (double x), double tol)
{
    double c=(a+b)/2.0;
    double Sac=simpson(a,c,f);
    double Scb=simpson(c,b,f);
    double Sab=simpson(a,b,f);
    double delta=Sab-(Sac+Scb);
    if(fabs(delta/15.0)>tol)
    {
        return adaptsimpson(a,c,f,tol/2.0) + adaptsimpson(c,b,f,tol/2.0);
    }
    else
    {
        return Sac+Scb-(delta/15.0);
    }
}

static double fexp(double x)
{
    return exp((x*x)/2);
}

double probabilidade (double sigma)
{
    return (1/sqrt(2*M_PI))*adaptsimpson(-1*sigma,sigma,fexp,5e-9);
}

double quadraturagauss (double a, double b, double (*f) (double x))
{
    double raizes[4]={
            -1*sqrt((15+2*sqrt(30))/35.0),
            -1*sqrt((15-2*sqrt(30))/35.0),
             1*sqrt((15-2*sqrt(30))/35.0),
             1*sqrt((15+2*sqrt(30))/35.0)};

    double coefs[4]={
            (90-5*sqrt(30))/180.0,
            (90+5*sqrt(30))/180.0,
            (90+5*sqrt(30))/180.0,
            (90-5*sqrt(30))/180.0,
    };
    double total=0.0;
    for(int i=0; i<4; i++)
    {
        total+=coefs[i]*(f( ((b-a)*raizes[i]+b+a)/2.0 )*((b-a)/2.0));
    }
    return total;
}

double probabilidade2 (double sigma)
{
    return (1/sqrt(2*M_PI))*quadraturagauss(-1*sigma,sigma,fexp);
}