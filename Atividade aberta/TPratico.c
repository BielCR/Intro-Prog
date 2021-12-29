/*
Trabalho prático caça-palavras
Gabriel cezar Rodrigues 21.1.4157
BCC201 - introdução a programação
*/
#include <stdio.h>
#include <stdlib.h>

//funcao que fnaliza o programa
void finaliza(){
    printf("\n\nTchau!");
    exit(0);
}


//menu de inicio
int inicio(){
    char escolha[5];
    printf("Bem vindo ao Caca Palavras\nO que deseja fazer:\n1. Comecar um novo jogo.\n2. Continuar um jogo.\n3. Instrucoes do jogo.\n\n");
    printf("Escolha a opcao (digite \'sair\' em qualquer lugar para sair do jogo): ");
    fgets(escolha, 5, stdin);
    if(strcmp(escolha, "sair") == 0){
        finaliza();
    }
    return (escolha[0] - '0');
}

//solicita nome do nome do arquivo
void solicitaNome(char * nome){
   
}

//comecar novo jogo


void continuar(char *nome){
    //*nome = solicitaNome();

}

void instrucoes(){

    
}



int main()
{
    int escolha, dificuldade;
    char nome[100], nivelStr[10];
    
    do{
        escolha = inicio();
        switch (escolha){
            case 1:
                printf("Digite o nome do arquivo com as palavras: ");
                fgets(nome, 99, stdin);
                printf("%s", nome);
                if(strcmp(nome, "sair") == 0)
                    finaliza();

                printf("Digite o nivel de dificuldade facil (1), medio (2) ou dificil (3).: ");
                fgets(nivelStr, 9, stdin);
                if(strcmp(nivelStr, "sair") == 0)
                    finaliza();
                
                dificuldade = (nivelStr[0] - '0');
                printf("\nNivel aqui o: %d", dificuldade);
                 break;
                
            case 2:
                continuar(nome);
                break;
            case 3:
                instrucoes();
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }while(escolha != 1 && escolha != 2);

    FILE *arq = fopen(nome, "r");
    int n = 0, m = 0, quantPalavras = 0;
    char matriz[50];
    if(escolha == 1){
        fscanf(arq,  "%d %d\n%d", &n, &m, &quantPalavras);
        char **palavras = malloc(quantPalavras + 2);
        int i = 2;
        printf("\n\nN: %d\nM: %d\nQuant: %d", n, m, quantPalavras);



        while(i < quantPalavras){
            fgets(&palavras[i], sizeof palavras[i], arq);
            printf("%s", palavras[i]);
            i++;
        }      
        
    }

    return 0;
}
