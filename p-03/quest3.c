/*Aluno: Gabriel Cezar Rodrigues
Matricula: 21.1.4157
Turma: 41*/

#include <stdio.h>
#include <math.h>

int calculaDuracao(int *horaI, int *minutoI, int *horaT, int *minutoT);

void main(){
    int horaI, minutoI, horaT, minutoT, duracao;
    printf("Digite a hora e os minutos em que o jogo iniciou: ");
    scanf("%d", &horaI);
    scanf("%d", &minutoI);
    
    printf("Digite a hora e os minutos em que o jogo finalzou: ");
    scanf("%d", &horaT);
    scanf("%d", &minutoT);

    printf("O jogo durou %d minutos.", calculaDuracao(&horaI, &minutoI, &horaT, &minutoT));
}

int calculaDuracao(int *horaI, int *minutoI, int *horaT, int *minutoT){
    int horaIMinutos = (*horaI * 60) + *minutoI;
    int horaTMinutos = (*horaT * 60) + *minutoT;
    int resultado = horaTMinutos - horaIMinutos;
    return resultado;
}