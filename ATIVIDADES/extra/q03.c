#include <stdio.h>


void main()
{
    float n1, n2, n3, *media;
    // fazer a alocação dinamica do ponteiro.
    media = (float *) malloc (sizeof(float));
    // ler as notas
    scanf("%f %f %f",&n1, &n2, &n3);
    // passar a media para o conteudo do local de memoria para onde o ponteiro aponta.
    *media = (n1 + n2 + n3) / 3;
    // Verificando a Media para saber se o aluno está aprovado ou reprovado.
    if(*media >= 7)
    {
        printf("Aprovado\n");
    }else
    {
        printf("Reprovado\n");
    }
    // mostrar a media
    printf("%.2f\n",*media);
}