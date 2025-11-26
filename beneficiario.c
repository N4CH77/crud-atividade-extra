// -- Bibliotecas utilizadas --
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "beneficiario.h"

// 1. [CRIAR]
void criarBeneficiario() {

struct Beneficiario novoBeneficiario;
FILE *arquivo;

printf("\n--Cadastrando Novo Beneficiario--\n");

getchar();

// --- Pedindo os dados ---
printf("Digite o CPF (numero): ");
fgets(novoBeneficiario.cpf, 15, stdin);
novoBeneficiario.cpf[strcspn(novoBeneficiario.cpf, "\n")] = '\0';

printf("Digite o Nome: ");
fgets(novoBeneficiario.nome, 100, stdin);

printf("Digite a idade (numero): ");
scanf("%d", &novoBeneficiario.idade);

getchar();

printf("Digite o sexo (masculino/feminino): ");
fgets(novoBeneficiario.sexo, 20, stdin);
novoBeneficiario.sexo[strcspn(novoBeneficiario.sexo, "\n")] = '\0';

// ___ Abertura de arquivo ___
arquivo = fopen("beneficiario.txt", "a");

if (arquivo == NULL) {
    printf("ERRO! Nao foi possivel abrir o arquivo.\n");
    return;
}

// ___ Dados do arquivo ___
fprintf(arquivo, "Cpf: %s\n", novoBeneficiario.cpf);
fprintf(arquivo, "Nome: %s\n", novoBeneficiario.nome);
fprintf(arquivo, "Idade: %d\n", novoBeneficiario.idade);
fprintf(arquivo, "Sexo: %s\n", novoBeneficiario.sexo);
fprintf(arquivo, "---------------------\n");

fclose(arquivo);

printf("\n>>> Beneficiario salvo com sucesso... <<<\n");
}

// 2. [LER]
void lerBeneficiarios() {
    FILE *arquivo;
    char linha[500];

// ___ Abertura de arquivo ___
arquivo = fopen("beneficiario.txt", "r");

if (arquivo == NULL) {
    printf("\nERRO! Nao foi possivel abrir o arquivo.\n");
    printf("Talvez voce ainda nao criou seu documento?\n");
    return;
}

printf("\n--- TODOS OS DOCUMENTOS SALVOS ---\n\n");
while (fgets(linha, 500, arquivo) != NULL) {
        printf("%s", linha);
}

printf("\n--- FIM DOS DOCUMENTOS ---\n");

fclose(arquivo);
}

// 3. [ATUALIZAR]
void atualizarBeneficiario() {
    char cpfBusca[20];
    char novaLinha[500];
    int beneficiarioEncontrado = 0;
    printf("\n--- Atualizar Beneficiario ---\n");
    printf("\nDigite o CPF do beneficiario que deseja atualizar: ");
    getchar();
    fgets(cpfBusca, 20, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0';

// ___ Abertura de arquivo ___
    FILE *arquivoOriginal = fopen("beneficiario.txt", "r");
    FILE *arquivoTemp = fopen("beneficiario_temp.txt", "w");

    if (arquivoOriginal == NULL || arquivoTemp == NULL) {
        printf("\nERRO! Nao foi possivel abrir o arquivo.\n");
        return;
    }

    while (fgets(novaLinha, 500, arquivoOriginal) != NULL) {
        
        if (strstr(novaLinha, cpfBusca) != NULL) {
            beneficiarioEncontrado = 1;
            printf("\nBeneficiario encontrado! Insira os novos dados:\n");

            struct Beneficiario benAtualizado;

            printf("Digite o novo Nome: ");
            fgets(benAtualizado.nome, 100, stdin);
            benAtualizado.nome[strcspn(benAtualizado.nome, "\n")] = '\0'; 
            printf("Digite a nova idade (numero): ");
            scanf("%d", &benAtualizado.idade);
            getchar();

            printf("Digite o novo sexo (masculino/feminino): ");
            fgets(benAtualizado.sexo, 20, stdin);
            benAtualizado.sexo[strcspn(benAtualizado.sexo, "\n")] = '\0'; 

            fprintf(arquivoTemp, "Cpf: %s\n", cpfBusca); 
            fprintf(arquivoTemp, "Nome: %s\n", benAtualizado.nome);
            fprintf(arquivoTemp, "Idade: %d\n", benAtualizado.idade);
            fprintf(arquivoTemp, "Sexo: %s\n", benAtualizado.sexo);
            fprintf(arquivoTemp, "---------------------\n");

            for (int i = 0; i < 4; i++) {
                fgets(novaLinha, 500, arquivoOriginal);
            }
        } else {
            fputs(novaLinha, arquivoTemp);
        }
    } 

    fclose(arquivoOriginal);
    fclose(arquivoTemp);

    remove("beneficiario.txt");
    rename("beneficiario_temp.txt", "beneficiario.txt");
    
    if (beneficiarioEncontrado) {
        printf("\n>>> Beneficiario atualizado com sucesso! <<<\n");
    } else {
        printf("\n>>> Beneficiario com CPF %s nao encontrado. <<<\n", cpfBusca);
    }
} 

// 0. LIMPAR TELA
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #endif
}