# Projeto CRUD em C
![Linguagem C](https://img.shields.io/badge/Linguagem-C-00599C?style=for-the-badge&logo=c&logoColor=white)

> Versão: 1.0.0 (CRUD Básico - C e R)

Este é um projeto simples de CRUD (Create, Read, Update, Delete) feito em linguagem C. Ele foi desenvolvido como um exercício para a matéria BASES DE PROGRAMAÇÃO do curso de Engenharia de Computação da UniJorge.

O programa simula o cadastro de documentos (CPF, Nome, Idade, Sexo) em uma empresa e salva os dados em um arquivo `documento.txt`.

---

## Tecnologias Utilizadas

* **Linguagem:** C
* **Compilador:** GCC (MinGW-w64)

---

## Funcionalidades
* **[1] Criar:** Adiciona um novo documento ao banco de dados (`documento.txt`).
* **[2] Ler:** Lê e exibe todos os documentos salvos no `documento.txt`.
* **[3] Atualizar:** (Não implementado - exibe apenas uma mensagem)
* **[4] Deletar:** (Não implementado - exibe apenas uma mensagem)
* **[5] Sair:** Encerra o programa.

---

## Demonstração
<img width="1536" height="946" alt="demo png" src="https://github.com/user-attachments/assets/5df686dd-4437-4f1e-b7ca-2be930025769" />

---

## Desafios & Soluções
Durante o desenvolvimento, alguns desafios interessantes surgiram:

1.  **`int` vs `char[]` para CPF:** O CPF foi implementado como `char[15]` (texto) e não `int` (número).
    * **Problema:** Um `int` de 32 bits não armazena os 11 dígitos de um CPF (o limite é ~2.14 bilhões).
    * **Solução:** Tratar o CPF como um texto (`char[]`) resolve o problema de tamanho e permite salvar formatação (pontos e traço).

2.  **`scanf` vs `fgets` (Buffer do Teclado):**
    * **Problema:** O `scanf("%d", ...)` usado para ler a opção do menu e a idade deixava um `\n` (Enter) "sobrando" no buffer do teclado.
    * **Solução:** A função `getchar()` foi usada estrategicamente após cada `scanf` para "consumir" esse `\n` e limpar o buffer, permitindo que o `fgets()` seguinte funcionasse corretamente para ler os textos.

---

## Como Compilar e Rodar

1.  Você precisa ter um compilador C (como o GCC) instalado.
2.  Abra o terminal e navegue até a pasta do projeto.
3.  Compile o código:
    ```bash
    gcc main.c -o crud
    ```
4.  Execute o programa:
    * No Linux/Mac: `./crud`
    * No Windows: `crud.exe`

---

## Autor

* **David Augusto (N4CH77)**
* [LinkedIn](https://www.linkedin.com/in/n4ch77/)
* [GitHub](https://github.com/N4CH77)
