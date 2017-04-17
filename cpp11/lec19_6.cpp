#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;
using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////
//	19강 5.Rvalue reference 형 변수는 lvaule이다.
///////////////////////////////////////////////////////////////////////////

void foo(int& r) { cout << "int&" << endl; }					//	1
void foo(int&& r) { cout << "int&&" << endl; }					//	2

int main()
{
	int v = 10;
	foo(v);			// lvalue, 1
	foo(10);		// rvalue, 2

	int& r1 = v;

	foo(r1);		//1

	int&& r2 = 10;	// 10은 rvalue, r2가 가리킴으로 이름이 생김,
	foo(r2);		// 1? 2.. 1
					// 10자체는 rvalue
					// r2는 lvaule
					// "이름이 있는 rvalue reference 형 변수는 lvalue 이다."
	r2 = 30;

	foo(static_cast<int&&>(r2)); //r2 (lvalue)를 rvalue로 캐스팅하는 코드.
}
