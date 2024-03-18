#include <stdio.h>
#include "geraVetor.h"

#define TAMANHO_VETOR 100

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
    int numeros[TAMANHO_VETOR];
    //int numeros[] = {2,8,7,1,3,5,6,4};


    //adicionaNumerosAleatorios(numeros,TAMANHO_VETOR);
    //insereCrescente(numeros,TAMANHO_VETOR); //Melhor caso
    //insereDecrescente(numeros,TAMANHO_VETOR); //Pior caso
    adicionaNumerosSemiOrdenados(numeros,TAMANHO_VETOR,95);


    printArray(numeros,TAMANHO_VETOR);
    int comparacoes, trocas = 0;
    //partition(numeros,0,TAMANHO_VETOR-1);
    quicksort(numeros,0,TAMANHO_VETOR-1,&comparacoes,&trocas);
    //printArray(numeros,TAMANHO_VETOR);
    checaOrdenacao(numeros,TAMANHO_VETOR);
    printf("Numero de trocas:%d\nNumero de comparacoes:%d\n",trocas,comparacoes);
}