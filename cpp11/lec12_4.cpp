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
	explicit Point(int a) : x(a), y(0) {}

	explicit Point() : x(0), y(0) {}
	explicit Point(int a, int b) : x(a), y(b) {}
};


int main()
{
	/*
	Point p1(0);			//direct ok
	Point P2 = 0;			//copy ...error

	Point p3{ 0 };			//ok
	Point p4 = { 0 };		//copy error

	Point p5(0, 0);			//direct ok...
	Point p6 = (0, 0);		//�̷� ǥ���� ����
	*/

	//Point p7{ 0,0 };		//direct
	//Point p8 = { 0,0 };		//copy error, explicit ���̸� ����

	Point p9;				// default ������
	Point p10{};			// uniform initializer

	Point p11 = {};			// default�� explicit ���̸� copy���� �����߻�
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
