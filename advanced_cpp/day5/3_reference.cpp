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

	// ? 에는 n,10 중 어느것이 놓여야 될지 생각해 보시요.
	// reference collapse : 규칙 && && 일때만 &&
	//						나머지 경우는 &
	LREF& r3 = n ;		// int& & => int&
	LREF&& r4 = n ;		//	
	RREF& r5 = n ;		//	
	RREF&& r6 = 10 ;		//
}