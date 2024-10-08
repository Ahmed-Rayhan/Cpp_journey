#include <iostream>
#include <limits>
using namespace std;

const int SIZE = 3;

// Function to initialize the Tic-Tac-Toe board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic-Tac-Toe board
void displayBoard(const char board[SIZE][SIZE]) {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool hasWon(const char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool isBoardFull(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to get the current player's move
void getPlayerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Validate input
        if (cin.fail() || row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid move. Please try again.\n";
        } else {
            break;
        }
    }
    board[row][col] = player;
}

// Function to switch the player
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!\n";

    // Main game loop
    while (true) {
        displayBoard(board);
        getPlayerMove(board, currentPlayer);

        // Check for a win
        if (hasWon(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = switchPlayer(currentPlayer);
    }

    return 0;
}
