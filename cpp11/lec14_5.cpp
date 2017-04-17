#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	decltype
///////////////////////////////////////////////////////////////////////////

int x = 0;

int& foo(int a, int b) { return x; }

int main()
{
	//auto ret = foo(0, 0);			//int ret = 

	//decltype(foo(0, 0)) ret = foo(0, 0);		// int& ret = foo(0,0);

	decltype(auto) ret = foo(0, 0);		// 우변의 데이터 타입을 보고 결정, 다만 auto 추론규칙이 아닌 decltype 추론규칙으로 추론

	ret = 10;

	cout << x << endl;
}

