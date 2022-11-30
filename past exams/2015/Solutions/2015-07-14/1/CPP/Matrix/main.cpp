#include <iostream>
#include <iomanip>

using namespace std;

void display_matrix(const float m[][3], const size_t ROWS, const size_t COLS) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << fixed << setprecision(1) << m[i][j] << "  ";
        }
        cout << endl;
    }
}

float getAvgOfElements(int i, int j, const float img[][3], const size_t ROWS, const size_t COLS) {
    float avg = 0.0f;

    size_t cntElements = 0;
    for (int k = 2 * i; k <= 2 * i + 1 && k < ROWS; ++k) {
        for (int l = 2 * j; l <= 2 * j + 1 && l < COLS; ++l) {
            avg += img[k][l];
            ++cntElements;
        }
    }

    if (!cntElements) {
        return avg;
    }

    return avg / (float) cntElements;
}

void subsample(const float img[][3], const size_t ROWS, const size_t COLS) {
    size_t S_ROWS = (ROWS + 1) / 2;
    size_t S_COLS = (COLS + 1) / 2;

    for (int i = 0; i < S_ROWS; ++i) {
        for (int j = 0; j < S_COLS; ++j) {
            cout << getAvgOfElements(i, j, img, ROWS, COLS) << "  ";
        }
        cout << endl;
    }
}

int main() {
    const size_t ROWS = 2; // N
    const size_t COLS = 3; // M

    const float img[][COLS]{
            {1.0, 2.0, 3.0},
            {4.5, 6.5, 7.5}
    };

//     display_matrix(img, ROWS, COLS);

    subsample(img, ROWS, COLS);

    return 0;
}
