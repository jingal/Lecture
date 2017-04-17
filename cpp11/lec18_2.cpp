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
//	Reference Return (������ vs ��������, lvalue vs rvalue)
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	Point(const Point& p) { cout << "Point(const Point&)" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

Point p(1, 2);

//Point foo()		// ������ : �ӽð�ü ����, �Լ�ȣ���� lvalue�� �� �� ����.
Point& foo()		// �������� : �ӽð�ü ���� �ȵ�, �Լ�ȣ���� lvalue�� ���� �� �ִ�.
{
	// Point p(0,0);	// ���������� ����
	return p;		//return Point(p);
}

int main()
{
	//foo().x = 10;		//error, �ӽð�ü�� lvalue�� �� �� ����.!!
	foo().x = 10;		//

	cout << p.x << endl;
}