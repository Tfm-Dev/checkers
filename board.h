#ifndef BOARD_H_
#define BOARD_H_

#include "piece.h"
#include "position.h"

typedef struct {
    Piece board[8][8];
}Board;

typedef struct {
    Position from;
    Position to;
}Move;

Board newBoard();
int possibleMoves(Board board, Position position, Move** move, int countMove);
int validMove(Board board, Move move);

#endif