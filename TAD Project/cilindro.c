#include "cilindro.h"

s_cilindro inicializa_cilindro(float altura, float raio) {
    s_cilindro cilindro;
    float PI = 3.14159265359;

    cilindro.altura = altura;
    cilindro.raio = raio;
    cilindro.volume = PI * (cilindro.raio * cilindro.raio) * cilindro.altura;
    cilindro.area = (2 * PI) * cilindro.raio * (cilindro.raio + cilindro.altura);
    return cilindro;
}

float getVolumeCilindro(s_cilindro cilindro) {
    return cilindro.volume;
}

float getAreaCilindro(s_cilindro cilindro) {
    return cilindro.area;
};
