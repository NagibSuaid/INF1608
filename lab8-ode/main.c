#include <stdio.h>
#include<math.h>
#include "ode.h"

int chamadas;

double yl (double t, double y)
{
    chamadas+=1;
    return t*(y+t*t);
}

int main (void)
{
    
    double y0 =-1;
    double t0 = 0;
    double t1 = 2.4;
    double y1 = exp(t1*t1/2)-t1*t1-2;

    chamadas=0;
    
    printf("\n-- Passos Constantes --\n");
    double v = RungeKutta(t0,t1,0.001,y0,yl);
    printf("Valor encontrado: %g\n",v);
    printf("Erro relativo: %g\n",fabs(v-y1)/y1);
    printf("Avaliacoes: %d\n",chamadas);

    printf("\n\n");

    chamadas=0;
    printf("-- Passo Adaptativo --\n");
    v = RungeKuttaAdapt(t0,t1,y0,yl,1.0e-12);
    printf("Valor encontrado: %g\n",v);
    printf("Erro relativo: %g\n",fabs(v-y1)/y1);
    printf("Avaliacoes: %d\n",chamadas);

    printf("\n\n");

}