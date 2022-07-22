#include "piece.h"

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _ERR_H_
    #include "err.h"
#endif

/**
 * Create a new Piece
 * 
 * @param type   Type of Piece: 'M' or 'K';
 * @param color  Color of Piece: 'W' or 'B'.
 * 
 * @return Piece pointer
*/
Piece *newPiece(char type, char color) {
    Piece *piece = (Piece *) malloc(sizeof(Piece));

    if (!piece) memoryErr();

    piece->type = type;
    piece->color = color;

    return piece;
}