#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void printNumbers(int row, float arr[27], int &i) {
    if (arr[row] - 0 < 1e-6) {
        cout << "        ";
        return;
    }

    cout << right << setw(8) << fixed << setprecision(4) << arr[row];
    i++;
}

void rng() {
    srand(time(nullptr));
    float A[27];

    for (float &i: A) {
        i = ((float) rand() / RAND_MAX) * 4.9;
    }

    float a1[27], a2[27], a3[27], a4[27], a5[27];
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;

    for (float i: A) {
        if (i >= 0 && i < 1) {
            a1[i1++] = i;
        } else if (i >= 1 && i < 2) {
            a2[i2++] = i;
        } else if (i >= 2 && i < 3) {
            a3[i3++] = i;
        } else if (i >= 3 && i < 4) {
            a4[i4++] = i;
        } else {
            a5[i5++] = i;
        }
    }

    const short WIDTH = 12;
    cout << left << setw(WIDTH) << "Под 1"
         << setw(WIDTH) << "Под 2"
         << setw(WIDTH) << "Под 3"
         << setw(WIDTH) << "Под 4"
         << setw(WIDTH) << "Под 5" << endl;

    int i = 0, row = 0;
    while (i < 27) {
        printNumbers(row, a1, i);
        printNumbers(row, a2, i);
        printNumbers(row, a3, i);
        printNumbers(row, a4, i);
        printNumbers(row, a5, i);
        cout << endl;
        row++;
    }
}

int main() {
    rng();
    return 0;
}