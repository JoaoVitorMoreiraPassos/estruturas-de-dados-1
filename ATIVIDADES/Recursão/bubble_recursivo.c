#include <stdio.h>
#include <stdlib.h>
#define tam 50
int vetor[tam];


void bubble(int n){
    int num_comp = 0;
    int num_mov = 0;
    int i, j, temp;
    for (i = 0; i < n-1; i ++){
        for (j = 1; j < n; j ++){
            if(vetor[j] < vetor[j-1]){
                temp = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = temp;
            }
        }
    }
}


void bolhaRec(int n){
    int i, temp;
    if(n == 0){return;}
    else{
        for(i = 1; i < n; i ++){
            if(vetor[i] < vetor[i-1]){
                temp = vetor[i];
                vetor[i] = vetor[i-1];
                vetor[i-1] = temp;
            }
        }
        bolhaRec(n-1);
    }
}


void main()
{
    int i;
    for (i = tam-1; i >= 0; i --)
    {
        vetor[i] = (rand()%tam) + 1;
        // vetor[i] = i + 1;
        printf("%d - ",vetor[i]);
    }
    printf("\n\n");
    // bubble(tam);
    bolhaRec(tam);
    for (i = 0; i < tam; i ++)
    {
        printf("%d - ",vetor[i]);
    }
}