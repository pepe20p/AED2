#include <stdio.h>
#include "geraVetor.h"

#define TAMANHO_VETOR 100000

int partition(int Vet[],int inicio,int fim, int *comparacoes, int *trocas){
    int pivo = Vet[fim];
    int i = inicio-1;
    int aux;
    for (int j = inicio; j < fim; j++) {
        if (Vet[j] <= pivo) {
            *comparacoes+=1;
            *trocas+=1;
            i +=1;
            aux = Vet[j];
            Vet[j] = Vet[i];
            Vet[i] = aux;
        }
        else *comparacoes+=1;
    }
    aux = Vet[i+1];
    Vet[i+1] = Vet[fim];
    Vet[fim] = aux;
    return i+1;
}

void quicksort(int Vet[], int inicio, int fim, int *comparacoes, int *trocas) {
    if (inicio < fim){
        int meio = partition(Vet,inicio, fim,comparacoes,trocas);
        quicksort(Vet, inicio, meio-1,comparacoes,trocas);
        quicksort(Vet, meio+1, fim,comparacoes,trocas);
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
    //partition(vetor,0,TAMANHO_VETOR-1);
    quicksort(vetor,0,TAMANHO_VETOR-1,&comparacoes,&trocas);
    //printArray(vetor,TAMANHO_VETOR);
    checaOrdenacao(vetor,TAMANHO_VETOR);
    printf("Numero de trocas:%d\nNumero de comparacoes:%d\n",trocas,comparacoes);
}