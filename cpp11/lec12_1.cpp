#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	object initialization
///////////////////////////////////////////////////////////////////////////

// C++ 98/03 초기화 구문의 문제점

//1. 객체의 종류에 따라 초기화 방법이 다르다

int n1 = 0;
int n2(0);

//배열, 구조체
int ar[3] = { 1,2,3 };
struct Point p = { 1,2 };

//2. 클래스 안에 배열 멤버를 초기화 할 수 없다. static 멤버가 아니면 방법이 없음
class Test
{
	int x[10];
};

//3. 동적으로 할당하는 배열을 초기화 할 수 없다.
int *p = new int[3];


//4. STL의 컨테이너를 초기화 할 수 있는 편리한 방법이 없다.

vecotr<int> v;
v.push_back(1);
