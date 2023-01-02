#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct pilha Pilha;
struct pilha{
  int info[TAM];
  int topo;
};

void pilha_inicializa (Pilha* p);
void pilha_push(Pilha* p, int valor);
void pilha_pop(Pilha *p);
void pilha_imprime(Pilha *p);

void main (){
  Pilha pilha;
  pilha_inicializa(&pilha);
  int i;
  for(i = 1; i <= 9; i++){
    pilha_push(&pilha, i*11);
  }
  pilha_imprime(&pilha);
  pilha_pop(&pilha);
  pilha_imprime(&pilha);

}
// ===================================//
void pilha_inicializa (Pilha* p){
  p->topo = -1;
}
// ===================================//
void pilha_push(Pilha* p, int valor){
  if(pilha_cheia(p) == 0){           
    p->topo++;                       
    p->info[p->topo] = valor;          
  }else{ 
    printf("Pilha esta Cheia!!");
  }
}                                     
int pilha_cheia(Pilha* p){            
  if(p->topo >= TAM - 1)              
    return 1;                         
  return 0;                           
}                                     
// =================================== //
void pilha_pop(Pilha *p){
  int valor = 0;
  if(pilha_vazia(p) == 0){
    valor = p->info[p->topo];
    p->topo--;
  }else{
    printf("\nPilha ja esta Vazia!!");
  }
  // return valor;
}
int pilha_vazia(Pilha* p){
  if(p ->topo == -1)
    return 1;
  return 0;
}
// ===================================//
void pilha_imprime(Pilha *p){
  int i;
  if(pilha_vazia(p) == 0){
    printf("\nPilha: ");
    for(int i = p->topo; i >= 0; i--){
      if(i == 0){
        printf("%d", p->info[i]);
      }else{
        printf("%d | ", p->info[i]);
      }
    }
  }else{
    printf("\nPilha esta vazia!!!");
  }
}