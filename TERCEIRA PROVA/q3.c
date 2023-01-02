#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100

typedef struct pilha Pilha;

struct pilha{
    char info[TAM];
    int topo;
};

int isNumber(char c);
int isVal(char *str);
void pilha_inicializa (Pilha* p);
void pilha_push(Pilha* p, char valor);
char pilha_pop(Pilha *p);
void pilha_imprime(Pilha *p);
int pilha_cheia(Pilha* p);
int pilha_vazia(Pilha* p);
int Prioridade(char c, char t);
void inParaPos(char expr[]);


void main(){
  char expressao[100];
  //Pede para o usuario digitar a expressao;
  printf("Digite uma expressao: ");
  scanf("%100[^\n]s", expressao);
  //Se a expressao for valida chama a funcao inParaPos para transforma-la em posfixa.
  if(isVal(expressao)){inParaPos(expressao);}
  //Se nao, mostra que a expressao eh invalida.
  else{printf("Expressao invalida.\n");}
}
void inParaPos(char *expressao){
    Pilha p;
    int i, j,tposf = 0;
    char c,t, posfixa[TAM];
    pilha_inicializa(&p);//Incializa a pilha.
    pilha_push(&p, '(');//Adiciona um parenteses inicial na lista.
    i = 0;
    do{
        c = expressao[i];//Pega o caractere da posicao i da expressao.
        i++;//incrementa o i;
        if(isNumber(c)){//Se o caratere atual e um numero.
            posfixa[tposf] = c;//Adiciona o caractere na ultima posicao da string que vai ser a expressao posfixa.
            tposf ++;//Muda a ultima posicao da posfixa.
            while (isNumber(expressao[i])){// Enquanto os proximos caracteres forem numeros.
                posfixa[tposf] = expressao[i];tposf ++;//Adiciona o caractere da posicao i da expressao e muda a ultima posicao da posfixa.
                i ++;
            }printf(" ");posfixa[tposf] = ' ';tposf ++;//Adiciona um espaco e muda a ultima posicao na posfixa
        }
        else if(c == '('){// Se o c for igual a '(' adiciona-o na pilha.
            pilha_push(&p, '(');
        }
        else if(c == ')' || c == '\0'){//Se o c for igual a ')' ou '\0'.
            /*Enquanto nao chegar o parenteses de abertura da um pop na pilha e salva o valor removido para adicionar
              na posfixa, no caso serao os operadores. */
            do{
                t = pilha_pop(&p);
                if(t != '('){
                    posfixa[tposf] = t;tposf ++;
                    posfixa[tposf] = ' ';tposf ++;
                }
            }while(t != '(');
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/'){// Se o c for igual a um operador.
            //Verifica a prioridade do ultimo sinal adicionado a pilha e o novo que chegou.
            //Se a prioridade do atual for maior que o ultimo adicionado na pilha, adiciona ele na pilha e para o laco.
            //Se nao, adiciona o ultimo elemento da pilha que foi removido e adiciona na posfixa.
            while(1){
                t = pilha_pop(&p);
                if(Prioridade(c, t)){
                    pilha_push(&p, t);
                    pilha_push(&p, c);
                    break;
                }
                else{
                    // printf("%c ", t);
                    posfixa[tposf] = t;tposf++;
                    posfixa[tposf] = ' ';tposf++;
                }
            }
        }
    }while(c != '\0');//Para quando chegar no fim da expressao.
    posfixa[tposf] = '\0';//finaliza a posfixa.
    printf("\nposfixa: %s\n",posfixa); //Mostra a posfixa.  
}
int Prioridade(char c, char t){
    int pc,pt;
    //Pega preferencia dos sinail.
    if(c == '*' || c == '/')
        pc = 2;
    else if(c == '+' || c == '-')
        pc = 1;
    else if(c == '(')
        pc = 0;
    
    if(t == '*' || t == '/')
        pt = 2;
    else if(t == '+' || t == '-')
        pt = 1;
    else if(t == '(')
        pt = 0;
    
    return (pc > pt);//Se a prioridade do c for maior que a do t retorna 1, senao retorna 0;
}

void pilha_inicializa (Pilha* p){
    //Inicializa a pilha estatica.
    p->topo = -1;
}

int pilha_cheia(Pilha* p){
  if(p->topo >= TAM - 1)
    return 1;
  return 0;
} 
int pilha_vazia(Pilha* p){
  if(p ->topo == -1)
    return 1;
  return 0;
}
void pilha_push(Pilha* p, char valor){
    //Empilha um item em uma pilha estatica.
    if(pilha_cheia(p) == 0){           
        p->topo++;                       
        p->info[p->topo] = valor;          
    }else{ 
        printf("Pilha esta Cheia!!");
    }
}                                     
                                    
char pilha_pop(Pilha *p){
    // Desimpilha uma pilha estatica, e retorna o valor removido.
    char valor;
    if(pilha_vazia(p) == 0){
        valor = p->info[p->topo];
        p->topo--;
    }else{
        printf("\nPilha ja esta Vazia!!");
    }
    return valor;
}

int isVal(char *str){
    // Verifica a quantidade de parenteses para ver se a expressao eh valida.
    int i, qtabre = 0, qtfecha = 0;
    for(i = 0; str[i] != '\0'; i ++){
        if(str[i] == '('){
            qtabre ++;
        }
        if(str[i] == ')'){
            qtfecha ++;
        }
    }
    return (qtabre == qtfecha);//Se a quantidade de aberturas for a mesma de fechaduras retorna 1 senao retorna 0;
}
int isNumber(char c){
    //Verifica se um caractere e um numero ou nao;
    //Se sim retorna 1, senao retorna 0;
    switch(c){
        case '1': return 1; break;
        case '2': return 1; break;
        case '3': return 1; break;
        case '4': return 1; break;
        case '5': return 1; break;
        case '6': return 1; break;
        case '7': return 1; break;
        case '8': return 1; break;
        case '9': return 1; break;
        case '0': return 1; break;
        default: return 0; break;
    }
}