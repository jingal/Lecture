//3_reference2

#include <iostream>
using namespace std;

// int&		: int 타입의 lvalue만 받을 수 있다. "lvalue reference"
// int&&	: int 타입의 rvalue만 받을 수 있다. "rvalue reference"
// T&		: 모든 타입의 lvaule만 받을 수 있다.
// T&&		: 모든 타입의 lvaule와 rvalue를 다 받을 수 있다.	"forwarding reference"
//				lvalue를 보내면 f4(int&)버전 생성
//				rvalue를 보내면 f4(int&&) 버전 생성

void f1(int& a) {}
void f2(int&& a) {}

template<typename T> void f3(T& a) {}

/*
int main()
{
	int n = 0;

	//T가 타입을 사용자가 명시적으로 전달하는 경우
	f3<int>(n);			//int	& => int&
	f3<int&>(n);		//int&	& => int&
	f3<int&&>(n);		//int&& & => int&

	//T 타입을 지정하지 않은 경우
	f3(n);				// T를 위 3가지 모두 되지만 
						// 컴파일러는 int로 결정
	f3(10);				// error
}
*/

template<typename T> void f4(T&& a) {}

int main()
{
	int n = 10;

	//?에 n또는 10을 넣어 보세요.
	
	f4<int>(10);		//int	&& => int&&
	f4<int&>(n);		//int&	&& => int&
	f4<int&&>(10);		//int&& && => int&&
						
	//타입을 지정하지 않은 경우
	f4(n);				// T:int&		T&&: int&
	f4(10);				// T:int		T&&: int&&
}
