#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista *criar_lista() {
    Lista *nova = malloc(sizeof(Lista));

    if (nova == NULL) {
        return NULL;
    }

    nova->inicio = NULL;
    return nova;
}

void preencherListaCrescente(Lista *l, int n) {
    if (l == NULL) {
        return;
    }

    for(int i = 0; i < n; i++) {
        Elemento *elemento, *aux;

        elemento = malloc(sizeof(Elemento));

        elemento->valor = i;
        elemento->prox = NULL;

        if (l->inicio == NULL) {
            l->inicio = elemento;
        } else {
            aux = l->inicio;

            while (aux->prox != NULL) {
                aux = aux->prox;
            }

            aux->prox = elemento;
        }
    }
}

void preencherListaDecrescente(Lista *l, int n) {
    if (l == NULL) {
        return;
    }

    for(int i = n; i > 0; i--) {
        Elemento *elemento, *aux;

        elemento = malloc(sizeof(Elemento));

        elemento->valor = i;
        elemento->prox = NULL;

        if (l->inicio == NULL) {
            l->inicio = elemento;
        } else {
            aux = l->inicio;

            while (aux->prox != NULL) {
                aux = aux->prox;
            }

            aux->prox = elemento;
        }
    }
}

void mostrar_lista(Lista *lista) {
    Elemento *aux;

    if (lista == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    aux = lista->inicio;

    printf("--- Mostrando Lista ---\n");
    while (aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }
}

Lista* destruir(Lista *lista) {
    Elemento *auxAnterior, *auxProximo;

    if (lista == NULL) {
        printf("A lista já foi deletada!\n");
    }

    auxProximo = lista->inicio;

    while(auxProximo != NULL) {
        auxAnterior = auxProximo;
        auxProximo = auxProximo->prox;
        free(auxAnterior);
    }

    free(lista);
    lista = NULL;
    printf("Lista deletada!\n");
    return lista;
}