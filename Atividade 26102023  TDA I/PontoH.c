#include <stdio.h>
#include <stdlib.h>

#include "PontoH.h"

// Criar um tipo abstrato de dados que represente uma pessoa, contendo: nome, data de nascimento e CPF.
// -Crie uma fun��o que receba um ponteiro para o TDA e preencha os dados da estrutura.
// -Crie outra fun��o que receba um ponteiro para o TDA e imprima os dados da estrutura.
// -Crie um ponteiro para o TDA (no programa principal) e utilize as fun��es criadas.

int main()
{
DadosPessoa *ponteiropessoa = (DadosPessoa *)malloc(sizeof(DadosPessoa));

preencherDados(ponteiropessoa);

printf("Dados da pessoa: ");
printarPessoa(ponteiropessoa);

}
