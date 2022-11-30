#include "ChessPiece.h"

ChessPosition CHESS_PIECE::ChessPiece::getPosition() {
    return currentPosition;
}

bool CHESS_PIECE::ChessPiece::captures(ChessPosition pos) {
    vector<ChessPosition> moves = allowedMoves();

    return any_of(moves.begin(), moves.end(), [&](ChessPosition p) { return p == pos; });
}
