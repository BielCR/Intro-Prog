//Gabriel Cezar Rodrigues   21.1.4157

#include <stdio.h>

long long fat(int n);

int main(){
    int valor;
    printf("Digite o valor de n: ");
    scanf("%d", &valor);
    long long fatorial = fat(valor);
    printf("\n%d! = %lld", valor, fatorial);
    return 0;
}

long long fat(int n){
    long long resultado = 1;
    int contador = 1;
    do{
        resultado = resultado * contador;
        contador++;
    }while(contador != (n+1));
    return resultado;
}