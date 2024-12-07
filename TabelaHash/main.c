#include <stdio.h>
#include "tabelahash.h"

int main(void)
{
    Lista* tabelaHash = criarTabelaHash();
    preencherTabelaHash(tabelaHash);

    printf("Tabela Hash:\n");
    inserirTabelaHash(tabelaHash, 321);
    mostrarTabelaHash(tabelaHash);
    printf("Resultado: %d\n", buscarTabelaHash(tabelaHash, 20));
    printf("Resultado: %d\n", buscarTabelaHash(tabelaHash, 240));
}
