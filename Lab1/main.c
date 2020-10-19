#define _USE_MATH_DEFINES
#include <math.h>
#include "taylor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
    for (double i = -2.0 * M_PI; i<=2.0 * M_PI; i+= 4.0 * M_PI/100.0)
    {
        double m=cos(i);
        double t=cos_taylor(i);
        double er=fabs(m-t);
        if(er>=0.005)
        {
            printf("ERRO ENCONTRADO!!\n");
        }
        printf("i= %g\nmath: %g\ntaylo: %g\nerro: %g\n---------\n",i,m,t,er);
        
        
    }
    return 0;
}