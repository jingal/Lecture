// 4_ObejctGennerator - 177 page

#include <iostream>
#include <list>
using namespace std;

// �Լ� ���ø��� �����Ϸ��� Ÿ�� �߷��� ����������
// Ŭ���� ���ø��� �����Ϸ��� �߷��� �� ����.
template<typename T>		// Ÿ������ (type parameter)
T square(T a)				// �Լ�����
{
	return a * a;
}

int main()
{
	square<int>(3);				// �� ǥ���� ��Ȯ�� ǥ���Դϴ�.
	square(3);					// �Լ� ���ڷ� Ÿ�� �߷�
								// type deduction(inference)

	//list<int> = { 1,2,3 };
	list<int> s(10, 1);				// 10���� 1�� �ʱ�ȭ
	list s(10, 1);					// error. int ���� �ȵ�
									// ��, C++17 ���� ���� ����
}


