package com.fmi.chess.piece;

import com.fmi.chess.position.ChessPosition;

import java.util.List;

public abstract class ChessPiece {
    protected ChessPosition currentPosition;

    public ChessPosition getPosition() {
        return currentPosition;
    }

    public void setCurrentPosition(ChessPosition currentPosition) {
        this.currentPosition = currentPosition;
    }

    public abstract List<ChessPosition> allowedMoves();

    public abstract PieceType getType();

    public Boolean captures(ChessPosition pos) {
        return allowedMoves().stream().anyMatch(p -> p.equals(pos));
    }
}
