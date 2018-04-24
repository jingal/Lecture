#include <iostream>
#include <memory>
using namespace std;

//Test t;		//error

class Test;		// class forward declaration
Test *t;		//ok, 전방선언이 있으면 가능., 
				// incomplete obejct : 전방선언만 있는 타입의 
				//						포인터
				// delete시에 소멸자가 호출되지 않는다.

//checked delete
void foo(Test* p)
{
	//sizeof(Test); //옛날방법. 완전한 타입만 크기를 구할 수 있다.
	//enum { type_must_be_comlete = sizeof(Test); };
	static_assert(sizeof(Test) >= 1, "error");

	delete p;

	default_delete<int> d;
}

class Test
{
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl;  }
};

int main()
{
	Test *p = new Test;
	foo(p);
}