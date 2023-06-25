#include "InitEnd.h"
#include "Process.h"

void InitEnd::createRange(int minE, int maxE, char(*suduZJ)[len + 1])
{

    int Enum = rand() % (maxE - minE + 1) + minE;

    for (int i = 0; i < Enum; i++)
    {
        randomW1(suduZJ);
    }

}

void InitEnd::createDifficult(int gameDifficulty, char(*suduZJ)[len + 1])
{
    if (gameDifficulty == 1)
    {
        createRange(20, 31, suduZJ);
    }
    else if (gameDifficulty == 2)
    {
        createRange(32, 43, suduZJ);
    }
    else if (gameDifficulty == 3)
    {
        createRange(44, 55, suduZJ);
    }
}

void InitEnd::createUnique(char(*suduZJ)[len + 1])
{
    int Enum = rand() % (55 - 20 + 1) + 20;
    char newSuduZJ[len + 1][len + 1];
    for (int i = 0; i < Enum; i++)
    {
        for (int a = 0; a < len; a++)
        {
            for (int b = 0; b < len; b++)
            {
                newSuduZJ[a][b] = suduZJ[a][b];
            }
        }
        randomW1(newSuduZJ);
        if (!Process::checkOneAns(newSuduZJ))
        {
            return;
        }
        for (int a = 0; a < len; a++)
        {
            for (int b = 0; b < len; b++)
            {
                suduZJ[a][b] = newSuduZJ[a][b];
            }
        }

    }
}

void InitEnd::randomW1(char(*suduZJ)[len + 1])
{

    while (true)
    {
        int x, y;
        x = rand() % 9;
        y = rand() % 9;
        if (suduZJ[x][y] != '$')
        {
            suduZJ[x][y] = '$';
            return;
        }
    }
}

void InitEnd::generateN(int n)
{
    char temp[len + 1][len + 1];
    int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };
    for (int i = 0; i < 6 && n; i++)
    {
        if (i)
        {
            std::next_permutation(shift + 3, shift + 6);
            shift[6] = 2, shift[7] = 5, shift[8] = 8;
        }
        for (int j = 0; j < 6 && n; j++)
        {
            if (j) std::next_permutation(shift + 6, shift + 9);
            char row[10] = "123456789";
            for (int k = 0; k < 40320 && n; k++)
            {
                if (k) std::next_permutation(row + 1, row + 9);


                for (int r = 0; r < 9; r++)
                {
                    for (int c = 0; c < 9; c++)
                        temp[r][c] = row[(c + shift[r]) % 9];
                    temp[r][len] = 0;
                }

                putSudokuToFile(temp);

                --n;
            }
        }
    }
}
void InitEnd::random1(char(*sudoku)[len + 1])
{
    int shift[9] = { 0, 3, 6, 1, 4, 7, 2, 5, 8 };

    int maxi = rand() % 6, maxj = rand() % 6, maxk = ((rand() * rand()) % 40320 + 40320) % 40320;
    char row[10] = "123456789";
    for (int i = 0; i < maxi; i++)
    {
        if (i)
        {
            std::next_permutation(shift + 3, shift + 6);
            shift[6] = 2, shift[7] = 5, shift[8] = 8;
        }
        for (int j = 0; j < maxj; j++)
        {
            if (j) std::next_permutation(shift + 6, shift + 9);

            for (int k = 0; k < maxk; k++)
            {
                if (k) std::next_permutation(row + 1, row + 9);

            }
        }
    }
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            sudoku[r][c] = row[(c + shift[r]) % 9];
        }
    }
}
