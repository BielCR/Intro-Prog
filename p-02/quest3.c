//Gabriel Cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>
#include <stdlib.h>

//definindo a variavel global
char letra = 'a';

//prototipo da funcao
int vogal();

//funcao que verifica se e vogal
int vogal(){
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
        letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        return 1;
}

void main(){
    //lendo o que esta armazenado na variavel global
    printf("O valor armazenado na variavel global eh: %c\n", letra);

    if(vogal() == 1)
        printf("A variavel global eh uma vogal.");
    else
        printf("A variavel global eh uma consoante.");
}