package game.player;

import game.model.GameBoard;
import game.model.LandType;
import game.model.PieceType;
import game.model.Point;

import java.util.ArrayList;
import java.util.List;

public class Knight extends GamePlayer {

    public Knight(int x, int y) {
        super(x, y);
    }

    private static boolean checkPosition(int x, int y) {
        if (GameBoard.board[x][y] != 0) {
            return false;
        }

        for (int i = -1; i <= 1; ++i) {
            for (int j = 0; j < 1; ++j) {
                if (isInsideBoard(x + i, y + j) &&
                        GameBoard.board[x + i][x + j] == LandType.FIRE.getCode()) {
                    return false;
                }
            }
        }

        return true;
    }

    @Override
    public List<Point> allowedMoves() {
        List<Point> moves = new ArrayList<>();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (isInsideBoard(currPosition.x() + i, currPosition.y() + j) &&
                        checkPosition(currPosition.x() + i, currPosition.y() + j)) {
                    moves.add(Point.of(currPosition.x() + i, currPosition.y() + j));
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
