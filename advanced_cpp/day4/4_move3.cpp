// 4_move3 - 133 page

#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

struct Test
{
	int* p = 0;

	Test() {
		p = new int[100];
	}

	Test(const Test& t)
	{
		cout << "���� ������" << endl;
		p = new int[100];
		memcpy(p, t.p, sizeof(int) * 100);
	}
	
	// �Ϲ��Լ��� �ظ��ϸ� noexept ���̴� ���� ����.
	// ���ܰ� ������ ǥ��
	// f() nothrow(int) : int Ÿ���� ���ܰ� �߻��� �� ����
	// f() nothrow() : C++ 98
	// f() noexecpt : C++ 11

	Test(Test&& t) noexcept
	{
		cout << "move ������" << endl;
		p = t.p;
		t.p = 0;
	}

	void foo() const noexcept {}

	~Test() { delete[] p; }
};

void foo() noexcept {}

int main()
{
	vector<Test> v(2);
	v.resize(4); // 2��¥�� ���۸� 4���� �����ؾ� �մϴ�.

	//���� ����
	//1.������, ����, �Ҹ��ڵ�
	is_nothrow_default_constructible<Test>::value;

	//foo�Լ��� ���� ���ɼ� ����
	// unevaluated expression
	bool b2 = noexcept(foo());
}