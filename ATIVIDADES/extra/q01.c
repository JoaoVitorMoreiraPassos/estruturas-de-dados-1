#include <stdio.h>
#include <stdlib.h>


double positivo(double n)
{
    if(n < 0){
        return n * -1;
    }
    return n;
}


int media(double *vetor, int n, int *i)
{
    double diferenca, soma = 0, media;
    int j;

    for(j= 0; j< n; j++)
    {
        // A cada repetição incrementa a variavel soma com uma media presente no vetor.
        soma += vetor[j];
    }
    // A média sera igual a soma das notas divivido pela quantidade de notas.
    media = soma/n;
    printf("%lf\n",media);
    // a variável diferenca recebera a média menos a distancia da nota localizada na posição 0 do vetor.
    diferenca = media - vetor[0];
    // para facilitar comparações trata-se a diferenca para que tal variavel não assuma valores negativos.
    diferenca = positivo(diferenca);
    for (j = 1; j < n; j ++)
    {   
        // Nesse laço o programa fará a comparação entre a menor diferença encontrada no vetor com a nota localizada na posição do iterador j no vetor de notas.
        // Se a distancia da nota atual for menor que a menor diferença encontrada a variável diferenca recebe o conteudo da variável temp e o conteudo do espaço de memoria para onde o ponteiro *i aponta recebe o valor do iterador j.
        double temp = media - vetor[j];
        temp = positivo(temp);
        if(temp < diferenca)
        {
            diferenca = temp;
            *i = j;
        }
    }
}


void main()
{
    double vetor[] ={10, 20, 30, 40, 50, 2};
    int indice, i;
    
    media(vetor, 6, &indice);
    printf("%d\n",indice);
}