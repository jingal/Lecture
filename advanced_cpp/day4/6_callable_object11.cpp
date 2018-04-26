// 6_callableobject11

#include <iostream>
#include <algorithm>
using namespace std;

// 함수를 인자로 받는 함수 만들기
// 함수 포인터로 만들면 : 함수객체를 받을 수 없다.
/*
void unload(void(*f)())
{
	f();
}
*/

// 일반 참조 변수로 임시객체를 가리킬 수 없다.
// 아래 처럼 만들면 람다표현식을 받을 수 없다.
// template<typename T> void unload(T& f)

// 상수 참조는 임시객체를 가리킬 수 있다.
// 그러나, 상수객체는 상수 함수만 호출 가능
// 그래서 mutable 람다를 사용할 수 없다.

// rvalue referrence : 상수 성이 추가되지 않고 
//						임시객체를 받을 수 있다.
template<typename T> void unload(T&& f)
{
	f();
}

void foo() { }

int main()
{
	//unload(&foo); //함수포인터를 인자로
	int n1 = 0, n2 = 0;
	//unload( [n1, n2]() { cout << "AA" << endl; });

	//mutalbe은 상수함수가 아니게 만들므로, 상수 참조로 사용될 수 없음
	unload([n1, n2]() mutable { cout << "AA" << endl; });

	//Point p(1, 1);
	//Point(1, 1); // 임시객체는 이름이 없기 때문에 ;만나면 파괴됨

	// 임시객체의 수명을 연장시키는 기법
	//const Point& r = Point(1, 1);
}