#include <stdio.h>
#include <string.h>


int vogalOrNo(char c)
{
/*  Recebe um caractere e o compara com as vogais presentes 
    Em um vetor que contém vogais se ele for igual a uma vogal
    Retornará 1, senão retornará 0 */
    char vogais[] = {"AaEeIiOoUu"};
    int i, t = strlen(vogais);
    for (i = 0; i < t; i ++)
    {
        if(c == vogais[i])
        {
            return 1;
        }
    }
    return 0;
}


int contaString(char *str1, char *str2, int *q1, int *q2)
{
/*  Recebe duas strings e dois ponteiros inteiros */
    int i, vogais = 0;
/*  Utiliza a função strlen para extrair o tamanho das strings */
    int t1 = strlen(str1), t2 = strlen(str2);
/*  Faz a iteração no primeiro vetor */
    for (i = 0; i < t1; i ++)
    {
    /*  Verifica se o caractere no indice i do vetor é maiusculo ou não */
        if(str1[i] > 64 && str1[i] < 91)
        {
            ++ *q1;
        }
    /*  Verifica se o caractere no indice i do vetor é uma vogal ou não */
        if(vogalOrNo(str1[i]) == 1)
        {
            vogais ++;
        }
    }
/*  Faz a iteração no segundo vetor */
    for (i = 0; i < t2; i ++)
    {
    /*  Verifica se o caractere no indice i do vetor é maiusculo ou não */
        if(str2[i] > 64 && str2[i] < 91)
        {
            ++ *q2;
        }
    /*  Verifica se o caractere no indice i do vetor é uma vogal ou não */
        if(vogalOrNo(str2[i]) == 1)
        {
            vogais ++;
        }
    }
/*  No final retorna a quantidade de vogais presentes na primeira e segunda
    String juntas */
    return vogais; 
}


void main()
{
    char str1[20], str2[20];
    printf("primeira frase:");
    scanf(" %[^\n]s",str1);
    printf("segunda frase:");
    scanf(" %[^\n]s",str2);

    int q1 = 0, q2 = 0;
    int vogais = contaString(str1,str2,&q1,&q2);

    printf("vogais: %d\nmaiusculas 1: %d\nmaiusculas 2: %d\n",vogais,q1,q2);
}