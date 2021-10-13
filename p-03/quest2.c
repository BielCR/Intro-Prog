/*Aluno: Gabriel Cezar Rodrigues
Matricula: 21.1.4157
Turma: 41*/

#include <stdio.h>
#include <math.h>


int calculaRaizes(float a, float b, float c, float *raiz1, float *raiz2);

void main(){
    float a, b, c, raiz1, raiz2;
    printf("Digite o valor de a, b e c nessa mesma ordem: ");
    scanf("\n%f", &a);
    scanf("\n%f", &b);
    scanf("\n%f", &c);

    int resultado = calculaRaizes(a, b, c, &raiz1, &raiz2);

    if(resultado == 1){
        printf("\nAs raizes da equacao sao %.2f e %.2f", raiz1, raiz2);
    }else{
        printf("A equacao nao tem raizes reais.");
    }
}

int calculaRaizes(float a, float b, float c, float *raiz1, float *raiz2){
    float delta = b*b-4*a*c;
    printf("%.2f", delta);
    if(delta >= 0.0){
        *raiz1 = (-b + sqrt(delta)) / (2 * a);
        *raiz2 = (-b - sqrt(delta)) / (2 * a);
        return 1;
    }else{
        return 0;
    }
}