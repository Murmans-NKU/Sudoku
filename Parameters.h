#pragma once
#define len 9
#define K 3
#define inf 0x3f3f3f3f
#define mod 1000000000 + 7
#define OUTFILENAME "out.txt"
#include <string>
bool readSudokuFromFile(const std::string& filename, char(*sudoku)[len + 1]);
bool putSudokuToFile(char(*sudoku)[len + 1]);