//3_trivial4

#include <iostream>
#include <type_traits>
using namespace std;

// C�� C++�� ȣȯ���� ���� ����
// trivial : �Լ��� �ϴ� ���� ���ٴ� �ǹ� (�Լ�����)
// standard layout : �޸� ������ c�� �����ϴٴ� �ǹ�
// pod : plain old data => Trivial && standard layout
// aggregate : �ʱ�ȭ�� ����

template<typename T>
void mymemset(T* p)
{
	static_assert(is_pod<T>::value, "T is not pod");
	// �Ʒ�ó�� �ص� �ɱ�?
	memset(p, 0, sizeof(T));
}

struct Point
{
	int x, y;
	Point() {}
};

int main()
{
	//int x;
	//mymemset(&x);

	Point p;
	mymemset(&p);
}