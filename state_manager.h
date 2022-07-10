#ifndef SM
#define SM

// The following functions will initialize, update, draw, and destroy states

// fnPtr points to a function that takes no args and returns an unsigned int
typedef unsigned int (*fnPtr)();

// fnPtrFlot takes a float as an argument.
typedef unsigned int (*fnPtrFlt)(float);

// state determines what is on the screen
typedef struct {
   fnPtr init;
   fnPtr destroy;
   fnPtrFlt draw;
   fnPtrFlt update;
} State;

typedef struct {
    // stack is an array of pointers
    // must hold pointers to state that they are only created/stored once
    State **stack;
    // number of states that can be stored
    int capacity;
    // index to the current/top state
    int top;
} StateManager;

// State Manager (SM) init and destry functions
void SM_init(StateManager *curr_stack, int input_capacity);
void SM_destroy(StateManager *curr_stack);

// returns new capacity
int SM_resize(StateManager *curr_stack);

// public actions on SM. Always return top index after function has acted
int SM_push(StateManager *curr_stack, State *new_top);
int SM_pop(StateManager *curr_stack);

void SM_log(StateManager *curr_stack);

// functions to interact with the current state
void SM_update(StateManager *curr_stack, float delta);
void SM_draw(StateManager *curr_stack, float delta);

#endif
