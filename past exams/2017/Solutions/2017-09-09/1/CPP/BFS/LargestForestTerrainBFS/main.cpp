#include <iostream>
#include <queue>

using namespace std;

const int N = 4;
const int M = 6;

bool is_valid(int x, int y, char terrain[][M], bool **visited) {
    return x >= 0 && y >= 0 && x < N && y < M && terrain[x][y] == '4' && !visited[x][y];
}

int bfs(int i, int j, char terrain[][M], bool **visited) {
    const int xd[] = {-1, 0, 0, 1,}, yd[] = {0, -1, 1, 0}, DIR = 4;

    queue<pair<int, int>> Q;
    Q.push({i, j});

    int cnt = 0;

    while (!Q.empty()) {
        pair<int, int> coord = Q.front();
        Q.pop();

        ++cnt;
        visited[coord.first][coord.second] = true;

        for (int k = 0; k < DIR; ++k) {
            int curr_X = coord.first + xd[k];
            int curr_Y = coord.second + yd[k];
            if (is_valid(curr_X, curr_Y, terrain, visited)) {
                Q.push({curr_X, curr_Y});
                visited[curr_X][curr_Y] = true;
            }
        }
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
                int curr_comp = bfs(i, j, terrain, visited);
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

    int largest_forrest_terrain = max_component(terrain);

    cout << largest_forrest_terrain << endl;

    return 0;
}
