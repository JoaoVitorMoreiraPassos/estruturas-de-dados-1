#include <stdio.h>
#include <string.h>


typedef struct Disciplina
{
    int codigo_disciplina;
    int codigo_curso;
    char nome[30];
    int periodo;
    int carga_horaria;
}Disciplina;

typedef struct Cursos
{
    int codigo;
    char nome[30];
    int quantidade_periodos;
    Disciplina *disciplinas;
    int quant_disciplinas;
}Cursos;

char *devolve_nome(Cursos *cursos, int t);
int devolve_quant_disciplinas(Cursos *cursos, int t, int codigo);
int quant_disciplinas_periodo(Cursos *cursos, int t, int codigo, int perido);

void main()
{
    Cursos *cursos;
    int num_cursos, i, j;
    printf("Quantidade de cursos que vao ser cadastrados: ");
    scanf("%d",&num_cursos);
    cursos = (Cursos *) calloc(num_cursos, sizeof(Cursos));//Aloca o ponteiro usando como tamanho o numero de cursos.
    
    for (i = 0; i < num_cursos; i ++)
    {// Esse primeiro laco irah ler os dados de um curso
        printf("codigo do curso: ");
        scanf("%d",&cursos[i].codigo);

        printf("nome do curso: ");
        scanf(" %[^\n]s",cursos[i].nome);
        
        printf("quantidade de periodos: ");
        scanf("%d", &cursos[i].quantidade_periodos);
        
        printf("quantidade de disciplinas:");
        scanf("%d", &cursos[i].quant_disciplinas);
        //Depois de ter lido a quantidade de disciplinas do curso lido, Fara a alocacao dinamica
        //do ponteiro do tipo Disciplinas contido em no no struct "Cursos" utilzando a quantidade
        //de disciplinas como tamanho para nao sobrar memoria.
        cursos[i].disciplinas = (Disciplina *) calloc(cursos[i].quant_disciplinas, sizeof(Disciplina));

        for (j = 0; j < cursos[i].quant_disciplinas; j ++)
        {// Esse laco ira ler os dados da disciplinas do curso atual.
            cursos[i].disciplinas[j].codigo_curso = cursos[i].codigo;
            printf("Codigo da disciplina: ");
            scanf("%d",&cursos[i].disciplinas[j].codigo_disciplina);
        
            printf("Nome da disciplina: ");
            scanf(" %[^\n]s ",cursos[i].disciplinas[j].nome);
        
            printf("periodo da disciplina %s:",cursos[i].disciplinas[j].nome);
            scanf("%d",&cursos[i].disciplinas[j].periodo);
        
            printf("carga horaria da disciplina: ");
            scanf("%d",&cursos[i].disciplinas[j].carga_horaria);
            
        }
        printf("------------------------------------------------\n");
        
    }
    int cod_curso, per;
    printf("O curso com mais disciplinas eh: %s\n",devolve_nome(cursos, num_cursos));//Irah mostrar nome do curso com mais periodos.
    printf("------------------------------------------------\n");
    printf("digite o codigo do curso para ver a quantidade de disciplinas: ");
    scanf("%d",&cod_curso);
    printf("Esse possui %d disciplina(s).\n",devolve_quant_disciplinas(cursos, num_cursos, cod_curso));//Irah mostrar a quantidade de disciplinas de um curso.
    printf("------------------------------------------------\n");
    printf("Digite o codigo do curso e o periodo. ex: 12345 3:");
    scanf("%d %d",&cod_curso, &per);
    printf("Esse periodo tem %d disciplina(s).",quant_disciplinas_periodo(cursos,num_cursos,cod_curso, per));//Irah mostra a quantidade de disciplinas por periodo de um curso.
    //Agora libera o ponteiros.
    for (i = 0; i < num_cursos; i ++){
            free(cursos[i].disciplinas);
        }
    free(cursos);
}

char *devolve_nome(Cursos *cursos, int t)
{
    int i, maior;
    maior = 0;//Inicializa a variavel maior com o primero indice de "cursos".
    for (i = 1; i < t; i ++)
    {//O laco percorre da segunda posicao de "cursos" ate a ultima.
        if(cursos[i].quantidade_periodos > cursos[maior].quantidade_periodos)
        {// Compara a quantidade de periodos dos cursos de posicao "i" com os de posicao "maior".
         // Se um curso tiver mais periodos que o curso de posicao "maior", "maior" recebe o indice desse curso. 
            maior = i;
        }
    }
    return cursos[maior].nome;//Utiliza o indice do curso com maior quantidade de periodos para retornar o seu nome.
}

int devolve_quant_disciplinas(Cursos *cursos, int t, int codigo)
{
    //Pesquisa um curso utilizando seu codigo e retorna quantas disciplinas ele tem.
    int i;
    for (i = 0; i < t; i ++)
    {// Percorre todas as posicoes de "cursos".
        if(cursos[i].codigo == codigo)
        {// Verifica se o codigo do curso de posicao "i" eh igual ao codigo passado por parametro. Se for igual retorna a quantidade de disciplinas.
            return cursos[i].quant_disciplinas;
        }
    }
    return 0;//Se o curso nao por encontrado retorna 0;
}

int quant_disciplinas_periodo(Cursos *cursos, int t, int codigo, int periodo)
{
    //Recebe a tabela de cursos, a quantidade de cursos, o codigo do curso desejado, e o periodo.
    int i, j, quantidade;
    quantidade = 0;//Inicializa quandidade como 0.
    for (i = 0; i < t; i ++)
    {//Percorre todas as posicoes de "cursos".
        if(codigo == cursos[i].codigo)
        {// Verifica se o codigo do curso da posicao "i" eh igual ao passado por parametro.
         // Se for igual, inicia um laco para contar as disciplinas.
            for(j = 0; j < cursos[i].quant_disciplinas; j ++)
            {
                if( cursos[i].disciplinas[j].periodo == periodo )
                {// Verifica se a disciplina pertence ao periodo passado por parametro. Se for igual incrementa a variavel "quantidade".
                    quantidade ++;
                }
            }
        }
    }
    return quantidade;// Retorna a quantidade.
}