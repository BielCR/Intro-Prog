//Gabriel Cezar Rodrigues 21.1.4157 turma 41

#include <stdio.h>
#include <math.h>

//declarando funcoes
double calculoDist(double [], double []);
double lePontoX(int);
double lePontoY(int);

//criando as funcoes de fato

//lendo o x da coordenada
double lePontoX(int cont){
    double retorno;
    printf("Insira o valor de x para o ponto %d: ", cont);
    scanf("%lf", &retorno);
    return retorno;
}

//lendo o y da coordenada
double lePontoY(int cont){
    double retorno;
    printf("Insira o valor de y para o ponto %d: ", cont);
    scanf("%lf", &retorno);
    return retorno;
}

//calculando a distancia
double calculoDist(double p1[], double p2[]){
    double distancia = sqrt(pow((p2[0]-p1[0]),2)+pow((p2[1]-p1[1]),2));
    return distancia;
}

void main(){
    //declarando os arrays
    double p1[2] = {0,0}, p2[2] = {0,0};
    
    //Declarando variavel de controle da interação com usuário
    int contador = 1;

    //funcoes de leitura dos valores 
    p1[0] = lePontoX(contador);
    p1[1] = lePontoY(contador);
    contador++;
    p2[0] = lePontoX(contador);
    p2[1] = lePontoY(contador);

    //calculando a distancia
    double resultado = calculoDist(p1, p2);
    printf("%lf", resultado);


}