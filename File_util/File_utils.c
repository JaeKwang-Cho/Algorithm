#pragma warning(disable : 4996)
#include "File_utils.h"

#define TEMP_SIZE (4096)

void copy_file(const char* src, const char* des) {
	char	temp[TEMP_SIZE];
	size_t read_size;
	if (src == NULL || des == NULL) {
		printf("file path fail : \"%s\" or \"%s\" is NULL\n",src,des);
		return;
	}
	FILE* fp= fopen(src, "rb");
	if (fp == NULL) {
		perror("***fopen error : \n ");
		return;
	}
	read_size = fread(temp, sizeof(char), 4048, fp);

	fp = fopen(des, "wb");
	if (fp == NULL) {
		perror("***fopen error: \n");
		return;
	}
	fwrite(temp, sizeof(char), read_size, fp);
	fflush(fp);
	printf("copy file  %s\n", src);

	if (feof(fp)) {
		printf("EOF indicator set\n");
		clearerr(fp);
	}

	if (ferror(fp)) {
		printf("Error indicator set\n");
		clearerr(fp);
	}

	fclose(fp);
}

void move_file(const char* src, const char* des) {
	if (src == NULL || des == NULL) {
		printf("file path fail : \"%s\" or \"%s\" is NULL\n", src, des);
		return;
	}
	int rf;
	copy_file(src, des);
	rf = remove(src);
	if (rf) {
		perror("*** remove error : ");
		return;
	}
	printf("move %s to %s\n",src,des);
}

void read_file(const char* src, char* arr,size_t arr_size) {
	if (src == NULL || arr == NULL) {
		printf("file path fail : \"%s\"  is NULL\n", src);
		return;
	}
	FILE* fp= fopen(src, "rb");
	size_t read_size;
	if (fp == NULL) {
		perror("***fopen error : \n ");
		return;
	}
	read_size= fread(arr, sizeof(char), arr_size, fp);
	printf("read file : %s \n", src);
	if (fclose(fp)!=0) {
		perror("***file close error : fclose(fp)\n");
	}
	return;
}

void write_file(const void* src ,const char* des,size_t src_size) {
	FILE* fp= fopen(des, "wb");
	if (fp == NULL) {
		perror("***fopen error: \n");
		return;
	}
	fwrite(src, sizeof(char), src_size, fp);
	fflush(fp);
	printf("write file :  %s\n", des);

	if (feof(fp)) {
		printf("EOF indicator set\n");
		clearerr(fp);
	}
	if (ferror(fp)) {
		printf("Error indicator set\n");
		clearerr(fp);
	}

	fclose(fp);
}

void* get_data(const void* src, void * des,size_t des_size) {
	if (src == NULL) {
		printf("src is NULL. default return NULL;\n");
		return NULL;
	}
	if (des == NULL) {
		printf("des is NULL. default return NULL\n");
		return NULL;
	}
	memcpy(des, src, des_size);

	return des;
}

