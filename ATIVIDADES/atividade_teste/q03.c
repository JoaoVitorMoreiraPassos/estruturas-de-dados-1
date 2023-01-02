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
    int v[10], maior = 1, menor = 1,i;
    gerarVetor(v);
    for ( i = 0; i < 10; i ++)
    {
        if(v[i] > maior)
        {
            maior = v[i];
        }
        if(v[i] < menor)
        {
            menor = v[i];
        }
    }
    printf("maior: %d\n",maior);
    printf("menor: %d\n",menor);
}