//3_coercion - 43 page

#include <iostream>
#include <list>
using namespace std;


// T() : T�� primitive Ÿ���̰ų� �������̸� 0
//		user Ÿ���̸� ����Ʈ �����ڷ� ���� ��ü
template<typename T>
struct Point
{
	T x, y;

	Point(T a = T(), T b = T()) : x(a), y(b) {}
};


int main()
{
	Point<int> p1(1, 1);
	Point<int> p2 = p1;			// ���� ������
								// �����Ϸ��� ���� ����Ʈ ���� ������


	// p3�� p1�� �ٸ� Ÿ���Դϴ�.
	// ����Ʈ ���� �����ڸ� ����� �� �����ϴ�.
	Point<double> p3 = p1;		//�Ǵ°� �������? �ȵǴ°� �������?
								// �ǵ��� �� �� ������?
}