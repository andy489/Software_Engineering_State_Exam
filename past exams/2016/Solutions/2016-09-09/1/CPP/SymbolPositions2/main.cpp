#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Custom_Sort {
private:

    static bool is_interval_valid(const pair<int, int> &p) {
        return p.first != INT_MAX && p.second != INT_MIN && p.first != p.second;
    }

public:

    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (!is_interval_valid(p1)) {
            return false;
        } else if (!is_interval_valid(p2)) {
            return true;
        }

        int left_dist = p1.second - p1.first;
        int right_dist = p2.second - p2.first;

        if (right_dist < left_dist) {
            return true;
        } else if (right_dist == left_dist) {
            return p1.first < p2.first;
        }

        return false;
    }
};


pair<int, int> find_pos_equal_chars(const char *str) {
    const int ASCII_MAX = 127;

    int len = (int) strlen(str);
    vector<pair<int, int>> char_positions(ASCII_MAX);

    for (int i = 0; i < ASCII_MAX; i++) {
        char_positions[i].first = INT_MAX;
        char_positions[i].second = INT_MIN;
    }

    for (int i = 0; i < len; i++) {
        char_positions[str[i]].first = min(char_positions[str[i]].first, i);
        char_positions[str[i]].second = max(char_positions[str[i]].second, i);
    }

    sort(char_positions.begin(), char_positions.end(), Custom_Sort());

    return char_positions[0];
}

int main() {
    pair<int, int> p = find_pos_equal_chars("this is just a simple example");
    cout << p.first << " " << p.second << endl;

    p = find_pos_equal_chars("p is right after p ");
    cout << p.first << " " << p.second << endl;

    return 0;
}