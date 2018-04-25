//3_trivial4

#include <iostream>
#include <type_traits>
using namespace std;

// C와 C++의 호환성에 대한 용어들
// trivial : 함수가 하는 일이 없다는 의미 (함수관점)
// standard layout : 메모리 구조가 c와 동일하다는 의미
// pod : plain old data => Trivial && standard layout
// aggregate : 초기화의 관점

template<typename T>
void mymemset(T* p)
{
	static_assert(is_pod<T>::value, "T is not pod");
	// 아래처럼 해도 될까?
	memset(p, 0, sizeof(T));
}

struct Point
{
	int x, y;
	Point() {}
};

int main()
{
	//int x;
	//mymemset(&x);

	Point p;
	mymemset(&p);
}