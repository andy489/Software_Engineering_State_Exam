#pragma once

#include "./../ChessPosition/ChessPos.h"

#include <vector>

using namespace CHESS_POS;
using namespace std;

namespace CHESS_PIECE {
    class ChessPiece {
    protected:
        ChessPosition currentPosition;

    public:
        ChessPosition getPosition();

        virtual vector<ChessPosition> allowedMoves() = 0;

        virtual string getType() = 0;

        bool captures(ChessPosition pos);
    };
}