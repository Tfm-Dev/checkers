#include "board.h"

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _ERR_H
    #include "err.h"
#endif

/**
 * Create a new checkers board.
 * 
 * @param void
 * 
 * @return New Checkers board.
*/
Board newBoard() {
    Board *board = (Board *) calloc(1, sizeof(Board));

    if (!board) memoryErr();
    
    (*board).pieces[0][1] = newPiece('M', 'B');
    (*board).pieces[0][3] = newPiece('M', 'B');
    (*board).pieces[0][5] = newPiece('M', 'B');
    (*board).pieces[0][7] = newPiece('M', 'B');

    (*board).pieces[1][0] = newPiece('M', 'B');
    (*board).pieces[1][2] = newPiece('M', 'B');
    (*board).pieces[1][4] = newPiece('M', 'B');
    (*board).pieces[1][6] = newPiece('M', 'B');

    (*board).pieces[2][1] = newPiece('M', 'B');
    (*board).pieces[2][3] = newPiece('M', 'B');
    (*board).pieces[2][5] = newPiece('M', 'B');
    (*board).pieces[2][7] = newPiece('M', 'B');

    (*board).pieces[5][0] = newPiece('M', 'W');
    (*board).pieces[5][2] = newPiece('M', 'W');
    (*board).pieces[5][4] = newPiece('M', 'W');
    (*board).pieces[5][6] = newPiece('M', 'W');

    (*board).pieces[6][1] = newPiece('M', 'W');
    (*board).pieces[6][3] = newPiece('M', 'W');
    (*board).pieces[6][5] = newPiece('M', 'W');
    (*board).pieces[6][7] = newPiece('M', 'W');

    (*board).pieces[7][0] = newPiece('M', 'W');
    (*board).pieces[7][2] = newPiece('M', 'W');
    (*board).pieces[7][4] = newPiece('M', 'W');
    (*board).pieces[7][6] = newPiece('M', 'W');

    return *board;

    free(board);
}

/**
 * Verify if exist piece in position.
 * 
 * @param board
 * @param position
 * 
 * @return True(1) or False(0)
*/
int existPieceInPosition(Board board, Position pos) {
    return board.pieces[pos.row][pos.column] ? 1 : 0;
}

/**
 * Verify if the piece belongs to current player
 * 
 * @param board
 * @param position 
 * @param currentPlayer
 * 
 * @return True(1) or False(0)
*/
int colorPieceIsCurrent(Board board, Position pos, char currentPlayer) {
    return board.pieces[pos.row][pos.column]->color == currentPlayer ? 1 : 0;
}