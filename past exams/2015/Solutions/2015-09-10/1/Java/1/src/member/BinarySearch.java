package member;

import java.util.Arrays;

public class BinarySearch {
    public static boolean member(int x, int[] a, int size) {
        if (size == 0) return false;
        return a[size / 2] == x ||
                (a[size / 2] < x && member(x, Arrays.copyOfRange(a, size / 2, size), size / 2)) ||
                (a[size / 2] > x && member(x, a, size / 2));
    }
}
