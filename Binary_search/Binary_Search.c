#include "Binary_Search.h"
#include "comp_func.h"
/*다른 곳에는 하나도 안써도 되는데 여기다가는 enum을 써야 한다...*/
void* my_Bsearch(const void* key, const void* ptr, size_t count, int(*comp)(const void*, const void*,enum type mt), type_t mt) {
	int index_log_end = count;
	int index_log_start = 0;
	int* pt_i;
	double* pt_d;
	char** pt_c;
	int* key_i;
	double* key_d;
	char* key_c;


	switch (mt) {
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
	pt_i = (int*)ptr;
	key_i = (int*)key;
	index_log_end = count;
	index_log_start = 0;
	unsigned flag_index = (index_log_start + index_log_end) / 2;
	int flag_int = pt_i[flag_index];
	int con = comp(key_i, &flag_int, type_int);
	while (con != 0) {
		if (con > 0) {
			index_log_start = flag_index;
		}
		else if (con < 0) {
			index_log_end = flag_index;
		}
		flag_index = (index_log_start + index_log_end) / 2;
		flag_int = pt_i[flag_index];
		con = comp(key_i, &flag_int, type_int);
	}
	return key_i;
	}
W_DOUB:
	{
		pt_d = (double*)ptr;
		key_d = (double*)key;
		index_log_end = count;
		index_log_start = 0;
		unsigned int flag_index = (index_log_start + index_log_end) / 2;
		double flag_double = pt_d[flag_index];
		int con = comp(key_d, &flag_double, type_double);
		while (con != 0) {
			if (con > 0) {
				index_log_start = flag_index;
			}
			else if (con < 0) {
				index_log_end = flag_index;
			}
			flag_index = (index_log_start + index_log_end) / 2;
			flag_double = pt_d[flag_index];
			con = comp(key_d, &flag_double, type_double);
		}
		return key_d;
	}
W_CHAR:
	{
		pt_c = (char**)ptr;
		key_c = (char*)key;
		index_log_end = count;
		index_log_start = 0;
		size_t flag_index = (index_log_start + index_log_end) / 2;
		char* flag_str = pt_c[(index_log_start + index_log_end) / 2];
		int con = comp(key_c, flag_str,type_char);
		while (con != 0) {
			if (con > 0) {
				index_log_start = flag_index;
			}
			else if (con < 0) {
				index_log_end = flag_index;
			}
			flag_index = (index_log_start + index_log_end) / 2;
			flag_str = pt_c[flag_index];
			con = comp(key_c, flag_str, type_char);
		}
		return flag_str;
	}
}

