#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa{
  char cpf[15];
  char nome[100];
  int idade;
  Pessoa *ant;
  Pessoa *prox;
};

Pessoa* inicializa(void);
Pessoa* inserePessoa(Pessoa* p, char *cpf, char *nome, int idade);
Pessoa* alocaPessoa(char *cpf, char *nome, int idade);
Pessoa* ordenaCpf(Pessoa* p);
void idadeMenor(Pessoa* p, int idade);
void vizinhoVelho(Pessoa* p, char *cpf);
int tamanhoLista(Pessoa* p);
void mostraPessoas(Pessoa* p);

void main(){
  Pessoa* pe;
  pe = inicializa();

  int idade, i = 0;
  char cpf[15], nome[100];

  printf("\n====Adicionando=Pessoas====\n");
  while(i != 1){
    printf("\nCpf: ");
    scanf(" %[^\n]s", cpf);
    printf("Nome: ");
    scanf(" %[^\n]s", nome);
    printf("Idade: ");
    scanf("%d", &idade);
    pe = inserePessoa(pe, cpf, nome, idade);

    printf("\nInformar mais? [0]SIM [1]NAO: ");
    scanf("%d", &i);
  }
  pe = ordenaCpf(pe);
  mostraPessoas(pe);
  int num;
  i = 0;
  while(i != 1){
    printf("\n\n====OPCOES====");
    printf("\n1 - Ver pessoas menores que uma idade \n2 - Vizinho Mais Velho: ");
    scanf("%d", &num);
    switch(num){
      case 1:
        printf("\nInforme uma idade: ");
        scanf("%d", &idade);
        idadeMenor(pe, idade);
        break;
      case 2:
        printf("\nInforme um CPF: ");
        scanf(" %[^\n]s", cpf);
        vizinhoVelho(pe, cpf);
        break;
      default:
        break;
    }
    printf("\nDeseja Encerrar [0]NAO [1]SIM: ");
    scanf("%d", &i);
  }
}
Pessoa* inicializa(){
  return NULL;
}
Pessoa* alocaPessoa(char *cpf, char *nome, int idade){
  Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
  strcpy(p->cpf, cpf);
  strcpy(p->nome, nome);
  p->idade = idade;
  p->prox = NULL;
  p->ant = NULL;
  return p;
}

Pessoa* inserePessoa(Pessoa* p, char *cpf, char *nome, int idade){
  Pessoa* novo = alocaPessoa(cpf, nome, idade);

  if(p == NULL){
    novo->ant = NULL;
  }else{
    p->ant = novo;
    novo->prox = p;
  }
  return novo;
}

int tamanhoLista(Pessoa* p){
  Pessoa* tam = NULL;
  tam = p;
  int t = 0;
  while(tam != NULL){
    t += 1;
    tam = tam->prox;
  }
  return t;
}

Pessoa* ordenaCpf(Pessoa* p){
  Pessoa* ord = NULL;
  ord = p;
  int i, j, tam, auxI;
  char auxC[15], auxN[100];
  tam = tamanhoLista(p);
// Metodo da bolha adaptado para ordenar a lista
  for(i = 0; i < tam; i++){
    for(j = 1; j < tam-i; j++){
      if(strcmp(ord->prox->cpf, ord->cpf) == -1){
        strcpy(auxC, ord->cpf);
        strcpy(auxN, ord->nome);
        auxI = ord->idade;

        strcpy(ord->cpf, ord->prox->cpf);
        strcpy(ord->nome, ord->prox->nome);
        ord->idade = ord->prox->idade;

        strcpy(ord->prox->cpf, auxC);
        strcpy(ord->prox->nome, auxN);
        ord->prox->idade = auxI;
      }
//    Avança para a proxima lista
      ord = ord->prox;
    }
//  Volta a lista pro final, pois a ordenação acontece do
//  final para o começo, entao a cada um numero ordenado é
//  necessario voltar pro final para a ordenação ocorrer corretamente.
    while(ord->ant != NULL){
      ord = ord->ant;
    }
  }
  printf("\nLista Ordenada!!");
  return ord;
}

void idadeMenor(Pessoa* p, int idade){
  Pessoa* pe = p;
  Pessoa* menor = NULL;

  while(pe != NULL){
    if(pe->idade < idade){
      menor = inserePessoa(menor, pe->cpf, pe->nome, pe->idade);
    }
    pe = pe->prox;
  }
  menor = ordenaCpf(menor);
  mostraPessoas(menor);
}

void vizinhoVelho(Pessoa* p, char *cpf){
  Pessoa* v = p;
  int maior;

  while(v != NULL){
    if(strcmp(v->cpf, cpf) == 0){
      if(v->ant == NULL){//se o cpf é o ultimo da lista
        maior = v->prox->idade;
        printf("\nIdade do Vizinho mais velho: %d anos!", maior);
        if(maior > v->idade)
          printf("\nVizinho e mais velho do que a pessoa informada!");
        else if(maior == v->idade)
          printf("\nVizinho e pessoa informada tem a mesma idade!");
        else
          printf("\nPessoa informada e mais velha que vizinho!");
      }
      else if(v->prox == NULL){//se o cpf é o primeiro da lista
        maior = v->ant->idade;
        printf("\nIdade do Vizinho mais velho: %d anos!", maior);
        if(maior > v->idade)
          printf("\nVizinho e mais velho do que a pessoa informada!");
        else if(maior == v->idade)
          printf("\nVizinho e pessoa informada tem a mesma idade!");
        else
          printf("\nPessoa informada e mais velha que vizinho!");
      }
      else{
        maior = v->ant->idade;
        // Verifica qual dos vizinhos tem a maior idade e guarda a maior idade na var "maior".
        if(v->prox->idade > maior)
          maior = v->prox->idade;
        printf("\nIdade do Vizinho mais velho: %d anos!", maior);
        if(maior > v->idade)
          printf("\nVizinho e mais velho do que a pessoa informada!");
        else if(maior == v->idade)
          printf("\nVizinho e pessoa informada tem a mesma idade!");
        else
          printf("\nPessoa informada e mais velha que vizinho!");
      }
    }
    v = v->prox;
  }
}

void mostraPessoas(Pessoa* p){
  Pessoa* mostra = NULL;
  mostra = p;
  printf("\n\nPessoas Informadas: ");
  printf("\nCPF | NOME | IDADE");
  do{
    printf("\n%s | %s | %d", mostra->cpf, mostra->nome, mostra->idade);
    if(mostra->prox == NULL){
      break;
    }
    mostra = mostra->prox;
  }while(1);
}