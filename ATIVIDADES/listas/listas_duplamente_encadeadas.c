//Listas duplamente encadeadas.

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
    int info;
    Lista *ant;
    Lista *prox;
};

Lista * inicializa(void){
    return NULL;
}

Lista * alocaNo(int valor){//Cria um novo elemento pra lista.
    Lista *no = (Lista *) malloc(sizeof(Lista));
    no->info = valor;
    no->ant = NULL;
    no->prox = NULL;
    return no;
}

Lista * insere(Lista *l, int valor){
    Lista *novo = alocaNo(valor);
    if(l == NULL){//Se a lista nao tiver nenhum elemento.
        novo->ant = NULL;//O anterior ira ser nulo.
    }else{//Se a lista ja tiver algum elemento.
        l->ant = novo;// O anterior sera o novo elemento.
    }
    novo->prox = l;// Proximo sera o elemento passado.
    return novo;
}

void imprime(Lista* raiz){
    if(raiz != NULL){//Se a lista tiver pelo menos um elemento.
        Lista* p = NULL;
        Lista* n = NULL;
        p = raiz;
        do{//Mostra do primeiro elemento da lista ate o ultimo.
            printf("%d ",p->info);
            if(p->prox == NULL){break;}
            p = p->prox;
        }while(1);printf("\n");
        for(p = p; p != NULL; p = p->ant){//Mostra do ultimo elemento da lista ate a o primeiro.
            printf("%d ", p->info);
        }printf("\n");
    }
    else{printf("lista vazia\n");}//Se a lista estiver vazia.
}

Lista * busca(Lista *l, int valor){
    Lista *p;
    for (p = l; p != NULL; p = p->prox){//Busca por um elemento e quando o encontra retorna a lista começando a partir dele.
        if(p->info == valor){
            return p;
        }
    }
    return NULL;//Se nao encontrar retorn nulo.
}
Lista *remover(Lista *l, int valor){
    Lista *p;
    for (p = l; p != NULL; p = p->prox){//Procoura o valor na lista.
        if(p->info == valor){
            break;
        }
    }
    printf("aqui\n");
    if(p == NULL){//Se o valor nao foi encontrado.
        return l;
    }
    if((p->ant) == NULL){//Se o valor foi encontrado na primeira posicao da lista.
        if(p->prox == NULL){//Se So tem um elemento na lista.
            l = NULL;//Apenas retorna nulo.
        }else{//Se tem mais de um elemento na lista.
            l = p->prox;// Passa a referencia para o segundo elemento.
            l->ant = NULL;// Atribui nulo para o antigo primeiro elemento.
        }
    }else{//Se estiver em qualquer posicao que nao seja a primeira.
        if(p->prox == NULL){//Se estiver na ultima posicao.
            (p->ant)->prox = NULL;// O proximo do penultimo elemento agora apontara para nulo.
        }
        else{//Se for qualquer elemento da lista depois do primeiro e antes do ultimo.
            (p->prox)->ant = p->ant;//O anterior do elemento sucessor apontara para o antecessor.
            (p->ant)->prox = p->prox;//O proximo do elemento antecessor apontara para o sucessor.
        }
    }
    free(p);//Libera o p.
    return l;// Retorna a lista modificada.
}

Lista *libera(Lista *l){
    Lista *p = l;
    Lista *t = NULL;

    while (p != NULL)
    {//Percorre todos os elementos da lista.
        t = p->prox;//Pega a referencia dos proximos valores da lista.
        free(p);//libera a primeira posicao da lista no momento.
        p = t;//recupera os proximos valores da lista.
    }
    printf("liberado\n");
    return NULL;//retorna nulo.
}
void main(){
    Lista *list;
    list = inicializa();
    int i;

    for (i = 0; i < 10; i ++){
        list = insere(list, i+1);
    }

    list = remover(list, 5);
    imprime(list);
    
    list = libera(list);
    imprime(list);
}