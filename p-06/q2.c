//Gabriel Cezar Rodrigues   21.1.4157

#include <stdio.h>
#include <math.h>

int validaCpf(long long int cpf){
    int cont = 1, digito = 0, verificacao = 0, mult = 10, div  = 10, casas = 1, tira = 0;
    while(cont <= 9){
            digito = (cpf / pow(10, div));
            printf("%d = ", digito);
            if(cont !=1){
                tira = digito + pow(10, cont - 1);
                printf("%d - ", tira);
                digito = digito - tira;
            }
            printf("%d \n", digito);
            verificacao = digito * mult;
            verificacao = (verificacao * 10) % 11;
            cont++;
            div--;
            
    }
    return cont;

}

int main(){
    long long int cpf;
    printf("Digite o numero termos.");
    scanf("%lld", &cpf);
    int a = validaCpf(cpf);
    return 0;
}