#include <iostream>
#include <cassert>

using namespace std;


//static_assert(sizeof(double) > 8, "error, assert failed");

void foo(int age)
{
	static_assert(age > 0, "failed");	// error, ��Ÿ���� üũ �ȵ�, ���ǽ��� ������ �ð��� �����Ǿ�� �Ѵ�.
}

int main()
{
	static_assert(sizeof(double) > 8, "error, assert failed");
}



/*
void foo(int age)
{
	//���ڸ� ����ϱ� ���� ��ȿ���� ���� Ȯ���Ѵ�.
	assert(age > 0);

	// age ���...
	//
}

int main()
{
	foo(0);
}
*/