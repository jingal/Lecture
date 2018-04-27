//2_rvalue4

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point() {}

	//���� �����ڸ� ��Ȯ�� �ľ��� ���ô�.
	// �ĺ� 1: ��������ڸ� ȣ���ϰ� �ǹǷ� ���� ���� ������ ȣ��, 
	//			���ڷ� �� �� ����.
	//Point(Point p) {}

	//�ĺ� 2: ����
	//���� : �ӽð�ü�� ���� �� ����.
	//			�Լ��� �����ϴ°��� ���� �� ���� �ȴ�.
	//			�ӽð�ü�� ���� rvalue�� �޾ƾ� �ϱ� ������ Ż��

	//Point(Point& p) {}
	//Point(Point p) {}		// Point p = p1; �� ��������ڸ� ȣ���ϰ� �ǹǷ� ���� ���� ������ ȣ��


	//�ĺ� 3: �ᱹ, lvalue�� rvalue�� ��� ��������
	// const lvalue reference �ۿ� ����.
	Point(const Point& p) { cout << "copy" << endl; }


	// rvalue �϶��� ���� �Լ��� �ƴ� �Ʒ� �Լ��� ���
	// �˴ϴ�. �׷��� move������ ����� �Ʒ��� �����ϴ�.
	Point(Point&& p) { cout << "move" << endl; }
};


Point foo() { Point p; return p; }

int main()
{
	Point p1;
	Point p2(p1);		// Point( Point )�� ����� �ʿ��մϴ�.

	Point p3 = foo();

	Point p4 = p1;								//copy
	Point p5 = static_cast<Point&&>(p1);		//move
	Point p6 = move(p2);						//move
}