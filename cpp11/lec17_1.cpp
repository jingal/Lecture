#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;
using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////
//	Temporay object (임시 객체의 명시적 생성과 수명)
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
};

int main()
{
	//Point(0, 0);	//	1. 명시적으로 만드는 임시객체, 이름이 없다.

	//Point p(0, 0);	// 2. 지역객체, 이름이 있다.

	Point(0, 0), cout << "X" << endl;

	cout << "A" << endl;
}


/*
//임시객체개념
int main()
{
	int a = 20, b = 10;

	int c = (a + b) * (a - b);		// int temp1 = a+b;
									// int temp2 = a-b;
									// c = temp1 * temp2;
}
*/
