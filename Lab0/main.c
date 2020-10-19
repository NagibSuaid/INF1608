#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main()
{
    double* vet1 = criavet(10);
    double* vet2 = criavet(10);
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        double r = randfrom(-100,100);
        vet1[i]=r*r;
        vet2[i]=r;
    }
    double prodEscalar=0;
    for(int i=0;i<10;i++)
    {
        prodEscalar+= vet2[i]* vet2[i]* vet2[i];
    }
    printf("Produto escalar:\nEsperado=%g\nObtido  =%g\n",
    prodEscalar,prodescalar(10,vet1,vet2));
    printf("-------------------------------------------\n");
}