#include "Process.h"
#include <cassert>
char Process::g[MAXN];
int Process::n, Process::m, Process::siz;
int Process::U[maxnode], Process::D[maxnode], Process::R[maxnode], Process::L[maxnode], Process::Row[maxnode], Process::Col[maxnode];
int Process::H[MAXN], Process::S[MAXM];
int Process::ansd, Process::ans[MAXN];
int Process::flag;


void  Process::init(int _n, int _m) {
    n = _n;
    m = _m;
    for (int i = 0; i <= m; ++i) {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i] = i - 1;
        R[i] = i + 1;
    }
    assert(_m < maxnode && m > 0);
    R[m] = 0;
    L[0] = m;
    siz = m;
    for (int i = 1; i <= n; ++i) H[i] = -1;
}

void  Process::Link(int r, int c) {
    ++S[Col[++siz] = c];
    Row[siz] = r;
    D[siz] = D[c];
    U[D[c]] = siz;
    U[siz] = c;
    D[c] = siz;
    if (H[r] < 0) H[r] = L[siz] = R[siz] = siz;
    else {
        R[siz] = R[H[r]];
        L[R[H[r]]] = siz;
        L[siz] = H[r];
        R[H[r]] = siz;
    }
}

void  Process::remove(int c) {
    L[R[c]] = L[c], R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i]) {
        for (int j = R[i]; j != i; j = R[j]) {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            --S[Col[j]];
        }
    }
}

void  Process::resume(int c) {
    for (int i = U[c]; i != c; i = U[i])
        for (int j = L[i]; j != i; j = L[j])
            ++S[Col[U[D[j]] = D[U[j]] = j]];
    L[R[c]] = R[L[c]] = c;
}

bool  Process::Dance(int d) {
    if (R[0] == 0) {
        for (int i = 0; i < d; ++i) g[(ans[i] - 1) / len] = (ans[i] - 1) % len + '1';    ///输出的数字
        return true;
    }
    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i])
        if (S[i] < S[c]) c = i;
    remove(c);
    for (int i = D[c]; i != c; i = D[i]) {
        ans[d] = Row[i];
        for (int j = R[i]; j != i; j = R[j]) remove(Col[j]);
        if (Dance(d + 1)) return 1;
        for (int j = L[i]; j != i; j = L[j]) resume(Col[j]);
    }
    resume(c);
    return false;
}
void  Process::place(int& r, int& c1, int& c2, int& c3, int& c4, int i, int j, int k) {
    r = (i * len + j) * len + k;
    c1 = i * len + j + 1;
    c2 = len * len + i * len + k;
    c3 = len * len * 2 + j * len + k;
    c4 = len * len * 3 + ((i / K) * K + (j / K)) * len + k;
}
bool  Process::solve(char(*in)[len + 1])
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
        {
            g[i * len + j] = in[i][j];
        }
    g[len * len] = 0;
    init(len * len * len, len * len * 4);
    int r, c1, c2, c3, c4;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            for (int k = 1; k <= len; ++k) {
                ///根据题目给出的具体形式改动
                if (g[i * len + j] == '$' || g[i * len + j] == '0' + k) {
                    place(r, c1, c2, c3, c4, i, j, k);
                    Link(r, c1);
                    Link(r, c2);
                    Link(r, c3);
                    Link(r, c4);
                }
            }
        }
    }
    if (Dance(0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void  Process::getAns(char(*shudu)[len + 1])
{

    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; j++)
        {
            shudu[i][j] = g[i * len + j];
        }
        shudu[i][len] = 0;
    }
}


void  Process::oneAns(int d) {
    if (flag >= 2) return;
    if (R[0] == 0) {
        //for (int i = 0; i < d; ++i) g[(ans[i] - 1) / lenSD] = (ans[i] - 1) % lenSD + '1';    ///输出的数字
        flag++;
        return;
    }
    int c = R[0];
    for (int i = R[0]; i != 0; i = R[i])
        if (S[i] < S[c]) c = i;
    remove(c);
    for (int i = D[c]; i != c; i = D[i]) {
        ans[d] = Row[i];
        for (int j = R[i]; j != i; j = R[j]) remove(Col[j]);
        oneAns(d + 1);
        for (int j = L[i]; j != i; j = L[j]) resume(Col[j]);
    }
    resume(c);
}
bool Process::checkOneAns(char(*in)[len + 1])
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
        {
            g[i * len + j] = in[i][j];
        }
    g[len * len] = 0;
    init(len * len * len, len * len * 4);
    int r, c1, c2, c3, c4;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            for (int k = 1; k <= len; ++k) {
                ///根据题目给出的具体形式改动
                if (g[i * len + j] == '$' || g[i * len + j] == '0' + k) {
                    place(r, c1, c2, c3, c4, i, j, k);
                    Link(r, c1);
                    Link(r, c2);
                    Link(r, c3);
                    Link(r, c4);
                }
            }
        }
    }
    flag = 0;
    oneAns(0);
    return flag == 1;
}