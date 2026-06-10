#include <stdio.h>
#include <stdlib.h>

// Atividade 3: Definição da Struct Produto
typedef struct {
    int id;
    float preco;
} Produto;

// Atividade 1 e 2: Passagem por referência para aplicar aumento/desconto
void aplicar_aumento(float *preco, float percentual) {
    // Modificação direta na memória usando o operador de derreferenciação (*)
    *preco = *preco + (*preco * (percentual / 100.0));
}

// Atividade 3: Função adaptada para receber ponteiro de Struct e usar o operador seta (->)
void aplicar_desconto(Produto *p, float percentual) {
    // O operador -> acessa o membro de uma struct através de um ponteiro
    p->preco = p->preco - (p->preco * (percentual / 100.0));
}

// Atividade 4: Impressão utilizando Aritmética de Ponteiros (sem colchetes)
void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("\n--- Lista de Produtos (Estoque) ---\n");
    for (int i = 0; i < quantidade; i++) {
        // (ptr + i) desloca o ponteiro na memória pelo tamanho de 'i' estruturas Produto
        printf("ID: %d | Preco: R$ %.2f\n", (ptr + i)->id, (ptr + i)->preco);
    }
    printf("-----------------------------------\n");
}

int main() {
    // --- DEMONSTRAÇÃO DA ATIVIDADE 1 ---
    printf("=== Atividade 1: Modificacao Direta ===\n");
    float preco_avulso = 100.0;
    float *ptr_preco = &preco_avulso;
    
    printf("Preco original: R$ %.2f\n", preco_avulso);
    aplicar_aumento(ptr_preco, 10.0); // Aumenta 10%
    printf("Preco apos aumento de 10%% (via ponteiro): R$ %.2f\n\n", preco_avulso);


    // --- DEMONSTRAÇÃO DA ATIVIDADE 5 (Alocação Dinâmica que engloba Atividades 2, 3 e 4) ---
    printf("=== Atividade 5: Alocacao Dinamica de Estoque ===\n");
    int quantidade;

    printf("Quantos produtos deseja cadastrar no estoque? ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    // Alocação dinâmica de memória usando malloc
    Produto *estoque = (Produto *) malloc(quantidade * sizeof(Produto));

    // Validação da alocação
    if (estoque == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        return 1;
    }

    // Preenchendo o array iterando com aritmética de ponteiros
    for (int i = 0; i < quantidade; i++) {
        Produto *p_atual = estoque + i; // Ponteiro para a posição atual
        
        printf("\nCadastrando Produto [%d]:\n", i + 1);
        printf("Digite o ID: ");
        scanf("%d", &(p_atual->id));
        printf("Digite o Preco: R$ ");
        scanf("%f", &(p_atual->preco));
    }

    // Atividade 4: Exibindo os produtos originais
    printf("\nEstado Inicial do Estoque:");
    imprimir_produtos(estoque, quantidade);

    // Atividade 2 e 3: Aplicando desconto de 15% no primeiro produto (se houver)
    if (quantidade > 0) {
        printf("\nAplicando 15%% de desconto no primeiro produto (ID: %d) via funcao...\n", estoque->id);
        aplicar_desconto(estoque, 15.0); // estoque aponta para o primeiro elemento
        
        // Relatório atualizado
        printf("\nEstado Atualizado do Estoque:");
        imprimir_produtos(estoque, quantidade);
    }

    // Atividade 5: Liberação obrigatória da memória alocada
    free(estoque);
    estoque = NULL; // Boa prática: evita ponteiro "solto" (dangling pointer)

    printf("\nMemoria liberada com sucesso. Programa encerrado.\n");
    return 0;
}
