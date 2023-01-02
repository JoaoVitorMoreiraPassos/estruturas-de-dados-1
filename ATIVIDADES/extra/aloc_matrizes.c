#include <stdio.h>


// void main(){
//     int quant, i, j;
//     scanf("%d",&quant);
//     float *notas;
//     notas = (float *) calloc(quant, sizeof(float));
    
//     for (i = 0; i< quant; i ++){
//         scanf("%f", &notas[i]);
//     }

//     float media = 0;
//     for(i = 0; i < quant; i ++){
//         media += notas[i];
//     }
//     printf("%.2f",media /= quant);
//     free(notas);
// }


void main(){
    float ***m;
    int t1 = 1, t2 = 3, t3 = 3,i,j,k;
    m = (float ***) calloc(t1,sizeof(float **));
    for(i = 0; i < t2; i ++){
        m[i] = (float **) calloc(t2, sizeof(float *));
    }
    for(i = 0; i < t2; i ++){
        for (j = 0; j < t3; j ++){
            m[i][j] = (float *) calloc(t3,sizeof(float));
        }
    }
    for(i = 0; i < t1; i ++){
        for(j = 0; j < t2; j ++){
            for( k = 0;k < t3; k ++){
                printf("%.0f ",m[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    for(i = 0; i < t2; i ++){
        for (j = 0; j < t3; j ++){
            free(m[i][j]);
        }
    }
    for(i = 0; i < t2; i ++){
        free(m[i]);
    }
    free(m);
}