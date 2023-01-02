#include <stdio.h>

void divide(int *v, int t);

void main()
{
    /* Cria o vetor o aloca dinamicamente. */
    int *vector;
    vector = (int *) malloc(sizeof(int));
    int i,t;
    /* Faz a leitura o tamanho do vetor. */
    printf("Enter the vecto size: ");
    scanf("%d",&t);
    /* Como o tamanho do vetor, agora o programama ler os numeros do vetor. */
    for (i = 0; i < t; i ++)
    {
        printf("Number %d: ",i+1);
        scanf("%d",&vector[i]);
    }
    printf("#-#-#-#-#-#-#-#-#-#-#-#-#\n");
    /*chama a fucao divide que irar mostra o vetor de dentro para fora. */
    divide(vector,t);
}


void divide(int *v, int t)
{
    int i,half, left, right;
    /* a funcao foi preparada para vetores de ordens impar e par. */
    /* Primeiro if serve para vetores de ordem impar. */
    if( t % 2 != 0)
    {
        /* A metade irah receber o tamanho do vetor divido por 2. */
        half = t/2;
        /* Primeiro serah mostrado o valor central do vetor. */
        printf("%d\n", v[half]);
        /* Armazenamos a posicao que antecede a central e a que
        sucede a posicao central. 
        */
        left = half - 1;
        right = half + 1;
        /* O laco fara um numero de repeticoes igual ao half, pois
        irah mostra um numero do lado esquerdo e outro do direito de uma vez. 
        */
        for(i = 0; i < half; i ++)
        {
            /* Aqui serao mostrados 2 numeros um do lado esquerdo e outro do
            lado direito. */
            printf("%d %d\n",v[left],v[right]);
            left --;
            right ++;
        }
    }
    /*Segundo caso eh para vetores de ordem par. */
    else
    {
        /*Em vetores de ordem par nao teremos  1 posicao central mas sim 2. */
        left = t/2 - 1;
        right = t/2;
        /*O laco farah um numero de repeticoes igual a metade do vetor, pois
        serao mostrados dois numeros por vez.
        */
        for (i = 0; i < t / 2; i ++)
        {
            /* Aqui serao mostrados 2 numeros um do lado esquerdo e outro do
            lado direito. */
            printf("%d %d\n",v[left],v[right]);
            left --;
            right ++;
        }
    }
    //Agora libera o ponteiros.
    free(v);
}