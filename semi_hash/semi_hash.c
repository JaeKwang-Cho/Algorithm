#include "semi_hash.h"

static int check_duplication[HASHMAP_SIZE] = { 0, };

unsigned int hash_func(const char* key) {
	unsigned int hash = 0;
	int i;
	size_t len = strlen(key);

	for (i = 0; i < len; i++) {
		hash = 65599 * hash + key[i];
	}
	return hash;
}
int add(char*** map, const char* value,const char* key, unsigned int (*func)(const char*)) {
	if (map == NULL || value == NULL || key == NULL) {
		perror("input value is invalid, Default return -1");
		return -1;
	}
	unsigned int index ;
	index = func(key) % HASHMAP_SIZE;
	size_t i = index;

	char*** ppp = map;

	do {
		if (*(*(ppp))[i] == '\0') {
			memcpy((*(ppp))[i], key, sizeof(char) * STRLEN);
			memcpy((*(ppp + 1))[i], value, sizeof(char) * STRLEN);
			printf("Success\n");
			printf("value : %s, key : %s , index : %u, i : %u, dup : %u\n", value, key, index, i, check_duplication[index]);
			return TRUE;
		}
		i = (i + 1) % HASHMAP_SIZE;
		check_duplication[index]++;
	} while (i != index);

	printf("FALSE");
	printf("**value : %s, key : %s\n", value, key);
	return FALSE;
}
unsigned int* get_dup(void) {
	return check_duplication;
}

int get_value(char*** map, const char* key, char* value, unsigned int (*func)(const char*)){
	if (map == NULL || key == NULL) {
		perror("input value is invalid, Default return -1");
		return -1;
	}
	unsigned int index;
	index = func(key) % HASHMAP_SIZE;
	size_t i = index;
	size_t j = check_duplication[index];

	char*** ppp = map;

	do {
		if (compare_str((*(ppp))[i],key) == 0) {
			memcpy(value, (*(ppp + 1))[i], sizeof(char) * STRLEN);
			return TRUE;
		}
		i = (i + 1) % HASHMAP_SIZE;
	} while (i != index);

	value = NULL;
	return FALSE;
}

char***  init_hashmap(char*** map){
	size_t i;
	char*** mmap;
	mmap = (char***)malloc(sizeof(char**)*2);
	if (mmap == NULL) {
		perror("mmap allocation is failed. Default return NULL");
		return NULL;
	}
	*mmap = (char**)malloc(sizeof(char*)*HASHMAP_SIZE);
	if (*mmap == NULL) {
		perror("*mmap allocation is failed. Default return NULL");
		return NULL;
	}
	*(mmap+1) = (char**)malloc(sizeof(char*)* HASHMAP_SIZE);
	if (*(mmap + 1) == NULL) {
		perror("*(mmap + 1) allocation is failed. Default return NULL");
		return NULL;
	}

	for (i = 0; i < HASHMAP_SIZE; i ++) {
		(*mmap)[i] = (char*)malloc(sizeof(char)*STRLEN);
		if ((*mmap)[i] == NULL) {
			perror("*mmap[%d] allocation is failed. Default return NULL",i);
			return NULL;
		}
		memset((*mmap)[i], '\0', STRLEN);
		(*(mmap + 1))[i]=(char*)malloc(sizeof(char) * STRLEN);
		if ((*(mmap + 1))[i] == NULL) {
			perror("*(mmap + 1)[%d] allocation is failed. Default return NULL", i);
			return NULL;
		}
		memset((*(mmap + 1))[i], '\0', STRLEN);
	}
	map = mmap;

	return map;
}
/* 
int erase(char*** map, const char* key, unsigned int (*func)(const char*) {
	if (map == NULL || key == NULL) {
		perror("input value is invalid, Default return -1");
		return -1;
	}
	unsigned int index;
	index = func(key) % HASHMAP_SIZE;
	size_t i = index;
	size_t j = check_duplication[index];

	do {
		if (compare_str(*(map)[i], key) == 0 ) {
			memcpy(*(map)[i], 0, sizeof(char) * STRLEN);
			memcpy(*(map + 1)[i], 0, sizeof(char) * STRLEN);
		}
		if()
		j--;
		i++;
	} while (i != index || *(map)[i] = '\0');
	if (j != 0) {

	}
 erase 할때, 다른 index값을 받는데 거기에 이미 차지해버리고 그것보다 작은 값이 다음에 들어있을 때 어떻게 해결할지 알아내기
	return FALSE;

	char*** ppp = map;
}*/
void destroy_map(char*** map) {
	size_t i;
	if (map == NULL) {
		perror("map is NULL");
		return;
	}
	char*** ppp = map;
	for (i = 0; i < HASHMAP_SIZE; i++) {
		free((*ppp)[i]);
		free((*(ppp + 1))[i]);
	}
	free(*ppp);
    free(*(ppp + 1));
	free(ppp);
	ppp = NULL;
	
	
}
int  compare_str(const void* s1, const void* s2) {
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
		if (*st1 - *st2 != 0) {
			return *st1 - *st2;
		}
		st1++;
		st2++;
	}
	return *st1 - *st2;
}