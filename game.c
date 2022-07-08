#include "game.h"
#include <stdio.h>

enum State {
    RUNNING = 1,
    WINNER = 2,
    DRAW = 3
};

typedef struct {
    enum State state;
    int stage;
}Game;

Game newGame();

void run() {
    Game game = newGame();
    printf("Test game state: %d and stage: %d\n", game.state, game.stage);
    while(1);
}

Game newGame() {
    Game game = {
        RUNNING,
        1
    };
    return game;
}