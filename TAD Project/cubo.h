#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

typedef struct Cubo {
    float aresta;
    float area;
    float volume;
} s_cubo;

s_cubo inicializa_cubo(float lado);
float getAresta(s_cubo cubo);
float getAreaCubo(s_cubo cubo);
float getVolumeCubo(s_cubo cubo);

#endif // CUBO_H_INCLUDED
