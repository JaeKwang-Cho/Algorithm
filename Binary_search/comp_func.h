#ifndef COMP_FUNC_H
#define COMP_FUNC_H
#ifndef NULL
#define NULL ((void*)0)
#endif
int my_comp(const void*, const void*, /* enum */ type_t );
/*매개변수를 typedef로 넘길때 뭔가 이상한게 있음.
my_Bsearch에 넘겨줄때는 enum을 앞에 붙여줘서 자료형을 명시해줘야하고,
 또 자료형을 모른다고 하면서 enum을 defaul로 int로 해버린다고 한다.
 
 1.clang은 경고만 하고 int로 바꾸고 오히려 넣으면 컴파일 오류를 준다

 2. 비주얼 스튜디오는 아예 오류를 내버린다.


 LNK 1120, LNK2019 */


#endif




