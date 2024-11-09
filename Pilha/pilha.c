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

    return  pilha;
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

int pop(Pilha *pilha) {
    int removido = 0;

    if(pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return -1;
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

