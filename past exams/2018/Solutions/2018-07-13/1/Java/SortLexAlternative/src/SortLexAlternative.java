import java.util.Arrays;
import java.util.List;

public class SortLexAlternative {
    static List<Integer> sortLex(int[] a) {
        return Arrays.stream(a)
                .mapToObj(Integer::toString)
                .sorted()
                .map(Integer::valueOf)
                .toList();
    }

    public static void main(String... args) {
        int[] a = {13, 14, 7, 2018, 9, 0, 201};
        System.out.println(sortLex(a));
    }
}
