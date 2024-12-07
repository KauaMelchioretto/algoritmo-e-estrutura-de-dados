#include <stdio.h>
#include "arvore.h"

#include <stdlib.h>

Arvore* criar_arvore() {
    Arvore *arvore = malloc(sizeof(Arvore));

    if(arvore == NULL)
        return NULL;

    arvore->raiz = NULL;
    return arvore;
}

No* inserir(Arvore *arvore, int valor) {
    if(arvore == NULL) {
        return NULL;
    }

    No *raiz = arvore->raiz;
    No *no = malloc(sizeof(No));
    no->direita = NULL;
    no->esquerda = NULL;
    no->valor = valor;

    if(raiz == NULL) {
        arvore->raiz = no;
    } else {
        while(raiz != NULL) {
            while(valor < raiz->valor) {
                if(raiz->esquerda == NULL) {
                    raiz->esquerda = no;
                    return no;
                }
                raiz = raiz->esquerda;
            }

            while(valor > raiz->valor) {
                if(raiz->direita == NULL) {
                    raiz->direita = no;
                    return no;
                }

                raiz = raiz->direita;
            }
        }
    }
}
