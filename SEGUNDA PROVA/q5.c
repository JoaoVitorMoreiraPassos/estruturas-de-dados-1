#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

typedef struct{
    char nome[50];
    int jogos;
    int gols;
    int assistencias;
}jogadorDeFutebol;

void start(jogadorDeFutebol **jogador);
void atribui(jogadorDeFutebol **jogador, int cod);
void imprime(jogadorDeFutebol **jogador, int cod);
void somaEstatistica(jogadorDeFutebol **jogador, int cod1, int cod2);
void ehBom(jogadorDeFutebol **jogador, int cod);
void liberarMemoria(jogadorDeFutebol **jogador, int cod);

void main(){
  jogadorDeFutebol *jogador[MAX];

  start(jogador);
  while(1){//Menu de escolhas.
    int num, num2;
    printf("\n======================================\n");
    printf("1 - Adicionar Jogador\n2 - Ver dados\n3 - Somar estatisticas");
    printf("\n4 - Ver se e Bom\n5 - Liberar Memoria\n0 - Encerrar -> ");
    scanf("%d",&num);
    printf("======================================\n\n");
    switch(num){//O switch irah dizer qual funcao chamar de acordo com a escolha do usuario.
      case 1:
        printf("Informe uma posicao para preencher de %d a %d: ", 1, MAX);
        scanf("%d", &num);
        atribui(jogador, num);
        break;
      case 2:
        printf("\nQual jogador de %d a %d vc deseja ver os dados: ", 1, MAX);
        scanf("%d", &num);
        imprime(jogador, num);
        break;
      case 3:
        printf("\nQuais jogadores de %d a %d vc deseja somar as estatisticas: ", 1, MAX);
        scanf("%d %d", &num, &num2);
        somaEstatistica(jogador, num, num2);
        break;
      case 4:
        printf("\nQual jogador de %d a %d vc deseja ver se e bom: ", 1, MAX);
        scanf("%d", &num);
        ehBom(jogador, num);
        break;
      case 5:
        printf("Qual posicao de Jogador de %d a %d deseja liberar memoria: ", 1, MAX);
        scanf("%d", &num);
        liberarMemoria(jogador, num);
        break;
      default:
        break;
    }
    if(num == 0)
      break;
  }
}

void start(jogadorDeFutebol **jogador){
  int i;
//  Inicializa com NULL o struct que é um vetor de jogadores, ate a quantidade total de jogadores. 
  for(i = 0; i < MAX; i++){
    jogador[i] = NULL;
  }
}

void atribui(jogadorDeFutebol **jogador, int cod){
  
  if(cod < 0 || cod > MAX){//Verifica se o codigo passado estah nos limites do vetor.
    printf("Indice fora do limite de Jogadores!");
  }
  if(jogador[cod-1] == NULL){//Verifica se nessa posicao do vetor nao tem nenhum jogador cadastrado, se nao tiver, coleta os dados de um novo jogador.
    jogador[cod-1] = (jogadorDeFutebol *) malloc(sizeof(jogadorDeFutebol));
    printf("\n");
    printf("Nome do Jogador %d: ", cod);
    scanf(" %[^\n]s", jogador[cod-1]->nome);
    printf("Quantos jogos o jogador %d jogou: ", cod);
    scanf("%d", &jogador[cod-1]->jogos);
    printf("Quantos Gols o jogador %d fez: ", cod);
    scanf("%d", &jogador[cod-1]->gols);
    printf("Quantas assistencias o jogador %d deu: ", cod);
    scanf("%d", &jogador[cod-1]->assistencias);
  }
  else{
    printf("Posição ja ocupada!");
  }
}

void imprime(jogadorDeFutebol **jogador, int cod){//Mostra os dados de um jogador.
  if(cod < 0 || cod > MAX){//Verifica se o codigo passado estah nos limites do vetor.
    printf("Indice fora do limite de Jogadores!");
  }
  if(jogador[cod-1] != NULL){//Verifica se a posicao passada nao estah vazia, se nao estiver, mostra os dados do jogador.
    printf("\n%d - Jogador: %s", cod, jogador[cod-1]->nome);
    printf("\n%d - Jogos: %d", cod, jogador[cod-1]->jogos);
    printf("\n%d - Gols: %d", cod, jogador[cod-1]->gols);
    printf("\n%d - Assistencias: %d\n", cod, jogador[cod-1]->assistencias);
  }
  else{
    printf("Posicao Vazia!\n");
  }
}

void somaEstatistica(jogadorDeFutebol **jogador, int cod1, int cod2){//Mostra a soma das estatisticas de dois jogadores.
  if(cod1 < 0 || cod1 > MAX || cod2 < 0 || cod2 > MAX){//Verifica se o codigo passado estah nos limites do vetor.
    printf("Algum indice fora do limite de Jogadores!");
  }
  if(jogador[cod1-1] != NULL && jogador[cod2-1] != NULL){//Verifica se as posicoes passadas nao estao vazias, se nao estiver, mostra a soma das estatisticas dos jogadores.
    printf("\nJogadores: %s e %s", jogador[cod1-1]->nome, jogador[cod2-1]->nome);
    printf("\n-Estatisticas Somadas-");
    printf("\n - Jogos: %d", jogador[cod1-1]->jogos+jogador[cod2-1]->jogos);
    printf("\n - Gols: %d", jogador[cod1-1]->gols+jogador[cod2-1]->gols);
    printf("\n - Assistencias: %d", jogador[cod1-1]->assistencias+jogador[cod2-1]->assistencias);
  }
  else{
    printf("Um dos Jogadores nao foi Inserido!\n");
  }
}

void ehBom(jogadorDeFutebol **jogador, int cod){
  if(cod < 0 || cod > MAX){//Verifica se o codigo passado estah nos limites do vetor.
    printf("Indice fora do limite de Jogadores!");
  }
  if(jogador[cod-1] != NULL){//Verifica se a posicao passada nao estah vazia.
    if(jogador[cod-1]->gols >= jogador[cod-1]->jogos){//Primeiro criterio eh se o jogador tem mais gols ou a mesma quantidade de partidas.
      printf("O jogador %s eh muito Bom\n", jogador[cod-1]->nome);
    }
    else{// Caso nao atenda o primeiro criterio, vemos se ele tem muitas assistencias.
      if(jogador[cod-1]->assistencias >= jogador[cod-1]->jogos){
        printf("O jogador %s esta jogando Bem\n", jogador[cod-1]->nome);
      }else{//Se nao atender a nenhum dos criterios, informa que o jogador nao estah bem.
        printf("O jogador %s nao esta em jogando bem", jogador[cod-1]->nome);
      }
    }
  }
  else{
    printf("Jogador %d nao foi adicionado ainda!\n", cod);
  }
}

void liberarMemoria(jogadorDeFutebol **jogador, int cod){

  if(cod < 0 || cod > MAX){//Verifica se o codigo passado estah nos limites do vetor.
    printf("Indice fora do limite de Jogadores!");
  }
  if(jogador[cod-1] != NULL){//Verifica se a posicao passada nao estah vazia.
    free(jogador[cod-1]);//libera a memoria depois atriui nulo.
    jogador[cod-1] = NULL;
    printf("Memoria Liberada com Sucesso.");
  }
  else{
    printf("Essa posicao ja esta liberada!\n");
  }
}