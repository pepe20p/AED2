#include <stdio.h>
#include <stdlib.h>
#include "geraVetor.h"

#define TAMANHO_VETOR 1000000

typedef struct {
    int vet[TAMANHO_VETOR];
    int N;
    int size;
}heap_type;

void exchange(int *vet, int i, int j){
    int aux;
    aux =  vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void maxHeapify(heap_type *A, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest;
    if (l < A->size && A->vet[l] > A->vet[i])
    {
        largest = l;
    }
    else largest = i;

    if (r < A->size && A->vet[r] > A->vet[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        exchange(A->vet,i,largest);
        maxHeapify(A,largest);
    }
    
}

void BuildMaxHeap(heap_type *A){
    A->size = A->N;
    int i;
    for (i = (A->N/2)-1; i >=0; i--)
    maxHeapify(A,i);
}

void HeapSort(heap_type *A){
    int i;
    BuildMaxHeap(A);
    for (i = A->N-1; i >= 1; i--)
    {
        exchange(A->vet,0,i);
        A->size--;
        maxHeapify(A,0);
    }
}

int main(){
    heap_type A;
    int i;
    A.N = TAMANHO_VETOR;
    //A.vet = malloc(sizeof(int)*A.N);
    adicionaNumerosAleatorios(A.vet,TAMANHO_VETOR);
    //insereCrescente(A.vet,TAMANHO_VETOR); //Melhor caso
    //insereDecrescente(A.vet,TAMANHO_VETOR); //Pior caso
    //adicionaNumerosSemiOrdenados(A.vet,TAMANHO_VETOR,95);
    printArray(A.vet,A.N);
    HeapSort(&A);
    checaOrdenacao(A.vet,A.N);
    //print(&A);
}
