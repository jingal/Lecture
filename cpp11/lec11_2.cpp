#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	delete function
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0 ) : x(0), y(b) {}

	Point(const Point&) = delete;

//private:
//	Point(const Point&);		//c++11 이전
};


int main()
{
	Point p1(1, 1);
	Point p2 = p1;		//복사 생성자.	
}
