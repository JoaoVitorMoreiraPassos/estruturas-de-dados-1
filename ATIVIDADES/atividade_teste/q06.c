#include <stdio.h>


void main()
{
    int matriz[10][10];
    int i, j,soma = 0;
    for (i = 0; i < 10; i ++)
    {
        for (j = 0; j < 10; j ++)
        {
            matriz[i][j] = (rand()%10)+1;
            soma += matriz[i][j];
        }
    }
    printf("%d",soma);
}