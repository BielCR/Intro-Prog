/*Aluno: Gabriel Cezar Rodrigues
Matricula: 21.1.4157
Turma: 41*/

#include <stdio.h>

void converterCelsius(float celcius, float *fahrenheit, float *kelvin);

void main(){
    float celcius, fahrenheit, kelvin;
    printf("Digite o valor da temperatura em Celsius: ");
    scanf("%f", &celcius);

    converterCelsius(celcius, &fahrenheit, &kelvin);

    printf("\n%.2f Graus Celsius equivale a %.2f graus Fahrenheit.", celcius, fahrenheit);
    printf("\n%.2f Graus Celsius equivale a %.2f graus Kelvin.", celcius, kelvin);
}

void converterCelsius(float c, float *f, float *k){
    *f = c * 9/5 + 32;
    *k = c + 273.15;
}