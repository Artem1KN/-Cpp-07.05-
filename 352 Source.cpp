#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int maxd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N;
    fin >> N;
    for (int i = N / 2; i > 0; i--)
        if (maxd(i, N - i) == 1)
            fout << i << ' ' << N - i << endl;

    return 0;
}