//Gabriel Cezar Rodrigues   21.1.4157   Pratica 11

#include <stdio.h>
#include <stdlib.h>


double** cria_matriz(int m, int n){
    double **matriz = malloc(m * sizeof(int*));
    for (int i = 0; i < n; i++)
        matriz[i] = malloc(n * sizeof(int));
    return matriz;
}

double** cria_transposta (double **A, int m, int n){
    double **t = cria_matriz(n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            t[i][j] = A[j][i];
    }
    return t;
}


void desaloca_matriz(double** A, int m){
    for (int i = 0; i < m; i++)
        free(A[i]);
    free(A);
}

int main(){

    //declarando a matriz
    int m, n;
    printf("Digite o numero de linhas e colunas da matriz: ");
    scanf("%d %d", &m, &n);
    double **matriz = cria_matriz(m, n);
    
    //armazenando valores na matriz
    printf("\nDigite os valores da matriz\n");
    for (int i = 0; i < m; i++){
        printf("--------Linha %d--------\n", (i+1));
        for (int j = 0; j < n; j++){
            printf("coluna %d: ", (j+1));
            scanf("%lf", &matriz[i][j]);
        }
        printf("\n");
    }

    //criando transposta
    double **transposta = cria_transposta(matriz, m, n);

    //exibindo matriz original
    printf("\n\n---------------Matriz original---------------\n");
    for (int i = 0; i < m; i++){
        printf("[");
        for (int j = 0; j < n; j++)
            j == 0 ? printf(" %.2lf", matriz[i][j]) : printf(", %.2lf", matriz[i][j]);
        printf(" ]\n");
    }

    //exibindo matriz transposta
    printf("\n\n---------------Matriz transposta---------------\n");
    for (int i = 0; i < n; i++){
        printf("[");
        for (int j = 0; j < m; j++)
            j == 0 ? printf(" %.2lf", transposta[i][j]) : printf(", %.2lf", transposta[i][j]);
        printf(" ]\n");
    }

    
    desaloca_matriz(matriz, m);
    desaloca_matriz(transposta, n);
    return 0;
}