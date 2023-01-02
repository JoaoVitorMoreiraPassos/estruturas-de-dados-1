#include <stdio.h>

void minutosHoras(int *m)
{
    // Cria uma variável para horas com o valor 0.
    int horas = 0;
    // Enquanto *m for maior igual a 60 a hora recebe mais 1 e *m recebe ele mesmo menos 60.
    // Se *m for menor que 60 a hora já é igual a 0 e *m já vai ser os minutos.
    while (*m >= 60)
    {
        horas += 1;
        *m -= 60;
    }
    printf("%dh e %d m\n",horas, *m);
    
}
void main()
{
    int *M;
    // Fazer a alocação dinamica do ponteiro.
    M = (int *) malloc(sizeof(int));
    // Definir um valor para o conteudo do espaço de memoria para onde o ponteiro aponta.
    *M = 60;
    minutosHoras(M);
}