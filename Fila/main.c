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
    Elemento *elemento, *aux;
    
    if(fila == NULL) {
        return;
    }
    
    elemento = malloc(sizeof(Elemento));
    elemento->dado = dado;
    elemento->prox = NULL;
    
    if(fila->inicio == NULL) {
        fila->inicio = elemento;
    } else {
        aux = fila->fim;
        aux->prox = elemento;
        //fila->fim->prox = elemento; Isso aqui é bom por ser curto porém é mais difícil de entender
    }
    
    fila->fim = elemento;
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

int remover(Fila* fila) {
    Elemento *aux;
    int retorno = 0;
    
    if(fila == NULL) {
        return 0;
    }
    
    if(fila->inicio == NULL) {
        return 0;    
    }
    
    aux = fila->inicio;
    fila->inicio = aux->prox;
    retorno = aux->dado;
    
    free(aux);
    
    if(fila->inicio == NULL) {
        fila->fim = NULL;  
    }
    
    aux = NULL;
    
    return retorno;
}

int tamanho(Fila *fila) {
    Elemento *aux;
    int cont = 0;
    
    if(fila == NULL) {
        return -1;
    }
    
    if(fila->inicio == NULL) {
        return 0;
    }
    
    aux = fila->inicio;
    cont++;
    
    while(aux->prox != NULL) {
        aux = aux->prox;
        cont++;
    }
    
    return cont;
}

int destruir(Fila *fila) {
    
}

int main() {
    Fila *fila;
    int elementoRemovido;
    
    printf("cria fila...\n");
    fila = cria_fila();
    printf("Fila criada...\n");
    inserir(fila, 1);
    inserir(fila, 2);
    inserir(fila, 3);
    inserir(fila, 4);
    inserir(fila, 5);
    mostrar_fila(fila);
    
    elementoRemovido = remover(fila);
    printf("Elemento removido: %d\n", elementoRemovido);
 
    elementoRemovido = remover(fila);
    printf("Elemento removido: %d\n", elementoRemovido);

    printf("\nLista após remover:\n");
    mostrar_fila(fila);
    
    int tamanhoLista = tamanho(fila);
    printf("Tamanho: %d\n", tamanhoLista);
    printf("Hello World");

    return 0;
}