#ifndef ARVORE_H
#define ARVORE_H

typedef struct No {
    int valor;
    struct No *direita;
    struct No *esquerda;
} No;

typedef struct Arvore {
    struct No* raiz;
} Arvore;

Arvore* criar_arvore();
No* inserir(Arvore *a, int v);

#endif //ARVORE_H
