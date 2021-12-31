/*
Trabalho prático caça-palavras
Gabriel cezar Rodrigues 21.1.4157
BCC201 - introdução a programação
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

//funcao que cria matrizes de String
char **fazMatrizChar(int n, int m, int strinOuChar){
    char **matriz = malloc(n * sizeof(char**));

    if(strinOuChar == 1){ //se for 1, cria matriz de string
        for (int i = 0; i < n; i++)
            matriz[i] = malloc(m * sizeof(char*));
    }else{ //cria matriz de char
        for (int i = 0; i < n; i++)
            matriz[i] = malloc(m * sizeof(char));
    }
    return matriz;
}

//funcao que cria matrizes de Int
int **fazMatrizInt(int n, int m){
    int **matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        matriz[i] = malloc(m * sizeof(int));
    return matriz;
}

void horizontal(char **palavras, int **linha, int**coluna, int n, int m, int *tamanhoPalavras, int i, int **linhaUsada, int**colunaUsada, char**matriz){
    int verificadorUsado;
    for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
        verificadorUsado = 0;
        linha[i][0] = (rand() % n);
        coluna[i][0] = (rand() % (m-tamanhoPalavras[i]));//a coluna não deve estar mais proxima da borda do que o tamanho da palavra
        
        linha[i][1] = linha[i][0];//ultima linha usada pela string
        coluna[i][1] = coluna[i][0] + tamanhoPalavras[i]; //ultima coluna usada pela string

        //se crusar com uma palvra na vertical
        if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1] && coluna[i][0] <= colunaUsada[j][0] && coluna[i][1] >= colunaUsada[j][0])
                verificadorUsado = 1;
        
        if(linhaUsada[j][0] == linha[i][0]){

            if(coluna[i][0] >= colunaUsada[j][0] && coluna[i][0] <= colunaUsada[j][1]) //se estiver comecando dentro de alguma palavra usada
                verificadorUsado = 2;
                
            

            if(coluna[i][1] >= colunaUsada[j][0] && coluna[i][1] <= colunaUsada[j][1]) //se estiver finalizando dentro de alguma palavra usada
                verificadorUsado = 3;

            if((m - colunaUsada[j][1]) < (tamanhoPalavras[i] - 1) && colunaUsada[j][0] < (tamanhoPalavras[i] - 1)) //se não tiver espaco depois da coluna ou antes
                verificadorUsado = 4;

        }
    
        if(coluna[i][1] > m)
            verificadorUsado = 5;

        printf(" - %d\n", verificadorUsado);
        if (verificadorUsado == 0){
            linhaUsada[i][0] = linha[i][0]; // linha usada
            linhaUsada[i][1]= linha[i][1]; //linha final eh a mesma
            colunaUsada[i][0] = coluna[i][0]; //coluna usada inicial
            colunaUsada[i][1] = coluna[i][1];  //coluna usada final

            for(int k = 0; k < tamanhoPalavras[i]; k++)
                matriz[linha[i][0]][coluna[i][0] + k] = palavras[i][k];
            
            break;    
        }
    }
}

void vertical(char **palavras, int **linha, int**coluna, int n, int m, int *tamanhoPalavras, int i, int **linhaUsada, int**colunaUsada, char**matriz){
    int verificadorUsado;
    for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
                                
        verificadorUsado = 0;
        linha[i][0] = (rand() % (n-tamanhoPalavras[i]));//a linha não deve estar mais proxima da borda do que o tamanho da palavra
        coluna[i][0] = (rand() % m);
        linha[i][1] = linha[i][0] + tamanhoPalavras[i];//ultima linha usada pela string
        coluna[i][1] = coluna[i][0]; //ultima coluna usada pela string

        //se cruzar com alguma palavra na horizontal
        if(coluna[i][0] >= colunaUsada[j][0] && coluna[i][0] <= colunaUsada[j][1] && linha[i][0] <= linhaUsada[j][0] && linha[i][1] >= linhaUsada[j][0])
                verificadorUsado = 1;


        if(colunaUsada[j][0] == coluna[i][0]){

            if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1]) //se estiver comecando dentro de alguma palavra usada
                verificadorUsado = 2;


            if(linha[i][1] >= linhaUsada[j][0] && linha[i][1] <= linhaUsada[j][1]) //se estiver finalizando dentro de alguma palavra usada
                verificadorUsado = 3;


            if((n - linhaUsada[j][1]) < (tamanhoPalavras[i] - 1) && linhaUsada[j][0] < (tamanhoPalavras[i] - 1)) //se não tiver espaco depois da coluna ou antes
                verificadorUsado = 4;
        }

        if(linha[i][1] > n)
            verificadorUsado = 5;

        printf(" - %d\n", verificadorUsado);
        
        if (verificadorUsado == 0){
            linhaUsada[i][0] = linha[i][0]; // linha usada
            linhaUsada[i][1]= linha[i][1]; //linha final eh a mesma
            colunaUsada[i][0] = coluna[i][0]; //coluna usada inicial
            colunaUsada[i][1] = coluna[i][1];  //coluna usada final

            for(int k = 0; k < tamanhoPalavras[i]; k++)
                matriz[linha[i][0]+k][coluna[i][0]] = palavras[i][k]; //colocando as string na matriz
            
            break;    
        }
    }
}

void diagonal(char **palavras, int **linha, int**coluna, int n, int m, int *tamanhoPalavras, int i, int **linhaUsada, int**colunaUsada, char**matriz){
    int verificadorUsado;
    for (int j = 0; j <= i; j++){//verificando se já foi usado a coluna ou a linha
                                
        verificadorUsado = 0;
        linha[i][0] = (rand() % n);//a linha não deve estar mais proxima da borda do que o tamanho da palavra
        coluna[i][0] = (rand() % m);
        linha[i][1] = linha[i][0] + tamanhoPalavras[i];//ultima linha usada pela string
        coluna[i][1] = coluna[i][0] + tamanhoPalavras[i]; //ultima coluna usada pela string

        //se cruzar com alguma palavra na horizontal
        if(coluna[i][0] >= colunaUsada[j][0] && coluna[i][0] <= colunaUsada[j][1] && linha[i][0] <= linhaUsada[j][0] && linha[i][1] >= linhaUsada[j][0])
                verificadorUsado = 1;
        
        //se cruzar com palavra na vertical
        if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1] && coluna[i][0] <= colunaUsada[j][0] && coluna[i][1] >= colunaUsada[j][0])
                verificadorUsado = 1;


        if(colunaUsada[j][0] == coluna[i][0]){

            if(linha[i][0] >= linhaUsada[j][0] && linha[i][0] <= linhaUsada[j][1]) //se estiver comecando dentro de alguma palavra usada
                verificadorUsado = 2;


            if(linha[i][1] >= linhaUsada[j][0] && linha[i][1] <= linhaUsada[j][1]) //se estiver finalizando dentro de alguma palavra usada
                verificadorUsado = 3;


            if((n - linhaUsada[j][1]) < (tamanhoPalavras[i] - 1) && linhaUsada[j][0] < (tamanhoPalavras[i] - 1)) //se não tiver espaco depois da coluna ou antes
                verificadorUsado = 4;

            
        }

        if(linha[i][1] > n)
            verificadorUsado = 5;

        printf(" - %d\n", verificadorUsado);
        
        if (verificadorUsado == 0){
            linhaUsada[i][0] = linha[i][0]; // linha usada
            linhaUsada[i][1]= linha[i][1]; //linha final eh a mesma
            colunaUsada[i][0] = coluna[i][0]; //coluna usada inicial
            colunaUsada[i][1] = coluna[i][1];  //coluna usada final

            for(int k = 0; k < tamanhoPalavras[i]; k++)
                matriz[linha[i][0]+k][coluna[i][0]+k] = palavras[i][k]; //colocando as string na matriz
            
            break;    
        }
    }
}


int main()
{
    srand ( time(NULL) );
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
            char **palavras = fazMatrizChar(quantPalavras, 100, 1);//criando uma matriz para as palavras
            printf("\n\nN: %d\nM: %d\nQuant: %d\n\n", n, m, quantPalavras);
            int *tamanhoPalavras = malloc(quantPalavras);

            //lendo o restante das palvras
            for (int i = 0; i < quantPalavras; i++){
                fscanf(arq, "%s\n", palavras[i]);
                tamanhoPalavras[i] = (strlen(palavras[i]));
                printf("%s - %d\n", palavras[i], tamanhoPalavras[i]);
            }

            matriz = fazMatrizChar(n, m, 2); //criando matriz do caca palavras
            printf("\n");

            for (int i = 0; i < n; i++){//preenchendo a matriz com valores aleatórios
                for (int j = 0; j < m; j++){
                    matriz[i][j] = 'A' + (char)(rand() % 26);
                    printf("%c ", matriz[i][j]);
                }
                printf("\n");
            }
            printf("\n\nEntrou\n\n");

            

            int **linha = fazMatrizInt(quantPalavras, 2), **coluna = fazMatrizInt(quantPalavras, 2), orientacao, verificadorUsado;
            int **linhaUsada = fazMatrizInt(quantPalavras, 2), **colunaUsada = fazMatrizInt(quantPalavras, 2);  

            if(dificuldade == 1){
                for (int i = 0; i < quantPalavras; i++){ //repetir todas as palavras

                    verificadorUsado = 0;
                    linhaUsada[i][0] = -5; //inicializando com valores aletorios a linha inicial.
                    colunaUsada[i][0] = -5;//inicializando com valores aletorios a coluna inicial.
                    linhaUsada[i][1] = 1000; //inicializando com valores aletorios a linha final.
                    colunaUsada[i][1] = 1000;//inicializando com valores aletorios a coluna final.
                    
                    do{//enquanto não achar um espaco, nao muda de palavra
                        
                        orientacao = (rand() % 2); //sorteando 0 ou 1 pra orientação
                        printf("\norientacao: %d - %s", orientacao, palavras[i]);

                        if (orientacao == 0) //se orientacao for igual a zero, é horizontal
                            horizontal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz); 
                            
                        if (orientacao == 1) //se orientacao for igual a 1, é vertical
                            vertical(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz);
                        


                        
                    }while(verificadorUsado == 1);
                }    
            }
            if(dificuldade == 2){
                for (int i = 0; i < quantPalavras; i++){ //repetir todas as palavras

                    verificadorUsado = 0;
                    linhaUsada[i][0] = -5; //inicializando com valores aletorios a linha inicial.
                    colunaUsada[i][0] = -5;//inicializando com valores aletorios a coluna inicial.
                    linhaUsada[i][1] = 1000; //inicializando com valores aletorios a linha final.
                    colunaUsada[i][1] = 1000;//inicializando com valores aletorios a coluna final.
                    
                    do{//enquanto não achar um espaco, nao muda de palavra
                        
                        orientacao = (rand() % 3); //sorteando 0, 1 ou 2 pra orientação
                        printf("\norientacao: %d - %s", orientacao, palavras[i]);

                        if (orientacao == 0) //se orientacao for igual a zero, é horizontal
                            horizontal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz); 
                            
                        if (orientacao == 1) //se orientacao for igual a 1, é vertical
                            vertical(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz);
                        
                        if(orientacao == 2) //se orientacao for igual a 2, é diagonal
                            diagonal(palavras, linha, coluna, n, m, tamanhoPalavras, i, linhaUsada, colunaUsada, matriz);


                        
                    }while(verificadorUsado == 1);
                }

            } 
        }
        


        printf("\n");

        //exibindo a matriz com as palvras
        for (int i = 0; i < n; i++){
            if(i == 0){ 
                printf("    ");
                for (int j = 0; j < m; j++)
                    printf("%d ", (j+1));
                printf("\n");
            }
            i < 9 ? printf("%d  - ", (i+1)) : printf("%d - ", (i+1));
            for (int j = 0; j < m; j++)
                printf("%c ", matriz[i][j]);

            printf("\n");
        }




    return 0;
}
