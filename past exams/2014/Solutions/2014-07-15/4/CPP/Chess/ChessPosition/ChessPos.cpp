#include "ChessPos.h"

bool CHESS_POS::ChessPosition::operator==(const ChessPosition &otherPos) const {
    return row == otherPos.row && col == otherPos.col;
}

ostream &CHESS_POS::operator<<(ostream &os, const CHESS_POS::ChessPosition &pos) {
    os << pos.row << pos.col;
    return os;
}

CHESS_POS::ChessPosition::ChessPosition() {
    row = 'A';
    col = 1;
}

char CHESS_POS::ChessPosition::getRow() {
    return row;
}

short CHESS_POS::ChessPosition::getCol() {
    return col;
}
