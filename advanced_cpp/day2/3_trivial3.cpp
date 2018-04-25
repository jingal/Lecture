//3_trivial3

#include <iostream>
using namespace std;

// C와 C++의 호환성에 대한 용어들
// trivial : 함수가 하는 일이 없다는 의미 (함수관점)
// standard layout : 메모리 구조가 c와 동일하다는 의미
// pod : plain old data => Trivial && standard layout
// aggregate : 초기화의 관점

struct Point
{
	int x, y;					// standard layout
	//Point() {}				// 사용자가 추가했기 때문에 trivial 하지 않음
	//virtual void foo() {}		//vptr이 추가되기 때문에 standard layout이 안됨
};

int main()
{
	cout << is_trivially_constructible<Point>::value << endl;
	cout << is_standard_layout<Point>::value << endl;
}