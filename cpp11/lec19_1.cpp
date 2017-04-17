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
//	19강 1. lvalue vs rvalue
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	Point(const Point& p) { cout << "Point(const Point&)" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	int v1 = 10, v2 = 20;

	v1 = 30;			// ok.. v1은 lvalue
	//30 = v1;			// error. 30은 rvalue, rvalue 는 오른쪽에만 올 수 있음
	v2 = v1;			// ok.. 


	cout << &v1 << endl;	// ok.. lvalue는 주소를 구할 수 있다.
	//cout << &10 << endl;	// error. rvalue는 주소를 구할 수 없다.

	Point p;				
	cout << &p << endl;			// ok.
	cout << &Point() << endl;	// error.

}