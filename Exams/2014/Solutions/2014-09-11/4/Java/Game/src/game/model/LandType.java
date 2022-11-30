package game.model;

public enum LandType {
    EARTH(0),
    FIRE(1),
    WATER(2);

    private int code;

    // Constructor is always private or default.
    // You cannot create an instance of enum using the new operator.
    LandType(int code) {
        this.code = code;
    }

    public int getCode() {
        return code;
    }
}
