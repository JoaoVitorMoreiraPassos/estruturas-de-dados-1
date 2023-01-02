#include <stdio.h>
#include <string.h>

#define tot_letters 30

typedef struct Players
{
    char name[tot_letters];
    int age;
    int shirt_number;
    char pos[tot_letters];
    float height;

}Players;

typedef struct Teams
{
    Players *players;
    int tam;
}Teams;

int letterB(Players *players, int t);
int numNames(char names[][tot_letters],int t);
void letterA(Players *players, float *biggest, int t);
float letterC(Players *players, char names[][tot_letters], int t);


void main(){
    int i,j, sn;
    /*Faz a declaração do struct do tipo T e aloca dinamicamente
    O ponteiro "players" do tipo Players que vem dentro do struct Teams*/
    Teams santos;
    santos.players = (Players *) malloc(sizeof(Players));
    /*Inicia a variavel de controle de quantidade de jogadores*/
    santos.tam = 0;

    /*Laco utilizado para leitura de informações dos jogadores
    Antes de ler os dados de cada jogador deve se informar se
    voce ja terminou digitando 1 ou se ainda tem mais jogadores 
    digitando 0*/
    i = 0;
    while (1){
        printf("You finished?[1/0]: ");
        scanf("%d", &sn);
        if(sn == 1){
            break;
        }
        printf("enter the name: ");
        scanf(" %[^\n]s", santos.players[i].name);

        printf("enter the age: ");
        scanf("%d", &santos.players[i].age);

        printf("Enter the shirt number: ");
        scanf("%d", &santos.players[i].shirt_number);

        printf("Enter the name of the position: ");
        scanf(" %[^\n]s", santos.players[i].pos);

        printf("Enter the height: ");
        scanf("%f", &santos.players[i].height);

        santos.tam += 1;
        i ++;
    }
    printf("#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#\n");

    //  letter a
    /* Chama a funcao letterA que eh ira processar os dados de
    todos os jogadores e irah passar a altura do maior jogador
    na variavel "max_height" que eh passada por referencia.
    Em seguida mostra a altura.*/
    float max_height = 0.0;
    letterA(santos.players, &max_height, santos.tam);
    printf("Greater height: %.2f\n", max_height);

    // letter b
    /* Faz a variavel "age" receber o retorno da funcao "letterB"
    que por sua vez retorna idade o menor jogador.
    Em seguida mostra a idade.*/
    int age = letterB(santos.players, santos.tam);
    printf("Age of lowest player: %d\n",age);

    // letter c
    /*Cria uma matriz para armazenar os nomes dos jogadores que tem
    altura media que vai ser declarada com capacidade de armazenar
    a quantidade de nomes igual a quantidade de jogadores registrados
    e cada nome poderah ter a quantidade de letras declarada globalmente.
    */
    char names[santos.tam][tot_letters];
    /* Faz a variavel "average" receber o retorno da funcao letterC que eh
    a media das alturas dos jogadores. A funcao tambem irah adicionar o nome
    dos jogadores com altura igual a media na matriz names. 
    */
    float average = letterC(santos.players, &names, santos.tam);
    /* A variavel "num_names" irah recebe a quantidade de nomes que foram
    adicionados dentro da matriz names atraves da funcao "numNames" 
    */
    int num_names = numNames(names, santos.tam);
    /* Mostra altura media armazenada na variavel "average" e em seguida
    irah mostrar o nome dos jogadores que possuem a altura media 
    */
    printf("Height average: %.2f\n",average);
    printf("Average height player(s): ");
    for (i = 0; i < num_names; i ++){
        if(i != (num_names - 1))
        {
            printf("%s, ",names[i]);
        }
        else{
            printf("%s.",names[i]);
        }
        
    }
    //Agora libera o ponteiros.
    free(santos.players);
}


void letterA(Players *players, float *max_height, int t)
{
    int i;
    *max_height = players[0].height;
    /* O laco irah percorrer o ponteiro de struct "players" em busca da
    maior altura, entre as alturas dos jogadores registrados, quando achar
    irah utilizar o apontador "max_height" para armazenar o valor na 
    variavel passada por referencia.
    */
    for (i = 1; i < t; i ++)
    {

        if(players[i].height > *max_height)
        {
            *max_height = players[i].height;
        }
    }
}


int letterB(Players *players, int t)
{
    int i, min_height;
    min_height = 0;
    /* O laco irah percorrer o ponteiro de struct "players" em busca da
    menor altura, entre as alturas dos jogadores registrados,
    Utiliza a variavel "min_height" como indice de comparacao assim,
    quando a menor altura for encotrada, serah guardada a posicao
    no vetor onde se encotra o menor jogador.
    */
    for (i = 1; i < t; i ++){
        if(players[i].height < players[min_height].height)
        {
            min_height = i;
        }
    }
    /* Utiliza a variavel "min_heigth", que possui a posicao do menor
    jogador, para acessar sua idade e armazenar na vairavel "age", em 
    seguida retorna "age".
    */
    int age = players[min_height].age;
    return age;
}


float letterC(Players *players, char names[][tot_letters], int t)
{
    int i,j, aux;
    float comparator;
    float average = 0.0;
    /* O laco irah percorrer o ponteiro de struct "players" somando as
    alturas multiplicadas por 100 dos jogadores e armazenando na vairavel
    "average".
    */
    for (i = 0; i < t; i ++){
        average += (players[i].height)* 100;
    }
    /* Divide a soma das altura pela quantidade de jogadores para obter
    a media*/
    average /= t;
    aux = 0;
    /*O laco irah percorrer o ponteiro de struct "players" em busca de
    alturas iguais a media, para adicionar o nome dos jogadores na matriz
    "names".*/
    for (i = 0; i < t; i ++){
        /* Aqui o comparador irah receber a subtracao entre a altura do 
        jogador da posicao "i" do vetor e a media, porque se eles forem iguais
        tem que ser igual a zero ou um valor bem aproximado pois quando
        se trabalha com floats nem sempre temos resultados 100% precisos,
        por isso para veficiar se é igual ou nao foi utilizada uma margem
        de erro de 0.000001 para cima e -0.000001 para baixo. 
        */
        comparator = (players[i].height * 100) - average;
        if ( comparator < 0.000001 && comparator > -0.000001)
        {
            /*Se a diferenca for igual ou aproximada a 0, adiciona-se o nome
            do jogador da posicao "i" na posicao "aux" da matriz "names"  
            */
            strcpy(names[aux], players[i].name);
            aux ++;
        }
    }
    /* O laco ira percorrer a matriz "names" da primeira posicao vazia ate
    a ultima pondo um finalizador na primeira posicao dos vetores.
    */
    for(i = aux; i < t; i ++){
        names[i][0] = '\0';
    }
    /* Como a media foi feita com as altura multiplicas por 100 para o 
    programa fazer os calculos com centimetros, agora dividi-se a media
    por 100 para retorna-la em metros.
    */
    average /= 100;
    return average;
}


int numNames(char names[][tot_letters],int t)
{
    int i,num_names = 0;
    /* O laco irah percorrer a matriz "names" e procurar por strings
    preenchidas para incrementar a variavel "num_names".
    */
    for (i = 0; i < t; i ++){
        if(strlen(names[i]) > 0){
            num_names ++;
        }
    }
    /* Retorna a quantidade de strings preenchidas na matriz.*/
    return num_names;
}