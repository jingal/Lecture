// 3_ExceptionSafefy2 (예외안정성) - 59 page

#include <iostream>
using namespace std;


// Exception Safety (예외 안정성)
// 예외가 발생하더라도 계속 사용할 수 있어야 한다.
// 완벽 보장 : 예외가 없다. int a = 0, int* p = 0;

// 강력 보장 : 예외가 있지만 예외를 잡으면 
//				객체의 상태는 예외바생 이전의 상태를 보장한다.

// 기본보장 : 예외가 발생해도 자원 누수는 없다.
//				하지만, 객체의 상태는 알수 없다. 사용할 수 없다.

template<typename T> class Stack
{
	T buff[10];
	int idx = 0;

public:
	void push(const T& a) {
		buff[idx++] = a;
	}
	/*
	T pop()
	{
	--idx;

	if (idx < 0)
	throw 1;

	return buff[idx];
	}
	*/


	// 오류를 먼저 확인학 상태를 변경한다.
	T pop()
	{
		if (idx < 1)
			throw 1;

		--idx;
		return buff[idx];
	}

};

int main()
{
	Stack<int> s;

	try {
		s.pop();
	}
	catch (...) {}

	cout << "프로그램은 계속 실행" << endl;
	//그런데, s를 계속 사용해도 될까요?
}
