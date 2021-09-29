#include <stdio.h>

int main(){
    float a, b, c, d, e;
    float result;
    printf("Usuario, fazor informar os valores de a, b, c, d, e:\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);
    scanf("%f", &e);
    result = (a * a * a) * ((b + c) / d + e);
    printf("a = %.0f, b = %.0f c = %.0f, d = %.0f, e = %.0f\n", a, b, c, d, e);
    printf("x = %.0f", result);
    return 0;
}