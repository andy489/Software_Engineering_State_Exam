#include <iostream>

using namespace std;

typedef int(*func_ptr)(char, int);

template<typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType *arr, size_t size, OpType op, ReturnType nil) {
    ReturnType result = nil;

    for (size_t i = 0; i < size; ++i) {
        result = op(arr[i], result);
    }

    return result;
}

int op(char Digit, int Result) {
    return (Result * 10) + (Digit - '0');
}

int str_to_int(const char *str) {
    return (str == nullptr) ?
           0 :
           fold_left(str, strlen(str), op, 0);
}

int main() {
    char *str = "123456789";

    cout << fold_left<int, char, func_ptr>(str, strlen(str), op, 0);
    // cout << fold_left<int, char, int(char, int)>(str, strlen(str), op, 0);

    return 0;
}
