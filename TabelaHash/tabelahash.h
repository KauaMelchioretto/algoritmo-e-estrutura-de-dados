#ifndef TABELAHASH_H
#define TABELAHASH_H

typedef struct Elemento{
    int valor;
    struct Elemento* prox;
} Elemento;

typedef struct Lista{
    Elemento* inicio;
} Lista;

// cria uma lista com tamanho definido
Lista* criar_lista();

// busca valor na lista
int buscarLista(Lista *lista, int valor);

// busca valor na tabela hash
int buscarTabelaHash(Lista* tabelaHash, int valor);

// insere um dado pela (chave x) na lista. retorna NULL em caso de falha
Elemento* inserirLista(Lista* l, int x);

// mostra a lista
void mostrar_lista(Lista *lista);

// calcula hash da tabela
int hash(int chave);

// aloca/cria a tabela hash
Lista* criarTabelaHash();

// insere valor na tabela hash utilizando junto a função de inserirLista
Elemento* inserirTabelaHash(Lista* tabelaHash, int valor);

// printa a tabela hash
void mostrarTabelaHash(Lista* l);

// popula a tabela hash com valores para facilitar os testes
void preencherTabelaHash(Lista* tabelaHash);

#endif //TABELAHASH_H
