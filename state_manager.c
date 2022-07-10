#include"stdio.h"
#include"stdlib.h"
#include"assert.h"

#include"state_manager.h"

// State Manager (SM) init and destry functions

void SM_init(StateManager *curr_SM, int input_capacity) {
    // user inputs the number of scenes, will automaticall update if there are
    // too many scenes
    curr_SM -> capacity = input_capacity;
    // size of all pointers should be the same, but just in case
    curr_SM -> stack    = malloc(curr_SM->capacity * sizeof(State*));
    assert(curr_SM != NULL);

    curr_SM -> top      = -1;
}

void SM_destroy(StateManager *curr_SM) {
    while (SM_pop(curr_SM) != -1);

    free(curr_SM->stack);
}

// returns new capacity
int SM_resize(StateManager *curr_SM) {

    curr_SM -> capacity *= 2;
    curr_SM -> stack = realloc(curr_SM -> stack,
                                  curr_SM -> capacity * sizeof(State*));
    assert(curr_SM != NULL);

    return curr_SM -> capacity;
}

// public actions on SM. Always return top index after function has acted

int SM_push(StateManager *curr_SM, State *new_top) {
    if ((curr_SM -> top)+1 >= curr_SM -> capacity) {
        SM_resize(curr_SM);
    }
    curr_SM -> top++;

    (curr_SM -> stack)[curr_SM -> top] = new_top;

    return curr_SM -> top;
}

int SM_pop(StateManager *curr_SM) {

    if (curr_SM -> top == -1) {
        fprintf(stderr, "No elements to remove!\n");
        return -1;
    }

    State *curr_state = curr_SM -> stack[curr_SM -> top];
    if (curr_state -> destroy != NULL)
        curr_state -> destroy();

    curr_SM -> stack [curr_SM -> top] = NULL;
    curr_SM -> top--;

    return curr_SM -> top;
}

void SM_log(StateManager *curr_SM) {

    int disp = curr_SM -> top;
    printf("Curr top: %d\n", disp);

    disp = curr_SM -> capacity;
    printf("Curr capacity: %d\n", disp);
}

// functions to interact with the current state
void SM_update(StateManager *curr_SM, float delta) {
    State *curr_state = curr_SM -> stack[curr_SM -> top];

    if (curr_state -> update != NULL)
        curr_state -> update(delta);
}

void SM_draw(StateManager *curr_SM, float delta) {
    State *curr_state = curr_SM -> stack[curr_SM -> top];

    if (curr_state -> draw != NULL)
        curr_state -> draw(delta);
}
