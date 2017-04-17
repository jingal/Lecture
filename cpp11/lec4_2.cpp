#include <iostream>

using namespace std;

class Point {
	int x, y;

public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};


// placement new : 이미존재하는 객체의 생성자를 호출하기 위한 new.
/*
void* operator new(size_t sz, Point *p)
{
	return p;
}
*/

int main()
{

	Point p;				// 생성자

	//new Point; //인자한개인 operator new() 호출.

	new (&p) Point;		//이 표현이 위의 operator new() 호출
						// 이미 존재하는 객체 p의 생성자를 호출.

	//p.Point();		//생성자의 명시적 호출.. error
	p.~Point();			// OK


	//소멸자 호출
}
