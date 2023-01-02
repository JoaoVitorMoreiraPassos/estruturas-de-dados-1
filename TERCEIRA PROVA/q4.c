#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilhaD PilhaD;
struct pilhaD{
  float info;
  PilhaD* prox;
};
// ===================================//
PilhaD* pilhaD_inicializa(){
  return NULL;
}
int pilhaD_vazia(PilhaD* p){
  if(p == NULL)
    return 1;
  return 0;
}
// ===================================//
PilhaD* alocaNo(float valor){
  PilhaD* no = (PilhaD*) malloc(sizeof(PilhaD));
  no->info = valor;
  no->prox = NULL;
  return no;
}
PilhaD* pilhaD_push(PilhaD* p, float valor){// Adiciona valor
  PilhaD *novo = alocaNo(valor);
  novo->prox = p;
  return novo;
}

PilhaD* pilhaD_pop(PilhaD** p){// Retira
  PilhaD* remove;
  if(pilhaD_vazia(*p) == 0){
    remove = *p;
    *p = remove->prox;
  }
  return remove;
}
// ===================================//
float operacao(float a, float b, char x){
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
void resolveExpressao(char x[]){// "51 13 12 * +"
  int n = 0, s = 0;
  char *pt;
  float num;
  PilhaD *n1, *n2, *pi = NULL;

  pt = strtok(x, " "); //Função da string.h que divide o vetor a partir dos espaços.
  while(pt){
    if(pt[0]== '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
      n2 = pilhaD_pop(&pi);
      n1 = pilhaD_pop(&pi);
      num = operacao(n1->info, n2->info, pt[0]);
      pi = pilhaD_push(pi, num);
      free(n1);
      free(n2);
      s++;
    }
    else{
      num = strtol(pt, NULL, 10);//converter string pra int.
      if(pt[0] == '0'){
        num = 0;
        pi = pilhaD_push(pi, num);
      }else{
        pi = pilhaD_push(pi, num);
        if(num == 0){
          printf("\nEXPRESSAO INVALIDA!");
          return;
        }
      }
      n++;
    }
    pt = strtok(NULL, " ");
  }
  if(s > n){// Caso a expressao tenha mais sinais do que numeros.
    printf("\nEXPRESSAO INVALIDA!");
    exit(1);
  }
//No fim só restara o resultado na pilha, entao mostra ele. 
  printf("\nResultado: %.2f", pi->info);
}

void main(){
  char exp[100] = {"23 2 + 2 *"};

// Infixa                      Pós-fixa(NA POS FIXA NAO TEM PARENTESES)
// (51+13*12)                  51 13 12 * +                R = 207
// (5*(3+2)/4-6)               5 3 2 + * 4 / 6 -           R = 0,25
// (5+3+2*4-6*7*1)             5 3 + 2 4 * + 6 7 * 1 * -   R = -26
// (5*(3+(2*(4+(6*(7+1))))))   5 3 2 4 6 7 1 + * + * + *   R = 535

  resolveExpressao(exp);
}
