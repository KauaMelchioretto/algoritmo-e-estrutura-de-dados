#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

typedef struct Cilindro {
    float altura;
    float raio;
    float volume;
    float area;
} s_cilindro;

s_cilindro inicializa_cilindro(float altura, float raio);
float getAreaCilindro(s_cilindro cilindro);
float getVolumeCilindro(s_cilindro cilindro);

#endif // CILINDRO_H_INCLUDED
