#pragma once

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

class DisplayInformation {
public:
    virtual void displayGreetingOutput() = 0;
    virtual void displaySecretWord() = 0;
    virtual void displayMistakes() = 0;
    virtual void displayHangman(int attempts) = 0;
};