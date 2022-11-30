#include <iostream>
#include <vector>

using namespace std;

const int N = 5;
const int GameBoard[][N] = {
        {1,   1,   0, 2, 0},
        {0,   2,   1, 0, 2},
        {2,   'S', 2, 2, 1},
        {0,   2,   2, 2, 0},
        {'K', 2,   1, 1, 1}
};

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    friend ostream &operator<<(ostream &os, const Point &pt) {
        os << '(' << pt.x << ',' << pt.y << ')';
        return os;
    }
};

enum PieceType {
    KNIGHT,
    SEA_MONSTER
};

enum LandType {
    EARTH = 0,
    FIRE,
    WATER
};

class GamePlayer {
protected:
    Point currPosition;

    static bool isInsideBoard(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < N;
    }

public:
    GamePlayer(int x, int y) : currPosition(x, y) {}

    Point getPosition() {
        return currPosition;
    }

    bool isNeighbourTo(Point pos) const {
        return abs(currPosition.x - pos.x) <= 1 && abs(currPosition.y - pos.y) <= 1;
    }

    virtual vector<Point> allowedMoves() = 0;

    virtual PieceType getType() = 0;
};

class Knight : public GamePlayer {
private:
    static bool checkPosition(int x, int y) {
        if (GameBoard[x][y] != 0) {
            return false;
        }

        for (int i = -1; i <= 1; ++i) {
            for (int j = 0; j < 1; ++j) {
                if (isInsideBoard(x + i, y + j) && GameBoard[x + i][x + j] == LandType::FIRE) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    Knight(int x, int y) : GamePlayer(x, y) {}

    vector<Point> allowedMoves() override {
        vector<Point> moves;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) { continue; }

                if (isInsideBoard(currPosition.x + i, currPosition.y + j) &&
                    checkPosition(currPosition.x + i, currPosition.y + j)) {
                    moves.emplace_back(currPosition.x + i, currPosition.y + j);
                }
            }
        }

        return moves;
    }

    PieceType getType() override {
        return PieceType::KNIGHT;
    }

    ~Knight() = default;
};

class SeaMonster : public GamePlayer {

public:
    SeaMonster(int x, int y) : GamePlayer(x, y) {}

    vector<Point> allowedMoves() override {
        vector<Point> moves;

        for (int i = -1; currPosition.x + i >= 0; i--) {
            if (GameBoard[currPosition.x + i][currPosition.y] != LandType::WATER) { break; }
            moves.emplace_back(currPosition.x + i, currPosition.y);
        }

        for (int i = 1; currPosition.x + i < N; i++) {
            if (GameBoard[currPosition.x + i][currPosition.y] != LandType::WATER) { break; }
            moves.emplace_back(currPosition.x + i, currPosition.y);
        }

        for (int i = -1; currPosition.y + i >= 0; i--) {
            if (GameBoard[currPosition.x][currPosition.y + i] != LandType::WATER) { break; }
            moves.emplace_back(currPosition.x, currPosition.y + i);
        }

        for (int i = 1; currPosition.y + i < N; i++) {
            if (GameBoard[currPosition.x][currPosition.y + i] != LandType::WATER) { break; }
            moves.emplace_back(currPosition.x, currPosition.y + i);
        }

        return moves;
    }

    PieceType getType() override {
        return PieceType::SEA_MONSTER;
    }

    ~SeaMonster() = default;
};

void allMoves(GamePlayer **players, size_t n) {
    for (int i = 0; i < n; ++i) {
        GamePlayer *currentPlayer = players[i];
        vector<Point> allowedMovesForIthPlayer = currentPlayer->allowedMoves();

        for (const Point move: allowedMovesForIthPlayer) {
            for (int j = 0; j < n; ++j) {
                if (i != j && players[j]->isNeighbourTo(move)) {
                    cout << (currentPlayer->getType() == PieceType::KNIGHT ? "Knight" : "Sea Monster") << " "
                         << currentPlayer->getPosition() << " -> " << move << endl;
                }
            }
        }
    }
}

int main() {
    GamePlayer *players[2]{new Knight(4, 0), new SeaMonster(2, 1)};
    allMoves(players, 2);

    return 0;
}
