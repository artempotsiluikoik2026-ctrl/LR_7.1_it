//ЛР 7.1 іт

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** Q, const int rowCount, const int colCount);
void Sort(int** Q, const int rowCount, const int colCount);
void Change(int** Q, const int col1, const int col2, const int rowCount);
void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 62;
    int rowCount = 7;
    int colCount = 6;

    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Q[i] = new int[colCount];

    Create(Q, rowCount, colCount, Low, High);
    Print(Q, rowCount, colCount);

    Sort(Q, rowCount, colCount);
    Print(Q, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(Q, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(Q, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;

    return 0;
}

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            Q[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** Q, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << Q[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** Q, const int col1, const int col2, const int rowCount)
{
    int t;
    for (int i = 0; i < rowCount; i++)
    {
        t = Q[i][col1];
        Q[i][col1] = Q[i][col2];
        Q[i][col2] = t;
    }
}

void Sort(int** Q, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((Q[0][j1] < Q[0][j1 + 1])
                ||
                (Q[0][j1] == Q[0][j1 + 1] &&
                    Q[1][j1] > Q[1][j1 + 1])
                ||
                (Q[0][j1] == Q[0][j1 + 1] &&
                    Q[1][j1] == Q[1][j1 + 1] &&
                    Q[2][j1] > Q[2][j1 + 1]))
                Change(Q, j1, j1 + 1, rowCount);
}

void Calc(int** Q, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (Q[i][j] % 2 == 0 && !((i + j) % 8 == 0))
            {
                S += Q[i][j];
                k++;
                Q[i][j] = 0;
            }
}