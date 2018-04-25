//1_생성자

#include <iostream>
using namespace std;

struct Base
{
	Base() { cout << "Base()" << endl; }
	Base(int a) { cout << "Base(int a)" << endl; }
	~Base() { cout << "~Base()" << endl; }
};

// 객체 생성시 상속받은 클래스의 생성자가 호출됨

struct Derived : public Base //struct일 경우 public 생략 가능
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