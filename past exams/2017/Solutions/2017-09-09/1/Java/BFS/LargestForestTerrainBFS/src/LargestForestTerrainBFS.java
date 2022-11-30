import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class LargestForestTerrainBFS {

    record Coord(int x, int y) {
        public static Coord of(int x, int y) {
            return new Coord(x, y);
        }
    }

    public static int maxComponent(char[][] terrain) {
        final int N = terrain.length;
        final int M = terrain[0].length;

        boolean[][] visited = new boolean[N][M];

        Arrays.stream(visited).forEach(a -> Arrays.fill(a, false));

        int maxComp = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (terrain[i][j] == '4') {
                    int currComp = bfs(i, j, terrain, visited);
                    maxComp = Math.max(maxComp, currComp);
                }
            }
        }

        return maxComp;
    }

    private static int bfs(int i, int j, char[][] terrain, boolean[][] visited) {
        final int[] dx = {-1, 0, 0, 1,};
        final int[] dy = {0, -1, 1, 0,};
        final int DIR = 4;

        Queue<Coord> Q = new LinkedList<>();
        Q.add(Coord.of(i, j));

        int cnt = 0;

        while (!Q.isEmpty()) {
            Coord coord = Q.poll();
            cnt++;
            visited[coord.x()][coord.y()] = true;

            for (int k = 0; k < DIR; k++) {
                int currX = coord.x() + dx[k];
                int currY = coord.y() + dy[k];
                if (isValid(currX, currY, terrain, visited)) {
                    Q.add(Coord.of(currX, currY));
                    visited[currX][currY] = true;
                }
            }
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
