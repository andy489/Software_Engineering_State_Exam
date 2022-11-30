#pragma once

#include "ChessPiece.h";

using namespace CHESS_PIECE;

namespace KNIGHT {
    class Knight : public ChessPiece {
    private:
        bool isKnightMove(char row, short col);
    public:
        Knight(char row, short col);
        vector<ChessPosition> allowedMoves() override;
        string getType() override;
    };
}