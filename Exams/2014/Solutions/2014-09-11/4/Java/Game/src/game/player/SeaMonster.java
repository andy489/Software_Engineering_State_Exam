package game.player;

import game.model.GameBoard;
import game.model.LandType;
import game.model.PieceType;
import game.model.Point;

import java.util.ArrayList;
import java.util.List;

public class SeaMonster extends GamePlayer {

    public SeaMonster(int x, int y) {
        super(x, y);
    }

    @Override
    public List<Point> allowedMoves() {
        List<Point> moves = new ArrayList<>();

        for (int i = -1; currPosition.x() + i >= 0; i--) {
            if (GameBoard.board[currPosition.x() + i][currPosition.y()] != LandType.WATER.getCode()) {
                break;
            }
            moves.add(Point.of(currPosition.x() + i, currPosition.y()));
        }

        for (int i = 1; currPosition.x() + i < N; i++) {
            if (GameBoard.board[currPosition.x() + i][currPosition.y()] != LandType.WATER.getCode()) {
                break;
            }
            moves.add(Point.of(currPosition.x() + i, currPosition.y()));
        }

        for (int i = -1; currPosition.y() + i >= 0; i--) {
            if (GameBoard.board[currPosition.x()][currPosition.y() + i] != LandType.WATER.getCode()) {
                break;
            }
            moves.add(Point.of(currPosition.x(), currPosition.y() + i));
        }

        for (int i = 1; currPosition.y() + i < N; i++) {
            if (GameBoard.board[currPosition.x()][currPosition.y() + i] != LandType.WATER.getCode()) {
                break;
            }
            moves.add(Point.of(currPosition.x(), currPosition.y() + i));
        }

        return moves;
    }

    @Override
    public PieceType getType() {
        return PieceType.SEA_MONSTER;
    }
}
