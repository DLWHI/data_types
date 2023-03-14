#include "../include/pstring.h"
#include <string.h>
#include <stdlib.h>

typedef struct pstring {
  char* ptr;
  size_t len;
  size_t mem_len;
} pstring;

pstring* string_construct(const char* value)
{
  pstring* created =  malloc(sizeof(*created));
  size_t l = strlen(value);
  created->ptr = malloc(sizeof(*value)*l*2);
  created->len = l;
  created->mem_len = 2*l;
  for (size_t i = 0; i < l + 1; i++)
    created->ptr[i] = value[i];
  return created;
}
pstring* string_destroy(pstring* target)
{
  free(target->ptr);
  free(target);
  return NULL;
}

void string_resize(pstring* target, size_t newsize)
{
  target->ptr = realloc(target->ptr, newsize);
  target->mem_len = newsize;
  if (target->len >= newsize)
  {
    target->len = newsize;
    target->ptr[target->len] = '\0';
  }
}
void string_shrink_to_fit(pstring* target)
{
  target->ptr = realloc(target->ptr, target->len + 1);
  target->mem_len = target->len + 1;
}

void string_append(pstring* target, char last)
{
  if (target->mem_len <= target->len + 1)
    string_resize(target, target->mem_len*2);
  target->ptr[target->len++] = last;
  target->ptr[target->len] = '\0';
}
void string_backspace(pstring* target)
{
  target->ptr[target->len] = '\0';
}
size_t string_length(pstring* target)
{
  return target->len;
}