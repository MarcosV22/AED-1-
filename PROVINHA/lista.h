#ifndef LISTA_H
#define LISTA_H

typedef struct Num {
    int dado;
    struct Num* proximo;
} Num;

typedef struct Lista {
    Num* inicio;
} Lista;

void iniciarlizarLista(Lista* lista);
void inserirElemento(Lista* lista, int valor);
int removerMaiorElemento(Lista* lista);
void imprimirMaiorElemento(Lista* lista);

#endif
