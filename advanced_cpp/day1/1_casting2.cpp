//1_casting2.cpp - 책 7 page addressof

#include <iostream>
#include <memory>
#include <cstdio>
#include <cstring>

using namespace std;

// C++ 캐스팅
// static_cast : 컴파일 시간 캐스트, 연관성 있는 타입만 가능
//					void* => 다른 타입 허용
//				standard conversion 허용
//				컴파일 시간에 적용되므로 성능 저하 없음


// reinterpret_cast : 메모리의 재해성
//						포인터 끼리의 캐스팅
//						포인터 <-> 값 캐스팅
//						값 <-> 값 캐스팅 안됨


int main()
{
	double d = 3;
	//int n = reinterpret_cast<double>(n);		// error

	//int* p = 10;							// error
	int* p = (int*)10;						// ok
	//int* p = static_cast<int*>(10);		// error
	int* p = reinterpret_cast<int*>(10);	// ok

	// 서로 다른 타입도 주소끼리는 가능
	//double *p = reinterpret_cast<double*>(&n);	//ok


	//포인터 외에 참조도 가능
	int n2 = 10;
	char& c = reinterpret_cast<char&>(n2);


}


/*
int main()
{
	double d = 3;
	//int n = d;
	int n = static_cast<int>(d);				//standard conversion --> 암시적 컨버전 허용

	int* p = static_cast<int*>(malloc(100));

	// 서로 다른 타입의 포인터를 캐스팅할 수 없다.
	// double* p2 = static_cast<double*>(&n);		// error

}*/