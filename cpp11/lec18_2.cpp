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
//	Reference Return (값리턴 vs 참조리턴, lvalue vs rvalue)
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

//Point foo()		// 값리턴 : 임시객체 리턴, 함수호출이 lvalue가 될 수 없다.
Point& foo()		// 참조리턴 : 임시객체 생성 안되, 함수호출을 lvalue에 놓을 수 있다.
{
	// Point p(0,0);	// 지역변수는 위험
	return p;		//return Point(p);
}

int main()
{
	//foo().x = 10;		//error, 임시객체는 lvalue가 될 수 없다.!!
	foo().x = 10;		//

	cout << p.x << endl;
}