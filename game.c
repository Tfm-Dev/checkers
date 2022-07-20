#include "game.h"

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _BOARD_H
    #include "board.h"
#endif

#ifndef _GUI_H 
    #include "gui.h"
#endif

#ifndef _POSITION_H
    #include "position.h"
#endif

#ifndef _MOVE_H
    #include "move.h"
#endif

#ifndef _ERR_H
    #include "err.h"
#endif

/**
 * Game State
 * ==============================================
 * int turn - Current turn of game;
 * char currentPlayer - Current player of game;
 * Board board - the Board of game;
 * struct GameState* next - Next Game State.
 * ==============================================
*/
struct GameState{
    int turn;
    char currentPlayer;
    Board board;
    struct GameState* next;
};

void startGame();
struct GameState *newGameState(int turn, char currentPlayer, Board board);
struct GameState *insertGameState(struct GameState *gameState, int turn, char currentPlayer, Board board);
struct GameState *currentGameState(struct GameState *gameState);
int finishGame();

/**
 * Init game
 * 
 * @param void
 * 
 * @return void
*/
void init() {
    do {
        switch (menu())
        {
            case 1:
                startGame();
                continue;
            case 2:
                continue;
            case 3:
                continue;
            default:
                break;
        }
        break;
    } while(1);
}

/**
 * Start new game
 * 
 * @param void
 * 
 * @return void
*/
void startGame() {
    struct GameState *gameState, *current;
    char *choise = (char*) malloc(sizeof(char) * 2);

    current = gameState = newGameState(1, 'W', newBoard());

    // Game loop
    while(!finishGame()) {
        printState(current->board, current->turn, current->currentPlayer, choise);

        // Valid Position
        if (!validPlayerPosition(choise[1], choise[0])) {
            invalidPositionWarning();
            continue;
        }

        // Get Position from
        Position from = fromPlayerPosition(choise[1], choise[0]);

        // Valid Piece in Position
        if (!existPieceInPosition(current->board, from)) {
            invalidPieceInPositionWarning();
            continue;
        }

        // Valid Piece is a current player
        if (!colorPieceIsCurrent(current->board, from, current->currentPlayer)) {
            invalidPieceWarning();
            continue;
        }

        // Get all possible moves
        Move move = possibleMoves(from, current->board);

        // Valid if exists possible move
        if (!existsMove(move)) {
            notPossibleMoveWarning();
            continue;
        }

        // Position to
        Position to;

        do {
            printMove(current->board, move, choise);

            // Valid Position
            if (!validPlayerPosition(choise[1], choise[0])) {
                invalidPositionWarning();
                continue;
            }   

            // Get Postion to
            to = fromPlayerPosition(choise[1], choise[0]);

            // Valid Position Move
            if (!move.board[to.row][to.column]) {
                invalidMoveWarning();
                continue;
            }

            break;
        } while(1);

        // Save moviment
        gameState = insertGameState(gameState, (current->turn + 1), current->currentPlayer == 'W' ? 'B' : 'W', makeMove(current->board, from, to));

        // Update Game State current
        current = currentGameState(gameState);
    }

    // Free memory
    current = gameState;

    while (current != NULL) {
        gameState = current->next;
        free(current);
        current = gameState;
    }
}

/**
 * Create a new game state.
 * 
 * @param turn           Current turn a state;
 * @param currentPlayer  Current player a state;
 * @param board          Current board a state.
 * 
 * @return GameState pointer.
*/
struct GameState *newGameState(int turn, char currentPlayer, Board board) {
    struct GameState *gameState = (struct GameState *) malloc(sizeof(struct GameState));

    if(!gameState) memoryErr();

    gameState->turn = turn;
    gameState->currentPlayer = currentPlayer;
    gameState->board = board;
    gameState->next = NULL;

    return gameState;
}

/**
 * Insert new game state.
 * 
 * @param gameState      GameState pointer an insert;
 * @param turn           Current turn a game state to insert;
 * @param currentPlayer  Current player a game state to insert;
 * @param board          Current board a game state to insert.
 * 
 * @return GameState pointer.
*/
struct GameState *insertGameState(struct GameState *gameState, int turn, char currentPlayer, Board board) {   
    if (gameState == NULL) return newGameState(turn, currentPlayer, board);

    gameState->next = insertGameState(gameState->next, turn, currentPlayer, board);

    return gameState;
}

/**
 * Get a current Game State in the main Game State.
 * 
 * @param gameState  Main Game State.
 * 
 * @return current Game State pointer.
*/
struct GameState *currentGameState(struct GameState *gameState) {
    if (gameState->next == NULL) return gameState;
    return currentGameState(gameState->next);
}

/**
 * Verify a state of game
 * 
 * @return True(1) or False(0).
*/
int finishGame() {
    return 0;
}