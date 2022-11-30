#include <iostream>

using namespace std;

const int N = 4;
const int M = 6;

void display_terrain(char terrain[][M]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << terrain[i][j] << ' ';
        }

        cout << endl;
    }
}

bool validate(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int K = 8;

bool check_neighbours(int i, int j, char terrain[][M]) {
    int cnt = 0;

    for (int k = 0; k < K; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];

        if (validate(x, y)) {
            char curr = terrain[x][y];
            if (curr == '4') {
                ++cnt;
            }
        }
    }

    return cnt >= 3;
}

void change_terrain_after_n_years(int n, char terrain[][M]) {
    if (n < 0) {
        return;
    }

    while (n--) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                char curr = terrain[i][j];

                switch (curr) {
                    case '1':
                        terrain[i][j] = '2';
                        break;
                    case '2':
                        terrain[i][j] = '3';
                        break;
                    case '3':
                        terrain[i][j] = '4';
                        break;
                    default:
                        break;
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (check_neighbours(i, j, terrain)) {
                    terrain[i][j] = '3';
                }
            }
        }
    }
}

int main() {
    char terrain[][M] = {
            {'R', 'R', '1', '1', '2', '2'},
            {'1', 'R', 'R', 'R', '1', '2'},
            {'S', '1', 'R', 'R', '2', '3'},
            {'4', '4', 'S', 'S', 'R', 'R'},
    };

    const int YEARS = 100;

    change_terrain_after_n_years(YEARS, terrain);
    display_terrain(terrain);

    return 0;
}
