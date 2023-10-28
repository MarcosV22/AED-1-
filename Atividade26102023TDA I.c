#include <stdio.h>
#include <stdlib.h>

// Criar um tipo abstrato de dados que represente uma pessoa, contendo: nome, data de nascimento e CPF.
// -Crie uma fun��o que receba um ponteiro para o TDA e preencha os dados da estrutura.
// -Crie outra fun��o que receba um ponteiro para o TDA e imprima os dados da estrutura.
// -Crie um ponteiro para o TDA (no programa principal) e utilize as fun��es criadas.

typedef struct {               // Struct
    char nome[50];
    char dataNascimento[11];
    char cpf[12];
} DadosPessoa;

void preencherDados(DadosPessoa *DadosPessoa) {        // Fun��o para preencher os dados
    printf("Nome da Pessoa: ");
    scanf("%s", DadosPessoa->nome);
    printf("Data de nascimento: ");
    scanf("%s", DadosPessoa->dataNascimento);
    printf("Digite o CPF: ");
    scanf("%s", DadosPessoa->cpf);
}
void printarPessoa(DadosPessoa *DadosPessoa) {          // Fun��o para printar os dados
     printf("Nome: %s\n", DadosPessoa->nome);
    printf("Data de Nascimento: %s\n", DadosPessoa->dataNascimento);
    printf("CPF: %s\n", DadosPessoa->cpf);
}

int main()
{
DadosPessoa *ponteiropessoa = (DadosPessoa *)malloc(sizeof(DadosPessoa)); // Criar um ponteiro na fun��o principal

preencherDados(ponteiropessoa); // Chamar fun��o

printf("Dados da pessoa: "); // Chamar fun��o
printarPessoa(ponteiropessoa);

}
