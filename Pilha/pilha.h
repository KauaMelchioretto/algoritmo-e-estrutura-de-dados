#ifndef PILHA_H
#define PILHA_H

typedef struct Elemento{
    int dado;
    struct Elemento* prox;
} Elemento;

typedef struct ElementoReal {
    float dado;
    struct ElementoReal* prox;
} ElementoReal;

typedef struct Pilha {
    Elemento* topo;
} Pilha;

typedef struct PilhaReal {
    ElementoReal* topo;
} PilhaReal;

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

// Implementações de exercícios
void mostrar_pilha(Pilha *p);
void converte_pra_binario(int x);

void push_char(Pilha *p, char operacao);
void push_real(PilhaReal *pilha_real, float dado);
float pop_real(PilhaReal *pilha_real);
PilhaReal* criar_pilha_real();
float calcula(PilhaReal *valores, Pilha *operacoes);
void procura_carro(Pilha *pilha, int placa);
void valida_pilha_igual(Pilha *pilha1, Pilha *pilha2);
void pilha_maior(Pilha *pilha1, Pilha *pilha2);
void inverte_pilha(Pilha *pilha);
void imprime_pilha_reversa(PilhaReal *pilha);

#endif //PILHA_H