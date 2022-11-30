package com.fmi.chess.position;

public record ChessPosition(Character row, Short col) {
    @Override
    public String toString() {
        return String.format("%c%s", row, col);
    }
}
