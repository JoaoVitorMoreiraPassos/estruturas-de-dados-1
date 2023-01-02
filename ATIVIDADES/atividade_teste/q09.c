#include <stdio.h>
#include <math.h>


float perimetro(int b, int h)
{
    float p = (b*2) + (h*2);
    return p;
}

float semiperimetro(int b, int h)
{
    float sp = b + h;
    return sp;
}

float area(int b, int h)
{
    float a = b * h;
    return a;
}

float diagonal(int b, int h)
{
    float d = sqrt(pow(b,2)+pow(h,2));

    return d;
}

void main()
{
    float n = semiperimetro(14,10);
    printf("%.2f\n",n);
}