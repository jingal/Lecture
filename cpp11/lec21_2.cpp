#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
#include <typeinfo>
#include <vector>
#include <boost/type_index.hpp>
#include <memory>

using namespace std;
using namespace std::chrono;
using namespace boost::typeindex;

///////////////////////////////////////////////////////////////////////////
//	21강 Perfect forwarding 활용 #2
///////////////////////////////////////////////////////////////////////////

void* operator new(size_t sz)
{
	cout << "new" << endl;
	return malloc(sz);
}

void operator delete(void* p) { free(p); }


class Point
{
	int x, y;

public:
	//Point(int a = 0, int b = 0) {}
	Point(int a, int b) {}
};

int main()
{
	//shared_ptr<Point> p1(new Point(1, 1));		// new 에서 메모리할당, share_ptr 생성자에서 할당

	//sizeof(Point) + sizeof(관리객체)를 한번 메모리 할당
	//shared_ptr<Point> p2 = make_shared<Point>();
	shared_ptr<Point> p2 = make_shared<Point>(1,1);	//완벽한 전달자로 
}
