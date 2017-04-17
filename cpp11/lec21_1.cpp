#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21강 Perfect forwarding 활용
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;

public:
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
	Point(const Point& p) { cout << "Point(const Point& p)" << endl; }	
};

int main()
{
	vector<Point> v;

	// vector에 요소 넣기 1
	//Point p(1, 2);
	//v.push_back(p);		// 내부적으로 복사해서 heap에 보관, 생성자 두번 불림


	//임시객체로 넣기.. 2
	//v.push_back(Point(1, 2));	//v.push_back({1,1});


	//생성자 인자만 전달해서 v가 내무적으로 Point를 만들게 한다.
	v.emplace_back(1, 2);
}