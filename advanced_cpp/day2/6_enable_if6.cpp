// 6_enable_if6 - 77 page

#include <iostream>
#include <type_traits>
using namespace std;


template<typename T> void print(T a)
{
	//if (is_pointer<T>::value)				// if(false)
	// 컴파일 시간 if문.. 조건의 조사를 컴파일 시간에 조사
	// false가 나오면 컴파일 제외
	// c++ 17, 컴파일 타임 상수만 사용 가능
	if constexpr (is_pointer<T>::value)
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}

typename enable_if<!is_pointer<T>::value, void>::type foo(T a)
{
	//...
}

int main()
{
	int n = 10;
	print(n);		// 1. 에러의 원인.
	print(&n);
}