#ifndef SEMI_HASH_H
#define SEIM_HASH_H

#ifndef TRUE
#define TRUE (1)
#define FALSE (0)
#endif // !TRUE

#ifndef NULL
#define NULL ((void*)0)
#endif // !NULL


#define HASHMAP_SIZE 13
#define STRLEN 16

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int hash_func(const char*);

int add(char*** map, const char* value, const char* key, unsigned int (*func)(const char*));

char*** init_hashmap(char*** map);

//void erase(char** map, const char key);

int* get_dup(void);

void destroy_map(char*** map);

int  compare_str(const void* s1, const void* s2);

#endif // !SEMI_HASH_H
