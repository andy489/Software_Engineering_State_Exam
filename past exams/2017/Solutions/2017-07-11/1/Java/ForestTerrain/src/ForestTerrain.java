public class ForestTerrain {

    static final int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static final int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    static final int K = 8;

    static boolean validate(int x, int y, char[][] terrain) {
        final int N = terrain.length;
        final int M = terrain[0].length;

        return x >= 0 && y >= 0 && x < N && y < M;
    }

    public static boolean checkNeighbours(int i, int j, char[][] terrain) {
        int cnt = 0;

        for (int k = 0; k < K; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (validate(x, y, terrain)) {
                char curr = terrain[x][y];
                if (curr == '4') {
                    ++cnt;
                }
            }
        }

        return cnt >= 3;
    }

    public static void changeTerrainAfterNYears(int n, char[][] terrain) {
        if (n < 0) {
            return;
        }

        final int N = terrain.length;
        final int M = terrain[0].length;

        while (n-- > 0) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    char curr = terrain[i][j];

                    switch (curr) {
                        case '1' -> terrain[i][j] = '2';
                        case '2' -> terrain[i][j] = '3';
                        case '3' -> terrain[i][j] = '4';
                        default -> {
                        }
                    }
                }
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (checkNeighbours(i, j, terrain)) {
                        terrain[i][j] = '3';
                    }
                }
            }
        }
    }

    static void displayTerrain(char[][] terrain) {
        for (char[] chars : terrain) {
            for (char c : chars) {
                System.out.printf("%c ", c);
            }

            System.out.println();
        }
    }

    public static void main(String... args) {
        char[][] terrain = {
                {'R', 'R', '1', '1', '2', '2'},
                {'1', 'R', 'R', 'R', '1', '2'},
                {'S', '1', 'R', 'R', '2', '3'},
                {'4', '4', 'S', 'S', 'R', 'R'}
        };

        final int YEARS = 100;

        changeTerrainAfterNYears(YEARS, terrain);

        displayTerrain(terrain);
    }
}
