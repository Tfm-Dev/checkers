#include "gui.h"

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_WHITE     "\033[97m"
#define ANSI_COLOR_BLACK     "\033[30m"
#define ANSI_BGCOLOR_GREEN   "\033[42m"
#define ANSI_BGCOLOR_GREY   "\033[100m"
#define ANSI_COLOR_RESET   "\033[m"

void clear() {
#ifdef _WIN32
    system("cls");
#elif defined(__unix__)
    printf("\033[H\033[J");
#endif
}

void pause() {
    getchar();
}

void menu(int* choise) {
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
    scanf_s("%d", choise);
    fflush(stdin);
}

void printState(Game gameState, char* choise) {
    clear();
    printBoard(gameState.board);
    printf("Turn: \n");
    printf("Current Player: \n");
    printf("Choise: ");
    scanf_s("%s", choise);
    fflush(stdin);
}

void printBoard(Board board) {
    printf("  _ _ _ _ _ _ _ _\n");
    for(int i = 0; i < 8; i++) {
        printf("%d|", 8-i);
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0 && j % 2 != 0) printf(ANSI_BGCOLOR_GREY);
                else
                    if (i % 2 != 0 && j % 2 == 0) printf(ANSI_BGCOLOR_GREY);
            if (board.board[i][j].type) {
                printf("\033[4m");
                if (board.board[i][j].color == 'B') printf(ANSI_COLOR_BLACK);
                else printf(ANSI_COLOR_WHITE);
                printf("%c" ANSI_COLOR_RESET "|", board.board[i][j].type);
            }
            else {
                printf("_" ANSI_COLOR_RESET "|");
            }
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

void load() {

}

void instruction() {
    printf("===================\n");
    printf("|    Checkers     |\n");
    printf("|       in        |\n");
    printf("|       C         |\n");
    printf("===================\n");
}

void winner(char winner) {
    printf("===================\n");
    printf("|                 |\n");

    if(winner == 'w') printf("|      White      |\n");
    else printf("|      Black      |\n");

    printf("|      Winner     |\n");
    printf("|                 |\n");
    printf("===================\n");
}

void draw() {
    printf("===================\n");
    printf("|                 |\n");
    printf("|      Draw       |\n");
    printf("|                 |\n");
    printf("===================\n");
}

void printInvalidMove() {
    clear();
    printf("Invalid Position!\nPlease, insert a valid position.");
    pause();
}

void printMove(Game game, Move* move, int countMove) {
    clear();
    printf("  _ _ _ _ _ _ _ _\n");
    for(int i = 0; i < 8; i++) {
        printf("%d|", 8-i);
        for (int j = 0; j < 8; j++) {
            for (int h = 0; h < countMove; h ++) {
                if (i == move[h].to.row && j == move[h].to.column) {
                    printf(ANSI_BGCOLOR_GREEN);
                    break;
                }
                else if (i % 2 == 0 && j % 2 != 0) printf(ANSI_BGCOLOR_GREY);
                else if (i % 2 != 0 && j % 2 == 0) printf(ANSI_BGCOLOR_GREY);
            }
            if (game.board.board[i][j].type) {
                printf("\033[4m");
                if (game.board.board[i][j].color == 'B') printf(ANSI_COLOR_BLACK);
                else printf(ANSI_COLOR_WHITE);
                printf("%c" ANSI_COLOR_RESET "|", game.board.board[i][j].type);
            }
            else {
                printf("_" ANSI_COLOR_RESET "|");
            } 
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
    system("pause");
}