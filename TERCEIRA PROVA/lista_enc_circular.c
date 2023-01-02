#include <stdio.h>
#include <stdlib.h>

typedef struct listaC ListaC;

struct listaC{
  int info;
  ListaC *prox;
};

ListaC* inicializa(void);
ListaC* insereCircular (ListaC* l, int valor);
ListaC* alocaNo(int valor);
void imprimeCircular(ListaC* l);
ListaC* busca(ListaC* l, int v);
ListaC* retiraCircular(ListaC* l, int v);
ListaC* libera (ListaC* l);

void main (){
// Na lista circular, o valor da lista sempre é o primeiro elemento informado(no caso 23)
  ListaC* listaC;
  ListaC* lbusca;

  listaC = inicializa();
  listaC = insereCircular(listaC, 23);
  listaC = insereCircular(listaC, 45);
  listaC = insereCircular(listaC, 17);
  imprimeCircular(listaC);

  lbusca = busca(listaC, 23);
  if(lbusca == NULL){
    printf("\nNumero nao encontrado!");
  }else{
    printf("\nAchou: %d\n", lbusca->info); // Exibe o Numero que achou
  }

  listaC = retiraCircular(listaC, 45);
  imprimeCircular(listaC);

  // listaC = libera(listaC);
  // imprimeCircular(listaC);

}

ListaC* inicializa(void){
  return NULL;  
}

ListaC* insereCircular(ListaC* l, int valor){
  ListaC* novo = alocaNo(valor);

  if (l == NULL){
    novo->prox = novo;
    l = novo;
  }
  else{
    novo->prox = l->prox;
    l->prox = novo;
  }
  return l;
}

ListaC* alocaNo(int valor){
  ListaC* no = (ListaC*) malloc(sizeof(ListaC));
  no->info = valor;
  no->prox = NULL;
  return no;
}

void imprimeCircular(ListaC* l){
  ListaC* p = l;
  if (p){
    do{
      p = p->prox; /* avança para o próximo nó */
      printf("%d ", p->info);
    }while (p != l);
  }
}

ListaC* busca(ListaC* l, int v){
  ListaC* p = l;
  if (p){
    do {
      p = p->prox; /* avança para o próximo nó */
      if(p->info == v){
        return p;
      }
    }while (p != l);
  }
  return NULL;
}

ListaC* retiraCircular(ListaC* l, int v){
  ListaC* ant = NULL;
  ListaC* p = l;
  int achou = 0;

  if (p == NULL) // Se a lista for nula
    return NULL;
  if (p){ // descobrir quem é o anterior
    do{
      ant = p;
      p = p->prox; /* avança para o próximo nó */
      if (p->info == v){
        achou = 1;
      break;
      }
    }while(p != l);
  }
  if(!achou) // Se não achar o elemento
    return l;
  if (p->prox == p){// Quando há apenas um único elemento da lista
    free(p);
    return NULL;
  }
  if(p == l){ // Caso quando a remoção é a referência da lista
    ant->prox = l->prox;
    l = ant;
  }else {
    ant->prox = p->prox;
  }
  free(p);
  return l;
}

ListaC* libera (ListaC* l){
  ListaC* p = l;
  ListaC* t = NULL;
  if(p){
    do{
      t = p->prox;
      free(p);
      p = t;
    }while(p != l);
  }
  return NULL;
}
