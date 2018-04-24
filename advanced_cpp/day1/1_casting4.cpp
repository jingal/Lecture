//1_casting4.cpp - 책 7 page addressof

#include <iostream>

using namespace std;


// C++11 부터 멤버에 바로 초기화 가능.
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

	// 값 캐스팅	: Base 타입의 임시객체 생성
	// 참조 캐스팅	: 임시객체를 만들지 않는다.
	cout << d.value << endl;						//20
	d.print();

	// 임시객체는 주소 연산자로 주소를 얻을 수 없습니다.
	// 그래서 print()를 만들었습니다.
	static_cast<Base&>(d).print();
	static_cast<Base>(d).print();

	// 임시객체는 왼쪽에 놓을 수 없다.
	// 임시로 만들어 지므로 그리고 이름이 없으므로 
	// 해당 문장종료시 파괴되므로
	static_cast<Base&>(d).value = 10;		//ok
	//static_cast<Base>(d).value = 10;		//error

	cout << static_cast<Base>(d).value << endl;		//10 
													// Base 임시객체를 생성
	
	cout << static_cast<Base&>(d).value << endl;	//10
	
}

