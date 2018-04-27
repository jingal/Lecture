//2_rvalue

#include <iostream>

using namespace std;


// CPL에서 최초에 정의
// lvalue : 등호의 오른쪽과 왼쪽에 모두 가능
//			++주소를 구할 수 있다++. (c에서 정의 변경)
//			이름이 있는 것 (c++)
//			++이름이 있고++, 단일 식을 넘어서 존재
//			참조를 리턴하는 함수
// rvalue : 등호의 오른쪽만 가능
//			주소를 구할 수 없다. (c에서 정의 변경)
//			이름이 없는 것(C++)
//			이름이 없고, 단일식에서만 존재
//			값을 리턴하는 함수
//			literal(e.g. 10, 3.4 "AA"), 임시객체

int main()
{
	int v1 = 10, v2 = 20;

	v1 = 10;			// v1 : lvalue, 10 : rvalue
	10 = v1;			// error, 어셈관점에서 보면 코드로 10이 박혀있음
	v2 = v1;			// 

	cout << &10 << endl;

	const int c = 10;
	c = 20;		// c : lvalue, ? rvalue
				// 수정 불가능한 lvalue

	// 질문 : 모든 rvalule는 상수이다. ? -> 아니다
	//			임시객체는 상수가 아니다.

	// 
}