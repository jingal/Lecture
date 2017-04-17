#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	direct vs copy initialization
///////////////////////////////////////////////////////////////////////////

class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int a) : x(a), y(0) {}	
	Point(int a, int b) : x(a), y(b) {}
};

void foo(Point p) {} //point p = 5;


int main()
{
	Point p1 = 5;
	foo(5);

	Point P2 = { 1,1 };			//copy ...error
}




// copy initialization : �ʱ�ȭ�ÿ� =�� ����ϴ� ��
// direct initialization : �ʱ�ȭ�ÿ� =�� ������� �ʴ� ��
/*
int main()
{
int n1(0);		//���� �ʱ�ȭ (direct)
int n2 = 0;		// ���� �ʱ�ȭ

int n3{ 0 };		//direct, explicit�� ������ ������ ����� �ȵ�
int n4 = { 0 };		// copy
}
*/
