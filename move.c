#include "move.h"

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _ERR_H
    #include "err.h"
#endif

/**
 * Create a new possible moves.
 * 
 * @param void
 * 
 * @return Possible moves.
*/
Move newMove() {
    Move *new = (Move *) malloc(sizeof(Move));

    if (!new) memoryErr();

    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j ++) new->board[i][j] = 0;

    return *new;

    free(new);
}

/**
 * Get all possible moves.
 * 
 * @param from   Origin position;
 * @param board  Board of game.
 * 
 * @return All possible moves of piece;
*/
Move possibleMoves(Position from, Board board) {
    Move move = newMove();

    if (board.pieces[from.row][from.column]->color == 'W') {
        if (validPosition((from.row - 1), (from.column - 1)) && !board.pieces[from.row - 1][from.column - 1]) {
            Position pos = newPosition((from.row - 1), (from.column - 1));
            move.board[pos.row][pos.column] = 1;
        }
        if (validPosition((from.row - 1), (from.column + 1)) && !board.pieces[from.row - 1][from.column + 1]) {
            Position pos = newPosition((from.row - 1), (from.column + 1));
            move.board[pos.row][pos.column] = 1;
        }
    } else {
        if (validPosition((from.row + 1), (from.column - 1)) && !board.pieces[from.row + 1][from.column - 1]) {
            Position pos = newPosition((from.row + 1), (from.column - 1));
            move.board[pos.row][pos.column] = 1;
        }
        if (validPosition((from.row + 1), (from.column + 1)) && !board.pieces[from.row + 1][from.column + 1]) {
            Position pos = newPosition((from.row + 1), (from.column + 1));
            move.board[pos.row][pos.column] = 1;
        }
    }

    return move;
}

/**
 * Make a moviment.
 * 
 * @param board  Board of game;
 * @param from   Origin position;
 * @param to     Destination position;
 * 
 * @return Board with moviment
*/
Board makeMove(Board board, Position from, Position to) {
    Board new = board;
    Piece *temp = NULL;

    temp = new.pieces[from.row][from.column];
    new.pieces[from.row][from.column] = NULL;
    new.pieces[to.row][to.column] = temp;

    return new;
}

/**
 * Verify if exist possible move to piece.
 * 
 * @param move  Possible moves.
 * 
 * @return True(1) or False(0).
*/
int existsMove(Move move) {
    for (int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) if (move.board[i][j]) return 1;
    return 0;
}