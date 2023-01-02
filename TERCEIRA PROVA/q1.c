#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct carro Carro;
struct carro{
	char placa[MAX][7];
	int movs[10];
	int fim;
};

void carro_inicializa(Carro* c);
void entra_carro(Carro* c, char *str, int mov);
void sai_carro(Carro* c, char *str);
void pop(Carro *c);
int est_cheio(Carro* c);
int est_vazio(Carro* c);
int existeCarro(Carro* c, char *str);

void main (){
	Carro carro;
	carro_inicializa(&carro);
	char c, placa[7]; 
	int stop = 0;
	//Menu de navegacao do usuario.
	while(stop != 1){
		printf("\nDeseja entrar[E] ou sair[S] do estacionamento: ");
		setbuf(stdin,NULL);
		scanf(" %c", &c);
		imprime(&carro);
		switch(c){
			case 'E'://Inserir carro.
				printf("\nInforme a placa do veiculo que vai entrar: ");
				scanf("%s", &placa);
				entra_carro(&carro, placa, 0);
				break;
			case 'S'://Retirar carro.
				printf("\nInforme a placa do veiculo que vai sair: ");
				scanf("%s", &placa);
				sai_carro(&carro, placa);
				break;
			default:
				printf("\nOPCAO INVALIDA!!");
				break;
		}
		printf("\nDeseja encerrar [0]NAO [1]SIM: ");// Encerra o programa.
		scanf("%d", &stop);
	}
	imprime(&carro);
}
void carro_inicializa(Carro* c){
		c->fim = -1;
}
void pop(Carro *c){
		//Remove o primeiro item da lista.
		int i;
		for(i = 0; i < c->fim; i ++){
			strcpy(c->placa[i], c->placa[i+1]);
			c->movs[i] = c->movs[i+1];
		}
		c->fim -= 1;
}

int est_cheio(Carro* c){
// Verifica se o estacionamento esta cheio.
		if(c->fim >= MAX-1){
			return 1;
		} 
		return 0;
}

int est_vazio(Carro* c){
// Verifica se o estacionamento esta vazio.
		if(c->fim == -1)
			return 1;
		return 0;
}
void entra_carro(Carro* c, char *str, int mov){
		//Insere um carro no estcionamento.
		if(est_cheio(c) == 0){
			c->fim ++;
			strcpy(c->placa[c->fim], str);
			c->movs[c->fim] = mov;
		}
		else{
			printf("\nEstacionamento esta cheio");
		}
}
void sai_carro(Carro* c, char *str){
	//Retira um carro escolhido pelo usuario.
	int aux, i, num_movs;
	if(est_vazio(c) == 0){// Verifica se o estacionamento esta vazio.
		aux = existeCarro(c, str);// A variavel aux recebera a posicao do carro se ele existir ou -1 se ele nao estiver o estacionamento.
		if( aux != -1){//Verifica se o carro existe.
			int mov_aux, mov_car;
			char placa_aux[7], prime[7];
			strcpy(prime, c->placa[0]);//Salva a placa do carro esta mais proximo da saida.
			num_movs = aux;//Representa a quantidade de carros que serao movido para o carro selecionado sair.
			i = 0;
			if(strcmp(prime, str) == 0){//Verifica se o carro eh o mais proximo da saida.
				mov_car = c->movs[0];//Salva a quantidade de vezes que esse carro se movimentou para outros carros sairem.
				pop(c);//Remove o carro.
			}else{//Se o carro nao for o primeiro.
				do{
					if(strcmp(str, c->placa[i]) != 0){//Se nao for o carro procurado.
						//Remove o carro mais proximo da saida e o adiciona no fim da fila.
						mov_aux = c->movs[i]+1;
						strcpy(placa_aux, c->placa[i]);
						pop(c);
						entra_carro(c, placa_aux, mov_aux);
					}else{//Se for o carro procurado.
						//Apena remove o carro e salva quantas vezes o carro manobrou para outros carros sairem.
						mov_car = c->movs[i];
						pop(c);
					}
				}while(strcmp(prime, c->placa[i]) != 0);//Repete o laco ate que o primeiro carro mais proximo da saida volte ao inicio da fila.
			}
			//Mostra os dados pedidos na questao.
			printf("----------------------------------------\n:: Se moveu %d vez(es) para outros carros sairem.\n", mov_car);
			printf(":: %d carros se moveram para ele sair.\n", num_movs);
			printf("   Uma vaga surgiu.\n----------------------------------------\n");
		}
		else{//Se o carro nao estiver no estacionamento.
			printf("\nCarro com esta placa nao esta estacionado!");
		}
	}
	else{//Se o estacionamento estiver vazio.
		printf("\nEstacionamento esta vazio!!");
	}
}

int existeCarro(Carro* c, char *str){
	// Verifica se o carro com a placa informada esta estacionada;
	int i;
	for(i = 0; i <= c->fim; i++){
		if(strcmp(c->placa[i], str) == 0){
				return i;
		}
	}
	return -1;
}

void imprime(Carro *c){
	//Mostra as vagas do estacionamento preenchidas ou vagas.
	int i;
	printf("Saida |");
	for (i = 0; i < MAX; i ++){
		if(i <= c->fim){
				printf(" %s |", c->placa[i]);
		}else{
				printf(" vago |");
		}
	}
	printf(" Entrada\n");
}