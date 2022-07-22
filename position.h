#ifndef _POSITION_H_
#define _POSITION_H_

/**
 * Position
 * ================================
 * int row - Row of position;
 * int column - Column of position;
 * ================================
*/
typedef struct {
    int row;
    int column;
}Position;

// Create Functions
Position newPosition(int row, int column);
Position fromPlayerPosition(char row, char column);

// Convert Function
char* toPlayerPosition(int row, int column);

// Valid Function
int validPlayerPosition(char row, char column);
int validPosition(int row, int column);

#endif