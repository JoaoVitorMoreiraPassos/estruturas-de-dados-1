#include <stdio.h>
#include <string.h>

typedef struct Produto{
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;


void main(){
    int a, c;
    char b[50];
    float d;
    scanf("%d",&a);
    scanf(" %[^\n]s",b);
    scanf("%d", &c);
    scanf("%f",&d);
    int i;
    Produto p;
    p.id = a;
    for ( i = 0; i < strlen(b); i ++){
        p.nome[i] = b[i];
    }
    p.nome[i] = '\0';
    p.quantidade = c;
    p.preco = d;
    
    printf("id: %d\nnome: %s\nquantidade: %d\npreco: %.2f",p.id,p.nome,p.quantidade,p.preco);
}