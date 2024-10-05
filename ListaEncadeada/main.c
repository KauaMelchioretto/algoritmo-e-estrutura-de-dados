#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    struct Elemento *prox;
    int valor;
} Elemento;

typedef struct Lista
{
    Elemento *inicio;
} Lista;

Lista *criar_lista()
{
    Lista *nova = malloc(sizeof(Lista));

    if (nova == NULL)
    {
        return NULL;
    }

    nova->inicio = NULL;
    return nova;
}

Elemento *inserir(Lista *l, int valor)
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

Elemento *insere_posicao(Lista *l, int valor, int posicao)
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
    // Além de dar o free() tem que dar um NULL pois mesmo que dando o free() é acabado puxando outro endereço de memória para esta variável, assim, acaba dando xabu no método de mostrar a lista
    lista = NULL;
    printf("Lista deletada!\n");
    return lista;
}

int main()
{
    Lista *lista = criar_lista();
    inserir(lista, 1);
    inserir(lista, 2);
    insere_posicao(lista, 5, 1);
    printf("Itens de busca por índice:\n");
    printf("%d\n", buscar_por_indice(lista, 1)->valor);
    printf("%d\n", buscar_por_indice(lista, 2)->valor);

    mostrar_lista(lista);

    printf("--- Removendo dado por valor ---\n");
    removerDadoPorValor(lista, 5);
    inserir_inicio(lista, 99);
    inserir_inicio(lista, 88);
    removerDadoPorValor(lista, 10);
    mostrar_lista(lista);
    lista = destruir(lista);
    mostrar_lista(lista);

    return 0;
}
