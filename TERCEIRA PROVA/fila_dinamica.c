#include <stdio.h>
#include <stdlib.h>

typedef struct filaD FilaD;
struct filaD{
  int info;
  FilaD* prox;
};

FilaD* filaD_inicializa();
FilaD* filaD_insere(FilaD* f, int valor);
FilaD* alocaNo(int valor);
void filaD_remove(FilaD** f);
int filaD_vazia(FilaD* f);
void imprime(FilaD* f);
FilaD* liberaFila(FilaD* f);

void main (){
  FilaD *fila;
  
  fila = filaD_inicializa();

  int i;
//Preencenho a lista;
  for(i = 1; i <= 9; i++){
    fila = filaD_insere(fila, i*11);
  }
  imprime(fila);
  filaD_remove(&fila);//Remove o primeiro elemento informado.
  imprime(fila);
  fila = liberaFila(fila);
  imprime(fila);

}
// ===================================//
FilaD* filaD_inicializa (){
  return NULL;
}
int filaD_vazia(FilaD* f){
  if(f == NULL)
    return 1;
  return 0;
}
// ===================================//
FilaD* filaD_insere(FilaD* f, int valor){
  FilaD *novo = alocaNo(valor);
    if (filaD_vazia(f)){
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
FilaD* alocaNo(int valor){
  FilaD* no = (FilaD*) malloc(sizeof(FilaD));
  no->info = valor;
  no->prox = NULL;
  return no;
  }
// ===================================//
void filaD_remove(FilaD** f){
  FilaD* aux;
  int valor;
  if(filaD_vazia(*f) == 0){
    aux = *f;
    valor =(*f)->info;
    *f = (*f)->prox;
    free(aux);
    printf("\nValor %d Removido!", valor);
  }
  else{
    printf("Lista ja vazia!!");
  }
}
// ===================================//
void imprime(FilaD* f){
  FilaD* mostra;
  if(filaD_vazia(f) == 0){
    printf("\nLista: ");
    mostra = f;
    do{
      printf("%d | ", mostra->info);
      mostra = mostra->prox;
    }while(mostra != NULL);
  }
  else{
    printf("\nFila Vazia!!!");
  }
}
// ===================================//
FilaD* liberaFila(FilaD* f){

  if(filaD_vazia(f) == 0){
    FilaD* aux;
    while(f != NULL){
      aux = f;
      f = f->prox;
      free(aux);
    }
    printf("\nTodos os elementos removidos!");
  }
  else{
    printf("\nPilha ja esta Vazia");
  }
  return f;
}
