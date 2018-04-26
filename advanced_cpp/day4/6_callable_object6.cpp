// 6_callableobject6

#include <iostream>
#include <algorithm>

using namespace std;

// callable object : ()�� ȣ�� ������ ��ü
// �Ϲ� �Լ� 
// �Լ� ��ü(Function Object, Functor)
// ���� ǥ����
// 

int main()
{
	int n1 = 10, n2 = 10;
	int x[] = { 1,2,3,4,5 };

	//����ǥ���Ŀ��� �������� ���
	//for_each(x, x + 5,
	//	[n1, n2](int n) { n1 = 0; cout << n + n1 + n2 << ","; });

	// mutalbe ���� : () ������ �Լ��� ���� �Լ��� �ش޶�.
	for_each(x, x + 5,
		[n1, n2](int n) mutable { n1 = 0; cout << n + n1 + n2 << ","; });


	//------------------------------------
	// �� ������ ���� �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	// ���� ǥ������ �Լ���ü�� �ڵ������ϴ� ����
	// �Դϴ�.!!!

	class ClosureType
	{
		int n1, n2;
	public:
		ClosureType(int a, int b) : n1(a), n2(b) {}

		inline void operator()(int n) //const --> mutable�� �Ұ�� const�� ����
		//inline void operator()(int n) const
		{
			n1 = 0;	// ��� �Լ��̹Ƿ� ��������� ������ �� ����
			cout << n + n1 + n2 << ",";
		}
	};

	// ����ǥ������ ����� ��ü�� Closure�� �θ���.
	// �Ʒ� �ڵ忡�� n1, n2�� main�� �������� �Դϴ�.
	for_each(x, x + 5, ClosureType(n1,n2));
}
