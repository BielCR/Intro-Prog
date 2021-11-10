//Gabriel cezar Rodrigues 21.1.4157

#include <stdio.h>

int main(){
    float prova1 [15], prova2[15];
    int i;
    for(i = 0; i < 15; i++){
        printf("Digite repectivamente o valor da prova 1 e 2 do aluno %d:\n", i+1);
        scanf("%f %f", &prova1[i], &prova2[i]);
    }
    for(i = 0; i < 15; i++){
        float media = (prova1[i] + prova2[i]) / 2;
        if(media >= 60.0) printf("Aluno %d aprovado, media: %.2f\n", i+1, media);
        else printf("Aluno %d reprovado, media: %.2f\n", i+1, media);
    }
}