#include <iostream>
#include <cstdio>

using namespace std;


class Test
{
	int value;

public:
	explicit Test(int n) : value(n) {}
};


int main()
{
	Test t1(5);			//	direct initialization ==> ���� �Ѱ��� �����ڸ� ȣ���ؼ� ��ü �ʱ�ȭ
	Test t2 = 5;		//	copy initialization ==> A. 5�� ��ȯ �����ڸ� ����ؼ� Test �ӽð�ü ����
						//							B. �ӽð�ü�� ���� �����ڸ� ����ؼ� t2 ����


	shared_ptr<int> p1(new int);		//ok..
	shared_ptr<int> p2 = new int;		// error.. shared_ptr<> �����ڴ� explict, 
										// ������ �Ͻ��� ��ȯ�� ���ڴ� �������̱� ������, ��κ� explict �����ڸ� ���
}