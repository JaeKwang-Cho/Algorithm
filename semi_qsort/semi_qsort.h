#ifndef SEMI_QSORT_H
#define SEMI_QSORT_H

#include <stdio.h>
#include <stdlib.h>

#ifndef NULL
#define NULL ((void*)0)
#endif // !NULL

void* semi_qsort(void* src, size_t E_nums, size_t size, int(*comp)(const void*, const void*));
void swap(void*, void*, size_t);

#endif //!SEMI_QSORT_H
