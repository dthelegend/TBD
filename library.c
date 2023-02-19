#include "library.h"

#include <stdio.h>

#include <stdio.h>

Note readTape()
{
    return A;
}

Note writeTape(Note input)
{
    return input;
}

void moveTape(Direction direction) {
    return;
}

Program allStates[256][7] = {
        {
            {A, RIGHT, 0}, // A
            {B, RIGHT, 0}, // B
            {C, RIGHT, 0}, // C
            {D, RIGHT, 0}, // D
            {E, RIGHT, 0}, // E
            {F, RIGHT, 0}, // F
            {G, RIGHT, 0}, // G
        }
};

const Program *startState = &allStates[0][A];

Program* nextState(Program* prevState) {
    if(prevState == NULL) {
        prevState = startState;
    }

    Program* next_state_pos;
    Note c_note;

    writeTape(prevState->writeNote);
    moveTape(prevState->direction);

    next_state_pos = allStates[prevState->NextState];

    if (next_state_pos == NULL)
        return NULL;

    c_note = readTape();
    return &next_state_pos[c_note];
}

int main(int argv, char** args) {
    int i = 0;
    Program* current_state;

    printf("Hello world!\n");

    current_state = startState;
    do {
        printf("%d %d %d\n", current_state->writeNote, current_state->direction, current_state->NextState);
        current_state = nextState(current_state);
        i++;
    } while (i < 7);
}