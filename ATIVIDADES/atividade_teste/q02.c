#include <stdio.h>

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

void main()
{
    int v[10], i;
    gerarVetor(v);
    for (i = 0; i < 10; i ++)
    {
        if(v[i] % 2 == 0)
        {
            printf("%d eh par.\n",v[i]);
        }else
        {
            printf("%d eh impar.\n",v[i]);
        }
    }
}