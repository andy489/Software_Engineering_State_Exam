#include <iostream>     /* cout */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <map>
#include <set>

using namespace std;

string str_gen(int n, string a) {
    string s;
    for (int i = 0; i < n; ++i) { s += a; }
    return s;
}

int numSpaces(int a) {
    if (a % 1000 == 0) { return 6; }
    else if (a % 100 == 0) { return 5; }
    else if (a % 10 == 0) { return 4; }
    return 3;
}

bool check(map<int, multiset<int>> &histogram) {
    for (map<int, multiset<int>>::const_iterator it = histogram.begin(); it != histogram.end(); ++it) {
        if (!it->second.empty()) { return true; }
    }
    return false;
}

int main() {
    const int SIZE = 27, BOUND = 4900, INTERVALS = 5;
    int arr[SIZE];

    srand(time(nullptr));
    for (int &i: arr) { i = rand() % BOUND + 1; }

    map<int, multiset<int>> histogram;
    for (int i = 0; i < INTERVALS; ++i) { histogram[i]; }

    bool indicatorsEmpty[INTERVALS];
    fill(begin(indicatorsEmpty), end(indicatorsEmpty), true);

    for (int r: arr) {
        int intervalNum = r / 1'000;
        histogram[intervalNum].insert(r);
        indicatorsEmpty[intervalNum] = false;
    }

    cout << "Под 1    Под 2    Под 3    Под 4    Под 5" << endl;
    while (check(histogram)) {
        for (int i = 0; i < INTERVALS; ++i) {
            if (histogram[i].empty()) { cout << str_gen(9, " "); }
            else {
                auto it = histogram[i].begin();
                cout << " " << *it / 1000.0 << str_gen(numSpaces(*it), " ");
                histogram[i].erase(it);
            }
        }
        cout << endl;
    }

    return 0;
}
