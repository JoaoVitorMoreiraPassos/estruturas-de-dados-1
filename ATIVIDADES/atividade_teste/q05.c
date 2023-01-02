#include <stdio.h>


void main()
{
    int matriz_a[10][20];
    int i, j;

    for (i = 0; i < 10; i ++)
    {
        for (j = 0; j < 20; j ++)
        {
            matriz_a[i][j] = (rand()%10)+1;
            printf("%d ",matriz_a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int matriz_b[10][20];
    for (i = 0; i < 10; i ++)
    {
        for (j = 0; j < 20; j ++)
        {
            matriz_b[i][j] = matriz_a[i][j] * 3;
            printf("%d ",matriz_b[i][j]);
        }
        printf("\n");
    }
}