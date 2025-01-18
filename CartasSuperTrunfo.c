#include <stdio.h>
// funcao para criar os codigos das cartas
void criaCodigo() {
    char estado[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; // estado de A a H
    int cidade[4] = {1, 2, 3, 4}; // cidade de 1 a 4

    printf("Códigos das Cartas:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c%02d\n", estado[i], cidade[j]); // exibe o codigo da carta
        }
    }

}
// funcao para cadastras cada cidade
typedef struct {
    char codigo[4]; // codigo da cidade
    int populacao; // populacao da cidade
    float area; // area da cidade
    float pib; // pib da cidade
    int pontosTuristicos; // pontos turisticos da cidade
} Cidade;

// estrutura para ler os dados de cada cidade
void cadastrarCidade(Cidade *cidade) {
    printf("Digite o codigo da cidade: ");
    scanf("%s", cidade->codigo);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a area da cidade: ");
    scanf("%f", &cidade->area);

    printf("Digite o pib da cidade: ");
    scanf("%f", &cidade->pib);

    printf("Digite o numero de pontos turisticos da cidade: ");
    scanf("%d", &cidade->pontosTuristicos);

}

// funcao para exibir os dados de cada cidade
void exibirCidade(Cidade cidade) {
    // calcula a densidade populacional e o pib per capita
    float densidadePopulacional = cidade.populacao / cidade.area;
    float pibPerCapita = cidade.pib / cidade.populacao;

    printf("Codigo: %s\n", cidade.codigo);
    printf("Populacao: %d habitantes\n", cidade.populacao);
    printf("Area: %.2f km²\n", cidade.area);
    printf("PIB: %.2f milhoes\n", cidade.pib);
    printf("Pontos Turisticos: %d\n", cidade.pontosTuristicos);
    printf("Densidade polulacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: %.2f milhoes/habitante\n", pibPerCapita);
}
// funcao para calcular o super poder de um cidade 
float calcularSuperPoder(Cidade cidade) {
    float densidadePopulacional = cidade.populacao / cidade.area;
    float pibPerCapita = cidade.pib / cidade.populacao;
    return cidade.populacao + cidade.area + cidade.pib + cidade.pontosTuristicos + densidadePopulacional + pibPerCapita;
}
// funcao para comparar 
void compararSuperPoder(Cidade cidade1, Cidade cidade2) {
    float superPoder1 = calcularSuperPoder(cidade1);
    float superPoder2 = calcularSuperPoder(cidade2);
    // exibir o vencedor ou empate se houver
    if (superPoder1 > superPoder2) {
            printf("A cidade %s é a vencedora!\n", cidade1.codigo);
        } else if (superPoder1 < superPoder2) {
            printf("A cidade %s é a vencedora!\n", cidade2.codigo);
        } else {
            printf("Empate entre as cidades %s e %s!\n", cidade1.codigo, cidade2.codigo);
    }
}
int main() {
    int n;
    printf("Quantas cidades deseja cadastrar? ");	
    scanf("%d", &n);

    Cidade cidades[n]; // array para armazenar as cidades cadastradas

    // ler dados de todas as cidades 
    for (int i = 0; i < n; i++) {
        printf("\nCadastrando cidade %d:\n", i + 1);
        cadastrarCidade(&cidades[i]);
    }
    // exibir os dados de todas as cidades
    printf("\nDados das Cidades:\n");
    for (int i = 0; i < n; i++) {
        printf("\nCidade %d:\n", i + 1);
        exibirCidade(cidades[i]);
    }
    // comparar entre duas cidades
    if (n > 1 ) {
        int cidade1, cidade2;
        printf("\n Escolha duas cidades para comparar (entre 1 e %d):\n", n);
        scanf("%d %d", &cidade1, &cidade2);

        if (cidade1 > 0 && cidade1 <= n && cidade2 > 0 && cidade2 <= n) {
            compararSuperPoder(cidades[cidade1 - 1], cidades[cidade2 - 1]);
        } else {
            printf("Cidades invalidas!\n");
        }
    }
    return 0;
}