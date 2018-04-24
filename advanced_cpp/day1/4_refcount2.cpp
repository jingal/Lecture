//4_�������2

#include <iostream>
#include <vector>
using namespace std;

class Car
{
	int m_refCount = 0;		//��ü�� ��� �����Ͱ� ����ϴ°� ����
public:
	void ref() { m_refCount++; }
	void deref() 
	{ 
		if (--m_refCount == 0) delete this;
	}

	//protected �Ҹ��� : �ܺο��� ��ü�� �ı��� �� ���� �Ҷ� ���.
	//					��ü�� ���ÿ� ���� �� ����.
	//					195 ������ �Ʒ�

protected:
	~Car() { cout << "~Car" << endl; }
};

int main()
{
	Car *p1 = new Car;		//��Ģ 1. ��ü ������ ������� ����
	p1->ref();

	Car *p2 = p1;			//��Ģ 2. ��ü ����� ������� ����
	p2->ref();

	delete p1;

	//��Ģ 3. ����Ŀ��� ������� ����
	p2->deref();
	p1->deref();
}