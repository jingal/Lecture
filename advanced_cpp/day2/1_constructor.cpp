//1_������

#include <iostream>
using namespace std;

struct Base
{
	Base() { cout << "Base()" << endl; }
	Base(int a) { cout << "Base(int a)" << endl; }
	~Base() { cout << "~Base()" << endl; }
};

// ��ü ������ ��ӹ��� Ŭ������ �����ڰ� ȣ���

struct Derived : public Base //struct�� ��� public ���� ����
{
	Derived() { cout << "Derived()" << endl; }
	Derived(int a) : Base(a) { cout << "Derived(int a)" << endl; }
	~Derived() { cout << "~Derived()" << endl; }

	//Derived()			: Base() { cout << "Derived()" << endl; }
	//Derived(int a)	: Base(a) { cout << "Derived(int a)" << endl; }
	//~Derived() { cout << "~Derived()" << endl; ~Base(); }

};

int main()
{
	//Derived a;
	Derived d(5);

}