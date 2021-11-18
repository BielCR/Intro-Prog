//Gabriel cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>

void leitura(int matriz[][10], int linha, int coluna){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("Valor de [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void impressora(int matriz[][10], int linha, int coluna){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%d ", &matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int m, p, q, n;
    int soma = 0;

    //verificando os casos de erro
    do{
        printf("Digite quantas linhas e colunas possue a matriz A, respectivamente:\n");
        scanf("%d %d", &m, &p);

        printf("Digite quantas linhas e colunas possue a matriz B, respectivamente:\n");
        scanf("%d %d", &q, &n);

        if(p != q)
            printf("O valor digitado nao eh valido. \nO numero de colunas da Matriz A tem que ser igual ao numero de linhas da matriz B.\n");
        if(m > 10 || n > 10 || p > 10 || q > 10)
            printf("Os valores digitados precisam ser menores ou iguais a 10.\n");
    }while(p != q || m > 10 || n > 10 || p > 10 || q > 10);



    int a[m][10], b[q][10], c[m][10];

    //lendo matriz A
    printf("digite os valores da matriz A:\n");
    leitura(a, m, p);

    //lendo matriz b
    printf("digite os valores da matriz B:\n");
    leitura(b, q, n);


    //produto
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < p; k++){
                soma += a[i][k] * b[k][j];
            }
            c[i][j] = soma;
            soma = 0;
        }
    }

    impressora(c, m, n);

    return 0;
}