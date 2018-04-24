//1_casting4.cpp - å 7 page addressof

#include <iostream>

using namespace std;


// C++11 ���� ����� �ٷ� �ʱ�ȭ ����.
struct Base { 
	int value = 10; 
	void print() { cout << this << endl; }
	~Base() {
		{ cout << this << " destroyed" << endl; }
	}
};
struct Derived : public Base { int value =  20; };

int main()
{
	Derived d;

	// �� ĳ����	: Base Ÿ���� �ӽð�ü ����
	// ���� ĳ����	: �ӽð�ü�� ������ �ʴ´�.
	cout << d.value << endl;						//20
	d.print();

	// �ӽð�ü�� �ּ� �����ڷ� �ּҸ� ���� �� �����ϴ�.
	// �׷��� print()�� ��������ϴ�.
	static_cast<Base&>(d).print();
	static_cast<Base>(d).print();

	// �ӽð�ü�� ���ʿ� ���� �� ����.
	// �ӽ÷� ����� ���Ƿ� �׸��� �̸��� �����Ƿ� 
	// �ش� ��������� �ı��ǹǷ�
	static_cast<Base&>(d).value = 10;		//ok
	//static_cast<Base>(d).value = 10;		//error

	cout << static_cast<Base>(d).value << endl;		//10 
													// Base �ӽð�ü�� ����
	
	cout << static_cast<Base&>(d).value << endl;	//10
	
}

