// 5_excetion2

#include <iostream>
using namespace std;

// 소멸자는 절대 예외를 던지면 안된다.
// operator delete()는 예외가 있으면 안된다.
// move 생성자도 예외가 없는 게 좋다.

struct Test
{
	~Test() {
		cout << "소멸자" << endl; throw 1;
	}
};

void foo()
{
	Test t;
	throw 1;		// 지역변수는 파괴 된다. (stack unwinding)
}

int main()
{
	try
	{
		foo();
	}
	catch (...)
	{
		
	}
}
