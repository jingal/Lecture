//5_SFINAE7
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;



//Point p(1, 1);
//Point(1, 1);		//임시객체 생성

struct Test { 
	//void foo() {} 
};


template<typename U> struct has_foo_function
{
	// 핵심 : 멤버 함수 foo가 있으면 성공
	//			없으면 치환 실패가 되어야 한다.

	// 아래 표현은 check(값)이 된다. check(타입)이 필요하다.
	// 함수 선언이므로
	//template<typename T> static char check( sizeof( T().foo()) );
	
	template<typename T> 
	static char check( decltype(T().foo()) *);

	template<typename T> static short check(...);

	enum { value = (sizeof(check<U>(0)) == sizeof(char)) };
};

int main()
{
	cout << has_foo_function<Test>::value << endl;
}
