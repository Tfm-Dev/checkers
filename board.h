#ifndef _BOARD_H_
#define _BOARD_H_

#ifndef _PIECE_H_
    #include "piece.h"
#endif

#ifndef _POSITION_H_
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