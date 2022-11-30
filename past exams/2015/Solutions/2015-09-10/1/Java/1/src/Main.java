import bitwise.Bitwise;
import result.Result;
import sort.SelectionSort;

import static member.BinarySearch.member;

public class Main {

    public static void main(String... args) {
        int[] a = {1, 3, 6, 8, 8, 9, 9, 14};
        int[] b = {1, 3, 5, 6, 8, 8, 9, 9, 15, 14};
        int[] c = {5, 1, 9, 0, -3, 14, 5};

        for (int i : b) {
            System.out.printf("Element %d is %s present%n", i, member(i, a, a.length) ? "" : "NOT");
        }
        System.out.println();

        SelectionSort.sort(c);
        for (int i : c) {
            System.out.printf("%d ", i);
        }
        System.out.println();
        System.out.println();

        Result.res();
        System.out.println();

        int x = 6, y = 11;
        System.out.printf("Result of bitwise operation %d|%d is: ", x, y);
        Bitwise.bitwise(6, 11);
    }
}
