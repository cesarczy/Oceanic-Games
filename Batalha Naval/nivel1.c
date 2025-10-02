#include <stdio.h>

#define TAM 10

void exibirTabuleiro(int tabuleiro[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", tabuleiro[i]);
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAM] = {0}; // Inicializa o tabuleiro com 0 (água)
    
    int posicao = 2;
    int tamanhoNavio = 3;
    
    for (int i = 0; i < tamanhoNavio; i++) {
        if (posicao + i < TAM) {
            tabuleiro[posicao + i] = 1;
        }
    }
    
    printf("Tabuleiro (Novato):\n");
    exibirTabuleiro(tabuleiro, TAM);
    
    return 0;
}