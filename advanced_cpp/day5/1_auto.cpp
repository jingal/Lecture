//1_auto 

#include <iostream>
using namespace std;



int main()
{
	int n = 0;	
	int& r = n;
	const int c = 0;

	// a1,a2, a3의 타입을 생각해 보세요.
	// 1. auto는 복사본을 만드는 방식입니다.
	//		값의 타입만 고려합니다.
	//		우변의 const, volatile, reference를 제거후 결정

	auto a1 = n;			//int
	auto a2 = r;			//int
	auto a3 = c;			//int

	decltype(n) d1;			//int
	decltype(r) d2;			//int&				- 초기값이 없으므로 error
	decltype(c) d3;			//constint			- 초기값이 없으므로 error
}