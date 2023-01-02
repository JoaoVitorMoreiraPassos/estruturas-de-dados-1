#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const tam = 10;

void gerarVetor(int *v)
{
    int i; 
    for (i = 0; i < tam; i ++)
    {
        v[i] = (rand()%10)+1;
        printf("%d - ", v[i]);
    }
    printf("\n");
}

void main()
{
    int v1[tam], v2[tam], v3[tam];
    gerarVetor(v1);
    gerarVetor(v2);
    int i;
    for (i = 0; i < tam; i ++)
    {
        v3[i] = v1[i] + v2[i];
        printf("%d - ",v3[i]);
    }
}