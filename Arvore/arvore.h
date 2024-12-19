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
int buscar_no_arvore(Arvore *a, int v);
void imprimir_simetrica(No *no);
No* remover_no(No *no, int v);
No* remover_raiz(No *no);

#endif //ARVORE_H
