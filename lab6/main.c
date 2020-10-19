#include "integral.h"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

double fa(double x)
{
    return cos(x) - (2*sin(x));
}

double fal(double x)
{
    return -sin(x)-(2*cos(x));
}

double fc1(double x)
{
    return x/(sqrt(x*x + 9));
}
double fc2(double x)
{
    return x*x*log(x);
}
double fc3(double x)
{
    return x*x*sin(x);
}

int main()
{
    printf("\nA)\n");
    printf("h otimo encontrado: %g\n",h_otimo(fa,fal,0.0));
    printf("h otimo real: %g\n",pow(3*pow(2,-52)/4,1.0/3.0));

    printf("\nB)\n");
    printf("erro do metodo de segunda ordem: %g\n",fabs(derivada(fa,0,1e-3) - fal(0)));
    printf("erro do metodo de terceira ordem: %g\n",fabs(richardson(fa,0,1e-3) - fal(0)));

    printf("\nC)\n");
    printf("integral 1:\n");
    printf("\tT16: %.15g\n",trapezio(fc1,0,4,16));
    printf("\tT32: %.15g\n",trapezio(fc1,0,4,32));
    printf("\tS16: %.15g\n",simpson(fc1,0,4,16));
    printf("\tS32: %.15g\n",simpson(fc1,0,4,32));

    printf("integral 2:\n");
    printf("\tT16: %.15g\n",trapezio(fc2,1,3,16));
    printf("\tT32: %.15g\n",trapezio(fc2,1,3,32));
    printf("\tS16: %.15g\n",simpson(fc2,1,3,16));
    printf("\tS32: %.15g\n",simpson(fc2,1,3,32));

    printf("integral 3:\n");
    printf("\tT16: %.15g\n",trapezio(fc3,0,M_PI,16));
    printf("\tT32: %.15g\n",trapezio(fc3,0,M_PI,32));
    printf("\tS16: %.15g\n",simpson(fc3,0,M_PI,16));
    printf("\tS32: %.15g\n",simpson(fc3,0,M_PI,32));
    return 0;
}
