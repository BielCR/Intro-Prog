//Gabriel cezar Rodrigues 21.1.4157

#include <stdio.h>

int main(){
    float temperatura[30], soma = 0;
    for (int i = 0; i < 30; i++){
        printf("Digite a temperatura do dia %d do mes: ", i+1);
        scanf("%f", &temperatura[i]);
        soma += temperatura[i];
    }
    float media = soma / 30;
    printf("Os dias que ficaram acima da media foram esses: \n");
    for (int i = 0; i < 30; i++){
        if(temperatura[i] >= media) printf("Dia %d : %.2fC\n", i+1, temperatura[i]);
    }
    printf("\nOs dias que ficaram abaixo da media foram esses: \n");
    for (int i = 0; i < 30; i++){
        if(temperatura[i] < media) printf("Dia %d : %.2fC\n", i+1, temperatura[i]);
    }
    printf("\nA media foi: %.2f", media);   
}