#include <iostream>
#include <stdlib.h>
using namespace std;

void iniciarTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }

    }
}

void imprimirTabuleiro(char tabuleiro[3][3]) {
    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++) {
            cout << tabuleiro[linha][coluna];
        }
        cout << endl;
    }
}

int main() {
    char tabuleiro[3][3], jogador;
    int i, j, linha, coluna, rodada, ganhou;

}