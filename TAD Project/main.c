#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"
#include "cilindro.h"

int main()
{
    float aresta;

    printf("Digite o valor do lado/aresta do cubo:\n");
    scanf("%f", &aresta);
    s_cubo cubo = inicializa_cubo(aresta);
    printf("Aresta: %f\n", getAresta(cubo));
    printf("Area: %f\n", getAreaCubo(cubo));
    printf("Volume: %f\n", getVolumeCubo(cubo));

    float raio;
    float altura;
    printf("Digite o valor da altura do cilindro\n");
    scanf("%f", &altura);
    printf("Digite o valor do raio do cilindro:\n");
    scanf("%f", &raio);
    s_cilindro cilindro = inicializa_cilindro(altura, raio);
    printf("Area do cilindro: %.2f\n", getAreaCilindro(cilindro));
    printf("Volume do cilindro: %.2f\n", getVolumeCilindro(cilindro));
    system("pause");

    return 0;
}
