#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tot_livros = 0;

typedef struct{
    int codigo;
    char *titulo;
    char *autor;
    char *editora;
    int ano;
    int n_exemplares;
}Livro;

void insereLivros(Livro **livros);//Insere Livros em um vetor de uma matriz do tipo Livro.
void mostraPorEditora(Livro **livros, char *editora);//Mostra Livros por editora.
void mostraPorAutor(Livro **livros, char *autor);//Mostra Livors por autor.
void removeLivros(Livro **livros, int cod);//Remove Livros de um vetor de um a matriz do tipo Livro.


int main(){
    Livro **livros;
    livros = (Livro **) calloc(1,sizeof(Livro*));//Aloca a matriz com uma linha.
    if(livros == NULL){
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    int escolha, encerra, codigo;
    char temp[30];
    while (1){//Menu de escolha.
        printf("Inserir Livro[1].\nMostrar Livro Por Editora[2]\nMostrar Livro Por Autor[3].\nRemover Livro[4].\nEncerrar[qualquer outro num].\n");
        printf("------------------------\n");
        printf("escolha: ");
        scanf("%d", &escolha);
        printf("------------------------\n");
        switch (escolha)
        {//O switch irah dizer qual funcao chamar de acordo com a escolha do usuario.
        case 1:
            insereLivros(livros);
            break;
        case 2:
            printf("Digite o nome da editora: ");
            scanf(" %[^\n]s", temp);
            mostraPorEditora(livros, temp);
            break;
        case 3:
            printf("Digite o nome da autor: ");
            scanf(" %[^\n]s", temp);
            mostraPorAutor(livros, temp);
            break;
        case 4:
            printf("Digite o codigo do livro a ser removido: ");
            scanf(" %d", &codigo);
            removeLivros(livros, codigo);
            break;
        default:
            encerra = 1;
            break;
        }
        if(encerra == 1){
            break;
        }
    }
    int i;
    for (i = 0; i <tot_livros; i ++){
        printf("%d %s\n", livros[0][i].codigo, livros[0][i].titulo);
    }
    free(livros[0]);
    free(livros);
    return 0;
}


void insereLivros(Livro **livros){
    int i = 0, encerra;
    char temp[50];
    while (1)
    { 
        printf("Deseja encerra. [1: Sim, 0: Nao]: ");
        scanf("%d", &encerra);
        if(encerra == 1){//serve para parar a coleta de dados dos livros.
            break;
        }
        if(tot_livros == 0){// Se a quantidade de livros for igual a 0, entao o vetor sera alocado com o tamanho 1,
            livros[0] = (Livro *) calloc(1, sizeof(Livro));
        }
        else{// Senao sera realocado com a quantidade de livros que ele tera depois de adicionar mais um livro. Assim o vetor se ajusta de acordo com a quantidade de livros.
            livros[0] = (Livro *) realloc(livros[0], (tot_livros+1) * sizeof(Livro)); 
        }
        //Inicializa os dados do livro com NULL.
        livros[0][tot_livros].codigo = NULL;
        livros[0][tot_livros].titulo = NULL;
        livros[0][tot_livros].autor = NULL;
        livros[0][tot_livros].editora = NULL;
        livros[0][tot_livros].ano = NULL;
        livros[0][tot_livros].n_exemplares = NULL;
        //Coleta os dados do livro.
        printf("Codigo do livro: ");
        scanf("%d",&livros[0][tot_livros].codigo);

        printf("Nome do livro: ");
        scanf(" %[^\n]s", temp);
        livros[0][tot_livros].titulo = (char*) malloc((strlen(temp)+1) * sizeof(char));
        strcpy(livros[0][tot_livros].titulo, temp);

        printf("Editora do livro: ");
        scanf(" %[^\n]s", temp);
        livros[0][tot_livros].editora = (char*) calloc(strlen(temp)+1, sizeof(char));
        strcpy(livros[0][tot_livros].editora, temp);

        printf("Autor do livro: ");
        scanf(" %[^\n]s", temp);
        livros[0][tot_livros].autor = (char*) calloc(strlen(temp)+1, sizeof(char));
        strcpy(livros[0][tot_livros].autor, temp);

        printf("Ano de Lancamente: ");
        scanf("%d", &livros[0][tot_livros].ano);

        printf("Numero de exemplares: ");
        scanf("%d", &livros[0][tot_livros].n_exemplares);
        tot_livros ++;//Aumenta a quantidade de livros em 1.
    }
}

void mostraPorEditora(Livro **livros, char *editora){
    int i, achou = 0;
    for (i = 0; i < tot_livros; i ++){//Busca sequencialmente por um livro que tenha editor igual a buscada.
        if(strcmp(livros[0][i].editora , editora) == 0){
            printf("Cod: %d  |  Titulo: %s  |  Editora: %s |  Autor: %s  |  Ano: %d  |  N exe: %d\n", livros[0][i].codigo, livros[0][i].titulo, livros[0][i].editora, livros[0][i].autor, livros[0][i].ano, livros[0][i].n_exemplares);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("\nlivro nao encotrado!\n--------------------\n");
    }
}

void mostraPorAutor(Livro **livros, char *autor){
    int i, achou = 0;
    for (i = 0; i < tot_livros; i ++){//Busca sequencialmente por um livro que tenha o autor igual ao buscado.
        if(strcmp(livros[0][i].autor , autor) == 0){
            printf("Cod: %d  |  Titulo: %s  |  Editora: %s |  Autor: %s  |  Ano: %d  |  N exe: %d\n", livros[0][i].codigo, livros[0][i].titulo, livros[0][i].editora, livros[0][i].autor, livros[0][i].ano, livros[0][i].n_exemplares);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("\nlivro nao encotrado!\n--------------------\n");
    }
}

void removeLivros(Livro **livros, int cod){
    int i, j;
    if(tot_livros <= 1){
        if(livros[0][0].codigo == cod){
            free(livros[0][0].codigo);
            free(livros[0][0].titulo);
            free(livros[0][0].editora);
            free(livros[0][0].autor);
            free(livros[0][0].ano);
            free(livros[0][0].n_exemplares);
            tot_livros --;
        }  
    }else{
        for (i = 0; i < tot_livros; i ++){//Procura pelo livro que tem o codigo iqual ao recebido por parametro.
            if(livros[0][i].codigo == cod){
                printf("aqui\n");
                for(j = i; j < tot_livros; j ++){//Percorre da posicao do curso a ser removida ate a penultima.
                    printf("aqui1\n");
                // A posicao atual ira receber a posica posterior. assim o curso sera substituido e nao existira mais.
                    livros[0][j].codigo = livros[0][j+1].codigo;
                    livros[0][j].ano = livros[0][j+1].ano;
                    livros[0][j].n_exemplares = livros[0][j+1].n_exemplares;
                    strcpy(livros[0][j].editora, livros[0][j+1].editora);
                    strcpy(livros[0][j].autor, livros[0][j+1].autor);
                    strcpy(livros[0][j].titulo, livros[0][j+1].titulo);
                }
                //Libera a ultima posicao do vetor.
                free(livros[0][j].codigo);
                free(livros[0][j].titulo);
                free(livros[0][j].autor);
                free(livros[0][j].ano);
                free(livros[0][j].editora);
                free(livros[0][j].n_exemplares);
                //realoca o vetor para o ajustar a quantidade de livros.
                livros[0] = (Livro *) realloc(livros[0], (tot_livros-1) * sizeof(Livro));
                tot_livros --;//diminui em 1 a quantiade de livros.
            }
        }
    }
}