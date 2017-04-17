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


class Base
{
public :
	int value = 10;	// C++ 11 style

	Base() { cout << "Base()" << endl; }
	~Base() { cout << "~Base()" << endl; }
	Base(const Base&) { cout << "Base(const Base&)" << endl; }
};

class Derived : public Base
{
public:
	int value = 20;
};

int main()
{
	Derived d;

	cout << d.value << endl;		//20
	cout << d.Base::value << endl;	//10

	//cout << (static_cast<Base>(d)).value << endl;		//10, Base 임시객체 생성. Base(d).value
	cout << (static_cast<Base&>(d)).value << endl;		//10, 객체를 부모타입으로 캐스팅할 때 참조타입으로 캐스팅 해야함.

	//(static_cast<Base>(d)).value = 30;		//error
	(static_cast<Base&>(d)).value = 30;		//error
}