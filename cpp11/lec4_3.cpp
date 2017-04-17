#include <iostream>

using namespace std;

class Point {
	int x, y;

public:
	Point(int a, int b) : x(a), y(b) {}	
};



int main()
{

	// Point �Ѱ��� ���� ����� ����
	Point* p1 = new Point(1, 1);		//ok

	// 10���� ���� ����� ����.
	//Point* p2 = new Point[10];

	//�޸𸮸� ���� �Ҵ�
	Point *p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	//�޸𸮸� ��ü�� ��ȯ - ������ ȣ��
	for (int i = 0; i < 10; i++) {
		new (&p3[i]) Point(0, 0);
	}
}
