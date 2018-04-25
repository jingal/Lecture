//3_coercion2 - 43 page

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

	// 복사 생성자
	// 템플릿 클래스 선언 안에서는 Point는 Point<T>와 동일한 의미
	//Point(const Point& p)) {}


	// step 1.
	// 아래 코드 문제점 : 자신과 동일한 타입의 Point만 받을 수 있다.
	// Point<double> p2 = p1;
	// 위에서 p1은 반드시 Point<double> 이어야한다.
	// Point(const Point<T>& p)) {}

	// step 2.
	// 특징 : 무조건 Point<int>를 받을 수 있다.
	// Point<double> p2 = p1; //Point<int> p1이라도 가능
	// 단점 : p1이 Point<float>이라면 error
	// Point(const Point<int>& p)) {}

	// steop 3.
	// Point<double> p2 = p1;
	// T는 double로 결정되었지만, 아래 함수에서 U는 
	// 다시 임의의 타입입니다. 그래서 p1은
	// Point<double>, Point<float>등 모두 가능.

	// "U(int)가 T(double)로 암시적 형변환 된다면
	// Point<U>는 Point<T>로 암시적 형변환 되어야 한다.
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}
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

	//Point p; // error. T가 결정될 수 없다.
}