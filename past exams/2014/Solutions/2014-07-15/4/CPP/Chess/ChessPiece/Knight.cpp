#include "Knight.h"

KNIGHT::Knight::Knight(char row, short col) {
    this->currentPosition = {row, col};
}

vector<ChessPosition> KNIGHT::Knight::allowedMoves() {
    vector<ChessPosition> moves;

    for (char c = 'A'; c <= 'H'; c++) {
        for (short s = 1; s <= 8; s++) {
            if (currentPosition.getRow() != c && currentPosition.getCol() != s && isKnightMove(c, s)) {
                moves.emplace_back(c, s);
            }
        }
    }

    return moves;
}

string KNIGHT::Knight::getType() {
    return "Knight";
}

bool KNIGHT::Knight::isKnightMove(char row, short col) {
    return (abs(currentPosition.getRow() - row) + abs(currentPosition.getCol() - col)) == 3;
}
