#include "matriz.h"
#include <math.h>

int GradConj (int n, double** A, double* b, double* x, double tol)
{
    double *d = criavet(n);
    double *r = criavet(n);
    int iters = 0;

    double* Ax = criavet(n);
    multmv(n,n,A,x,Ax);
    for(int i=0; i<n; i++)
    {
        double vi = b[i]-Ax[i];
        d[i]=vi;
        r[i]=vi;
    }
    
    double last_rTr = 0;
    for(int i=0; i<n; i++)
    {
        last_rTr+=r[i]*r[i];
    }

    for(int i=0; i<n; i++)
    {
        
        if(norma2(n,r)<tol)
        {
            break;
        }

    
        multmv(n,n,A,d,Ax);
        double dTAd = 0;
        for(int i=0; i<n; i++)
        {
            dTAd+=d[i]*Ax[i];
        }

        double alpha = last_rTr/dTAd;

        for(int i=0; i<n; i++)
        {
            x[i]+=alpha * d[i];
            r[i]-=alpha * Ax[i];
        }

        double rTr =0;
        for(int i=0; i<n; i++)
        {
            rTr+=r[i]*r[i];
        }

        double beta = rTr / last_rTr;

        for(int i=0; i<n; i++)
        {
            d[i] = r[i] + beta * d[i];
        }

        last_rTr = rTr;
        iters+=1;
    }


    liberavet(d);
    liberavet(r);
    liberavet(Ax);
    return iters;
}

int GradConjPreCond (int n, double** A, double* b, double* x, double tol)
{
    double *d = criavet(n);
    double *r = criavet(n);
    double *z = criavet(n);
    int iters = 0;

    double* Ax = criavet(n);
    multmv(n,n,A,x,Ax);
    for(int i=0; i<n; i++)
    {
        r[i]=b[i]-Ax[i];
        d[i]=r[i]/A[i][i];
        z[i]=d[i];
    }
    
    double last_rTz = 0;
    for(int i=0; i<n; i++)
    {
        last_rTz+=r[i]*z[i];
    }

    for(int i=0; i<n; i++)
    {
        
        if(norma2(n,r)<tol)
        {
            break;
        }

    
        multmv(n,n,A,d,Ax);
        double dTAd = 0;
        for(int i=0; i<n; i++)
        {
            dTAd+=d[i]*Ax[i];
        }

        double alpha = last_rTz/dTAd;

        for(int i=0; i<n; i++)
        {
            x[i]+=alpha * d[i];
            r[i]-=alpha * Ax[i];
            z[i]/=A[i][i];
        }

        double rTz =0;
        for(int i=0; i<n; i++)
        {
            rTz+=r[i]*z[i];
        }

        double beta = rTz / last_rTz;

        for(int i=0; i<n; i++)
        {
            d[i] = z[i] + beta * d[i];
        }

        last_rTz = rTz;
        iters+=1;
    }


    liberavet(d);
    liberavet(r);
    liberavet(z);
    liberavet(Ax);
    return iters;
}