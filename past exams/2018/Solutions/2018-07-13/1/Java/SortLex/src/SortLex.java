public class SortLex {

    public static void print(int[] a) {
        for (int j : a) {
            System.out.printf("%d ", j);
        }

        System.out.println();
    }

    public static void sortLex(int[] a) {
        quickSort(a, 0, a.length - 1);
    }

    private static void quickSort(int[] a, int start, int end) {
        if (start >= end) return;

        int pivot = partition(a, start, end);

        quickSort(a, start, pivot - 1);
        quickSort(a, pivot + 1, end);
    }

    private static void mySwap(int[] a, int p1, int p2) {
        int temp = a[p1];
        a[p1] = a[p2];
        a[p2] = temp;
    }

    private static boolean compare(int a, int b) {
        if (a == 0 && b != 0) return true;
        if (b == 0 && a != 0) return false;

        final int MAX_DIGITS = 10;
        int[] digits_a = new int[MAX_DIGITS];
        int[] digits_b = new int[MAX_DIGITS];

        int i = MAX_DIGITS - 1;
        while (a > 0) {
            digits_a[i--] = (short) (a % 10);
            a /= 10;
        }

        i = MAX_DIGITS - 1;
        while (b > 0) {
            digits_b[i--] = (short) (b % 10);
            b /= 10;
        }

        int j = 0, k = 0;
        while (j < MAX_DIGITS && digits_a[j] == 0) ++j;
        while (k < MAX_DIGITS && digits_b[k] == 0) ++k;

        for (; j < MAX_DIGITS && k < MAX_DIGITS; ++j, ++k) {
            int diff = digits_a[j] - digits_b[k];
            if (diff > 0) return false;
            else if (diff < 0) return true;
        }

        if (j < MAX_DIGITS) return false;
        if (k < MAX_DIGITS) return true;

        return true;
    }

    private static int partition(int[] a, int start, int end) {
        int pivIndex = start + ((end - start) >> 1); // middle pivot

        mySwap(a, pivIndex, end);
        int pivot = a[end];
        pivIndex = start;

        for (int i = start; i < end; i++) {
            if (compare(a[i], pivot)) {
                mySwap(a, i, pivIndex++);
            }
        }

        mySwap(a, pivIndex, end);

        return pivIndex;
    }

    public static void main(String... args) {
        int[] a = {13, 14, 7, 2018, 9, 0, 201};

        print(a);
        sortLex(a);
        print(a);
    }
}
