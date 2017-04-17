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
//	Temporary object create(�ӽð�ü�� �����Ǵ� �پ��� ���)
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	Point(const Point& p) { cout << "Point(const Point&)" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

class Int32
{
	int value;

public:
	Int32(int n = 0) : value(n) {}

	//���� ���� ������ - ��������
	Int32& operator++()
	{
		++value;
		return *this;
	}


	// ���� ���� ������ - ������. �ӽð�ü ����
	Int32 operator++(int)
	{
		Int32 temp = *this;
		++value;
		return temp;
	}
};

int main()
{
	int n = 3;
	
	n++;		// �ӽð�ü ����. �ڱ���¸� ��� ����
	//n++ = 10;	// error
	//n++++;		//(n++)++, error

	++n;		// n��ü�� ����.
	++n = 10;	// ok;
	++++n;		// ++(++n);
}