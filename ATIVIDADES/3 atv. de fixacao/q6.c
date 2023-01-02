#include <stdio.h>
#include <stdlib.h>


int **soma(int **matriz1, int **matriz2, int m, int n, int p, int q);
int **subtrai(int **matriz1, int **matriz2, int m, int n, int p, int q);
int **multiplica(int **matriz1, int **matriz2, int m, int n,int q, int p);
int **aloca_matriz(int l, int c);
void mostra_matriz(int **matriz, int m, int n);

void main()
{
    int **matriz1;
    int **matriz2;
    int m, n, p, q, i, j;
    printf("quantidade de linhas e colunas da matriz 1.Ex: 2 2: ");
    scanf("%d %d",&m, &n);
    printf("quantidade de linhas e colunas da matriz 2.Ex: 2 2: ");
    scanf("%d %d",&q, &p);
    matriz1 = aloca_matriz(m,n);//Alocando as matrizes.
    matriz2 = aloca_matriz(q,p);//Alocando as matrizes.
    for (i = 0; i < m; i ++)
    {
        for (j = 0; j < n; j ++)
        {
            scanf("%d",&matriz1[i][j]);
        }
    }//Fazer a leitura da primeira matriz.
    printf("leu a primeira.\n");
    for (i = 0; i < q; i ++)
    {
        for (j = 0; j < p; j ++)
        {
            scanf("%d",&matriz2[i][j]);
        }
    }//Fazer a leitura da segunda matriz.
    printf("leu a segunda.\n");
    printf("-----------------------\n");

    printf("soma:\n");
    int **somada;
    somada = soma(matriz1,matriz2,m,n,q,p);//Chama a funcao "soma" que irah somar duas matrizes e retornar outra matriz com o resultado.
    if(somada != NULL)
    {
        mostra_matriz(somada, m, n);
    }
    printf("-----------------------\n");

    printf("subtracao:\n");
    int **subtraida;
    subtraida = subtrai(matriz1,matriz2,m,n,q,p);//Chama a funcao "subtrai" que irah subtrair duas matrizes e retornar outra matriz com resultado.
    if(subtraida != NULL)
    {
        mostra_matriz(subtraida,m,n);
    }
    printf("-----------------------\n");

    printf("multiplicacao: \n");
    int **multiplicada;
    multiplicada = multiplica(matriz1,matriz2,m,n,q,p);//Chama a funcao "multiplica" que irah multiplicar duas matrizes e retornar outra matriz com o resultado.
    if(multiplicada != NULL)
    {
        mostra_matriz(multiplicada,m,p);    
    }
    //Agora libera o ponteiros.
    free(matriz1);
    free(matriz2);
    free(somada);
    free(subtraida);
    free(multiplicada);
}

int **soma(int **matriz1, int **matriz2, int m, int n, int p, int q)
{
    int i;
    int **matriz3;
    matriz3 = aloca_matriz(m, n);//Alocando matriz3
    if( m == p && n == q)
    {//Verifica se as matrizes 1 e 3 tem as mesmas medidas.
        int j;
        for (i = 0; i < m; i ++)
        {//Percorre as linhas das matrizes.
            for (j = 0; j < n; j ++)
            {//Percorre as colunas das matrizes.
                matriz3[i][j] = (matriz1[i][j] + matriz2[i][j]);//Soma a matriz posicao por posicao.
            }
        }
        return matriz3;//Retorna a soma das 2 matrizes.
    }
    else{
        return NULL;//Se as medidas das matrizes forem diferente retorna NULL pois nao eh possivel somar matrizes de medidas diferentes.
    }
}

int **subtrai(int **matriz1, int **matriz2, int m, int n, int p, int q)
{
    int i;
    int **matriz3;
    matriz3 = aloca_matriz(m, n);//Alocando matriz3
    if( m == p && n == q)
    {//Verifica se as matrizes 1 e 3 tem as mesmas medidas.
        int j;
        for (i = 0; i < m; i ++)
        {//Percorre as linhas das matrizes.
            for (j = 0; j < n; j ++)
            {//Percorre as colunas das matrizes.
                matriz3[i][j] = (matriz1[i][j] - matriz2[i][j]);//Subtrai a matriz posicao por posicao.
            }
        }
        return matriz3;//Retorna a subtracao das 2 matrizes.
    }
    else{
        return NULL;//Se as medidas das matrizes forem diferente retorna NULL pois nao eh possivel subtrair matrizes de medidas diferentes.
    }
}

int **multiplica(int **matriz1, int **matriz2, int m, int n,int q, int p)
{
    int i, j, k;
    int **matriz3;
    matriz3 = aloca_matriz(m,p);// Alocando a matriz
    int somamatorio;
    if(m == p || n == q)
    {//Verifica se as matrizes sao validas para multiplicacao.
        for( i = 0; i < m; i ++)
        {//Percorre as linhas da "matriz1"
            for (j = 0; j < p; j ++)
            {//Percorre as colunas da "matriz2"
                somamatorio = 0;
                for ( k = 0; k < n; k ++)
                {//Percorre as colunas da "matriz1" e as linhas da "matriz2"
                    somamatorio += matriz1[i][k] * matriz2[k][j];//Soma as multiplicacoes.
                }
                matriz3[i][j] = somamatorio;// Adiciona o a soma das multiplicacoes em sua posica na "matriz3".
            }
        }
        return matriz3;//Retorna a muliplicacao das 2 matrizes.
    }
    else{
        return NULL;//Para obter o produto de 2 matrizes, eh necessario que o numero de linhas de uma seja igual ao numero de colunas da outra, Entao o retorno sera NULL.
    }
}


void mostra_matriz(int **matriz, int m, int n)
{//Recebe uma matriz e suas medidas depois mostra seus valores.
    int i, j;
    for(i = 0; i < m; i ++)
    {
        for (j = 0 ; j < n; j ++)
        {
            if(j != n-1)
            {
                printf("%d%2c ",matriz[i][j],'|');
            }else{printf("%d",matriz[i][j]);}
        }
        printf("\n");
    }
}


int **aloca_matriz(int l, int c)
{//Aloca a matriz com os tamanhos recebidos por parametro.
    int **v;
    int i;
    v = (int **) calloc(l, sizeof(int *));
    if(v == NULL)
    {
        printf("erro de memorira\n");
        exit(1);
    }
    for (i = 0; i < l; i ++)
    {
        v[i] = (int *) calloc(c, sizeof(int));
        if(v[i] == NULL)
        {
            printf("Erro de memoria\n");
            exit(1);
        }
    }
    return v;
}