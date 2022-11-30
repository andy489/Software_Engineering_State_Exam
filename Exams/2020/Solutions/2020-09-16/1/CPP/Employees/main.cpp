#include <iostream>

using namespace std;

const char *get_manager(const char *employee, const char *leaders[][2], size_t n) {
    for (int i = 0; i < n; ++i) {
        if (!strcmp(employee, leaders[i][0])) {
            return leaders[i][1];
        }
    }

    return nullptr;
}

bool is_subordinate(const char *employee, const char *manager, const char *leaders[][2], size_t n) {
    const char *currManager = get_manager(employee, leaders, n);

    if (!currManager) {
        return false;
    }

    if (!strcmp(currManager, manager)) {
        return true;
    }

    return is_subordinate(currManager, manager, leaders, n);
}

const char *the_big_boss(const char *leaders[][2], size_t n) {
    const char *employee = leaders[0][0];
    const char *manager = get_manager(employee, leaders, n);

    while (manager) {
        employee = manager;
        manager = get_manager(employee, leaders, n);
    }

    return employee;
}

int main() {
    const char *leaders[][2] = {
            {"Ivan Ivanov",   "Maria Ivanova"},
            {"Maria Ivanova", "Ivan Draganov"},
            {"Ivan Draganov", "Stoyan Petrov"}
    };

    const int N = sizeof leaders / (2 * sizeof(char *));

    cout << (is_subordinate("Ivan Ivanov", "Stoyan Petrov", leaders, N) ? "TRUE" : "FALSE") << endl;
    cout << (is_subordinate("Ivan Ivanov", "Maria Ivanova", leaders, N) ? "TRUE" : "FALSE") << endl;
    cout << (is_subordinate("Ivan Ivanov", "Ivan Draganov", leaders, N) ? "TRUE" : "FALSE") << endl;
    cout << (is_subordinate("Stoyan Petrov", "Petar Petrov", leaders, N) ? "TRUE" : "FALSE") << endl;
    cout << (is_subordinate("Maria Ivanova", "Stoyan Petrov", leaders, N) ? "TRUE" : "FALSE") << endl;

    cout << the_big_boss(leaders, N) << endl;

    return 0;
}