#include <stdio.h>

#define TAM 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0) //
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Declaração dos navios como vetores unidimensionais //
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais //
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical   = 5, colunaVertical   = 7;
 
    // Posiciona navio horizontal //
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical //
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Exibe o tabuleiro com rótulos //
    printf("\n   "); // espaço inicial para alinhar //
    for (int j = 1; j <= TAM; j++) {
        printf("%2d ", j); // números das colunas //
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c  ", 'A' + i); // letras das linhas //
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
