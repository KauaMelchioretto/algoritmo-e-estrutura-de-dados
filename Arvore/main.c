#include <stdio.h>
#include "arvore.h"

int main(void)
{
    Arvore *arvore = criar_arvore();
    inserir(arvore, 6);
    inserir(arvore, 2);
    inserir(arvore, 7);
    inserir(arvore, 4);
    inserir(arvore, 3);
    inserir(arvore, 5);

    return 0;
}
