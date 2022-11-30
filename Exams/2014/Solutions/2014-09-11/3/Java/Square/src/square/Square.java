package square;

public class Square {

    public static void square(final float[] x, final float[] y) {
        final int N = x.length;

        if (N != y.length) {
            throw new IllegalStateException("Invalid coordinates");
        }

        float mostLeftX = Float.MAX_VALUE;
        float mostRightX = Float.MIN_VALUE;

        float mostDownY = Float.MAX_VALUE;
        float mostUpY = Float.MIN_VALUE;

        for (int i = 0; i < N; i++) {
            if (x[i] < mostLeftX) {
                mostLeftX = x[i];
            }
            if (x[i] > mostRightX) {
                mostRightX = x[i];
            }

            if (y[i] < mostDownY) {
                mostDownY = y[i];
            }

            if (y[i] > mostUpY) {
                mostUpY = y[i];
            }
        }

        float distX = Math.abs(mostLeftX - mostRightX);
        float distY = Math.abs(mostUpY - mostDownY);

        float side = Math.max(distX, distY);

        float centerX = mostLeftX + side / 2.0f;
        float centerY = mostDownY + side / 2.0f;

        System.out.printf("Square center coordinates: (%s, %s)%nSide length: %s%n",
                String.format("%.1f", centerX),
                String.format("%.1f", centerY),
                String.format("%.1f", side)
        );
    }

    public static void main(String... args) {
        final float[] x = {2.2f, 3.3f, 3.0f, 4.0f, -3.0f};
        final float[] y = {3.2f, -1.3f, 2.0f, 1.0f, -1.5f};

        square(x, y);
    }
}
