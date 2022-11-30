package com.fmi.chess.piece;

import com.fmi.chess.position.ChessPosition;

import java.util.ArrayList;
import java.util.List;

public class Rook extends ChessPiece {
    public Rook(Character a, Short i) {
        setCurrentPosition(new ChessPosition(a, i));
    }

    @Override
    public List<ChessPosition> allowedMoves() {
        List<ChessPosition> moves = new ArrayList<>();

        for (char c = 'A'; c <= 'H'; c++) {
            if (c != currentPosition.row()) {
                moves.add(new ChessPosition(c, currentPosition.col()));
            }
        }

        for (short s = 1; s <= 8; s++) {
            if (s != currentPosition.col()) {
                moves.add(new ChessPosition(currentPosition.row(), s));
            }
        }

        return moves;
    }

    @Override
    public PieceType getType() {
        return PieceType.ROOK;
    }
}
