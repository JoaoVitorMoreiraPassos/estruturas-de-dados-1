#include <stdio.h>
#include <stdlib.h>
#include "localBib.h"

void gerarVetor(int *v)
{
    int i; 
    for (i = 0; i < 10; i ++)
    {
        v[i] = (rand()%10)+1;
        printf("%d - ", v[i]);
    }
    printf("\n");
}