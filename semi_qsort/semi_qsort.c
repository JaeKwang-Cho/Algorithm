#include "semi_qsort.h"

void* semi_qsort(void* src,size_t E_nums, size_t E_size, int(*comp)(const void*, const void*)) {
	printf("semi_qsort start. E_nums is %d\n.",E_nums);
	printf("\n");
	char* f_ptr;
	char* p_ptr;
	char* pivots;
	char* end_ptr;
	char* pivot;
	size_t f_piv = 1;
	size_t p_piv = 1;
	size_t i;
	if (src == NULL) {
		perror("src is NULL.");
		goto END;
	}
	if (E_nums == 0 || E_nums == 1) {
		perror("E_nums is Zero or One.");
		goto END;
	}
	if (E_nums == 2) {
		if (comp(src, (char*)src + E_size)> 0){
			swap(src, (char*)src + E_size,E_size);
		}
		goto END;
	}

	f_ptr = (char*)src + E_size;
	p_ptr = (char*)src + (E_size * (E_nums -1));
	end_ptr = p_ptr;
	while (f_ptr != (p_ptr-E_size)) {
		if ((comp(src, f_ptr) <= 0) && (comp(src,p_ptr)>0)) {
			swap(f_ptr, p_ptr,E_size);
			printf("swaped ");
			continue;
		}
		if (comp(src, f_ptr) > 0) {
			f_ptr+= E_size;
			f_piv++;
			continue;
		}
		if (comp(src, p_ptr) <= 0) {
			p_ptr-= E_size;
			p_piv++;
			continue;
		}
	}
	if ((comp(src, f_ptr) <=0) && (comp(src, p_ptr) > 0)) {
		swap(f_ptr, p_ptr, E_size);
		printf("swaped ");
	}
	if (comp(src, p_ptr)>0) {
		swap(src, p_ptr, E_size);
		printf("swaped ");
		f_piv++;
		p_piv--;
		pivot = p_ptr;
		semi_qsort(src, f_piv,E_size,comp);
		semi_qsort(pivot+ E_size,p_piv , E_size,comp);
		goto END;
	}
	else if(comp(src,f_ptr)> 0) {
		swap(src, f_ptr, E_size);
		printf("swaped ");
		pivot = f_ptr;
		semi_qsort(src, f_piv, E_size, comp);
		semi_qsort(pivot + E_size,p_piv, E_size, comp);
		goto END;
	}
	else {
		swap(src, f_ptr-E_size, E_size);
		printf("swaped ");
		f_piv--;
		pivot = f_ptr - E_size;
		p_piv++;
		semi_qsort(src, f_piv, E_size, comp);
		semi_qsort(pivot + E_size, p_piv, E_size, comp);
		goto END;
	}
	

END:

	return src;
}
void swap(void* s1, void* s2,size_t size) {
	char* temp;
	size_t i;
	if (s1 == NULL || s2 == NULL) {
		perror("s1, s2 is invalid. NULL\n terminate \"swap\".\n ");
		return;
	}
	 temp = malloc(size);
	if (temp == NULL) {
		perror("swap allocation is failed. default return NULL.\n");
		return ;
	}
	/*printf("%lu\n", size);
	for (i = 0; i < size; i++) {
		temp[i] = ((char*)s1)[i];
		((char*)s1)[i] = ((char*)s2)[i];
		((char*)s2)[i] = temp[i];
		printf("%c, %c, %c \n ", temp[i], ((char*)s1)[i], ((char*)s2)[i]);
	}
	printf("%lf", *(float*)s1);
	printf("%lf", *(float*)s2);*/

	memcpy(temp, s1, size);
	memcpy(s1, s2, size);
	memcpy(s2, temp, size);

	free(temp);
	temp = NULL;

	return;
}