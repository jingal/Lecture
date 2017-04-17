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
//	Reference & temporary object (�ӽÿ� ����)
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{	
	//Point p(0, 0);
	//Point& r1 = p; //ok..

	//Point &r2 = Point(0, 0);		//error, vs������ ������ �ȳ�, vs�� ���Ȯ�� ������, ������Ʈ -> C++ -> ��� -> ���Ȯ�� �������� �ƴϿ�� ����

	const Point& r3 = Point(0, 0);		//ok.. ��������� �����ϸ�, �ӽð�ü�� ������ r3�� ����� ��������.
										// �̸��� ���� ��ü�� �̸��� �ο���

	Point&& r4 = Point(0, 0);			//ok,.. rvalue ���۷����� �ӽð�ü�� ����ų �� �ִ�. C++11

	cout << "A" << endl;
}