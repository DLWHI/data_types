#ifndef STRING_T_H_
#define STRING_T_H_

typedef unsigned long size_t;

typedef struct string_t string_t;

string_t* string_construct(const char* value);
string_t* string_destroy(string_t* target);

void string_resize(string_t* target, size_t newsize);
void string_shrink_to_fit(string_t* target);

void string_append(string_t* target, char last);
void string_backspace(string_t* target);
size_t string_length(string_t* target);

const char* string_c_str(string_t* target);
#endif
