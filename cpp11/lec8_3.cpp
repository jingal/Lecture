#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	Delegate constructor
///////////////////////////////////////////////////////////////////////////

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	Point() : Point(0,0)	// "위임 생성자"
	{
		//Point(0, 0);		// 다른 생성자 호출이 아니고.. Point의 임시 객체를 만드는 표현..
							// 임시객체를 생성

	}
};

int main()
{
	Point p;
	cout << p.x << "," << p.y << endl;
}



