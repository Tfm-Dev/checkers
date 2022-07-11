#include "position.h"

#include <stdlib.h>

Position toPosition(int row, int column) {
    Position position = {
        row,
        column
    };
    return position;
}

Position fromPlayerPosition(char row, char column) {
    Position position = {
        8 - atoi(&row),
        column - 'a' 
    };
    return position;
}

int validPlayerPosition(char row, char column) {
    if (atoi(&row) > 8 || atoi(&row) < 1) return 0;
    if (column > 104 || column < 97) return 0;
    return 1;
}

int validPosition(int row, int column) {
    if (row > 7 || row < 0) return 0;
    if (column > 7 || column < 0) return 0;
    return 1;
}