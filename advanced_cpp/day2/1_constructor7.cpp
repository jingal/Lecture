//1_������7

#include <iostream>
using namespace std;


//�����ڿ� ����
// �ذ�å : 32 page, two phase initialization
struct Test
{
	int* p;

	// �����ڿ����� ���� ���ɼ��� �ִ� ��� �ϵ����� ����. 0 �ʱ�ȭ�� ����.
	Test() : p(0) {}

	//��ü�� �ʿ��� �ʱ�ȭ�� �ϴ� �����Լ�
	void init()
	{
		// ���⼭�� �����Լ��� ����� �� �ִ�.
		// ��, �ʱ�ȭ �������� �����Լ� ��밡��.
		cout << "�ڿ��Ҵ�" << endl;
		p = new int;

		// �۾��߿��� ���� �߻�
		throw 1;
	}

	~Test() {
		cout << "�ڿ� ����" << endl;
		delete p;
	}
};

int main()
{
	try {
		Test t;
		t.init();
	}
	catch (...) {}

	cout << "��� ����" << endl;

	//Test t;
}