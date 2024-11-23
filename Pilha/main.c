#include <stdio.h>
#include "pilha.h"

int main() {
    int valor = 0;
    // Pilha *pilha = criar_pilha();
    // printf("Digite um valor: \n");
    // scanf("%d", &valor);
    // push(pilha, valor);
    //
    // printf("Digite um valor: \n");
    // scanf("%d", &valor);
    // push(pilha, valor);
    //
    // printf("Digite um valor: \n");
    // scanf("%d", &valor);
    // push(pilha, valor);
    //
    // mostrar_pilha(pilha);
    // int removido = pop(pilha);
    // printf("Dado removido: %d\n", removido);
    // mostrar_pilha(pilha);

    // Exercício 4 (calculadora polonesa)
    PilhaReal *pilha_real = criar_pilha_real();
    push_real(pilha_real, 2);
    push_real(pilha_real, 2.50);
    push_real(pilha_real, 3);
    push_real(pilha_real, 1.50);
    push_real(pilha_real, 5);

    Pilha *pilha_operacoes = criar_pilha();
    push_char(pilha_operacoes, '/');
    push_char(pilha_operacoes, '+');
    push_char(pilha_operacoes, '*');
    push_char(pilha_operacoes, '-');

    // Resultado deve ser 6.5, sequência do cálculo (5 - 1.50) * 3 + 2.50 / 2
    float valorCalculo = calcula(pilha_real, pilha_operacoes);
    printf("Resultado: %f\n", valorCalculo);

    Pilha *pilha_carros = criar_pilha();
    push(pilha_carros, 1);
    push(pilha_carros, 2);
    push(pilha_carros, 3);
    push(pilha_carros, 4);
    push(pilha_carros, 5);
    printf("Digite o numero de 1 a 5 para placa de carros\n");
    int placa = 0;
    scanf("%d", &placa);
    procura_carro(pilha_carros, placa);

    return 0;
}
