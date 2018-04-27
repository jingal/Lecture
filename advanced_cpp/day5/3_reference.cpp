//3_reference

#include <iostream>
using namespace std;

typedef int& LREF;
typedef int&& RREF;


int main()
{
	int n = 10;
	int& r1 = n;
	int&& r2 = 10;

	// ? ���� n,10 �� ������� ������ ���� ������ ���ÿ�.
	// reference collapse : ��Ģ && && �϶��� &&
	//						������ ���� &
	LREF& r3 = n ;		// int& & => int&
	LREF&& r4 = n ;		//	
	RREF& r5 = n ;		//	
	RREF&& r6 = 10 ;		//
}