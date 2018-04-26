// 6_callableobject7

#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20;

	//[&](int a) { v1 = a; v2 = a; cout << "A" << endl; };
	[](int a) { cout << "A" << endl; };
		
	//------------------------------------------------------
	class ClosureType
	{		
	public:
		inline void operator()(int a)
		{			
			cout << "A" << endl;
		}
	};

	ClosureType();		//임시객체 생성
	//ClosureType()(5);		//임시객체 () 연산자 함수 호출
}
