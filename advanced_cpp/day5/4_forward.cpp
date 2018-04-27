//4_forward 

#include <iostream>
using namespace std;

void foo(int a) {}
void goo(int& a) { a = 20; }
void hoo(int&& a) {}

//함수 호출을 스레드에 안전하게 하는 함수
// perfect forwardng : 래퍼함수가 받은 인자를 
//						원본함수에게 완벽하게 전달하는 기술
// 1. 래퍼함수에서는 복사본으로 받으면 안된다. - 참조
// 2. 상수성이 추가되어도 안된다.
// 3. 해결책 => T&&로 해야 한다.
template<typename F, typename T>
void lockAndCall(F f, T&& t)
{
	f(t);
}

int main()
{
	int n = 10;

	lockAndCall(foo, 10);		//(10)
	lockAndCall(goo, n);		//goo(n)
	lockAndCall(hoo, 10);		//hoo(10) //error
}