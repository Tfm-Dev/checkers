#ifndef _GUI_H_
#define _GUI_H_

#ifndef _BOARD_H_
    #include "board.h"
#endif

#ifndef _MOVE_H_
    #include "move.h"
#endif

// Choise functions
int menu();
void printState(Board board, int turn, char currentPlayer, char *choise);
void printMove(Board board, Move move, char *choise);

// Print functions
void printBoard(Board board, Move *move);
void printWinner(char winner);
void printDraw();

#endif