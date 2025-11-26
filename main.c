/*
 * Projeto: Sistema de Gestão de Beneficiários (ODS 2 - Fome Zero)
 * Disciplina: Bases de Programação - Eng. Computação
 * * Desenvolvedor Responsável:
 * 1. David Augusto Ribeiro Lima (N4CH77)
 * * Nota: Projeto desenvolvido individualmente, abrangendo todas as etapas
 * de arquitetura, implementação, testes e documentação.
 */

// -- Bibliotecas utilizadas --
#include <stdio.h>
#include <stdlib.h>

#include "beneficiario.h"

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
            criarBeneficiario();
            break;
        case 2:
            lerBeneficiarios();
            break;
        case 3:
            atualizarBeneficiario();
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

