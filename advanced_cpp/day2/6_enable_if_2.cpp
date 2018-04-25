// 6_enable_if2 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;

// 핵심
// 1. static_assert : 조건을 만족하지 않은 경우 무조건 error
// 2. enable_if : 조건을 만족하지 않은 경우 코드 생성 안함.
//					동일한 이름에 다른 함수가 있다면 사용가능.

/*
template<typename T>
void foo(T a)
{
	//이 함수 a가 정수 계열 일때만 동작해야 합니다.

	static_assert(is_integral<T>::value, "error");
	cout << "T" << endl;
}
*/
template<typename T> 
typename enable_if<is_integral<T>::value, T>::type foo(T a)
{
	cout << "T" << endl;
}

void foo(double d)
{	
	cout << "실수 버전" << endl;
}


int main()
{
	//foo(3);
	foo(3.3f);
}
