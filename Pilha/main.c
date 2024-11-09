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

    return 0;
}
