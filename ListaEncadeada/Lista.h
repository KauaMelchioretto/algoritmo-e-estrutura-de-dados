#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

// Isso aqui não está sendo utilizado más será útil nas implementações

typedef struct No {
    struct No* prox;
    int chave;
} No;

typedef struct Lista {
    No* ptlista;
} Lista;

// cria uma lista com tamanho definido
Lista* criar_lista();
// destroi a lista
void destruir_lista(Lista* l);
// retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista* l);
// busca um dado pela chave x. retorna NULL em caso de falha
No* buscar(Lista* l, int x);
// busca um dado pela chave x. retorna NULL em caso de falha, retorna ant contendo ponteiro anterior
No* buscar_enc(Lista* li, int x, No** ant);
// insere um dado pela (chave x). retorna NULL em caso de falha
No* inserir(Lista* l, int valor);
// remove dado da lista
void remover(Lista* l, int valor);
// retorna o primeiro da lista
No* primeiro(Lista* l);
// retorna o ultimo da lista
No* ultimo(Lista* l);
// retorna um elemento pela posicao
No* buscar_por_indice(Lista* l, int i);

#endif // LISTA_H_INCLUDED
