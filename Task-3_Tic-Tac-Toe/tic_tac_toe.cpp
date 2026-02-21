#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "\n";
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "--+---+--" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "--+---+--" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "\n";
}

bool checkWin(char board[3][3], char player) {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

int main() {

    char playAgain;

    do {
        char board[3][3] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
        };

        char currentPlayer = 'X';
        int choice;
        int row, col;

        while (true) {

            displayBoard(board);

            cout << "Player " << currentPlayer << ", enter position (1-9): ";
            cin >> choice;

            row = (choice - 1) / 3;
            col = (choice - 1) % 3;

            if (choice < 1 || choice > 9 ||
                board[row][col] == 'X' ||
                board[row][col] == 'O') {

                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                cout << "Game is a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
