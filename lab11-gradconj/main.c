#include <stdio.h>
#include "gradconj.h"
#include "matriz.h"

#define N 10

int main()
{
    double** A = criamat(N,N);
    double* b = criavet(N);
    double* x = criavet(N);

    for(int i=0; i<N; i++)
    {
        b[i]=0;
        x[i]=0;
        for(int j=0; j<N; j++)
        {
            if(i == j)
            {
                A[i][j] = i+1.0;
            }
            else if(j == i+1 || j== i-1)
            {
                A[i][j] = 0.4;
            }
            else
            {
                A[i][j] = 0.0;
            }
            b[i]+=A[i][j];
        }
    }


    printf("\n--GradConj--\n");
    int iters = GradConj(N,A,b,x,1.0e-7);
    printf("iters: %d\n",iters);
    printf("solucao: [ ");
    for(int i=0; i<N;i++)
    {
        printf("%g, ",x[i]);
    }
    printf("]\n");

    for(int i=0; i<N; i++)
    {
        x[i]=0.0;
    }

    printf("\n--GradConjPreCond--\n");
    iters = GradConjPreCond(N,A,b,x,1.0e-7);
    printf("iters: %d\n",iters);
    printf("solucao: [ ");
    for(int i=0; i<N;i++)
    {
        printf("%g, ",x[i]);
    }
    printf("]\n");

    liberamat(N,A);
    liberavet(b);
    liberavet(x);
    return 0;
}