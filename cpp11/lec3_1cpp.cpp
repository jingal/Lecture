#include <iostream>

using namespace std;


class Point
{
	int x, y;
public:
	void set(int a, int b) {
		x = a;
		y = b;
	}

	/*
	void set(Point* const hits, int a, int b)
	{
		this->x = a;
		this->y = b;
	}
	*/

	static void foo(int a) //void foo(int a)
	{
		x = a;			//this->x =a;라고 변경되어야 한다.
						//이 함수는 this가 없다 error;
	}

};

int main()
{
	Point p1;
	Point p2;

	p1.set(10, 20);			// 원리
							// push 20
							// push 10 진짜 인자는 스택으로 전달
							// lea ecx &p1;
							// call
}