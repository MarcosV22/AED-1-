#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista* lista) {
    lista->inicio = NULL;
}

void inserirElemento(Lista* lista, int valor) {
    Num* novoNum = (Num*)malloc(sizeof(Num));
    novoNum->dado = valor;
    novoNum->proximo = lista->inicio;
    lista->inicio = novoNum;
}

int removerMaiorElemento(Lista* lista) {
    if (lista->inicio == NULL) {

        return -1;
    }

    Num* atual = lista->inicio;
    Num* anterior = NULL;
    Num* maior = lista->inicio;

    while (atual != NULL) {
        if (atual->dado > maior->dado) {
            maior = atual;
            anterior = anterior;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {

        lista->inicio = maior->proximo;
    } else {
        anterior->proximo = maior->proximo;
    }

    int valorMaior = maior->dado;
    free(maior);
    return valorMaior;
}

void imprimirMaiorElemento(Lista* lista) {
    int maior = removerMaiorElemento(lista);
    if (maior != -1) {
        printf("Maior elemento: %d\n", maior);
    } else {
        printf("Lista vazia\n");
    }
}
