// 6_callableobject2


#include <iostream>

using namespace std;


// callable object : ()로 호출 가능한 객체
// 일반 함수 
// 함수 객체(Function Object, Functor)


struct Plus
{
	//구조체 안에 구현부를 넣으면 자동적으로 inline으로 변경
	inline int operator()(int a, int b) const { return a + b; }
};


inline int plus(int a, int b) { return a + b; }

// 아래 템플릿에 일반함수를 보냈을 때
// 일반함수는 자신만의 타입이 없다.
// int(*f)(int, int)이 모양의 함수는 모두 같은 타입이다.
// inline을 하더라도 어떤 함수가 올지 모르기 때문에 inline치환이 안됨
void foo(int(*f)(int, int))
{
	int n = f(1, 2); 
}

// Plus 객체를 템플릿 foo에 보내면 컴파일러는 아래코드 생성
//
void foo(Plus f)
{
	int n = f(1, 2);
}


template<typename F> void foo(F f)
{
	int n = f(1, 2); //이 순간을 생각해 봅시다.
}

int main()
{
	foo(&plus);		// F : int(*)(int, int)
	foo(&minus);	// F : int(*)(int, int)

	Plus p;
	p(1, 2);		//

	Plus()(1, 2);

	Plus p;
	foo(p);		// F : Plus

	Minus m;
	foo(m);		// F : Minus
}
