#include <iostream>

using namespace std;

void selection_sort(int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        int min_ind = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_ind]) {
                min_ind = j;
            }

            swap(arr[i], arr[min_ind]);
        }
    }
}

void insertion_sort(int *arr, const int size) {
    for (int i = 1; i < size; i++) {
        const int new_val = arr[i];
        int ind = i;

        while (ind > 0 && arr[ind - 1] > new_val) {
            arr[ind] = arr[ind - 1];
            ind--;
        }

        arr[ind] = new_val;
    }
}

void bubble_sort(int *arr, const int size) {
    int i, j;
    bool swapped;

    for (i = 0; i < size - 1 && swapped; ++i) {
        swapped = false;

        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void print(int *arr, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }

    cout << std::endl;
}


int main() {
    int arr[]{4, 10, 2, 8, 4, 16, 3};
    const int size = sizeof arr / sizeof(int);

    print(arr, size);

    selection_sort(arr, size);
//    insertion_sort(arr, size);
//    bubble_sort(arr, size);

    print(arr, size);

    return 0;
}

