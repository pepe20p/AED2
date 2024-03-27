#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int n;
    struct Node *prox;
}Node_T;


Node_T* InsereLista(Node_T *Inicio,int n){
    Node_T* No = Inicio;
    if (No == NULL) {
        Node_T *novo = (Node_T *) malloc(sizeof(Node_T));
        novo->n = n;
        novo->prox = NULL;
        return novo;
    }
    while (No->prox != NULL) No = No->prox;
    Node_T *ultimo = (Node_T *) malloc(sizeof(Node_T));
    ultimo->n=n;
    ultimo->prox=NULL;
    No->prox=ultimo;
    return Inicio;
}

void printLista(Node_T *No){
    if (No != NULL) {
        printf("%d\n", No->n);
        printLista(No->prox);
    }
}

void limpa(Node_T *No){
    if (No != NULL) {
        limpa(No->prox);
        free(No);
    }
    
}

int main() {
    Node_T *lista= NULL;
    lista = InsereLista(lista,1);
    InsereLista(lista,3);
    printLista(lista);
    limpa(lista);
}