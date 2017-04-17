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
	//void(*f2)() = &Test::func1;		// error. this ������

	void(*f3)() = &Test::func2;			// ok.. static ����Լ��� this�� ����..
	void(Test::*f2)() = &Test::func1;			// ok.. static ����Լ��� this�� ����..

	//f2();		//error. ������ ��ü(this)�� ����.

	Test t;
	//t.f2();		//error. f2�� Test�� ����� �ƴϴ�..

	//t.*f2();		//.* : Pointer to Member ������.. error. ������ �켱����..
	(t.*f2)();
}