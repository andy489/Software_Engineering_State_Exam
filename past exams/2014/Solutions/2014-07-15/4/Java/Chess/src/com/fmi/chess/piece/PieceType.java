package com.fmi.chess.piece;

public enum PieceType {
    ROOK,
    KNIGHT;

    @Override
    public String toString() {
        return switch (this) {
            case ROOK -> "Rook";
            case KNIGHT -> "Knight";
        };
    }
}
