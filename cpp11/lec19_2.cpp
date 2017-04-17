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
//	19�� 1. lvalue vs rvalue
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
	foo() = 20;		// error, �ӽð�ü�� �����ϱ� ����, ��, ���� �����ϴ� �Լ��� rvalue
	goo() = 20;		// ok.. ������ �����ϴ� �Լ��� lvalue
}