#include <iostream>

void selectionSort(int nums[], const int SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        int min = i;
        for (int j = min + 1; j < SIZE; ++j) {
            if (nums[j] < nums[min]) min = j;
        }

        if (min != i) {
            int x = nums[i];
            nums[i] = nums[min];
            nums[min] = x;
        }
    }
}

int main() {
    int a[]{5, 1, 9, 0, -3, 14, 5};
    const int SIZE = sizeof a / sizeof(int);

    selectionSort(a, SIZE);

    for (int i: a) {
        printf("%d ", i);
    }

    return 0;
}
