#include <iostream>

int *pos(const char *str) {
    int *pos = new int[2];

    const int SIZE = (int) strlen(str);

    const int ASCII_SZ = 127;
    int first[ASCII_SZ], last[ASCII_SZ];

    for (int i = 0; i < ASCII_SZ; ++i) {
        first[i] = last[i] = -1;
    }

    for (int i = 0; i < SIZE; ++i) {
        if (first[str[i]] == -1) {
            first[str[i]] = i;
        }

        last[str[i]] = i;
    }


    int curr_max = -1;
    for (int i = 0; i < ASCII_SZ; ++i) {
        int curr_dist = last[i] - first[i];

        if (curr_dist > curr_max) {
            curr_max = curr_dist;
            pos[0] = first[i];
            pos[1] = last[i];
        }
    }

    return pos;
}

int main() {
    char *str = new char[]{"this is just a simple example"};

    int *res = pos(str);

    std::cout << res[0] << ' ' << res[1] << std::endl;

    return 0;
}
