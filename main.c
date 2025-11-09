// -- Bibliotecas utilizadas --
#include <stdio.h>
#include <stdlib.h>

// -- Estrutura para leitura ou criação do documento (CPF, nome, idade e sexo) da empresa --
struct Documento
{
    char cpf[15]; // "char" guarda um texto. No exemplo, 15 caracteres
    char nome[100];
    int idade; // "int" guarda números
    char sexo[20];
};

// -- Declaração das funções p/ main() [3 funções] --
void criarDocumento(); // Linha 61
void lerDocumentos(); // Linha 106
void limparTela(); // Linha 131

// -- Opções (CRIAR, LER, ATUALIZAR, DELETAR E SAIR) --
int main() {
    int opcoes;
    while (1)
    {
        limparTela();
        printf("\nOpcoes:\n");
        printf("1 - Criar\n");
        printf("2 - Ler\n");  
        printf("3 - Atualizar\n");
        printf("4 - Deletar\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcoes);

    switch (opcoes)
    {
        case 1:
            criarDocumento();
            break;
        case 2:
            lerDocumentos();
            break;
        case 3:
            printf("\n>>> Você escolheu ATUALIZAR\n");
            break;
        case 4:
            printf("\n>>> Você escolheu DELETAR\n");
            break;
        case 5:
            printf("\n>>> Saindo...\n");
            exit(0);    
        default:
            printf("\n>>> Opção inválida! Tente novamente.\n");
            break;
            }

    }
    return 0; 
}

// 1. [CRIAR]
void criarDocumento() {

struct Documento novoDocumento;
FILE *arquivo;

printf("\n--Criando um novo Documento--\n");

getchar();

// --- Pedindo os dados ---
printf("Digite o CPF (numero): ");
fgets(novoDocumento.cpf, 15, stdin);

printf("Digite o Nome: ");
fgets(novoDocumento.nome, 100, stdin);

printf("Digite a idade (numero): ");
scanf("%d", &novoDocumento.idade);

getchar();

printf("Digite o sexo (masculino/feminino): ");
fgets(novoDocumento.sexo, 20, stdin);

// ___ Abertura de arquivo ___
arquivo = fopen("documento.txt", "a");

if (arquivo == NULL) {
    printf("ERRO! Nao foi possivel abrir o arquivo.\n");
    return;
}

// ___ Dados do arquivo ___
fprintf(arquivo, "Cpf: %s", novoDocumento.cpf);
fprintf(arquivo, "Nome: %s", novoDocumento.nome);
fprintf(arquivo, "Idade: %d\n", novoDocumento.idade);
fprintf(arquivo, "Sexo: %s", novoDocumento.sexo);
fprintf(arquivo, "---------------------\n");

fclose(arquivo);

printf("\n>>> Documento salvo com sucesso no nosso banco de dados! <<<\n");
}

// 2. [LER]
void lerDocumentos() {
    FILE *arquivo;
    char linha[500];

// ___ Abertura de arquivo ___
arquivo = fopen("documento.txt", "r");

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

// 0. LIMPAR TELA
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #endif
}