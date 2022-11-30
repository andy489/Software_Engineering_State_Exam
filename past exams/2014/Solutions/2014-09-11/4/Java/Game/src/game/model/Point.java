package game.model;

public record Point(int x, int y) {
    @Override
    public String toString() {
        return "(" + x + ',' + y + ')';
    }

    public static Point of(int x, int y) {
        return new Point(x, y);
    }
}
