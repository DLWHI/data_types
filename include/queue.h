#ifndef QUEUE_H_
#define QUEUE_H_

typedef unsigned long size_t;

typedef struct queue queue;

queue* queue_init(char* value);
queue* queue_copy(const queue* other);
void queue_destroy(queue* this);

queue* queue_push(queue* this, char* value);
queue* queue_pop(queue* this);
void* queue_peek(queue* this);

size_t queue_len(queue* this);
void queue_trace(queue* this);

#endif
