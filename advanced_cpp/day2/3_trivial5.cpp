//3_trivial5

#define _ENABLE_ATOMIC_ALIGNMENT_FIX

#include <iostream>
#include <atomic>
using namespace std;

int n = 0;	//전역변수
atomic<int> n2(0);

struct Point
{
	int x = 0, y = 0, z = 0;

	Point() {}
	Point(const Point& p) {}
};


// 복사 생성자가 하는 일이 없을 경우에만 atomic 사용 가능
atomic<Point> pt;

int main()
{
	//멀티스레드 환경에서 아래 코드 생각해 보세요.
	//n = n + 1;
	//n = 10;

	n2.fetch_add(1);			// lock inc n2	- lock free
	n2.store(10);				// 

	cout << n2.is_lock_free() << endl;

	Point p3;
	pt.store(p3);		//pt = p3를 스레드 안전하게 

	cout << pt.is_lock_free() << endl;

}