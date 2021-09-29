/*
Aluno: Gabriel Cezar Rodrigues
Matricula: 21.1.4157
Turma: 41
*/
#include <stdio.h>

int main(){
    //declarando a variavel
    int ano;

    //solicitando que o usuario digite um valor para a variavel
    printf("Usuario, favor informar um ano:\n");
    scanf("%i", &ano);

    //fazendo as verificacoes para ver se o ano e bissexto
    if(ano % 4 == 0 && ano % 100 != 0 || ano % 100 == 0 && ano % 400 == 0){
        //caso o ano seja bissexto (if(true))
        printf("Ano bissexto!");
    }
    else{
        //caso o ano nao seja bissexto (if(false))
        printf("Ano nao bissexto!");
    } 
    return 0;
}