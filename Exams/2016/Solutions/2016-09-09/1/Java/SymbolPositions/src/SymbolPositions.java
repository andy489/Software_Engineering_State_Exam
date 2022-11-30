public class SymbolPositions {

    public static int[] pos(String str) {
        int[] res = {-1, -1};
        final int ASCII_SZ = 127;

        int[] first = new int[ASCII_SZ];
        int[] last = new int[ASCII_SZ];

        for (int i = 0; i < ASCII_SZ; i++) {
            first[i] = last[i] = -1;
        }

        final int SIZE = str.length();

        for (int i = 0; i < SIZE; i++) {
            int p = str.charAt(i);

            if (first[p] == -1) {
                first[p] = i;
            }

            last[p] = i;
        }

        int curr_max = -1;
        for (int i = 0; i < ASCII_SZ; i++) {
            int curr_dist = last[i] - first[i];

            if (curr_dist > curr_max) {
                curr_max = curr_dist;
                res[0] = first[i];
                res[1] = last[i];
            }
        }

        return res;
    }

    public static void main(String... args) {
        String str = "this is just a simple example";

        int[] res = pos(str);

        System.out.printf("%d %d%n", res[0], res[1]);
    }
}
