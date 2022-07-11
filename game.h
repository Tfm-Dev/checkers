#ifndef GAME_H_
#define GAME_H_

#include "board.h"
#include "piece.h"

enum State {
    PLAY = 1,
    WINNER = 2,
    DRAW = 3
};

typedef struct {
    enum State state;
    int stage;
    Board board;
    char currentPlayer;
}Game;

void run();

#endif