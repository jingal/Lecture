#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	member initialization
///////////////////////////////////////////////////////////////////////////

int x = 0;

class Test
{
public:
	//int data = 0;		//member initializer
	int data = ++x;		//�������� ���� ���� �ǰ� ������ �Ҹ�
						//11���ʹ� �ʱ�ȭ �ڵ尡 ���� ���, ������ ���� �Ҹ�

	Test() {}
	Test(int b) : data(b) {}		// �ʱ�ȭ ����Ʈ�� ���� ��� ��� �ʱ�ȭ �ڵ� ����ȵ�
};

int main()
{
	Test t1;					//t1.data => 1
	Test t2(3);					//t2.data => 3

	cout << t1.data << endl;	//0
	cout << t2.data << endl;	//3

	char c1{ 0 };
	char c2 = { 0 };
	char c3 = { 'a' };
	char c4 = { 300 };
}