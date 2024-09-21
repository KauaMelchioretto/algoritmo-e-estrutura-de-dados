#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED

typedef struct triangulo {
    float a;
    float b;
    float c;
    float perimetro;
    float area;
} s_triangulo;

s_triangulo inicializa_triangulo(float a, float b, float c);
float getAreaTriangulo(s_triangulo triangulo);
float getVolumeTriangulo(s_triangulo triangulo);
float getPerimetroTriangulo(s_triangulo triangulo);
#endif // TRIANGULO_H_INCLUDED
