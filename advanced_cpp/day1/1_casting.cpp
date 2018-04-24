//1_casting.cpp - 책 7 page addressof

#include <iostream>

using namespace std;

// C 캐스팅의 문제점1
/*
int main()
{
	int n = 4;
	//double* p = &n;			// error. 서로 다른 타입의 주소는 담을 수 없다.
	double* p = (double*)&n;	// compile OK, 
	
	*p = 3.4;
}
*/

// C캐스팅의 문제점 2
int main()
{
	//const int c = 10;	// 컴파일 시간 상수
						// 매크로 처럼 취급 된다.
						// 컴파일러는 컴파일 중에 하단에 있는 c를 10을 치환시킴

	int n = 10;			// 
	const int c = n;	// 실행시간 상수.
						// 초기값을 컴파일 시간에 알 수 없다.

	//int *p = &c;		// 이 한줄을 생각해 봅시다.
						//error
	int *p = (int*)&c;

	*p = 20;

	cout << c << endl;		//10	20
	cout << *p << endl;		//20	20
}