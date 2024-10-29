#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;
    char name[40];
    int priority;
    int wait;
    struct Process *prox;
} Process;

typedef struct Fila {
    Process* inicio;
    Process* fim;
} Fila;

Fila* cria_fila() {
    Fila *fila = malloc(sizeof(Fila));
    
    if(fila == NULL) {
        return NULL;
    }
    
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void inserir(Fila* fila) {
    Process *process, *aux;

    if(fila == NULL) {
        return;
    }
    
    process = malloc(sizeof(Process));
    
    printf("Digite o ID do processo\n");
    scanf("%d", &process->id);
    printf("Digite o nome do processo\n");
    scanf("%s", process->name);
    printf("Digite a prioridade do processo\n");
    scanf("%d", &process->priority);
    printf("Digite o tempo de execução do proceso\n");
    scanf("%d", &process->wait);
    
    process->prox = NULL;
    
    if (fila->inicio == NULL) {
        fila->inicio = process;
    } else {
        aux = fila->fim;
        aux->prox = process;
    }

    fila->fim = process;
    printf("Processo salvo com sucesso!\n");
}

void mostrar_fila(Fila* fila) {
    Process *aux;
    int count = 0;
    
    if(fila == NULL) {
        return;
    }
    
    aux = fila->inicio;
    
    while(aux != NULL) {
        printf("%d° da lista -> Processo de ID %d, Nome: %s, Prioridade: %d, Tempo execução: %d \n", count++, aux->id, aux->name, aux->priority, aux->wait);
        aux = aux->prox;
    }
}

int executarProcesso(Fila* fila) {
    Process *aux;
    int retorno = 0;
    
    if(fila == NULL) {
        return 0;
    }
    
    if(fila->inicio == NULL) {
        return 0;    
    }
    
    aux = fila->inicio;
    fila->inicio = aux->prox;
    retorno = aux->id;
    
    free(aux);
    
    if(fila->inicio == NULL) {
        fila->fim = NULL;  
    }
    
    aux = NULL;
    
    return retorno;
}

int qtdProcessos(Fila *fila) {
    Process *aux;
    int cont = 0;
    
    if(fila == NULL) {
        return -1;
    }
    
    if(fila->inicio == NULL) {
        return 0;
    }
    
    aux = fila->inicio;
    cont++;
    
    while(aux->prox != NULL) {
        aux = aux->prox;
        cont++;
    }
    
    return cont;
}

int matarProcessoMaiorTempo(Fila* fila) {
    if(fila == NULL || fila->inicio == NULL) {
        return -1;
    }

    Process *aux = fila->inicio;
    Process *processoMaiorTempo = aux;
    Process *processoAnterior = NULL;
    Process *anteriorMaiorTempo = NULL;

    while(aux != NULL) {
        if(aux->wait > processoMaiorTempo->wait) {
            processoMaiorTempo = aux;
            anteriorMaiorTempo = processoAnterior;
        }

        processoAnterior = aux;
        aux = aux->prox;
    }

    if(anteriorMaiorTempo->wait == NULL) {
        printf("Não há processos com tempo maior do que 0 segundos de execução\n");
        fila->inicio = processoMaiorTempo->prox;
    } else {
        anteriorMaiorTempo->prox = processoMaiorTempo->prox;
    }

    if(processoMaiorTempo == fila->fim) {
        fila->fim = anteriorMaiorTempo;
    }


    int idProcessoMorto = processoMaiorTempo->id;
    free(processoMaiorTempo);
    processoMaiorTempo = NULL;

    return idProcessoMorto;
}

Fila* intercalarFilas(Fila *fila1, Fila *fila2) {
    if(fila1 == NULL || fila2 == NULL) {
        printf("Uma das filas está nula\n");
        return;
    }

    Fila *fila3 = criar_fila();

    Process *aux1 = fila1->inicio;
    Process *aux2 = fila2->inicio;
    Process *aux3 = aux1;
    fila3->inicio = aux3;
    fila3->fim = aux3;

    while(aux1 != NULL && aux2 != NULL) {
        aux3->prox = aux1;
        aux3->prox = aux2;
        aux2 = aux2->prox;
        aux1 = aux1->prox;
    }

    return fila3;
}

int main() {
    // Questão 3
    Fila *fila1;
    printf("cria fila...\n");
    fila1 = cria_fila();
    printf("Fila criada...\n");
    inserir(fila1);
    inserir(fila1);
    inserir(fila1);
    // mostrar_fila(fila);
    // int processoExecutado = executarProcesso(fila);
    // printf("Processo de ID '%d' executado com sucesso!\n", processoExecutado);
    // mostrar_fila(fila);
    // inserir(fila);
    // mostrar_fila(fila);
    // int idProcessoMorto = matarProcessoMaiorTempo(fila);
    // printf("Processo de ID '%d' morto por maior tempo de execução!\n", idProcessoMorto);
    // mostrar_fila(fila);
    
    // Questão 4
    Fila *fila2;
    printf("cria fila 2...\n");
    fila2 = cria_fila();
    printf("Fila 2 criada...\n");
    inserir(fila2);
    inserir(fila2);
    inserir(fila2);

    Fila *fila3;
    printf("cria fila 3...\n");
    fila3 = intercalarFilas(fila1, fila2);
    mostrar_fila(fila3);
    
    return 0;
}