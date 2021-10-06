//Gabriel Cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>

//Declarando as funcoes
void inicio();
void angulo();
void temp();
double graus(double);
double rad(double);
double celsius(double, int);
double fahrenheit(double, int);
double kelvin(double, int);


//Main
int main() {
    inicio();
    return 0;
}

//funcao que realiza a escolha inicial
void inicio(){
    //Recebendo a opcao de escolha do usuario
    int opcao;
    printf("### CONVERSOR DE UNIDADES ###\n\n1) Angulo\n2) Temperatura\n\nDigite uma opcao:");
    scanf("%d", &opcao);

    //Analisando as possiveis escolhas
    switch(opcao){
        case 1:
            angulo();
            break;
        case 2:
            temp();
            break;
        //caso o valor nao seja os predefinidos
        default:
            printf("A opcao digitada nao existe!");
            break;
    }
}

//Funcao caso o usuario escolha a opcao de converter angulos
void angulo(){
    int opcao;
    printf("\nQual a unidade de origem?\n\n1) Graus\n2) Radianos\n\nSelecione um opcao:");
    scanf("%d", &opcao);
    double valor = 0, resultado = 0;
    switch(opcao){
        case 1:
            printf("\nDigite um valor em Graus: ");
            scanf("%lf", &valor);
            resultado = graus(valor);
            printf("Valor em Radianos: %.6lf", resultado);
            break;
        case 2:
            printf("\nDigite um valor em Radianos: ");
            scanf("%lf", &valor);
            resultado = rad(valor);
            printf("Valor em Graus: %.6lf", resultado);
            break;
        default:
            printf("\nA opcao digitada nao existe!");
            break;

    }

}

//Caso o angulo escolhido for graus
double graus(double valor){
    return valor * (3.14159 / 180);
}

//Caso o angulo escolhido foir rad
double rad(double valor){
    return valor * (180 / 3.14159);
}

//Funcao caso o usuario escolha a opcao de converter temperatura
void temp(){
    //Lendo qual vai ser a unidade fornecida pelo usuario
    int opcao;
    printf("\nQual a unidade de origem?\n\n1) Celsius\n2) Fahrenheit\n3) Kelvin\n\nSelecione um opcao:");
    scanf("%d", &opcao);

    double valor = 0, f = 0, c = 0, k = 0;
    //analisando as alternativas escolhidas
    switch(opcao){
        //caso celsius
        case 1:
            printf("\nDigite um valor em Celsius: ");
            scanf("%lf", &valor);

            //conversao celsius fahrenheit
            f = fahrenheit(valor, opcao);
            printf("\nValor em Fahrenheit: %.2lf", f);

            //conversao celsius kelvin
            k = kelvin(valor, opcao);
            printf("\nValor em Kelvin: %.2lf", k);
            break;

        //caso fahrenheit
        case 2:
            printf("\nDigite um valor em Fahrenheit: ");
            scanf("%lf", &valor);

            ////conversao fahrenheit celsius
            c = celsius(valor, opcao);
            printf("\nValor em Celsius: %.2lf", c);

            //conversao fahrenheit kelvin
            k = kelvin(valor, opcao);
            printf("\nValor em Kelvin: %.2lf", k);
            break;

        //caso kelvin
        case 3:
            printf("\nDigite um valor em Kelvin: ");
            scanf("%lf", &valor);
            c = celsius(valor, opcao);
            printf("\nValor em Celsius: %.2lf", c);
            f = fahrenheit(valor, opcao);
            printf("\nValor em Fahrenheit: %.2lf", f);
            break;

            //caso nao digite uma opcao valida
        default:
            printf("\nA opcao digitada nao existe!");
            break;

    }

}

//conversao para celsius
double celsius(double valor, int opcao){
    //vendo de qual unidade o valor pertence
    switch(opcao){
        //se fahrenheit
        case 2:
            return (valor - 32) * 5/9;
            break;

        //se kelvin
        case 3:
            return  valor - 273.15;
            break;
        default:
            break;
    }
    return 0;
}

//conversao para fahrenheit
double fahrenheit(double valor, int opcao){
    //vendo de qual unidade o valor pertence
    switch(opcao){
        //se celsius
        case 1:
            return (valor * 9/5) + 32;
            break;

        //se kelvin
        case 3:
            return  (valor - 273.15) * 9/5 + 32;
            break;
        default:
            break;
    }
    return 0;
}

//conversao para kelvin
double kelvin(double valor, int opcao){
    //vendo de qual unidade o valor pertence
    switch(opcao){
        //se celsius
        case 1:
            return valor + 273.15;
            break;

        //se fahrenheit
        case 2:
            return  (valor - 32) * 5/9 + 273.15;
            break;
        default:
            break;
    }
    return 0;
}