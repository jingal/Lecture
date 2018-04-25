//4_default

#include <iostream>
#include <atomic>
using namespace std;

struct Point
{
	int x, y;

	//Point() {}
	Point() = default;
};

int main()
{
	int n{};
	//Point p;				// value initialization : 쓰레기값
	Point p{};				// default initialization : 모든 멤버가 0으로 초기화
							// C++ 11문법

	cout << p.x << endl;	// 쓰레기값
	cout << p.y << endl;
}