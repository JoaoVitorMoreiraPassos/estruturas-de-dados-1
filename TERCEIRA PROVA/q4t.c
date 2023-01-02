#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhaD PilhaD;
struct pilhaD{
    float info;
    PilhaD* prox;
};

PilhaD* pilhaD_inicializa();
int pilhaD_vazia(PilhaD* p);
PilhaD* alocaNo(float valor);
PilhaD* pilhaD_push(PilhaD* p, float valor);
PilhaD* pilhaD_pop(PilhaD** p);
float operacao(float a, float b, char x);
void resolveExpressao(char *x);

void main(){
    char exp[100] = {"20 2   10 + * 5 /"};

// Infixa                      Pós-fixa(NA POS FIXA NAO TEM PARENTESES)
// (51+13*12)                  51 13 12 * +                R = 207
// (5*(3+2)/4-6)               5 3 2 + * 4 / 6 -           R = 0,25
// (5+3+2*4-6*7*1)             5 3 + 2 4 * + 6 7 * 1 * -   R = -26
// (5*(3+(2*(4+(6*(7+1))))))   5 3 2 4 6 7 1 + * + * + *   R = 535

    resolveExpressao(exp);
}

PilhaD* pilhaD_inicializa(){
  return NULL;
}
int pilhaD_vazia(PilhaD* p){//Verifica se a pilha esta vazia.
    if(p == NULL)
        return 1;
    return 0;
}
PilhaD* alocaNo(float valor){//Cria um no de uma pilha.
    PilhaD* no = (PilhaD*) malloc(sizeof(PilhaD));
    no->info = valor;
    no->prox = NULL;
    return no;
}
PilhaD* pilhaD_push(PilhaD* p, float valor){// Insere um valor em uma pilha dinamica.
    PilhaD *novo = alocaNo(valor);
    novo->prox = p;
    return novo;
}

PilhaD* pilhaD_pop(PilhaD** p){// Remove um elemento de uma pilha e retorna o elemento removido.
    PilhaD* remove;
    if(pilhaD_vazia(*p) == 0){
        remove = *p;
        *p = remove->prox;
    }
    return remove;
}
void resolveExpressao(char *x){
    int n = 0, s = 0;
    char *pt;
    float num;
    PilhaD *n1, *n2, *pi = NULL;

    pt = strtok(x, " ()"); // Irah separar a string por espacos e parenteses.
    while(pt){//Enquanto nao chegar no '\0'.
        printf("pt = %s - ", pt);
        if(pt[0]== '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            //Se o pt for um operador.
            //Pega os dois ultimos numeros da pilha.
            //Atribui em num o resultado da operacao desses dois numeros e o empilha em pi.
            n2 = pilhaD_pop(&pi);
            n1 = pilhaD_pop(&pi);
            num = operacao(n1->info, n2->info, pt[0]);
            pi = pilhaD_push(pi, num);
            free(n1);
            free(n2);
            s++;
        }
        else{// Se o pt for um numero.
            num = strtol(pt, NULL, 10);//Converte de string para numero.
            if(pt[0] == '0'){//Como a funcao retorna 0 se o valor passado nao for um numero, verifica se o valor da string eh 0 para evitar confusoes.
                num = 0;
                pi = pilhaD_push(pi, num);//Empilha o numero em pi.
            }else{//Se for um numero diferente de 0.
                //Empilha o o numero em pi e verifca se num eh igual 0, pois nesse caso, se for, eh porque ele nao era um numero.
                pi = pilhaD_push(pi, num);
                if(num == 0){
                    printf("\nEXPRESSAO INVALIDA!");
                    exit(1);
                }
            }
            n++;
        }
        pt = strtok(NULL, " ()");//Passa para o proximo valor.
        printf("ptf = %s\n",pt);
    }
    printf("pt = %s\n",pt);
    if(s > n){// Se tiver mais operadores que numeros.
        printf("\nEXPRESSAO INVALIDA!");
        exit(1);
    }
    //No fim só restara o resultado na pilha, entao mostra ele. 
    printf("\nResultado: %.2f", pi->info);
}
float operacao(float a, float b, char x){
    //Utiliza o x para saber qual operacao fazer e retorna o resulto.
    switch(x){
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '/':
            if(b == 0){// quando for uma divisao por 0.
                printf("\nEXPRESSAO INVALIDA!!");
                exit(1);
            }
            return a / b;
            break;
        case '*':
            return a * b;
            break;
        default:
            printf("\nerro");
    }
}
