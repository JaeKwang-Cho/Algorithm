#include "compare_func.h"


int compare_int(const void* s1, const void* s2) {
	int n1;
	int n2;
	
	if (s1 == NULL || s2 == NULL) {
		perror("s1 or s2 is NULL. Default return 0");
		return 0;
	}
	n1 = *(int*)s1;
	n2 = *(int*)s2;

	return n1 - n2;
}
int compare_char(const void* s1, const void* s2) {
	char c1;
	char c2;
	if (s1 == NULL || s2 == NULL) {
		perror("s1 or s2 is NULL. Default return 0");
		return 0;
	}

	c1 = *(char*)s1;
	c2 = *(char*)s2;

	return c1 - c2;

}
int compare_str(const void* s1, const void* s2) {
	char* st1;
	char* st2;
	size_t len1;
	size_t len2;

	if (s1 == NULL || s2 == NULL) {
		perror("s1 or s2 is NULL. Default return 0");
		return 0;
	}
	st1 = (char*)s1;
	st2 = (char*)s2;

	while (*st1 != '\0' && *st2 != '\0') {
		if (compare_char(st1, st2) != 0) {
			return compare_char(st1, st2);
		}
		st1++;
		st2++;
	}
	return compare_char(st1, st2);
}
int compare_float(const void* s1, const void* s2) {
	float d1;
	float d2;
	float res;
	if (s1 == NULL || s2 == NULL) {
		perror("s1 or s2 is NULL. Default return 0");
		return 0;
	}
	
 	d1 = *(float*)s1;
	d2 = *(float*)s2;
	res = d1 - d2 + FLT_EPSILON;

	return (int)(res);
}
/*
int compare_human_age_name(const void* s1, const void* s2) {
	if (s1 == NULL || s2 == NULL) {
		perror("s1 or s2 is NULL. Default return 0");
		return 0;
	}
	human_t* h1;
	human_t* h2 ;

	h1 = (human_t*)s1;
	h2 = (human_t*)s2;

	if (h1->age == h2->age) {

	}


}*/