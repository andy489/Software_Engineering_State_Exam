#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define SIZE 11
#define eb emplace_back
#define f first
#define s second

vector<pair<int, int>> getSymGroup(int x, int y) {
    vector<pair<int, int>> symGroup;

    symGroup.eb(x, y);
    symGroup.eb(SIZE - x - 1, SIZE - y - 1); // center

    if (x != y && x + y != SIZE - 1) {
        symGroup.eb(SIZE - y - 1, SIZE - x - 1); // primary
        symGroup.eb(y, x); // secondary
    }

    return symGroup;
}

double **change(const double matrix[SIZE][SIZE]) {
    double **updatedMatrix = new double *[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        updatedMatrix[i] = new double[SIZE];
    }

    for (int i = 0; i <= SIZE >> 1; ++i) {
        for (int j = 0; j < SIZE - i; ++j) {
            vector<pair<int, int>> symmetricGroup = getSymGroup(i, j);

            double avg = 0.0f;

            for (pair<int, int> p: symmetricGroup) {
                avg += matrix[p.f][p.s];
            }

            if (!symmetricGroup.empty()) {
                avg /= (double) symmetricGroup.size();
            }

            for (pair<int, int> p: symmetricGroup) {
                updatedMatrix[p.f][p.s] = avg;
            }
        }
    }

    return updatedMatrix;
}

int main() {
    double matrix[SIZE][SIZE] = {
            {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1, 2, 3},
            {2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 2, 3, 4},
            {3.1, 4.2, 5.3, 6.4, 7.5, 8.6, 9.7, 1.8, 3, 4, 5},
            {4.1, 5.2, 6.3, 7.4, 8.5, 9.6, 1.7, 2.8, 4, 5, 6},
            {5.1, 6.2, 7.3, 8.4, 9.5, 1.6, 2.7, 3.8, 5, 6, 7},
            {6.1, 7.2, 8.3, 9.4, 1.5, 2.6, 3.7, 4.8, 6, 7, 8},
            {7.1, 8.2, 9.3, 1.4, 2.5, 3.6, 4.7, 5.8, 7, 8, 9},
            {8.1, 9.2, 1.3, 2.4, 3.5, 4.6, 5.7, 6.8, 8, 9, 1},
            {9.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 9, 1, 2},
            {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1, 2, 3},
            {2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 2, 3, 4},
    };

    double **updatedMatrix = change(matrix);

    cout << setprecision(2);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << updatedMatrix[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;
}
