#include <iostream>
#include <fstream>
#include <cstdlib> // 包含atoi函数，用于将字符串转换为整数
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime> 
#include <vector>
#include "Verify.h"
#include "Parameters.h"
#include "Process.h"
#include "InitEnd.h"

using namespace std;
char g[len + 1][len + 1];

int main(int argc, char* argv[]) {

    srand(static_cast<unsigned int>(time(NULL)));
    std::ofstream file(OUTFILENAME, ios::trunc);

    Verify arg;
    if (!arg.verification(argc, argv))
        return 1;
    if (arg.sudokuFilePath != "")
    {

        if (readSudokuFromFile(arg.sudokuFilePath, g))
        {
            if (Process::solve(g))
            {

                Process::getAns(g);
                putSudokuToFile(g);
            }
        }
        else
        {
            std::cout << "�޷��򿪣�" << arg.sudokuFilePath << std::endl;

        }
    }
    else if (arg.sudokuCount)
    {
        InitEnd::generateN(arg.sudokuCount);
    }
    else if (arg.gameCount)
    {
        if (arg.gameDifficulty)
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                InitEnd::random1(g);
                InitEnd::createDifficult(arg.gameDifficulty, g);
                putSudokuToFile(g);
            }
        }
        else if (arg.uniqueSolution)
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                InitEnd::random1(g);
                InitEnd::createUnique(g);
                putSudokuToFile(g);
            }
        }
        else if (arg.emptyCellsMin)
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                InitEnd::random1(g);
                InitEnd::createRange(arg.emptyCellsMin, arg.emptyCellsMax, g);
                putSudokuToFile(g);
            }
        }
        else
        {
            for (int i = 0; i < arg.gameCount; i++)
            {
                InitEnd::random1(g);
                InitEnd::createRange(20, 55, g);
                putSudokuToFile(g);
            }

        }
    }
}

