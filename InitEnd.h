#pragma once
#include "Verify.h"
#include "Parameters.h"
#include "Process.h"
#include <iostream>
#include <algorithm>
#include <cstring>
class InitEnd
{
public:
	static void createRange(int minE, int maxE, char(*suduZJ)[len + 1]);
	static void createDifficult(int gameDifficulty, char(*suduZJ)[len + 1]);
	static void createUnique(char(*suduZJ)[len + 1]);
	static void generateN(int n);
	void static random1(char(*sudoku)[len + 1]);
private:
	static void randomW1(char(*suduZJ)[len + 1]);
};