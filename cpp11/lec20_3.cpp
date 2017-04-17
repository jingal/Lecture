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

//void foo(int& n) { cout << "foo" << endl; n = 20; }
//void goo(int n) { cout << "goo" << endl; }
//void hoo(int&& a) { cout << "hoo" << endl; }

// int& : lvalue reference
// int&& : rvalue reference
// T&& : forward reference
//		 인자로 lvalue로 전달되면 T : int &로 결정, T&& : int& && => int&
//		        rvalue로 전달되면 T : 값타입(int), T&& : int && => int&&		

/*
2번째 버전
template<typename F, typename T> void logTime(F f, T&& a)
{
	//a는 lvaule이므로 다시 rvalue로 캐스팅해야한다.
	f(static_cast<int&&>(a));
}
*/

/* 3번째 버전
template<typename F, typename T> void logTime(F f, T&& a)
{	
	//f(static_cast<int&&>(a));
	f(forward<T>(a));				//내부적으로 static_cast<T&&> 수행.
}
*/

//void foo(int a, int& b, int&& ) { b = 20; }
int& foo(int a, int& b, int&&) { b = 20;  return b; }


// 인자의 갯수에 상관없이, 리턴값에 상관없는 perfect forwarding 함수
/* 4번째 버전
template<typename F, typename ...Types> decltype(auto) logTime(F f, Types&& ... args)
{	
	return f(forward<Types>(args)...);				//내부적으로 static_cast<T&&> 수행.
}
*/

// 값보다는 참조로
template<typename F, typename ...Types> decltype(auto) logTime(F&& f, Types&& ... args)
{
	return f(forward<Types>(args)...);				//내부적으로 static_cast<T&&> 수행.
}


int main()
{
	int n = 10;

	int& r = logTime(foo, 10, n, 10);
	//logTime(foo, n);
	//logTime(goo, 10);
	cout << n << endl;		//20나와야 한다.

							// hoo(10);	//ok..
	//logTime(hoo, 10);		//10은 rvalue, int&&  a = 10; //a 즉 rvalue reference 형변수는 lvalue


}