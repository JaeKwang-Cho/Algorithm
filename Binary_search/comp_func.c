#include "comp_func.h"
#include "Binary_Search.h"


int my_comp(const void* src1, const void* src2, type_t mytype) {

  	switch (mytype) {
	case type_int:
		goto W_INT;
		break;
	case type_double:
		goto W_DOUB;
		break;
	case type_char:
		goto W_CHAR;
		break;
	default:
		break;
	}
W_INT:
	{
		//assert(src1 != NULL);
		//assert(src2 != NULL);

		const int num1 = *(int*)src1;
		const int num2 = *(int*)src2;

		printf("**int_comp , result is %d\n", num1 - num2);
		return num1 - num2;
	}
W_DOUB:
	{
		//assert(src1 != NULL);
		//assert(src2 != NULL);

		const double num1 = *(double*)src1;
		const double num2 = *(double*)src2;
		printf("**double_comp , result is %f\n", num1 - num2);
		return (int)(num1 - num2);
	}
W_CHAR:
	{
		//assert(src1 != NULL);
		//assert(src2 != NULL);

		char* p1 = (char*)src1;
		char* p2 = (char*)src2;

		while (*p1 != '\0' && *p2 != '\0') {
			if (*p1 != *p2) {
				printf("**char_comp , result is %d\n", *p1 - *p2);
				return *p1 - *p2;
			}
			p1++;
			p2++;
		}
		printf("**char_comp , result is %d : \"not bad\"\n", *p1 - *p2);
		return 0;
	}
}
