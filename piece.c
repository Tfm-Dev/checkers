#include "piece.h"

Piece newPiece(char type, char color, Position position) {
    Piece piece = {
        type,
        color,
        position
    };
    return piece;
}