#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string str;
    long long longk;
    fin >> str >> longk;
    long long longn = 0;

    for (char digit : str)
        longn = (longn * 10 + (int)(digit - 48)) % longk;

    fout << longn << endl;

    return 0;
}