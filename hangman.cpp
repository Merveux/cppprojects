
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));

    // List of words
    string words[] = {
        "apple", "teacher", "computer",
        "school", "programming", "keyboard",
        "internet", "science", "football",
        "friend" 
    };

    int numberOfWords = 10;

    char playAgain = 'y';

    cout << "==============================" << endl;
    cout << "       WELCOME TO HANGMAN     " << endl;
    cout << "==============================" << endl;

    // Start game
    while (playAgain == 'y' || playAgain == 'Y') {

        // STEP 1: SELECT DIFFICULTY FIRST

        int difficulty;
        int maxAttempts;

        cout << "\nSELECT YOUR DIFFICULTY LEVEL" << endl;
        cout << "1. EASY   (10 attempts)" << endl;
        cout << "2. MEDIUM (6 attempts)" << endl;
        cout << "3. HARD   (4 attempts)" << endl;

        cout << "\nEnter your choice: ";
        cin >> difficulty;

        // Validate difficulty
        while (difficulty < 1 || difficulty > 3) {

            cout << "Invalid choice! Please enter 1, 2, or 3: ";
            cin >> difficulty;
        }

        // Set difficulty
        if (difficulty == 1) {
            maxAttempts = 10;
            cout << "\nYou selected EASY!" << endl;
        }
        else if (difficulty == 2) {
            maxAttempts = 6;
            cout << "\nYou selected MEDIUM!" << endl;
        }
        else {
            maxAttempts = 4;
            cout << "\nYou selected HARD!" << endl;
        }

        int attemptsLeft = maxAttempts;

        // STEP 2: SELECT RANDOM WORD

        int randomIndex = rand() % numberOfWords;

        string secretWord = words[randomIndex];

        // STEP 3: HIDE THE WORD

        string hiddenWord = "";

        for (int i = 0; i < secretWord.length(); i++) {
            hiddenWord += "_";
        }

        // STEP 4: CREATE GUESS VARIABLES

        string guessedLetters = "";
        string incorrectGuesses = "";

        char guess;

        cout << "\nGame starting..." << endl;

        // STEP 5: MAIN GAME LOOP

        while (attemptsLeft > 0 && hiddenWord != secretWord) {

            // DISPLAY HANGMAN

            cout << "\n";
            cout << "  +---+" << endl;
            cout << "  |   |" << endl;

            if (attemptsLeft <= maxAttempts - 1)
                cout << "  |   O" << endl;
            else
                cout << "  |" << endl;

            if (attemptsLeft <= maxAttempts - 2)
                cout << "  |   |" << endl;
            else
                cout << "  |" << endl;

            if (attemptsLeft <= maxAttempts - 3)
                cout << "  |  /|\\" << endl;
            else if (attemptsLeft <= maxAttempts - 2)
                cout << "  |  /" << endl;
            else
                cout << "  |" << endl;

            if (attemptsLeft <= maxAttempts - 4)
                cout << "  |  / \\" << endl;
            else
                cout << "  |" << endl;

            cout << "  |" << endl;
            cout << "__|__" << endl;

            // DISPLAY CURRENT WORD

            cout << "\nWord: ";

            for (int i = 0; i < hiddenWord.length(); i++) {
                cout << hiddenWord[i] << " ";
            }

            cout << "\nIncorrect guesses: "
                 << incorrectGuesses << endl;

            cout << "Guesses left: "
                 << attemptsLeft << endl;

            // ASK PLAYER TO GUESS

            cout << "\nGuess a letter: ";
            cin >> guess;

            // CHECK VALID INPUT

            if (!((guess >= 'a' && guess <= 'z') ||
                  (guess >= 'A' && guess <= 'Z'))) {

                cout << "Invalid input! Enter a letter." << endl;
                continue;
            }

            // CONVERT UPPERCASE TO LOWERCASE

            if (guess >= 'A' && guess <= 'Z') {
                guess = guess + 32;
            }

            // CHECK IF LETTER WAS ALREADY GUESSED

            if (guessedLetters.find(guess) != string::npos) {

                cout << "You already guessed this letter!" << endl;
                continue;
            }

            guessedLetters += guess;

            // CHECK IF LETTER IS IN THE SECRET WORD

            bool correct = false;

            for (int i = 0; i < secretWord.length(); i++) {

                if (secretWord[i] == guess) {

                    hiddenWord[i] = guess;
                    correct = true;
                }
            }

            // HANDLE THE GUESS

            if (correct) {

                cout << "Correct guess!" << endl;

            }
            else {

                cout << "Wrong guess!" << endl;

                incorrectGuesses += guess;
                incorrectGuesses += " ";

                attemptsLeft--;
            }

        }

        // STEP 6: DISPLAY FINAL HANGMAN

        cout << "\n";

        cout << "  +---+" << endl;
        cout << "  |   |" << endl;

        if (attemptsLeft <= maxAttempts - 1)
            cout << "  |   O" << endl;
        else
            cout << "  |" << endl;

        if (attemptsLeft <= maxAttempts - 2)
            cout << "  |   |" << endl;
        else
            cout << "  |" << endl;

        if (attemptsLeft <= maxAttempts - 3)
            cout << "  |  /|\\" << endl;
        else
            cout << "  |" << endl;

        if (attemptsLeft <= maxAttempts - 4)
            cout << "  |  / \\" << endl;
        else
            cout << "  |" << endl;

        cout << "  |" << endl;
        cout << "__|__" << endl;

        // STEP 7: CHECK WIN OR LOSS

        cout << "\n==============================" << endl;

        if (hiddenWord == secretWord) {

            cout << "CONGRATULATIONS! YOU WON!" << endl;

            cout << "The correct word was: "
                 << secretWord << endl;

        }
        else {

            cout << "GAME OVER! YOU LOST!" << endl;

            cout << "The correct word was: "
                 << secretWord << endl;
        }

        cout << "==============================" << endl;

        // STEP 8: PLAY ANOTHER ROUND

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    }

    cout << "\nThank you for playing Hangman!" << endl;

    return 0;
}
