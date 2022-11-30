#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
const int N = sizeof dx / sizeof(int);

void readInput(int &n, int &m, vector<vector<int>> &matrix) {
    cin >> n >> m;
    matrix.assign(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
}

struct PaintedArea {
    pair<int, int> innerPoint;
    int sumPixels;
    int cntPixels;

    PaintedArea(pair<int, int> innerPoint, int sumPixels, int cntPixels) :
            innerPoint(move(innerPoint)), sumPixels(sumPixels), cntPixels(cntPixels) {}

    void add(PaintedArea other) {
        sumPixels += other.sumPixels;
        cntPixels += other.cntPixels;
    }

    bool isNotContour() const {
        return sumPixels != 0;
    }

    void displayStatistics() const {
        cout << "(" << innerPoint.first << ", " << innerPoint.second << ") "
             << sumPixels * 1.0 / cntPixels << endl;
    }
};

bool valid(int i, int j, vector<vector<int>> &matrix, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m && matrix[i][j] > 0;
}

PaintedArea dfs(int i, int j, vector<vector<int>> &matrix, int n, int m) {
    if (matrix[i][j] <= 0) {
        return {{0, 0}, 0, 0};
    }

    PaintedArea area = {{i, j}, matrix[i][j], 1};
    matrix[i][j] *= -1;

    for (int k = 0; k < N; ++k) {
        if (valid(i + dx[k], j + dy[k], matrix, n, m)) {
            PaintedArea curr = dfs(i + dx[k], j + dy[k], matrix, n, m);
            area.add(curr);
        }

    }

    return area;
}

int main() {
    int n, m;
    vector<vector<int>> matrix;
    readInput(n, m, matrix);

    vector<PaintedArea> areas;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            PaintedArea currArea = dfs(i, j, matrix, n, m);
            if (currArea.isNotContour()) {
                areas.push_back(currArea);
            }
        }
    }

    for (PaintedArea area: areas) {
        area.displayStatistics();
    }

    return 0;
}

/*
6 6
170 0 0 255 221 0
68 0 17 0 0 68
221 0 238 136 0 255
0 0 85 0 136 238
238 17 0 68 0 255
85 170 0 221 17 0

1 6
170 0 0 255 221 0
*/