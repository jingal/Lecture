//1_생성자9

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}
};

int main()
{
	Point* p1 = new Point;	// 1. 메모리 할당 
							// 2. 생성자 호출

	//1. 메모리만 할당하는 방법 (malloc 역활)
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));

	//2. 이미 메모리가 할당된 공간에 생성자만 호출하는 방법
	new(p2) Point(0, 0);			// 메모리 p2의 생성자 호출

	p2->~Point();			// 메모리 해지 없이 소멸자만 호출

	operator delete(p2);	// 소멸자 호출 없이 메모리만 해지
							// free
}

// malloc : 메모리 할당
// new : 객체 생성 (메모리 할당 + 생성자 호출)

// new Point()				:	새로운 메모리에 객체 생성
// new(메모리 주소) Point	:	기존의 메모리에 객체 생성