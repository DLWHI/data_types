#ifndef STACK_H_
#define STACK_H_

typedef unsigned long size_t;

typedef struct stack stack;

stack* stack_init(char* value);
void stack_destroy(stack* this);

stack* stack_push(stack* this, char* value);
stack* stack_pop(stack* this);
char* stack_peek(stack* this);

size_t stack_len(stack* this);
void stack_trace(stack* this);

#endif
