#include "tabelahash.h"

#include "tabelahash.h"
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 11

Lista *criar_lista() {
    Lista *nova = malloc(sizeof(Lista));

    if (nova == NULL) {
        return NULL;
    }

    nova->inicio = NULL;
    return nova;
}

int hash(int chave) {
    return chave % TAMANHO_TABELA;
}

Lista* criarTabelaHash() {
    Lista* tabelaHash = malloc(TAMANHO_TABELA * sizeof(Lista));

    if(tabelaHash == NULL) {
        printf("Erro ao criar tabela hash\n");
    }

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabelaHash[i].inicio = NULL;
    }

    return tabelaHash;
}

Elemento *inserirLista(Lista *l, int valor) {
    Elemento *elemento, *aux;

    if (l == NULL) {
        return NULL;
    }

    elemento = malloc(sizeof(Elemento));

    if (elemento == NULL) {
        return NULL;
    }

    elemento->valor = valor;
    elemento->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = elemento;
        return elemento;
    } else {
        aux = l->inicio;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = elemento;
    }

    return elemento;
}

void preencherTabelaHash(Lista *tabelaHash) {
    int valores[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                     11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    int n = sizeof(valores) / sizeof(valores[0]);
    for(int i = 0; i < n; i++) {
        inserirTabelaHash(tabelaHash, valores[i]);
    }
}

int buscarLista(Lista *lista, int valor) {
    if(lista == NULL || lista->inicio == NULL) {
        printf("Lista nula ou vazia\n");
        return NULL;
    }

    Elemento *aux = lista->inicio;

    while(aux != NULL) {
        if(aux->valor == valor) {
            return valor;
        }
        aux = aux->prox;
    }

    printf("Valor nao encontrado\n");
    return NULL;
}

int buscarTabelaHash(Lista* tabelaHash, int valor) {
   if(tabelaHash == NULL) {
       printf("Tabela hash nao esta iniciada\n");
       return NULL;
   }

    int key = hash(valor);

    printf("**** Buscando valor %d no indice %d da tabela hash ****\n", valor, key);
    return buscarLista(&tabelaHash[key], valor);
}

Elemento* inserirTabelaHash(Lista* tabelaHash, int valor) {
    if(tabelaHash == NULL) {
        printf("Tabela hash nao incializada\n");
        return NULL;
    }

    int index = hash(valor);
    return inserirLista(&tabelaHash[index], valor);
}

void mostrarTabelaHash(Lista* tabelaHash) {
    if(tabelaHash == NULL) {
        printf("Tabela hash nao inicializada\n");
        return;
    }

    for(int i = 0; i < TAMANHO_TABELA; i++) {
        printf("indice %d: ", i);
        mostrar_lista(&tabelaHash[i]);
        printf("\n");
    }
}

void mostrar_lista(Lista *lista) {
    Elemento *aux;

    if (lista == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    aux = lista->inicio;

    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}
