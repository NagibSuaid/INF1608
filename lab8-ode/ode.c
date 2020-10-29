#include <math.h>
#include "ode.h"

static double RungeKuttaStep(double t, double h,double y, double (*f) (double t, double y))
{
    double k1=h*f(t,y);
    double k2=h*f(t+h/2,y+k1/2);
    double k3=h*f(t+h/2,y+k2/2);
    double k4=h*f(t+h,y+k3);
    return y+(k1+2*k2+2*k3+k4)/6.0;
}

double RungeKutta (double t0, double t1, double h, double y0,
double (*f) (double t, double y))
{
    double t=t0;
    double y=y0;
    while( (t1-t) >= h/2 )
    {
        y=RungeKuttaStep(t,h,y,f);
        t=t+h;
    }
    return y;
}

double RungeKuttaAdapt (double t0, double t1, double y0,
double (*f) (double t, double y), double tol)
{
    double t=t0;
    double y=y0;
    double h=1.0e-7;
    while( (t1-t) >= 0.0 )
    {
        double y1=RungeKuttaStep(t,h,y,f);
        double y2=RungeKuttaStep(t+h/2,h/2,RungeKuttaStep(t,h/2,y,f),f);
        double erro=(y2-y1)/15;
        double fator=pow((tol/fabs(erro)),1.0/5.0);
        if(fator>=1)//passo validado
        {
            t+=h;
            if(fator<1.2)
            {
                h*=fator;
            }
            else
            {
                h*=1.2;
            }

            y=y2+erro;
        }
        else//passo rejeitado
        {
            h*=0.8*fator;
        }
       
    }
    return y;
}