#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, M;
    fin >> N >> M;
    vector<pair<int, int>> road(N);
    int Di, Li, Hi;
    int roadLength = 0;
    for (int i = 0; i < N; i++)
    {
        fin >> Di >> Li >> Hi;
        road[i] = pair<int, int>(min(Li, M), Hi);
        roadLength += Di;
    }
    sort(road.begin(), road.end());

    int speed = road[0].first;
    int amountH = 0;
    double minTime = INT32_MAX;
    for (auto segment : road)
    {
        if (1.0 * roadLength / segment.first + amountH <= minTime)
        {
            minTime = 1.0 * roadLength / segment.first + amountH;
            speed = segment.first;
        }
        amountH += segment.second;
    }

    fout << speed << endl;

    return 0;
}