import java.text.DecimalFormat;

public class Matrix {
    public static float getAvgOfElements(int i, int j, final float[][] img) {
        final int ROWS = img.length;
        final int COLS = img[0].length;

        float avg = 0.0f;
        int cntElements = 0;

        for (int k = 2 * i; k <= 2 * i + 1 && k < ROWS; k++) {
            for (int l = 2 * j; l <= 2 * j + 1 && l < COLS; l++) {
                avg += img[k][l];
                cntElements++;
            }
        }

        if (cntElements == 0) {
            return avg;
        }

        return avg / cntElements;
    }

    public static void subSample(final float[][] img) {
        final int ROWS = (img.length + 1) / 2;
        final int COLS = (img[0].length + 1) / 2;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                System.out.printf("%s  ", getAvgOfElements(i, j, img));
            }
            System.out.println();
        }
    }

    public static void displayImg(final float[][] img) {
        for (float[] floats : img) {
            for (float el : floats) {
                System.out.printf("%.1f  ", el);
            }

            System.out.println();
        }
    }

    public static void main(String... args) {
        final float[][] img = {
                {1.0f, 2.0f, 3.0f},
                {4.5f, 6.5f, 7.5f}
        };

//        displayImg(img);

        subSample(img);
    }
}
