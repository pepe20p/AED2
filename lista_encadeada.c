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
        printf("%d", No->n);
        printLista(No->prox);
    }
    if (No == NULL) printf("\n");
}

void limpa(Node_T *No){
    if (No != NULL) {
        limpa(No->prox);
        free(No);
    }
    
}

void divideLista(Node_T *lista, Node_T *L,Node_T *R){
    Node_T *frente, *tras;
    //Node_T* tras;
    tras = lista;
    frente = lista->prox;

    while (frente!=NULL) {
        frente = frente->prox;
        if (frente!=NULL) {
            tras = tras->prox;
            frente = frente->prox;
        }
    }
    
    L = lista;
    R = tras->prox;
    tras->prox = NULL;
}

int main() {
    Node_T *lista= NULL;
    Node_T *L= NULL;
    Node_T *R= NULL;
    lista = InsereLista(lista,1);
    InsereLista(lista,3);
    InsereLista(lista,2);
    InsereLista(lista,7);
    InsereLista(lista,5);
    divideLista(lista,L,R);
    printLista(lista);
    printLista(L);
    printLista(R);
    limpa(lista);
    limpa(L);
    limpa(R);
}