#ifndef PIECE_H_
#define PIECE_H_

#include "position.h"

typedef struct {
    char type;
    char color;
    Position position;
}Piece;

Piece newPiece(char type, char color, Position position);

#endif