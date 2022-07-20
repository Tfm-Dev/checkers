#include "err.h"

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
 * Error insufficient memory.
 * 
 * @param void
 * 
 * @return void.
*/
void memoryErr() {
    printf("**" ANSI_COLOR_ERROR " Error: Insufficient memory! " ANSI_COLOR_RESET "**");
    getchar();
    exit;
}

/**
 * Warning invalid position!
 * 
 * @param void
 * 
 * @return void.
*/
void invalidPositionWarning() {
    printf("**" ANSI_COLOR_WARNING " Warnig: Invalid Position! " ANSI_COLOR_RESET "**");
    getchar();
}

/**
 * Warnig no piece in this position!
 * 
 * @param void
 * 
 * @return void.
*/
void invalidPieceInPositionWarning() {
    printf("**" ANSI_COLOR_WARNING " Warnig: No piece in this position! " ANSI_COLOR_RESET "**");
    getchar();
}

/**
 * Warning this piece not your
 * 
 * @param void
 * 
 * @return void.
*/
void invalidPieceWarning() {
    printf("**" ANSI_COLOR_WARNING " Warning: This piece not your! " ANSI_COLOR_RESET "**");
    getchar();
}

/**
 * Warning this piece not have a possible move!
 * 
 * @param void
 * 
 * @return void.
*/
void notPossibleMoveWarning() {
    printf("**" ANSI_COLOR_WARNING " Warning: This piece not have a possible move! " ANSI_COLOR_RESET "**");
    getchar();
}

/**
 * Warning invalid moviment!
 * 
 * @param void
 * 
 * @return void.
*/
void invalidMoveWarning() {
    printf("**" ANSI_COLOR_WARNING " Warning: Invalid Moviment! " ANSI_COLOR_RESET "**");
    getchar();
}