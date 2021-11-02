//Gabriel Cezar Rodrigues   21.1.4157

#include <stdio.h>

int parOuImpar(int x, int y);

int main(){
    int x, y;
    int verificador = 0;
    int espacos , contadorEspacos, contadorAsteriscos, contadorLinhas;

    //repeticao para verificar se os valores digitados sao validos
    do{
        printf("Digite os valores de x e y: ");
        scanf("%d %d", &x, &y);

        //verificando se os valores sao pares
        if(parOuImpar(x, y) == 1){
            printf("Apenas numeros pares sao aceitos");
            verificador = 0; //verificador se o valor eh valido

        }else if (x >= y){ //verificando se o x eh maior o igual a y
            printf("X deve ser menor que Y");
            verificador = 0; //verificador se o valor eh valido

        }else{ //criando o trapezio
            espacos = (y - x) /2; // calculo dos espacos antes dos asteriscos
            contadorLinhas = espacos; //percebi que as linhas sao a mesma quantidade de espacos
            
            //repeticao para as linhas
            do{
                //repeticao para os espacos antes do asterisco
                contadorEspacos = 0;
                do{
                    printf(" ");
                    contadorEspacos++;
                }while(contadorEspacos <= espacos);
                espacos--;

                //repeticao para os asteriscos
                contadorAsteriscos  = 0;
                do{
                    printf("*");
                    contadorAsteriscos ++;
                }while(contadorAsteriscos<x);
                x+=2;

                //imprimindo a linha e diminuindo o contador
                contadorLinhas--;
                printf("\n");

            }while(contadorLinhas>=0);

        verificador = 1; //verificador se o valor eh valido
        }
    }while(verificador  == 0);
}

//funcao para conferir se o valor eh par ou impar
int parOuImpar(int x, int y){
    if(x % 2 == 0 && y % 2 == 0)
        return 0;
    else
        return 1;
}