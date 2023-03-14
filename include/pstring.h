#ifndef PSTRING_H_
#define PSTRING_H_

typedef unsigned long size_t;

typedef struct pstring pstring;

pstring* string_construct(const char* value);
pstring* string_destroy(pstring* target);

void string_resize(pstring* target, size_t newsize);
void string_shrink_to_fit(pstring* target);

void string_append(pstring* target, char last);
void string_backspace(pstring* target);
size_t string_length(pstring* target);

#endif
