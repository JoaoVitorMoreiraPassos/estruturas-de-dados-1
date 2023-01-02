#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 10
typedef struct fila Fila;

struct fila{
  char info[7];
  int movs;
  Fila* prox;
};


Fila* inicializa();
Fila* insere(Fila* f, char *str, int movs);
Fila* sair(Fila *f, char *str);
Fila* alocaNo(char *str, int movs);
Fila* pop(Fila *f);
int existeCarro(Fila *f, char *str);

int filaCheia(Fila *f);
void imprime(Fila *f);

void main(){
    int acao, i = 0;
    char placa[7];
    Fila *fi;
    fi = inicializa();
    //Menu de navegacao para o usuario.
    while(!i){
        printf("1 - Entrar.\n2 - Tirar o Carro.\n3 - Encerrar\nEscolha: ");
        scanf("%d", &acao);
        switch(acao){
            case 1://Insere carro.
                imprime(fi);
                printf("Numero da placa: ");
                scanf(" %s",placa);
                fi = insere(fi, placa,0);
                break;
            case 2://Remove carro.
                imprime(fi);
                printf("Numero da placa: ");
                scanf(" %s", placa);
                fi = sair(fi,placa);
                break;
            default:
                i = 1;
                break;
        }
    }
    //Mostra a situacao final do estacionamento.
    imprime(fi);
}

Fila* inicializa (){
  return NULL;
}
Fila* pop(Fila *f){
    //Remove o carro mais proximo da saida.
    if(fila_vazia(f) || f->prox == NULL){//Verifica se a fila e vazia ou se ele e o unico no estacionamento.
        return NULL;
    }
    //Se nao
    //Passa a refencia da fila para o segundo carro mais proximo da saida e libera a antiga primeira.
    Fila *aux = f;
    f = f->prox;
    free(aux);
    return f;//retorna a fila com a nova referencia.
}
int fila_vazia(Fila* f){
    //Verifica se a lista esta vazia.
    if(f == NULL)
        return 1;
    return 0;
}

int filaCheia(Fila *f){
    //Verifica se a lista esta cheia.
    Fila *p;
    int fim = 0;
    for (p = f; p != NULL; p = p->prox){//Percorre toda a fila contando quantos elementos existem na fila.
        fim ++;
    }
    if(fim == max){// Se a quantidade de carros for igual a quantidade de vagas entao retorna 1.
        return 1;
    }
    // Se nao retorna -1.
    return -1;
}

Fila* insere(Fila* f, char *str, int movs){
    //Adiciona um carro no estacionamento.
    int cheia = filaCheia(f);
    Fila *novo = alocaNo(str, movs);// Cria um novo no.
    if(cheia == -1){ //Verifica se a fila esta cheia.
        if(fila_vazia(f)){// Verifica se a fila esta vazia.
            f = novo;//Apenas atribui o para a fila.
        }
        else{
            //Se ja tiver algum carro na fila.
            if(existeCarro(f,str) == 0){//Se o carro nao estiver no estacionamento.
                //Percorre a fila ate chegar ao ultimo item.
                Fila* atual = f;
                while(atual->prox != NULL){
                    atual = atual->prox;
                }
                //Adiciona o no no final da fila.
                atual->prox = novo;
            }else{//Se o carro ja estiver no estacionamento.
                printf("Carro ja existe.\n");
            }
        }
    }
    else{//Se o estacionamento estiver lotado.
        printf("Estacionamento lotado\n");
    } 
    return f; //Retorna a fila.
}
Fila* alocaNo(char *str, int movs){
    //Cria um no.
    Fila* no = (Fila*) malloc(sizeof(Fila));
    strcpy(no->info, str);
    no->movs = movs;
    no->prox = NULL;
    return no;
}

Fila* sair(Fila* f, char *str){
    //Remove um carro do estacionamento.
    Fila *p, *aux, *aux1;
    char infoaux[7], prime[7];
    int num_movs = 0, movsaux, movstemp;
    aux1 = NULL;
    if(!fila_vazia(f)){//Verifica se nao esta vazia.
        for (p = f; p != NULL; p = p->prox){//Procura pelo carro.
            /*Se encontrar
              Salva quantas vezes ele se movimentou para outros carros sairem.
              Passa a referencia da lista para o auxiliar.
              A fila tera como refencia o carro a ser removido.*/
            if(strcmp(str, p->info) == 0){
                movsaux = p->movs;
                aux = f;
                f = p;
                break;
            }
            // Salva o elemento anterior.
            aux1 = p;
        }
        //Se o carro nao foi encontrado.
        if(p == NULL){
            printf("Nenhum veiculo com essa placa.\n");
            return f;
        }
        //Se o carro for o unico na fila.
        if(aux->prox == NULL){
            printf("--------------\nSurgiu 1 vaga!\n");
            printf(":: Esse carro manobrou %d vez(es) para outros carros sairem.\n", aux->movs);
            printf(":: %d carros se movimentaram para ele sair.\n-------------\n", 0);
            return NULL;
        }else{//Se tiver mais de um elemento na fila.
            strcpy(prime, aux->info);//Salva a placa do carro mais proximo da saida.
            for(p = aux; p != f; p = p->prox){
                /*Como a fila agora so tem a refencia do carro a ser removido ate os ultimos,
                  adicionamos os primeiros no fim da fila.*/
                num_movs ++;
                p->movs ++;
                f = insere(f, p->info, p->movs);
            }
            f = pop(f);//Com o carro selecionado pelo usuario no inico da fila ele serah removido.
            //Se a lista ainda tiver mais que um elemento.
            if(!(f->prox == NULL)){
                for(p = f; strcmp(p->info , prime) != 0;p = f){
                    /*Para realocar os primeiros carros a chegar na sua posicao inicial
                      Remove-se os que agora estao na frente e o os adicionam atras na fila.
                      Ate que o primeiro item esteja de volta ao inicio da fila ou saida do estacionamento.*/
                    p->movs ++;
                    movstemp = p->movs;
                    strcpy(infoaux, p->info);
                    f = pop(f);
                    f = insere(f,infoaux,movstemp);
                }
            }
        }
        //Mostra os dados.
        printf("--------------\n");
        imprime(f);
        printf("--------------\nSurgiu 1 vaga!\n");
        printf(":: Esse carro manobrou %d vez(es) para outros carros sairem.\n", movsaux);
        printf(":: %d carros se movimentaram para ele sair.\n-------------\n", num_movs);
        return f;
    }else{
        printf("Lista Vazia.\n");
        return f;
    }
}

int existeCarro(Fila *f, char *str){
    //Varre a lista procurando por um carro com a placa informada pelo usuario.
    Fila *p;
    for (p = f; p != NULL; p = p->prox){
        if(strcmp(str, f->info) == 0){
            return 1;
        }
    }
    return 0;
}
void imprime(Fila *f){
    //Mostra as vagas do estacionamento preenchidas ou vagas.
    Fila *p;
    int i = 0,j;
    printf("Saida ");
    for (p = f; p != NULL; p = p->prox){
        if(p == f){
            printf("| %s |", p->info);
        }else{
            printf(" %s |", p->info);
        }
        i ++;
    }
    for(j = i; j < max; j ++){
        if(j == 0){
            printf("| vago |");
        }else{
            printf(" vago |");
        }  
    }
    printf(" Entrada\n");
}