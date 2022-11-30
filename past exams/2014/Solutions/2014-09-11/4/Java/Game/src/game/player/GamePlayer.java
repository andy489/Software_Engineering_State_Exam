package game.player;

import game.model.GameBoard;
import game.model.PieceType;
import game.model.Point;

import java.util.List;

public abstract class GamePlayer {
    protected Point currPosition;
    protected static final int N = GameBoard.board.length;

    public Point getPosition() {
        return currPosition;
    }

    static boolean isInsideBoard(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

    public GamePlayer(int x, int y) {
        this.currPosition = new Point(x, y);
    }

    public boolean isNeighbourTo(final Point pos) {
        return Math.abs(currPosition.x() - pos.x()) <= 1 && Math.abs(currPosition.y() - pos.y()) <= 1;
    }

    public abstract List<Point> allowedMoves();

    public abstract PieceType getType();
}
