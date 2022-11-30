#include <iostream>

using namespace std;

bool find(int value, int *arr, size_t size) {
    if (size == 0) return false;

    size_t mid = size / 2;
    if (value == arr[mid]) return true;

    if (value < arr[mid])
        return find(value, arr, mid);
    else
        return find(value, arr + mid + (size & 1), mid);
}

int main() {
    int arr[] = {-10, -5, -1, 0, 1, 3, 4, 7, 10};
    size_t size = sizeof arr / sizeof(int);

    find(10, arr, size);

    for (int i = -10; i <= 10; ++i) {
        cout << "Element " << i << (find(i, arr, size) ? "" : " NOT") << " FOUND" << endl;
    }

    return 0;
}
