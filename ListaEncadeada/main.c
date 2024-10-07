/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "Lista.h"

int main() {
    Lista *lista = criar_lista();
    inserir(lista, 4);
    inserir(lista, 2);
    inserir_posicao(lista, 5, 1);
    printf("Itens de busca por índice:\n");
    printf("%d\n", buscar_por_indice(lista, 1)->valor);
    printf("%d\n", buscar_por_indice(lista, 2)->valor);

    mostrar_lista(lista);

    printf("--- Removendo dado por valor ---\n");
    removerDadoPorValor(lista, 5);
    inserir_inicio(lista, 23);
    inserir_inicio(lista, 1);
    inserir(lista, 15);
    removerDadoPorValor(lista, 10);
    mostrar_lista(lista);
    // lista = destruir(lista);
    mostrar_lista(lista);
    
    Elemento *maiorElemento = busca_maior_elemento(lista);
    Elemento *menorElemento = busca_menor_elemento(lista);
    printf("Maior valor da lista: %d\n", maiorElemento->valor);
    printf("Menor valor da lista: %d\n", menorElemento->valor);
    
    int soma = soma_valores(lista);
    printf("Soma dos valores da lista: %d\n", soma);
    double media = media_valores(lista);
    printf("Média dos valores: %.2lf\n", media);
    int acima_media = count_acima_da_media(lista);
    printf("Há '%d' valores acima da média\n", acima_media);
    return 0;
}
