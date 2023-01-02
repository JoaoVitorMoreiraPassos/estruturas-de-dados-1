#include <stdio.h>
#include <stdlib.h>


void ler_aposta(int *aposta, int n);
void sorteia_valores(int *sorteio, int n);
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int
ns);
void mostraAcertos(int *aposta, int *sorteio,int *acertos, int na, int ns, int nac);
int jaExiste(int *v,int n, int size);

int main(){
    int quant;
    int n_apost;
    int n_sort= 20;
    while(1){//Ler a quantidade de numeros que o usuario vai apostar.
        printf("Quantidade de numeros a apostar: ");
        scanf("%d", &n_apost);
        if(n_apost > 0 && n_apost <= 20){
            break;
        }else{printf("Numero invalido!\n");}
    }
    int *aposta, *sorteio;
    //Aloca os vetores de aposta e sorteio.
    aposta = (int *) calloc(n_apost, sizeof(int));
    sorteio = (int *) calloc(n_sort, sizeof(int));
    int *acertos;
    ler_aposta(aposta, n_apost);//Ler os numeros apostados pelo usuario.
    printf("leu\n");
    sorteia_valores(sorteio, n_sort);//Sorteia os numeros.
    printf("sorteou\n");
    acertos = compara_aposta(aposta, sorteio, &quant, n_apost, n_sort);// Pega os valores que o usuario acertou.
    printf("quan: %d\n",quant);
    mostraAcertos(aposta, sorteio, acertos, n_apost, n_sort, quant);// Mostra o resultado.
    int i;
    free(acertos);
    free(aposta);
    free(sorteio);
    printf("concluido com sucesso");
    return 0;
}

void ler_aposta(int *aposta, int n){
    int i, temp;
    for (i = 0; i < n; i ++){//Irah ler numeros ate que a quantidade de numeros seja igual a recebida por parametro.
        while (1){//Verifica se o numero esta entre 0 e 100 ou se estah repetido.
            printf("%do Numero: ", i+1);
            scanf("%d", &temp);
            if(temp >= 0 && temp <= 100 && (jaExiste(aposta, temp, i)) == 0){
                break;
            }
            else{
                printf("Numero invalido!\n");
            }
        }
        aposta[i] = temp;//Depois de verificar adicionar o numero no vetor.
    }
}

void sorteia_valores(int *sorteio, int n){
    int i,j, temp, aux;
    int passa;
    aux = 0;
    for (i = 0; i < n; i ++){//Sotear 20 numeros.
        while(1){
            temp = (rand()%101);//Os numeros sorteados serao entre 0 e 100.
            passa = jaExiste(sorteio, temp, i);//Verifica se o numero ja existe no vetor.
            if(passa == 0){//Se nao existir adiciona o temp no vetor de numeros sorteados.
                sorteio[aux] = temp;
                aux ++;
            }
        }
        
    }
}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int
ns){
    int *v;
    int i, j;
    *qtdacertos = 0;//Inicializa a quantidad de acertos como 0.
    for (i = 0; i < na; i ++){//Percorre o vetor dos numeros apostados.
        for(j = 0; j < ns; j ++){//Percorre o vetor dos numeros sorteados
            if(aposta[i] == sorteio[j]){//Verifica se o numero do vetor dos apostados eh igual ao do vetor dos sorteados.
                if(*qtdacertos == 0){//Verifica a quantidade de acertos para fazer a alocao ou realocacao dinamica do vetor.
                    v = (int *) calloc(1, sizeof(int));
                }
                else{
                    v = (int *) realloc(v,(*qtdacertos+1)* sizeof(int));
                }
                v[*qtdacertos] = sorteio[j];//Adiciona o numero na ultima posicao do vetor dos acertados.
                ++ *qtdacertos;//Aumenta em 1 a quantidade de numeros acertados.
            }
        }
    }
    return v;//Retorna o vetor dos acertados.
}


void mostraAcertos(int *aposta, int *sorteio,int *acertos, int na, int ns, int nac){
    //Mostra o resultados.
    int i;
    printf("apostados\n");
    for (i = 0; i < na; i ++){
        if(i != na-1){
            printf("%d  |  ", aposta[i]);
        }else{
            printf("%d\n",aposta[i]);
        }
    }
    printf("\nSorteados\n");
    for (i = 0; i < ns; i ++){
        if(i != ns-1){
            printf("%d  |  ", sorteio[i]);
        }else{
            printf("%d\n",sorteio[i]);
        }
    }
    printf("\nAcertados\n");
    for (i = 0; i < nac; i ++){
        if(i != nac-1){
            printf("%d  |  ", acertos[i]);
        }else{
            printf("%d\n",acertos[i]);
        }
    }
}

int jaExiste(int *v,int n, int size){
    int i;
    for (i = 0; i < size; i ++){//Percorre o vetor passado ate seu ultimo valor em busca de um numero, se encontrar retorna 1,senao, retorna 0.
        if(v[i] == n){
            return 1;
        }
    }
    return 0;
}