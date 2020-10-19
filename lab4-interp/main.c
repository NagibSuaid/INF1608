#include "interp.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double normDivisor;

double normal(double x)
{
    return exp(-2*x*x)/(normDivisor);
}

int main()
{
    normDivisor=0.5 * sqrt(2 * PI);
    double samples50[100];
    regular(100,-3,3,samples50);


    FILE* arq = fopen("interpolacao.csv","w");
    int i=0;
    do
    {
        fprintf(arq,"%g",normal(samples50[i]));
        i++;
    } while (i<100 && fprintf(arq,","));
    fprintf(arq,"\n");
    
    
    
   
    double samples10[10]; 
    regular(10,-3,3,samples10);

    double coefs[10];
    coeficientes(10,samples10,normal,coefs);

    i=0;
    do
    {
        fprintf(arq,"%g",avalia(10,samples10,coefs,samples50[i]));
        i++;
    } while (i<100 && fprintf(arq,","));
    fprintf(arq,"\n");


   
    //samples10[10]; 
    chebyshev(10,-3,3,samples10);

    //coefs[10];
    coeficientes(10,samples10,normal,coefs);
    
    i=0;
    do
    {
        fprintf(arq,"%g",avalia(10,samples10,coefs,samples50[i]));
        i++;
    } while (i<100 && fprintf(arq,","));

    fclose(arq);
}