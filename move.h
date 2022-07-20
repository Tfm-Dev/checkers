#ifndef _MOVE_H_
#define _MOVE_H_

#ifndef _POSITION_H_
    #include "position.h"
#endif

#ifndef _BOARD_H
    #include "board.h"
#endif

/**
 * Possible Moves
 * ==========================================
 * int board[8][8] - Board of possible moves;
 * ==========================================
*/
typedef struct{
    int board[8][8];
}Move;

// Functions with return Move 
Move newMove();
Move possibleMoves(Position from, Board board);

// Functions with board return
Board makeMove(Board board, Position from, Position to) ;

// Valid Functions
int existsMove(Move move);

#endif