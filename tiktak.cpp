
#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char board[]) {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "     |     |     \n";
    cout << "\n";
}

// Function to check if a player has won
bool checkWinner(char board[], char player) {

    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player &&
            board[i + 1] == player &&
            board[i + 2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == player &&
            board[i + 3] == player &&
            board[i + 6] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == player &&
        board[4] == player &&
        board[8] == player) {
        return true;
    }

    if (board[2] == player &&
        board[4] == player &&
        board[6] == player) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool checkDraw(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }

    return true;
}

// Function to play one game
void playGame() {

    // Create an array for the game board
    char board[9] = {'1', '2', '3',
                     '4', '5', '6',
                     '7', '8', '9'};

    char player = 'X';
    int choice;

    cout << "\n===== TIC-TAC-TOE GAME =====\n";

    // Display the empty board
    displayBoard(board);

    // Continue playing until someone wins or the game is a draw
    while (true) {

        cout << "Player " << player;
        cout << ", enter a number (1-9): ";
        cin >> choice;

        // Validate the user's input
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";

            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        // Check if the number is between 1 and 9
        if (choice < 1 || choice > 9) {
            cout << "Invalid choice! Please choose between 1 and 9.\n";
            continue;
        }

        // Check if the selected cell is already occupied
        if (board[choice - 1] == 'X' ||
            board[choice - 1] == 'O') {
            cout << "That position is already taken! Try again.\n";
            continue;
        }

        // Place the player's symbol on the board
        board[choice - 1] = player;

        // Display the updated board
        displayBoard(board);

        // Check if the current player has won
        if (checkWinner(board, player)) {
            cout << "Congratulations! Player " << player << " wins!\n";
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board)) {
            cout << "The game is a DRAW!\n";
            break;
        }

        // Switch players
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }
}

// Main function
int main() {

    char replay;

    do {
        // Start a new game
        playGame();

        // Ask players if they want to play again
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThank you for playing Tic-Tac-Toe!\n";

    return 0;
}
