//1_casting3.cpp - å 7 page addressof

#include <iostream>
#include <memory>
#include <cstdio>
#include <cstring>

using namespace std;

struct A { int a; };
struct B { int b; };

struct X : public A, public B { int c; };

int main()
{
	X x;
	cout << &x << endl;		//1000������� �Ҷ�

	A* pA = &x;							//1000
	//B* pB = &x;						//1004

	//B* pB = (B*)&x;					//1004
	//B* pB = static_cast<B*>(&x);		//1004
							// &x + sizeof(A)
							// &x �ȿ��� B�� ã�ƶ�.
							// B�� ������ ������ �ð� ����.

	B* pB = reinterpret_cast<B*>(&x);	//1000
							// ������ �ð� ĳ��Ʈ..
							// &x �� ������ BŸ������ ����ϰڴ�.
							// �߰����� ���� ���� �ʰ�,
							// ���� ������ ���� ����� ��.
							// �̸��� �ٽ� �ؼ��ϰڴ�.

	pB->b = 100;			//x�� ��� ��� �����?
	cout << x.a << endl;	// 100

	//�Ʒ� �ڵ� ��� ������ ������.
	cout << pA << endl;
	cout << pB << endl;
}