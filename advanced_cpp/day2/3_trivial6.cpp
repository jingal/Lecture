//3_trivial6

#include <iostream>
#include <atomic>
using namespace std;

// agregate 타입 : {}로 초기화가 가능한 타입들, 배열, 구조체, 공용체등..
struct Point
{
	int x = 0, y = 0;

	Point() {}						// trivial & aggregate 도 아님
									// 사용자가 생성자를 만들면 컴파일러는 
									// 생성자 안에서 무엇인가 하는 것으로 판단.
	Point() = default;				// trival & aggregate
									// c++11 문법
									// 디폴트 생성자를 만들어 달라.
									// 최적화도 되며, 중괄호 초기화도 가능

	void foo() {}					// 일반 함수는 있어도 aggreate
	//virtual void foo() {}			// aggregate 아님
	//Point() {}						// 이코드 때문에 aggregate 아님.
	//Point(int a, int b) {}
};

int main()
{
	Point p1;
	Point p2 = { 0, 0 };
	//Point p2{ 0, 0 };



//	Point p3(0, 0);
//	Point p3{ 0, 0 };	//C++11 부터 제공

//	int a = 0;
//	int x[2] = { 0, 0 };
//	Point p(1, 1);

	// 일관된 초기화 문법, 모든 종류의 변수를 {}로 초기하
	int a = { 0 };
	int x[2] = { 0, 0 };
	Point p = { 1, 1 };

}