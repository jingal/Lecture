//1_생성자7

#include <iostream>
using namespace std;


//생성자와 예외
// 해결책 : 32 page, two phase initialization
struct Test
{
	int* p;

	// 생성자에서는 예외 가능성이 있는 어떠한 일도하지 말자. 0 초기화만 하자.
	Test() : p(0) {}

	//객체에 필요한 초기화를 하는 전용함수
	void init()
	{
		// 여기서는 가상함수도 사용할 수 있다.
		// 즉, 초기화 과정에서 가상함수 사용가능.
		cout << "자원할당" << endl;
		p = new int;

		// 작업중에서 예외 발생
		throw 1;
	}

	~Test() {
		cout << "자원 해지" << endl;
		delete p;
	}
};

int main()
{
	try {
		Test t;
		t.init();
	}
	catch (...) {}

	cout << "계속 실행" << endl;

	//Test t;
}