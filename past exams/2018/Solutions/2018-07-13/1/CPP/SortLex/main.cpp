#include <iostream>

using namespace std;

bool compare(unsigned a, unsigned b) {
    if (a == 0 && b != 0) return true;
    if (b == 0 && a != 0) return false;

    const int MAX_DIGITS = 10;
    short digits_a[MAX_DIGITS]{0}, digits_b[MAX_DIGITS]{0};

    int i = MAX_DIGITS - 1;
    while (a) {
        digits_a[i--] = (short) (a % 10);
        a /= 10;
    }

    i = MAX_DIGITS - 1;
    while (b) {
        digits_b[i--] = (short) (b % 10);
        b /= 10;
    }

    int j = 0, k = 0;
    while (j < MAX_DIGITS && !digits_a[j]) ++j;
    while (k < MAX_DIGITS && !digits_b[k]) ++k;

    for (; j < MAX_DIGITS && k < MAX_DIGITS; ++j, ++k) {
        short diff = digits_a[j] - digits_b[k];
        if (!diff) continue;
        else if (diff > 0) return false;
        else return true;
    }

    if (j < MAX_DIGITS) return false;
    if (k < MAX_DIGITS) return true;

    return true;
}

void my_swap(unsigned *a, int p1, int p2) {
    int temp = a[p1];
    a[p1] = a[p2];
    a[p2] = temp;
}

int partition(unsigned *a, int start, int end) {
    int piv_index = start + ((end - start) >> 1); // middle pivot

    my_swap(a, piv_index, end);
    unsigned pivot = a[end];
    piv_index = start;

    for (int i = start; i < end; ++i) {
        if (compare(a[i], pivot)) {
            my_swap(a, i, piv_index++);
        }
    }

    my_swap(a, piv_index, end);

    return piv_index;
}

void quick_sort(unsigned *a, int start, int end) {
    if (start >= end) return;

    int pivot = partition(a, start, end);

    quick_sort(a, start, pivot - 1);
    quick_sort(a, pivot + 1, end);
}

void sortLex(unsigned *a, const unsigned n) {
    quick_sort(a, 0, n - 1);
}

void print(unsigned *a, const unsigned n) {
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    unsigned a[] = {13, 14, 7, 2018, 9, 0, 201};
    const unsigned n = sizeof a / sizeof(unsigned);

    print(a, n);
    sortLex(a, n);
    print(a, n);

    return EXIT_SUCCESS;
}
