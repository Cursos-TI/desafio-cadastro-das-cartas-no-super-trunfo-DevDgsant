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

int main() {
    // funcao principal
    printf("Gerando os codigos das cartas...\n");
    criaCodigo();
    return 0;
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
    printf("Codigo: %s\n", cidade.codigo);
    printf("Populacao: %d\n", cidade.populacao);
    printf("Area: %.2f\n", cidade.area);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Pontos Turisticos: %d\n", cidade.pontosTuristicos);
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

    return 0;   
}