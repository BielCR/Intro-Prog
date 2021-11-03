//Gabriel Cezar Rodrigues   21.1.4157

#include <stdio.h>
#include <math.h>



int validaCpf(long long int cpf){
    int digito; //variavel para armazenar o digito que esta sendo tratado;
    int multiplicador = 10; // valor para multiplicar os digitos e verificar com o digito final
    int verificador = 0; // variavel que armazena os valores do digito durante a validacao
    long long int cont = 100000000; //variavel contadora e utilizada para separar os digitos do cpf

    long long int primeiros = cpf/100; //variavel auxiliar criada para armazenar os 9 primeiros digitos do cpf

    int primeiroV = cpf/10 - (primeiros * 10);  //pegando o primeiro digito verificador
    int segundoV = cpf - (primeiros * 100) - primeiroV * 10; //pegando o segundo igito verificador

    while(cont > 0 && multiplicador >= 2){ 
        digito = primeiros/cont; //digito recebe o valor do primeiro digito do cpf em diante
        primeiros -= digito*cont; //atualizo o valor da varialvel que armazena os primeiros digitos do cpf
        cont /= 10; //divido o contador por 10 para pegar a proxima casa decimal do cpf

        verificador += digito * multiplicador; //multiplicando o valor da variavel pelo multiplicador e assim chegar no numero do verificador
        multiplicador--; // diminuindo um no verificador para atender a regra
    }
    verificador = (verificador * 10) % 11; //multiplicando os digitos por 10 e pegando o resto da divisao por 11
    //printf("%d  =  %d\n", verificador, primeiroV);


    if(verificador == primeiroV){
        multiplicador = 11; //agora eh necessario multiplicar mais um numero
        cont = 10000000000; //contador e divisor com 10 zeros
        verificador = 0;//resetando o valor de verificador

        while(multiplicador >= 2){
            digito = cpf/cont; //separando do primero digito em diante
            cpf -= digito*cont; //atualizo o valor da varialvel que armazena os digitos do cpf
            cont /= 10; //divido o contador por 10 para pegar a proxima casa decimal do cpf

            verificador += digito * multiplicador; //multiplicando o valor da variavel pelo multiplicador e assim chegar no numero do verificador
            multiplicador--; // diminuindo um no verificador para atender a regra
        }
        verificador = (verificador * 10) % 11; //multiplicando os digitos por 10 e pegando o resto da divisao por 11
        //printf("%d  =  %d\n", verificador, segundoV);
        
        if(verificador == segundoV){
            return 1; //aqui o cpf atende todas as condicoes para se tornar valido
        }
    }
    return 0;
}


int main(){
    long long int cpf;
    printf("Digite o seu cpf: ");
    scanf("%lld", &cpf);
    if(validaCpf(cpf) == 1)
        printf("Seu CPF %lld se encontra validado.", cpf);
    else
        printf("O CPF %lld se encontra invalido.", cpf);
    return 0;
}