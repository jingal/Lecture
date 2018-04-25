//1_생성자5, 31 page 생성자와 가상함수

#include <iostream>
using namespace std;

//생성자에서는 가상함수가 호출되지 않는다.
// 아래 코드에서 Base() { goo(); } 가
// Derived::goo를 호출한 경우 초기화 되지 않은
// 멤버데이타는 사용하는 현상이 나오게 된다.
// 그래서 생성자에서는 가상함수가 동작하지 않는다.

struct Base
{
	Base() { goo(); }		
	//void foo() { goo(); }		// Derived goo 호출
	virtual void goo() { cout << "1 Base goo" << endl; }
};

struct Derived : public Base
{
	// MemberData m
	virtual void goo() 
	{ 
		//멤버데이타 m 사용
		cout << "2 Derived goo" << endl;  
	}
};

int main()
{
	Derived d; //결과 예측해 보세요.
	//d.foo();	
}