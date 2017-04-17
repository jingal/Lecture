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
	Point() : x(0), y(0) {}
	Point(int a) : x(a), y(0) {}	
	Point(int a, int b) : x(a), y(b) {}
};

void foo(Point p) {} //point p = 5;


int main()
{
	Point p1 = 5;
	foo(5);

	Point P2 = { 1,1 };			//copy ...error
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
