#include <stdio.h>
#include <stdlib.h>

struct lista{
  int* elementos;
  int tamanho;
};

typedef struct lista Lista;

Lista *CriaLista(int tamanho){
    Lista *retorno = malloc(sizeof(Lista));
    int* elementos = malloc(tamanho * sizeof(int));

    retorno->elementos = elementos;
    retorno->tamanho = tamanho;
    return retorno;
}

void PreencherValoresDaListaAutomaticamente(Lista *lista){
    for(int i = 0;i<lista->tamanho;i++){
        lista->elementos[i] = i*2;
    }
}


void PreencherValoresDaLista(Lista *lista){
    if(lista == NULL){
        return;
    }

    printf("Por Favor preencha a lista\n");
    for(int i = 0;i<lista->tamanho;i++){
        printf("   Elemento %d da lista: ",i);
        int elemento;
        scanf("%d",&elemento);
        lista->elementos[i] = elemento;
    }
}

void ExibirLista(Lista *lista){
    if(lista == NULL){
        return;
    }
    printf("INICIO DA EXIBICAO DOS ELEMENTOS\n\n");
    for(int i = 0; i< lista->tamanho;i++){
        printf("Elemento %d da Lista: %d\n",i, lista->elementos[i]);
    }
    printf("\nFIM DA EXIBICAO DOS ELEMENTOS\n\n");
}

void InserirElementoNaLista(Lista* lista, int elemento){
    lista->tamanho++;
    int* novoArray = realloc(lista->elementos, lista->tamanho * sizeof(int));
    novoArray[lista->tamanho-1] = elemento;
    lista->elementos = novoArray;
}

void BuscarElementoNaListaDeFormaSequencial(Lista *lista, int numeroProcurado){
    if(lista == NULL || numeroProcurado == NULL){
        return;
    }

    for(int i = 0;i<lista->tamanho;i++){
        if(lista->elementos[i]==numeroProcurado){
            printf("BUSCA SEQUENCIAL: O numero %d foi encontrado na lista, ele esta na posicao %d(Precisei de %d buscas para encontrar)\n", numeroProcurado,i,i+1);
            return;
        }
    }

    printf("BUSCA SEQUENCIAL:O numero %d nao foi encontrado na lista.\n",numeroProcurado);

}
void BuscarElementosDeFormaBinaria(Lista *lista,int numeroProcurado){
    int tamanho = lista->tamanho;
    int inicio = 0;
    int fim = tamanho-1;

    int count = 0;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (lista->elementos[meio] == numeroProcurado) {
            printf("BUSCA BINARIA: O numero %d foi encontrado e esta na posicao %d(precisei fazer %d buscas para encontrar)\n",numeroProcurado,meio,count);
            return;
        }

        if (lista->elementos[meio] < numeroProcurado) {
            inicio = meio + 1; // Descarta a metade da esquerda
        } else {
            fim = meio - 1; // Descarta a metade da direita
        }
        count++;
    }
    printf("BUSCA BINARIA:O numero %d nao foi encontrado(precisei de %d buscas para nao encontrar).\n",numeroProcurado,count);
}

void BuscarOMenorElemento(Lista *lista){
    if(lista == NULL){
        return -1;
    }
    int menor = lista->elementos[0];

    for(int i = 1;i<lista->tamanho;i++){
        if(lista->elementos[i]<menor){
            menor = lista->elementos[i];
        }
    }
    printf("MENOR ELEMENTO: Menor elemento da lista: %d\n",menor);
}

void SomarTodosOsElementos(Lista *lista){
    if(lista == NULL){
        return;
    }

    int soma = 0;

    for(int i = 0;i<lista->tamanho;i++){
        soma+=lista->elementos[i];
    }

    printf("SOMA: Soma de todos os elementos:%d\n",soma);
}

void ProdutoDeTodosOsElementos(Lista *lista){
    if(lista == NULL){
        return;
    }

    int produto = 1;

    for(int i = 0;i<lista->tamanho;i++){
        produto*=lista->elementos[i];
    }

    printf("PRODUTO:Produto de todos os elementos:%d\n",produto);
}

void DestruirLista(Lista* lista){
    free(lista->elementos);
    free(lista);
}

int main()
{

    int tamanho = 0,numeroProcurado = 0;

    printf("Insira o tamanho da lista: ");
    scanf("%d",&tamanho);

    Lista* listinha = CriaLista(tamanho);

    PreencherValoresDaLista(listinha);

    system("cls");
    ExibirLista(listinha);

    printf("Exemplo de Busca com um numero encontrado e outro nao encontrado:\n\n");
    BuscarElementoNaListaDeFormaSequencial(listinha,listinha->elementos[0]);
    BuscarElementosDeFormaBinaria(listinha,198462);

    printf("\n Insira um numero para buscar na lista, (farei uma busca sequencial e uma busca binaria):");
    scanf("%d",&numeroProcurado);

    system("cls");
    ExibirLista(listinha);
    BuscarElementoNaListaDeFormaSequencial(listinha,numeroProcurado);
    BuscarElementosDeFormaBinaria(listinha,numeroProcurado);


    BuscarOMenorElemento(listinha);
    SomarTodosOsElementos(listinha);
    ProdutoDeTodosOsElementos(listinha);

    Lista* lista2 = CriaLista(30);
    PreencherValoresDaListaAutomaticamente(lista2);

    printf("\n Insira um numero para buscar na lista 2:");
    scanf("%d",&numeroProcurado);
    BuscarElementoNaListaDeFormaSequencial(lista2,numeroProcurado);
    BuscarElementosDeFormaBinaria(lista2,numeroProcurado);

    DestruirLista(listinha);
    DestruirLista(lista2);

    return 0;
}
