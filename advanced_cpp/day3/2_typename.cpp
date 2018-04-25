// 2_typename

#include <iostream>
#include <vector>
using namespace std;

struct AAA
{
	typedef int DWORD;
	struct rebind1 { };	
	template<typename T>struct rebind2 
	{ 
		typedef T other;
	};
};

template<typename T> typename T::template rebind2<int> foo(T a)
{
	// T : AAA	
	//typename T::DWORD n;		// DWORD는 static 멤버(값) 
								// 또는 typedef(타입)일 수 있다
								// typename이 없으면 값(static변수)로 해석	

	typename T::rebind1 m;

	// rebind2의 객체 n2를 만들어 보세요.
	//typename T::rebind2<int> p;--> 컴파일러가 rebind2의 뒤에 나오는 <를 알수가 없음
	
	typename T::template rebind2<int> n2;
	//typename T::rebind2<int>::other nt;

	typename T::template rebind2<int>::other n3;

	return n2;
}

int main()
{
	AAA a;
	foo(a);
}