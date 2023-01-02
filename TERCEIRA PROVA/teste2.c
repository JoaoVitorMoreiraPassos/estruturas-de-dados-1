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


Fila* fila_inicializa();
Fila* fila_insere(Fila* f, char *str, int movs);
Fila*sair(Fila *f, char *str);
Fila* alocaNo(char *str, int movs);
Fila* pop(Fila *f);
int existeCarro(Fila *f, char *str);

int filaCheia(Fila *f);
void imprime(Fila *f);

void main(){
    int acao, i = 0;
    char placa[7];
    Fila *fi;
    fi = fila_inicializa();
    while(!i){
        printf("1 - Entrar.\n2 - Tirar o Carro.\n3 - Encerrar\nEscolha: ");
        scanf("%d", &acao);
        switch(acao){
            case 1:
                imprime(fi);
                printf("Numero da placa: ");
                scanf(" %s",placa);
                fi = fila_insere(fi, placa,0);
                break;
            case 2:
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
    imprime(fi);
}

Fila* fila_inicializa (){
  return NULL;
}
Fila* pop(Fila *f){
    if(f == NULL || f->prox == NULL){
        return NULL;
    }
    Fila *aux = f;
    f = f->prox;
    free(aux);
    return f;
}
int fila_vazia(Fila* f){
    if(f == NULL)
        return 1;
    return 0;
}

int filaCheia(Fila *f){
    Fila *p;
    int fim = 0;
    for (p = f; p != NULL; p = p->prox){
        fim ++;
    }
    if(fim == max){
        return 1;
    }
    return -1;
}

Fila* fila_insere(Fila* f, char *str, int movs){
    int cheia = filaCheia(f);
    Fila *novo = alocaNo(str, movs);
    if(cheia == -1){ 
        if(fila_vazia(f)){
            f = novo;
        }else{
            if(existeCarro(f,str) == 0){
                Fila* atual = f;
                while(atual->prox != NULL){
                    atual = atual->prox;
                }
                atual->prox = novo;
            }else{
                printf("Carro ja existe.\n");
            }
        }
    }
    else{
        printf("Estacionamento lotado\n");
    } 
    return f;
}
Fila* alocaNo(char *str, int movs){
  Fila* no = (Fila*) malloc(sizeof(Fila));
  strcpy(no->info, str);
  no->movs = movs;
  no->prox = NULL;
  return no;
}

Fila* sair(Fila* f, char *str){
    Fila *p, *aux, *aux1;
    char infoaux[7], prime[7];
    int num_movs = 0, movsaux, movstemp;
    aux1 = NULL;
    if(!fila_vazia(f)){
        for (p = f; p != NULL; p = p->prox){
            if(strcmp(str, p->info) == 0){
                movsaux = p->movs;
                aux = f;
                f = p;
                break;
            }
            aux1 = p;
        }
        if(p == NULL){
            printf("Nenhum veiculo com essa placa.\n");
            return f;
        }
        if(aux->prox == NULL){
            return NULL;
            printf("--------------\nSurgiu 1 vaga!\n");
            printf(":: Esse carro manobrou %d vez(es) para outros carros sairem.\n", aux->movs);
            printf(":: %d carros se movimentaram para ele sair.\n-------------\n", 0);
        }else{
            strcpy(prime, aux->info);
            for(p = aux; p != f; p = p->prox){
                num_movs ++;
                p->movs ++;
                f = fila_insere(f, p->info, p->movs);
            }
            imprime(f);
            f = pop(f);
            if(!(f->prox == NULL) && aux1 != NULL){
                for(p = f; strcmp(p->info , prime) != 0;p = f){
                    p->movs ++;
                    movstemp = p->movs;
                    strcpy(infoaux, p->info);
                    f = pop(f);
                    f = fila_insere(f,infoaux,movstemp);
                }
            }else{
                printf("aqui\n");
            }
        }
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
    Fila *p;
    for (p = f; p != NULL; p = p->prox){
        if(strcmp(str, f->info) == 0){
            return 1;
        }
    }
    return 0;
}
void imprime(Fila *f){
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