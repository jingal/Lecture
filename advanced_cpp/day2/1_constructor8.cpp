//1_생성자8

#include <iostream>
using namespace std;


//해결책 2. RAII ( Resource Acquistion Is Initialize)
//			자원을 획득하는 것은 자원 관리객체가 초기화 될때이다.
//			자원관리 전용 클래스 사용

// 멤버의 생성자가 성공하면 멤버의 소멸자가 호출되는 것은
// 보장된다.

// 아래 코드에서 Test 생성자는 실패해서 Test 소멸자가
// 호출되지 않지만
// p의 생성이 성공하면 p의 소멸자는 호출된다.

// 클래스가 생성자에서 자원을 할당하면
// Rule of 3 : 소멸자, 복사 생성자, 대입 연산자를 만들어야 한다.
// Rule of 5 : C++11에서는 move 생성자, move 대입이 필요하다.
// Rule of 0 : 스마트 포인터등의 자원 관리 도구를 사용하면 
//			   5개의 함수를 만들지 않아도 된다.

#include <memory>

struct Test
{
	//int* p;
	shared_ptr<int> p;

	Test() : p (new int)
	{		
		//p = make_shared<int>();
		// 작업중에서 예외 발생
		throw 1;
	}

};

int main()
{
	try {
		Test t;
	}
	catch (...) {}

	cout << "계속 실행" << endl;

	//Test t;
}