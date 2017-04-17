#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	default function
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a, int b) {}

	//Point() {}
	Point() = default;			// 사용자가 아무것도 안할경우에는 default를 사용
};


int main()
{
	Point p1;
	Point p2(1, 2);

	Point p3{};
	cout << p3.x << endl;

	Point p1 = { 1,1 };
}
