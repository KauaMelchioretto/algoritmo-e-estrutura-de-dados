#include <stdio.h>
#include "lista.h"

int main() {
    Lista *lista = criar_lista();
    preencherListaDecrescente(lista, 100);
    mostrar_lista(lista);

    return 0;
}