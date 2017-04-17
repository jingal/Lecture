#include <iostream>

using namespace std;


// 변환 연산자 : Complex => 다른 타입 : operator 다른타입()
// 변환 생성자 : Complex <= 다른 타입 : Complex (다른 타입)

class Complex
{
	int re;
	int im;

public:
	Complex() : re(0), im(0) {}
	Complex(int a, int b) : re(a), im(b) {}

	//인자 하나를 가지는 생서자 : 변환생성자.. 다른 타입이 객체로 변환되게 한다.
	Complex(int a) : re(a), im(0) {}

	//변환 연산자 : 객체를 다른 타입으로 변환되게 한다.
	//	특징 : 리턴 타입을 표기하지 않는다.
	operator int() { return re; }
};


int main()
{
	int n = 0;
	Complex c1;
	Complex c2(1, 2);

	n = c2;		//c2.operator int() 함수를 찾는다..
	c2 = n;		//n.operator Complex()가 있으면 된다... 그런데, n은 객체가 아니다.

	cout << n << endl;
}