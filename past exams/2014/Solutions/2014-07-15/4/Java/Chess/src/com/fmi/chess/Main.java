package com.fmi.chess;

import com.fmi.chess.piece.ChessPiece;
import com.fmi.chess.piece.Knight;
import com.fmi.chess.piece.Rook;
import com.fmi.chess.position.ChessPosition;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void allMoves(List<ChessPiece> pieces) {

        for (ChessPiece currPiece : pieces) {
            List<ChessPosition> currMoves = currPiece.allowedMoves();

            boolean flagFirst = true;

            for (ChessPosition move : currMoves) {
                boolean makesConflict = false;

                for (ChessPiece piece : pieces) {
                    if (currPiece.equals(piece)) {
                        continue;
                    }

                    if (piece.captures(move)) {
                        makesConflict = true;
                        break;
                    }
                }

                if (!makesConflict) {
                    if (flagFirst) {
                        System.out.print(currPiece.getType() + " " + currPiece.getPosition() + " -> " + move);
                        flagFirst = false;
                    } else {
                        System.out.print(", " + move);
                    }
                }
            }
            System.out.println();
        }
    }

    public static void main(String... args) {
        List<ChessPiece> pieces = new ArrayList<>(Arrays.asList(
                new Rook('A', (short) 1),
                new Knight('B', (short) 3)
        ));

        allMoves(pieces);
    }
}
