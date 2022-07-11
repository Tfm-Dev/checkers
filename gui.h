#ifndef GUI_H_
#define GUI_H_

#include "game.h"
#include "board.h"

void menu(int* choise);
void printState(Game gameState, char* choise);
void printBoard(Board board);
void load();
void instruction();
void winner(char winner);
void draw();
void printInvalidPosition();
void printMove(Game game, Move* move, int countMove, char* choise);
void printInvalidMove();

#endif