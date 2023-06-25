#pragma once
#include <iostream>
#include "Parameters.h"

const int MAXN = len * len * len + 10;
const int MAXM = len * len * 4 + 10;
const int maxnode = MAXN * 4 + MAXM + 10;
class Process
{
    static int flag;
    static char g[MAXN];
    static int n, m, siz;
    static int U[maxnode], D[maxnode], R[maxnode], L[maxnode], Row[maxnode], Col[maxnode];
    static int H[MAXN], S[MAXM];
    static int ansd, ans[MAXN];
public:
    void static init(int _n, int _m);
    void static Link(int r, int c);
    void static remove(int c);
    void static resume(int c);
    bool static Dance(int d);
    static void  place(int& r, int& c1, int& c2, int& c3, int& c4, int i, int j, int k);
    bool static solve(char(*in)[len + 1]);
    void static getAns(char(*)[len + 1]);

    void static oneAns(int d);
    static bool checkOneAns(char(*in)[len + 1]);
};