#include <stdio.h>
#include "geraVetor.h"

#define TAMANHO_VETOR 100

void insertion(int Vet[]){
    int i,j,aux;
    int trocas = 0, comparacoes = 0;
    for (i = 1; i < TAMANHO_VETOR; i++) {
        j = i - 1;
        aux = Vet[i];
        if (Vet[j] < aux) comparacoes++; //Nao faz parte do algoritmo, apenas para contagem de comparacoes
        while (j >= 0 && Vet[j] > aux)  {
            Vet[j+1] = Vet[j];
            trocas++;
            comparacoes++;
            j--;
        }
        Vet[j+1] = aux;
    }
    printf("Numero de trocas:%d\nNumero de comparacoes:%d\n",trocas,comparacoes);
}

int main(){
    int vetor[TAMANHO_VETOR];
    
    //adicionaNumerosAleatorios(vetor,TAMANHO_VETOR);
    //insereCrescente(vetor,TAMANHO_VETOR); //Melhor caso
    //insereDecrescente(vetor,TAMANHO_VETOR); //Pior caso
    adicionaNumerosSemiOrdenados(vetor,TAMANHO_VETOR,95);


    printArray(vetor,TAMANHO_VETOR);
    insertion(vetor);
    checaOrdenacao(vetor,TAMANHO_VETOR);
    //printArray(vetor,TAMANHO_VETOR);
}