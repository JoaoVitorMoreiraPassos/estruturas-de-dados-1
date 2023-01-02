#include <stdio.h>


void fatoraPotencia(int numero, int *base, int *exp)
{
    // Zerar o expoente para utiliza-lo.
    *exp = 0;
    // Inicializar i recebendo 2 pois é a menor base possivel, e aux recebe o valor de numero para servir de backup para comparações futuras.
    int i = 2, aux = numero;
    // Laço para fatorar o numero até ele chegar ao valor 1.
    while (numero != 1){
        // Para o caso do número ser divisível por i o *exp é somado com 1 e o numero recebe ele mesmo divido pelo i
        // Se o número for um quadrado perfeito ou um um numero primo quando ele achar um valor que ele seja divisível irá se dividir por esse valor até chegar a 1.
        if(numero % i == 0){
            *exp += 1;
            numero /= i;
        }
        else{
            // Se numero não for divisível por i
            // Se o número for diferente de aux significa que ele ja foi divido por um valor e chegou a um ponto que esse valor não o divide mais logo não tem como representa-lo apenas com uma base e expoente, para esse caso tratei fazendo a base valer o valor inicial do numero e o expoente ser igual a 1, em seguida o laço é finalizado.
            if(numero != aux){
                *base = aux;
                *exp = 1;
                break;
            }
            i ++;
        }
        *base = i;
    }
    
}


void main()
{
    int n, base = 0, exp = 0;
    n = 10; 

    fatoraPotencia(n, &base, &exp);
    printf("%d - %d",base, exp);
}