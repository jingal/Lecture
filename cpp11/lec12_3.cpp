#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	braced init
///////////////////////////////////////////////////////////////////////////

// �ϰ��� �ʱ�ȭ (uniform initialize, brace init) : ��ü�� ���¿� ��� ���� �߰�ȣ(brace, {}) �� ����ؼ� �ʱ�ȭ �ϴ°�.

// prevent narrow : ������ �ս��� �߻��ϴ� �ʱ�ȭ�� error �߻�

// braced-init-list

int main()
{
	int n1 = { 0 };
	int n1 = { 3.4 };
	char n1 = { 300 };


	int x[3] = { 1,2,3 };

	vector<int> v = { 1,2,3 };
}
