#include "matriz.h"
#include <math.h>
#include <stdlib.h>


// cria (aloca) um vetor de dimensão n, retornando seu ponteiro
double* criavet (int n)
{
    return (double*) malloc(n * sizeof(double));
}

// libera (a memória) de um vetor previamente criado
void liberavet (double* v)
{
    free(v);
}

// calcula e retorna o produto escalar entre dois vetores de dimensão n
double prodescalar (int n, const double* v, const double* w)
{

    double prod=0;
    for(int i=0;i<n;i++)
    {
        prod+=v[i]*w[i];
    }

    return prod;
}

// calcula e retorna a norma-2 de um vetor de dimensão n
double norma2 (int n, const double* v)
{

    double norma2=0;
    for(int i=0;i<n;i++)
    {
        norma2+=v[i]*v[i];
    }

    return sqrt(norma2);
}

// calcula a produto de um vetor v por um escalar s;
// o resultado deve ser armazenado no vetor w, previamente criado
void multvs (int n, const double* v, double s, double *w)
{
    for(int i=0;i<n;i++)
    {
        w[i]=s*v[i];
    }
    return;
}


// cria (aloca) uma matriz de dimensão m x n, retornando seu ponteiro;
// a matriz é representado por vetor de vetores linha
double** criamat (int m, int n)
{
    double** mat = (double**)malloc(m*sizeof(double*));
    double* vet = (double*)malloc(m*n*sizeof(double));
    for(int i=0;i<m;i+=1)
    {
        mat[i]=&vet[i*n];
    }
    return mat;
}

// cria (aloca) uma matriz triangular inferior de dimensão m x m;
// a matriz é representado por vetor de vetores linha:
// o primeiro vetor linha tem dimensão 1, o segundo 2, e assim por diante
double** criamattri (int m)
{
    double** mat = (double**)malloc(m*sizeof(double*));
    double* vet = (double*)malloc((((m+1)*m)/2.0) * sizeof(double));

    int mem=0;
    for(int i=0;i<m;i+=1)
    {
        mat[i]=&vet[mem+i];
        mem+=i;
    }
    return mat;
}

// libera (a memória) de uma matriz previamente criada
void liberamat (int m, double** A)
{
    free(A[0]);
    free(A);
}

// preenche a matriz transposta de A em T, previamente criada;
// A tem dimensão m x n; T tem dimensão n x m
void transposta (int m, int n, const double** A, double** T)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            T[j][i]=A[i][j];
        }
    }
}

// calcula o produto de uma matriz A (m x n) por um vetor v (m),
// resultando no vetor w (m), previamente criado
void multmv (int m, int n, const double** A, const double* v, double* w)
{
    for(int i=0;i<m;i++)
    {
        double acc=0;
        for(int j=0;j<n;j++)
        {
           acc+=A[i][j] * v[j];
        }
        w[i]=acc;
    }
}

// calcula o produto de uma matriz A (m x n) por uma matriz B (n x q),
// armazenando o resultado na matriz C (m x q), previamente criada
void multmm (int m, int n, int q, const double** A, const double** B, double** C)
{
 
    for (int i=0;i<m;i++)
    {
        for(int k=0;k<q;k++)
        {

            double acc=0;
            for(int j=0;j<n;j++)
            {
               acc+=A[i][j] * B[j][k];
            }            
            C[i][k]=acc;
        }
    }

}