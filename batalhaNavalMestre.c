#include <stdio.h>

#define TAM 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5 


void sobreporHabilidade(int tabuleiro[TAM][TAM], int size, int mat[][5], int origemLinha, int origemColuna);

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0) //
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Declaração dos navios como vetores //
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAMANHO_NAVIO]   = {NAVIO, NAVIO, NAVIO};
    int navioDiagonal1[TAMANHO_NAVIO]  = {NAVIO, NAVIO, NAVIO}; 
    int navioDiagonal2[TAMANHO_NAVIO]  = {NAVIO, NAVIO, NAVIO}; 

    // Coordenadas iniciais //
    int linhaHorizontal = 2, colunaHorizontal = 4;
    int linhaVertical   = 5, colunaVertical   = 7;
    int linhaDiagonal1  = 0, colunaDiagonal1  = 0; 
    int linhaDiagonal2  = 0, colunaDiagonal2  = 9; 


    // Posiciona navio horizontal //
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical //
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Posiciona navio diagonal principal //
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = navioDiagonal1[i];
    }

    // Posiciona navio diagonal inversa  //
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = navioDiagonal2[i];
    }

    const int S = 5;
    int cone[S][S], cruz[S][S], octa[S][S];


    for (int r = 0; r < S; r++) {
        for (int c = 0; c < S; c++) {
            cone[r][c] = 0;
        }
    }
    int meio = S / 2;
    for (int r = 0; r < S; r++) {
        int inicio = meio - r;
        int fim    = meio + r;
        for (int c = 0; c < S; c++) {
            if (c >= inicio && c <= fim) cone[r][c] = 1;
        }
    }


    for (int r = 0; r < S; r++) {
        for (int c = 0; c < S; c++) {
            cruz[r][c] = 0;
        }
    }
    for (int r = 0; r < S; r++) cruz[r][meio] = 1;
    for (int c = 0; c < S; c++) cruz[meio][c] = 1;

    for (int r = 0; r < S; r++) {
        for (int c = 0; c < S; c++) {
            octa[r][c] = 0;
            int dist = (r > meio ? r - meio : meio - r) + (c > meio ? c - meio : meio - c);
            if (dist <= meio) octa[r][c] = 1;
        }
    }


    sobreporHabilidade(tabuleiro, S, cone, 4, 4);
    sobreporHabilidade(tabuleiro, S, cruz, 3, 6);
    sobreporHabilidade(tabuleiro, S, octa, 6, 3);


   
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


void sobreporHabilidade(int tabuleiro[TAM][TAM], int size, int mat[][5], int origemLinha, int origemColuna) {
    int meio = size / 2;
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (mat[r][c] == 1) {
                int tr = origemLinha + (r - meio);
                int tc = origemColuna + (c - meio);
                if (tr >= 0 && tr < TAM && tc >= 0 && tc < TAM) {
                    if (tabuleiro[tr][tc] == AGUA) {
                        tabuleiro[tr][tc] = HABILIDADE;
                    }
                }
            }
        }
    }
}