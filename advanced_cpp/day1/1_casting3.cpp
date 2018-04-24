//1_casting3.cpp - 책 7 page addressof

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
	cout << &x << endl;		//1000번지라고 할때

	A* pA = &x;							//1000
	//B* pB = &x;						//1004

	//B* pB = (B*)&x;					//1004
	//B* pB = static_cast<B*>(&x);		//1004
							// &x + sizeof(A)
							// &x 안에서 B를 찾아라.
							// B가 없으면 컴파일 시간 에러.

	B* pB = reinterpret_cast<B*>(&x);	//1000
							// 컴파일 시간 캐스트..
							// &x 를 무조건 B타입으로 사용하겠다.
							// 추가적인 일을 하지 않고,
							// 단지 에러만 내지 말라는 것.
							// 이름을 다시 해석하겠다.

	pB->b = 100;			//x의 어디에 들어 갈까요?
	cout << x.a << endl;	// 100

	//아래 코드 결과 예측해 보세요.
	cout << pA << endl;
	cout << pB << endl;
}