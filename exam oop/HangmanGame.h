#pragma once

#include "DisplayInformation.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

class HangmanGame : public DisplayInformation {
private:
    string encryptedWord;
    string secretWord;
    int attempts;
    string guessedLetters;

public:
    HangmanGame(const string& filename);
    int countWordsInFile(const string& filename);
    string loadRandomWordFromFile(const string& filename);
    string decryptWord(const string& encryptedWord);
    bool guessLetter(char guess);
    bool isGameOver();
    bool guessLetterAndDisplayHangman(char guess);
    void displayGreetingOutput();
    void displaySecretWord();
    void displayMistakes();
    void displayHangman(int attempts);
    string getEncryptedWord();
    int getAttempts();
};