#include <stdio.h>


void main()
{
    float notas[4],soma = 0;
    int i;
    for (i = 0; i < 4; i ++)
    {
        scanf("%f",notas[i]);
        soma += notas[i];
    }
    printf("%.2f", soma/4);
}