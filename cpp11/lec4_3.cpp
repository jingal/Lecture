#include <iostream>

using namespace std;

class Point {
	int x, y;

public:
	Point(int a, int b) : x(a), y(b) {}	
};



int main()
{

	// Point 한개를 힙에 만들어 보자
	Point* p1 = new Point(1, 1);		//ok

	// 10개를 힙에 만들어 보자.
	//Point* p2 = new Point[10];

	//메모리를 먼저 할당
	Point *p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	//메모리를 객체로 변환 - 생성자 호출
	for (int i = 0; i < 10; i++) {
		new (&p3[i]) Point(0, 0);
	}
}
