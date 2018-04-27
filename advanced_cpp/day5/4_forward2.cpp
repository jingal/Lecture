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
	//캐스팅이 필요없지만, 같은 타입으로 캐스팅해도 된다.
	f(static_cast<int&>(t));
}

//main							lockAndCall							hoo
// 10(rvalue)		=			int&& t		=> 캐스팅 필요	=>		int&&
//								여기서 t는 lvaule

// 결국, lockAndCall을 거치면서 복사본을 만들지는 않았지만
// rvalue를 lvalue로 변경하게 됩니다.
template<typename F>
void lockAndCall(F f, int&& t)
{
	f(static_cast<int&&>(t));
}

int main()
{
	int n = 10;

	lockAndCall(hoo, 10);		//10은 rvalue
}