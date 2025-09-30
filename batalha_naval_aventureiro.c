#include <stdio.h>
#define TAMANHO 10
#define OCUPADO 3
#define LIVRE 0

void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = LIVRE;
        }
    }
}

void posicionar_navios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Navio 1: Vertical (Tamanho 4)
    // De (1, 1) a (4, 1)
    for (int i = 1; i < 5; i++) {
        tabuleiro[i][1] = OCUPADO;
    }

    // Navio 2: Horizontal (Tamanho 3)
    // De (7, 5) a (7, 7)
    for (int j = 5; j < 8; j++) {
        tabuleiro[7][j] = OCUPADO;
    }

    // Navio 3: Diagonal Principal (Cima-Esquerda para Baixo-Direita, Tamanho 3)
    // De (0, 0) a (2, 2)
    for (int k = 0; k < 3; k++) {
        tabuleiro[k][k] = OCUPADO;
    }

    // Navio 4: Diagonal Secundária (Cima-Direita para Baixo-Esquerda, Tamanho 4)
    // De (3, 9) a (6, 6)
    for (int k = 0; k < 4; k++) {
        tabuleiro[3 + k][9 - k] = OCUPADO;
    }
}

void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    printf("  ---------------------\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d |", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    inicializar_tabuleiro(tabuleiro);
    posicionar_navios(tabuleiro);

    printf("==========================================\n");
    printf("   Batalha Naval - Nivel Aventureiro (10x10)\n");
    printf("   0: Posicao Vazia | 3: Posicao Ocupada\n");
    printf("==========================================\n\n");

    exibir_tabuleiro(tabuleiro);

    printf("\n==========================================\n");

    return 0;
}
