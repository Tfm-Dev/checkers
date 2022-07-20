#include "gui.h"

#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#ifndef _CONSTANTS_H
    #include "constants.h"
#endif

/**
 * clear console screen in Windows and Linux
 * 
 * @return void
 * @see clean console screen
*/
void clear() {
#ifdef _WIN32
    system("cls");
#elif defined(__UNIX__)
    printf("\033[H\033[J");
#endif
}

/**
 * Displays the main menu and allows the player to make a choice
 * The possible choices are:
 * 1 - New Game;
 * 2 - Load a game;
 * 3 - Instructions;
 * Any value - Exit application.
 * 
 * @return The choise of player.
 * @see The main menu.
*/
int menu() {
    int choise;

    clear();

    printf("===================\n");
    printf("|    Checkers     |\n");
    printf("|       in        |\n");
    printf("|       C         |\n");
    printf("===================\n");
    printf("|1- New Game      |\n");
    printf("|2- Load Game     |\n");
    printf("|3- Instruction   |\n");
    printf("|4- Exit          |\n");
    printf("===================\n");
    printf("Choise: ");

    scanf("%d", &choise);
    getchar();

    return choise;
}

/**
 * Display board with game state information.
 * 
 * @param Board          The board of game;
 * @param turn           The current turn of game;
 * @param currentPlayer  The current player of game.
 * 
 * @return void.
 * @see The board, turn and current player.
*/
void printState(Board board, int turn, char currentPlayer, char *choise) {
    clear();
    printBoard(board, NULL);

    printf("Turn: %d\n", turn);
    printf("Current Player: %c\n", currentPlayer);
    printf("Choise: ");

    scanf("%s", choise);
    getchar();
}

/**
 * Display board with possible moves.
 * 
 * @param board   The board of game;
 * @param move    The possible moves;
 * @param choise  The choise of player.
 * 
 * @return void.
 * @see The board with possible moves.
*/
void printMove(Board board, Move move, char *choise) {
    clear();
    printBoard(board, &move);

    printf("Choise move: ");

    scanf("%s", choise);
    getchar();
}

/**
 * Display board of game.
 * 
 * @param board  The board of game;
 * @param move   Possible moves pointer.
 * 
 * @return void.
 * @see The Board.
*/
void printBoard(Board board, Move *move) {
    printf("  _ _ _ _ _ _ _ _\n");
    for(int i = 0; i < 8; i++) {
        printf("%d|", 8-i);
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0 && j % 2 != 0) printf(ANSI_BGCOLOR_GREY);
                else
                    if (i % 2 != 0 && j % 2 == 0) printf(ANSI_BGCOLOR_GREY);
            if (board.pieces[i][j] != NULL) {
                printf("\033[4m");
                if (board.pieces[i][j]->color == 'B') printf(ANSI_COLOR_BLACK);
                else printf(ANSI_COLOR_WHITE);
                printf("%c" ANSI_COLOR_RESET "|", board.pieces[i][j]->type);
            }
            else {
                if (move && move->board[i][j]) printf(ANSI_BGCOLOR_GREEN);
                printf("_" ANSI_COLOR_RESET "|");
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

/**
 * Display player winner game.
 * 
 * @param winner The player winner.
 * 
 * @return void.
 * @see winner.
*/
void winner(char winner) {
    printf("===================\n");
    printf("|                 |\n");
    winner == 'w' ? printf("|    White Win    |\n") : printf("|    Black Win    |\n");
    printf("|                 |\n");
    printf("===================\n");
}

/**
 * Display draw game.
 * 
 * @return void.
 * @see draw.
*/
void draw() {
    printf("===================\n");
    printf("|                 |\n");
    printf("|      Draw       |\n");
    printf("|                 |\n");
    printf("===================\n");
}