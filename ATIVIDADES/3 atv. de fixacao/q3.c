#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
}Aluno;

void imprime_aprovados(int n, Aluno **turmas);
float media_turma(int n, Aluno** turmas, char turma);
int aprovado_ou_nao(float p1, float p2, float p3, float *media);


void main()
{
    int i, tam;
    printf("Quantidade de alunos: ");
    scanf("%d",&tam); // Faz a leitura da quantidade de alunos que vai ser lida.
    Aluno **turmas;
    turmas = (Aluno **) calloc(1, sizeof(Aluno*)); // Aloca o ponteiro de ponteiros do tipo Aluno.
    turmas[0] = (Aluno *) calloc(tam,sizeof(Aluno)); // Aloca o ponteiro de estruct do tipo Aluno.
    if(turmas[0] == NULL){
        printf("erro");
        exit(1);
    }// verifica se o ponteiro foi alocado corretamente.
    for(i = 0; i < tam; i ++)
    {// Aqui serah feita a leitura dos dados de cada aluno.
        printf("Nome do aluno: ");
        scanf(" %[^\n]s", turmas[0][i].nome);
        printf("Matricula do aluno: ");
        scanf(" %s", turmas[0][i].matricula);
        printf("Turma do aluno: ");
        scanf(" %c", &turmas[0][i].turma);
        printf("1a nota do aluno: ");
        scanf(" %f", &turmas[0][i].p1);
        printf("2a nota do aluno: ");
        scanf(" %f", &turmas[0][i].p2);   
        printf("3a nota do aluno: ");
        scanf(" %f", &turmas[0][i].p3);
    }
    printf("leitura concluida.\n");
    printf("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");
    printf("Aluno(s) aprovado(s)\n");
    imprime_aprovados(tam, turmas);// A funcao irah mostrar os dados dos alunos aprovados.
    printf("Media de uma turma: %.2f\n",media_turma(tam, turmas, 'B'));// mostra a media da turma que for passada no 3o parametro.
    //Agora libera o ponteiros.
    free(turmas[0]);
    free(turmas);
}

void imprime_aprovados(int n, Aluno **turmas)
{
    int i;
    float media;
    for (i = 0; i < n; i ++)
    {//O laco irah percorrer todas as posicoes de "turmas".
        if(aprovado_ou_nao(turmas[0][i].p1,turmas[0][i].p2,turmas[0][i].p3,&media) == 1)
        {//Passa as notas de cada aluno para a funcao "aprovado_ou_nao" que verifica se a media eh maior que 7
         //e atribui a media no endereco da variavel passada no 4o parametro. Se o retorno for 1 ou seja se o aluno
         //estiver aprovado, seus dados serao mostrados.
            printf("    %s|%8s    |%5c    |   %.2f   |\n",turmas[0][i].matricula,turmas[0][i].nome,turmas[0][i].turma,media);
        }
        
    }
}


float media_turma(int n, Aluno** turmas, char turma)
{
    int i,t = 0;
    float media = 0;
    for (i = 0; i < n; i ++)
    {// O laco irah percorrer todas as posicoes de "turmas".
        if(turmas[0][i].turma == turma)
        {//Verifica se a turma do aluno eh igual a passada por parametro. Se for igual, 
         //incrementa a variavel "media" com a media do aluno e tambem incrementa a
         //variavel "t" que eh quantidade de alunos da turma.*/
            media += (turmas[0][i].p1 + turmas[0][i].p2 + turmas[0][i].p3) / 3;
            t ++;
        }
    }
    media /= t ;// divide a soma das medias dos alunos pela quantidade de alunos.
    return media;// Retorna a media.
}

int aprovado_ou_nao(float p1, float p2, float p3, float *media)
{
    *media = (p1 + p2 + p3) / 3;//calcula a media de tres notas e adiciona em "*media".
    if(*media >= 7)
    {return 1;}
    else{return 0;}//Se a media for maior ou igual a 7 retorna 1. Senao retorna 0.
}
