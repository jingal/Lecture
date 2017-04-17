#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	default / value initialization
///////////////////////////////////////////////////////////////////////////

class Point
{
public: 
	int x, y;

	//Point() {}						//사용자 default 생성자 추가하고 초기화 안하면 쓰레기값
	Point() = default;
};

int main()
{
	Point p1;						// default initialization
	Point p2{};						// value initialization

	cout << p1.x << endl;			//쓰레기값
	cout << p2.x << endl;			// 0	
}
