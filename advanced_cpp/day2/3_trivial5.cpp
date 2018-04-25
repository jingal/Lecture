//3_trivial5

#define _ENABLE_ATOMIC_ALIGNMENT_FIX

#include <iostream>
#include <atomic>
using namespace std;

int n = 0;	//��������
atomic<int> n2(0);

struct Point
{
	int x = 0, y = 0, z = 0;

	Point() {}
	Point(const Point& p) {}
};


// ���� �����ڰ� �ϴ� ���� ���� ��쿡�� atomic ��� ����
atomic<Point> pt;

int main()
{
	//��Ƽ������ ȯ�濡�� �Ʒ� �ڵ� ������ ������.
	//n = n + 1;
	//n = 10;

	n2.fetch_add(1);			// lock inc n2	- lock free
	n2.store(10);				// 

	cout << n2.is_lock_free() << endl;

	Point p3;
	pt.store(p3);		//pt = p3�� ������ �����ϰ� 

	cout << pt.is_lock_free() << endl;

}