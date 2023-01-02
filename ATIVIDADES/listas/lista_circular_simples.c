#include <stdio.h>


typedef struct lista Lista;

struct lista{
    int info;
    Lista *prox;
};

Lista *inicializa(void){
    return NULL;
}

Lista *alocaNo(int valor){
    Lista *no = (Lista *) malloc(sizeof(Lista));
    no->info = valor;
    no->prox = NULL;
    return no;
}

Lista* insere(Lista* l, int valor){
    Lista* novo = alocaNo(valor);
    if (l == NULL){
        novo->prox = novo;
        l = novo;
    }else{
        novo->prox = l->prox;
        l->prox = novo;
    }
    return l;
}

void imprime(Lista* raiz){
    Lista* p;
    p = raiz;
    if(p != NULL){do{
        p = p->prox;
        printf("%d ",p->info);
    }while(p != raiz);printf("\n");
    }
    else{
        printf("lista vazia\n");
    }
}

Lista *busca(Lista * l, int valor){
    Lista *p;
    p = l;
    if(p != NULL){
        do{
            p = p->prox;
            if(p->info == valor){
                return p;
            }
        }while(p != l);
    }
    else{
        printf("lista vazia\n");
    }
    return NULL;
}

Lista* retiraCircular(Lista* l, int v){
    Lista* ant = NULL;
    Lista* p = l;
    int achou = 0;
    if (p == NULL) // Se a lista for nula
        return NULL;
    if (p){ // descobrir quem é o anterior
        do {
            ant = p;
            p = p->prox; /* avança para o próximo nó */
            if (p->info == v){
                achou = 1;
                break;
            }
        } while (p != l);
    }
    if(!achou) // Se não achar o elemento
        return l;
    if (p->prox == p){// Quando há apenas um único elemento da lista
        free(p);
        return NULL;
    }
    if (p == l){ // Caso quando a remoção é a referência da lista
        ant->prox = l->prox;
        l = ant;
    }else {
        ant->prox = p->prox;
    }
    free(p);
    return l;
}


void main(){
    Lista *list;
    list = inicializa();
    int i;
    for(i = 0; i < 5; i ++){
        list = insere(list, i+1);
    }
    list = retiraCircular(list, 1);
    imprime(list);
}