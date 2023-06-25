#pragma once
#include <cstring>
#include <iostream>
#include <sstream>

class Verify {
public:
    int sudokuCount = 0;
    std::string sudokuFilePath;
    int gameCount = 0;
    int gameDifficulty = 0;
    int emptyCellsMin = 0;
    int emptyCellsMax = 0;
    bool uniqueSolution = false;

    Verify() {}
    bool verification(int argc, char** argv);
};