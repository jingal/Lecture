//1_auto 

#include <iostream>
using namespace std;



int main()
{
	int n = 0;	
	int& r = n;
	const int c = 0;

	// a1,a2, a3�� Ÿ���� ������ ������.
	// 1. auto�� ���纻�� ����� ����Դϴ�.
	//		���� Ÿ�Ը� ����մϴ�.
	//		�캯�� const, volatile, reference�� ������ ����

	auto a1 = n;			//int
	auto a2 = r;			//int
	auto a3 = c;			//int

	decltype(n) d1;			//int
	decltype(r) d2;			//int&				- �ʱⰪ�� �����Ƿ� error
	decltype(c) d3;			//constint			- �ʱⰪ�� �����Ƿ� error
}