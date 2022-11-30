#include <iostream>

bool member(int x, int a[], int size) {
    if (size == 0) return false;
    return a[size / 2] == x ||
           (a[size / 2] < x && member(x, a + size / 2, size / 2)) ||
           (a[size / 2] > x && member(x, a, size / 2));
}

int main() {
    int a[]{1, 3, 6, 8, 8, 9, 9, 14};
    const int SIZE = sizeof a / sizeof(int);

    int b[]{1, 3, 5, 6, 8, 8, 9, 9, 15, 14};
    for (int i: b) {
        printf("Element %d is %s present\n", i, member(i, a, SIZE) ? "" : "NOT");
    }

    return 0;
}
