package sort;

public class SelectionSort {
    public static void sort(int[] nums) {
        final int SIZE = nums.length;

        for (int i = 0; i < SIZE; ++i) {
            int min = i;
            for (int j = min + 1; j < SIZE; ++j) {
                if (nums[j] < nums[min]) min = j;
            }

            if (min != i) {
                int x = nums[i];
                nums[i] = nums[min];
                nums[min] = x;
            }
        }
    }
}
