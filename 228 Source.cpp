#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N; 
    double amount = 100;
    double dollar, euro, newdollar, neweuro;

    fin >> N >> dollar >> euro;

    for (int i = 0; i < N - 1; i++)
    {
        fin >> newdollar >> neweuro;
        amount *= max(1.0, max(newdollar / dollar, neweuro / euro));
        dollar = newdollar;
        euro = neweuro;
    }

    fout << fixed << amount << endl;

    return 0;
}