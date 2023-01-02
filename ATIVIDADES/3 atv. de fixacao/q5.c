#include <stdio.h>
#include <string.h>

char *repete(char *s, int n);


void main()
{
    char *s = {"Ola"};
    repete(s, 10);
}

char *repete(char *s, int n)
{
    char *nova_string;
    nova_string = (char *) calloc(strlen(s)*n+(n-1),sizeof(char));// Aloca o ponteiro definindo o tamanho exato que ela irah recebe.
    if (nova_string == NULL)
    {
        printf("erro\n");
        exit(1);
    }
    int i, j, t = strlen(s), aux = 0;
    for (i = 0; i < n; i ++)
    {//Esse laco serve para controlar quantas vezes a palavra irah se repetir.
        for(j = 0; j < t; j ++)
        {//Esse laco ira passar os caracteres de "s" para "nova_string".
            nova_string[aux] = s[j];
            aux ++;
        }
        if(i != n-1)
        {//Essa condicao serve para colocar um espaco depois da palavra ser preenchica, apenas se nao for a ultima repeticao.
            nova_string[aux] = ' ';
            aux ++;
        }
    }
    nova_string[aux] = '\0';//Insere o terminador da string.
    printf("%s\n",nova_string);//Mostra a nova string.
    //Agora libera o ponteiros.
    free(nova_string);
}

