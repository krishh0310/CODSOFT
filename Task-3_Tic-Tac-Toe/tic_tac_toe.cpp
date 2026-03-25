#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

class TicTacToe {
public:
    TicTacToe() : board{}, current_player('X') {}

    void play() {
        while (true) {
            print_board();
            make_move();
            if (check_winner()) {
                print_board();
                cout << "Player '" << current_player << "' wins!\n";
                break;
            }
            if (is_full()) {
                print_board();
                cout << "Draw!\n";
                break;
            }
            current_player = (current_player == 'X') ? 'O' : 'X';
        }
    }

private:
    array<array<char, 3>, 3> board;
    char current_player;

    void print_board() const {
        for (const auto& row : board) {
            for (char cell : row) {
                cout << (cell ? cell : '-') << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void make_move() {
        int row, col;
        while (true) {
            cout << "Player '" << current_player << "' (row col): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && !board[row][col]) {
                board[row][col] = current_player;
                break;
            }
            cout << "Invalid move!\n";
        }
    }

    bool check_winner() const {
        //  rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player) ||
                (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)) {
                return true;
            }
        }
        // diagonals
        return (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player) ||
               (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player);
    }

    bool is_full() const {
        for (const auto& row : board)
            if (any_of(row.begin(), row.end(), [](char c) { return !c; }))
                return false;
        return true;
    }
};

int main() {
    TicTacToe().play();
    return 0;
}
