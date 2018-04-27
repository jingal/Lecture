//2_rvalue2

#include <iostream>
using namespace std;


struct Point {
	int x, y;
};

int main()
{
	int n = 10;
	
	// 규칙 1. 비상수 lvalue reference는 lvalue만 가리킨다.
	//int& r1 = n;		//ok
	//int& r2 = 10;		//error


	// 규칙 2. 상수 lvalue reference는 lvalue/rvalue 모두 가리킨다.
	// 단점 : 가리킬수는 있지만 상수성이 추가된다.	
	//const int& r1 = n;		//ok
	//const int& r2 = 10;		//ok
	//const Point& r3 = Point();		//ok

	// 규칙 3. C++11 rvalue reference는 상수성이 
	//			없이 rvalue를 가리킬 수 있다.
	//			lvalue는 가리킬 수 없다.
	// 단점 : 
	//int&& r1 = n;				//error
	int&& r2 = 10;				//ok
	Point&& r3 = Point();		//ok

	r2 = 30;
	r3.x = 10;

}