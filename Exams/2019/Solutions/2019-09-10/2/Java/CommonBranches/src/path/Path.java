package path;

public record Path(Long cost, String word) {

    public static Path of(Long cost, String word) {
        return new Path(cost, word);
    }
}

