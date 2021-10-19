//Gabriel Cezar Rodrigues   21.1.4157

#include <stdio.h>

int parOuImpar(int x, int y);
int contaRepeticao(int x, int y);

int main(){
    int x, y;
    int espacos;
    do{
        printf("Digite os valores de x e y: ");
        scanf("%d %d", &x, &y);
        if(parOuImpar(x, y) == 1){
            printf("Apenas numeros pares sao aceitos");
        }else if (x >= y){
            printf("X deve ser menor que Y");
        }else{
            espacos = (y - x) /2;

        }
}