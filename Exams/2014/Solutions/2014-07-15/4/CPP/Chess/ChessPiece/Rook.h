#pragma once

#include "ChessPiece.h";

using namespace CHESS_PIECE;

namespace ROOK {
    class Rook : public ChessPiece {
    public:

        Rook(char row, short col);

        vector<ChessPosition> allowedMoves() override;

        string getType() override;

    };
}