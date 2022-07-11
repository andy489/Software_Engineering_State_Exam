#include <iostream>
#include <vector>
#include <random>

using namespace std;

random_device rd;
mt19937 gen(rd());

int get_rand(int l, int r) {
    uniform_int_distribution<> distr(l, r);
    return distr(gen);
}

void print(const int *arr, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }

    cout << endl;
}

int partition(int *arr, int l, int r) {
    int piv_ind = get_rand(l, r);   // random pivot
//    int piv_ind = l + (r - l) / 2;  // middle pivot

    swap(arr[piv_ind], arr[r]);

    int pivot = arr[r];
    piv_ind = l;

    for (int i = l; i < r; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[piv_ind++]);
        }
    }

    swap(arr[piv_ind], arr[r]);
    return piv_ind;
}

void quick_sort(int *arr, int l, int r) {
    if (l >= r) {
        return;
    }

    int pivot = partition(arr, l, r);

    quick_sort(arr, l, pivot - 1);
    quick_sort(arr, pivot + 1, r);
}

int main() {
    int arr[]{5, 1, 4, 2, 3};
    const int size = sizeof arr / sizeof(int);
    print(arr, size);

    quick_sort(arr, 0, size - 1);

    print(arr, size);

    return 0;
}
