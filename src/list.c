#include "../include/list.h"
#include <stdlib.h>

list* list_init(char* value)
{
  list* head = malloc(sizeof(list));
  head->next = NULL;
  head->symbols = value;
  return head;
}
void list_destroy(list* this)
{
    if (!this)
        return;
    list* next = this->next;
    for(; next; this = next, next = next->next)
        free(this);
    free(this);
}

list* list_push_back(list* this, char* value)
{
    if (!this)
        return list_init(value);
    list* next = malloc(sizeof(list));
    next->symbols = value;
    next->next = NULL;
    list* tail = this;
    for (; tail->next; tail = tail->next) {};
    tail->next = next;
    return this;
}
list* list_pop_back(list* this)
{
    if (!this)
        return this;
    if(!this->next)
    {
        free(this);
        return NULL;
    }
    list* head = this;
    for (; this->next && this->next->next; this = this->next) {};
    free(this->next);
    this->next = NULL;
    return head;
}
char* list_back(list* this)
{
    for (; this->next; this = this->next) {};
    return this->symbols;
}

list* list_push_front(list* this, char* value)
{
    list* next;
    if (this)
        next = malloc(sizeof(list));
    else
        next = list_init(value);
    next->symbols = value;
    next->next = this;
    return next;
}
list* list_pop_front(list* this)
{
    if (!this)
        return this;
    list* new_head = this->next;
    free(this);
    return new_head;
}
char* list_front(list* this)
{
    if (!this)
        return NULL;
    return this->symbols;
}

size_t list_len(list* this)
{
    size_t l = 0;
    for (; this->next; this = this->next, l++) {};
    return l;
}
#ifdef DEBUG_MODE
#include <stdio.h>
void list_trace(list* this)
{
  for(; this->next; this = this->next)
    printf("%s\n", this->symbols);
  printf("%s\n", this->symbols);
}
#endif
