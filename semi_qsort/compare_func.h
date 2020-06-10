#ifndef COMPARE_FUNC_H
#define COMPARE_FUNC_H

#ifndef NULL
#define NULL ((void*)0)
#endif // !NULL

#include "human.h"
#include <stdio.h>
#include <float.h>

int compare_int(const void* s1, const void* s2);
int compare_char(const void* s1, const void* s2);
int compare_str(const void* s1, const void* s2);
int compare_float(const void* s1, const void* s2);
/*int compare_human(const void* s1, const void* s2);*/

#endif


