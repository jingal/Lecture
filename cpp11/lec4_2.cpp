#include <iostream>

using namespace std;

class Point {
	int x, y;

public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};


// placement new : �̹������ϴ� ��ü�� �����ڸ� ȣ���ϱ� ���� new.
/*
void* operator new(size_t sz, Point *p)
{
	return p;
}
*/

int main()
{

	Point p;				// ������

	//new Point; //�����Ѱ��� operator new() ȣ��.

	new (&p) Point;		//�� ǥ���� ���� operator new() ȣ��
						// �̹� �����ϴ� ��ü p�� �����ڸ� ȣ��.

	//p.Point();		//�������� ����� ȣ��.. error
	p.~Point();			// OK


	//�Ҹ��� ȣ��
}
