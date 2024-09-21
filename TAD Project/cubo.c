#include "cubo.h"

s_cubo inicializa_cubo(float lado) {
    s_cubo cubo;
    cubo.aresta = lado;
    cubo.volume = cubo.aresta * cubo.aresta * cubo.aresta;
    cubo.area = 6 * (cubo.aresta * cubo.aresta);
    return cubo;
};

float getAresta(s_cubo cubo) {
    return cubo.aresta;
}

float getVolumeCubo(s_cubo cubo) {
    return cubo.volume;
}

float getAreaCubo(s_cubo cubo) {
    return cubo.area;
}
