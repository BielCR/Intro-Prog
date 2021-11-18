//Gabriel cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>
#include <string.h>

int main(){
    char texto[300];
    printf("Digite o texto para censurar: \n");
    fgets(texto, 299, stdin);
    
    int tamanho = strlen(texto);
    texto[tamanho-1] = '\0';

    for (int i = 0; i < tamanho; i++){
        switch (texto[i]){
            case 'a':
                texto[i] = '@';
                break;
            case 'e':
                texto[i] = '_';
                break;
            case 'i':
                texto[i] = '|';
                break;
            case 'o':
                texto[i] = '0';
                break;
            case 'u':
                texto[i] = '#';
                break;
            case 's':
                texto[i] = '$';
                break;
            default:
                break;
        }
    }

    printf("\n\n%s", texto);

    
}