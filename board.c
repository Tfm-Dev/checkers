#include "board.h"

#include "position.h"
#include <stdlib.h>

Board newBoard() {
    Board* board = (Board *) calloc(1, sizeof(Board));
    
    (*board).board[0][1] = newPiece('M', 'B', toPosition(0, 1));
    (*board).board[0][3] = newPiece('M', 'B', toPosition(0, 3));
    (*board).board[0][5] = newPiece('M', 'B', toPosition(0, 5));
    (*board).board[0][7] = newPiece('M', 'B', toPosition(0, 7));

    (*board).board[1][0] = newPiece('M', 'B', toPosition(1, 0));
    (*board).board[1][2] = newPiece('M', 'B', toPosition(1, 2));
    (*board).board[1][4] = newPiece('M', 'B', toPosition(1, 4));
    (*board).board[1][6] = newPiece('M', 'B', toPosition(1, 6));

    (*board).board[2][1] = newPiece('M', 'B', toPosition(2, 1));
    (*board).board[2][3] = newPiece('M', 'B', toPosition(2, 3));
    (*board).board[2][5] = newPiece('M', 'B', toPosition(2, 5));
    (*board).board[2][7] = newPiece('M', 'B', toPosition(2, 7));

    (*board).board[5][0] = newPiece('M', 'W', toPosition(1, 0));
    (*board).board[5][2] = newPiece('M', 'W', toPosition(1, 2));
    (*board).board[5][4] = newPiece('M', 'W', toPosition(1, 4));
    (*board).board[5][6] = newPiece('M', 'W', toPosition(1, 6));

    (*board).board[6][1] = newPiece('M', 'W', toPosition(2, 1));
    (*board).board[6][3] = newPiece('M', 'W', toPosition(2, 3));
    (*board).board[6][5] = newPiece('M', 'W', toPosition(2, 5));
    (*board).board[6][7] = newPiece('M', 'W', toPosition(2, 7));

    (*board).board[7][0] = newPiece('M', 'W', toPosition(1, 0));
    (*board).board[7][2] = newPiece('M', 'W', toPosition(1, 2));
    (*board).board[7][4] = newPiece('M', 'W', toPosition(1, 4));
    (*board).board[7][6] = newPiece('M', 'W', toPosition(1, 6));

    return *board;
}

int possibleMoves(Board board, Position position, Move** move, int countMove) {
    Move try = { position, position };
    if (board.board[position.row][position.column].type != 0) {
        if (board.board[position.row][position.column].color == 'B') {
            if(validPosition(++try.to.row, --try.to.column)) {
                if (validMove(board, try)) { 
                    countMove++;
                    *move = (Move*) realloc(*move, (countMove * sizeof(Move)));
                    *(*move + (countMove - 1)) = try;
                }
            }
            try.to = position;
            if(validPosition(++try.to.row, ++try.to.column)) {
                if (validMove(board, try)) { 
                    countMove++;
                    *move = (Move*) realloc(*move, (countMove * sizeof(Move)));
                    *(*move + (countMove - 1)) = try;
                }
            }
        } else {
            if(validPosition(--try.to.row, --try.to.column)) {
                if (validMove(board, try)) { 
                    countMove++;
                    *move = (Move*) realloc(*move, (countMove * sizeof(Move)));
                    *(*move + (countMove - 1)) = try;
                }
            }
            try.to = position;
            if(validPosition(--try.to.row, ++try.to.column)) {
                if (validMove(board, try)) { 
                    countMove++;
                    *move = (Move*) realloc(*move, (countMove * sizeof(Move)));
                    *(*move + (countMove - 1)) = try;
                }
            }
        }
    }

    return countMove;
}

int validMove(Board board, Move move) {
    if (board.board[move.from.row][move.from.column].type != 0) {
        if (board.board[move.to.row][move.to.column].type != 0) {
            return 0;
        } 
        return 1;
    }
    return 0;
}

int selectMove(Position position, Move* move, int countMove) {
    int select = -1;
    for (int i = 0; i < countMove; i++) {
        if (move[i].to.row == position.row && move[i].to.column == position.column) {
            select = i;
            break;
        }
    }
    return select;
}