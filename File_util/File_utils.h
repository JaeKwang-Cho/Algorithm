#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

void copy_file(const char* src, const char* des);
void move_file(const char* src, const char* des);
void read_file(const char* src,char* arr, size_t arr_size);
void write_file(const void* , const char* , size_t );
void* get_data(const void* , void* , size_t );

#endif

