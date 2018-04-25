//1_������9

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
	Point* p1 = new Point;	// 1. �޸� �Ҵ� 
							// 2. ������ ȣ��

	//1. �޸𸮸� �Ҵ��ϴ� ��� (malloc ��Ȱ)
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)));

	//2. �̹� �޸𸮰� �Ҵ�� ������ �����ڸ� ȣ���ϴ� ���
	new(p2) Point(0, 0);			// �޸� p2�� ������ ȣ��

	p2->~Point();			// �޸� ���� ���� �Ҹ��ڸ� ȣ��

	operator delete(p2);	// �Ҹ��� ȣ�� ���� �޸𸮸� ����
							// free
}

// malloc : �޸� �Ҵ�
// new : ��ü ���� (�޸� �Ҵ� + ������ ȣ��)

// new Point()				:	���ο� �޸𸮿� ��ü ����
// new(�޸� �ּ�) Point	:	������ �޸𸮿� ��ü ����