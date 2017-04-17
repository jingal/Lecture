#include <iostream>

using namespace std;



class Test
{
public:
	void func1() {}
	static void func2() {
	}
};

void foo() {}

int main()
{
	void(*f1)() = &foo;					// ok..
	//void(*f2)() = &Test::func1;		// error. this 때문에

	void(*f3)() = &Test::func2;			// ok.. static 멤버함수는 this가 없다..
	void(Test::*f2)() = &Test::func1;			// ok.. static 멤버함수는 this가 없다..

	//f2();		//error. 전달할 객체(this)가 없다.

	Test t;
	//t.f2();		//error. f2는 Test의 멤버가 아니다..

	//t.*f2();		//.* : Pointer to Member 연산자.. error. 연산자 우선순위..
	(t.*f2)();
}