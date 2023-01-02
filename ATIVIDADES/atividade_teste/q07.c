#include <stdio.h>


void main()
{
    int matriz[7][7][7];
    int i, j, k;

    for (i = 0; i < 6; i ++)
    {
        for (j = 0; j < 7; j ++)
        {
            for (k = 0; k < 7; k ++)
            {
                matriz[i][j][k] = k;
                printf("%d ",matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}