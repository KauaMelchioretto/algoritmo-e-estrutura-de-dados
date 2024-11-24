#include <stdio.h>
#include "pilha.h"

int main() {
    int valor = 0;
    Pilha *pilha = criar_pilha();
    printf("Digite um valor: \n");
    scanf("%d", &valor);
    push(pilha, valor);

    printf("Digite um valor: \n");
    scanf("%d", &valor);
    push(pilha, valor);

    printf("Digite um valor: \n");
    scanf("%d", &valor);
    push(pilha, valor);

    mostrar_pilha(pilha);
    int removido = pop(pilha);
    printf("Dado removido: %d\n", removido);
    mostrar_pilha(pilha);

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

    // Exercício 5 (imprime pilha reversa, não é revertido na mesma pilha apenas passado os elementos para outra pilha)
    PilhaReal *pilhaReal = criar_pilha_real();
    push_real(pilhaReal, 2.34);
    push_real(pilhaReal, 3.1413);
    push_real(pilhaReal, 12);
    push_real(pilhaReal, 1.32);
    imprime_pilha_reversa(pilhaReal);

    //Exercício 6 (procura placa de carro na pilha)
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

    //Exercício 7 (valida se 2 pilhas são iguais, ou seja possam os mesmos números nas mesmas posições)

    // Testa se for falso (pilhas diferentes)
    Pilha *pilha1 = criar_pilha();
    push(pilha1, 1);
    push(pilha1, 2);
    push(pilha1, 3);

    Pilha *pilha2 = criar_pilha();
    push(pilha2, 1);
    push(pilha2, 3);
    push(pilha2, 4);

    printf("Testando pilha 1 [1, 2, 3] e pilha 2 [1, 3, 4]...\n");
    valida_pilha_igual(pilha1, pilha2);

    // // Testa se for verdadeiro (pilhas iguais)
    Pilha *pilha3 = criar_pilha();
    push(pilha3, 1);
    push(pilha3, 2);
    push(pilha3, 3);

    Pilha *pilha4 = criar_pilha();
    push(pilha4, 1);
    push(pilha4, 2);
    push(pilha4, 3);

    printf("Testando pilha 3 [1, 2, 3] e pilha 4 [1, 2, 3]...\n");
    valida_pilha_igual(pilha3, pilha4);

    // Exercício 8 (qual pilha é maior)
    Pilha *pilha5 = criar_pilha();
    push(pilha5, 1);
    push(pilha5, 2);
    push(pilha5, 3);
    push(pilha5, 4);

    Pilha *pilha6 = criar_pilha();
    push(pilha6,1);
    push(pilha6,2);
    push(pilha6,3);

    printf("Validando qual pilha eh maior, pilha 1 [1, 2, 3, 4] ou pilha 2 [1, 2, 3]...\n");
    pilha_maior(pilha5, pilha6);

    printf("Validando qual pilha eh maior, pilha 1 [1, 2, 3] ou pilha 2 [1, 2, 3, 4]...\n");
    pilha_maior(pilha6, pilha5);

    //Exercício 9 (inverte pilha utilizando o mesmo objeto da pilha passada por parâmetro)
    printf("Invertendo a pilha [1, 2, 3, 4]...\n");
    inverte_pilha(pilha5);

    return 0;
}
