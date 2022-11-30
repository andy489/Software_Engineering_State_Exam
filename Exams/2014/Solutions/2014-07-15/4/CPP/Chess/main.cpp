#include "./ChessPiece/Rook.h";
#include "./ChessPiece/Knight.h";

using namespace ROOK;
using namespace KNIGHT;

void allMoves(ChessPiece **pieces, int n) {
    for (int i = 0; i < n; ++i) {
        ChessPiece *currChessPiece = pieces[i];

        vector<ChessPosition> currMoves = currChessPiece->allowedMoves();

        bool flagFirst = true;

        for (ChessPosition &move: currMoves) {
            bool makesConflict = false;

            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }

                if (pieces[j]->captures(move)) {
                    makesConflict = true;
                    break;
                }
            }

            if (!makesConflict) {
                if (flagFirst) {
                    cout << currChessPiece->getType() << ' ' << currChessPiece->getPosition() << " -> " << move;
                    flagFirst = false;
                } else {
                    cout << ", " << move;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    ChessPiece *allPieces[2];
    Rook r1{'A', 1};
    Knight k1{'B', 3};

    allPieces[0] = &r1;
    allPieces[1] = &k1;

    allMoves(allPieces, 2);

    return 0;
}
