#include <stdio.h>
#include <stdlib.h>

typedef struct DateTime {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} DateTime;

struct DateTime criaHora() {
    int dia, mes, ano, hora, minuto, segundo;
    DateTime dataHora;
    
    printf("Digite o dia\n");
    scanf("%d", &dia);
    printf("Digite o mes\n");
    scanf("%d", &mes);
    printf("Digite o ano\n");
    scanf("%d", &ano);
    printf("Digite o hora\n");
    scanf("%d", &hora);
    printf("Digite o minuto\n");
    scanf("%d", &minuto);
    printf("Digite o segundo\n");
    scanf("%d", &segundo);
    
    dataHora.dia = dia;
    dataHora.mes = mes;
    dataHora.ano = ano;
    dataHora.hora = hora;
    dataHora.minuto = minuto;
    dataHora.segundo = segundo;
    
    return dataHora;
}

typedef struct Aviao {
    int numero;
    char modelo[50];
    char prefixo[50];
    char empresa[50];
    struct DateTime dataHora;
    struct Aviao* prox;
} Aviao;

typedef struct Fila {
    Aviao* inicio;
    Aviao* fim;
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
    Aviao *aviao, *aux;
    int numero, modelo;
    struct DateTime dataHora;
    
    if(fila == NULL) {
        return;
    }
    
    aviao = malloc(sizeof(Aviao));
    
    printf("Digite o numero do voo\n");
    scanf("%d", &numero);
    aviao->numero = numero;
    
    printf("Digite o modelo do aviao\n");
    scanf("%s", aviao->modelo);
    
    printf("Digite o prefixo do aviao\n");
    scanf("%s", aviao->prefixo);
    
    printf("Digite a empresa do aviao\n");
    scanf("%s", aviao->empresa);
    
    dataHora = criaHora();
    aviao->dataHora = dataHora;
    aviao->prox = NULL;
    
    if (fila->inicio == NULL) {
        fila->inicio = aviao;
    } else {
        aux = fila->fim;
        aux->prox = aviao;
    }

    fila->fim = aviao;
    printf("Avião criado com sucesso!\n");
}

void mostrar_fila(Fila* fila) {
    Aviao *aux;
    int count = 0;
    
    if(fila == NULL) {
        return;
    }
    
    aux = fila->inicio;
    
    while(aux != NULL) {
        printf("%d° da lista -> N° do voo %d\n", count++, aux->numero);
        aux = aux->prox;
    }
}

int autorizarDecolagem(Fila* fila) {
    Aviao *aux;
    int retorno = 0;
    
    if(fila == NULL) {
        return 0;
    }
    
    if(fila->inicio == NULL) {
        return 0;    
    }
    
    aux = fila->inicio;
    fila->inicio = aux->prox;
    retorno = aux->numero;
    
    free(aux);
    
    if(fila->inicio == NULL) {
        fila->fim = NULL;  
    }
    
    aux = NULL;
    
    return retorno;
}

int qtdAvioesNaFila(Fila *fila) {
    Aviao *aux;
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

void listaPrimeiro(Fila *fila) {
    Aviao *aux;
    
    if(fila == NULL) {
        return;
    }
    
    if(fila->inicio == NULL) {
        printf("Nao ha avioes na fila\n");
    }
    
    aux = fila->inicio;
    printf("N° do voo: %d, modelo: %s, prefixo: %s, nome da empresa: %s, data: %d/%d/%d %d:%d:%d\n", aux->numero, aux->modelo, aux->prefixo, aux->empresa, aux->dataHora.dia, aux->dataHora.mes, aux->dataHora.ano, aux->dataHora.hora, aux->dataHora.minuto, aux->dataHora.segundo);
}

void furaFilaPorPosicao(Fila *fila, int posicaoAviao) {
    Aviao *aux, *auxAnterior;
    int count = 0;
    
    if(fila == NULL) {
        return;
    }
    
    if(fila->inicio == NULL) {
        printf("Nao ha avioes na fila\n");
    }
    
    aux = fila->inicio;
    
    while(count < posicaoAviao && aux->prox != NULL) {
        auxAnterior = aux;
        aux = aux->prox;
        count++;
    }
    
    auxAnterior->prox = aux->prox;
    aux->prox = fila->inicio;
    fila->inicio = aux;
    
    printf("O voo N° %d furou a fila para o inicio\n", aux->numero);
}

void furaFilaInicio(Fila *fila) {
    Aviao *aviao, *aux;
    int numero, modelo;
    struct DateTime dataHora;
    
    if(fila == NULL) {
        return;
    }
    
    aviao = malloc(sizeof(Aviao));
    
    printf("Digite o numero do voo\n");
    scanf("%d", &numero);
    aviao->numero = numero;
    
    printf("Digite o modelo do aviao\n");
    scanf("%s", aviao->modelo);
    
    printf("Digite o prefixo do aviao\n");
    scanf("%s", aviao->prefixo);
    
    printf("Digite a empresa do aviao\n");
    scanf("%s", aviao->empresa);
    
    dataHora = criaHora();
    aviao->dataHora = dataHora;
    aviao->prox = NULL;
    
    if (fila->inicio == NULL) {
        fila->inicio = aviao;
    } else {
        aviao->prox = fila->inicio;
        fila->inicio = aviao;
    }

    printf("Novo avião furou a fila com sucesso!\n");
    fila->fim = aviao;
}


int main() {
    Fila *fila;
    
    printf("cria fila...\n");
    fila = cria_fila();
    printf("Fila criada...\n");
    // Exercicio 1
    inserir(fila);
    inserir(fila);
    inserir(fila);
    mostrar_fila(fila);
    int qtdAvioes = qtdAvioesNaFila(fila);
    printf("Avioes na fila: %d\n", qtdAvioes);
    int vooAutorizado = autorizarDecolagem(fila);
    printf("Voo de N° %d autorizado para decolagem\n", vooAutorizado);
    listaPrimeiro(fila);
    // o 1 termina aqui
    
    // Exercicio 2
        // furaFilaPorPosicao(fila, 1);
    furaFilaInicio(fila);
    mostrar_fila(fila);
    // O 2 termina aqui
    
    return 0;
}