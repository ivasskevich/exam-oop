#include "HangmanGame.h"
#include "DisplayInformation.h"

using namespace std;

int main() {
    HangmanGame game("words.txt");

    time_t startTime = time(nullptr);
    int numberOfAttempts = 0;

    game.displayGreetingOutput();

    while (!game.isGameOver()) {

        game.displaySecretWord();
        game.displayMistakes();

        numberOfAttempts++;

        char guess;
        cout << "Letter: ";
        cin >> guess;
        cout << endl;

        if (game.guessLetterAndDisplayHangman(guess)) {
            cout << "Congratulations, you guessed the word: " << game.getEncryptedWord() << endl;
            break;
        }
    }

    if (game.getAttempts() == 6) {
        cout << "Game over. You didn't guess the word. The word you guessed was: " << game.getEncryptedWord() << endl;
    }

    time_t endTime = time(nullptr);
    int elapsedTime = static_cast<int>(endTime - startTime);
    cout << "Time: " << elapsedTime << " seconds" << endl;
    game.displayMistakes();
    cout << "Number of attempts: " << numberOfAttempts << endl;

    return 0;
}