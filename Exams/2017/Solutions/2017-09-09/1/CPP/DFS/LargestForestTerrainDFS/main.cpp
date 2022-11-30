#include <iostream>

using namespace std;

const int N = 4;
const int M = 6;

const int xd[] = {-1, 0, 0, 1,};
const int yd[] = {0, -1, 1, 0};

const int DIR = 4;

bool is_valid(int x, int y, char terrain[][M], bool **visited) {
    return x >= 0 && y >= 0 && x < N && y < M && terrain[x][y] == '4' && !visited[x][y];
}

int dfs(int i, int j, char terrain[][M], bool **visited) {
    if (!is_valid(i, j, terrain, visited)) return 0;

    visited[i][j] = true;
    int cnt = 1;

    for (int k = 0; k < DIR; ++k) {
        cnt += dfs(i + xd[k], j + yd[k], terrain, visited);
    }

    return cnt;
}

int max_component(char terrain[][M]) {
    bool **visited = new bool *[N];

    for (int i = 0; i < N; ++i) {
        visited[i] = new bool[M];
    }

    fill(*visited, *visited + N * M, false);

    int max_comp = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (terrain[i][j] == '4') {
                int curr_comp = dfs(i, j, terrain, visited);
                max_comp = max(max_comp, curr_comp);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        delete[] visited[i];
    }

    delete[] visited;

    return max_comp;
}

int main() {

    char terrain[][M] = {
            {'R', 'R', '1', '1', '2', '2'},
            {'1', 'R', 'R', 'R', '1', '2'},
            {'S', '1', 'R', 'R', '2', '3'},
            {'4', '4', 'S', 'S', 'R', 'R'},
    };

    int largest_forest_terrain = max_component(terrain);

    cout << largest_forest_terrain << endl;

    return 0;
}
