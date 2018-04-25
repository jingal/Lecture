//1_생성자6

#include <iostream>
using namespace std;


//생성자와 예외
// 문제점 : 생성자 호출에 성공한 객체만 소멸자를 호출한다.
//			생서자에서 예외가 발생하면 소멸자가 호출되지 않는다.
//			생성자에서 실패를 반환하는 방법은 
//			예외밖에 없었기 때문에.. 많이 사용되었었다.
struct Test
{
	int* p;

	Test()
	{
		cout << "자원할당" << endl;
		p = new int;

		// 작업중에서 예외 발생
		throw 1;
	}

	// 소멸자는 생성자가 완벽하게 성공했을 경우에만 불림
	~Test() {
		cout << "자원 해지" << endl;
		delete p;
	}
};

int main()
{
	try {
		Test t;	
	}
	catch(...) {}

	cout << "계속 실행" << endl;

	//Test t;
}