//Gabriel cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>
#include <string.h>


typedef struct
{
    char nome[50];
    float nota, freq;
} Aluno;


int main()
{
    FILE *arquivo = fopen("arquivo.txt", "w");
    int ver = 0;
    Aluno *a;
    do{
        printf("Digite 1 para finalizar o programa e 0 para add outro aluno.");
        scanf("%d", &ver);
        printf("\nDigite o nome do aluno: ");
        fgets(a->nome, 49, stdin);
        printf("Digite a nota do aluno: ");
        scanf("%f", &a->nota);
        printf("Digite a frequencia do aluno em porcento: ");
        scanf("%f", &a->freq);

        fprintf(arquivo, "%s %f %f", a->nome, a->nota, a->freq);
    }while(ver == 0);

    fclose(arquivo);

    return 0;
}