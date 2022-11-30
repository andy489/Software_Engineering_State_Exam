#pragma once

#include <iostream>

using namespace std;

namespace CHESS_POS {
    class ChessPosition {
        char row;
        short col;

    public:
        ChessPosition();
        ChessPosition(char row, short col) : col(col), row(row) {}

        char getRow();
        short getCol();

        bool operator==(const ChessPosition &otherPos) const;

        friend ostream &operator<<(ostream &os, const ChessPosition &pos);
    };
}