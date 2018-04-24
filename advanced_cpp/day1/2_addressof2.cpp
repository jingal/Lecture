//2_addressof2.cpp - 책 7 page addressof
#include <iostream>
using namespace std;


class Point
{
	int x = 0;
	int y = 0;
public:
	Point* operator&() const { return 0; }	// 내 주소를 알려하지 말라.
};

int main()
{
	Point p;

	//p의 주소를 거내보자.
	&p;	//1. p.operator&() 이므로 실패

	//2. 컴파일러를 속여야 한다. p를 다른 타입으로
	//char c = static_cast<char>(p);	//error, 연관성이 없어서 실패

	//char c = reinterpret_cast<char>(p);	//
					// 1. 값캐스팅이 안된다.
					// 2. 캐스팅이 성공핻 임시객체이다.
	
	char* p1 = reinterpret_cast<char*>(&p);	
					// 에러가 없지만 &p 했으므로 0

	cout << (void*)p1<< endl;					

	char* p2 = &(reinterpret_cast<char&>(p));	//
	cout << (void*)p2 << endl;

	const Point pt;

	Point* p3 = reinterpret_cast<Point*>(
				&(reinterpret_cast<char&>(
					const_cast<Point&>(pt))));	//
	cout << (void*)p3 << endl;

	Point pt2;
	Point* pp = addressof(pt2);	//c++ 11 공식 표준.

	cout << pp << endl;
}
