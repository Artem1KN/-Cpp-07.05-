#include <iostream>
#include <fstream>

using namespace std;

long defaultval = -INT64_MAX;
long vals[21][21][21];

long funktion(long a, long b, long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
    {
        if (vals[20][20][20] == defaultval)
            vals[20][20][20] = funktion(20, 20, 20);
        return vals[20][20][20];
    }
    else
    {
        if (vals[a][b][c] == defaultval)
        {
            if (a < b && b < c)
                vals[a][b][c] = funktion(a, b, c - 1) + funktion(a, b - 1, c - 1) - funktion(a, b - 1, c);
            else
                vals[a][b][c] = funktion(a - 1, b, c) + funktion(a - 1, b - 1, c) + funktion(a - 1, b, c - 1) - funktion(a - 1, b - 1, c - 1);
        }
        return vals[a][b][c];
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            for (int k = 0; k < 21; k++)
                vals[i][j][k] = defaultval;

    long a, b, c;
    fin >> a >> b >> c;
    fout << funktion(a, b, c) << endl;
    return 0;
}