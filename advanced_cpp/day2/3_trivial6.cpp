//3_trivial6

#include <iostream>
#include <atomic>
using namespace std;

// agregate Ÿ�� : {}�� �ʱ�ȭ�� ������ Ÿ�Ե�, �迭, ����ü, ����ü��..
struct Point
{
	int x = 0, y = 0;

	Point() {}						// trivial & aggregate �� �ƴ�
									// ����ڰ� �����ڸ� ����� �����Ϸ��� 
									// ������ �ȿ��� �����ΰ� �ϴ� ������ �Ǵ�.
	Point() = default;				// trival & aggregate
									// c++11 ����
									// ����Ʈ �����ڸ� ����� �޶�.
									// ����ȭ�� �Ǹ�, �߰�ȣ �ʱ�ȭ�� ����

	void foo() {}					// �Ϲ� �Լ��� �־ aggreate
	//virtual void foo() {}			// aggregate �ƴ�
	//Point() {}						// ���ڵ� ������ aggregate �ƴ�.
	//Point(int a, int b) {}
};

int main()
{
	Point p1;
	Point p2 = { 0, 0 };
	//Point p2{ 0, 0 };



//	Point p3(0, 0);
//	Point p3{ 0, 0 };	//C++11 ���� ����

//	int a = 0;
//	int x[2] = { 0, 0 };
//	Point p(1, 1);

	// �ϰ��� �ʱ�ȭ ����, ��� ������ ������ {}�� �ʱ���
	int a = { 0 };
	int x[2] = { 0, 0 };
	Point p = { 1, 1 };

}