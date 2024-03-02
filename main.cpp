#include <iostream>
#include <stdlib.h>
using namespace std;

void inicializarTabuleiro(char tabuleiro[3][3]){

    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }

    }
}

int main() {

}