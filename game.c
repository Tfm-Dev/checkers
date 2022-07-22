#include "game.h"

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _BOARD_H_
    #include "board.h"
#endif

#ifndef _GUI_H_
    #include "gui.h"
#endif

#ifndef _POSITION_H_
    #include "position.h"
#endif

#ifndef _MOVE_H_
    #include "move.h"
#endif

#ifndef _ERR_H_
    #include "err.h"
#endif

/**
 * Game State
 * ============================================================
 * int turn - Current turn of game;
 * char currentPlayer - Current player of game;
 * int movesWithoutCaptureOrPromotion - Count moves without Capture or Promotion (Draw);
 * Board board - the Board of game;
 * struct GameState* next - Next Game State.
 * ============================================================
*/
struct GameState{
    int turn;
    char currentPlayer;
    int movesWithoutCaptureOrPromotion;
    Board board;
    struct GameState* next;
};

void startGame();
struct GameState *newGameState(int turn, char currentPlayer, int movesWithoutCaptureOrPromotion, Board board);
struct GameState *insertGameState(struct GameState *gameState, int turn, char currentPlayer, int movesWithoutCaptureOrPromotion, Board board);
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

    current = gameState = newGameState(1, 'W', 0, newBoard());

    // Game loop
    while(!finishGame(current->board, current->movesWithoutCaptureOrPromotion)) {
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
        Move move = possibleMoves(current->board, from);

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
        gameState = insertGameState(gameState, (current->turn + 1), current->currentPlayer == 'W' ? 'B' : 'W', 0, makeMove(current->board, from, to));

        // Update Game State current
        current = currentGameState(gameState);
    }

    // winOrDraw() ? printWinner(getWinner()) : printDraw();

    // Free memory
    current = gameState;

    while (current != NULL) {
        gameState = current->next;
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) free(current->board.pieces[i][j]);
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
struct GameState *newGameState(int turn, char currentPlayer, int movesWithoutCaptureOrPromotion, Board board) {
    struct GameState *gameState = (struct GameState *) malloc(sizeof(struct GameState));

    if(!gameState) memoryErr();

    gameState->turn = turn;
    gameState->currentPlayer = currentPlayer;
    gameState->movesWithoutCaptureOrPromotion = movesWithoutCaptureOrPromotion;
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
struct GameState *insertGameState(struct GameState *gameState, int turn, char currentPlayer, int movesWithoutCaptureOrPromotion, Board board) {   
    if (gameState == NULL) return newGameState(turn, currentPlayer, movesWithoutCaptureOrPromotion, board);

    gameState->next = insertGameState(gameState->next, turn, currentPlayer, movesWithoutCaptureOrPromotion, board);

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
int finishGame(Board board, int movesWithoutCaptureOrPromotion) {
    int white, black;
    white = black = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.pieces[i][j] && board.pieces[i][j]->color == 'W') white += 1;
            if (board.pieces[i][j] && board.pieces[i][j]->color == 'B') black += 1;
        }
    }
    if (white == 0 || black == 0) return 1;
    if (movesWithoutCaptureOrPromotion >= 40) return 1;
    return 0;
}