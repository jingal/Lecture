//1_생성자3 25 page

#include <iostream>
using namespace std;

// 핵심: 메모리에 놓이는 순서대로 생성자 호출
// 1. 기반 클래스의 멤버 생성자		- BM()
// 2. 기반 클래스의 생성자			- Base()
// 3. 자신의 멤버의 생성자			- M()
// 4. 자신의 생성자.				- Derived()

// 이 순서는 사용자가 변경할 수 없다.!!
// 직접 초기화 리스트에서 호출해서 순서는 변경되지 않는다.

struct BM { BM() { cout << "BM()" << endl; } };
struct M { M() { cout << "M()" << endl; } };

struct Base
{
	BM bm;
	Base() : bm() { cout << "Base()" << endl; }
};

struct Derived : public Base
{
	M m;
	Derived() : Base(), m() { cout << "Derived()" << endl; } // 순서를 바꿔도 호출순서는 바뀌지 않음
};


int main()
{
	Derived d; //화면 출력 결과 예측해 보세요.
}