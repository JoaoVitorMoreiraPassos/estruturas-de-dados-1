#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * indexs(char *str, char c, int *size);

int main(){
    int *v, tam, i;

    char *str;
    str = (char*) calloc(100, sizeof(char));//Aloca dinamicamente uma string com capacidade de receber 100 caracteres.

    if(str == NULL){
        printf("Memoria insufiente\n");
        exit(1);
    }
    strcpy(str, "luana batista");//Atribui o valor para a string.

    v = indexs(str, 'a', &tam);//Chama a funcao para ver quantas vezes um caractere se repete em uma string.
    for (i = 0; i < tam; i ++){//mostrara os indices onde o caractere foi encotrado.
        printf("%d - ",v[i]);
    }
    
    printf("\n");
    free(str);
    free(v);
    return 0;
}

int * indexs(char *str, char c, int *size){
    int i, len = strlen(str);
    int *array;
    *size = 0;
    for (i = 0; i < len; i ++){//Irah percorrer a string recebida por parametro.
        if(str[i] == c){//Se encotrar o caractere.
            if(*size == 0){//Verifica quantas vezes o caractere foi encontrado para fazer a alocao ou realocacao dinamica do vetor.
                array = (int *) calloc(1, sizeof(int));
                if(array == NULL){
                    printf("Memoria insuficiente\n");
                    exit(1);
                }
            }else{
                array = (int *) realloc(array, (*size+1) * sizeof(int));
                if(array == NULL){
                    printf("Memoria insuficiente\n");
                    exit(1);
                }
            }
            array[*size] = i;//Adiciona o indice na ultima posicao do vetor.
            ++ *size;//aumenta o tamanho do vetor.
        }
    }
    return array;// Retorna o vetor com os indices onde o caractere pode ser encontrado.
}