#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct filaD FilaD;
struct filaD{
  int info;
  FilaD* prox;
};

typedef struct pilhaD PilhaD;
struct pilhaD{
  int info;
  PilhaD* prox;
};

FilaD* filaD_inicializa();
PilhaD* pilhaD_inicializa();
FilaD* alocaNoF(int valor);
PilhaD* alocaNoP(int valor);
int filaD_vazia(FilaD* f);
FilaD* filaD_insere(FilaD* f, int valor);
PilhaD* pilhaD_insere(PilhaD* p, int valor);
PilhaD* intercala(FilaD* f, PilhaD* p);
void imprime(FilaD* f, PilhaD* p, PilhaD* novaP);

void main(){
  FilaD *fila;
  PilhaD* pilha;

  fila = filaD_inicializa();
  pilha = pilhaD_inicializa();

  int i, num;
//Preencenho a lista;
  for(i = 1; i <= MAX; i++){
    printf("Informe o %d da Fila: ", i);
    scanf("%d", &num);
    fila = filaD_insere(fila, num);
  }
  printf("\nFila Inserida!!\n");
//Preencenho pilha;
  for(i = 1; i <= MAX; i++){
    printf("Informe o %d da Pilha: ", i);
    scanf("%d", &num);
    pilha = pilhaD_insere(pilha, num);
  }
  printf("\nPilha Inserida!!");

  PilhaD* nova;
  nova = intercala(fila, pilha);
  imprime(fila, pilha, nova);

}

FilaD* filaD_inicializa(){
  return NULL;
}
PilhaD* pilhaD_inicializa(){
  return NULL;
}
FilaD* alocaNoF(int valor){
  FilaD* no = (FilaD*) malloc(sizeof(FilaD));
  no->info = valor;
  no->prox = NULL;
  return no;
}
PilhaD* alocaNoP(int valor){
  PilhaD* no = (PilhaD*) malloc(sizeof(PilhaD));
  no->info = valor;
  no->prox = NULL;
  return no;
}
int filaD_vazia(FilaD* f){
  if(f == NULL)
    return 1;
  return 0;
}
FilaD* filaD_insere(FilaD* f, int valor){
  FilaD *novo = alocaNoF(valor);

  if(filaD_vazia(f) == 1){
    f = novo;
  }
  else{
    FilaD* atual = f;
    while(atual->prox != NULL){
      atual = atual->prox;
    }
    atual->prox = novo;
  }
  return f;
}

PilhaD* pilhaD_insere(PilhaD* p, int valor){
  PilhaD *novo = alocaNoP(valor);
  novo->prox = p;
  return novo;
}

PilhaD* intercala(FilaD* f, PilhaD* p){
  FilaD* auxF = f;
  PilhaD* auxP = p;
  PilhaD* novaP = NULL;
  while(auxF != NULL){
    if((auxF->info%2) == 0){
      novaP = pilhaD_insere(novaP, auxF->info);
      auxF = auxF->prox;
      novaP = pilhaD_insere(novaP, auxP->info);
      auxP = auxP->prox;
    }
    else{
      novaP = pilhaD_insere(novaP, auxP->info);
      auxP = auxP->prox;
      novaP = pilhaD_insere(novaP, auxF->info);
      auxF = auxF->prox;
    }
  }
  return novaP;
}

void imprime(FilaD* f, PilhaD* p, PilhaD* novaP){
  FilaD* fila = f;
  PilhaD* pilha = p;
  PilhaD* mostra = novaP;

  printf("\n\nFila: ");
  do{
      printf("%d ", fila->info);
      fila = fila->prox;
  }while(fila != NULL);

  printf("\nPilha: ");
  do{
      printf("%d ", pilha->info);
      pilha = pilha->prox;
  }while(pilha != NULL);

  int v[100], t = -1, i;
  printf("\n\nNova Pilha: ");
  do{
      t++;
      v[t] = mostra->info;
      // printf("%d | ", mostra->info);
      mostra = mostra->prox;
  }while(mostra != NULL);

  for(t; t >= 0; t--){
    printf("%d | ", v[t]);
  }
}
