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
//	19강 1. lvalue vs rvalue
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	Point(const Point& p) { cout << "Point(const Point&)" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int x = 10;

int foo() { return x; }
int& goo() { return x; }

int main()
{
	foo() = 20;		// error, 임시객체를 리턴하기 때문, 즉, 값을 리턴하는 함수는 rvalue
	goo() = 20;		// ok.. 참조를 리턴하는 함수는 lvalue
}