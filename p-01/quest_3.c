/*
Aluno: Gabriel Cezar Rodrigues
Matricula: 21.1.4157
Turma: 41
*/
#include <stdio.h>

int main(){
    //declarando as variaveis
    int n1, n2, n3;

    //atribuindo valores as variaveis com interacao do usuario
    printf("Usuario, favor informar o primeiro numero:\n");
    scanf("%d", &n1);
    printf("Usuario, favor informar o segundo numero:\n");
    scanf("%d", &n2);
    printf("Usuario, favor informar o terceiro numero:\n");
    scanf("%d", &n3);

    //atribuindo valores padroes as variaveis para poder comparar nos if's
    int maior = n1, medio = n1, menor = n1;

    //verificando quem e o maior numero
    if(n1 >= maior && n1 > n2 && n1 > n3){
        maior = n1;
    }
    if(n2 >= maior && n2 > n1 && n2 > n3){
        maior = n2;
    }   
    if(n3 >= maior && n3 > n1 && n3 > n2){
        maior = n3;
    }

    //verificando quem e o menor numero
    if(n1 <= menor && n1 < n2 && n1 < n3){
        menor = n1;
    }
    if(n2 <= menor && n2 < n1 && n2 < n3){
        menor = n2;
    }
    if(n3 <= menor && n3 < n1 && n3 < n2){
        menor = n3;
    }
        
    //verificando quem e o medio
    if(n1 != maior && n1 != menor){
        medio = n1;
    }
    if(n2 != maior && n2 != menor){
        medio = n2;
    }
    if(n3 != maior && n3 != menor){
        medio = n3;
    }

    //exibindo resultados
    printf("Menor: %d\n", menor);
    printf("Intermediario: %d\n", medio);
    printf("Maior: %d\n", maior);
    return 0;
}