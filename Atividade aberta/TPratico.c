/*
Trabalho prático caça-palavras
Gabriel cezar Rodrigues 21.1.4157
BCC201 - introdução a programação
*/
#include <stdio.h>
#include <stdlib.h>

//funcao que fnaliza o programa
void finaliza(char *string){
    if(strcmp(string, "sair") == 0){
        printf("\n\nTchau!");
        exit(0);
    }
}


//menu de inicio
int inicio(){
    char escolha[5];
    printf("\n\nBem vindo ao Caca Palavras\nO que deseja fazer:\n1. Comecar um novo jogo.\n2. Continuar um jogo.\n3. Instrucoes do jogo.\n\n");
    printf("Escolha a opcao (digite \'sair\' em qualquer lugar para sair do jogo): ");
    fgets(escolha, 5, stdin);
    finaliza(escolha);
    
    return (escolha[0] - '0');
}

//solicita nome do nome do arquivo
void solicitaNomeArquivo(char *nome){
   printf("\nDigite o nome do arquivo com as palavras: ");
    scanf("%s", nome);
    finaliza(nome);
}


void instrucoes(){

    
}

//funcao que cria matrizes
char **fazMatriz(int n, int m){
    char **matriz = malloc(m * sizeof(char**));
    for (int i = 0; i < m; i++)
        matriz[i] = malloc(n * sizeof(char*));
    return matriz;
}



int main()
{
    int escolha, dificuldade;
    char nome[100], nivelStr[10];
    
    do{
        escolha = inicio();
        switch (escolha){
            case 1: //iniciando um novo jogo
                solicitaNomeArquivo(nome);
                printf("\nDigite o nivel de dificuldade facil (1), medio (2) ou dificil (3).: ");
                scanf("%s", nivelStr);
                finaliza(nivelStr);
                dificuldade = (nivelStr[0] - '0'); // transformando a escolha em um inteiro

                break;
                
            case 2:
                break;
            case 3:
                instrucoes();
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }while(escolha != 1 && escolha != 2);

    FILE *arq = fopen("dicionario.txt", "r"); //abrindo um arquivo pra leitura
    int n = 0, m = 0, quantPalavras = 0;
    char **matriz;

    if(escolha == 1){ //se for um novo jogo

        fscanf(arq,  "%d %d\n%d\n", &n, &m, &quantPalavras); //lendo as 3 primeiras linhas do dicionario
        char **palavras = fazMatriz(quantPalavras, 100);//criando uma matriz para as palavras
        printf("\n\nN: %d\nM: %d\nQuant: %d\n\n", n, m, quantPalavras);
        int stlen[quantPalavras];

        //lendo o restante das palvras
       for (int i = 0; i < quantPalavras; i++){
            fscanf(arq, "%s\n", palavras[i]);
            printf("%s\n", palavras[i]);
            stlen[i] = (strlen(palavras[i]));
        }

        matriz = fazMatriz(n, m); //criando matriz do caca palavras
        printf("\n");

        for (int i = 0; i < n; i++){//preenchendo a matriz com valores aleatórios
            for (int j = 0; j < m; j++){
                matriz[i][j] = 'A' + (rand() % 26);
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }
            printf("\n\nEntrou\n\n");

        

        int linha, coluna, orientacao, verificadorUsado;
        int linhaUsada[quantPalavras][2], colunaUsada[quantPalavras][2];  
        printf("\n\n%d", dificuldade);

        if(dificuldade == 1){
            for (int i = 0; i < quantPalavras; i++){ //repetir todas as palavras

                verificadorUsado = 0;
                linhaUsada[i][0] = -5; //inicializando com valores aletorios a linha inicial.
                colunaUsada[i][0] = -5;//inicializando com valores aletorios a coluna inicial.
                linhaUsada[i][1] = -5; //inicializando com valores aletorios a linha final.
                colunaUsada[i][1] = -5;//inicializando com valores aletorios a coluna final.
                
                do{//enquanto não achar um espaco, nao muda de palavra
                    
                    orientacao = (rand() % 2); //sorteando 0 ou 1 pra orientação
                    printf("\norientacao: %d", orientacao);

                    if (orientacao == 0){ //se orientacao for igual a zero, é horizontal
                        linha = (rand() % n);
                        coluna = (rand() % (m-stlen[i]));//a coluna não deve estar mais proxima da borda do que o tamanho da palavra
                       
                        for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
                            if(linhaUsada[j][0] == linha){
                                if(coluna >= colunaUsada[j][0] && coluna <= colunaUsada[j][1])
                                    verificadorUsado = 1;
                                if((m - colunaUsada[j][1]) < (stlen[i] - 1) && colunaUsada[j][0] < (stlen[i] - 1))
                                    verificadorUsado = 1;
                            }
                            if((m - coluna) < stlen[i])
                                verificadorUsado = 1;
                        }
                        if (verificadorUsado == 0){
                                linhaUsada[i][0] = linha; // linha usada
                                linhaUsada[i][1]= linha; //linha final eh a mesma
                                colunaUsada[i][0] = coluna; //coluna usada inicial
                                colunaUsada[i][1] = coluna + stlen[i];  //coluna usada final

                                for(int k = 0; k < stlen[i]; k++)
                                    matriz[linha][coluna+k] = palavras[i][k];
                                
                        }
                        
                    }

                    if (orientacao == 0){ //se orientacao for igual a 1, é vertical
                        linha = (rand() % (n - stlen[i]));//a linha não deve estar mais proxima da borda do que o tamanho da palavra
                        coluna = (rand() % m);

                        for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
                            if(colunaUsada[j][0] == coluna){
                                if(linha >= linhaUsada[j][0] && linha <= linhaUsada[j][1])
                                    verificadorUsado = 1;
                                if((n - linhaUsada[j][1]) < (stlen[i] - 1) && linhaUsada[j][0] < (stlen[i] - 1))
                                    verificadorUsado = 1;
                            }
                            if((n - linha) < stlen[i])
                                verificadorUsado = 1;
                        }
                        if (verificadorUsado == 0){
                                linhaUsada[i][0] = linha; // linha usada
                                linhaUsada[i][1]= linha + stlen[i]; //linha final eh a mesma
                                colunaUsada[i][0] = coluna; //coluna usada inicial
                                colunaUsada[i][1] = coluna;  //coluna usada final

                                for(int k = 0; k < stlen[i]; k++)
                                    matriz[linha+k][coluna] = palavras[i][k];
                        }
                        
                    }



                    
                }while(verificadorUsado == 1);
            }    
        } 

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                printf("%c ", matriz[i][j]);
            printf("\n");
        }
        
    }

    return 0;
}
