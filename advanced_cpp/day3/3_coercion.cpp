//3_coercion - 43 page

#include <iostream>
#include <list>
using namespace std;


// T() : T가 primitive 타입이거나 포인터이면 0
//		user 타입이면 디폴트 생성자로 만든 객체
template<typename T>
struct Point
{
	T x, y;

	Point(T a = T(), T b = T()) : x(a), y(b) {}
};


int main()
{
	Point<int> p1(1, 1);
	Point<int> p2 = p1;			// 복사 생성자
								// 컴파일러가 만든 디폴트 복사 생성자


	// p3와 p1은 다른 타입입니다.
	// 디폴트 복사 생성자를 사용할 수 없습니다.
	Point<double> p3 = p1;		//되는게 좋을까요? 안되는게 좋을까요?
								// 되도록 할 수 없을까?
}