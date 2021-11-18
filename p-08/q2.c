//Gabriel cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>
#include <string.h>

int main(){
    char palavra [60], inverso[60];
    do{
        printf("---------------------------------------------------------------------------");
        printf("\nDigite uma palavra qualquer para verificar se ela eh palindroma.\nCaso deseje finalizar o programa, digite FIM: \n");
        fgets(palavra, 59, stdin);
        int tamanho = strlen(palavra);
        palavra[tamanho-1] = '\0';

        //finalizando o programa se digitar fim
        if (strcmp(palavra, "FIM") == 0)
            return 0;

        //preenchendo um string contrario para verificar
        for (int i = 0; i < tamanho - 1; i++)
            inverso[i] = palavra[tamanho-2-i];

        inverso[tamanho - 1] = '\0';

        //verificando
        int verificador = 0;
        for (int i = 0; i < tamanho - 1; i++){
            if (palavra[i] == inverso[i])
               verificador++;
        }


        printf("\nPalavra digitada: %s\nInverso da palavra: %s\n", palavra, inverso);
        if (verificador == tamanho - 1)
            printf("A palavra eh um palindromo\n");
        else
            printf("Nao eh um palindromo\n");        
    } while (strcmp(palavra, "FIM") != 0);

    return 0;
}