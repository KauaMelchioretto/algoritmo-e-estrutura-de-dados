#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Elemento{
    int valor;
    struct Elemento* prox;
} Elemento;

typedef struct Lista{
    Elemento* inicio;
} Lista;

// cria uma lista com tamanho definido
Lista* criar_lista();

// destroi a lista
void destruir_lista(Lista* l);

// insere um dado pela (chave x) na lista. retorna NULL em caso de falha
Elemento* inserir(Lista* l, int x);

void preencherListaCrescente(Lista *l, int n);
void mostrar_lista(Lista *lista);
void preencherListaDecrescente(Lista *l, int n);
void preencherListaAleatoria(Lista *l, int n);
Lista* bubbleSort(Lista *l);
Lista* selectionSort(Lista *l);

#endif // LISTA_H_INCLUDED