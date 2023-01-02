#include <stdio.h>
#include <stdlib.h>
#define tam 50
int vetor[tam];


void selecao(int n){
    int i, j, min, temp;
    for (i = 0; i < n; i ++){
        min = i;
        for (j = i+1; j < n; j ++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        temp = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = temp;
    }
}


void selecaoRec(int n){
    int i, max, temp;
    if(n == 1){return;}
    else{
        max = n-1;
        for (i = n-2; i >= 0 ; i --){
            if(vetor[i] > vetor[max]){
                max = i;
            }
        }
        temp = vetor[max];
        vetor[max] = vetor[n-1];
        vetor[n-1] = temp;
        selecaoRec(n - 1);
    }
}


void main()
{
    int i,t = 50;
    for (i = 49; i >= 0; i --)
    {
        // vetor[i] = (rand()%tam) + 1;
        vetor[i] = i + 1; 
        printf("%d - ",vetor[i]);
    }
    printf("\n\n");
    // selecao(t);
    selecaoRec(t);
    for (i = 0; i < tam; i ++){
        printf("%d - ",vetor[i]);
    }
}