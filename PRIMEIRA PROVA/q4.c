#include <stdio.h>
#include <string.h>


void mostraTrocado(char c){
/*  Recebe um caractere */
/*  Verifica com o switch se o caractere recebido é uma vogal e
    Se for mostra outra vogal no seu lugar */
    switch (c)
        {
        case 'a': printf("u"); break;
        case 'e': printf("o"); break;
        case 'i': printf("u"); break;
        case 'o': printf("a"); break;
        case 'u': printf("e"); break;
        case 'A': printf("U"); break;
        case 'E': printf("O"); break;
        case 'I': printf("U"); break;
        case 'O': printf("A"); break;
        case 'U': printf("E"); break;
        default: printf("%c",c); break;
        }
}


void main()
{
    char frase[50];
    int i, t;
    printf("Digite uma frase: ");
/*  Lê uma string */
    scanf(" %[^\n]s",frase);
/*  Pega o tamanho de frase */
    t = strlen(frase);
/*  Percorre a string até seu ultimo caractere */
    for (i = 0; i < t; i ++)
    {
/*  Chama a função mostraTrocado passando o caractere da posição i da string */
        mostraTrocado(*(frase+i));
    }
    printf("\n");
}