#include <iostream>
using namespace std;

char board[3][3];  // Tic-Tac-Toe board
char currentPlayer = 'X';  // Current player ('X' or 'O')

void initializeBoard() {
    // Fill the board with numbers 1-9 to represent empty spaces
    int counter = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = '0' + counter++;
}

void displayBoard() {
    // Display the current state of the board
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--|---|--\n";
    }
    cout << "\n";
}

bool isValidMove(int move) {
    // Check if the move is valid (within bounds and on an empty spot)
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O';
}

void makeMove(int move) {
    // Update the board with the current player's move
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = currentPlayer;
}

bool checkWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
    for (int i = 0; i < 3; ++i)
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool checkDraw() {
    // Check if all spots are filled without a winner
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    // Switch the current player
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    initializeBoard();
    int move;

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (isValidMove(move)) {
            makeMove(move);

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();  // Switch turns
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

