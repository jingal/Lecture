//4_forward3

#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 20; }
void hoo(int&& a) {}

/*
template<typename F, typename T>
void lockAndCall(F f, T&& t)
{
	f(std::forward<T>(t));
}
*/

//main							lockAndCall				foo
// n(lvalue)		=			int& t			=> 		int&

template<typename F>
void lockAndCall(F f, int& t)
{
	//f(t);
	//ĳ������ �ʿ������, ���� Ÿ������ ĳ�����ص� �ȴ�.
	f(static_cast<int&>(t));
}

//main							lockAndCall							hoo
// 10(rvalue)		=			int&& t		=> ĳ���� �ʿ�	=>		int&&
//								���⼭ t�� lvaule

// �ᱹ, lockAndCall�� ��ġ�鼭 ���纻�� �������� �ʾ�����
// rvalue�� lvalue�� �����ϰ� �˴ϴ�.
template<typename F>
void lockAndCall(F f, int&& t)
{
	f(static_cast<int&&>(t));
}

int main()
{
	int n = 10;

	lockAndCall(hoo, 10);		//10�� rvalue
}