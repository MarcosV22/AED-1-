#include <stdio.h>
#include "lista.h"
#include "lista.c"
#include <time.h>

int main() {
    char nome[] = "Marcos Vinicius";
    char codigoexercicio[] = "001";

    time_t now;
    time(&now);
    printf("\nData e hora de entrega: %s", ctime(&now));
    printf("\nNome: %s", nome);
    printf("\nCodigo do exercicio: %s \n", codigoexercicio);
    Lista minhaLista;
    inicializarLista(&minhaLista);

    inserirElemento(&minhaLista, 15);
    inserirElemento(&minhaLista, 28);
    inserirElemento(&minhaLista, 9);
    inserirElemento(&minhaLista, 31);
    inserirElemento(&minhaLista, 2);

    imprimirMaiorElemento(&minhaLista);

 return 0;

}
