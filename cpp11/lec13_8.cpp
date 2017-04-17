#include <iostream>
#include <type_traits>
//#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	aggregate initialization
///////////////////////////////////////////////////////////////////////////

struct Point
{
	int x;
	int y;

	// 생성자가 없을 경우 구조체
	//	Point() {}
	//	Point(int a, int b) : x(a), y(b) { cout << "int, int" << endl; }


	//	Point() {}
	//	Point(int a, int b) : x(a), y(b) { cout << "int, int" << endl; } 
	//	p2에서 에러 발생
	//

	//Point() = default;		: aggregate

	//virtual void foo() {}		: aggregate

	void foo() {}				//: aggregate
};

int main()
{
	Point p1;				//ok
	Point p2 = { 1,1 };		//ok


	int x[10] = { 1,2,3 };

	//aggregate : 배열, 구조체
}

