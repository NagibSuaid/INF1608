#include "mmq.h"
#include "matriz.h"
#include "sistlinear.h"
#include "math.h"

double MMQ (int m, int n, double** A, double* b, double* x)
{
    double** AT = criamat(n,m);
    transposta(m,n,(const double**)A,AT);

    double** ATA = criamat(n,n);
    multmm(n,m,n,(const double**)AT,(const double**)A,ATA);

    double*ATb = criavet(n);
    multmv(n,m,(const double**)AT,(const double*)b,ATb);
    liberamat(n,AT);

    gauss(n,ATA,ATb,x);
    liberamat(n,ATA);
    liberavet(ATb);

    double* obtido = criavet(m);
    multmv(m,n,(const double**)A,(const double*)x,obtido);
    double* residuo = criavet(m);
    for(int i=0; i<m; i++)
    {
        residuo[i]=b[i]-obtido[i];
    }
    liberavet(obtido);

    double erro = norma2(m,(const double*)residuo); 
    liberavet(residuo);

    return erro;
}


double periodico (int n, double* t, double* v, double* c)
{
    double **A = criamat(n,6);
    for(int i=0; i<n; i++)
    {
        A[i][0]=1.0;
        A[i][1]=t[i];
        A[i][2]=sin(2*M_PI*t[i]);
        A[i][3]=cos(2*M_PI*t[i]);
        A[i][4]=sin(4*M_PI*t[i]);
        A[i][5]=cos(4*M_PI*t[i]);
    }
    double erro = MMQ(n,6,A,v,c);
    liberamat(n,A);
    return erro;
}

double previsao (double* c, double t)
{
    return (
        (c[0])+
        (c[1]*t)+
        (c[2]*sin(2*M_PI*t))+
        (c[3]*cos(2*M_PI*t))+
        (c[4]*sin(4*M_PI*t))+
        (c[5]*cos(4*M_PI*t))
    );
}