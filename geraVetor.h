#ifndef _vetores_h
#define _vetores_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int Vet[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ",Vet[i]);
    }
    printf("\n");
}

void adicionaNumerosAleatorios(int Vet[], int N){
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        Vet[i] = rand() % N;
    }
}

void insereCrescente(int Vet[], int N){
    for (int i = 0; i < N; i++) {
        Vet[i] = i;
    }
}

void insereDecrescente(int Vet[], int N){
    for (int i = 0; i < N; i++) {
        Vet[i] = N-i-1; //-1 para que a funcao retorne exatamente o inverso da funcao Crescente
    } 
}

void adicionaNumerosSemiOrdenados(int Vet[], int N, int ordenacao){
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        if (rand()%101>= ordenacao) {
            Vet[i] = rand() % N;
        }
        else {
            Vet[i] = i;
        }
    }
}

void checaOrdenacao(int Vet[], int N){
    for (int i = 1; i < N; i++) {
        if (Vet[i] < Vet[i-1])    {
            printf("Vetor nao ordenado\n");
            return;
        }
    }
    printf("Vetor ordenado\n");
}

#endif