#ifndef COMP_FUNC_H
#define COMP_FUNC_H
#ifndef NULL
#define NULL ((void*)0)
#endif
int my_comp(const void*, const void*, /* enum */ type_t );
/*�Ű������� typedef�� �ѱ涧 ���� �̻��Ѱ� ����.
my_Bsearch�� �Ѱ��ٶ��� enum�� �տ� �ٿ��༭ �ڷ����� ���������ϰ�,
 �� �ڷ����� �𸥴ٰ� �ϸ鼭 enum�� defaul�� int�� �ع����ٰ� �Ѵ�.
 
 1.clang�� ��� �ϰ� int�� �ٲٰ� ������ ������ ������ ������ �ش�

 2. ���־� ��Ʃ����� �ƿ� ������ ��������.


 LNK 1120, LNK2019 */


#endif




