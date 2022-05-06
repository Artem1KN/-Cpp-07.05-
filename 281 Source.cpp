#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int k = 1;
    int n, m;
    fin >> n >> m;
    long long num = 1;
    long long denum = 1;
    

    for (int i = 1; n != m; n--, i++)
    {
        num *= n;
        denum *= i;
        k += (int)(num / denum);
    }

    fout << k << endl;

    return 0;
}