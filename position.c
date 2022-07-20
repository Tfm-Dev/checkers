#include "position.h"

#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

/**
 * Create a new Position with int.
 * 
 * @param row     Row of position;
 * @param column  Column of position.
 * 
 * @return Position.
*/
Position newPosition(int row, int column) {
    Position position = {
        row,
        column
    };
    return position;
}

/**
 * Create a new Position with char.
 * 
 * @param row     Row of position;
 * @param column  Column of position.
 * 
 * @return Position.
*/
Position fromPlayerPosition(char row, char column) {
    Position position = {
        8 - atoi(&row),
        column - 'a' 
    };
    return position;
}

/**
 * Convert Position to Player Position.
 * Example: [0, 0] to 'a8'.
 * 
 * @param row     Row of position;
 * @param column  Column of position
 * 
 * @return char*
*/
char* toPlayerPosition(int row, int column) {
    char* playerPosition = (char *) calloc(2, (2 * sizeof(char)));
    *(playerPosition + 0) = ('a' + column);
    *(playerPosition + 1) = (8 - row) + '0';
    return playerPosition;
}

/**
 * Valid Player position.
 * Valid values: - for row: 1 to 8; - for column: 'a' to 'g'.
 * 
 * @param row     Row of position;
 * @param column  Column of position.
 * 
 * @return True(1) or False(0).
*/
int validPlayerPosition(char row, char column) {
    if (atoi(&row) > 8 || atoi(&row) < 1) return 0;
    if (column > 104 || column < 97) return 0;
    return 1;
}

/**
 * Valid Position.
 * Valid values: for row and column: 0 to 7.
 * 
 * @param row     Row of position;
 * @param column  Column of position.
 * 
 * @return True(1) or False(0).
*/
int validPosition(int row, int column) {
    if (row > 7 || row < 0) return 0;
    if (column > 7 || column < 0) return 0;
    return 1;
}