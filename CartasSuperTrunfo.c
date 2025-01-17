#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 25 // Maximo de cartas cadastradas 
#define MAX_ESTADOS 8 // Número de estados por país 
#define MAX_CIDADES 4 // Número de cidades por estados 

// ARMAZENAR DADOS DAS CIDADES 
typedef struct {
    char codigo[4]; // código de cada carta 
    char nomeCidade[25];
} Cidade;  

// ARMAZENAR DADOS DOS ESTADOS 
typedef struct {
    char nomeEstado; 
    Cidade_cidades[MAX_CIDADES]; // 4 cidades por estado 
} Estado; 

// ARMAZENAR DADOS DOS PAÍSES ]
typedef struct {
    char nome[25] 
    int populacao
    float area 
    float pib 
    int pontosTuristicos 
    Estado_estados[MAX_ESTADOS];
} Pais

// FUNCAO PARA LIMPAR O BUFFER DE ENTRADA 
void limparBuffer(void) {
    int c;
    while (((c = getchar()) != '\n') && (c != EOF));
}

// CADASTRANDO CIDADES 
void cadastrarCidade(Cidade *cidade, char nomeCidade[], char estado, int numeroCidade) {
    // GERANDO O CODIGO DA CIDADE BASEANDO NO ESTADO E CIDADE
    snprintf(cidade->codigo, sizeof(cidade->codigo), "%c%02d", estado, numeroCidade);

    // NOME DA CIDADE
    strcpy(cidade->nomeCidade, nomeCidade);
}

void cadastrarEstado(struct Estado *estado, char nomeEstado, struct Pais *país) {
    estado->nomeEstado = nomeEstado;

    // CADASTRAR AS CIDADES DO ESTADO
    for (int i = 0; i < MAX_CIDADES; i++) {
        char nomeCidade[25];
        printf("Digite o nome da cidade %d para o estado %c: ", i + 1, nomeEstado);
        limparBuffer();
        scanf("%[^\n]", nomeCidade);

        // valida o nome da cidade
        if (strlen(nomeCidade) == 0) {
            printf("Nome da cidade nao pode ser vazio. Tente novamente. \n");
            i--;
            continue;
        }

        cadastrarCidade(&estado->cidades[i], nomeCidade, nomeEstado, i + 1);

    }
    // SALVAR O ESTADO DENTRO DO PAÍS
    pais->estados[estado->nomeEstado - 'A'] = *estado;
}
