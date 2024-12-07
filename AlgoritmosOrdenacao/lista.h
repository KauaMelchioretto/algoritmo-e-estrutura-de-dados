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

// retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista* l);

// busca um dado pela chave x. retorna NULL em caso de falha
Elemento* buscar_por_elemento(Lista* l, int x);

// busca um dado pela posicao pos. retorna NULL em caso de falha
Elemento* buscar_por_posicao(Lista* l, int pos);

// insere um dado pela (chave x) no inicio da lista. retorna NULL em caso de falha
Elemento* inserir_inicio(Lista* l, int x);

// insere um dado pela (chave x) na posicao pos. retorna NULL em caso de falha
Elemento* inserir_posicao(Lista* l, int x, int pos);

// insere um dado pela (chave x) na lista. retorna NULL em caso de falha
Elemento* inserir(Lista* l, int x);

// remove dado da lista
void remover(Lista* l, int x);

// retorna o primeiro da lista
Elemento* primeiro(Lista* l);

// retorna o ultimo da lista
Elemento* ultimo(Lista* l);

// retorna um elemento pela posicao
Elemento* buscar_por_indice(Lista* l, int i);

void preencherListaCrescente(Lista *l, int n);
void mostrar_lista(Lista *lista);
void preencherListaDecrescente(Lista *l, int n);

#endif // LISTA_H_INCLUDED