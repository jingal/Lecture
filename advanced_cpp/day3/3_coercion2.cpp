//3_coercion2 - 43 page

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

	// ���� ������
	// ���ø� Ŭ���� ���� �ȿ����� Point�� Point<T>�� ������ �ǹ�
	//Point(const Point& p)) {}


	// step 1.
	// �Ʒ� �ڵ� ������ : �ڽŰ� ������ Ÿ���� Point�� ���� �� �ִ�.
	// Point<double> p2 = p1;
	// ������ p1�� �ݵ�� Point<double> �̾���Ѵ�.
	// Point(const Point<T>& p)) {}

	// step 2.
	// Ư¡ : ������ Point<int>�� ���� �� �ִ�.
	// Point<double> p2 = p1; //Point<int> p1�̶� ����
	// ���� : p1�� Point<float>�̶�� error
	// Point(const Point<int>& p)) {}

	// steop 3.
	// Point<double> p2 = p1;
	// T�� double�� �����Ǿ�����, �Ʒ� �Լ����� U�� 
	// �ٽ� ������ Ÿ���Դϴ�. �׷��� p1��
	// Point<double>, Point<float>�� ��� ����.

	// "U(int)�� T(double)�� �Ͻ��� ����ȯ �ȴٸ�
	// Point<U>�� Point<T>�� �Ͻ��� ����ȯ �Ǿ�� �Ѵ�.
	template<typename U>
	Point(const Point<U>& p) : x(p.x), y(p.y) {}
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

	//Point p; // error. T�� ������ �� ����.
}