#include <stdio.h>
#include <stdlib.h>
#include "geraVetor.h"
#include <limits.h>

#define TAMANHO_VETOR 15

int retornaMaiorNumero(int Vet[], int N){
    int maior=INT_MIN;
    for (int i = 0; i < N; i++) {
        if (Vet[i]>maior) maior = Vet[i];
    }
    return maior;
}

void countingSortPorDigito(int Vet[], int N,int digito){
    int VetOrdenado[N+1];
    int i;
    int k = Vet[0];

    for (int i = 1; i < N; i++) {
        if (((Vet[i] / digito) % 10) > k) k = Vet[i];
    }
    int C[k+1];
    for (i = 0; i <= k; i++) C[i]=0;
    for (i = 0; i < N; i++) C[(Vet[i]/digito)%10] = C[(Vet[i]/digito)%10]+1;
    for (i = 1; i <= k+1; i++) C[i] = C[i] + C[i-1];
    for (i = N-1; i >= 0; i--) {
        VetOrdenado[(C[(Vet[i]/digito)%10]-1)] = Vet[i];
        C[Vet[i]] = C[Vet[i]] - 1; 
    }
    for (i = 0; i < N; i++) Vet[i] = VetOrdenado[i];
}

void RadixSort(int Vet[], int N){
    int maior = retornaMaiorNumero(Vet,N);
    int digito;
    for (digito = 1; maior / digito > 0; digito *= 10)
    {
        countingSortPorDigito(Vet,N,digito);
    }
    
}

int main() {
    int vetor[TAMANHO_VETOR];
    //int vetor[] = {2,8,7,1,3,5,6,4};


    adicionaNumerosAleatorios(vetor,TAMANHO_VETOR);
    //insereCrescente(vetor,TAMANHO_VETOR);
    //insereDecrescente(vetor,TAMANHO_VETOR);
    //adicionaNumerosSemiOrdenados(vetor,TAMANHO_VETOR,95);


    printArray(vetor,TAMANHO_VETOR);
    int comparacoes, trocas = 0;
    comparacoes = retornaMaiorNumero(vetor,TAMANHO_VETOR);
    RadixSort(vetor,TAMANHO_VETOR);
    printArray(vetor,TAMANHO_VETOR);
    checaOrdenacao(vetor,TAMANHO_VETOR);
    printf("Numero de trocas:%d\nNumero de comparacoes:%d\n",trocas,comparacoes);
}