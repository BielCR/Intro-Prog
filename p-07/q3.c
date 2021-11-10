//Gabriel cezar Rodrigues 21.1.4157

#include <stdio.h>
#include <stdlib.h>

void repet(int *valorRepet, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("O inteiro %d  repetiu %d vezes.\n", i+1, valorRepet[i]);
    }
}
int main(){
    int digitado, verificador500 = 0;
    while(verificador500 == 0){
        printf("Digite um digitado inteiro menor ou igual a 500: ");
        scanf("%d", &digitado);
        if (digitado <= 500) verificador500 = 1;
        else printf("\nO digitado digitado eh invalido.");
    }
    int valorRepet[digitado], aleatorio;
    for(int i = 1; i <= 100000; i++){
        aleatorio = (rand() % (digitado+1));
        if(valorRepet[aleatorio] == 0) valorRepet[aleatorio] = 1;
        else valorRepet[aleatorio] += 1;
    }

    repet(valorRepet, digitado);
}