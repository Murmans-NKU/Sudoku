#include "Verify.h"
bool Verify::verification(int argc, char** argv)
{

    sudokuCount = 0;
    sudokuFilePath = "";
    gameCount = 0;
    gameDifficulty = 0;
    emptyCellsMin = 0;
    emptyCellsMax = 0;
    uniqueSolution = false;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            char option = argv[i][1];

            switch (option) {
            case 'c':
                if (i + 1 < argc) {
                    sudokuCount = std::atoi(argv[i + 1]);
                    if (sudokuCount < 1 || sudokuCount > 1000000) {
                        std::cout << "Invalid Sudoku count. Allowed range: 1-1000000." << "\n";
                        return false;
                    }
                }
                else {
                    std::cout << "Missing argument for option -c." << "\n";
                    return false;
                }
                break;
            case 's':
                if (i + 1 < argc) {
                    sudokuFilePath = argv[i + 1];
                }
                else {
                    std::cout << "Missing argument for option -s." << "\n";
                    return false;
                }
                break;
            case 'n':
                if (i + 1 < argc) {
                    gameCount = std::atoi(argv[i + 1]);
                    if (gameCount < 1 || gameCount > 10000) {
                        std::cout << "Invalid game count. Allowed range: 1-10000." << "\n";
                        return false;
                    }
                }
                else {
                    std::cout << "Missing argument for option -n." << "\n";
                    return false;
                }
                break;
            case 'm':
                if (i + 1 < argc) {
                    gameDifficulty = std::atoi(argv[i + 1]);
                    if (gameDifficulty < 1 || gameDifficulty > 3) {
                        std::cout << "Invalid game difficulty. Allowed range: 1-3." << "\n";
                        return false;
                    }
                }
                else {
                    std::cout << "Missing argument for option -m." << "\n";
                    return false;
                }
                break;
            case 'r':
                if (i + 1 < argc) {
                    std::string rangeArg = argv[i + 1];
                    std::istringstream iss(rangeArg);
                    char separator;
                    iss >> emptyCellsMin >> separator >> emptyCellsMax;
                    if (iss.fail() || separator != '-' || emptyCellsMin < 20 || emptyCellsMax > 55 || emptyCellsMin > emptyCellsMax) {
                        std::cout << "Invalid empty cells range. Allowed range: 20-55. Format: min-max." << "\n";
                        return false;
                    }
                }
                else {
                    std::cout << "Missing argument for option -r." << "\n";
                    return false;
                }
                break;
            case 'u':
                uniqueSolution = true;
                break;
            default:
                std::cout << "Unknown option: " << option << "\n";
                return false;
            }
        }
    }
    if (uniqueSolution || gameDifficulty || emptyCellsMin)
        if (!gameCount)
        {
            std::cout << "Missing Option for option -n." << "\n";
            return false;
        }


    return true;
}
