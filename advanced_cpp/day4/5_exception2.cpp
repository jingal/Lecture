// 5_excetion2

#include <iostream>
using namespace std;

// �Ҹ��ڴ� ���� ���ܸ� ������ �ȵȴ�.
// operator delete()�� ���ܰ� ������ �ȵȴ�.
// move �����ڵ� ���ܰ� ���� �� ����.

struct Test
{
	~Test() {
		cout << "�Ҹ���" << endl; throw 1;
	}
};

void foo()
{
	Test t;
	throw 1;		// ���������� �ı� �ȴ�. (stack unwinding)
}

int main()
{
	try
	{
		foo();
	}
	catch (...)
	{
		
	}
}
