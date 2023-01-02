#include <stdio.h>

int soma(int n)
{
/*  A função ira se chamar passando n - 1 até o n valer 1
    Quando isso acontecer irá regredir somando os valores
    Retornados */
    if(n == 1){return 1;}
    else
    {
        return (n + soma(n-1));
    }
}


void main()
{
    int n = 10;
    int d = soma(n);
    printf("%d\n",d);
}