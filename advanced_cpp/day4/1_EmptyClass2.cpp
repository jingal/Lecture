//1_EmptyClass2 - 73 page EBCO

#include <iostream>
using namespace std;

int main()
{

	// ������ �߸��� ����
	//int* p = new int;		// �޸� �Ҵ� ���н� 0�� �ƴϰ� 
							// std::bad_alloc ���� �߻�
							// 0üũ ���� try catch (bad alloc)�� ����ؾ� ��.

	// ���н� ���� ��� 0�� ��ȯ�� �޶�.
	int* p = new(nothrow) int;

	if (p == 0)
	{
		//...
	}

	delete p;
}


