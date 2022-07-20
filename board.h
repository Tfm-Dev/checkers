#ifndef _BOARD_H
#define _BOARD_H

#ifndef _PIECE_H
    #include "piece.h"
#endif

#ifndef _POSITION_H
    #include "position.h"
#endif

/**
 * Board
 * ======================================
 * Piece *pieces[8][8] - Board of pieces;
 * ======================================
*/
typedef struct {
    Piece *pieces[8][8];
}Board;

// Create Function
Board newBoard();

// Valid Functions
int existPieceInPosition(Board board, Position pos);
int colorPieceIsCurrent(Board board, Position pos, char currentPlayer);

#endif