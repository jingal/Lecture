// 6_callableobject5

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
	int x[] = { 1,2,3,4,5};

	for_each(x, x+5,
		[](int n) { cout << n << ","; });
	//------------------------------------
	// �� ������ ���� �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	// ���� ǥ������ �Լ���ü�� �ڵ������ϴ� ����
	// �Դϴ�.!!!

	class ClosureType
	{
	public:
		inline void operator()(int n) const
		{
			cout << n << ",";
		}
	};

	// ����ǥ������ ����� ��ü�� Closure�� �θ���.
	for_each(x, x + 5, ClosureType());
}
