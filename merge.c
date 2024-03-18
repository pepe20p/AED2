#include <stdio.h>
#include "geraVetor.h"

#define TAMANHO_VETOR 100

void merge(int Vet[], int comeco, int meio, int fim, int *comparacoes, int *trocas) {
    int i,j,k;
    int tam1 = meio-comeco+2;
    int tam2 = fim-meio+1;
    int L[tam1], R[tam2];
    for (i = 0; i < tam1-1; i++)  {
        L[i] = Vet[comeco+i];
    }
    for (j = 0; j < tam2-1; j++)  {
        R[j] = Vet[meio+j+1];    }
    L[tam1-1] = __INT_MAX__;
    R[tam2-1] = __INT_MAX__;
    i = 0;
    j = 0;
    for (k = comeco; k <= fim; k++) {
        if (L[i]<R[j])  {
            *comparacoes += 1;
            Vet[k]=L[i];
            i++;
        }
        else    {
            *comparacoes += 1;
            *trocas +=1;
            Vet[k]=R[j];
            j++;
        }
    }
}

void merge_sort(int Vet[], int comeco, int fim, int *comparacoes, int *trocas){
    if (comeco < fim) {
        int meio = (((comeco+fim)/2));
        merge_sort(Vet,comeco,meio,comparacoes,trocas);
        merge_sort(Vet,meio+1,fim,comparacoes,trocas);
        merge(Vet,comeco,meio,fim,comparacoes,trocas);
    }
}

int main(){
    int numeros[TAMANHO_VETOR];
    //int numeros[] = {2,2,2,2};


    //adicionaNumerosAleatorios(numeros,TAMANHO_VETOR);
    insereCrescente(numeros,TAMANHO_VETOR); //Melhor caso
    //insereDecrescente(numeros,TAMANHO_VETOR); //Pior caso
    //adicionaNumerosSemiOrdenados(numeros,TAMANHO_VETOR,95);


    printArray(numeros,TAMANHO_VETOR);
    //merge(numeros,0,2,5);
    int comparacoes, trocas = 0;
    merge_sort(numeros,0,TAMANHO_VETOR-1,&comparacoes,&trocas);
    //printArray(numeros,TAMANHO_VETOR);
    checaOrdenacao(numeros,TAMANHO_VETOR);
    printf("Numero de trocas:%d\nNumero de comparacoes:%d\n",trocas,comparacoes);
}