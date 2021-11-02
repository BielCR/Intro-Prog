//Gabriel Cezar Rodrigues   21.1.4157

#include <stdio.h>
#include <math.h>

double pi(int termos){
    int contador = 1, base = 3;
    double s = 1;
    while(contador <= termos){
        if(contador % 2 == 0)
            s += 1 / pow(base, 3);
        else
            s -= 1 / pow(base, 3);
        base += 2;
        contador ++;
    }
    
    double pi = pow(s * 32, 1.0/3.0);
    return pi;
}

int main(){
    int termos;
    printf("Digite o numero termos.");
    scanf("%d", &termos);
    printf("PI = %lf", pi(termos));
    return 0;
}