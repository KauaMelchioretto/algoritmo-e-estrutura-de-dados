#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "lista.h"
#include <time.h>

double medir_tempo(void (*algoritmo)(Lista*, int), Lista* lista, int n) {

    struct timeval inicio, fim;
    double tempoGasto;
    gettimeofday(&inicio, NULL);

    algoritmo(lista, n);

    gettimeofday(&fim, NULL);
    tempoGasto = (double)(fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;

    return  tempoGasto;
}

void criaArquivoRelatorio(char* file, void(*algoritmo), void(*preencherListaN(Lista* lista, int tamanho))) {
    FILE* arquivo = fopen(file, "w");
    fprintf(arquivo, "Tamanho da Lista;Tempo (s)\n");
    for (int tamanho = 100; tamanho <= 1000; tamanho += 100) {
        Lista* lista = criar_lista();
        preencherListaN(lista, tamanho);

        double tempo_execucao = medir_tempo(algoritmo, lista, tamanho);
        fprintf(arquivo, "%d;%f\n", tamanho, tempo_execucao);
    }
    fclose(arquivo);
}

int main() {
    criaArquivoRelatorio("dadosSelectionSortAleatoria.csv", selectionSort, preencherListaAleatoria);
    criaArquivoRelatorio("dadosSelectionSortCrescente.csv", selectionSort, preencherListaCrescente);
    criaArquivoRelatorio("dadosSelectionSortDecrescente.csv", selectionSort, preencherListaDecrescente);
    criaArquivoRelatorio("dadosBubbleSortAleatoria.csv", bubbleSort, preencherListaAleatoria);
    criaArquivoRelatorio("dadosBubbleSortCrescente.csv", bubbleSort, preencherListaCrescente);
    criaArquivoRelatorio("dadosBubbleSortDecrescente.csv", bubbleSort, preencherListaDecrescente);

    // Modo visível de execução para comparação, caso queira, caso contrário mantenha os métodos acima para criação de arquivos CSV
    // Lista *lista = criar_lista();
    // struct timeval inicio, fim;
    // double tempoGasto;
    //
    // // DESCRESCENTE
    // preencherListaDecrescente(lista, 100);
    // printf("**** Lista *DECRESCENTE* antes de ordenar ****\n");
    // mostrar_lista(lista);
    //
    // // BUBBLESORT DESCRESCENTE
    // gettimeofday(&inicio, NULL);
    // lista = bubbleSort(lista);
    // gettimeofday(&fim, NULL);
    // tempoGasto = (double)(fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
    //
    // // MOSTRA DESCRESCENTE ORDENADA
    // printf("****Lista *DECRESCENTE* depois de ordenar ****\n");
    // mostrar_lista(lista);
    // printf("Tempo gasto: %.6f segundos\n", tempoGasto);
    //
    // // DESCRESCENTE
    // preencherListaDecrescente(lista, 100);
    // printf("**** Lista *DECRESCENTE* antes de ordenar ****\n");
    // mostrar_lista(lista);
    //
    // // SELECTIONSORT DESCRESCENTE
    // gettimeofday(&inicio, NULL);
    // lista = selectionSort(lista);
    // gettimeofday(&fim, NULL);
    // tempoGasto = (double)(fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
    //
    // // MOSTRA DESCRESCENTE ORDENADA
    // printf("****Lista *DECRESCENTE* depois de ordenar ****\n");
    // mostrar_lista(lista);
    // printf("Tempo gasto: %.6f segundos\n", tempoGasto);
    //
    // //CRESCENTE
    // preencherListaCrescente(lista, 100);
    // printf("**** Lista *CRESCENTE* antes de ordenar ****\n");
    // mostrar_lista(lista);
    //
    // // BUBBLESORT CRESCENTE
    // gettimeofday(&inicio, NULL);
    // lista = bubbleSort(lista);
    // gettimeofday(&fim, NULL);
    // tempoGasto = (double)(fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
    //
    // // MOSTRA CRESCENTE ORDENADA
    // printf("****Lista *CRESCENTE* depois de ordenar ****\n");
    // mostrar_lista(lista);
    // printf("Tempo gasto: %.6f segundos\n", tempoGasto);
    //
    // //CRESCENTE
    // preencherListaCrescente(lista, 100);
    // printf("**** Lista *CRESCENTE* antes de ordenar ****\n");
    // mostrar_lista(lista);
    //
    // // SELECTIONSORT CRESCENTE
    // gettimeofday(&inicio, NULL);
    // lista = selectionSort(lista);
    // gettimeofday(&fim, NULL);
    // tempoGasto = (double)(fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
    //
    // // MOSTRA CRESCENTE ORDENADA
    // printf("**** Lista *CRESCENTE* depois de ordenar ****\n");
    // mostrar_lista(lista);
    // printf("Tempo gasto: %.6f segundos\n", tempoGasto);
    //
    // // ALEATORIA
    // preencherListaAleatoria(lista, 100);
    // printf("**** Lista *ALEATORIA* antes de ordenar ****\n");
    // mostrar_lista(lista);
    //
    // // BUBBLESORT ALEATORIA
    // gettimeofday(&inicio, NULL);
    // lista = bubbleSort(lista);
    // gettimeofday(&fim, NULL);
    // tempoGasto = (double)(fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
    //
    // // MOSTRA ALEATORIA ORDENADA
    // printf("**** Lista *ALEATORIA* depois de ordenar ****\n");
    // mostrar_lista(lista);
    // printf("Tempo gasto: %.6f segundos\n", tempoGasto);
    //
    // // ALEATORIA
    // preencherListaAleatoria(lista, 100);
    // printf("**** Lista *ALEATORIA* antes de ordenar ****\n");
    // mostrar_lista(lista);
    //
    // // SELECTIONSORT ALEATORIA
    // gettimeofday(&inicio, NULL);
    // lista = selectionSort(lista);
    // gettimeofday(&fim, NULL);
    // tempoGasto = (double)(fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
    //
    // // MOSTRA ALEATORIA ORDENADA
    // printf("**** Lista *ALEATORIA* depois de ordenar ****\n");
    // mostrar_lista(lista);
    // printf("Tempo gasto: %.6f segundos\n", tempoGasto);

    return 0;
}