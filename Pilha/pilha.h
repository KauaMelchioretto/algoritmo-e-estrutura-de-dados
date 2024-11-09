#ifndef PILHA_H
#define PILHA_H

typedef struct Elemento{
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct Pilha{
    Elemento* topo;
}Pilha;

// cria uma pilha com tamanho definido
Pilha* criar_pilha();

// destroi a pilha
void destruir_pilha(Pilha* p);

// insere no topo da pilha
void push(Pilha* p, int x);

// remove do topo da pilha
int pop(Pilha* p);

// retorna o tamanho da pilha (numero de elementos inseridos)
int tamanho(Pilha* p);

void mostrar_pilha(Pilha *p);

#endif //PILHA_H