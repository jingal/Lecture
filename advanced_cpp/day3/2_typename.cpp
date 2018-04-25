// 2_typename

#include <iostream>
#include <vector>
using namespace std;

struct AAA
{
	typedef int DWORD;
	struct rebind1 { };	
	template<typename T>struct rebind2 
	{ 
		typedef T other;
	};
};

template<typename T> typename T::template rebind2<int> foo(T a)
{
	// T : AAA	
	//typename T::DWORD n;		// DWORD�� static ���(��) 
								// �Ǵ� typedef(Ÿ��)�� �� �ִ�
								// typename�� ������ ��(static����)�� �ؼ�	

	typename T::rebind1 m;

	// rebind2�� ��ü n2�� ����� ������.
	//typename T::rebind2<int> p;--> �����Ϸ��� rebind2�� �ڿ� ������ <�� �˼��� ����
	
	typename T::template rebind2<int> n2;
	//typename T::rebind2<int>::other nt;

	typename T::template rebind2<int>::other n3;

	return n2;
}

int main()
{
	AAA a;
	foo(a);
}