#include <iostream>
#include <type_traits>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	nullptr #1 - 0�� ������
///////////////////////////////////////////////////////////////////////////

int main()
{
	int n1 = 0;
	int* p1 = 0;			//0�� int, �����ͷ� �Ͻ��� ����ȯ ����

	int n2 = 10;			// ok.
	int* p2 = 10;			// error;
}