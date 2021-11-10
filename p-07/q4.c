//Gabriel cezar Rodrigues 21.1.4157

#include <stdio.h>

int main(){
    int troca, cont = 0;
    int vetor[15];
    while(cont < 15){
        printf("digite o valor numero %d: \n", cont+1);
        scanf("%d", &vetor[cont]);
        cont++;
    }
    
    printf("Quantos valores deseja rotacionar? ");
    scanf("%d", &troca);

    //exibindo o vetor sem as trocas
    printf("Vetor sem as trocas: \n");
    for(int i = 0; i < 15; i++){
        printf("%d ",vetor[i]);
    }
    //armazenando os valores em um vetor auxiliar
    int aux[troca];
    for (int i = 0; i < troca; i++){
        aux[i] = vetor[i];
    }

    //movendo os valores do vetor para a esquerda
    for(int i = 0; i < 15 - troca; i++){
        vetor[i] = vetor[i+troca];
    }

    //movendo os valores
    for (int i = 0; i < troca; i++){
        vetor [15 - troca + i] = aux[i];
    }

    //exibindo vetor com as trocas
    printf("\n\nVetor com as trocas: \n");
    for(int i = 0; i < 15; i++){
        printf("%d ",vetor[i]);
    }
    
}