#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	initializer_list
///////////////////////////////////////////////////////////////////////////

//initializer_list<int> : braced-init-list�� ��Ҹ� ���۰� �� (����)�� ����Ű�� Ŭ����

int main()
{
		//VC++ : int *first, *last;
		//g++ : int *first, count

	initializer_list<int> s = { 12,3,4,5,6,7,8,9,10 };

	auto p1 = s.begin();
	auto p2 = s.end();

	*p1 = 10; //error, �б⸸ ����, �Լ��� ���ڷ� ���� ���
}
