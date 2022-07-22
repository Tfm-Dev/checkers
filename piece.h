#ifndef _PIECE_H_
#define _PIECE_H_

/**
 * Piece
 * ============================
 * char type - Type of piece;
 * char color - Color of Piece;
 * ============================
*/
typedef struct {
    char type;
    char color;
}Piece;

// Create Function
Piece *newPiece(char type, char color);

#endif