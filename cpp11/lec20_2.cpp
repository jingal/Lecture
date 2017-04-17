#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
//#include <vector>
#include <boost/type_index.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	20강 완벽한 전달자 해결책
///////////////////////////////////////////////////////////////////////////

void foo(int& n) { cout << "foo" << endl; n = 20; }
void goo(int n) { cout << "goo" << endl; } 
void hoo(int&& a) { cout << "hoo" << endl; }

//template<typename F, typename T> void logTime(F f, T arg)

// 1번 우선 int, 인자는 반드시 참조로 받아야 함.
template<typename F> void logTime(F f, int& a)
{	
	f(a);
}


// R Value 참조
/*
template<typename F> void logTime(F f, int&& a)
{	
	f(a);
}
*/


template<typename F> void logTime(F f, int&& a)
{
	//a는 lvaule이므로 다시 rvalue로 캐스팅해야한다.
	f(static_cast<int&&>(a));
}



int main()
{
	int n = 10;
	
	logTime(foo, n);
	logTime(goo, 10);
	cout << n << endl;		//20나와야 한다.

	// hoo(10);	//ok..
	logTime(hoo, 10);		//10은 rvalue, int&&  a = 10; //a 즉 rvalue reference 형변수는 lvalue
}


// 래퍼함수가 원본 함수에 인자(int)를 완벽히 전달하려면
// 1. 함수 인자는 참조로 받아야 한다.
// 2. int&와 int&&를 인자로 받도록 2개의 함수로 오버로딩 해야한다.
// 3. int&& 버전의 함수에서는 원본함수를 호출할 때 반드시 rvalue로 캐스팅해야 한다.
// 문제점 : 원본 함수의 인자가 한개가 아니라 2개, 3개, N개라면.
