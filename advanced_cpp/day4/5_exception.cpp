// 5_excetion 

#include <iostream>
using namespace std;

// C++ ǥ�ؿ� �̹� ���ܸ� ���� ��� Ŭ���� ����
/*
class exception
{
public:
	virtual const char* what()
	{
		return "unknown exception";
	}
};*/

struct memory_exeption : public exception
{
	virtual const char* what() const override
	{
		return "memory error";
	}
};

void foo()
{
	if (1) //����
		throw memory_exeption();
		// �ӽ� ������ �������� exception ������ ���������� ������ ���� �� ����
}

int main()
{
	try
	{
		foo();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}
