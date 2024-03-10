#include <iostream>
// #include <stdlib.h>
using namespace std;

void inicializarJogo();

void menu() {
    int opcao = 0;

    while (opcao != 2) {
        cout << "Bem-vindo ao Jogo da Velha! Por favor, digite o número da opção desejada: " << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Sair" << endl;
        cin >> opcao;

        if (opcao < 0 || opcao > 2) {
            cout << "Opção inválida. Tente novamente." << endl;
            opcao = 0;
        }
        
        if (opcao == 1) {
            cout << "Jogo iniciado!" << endl;
            inicializarJogo();
            break;
        }
    }
    cout << "Até a próxima! :D" << endl;
}

void inicializarTabuleiro(char tabuleiro[3][3]) {

    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]) { 
    
    int linha, coluna;

    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna <3; coluna++){
            cout << tabuleiro[linha][coluna];
        }

        cout << endl;
    }
}

bool verificarLinhas(char tabuleiro[3][3]) {
    int linha;
    bool vencedor = false;
    for (linha = 0; linha < 3; linha++){
        if (tabuleiro[linha][0] == 'X' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][1]){
            cout << "O jogador 1 venceu!" << endl;
            vencedor = true;
        }
        else if (tabuleiro[linha][0] == 'O' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][1]){
            cout << "O jogador 2 venceu!" << endl;
            vencedor = true;
        }
    }
    return vencedor;
}

bool verificarColunas (char tabuleiro[3][3]) {
    int coluna;
    bool vencedor = false;
    for (coluna = 0; coluna < 3; coluna++){
        if (tabuleiro[0][coluna] == 'X' && tabuleiro[1][coluna] == tabuleiro[0][coluna] && tabuleiro[2][coluna] == tabuleiro[1][coluna]){
            cout << "O jogador 1 venceu!" << endl;
            vencedor = true;
        }
        else if (tabuleiro[0][coluna] == 'O' && tabuleiro[1][coluna] == tabuleiro[0][coluna] && tabuleiro[2][coluna] == tabuleiro[1][coluna]){
            cout << "O jogador 2 venceu!" << endl;
            vencedor = true;
        }
    }
    return vencedor;
}

bool verificarDiagonais (char tabuleiro[3][3]) {
    bool vencedor = false;

    if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == tabuleiro[0][0] && tabuleiro[2][2] == tabuleiro[1][1]){
        cout << "O jogador 1 venceu!" << endl;
        vencedor = true;
    }
    else if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == tabuleiro[0][0] && tabuleiro[2][2] == tabuleiro[1][1]){
        cout << "O jogador 2 venceu!" << endl;
        vencedor = true;
    }
    return vencedor;
}

void inicializarJogo() {

    int posicaoColuna, posicaoLinha;
    int vezJogador = 1;
    int rodada = 0;
    char tabuleiro[3][3];
    char jogador1[30];
    char jogador2[30];
    char resposta;
    bool vencedor = false;

    cout << "Jogador 1, insira seu nome: " << endl;
    cin >> jogador1;
    cout << "Jogador 2, insira seu nome: " << endl;
    cin >> jogador2;

    inicializarTabuleiro(tabuleiro);
    while (rodada < 9 && vencedor == false) {
        exibirTabuleiro(tabuleiro);

        cout << "Rodada: " << rodada << endl;

        if (vezJogador == 1) {
            cout << "É a vez de " << jogador1 << "(X)" << endl;
            cout << "Digite a linha: " << endl;
            cin >> posicaoLinha;
            posicaoLinha = posicaoLinha - 1;
            cout << "Digite a coluna: " << endl;
            cin >> posicaoColuna;
            posicaoColuna = posicaoColuna - 1;

            if (tabuleiro[posicaoLinha][posicaoColuna] == 'X' || tabuleiro[posicaoLinha][posicaoColuna] == 'O') {
                cout << "Jogada inválida!" << endl;
                continue;

            } else {
                tabuleiro[posicaoLinha][posicaoColuna] = 'X';
                vezJogador++;
            }

        } else {
            cout << "É a vez de " << jogador2 << "(O)" << endl;
            cout << "Digite a linha: " << endl;
            cin >> posicaoLinha;
            posicaoLinha = posicaoLinha - 1;
            cout << "Digite a coluna: " << endl;
            cin >> posicaoColuna;
            posicaoColuna = posicaoColuna - 1;

            if (tabuleiro[posicaoLinha][posicaoColuna] == 'X' || tabuleiro[posicaoLinha][posicaoColuna] == 'O') {
                cout << "Jogada inválida!" << endl;
                continue;

            } else {
                tabuleiro[posicaoLinha][posicaoColuna] = 'O';
                vezJogador--;
            }
        }
        if (verificarLinhas(tabuleiro) || verificarColunas(tabuleiro) || verificarDiagonais(tabuleiro)) {
            vencedor = true;
            break;
        }

        rodada++;
    }

    exibirTabuleiro(tabuleiro);
    cout << "FIM DE JOGO" << endl;
    cout << "Deseja jogar novamente? (S/N)" << endl;
    cin >> resposta;

    if (resposta == 'S') {
        menu();
    } else {
        cout << "Até a próxima! :D" << endl;
    }
    
}

int main() {
    menu();
    return 0;
}