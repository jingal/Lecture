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
		x = a;			//this->x =a;��� ����Ǿ�� �Ѵ�.
						//�� �Լ��� this�� ���� error;
	}

};

int main()
{
	Point p1;
	Point p2;

	p1.set(10, 20);			// ����
							// push 20
							// push 10 ��¥ ���ڴ� �������� ����
							// lea ecx &p1;
							// call
}