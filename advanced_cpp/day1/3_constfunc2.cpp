//3_����Լ�2 - ���� �⺻������ �߿��� ����

#include <iostream>
using namespace std;

// �ٽ�. ��� �Լ��� ��ü�� ���¸� �������� ������
//		�ݵ�� ��� ����Լ��� ������ �Ѵ�.
//		��� ����Լ��� ������ �ƴ� �ʼ� �̴�.!
struct Rect
{
	int x, y, w, h;
	int getArea() const { return w*h; }		//const�� �ݵ�� ����ϴ� ����
};

// call by value ��� const T&�� ����.
void foo(const Rect& r)
{
	int n = r.getArea();
}

int main()
{
	Rect r;					//�ʱ�ȭ �ߴٰ� ����
	int n = r.getArea();

	//foo(r);
}