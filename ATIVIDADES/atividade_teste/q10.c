#include <stdio.h>


void main()
{
    char nome[15], sobrenome[20];
    printf("Nome: ");
    scanf(" %[^\n]s",&nome);
    printf("Sobrenome: ");
    scanf(" %[^\n]s",&sobrenome);

    printf("%s %s", nome, sobrenome);
}