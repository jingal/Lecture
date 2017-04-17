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
//	19�� 2. Lvalue reference vs rvalue reference
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

	// ���� 1. C++ ���� ���������� lvaule�� ����ų �� �ִ�.
	int& r1 = v;		// ok.
	//int& r2 = 10;		// error.
	Point& r3 = foo();	// error.
	Point& r4 = goo();	// ok.


	// ���� 2. const ������ rvalue�� lvalue �� ���� ����ų �� �ִ�.
	const int& cr1 = v;			// ok.
	const int& cr2 = 10;		// ok.
	const Point& cr3 = foo();	// ok.
	//cr3.set(10, 20);			// error. cr3�� �����ü, ��� �Լ��� ȣ�� ����.
	const Point& cr4 = goo();	// ok.


	// ���� 3. rvalue reference�� rvalue�� ������ �� �ִ�.
	int&& rr1 = v;			// error.
	int&& rr2 = 10;			// ok.
	Point&& rr3 = foo();	// ok.
	rr3.set(10, 20);		// ok... rr3�� ����� ��ü�� �ƴϴ�.
	Point&& rr4 = goo();	// error.
}
