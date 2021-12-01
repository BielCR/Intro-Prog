//Gabriel cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>
#include <math.h>
#define i = sqrt(-1)

typedef struct
{
    double real;
    double imaginario;
} Complexo;

// funcao que retorna x + y
Complexo somaComplexo(Complexo x, Complexo y){
    Complexo result;
    result.imaginario = x.imaginario + y.imaginario;
    result.real = x.real + y.real;

    return result;
}

// funcao que retorna x - y
Complexo subComplexo(Complexo x, Complexo y){
    Complexo result;
    result.imaginario = x.imaginario - y.imaginario;
    result.real = x.real - y.real;

    return result;
}

// funcao que retorna x * y
Complexo multComplexo(Complexo x, Complexo y){
    Complexo result;
    result.imaginario = x.real * y.imaginario + x.imaginario * y.real;
    result.real = x.real * y.real - x.imaginario * y.imaginario;

    return result;
}

void imprime(Complexo final){
    printf("Resultado = %.2lf", (final.real + final.imaginario * i));
}

int main()
{
    int a, b, c, d;
    char operador;
    Complexo x, y;

    printf("Calculadora de numeros complexos!\n\n");
    printf("Digite os valores de a e b (x = a + bi): ");
    scanf("%d %d", &x.real, &x.imaginario);
    printf("Digite os valores de c e d (y = c + di): ");
    scanf("%d %d", &y.real, &y.imaginario);
    printf("Digite a operacao (+, - ou *): ");
    scanf("%c", &operador);

    switch (operador)
    {
    case '+':
        imprime(somaComplexo(x, y));
        break;
    case '-':
        imprime(subComplexo(x, y));
        break;
    case '*':
        imprime(multComplexo(x, y));
        break;
    
    default:
        printf("\nErro! Operador invalido.");
        break;
    }

    return 0;
}