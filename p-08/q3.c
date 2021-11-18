//Gabriel cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>
#include <string.h>

//funcao que conta quantas letras tem na string tirando os espacos
int contadorLetras(char *nome, int tamanho, int remove){
    int contador = 0;
    for (int i = 0; i < tamanho - remove; i++){
        if(nome[i] != ' ')
            contador++;
    }
    return contador;
}

int main(){
    char nome[72];
    printf("Digite o nome completo: ");
    fgets(nome, 70, stdin);
    
    int tamanho = strlen(nome);
    nome[tamanho-1] = '\0';

    //tirando o ultimo nome
    int ultimo = 0;
    for(int i = tamanho -2; i > 0; i--){
        if(nome[i] != ' ')
            ultimo++;
        else
            i = 0;
    }
    //criando um string para armazenar o ultimo nome
    char ultimoNome[ultimo+1];
    ultimoNome[ultimo] = '\0';

    //armazenando a ultima posicao do stirng nome antes do ultimo nome
    int primeiros = (tamanho - 2) - ultimo;

    //salvando o ultimo nome na string
    for (int i = 0; i < primeiros; i++){
        ultimoNome[i] = nome[primeiros + 1 + i];
    }

    //salvando os  primeiros nomes em um vetor separado
    char primeirosNomes[primeiros+1];
    primeirosNomes[primeiros] = '\0';
    for (int i = 0; i < primeiros; i++)
    {
        primeirosNomes[i] = nome[i];
    }

    //imprimindo resultados
    printf("\n\n%s, %s\n", ultimoNome, primeirosNomes);
    printf("Total de letras: %d\n", contadorLetras(nome, tamanho, 1));
    printf("Total de letras do ultimo sobrenome: %d\n", contadorLetras(ultimoNome, strlen(ultimoNome), 0));


    return 0;
}