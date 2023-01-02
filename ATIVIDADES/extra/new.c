#include <stdio.h>
#include <string.h>

#define max 3

typedef struct
{
    int mat;
    char *nome;
    char *end;
    char *tel;
}Aluno;

char *aloc_char( int t);
Aluno *aloc_aluno(int t);
void retira(Aluno **v,int pos);
void imprime(Aluno **v, int pos);
void imprime_tudo(Aluno **v, int tam);
void inicializa(Aluno **v, int tam);
void preenche(Aluno **v, int pos);


void main(){
    int i;
    Aluno *tab[max];
    *tab = (Aluno **) calloc(max, sizeof(Aluno*));
    inicializa(tab, max);
    preenche(tab, 1);
    imprime(tab,1);
    retira(tab,1);
}
void inicializa(Aluno **v, int tam){
    int i;
    for(i = 0; i < tam; i ++){
        v[i] = NULL;
    }
}

void preenche(Aluno **v, int pos){
    int aux;
    char temp[181];
    if(v[pos] == NULL){

        v[pos] = (Aluno *) calloc(1,sizeof(Aluno));

        printf("matr: ");
        scanf("%d", &aux);
        v[pos][0].mat = aux;

        printf("nome: ");
        scanf(" %[^\n]s ",temp);
        v[pos][0].nome = aloc_char(strlen(temp)+ 1);
        strcpy(v[pos][0].nome, temp);

        printf("end: ");
        scanf(" %[^\n]s ",temp);
        v[pos][0].end = aloc_char(strlen(temp)+ 1);
        strcpy(v[pos][0].end, temp);
        printf("tel: ");

        scanf(" %[^\n]s ",temp);
        v[pos][0].tel = aloc_char(strlen(temp) + 1);
        strcpy(v[pos][0].tel, temp);
    }
}

void imprime(Aluno **v, int pos){
    if(v[pos] != NULL){
        printf("matr: %d\n",v[pos]->mat);
        printf("nome: %s\n",v[pos]->nome);
        printf("end: %s\n",v[pos]->end);
        printf("tel: %s\n",v[pos]->tel);
    }

}
void imprime_tudo(Aluno **v, int tam){
    int i;
    for (i = 0; i < tam; i ++){
        imprime(v,i);
    }
}


char *aloc_char(int t){
    int i;
    char *str;
    str = (char *) calloc(t, sizeof(char));
    if(str == NULL){
        printf("Erro: memoria insuficiente\n");
        exit(1);
    }

    return str;
}


void retira(Aluno **v,int pos){
    free(v[pos]);
    v[pos] = NULL;
}