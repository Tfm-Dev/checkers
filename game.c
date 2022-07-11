#include "game.h"

#include "gui.h"
#include <stdlib.h>

void newGame();
void makeMove(Move move);

void run() {
    int choise;
    menu(&choise);
    do {
        switch (choise)
        {
            case 1:
                newGame();
                break;
            case 2:
                load();
                break;
            case 3:
                instruction();
                break;
            default:
                break;
        }
    } while(choise == 3);
}

void newGame() {
    Game game = {
        PLAY,
        1,
        newBoard(),
        'W'
    };
    char* choise;
    Move* move;
    Position position;
    while(game.state != WINNER || game.state != DRAW) {
        choise = (char*) calloc(2, 2 * sizeof(char));
        printState(game, choise);
        if (!validPlayerPosition(choise[1], choise[0])) { 
            printInvalidMove();
            continue;
        }
        position = fromPlayerPosition(choise[1], choise[0]);
        possibleMoves(game.board, position, &move, 0);
        printMove(game, move);
    }
    free(move);
    free(choise);
}

void makeMove(Move move) {

}

void endGame() {

}