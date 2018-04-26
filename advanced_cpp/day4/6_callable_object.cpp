#include <iostream>

using namespace std;


// callable object : ()�� ȣ�� ������ ��ü
// �Ϲ� �Լ� 
// �Լ� ��ü(Function Object, Functor)

void foo() {}

struct Plus
{
	int operator()(int a, int b) const
	{
		cout << "plus" << endl;
		return a + b;
	}

};


int main()
{
	foo();

	Plus p;
	p(1, 2);		//

	Plus()(1, 2);

	// a + b; //a.operator+ (b)
	// a - b; //a.operator- (b)
	// a(); //a.operator()()
	// a(1,2); //a.operator()(1,2)
}
