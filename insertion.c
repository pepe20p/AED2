#include <stdio.h>
#include "vetores.h"

#define TAMANHO_VETOR 100

void insertion(int Vet[]){
    int i,j,aux;
    int trocas = 0, comparacoes = 0;
    for (i = 1; i < TAMANHO_VETOR; i++)
    {
        j = i - 1;
        aux = Vet[i];
        if (Vet[j] < aux) comparacoes++; //Nao faz parte do algoritmo, apenas para contagem de comparacoes
        while (j >= 0 && Vet[j] > aux)
        {
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
    int numeros[TAMANHO_VETOR];
    
    //adicionaNumerosAleatorios(numeros,TAMANHO_VETOR);
    //insereCrescente(numeros,TAMANHO_VETOR); //Melhor caso
    //insereDecrescente(numeros,TAMANHO_VETOR); //Pior caso
    adicionaNumerosSemiOrdenados(numeros,TAMANHO_VETOR,95);


    printArray(numeros,TAMANHO_VETOR);
    //insertion(numeros);
    //printArray(numeros,TAMANHO_VETOR);
}