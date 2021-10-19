//Gabriel Cezar Rodrigues   21.1.4157

#include <stdio.h>

int is_prime (int n);

int main(){
    int n, result;
    printf("Digite um valor inteiro para conferir se ele eh primo.\n");
    scanf("%d", &n);
    result = is_prime(n);
    if(result == 1){
        printf("%d eh um numero primo.", n);
    }else{
        printf("%d NAO eh um numero primo.", n);
    }
    return 0;
}

int is_prime(int n){
    int result, cont = 2; //iniciando o contador como 2 para n pegar o resto da divisao por 1
    do{
        result = n % cont;
        if(result == 0){
            return 0;
        }else{
            return 1;
        }
        cont++;
        if(cont > 10 && result != 0){
            return 1;
        }
    }while(cont < n);//menor do que n pois nao queremos que calcule o resto da divisao pelo proprio numero
}