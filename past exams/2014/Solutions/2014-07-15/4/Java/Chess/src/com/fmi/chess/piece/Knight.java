package com.fmi.chess.piece;

import com.fmi.chess.position.ChessPosition;

import java.util.ArrayList;
import java.util.List;

public class Knight extends ChessPiece {
    public Knight(Character a, Short i) {
        setCurrentPosition(new ChessPosition(a, i));
    }

    private Boolean isKnightMove(char row, short col) {
        return (Math.abs(currentPosition.row() - row) + Math.abs(currentPosition.col() - col)) == 3;
    }

    @Override
    public List<ChessPosition> allowedMoves() {
        List<ChessPosition> moves = new ArrayList<>();

        for (char c = 'A'; c <= 'H'; c++) {
            for (short s = 1; s <= 8; s++) {
                if (currentPosition.row() != c && currentPosition.col() != s && isKnightMove(c, s)) {
                    moves.add(new ChessPosition(c, s));
                }
            }
        }

        return moves;
    }

    @Override
    public PieceType getType() {
        return PieceType.KNIGHT;
    }
}
