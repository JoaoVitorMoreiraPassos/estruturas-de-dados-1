#include <stdio.h>


void main(){
    int tam;
    printf("tamanho da string: ");
    scanf("%d", &tam);
    
    char *str;
    str = (char *) malloc(sizeof(char));

    printf("digite a string: ");
    scanf(" %[^\n]s", str);

    printf("%s", str);
}