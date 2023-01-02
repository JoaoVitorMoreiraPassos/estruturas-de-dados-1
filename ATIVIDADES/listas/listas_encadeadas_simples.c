//Listas encadeadas simples.

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
    int info;
    Lista *prox;
};

Lista * inicializa(void){
    return NULL;
}
Lista * alocaNo(int valor){
    Lista *no = (Lista *) malloc(sizeof(Lista));
    no->info = valor;
    no->prox = NULL;
    return no;
}
Lista * insere(Lista *l, int valor){
    Lista *novo = alocaNo(valor);
    novo->prox = l;
    return novo;
}

void imprime(Lista* raiz){
    if (raiz != NULL){
        printf("%d ", raiz->info);
        imprime(raiz->prox);
    }
}
Lista * busca(Lista *l, int valor){
    Lista *p;
    for (p = l; p != NULL; p = p->prox){
        if(p->info == valor){
            return p;
        }
    }
    return NULL;
}
Lista *remover(Lista *l, int valor){
    Lista *p;
    Lista *ant = NULL;
    for (p = l; p != NULL; p = p->prox){
        if(p->info == valor){
            break;
        }
        ant = p;
    }
    if(p == NULL){
        return l;
    }
    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

Lista *libera(Lista *l){
    Lista *p = l;
    Lista *t = NULL;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }

    return NULL;
    
}
void main(){
    Lista *list;
    list = inicializa();
    list = insere(list, 1);
    list = insere(list, 2);
    list = insere(list, 3);
    list = insere(list, 4);
    list = insere(list, 5);
    list = insere(list, 6);
    list = remover(list, 3);
    imprime(list);
}