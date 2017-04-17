#include <iostream>
#include <type_traits>
//#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	auto
///////////////////////////////////////////////////////////////////////////

int main() 
{
	int n = 10;
	int& r = n;

	const int c = 10;
	const int& cr = c;


	//��Ģ 1. �� Ÿ�� �϶� : �캯 ������ reference, const, volatile �Ӽ��� �����ϰ� auto Ÿ�� ����
	auto a1 = n;			// int
	auto a2 = r;			// int
	auto a3 = c;			// int 
	auto a4 = cr;			// int


	//��Ģ 2. ���� Ÿ�� �϶� : const, volatile �Ӽ� ����, ���۷��� �Ӽ��� �����ϰ� auto ����
	auto& a5 = n;			// auto : int		a5 : int&
	auto& a6 = r;			// auto : int		a6 : int&
	auto& a7 = c;			// auto : const int a7 : const int&
	auto& a8 = cr;			// auto : const int	a8 : const int&

	//��Ģ 3. forwading reference
	auto&& a9 = n;	
}


/*
int main()
{
	int n = 10;
	auto a1 = n;		//a1�� int

	int& r = n;
	auto a2 = r;		//int ? int&

	a2 = 20;

	cout << n << endl;
}

*/
