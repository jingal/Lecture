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
//	Temporary obejct & function return (�ӽ� ��ü�� �Լ� ����)
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	Point(const Point& p) { cout << "Point(const Point&)" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

Point foo()
{
	/*
	Point pt(1, 1);		// 2. ������ ȣ�� - pt ��ü

	cout << "foo" << endl;		// 3.foo ���

	return pt;		//return Point(pt);		// 4. ���Ͽ� �ӽð�ü ����. - ���� ������ ȣ��	
											// 5. �Ҹ��� ȣ�� - ���������� pt
	*/
	cout << "foo" << endl;

	// RVO (Return Value Optimization) : ����鼭 ��������.
	return Point(1, 1);		// ����鼭 ����, 
							// Release ����� ��� NRVO (Named RVO�� ������)
}

int main()
{
	Point p(0, 0);		// 1. ������ ȣ�� - p��ü

	p = foo();			// 6. �Ҹ��� ȣ�� - �ӽð�ü �ı�.

	cout << "A" << endl;	// 7. A���
							// 8. �Ҹ��� ȣ�� - p��ü �ı�.
}