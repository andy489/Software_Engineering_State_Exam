// a -> a
// b -> aba
// c -> abacaba
// ...

#include <iostream>

void recursive_print(char c) {
    if (c >= 'a') {
        recursive_print(c - 1);
        std::cout << c;
        recursive_print(c - 1);
    }
}

int main() {
    recursive_print('a');
    std::cout << std::endl;

    recursive_print('b');
    std::cout << std::endl;

    recursive_print('c');
    std::cout << std::endl;

    return 0;
}
