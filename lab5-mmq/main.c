#include <stdio.h>
#include "mmq.h"
#include "matriz.h"


int main()
{
    double** A = criamat(5,3);
    double* X = criavet(3);
    double* B = criavet(5);

    //2-A-A
    A[0][0]= 3.0; A[0][1]=-1.0; A[0][2]= 2.0;   

    A[1][0]= 4.0; A[1][1]= 1.0; A[1][2]= 0.0;

    A[2][0]=-3.0; A[2][1]= 2.0; A[2][2]= 1.0;

    A[3][0]= 1.0; A[3][1]= 1.0; A[3][2]= 5.0;

    A[4][0]=-2.0; A[4][1]= 0.0; A[4][2]= 3.0;

    B[0]= 10.0;
    B[1]= 10.0;
    B[2]= -5.0;
    B[3]= 15.0;
    B[4]=  0.0;

    double erro = MMQ(5,3,A,B,X);

    printf("\n-----------2-A-A-----------\n");
    printf("Erro encontrado: %g\n",erro);
    printf("Vetor encontrado: [ %g , %g , %g ]\n",X[0],X[1],X[2]);

    liberamat(5,A);
    liberavet(X);
    //Vamos reciclar B

    //2-A-B
    A = criamat(5,4);
    X = criavet(4);

    A[0][0]= 4.0; A[0][1]= 2.0; A[0][2]= 3.0;   A[0][3]= 0.0;

    A[1][0]=-2.0; A[1][1]= 3.0; A[1][2]=-1.0;   A[1][3]= 1.0;

    A[2][0]= 1.0; A[2][1]= 3.0; A[2][2]=-4.0;   A[2][3]= 2.0;

    A[3][0]= 1.0; A[3][1]= 0.0; A[3][2]= 1.0;   A[3][3]=-1.0;

    A[4][0]= 3.0; A[4][1]= 1.0; A[4][2]= 3.0;   A[4][3]=-2.0;

    B[0]= 10.0;
    B[1]=  0.0;
    B[2]=  2.0;
    B[3]=  0.0;
    B[4]=  5.0;

    erro = MMQ(5,4,A,B,X);

    printf("\n-----------2-A-B-----------\n");
    printf("Erro encontrado: %g\n",erro);
    printf("Vetor encontrado: [ %g , %g , %g , %g ]\n",X[0],X[1],X[2],X[3]);

    liberamat(5,A);
    liberavet(X);
    liberavet(B);


    //2-B
    double yearsSince2015[24];
    for(int i=0;i<24; i++)
    {
        yearsSince2015[i]=i/12.0;
    }
    double iceExtents[24] = {
        /*2015*/
        13.75,
        14.51,
        14.49,
        13.98,
        12.69,
        11.05,
        8.83,
        5.66,
        4.68,
        7.79,
        10.11,
        12.33,

        /*2016*/
        13.64,
        14.32,
        14.53,
        13.83,
        12.08,
        10.60,
        8.13,
        5.6,
        4.72,
        6.45,
        9.08,
        12.09
    };
    double c[6];
    printf("\n-----------2-B-------------\n");
    erro=periodico(24,yearsSince2015,iceExtents,c);
    printf("Erro encontrado: %g\n",erro);
    printf("Area de gelo prevista para hoje: %g\n",previsao(c,5+(9.0/17.0)));
    printf("Coeficiente linear (c1) encontrado: %g\n",c[1]);
}