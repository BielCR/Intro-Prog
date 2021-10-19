/*Aluno: Gabriel Cezar Rodrigues
Matricula: 21.1.4157
Turma: 41*/

#include <stdio.h>
#include <math.h>

void calculaDuracao(int horaI, int minutoI, int horaT, int minutoT, int *duracao);

int main(){
    int horaI, minutoI, horaT, minutoT, duracao;
    printf("Digite a hora e os minutos em que o jogo iniciou: ");
    scanf("%d %d", &horaI, &minutoI);
    
    printf("Digite a hora e os minutos em que o jogo finalzou: ");
    scanf("%d %d", &horaT, &minutoT);
    calculaDuracao(horaI, minutoI, horaT, minutoT, &duracao);

    printf("O jogo durou %d minutos.", duracao);
    return 0;
}

void calculaDuracao(int horaI, int minutoI, int horaT, int minutoT, int *duracao){
    int horaIMinutos = (horaI * 60) + minutoI;
    int horaTMinutos = (horaT * 60) + minutoT;
    *duracao = horaTMinutos - horaIMinutos;
    if(*duracao < 0){
        *duracao += 1440;
    }
}