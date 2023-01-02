#include <stdio.h>
#include <stdlib.h>

void main(){
    char *nomes[] = {"Joao","Maria","Carlos","Paulo","Carol","Luiza","Jose"};
    FILE *arq;
    arq = fopen("testes.txt","w");
    int i;
    float notes;

    for (i = 0; i < 10; i ++){
        fprintf(arq,"%s\n",nomes[rand()%7]);
        fprintf(arq,"%d\n",(rand()%100000)+99999);
        fprintf(arq,"%c\n",((rand()%3)+65));
        notes = ((rand()%100)+10)/10;
        fprintf(arq,"%.2f\n",notes);
        notes = ((rand()%100)+10)/10;
        fprintf(arq,"%.2f\n",notes);
        notes = ((rand()%100)+10)/10;
        fprintf(arq,"%.2f\n",notes);
        
    }
    fclose(arq);
    printf("concluido\n");
}