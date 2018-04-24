//3_상수함수2 - 아주 기본이지만 중요한 문법

#include <iostream>
using namespace std;

// 핵심. 멤버 함수가 객체의 상태를 변경하지 않으면
//		반드시 상수 멤버함수로 만들어야 한다.
//		상수 멤버함수는 선택이 아닌 필수 이다.!
struct Rect
{
	int x, y, w, h;
	int getArea() const { return w*h; }		//const는 반드시 써야하는 문법
};

// call by value 대신 const T&가 좋다.
void foo(const Rect& r)
{
	int n = r.getArea();
}

int main()
{
	Rect r;					//초기화 했다고 가정
	int n = r.getArea();

	//foo(r);
}