#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct Fila {
    Elemento* inicio;
    Elemento* fim;
} Fila;

Fila* cria_fila() {
    Fila *fila = malloc(sizeof(Fila));
    
    if(fila == NULL) {
        return NULL;
    }
    
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void inserir(Fila* fila, int dado) {
    Elemento *elemento;
    
    if(fila == NULL) {
        return;
    }
    
    elemento = malloc(sizeof(Elemento));
    elemento->dado = dado;
    elemento->prox = NULL;
    
    if(fila->inicio == NULL) {
        fila->inicio = elemento;
        fila->fim = elemento;
    } else {
        fila->fim->prox = elemento;
        fila->fim = elemento;
    }
}

void mostrar_fila(Fila* fila) {
    Elemento *aux;
    
    if(fila == NULL) {
        return;
    }
    
    aux = fila->inicio;
    
    while(aux != NULL) {
        printf("Dado: %d\n", aux->dado);
        aux = aux->prox;
    }
}

void remover(Fila* fila) {
 //implementar   
}

int main() {
    Fila *fila;
    printf("cria fila...\n");
    fila = cria_fila();
    printf("Fila criada...\n");
    inserir(fila, 1);
    inserir(fila, 2);
    inserir(fila, 3);
    inserir(fila, 4);
    inserir(fila, 5);
    mostrar_fila(fila);
    printf("Hello World");

    return 0;
}