#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
string colorsForPlayer[3] = {"\033[31m", "\033[36m", "\033[0m"};
char players[2] = {'X', 'O'};
int currentPlayer = 0;


string getColorForPlayer(char player){
    if (player == 'X'){
        return colorsForPlayer[0];
    }else if (player == 'O'){
        return colorsForPlayer[1];
    }else {
        return colorsForPlayer[2];
    }
}


void showBoard(){

    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        string color1 = getColorForPlayer(board[i][0]);
        string color2 = getColorForPlayer(board[i][1]);
        string color3 = getColorForPlayer(board[i][2]);
        cout << color1 <<"  " << board[i][0] << "\033[0m  |  " << color2 << board[i][1] << "\033[0m  |  " << color3 << board[i][2] << "\033[0m  \n";
        if (i < 2){
            cout << "_____|_____|_____\n     |     |     \n";
        }
    }
    cout << "     |     |     \n";
}


void CaptureResponse(){
    cout << getColorForPlayer(players[currentPlayer]) <<"Selecciona tu posición: \033[0m";
    int position;
    cin >> position;

    if (position < 1 || position > 9){
        cout << "\033[101m [Error] la posicion [" << position << "] es una posicion invalida, por favor ingresar una posicion en el rango [1 a 9]\033[0m\n";
        CaptureResponse();
    }else{
        int row = (position - 1) / 3;
        int colum = (position - 1) % 3;

        if (board[row][colum] == 'X' || board[row][colum] == 'O'){
            cout << "\033[101m [Error] la posicion [" << position << "] es una posicion ocupada, por favor ingresar una posicion disponible\033[0m\n";
            CaptureResponse();
        }else{
            board[row][colum] = players[currentPlayer];
        }
    }
}


int isGameFinished(){
    int answer = 0;
    int i = 0;

    while (answer == 0 && i < 3)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            if (board[i][0] == 'X'){
                answer = 1;
            }else{
                answer = 2;
            }
        }else if (board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            if (board[0][i] == 'X'){
                answer = 1;
            }else{
                answer = 2;
            }
        }
        i++;
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        if (board[0][0] == 'X'){
            answer = 1;
        }else{
            answer = 2;
        }
    }else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        if (board[0][2] == 'X'){
            answer = 1;
        }else{
            answer = 2;
        }
    }

    bool isDraw = true;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] != 'X' && board[i][j] != 'O'){
                isDraw = false;
            }
        }
    }

    if (isDraw){
        answer = 3;
    }

    return answer;
}


int main(){
    bool isFinished = false;
    int result;

    cout << "\033[35m el juego ha comenzado :D! \033[0m\n";

    while (!isFinished){
        showBoard();
        cout << getColorForPlayer(players[currentPlayer]) << "Es el turno de [" << players[currentPlayer] << "]\033[0m\n";
        CaptureResponse();
        currentPlayer = (currentPlayer == 0) ? 1 : 0;
        result = isGameFinished();
        if (result != 0){
            isFinished = true;
        }
    }

    showBoard();

    cout << "\033[104mJuego Finalizado!\033[0m\n";
    if (result != 3){
        cout << "\033[35m El ganador es el jugador [" << players[result - 1] << "]\033[0m" << endl;;
    }else{
        cout << "\033[33m Empate lol! \033[0m" << endl;
    }

    return 0;
}