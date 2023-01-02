#include <stdio.h>
#include <string.h>


int vogalOrNo(char c)
{
/*  Recebe um caractere e o compara com as vogais presentes 
    Em um vetor que contém vogais se ele for igual a uma vogal
    Retornará 1, senão retornará 0 */
    char vogais[] = {"AaEeIiOoUu"};
    int i, t = strlen(vogais);
    for (i = 0; i < t; i ++)
    {
        if(c == vogais[i])
        {
            return 1;
        }
    }
    return 0;
}


char * vogais(char *str1, char *str2)
{
/*  Recebe duas strings */
/*  Extrai o tamanho das duas strings*/
    int i, j, t1 = strlen(str1), t2 = strlen(str2), t3 = 0;
/*  Cria um ponteiro de caracteres e o aloca dinamicamente */
    char *str3;
    str3 = (char *) malloc(sizeof(char));
    int menor,maior;
    if(t1 < t2){
        menor = t1;
        maior = t2;
    }else{
        menor = t2;
        maior = t1;
    }
/*  Percorre as duas strings */
    for(i = 0; i < menor; i ++){
        if(vogalOrNo(str1[i]) == 1){
            str3[t3] = str1[i];
            t3 ++;
        }
        if(vogalOrNo(str2[i]) == 1){
            str3[t3] = str2[i];
            t3 ++;
        }
    }
    if(t3 != maior){
        for(j = i; j < maior; j ++){
            if(t1 == maior){
                if(vogalOrNo(str1[j]) == 1){
                    str3[t3] = str1[j];
                    t3 ++;
                }
            }
            if(t2 == maior){
                if(vogalOrNo(str2[j]) == 1){
                    str3[t3] = str2[j];
                    t3 ++;
                }
            }
        }
    }
    
/*  Finaliza o vetor adicionando um '\0' no final */
    str3[t3] = '\0';
/*  Retorna um ponteiro */
    return str3;
}


void main()
{
    char str1[20], str2[20];
    char *str3;
/*  lê as duas strings */
    scanf(" %[^\n]s", &str1);
    scanf(" %[^\n]s", &str2);
/*  Atribue ao ponteiro o retono a função vogais */    
    str3 = vogais(&str1,&str2);
/*  Mostra caractere por caractere de str3 */
    int i;
    for(i = 0; i < strlen(str3); i ++)
    {
        printf("%c",*(str3+i));
    }
}
