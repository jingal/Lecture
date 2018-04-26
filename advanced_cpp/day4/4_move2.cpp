// 4_move2 - 133 page

#include <iostream>
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

	Test(Test&& t) noexcept
	{		
		cout << "move ������" << endl;
		p = t.p;
		t.p = 0;
	}	

	~Test() { delete[] p; }
};

int main()
{
	Test* p1 = new Test[2];

	//���۸� 4���� Ű����� �մϴ�.
	// 1. new�� �ƴ� operator new�� �޸𸮸� �Ҵ�
	// 
	Test* p2 = static_cast<Test*>(
				operator new(sizeof(Test) * 4));

	//2. 2���� ���� ���۳��� ����
	for (int i = 0; i < 2; i++)
	{
		//new(&p2[i]) Test(p1[i]);		//���� ������.
		//new(&p2[i]) Test(move(p1[i]));		//Move ������.

		// move_if_noexcept : ���ܰ� ���� ���� move
		//						���ܰ� ���� �� �ִٸ� copy
		new(&p2[i]) Test(move_if_noexcept(p1[i]));
	}
}