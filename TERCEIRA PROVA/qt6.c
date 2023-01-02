#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct filaD FilaD;
struct filaD{
    int info;
    FilaD* prox;
};

typedef struct pilhaD PilhaD;
struct pilhaD{
    int info;
    PilhaD* prox;
};

FilaD* filaD_inicializa();
PilhaD* pilhaD_inicializa();
FilaD* alocaNoF(int valor);
PilhaD* alocaNoP(int valor);
int filaD_vazia(FilaD* f);
FilaD* filaD_insere(FilaD* f, int valor);
PilhaD* pilhaD_insere(PilhaD* p, int valor);
PilhaD* intercala(FilaD* f, PilhaD* p);
void imprime(FilaD* f, PilhaD* p, PilhaD* novaP);

void main(){
    FilaD *fila;
    PilhaD* pilha;

    fila = filaD_inicializa();
    pilha = pilhaD_inicializa();

    int i, num;
    //Preencenho a lista;
    for(i = 1; i <= MAX; i++){
        printf("Informe o %d da Fila: ", i);
        scanf("%d", &num);
        fila = filaD_insere(fila, num);
    }
    printf("\nFila Inserida!!\n");
    //Preencenho pilha;
    for(i = 1; i <= MAX; i++){
        printf("Informe o %d da Pilha: ", i);
        scanf("%d", &num);
        pilha = pilhaD_insere(pilha, num);
    }
    printf("\nPilha Inserida!!");

    PilhaD* nova;
    nova = intercala(fila, pilha);
    imprime(fila, pilha, nova);
}

FilaD* filaD_inicializa(){//Inicializa uma fila dinamica
    return NULL;
}
PilhaD* pilhaD_inicializa(){//Inicializa uma pilha dinamica
    return NULL;
}
FilaD* alocaNoF(int valor){//Cria um no de uma Fila.
    FilaD* no = (FilaD*) malloc(sizeof(FilaD));
    no->info = valor;
    no->prox = NULL;
    return no;
}
PilhaD* alocaNoP(int valor){//Cira uma no de uma Pilha.
    PilhaD* no = (PilhaD*) malloc(sizeof(PilhaD));
    no->info = valor;
    no->prox = NULL;
    return no;
}
int filaD_vazia(FilaD* f){//Verifica se uma fila esta vazia.
    if(f == NULL)
        return 1;
    return 0;
}
FilaD* filaD_insere(FilaD* f, int valor){
    //Insere um elemento em uma lista
    FilaD *novo = alocaNoF(valor);

    if(filaD_vazia(f) == 1){
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

PilhaD* pilhaD_insere(PilhaD* p, int valor){
    //Empilha um elemento em uma pilha.
    PilhaD *novo = alocaNoP(valor);
    novo->prox = p;
    return novo;
}

PilhaD* intercala(FilaD* f, PilhaD* p){

    FilaD* auxF = f;
    PilhaD* auxP = p;
    PilhaD* novaP = NULL;
    while(auxF != NULL){//O laco se repete ate chegar no ultimo item da fila
        if((auxF->info%2) == 0){
            //Se o valor da referencia da lista for par.
            novaP = pilhaD_insere(novaP, auxF->info);//Empilha o valor da fila.
            auxF = auxF->prox;//Avanca para o proximo elemento da fila.
            novaP = pilhaD_insere(novaP, auxP->info);//Empilha o valor da pilha.
            auxP = auxP->prox;//Avanca para o proximo elemento da pilha.
        }
        else{
            //Se o valor da referencia da lista for impar.
            novaP = pilhaD_insere(novaP, auxP->info);//Empilha o valor da pilha.
            auxP = auxP->prox;//Avanca para o proximo elemento da pilha.
            novaP = pilhaD_insere(novaP, auxF->info);//Empilha o valor da fila.
            auxF = auxF->prox;//Avanca para o proximo elemento da fila.
        }
    }
    return novaP;//Retorna a pilha com os valores intercalados.
}

void imprime(FilaD* f, PilhaD* p, PilhaD* novaP){
    FilaD* fila = f;
    PilhaD* pilha = p;
    PilhaD* mostra = novaP;
    //Mostra a pilha e a lista.
    printf("\n\nFila: ");
    do{
        printf("%d ", fila->info);
        fila = fila->prox;
    }while(fila != NULL);

    printf("\nPilha: ");
    do{
        printf("%d ", pilha->info);
        pilha = pilha->prox;
    }while(pilha != NULL);
    //Passa os valores da pilha intercalada em um vetor, depois mostra os numeros.
    int v[100], t = -1;
    printf("\n\nNova Pilha: ");
    do{
        t++;
        v[t] = mostra->info;
        printf("%d | ", mostra->info);
        mostra = mostra->prox;
    }while(mostra != NULL);
}
