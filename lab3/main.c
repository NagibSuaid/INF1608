#include <math.h>
#include <stdio.h>
#include "matriz.h"
#include "sistlinear.h"

static void showvet(int n, double* v)
{
    for(int i=0;i<n;i++)
    {
        printf("%.3g ",v[i]);
    }
    printf("\n");
}

static void showmattri(int i, double**M)
{
    for(int k=0;k<i;k++)
    {
        showvet(k+1,M[k]);
    }
}


int main()
{
    const double A30[3]={ 1,-1, 0};
    const double A31[3]={-1, 2, 1};
    const double A32[3]={ 0, 1, 2};
    const double* A3[3] = {A30,A31,A32};
 
    double b3[3] = {0,2,3};


    const double A60[6]={3,-1,0,0,0,0.5};
    const double A61[6]={-1,3,-1,0,0.5,0};
    const double A62[6]={0,-1,3,-1,0,0};
    const double A63[6]={0,0,-1,3,-1,0};
    const double A64[6]={0,0.5,0,-1,3,-1};
    const double A65[6]={0.5,0,0,0,-1,3};
    const double* A6[6]={A60,A61,A62,A63,A64,A65};

    double b6[6] = {2.5,1.5,1,1,1.5,2.5};
    

    double* x = criavet(3);

    printf("Gauss/3x3:\n");

    double **copy =criamat(3,3);
    for(int i=0;i<3;i++)
    {
        for(int j=0; j<3;j++)
        {
            copy[i][j]=A3[i][j];
        }
    }

    gauss(3,copy,b3,x);
    showvet(3,x);
    printf("----------------\n");
    multmv(3,3,A3,x,b3);
    showvet(3,b3);
    liberamat(3,copy);

    printf("###################################\n");

    printf("Cholesky/3x3:\n");
    copy=criamattri(3);
    for(int i=0;i<3;i++)
    {
        for(int j=0; j<=i;j++)
        {
            copy[i][j]=A3[i][j];
        }
    }
    cholesky(3,copy);
    showmattri(3,copy);
    printf("----------------\n");
    substituicoes(3,copy,b3,x);
    showvet(3,x);
    printf("----------------\n");
    multmv(3,3,A3,x,b3);
    showvet(3,b3);
    liberamat(3,copy);
    liberamat(3,copy);
    liberavet(x);

    printf("###################################\n");

    x=criavet(6);
    printf("Gauss/6x6:\n");

    copy =criamat(6,6);
    for(int i=0;i<6;i++)
    {
        for(int j=0; j<6;j++)
        {
            copy[i][j]=A6[i][j];
        }
    }

    gauss(6,copy,b6,x);
    showvet(6,x);
    printf("----------------\n");
    multmv(6,6,A6,x,b6);
    showvet(6,b6);
    liberamat(6,copy);

    printf("###################################\n");

    printf("Cholesky/6x6:\n");
    copy=criamattri(6);
    for(int i=0;i<6;i++)
    {
        for(int j=0; j<=i;j++)
        {
            copy[i][j]=A6[i][j];
        }
    }
    cholesky(6,copy);
    showmattri(6,copy);
    printf("----------------\n");
    substituicoes(6,copy,b6,x);
    showvet(6,x);
    printf("----------------\n");
    multmv(6,6,A6,x,b6);
    showvet(6,b6);
    liberamat(6,copy);
    liberavet(x);

    printf("###################################\n");
    return 0;
}