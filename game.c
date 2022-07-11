#include "game.h"

#include "gui.h"
#include <stdlib.h>

void newGame();
void makeMove(Move move, Board* board);
char newTurn(char currentPlayer);

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
    int select;
    int countMove;
    Position position;
    while(game.state != WINNER || game.state != DRAW) {
        move = (Move*) calloc(1, sizeof(Move));
        choise = (char*) calloc(2, 2 * sizeof(char));
        printState(game, choise);
        if (!validPlayerPosition(choise[1], choise[0])) { 
            printInvalidPosition();
            continue;
        }
        position = fromPlayerPosition(choise[1], choise[0]);
        countMove = possibleMoves(game.board, position, &move, 0);
        do {
        printMove(game, move, countMove, choise);
        position = fromPlayerPosition(choise[1], choise[0]);
        if (!validPlayerPosition(choise[1], choise[0])) { 
            printInvalidPosition();
            continue;
        }
        select = selectMove(position, move, countMove);
        if (select == -1) printInvalidMove();
        } while(select == -1);
        makeMove(move[select], &game.board);
        game.stage += 1;
        game.currentPlayer = newTurn(game.currentPlayer);
    }
    free(move);
    free(choise);
}

void makeMove(Move move, Board* board) {
    Piece swap = board->board[move.from.row][move.from.column];
    Piece* null = (Piece *) calloc(1, sizeof(Piece));
    board->board[move.from.row][move.from.column] = *null;
    board->board[move.to.row][move.to.column] = swap;
}

char newTurn(char currentPlayer) {
    return currentPlayer == 'W' ? 'B' : 'W';
}

void endGame() {

}