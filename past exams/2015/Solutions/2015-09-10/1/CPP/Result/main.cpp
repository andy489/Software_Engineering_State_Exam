#include <iostream>

int main() {
    int a = 0;
    int b = 15;
    int result = -1;

    if (b < 10 && b / a < 10) result = 0;
        /*
        * AND list fail fast.
        * b / a will never be checked
        * if statement in and list
        * before it is false
        */
    else result = 1;

    printf("%d\n", result);

    return 0;
}

// Answer: в) 1
