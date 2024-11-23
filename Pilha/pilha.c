#include "pilha.h"

#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

Pilha* criar_pilha() {
    Pilha *pilha;

    pilha = malloc(sizeof(Pilha));

    if(pilha == NULL) {
        return NULL;
    }

    pilha->topo = NULL;

    return pilha;
}

PilhaReal* criar_pilha_real() {
    PilhaReal *pilha_real;

    pilha_real = malloc(sizeof(PilhaReal));

    if(pilha_real == NULL) {
        return NULL;
    }

    pilha_real->topo = NULL;

    return pilha_real;
}

void push(Pilha *pilha, int valor) {
    Elemento *elemento;

    elemento = malloc(sizeof(Elemento));

    elemento->dado = valor;
    elemento->prox = NULL;

    if(pilha->topo == NULL) {
        pilha->topo = elemento;
    } else {
        elemento->prox = pilha->topo;
        pilha->topo = elemento;
    }
}

void push_char(Pilha *pilha, char operacao) {
    Elemento *elemento;

    elemento = malloc(sizeof(Elemento));

    elemento->dado = (int)operacao;
    elemento->prox = pilha->topo;
    pilha->topo = elemento;
}

void push_real(PilhaReal *pilha_real, float dado) {
    ElementoReal *elemento_real;

    elemento_real = malloc(sizeof(ElementoReal));

    elemento_real->dado = dado;
    elemento_real->prox = NULL;

    if(pilha_real->topo == NULL) {
        pilha_real->topo = elemento_real;
    } else {
        elemento_real->prox = pilha_real->topo;
        pilha_real->topo = elemento_real;
    }
}

float pop_real(PilhaReal *pilha_real) {
    float removido = 0;

    if(pilha_real->topo == NULL) {
        printf("Pilha vazia\n");
        return -999;
    }

    ElementoReal *elemento_real = pilha_real->topo;
    pilha_real->topo = elemento_real->prox;
    removido = elemento_real->dado;

    free(elemento_real);
    elemento_real = NULL;

    return removido;
}

int pop(Pilha *pilha) {
    int removido = 0;

    if(pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return -999;
    }

    Elemento *aux = pilha->topo;
    removido = aux->dado;
    pilha->topo = aux->prox;

    free(aux);
    aux = NULL;

    return removido;
}

void mostrar_pilha(Pilha *pilha) {
    if(pilha == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    Elemento *aux;
    aux = pilha->topo;

    while (aux != NULL) {
        printf("Dado: %d\n", aux->dado);
        aux = aux->prox;
    }
}

void converte_pra_binario(int valor) {
    Pilha *pilhaBinario = criar_pilha();

    Elemento *aux = malloc(sizeof(Elemento));

    while(valor > 0) {
        push(pilhaBinario, valor % 2);
        valor = valor / 2;
    }
}

float calcula(PilhaReal *valores, Pilha *operacoes) {
    if(valores == NULL || operacoes == NULL) {
        return;
    }

    int operacao = 0;
    float valor1 = 0, valor2 = 0;
    float resultado = 0;

    while(operacoes->topo != NULL) {
        valor1 = pop_real(valores);
        valor2 = pop_real(valores);
        operacao = pop(operacoes);

        switch((char)operacao) {
            case '+' :
                resultado = valor1 + valor2;
                push_real(valores, resultado);
            break;

            case '-' :
                resultado = valor1 - valor2;
                push_real(valores, resultado);
            break;

            case '/' :
                resultado = valor1 / valor2;
                push_real(valores, resultado);
            break;

            case '*' :
                resultado = valor1 * valor2;
                push_real(valores, resultado);
            break;
        }
    }

    return resultado;
}
