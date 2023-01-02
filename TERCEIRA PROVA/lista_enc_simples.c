#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
struct lista{
  int info;
  Lista *prox;
};

Lista* inicializa(void);
Lista* insere(Lista* l, int valor);
Lista* alocaNo(int valor);
void imprime(Lista* raiz);
Lista* busca(Lista* l, int v);
Lista* retira (Lista* l, int v);
Lista* libera(Lista* l);

void main (){
// Na lista simples, o valor da lista sempre é o ultimo elemento informado(no caso 17).
  Lista* lista;
  Lista* lbusca;
  lista = inicializa();
  lista = insere(lista, 23);
  lista = insere(lista, 45);
  lista = insere(lista, 17);
  imprime(lista);

  lbusca = busca(lista, 23);
  if(lbusca == NULL){
    printf("\nNumero nao encontrado!");
  }else{
    printf("\nAchou: %d\n", lbusca->info); // Exibe o Numero que achou
  }

  // lista = retira(lista, 45);
  
  // lista = libera(lista); // Libera todos os elementos.
  // imprime(lista);

}

Lista* inicializa(void){
  return NULL;
}

Lista* insere(Lista* l, int valor){
  Lista* novo = alocaNo(valor);
  novo->prox = l;
  return novo;
}

Lista* alocaNo(int valor){
  Lista* no = (Lista*) malloc(sizeof(Lista));
  no->info = valor;
  no->prox = NULL;
  return no;

}

void imprime(Lista* raiz){
  Lista* p = NULL;
  printf("\nTodos os Numeros da Lista: ");
  for (p = raiz; p != NULL; p = p->prox){
    printf("%d ", p->info);
  }
}

Lista* busca (Lista* l, int v){
  Lista* p;
  for (p=l; p!=NULL; p = p->prox) {
  if (p->info == v)
    return p;
  }
  return NULL;
}

Lista* retira(Lista* l, int v){
  Lista* ant = NULL;
  Lista* p = l;
  for (p=l; p!=NULL; p = p->prox) {
    if (p->info == v){
      break;
    }
    ant = p;
    }
  if (p == NULL)
    return l;
  if (ant == NULL){
    l = p->prox;
  }else {
    ant->prox = p->prox;
  }
  free(p);
  return l;
}

Lista* libera(Lista* l){
  Lista* p = l;
  Lista* t = NULL;
  while (p != NULL) {
    t = p->prox;
    free(p);
    p = t;
  }
  return NULL;
}
