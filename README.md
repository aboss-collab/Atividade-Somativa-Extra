# Atividade-Somativa-Extra
Ponteiros, Structs e Alocação
# Exercícios de Ponteiros e Memória em C

Este repositório contém a resolução de uma série de atividades práticas focadas no entendimento e manipulação de **Ponteiros, Structs e Alocação Dinâmica de Memória** na linguagem C.

##  Atividades Desenvolvidas

* **Atividade 1: Fundamentos de Ponteiros e Modificação Direta**
    * Manipulação do valor de uma variável `float` exclusivamente através de seu endereço de memória (ponteiro).
* **Atividade 2: Passagem por Referência**
    * Encapsulamento da lógica de alteração em funções utilizando ponteiros como parâmetros (`void aplicar_desconto`), alterando o valor original diretamente na memória.
* **Atividade 3: Ponteiros para Structs**
    * Criação da estrutura `Produto` (contendo `id` e `preco`) e utilização do operador seta (`->`) para acessar e modificar membros via ponteiro.
* **Atividade 4: Aritmética de Ponteiros em Arrays**
    * Varredura e impressão de arrays de structs utilizando aritmética de ponteiros pura, no formato `*(ptr + i)` ou `(ptr + i)->membro`, sem utilizar colchetes `[]`.
* **Atividade 5: Alocação Dinâmica de Memória (`malloc` e `free`)**
    * Evolução do sistema para aceitar um tamanho de estoque definido pelo usuário em tempo de execução, gerenciando a memória manualmente com `malloc()` e liberando-a adequadamente com `free()`.

##  Como Executar o Projeto

Certifique-se de ter um compilador C (como o `gcc`) instalado em sua máquina.

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git](https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git)
