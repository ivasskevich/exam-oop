#include "HangmanGame.h"

HangmanGame::HangmanGame(const string& filename) : attempts(0), guessedLetters("") {
    srand(time(0));
    encryptedWord = loadRandomWordFromFile(filename);
    secretWord = decryptWord(encryptedWord);
}

int HangmanGame::countWordsInFile(const string& filename) {
    ifstream file(filename);
    int count = 0;
    string word;

    if (!file.is_open()) {
        cout << "Error when uploading a file" << endl;
        exit(0);
    }

    while (getline(file, word)) {
        count++;
    }

    file.close();
    return count;
}

string HangmanGame::loadRandomWordFromFile(const string& filename) {
    int wordCount = countWordsInFile(filename);
    ifstream file(filename);
    string word;
    int randomIndex = rand() % wordCount;

    if (!file.is_open()) {
        cout << "Error when uploading a file" << endl;
        exit(0);
    }

    for (int i = 0; i < randomIndex; i++) {
        getline(file, word);
    }

    file.close();
    return word;
}

string HangmanGame::decryptWord(const string& encryptedWord) {
    string decryptedWord = encryptedWord;
    for (int i = 0; i < decryptedWord.length(); i++) {
        if (isalpha(decryptedWord[i])) {
            decryptedWord[i] = '_';
        }
    }
    return decryptedWord;
}

bool HangmanGame::guessLetter(char guess) {
    bool found = false;
    for (int i = 0; i < encryptedWord.length(); ++i) {
        if (isalpha(encryptedWord[i]) && encryptedWord[i] == guess) {
            secretWord[i] = guess;
            found = true;
        }
    }
    return found;
}

bool HangmanGame::isGameOver() {
    return (attempts == 6);
}

bool HangmanGame::guessLetterAndDisplayHangman(char guess) {
    if (!guessLetter(guess)) {
        guessedLetters += guess;
        attempts++;
        displayHangman(attempts);
    }
    return secretWord == encryptedWord;
}

void HangmanGame::displayGreetingOutput() {
    cout << "Welcome to the game 'Hangman'!" << endl;
    cout << "You have 6 tries to guess the word" << endl;
    cout << "The words related to the names of cities" << endl;
}

void HangmanGame::displaySecretWord() {
    cout << "Word: " << secretWord << endl;
}

void HangmanGame::displayMistakes() {
    cout << "Mistakes (" << attempts << "): " << guessedLetters << endl;
}

void HangmanGame::displayHangman(int attempts) {
    switch (attempts) {
    case 1: cout << "        O" << endl; break;
    case 2: cout << "        O" << endl;
        cout << "        |" << endl; break;
    case 3: cout << "        O" << endl;
        cout << "       /|" << endl; break;
    case 4: cout << "        O" << endl;
        cout << "       /|\\" << endl; break;
    case 5: cout << "        O" << endl;
        cout << "       /|\\" << endl;
        cout << "       /" << endl; break;
    case 6: cout << "        O" << endl;
        cout << "       /|\\" << endl;
        cout << "       / \\" << endl; break;
    }
}

string HangmanGame::getEncryptedWord() {
    return encryptedWord;
}

int HangmanGame::getAttempts() {
    return attempts;
}