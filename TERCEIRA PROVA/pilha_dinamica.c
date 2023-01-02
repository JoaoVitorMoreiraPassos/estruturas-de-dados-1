#include <stdio.h>
#include <stdlib.h>

typedef struct pilhaD PilhaD;
struct pilhaD{
  int info;
  PilhaD* prox;
};

PilhaD* pilhaD_inicializa();
PilhaD* alocaNo(int valor);
PilhaD* pilhaD_push(PilhaD* p, int valor);
void pilhaD_pop(PilhaD** p);
int pilhaD_vazia(PilhaD* p);
void imprime(PilhaD* p);
PilhaD* liberaPilha(PilhaD* p);

void main(){
  PilhaD* pilha;

  pilha = pilhaD_inicializa();

  int i;
//Preencenho pilha;
  for(i = 1; i <= 9; i++){
    pilha = pilhaD_push(pilha, i*11);
  }
  imprime(pilha);
  pilhaD_pop(&pilha);//Remove o ultimo elemento informado.
  pilhaD_pop(&pilha);
  imprime(pilha);
  pilha = liberaPilha(pilha);
  imprime(pilha);

}
// ===================================//
PilhaD* pilhaD_inicializa(){
  return NULL;
}
// ===================================//
PilhaD* alocaNo(int valor){
  PilhaD* no = (PilhaD*) malloc(sizeof(PilhaD));
  no->info = valor;
  no->prox = NULL;
  return no;
}
PilhaD* pilhaD_push(PilhaD* p, int valor){// Adiciona valor
  PilhaD *novo = alocaNo(valor);
  novo->prox = p;
  return novo;
}
// ===================================//
void pilhaD_pop(PilhaD** p){// Retira
  PilhaD* aux;
  int valor;
  if(pilhaD_vazia(*p) == 0){
    aux = *p;
    valor =(*p)->info;
    *p = (*p)->prox;
    free(aux);
    printf("\nValor %d Removido!", valor);
  }else{
    printf("\nPilha vazia!");
  }
}
int pilhaD_vazia(PilhaD* p){
  if(p == NULL)
    return 1;
  return 0;
}
// ===================================//
void imprime(PilhaD* p){
  PilhaD* mostra;
  
  if(pilhaD_vazia(p) == 0){
    printf("\nPilha: ");
    mostra = p;
    do{
      printf("%d ", mostra->info);
      mostra = mostra->prox;
    }while(mostra != NULL);
  }
  else{
    printf("\nPilha Vazia");
  }
}
// ===================================//
PilhaD* liberaPilha(PilhaD* p){
  
  if(pilhaD_vazia(p) == 0){
    PilhaD* aux;
    while(p != NULL){
      aux = p;
      p = p->prox;
      free(aux);
    }
    printf("\nTodos os elementos removidos!");
  }
  else{
    printf("\nPilha ja esta Vazia");
  }
  return p;
}