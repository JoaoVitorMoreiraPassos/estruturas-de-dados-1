#include <stdio.h>


void primo(int m, int *p1, int *p2)
{
/*  Recebe um inteiro e dois ponteiros */
    int i, j, divs;
/*  Busca por um número primo começando por m - 1 até encontrar número primo*/
    for(i = m-1; i >= 2; i --)
    {
    /*  Para cada número realiza-se uma busca por seus divisores
        Começando por seu antecessor e indo ate o 1 */
        divs = 0;
        for(j = i-1; j >= 1; j --)
        {
            if(i % j == 0)
            {
                divs ++;
            }
        }
    /*  Se o número de divisores for menor ou igual a 1 ele é primo
        Como os números são buscados em ordem decrescente a partir 
        Do m o primeiro a ser achado será o mais próximo de m - 1
        Então a busca parará */
        if(divs <= 1)
        {
        /*  *p2 recebe o maior número primo menor que m */
            *p1 = i;
            break;
        }
    }
/* Busca por um número primo começãndo por m + 1 até encontrar o número primo */
    i = m+1;
    while (1)
    {
    /*  Para cada número realiza-se uma busca por seus divisores
        Começando por seu antecessor e indo ate o 1 */
        divs = 0;
        for(j = i-1; j >= 1; j --)
        {
            if(i % j == 0)
            {
                divs ++;
            }
        }
    /*  Se o número de divisores for menor ou igual a 1 ele é primo
        Como os números são buscados em ordem crescente a partir 
        Do m + 1 o primeiro a ser achado será o mais próximo de m 
        Então a busca parará */
        if(divs <= 1)
        {
        /*  *p2 recebe o menor número primo maior que m */
            *p2 = i;
            break;
        }
        i ++;
    }
}


void main()
{
    int m = 2, p1, p2;
    primo(m, &p1, &p2);
    printf("p1: %d\np2: %d\n",p1,p2);
}