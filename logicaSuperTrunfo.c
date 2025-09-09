#include <stdio.h>
#include <string.h>

// 1. Estrutura para representar uma carta (cidade)
struct Carta {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Enumeração para facilitar a escolha de atributos no menu
enum Atributos {
    POPULACAO = 1,
    AREA,
    PIB,
    PONTOS_TURISTICOS,
    DENSIDADE_DEMOGRAFICA
};

// Função para exibir o menu de atributos
void exibirMenu(int atributoJaEscolhido) {
    printf("\n--- Escolha um Atributo para Comparacao ---\n");
    if (atributoJaEscolhido != POPULACAO) {
        printf("1. Populacao\n");
    }
    if (atributoJaEscolhido != AREA) {
        printf("2. Area\n");
    }
    if (atributoJaEscolhido != PIB) {
        printf("3. PIB\n");
    }
    if (atributoJaEscolhido != PONTOS_TURISTICOS) {
        printf("4. Pontos Turisticos\n");
    }
    if (atributoJaEscolhido != DENSIDADE_DEMOGRAFICA) {
        printf("5. Densidade Demografica\n");
    }
}

// Função para obter o valor do atributo de uma carta
float obterValorAtributo(struct Carta carta, int atributo) {
    switch (atributo) {
        case POPULACAO:
            return carta.populacao;
        case AREA:
            return carta.area;
        case PIB:
            return carta.pib;
        case PONTOS_TURISTICOS:
            return carta.pontosTuristicos;
        case DENSIDADE_DEMOGRAFICA:
            return carta.densidadeDemografica;
        default:
            return 0.0;
    }
}

// Função para obter o nome do atributo
const char* obterNomeAtributo(int atributo) {
    switch (atributo) {
        case POPULACAO:
            return "Populacao";
        case AREA:
            return "Area";
        case PIB:
            return "PIB";
        case PONTOS_TURISTICOS:
            return "Pontos Turisticos";
        case DENSIDADE_DEMOGRAFICA:
            return "Densidade Demografica";
        default:
            return "Desconhecido";
    }
}

int main() {
    // 2. Criação das cartas usando a struct
    struct Carta carta1, carta2;

    // A. CADASTRO DA CARTA 1
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (ex: BA): ");
    scanf(" %2s", carta1.estado);
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf(" %3s", carta1.codigo);
    printf("Digite o Nome da Cidade (sem espacos): ");
    scanf(" %49s", carta1.nomeCidade);
    printf("Digite a Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Digite a Area (em km2): ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB (em reais): ");
    scanf("%f", &carta1.pib);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    carta1.densidadeDemografica = carta1.populacao / carta1.area;

    // B. CADASTRO DA CARTA 2
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (ex: SP): ");
    scanf(" %2s", carta2.estado);
    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf(" %3s", carta2.codigo);
    printf("Digite o Nome da Cidade (sem espacos): ");
    scanf(" %49s", carta2.nomeCidade);
    printf("Digite a Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Digite a Area (em km2): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB (em reais): ");
    scanf("%f", &carta2.pib);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    // C. ESCOLHA E COMPARACAO DOS ATRIBUTOS
    int escolha1, escolha2;

    do {
        exibirMenu(0); // Exibe o menu completo
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &escolha1);
    } while (escolha1 < POPULACAO || escolha1 > DENSIDADE_DEMOGRAFICA);

    do {
        exibirMenu(escolha1); // Exibe o menu sem a primeira escolha
        printf("Escolha o segundo atributo: ");
        scanf("%d", &escolha2);
    } while (escolha2 < POPULACAO || escolha2 > DENSIDADE_DEMOGRAFICA || escolha2 == escolha1);

    // D. CALCULOS E EXIBICAO DOS RESULTADOS
    printf("\n--- RESULTADO DA COMPARACAO ---\n");
    printf("Atributos escolhidos: %s e %s\n\n", obterNomeAtributo(escolha1), obterNomeAtributo(escolha2));

    // Obtém os valores dos atributos para cada carta
    float valor1_carta1 = obterValorAtributo(carta1, escolha1);
    float valor2_carta1 = obterValorAtributo(carta1, escolha2);
    float valor1_carta2 = obterValorAtributo(carta2, escolha1);
    float valor2_carta2 = obterValorAtributo(carta2, escolha2);

    // Exibe os valores
    printf("Carta 1 (%s)\n", carta1.nomeCidade);
    printf("  %s: %.2f\n", obterNomeAtributo(escolha1), valor1_carta1);
    printf("  %s: %.2f\n", obterNomeAtributo(escolha2), valor2_carta1);

    printf("Carta 2 (%s)\n", carta2.nomeCidade);
    printf("  %s: %.2f\n", obterNomeAtributo(escolha1), valor1_carta2);
    printf("  %s: %.2f\n", obterNomeAtributo(escolha2), valor2_carta2);

    // Soma dos atributos
    float somaCarta1 = valor1_carta1 + valor2_carta1;
    float somaCarta2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.nomeCidade, somaCarta1);
    printf("  %s: %.2f\n", carta2.nomeCidade, somaCarta2);

    // Determina o vencedor da rodada
    printf("\nResultado Final: ");
    if (somaCarta1 > somaCarta2) {
        printf("%s VENCEU!\n", carta1.nomeCidade);
    } else if (somaCarta2 > somaCarta1) {
        printf("%s VENCEU!\n", carta2.nomeCidade);
    } else {
        printf("EMPATOU!\n");
    }

    return 0;
}