//3_����Լ� - ���� �⺻������ �߿��� ����

#include <iostream>
using namespace std;

struct Point
{
	int x = 0;
	int y = 0;
	
	void set(int a, int b)
	{
		x = a;
		y = b;
	}

	void print() const		//�� �Լ��� ���� �������� �ʴ� �Լ��̴�.
	{
		//x = 10; //error
		cout << x << endl;
	}
};

int main()
{
	const Point p;

	p.x = 10;			//error, p�� ���
	p.set(10, 20);		//error, 
	p.print();			//ȣ��ǰ� �Ϸ��� ����Լ� �̾�� �Ѵ�.

	//��� ��ü�� ��� ��� �Լ��� ȣ�Ⱑ��.

	//p.set(10, 20);
	//p.print();
}