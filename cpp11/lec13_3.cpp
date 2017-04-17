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
	int n1;						// default
	int n2{};					// value
	//int n3();					// 함수 선언


	int *p1 = new int;			// default
	int *p2 = new int();		// value
	int *p3 = new int{};		// value


	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p2 << endl;
}
