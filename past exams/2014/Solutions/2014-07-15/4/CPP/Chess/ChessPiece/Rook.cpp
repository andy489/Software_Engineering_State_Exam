#include "Rook.h"

ROOK::Rook::Rook(char row, short col) {
    this->currentPosition = {row, col};
}

vector<ChessPosition> ROOK::Rook::allowedMoves() {
    vector<ChessPosition> moves;

    for (char c = 'A'; c <= 'H'; c++) {
        if (c != currentPosition.getRow()) {
            moves.emplace_back(c, currentPosition.getCol());
        }
    }

    for (short s = 1; s <= 8; s++) {
        if (s != currentPosition.getCol()) {
            moves.emplace_back(currentPosition.getRow(), s);
        }
    }

    return moves;
}

string ROOK::Rook::getType() {
    return "Rook";
}
