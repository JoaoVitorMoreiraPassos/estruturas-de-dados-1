#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int tot_cursos = 0;
int tot_discip = 0;

typedef struct
{
    int cod_disciplina;
    int cod_curso;
    char *nome;
    int periodo_da_disciplina;
    int carga_horaria_disciplina;
}Disciplina;


typedef struct
{
    int cod;
    char *nome;
    int quant_periodos;
    int carga_horaria_total;
    char *turno;
}Curso;

void cadastrarCursos(Curso *cursos);//Recebe um vetor do tipo Curso, preenche sua ultima posicao de acordo com quantidade de cursos cadastrados e o ordena.
void cadastrarDisciplinas(Curso *cursos, Disciplina *disciplinas, int codigo);// Recebe um vetor do tipo Curso, preenche sua ultima posicao de acordo com a quantidade de disciplinas cadastradadas e o ordena.
void mostraCurso(Curso *cursos, int codigo);// Recebe um vetor do tipo Curso e inteiro, usa o inteiro para procurar o curso a ser mostrado.
void mostraDisciplina(Disciplina *disciplinas, Curso *cursos, int codigo);//Recebe um vetor do tipo Disciplinas, outro do tipo Curso e um inteiro, pesquisa se a disciplina existe depois se o curso da disciplina existe, entao mostra a disciplina.
void mostraCursosPorTurno(Curso *cursos, char *turno);//Recebe um vetor do tipo Curso e uma string, usa a string para procurar disciplinas de um turno espefico.
void mostraDisciplinasDeUmCurso(Disciplina *disciplinas,Curso *cursos, int codigo);//Recebe um vetor do tipo Disciplinas, outro do tip Curso e um inteiro, verifica se o curso existe, depois faz a busca pelas disciplinas desse curso.
void mostraDisciplinasDeUmCursoPorPeriodo(Disciplina *disciplinas, Curso *cursos, int codigo_curso, int periodo);//Recebe um vetor do tipo Disciplinas, outro do tip Curso e dois inteiros, verifica se o curso existe, verifica se o periodo passado existe no curso, depois faz a busca pelas disciplinas do curso recebido no periodo recebido.
void removeDisciplinas(Disciplina *disciplinas, int codigo);//Recebe um Vetor de disciplinas e um inteiro, usa o codigo para procurar a disciplina,e a remove.
void removeCursos(Curso *cursos,Disciplina *disciplinas, int codigo);//Recebe um vetor do tipo Disciplinas, outro do tipo Curso e um inteiro, verifica se esse curso ja possui disciplinas, em seguida se nao tiver nenhuma disciplina, o curso eh removido.
void ordenaCursos(Curso *cursos);//Ordena um vetor do tipo Curso em ordem crescente de acordo com o codigo, utilizando o metodo de insercao.
void ordenaDisciplinas(Disciplina *disciplinas);//Ordena um vetor do tipo Disciplinas em ordem crescente de acordo com o codigo da disciplina, utilizando o metodo de insercao.
int verificaExistenciaCurso(Curso *cursos, int codigo);//Faz uma busca binaria em um vetor do tipo Curso, a busca eh feita pelo codigo dos cursos.
int verificaExistenciaDisciplina(Disciplina *disciplinas, int codigo);//Faz um busca binaria em um vetor do tipo Disciplina, a busca eh feita pelo codigo das disciplinas
int verificaSeOCursoTemDisciplina(Disciplina *disciplinas, int codigo);// Faz uma busca sequencial para verificar se em um vetor de discplinas, existe alguma disciplina com o codigo de curso igual ao codigo recebido por parametro.

int main(){
    Curso *cursos;
    Disciplina *disciplinas;
    //Aloca os vetores para receberem no maximo 100 itens.
    cursos = (Curso *) calloc(100, sizeof(Curso));
    disciplinas = (Disciplina *) calloc(100, sizeof(Disciplina));
    int escolha, codigo, periodo, encerra;
    char turno[15];
    while (1){//Menu de escolhas.
        printf("--------Escolha uma opcao-------\n");
        printf("Cadastrar curso[1].\nCadastrar Disciplina[2].\nMostrar Informacoes de um curso[3].\nMostrar Informacoes de uma disciplina[4].\nMostrar Cursos por turno[5].\nMostrar Disciplinas De Um Curso[6].\nMostrar disciplinas de um periodo de um curso[7].\nRemover uma disciplina[8].\nRemover Curso[9].\nEncerrar[Qualquer outro numero].\n");
        printf("--------------------------------\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        printf("--------------------------------\n");
        switch (escolha){//O switch irah dizer qual funcao chamar de acordo com a escolha do usuario.
        case 1:
            cadastrarCursos(cursos);
            break;
        case 2:
            printf("Codigo do curso que vai adicionar a disciplina: ");
            scanf("%d",&codigo);
            cadastrarDisciplinas(cursos, disciplinas ,codigo);
            break;
        case 3:
            printf("Codigo do curso a ser mostrado: ");
            scanf("%d", &codigo);
            mostraCurso(cursos, codigo);
            break;
        case 4:
            printf("Codigo da discplina a ser mostrada: ");
            scanf("%d", &codigo);
            mostraDisciplina(disciplinas, cursos, codigo);
            break;
        case 5:
            printf("Turno a ser pesquisado: ");
            scanf(" %[^\n]s", turno);
            mostraCursosPorTurno(cursos, turno);
            break;
        case 6:
            printf("Codigo do curso para ver suas disciplinas: ");
            scanf("%d", &codigo);
            mostraDisciplinasDeUmCurso(disciplinas, cursos, codigo);
            break;
        case 7:
            printf("Codigo e periodo para mostra as disciplinas. Ex: 33333 2: ");
            scanf("%d %d", &codigo, &periodo);
            mostraDisciplinasDeUmCursoPorPeriodo(disciplinas, cursos, codigo, periodo);
            break;
        case 8:
            printf("Codigo da disciplina a ser removida: ");
            scanf("%d",&codigo);
            removeDisciplinas(disciplinas, codigo);
            break;
        case 9:
            printf("Codigo do curso a ser excluido: ");
            scanf("%d", &codigo);
            removeCursos(cursos, disciplinas, codigo);
            break;
        default:
            encerra = 1;
            break;
        }
        if(encerra == 1){
            break;
        }
    }
    int i;
    for (i = 0; i < tot_cursos; i ++){
        printf("%d %s\n", cursos[i].cod, cursos[i].nome);
    }
    free(cursos);
    free(disciplinas);
    printf("Programa finalizado com sucesso.\n");
    return 0;    
}

void cadastrarCursos(Curso *cursos){
    int i, aux,encerra = 0;
    char temp_str[30], temp_turno[15];
    i = tot_cursos;
    while(1){//verifica se o codigo digitado pelo usurio ja existe ou nao, enquanto for repetido o programa nao funciona.
        printf("codigo do curso: ");
        scanf("%d",&aux);
        encerra = verificaExistenciaCurso(cursos, aux);
        if(encerra != -1){printf("Codigo invalido!\n");}
        else{break;}
    }
    cursos[i].cod = aux;//preenche o codigo do curso.
    //Faz a leitura dos dados do curso.
    printf("nome do curso: ");
    scanf(" %[^\n]s", temp_str);
    cursos[i].nome = (char *) calloc(strlen(temp_str)+1, sizeof(char));
    if(cursos[i].nome == NULL){
        printf("Memoria do nome.\n");
        exit(1);
    }
    strcpy(cursos[i].nome,temp_str);
    
    printf("quantidade de periodos: ");
    scanf("%d", &cursos[i].quant_periodos);

    printf("carga horaria total: ");
    scanf("%d", &cursos[i].carga_horaria_total);

    printf("turno: ");
    scanf(" %[^\n]s", temp_turno);
    cursos[i].turno = (char *) calloc(strlen(temp_turno)+1, sizeof(char));
    if(cursos[i].turno == NULL){
        printf("Memoria do turno.\n");
        exit(1);
    }
    strcpy(cursos[i].turno, temp_turno);
    tot_cursos ++;//Aumenta em 1 a quantidade de cursos.
    ordenaCursos(cursos);//ordena o vetor de cursos.
    printf("Curso Cadastrado!\n");
}


void cadastrarDisciplinas(Curso *cursos, Disciplina *disciplinas, int codigo){
    int i = tot_discip;
    int indice = verificaExistenciaCurso(cursos, codigo);//Verifica existencia do curso.
    char temp_nome[50];
    if(indice != -1){//Se o curso existir pega os dados da disciplina.
        disciplinas[i].cod_curso = cursos[indice].cod;//preenche o codigo do curso a qual a disciplina pertence.

        //Faz a leitura dos dados da disciplina. 
        printf("Codigo da disciplina: ");
        scanf("%d",&disciplinas[i].cod_disciplina);
        
        printf("Nome da disciplina: ");
        scanf(" %[^\n]s", temp_nome);
        disciplinas[i].nome = (char *) calloc(strlen(temp_nome)+1, sizeof(char));
        if(disciplinas[i].nome == NULL){
            printf("memoria insuficiente.\n");
            exit(1);
        }
        strcpy(disciplinas[i].nome, temp_nome);

        while(1){
            printf("Peridodo da disciplina: ");
            scanf("%d", &disciplinas[i].periodo_da_disciplina);
            if(disciplinas[i].periodo_da_disciplina > cursos[indice].quant_periodos)
            {
                printf("Periodo Invalido. Tente novamente!\n");
            }
            else{break;}
        }
        printf("Carga horaria da disciplina: ");
        scanf("%d", &disciplinas[i].carga_horaria_disciplina);

        tot_discip ++; // Aumenta em 1 a quantidade de disciplinas.
        ordenaDisciplinas(disciplinas);//Ordena o vetor de disciplinas.
    }
}


void mostraCurso(Curso *cursos, int codigo){
    int i;
    int index = verificaExistenciaCurso(cursos, codigo);//Verifica de o curso existe.
    if (index != -1){//Se o curso existir mostra suas informacoes.
        printf("Codigo: %d  |  ",cursos[index].cod);
        printf("Nome: %s  | ",cursos[index].nome);
        printf("Quantidade de periodos: %d  | ",cursos[index].quant_periodos);
        printf("Carga horaria total: %d  | ",cursos[index].carga_horaria_total);
        printf("Turno: %s\n",cursos[index].turno);
    }
    else{
        printf("Curso nao encotrado!\n");
    }
}


void mostraDisciplina(Disciplina *disciplinas, Curso *cursos, int codigo){
    int i;
    int index = verificaExistenciaDisciplina(disciplinas, codigo);//Verifica se a disciplina existe.
    if(index != -1){//Se existir, mostra suas informacoes 
        printf("Curso: %s  |  Codigo da disciplina: %d  |  Nome: %s  |  Periodo: %d  |  Carga horaria: %d\n",cursos[verificaExistenciaCurso(cursos, disciplinas[index].cod_curso)].nome,
                                                                                                             disciplinas[index].cod_disciplina,
                                                                                                             disciplinas[index].nome,
                                                                                                             disciplinas[index].periodo_da_disciplina,
                                                                                                             disciplinas[index].carga_horaria_disciplina
        );
    }
    else{
        printf("Codigo nao encotrado!\n");
    }
}


void mostraCursosPorTurno(Curso *cursos, char *turno){
    int i;
    for (i = 0; i < tot_cursos; i ++){//percorre sequencialmente o vetor de cursos.
        if(strcmp(cursos[i].turno ,turno) == 0){// O turno do curso da posicao i for igual ao buscado chama a funcao mostraCurso para mostrar suas informacoes.
            mostraCurso(cursos, cursos[i].cod);
        }
    }
}


void mostraDisciplinasDeUmCurso(Disciplina *disciplinas, Curso *cursos, int codigo){
    int i;
    int index = verificaExistenciaCurso(cursos, codigo);//Verifica se o curso existe.
    if(index != -1){//Se o curso existir.
        for (i = 0; i < tot_discip; i ++){//Percorre o vetor de disciplinas.
            if(disciplinas[i].cod_curso == codigo)
            {//Se o codigo de curso da disciplina for igual ao buscado, chama a funcao mostradisciplina para mostrar os dados da disciplinas.
                mostraDisciplina(disciplinas, cursos, disciplinas[i].cod_disciplina);
            }
        }
    }
    else
    {
        printf("Curso nao encotrado!\n");
    }
}


void mostraDisciplinasDeUmCursoPorPeriodo(Disciplina *disciplinas, Curso *cursos, int codigo_curso, int periodo){
    int i;
    int index = verificaExistenciaCurso(cursos, codigo_curso);//Verifica se o curso existe.
    if(index != -1 && periodo <= cursos[index].quant_periodos){//Se o curso existir e o curso tiver o perido passado.
        for(i = 0; i < tot_discip; i ++){//Percorre o vetor de disciplinas.
            if(disciplinas[i].cod_curso == codigo_curso && disciplinas[i].periodo_da_disciplina == periodo){// Se o codigo de curso da disciplina atual for igual ao buscado, e o perido da disciplina for iqual ao buscado, chama a funcao mostraDisciplina e mostra seus dados.
                mostraDisciplina(disciplinas, cursos, disciplinas[i].cod_disciplina);
            }
        }
    }
    else
    {
        printf("Curso nao encotrado ou periodo invalido!\n");
    }
}


int verificaExistenciaCurso(Curso *cursos, int codigo){
    int esq, dir,meio;
    esq = -1;
    dir = tot_cursos;
    while(esq < dir-1){//Enquanto o indice da esq for menor que o da direita - 1.
        meio = (dir+esq) / 2;//Obtem a posicao media.
        if(cursos[meio].cod == codigo){//Se o codigo buscado for igual ao codigo do curso na posicao meio, retorna o indice.
            return meio;
        }
        if(cursos[meio].cod < codigo){//Se o codigo buscado for maior que o codigo do curso na posicao meio, o indice da esq recebe o indice meio.
            esq = meio;
        }
        else{//Se o codigo buscado for menor que o codigo do curso na posicao meio, o indce da dir recebe o indice meio;
            dir = meio;
        }
    }
    return -1;//Se o curso nao for encotrado retorna -1;
}


void removeDisciplinas(Disciplina *disciplinas, int codigo){
    int i, j;
    int index = verificaExistenciaDisciplina(disciplinas, codigo);// Verifica se a disciplina existe.
    if(index != -1){//Se a disciplina existir.
        for (i = 0; i < tot_discip; i ++){//Percorre o vetor disciplinas.
            if(disciplinas[i].cod_disciplina == codigo){//Percorre da posicao do curso a ser removida ate a penultima.
            // A posicao atual ira receber a posica posterior, assim o curso sera substituido e nao existira mais.
                for(j = i; j < tot_discip - 1; j ++){
                    disciplinas[j].cod_curso = disciplinas[j+1].cod_curso;
                    disciplinas[j].carga_horaria_disciplina = disciplinas[j+1].carga_horaria_disciplina;
                    disciplinas[j].periodo_da_disciplina = disciplinas[j+1].periodo_da_disciplina;
                    disciplinas[j].cod_disciplina = disciplinas[j+1].cod_disciplina;
                    strcpy(disciplinas[j].nome, disciplinas[j+1].nome);
                }
                //Atribui NULL para os dados da ultima posicao.
                disciplinas[j].cod_curso = NULL;
                disciplinas[j].cod_disciplina = NULL;
                disciplinas[j].nome = NULL;
                disciplinas[j].periodo_da_disciplina = NULL;
                disciplinas[j].carga_horaria_disciplina = NULL;
                tot_discip --;//Aumenta em 1 a quantidade de disciplinas.
            } 
        }
        printf("Disciplina removida.\n");
    }
    else
    {
        printf("Disciplina nao cadastrada!\n");
    }
}


void removeCursos(Curso *cursos,Disciplina *disciplinas, int codigo){
    int j;
    int index = verificaExistenciaCurso(cursos,codigo);//Verifica se o curso existe.
    int temounao = verificaSeOCursoTemDisciplina(disciplinas, codigo);//Verifica se o curso tem disciplina ou nnao
    if(index != -1 && temounao == -1){//Se o curso existir e nao tiver disciplinas.
        for (j = index; j < tot_cursos-1; j ++){//Percorre da posicao do curso a ser removida ate a penultima.
            // A posicao atual ira receber a posica posterior. assim o curso sera substituido e nao existira mais.
            strcpy(cursos[j].nome, cursos[j+1].nome);
            cursos[j].cod = cursos[j+1].cod;
            cursos[j].quant_periodos = cursos[j+1].quant_periodos;
            cursos[j].carga_horaria_total = cursos[j+1].carga_horaria_total;
            strcpy(cursos[j].turno, cursos[j+1].turno);
        }
        // Os dados do curso da ultima posicao recebem NULL;
        cursos[j].cod = NULL;
        cursos[j].quant_periodos = NULL;
        cursos[j].carga_horaria_total = NULL;
        cursos[j].turno = NULL;
        cursos[j].nome = NULL;
        tot_cursos --;//Diminui em 1 a quantidade de cursos.
        printf("Curso removido\n");
    }
    else
    {
        printf("Esse curso nao estah cadastrado ou ja possui disciplinas!\n");
    }
}


int verificaExistenciaDisciplina(Disciplina *disciplinas, int codigo){
    int esq, dir,meio;
    esq = -1;
    dir = tot_discip;
    while(esq < dir-1){//Enquanto o indice da esq for menor que o da direita - 1.
        meio = (dir+esq) / 2;//Obtem a posicao media.
        if(disciplinas[meio].cod_disciplina == codigo){//Se o codigo buscado for igual ao codigo da disciplina na posicao meio, retorna o indice.
            return meio;
        }
        if(disciplinas[meio].cod_disciplina < codigo){//Se o codigo buscado for maior que o codigo da disciplina na posicao meio, o indice da esq recebe o indice meio.
            esq = meio;
        }
        else{//Se o codigo buscado for menor que o codigo do curso na posicao meio, o indce da dir recebe o indice meio.
            dir = meio;
        }
    }
    return -1;//Se o curso nao for encotrado retorna -1;
}


void ordenaCursos(Curso *cursos){
    int i, j, aux;
    //Variaveis de troca.
    int ch_aux, qp_aux;
    char nome_aux[30], turno_aux[30];
    for (i = 1; i < tot_cursos; i ++){
        // pega os valores do curso na posica i.
        aux = cursos[i].cod;
        strcpy(nome_aux, cursos[i].nome);
        qp_aux = cursos[i].quant_periodos;
        ch_aux = cursos[i].carga_horaria_total;
        strcpy(turno_aux, cursos[i].turno);
        j = i - 1;
        while ((j >= 0) && (aux < cursos[j].cod)){// Enquanto o j for maior ou igual a 0, e o cod do curso da posicao j for maior que aux, troca os dados dos cursos de posicao.
            cursos[j+1].cod = cursos[j].cod;
            cursos[j+1].quant_periodos = cursos[j].quant_periodos;
            cursos[j+1].carga_horaria_total = cursos[j].carga_horaria_total;
            strcpy(cursos[j+1].turno, cursos[j].turno);
            strcpy(cursos[j+1].nome, cursos[j].nome);
            
            j --;
        }
        //Repoe os valores do curso i.
        cursos[j+1].cod = aux;
        cursos[j+1].carga_horaria_total = ch_aux;
        cursos[j+1].quant_periodos = qp_aux;
        strcpy(cursos[j+1].turno, turno_aux);
        strcpy(cursos[j+1].nome, nome_aux);
    }
}


void ordenaDisciplinas(Disciplina *disciplinas){
    int i, j, aux;
    //Variaveis de troca.
    int ch_aux, p_aux,cod_c_aux;
    char nome_aux[30];
    for (i = 1; i < tot_discip; i ++){
        // pega os valores da disciplina na posica i.
        cod_c_aux = disciplinas[i].cod_curso;
        aux = disciplinas[i].cod_disciplina;
        strcpy(nome_aux, disciplinas[i].nome);
        p_aux = disciplinas[i].periodo_da_disciplina;
        ch_aux = disciplinas[i].carga_horaria_disciplina;
        j = i - 1;
        while ((j >= 0) && (cod_c_aux < disciplinas[j].cod_curso)){// Enquanto o j for maior ou igual a 0, e o codigo de curso da disciplina da posicao j for maior que cod_c_aux, troca os dados das disciplinas de posicao.
            disciplinas[j+1].cod_curso = disciplinas[j].cod_curso;
            disciplinas[j+1].cod_disciplina = disciplinas[j].cod_disciplina;
            disciplinas[j+1].periodo_da_disciplina = disciplinas[j].periodo_da_disciplina;
            disciplinas[j+1].carga_horaria_disciplina = disciplinas[j].carga_horaria_disciplina;
            strcpy(disciplinas[j+1].nome, disciplinas[j].nome);
            j --;
        }
        //Repoe os valores da disciplina i.
        disciplinas[j+1].cod_curso = cod_c_aux;
        disciplinas[j+1].cod_disciplina = aux;
        disciplinas[j+1].carga_horaria_disciplina = ch_aux;
        disciplinas[j+1].periodo_da_disciplina = p_aux;
        strcpy(disciplinas[j+1].nome, nome_aux);
    }
}

int verificaSeOCursoTemDisciplina(Disciplina *disciplinas, int codigo){
    //Utiliza a busca binaria para procurar por disciplinas que possuem o codigo do curso pesquisado.
    int i;
    int esq, dir,meio;
    esq = -1;
    dir = tot_discip;
    while(esq < dir-1){
        meio = (dir+esq) / 2;
        if(disciplinas[meio].cod_curso == codigo){
            return meio;
        }
        if(disciplinas[meio].cod_curso < codigo){
            esq = meio;
        }
        else{
            dir = meio;
        }
    }
    return -1;
}