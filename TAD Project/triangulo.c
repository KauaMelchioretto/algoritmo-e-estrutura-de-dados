#include "triangulo.h"

s_triangulo inicializa_triangulo(float a, float b, float c) {
    if(ehTrianguloValido(a, b, c) == 0) {
       printf("O tri�ngulo n�o � v�lido\n");
       return 0;
    } eles {
        s_triangulo triangulo;
        triangulo.a = a;
        triangulo.b = b;
        triangulo.c = c;
        //triangulo.perimetro = a+b+c;
        //triangulo.area = a *
    }
}

int ehTrianguloValido(float a, float b, float c) {
    if (a + b > c) && (a + c > b) && (b + c > a)
        return 1;
    else
        return 0;
}

