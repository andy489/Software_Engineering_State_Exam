import java.util.Arrays;

public class LargestForestTerrainDFS {

    static final int[] dx = {-1, 0, 0, 1,};
    static final int[] dy = {0, -1, 1, 0,};
    static final int DIR = 4;

    public static int maxComponent(char[][] terrain) {
        final int N = terrain.length;
        final int M = terrain[0].length;

        boolean[][] visited = new boolean[N][M];

        Arrays.stream(visited).forEach(a -> Arrays.fill(a, false));

        int maxComp = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (terrain[i][j] == '4') {
                    int currComp = dfs(i, j, terrain, visited);
                    maxComp = Math.max(maxComp, currComp);
                }
            }
        }

        return maxComp;
    }

    private static int dfs(int i, int j, char[][] terrain, boolean[][] visited) {
        if (!isValid(i, j, terrain, visited)) return 0;

        visited[i][j] = true;
        int cnt = 1;

        for (int k = 0; k < DIR; k++) {
            cnt += dfs(i + dx[k], j + dy[k], terrain, visited);
        }

        return cnt;
    }

    private static boolean isValid(int x, int y, char[][] terrain, boolean[][] visited) {
        return x >= 0 && y >= 0 && x < terrain.length && y < terrain[0].length && terrain[x][y] == '4' && !visited[x][y];
    }

    public static void main(String... args) {
        char[][] terrain = {{'R', 'R', '1', '1', '2', '2'}, {'1', 'R', 'R', 'R', '1', '2'}, {'S', '1', 'R', 'R', '2', '3'}, {'4', '4', 'S', 'S', 'R', 'R'}};

        int largestForestTerrain = maxComponent(terrain);

        System.out.println(largestForestTerrain);
    }
}
