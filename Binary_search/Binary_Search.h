#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include <stdio.h>
typedef enum type{type_int, type_double, type_char}type_t;

void* my_Bsearch(const void* key, const void* ptr, size_t count, int(*comp)(const void*, const void*,type_t),  type_t);

#endif





