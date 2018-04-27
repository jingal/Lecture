//1_auto3

#include <iostream>
using namespace std;

int foo() {}
int& goo() {}

//foo() = 10;	//error
//goo() = 10;	//ok
// 핵심 : 등호의 왼쪽에 오려면 (lvalue) 참조가 리턴되어야 한다.

int main()
{
	int	n;
	int* p = &n;

	// 1. 변수 이름만 있을 때 : 변수 선언을 통해서 추론
	decltype(n) d1;		//int
	decltype(p) d2;		//int*

	// 2. 변수를 포함한 표현식(expression)이 있을 때
	//		표현식이 lvalue면 : 참조
	//					lvalue가 될 수 없으면 : 값 (int)
	decltype(*p) d3;		// *p = 30, int&
	decltype(n + n) d4;		// n+n 은 왼쪽에 올 수 없다. int


	decltype((n)) d5;		// (n) = 10 할 수 있다. int&

	decltype(n++) d6;		// 함수로 만들경우 temp로 만들고 n++ 한 후에 temp 값 리턴, 
							// int : n++ = 10을 할 수 없다.
	decltype(++n) d7;		// n = n+1로 리턴
							// int& : ++n = 10을 할 수 있다.

	int x[3] = { 1,2,3 };		
	decltype(x[0]) d8; 		// int&
}