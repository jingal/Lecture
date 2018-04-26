// 6_callableobject11

#include <iostream>
#include <algorithm>
using namespace std;

// �Լ��� ���ڷ� �޴� �Լ� �����
// �Լ� �����ͷ� ����� : �Լ���ü�� ���� �� ����.
/*
void unload(void(*f)())
{
	f();
}
*/

// �Ϲ� ���� ������ �ӽð�ü�� ����ų �� ����.
// �Ʒ� ó�� ����� ����ǥ������ ���� �� ����.
// template<typename T> void unload(T& f)

// ��� ������ �ӽð�ü�� ����ų �� �ִ�.
// �׷���, �����ü�� ��� �Լ��� ȣ�� ����
// �׷��� mutable ���ٸ� ����� �� ����.

// rvalue referrence : ��� ���� �߰����� �ʰ� 
//						�ӽð�ü�� ���� �� �ִ�.
template<typename T> void unload(T&& f)
{
	f();
}

void foo() { }

int main()
{
	//unload(&foo); //�Լ������͸� ���ڷ�
	int n1 = 0, n2 = 0;
	//unload( [n1, n2]() { cout << "AA" << endl; });

	//mutalbe�� ����Լ��� �ƴϰ� ����Ƿ�, ��� ������ ���� �� ����
	unload([n1, n2]() mutable { cout << "AA" << endl; });

	//Point p(1, 1);
	//Point(1, 1); // �ӽð�ü�� �̸��� ���� ������ ;������ �ı���

	// �ӽð�ü�� ������ �����Ű�� ���
	//const Point& r = Point(1, 1);
}