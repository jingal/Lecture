//3_trivial3

#include <iostream>
using namespace std;

// C�� C++�� ȣȯ���� ���� ����
// trivial : �Լ��� �ϴ� ���� ���ٴ� �ǹ� (�Լ�����)
// standard layout : �޸� ������ c�� �����ϴٴ� �ǹ�
// pod : plain old data => Trivial && standard layout
// aggregate : �ʱ�ȭ�� ����

struct Point
{
	int x, y;					// standard layout
	//Point() {}				// ����ڰ� �߰��߱� ������ trivial ���� ����
	//virtual void foo() {}		//vptr�� �߰��Ǳ� ������ standard layout�� �ȵ�
};

int main()
{
	cout << is_trivially_constructible<Point>::value << endl;
	cout << is_standard_layout<Point>::value << endl;
}