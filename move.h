#ifndef _MOVE_H_
#define _MOVE_H_

#ifndef _POSITION_H_
    #include "position.h"
#endif

#ifndef _BOARD_H_
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
Move possibleMoves(Board board, Position from);

// Functions with board return
Board makeMove(Board board, Position from, Position to);

// Valid Functions
int existsMove(Move move);
int possibleCapture(Board board, Position from);

#endif