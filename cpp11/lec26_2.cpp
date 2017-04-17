#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>
#include <functional>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	26강 함수 객체(Function Object, Functor)
///////////////////////////////////////////////////////////////////////////

//함수객체 : ()를 사용해서 호출가능한 모든 객체
//			일반함수, 함수 포인터, 함수에 대한 참조, 멤버함수, 멤버함수 포인터, 참조
//			()연산자를 재정의한 객체

class Plus
{
public:
	int operator()(int a, int b) const
	{
		return a + b;
	}
};


int main()
{
	Plus p; //p는 객체

	int n = p(1 , 2);	// p.operator() (1,2)


	// a+b => a.operator+ (b)
	// a-b => a.operator- (b)
	// a() => a.operator() ()
	// a(1,2) => a.operator() (1,2)
}
