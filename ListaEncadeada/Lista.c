#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista *criar_lista() {
    Lista *nova = malloc(sizeof(Lista));

    if (nova == NULL)
    {
        return NULL;
    }

    nova->inicio = NULL;
    return nova;
}

Elemento *inserir(Lista *l, int valor) {
    Elemento *elemento, *aux;

    if (l == NULL)
    {
        return NULL;
    }

    elemento = malloc(sizeof(Elemento));

    if (elemento == NULL)
    {
        return NULL;
    }

    elemento->valor = valor;
    elemento->prox = NULL;

    if (l->inicio == NULL)
    {
        l->inicio = elemento;
        return elemento;
    }
    else
    {
        aux = l->inicio;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = elemento;
    }

    return elemento;
}

Elemento *inserir_inicio(Lista *l, int valor)
{
    Elemento *elemento, *aux;

    if (l == NULL)
    {
        return NULL;
    }

    elemento = malloc(sizeof(Elemento));

    if (elemento == NULL)
    {
        return NULL;
    }

    elemento->valor = valor;

    if (l->inicio != NULL)
    {
        elemento->prox = l->inicio;
        l->inicio = elemento;
        return elemento;
    }
    else
    {
        elemento->prox = NULL;
        l->inicio = elemento;
        return elemento;
    }
}

Elemento *inserir_posicao(Lista *l, int valor, int posicao)
{
    Elemento *elemento, *auxProx, *auxAtual, *aux;
    int i = 1;

    if (l == NULL)
    {
        return NULL;
    }

    elemento = malloc(sizeof(Elemento));

    if (elemento == NULL)
    {
        return NULL;
    }

    elemento->valor = valor;
    aux = l->inicio;

    if (l->inicio == NULL)
    {
        elemento->prox = NULL;
        l->inicio = elemento;
    }
    else
    {
        auxAtual = l->inicio;

        while (i < posicao && aux->prox != NULL)
        {
            aux = aux->prox;
            i++;
        }

        elemento->prox = aux->prox;
        aux->prox = elemento;
    }
    
    return elemento;  // Adicionado o retorno aqui
}

Elemento *buscar_por_indice(Lista *l, int posicao)
{
    Elemento *aux;
    int count = 0;

    if (l == NULL)
    {
        return NULL;
    }

    aux = l->inicio;

    while (count != posicao && aux->prox != NULL)
    {
        aux = aux->prox;
        count++;
    }

    return aux;
}

void mostrar_lista(Lista *lista)
{
    Elemento *aux;

    if (lista == NULL)
    {
        printf("A lista está vazia!\n");
        return;
    }

    aux = lista->inicio;

    printf("--- Mostrando Lista ---\n");
    while (aux != NULL)
    {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }
}

void removerDadoPorValor(Lista *lista, int valor)
{
    Elemento *auxProximo, *auxAnterior;

    if (lista == NULL)
    {
        return;
    }

    auxProximo = lista->inicio;

    while (auxProximo->valor != valor)
    {
        auxAnterior = auxProximo;
        auxProximo = auxProximo->prox;

        if (auxProximo == NULL)
        {
            printf("O valor '%d' não existe na lista!\n", valor);
            return;
        }
    }

    auxAnterior->prox = auxProximo->prox;
    printf("Valor '%d' removido\n", auxProximo->valor);
    free(auxProximo);
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

Elemento* busca_maior_elemento(Lista* lista) {
    int maiorValor = 0;
    Elemento *aux, *maiorElemento;
    
    if(lista == NULL) {
        return NULL;
    }
    
    aux = lista->inicio;
    maiorElemento = aux;
    
    while(aux != NULL) {
        if(aux->valor > maiorValor) {
            maiorValor = aux->valor;
            maiorElemento = aux;    
        }
        
        aux = aux->prox;
    }
    
    return maiorElemento;
}

Elemento* busca_menor_elemento(Lista *lista) {
    int menorValor = lista->inicio->valor;
    Elemento *aux, *menorElemento;
    
    if(lista == NULL) {
        return NULL;
    }
    
    aux = lista->inicio;
    menorElemento = aux;
    
    while(aux != NULL) {
        if(aux->valor < menorValor) {
            menorValor = aux->valor;
            menorElemento = aux;
        }
        
        aux = aux->prox;
    }
    
    return menorElemento;
}

int soma_valores(Lista *lista) {
    int soma = 0;
    Elemento *aux;
    
    if(lista == NULL) {
        return 0;  // Corrigido para retornar 0
    }
    
    aux = lista->inicio;
    
    while(aux != NULL) {
        soma += aux->valor;
        aux = aux->prox;
    }
    
    return soma;
}

double media_valores(Lista *lista) {
    int count = 0, soma = 0;
    double media = 0.0;
    Elemento *aux;
    
    if(lista == NULL) {
        return -1.0;    
    }
    
    aux = lista->inicio;
    
    while(aux != NULL) {
        count++;
        soma += aux->valor;
        aux = aux->prox;
    }
    
    return (double)soma / count;
}

int count_acima_da_media(Lista *lista) {
    int count_acima_da_media;
    double media = media_valores(lista);
    Elemento *aux;
    
    if(lista == NULL) {
        return NULL;
    }
    
    aux = lista->inicio;
    
    while(aux != NULL) {
        if(aux->valor > media) {
            count_acima_da_media++;
        }
        
        aux = aux->prox;
    }
    
    return count_acima_da_media;
}