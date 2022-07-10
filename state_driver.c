#include "stdio.h"
#include "stdlib.h"

#include "state_manager.h"

unsigned int init_1 () {
    printf("initializing state 1\n");
    return 1;
}

unsigned int destroy_1 () {
    printf("destroying state 1\n");
    return 1;
}

unsigned int init_2 () {
    printf("initializing state 2\n");
    return 2;
}

unsigned int destroy_2 () {
    printf("destroying state 2\n");
    return 2;
}

unsigned int update_1(float delta) {
    printf("updating 1: %f\n", delta);
    return 1;
} 

unsigned int update_2(float delta) {
    printf("updating 2: %f\n", delta);
    return 1;
} 

int main() {

    StateManager curr_stack;
    int input_capacity;

    printf("How many scenes will you have?\n");
    scanf("%d", &input_capacity);
    SM_init(&curr_stack, input_capacity);
    SM_log(&curr_stack);

    State s1 = {0}; // initialize all fields to 0
    s1.init = &init_1;
    s1.destroy = &destroy_1;
    s1.update = &update_1;

    SM_push(&curr_stack, &s1);
    SM_update(&curr_stack, 11.0);

    State s2 = {0};

    s2.init = &init_2;
    s2.destroy = &destroy_2;
    s2.update = &update_2;

    SM_push(&curr_stack, &s2);
    SM_update(&curr_stack, 10.0);

    SM_log(&curr_stack);

    SM_destroy(&curr_stack);
    return 0;
}
