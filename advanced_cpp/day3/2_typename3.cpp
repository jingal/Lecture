// 2_typename3

#include <iostream>
#include <list>
using namespace std;


// Ŭ���� 
// 1. ��� ����Ÿ
// 2. ��� �Լ�
// 3. ��� Ÿ�� - value_type, size_type, iterator

int main()
{
	list<int> s = { 1,2,3 };
	//int sz = s.size();			// ?�� � Ÿ������ �ұ�

	//unsigned int sz = s.size();

	list<int>::size_type sz = s.size();
}