//4_forward2

#include <iostream>
using namespace std;

void hoo(int&& a) {}
void foo(int& a) {}

// main		=>		lockAndCall				=>				�����Լ�
// n		=>		t(lvalue), T:int&		=>				foo(int&)
// 10		=>		t(lvalue), T:int		=> 				hoo(int&&)

template<typename F, typename T>
void lockAndCall(F f, T&& t)
{
	//f(std::forward<T>(t));

	// n�� �� :	T => int&, T&& : int&
	// 10�� �� : T => int, T&& : int&&
	//f(static_cast<T&&>(t));
	f(forward<T>(t));		//�� �ڵ尡 ���� ������ ĳ����
}

int main()
{
	int n = 10;

	lockAndCall(foo, n);		// T : int
	lockAndCall(hoo, 10);		// T : int&&
	
}