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
//	19강 2. Lvalue reference vs rvalue reference
///////////////////////////////////////////////////////////////////////////

class Point 
{
	int x, y;
public:
	Point() : x(0), y(0) {}
	void set(int a, int b) { x = a; y = b; }
};

Point p;
Point foo() { return p; }
Point& goo() { return p; }


int main()
{
	int v = 10;

	// 정리 1. C++ 기존 참조문법은 lvaule만 가르킬 수 있다.
	int& r1 = v;		// ok.
	//int& r2 = 10;		// error.
	Point& r3 = foo();	// error.
	Point& r4 = goo();	// ok.


	// 정리 2. const 참조는 rvalue와 lvalue 를 도두 가르킬 수 있다.
	const int& cr1 = v;			// ok.
	const int& cr2 = 10;		// ok.
	const Point& cr3 = foo();	// ok.
	//cr3.set(10, 20);			// error. cr3는 상수객체, 상수 함수만 호출 가능.
	const Point& cr4 = goo();	// ok.


	// 정리 3. rvalue reference는 rvalue만 참조할 수 있다.
	int&& rr1 = v;			// error.
	int&& rr2 = 10;			// ok.
	Point&& rr3 = foo();	// ok.
	rr3.set(10, 20);		// ok... rr3는 상수는 개체는 아니다.
	Point&& rr4 = goo();	// error.
}
