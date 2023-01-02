#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa Pessoa;
struct pessoa{
    char cpf[15];
    char nome[100];
    int idade;
    Pessoa *ant;
    Pessoa *prox;
};

Pessoa* inicializa(void);
Pessoa* inserePessoa(Pessoa* p, char *cpf, char *nome, int idade);
Pessoa* alocaPessoa(char *cpf, char *nome, int idade);
Pessoa* ordenaCpf(Pessoa* p);
void idadeMenor(Pessoa* p, int idade);
void vizinhoVelho(Pessoa* p, char *cpf);
int tamanhoLista(Pessoa* p);
void mostraPessoas(Pessoa* p);

void main(){
    Pessoa* pe;
    pe = inicializa();

    int idade, i = 0;
    char cpf[15], nome[100];
    //Faz a leitura dos dados das pessoas
    printf("\n====Adicionando=Pessoas====\n");
    while(i != 1){
        printf("\nCpf: ");
        scanf(" %[^\n]s", cpf);
        printf("Nome: ");
        scanf(" %[^\n]s", nome);
        printf("Idade: ");
        scanf("%d", &idade);
        pe = inserePessoa(pe, cpf, nome, idade);

        printf("\nInformar mais? [0]SIM [1]NAO: ");
        scanf("%d", &i);
    }
    pe = ordenaCpf(pe);//Ordena a lista.
    mostraPessoas(pe);//Mostra a lista.
    int num;
    i = 0;
    //Menu de opcoes para navegacao do usuario.
    while(i != 1){
        printf("\n\n====OPCOES====");
        printf("\n1 - Ver pessoas menores que uma idade \n2 - Vizinho Mais Velho \nEscolha: ");
        scanf("%d", &num);
        switch(num){
        case 1://Menores que uma idade. letra a.
            printf("\nInforme uma idade: ");
            scanf("%d", &idade);
            idadeMenor(pe, idade);
            break;
        case 2://Vizinho mais velho. letra b.
            printf("\nInforme um CPF: ");
            scanf(" %[^\n]s", cpf);
            vizinhoVelho(pe, cpf);
            break;
        default:
            break;
        }
        printf("\nDeseja Encerrar [0]NAO [1]SIM: ");
        scanf("%d", &i);
    }
}
Pessoa* inicializa(){
    return NULL;
}
Pessoa* alocaPessoa(char *cpf, char *nome, int idade){
    //Cria um no de uma lista.
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    strcpy(p->cpf, cpf);
    strcpy(p->nome, nome);
    p->idade = idade;
    p->prox = NULL;
    p->ant = NULL;
    return p;
}

Pessoa* inserePessoa(Pessoa* p, char *cpf, char *nome, int idade){
    //Insere um novo elemento em uma lista.
    Pessoa* novo = alocaPessoa(cpf, nome, idade);
    if(p == NULL){
        novo->ant = NULL;
    }else{
        p->ant = novo;
        novo->prox = p;
    }
    return novo;
}

int tamanhoLista(Pessoa* p){
    //Retorna o tamanho da lista.
    Pessoa* tam = NULL;
    tam = p;
    int t = 0;
    while(tam != NULL){
        t += 1;
        tam = tam->prox;
    }
    return t;
}

Pessoa* ordenaCpf(Pessoa* p){
    Pessoa* ord = NULL;
    ord = p;
    int i, j, tam, auxI;
    char auxC[15], auxN[100];
    tam = tamanhoLista(p);//Pega o tamanho para fazer a ordenacao.
    //Usa o metodo da bolha para ordenar.
    for(i = 0; i < tam; i++){
        for(j = 1; j < tam-i; j++){
            if(strcmp(ord->prox->cpf, ord->cpf) == -1){//Compara o cpf do elemento autal com o cpf do elemento sucessor.
                strcpy(auxC, ord->cpf);
                strcpy(auxN, ord->nome);
                auxI = ord->idade;

                strcpy(ord->cpf, ord->prox->cpf);
                strcpy(ord->nome, ord->prox->nome);
                ord->idade = ord->prox->idade;

                strcpy(ord->prox->cpf, auxC);
                strcpy(ord->prox->nome, auxN);
                ord->prox->idade = auxI;
            }
            //Passa para o proximo elemento.
            ord = ord->prox;
        }
        // Como o ord chegou ate o seu ultimo item eh preciso fazer o processo inverso para ele voltar ao inicio.
        while(ord->ant != NULL){
            ord = ord->ant;
        }
    }
    printf("\nLista Ordenada!!");
    return ord;
}

void idadeMenor(Pessoa* p, int idade){
    Pessoa* pe = p;
    Pessoa* menor = NULL;

    while(pe != NULL){
        //Varre os elementos em busca dos que tem a idade menor que a passada pelo usuario.
        //Quando acha insere os dados da pessoa na lista menor.
        if(pe->idade < idade){
            menor = inserePessoa(menor, pe->cpf, pe->nome, pe->idade);
        }
        pe = pe->prox;
    }
    menor = ordenaCpf(menor);//Ordena os menores.
    mostraPessoas(menor);//Mostra os menores.
}

void vizinhoVelho(Pessoa* p, char *cpf){
    Pessoa* v = p;
    int maior;
    while(v != NULL){//Enquanto nao chegar no final da lista.
        if(strcmp(v->cpf, cpf) == 0){
            if(v->ant == NULL){//Se for o ultimo elemento da lista.
                maior = v->prox->idade;//O maior vai ser o penultimo item.
                printf("\nIdade do Vizinho mais velho: %d anos!", maior);
                //Verifica se o vizinho mais velho eh mais velho, novo ou se tem a mesma idade do vizinho escolhido.
                if(maior > v->idade)
                    printf("\nVizinho e mais velho do que a pessoa informada!");
                else if(maior == v->idade)
                    printf("\nVizinho e pessoa informada tem a mesma idade!");
                else
                    printf("\nPessoa informada e mais velha que vizinho!");
            }
            else if(v->prox == NULL){//Se for o primeiro elemento da lista.
                maior = v->ant->idade;//O segundo sera o maior.
                printf("\nIdade do Vizinho mais velho: %d anos!", maior);
                //Verifica se o vizinho mais velho eh mais velho, novo ou se tem a mesma idade do vizinho escolhido.
                if(maior > v->idade)
                    printf("\nVizinho e mais velho do que a pessoa informada!");
                else if(maior == v->idade)
                    printf("\nVizinho e pessoa informada tem a mesma idade!");
                else
                    printf("\nPessoa informada e mais velha que vizinho!");
            }
            else{// Se nao for nem o primeiro nem o ultimo da lista.
                //Pega a idade do anterior e compara com a do proximo para ver qual eh mais velho.
                maior = v->ant->idade;
                if(v->prox->idade > maior)
                    maior = v->prox->idade;
                    printf("\nIdade do Vizinho mais velho: %d anos!", maior);
                //Verifica se o vizinho mais velho eh mais velho, novo ou se tem a mesma idade do vizinho escolhido.
                if(maior > v->idade)
                    printf("\nVizinho e mais velho do que a pessoa informada!");
                else if(maior == v->idade)
                    printf("\nVizinho e pessoa informada tem a mesma idade!");
                else
                    printf("\nPessoa informada e mais velha que vizinho!");
            }
        }
        v = v->prox;
    }
}

void mostraPessoas(Pessoa* p){
    //Mostra os dados de todos os vizinhos.
    Pessoa* mostra = NULL;
    mostra = p;
    printf("\n\nPessoas Informadas: ");
    printf("\nCPF | NOME | IDADE");
    do{
        printf("\n%s | %s | %d", mostra->cpf, mostra->nome, mostra->idade);
            if(mostra->prox == NULL){
            break;
        }
        mostra = mostra->prox;
    }while(1);
}