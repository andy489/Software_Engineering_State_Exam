import java.util.ArrayList;
import java.util.List;

public class SymmetricGroup {
    public static double[][] change(final double[][] matrix) {
        final int SIZE = matrix.length;
        double[][] updatedMatrix = new double[SIZE][SIZE];

        for (int i = 0; i <= SIZE >> 1; ++i) {
            for (int j = 0; j < SIZE - i; ++j) {
                List<Point> symmetricGroup = getSymGroup(i, j, SIZE);

                double avg = 0.0f;

                for (Point p : symmetricGroup) {
                    avg += matrix[p.x()][p.y()];
                }

                if (symmetricGroup.size() != 0) {
                    avg /= symmetricGroup.size();
                }

                for (Point p : symmetricGroup) {
                    updatedMatrix[p.x()][p.y()] = avg;
                }
            }
        }

        return updatedMatrix;
    }

    private static List<Point> getSymGroup(int x, int y, final int SIZE) {
        List<Point> symGroup = new ArrayList<>();

        symGroup.add(Point.of(x, y));
        symGroup.add(Point.of(SIZE - x - 1, SIZE - y - 1)); // center

        if (x != y && x + y != SIZE - 1) {
            symGroup.add(Point.of(SIZE - y - 1, SIZE - x - 1)); // primary
            symGroup.add(Point.of(y, x)); // secondary
        }

        return symGroup;
    }

    public static void main(String... args) {
        double[][] matrix = {
                {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1, 2, 3},
                {2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 2, 3, 4},
                {3.1, 4.2, 5.3, 6.4, 7.5, 8.6, 9.7, 1.8, 3, 4, 5},
                {4.1, 5.2, 6.3, 7.4, 8.5, 9.6, 1.7, 2.8, 4, 5, 6},
                {5.1, 6.2, 7.3, 8.4, 9.5, 1.6, 2.7, 3.8, 5, 6, 7},
                {6.1, 7.2, 8.3, 9.4, 1.5, 2.6, 3.7, 4.8, 6, 7, 8},
                {7.1, 8.2, 9.3, 1.4, 2.5, 3.6, 4.7, 5.8, 7, 8, 9},
                {8.1, 9.2, 1.3, 2.4, 3.5, 4.6, 5.7, 6.8, 8, 9, 1},
                {9.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 9, 1, 2},
                {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 1, 2, 3},
                {2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8, 2, 3, 4},
        };

        double[][] updatedMatrix = change(matrix);

        final int SIZE = matrix.length;

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                System.out.printf("%.1f ", updatedMatrix[i][j]);
            }

            System.out.println();
        }
    }
}
