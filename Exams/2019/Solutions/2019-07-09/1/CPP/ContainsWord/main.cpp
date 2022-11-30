#include <iostream>

using namespace std;

bool walk(char arr[6][6], int row, int col, const char *str) {
    if (*str == '\0')
        return true;

    if (row < 0 || col < 0 || row >= 6 || col >= 6)
        return false;

    if (arr[row][col] != *str)
        return false;

    arr[row][col] *= -1;

    bool result =
            walk(arr, row + 1, col, str + 1) ||
            walk(arr, row - 1, col, str + 1) ||
            walk(arr, row, col + 1, str + 1) ||
            walk(arr, row, col - 1, str + 1);

    arr[row][col] *= -1;

    return result;
}

bool contains(char arr[6][6], const char *str) {
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 6; ++col) {
            if (walk(arr, row, col, str))
                return true;
        }
    }

    return false;
}

int main() {
    char arr[6][6] = {
            {'y', 'u', 'f', 'a', 'b', 'c'},
            {'G', 'o', 'p', 'g', 'B', '1'},
            {'c', 'b', 'a', 'h', '3', '2'},
            {'d', 'k', 'j', 'i', '2', '3'},
            {'e', 'f', 'Q', 'N', '1', 'C'},
            {'h', 'g', 'h', 'M', 'A', 'r'}
    };

    char *WORDS[] = {"abcdefgh", "A123B123C", "", "abcdefghj"};
    const int SIZE = sizeof WORDS / sizeof(int);

    for (const char *word: WORDS) {
        cout << "\"" << word << "\"" << ' ' << (contains(arr, word) ? "CONTAINS" : "DOES NOT CONTAIN") << endl;
    }

    return 0;
}
