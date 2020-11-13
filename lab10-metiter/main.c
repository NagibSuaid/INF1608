#include "metiter.h"
#include <stdio.h>
#include "stdlib.h"


#define TOL 1.0e-7
#define RELAX 1.1
int main()
{

    
    do
    {   
        double A0[2] = {3,1};
        double A1[2] = {1,2};
        double **A = malloc(2*sizeof(double*));
        A[0]=A0;
        A[1]=A1;
        
        double x[2] = {0,0};

        double b[2] = {5,5};

        printf("\n--Jacobi--Problema 1--\n");
        int iters = Jacobi(2,A,b,x,TOL);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: [%g , %g] \n",x[0],x[1]);

        for(int i=0;i<2;i++)
        {
            x[i]=0;
        }

        printf("\n--GaussSeidel--Problema 1--\n");
        iters = GaussSeidel(2,A,b,x,TOL);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: [%g , %g] \n",x[0],x[1]);

        for(int i=0;i<2;i++)
        {
            x[i]=0;
        }

        printf("\n--SOR--Problema 1--\n");
        iters = SOR(2,A,b,x,TOL,RELAX);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: [%g , %g] \n",x[0],x[1]);

        free(A);
    }while(0);

    

    do
    {   
        double A0[6] = {3,-1,0,0,0,0.5};
        double A1[6] = {-1,3,-1,0,0.5,0};
        double A2[6] = {0,-1,3,-1,0,0};
        double A3[6] = {0,0,-1,3,-1,0};
        double A4[6] = {0,0.5,0,-1,3,-1};
        double A5[6] = {0.5,0,0,0,-1,3};
        double **A = malloc(6*sizeof(double*));
        A[0]=A0;
        A[1]=A1;
        A[2]=A2;
        A[3]=A3;
        A[4]=A4;
        A[5]=A5;
        
        double x[6] = {0,0,0,0,0,0};

        double b[6] = {2.5,1.5,1,1,1.5,2.5};

        printf("\n--Jacobi--Problema 2--\n");
        int iters = Jacobi(6,A,b,x,TOL);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: \n");
        printf("[");
        for(int i=0; i<6;i++)
        {
            printf("%g, ",x[i]);
        }
        printf("]\n");


        for(int i=0;i<6;i++)
        {
            x[i]=0;
        }

        printf("\n--GaussSeidel--Problema 2--\n");
        iters = GaussSeidel(6,A,b,x,TOL);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: \n");
        printf("[");
        for(int i=0; i<6;i++)
        {
            printf("%g, ",x[i]);
        }
        printf("]\n");


        for(int i=0;i<6;i++)
        {
            x[i]=0;
        }


        printf("\n--SOR--Problema 2--\n");
        iters = SOR(6,A,b,x,TOL,RELAX);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: \n");
        printf("[");
        for(int i=0; i<6;i++)
        {
            printf("%g, ",x[i]);
        }
        printf("]\n");


        for(int i=0;i<6;i++)
        {
            x[i]=0;
        }

        free(A);
    }while(0);

    do
    {   
        double A0[6] = {3,-1,0,0,0,0.5};
        double A1[6] = {-1,3,-1,0,0.5,0};
        double A2[6] = {0,-1,3,-1,0,0};
        double A3[6] = {0,0,-1,3,-1,0};
        double A4[6] = {0,0.5,0,-1,3,-1};
        double A5[6] = {0.5,0,0,0,-1,3};
        double **A = malloc(6*sizeof(double*));
        A[0]=A5;
        A[1]=A1;
        A[2]=A2;
        A[3]=A3;
        A[4]=A4;
        A[5]=A0;
        
        double x[6] = {0,0,0,0,0,0};

        double b[6] = {2.5,1.5,1,1,1.5,2.5};

        printf("\n--Jacobi--Linhas Trocadas--\n");
        int iters = Jacobi(6,A,b,x,TOL);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: \n");
        printf("[");
        for(int i=0; i<6;i++)
        {
            printf("%g, ",x[i]);
        }
        printf("]\n");


        for(int i=0;i<6;i++)
        {
            x[i]=0;
        }

        printf("\n--GaussSeidel--Linhas Trocadas--\n");
        iters = GaussSeidel(6,A,b,x,TOL);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: \n");
        printf("[");
        for(int i=0; i<6;i++)
        {
            printf("%g, ",x[i]);
        }
        printf("]\n");


        for(int i=0;i<6;i++)
        {
            x[i]=0;
        }


        printf("\n--SOR--Linhas Trocadas--\n");
        iters = SOR(6,A,b,x,TOL,RELAX);
        printf("iteracoes: %d\n",iters);
        printf("solucao encontrada: \n");
        printf("[");
        for(int i=0; i<6;i++)
        {
            printf("%g, ",x[i]);
        }
        printf("]\n");


        for(int i=0;i<6;i++)
        {
            x[i]=0;
        }

        free(A);
    }while(0);

    return 0;
}