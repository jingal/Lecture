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
//	Reference & temporary object (임시와 참조)
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

	//Point &r2 = Point(0, 0);		//error, vs에서는 에러가 안남, vs의 언어확장 때문에, 프로젝트 -> C++ -> 언어 -> 언어확장 사용안함을 아니요로 변경

	const Point& r3 = Point(0, 0);		//ok.. 상수참조로 선언하면, 임시객체의 수명이 r3의 수명과 같아진다.
										// 이름이 없는 객체에 이름이 부여됨

	Point&& r4 = Point(0, 0);			//ok,.. rvalue 레퍼런스는 임시객체를 가르킬 수 있다. C++11

	cout << "A" << endl;
}