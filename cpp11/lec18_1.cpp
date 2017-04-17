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
//	Temporary obejct & function return (임시 객체와 함수 리턴)
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
	Point pt(1, 1);		// 2. 생성자 호출 - pt 객체

	cout << "foo" << endl;		// 3.foo 출력

	return pt;		//return Point(pt);		// 4. 리턴용 임시객체 생성. - 복사 생성자 호출	
											// 5. 소멸자 호출 - 지역변수인 pt
	*/
	cout << "foo" << endl;

	// RVO (Return Value Optimization) : 만들면서 리턴하자.
	return Point(1, 1);		// 만들면서 리턴, 
							// Release 모드일 경우 NRVO (Named RVO를 지원함)
}

int main()
{
	Point p(0, 0);		// 1. 생성자 호출 - p객체

	p = foo();			// 6. 소멸자 호출 - 임시객체 파괴.

	cout << "A" << endl;	// 7. A출력
							// 8. 소멸자 호출 - p객체 파괴.
}