//1_������5, 31 page �����ڿ� �����Լ�

#include <iostream>
using namespace std;

//�����ڿ����� �����Լ��� ȣ����� �ʴ´�.
// �Ʒ� �ڵ忡�� Base() { goo(); } ��
// Derived::goo�� ȣ���� ��� �ʱ�ȭ ���� ����
// �������Ÿ�� ����ϴ� ������ ������ �ȴ�.
// �׷��� �����ڿ����� �����Լ��� �������� �ʴ´�.

struct Base
{
	Base() { goo(); }		
	//void foo() { goo(); }		// Derived goo ȣ��
	virtual void goo() { cout << "1 Base goo" << endl; }
};

struct Derived : public Base
{
	// MemberData m
	virtual void goo() 
	{ 
		//�������Ÿ m ���
		cout << "2 Derived goo" << endl;  
	}
};

int main()
{
	Derived d; //��� ������ ������.
	//d.foo();	
}