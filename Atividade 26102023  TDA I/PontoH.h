#ifndef PONTOH_H_INCLUDED
#define PONTOH_H_INCLUDED

typedef struct dados DadosPessoa;
struct dados {               // Struct
    char nome[50];
    char dataNascimento[11];
    char cpf[12];
};
void preencherDados(DadosPessoa *PTRPessoa){
printf("Nome da Pessoa: ");
    scanf("%s", PTRPessoa->nome);
    printf("Data de nascimento: ");
    scanf("%s", PTRPessoa->dataNascimento);
    printf("Digite o CPF: ");
    scanf("%s", PTRPessoa->cpf);}

void printarPessoa(DadosPessoa *PTRPessoa){
 printf("Nome: %s\n", PTRPessoa->nome);
    printf("Data de Nascimento: %s\n", PTRPessoa->dataNascimento);
    printf("CPF: %s\n", PTRPessoa->cpf);}

#endif // PONTOH_H_INCLUDED
