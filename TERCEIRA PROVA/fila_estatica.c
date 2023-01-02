#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct fila Fila;
struct fila{
  int info[TAM];
  int fim;
};

void fila_inicializa(Fila* p);
void fila_insere(Fila* f, int valor);
void fila_imprime(Fila* f);
void fila_remove(Fila *f);

void main (){
  Fila fila;

  fila_inicializa(&fila);
  int i;
  for(i = 1; i <= 9; i++){
    fila_insere(&fila, i*11);
  }
  fila_imprime(&fila);
  fila_remove(&fila);
  fila_remove(&fila);
  fila_remove(&fila);
  fila_imprime(&fila);

}
// ===================================//
void fila_inicializa(Fila* f){
  f->fim = -1;
}
// ===================================//
int i;//Para mostrar quando a fila esta cheia apenas uma vez.
void fila_insere(Fila* f, int valor){
  if(fila_cheia(f) == 0){
    f->fim++;
    f->info[f->fim] = valor;
    i = 0;
  }else{
    if(i == 0){
      printf("\nFila Cheia!");
      i = 1;
    }
  }
}
int fila_cheia(Fila* f){
  if(f->fim >= TAM - 1)
    return 1;
  return 0;
  }
// ===================================//
void fila_remove(Fila *f){
  int valor, i;
  if(fila_vazia(f) == 0){
    for (i =0 ; i < f->fim; i++){
      f->info[i] = f->info[i+1];
    }
    f->fim--;
  }else{
    printf("\nFila ja esta Vazia!!");
  }
}
int fila_vazia(Fila* f){
  if(f->fim == -1)
    return 1;
  return 0;
}
// ===================================//
void fila_imprime(Fila *f){
  int i;
  if(fila_vazia(f) == 0){
    printf("\nFila: ");
    for(i = 0; i <= f->fim; i++){
      if(i == f->fim){
        printf("%d", f->info[i]);
      }else{
        printf("%d | ", f->info[i]);
      }
    }
  }else{
    printf("\nFila esta vazia!!!");
  }
}