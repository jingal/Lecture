// 4_move - 133 page

#include <iostream>

using namespace std;


struct Test
{
	int* p = 0;

	Test() {
		p = new int[100];
	}

	Test(const Test& t)				// ���� ������
	{
		//���� ����
		cout << "���� ������" << endl;
		p = new int[100];
		memcpy(p, t.p, sizeof(int) * 100);
	}

	Test(Test&& t)			// move ����
	{		
		// ������ ����
		cout << "move ������" << endl;
		p = t.p;		// ���� ����.
		t.p = 0;		// ���� ��ü�� �ڿ� ����
	}
	��

	~Test() { delete[] p; }
};

int main()
{
	Test t1;
	Test t2 = t1;	// ���� ������ ȣ��
	Test t3 = std::move(t1);	// move ������ ȣ��
}
