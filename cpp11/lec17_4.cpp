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
//	Temporary obejct & function arguement
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

void foo(const Point& p)
{
	cout << "foo" << endl;
}

int main()
{
	//Point p(0, 0);
	//foo(p);

	foo(Point(0, 0));		//�ӽð�ü�� ����� ������ ����.

	int x[10] = { 1,2,3 };

	sort(x, x + 10, less<int>());

	cout << "A" << endl;
}