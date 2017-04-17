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
//	Temporary object create(임시객체가 생성되는 다양한 경우)
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

	//전위 증가 연산자 - 참조리턴
	Int32& operator++()
	{
		++value;
		return *this;
	}


	// 후위 증가 연산자 - 값리턴. 임시객체 생성
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
	
	n++;		// 임시객체 리턴. 자기상태를 잠시 보관
	//n++ = 10;	// error
	//n++++;		//(n++)++, error

	++n;		// n자체가 리턴.
	++n = 10;	// ok;
	++++n;		// ++(++n);
}