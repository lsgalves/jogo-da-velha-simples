#include <iostream>
#include <stdlib.h>

using namespace std;

void criaTabuleiro();

void printaTabuleiro();

void jogada(char simbolo, int jogador);

int verifica(char jogadorUm, char jogadorDois);

char tabuleiro[5][5];

int main(int argc, char const *argv[]) {

    char jogador1, jogador2;

    cout << "====================JOGO=DA=VELHA====================" << endl;

    cout << "Jogador 1 escolha seu simbolo: ";
    cin >> jogador1;

    cout << "Jogador 2 escolha seu simbolo: ";
    cin >> jogador2;
    criaTabuleiro();

    while(true){

        jogada(jogador1, 1);

        printaTabuleiro();

        if(verifica(jogador1, jogador2) == 1){
            cout << "Parabens Jogador 1, Voce Ganhou!!!" << endl;
            criaTabuleiro();
            system("pause");

        }else if(verifica(jogador1, jogador2) == 2){
            cout << "Parabens Jogador 2, Voce Ganhou!!!" << endl;
            criaTabuleiro();
            system("pause");
        }

        jogada(jogador2, 2);

        printaTabuleiro();

        if(verifica(jogador1, jogador2) == 1){
            cout << "Parabens Jogador 1, Voce Ganhou!!!" << endl;
            criaTabuleiro();
            system("pause");
        }else if(verifica(jogador1, jogador2) == 2){
            cout << "Parabens Jogador 2, Voce Ganhou!!!" << endl;
            criaTabuleiro();
            system("pause");
        }
    }

    return 0;
}

void criaTabuleiro(){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
          if(j == 1 || j == 3)
              tabuleiro[i][j] = '|';
          else if(i == 1 || i == 3)
              tabuleiro[i][j] = '-';
          else
              tabuleiro[i][j] = ' ';
        }
    }
}

void printaTabuleiro(){
    int i, j;
    system("cls");
    cout << endl;
    for(i = 0; i < 5; i++){
        cout << "                        ";
        for(j = 0; j < 5; j++){
            cout << tabuleiro[i][j];
        }
        cout << endl;
    }
}

void jogada(char simbolo, int jogador){
    int x, y;
    cout << "Vez do Jogador " << jogador << " (" << simbolo << "). X: ";
    cin >> x;
    cout << "Vez do Jogador " << jogador << " (" << simbolo << "). Y: ";
    cin >> y;

    if((x < 0 || x >= 5) || (y < 0 || y >= 5)){
        cout << "Coordenada Invalida! Tente novamente." << endl;
        jogada(simbolo , jogador);
    }else if(tabuleiro[x][y] != ' '){
        cout << "Coordenada Invalida! Tente novamente." << endl;
        jogada(simbolo , jogador);
    }else
        tabuleiro[x][y] = simbolo;
}

int verifica(char jogadaUm, char jogadaDois){
    int i, j;
    bool velha = true;
    int linUm, colUm, linDois, colDois, diagUm, diagDois;
    linUm = colUm = diagUm = linDois = colDois = diagDois = 0;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(tabuleiro[i][j] == jogadaUm)
                linUm++;
            else if(tabuleiro[i][j] == jogadaDois)
                linDois++;

            if(tabuleiro[j][i] == jogadaUm)
                colUm++;
            else if(tabuleiro[j][i] == jogadaDois)
                colDois++;
            
            if(((i == 0 || i == 4) && (j == 0 || j == 4)) || (i == 2 && j == 2)){
                if(tabuleiro[i][j] == jogadaUm)
                    diagUm++;
                else if(tabuleiro[i][j] == jogadaDois)
                    diagDois++;
            }        

            if(tabuleiro[i][j] == ' ')
                velha = false;

            if(linUm == 3 || colUm == 3 || diagUm == 3)
                return 1;
            else if(linDois == 3 || colDois == 3 || diagDois == 3)
                return 2;

        }
        linUm = colUm = linDois = colDois = 0;
    }
    if(velha){
        cout << "Deu Velha :(" << endl;
        criaTabuleiro();
    }
    return 0;
}
