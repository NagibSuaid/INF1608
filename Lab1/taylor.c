#include "taylor.h"
#define PI 3.14159265359
#define K 7
#define X0 0.0

//valores parciais da serie de taylor pre processados:
static const double taylor_coeficients[]={1.0,0.0,-0.5,0.0,1.0/24.0,0.0,-1.0/720.0};

double cos_taylor_90 (double x)
{
    //Avalia o valor de cos(x) para x em [0,PI/2]
    //Com precisao de duas casas decimais
    double total=0.0;
    double dif = (x-X0);
    for(int i=0;i<K;i+=1)
    {
        double parcela = 1.0;
        for(int j=0;j<i;j++)
        {
            parcela*=dif; 
        } //ao fim desse loop, parcela == (x-x0)^i
        total+=taylor_coeficients[i]*parcela;
    }
    return total;
}

static double cos_taylor_180 (double x)
//Avalia o valor de cos(x) para x em [0,PI]
//Com precisao de duas casas decimais
{
    if(x<=PI/2.0)
    {
        return cos_taylor_90(x);
    }
    return -1.0 * cos_taylor_90(PI - x);
}

double cos_taylor (double x)
{
    if(x>=0.0 && x<=PI)
    {
        return cos_taylor_180(x);
    }
    if(x<0.0)
    {
       return cos_taylor(-x);
    }

    return cos_taylor((2.0 * PI)-x);
    
}