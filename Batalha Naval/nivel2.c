#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, int tamanho, int direcao) {
    // direcao: 0 = horizontal, 1 = vertical, 2 = diagonal
    for (int i = 0; i < tamanho; i++) {
        if (linha < LINHAS && coluna < COLUNAS) {
            tabuleiro[linha][coluna] = 1;
            
            if (direcao == 0) coluna++; // horizontal
            else if (direcao == 1) linha++; // vertical
            else if (direcao == 2) { linha++; coluna++; } // diagonal
        }
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};
    
    // Exemplo: navio tamanho 4 na horizontal em (1,1)
    posicionarNavio(tabuleiro, 1, 1, 4, 0);
    
    // Exemplo: navio tamanho 3 na diagonal em (3,3)
    posicionarNavio(tabuleiro, 3, 3, 3, 2);
    
    printf("Tabuleiro (Aventureiro):\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}