#include "../include/stack.h"
#include <stdlib.h>

typedef struct stack
{
  char* symbols;
  stack* next;
} stack;


stack* stack_init(char* value)
{
  stack* head = malloc(sizeof(stack));
  head->next = NULL;
  head->symbols = value;
  return head;
}
void stack_destroy(stack* this)
{
  if (!this)
    return;
  stack* next = this->next;
  for(; next; this = next, next = next->next)
    free(this);
  free(this);
}

stack* stack_push(stack* this, char* value)
{
  stack* next;
  if (this)
    next = malloc(sizeof(stack));
  else
    next = stack_init(value);
  next->symbols = value;
  next->next = this;
  return next;
}
stack* stack_pop(stack* this)
{
  if (!this)
    return this;
  stack* new_head = this->next;
  free(this);
  return new_head;
}
char* stack_peek(stack* this)
{
  if (!this)
    return NULL;
  return this->symbols;
}

size_t stack_len(stack* this)
{
    size_t l = 0;
    for (; this->next; this = this->next, l++) {};
    return l;
}
#ifdef DEBUG_MODE
#include <stdio.h>
void stack_trace(stack* this)
{
  for(; this->next; this = this->next)
    printf("%s\n", this->symbols);
  printf("%s\n", this->symbols);
}
#endif
