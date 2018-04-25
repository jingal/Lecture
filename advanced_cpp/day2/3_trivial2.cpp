//3_trivial2

#include <iostream>
#include <type_traits>		// 타입의 특성을 조사하는
							// 메타 함수들..
using namespace std;

struct Test
{
	Test() {}
	Test(const Test&) {}
};

template<typename T> 
void copy_type(T* dst, T* src, int sz)
{
	if (is_trivially_copyable<T>::value)
	{
		cout << "memcpy 사용" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "trival 하지 않음. 복사생성자 사용" << endl;
		while (sz--)
		{
			new(dst) T(*src);		//복사 생성자 호출
			++dst, ++src;
		}
	}
}

int main()
{
	char s1[10] = "hello";
	char s2[10];

	//strcpy(s2, s1);
	copy_type(s2, s1, 10);

	Test t1[10];
	Test t2[10];

	copy_type(t2, t1, 10);
}

// 안드로이드 소스코드 
// platform / libutils/include/utils/typehelpers.h
// 안에서.. copy_type을 찾아보세요.