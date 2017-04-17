#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	direct vs copy initialization
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;
public:
	explicit Point(int a) : x(a), y(0) {}

	explicit Point() : x(0), y(0) {}
	explicit Point(int a, int b) : x(a), y(b) {}
};


int main()
{
	/*
	Point p1(0);			//direct ok
	Point P2 = 0;			//copy ...error

	Point p3{ 0 };			//ok
	Point p4 = { 0 };		//copy error

	Point p5(0, 0);			//direct ok...
	Point p6 = (0, 0);		//이런 표현은 없음
	*/

	//Point p7{ 0,0 };		//direct
	//Point p8 = { 0,0 };		//copy error, explicit 붙이면 에러

	Point p9;				// default 생성자
	Point p10{};			// uniform initializer

	Point p11 = {};			// default에 explicit 붙이면 copy에서 에러발생
}




// copy initialization : 초기화시에 =를 사용하는 것
// direct initialization : 초기화시에 =를 사용하지 않는 것
/*
int main()
{
	int n1(0);		//직접 초기화 (direct)
	int n2 = 0;		// 복사 초기화

	int n3{ 0 };		//direct, explicit면 직접은 되지만 복사는 안됨
	int n4 = { 0 };		// copy
}
*/
