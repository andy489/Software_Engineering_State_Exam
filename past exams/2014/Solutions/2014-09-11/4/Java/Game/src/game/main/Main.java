package game.main;

import game.model.Point;
import game.player.GamePlayer;
import game.player.Knight;
import game.player.SeaMonster;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void allMoves(List<GamePlayer> players) {
        final int n = players.size();

        for (int i = 0; i < n; ++i) {
            GamePlayer currPlayer = players.get(i);
            List<Point> allowedMovesForIthPlayer = currPlayer.allowedMoves();

            for (final Point move : allowedMovesForIthPlayer) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && players.get(j).isNeighbourTo(move)) {
                        System.out.println(currPlayer.getType() + " " + currPlayer.getPosition() + " -> " + move);
                    }
                }
            }
        }
    }

    public static void main(String... args) {
        List<GamePlayer> players = new ArrayList<>(
                Arrays.asList(new Knight(4, 0), new SeaMonster(2, 1))
        );

        allMoves(players);
    }
}
