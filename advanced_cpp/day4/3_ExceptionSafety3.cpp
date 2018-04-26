// 3_ExceptionSafefy3 (예외안정성) - 59 page

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
	void push(const T& a) { buff[idx++] = a; }

	// 제거와 반환은 분리되는 것이 안전하다.
	void pop() { --idx;	}
	T& top() { return buff[idx]; }
};

// 제거와 리턴이 분리된 이유
// 1. 예외 안정성의 강력 보장을 지원하기 위해
// 2. 참조리턴을 통해서 임시객체를 없애기 위해.
// STL의 모든 컨테이너는 제거와 반환이 분리되어 있습니다.
// C++ : 값의 개념과 참조(포인터)의 개념이 모두 존재
// Java : 참조만 존재

struct People {};

int main()
{
	Stack<People> s;

	People p;
	s.push(p);

	try
	{
		People p2 = s.top();		// 1. s.top 호출
									// 2. People 복사 생성자.
									// 2번에서 예외가 있으면어떻게 될까?
									// 제거되지 않았으므로 문제 없다.
		s.pop();
	}
	catch (...) {
		//s의 상태가 예외 이전과 동일할까?
	}

	cout << "프로그램은 계속 실행" << endl;
	//그런데, s를 계속 사용해도 될까요?
}
