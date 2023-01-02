//Lista Circular dupla

#include <stdio.h>
#include <stdlib.h>


typedef struct lista Lista;

struct lista{
    int info;
    Lista *ant;
    Lista *prox;
};

Lista *inicializa(void){
    return NULL;
}

Lista *alocaNo(int valor){//Cria um novo elemento pra lista.
    Lista *no = (Lista *) malloc(sizeof(Lista));
    no->info = valor;
    no->ant = NULL;
    no->prox = NULL;
    return no;
}

Lista* insere(Lista* l, int valor){
    Lista* novo = alocaNo(valor);
    if (l == NULL){//Se a lista estiver vazia.
        //Tanto o proximo quanto o anterior serao ele mesmo.
        novo->ant = novo;
        novo->prox = novo;
        l = novo;
    }else{//Se a lista ja tiver algum elemento.
        if(l == l->prox){//Se a lista so tiver 1 elemento.
            novo->ant = l;//O anterior do novo item serah o primeiro.
            novo->prox = l;//O proximo do novo item serah o primeiro.
            l->ant = novo;//O anterior do primeiro elemento sera o novo que agora e o ultimo.
            l->prox = novo;//O proximo elemento do primeiro sera o novo que agora e o ultimo.
        }else{//Se a lista tiver mais que um elemento.
            novo->ant = l->ant;// O aterior do novo item que sera o ultimo recebe o antigo ultimo elemento. 
            novo->prox = l;//O proximo do novo item recebe o primeiro item da lista.
            l->ant->prox = novo;//O proximo do antigo ultimo elemento recebe o novo.
            l->ant = novo;// O anterior do primeiro elemento aponta para o novo que agora eh o ultimo.
        }
    }
    return l;// Retorna a lista.
}

void imprime(Lista* raiz){
    Lista* p, *n;
    p = raiz;
    if(p != NULL){//Se a lista estiver preenchida.

        do{//Mostra os elementos da lista do primeiro ao ultimo.
            printf("%d ",p->info);
            p = p->prox;
        }while(p != raiz);printf("\n");

        n = p;
        do{//Mostra os elementos da lista do ultimo ate o primeiro.
            n = n->ant;
            printf("%d ",n->info);
        }while(n != p);printf("\n");
    }
    else{//Se a lista estiver vazia.
        printf("lista vazia\n");
    }
}

Lista *busca(Lista * l, int valor){
    Lista *p;
    p = l;
    if(p != NULL){// Se a lista estiver preenchida.
        do{//Procura elemento por elemento se e se enconrtrar retorna uma lista que comeca a partir dele.
            p = p->prox;
            if(p->info == valor){
                return p;
            }
        }while(p != l);
    }
    else{//Se a lista estiver vazia.
        printf("lista vazia\n");
    }
    return NULL;//Se nao encotrar o valor.
}

Lista* retiraCircular(Lista* l, int v){
    Lista* p = l;
    int achou = 0;
    if(p == NULL){// Se a lista estiver vazia.
        return NULL;
    }
    if(p){// Procura o valor a ser removido.
        do {
            p = p->prox;// avança para o próximo elemento.
            if (p->info == v){
                achou = 1;
                break;
            }
        } while (p != l);
    }
    if(!achou)// Se não achar o elemento
        return l;
    if (p->prox == p){// Quando há apenas um único elemento da lista
        free(p);
        return NULL;
    }
    if (p == l){ // Quando for para remover a referência da lista
        l->ant->prox = l->prox;// O proximo do ultimo elemento agora apontara para o segundo elemento.
        l->prox->ant = l->ant;// O anterior do segundo elemento agora apontara para o ultimo elemento.
        l = l->prox;// Passa a referencia da lista para o segundo elemento.
    }else {// Se nao for a referencia da lista e nem for o unico elemento.
        if(p->prox == l){// Se for o ultimo elemento da lista.
            p->ant->prox = l;//O proximo do penultimo elemento agora apontara para o primeiro elemento.
            l->ant = p->ant;// O anterior do primeiro elemento agora apontara para o penultimo elemento.
        }else{//Se for qualquer elemento da lista depois do primeiro e antes do ultimo.
            p->ant->prox = p->prox;// O proximo do elemento antecessor ao que sera removido agora apontara para o sucessor.
            p->prox->ant = p->ant;// O anterior do elemento sucessor ao que sera removido agora apontara para o antecessor.
        }
    }
    free(p);//Libera o p.
    return l;//Retorna a lista modificada.
}

Lista* libera (Lista* l){
    Lista* p = l;
    Lista* t = NULL;
    if(p){
        do{//Perocorre todos os elementos da lista
            t = p->prox;//Pega a refencia dos proximos valores da lista.
            free(p);//libera a primeira posicao da lista no momento.
            p = t;//recupera os proximos valores da lista
        }while(p != l);
    }
    printf("liberado\n");
    return NULL;//retorna nulo.
} 


void main(){
    Lista *list;
    list = inicializa();
    int i;

    for(i = 0; i < 10; i ++){
        list = insere(list, i+1);
    }
    list = retiraCircular(list, 1);
    list = retiraCircular(list, 3);
    imprime(list);

    list = libera(list);
    imprime(list);
}