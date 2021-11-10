//Gabriel cezar Rodrigues 21.1.4157

#include <stdio.h>

int main(){
    int fibonacci[10];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i = 2; i <= 10; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    printf("Os dez primeiros numeros sao:");
    for (int i = 0; i < 10; i++){
        printf(", %d", fibonacci[i]);
    }
    printf(".");
    return 0;
}