#ifndef TBD_LIBRARY_H
#define TBD_LIBRARY_H

typedef enum Note
{
    A,
    B,
    C,
    D,
    E,
    F,
    G
} Note;

typedef enum Direction {
    LEFT,
    RIGHT
} Direction;

Note readTape();

Note writeTape(Note input);

void moveTape(Direction direction);

typedef struct Program {
    Note writeNote;
    Direction direction;
    int NextState;
} Program;

Program* nextState(Program* prevState);

#endif //TBD_LIBRARY_H
