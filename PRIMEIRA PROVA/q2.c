#include <stdio.h>


int soma(int n, int m)
{
/*  A função se chamar passando n + 1 e m até o n ficar igual ao m
    Quando isso acontecer irá começar a regredir somando os números
    retornados */
    if(n == m)
    {
        return n;
    }
    else{
        return n + soma(n+1,m);
    }
}

void troca(int *n, int *m){
/*  Recebe dois ponteiros e troca os seus valores se o *n for maior que o *m */
    int aux;
    if(*n > *m){
        aux = *n;
        *n = *m;
        *m = aux;
    }
}

void main()
{
    int n = 10,m = 20;
    troca(&n,&m);
    
    printf("%d",soma(n,m));
}