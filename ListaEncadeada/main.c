#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    struct No* prox;
    int chave;
} No;

typedef struct Lista {
    No* ptlista;
} Lista;

Lista * criar_lista() {
    Lista* nova = malloc(sizeof(Lista));

    if(nova == NULL) {
        return NULL;
    }

    nova->ptlista = NULL;
    return nova;
}


No* inserir(Lista* l, int valor) {
    No* elemento, * aux;

    if(l == NULL) {
        return NULL;
    }

     elemento = malloc(sizeof(No));

    if(elemento == NULL) {
        return NULL;
    }

    elemento->chave = valor;
    elemento->prox = NULL;

    if(l->ptlista == NULL) {
        l->ptlista = elemento;
        return elemento;
    } else {
        aux = l->ptlista;

        while(aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = elemento;
    }

    return elemento;
}

No* insere_no_inicio(Lista* l, int valor) {
    No *elemento, *aux;

    if (l == NULL) {
        return NULL;
    }

    elemento = malloc(sizeof(No));

    if (elemento == NULL) {
        return NULL;
    }
    
    elemento->chave = valor;

    if (l->ptlista != NULL) {
        elemento->prox = l->ptlista;
        l->ptlista = elemento;
        return elemento;
    } else {
        elemento->prox = NULL;
        l->ptlista = elemento;
        return elemento;
    }
}

No* insere_posicao(Lista* l, int valor, int posicao) {
    No *elemento, *auxProx, *auxAtual, *aux;
    int i = 1;

    if (l == NULL) {
        return NULL;
    }

    elemento = malloc(sizeof(No));

    if (elemento == NULL) {
        return NULL;
    }

    elemento->chave = valor;
    aux = l->ptlista;

    if(l->ptlista == NULL) {
        elemento->prox = NULL;
        l->ptlista = elemento;
    } else {
        auxAtual = l->ptlista;

        while(i < posicao && aux->prox != NULL) {
            aux = aux->prox;
            i++;
        }
        elemento->prox = aux->prox;
        aux->prox = elemento;
    }
}

No *buscar_por_indice(Lista *l, int posicao){
    No *aux;
    int count = 0;

    if(l == NULL){
        return NULL;
    }

    aux = l->ptlista;

    while(count != posicao && aux->prox != NULL) {
        aux = aux->prox;
        count++;
    }

    return aux;
}

int main()
{
    Lista* lista = criar_lista();
    inserir(lista, 1);
    inserir(lista, 2);
    insere_posicao(lista, 5, 1);
    printf("%d\n", buscar_por_indice(lista, 1)->chave);
    printf("%d\n", buscar_por_indice(lista, 2)->chave);
    return 0;
}
