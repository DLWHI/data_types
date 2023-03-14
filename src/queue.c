#include "../include/queue.h"
#include <stdlib.h>

typedef struct queue
{
  char* symbols;
  queue* next;
} queue;


queue* queue_init(char* value)
{
  queue* head = malloc(sizeof(queue));
  head->next = NULL;
  head->symbols = value;
  return head;
}
void queue_destroy(queue* this)
{
  if (!this)
    return;
  queue* next = this->next;
  for(; next; this = next, next = next->next)
    free(this);
  free(this);
}

queue* queue_push(queue* this, char* value)
{
  if (!this)
    return queue_init(value);
  queue* next = malloc(sizeof(queue));
  next->symbols = value;
  next->next = NULL;
  queue* tail = this;
  for (; tail->next; tail = tail->next) {};
  tail->next = next;
  return this;
}
queue* queue_pop(queue* this)
{
  if (!this)
    return this;
  queue* new_head = this->next;
  free(this);
  return new_head;
}
void* queue_peek(queue* this)
{
  if (!this)
    return NULL;
  return this->symbols;
}

size_t queue_len(queue* this)
{
    size_t l = 0;
    for (; this->next; this = this->next, l++) {};
    return l;
}
#ifdef DEBUG_MODE
#include <stdio.h>
void queue_trace(queue* this)
{
  for(; this->next; this = this->next)
    printf("%s\n", this->symbols);
  printf("%s\n", this->symbols);
}
#endif
