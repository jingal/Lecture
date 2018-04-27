//4_forward2

#include <iostream>
using namespace std;

void hoo(int&& a) {}
void foo(int& a) {}

// main		=>		lockAndCall				=>				원본함수
// n		=>		t(lvalue), T:int&		=>				foo(int&)
// 10		=>		t(lvalue), T:int		=> 				hoo(int&&)

template<typename F, typename T>
void lockAndCall(F f, T&& t)
{
	//f(std::forward<T>(t));

	// n일 때 :	T => int&, T&& : int&
	// 10일 때 : T => int, T&& : int&&
	//f(static_cast<T&&>(t));
	f(forward<T>(t));		//이 코드가 위와 동일한 캐스팅
}

int main()
{
	int n = 10;

	lockAndCall(foo, n);		// T : int
	lockAndCall(hoo, 10);		// T : int&&
	
}