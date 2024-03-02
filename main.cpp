#include <iostream>
#include <stdlib.h>
using namespace std;

char tabuleiro[3][3];

void inicializarTabuleiro(){

    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }
}

int validarCaractere(char letra) {
    if (letra == 'X' || letra == 'O') {
        return 1;
    } else {
        return 0;
    }
}

int validarCoordenada(int x, int y) {
    if (x >= 0 && x < 3) {
        if (y >= 0 && y < 3) {
            return 1;
        }
    } else {
        return 0;
    }
}

int verificarPosicaoVazia(int x, int y) {
    if (tabuleiro[x][y] != 'X' && tabuleiro[x][y] != '0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {

}