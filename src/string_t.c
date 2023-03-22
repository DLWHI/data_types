#include "../include/string_t.h"
#include <string.h>
#include <stdlib.h>

typedef struct string_t {
  char* ptr;
  size_t len;
  size_t mem_len;
} string_t;

string_t* string_construct(const char* value)
{
  string_t* created =  malloc(sizeof(*created));
  size_t l = strlen(value);
  created->ptr = malloc(sizeof(*value)*l*2);
  created->len = l;
  created->mem_len = 2*l;
  for (size_t i = 0; i < l + 1; i++)
    created->ptr[i] = value[i];
  return created;
}
string_t* string_destroy(string_t* target)
{
  free(target->ptr);
  free(target);
  return NULL;
}

void string_resize(string_t* target, size_t newsize)
{
  target->ptr = realloc(target->ptr, newsize);
  target->mem_len = newsize;
  if (target->len >= newsize)
  {
    target->len = newsize;
    target->ptr[target->len] = '\0';
  }
}
void string_shrink_to_fit(string_t* target)
{
  target->ptr = realloc(target->ptr, target->len + 1);
  target->mem_len = target->len + 1;
}

void string_append(string_t* target, char last)
{
  if (target->mem_len <= target->len + 1)
    string_resize(target, target->mem_len*2);
  target->ptr[target->len++] = last;
  target->ptr[target->len] = '\0';
}
void string_backspace(string_t* target)
{
  target->ptr[target->len] = '\0';
}
size_t string_length(string_t* target)
{
  return target->len;
}

const char* string_c_str(string_t* target)
{
  return target->ptr;
}
