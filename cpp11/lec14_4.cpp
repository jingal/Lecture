#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	decltype
///////////////////////////////////////////////////////////////////////////

int main()
{
	int x[3] = { 1,2,3 };

	int n = 10;
	int* p = &n;

	// �����ڸ� ������ ������ �º��� �� �� �ִ� �� ���ο� ���� �޶��� --> �� �� ������ ����, �ƴϸ� ��
	decltype(p) d1;		// int*
	decltype(*p) d2;	// int ? int& --> int&
	decltype(x[0]) d3;	// x[0] = 10.. int &

	decltype(n + n) d4;	// n+n = 20.. error,   => int
	decltype(++n) d5;	// ++n = 20.. ok => int&, 11�� �ٲ� n�� ���ϵ�
	decltype(n++) d6;	// n++ = 20,; error, ������ �ִ� 10�� ���ϵ�, int
}

