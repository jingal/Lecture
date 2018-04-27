//1_auto2

#include <iostream>
using namespace std;

int main()
{
	int			n;	// n : 변수이름, 타입 : int
	double		d;	// d :  변수이름, 타입 : double

	// 변수이름 x, 타입 : int[3]
	int x[3] = { 1,2,3 };

	// 아래 코드에서 a와 d의 타입을 생각해 보세요.
	auto a = x;
	// 후보 1. int a[3] = x;	error
	// 후보 2. int* a	= x;	배열이 배열의 1번째 요소의
	//							주소로 암시적 형변환 되는 것 
	//							array to conversion

	decltype(x) d;		// int d[3]
	decltype(x) d = x;	// int d[3] = x 이므로 error
}