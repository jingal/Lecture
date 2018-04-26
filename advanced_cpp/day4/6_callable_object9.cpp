// 6_callableobject9

#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20;

	//[&](int a) { v1 = a; v2 = a; cout << "A" << endl; };
	// error, ()연산자가 상수함수이다. 멤버변경 안됨
	//[v1, v2](int a) { v1 = a, v2 = a, cout << "A" << endl; }(5);

	// mutable 람다 : ()연산자를 비상수함수로 해달라는 의미
	// 레퍼런스 캡쳐
	[&v1, &v2](int a) { v1 = a, v2 = a, cout << "A" << endl; }(5);

	cout << v1 << endl;	//5나오게 하려면 아래코드를 
						//어떻게 해야할까요?

	//------------------------------------------------------
	class ClosureType
	{
		int& v1;
		int& v2;
	public:
		ClosureType(int& a, int& b) : v1(a), v2(b) {}

		inline void operator()(int a) const
		{
			v1 = a, v2 = a;
			cout << "A" << endl;
		}
	};

	//ClosureType();			//임시객체 생성
	ClosureType(v1, v2)(5);		//임시객체 () 연산자 함수 호출
}
