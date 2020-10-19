#include <math.h>
#include "matriz.h"


/*Funcoes auxiliares: */

static void swap_rows(int n, double**M, int a, int b);

static void swap_rows(int n, double**M, int a, int b)
{
    for(int j=0; j<n; j++)
    {
        double aux=M[a][j];
        M[a][j]=M[b][j];
        M[b][j]=aux;
    }
}

void gauss (int n, double** A, double* b, double* x)
{
    for(int col=0;col<n-1;col++)
    {

        int pivot=col;
        for(int k=col+1; k<n; k++)
        {
            if(fabs(A[k][col])>fabs(A[pivot][col]))
            {
                pivot=k;
            }
        }
        swap_rows(n,A,col,pivot);
        double aux=b[col];
        b[col]=b[pivot];
        b[pivot]=aux;

        for(int row=col+1; row<n; row++)
        {
            double factor = A[row][col]/A[col][col];
            A[row][col]=0.0;
            for(int k=col+1; k<n; k++)
            {
                A[row][k]-=factor*A[col][k];
            }
            b[row]-=b[col]*factor;
        }
    }
    
    for(int i=n-1; i>=0; i--)
    {
        double s=0.0;
        for(int j=i+1; j<n; j++)
        {
            s+=A[i][j]*x[j];
        }
        x[i]=(b[i]-s)/A[i][i];
    }

}

void cholesky (int n, double** A)
{
    for(int k=0; k<n; k++)
    {
        A[k][k]=sqrt(A[k][k]);
        for(int i=k+1; i<n; i++)
        {
            A[i][k] = A[i][k]/A[k][k];
        }
        for(int i=k+1; i<n; i++)
        {
            for(int j=k+1; j<=i; j++)
            {
                A[i][j]-= A[i][k]*A[j][k];
            }
        }
    }
}

void substituicoes (int n, double** A, double* b, double* x)
{
    double* y = criavet(n);

    //Solving Ay=b;
    for(int i=0; i<n; i++)
    {
        double s=0.0;
        for(int j=0; j<i; j++)
        {
            s+=A[i][j]*y[j];
        }
        y[i]=(b[i]-s)/A[i][i];
    }

    //Solving A^tx=y
    for(int i=n-1; i>=0; i--)
    {
        double s=0.0;
        for(int j=n-1; j>i; j--)
        {
            s+=A[j][i]*x[j];
        }
        x[i]=(y[i]-s)/A[i][i];
    }

    liberavet(y);
}
