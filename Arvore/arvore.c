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

int buscar_no_arvore(Arvore *arvore, int valor) {
    if(arvore == NULL || arvore->raiz == NULL) {
        printf("Arvore vazia ou nao alocada\n");
        return NULL;
    }

    No *no = arvore->raiz;

    while(no != NULL) {
        while(valor < no->valor && no->esquerda != NULL) {
            no = no->esquerda;
        }

        while(valor > no->valor && no->direita != NULL) {
            no = no->direita;
        }

        if(valor == no->valor) {
            return no->valor;
        } else {
            printf("Valor nao encontrado na arvore\n");
            return 999;
        }
    }
}

void imprimir_simetrica(No *no) {
    if(no == NULL) {
        return;
    }

    imprimir_simetrica(no->esquerda);
    printf("%d\n", no->valor);
    imprimir_simetrica(no->direita);
}

No* remover_raiz(No *raiz) {
    No *pai = NULL;
    No *nova_raiz = NULL;

    if(raiz->esquerda == NULL) {
        nova_raiz = raiz->direita;
        free(raiz);
        raiz = NULL;
        return nova_raiz;
    }

    pai = raiz;
    nova_raiz = raiz->esquerda;

    while(nova_raiz->direita != NULL) {
        pai = nova_raiz;
        nova_raiz = nova_raiz->direita;
    }

    if(pai != raiz) {
        pai->direita = nova_raiz->esquerda;
        nova_raiz->esquerda = raiz->esquerda;
    }

    nova_raiz->direita = raiz->direita;
    free(raiz);
    raiz = NULL;
    return nova_raiz;
}

No* remover_no(No *no, int valor) {
    if(no != NULL) {
        if(valor < no->valor) {
            no->esquerda = remover_no(no->esquerda, valor);
        } else {
            if(valor > no->valor) {
                no->direita = remover_no(no->direita, valor);
            } else {
                no = remover_raiz(no);
            }
        }
    }

    return no;
}