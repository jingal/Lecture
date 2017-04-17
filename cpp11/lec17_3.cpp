#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>
#include <chrono>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;
using namespace std::chrono;

///////////////////////////////////////////////////////////////////////////
//	Reference & temporary object (임시와 참조) #3
///////////////////////////////////////////////////////////////////////////

string foo()
{
	return string("foo");		//임시객체로 리턴. 
}

void goo()
{
	throw string("goo");		//임시객체로 예외 전달.
}

int main()
{
	//string& s = foo();		// error. 임시객체로 리턴하기 때문에 컴파일 에러 발생

	try {
		goo();
	}
	catch (string& e)			// 임시객체를 예외로 던질 경우 참조로 잡을 수 있음 (예외케이스)
	{
		cout << e << endl;
	}	
}