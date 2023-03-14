#ifndef LIST_H_
#define LIST_H_

typedef unsigned long size_t;

typedef struct list
{
  char* symbols;
  struct list* next;
} list;

list* list_init(char* value);
void list_destroy(list* this);

list* list_push_back(list* this, char* value);
list* list_pop_back(list* this);
void* list_back(list* this);

list* list_push_front(list* this, char* value);
list* list_pop_front(list* this);
void* list_front(list* this);

size_t list_len(list* this);
void list_trace(list* this);

#endif