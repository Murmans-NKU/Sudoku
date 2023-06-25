#include "Parameters.h"
#include <cstring>
#include <fstream>

bool readSudokuFromFile(const std::string& filename, char(*sudoku)[len + 1]) {
    std::ifstream file(filename);
    if (!file) {
        return false;
    }

    for (int i = 0; i < len; ++i) {
        file >> sudoku[i];
    }

    file.close();
    return true;
}

bool putSudokuToFile(char(*sudoku)[len + 1]) {
    std::ofstream file(OUTFILENAME, std::ios::app);

    for (int j = 0; j < len; ++j) {
        file << sudoku[j] << "\n";
    }
    file << "\n";

    file.close();
    return true;
}
