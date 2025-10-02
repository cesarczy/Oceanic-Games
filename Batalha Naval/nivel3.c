#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void habilidadeCruz(int tabuleiro[LINHAS][COLUNAS], int centroX, int centroY, int alcance) {
    for (int i = centroX - alcance; i <= centroX + alcance; i++) {
        if (i >= 0 && i < LINHAS) tabuleiro[i][centroY] = 2; // 2 = área de efeito
    }
    for (int j = centroY - alcance; j <= centroY + alcance; j++) {
        if (j >= 0 && j < COLUNAS) tabuleiro[centroX][j] = 2;
    }
}

void habilidadeCone(int tabuleiro[LINHAS][COLUNAS], int inicioX, int inicioY, int direcao, int alcance) {
    // direcao: 0 = cima, 1 = baixo, 2 = esq, 3 = dir
    if (direcao == 3) { // direita
        for (int i = 0; i < alcance; i++) {
            for (int j = 0; j <= i; j++) {
                int x = inicioX + j;
                int y = inicioY + i;
                if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS) {
                    tabuleiro[x][y] = 3; // 3 = cone
                }
            }
        }
    }
    // Outras direções podem ser implementadas similarmente
}

void habilidadeOctaedro(int tabuleiro[LINHAS][COLUNAS], int centroX, int centroY, int raio) {
    for (int i = centroX - raio; i <= centroX + raio; i++) {
        for (int j = centroY - raio; j <= centroY + raio; j++) {
            if (i >= 0 && i < LINHAS && j >= 0 && j < COLUNAS) {
                int dist = abs(i - centroX) + abs(j - centroY);
                if (dist <= raio) {
                    tabuleiro[i][j] = 4; // 4 = octaedro
                }
            }
        }
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};
    
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);
    
    printf("\nApós habilidade Cruz (centro 5,5, alcance 2):\n");
    habilidadeCruz(tabuleiro, 5, 5, 2);
    exibirTabuleiro(tabuleiro);
    
    printf("\nApós habilidade Cone (inicio 2,2, direita, alcance 4):\n");
    habilidadeCone(tabuleiro, 2, 2, 3, 4);
    exibirTabuleiro(tabuleiro);
    
    printf("\nApós habilidade Octaedro (centro 7,7, raio 2):\n");
    habilidadeOctaedro(tabuleiro, 7, 7, 2);
    exibirTabuleiro(tabuleiro);
    
    return 0;
}