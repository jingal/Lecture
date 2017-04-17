#include <iostream>

using namespace std;


struct A
{
	int a;
	void fa() { cout << this << endl; }
};

struct B
{
	int b;
	void fb() { cout << this << endl; }
};

struct X : public A, public B
{
	int x;
};


int main()
{
	X obj;
	obj.fa();		//1000
	obj.fb();		//1004

	void (X::*f)();		//X의 멤버함수의 주소를 담는다.
						// f의 모양 {함수주소, this offset }, 즉 8바이트


	//f = &X::fa;		// f = {&fa, 0}
	f = &X::fb;			// f = { &fa, sizeof(A) };

	(obj.*f)();			//f가 fa라면 1000
						//		fb라면 1004
						// f(&obj)
						// f.함수주소( &obj + f.this_offset);

	cout << sizeof(f) << endl; //8
}


/*
int main()
{
	X obj;
	cout << &obj << endl;			// 1000

	A* pA = &obj;			// 1000
	B* pB = &obj;			//1004   &obj + sizeof(A)


	cout << pA << endl;
	cout << pB << endl;
}
*/