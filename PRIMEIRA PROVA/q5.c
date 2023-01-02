#include <stdio.h>


int particiona(int *v, int inicio, int final)
{
/*  Recebe um vetor e duas variáveis inteiras */
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
/*  Pivo irá receber o primeiro valor do vetor */
    pivo= v[inicio];
/*  Enquanto o valor de esq for menor que o valor de dir
    O programa ira procurar um valor maior que o pivo para aumentar o esq
    E um valor menor igual que o pivo para decrementar o dir
    No fim ele troca o valor do vetor na posição esq com o da posicao dir */
    while ((esq < dir))
    {
        while(v[esq] <= pivo)
        {
            esq ++;
        }
        while (v[dir] > pivo)
        {
            dir --;
        }
        if(esq < dir)
        {
            aux = v[esq];
            v[esq]= v[dir];
            v[dir] = aux;
        }
    }
/*  O primeiro valor recebe o valor do vetor da posicao dir
    E o valor da posicao dir recebe o pivo */
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}


void quickSort(int *v, int inicio, int fim)
{
/*  Recebe um vetor de inteiros e duas variáveis inteiras sendo o primeiro
    E o último endereço preenchido do vetor */
    int pivo;
    if(fim > inicio)
    {
    /*  Divide o vetor para ordena-lo separadamente */
        pivo = particiona(v,inicio,fim);
    /* chama o quicksort para a primeira metade */
        quickSort(v,inicio,pivo-1);
    /* chama o quicksort para a sengunda medade */
        quickSort(v,pivo+1,fim);
    }
}


int repetido(int n, int *v, int t)
{
/*  Recebe um número, um vetor e o tamanho do vetor
    O número será comparado com cada valor do vetor
    Se for igual a algum a função retorna 1
    Senão, a função retorna 0 */
    int i;
    for (i = 0; i < t; i ++)
    {
        if(v[i] == n)
        {
            return 1;
        }
    }
    return 0;
}


int * junta(int *v1, int t1, int *v2, int t2, int *t)
{
/*  Recebe dois vetores e seus respectivos tamanhos */
/*  Cria um ponteiro inteiro e o aloca dinamicamente */
    int *vetor;
    vetor = (int *) malloc(sizeof(int));
    int i;
/*  Irá passar os valores do primeiro vetor para o terceiro verificando
    Se os valores já estão presentes no vetor */
    for(i = 0; i < t1; i ++)
    {
        if(repetido(v1[i],vetor,*t) == 0)
        {
            vetor[*t] = v1[i];
            ++ *t;
        }
    }
/*  Irá passar os valores do segundo vetor para o terceiro verificando
    Se os valores já estão presentes no vetor */
    for (i = 0; i < t2; i ++)
    {
        if(repetido(v2[i],vetor,*t) == 0)
        {
            vetor[*t] = v2[i];
            ++ *t;
        } 
    }   
/*  Utiliza o quick sort para ordenar o terceiro vetor */
    quickSort(vetor,0,*t-1);
/*  Retorna o ponteiro*/
    return vetor;
}


void main()
{
    int v1[20], v2[20];
    int t1, t2;
    int i, aux;
    i = 0, t1 = 0;
/*  Faz a leitura do vetor ate o úsuario digitar -1
    Ao ler um número incrementa t1 que representa o tamanho do vetor */
    printf("Iniciando leitura do primeiro vetor:\npara encerrar digite -1\n");
    while(1){
        scanf("%d",&aux);
        if(aux == -1){
            break;
        }
        else{
            *(v1+i) = aux;
            t1 ++;
            i ++;
        }
        
    }
    i = 0, t2 = 0;
/*  Faz a leitura do vetor ate o úsuario digitar -1
    Ao ler um número incrementa t2 que representa o tamanho do vetor */
    printf("Iniciando leitura do segundo vetor:\npara encerrar digite -1\n");
    while(1){
        scanf("%d",&aux);
        if(aux == -1){
            break;
        }else{
            *(v2+i) = aux;
            t2 ++;
            i ++;
        }
    }
/*  ordena os dois vetores */
    quickSort(v1, 0, t1-1);
    quickSort(v2, 0, t2-1);
/*  Cria um ponteiro e faz ele receber o retorno da função junta
    Que um ponteiro que aponta para a primeira posição de um vetor
    ordenado da junção entre o vetor 1 e o vetor 2 sem repetições*/   
    int *vetor, t = 0;
    vetor = junta(v1,t1,v2,t2,&t);
    printf("t = %d\n",t);
    for(i = 0; i < t; i ++){
        printf("%d - ",vetor[i]);
    }
    printf("\n");
}