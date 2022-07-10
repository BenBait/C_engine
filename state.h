#ifndef STATE
#define STATE

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

#endif
