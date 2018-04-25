//5_SFINAE8
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;

struct Test {
	//void foo() {} 
	int foo() { return 0; }

	Test(int a) {}
};

//Test xdeclval();
template<typename T> T&& xdeclval();

/*
int main()
{
	// 임시객체
	//cout << sizeof( Test(0).foo() ) << endl;

	// xdeclval() : xdeclval이라는 함수 호출
	//cout << sizeof(xdeclval().foo()) << endl;

	// C++11 표준에 declval이 있습니다.
	// www.cppreference.com에서 declval 검색해 보세요.
	cout << sizeof(declval<Test>().foo()) << endl;
}
*/


template<typename U> struct has_foo_function
{
	template<typename T>
	static char check(decltype(declval<T>().foo()) *);

	template<typename T> 
	static short check(...);

	enum { value = (sizeof(check<U>(0)) == sizeof(char)) };
};

int main()
{
	cout << has_foo_function<Test>::value << endl;
}