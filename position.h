#ifndef POSITION_H_
#define POSITION_H_

typedef struct {
    int row;
    int column;
}Position;

Position toPosition(int row, int column);
Position fromPlayerPosition(char row, char column);
int validPlayerPosition(char row, char column);
int validPosition(int row, int column);

#endif